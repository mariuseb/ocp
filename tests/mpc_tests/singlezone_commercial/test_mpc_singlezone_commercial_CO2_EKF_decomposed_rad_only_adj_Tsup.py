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
from pprint import pprint

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    #mpc_cfg = os.path.join("mpc_configs", "3R2C_MPC_CO2_ext.json")
    #mpc_cfg = os.path.join("mpc_configs", "6R4C_MPC_ENV_no_CO2.json")
    mpc_env_cfg = os.path.join("mpc_configs", "3R2C_MPC_simpler_no_alg.json")
    mpc_hvac_cfg = os.path.join("mpc_configs", "HVAC_MPC_no_CO2_adj_Tsup.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "6R5C_EKF_ENV_no_CO2_adj_adj.json")
    #ekf_env_cfg = os.path.join("ekf_configs", "3R2C_simpler_EKF.json")
    #ekf_hvac_cfg = os.path.join("ekf_configs", "3R2C_HVAC_simpler_EKF_adj.json")
    
    #params_hvac = pd.read_csv("HVAC_model_latest.csv", index_col=0)
    params_hvac = pd.read_csv("HVAC_DAE_model_latest_Tsup_Tret_5min.csv", index_col=0)
    #params_env = pd.read_csv("envelope_model_latest.csv", index_col=0)
    #params_env = pd.read_csv("envelope_model_latest_6R4C.csv", index_col=0)
    params_env = pd.read_csv("envelope_model_latest_6R5C.csv", index_col=0)
    params_CO2 = pd.read_csv("CO2_model.csv", index_col=0)
    params_CO2.rename(index={"c": "c1"}, inplace=True)
    #params = pd.concat([params_env, params_hvac, params_CO2])
    params = pd.concat([params_hvac, params_env, params_CO2])
    _params = params[~params.index.duplicated(keep='first')]
    #params = params.values.flatten()
    #params_env = params_env.values.flatten()
    _params.loc["Prad_to_env_lim"] = 1E6
    _params.loc["Trad_lim"] = 293.15
    params = _params.to_dict()["0"]
    #params["Ci"] /= 1.5
    params = {k: {"init": v} for k, v in params.items()}

    kwargs = {
        "x_nom": [12,12],
        "x_nom_b": [289.15,289.15],
        "r_nom": [12,300,1E6,1E6,1E6],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [1E6],
        "u_nom_b ": [0],
        "z_nom": [12],
        "z_nom_b ": [289.15],
        #"p_nom" : np.array([1.e-04, 1.e-02, 1.e-04, 1.e-04, 1.e+01, 1.e-01, 1.e-01, 1.e+08,
        # 1.e+09, 1.e+07, 1.e+06, 1.e+06, 1.e+02, 1.e+04, 1.e+03, 1.e+00,
        #1.e+00, 1.e+01, 1.e+06, 12]),
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        #"slack": True
        "slack": True
    }
    
    #kwargs["p_nom_b"] = len(kwargs["p_nom"])*[0]
    #kwargs["p_nom_b"][-1] += 289.15

    mpc_env = mpc = MPC(
                        config=mpc_env_cfg,
                        functions=deepcopy(functions),
                        #param_guess=params_env, 
                        param_guess=params, 
                        **deepcopy(kwargs)
                        )  # to remove, replace with N
    kwargs = {
        "x_nom": [12,12,12],
        "x_nom_b": [289.15,289.15,289.15],
        "z_nom": [1E6,10,1E6],
        "z_nom_b": [0]*3,
        "r_nom": [12,300,1E6,1E6,1E6,1,1E6,12,12],
        "r_nom_b": [289.15,0,0,0,0,0,0,289.15,289.15],
        "u_nom": [1],
        "u_nom_b ": [0],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        #"slack": True
        "slack": True
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
    ekf = KalmanDAE(ekf_cfg,
                        functions=deepcopy(functions)
                        )
    # set params:
    R = ca.DM.eye(ekf.dae.n_y)
    Q = ca.DM.eye(ekf.n_x)*1E0
    ekf.set_params(params)
    ekf.set_R(R)
    ekf.set_Q(Q)
    
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
                    ["Ti", "Te"],
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day,
                    day_begin=8,
                    day_end=16
                    )
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0_env = np.array([293.15,293.15])
    #x0_hvac = np.array([293.15,293.15,293.15,420])
    x0_hvac = np.array([293.15,293.15,330.15])
    
    # sim horizon: 2 days
    days = 5
    K = int(days*24*bounds.t_h)
    time = pd.DataFrame(columns=["time"])

    """
    Keep history:
    """
    z_model = pd.DataFrame(columns=mpc.u_names + mpc_hvac.z_names)
    x_model = pd.DataFrame(columns=mpc.x_names + mpc_hvac.x_names)
    
    x_model.loc[0, mpc.x_names] = x0_env
    x_model.loc[0, mpc_hvac.x_names] = x0_hvac

    """
    Get parameters for the separated MPC problems:
    """
    params_env = mpc_env.p0
    params_hvac = mpc_hvac.p0
    params_ekf = _params.loc[ekf.dae.p].values
    z_model_from_whole = pd.read_csv("Prad_to_env.csv", index_col=0)

    #z_model_from_whole.index = np.arange(0,K*mpc_env.dt,mpc_env.dt)
    #Prad_to_env = 0
    params_env[-2] = 0
    for k in range(K):
        
        """
        Set estimated Trad as constraint in envelope problem:
        """
        params_env[-1] = x0_hvac[0]
        
        lbx_env, ubx_env, _ = bounds.get_bounds(k, mpc.N)
        #lbx[3:-1:4] = 290
        #ubx[3:-1:4] = 325
        #sol = pd.read_csv("whole_first.csv", index_col=0)
        sol_env, u_env, x0_env = mpc_env.solve(
                                    data[0:mpc.N],
                                    x0=x0_env,
                                    lbx=lbx_env,
                                    ubx=ubx_env,
                                    params=params_env,
                                    codegen=False
                                    ) 
        """
        Set Ti, Prad_to_env
        """
        data["Ti"] = 0
        data["Prad_to_env_MPC"] = 0
        data["Trad_MPC"] = 0
        data.loc[:(mpc.N-1)*mpc.dt, "Ti"] = sol_env.Ti.astype(float).values
        data.loc[:(mpc.N-1)*mpc.dt,"Prad_to_env_MPC"] = sol_env.Prad_to_env.astype(float).values
        #data.loc[:(mpc.N-1)*mpc.dt,"Trad_MPC"] = sol_env.Trad.astype(float).values
        #data.loc[:(mpc.N-1)*mpc.dt,"Prad_to_env_MPC"] = z_model_from_whole.loc[k*mpc_env.dt:(k+mpc_env.N)*mpc_env.dt,"Prad_to_env"]
        lbx_hvac, ubx_hvac, _ = bounds.get_bounds(k, mpc_hvac.N)
        # change CO2-constraints:        
        lbx_hvac = np.array([280,280,280]*(mpc_hvac.N-1))
        ubx_hvac = np.array([340,340,340]*(mpc_hvac.N-1))
        #lbx_hvac[3:-1:4] = 300
        #ubx_hvac[3:-1:4] = 800
        sol_hvac, u_hvac, x0_hvac = mpc_hvac.solve(
                                                    data[0:mpc_hvac.N],
                                                    x0=x0_hvac,
                                                    lbx=lbx_hvac,
                                                    ubx=ubx_hvac,
                                                    params=params_hvac,
                                                    codegen=False
                                                    )
        # store results:
        #sol["Trad_decomp"] = sol_hvac["Trad"]
        #sol["Tret_decomp"] = sol_hvac["Tret"]
        #sol["Ti_decomp"] = sol_env["Ti"]
        #params_env[-2] = sol_hvac["Prad_to_env"][1]
        z_model.loc[k, mpc.u_names] = sol_env.loc[0, mpc.u_names]
        z_model.loc[k, mpc_hvac.z_names] = sol_hvac.loc[0, mpc_hvac.z_names]
        x_model.loc[k+1, mpc.x_names] = sol_env.loc[1, mpc.x_names]
        x_model.loc[k+1, mpc_hvac.x_names] = sol_hvac.loc[1, mpc_hvac.x_names]
        
        if mpc.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol_env)
        if mpc_hvac.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol_hvac)
        
        time.loc[k] = mpc.solver.stats()["t_wall_total"]
        u_hvac["ahu_pump_sup"] = 0.03
        u_hvac["ahu_pump_ret"] = 0.03
        
        """
        Get current disturbances before advancing:
        """
        r_pred = data[ekf.dae.r_names].iloc[0].values
        """
        Advance:
        """
        data, y_meas, u_meas = boptest.evolve(u=u_hvac,
                                              y_as_array=False,
                                              u_as_array=False)
        #data.loc[0, "Prad_to_env_MPC"] = z_model_from_whole.loc[k+1, "Prad_to_env"]
        #data.loc[0, "Prad_to_env_MPC"] = sol_hvac.loc[k+1, "Prad_to_env"]
        
        if u_hvac["rad_val"] > 1e-3:
            print(y_meas)
            
        if k == 30:
            print("yes")
        if k == 31:
            print("yes")
        """
        Envelope filter:
        """
        x0 = np.concatenate([x0_env, x0_hvac])
        u_model = sol_hvac[ekf.dae.u].iloc[0].values
        u_model[1] = y_meas["Prad"]
        u_model[2] = y_meas["rad_flo"]
        y_z_meas = [y_meas[name] for name in ekf.y]
        x0, _, _ = ekf.estimate(
                                x0, 
                                #z=sol_env.loc[0, mpc.z_names].values,
                                p=params_ekf,
                                y=y_z_meas, 
                                u=u_model, 
                                r=r_pred
                                )  
        x0_env, x0_hvac = x0[:2], x0[2:]
        
    """
    Comparison z model and measured:
    """
    z_model["from_whole_to_env"] = z_model_from_whole.Prad_to_env
    z_model["from_whole_Prad"] = z_model_from_whole.Prad
    z_model = z_model.loc[:,~z_model.columns.duplicated()].copy()
    #res = boptest.get_data(tf=K*boptest.h)
    #Prad = res.Prad.shift(-1)
    #Prad = Prad.iloc[:-1]
    #z_model.index = Prad.index
    #ax = z_model.Prad.plot(color="r", linewidth=0.75, drawstyle="steps-post")
    #Prad.plot(color="k", linewidth=0.75, drawstyle="steps-post")
    #plt.show()
    fig, axes = plt.subplots(4,4, sharex=False)
    res = boptest.get_data(tf=K*boptest.h)
    res["Pvent"] -= res["Prad"]
    res = res.shift(-1)
    res = res.iloc[:-1]
    z_model.index = res.index
    
    mpc = mpc_hvac
    #mpc = mpc_env
    
    for name, ax in zip(mpc.z_names, axes.flatten()):
        try:
            z_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        ax.set_xticklabels([])
    #fig.tight_layout()
    plt.show()
    
    fig, axes = plt.subplots(3,2, sharex=False)
    res = boptest.get_data(tf=K*boptest.h)
    #res = res.iloc[:-1]
    x_model = x_model
    x_model.index = res.index
    x_names = mpc_env.x_names + mpc_hvac.x_names
    for name, ax in zip(x_names, axes.flatten()):
        try:
            x_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        ax.set_xticklabels([])
    #fig.tight_layout()
    plt.show()
        
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Prad")
    fig.tight_layout()
    plt.show()
    print(res)