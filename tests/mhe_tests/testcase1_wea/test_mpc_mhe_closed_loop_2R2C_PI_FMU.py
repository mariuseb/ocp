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
    
    #mpc_cfg = os.path.join(opt_config_base, "3R3C_bestest_air_MPC.json")
    mpc_cfg = os.path.join("mpc_configs", "3R2C_PID_FMU_MPC.json")
    mhe_cfg = os.path.join("mhe_configs", "2R2C_PI_MHE_1meas.json")
    #mpc_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_MPC_2meas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_idas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_map_test.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "2R2C_PI_EKF_1meas_Ai.json")
    #ekf_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_EKF_2meas.json")

    # pass in config?
    """
    params = ca.DM([
                    3.151236e-03,
                    5.428432e-03,
                    8.495345e-03,
                    2.564024e-04,
                    1.423833e+05,
                    2.187849e+07,
                    2.218342e+06,
                    5
                    ])
    params = ca.DM([
                    1.599046e-03,
                    1.250769e-02,
                    2.286526e-03,
                    1.513427e+05,
                    6.812778e+06,
                    9.272857e+00
                    ])
    params = ca.DM([
            3.183400e-03,
            1.199633e-02,
            3.591281e+05,
            8.441441e+06,
            5.791493e+00,
            4.061040e+02,
            5.000000e-01,
            9.315919e-01
                ])
    """
    params_mpc = ca.DM([
                        0.01,
                        0.01,
                        1E6,
                        5E6,
                        5
                        ])
 
    """
    kwargs = {
        "x_nom": 300,
        "u_nom": 5000,
        "r_nom": 300,
        "y_nom": 300,
        #"slack": True
        "slack": False
    }
    """
    
    
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12, 1],
        "u_nom_b": [289.15, 0],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0],
        #"z_nom": 5000,
        #"slack": True
        "slack": False
    }
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12],
        "u_nom_b": [289.15],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0],
        "slack": False
    }
    kwargs = {
        "x_nom": 1,
        "u_nom": [1],
        "u_nom_b": [0],
        "r_nom": 1,
        "y_nom": 1,
        #"slack": True
        "slack": False
    }
    
    dae = ca.DaeBuilder('pi', 'FMUs/PI/PI.fmutmp')
    dae.disp(True)
    aux = dae.p()
    name_in = ['x','u']
    name_out = ['ydef']
    pi_y = dae.create('pi_y', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "serial"})
    name_out = ['ode']
    pi_ode = dae.create('pi_ode', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "serial"})
    functions["pi_ode"] = pi_ode
    functions["pi_y"] = pi_y
    
    mpc = MPC(config=mpc_cfg,
              param_guess=params_mpc, 
              functions=functions,
              **deepcopy(kwargs))  # to remove, replace with N
    
    kwargs["slack"] = False
    
    params = ca.DM([
        0.01,
        0.01,
        1E6,
        5E6,
        5,
        100,
        (1/3)
        ])
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    
    mhe = MHE(config=mhe_cfg,
            param_guess=params, 
            **deepcopy(kwargs))  # to remove, replace with N
    
    
    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1_wea"
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
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    #x0 = np.array([294.05, 293.15, 300.15])
    #x0 = x_N = np.array([293.15, 293.15])
    x0 = x_N = np.array([293.15, 293.15,0])
    
    # sim horizon: 2 days

    P0 = ca.DM.eye(mpc.n_p + mpc.n_x)
    P0[:mhe.n_p, :mhe.n_p] *= 0
    P0[mhe.n_p:, mhe.n_p:] *= 0

    #params_ub = 1.3*params
    #params_lb = 0.7*params
    params_ub = 1*params
    params_lb = 1*params
    len_p = params.shape[0]
    #params_lb[len_p-1] = params[len_p-1]*0.7
    #params_ub[len_p-1] = params[len_p-1]*1.3
    #params_lb[0:7] = 0.7*params[0:7]
    #params_ub[0:7] = 1.3*params[0:7]
    #params_lb[0:5] = 0.7*params[0:5]
    #params_ub[0:5] = 1.3*params[0:5]
    
    Q = ca.DM.eye(mpc.n_x)
    R = ca.DM.eye(mhe.n_y)
    #R[1,1] = 1E-8

    fishers = pd.DataFrame(columns=(mpc.p_names + mpc.x_names))

    #us = pd.DataFrame(columns=["calc_mpc", "act"])
    
    days = 1
    K = days*24*bounds.t_h

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        # adjust upper bound of E:
        ubx[2:-1:3] *= 100
        ubx[-1] *= 100
        
        sol, u, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params_mpc,
                               codegen=False,
                               sqp=False
                               )
        #u["fan"] = 1
        data, y_meas, u_meas = boptest.evolve(u=u)
        z_model = sol[ekf.dae.z].iloc[0].values # first? or second entry?
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
            to_zero_indices = [ndx for ndx in y_data.index if not y_data.loc[ndx, "phi_h"]]
            y_data["Tset"].loc[to_zero_indices] = y_data["Ti"].loc[to_zero_indices]
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
                    x_N = ekf.df[mhe.x_names].iloc[-mhe.N+1].values
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
                # new mhe object:
                # keep df:
                mhe = MHE(config=mhe_cfg,
                        functions=deepcopy(functions),
                        param_guess=params,
                        **deepcopy(kwargs))
                # set df for estimation history:
                mhe.df = df
            """ 
            x_guess = y_data[["Ti"]].iloc[-mhe.N:].values
            shape = ((mhe.strategy.d)+1)*(mhe.N-1) + 1
            bds = np.resize(np.array([]),(1,shape))
            
            offset = 0
            for n in range(mhe.N-1): 
                bds[:,offset:(offset + (mhe.strategy.d+1))] = x_guess[n]
                offset += (mhe.strategy.d+1)
            bds[:,-1] = x_guess[-1]
            
            
            ones = np.ones(shape).reshape((1,shape))
            #lbx = y_data[["Ti"]].iloc[-mhe.N:]*0.9
            #ubx = y_data[["Ti"]].iloc[-mhe.N:]*1.1
            lbx = bds*0.9
            ubx = bds*1.1
            x_guess = bds
            x_guess = np.hstack([x_guess.T, x_guess.T, (ones*1E-5).T]).flatten()
            lbx = np.hstack([lbx.T, lbx.T, (ones*0).T]).flatten()
            ubx = np.hstack([ubx.T, ubx.T, (ones*1E3).T]).flatten()
            
            # TODO: hide collocation details when
            # passing ubx, lbx
            sol_mhe, params = mhe.solve(
                y_data,
                params,
                lbp=params_lb,
                ubp=params_ub,
                lbx=lbx,
                ubx=ubx,
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
                
            #params = params.values
            #params_lb[len_p-1] = params[len_p-1]*0.7
            #params_ub[len_p-1] = params[len_p-1]*1.3
            #params_lb = params*0.7
            #params_ub = params*1.3
            #params_lb = params*0.99
            #params_ub = params*1.01
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
            #us.loc[k, "calc_mhe"] = sol_mhe["Ph"].iloc[-1]
                    
        else: # TODO: issue: ekf warmup
            #z_model = sol[ekf.dae.z].iloc[1].values
            r_pred = data[ekf.dae.r_names].iloc[0].values
            x0 = ekf.estimate(
                            x0, 
                            #z=z_model,
                            y=y_meas, 
                            u=u, 
                            r=r_pred
                            )

    plt.rcParams.update({'font.size': 12})
    data = boptest.get_data(tf=K*mpc.dt)
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="phi_h")
    Tset = data.Tset[:-1] - 273.15
    Tset.index =dt_index
    axes[0].plot(Tset)
    fig.tight_layout()
    plt.show()    
    print(params)
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