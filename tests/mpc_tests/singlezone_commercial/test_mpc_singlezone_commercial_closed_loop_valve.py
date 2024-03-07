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
from ocp.filters import EKF, KalmanDAE
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
    
    mpc_cfg = os.path.join("mpc_configs", "3R2C_MPC.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "3R2C_EKF.json")

    params = np.array([1.25311678e-04,
                       1.45089509e+04, 
                       4.20000000e+03,
                       9.99000000e-01,
                       1.00000001e+00,
                       2.38176957e+00,
                       3.67901473e+01,
                       1.65120613e+00,
                       1.00000000e+03,
                       9.50000000e-01,
                       7.37731935e-01,
                       8.75000000e-01,
                       5.00000000e-01,
                       2.91632649e+02,
                       1.00000000e-04,
                       1.00000000e-06,
                       1.02520072e+00,
                       1.45307535e+00,
                       3.09999997e+02,
                       1.71071500e+00,
                       1.87171959e+02, 
                       6.57952230e+00,
                       2.00000002e+00, 
                       7.99999975e+00,
                       7.64359965e-01,
                       3.30759451e+02, 
                       4.25691748e-05, 
                       4.73998100e-04, 
                       4.54157104e-04,
                       2.92505112e+04,
                       1.25239773e-01,
                       8.02741952e+07,
                       3.38215281e+09, 
                       2.78795629e+02])

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "z_nom": [12,1E6,1E6,1,1,1,1,12,12,12,12,1,1,1E6],
        "z_nom_b": [289.15,0,0,0,0,0,0,289.15,289.15,289.15,289.15,0,0,0],
        "r_nom": [12,300,1E5,1E5,1E5],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [1,1,1,1,12],
        "u_nom_b ": [0,0,0,0,289.15],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        #"slack": True
        "slack": False
    }
    kwargs = dict()

    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    ekf = KalmanDAE(ekf_cfg,
                     functions=deepcopy(functions)
                     )
    # set params:
    ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="singlezone_commercial"
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
    x0 = np.array([293.15, 293.15, 293.15])
    
    # sim horizon: 2 days
    days = 2
    K = days*24*bounds.t_h
    time = pd.DataFrame(columns=["time"])

    u_hist = pd.DataFrame(columns=["model", "actual"])
    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        sol, u, x0  = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params,
                               codegen=True
                               )
        """
        if k == 14:
            print(sol) 
        """
        if k == 16:
            print(sol)
        
        # turn off ventilation:
        #u["ahu_pump_sup"] = 0.03
        #u["ahu_pump_ret"] = 0.03
        #u["ahu_Tsup"] = 288.15
        #u["rad_val"] = 1
        #u["dh_pump"] = 1
        
        if mpc.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol)
        
        time.loc[k] = mpc.solver.stats()["t_wall_total"]
        data, y_meas, u_meas = boptest.evolve(u=u,
                                              y_as_array=False,
                                              u_as_array=False)
        
        u_hist.loc[k*mpc.dt, "model"] = sol[ekf.dae.z].iloc[0].values[0]
        u_hist.loc[k*mpc.dt, "actual"] = y_meas["Prad"]
        #y_hist.loc[mpc.dt*k] = [y_meas[name] for name in ekf.y]   
        # input z as from model prediction:
        z_model = sol[ekf.dae.z].iloc[0].values
        u_model = sol[ekf.dae.u].iloc[0].values
        r_pred = data[ekf.dae.r_names].iloc[0].values
        # TODO: check if constraint active 
        y_z_meas = [y_meas[name] for name in ekf.y]
        x0 = ekf.estimate(
                          x0, 
                          z=z_model,
                          y=y_z_meas, 
                          u=u_model, 
                          r=r_pred
                          )
        

    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Prad")
    fig.tight_layout()
    plt.show()
    res = boptest.get_data(tf=K*boptest.h)
    print(res)   
    # look at CO2-concentration

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