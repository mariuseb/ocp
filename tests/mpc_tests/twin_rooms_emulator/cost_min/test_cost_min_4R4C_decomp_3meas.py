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
import matplotlib as mpl
mpl.rcParams['lines.linewidth'] = 0.75
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    # config:
    mpc_env_cfg = os.path.join("mpc_configs", "2R2C_MPC_env_cost.json")
    mpc_rad_cfg = os.path.join("mpc_configs", "2R2C_MPC_rad_cost.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "4R4C_EKF_3meas.json")
    params_hvac = pd.read_csv("hvac_model_PRBS.csv", index_col=0)
    params_env = pd.read_csv("envelope_model_alt_rad_first.csv", index_col=0)
    params_all = pd.concat([params_hvac, params_env])
    params_all = params_all[~params_all.index.duplicated(keep='first')]
    params_all.loc["Prad_to_env_zero"] = 1E4
    params = params_all.to_dict()["0"]
    params_dict = {k: {"init": v} for k, v in params.items()}

    kwargs_env = {
        "x_nom": [12,12],
        "x_nom_b": [289.15,289.15],
        "r_nom": [12,1E4,1],
        "r_nom_b": [289.15,0,0],
        "u_nom": [1E4],
        "u_nom_b ": [0],
        "slack": True
    }
    kwargs_rad = {
        "x_nom": [12,12],
        "x_nom_b": [289.15,289.15],
        "z_nom": [1,12,1E4,1E4],
        "z_nom_b": [0,289.15,0,0],
        "r_nom": [12,1E4,1E4,12],
        "r_nom_b": [289.15,0,0,289.15],
        "u_nom": [1],
        "u_nom_b ": [0],
        "slack": True
    }
    """
    kwargs_env = {
        "slack": False
    }
    kwargs_rad = {
        "slack": True
    }
    """
    mpc_env = MPC(config=mpc_env_cfg,
              functions=deepcopy(functions),
              param_guess=params_dict, 
              **deepcopy(kwargs_env))  # to remove, replace with N
    
    mpc_rad = MPC(config=mpc_rad_cfg,
              functions=deepcopy(functions),
              param_guess=params_dict, 
              **deepcopy(kwargs_rad))  # to remove, replace with N
    
    ekf = KalmanDAE(ekf_cfg,
                     functions=deepcopy(functions)
                     )

    # set params:
    R = ca.DM.eye(ekf.n_y)
    Q = ca.DM.eye(ekf.n_x)
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
    N = mpc_env.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 294.15}
    ub_day = {"Ti": 301.15}
    
    bounds = Bounds(mpc_env.dt,
                    mpc_env.x(),
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day,
                    day_begin=8,
                    day_end=18
                    )
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0_env = np.array([293.15,293.15])
    x0_rad = np.array([293.15,293.15])
    x0 = np.append(x0_env, x0_rad)
    
    # sim horizon: 2 days
    days = 7
    K = int(days*24*bounds.t_h)
    time = pd.DataFrame(columns=["time"])

    z_model = pd.DataFrame(columns=mpc_env.z_names + mpc_rad.z_names)
    x_model = pd.DataFrame(columns=mpc_env.x_names + mpc_rad.x_names)
    x_model.loc[0] = x0
    
    params = mpc_env.p0
    
    for k in range(K):
        lbx, ubx, ref = bounds.get_bounds(k, mpc_env.N)
        
        """
        Calculate Prad_to_env_zero as: (Trad[0] - Ti[0]/Rirad)
        where states are from EKF.
        """
        Prad_to_env_zero = (x0_rad[0] - x0_env[0])/params_all.loc["Rirad"]
        params[-1] = Prad_to_env_zero
        sol_env, u_env, x0_env = mpc_env.solve(
            data[0:mpc_env.N],
            x0=x0_env,
            lbx=lbx,
            ubx=ubx,
            params=params,
            codegen=True
        )
        
        if k == 4:
            print(sol_env)
        # preview:
        """
        lb_Ti = lbx[::5]
        lb_Ti = np.append(_x0[0], lb_Ti)
        sol["Ti_lb"] = lb_Ti
        ax = sol[["Ti_lb", "Trad"]].plot(drawstyle="steps-post")
        sol[["Ti"]].plot(ax=ax, drawstyle="steps-post", linestyle="dashed")
        ax1 = ax.twinx()
        #sol[["Prad", "Prad_to_env", "P_to_rad"]].plot(ax=ax1, color=["k","r","m"], drawstyle="steps-post")
        sol["rad_219"].plot(ax=ax1, color=["k","r","m"], drawstyle="steps-post")
        #ax1.legend(loc="upper right")
        ax.legend(loc="upper left")
        plt.show()
        """
        
        # store results:
        z_model.loc[k, mpc_env.z_names] = sol_env.loc[0, mpc_env.z_names]
        x_model.loc[k+1, mpc_env.x_names] = sol_env.loc[1, mpc_env.x_names]
        
        if mpc_env.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol_env)
        
        data_rad = data[0:mpc_rad.N]
        #data_rad["Tsup_ENV"] = sol_env["Tsup"][0:mpc_rad.N].values
        #data_rad["Ti_ENV"] = sol_env["Ti"][0:mpc_rad.N].values
        
        ###### some heuristics ######:
        #sol_env["Prad_to_env"].loc[sol_env["Prad_to_env"] < 600] = 0
        # set Ti free when Prad_to_env is zero:
        #sol_env["Ti"].loc[sol_env["Prad_to_env"].round(-2) == 0] = np.nan
        ##############################
        data_rad["Prad_to_env_ENV"] = sol_env["Prad_to_env"][0:mpc_rad.N].values
        data_rad["Ti_ENV"] = sol_env["Ti"][0:mpc_rad.N].values
        lbx_rad = np.array([280,280]*(mpc_rad.N-1))
        ubx_rad = np.array([340,340]*(mpc_rad.N-1))
        sol_rad, u_rad, x0_rad = mpc_rad.solve(
            data_rad,
            x0=x0_rad,
            lbx=lbx_rad,
            ubx=ubx_rad,
            params=params,
            codegen=True
        ) 
        z_model.loc[k, mpc_rad.z_names] = sol_rad.loc[0, mpc_rad.z_names]
        x_model.loc[k+1, mpc_rad.x_names] = sol_rad.loc[1, mpc_rad.x_names]
        time.loc[k] = mpc_env.solver.stats()["t_wall_total"]
        """
        Store r_pred before advancing:
        """
        r_pred = data[ekf.dae.r_names].iloc[0].values
        data, y_meas, u_meas = boptest.evolve(u=u_rad,
                                              y_as_array=False,
                                              u_as_array=False)
        
        if u_rad["rad_219"] > 1e-3:
            print(y_meas)
        
        # same:
        y_meas["Trad"] = y_meas["Tret"]
        """
        Concatenate z, u
        """ 
        sol_cat = pd.merge(
            sol_env[0:mpc_rad.N],
            sol_rad,
            left_index=True, 
            right_index=True
        )
        # preview:
        
        """
        lb_Ti = lbx[::3]
        lb_Ti = np.append(x0[0], lb_Ti)
        sol_cat["Ti_lb"] = lb_Ti
        ax = sol_cat[["Ti_lb", "Trad"]].plot(drawstyle="steps-post")
        sol_cat[["Ti"]].plot(ax=ax, drawstyle="steps-post", linestyle="dashed")
        ax1 = ax.twinx()
        #sol[["Prad", "Prad_to_env", "P_to_rad"]].plot(ax=ax1, color=["k","r","m"], drawstyle="steps-post")
        sol_cat["rad_219"].plot(ax=ax1, color=["k","r","m"], drawstyle="steps-post")
        #ax1.legend(loc="upper right")
        ax.legend(loc="upper left")
        plt.show()
        """
        
        #sol_rad["Prad_to_env"] = sol_env["Prad_to_env"][0:mpc_rad.N]
        #sol_rad["P_to_rad"] = sol_env["P_to_rad"][0:mpc_rad.N]
        u_model = sol_rad[ekf.dae.u].iloc[0].values
        u_model[1] = y_meas["Prad"]
        #u_model[2] = y_meas["rad_flo"]
        # TODO: check if constraint active 
        y_z_meas = [y_meas[name] for name in ekf.y]
        x0 = np.append(x0_env, x0_rad)
        x0, z, y = ekf.estimate(
                                x0, 
                                #z=sol.loc[0, mpc.z_names].values,
                                p=params,
                                y=y_z_meas, 
                                u=u_model, 
                                r=r_pred
                                )
        # Trad_zero 
        #params[-1] = x0_rad[2]
        x0_env, x0_rad = x0[:2], x0[2:4]
    """
    Comparison z model and measured:
    """
    
    fig, axes = plt.subplots(4,1, sharex=False)
    res = boptest.get_data(tf=K*boptest.h)
    #res = res.shift(-1)
    res.index = pd.to_timedelta(res.index, unit="s")
    #res = res.iloc[:-1]
    z_model.index = res.index
    
    z_names = mpc_env.z_names + mpc_rad.z_names
    
    for name, ax in zip(z_names, axes.flatten()):
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
    
    x_names = mpc_env.x_names + mpc_rad.x_names
    
    for name, ax in zip(x_names, axes.flatten()):
        try:
            _x_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        #ax.set_xticklabels([])
    ax1 = axes[0].twinx()
    z_model["Prad"].plot(ax=ax1, drawstyle="steps-post", color="g")
    res["Prad"].plot(ax=ax1, drawstyle="steps-post", color="m")
    #_x_model["Ti"].plot(ax=ax, drawstyle="steps-post", color="m")
    plt.show()
     
    """
    res.to_csv("boptest_results_MPC_EKF_N=%s.csv" %
               (str(mpc.N, )))
    x_model.to_csv("model_predictions_MPC_EKF_N=%s.csv" %
               (str(mpc.N, )))
    """
        
        
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Prad")
    #ax1 = axes[0].twinx()
    #res.cost.plot(ax=ax1)
    fig.tight_layout()
    plt.show()
    print(res)