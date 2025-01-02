#from ast import Param
from ocp.mpc import MPC
from ocp.mhe import MHE
from ocp.estimation import Estimation
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import KalmanDAE
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
    
    mpc_env_cfg = os.path.join("mpc_configs", "3R3C_MPC_min_energy_900s.json")
    #mpc_hvac_cfg = os.path.join("mpc_configs", "HVAC_MPC_si#mpler_300s.json")
    mpc_hvac_cfg = os.path.join("mpc_configs", "HVAC_MPC_simpler_900s_min_energy.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_env_cfg = os.path.join("ekf_configs", "3R3C_simpler_simpler_EKF.json")
    mhe_cfg = os.path.join("mhe_configs", "3R3C_MHE_900s.json")
    #ekf_hvac_cfg = os.path.join("ekf_configs", "3R3C_HVAC_EKF.json")
    
    #params_hvac = pd.read_csv("HVAC_model_latest.csv", index_col=0)
    params_hvac = pd.read_csv("HVAC_DAE_model_latest_Trad_Tret_1min.csv", index_col=0)
    #params_hvac = pd.read_csv("HVAC_DAE_model_latest_Tsup_Tret_1min.csv", index_col=0)
    params_env = pd.read_csv("envelope_model_latest_4R3C.csv", index_col=0)
    params = pd.concat([params_hvac, params_env])
    params = params[~params.index.duplicated(keep='first')]
    params = params.to_dict()["0"]
    params = {k: {"init": v} for k, v in params.items()}
    # to get the scale right:
    params["P_to_rad_MPC_1"] = {
        "init": 1E6
    }
    params["P_to_rad_MPC_2"] = {
        "init": 1E6
    }
    
    A = 8500
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ai": 0.15*A, # m²
        "rho_int": 1E-1,
    }
    """
    for name, value in priors.items():
        if name not in ("a", "b", "c"):
            param_guess[name]["init"] = value 
            param_guess[name]["lb"] = value*1E-3 
            param_guess[name]["ub"] = value*1E3 
        else:
            param_guess[name]["init"] = value 
            param_guess[name]["lb"] = value 
            param_guess[name]["ub"] = value 
    """
    for name, value in priors.items():
        params[name]["init"] = value 
        #params[name]["lb"] = value*1E-3 
        #params[name]["ub"] = value*1E3 

    kwargs = {
        "x_nom": [12,12,12],
        "x_nom_b": [289.15,289.15,289.15],
        "z_nom": [1E6,1E6],
        "z_nom_b": [0,0],
        "r_nom": [12,300,1E6,1E6,1E6],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [1],
        "u_nom_b": [0],
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        "slack": True
        #"slack": False
    }

    mpc_env = mpc = MPC(
                        config=mpc_env_cfg,
                        functions=deepcopy(functions),
                        #param_guess=params_env, 
                        truncate_scaling=True,
                        param_guess=params, 
                        **deepcopy(kwargs)
                        )  # to remove, replace with N
    
    
    kwargs["p_nom"] = mpc_env.p_nom
    kwargs.pop("z_nom")
    kwargs.pop("z_nom_b")
    kwargs["z_nom"] = 1
    kwargs["z_nom_b"] = 0
    kwargs["slack"] = False
    
    """ 
    EKF for envelope problem:
    kwargs = {
        "slack": True,
        "p_nom": mpc.p_nom
    }
    kwargs = {
        "x_nom": 1,
        "x_nom_b": 0,
        "z_nom": 1,
        "z_nom_b": 0,
        "r_nom": 1,
        "r_nom_b": 0,
        "u_nom": 1,
        "u_nom_b": 0,
        "y_nom": 1,
        "y_nom_b": 0,
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        "slack": False,
        "p_nom": mpc_env.p_nom
    }
    """
    P0x = np.eye(mpc.n_x)
    #P0x[0,0] = 1e-3
    ekf_env = KalmanDAE(
                        ekf_env_cfg,
                        P0=P0x,
                        functions=deepcopy(functions),
                        scale=deepcopy(kwargs)
                        )
    # set params:
    R = ca.DM.eye(ekf_env.dae.n_y)
    Q = ca.DM.eye(mpc.n_x)
    ekf_env.set_params(params)
    ekf_env.set_R(R)
    ekf_env.set_Q(Q)
    
    """
    MHE for envelope problem:
    kwargs = {
        "slack": True,
        "p_nom": mpc.p_nom
    }
    """
    #kwargs["slack"] = False
    mhe = MHE(config=mhe_cfg,
              functions=deepcopy(functions),
              #param_guess=params[:-2], 
              param_guess=params, 
              arrival_cost=True,
              **deepcopy(kwargs))  # to remove, replace with N
    
    kwargs = {
        "x_nom": [12]*2,
        "x_nom_b": [289.15]*2,
        "z_nom": [1E6,10,1E6],
        "z_nom_b": [0]*3,
        "r_nom": [12,300,1E6,1E6,1E6,1,12,12],
        "r_nom_b": [289.15,0,0,0,0,0,289.15,289.15],
        "u_nom": [1],
        "u_nom_b": [0],
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
    ub_day = {"Ti": 301.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
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
    x0_env = np.array([293.15]*3)
    #x0_hvac = np.array([293.15,293.15,293.15,420])
    
    sol = pd.read_csv("HVAC_DAE_sol_latest_Tret_1min.csv", index_col=0)
    #x0_hvac = sol.loc[0, ["Trad", "Tret", "Tsup"]].values
    #x0_hvac = np.array([306,309,330.15])
    x0_hvac = np.array([289.20, 317.15])
    
    # sim horizon: 2 days
    days = 14
    K = int(days*24*4)
    time = pd.DataFrame(columns=["time"])

    """
    Keep history:
    """
    z_model = pd.DataFrame(columns=list(set(mpc.u_names + mpc_hvac.z_names)))
    x_model = pd.DataFrame(columns=mpc.x_names + mpc_hvac.x_names)
    
    x_model.loc[0, mpc.x_names] = x0_env
    x_model.loc[0, mpc_hvac.x_names] = x0_hvac

    """
    Get parameters for the separated MPC problems:
    """
    params_env = mpc_env.p0
    params_hvac = mpc_hvac.p0
    
    #Q = ca.inv(Q)
    #R = ca.inv(R)
    
    d = np.array([0,0,0])
    ekf_env.df.loc[0] = x0_env
    
    P0 = ca.DM.eye(mpc_env.n_p + mpc_env.n_x)*1e-6
    P0[19,19] = 0
    P0[20,20] = 0
    P0[21,21] = 0
    P0[3,3] = 1E2
    P0[6,6] = 1E2
    #P0[9,9] = 1E2
    P0[13,13] = 1E2
    P0[18,18] = 1E4
    
    #Q = ca.inv(Q)
    #R = ca.inv(R)
    
    lb_mult = 0.1
    ub_mult = 10
    params_lb = lb_mult*params_env
    params_ub = ub_mult*params_env
    
    for k in range(K):
        
        #lbx[3:-1:4] = 290
        #ubx[3:-1:4] = 325
        
        #lbx_env, ubx_env, _ = bounds.get_bounds(int(k/3), mpc.N)
        lbx_env, ubx_env, _ = bounds.get_bounds(k, mpc.N)
        #lbx_env = np.array([280,280,280]*(mpc_env.N-1))
        #ubx_env = np.array([340,340,330]*(mpc_env.N-1))
        sol_env, u_env, _x0_env = mpc_env.solve(
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
        #sol_env.index = np.arange(0, mpc_env.N*mpc_env.dt, mpc_env.dt)
        sol_env.index = np.arange(0, mpc_env.N*mpc_env.dt, mpc_env.dt)
        #data.index = sol_env
        data_hvac = data[0:mpc_hvac.N]
        #data_hvac["Ti"] = sol_env.Ti.shift(1).loc[data_hvac.index]
        data_hvac["Ti"] = sol_env.Ti.loc[data_hvac.index]
        data_hvac["Trad_ENV"] = sol_env.Trad_ENV.loc[data_hvac.index]
        #data_hvac["Ti"] = data_hvac["Ti"].bfill()
        #data_hvac.index = np.arange(0, mpc_hvac.N*mpc_hvac.dt, mpc_hvac.dt)
        #data_hvac.loc[0, "Ti"] = sol_env.Ti[0].astype(float)
        #data_hvac.loc[(mpc_hvac.N-1)*mpc_hvac.dt, "Ti"] = sol_env.Ti[1].astype(float)
        """
        Interpolate between 0, -1 for Ti:
        """
        #data_hvac["Ti"] = data_hvac["Ti"].interpolate(method="linear")
        params_hvac[-2] = sol_env.P_to_rad.iloc[0].astype(float)
        params_hvac[-1] = sol_env.P_to_rad.iloc[1].astype(float)
        #data.loc[(2*mpc_hvac.N-1)*mpc_hvac.dt, "Ti"] = sol_env.Ti[2].astype(float)
        
        #data.loc[:(mpc.N-1)*mpc.dt,"Prad_to_env_MPC"] = sol_env.Prad_to_env.astype(float).values
        #lbx_hvac, ubx_hvac, _ = bounds.get_bounds(k, mpc_hvac.N)
        # change CO2-constraints:        
        lbx_hvac = np.array([280,280]*(mpc_hvac.N-1))
        ubx_hvac = np.array([340,340]*(mpc_hvac.N-1))
        #lbx_hvac[3:-1:4] = 300
        #ubx_hvac[3:-1:4] = 800

        if sol_env.Prad_to_env[0].astype(float) > 20000:
            print("yes")
        # Crad, possible change:
        params_hvac[-12] = params_env[9]
        sol_hvac, u_hvac, x0_hvac = mpc_hvac.solve(
                                                    data_hvac,
                                                    x0=x0_hvac,
                                                    lbx=lbx_hvac,
                                                    ubx=ubx_hvac,
                                                    params=params_hvac,
                                                    codegen=False
                                                    )
        # set starting state to end of horizon:
        """
        x0_hvac = sol_hvac.loc[3, mpc_hvac.x_names].values
        # store results:
        sol_hvac[mpc.u_names] = sol_env.loc[0, mpc.u_names]
        for i in range(4):
            z_model.loc[k+i, z_model.columns] = sol_hvac.loc[i, z_model.columns]
        """
        z_model.loc[k, mpc_hvac.z_names] = sol_hvac.iloc[0][mpc_hvac.z_names]
        # forward set:
        z_model.loc[k+1, mpc_hvac.z_names] = np.nan
        x_model.loc[k+1, mpc.x_names] = sol_env.iloc[1][mpc.x_names]
        x_model.loc[k+1, mpc_hvac.x_names] = sol_hvac.iloc[1][mpc_hvac.x_names]
        #x_model.loc[k+1, mpc_hvac.x_names] = sol_hvac.loc[3, mpc_hvac.x_names]
        
        if mpc.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol_env)
        if mpc_hvac.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol_env)
        
        time.loc[k] = mpc.solver.stats()["t_wall_total"]
        u_hvac["ahu_pump_sup"] = 0.03
        u_hvac["ahu_pump_ret"] = 0.03
        """
        Get current disturbances before advancing:
        """
        r_pred_env = data[ekf_env.dae.r_names].iloc[0].values
        #r_pred_hvac = data_hvac[ekf_hvac.dae.r_names].iloc[0].values
        """
        Advance:
        """
        data, y_meas, u_meas = boptest.evolve(u=u_hvac,
                                            y_as_array=False,
                                            u_as_array=False)
        
        if u_hvac["rad_val"] > 1e-3:
            print(y_meas)
        """
        Envelope filter:
        """
        u_model = sol_hvac[ekf_env.dae.u].iloc[0].values
        y_z_meas = [y_meas[name] for name in ekf_env.y]
        # before advancing EKF, extract state covariance:
        """
        x0_env, _, _ = ekf_env.estimate_adj(
                                        x0_env, 
                                        _x0_env,
                                        #z=sol_env.loc[0, mpc.z_names].values,
                                        p=params_env,
                                        y=y_z_meas, 
                                        u=u_model, 
                                        r=r_pred_env, 
                                        Q=Q,
                                        R=R
                                        )
        """
        # filtering: (i.e. predict, then correct )
        _x0_env, _, _ = ekf_env.estimate(
                                        _x0_env, 
                                        #_x0_env,
                                        #z=sol_env.loc[0, mpc.z_names].values,
                                        p=params_env,
                                        y=y_z_meas, 
                                        u=u_model, 
                                        r=r_pred_env, 
                                        #Q=Q,
                                        #R=R
                                        )
            
        """
        u_model = [y_meas[name] for name in ekf_hvac.dae.u]
        # but this Ti is not correct? more correct with x0 from sol_env
        u_model[1] = data_hvac.iloc[0].Ti
        y_z_meas = [y_meas[name] for name in ekf_hvac.y]
        
        x0_hvac, _, _ = ekf_hvac.estimate(
                            x0_hvac, 
                            p=params_hvac,
                            y=y_z_meas, 
                            u=u_model, 
                            r=r_pred_hvac
                            )
        """
        if k >= (mhe.N - 2):
            #P0x = ekf_env.P_aprioris[k - (mhe.N - 2)]
            # get labelled data:
            stop_time = (k+1)*boptest.h
            start_time = stop_time - (mhe.N - 1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti
            y_data["rad_flo"] = z_model["rad_flo"][-mhe.N:].values
            y_data = y_data.fillna(0)
            
            """
            start EKF smoother, at the tail end of MHE horizon:
            """
            #y_data["y2"] = y_data.Ph

            if k == (mhe.N - 2):
                # if first MHE solve, use initial guess for P
                #P0x = np.linalg.inv(ekf_env.P_aprioris[k - mhe.N + 2])
                
                #ekf_env.df.loc[0] = np.array([293.15]*3)
                #mhe.df.loc[0] = np.concatenate([mhe.p0, np.array([293.15]*3)])
                #ekf_env.df = ekf_env.df.sort_index()
                #mhe_df = ekf_env.df.copy()
                x_N = ekf_env.df[mhe.x_names].iloc[-mhe.N].values
            else:
                # use EKF smoothing:
                
                #x_N = sol_mhe.iloc[1][mhe.x_names].values
                x_N = ekf_env.df[mhe.x_names].iloc[-mhe.N].values
                #x_N = x0 = x10
            
            # smoothing (i.e. correct, then predict):
            x00, x10, P0x, res_x, res_y, res, _K, A = ekf_env.estimate_smoothing(
                            #x0=sol_mhe.iloc[0][mhe.x_names].values, \
                            x0=x0_env, \
                            x0_1=x_N, \
                            #z=sol_mhe.loc[0, mhe.z_names].values, \
                            u=y_data[mhe.u_names].iloc[0].values,  
                            r=y_data[mhe.r_names].iloc[0].values,  
                            y=y_data[mhe.y_names].iloc[0].values, 
                            p=params_env,
                            P_prev=P0x,
                            d=d,
                            #Q=linalg.inv(Q),
                            #R=linalg.inv(R)
                            Q=Q,
                            R=R
                            )
            if k == (mhe.N - 2):
                print(x10, _x0_env)

            _P0x = np.linalg.inv(P0x)

            if k < (mhe.N - 1):
                x_guess = ekf_env.df[["Ti", "Te","Trad_ENV"]].sort_index()[-mhe.N:].values.flatten()
                #x_guess = ekf_env.df[["Ti", "Te","Trad_ENV"]][-mhe.N:].values.T
            else:
                #x_guess = mhe.df[["Ti", "Te","Trad_ENV"]][-mhe.N+1:].shift(-1).ffill().values.flatten()
                #x_guess = mhe.df[["Ti", "Te","Trad_ENV"]][-mhe.N+1:].shift(-1).ffill().values.flatten()
                x_guess = sol_mhe[mhe.x_names].shift(-1).values.flatten()
                x_guess[-mhe.n_x:] = _x0_env
                #x_guess[-mhe.n_x:] = x10.flatten()
                #x_guess = ekf_env.df[["Ti", "Te","Trad_ENV"]].sort_index()[-mhe.N:].values.flatten()
                
            params_init = params  # keep
            # check if parameter scale has changed:
            # NOTE: drop this for now:
            """
            if not all(
                mhe.get_scale(np.array(params).flatten())
                ==
                np.array(mhe.p_nom).flatten()
            ):
                # keep df:
                df = mhe.df
                # new mhe object:
                # keep df:
                mhe = MHE(config=mhe_cfg,
                          functions=deepcopy(functions),
                          param_guess=params,
                          **deepcopy(kwargs))
                # set df for estimation history:
                mhe.df = df
            """
            
            # set P0x on P0
            if k < 2*mhe.N:
                P0[
                    mpc_env.n_p:(mpc_env.n_p + mpc_env.n_x),
                    mpc_env.n_p:(mpc_env.n_p + mpc_env.n_x)
                    ] = 0
            else:
                __P0x = ca.inv(ekf_env.P_aprioris[k - mhe.N + 2])
                P0[
                    mpc_env.n_p:(mpc_env.n_p + mpc_env.n_x),
                    mpc_env.n_p:(mpc_env.n_p + mpc_env.n_x)
                    ] = __P0x
                
            
            #lbx=1*x_guess
            #ubx=1*x_guess
            lbx=0.5*x_guess
            ubx=1.5*x_guess
            #lbx[3:6] = 0.8*lbx[3:6]
            #ubx[3:6] = 1.2*ubx[3:6]
            #x_guess[3:6] = [y_data["Ti"].iloc[1]]*3
            
            sol_mhe, params_env, raw_sol_mhe = mhe.solve(
                y_data,
                params_env,
                lbp=params_lb,
                ubp=params_ub,
                covar=ca.veccat(Q, R),
                P0=P0,
                x_N=x_N,
                lbx=lbx,
                ubx=ubx,
                x_guess=x_guess,
                return_raw_sol=True,
                codegen=False
            )
            #params_lb = lb_mult*params_env
            #params_ub = ub_mult*params_env
            x0_env = sol_mhe[mhe.dae.x].iloc[-1].values
            d = sol_mhe[mhe.d_names].iloc[-2].values
            #params_env = 
            #mhe_df.loc[(k+1)*mhe.dt] = x0_env
            print(params)
            
    """
    Comparison z model and measured:
    """
    z_model_comp = z_model.copy()
    x_model_comp = x_model.copy()
    
    z_model = z_model[:-1]
    
    fig, axes = plt.subplots(2, 1, sharex=False)
    res = boptest.get_data(tf=K*boptest.h)
    res["Pvent"] -= res["Prad"]
    res.Prad_to_env = -res.Prad_to_env
    res = res.shift(-1)
    res = res.iloc[:-1]
    #res["P_to_rad_act"] = res["Prad"]
    #mpc = mpc_hvac
    z_names = mpc_hvac.z_names
    z_names = ["Prad", "rad_flo"]
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
    
    x_model = x_model[:-1]
    
    x_names = mpc.x_names + mpc_hvac.x_names
    
    x_names = ["Ti", "Tret"]
    fig, axes = plt.subplots(2,1, sharex=True)
    res = boptest.get_data(tf=K*boptest.h)
    res = res.iloc[:-1]
    #x_model = x_model[:-1]
    #res_x = res[::3]
    res_x = res
    #res_x = res_x.iloc[:-1]
    x_model.index = res_x.index
    res_x["Trad_ENV"] = res_x["Trad"]
    for name, ax in zip(x_names, axes.flatten()):
        try:
            x_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res_x[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        #ax.set_xticklabels([])
    #fig.tight_layout()
    plt.show()
    
    #ekf_env.df["Ti_MHE"] = mhe_df.Ti
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
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Prad")
    fig.tight_layout()
    plt.show()
    print(res)
    
    """
    Parameters:
    """
    mhe_df = mhe.df.iloc[:-95].copy()
    params_env = pd.read_csv("envelope_model_latest_4R3C.csv", index_col=0)
    fig, axes = plt.subplots(5, 1, sharex=False)
    env_params = ["Ci", "Ce", "Rie", "Rea", "Ai"]
    N = len(env_params)
    for i, param in enumerate(env_params):
        axes[i].plot(mhe_df[param], linewidth=0.75)
        constant_param = mhe_df[param].copy()
        constant_param.loc[:] = params_env.loc[param].values[0]
        axes[i].plot(constant_param, linewidth=0.75, color="r")
        axes[i].set_ylabel(param)
        if i < (N-1):
            axes[i].set_xticklabels([])
    plt.show()