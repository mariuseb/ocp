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
    
    mpc_cfg = os.path.join("mpc_configs", "4R2C_MPC_inf_pump.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "4R2C_EKF_inf_pump.json")

    # pass in config?
    """
    Rie       4.537097e-05
    Rea       1.350598e-03
    Ria       3.155923e-04
    Ci        6.664602e+07
    Ce        3.017397e+09
    Ai        2.025661e+02
    n         1.439245e+00
    UA_nom    1.395614e+03
    eta       8.635318e-01
    delta     5.000000e-02
    
    Rie        4.448056e-05
    Rea        3.808951e-04
    Ria        6.425573e-04
    Tsup       3.400000e+02
    rho_int    3.807622e-01
    Ci         8.097878e+07
    Ce         2.895566e+09
    Ai         1.733774e+02
    n          1.430411e+00
    UA_nom     1.742356e+03
    eta        8.686290e-01
    
    params = ca.DM(
                   [
                4.079293e-05,
                2.628968e-04,
                1.370427e-03,
                3.400000e+02,
                3.569021e-01,
                7.902190e+07,
                3.266704e+09,
                1.821768e+02,
                1.068268e+00,
                6.288996e+03,
                8.703736e-01
                    ]
                   )
    """
    params = ca.DM(
                   [
                    3.913113e-05,
                    1.868912e-04,
                    6.666102e+07,
                    3.095777e+09,
                    2.125277e+02,
                    1.443879e+00,
                    1.384494e+03,
                    8.705821e-01
                    ]
                   )
    
    params = ca.DM(
                   [
                    3.567234e-05,
                    2.415617e-04,
                    1.000000e-03,
                    4.103551e-01,
                    9.087888e+07,
                    3.700653e+09,
                    2.085650e+02,
                    3.410576e+02,
                    1.092991e+00,
                    6.400912e+03,
                    1.000000e+00
                    ]
                   )
    
    
    kwargs = {
        "x_nom": 300,
        "z_nom": 5000,
        "u_nom": 300,
        "r_nom": 300,
        "p_nom": [1E-3,1E-3,1E6,1E7,1,1,10,1,300],
        "y_nom": 300,
        #"slack": Trues
        "slack": False
    }
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "z_nom": [300000],
        "z_nom_b": [0],
        "r_nom": 1,
        "y_nom": 1,
        #"slack": Trues
        "slack": True
    }
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "z_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        "p_nom": [1E-5,1E-4,1E-5,1E8,1E9,1E2,1,1E3,1,1],
        #"slack": Trues
        "slack": True
    }
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "z_nom": 1,
        "r_nom": 1,
        "slack": False
    }
    kwargs = {
        "x_nom": 300,
        "u_nom": [1],
        "z_nom": [1E6],
        "r_nom": [300,300,1E6,1E6,1E6],
        #"p_nom": [1E-5,1E-4,1E-5,1E8,1E9,1E2,1,1E3,1,1],
        #"p_nom_b": [0,0,0,0,0,0,0,0,289.15],
        #"slack": True
        "slack": False
    }
    
    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    
    ekf = KalmanBucy(ekf_cfg,
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
    x0 = np.array([293.15, 293.15])
    
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
        u["ahu_pump_sup"] = 0.03
        u["ahu_pump_ret"] = 0.03
        #u["ahu_Tsup"] = 288.15
        u["rad_val"] = 1
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