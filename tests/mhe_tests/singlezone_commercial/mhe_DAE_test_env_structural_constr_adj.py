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

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    RUN = True
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    #mpc_cfg = os.path.join("mpc_configs", "3R2C_MPC_CO2_ext.json")
    mpc_cfg = os.path.join("mpc_configs", "6R4C_MPC_ENV_no_CO2_adj.json")
    mhe_cfg = os.path.join("mhe_configs", "6R4C_MHE_ENV_no_CO2_structural_constr_adj.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "6R4C_EKF_ENV_no_CO2_adj_adj.json")

    #params_hvac = pd.read_csv("HVAC_DAE_model_latest_Tret.csv", index_col=0)
    #params_env = pd.read_csv("envelope_model_latest_6R5C.csv", index_col=0)
    params_hvac = pd.read_csv("HVAC_DAE_model_latest_Tret_5min.csv", index_col=0)
    params_env = pd.read_csv("envelope_model_latest_4R3C.csv", index_col=0)
    #params_env = pd.read_csv("envelope_model_latest_6R4C.csv", index_col=0)
    params_CO2 = pd.read_csv("CO2_model.csv", index_col=0)
    params_CO2.rename(index={"c": "c1"}, inplace=True)
    
    # perturb envelope parameters:
    """
    params_env.loc["Ce"] *= 1.5
    params_env.loc["Ci"] *= 0.5
    params_env.loc["Rie"] *= 0.45
    params_env.loc["Rea"] *= 1.3
    params_env.loc["Ai"] *= 1.7
    """
    
    params = pd.concat([params_hvac, params_env, params_CO2])
    _params = params[~params.index.duplicated(keep='first')]
    params = _params.to_dict()["0"]
    params_dict = {k: {"init": v} for k, v in params.items()}

    kwargs = {
        "x_nom": [12,12,12,12],
        "x_nom_b": [289.15,289.15,289.15,289.15],
        "z_nom": [1E6,1],
        "z_nom_b": [0,0],
        "r_nom": [12,300,1E6,1E6,1E6,1],
        "r_nom_b": [289.15,0,0,0,0,0],
        "u_nom": [1],
        "u_nom_b ": [0],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        #"slack": True
        "slack": False
    }

    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params_dict, 
              **deepcopy(kwargs))  # to remove, replace with N
    """
    kwargs["y_nom"] = [12,12,1E6,12]
    kwargs["y_nom_b"] = [289.15,289.15,0,289.15]
    kwargs["r_nom"] += [1E6,1]
    kwargs["r_nom_b"] += [0,0]
    kwargs["z_nom"] = 0
    kwargs["z_nom_b"] = 0
    """
    
    kwargs["p_nom"] = np.array(np.array([1.e+04, 1.e+00, 1.e+00, 1.e+02, 1.e+02, 1.e+03, 1.e+00, 1.e+02,
       1.e-04, 1.e-06, 1.e+00, 1.e+00, 1.e+00, 1.e+00, 1.e+00, 1.e+01,
       1.e+01, 1.e+01, 1.e+01, 1.e+03, 1.e+06, 1.e+06, 1.e+05, 1.e+02,
       1.e-04, 1.e-03, 1.e-04, 1.e-04, 1.e-01, 1.e-01, 1.e-06, 1.e+07,
       1.e+07, 1.e+07, 1.e+04, 1.e+06, 1.e+02, 1.e+00, 1.e-01, 1.e+03,
       1.e-05, 1.e+03, 1.e+00, 1.e-03, 1.e+01, 1.e+02]))
    
    kwargs["slack"] = True
    mhe_env = mhe = MHE(config=mhe_cfg,
                    functions=deepcopy(functions),
                    param_guess=params_dict, 
                    arrival_cost=False,
                    **deepcopy(kwargs))
    
    boptest_filename = "boptest_results_MHE_N=%s_fixed_model.csv" \
                % \
               (str(mhe.N, ))
    x_model_filename = "model_predictions_MHE_N=%s_fixed_model.csv" \
                % \
               (str(mhe.N, ))
               
    ekf = KalmanDAE(ekf_cfg,
                     functions=deepcopy(functions)
                     )
    """
    R = ca.DM.eye(2)
    R[0,0] = 1/1E-2
    R[1,1] = 1/1E-2
    #R[2,2] = 1/1E-9
    Q = ca.DM.eye(mhe.n_x)*1E3
    ekf.set_params(params)
    ekf.set_R(R)
    ekf.set_Q(Q)
    """
    
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
                    ub_day=ub_day,
                    day_begin=8,
                    day_end=16
                    )
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([293.15,293.15,293.15,293.15])
    ekf.df.loc[0, mpc.x_names] = x0
    ekf.df.loc[0, mpc.z_names] = [0,0]
    # sim horizon: 2 days
    days = 5
    K = int(days*24*bounds.t_h)
    time = pd.DataFrame(columns=["time"])

    z_model = pd.DataFrame(columns=mpc.z_names)
    x_model = pd.DataFrame(columns=mpc.x_names)
    x_model.loc[0, mpc.x_names] = x0
    
    params = mpc.p0
    
    """
    MHE, EKF params:
    """
    P0 = ca.DM.eye(mhe.n_p + mhe.n_x + mhe.n_z)
    # no arrival cost on params yet:
    P0[:mhe.n_p, :mhe.n_p] *= 0
    #P0[mhe.n_p:, mhe.n_p:] *= 0
    params_lb = 1*params
    params_ub = 1*params
    #Q = ca.DM.eye(mpc.n_x + mpc.n_z)*1E-3
    """
    For EKF:
    """
    R = ca.DM.eye(1)
    """
    R[0,0] = 1/1E-2
    R[1,1] = 1/1E-2
    R[2,2] = 1/1E-9
    R[3,3] = 1/1E-1
    """
    #Q = ca.DM.eye(mpc.n_x + mpc.n_z)*1E3
    Q = R*10
    #Q = ca.DM.eye(mpc.n_x)*1E3
    ekf.set_params(params)
    ekf.set_R(R)
    ekf.set_Q(Q)
    """
    For MHE:
    """
    R = ca.DM.eye(mhe.n_y)
    R[0,0] = 1
    R[1,1] = 1E-2
    R[2,2] = 1E-9
    R[3,3] = 1E-1
    #R[1,1] = 0
    #R[2,2] = 0
    #R[3,3] = 0
    Q = ca.DM.eye(mhe.n_x + mhe.n_z)*1E-3
    
    """
    Q[0,0] = R[0,0]/10
    Q[1,1] = R[0,0]/10
    Q[2,2] = R[0,0]/10
    Q[3,3] = R[1,1]/10
    Q[4,4] = R[2,2]/10
    Q[5,5] = R[3,3]/10
    """
    # invert for use in objective function:
    
    _params = pd.Series(_params["0"]).loc[mhe.dae.p]
    
    if RUN:
    
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
            # store results:
            z_model.loc[k, mpc.z_names] = sol.loc[0, mpc.z_names]
            x_model.loc[k+1, mpc.x_names] = sol.loc[1, mpc.x_names]
            
            if mpc.solver.stats()["return_status"] != "Solve_Succeeded":
                print(sol)
            
            time.loc[k] = mpc.solver.stats()["t_wall_total"]
            u["ahu_pump_sup"] = 0.03
            u["ahu_pump_ret"] = 0.03
            """
            Store r_pred before advancing:
            """
            r_pred = data[ekf.dae.r_names].iloc[0].values
            # advance:
            data, y_meas, u_meas = boptest.evolve(u=u,
                                                y_as_array=False,
                                                u_as_array=False)
            
            if u["rad_val"] > 1e-2:
                print(y_meas)
            
            """
            EKF estimation:
            
            Get P0 for states BEFORE
            evolving the EKF.
            """
            u_actual = sol[ekf.dae.u].iloc[0].values
            u_actual[1] = y_meas["Prad"]
            # TODO: check if constraint active 
            y_z_meas = [y_meas[name] for name in ekf.y]
            x0_ekf, z, y = ekf.estimate(
                                    x0, 
                                    #z=sol.loc[0, mpc.z_names].values,
                                    p=params,
                                    y=y_z_meas, 
                                    u=u_actual, 
                                    r=r_pred
                                    )
            try:
                P0_x_z = ekf.P_aprioris[k - mhe.N + 1]
                #P0_x_z = ekf.P[k]
                # filter:
                P0_x_z = np.array(P0_x_z)
                #P0_x_z[P0_x_z < 1e-4] = 0
                #P0_x_z = ekf.P_aprioris[k-1]
            except: # first iteration
                assert k < mhe.N
            """
            MHE estimation:
            """
            MHE_start = mhe.N - 1
            #if k >= (mhe.N - 1):
            if k >= MHE_start:
                # get labelled data:
                stop_time = (k+1)*boptest.h
                start_time = stop_time - (mhe.N - 1)*boptest.h
                y_data = boptest.get_data(ts=start_time, tf=stop_time)
                y_data[["rad_flo", "Prad", "rad_val", "Ta", "phi_s"]] = y_data[["rad_flo", "Prad", "rad_val", "Ta", "phi_s"]].shift(-1) 
                y_data["y1"] = y_data.Ti
                y_data["y2"] = y_data.Tret
                y_data["y3"] = y_data.Prad
                y_data["y4"] = y_data.rad_flo
                y_data = y_data.fillna(0)
                y_data = y_data.loc[:,~y_data.columns.duplicated()].copy()

                if k == MHE_start:
                    #x_N = ekf.df[mhe.x_names].iloc[-mhe.N+1].values
                    #z_N = ekf.df[mhe.z_names].iloc[-mhe.N+1].values
                    z_N = ekf.df[mhe.z_names].iloc[-mhe.N].values
                    x_N = ekf.df[mhe.x_names].iloc[-mhe.N].values
                else:
                    x_N = sol_mhe.iloc[1][mhe.x_names].values
                    z_N = sol_mhe.iloc[1][mhe.z_names].values
                    #x_guess = sol_mhe[mhe.x_names].shift .values
                x_guess = ekf.df[["Ti", "Te","Trad","Tret"]][-mhe.N:].values.flatten()
                """
                Generalized logic for the below:
                    - only valid for N=2
                """
                #z_N = sol.loc[0, mpc.z_names].values
                
                """
                TODO:
                    - only do this first time,
                    rest should use (shifted)
                    last estimate.
                """
                # set state covariance:
                #P0[mhe.n_p:, mhe.n_p:] = np.linalg.inv(P0_x_z)
                                    
                params_lb = 1*_params 
                params_ub = 1*_params 
                #params_lb["rad_flo_nom"] = 4
                #params_ub["rad_flo_nom"] = 10
                #params_lb["n1"] = 1
                #params_ub["n1"] = 3
                
                if k < 1*96:
                    params_lb[["Ce", "Ci", "Rie", "Rea", "Ai"]] *= 0.8
                    params_ub[["Ce", "Ci", "Rie", "Rea", "Ai"]] *= 1.2
                
                
                params_lb = params_lb.values
                params_ub = params_ub.values
                
                #params_init = params  # keep
                
                sol_mhe, params = mhe.solve(
                    y_data,
                    params,
                    lbp=params_lb,
                    ubp=params_ub,
                    x_guess=x_guess,
                    lbx=0.8*x_guess,
                    ubx=1.2*x_guess,
                    covar=ca.veccat(Q, R),
                    P0=P0,
                    x_N=x_N,
                    z_N=z_N,
                    #arrival_cost=True,
                    codegen=True
                )                  
                _params = params
                params = params.values
                #x0 = sol_mhe.iloc[-1][mhe.x_names].values
                x0 = sol_mhe.iloc[-1][mhe.x_names].values
            else:
                x0 = x0_ekf
        else:
            res = boptest.get_data(tf=K*boptest.h)
            #res = res.iloc[:-1]
            x_model = x_model
            x_model.index = res.index
            # write:
            res.to_csv(boptest_filename)
            x_model.to_csv(x_model_filename)
    else:
        res = pd.read_csv(boptest_filename, index_col=0)
        x_model = pd.read_csv(x_model_filename, index_col=0)
              
    res = boptest.get_data(tf=K*boptest.h)
    res.index = res.index.astype(int)
    ax = ekf.df.Ti.iloc[2:].plot(linestyle="dashed")
    try:
        mhe.df.Ti.plot(ax=ax)
    except TypeError:
        pass
    #res.Ti.plot(ax=ax, linestyle="dashed", linewidth=0.75, color="k")
    plt.show()
            
    res = boptest.get_data(tf=K*boptest.h)
    
    res = res.shift(-1)
    res["Pvent"] -= res["Prad"]
    fig, axes = plt.subplots(2,1, sharex=False)
    res = res.iloc[:-1]
    z_model.index = res.index
    
    for name, ax in zip(mpc.z_names, axes.flatten()):
        try:
            z_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        ax.set_xticklabels([])
    plt.show()
    
    res = boptest.get_data(tf=K*boptest.h)
    
    fig, axes = plt.subplots(2,2, sharex=False)
    #res = res.iloc[:-1]
    x_model = x_model
    x_model.index = res.index
    
    for name, ax in zip(mpc.x_names, axes.flatten()):
        try:
            x_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        ax.set_xticklabels([])
    #fig.tight_layout()
    plt.show()
     
    res.to_csv("boptest_results_MHE_N=%s_fixed_model.csv" %
               (str(mhe.N, )))
    x_model.to_csv("model_predictions_MHE_N=%s_fixed_model.csv" %
               (str(mhe.N, )))
        
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Prad")
    fig.tight_layout()
    plt.show()
    print(res)   
    # look at CO2-concentration