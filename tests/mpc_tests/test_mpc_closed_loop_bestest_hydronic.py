#from ast import Param
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF, KalmanBucy
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from copy import deepcopy
from ocp.functions import functions

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_func.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF_func.json")

    # pass in config?
    """
    Rie       6.987636e-04
    Rea       3.184517e-03
    Ci        5.407161e+06
    Ce        4.533857e+07
    Ai        2.767623e+01
    UA_nom    3.915722e+01
    """
    params = ca.DM([6.987636e-04,
                    3.184517e-03,
                    5.407161e+06,
                    4.533857e+07,
                    2.767623e+01,
                    3.915722e+01])
    
    
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 5000,
        "r_nom": 300,
        "y_nom": 12,
        "y_nom_b": 289.15,
        #"slack": True
        "slack": True
    }
    kwargs = {
        "x_nom": 300,
        "u_nom": 5000,
        "r_nom": 300,
        "y_nom": 300,
        #"slack": Trues
        "slack": True
    }
    
    mpc = MPC(config=mpc_cfg,
              functions=functions,
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_hydronic"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([294.05, 293.15])
    
    # sim horizon: 2 days
    days = 7
    K = days*24*bounds.t_h

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        sol, u, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params
                               )

        data, y_meas, u_meas = boptest.evolve(u=u)
        
        x0 = ekf.estimate(
                          x0, 
                          y=y_meas, 
                          u=u_meas, 
                          r=data.iloc[0].values
                          )

    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    fig.tight_layout()
    plt.show()    

    """
    plt.rcParams.update({'font.size': 11})
    
    res = boptest.get_data(tf=K*boptest.h)
    fig = plt.figure(figsize=(10,6))
    ax = fig.add_subplot(111)
    
    # colors
    colors = iter(plt.cm.rainbow(np.linspace(0, 1, 5)))
    #for i in range(n):
    #c = next(colors)
    #plt.plot(x, y, c=c)
    
    dt_index = pd.Timestamp("2020-01-01 00:00") + res.index
    
    #l1 = res.Ti.plot(ax=ax, color="k")
    #l1 = ax.plot(res.index, res.Ti, color="k", label="$T_i$")
    l1 = ax.plot(dt_index, (res.Ti-273.15), color=next(colors), label="$T_i$")
    ax1 = ax.twinx()
    #l2 = res.phi_h.plot(ax=ax1, color="k", linestyle="--")
    #l2 = ax1.plot(res.index, res.phi_h, color="k", linestyle="dashed", label="$\phi_h$")
    l2 = ax1.plot(dt_index, res.phi_h, color=next(colors), label="$\phi_h$")
    
    #ax.legend([l1, l2], , loc=0)
    ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d %H:%M'))
    fig.autofmt_xdate()
    #ax.legend(["Ti"])
    #ax1.legend(["phi_h"])
    # plot bounds:
    #bounds_plt = pd.concat([bounds]*days)
    bounds_plt = bounds.get_full(days)
    bounds_plt.index = res.index
    #bounds_plt[("lb", "Ti")].plot(ax=ax, drawstyle="steps")
    #bounds_plt[("ub", "Ti")].plot(ax=ax, drawstyle="steps")
    l3 = ax.plot(dt_index, (bounds_plt[("lb", "Ti")]-273.15), color="k", drawstyle="steps", label="$T_{i}^{lb}$")
    l4 = ax.plot(dt_index, (bounds_plt[("ub", "Ti")]-273.15), color="k", drawstyle="steps", label="$T_{i}^{ub}$")
    lns = l1+l2+l3+l4
    labs = [l.get_label() for l in lns]
    ax.legend(lns, labs, loc='upper center', ncol=4)
    _min, _max = ax.get_ylim()
    ax.set_ylim([_min, _max+1])
    _min, _max = ax1.get_ylim()
    ax1.set_ylim([_min, _max+1000])
    
    ax.set_ylabel(r"Temperature [$^\circ$C]")
    ax1.set_ylabel(r"Power [W]")
    
    fig.tight_layout()
    plt.show()    
    """