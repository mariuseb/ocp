#from ast import Param
from ocp.mpc import MPC
from ocp.mhe import MHE
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
from pprint import pprint
from datetime import datetime

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mhe_cfg = os.path.join("mhe_configs", "4R3C.json")
    mpc_env_cfg = os.path.join("mpc_configs", "3R3C_MPC_simpler_simpler.json")
    mpc_hvac_cfg = os.path.join("mpc_configs", "HVAC_MPC_300s_3R3C_env.json")
    #mpc_hvac_cfg = os.path.join("mpc_configs", "HVAC_MPC_3C_simpler_300s_ref_tracking.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_env_cfg = os.path.join("ekf_configs", "4R4C_one_level_EKF.json")
    ekf_hvac_cfg = os.path.join("ekf_configs", "3R3C_HVAC_simpler_EKF.json")
    
    #params_hvac = pd.read_csv("HVAC_model_latest.csv", index_col=0)
    params_hvac = pd.read_csv("HVAC_DAE_model_latest_Trad_Tret_1min.csv", index_col=0)
    #params_hvac = pd.read_csv("HVAC_DAE_model_latest_Tsup_Tret_1min.csv", index_col=0)
    #params_env = pd.read_csv("envelope_model_latest_4R3C.csv", index_col=0)
    params_env = pd.read_csv("envelope_model_latest_4R3C_rad_flo_shifted_5min.csv", index_col=0)
    #params_env = pd.read_csv("envelope_model_latest_4R3C_rad_flo_non_shifted_5min.csv", index_col=0)
    params = pd.concat([params_hvac, params_env])
    params = params[~params.index.duplicated(keep='first')]
    _params = params.copy()
    params = params.to_dict()["0"]
    params = {k: {"init": v} for k, v in params.items()}
    # to get the scale right:
    params["Prad_to_env_MPC"] = {
        "init": 1E6
    }
    
    kwargs = {
        "slack": True
        }
    
    mhe_env = mhe = MHE(config=mhe_cfg,
                    functions=deepcopy(functions),
                    param_guess=params, 
                    arrival_cost=False,
                    **deepcopy(kwargs))
    
    kwargs = {
        "x_nom": [12,12,12],
        "x_nom_b": [289.15,289.15,289.15],
        #"z_nom": [1E6,1E6],
        #"z_nom_b ": [0,0],
        "r_nom": [12,300,1E6,1E6,1E6],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [1E6],
        "u_nom_b ": [0],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        "slack": True
        #"slack": False
    }

    mpc_env = MPC(
                config=mpc_env_cfg,
                functions=deepcopy(functions),
                #param_guess=params_env, 
                param_guess=params, 
                **deepcopy(kwargs)
                )  # to remove, replace with N
    
    kwargs = {
        "x_nom": [12]*2 ,
        "x_nom_b": [289.15]*2,
        "z_nom": [1E6,1,1E6,1E6],
        "z_nom_b": [0]*4,
        "r_nom": [12,300,1E6,1E6,1E6,1,12,1E6],
        "r_nom_b": [289.15,0,0,0,0,0,289.15,0],
        "u_nom": [1],
        "u_nom_b ": [0],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        "slack": True
        #"slack": False
    }
    mpc_hvac = MPC(
                   config=mpc_hvac_cfg,
                   functions=deepcopy(functions),
                   param_guess=params, 
                   **deepcopy(kwargs)
                    )  # to remove, replace with N
    """
    EKF for envelope problem:
    """
    ekf_env = KalmanDAE(ekf_env_cfg,
                        functions=deepcopy(functions)
                        )
    # set params:
    R = ca.DM.eye(ekf_env.dae.n_y)
    Q = ca.DM.eye(mpc_env.n_x + 1)
    ekf_env.set_params(params)
    ekf_env.set_R(R)
    ekf_env.set_Q(Q)
   
    boptest = Boptest(
                      boptest_cfg,
                      name="singlezone_commercial"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc_env.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 301.15}
    
    
    bounds_env = Bounds(mpc_env.dt,
                    ["Ti","Te","Trad"],
                    ekf_env.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day,
                    day_begin=8,
                    day_end=16
                    )
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    #x0 = np.array([293.15]*4)
    x0_env = np.array([293.15]*3)
    #x0_hvac = np.array([293.15,293.15,293.15,420])
    
    sol = pd.read_csv("HVAC_DAE_sol_latest_Tret_1min.csv", index_col=0)
    #x0_hvac = sol.loc[0, ["Trad", "Tret", "Tsup"]].values
    #x0_hvac = np.array([306,309,330.15])
    x0_hvac = np.array([293.15]*2)
    x0 = np.concatenate([x0_env, [x0_hvac[-1]]])
    # sim horizon: 2 days
    days = 2
    K = int(days*24*4*3)
    #K = int(12)
    time = pd.DataFrame(columns=["time"])

    """
    Keep history:
    """
    z_model = pd.DataFrame(columns=mpc_hvac.z_names)
    x_model = pd.DataFrame(columns=mpc_env.x_names + mpc_hvac.x_names)
    u_hist = pd.DataFrame(columns=["whole", "decomp"])
    Trad_hist = pd.DataFrame(columns=["whole", "decomp"])
    
    x_model.loc[0, mpc_env.x_names] = x0_env
    x_model.loc[0, mpc_hvac.x_names] = x0_hvac

    """
    Get parameters for the separated MPC problems:
    """
    params_env = mpc_env.p0
    #params_hvac = mpc_hvac.p0
    MHE_start = mhe.N - 1
    
    ekf_env.df.loc[0] = x0
    _params.loc["Prad_to_env_MPC"] = 1E6
    _params = _params.loc[mpc_env.dae.p]
    
    for k in range(K):
        """
        Run decomposed problem:
        """
        lbx_env, ubx_env, _ = bounds_env.get_bounds(k, mpc_env.N)
        #lbx_env, ubx_env, _ = bounds.get_bounds(k, mpc.N)
        #lbx_env = np.array([280,280,280]*(mpc_env.N-1))
        #ubx_env = np.array([340,340,330]*(mpc_env.N-1))
        sol_env, u_env, x0_env = mpc_env.solve(
                                    data[0:mpc_env.N],
                                    x0=x0_env,
                                    lbx=lbx_env,
                                    ubx=ubx_env,
                                    params=params_env,
                                    codegen=False
                                    ) 
        sol_env.index = data.index[0:len(sol_env)]
        if mpc_env.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol_env)
        """
        Get and set data:
        """
        data_hvac = data[0:mpc_hvac.N]
        data_hvac["Ti"] = sol_env["Ti"].iloc[0:mpc_hvac.N]
        data_hvac["P_to_rad_ideal"] = sol_env["P_to_rad"].iloc[0:mpc_hvac.N]
        params_hvac[-1] = sol_env.Prad_to_env.iloc[0].astype(float)
        lbx_hvac = np.array([280,280]*(mpc_hvac.N-1))
        ubx_hvac = np.array([340,340]*(mpc_hvac.N-1))

        if sol_env.Prad_to_env[0].astype(float) > 20000:
            print("yes")

        sol_hvac, u_hvac, x0_hvac = mpc_hvac.solve(
                                                    data_hvac,
                                                    x0=x0_hvac,
                                                    lbx=lbx_hvac,
                                                    ubx=ubx_hvac,
                                                    params=params_env,
                                                    codegen=False
                                                    )
        sol_hvac.index = data.index[0:len(sol_hvac)]
        u_hist.loc[k, "decomp"] = float(u_hvac)
        
        if mpc_hvac.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol_hvac)
        
        """
        Store model predictions:
        """
        
        x_model.loc[k+1, mpc_env.x_names] = sol_env.iloc[1][mpc_env.x_names]
        x_model.loc[k+1, mpc_hvac.x_names] = sol_hvac.iloc[1][mpc_hvac.x_names]
        z_model.loc[k, mpc_hvac.z_names] = sol_hvac.iloc[0][mpc_hvac.z_names]
        #sol.index = np.arange(0, mpc.N*mpc.dt, mpc.dt)
        r_pred_env = data[ekf_env.dae.r_names].iloc[0].values
        """
        Advance:
        """
        u_hvac["ahu_pump_sup"] = 0.03
        u_hvac["ahu_psump_ret"] = 0.03
        data, y_meas, u_meas = boptest.evolve(u=u_hvac,
                        y_as_array=False,
                        u_as_array=False)
        
        """
        Estimate state:
        """
        u_model = sol_hvac[ekf_env.dae.u].iloc[0].values
        y_z_meas = [y_meas[name] for name in ekf_env.y]
        x0 = np.concatenate([x0_env, [x0_hvac[-1]]])
        """
        Potential error: Trad_ENV - Trad_HVAC != 0
        """
        x0, _, _ = ekf_env.estimate(
                                    x0, 
                                    #z=sol_env.loc[0, mpc.z_names].values,
                                    p=params_env,
                                    y=y_z_meas, 
                                    u=u_model, 
                                    r=r_pred_env
                                    )
        x0_env, x0_hvac = x0[0:3], x0[2:4]
        
        if k == MHE_start:
            # get labelled data:
            stop_time = (k+1)*boptest.h
            start_time = stop_time - (mhe.N - 1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data[["rad_flo", "Prad"]] = y_data[["rad_flo", "Prad"]].shift(-1) 
            y_data["y1"] = y_data.Ti
            #y_data["P_to_rad"] = z_model.P_to_rad_act.shift(-1).values
            y_data = y_data.fillna(0)
            y_data = y_data.loc[:,~y_data.columns.duplicated()].copy()
            
            x_guess = ekf_env.df[["Ti", "Te", "Trad"]][1:].values
                      
            P0 = ca.DM.eye(4)
            
            params_lb = 1*params_env
            params_ub = 1*params_env
            
            env_params = ["Rie", "Rea", "Ria", "Ci", "Ce", "Ai"]
            locs = []
            for name in env_params:
                locs.append(_params.index.get_loc(name))
            params_lb[locs] *= 0.1
            params_ub[locs] *= 10
        
            params_init = params_env  # keep
            sol_mhe, params_re = mhe.solve(
                    y_data,
                    params_env,
                    lbp=params_lb,
                    ubp=params_ub,
                    x_guess=x_guess,
                    #lbx=x_guess,
                    #ubx=x_guess,
                    covar=ca.veccat(Q, R),
                    P0=P0,
                    #x_N=x_N,
                    #z_N=z_N,
                    arrival_cost=False,
                    codegen=False
                )     
            params_env = params_re.values             
            #x0 = sol_mhe.iloc[-1][mhe.x_names].values
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
                    
    """
    Comparison z model and measured:
    """
    z_model_comp = z_model.copy()
    x_model_comp = x_model.copy()
    
    #z_model = z_model[:-1]
    
    fig, axes = plt.subplots(2,2, sharex=False)
    res = boptest.get_data(tf=K*boptest.h)
    res["Pvent"] -= res["Prad"]
    res.Prad_to_env = -res.Prad_to_env
    res = res.shift(-1)
    res = res.iloc[:-1]
    #res["P_to_rad_act"] = res["Prad"]
    #mpc = mpc_hvac
    z_names = mpc_hvac.z_names
    z_model.index = res.index
    
    for name, ax in zip(z_names, axes.flatten()):
        try:
            z_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        ax.set_xticklabels([])
        ax.legend()
    #fig.tight_layout()
    plt.show()
    
    ax = z_model["Prad"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
    z_model["P_to_rad_act"].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
    plt.show()
    
    #x_model = x_model[:-1]
    
    x_names = mpc_env.x_names + mpc_hvac.x_names
    
    fig, axes = plt.subplots(3,2, sharex=True)
    res = boptest.get_data(tf=K*boptest.h)
    #res = res.iloc[:-1]
    #x_model = x_model[:-1]
    #res_x = res[::3]
    res_x = res
    #res_x = res_x.iloc[:-1]
    x_model.index = res_x.index
    
    for name, ax in zip(x_names, axes.flatten()):
        try:
            x_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res_x[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        ax.set_xticklabels([])
    #fig.tight_layout()
    plt.show()
    
    #z_model_comp = z_model.copy()
    z_model_comp = z_model_comp.iloc[:-1]
    
    index = pd.Index(datetime(2020, 1, 1) + z_model_comp.index * pd.offsets.Second())
    z_model_comp.index = index
    
    res = boptest.get_data(tf=K*boptest.h)
    #res = res.iloc[:-1]
    res.Prad_to_env = -res.Prad_to_env
    res.index = z_model_comp.index
    z_model_comp["Prad_to_env_true"] = res.Prad_to_env
    
        
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds_env, heat_key="Prad")
    fig.tight_layout()
    plt.show()
    print(res)