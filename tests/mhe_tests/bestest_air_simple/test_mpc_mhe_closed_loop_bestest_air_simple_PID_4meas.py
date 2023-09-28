# %%
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
from ocp.filters import EKF, KalmanBucy
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from ocp.functions import functions
from copy import deepcopy

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    #mpc_cfg = os.path.join(opt_config_base, "3R3C_bestest_air_MPC.json")
    #mpc_cfg = os.path.join("mpc_configs", "3R2C_PID_FMU_MPC.json")
    mpc_cfg = os.path.join("mpc_configs", "3R2C_PID_MPC.json")
    #mpc_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_MPC_2meas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_idas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_map_test.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    #ekf_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_EKF_1meas.json")
    mhe_cfg = os.path.join("mhe_configs", "3R2C_bestest_air_simple_PID_MHE_FMU_stoch_3meas.json")
    mhe_cfg = os.path.join("mhe_configs", "3R2C_bestest_air_simple_PID_MHE_stoch_3meas.json")
    #mhe_cfg = os.path.join("mhe_configs", "3R2C_bestest_air_simple_PID_MHE_stoch.json")
    #ekf_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_EKF_2meas.json")

    """
    Handle FMU, add DLL equations to functions:    
    """
    
    #dae = ca.DaeBuilder('pi', 'FMUs/LimPID/LimPID.fmutmp')
    dae = ca.DaeBuilder('pi', 'FMUs/PI/PI.fmutmp')
    dae.disp(True)
    aux = dae.p()
    name_in = ['x','u']
    name_out = ['ydef']
    pi_y = dae.create('pi_y', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "openmp"})
    name_out = ['ode']
    pi_ode = dae.create('pi_ode', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "openmp"})
    functions["pi_ode"] = pi_ode
    functions["pi_y"] = pi_y

    
    params = ca.DM([0.01,0.001,1E6,5E6,5,500])
    params_mhe = params = ca.DM([0.01,0.001,1E6,5E6,5,500,0.1,120])
    params_mhe = params = ca.DM([
                2.230834e-04,
                2.253021e-03,
                4.756271e+06,
                2.237779e+07,
                2.943147e-01,
                2.479899e+03,
                0.1,
                120
                ])
    
    """
    """
    
    #ekf = KalmanBucy(ekf_cfg)
    # set params:
    #ekf.set_params(params)
    
    """
    """

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12],
        "u_nom_b": [289.15],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0],
        #"z_nom": 5000,
        #"slack": True
        "slack": False
    }
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
        "u_nom": [1],
        "u_nom_b": [0],
        "r_nom": 1,
        "y_nom": 1,
        #"slack": True
        "slack": False,
        "gamma": 1
    }
    
    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              functions=functions,
              **deepcopy(kwargs))  # to remove, replace with N
    #mpc.res = mpc.get("_y")
    
    
    mhe = MHE(config=mhe_cfg,
            param_guess=params_mhe, 
            functions=functions,
            **deepcopy(kwargs))  # to remove, replace with N
    # for gauss-newton:
    mhe.res = mhe.get("v1")
    
    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_air_simple"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 297.15}
    
    y = [name for k, name in mhe.dae.y]
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    #ekf.y,
                    y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    #x0 = np.array([294.05, 293.15, 300.15])
    #x0 = x_N = np.array([293.15, 293.15])
    #x0 = x_N = np.array([330.15, 293.15, 0])
    #x0 = x_N = np.array([293.15, 293.15, 1E-5])
    #x0 = x_N = np.array([288.15, 285.06, 0.0])
    x0 = x_N = np.array([293.15, 293.15, 0])
    
    # sim horizon: 2 days

    P0 = ca.DM.eye(mpc.n_p + mpc.n_x)
    P0[:mhe.n_p, :mhe.n_p] *= 0
    P0[mhe.n_p:, mhe.n_p:] *= 0

    params_ub = 1*params_mhe
    params_lb = 1*params_mhe
    #params_ub = 1.3*params_mhe
    #params_lb = 0.7*params_mhe
    #params_lb[0:7] = 0.7*params[0:7]
    #params_ub[0:7] = 1.3*params[0:7]
    params_lb[5] = 0.7*params_mhe[5]
    params_ub[5] = 1.3*params_mhe[5]
    
    Q = ca.DM.eye(mpc.n_x)
    #Q[2,2] = 0.01
    R = ca.DM.eye(mhe.n_y)
    #R[1,1] = 1E-4

    #fishers = pd.DataFrame(columns=(mpc.p_names + mpc.x_names))

    #us = pd.DataFrame(columns=["calc_mpc", "act"])
    
    days = 2
    K = days*24*bounds.t_h
    mhe_miss = pd.DataFrame(index=range(K), columns=["miss"])

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        ubx[2:-1:3] *= 100
        ubx[-1] *= 100
        
        sol, u, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params_mhe,
                               codegen=True
                               )
        #u["fan"] = 1
        data, y_meas, u_meas = boptest.evolve(u=u)
        #z_model = sol[ekf.dae.z].iloc[0].values # first? or second entry?
        #us.loc[k, "calc_mpc"] = sol["Ph"].iloc[0]
        #us.loc[k, "act"] = y_meas[1]
        
        #if k == 26:
        #    print(u)
        
        #if k >= mhe.N:
        if k >= (mhe.N - 1):
            # get labelled data:
            stop_time = (k+1)*boptest.h
            start_time = stop_time - (mhe.N - 1)*boptest.h
            #start_time = stop_time - mhe.N*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti
            y_data["y2"] = y_data.u_fan
            y_data["y3"] = y_data.Tsup
            y_data["y4"] = y_data.Ph
            #y_data.Ph = y_data.Ph.shift(-1)
            #y_data["y2"] = y_data.Ph
            #y_data = y_data[1:]

            #ax = y_data[["y1"]].plot(color="k")
            #ax1 = ax.twinx()
            #y_data[["y2"]].plot(color="r", ax=ax1, drawstyle="steps-post")
            #plt.show()
            
            #if k == mhe.N:
            if k == (mhe.N - 1):
                try:
                    #x_N = ekf.df[mhe.x_names].iloc[-mhe.N+1].values
                    x_N = x_N
                except IndexError: # mhe.N == 2
                    pass
            else:
                x_N = sol_mhe.iloc[1][mhe.x_names].values

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
                # new mhe Ti - 294.15,Ti - 294.15Ti - 294.15,Ti - 294.15Ti - 294.15,Ti - 294.15object:
                # keep df:
                mhe = MHE(config=mhe_cfg,
                        functions=deepcopy(functions),
                        param_guess=params,
                        **deepcopy(kwargs))
                # set df for estimation history:
                mhe.df = df
            """ 
            cols = ["Ti", "Te", "E"]
            x_guess = y_data[cols].iloc[-mhe.N:].values
            
            if mhe.strategy.name == "Collocation":
            #x_guess = y_data[["Ti"]].iloc[-mhe.N:].values
                shape = ((mhe.strategy.d)+1)*(mhe.N-1) + 1
                bds = np.resize(np.array([]),(shape,len(cols)))
                
                offset = 0
                for n in range(mhe.N-1): 
                    #bds[:,offset:(offset + (mhe.strategy.d+1))] = x_guess[n]
                    bds[offset:(offset + (mhe.strategy.d+1)), :] = np.tile(x_guess[n],
                                                                        ((mhe.strategy.d+1), 1))
                    offset += (mhe.strategy.d+1)
                #bds[:,-1] = x_guess[-1]
                bds[-1,:] = x_guess[-1]
                
                
                ones = np.ones(shape).reshape((1,shape))
                #lbx = y_data[["Ti"]].iloc[-mhe.N:]*0.9
                #ubx = y_data[["Ti"]].iloc[-mhe.N:]*1.1
            else:
                bds = x_guess
                
            lbx = bds*0.95
            ubx = bds*1.05
            # let integrator state E roam freely
            lbx[:,-1] *= 0.1
            ubx[:,-1] *= 10
            x_guess = bds
                
            #x_guess = np.hstack([x_guess.T, x_guess.T, (ones*sol["E"].iloc[1]).T]).flatten()
            # take E actual as guess:
            #x_guess = np.hstack([x_guess.T, x_guess.T, y_data["E"].values]).flatten()
            #x_guess = np.hstack([x_guess.T, x_guess.T, y_data["E"].values]).flatten()
            #lbx = np.hstack([lbx.T, lbx.T, (ones*0).T]).flatten()
            #ubx = np.hstack([ubx.T, ubx.T, (ones*2E1).T]).flatten()
            
            sol_mhe, params_mhe = mhe.solve(
                y_data,
                params_mhe,
                lbp=params_lb,
                ubp=params_ub,
                lbx=lbx,
                ubx=ubx,
                covar=ca.veccat(Q, R),
                P0=P0,
                x_guess=x_guess,
                x_N=x_N,
                arrival_cost=False,
                codegen=True
            )
            if mhe.solver.stats()["return_status"] != "Solve_Succeeded":
                mhe_miss.loc[k] = 1
                # if mhe fails, use mpc prediction as rest of x_hat
                x0 = np.append(y_meas[:1], sol[["Te", "E"]].iloc[1])
            else:
                mhe_miss.loc[k] = 0
                x0 = sol_mhe.iloc[-1][mhe.x_names].values
            
            """
            ax = sol_mhe.y1.plot()
            sol_mhe["Ti"].plot(ax=ax)
            ax.legend()
            plt.show()
            """
            
            params_lb[5] = 0.7*params_mhe[5]
            params_ub[5] = 1.3*params_mhe[5]
            #params_lb[5:] = 0.7*params_mhe[5:]
            #params_ub[5:] = 1.3*params_mhe[5:]
            #params_ub = 1.3*params_mhe
            #params_lb = 0.7*params_mhe
            #params_ub = 1.3*params_mhe
            #params_lb = 0.7*params_mhe
            #params = params.values
            #params_lb[0:5] = params[0:5]*0.7
            #params_ub[0:5] = params[0:5]*1.3
            #params_lb[0:7] = 0.7*params[0:7]
            #params_ub[0:7] = 1.3*params[0:7]
            #params_lb = params*0.99
            #params_ub = params*1.01
            #x0 = sol_mhe.iloc[-1][mhe.x_names].values
            #us.loc[k, "calc_mhe"] = sol_mhe["Ph"].iloc[-1]
                    
        else: # TODO: issue: ekf warmup
            #z_model = sol[ekf.dae.z].iloc[1].values
            #r_pred = data[ekf.dae.r_names].iloc[0].values
            
            # take measurement + model prediction:
            #x0 = np.append(y_meas[0], x0[1:])
            #x0 = np.append(y_meas[0], x0[1:])
            #x0 = np.append(y_meas[:1], sol[["Te", "E"]].iloc[1])
            x0 = y_meas
            

    plt.rcParams.update({'font.size': 12})
    data = boptest.get_data(tf=K*mpc.dt)
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Ph")
    mhe_miss.index = dt_index
    axes[1].plot(mhe_miss*5000, drawstyle="steps-post")
    fig.tight_layout()
    plt.show()    
    print(params)
    start = mhe.df.index[0]
    stop = mhe.df.index[-1]
    y_data = boptest.get_data(ts=start, tf=stop)
    ax = y_data[["Ti"]].plot(color="k", linestyle="dashed")
    mhe.df["Ti"].plot(ax=ax, color="r")
    plt.show()
    ax = y_data[["E"]].plot(color="k", linestyle="dashed")
    mhe.df["E"].plot(ax=ax, color="r")
    plt.show()
    
    #Ph_inf = data["u_fan"]*(data["Tsup"]-data["Ti"])*sol["UA_is"].iloc[0]
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
