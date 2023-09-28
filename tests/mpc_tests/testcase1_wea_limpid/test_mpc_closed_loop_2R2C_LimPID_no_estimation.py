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
from ocp.functions import functions

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    #mpc_cfg = os.path.join(opt_config_base, "3R3C_bestest_air_MPC.json")
    mpc_cfg = os.path.join("mpc_configs", "3R2C_LimPID_FMU_MPC.json")
    #mpc_cfg = os.path.join("mpc_configs", "3R2C_PID_FMU_MPC.json")
    #mpc_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_MPC_2meas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_idas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_map_test.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    #ekf_cfg = os.path.join("ekf_configs", "2R2C_PI_EKF_1meas_Ai.json")
    #ekf_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_EKF_2meas.json")
    
    """
    Handle FMU, add DLL equations to functions:    
    """
    
    dae = ca.DaeBuilder('pi', 'FMUs/LimPID_Buildings/LimPID.fmutmp')
    #dae = ca.DaeBuilder('pi', 'FMUs/PI/PI.fmutmp')
    dae.disp(True)
    aux = dae.p()
    name_in = ['x','u']
    name_out = ['ydef']
    pi_y = dae.create('pi_y', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "serial"})
    name_out = ['ode']
    pi_ode = dae.create('pi_ode', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "serial"})
    functions["pi_ode"] = pi_ode
    functions["pi_y"] = pi_y
    
    params = ca.DM([
                0.001,
                0.01,
                1E6,
                5E6,
                5])
    
    
    """
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12],
        "u_nom_b": [289.15],
        "r_nom": [12, 300, 12, 12],
        "r_nom_b": [289.15, 0, 289.15, 289.15],
        #"slack": True
        "slack": False
    }
    """
    
    kwargs = {
        "x_nom": 300,
        "u_nom": 300,
        "r_nom": 300,
        "y_nom": 300,
        #"slack": True
        "slack": False
    }
    kwargs = {
        "x_nom": 1,
        "z_nom": 1,
        "u_nom": [1],
        "u_nom_b": [0],
        "r_nom": 1,
        "y_nom": 1,
        #"slack": True
        "slack": False
    }
    
    #ekf = KalmanBucy(ekf_cfg)
    # set params:
    #ekf.set_params(params)
    
    mpc = MPC(config=mpc_cfg,
              param_guess=params,
              functions=functions, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1_wea_limpid"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 301.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    list(boptest.maps["y"].keys()),
                    day_begin=8,
                    day_end=18,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    #x0 = np.array([294.05, 293.15, 300.15])
    x0 = np.array([293.15, 293.15, 0])
    
    # sim horizon: 2 days
    days = 1
    K = days*24*bounds.t_h
    miss = 0

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        # adjust upper bound of E:
        ubx[2:-1:3] *= 1000
        ubx[-1] *= 1000
        
        sol, u, x0, raw = mpc.solve(
                                    data[0:mpc.N],
                                    x0=x0,
                                    lbx=lbx,
                                    ubx=ubx,
                                    params=params,
                                    codegen=False,
                                    return_raw_sol=True
                                    )
        #u["fan"] = 1
        if mpc.solver.stats()["return_status"] != "Solve_Succeeded":
            miss += 1
            #u = {}
        
        #u = {}
        data, y_meas, u_meas = boptest.evolve(u=u)
        #z_model = sol[ekf.dae.z].iloc[1].values
        x0 = y_meas
        #if (u_meas < y_meas)[0]:
        #    u_meas = y_meas
        #data["_y"] = u_meas[1]
        """
        x0 = ekf.estimate(
                          x0, 
                          y=[y_meas[0]], 
                          u=u_meas[2], 
                          #z=z_model,
                          r=data[ekf.dae.r_names].iloc[0]
                          )
        """

    plt.rcParams.update({'font.size': 12})
    data = boptest.get_data(tf=K*mpc.dt)
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="phi_h")
    Tset = data.Tset[:-1] - 273.15
    Tset.index =dt_index
    axes[0].plot(Tset)
    fig.tight_layout()
    plt.show()    
    print(params)  
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
