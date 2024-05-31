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
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_env_cfg = os.path.join("mpc_configs", "3R2C_MPC_simpler.json")
    mpc_hvac_cfg = os.path.join("mpc_configs", "HVAC_MPC_no_CO2.json")
    mhe_env_cfg = os.path.join("mhe_configs", "3R2C_MHE_simpler.json")
    mhe_hvac_cfg = os.path.join("mhe_configs", "HVAC_MHE_no_CO2.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    #ekf_cfg = os.path.join("ekf_configs", "6R4C_EKF_ENV_no_CO2.json")
    ekf_env_cfg = os.path.join("ekf_configs", "3R2C_simpler_EKF.json")
    ekf_hvac_cfg = os.path.join("ekf_configs", "3R2C_HVAC_simpler_EKF.json")
    
    params_hvac = pd.read_csv("HVAC_DAE_model_latest.csv", index_col=0)
    params_env = pd.read_csv("envelope_model_latest_6R4C.csv", index_col=0)
    params_CO2 = pd.read_csv("CO2_model.csv", index_col=0)
    params_CO2.rename(index={"c": "c1"}, inplace=True)
    params = pd.concat([params_hvac, params_env, params_CO2])
    params = params[~params.index.duplicated(keep='last')]
    #params = params.values.flatten()
    #params_env = params_env.values.flatten()
    params = params.to_dict()["0"]
    params = {k: {"init": v} for k, v in params.items()}

    kwargs = {
        "x_nom": [12,12],
        "x_nom_b": [289.15,289.15],
        "r_nom": [12,300,1E6,1E6,1E6],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [1E6],
        "u_nom_b ": [0],
        #"y_nom": [12],
        #"y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }

    mpc_env = mpc = MPC(
                        config=mpc_env_cfg,
                        functions=deepcopy(functions),
                        #param_guess=params_env, 
                        param_guess=params, 
                        **deepcopy(kwargs)
                        )  # to remove, replace with N
    
    #kwargs["y_nom"] = [12]
    #kwargs["y_nom_b"] = [289.15]
    kwargs = {
        "slack": True
    }
    
    mhe_env = mhe = MHE(config=mhe_env_cfg,
                        functions=deepcopy(functions),
                        param_guess=params, 
                        **deepcopy(kwargs))
    
    kwargs = {
        "x_nom": [12,12,12,1000],
        "x_nom_b": [289.15,289.15,289.15,0],
        "z_nom": [1E6,1E6,1,1,1,1,12,12,12,1,1,1,1E6,1,1,1,1,1E6],
        "z_nom_b": [0,0,0,0,0,0,289.15,289.15,289.15,0,0,0,0,0,0,0,0,0],
        "r_nom": [12,300,1E6,1E6,1E6,1,1E6,12],
        "r_nom_b": [289.15,0,0,0,0,0,0,289.15],
        "u_nom": [1,1,1,1],
        "u_nom_b ": [0,0,0,0],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        #"slack": True
        "slack": False
    }
    kwargs = {
        "x_nom": [12,12],
        "x_nom_b": [289.15,289.15],
        "z_nom": [1E6,10],
        "z_nom_b": [0]*2,
        "r_nom": [12,300,1E6,1E6,1E6,1,1E6,12],
        "r_nom_b": [289.15,0,0,0,0,0,0,289.15],
        "u_nom": [1],
        "u_nom_b ": [0],
        #"y_nom": [12,1E6,1],
        #"y_nom_b": [289.15,0,0],
        #"slack": True
        "slack": False
    }
    mpc_hvac = MPC(
                   config=mpc_hvac_cfg,
                   functions=deepcopy(functions),
                   param_guess=params, 
                   **deepcopy(kwargs)
                    )  # to remove, replace with N
    
    kwargs["y_nom"] = [12,1E6,1]
    kwargs["y_nom_b"] = [289.15,0,0]
    
    mhe_hvac = MHE(config=mhe_hvac_cfg,
                   functions=deepcopy(functions),
                   param_guess=params, 
                   **deepcopy(kwargs))
    """
    EKF for envelope problem:
    """
    ekf_env = KalmanDAE(ekf_env_cfg,
                        functions=deepcopy(functions)
                        )
    # set params:
    R = ca.DM.eye(ekf_env.dae.n_y)
    Q = ca.DM.eye(mpc.n_x + mpc.n_z)
    ekf_env.set_params(params)
    ekf_env.set_R(R)
    ekf_env.set_Q(Q)
    
    """
    EKF for HVAC problem:
    """
    ekf_hvac = KalmanDAE(ekf_hvac_cfg,
                         functions=deepcopy(functions)
                         )
    # set params:
    R = ca.DM.eye(ekf_hvac.dae.n_y)
    R[0,0] = 1
    R[1,1] = 1/1E-9
    R[2,2] = 1
    Q = ca.DM.eye(mpc_hvac.n_x + mpc_hvac.n_z)
    ekf_hvac.set_params(params)
    ekf_hvac.set_R(R)
    ekf_hvac.set_Q(Q)
    
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
    x0_env = np.array([293.15,291.15])
    #x0_hvac = np.array([293.15,293.15,293.15,420])
    x0_hvac = np.array([293.15,293.15])
    
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
    
    # mhe settings:
    P0 = ca.DM.eye(mpc.n_p + mpc.n_x)
    P0[:mhe.n_p, :mhe.n_p] *= 0
    P0[mhe.n_p:, mhe.n_p:] *= 0
    params_lb = params
    params_ub = params
    Q = ca.DM.eye(mpc.n_x)
    R = ca.DM.eye(mhe.n_y)*10
    #R[1,1] = 1E-8
    
    for k in range(K):
        lbx_env, ubx_env, _ = bounds.get_bounds(k, mpc.N)
        #lbx[3:-1:4] = 290
        #ubx[3:-1:4] = 325
        sol_env, u_env, x0_env = mpc_env.solve(
                                    data[0:mpc.N],
                                    x0=x0_env,
                                    lbx=lbx_env,
                                    ubx=ubx_env,
                                    params=params_env,
                                    codegen=True
                                    ) 
        """
        Set Ti, Prad_to_env
        """
        data["Ti"] = 0
        data["Prad_to_env_MPC"] = 0
        data.loc[:(mpc.N-1)*mpc.dt, "Ti"] = sol_env.Ti.astype(float).values
        data.loc[:(mpc.N-1)*mpc.dt,"Prad_to_env_MPC"] = sol_env.Prad_to_env.astype(float).values
        lbx_hvac, ubx_hvac, _ = bounds.get_bounds(k, mpc_hvac.N)
        # change CO2-constraints:        
        lbx_hvac = np.array([280,280]*(mpc_hvac.N-1))
        ubx_hvac = np.array([300,340]*(mpc_hvac.N-1))
        #lbx_hvac[3:-1:4] = 300
        #ubx_hvac[3:-1:4] = 800

        sol_hvac, u_hvac, x0_hvac = mpc_hvac.solve(
                                                    data[0:mpc_hvac.N],
                                                    x0=x0_hvac,
                                                    lbx=lbx_hvac,
                                                    ubx=ubx_hvac,
                                                    params=params_hvac,
                                                    codegen=True
                                                    )
        # store results:
        z_model.loc[k, mpc.u_names] = sol_env.loc[0, mpc.u_names]
        z_model.loc[k, mpc_hvac.z_names] = sol_hvac.loc[0, mpc_hvac.z_names]
        x_model.loc[k+1, mpc.x_names] = sol_env.loc[1, mpc.x_names]
        x_model.loc[k+1, mpc_hvac.x_names] = sol_hvac.loc[1, mpc_hvac.x_names]
        
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
        r_pred_hvac = data[ekf_hvac.dae.r_names].iloc[0].values
        """
        Advance:
        """
        data, y_meas, u_meas = boptest.evolve(u=u_hvac,
                                              y_as_array=False,
                                              u_as_array=False)
        
        if k >= (mhe.N - 1):
            # get labelled data:
            stop_time = (k+1)*boptest.h
            start_time = stop_time - (mhe.N - 1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti
            y_data["Prad_to_env"] = y_data["Prad"]
            #y_data["y2"] = y_data.Ph

            if k == (mhe.N - 1):
                x_N = ekf_env.df[mhe.x_names].iloc[-mhe.N+1].values
            else:
                x_N = sol_mhe.iloc[1][mhe.x_names].values

            #params_lb = 0.7*params_env
            #params_ub = 1.3*params_env
            params_lb = 1.0*params_env
            params_ub = 1.0*params_env

            params_init = params  # keep
            sol_mhe, params_env = mhe.solve(
                y_data,
                params_env,
                lbp=params_lb,
                ubp=params_ub,
                covar=ca.veccat(Q, R),
                P0=P0,
                x_N=x_N,
                arrival_cost=False,
                codegen=True
            )
            """
            ax = sol_mhe.y1.plot()
            sol_mhe["Ti"].plot(ax=ax)
            ax.legend()
            plt.show()
            """     
            params_env = params_env.values
            #params_lb = params
            #params_ub = params
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
        else:
            u_model = sol_env[ekf_env.dae.u].iloc[0].values
            y_z_meas = [y_meas[name] for name in ekf_env.y]
            x0_env, _, _ = ekf_env.estimate(
                                            x0_env, 
                                            z=sol_env.loc[0, mpc.z_names].values,
                                            p=params_env,
                                            y=y_z_meas, 
                                            u=u_model, 
                                            r=r_pred_env
                                            )  
            
        u_model = sol_hvac[ekf_hvac.dae.u].iloc[0].values
        y_z_meas = [y_meas[name] for name in ekf_hvac.y]
        x0_hvac, _, _ = ekf_hvac.estimate(
                                        x0_hvac, 
                                        z=sol_hvac.loc[0, mpc_hvac.z_names].values,
                                        p=params_hvac,
                                        y=y_z_meas, 
                                        u=u_model, 
                                        r=r_pred_hvac
                                        )
        
    """
    Comparison z model and measured:
    """
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
    
    mpc = mpc_env
    
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
        
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Prad")
    fig.tight_layout()
    plt.show()
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