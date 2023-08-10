# %%
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

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    #mpc_cfg = os.path.join(opt_config_base, "3R3C_bestest_air_MPC.json")
    mpc_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_MPC_1meas.json")
    #mpc_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_MPC_2meas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_idas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_map_test.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_EKF_1meas.json")
    #ekf_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_EKF_2meas.json")

    # pass in config?
    """
    params = ca.DM([
                    3.151236e-03,
                    5.428432e-03,
                    8.495345e-03,
                    2.564024e-04,
                    1.423833e+05,
                    2.187849e+07,
                    2.218342e+06,
                    5
                    ])
    params = ca.DM([
                    1.599046e-03,
                    1.250769e-02,
                    2.286526e-03,
                    1.513427e+05,
                    6.812778e+06,
                    9.272857e+00
                    ])
    """
    params = ca.DM([
            3.960196e-03,
            1.125336e-02,
            3.150582e+05,
            8.887156e+06,
            3.545100e+00,
            4.049526e+02
                    ])
    
    """
    kwargs = {
        "x_nom": 300,
        "u_nom": 5000,
        "r_nom": 300,
        "y_nom": 300,
        #"slack": True
        "slack": False
    }
    """
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12, 1],
        "u_nom_b": [289.15, 0],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0],
        #"slack": True
        "slack": True
    }
    kwargs = {
        "x_nom": 1,
        "u_nom": [1,1],
        "u_nom_b": [0,0],
        "r_nom": 1,
        "y_nom": 1,
        #"slack": True
        "slack": True
    }
    
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    
    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    
    
    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_air"
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
    #x0 = np.array([294.05, 293.15, 300.15])
    x0 = np.array([293.15, 293.15])
    
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
                               params=params,
                               codegen=True
                               )
        #u["fan"] = 1
        data, y_meas, u_meas = boptest.evolve(u=u)
        #z_model = sol[ekf.dae.z].iloc[1].values
        x0 = ekf.estimate(
                          x0, 
                          y=y_meas, 
                          u=u_meas, 
                          #z=z_model,
                          r=data.iloc[0].values
                          )

    plt.rcParams.update({'font.size': 12})
    data = boptest.get_data(tf=K*mpc.dt)
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Ph")
    fig.tight_layout()
    plt.show()    
    print(data)
    #Ph_inf = data["u_fan"]*(data["Tsup"]-data["Ti"])/sol["Ris"].iloc[0]
    #ax = data["Ph"].plot(color="r")
    #Ph_inf.plot(ax=ax, color="k", linestyle="dashed")
    #plt.show()

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
# %%
