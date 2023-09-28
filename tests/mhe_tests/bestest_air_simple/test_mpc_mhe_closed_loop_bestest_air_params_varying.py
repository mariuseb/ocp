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

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    #mpc_cfg = os.path.join(opt_config_base, "3R3C_bestest_air_MPC.json")
    mpc_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_MPC_1meas.json")
    #mpc_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_MPC_2meas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_idas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_map_test.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_EKF_1meas.json")
    mhe_cfg = os.path.join(opt_config_base, "3R2C_bestest_air_MHE_1meas.json")
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
    params = ca.DM([
        3.960196e-03,
        1.125336e-02,
        3.150582e+05,
        8.887156e+06,
        3.545100e+00,
        4.049526e+02
                ])
    params = ca.DM([0.001,0.01,1E6,1E7,5,500])
    
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
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    
    
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
        "u_nom": [12, 1],
        "u_nom_b": [289.15, 0],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0],
        "slack": True
    }
    kwargs = {
        "x_nom": 1,
        "u_nom": [1,1],
        "u_nom_b": [0,0],
        "r_nom": 1,
        "y_nom": 1,
        #"slack": True
        "slack": True
    }
    
    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    kwargs["slack"] = False
    
    mhe = MHE(config=mhe_cfg,
            param_guess=params, 
            **deepcopy(kwargs))  # to remove, replace with N
    
    
    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_air"
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
    x0 = x_N = np.array([291.15, 291.15])
    
    # sim horizon: 2 days

    P0 = ca.DM.eye(mpc.n_p + mpc.n_x)
    P0[:mhe.n_p, :mhe.n_p] *= 0
    P0[mhe.n_p:, mhe.n_p:] *= 0

    params_ub = 1.3*params
    params_lb = 0.7*params
    #params_lb[0:7] = 0.7*params[0:7]
    #params_ub[0:7] = 1.3*params[0:7]
    #params_lb[0:5] = 0.7*params[0:5]
    #params_ub[0:5] = 1.3*params[0:5]
    
    Q = ca.DM.eye(mpc.n_x)
    R = ca.DM.eye(mhe.n_y)
    #R[1,1] = 1E-8

    fishers = pd.DataFrame(columns=(mpc.p_names + mpc.x_names))

    #us = pd.DataFrame(columns=["calc_mpc", "act"])
    
    days = 7
    K = days*24*bounds.t_h

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
            sol_mhe, params = mhe.solve(
                y_data,
                params,
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
                
            params = params.values
            #params_lb[0:5] = params[0:5]*0.7
            #params_ub[0:5] = params[0:5]*1.3
            params_lb = 0.7*params
            params_ub = 1.3*params
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
                            u=u_meas, 
                            r=r_pred
                            )

    plt.rcParams.update({'font.size': 12})
    data = boptest.get_data(tf=K*mpc.dt)
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Ph")
    fig.tight_layout()
    plt.show()    

    mhe.df.index = dt_index[-len(mhe.df):]
    fig, ax = plt.subplots(6, 1, figsize=(8, 10))
    (mhe.df.Ci/3.6E6).plot(ax=ax[0], color="k")  # to kWh/C
    (mhe.df.Ce/3.6E6).plot(ax=ax[1], color="k")  # to kWh/C
    (mhe.df.Rie*1000).plot(ax=ax[2], color="k")  # to K/kW
    (mhe.df.Rea*1000).plot(ax=ax[3], color="k")  # to K/kW
    (mhe.df.UA_is/1000).plot(ax=ax[4], color="k")  # to K/kW
    mhe.df.Ai.plot(ax=ax[5], color="k")

    ax[0].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[1].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[2].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[3].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[4].set_ylabel(r"Cond. [$\frac{W}{K}$]")
    ax[5].set_ylabel(r"Area [$m^2$]")

    ax[0].legend([r"$C_i$"])
    ax[1].legend([r"$C_e$"])
    ax[2].legend([r"$R_{ia}$"])
    ax[3].legend([r"$R_{ea}$"])
    ax[4].legend([r"$UA_{is}$"])
    ax[5].legend([r"$A_w$"])

    ax[0].axes.get_xaxis().set_visible(False)
    ax[1].axes.get_xaxis().set_visible(False)
    ax[2].axes.get_xaxis().set_visible(False)
    ax[3].axes.get_xaxis().set_visible(False)
    ax[4].axes.get_xaxis().set_visible(False)
    fig.tight_layout()
    plt.show()
# %%
