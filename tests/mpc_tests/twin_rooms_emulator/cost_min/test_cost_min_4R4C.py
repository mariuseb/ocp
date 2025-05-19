#from ast import Param
from ocp.mpc import MPC
import numpy as np
#import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api_old import Boptest
#from pprint import pprint
from ocp.filters import KalmanDAE
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from copy import deepcopy
from ocp.functions import functions
#from pprint import pprint
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    # config:
    mpc_cfg = os.path.join("mpc_configs", "4R4C_MPC_cost.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "4R4C_EKF_1meas.json")
    params_hvac = pd.read_csv("hvac_model_PRBS.csv", index_col=0)
    params_env = pd.read_csv("envelope_model_alt_rad_first.csv", index_col=0)
    #params_env.loc["Ai"] = 1
    params = pd.concat([params_hvac, params_env])
    params = params[~params.index.duplicated(keep='first')]
    params = params.to_dict()["0"]
    params_dict = {k: {"init": v} for k, v in params.items()}

    kwargs = {
        "x_nom": [12,12,12,12],
        "x_nom_b": [289.15,289.15,289.15,289.15],
        "z_nom": [1,12,1E4,1E4],
        "z_nom_b": [0,289.15,0,0],
        "r_nom": [12,1E4],
        "r_nom_b": [289.15,0],
        "u_nom": [1],
        "u_nom_b ": [0],
        "slack": True
    }
    """
    kwargs = {
        "slack": False
    }
    """

    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params_dict, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    ekf = KalmanDAE(ekf_cfg,
                     functions=deepcopy(functions)
                     )
    # set params:
    R = ca.DM.eye(ekf.n_y)
    Q = ca.DM.eye(mpc.n_x)
    ekf.set_params(params)
    ekf.set_R(R)
    ekf.set_Q(Q)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="twin_rooms_emulator"
                      )
    # first forecast:
    data = boptest.get_forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 294.15}
    ub_day = {"Ti": 301.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day,
                    day_begin=8,
                    day_end=16
                    )
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = _x0 = np.array([293.15,293.15,293.15,293.15])
    
    # sim horizon: 2 days
    days = 2
    K = int(days*24*bounds.t_h)
    time = pd.DataFrame(columns=["time"])

    z_model = pd.DataFrame(columns=mpc.z_names)
    x_model = pd.DataFrame(columns=mpc.x_names)
    x_model.loc[0, mpc.x_names] = x0
    
    params = mpc.p0
    
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
        # preview:
        """
        lb_Ti = lbx[::4]
        lb_Ti = np.append(_x0[0], lb_Ti)
        sol["Ti_lb"] = lb_Ti
        ax = sol[["Ti_lb", "Trad"]].plot(drawstyle="steps-post")
        sol[["Ti"]].plot(ax=ax, drawstyle="steps-post", linestyle="dashed")
        ax1 = ax.twinx()
        #sol[["Prad", "Prad_to_env", "P_to_rad"]].plot(ax=ax1, color=["k","r","m"], drawstyle="steps-post")
        sol["rad_219"].plot(ax=ax1, color=["k","r","m"], drawstyle="steps-post")
        (sol["Prad"]/5000).plot(ax=ax1, color=["r","m"], drawstyle="steps-post")
        #ax1.legend(loc="upper right")
        ax.legend(loc="upper left")
        plt.show()
        """
        
        # store results:
        z_model.loc[k, mpc.z_names] = sol.loc[0, mpc.z_names]
        x_model.loc[k+1, mpc.x_names] = sol.loc[1, mpc.x_names]
        
        if mpc.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol)
        
        time.loc[k] = mpc.solver.stats()["t_wall_total"]
        #u["fan_219"] = 0.1
        #u["fan_ret_219"] = 0.1
        """
        Store r_pred before advancing:
        """
        r_pred = data[ekf.dae.r_names].iloc[0].values
        data, y_meas, u_meas = boptest.evolve(u=u,
                                              y_as_array=False,
                                              u_as_array=False)
        
        if u["rad_219"] > 1e-3:
            print(y_meas)
        
        # same:
        y_meas["Trad"] = y_meas["Tret"]
        """
        Concatenate z, u
        """ 
        u_model = sol[ekf.dae.u].iloc[0].values
        #u_model[1] = y_meas["Prad"]
        #u_model[2] = y_meas["rad_flo"]
        # TODO: check if constraint active 
        y_z_meas = [y_meas[name] for name in ekf.y]
        x0, z, y = ekf.estimate(
                                x0, 
                                #z=sol.loc[0, mpc.z_names].values,
                                p=params,
                                y=y_z_meas, 
                                u=u_model, 
                                r=r_pred
                                )
    """
    Comparison z model and measured:
    """
    fig, axes = plt.subplots(4,1, sharex=False)
    res = boptest.get_data(tf=K*boptest.h)
    #res = res.shift(-1)
    res.index = pd.to_timedelta(res.index, unit="s")
    #res = res.iloc[:-1]
    z_model.index = res.index
    
    for name, ax in zip(mpc.z_names, axes.flatten()):
        try:
            z_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        #ax.set_xticklabels([])
    plt.show()
    
    fig, axes = plt.subplots(4,1, sharex=False)
    res = boptest.get_data(tf=K*boptest.h)
    res.index = pd.to_timedelta(res.index, unit="s")
    #res = res.iloc[:-2]
    #res = res.iloc[:-1]
    _x_model = x_model[:-1].copy()
    res["Trad"] = res["Tret"]
    _x_model.index = res.index
    
    for name, ax in zip(mpc.x_names, axes.flatten()):
        try:
            _x_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        #ax.set_xticklabels([])
    ax = axes[0]
    #_x_model["Trad"].plot(ax=ax, color="g", linewidth=0.75, drawstyle="steps-post")
    #ax1 = ax.twinx()
    #z_model["Prad"].plot(ax=ax1, drawstyle="steps-post", color="g")
    #_x_model["Ti"].plot(ax=ax, drawstyle="steps-post", color="m")
    plt.show()
     
    res.to_csv("boptest_results_MPC_EKF_N=%s.csv" %
               (str(mpc.N, )))
    x_model.to_csv("model_predictions_MPC_EKF_N=%s.csv" %
               (str(mpc.N, )))
        
        
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Prad")
    fig.tight_layout()
    plt.show()
    print(res)