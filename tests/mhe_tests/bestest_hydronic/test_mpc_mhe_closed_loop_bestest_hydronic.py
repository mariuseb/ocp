# from ast import Param
import io
import pstats
import cProfile
import matplotlib.dates as mdates
from pstats import SortKey
from ocp.mpc import MPC
from ocp.mhe import MHE
import numpy as np
import json
import casadi as ca
# import sysid.dae as dae
# import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import KalmanBucy
from ocp.functions import functions
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
#from ocp.rl import Qlearning
import os
#import scipy
from copy import deepcopy
np.set_printoptions(precision=2)
#pd.set_option('display.height', 500)
pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option("display.precision", 16)
#import math
# profiling:
# import pdb

# text:
rc('mathtext', default='regular')
# datetime:
# plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"


if __name__ == "__main__":

     
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_func.json")
    mhe_cfg = os.path.join(opt_config_base, "2R2C_MHE_func.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF_func.json")

    # pass in config?
    """
    Rie       1.922773e-03
    Rea       8.390597e-03
    Ci        1.781685e+06
    Ce        2.050836e+07
    Ai        6.062751e+00
    n         1.156362e+00
    UA_nom    5.387476e+01
    eta       8.700000e-01
    """
    params = ca.DM([1.922773e-03,
                    8.390597e-03,
                    1.781685e+06, 
                    2.050836e+07,
                    6.062751e+00,
                    1.156362e+00,
                    5.387476e+01,
                    8.700000e-01])
    
    
    kwargs = {
        "x_nom": 300,
        "u_nom": 300,
        "r_nom": 300,
        "y_nom": 300,
        "z_nom": 5000,
        #"slack": Trues
        "slack": False
    }
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        #"slack": Trues
        "slack": False
    }
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 12,
        "z_nom": 5000,
        "u_nom_b": 289.15,
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0],
        #"slack": True
        "slack": True
    }
    
    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 12,
        "u_nom_b": 289.15,
        "r_nom": [12, 300, 5000],
        "r_nom_b": [289.15, 0, 0],
        "y_nom": [12, 5000],
        "y_nom_b": [289.15, 0],
        #"slack": True
        "slack": False
    }
    
    mhe = MHE(config=mhe_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    
    ekf = KalmanBucy(ekf_cfg,
                     functions=deepcopy(functions)
                     )
    # set params:
    ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_hydronic"
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
                    ub_day=ub_day)
    
    # mhe settings:
    P0 = ca.DM.eye(mpc.n_p + mpc.n_x)
    P0[:mhe.n_p, :mhe.n_p] *= 0
    P0[mhe.n_p:, mhe.n_p:] *= 0
    # P0 *= 1E-32

    # params_lb = ca.DM([0.001,0.01,1E5,1E6,1])
    # params_ub = ca.DM([0.1,0.1,1E7,1E8,50])
    #params_lb = params*0.7
    #params_ub = params*1.3
    params_lb = params
    params_ub = params
    #params_lb = params*0.9
    #params_ub = params*1.1
    #params_lb = params*0.99
    #params_ub = params*1.01
    #params_lb = params
    #params_ub = params
    #Q = ca.DM.eye(mpc.n_x + mpc.n_z)
    Q = ca.DM.eye(mpc.n_x)
    #Q[1,1] = 1E-3
    #Q[1,1] = 1E-2
    #Q[0,0] = 0
    #Q[1,1] = 0
    # this is the objective weighting:
    R = ca.DM.eye(mhe.n_y)
    R[1,1] = 1E-8
    #R[1,1] = 1E-10
    #R = ca.DM.eye(1)

    fishers = pd.DataFrame(columns=(mpc.p_names + mpc.x_names))
    days = 2
    K = days*24*bounds.t_h

    x0 = np.array([294.05, 293.15])
    us = pd.DataFrame(columns=["calc_mpc", "act"])
    
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

        data, y_meas, u_meas = boptest.evolve(u=u)
        # keep u's:
        us.loc[k, "calc_mpc"] = sol["Ph"].iloc[0]
        us.loc[k, "act"] = y_meas[1]

        if k >= (mhe.N - 1):
            # get labelled data:
            stop_time = (k+1)*boptest.h
            start_time = stop_time - (mhe.N - 1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti
            y_data["y2"] = y_data.Ph

            if k == (mhe.N - 1):
                x_N = ekf.df[mhe.x_names].iloc[-mhe.N+1].values
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
            params_lb = params
            params_ub = params
            #params_lb = params*0.99
            #params_ub = params*1.01
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
            us.loc[k, "calc_mhe"] = sol_mhe["Ph"].iloc[-1]
            
        else: # TODO: issue: ekf warmup
            z_model = sol[ekf.dae.z].iloc[1].values
            r_pred = data[ekf.dae.r_names].iloc[0].values
            x0 = ekf.estimate(
                            x0, 
                            z=z_model,
                            y=y_meas, 
                            u=u_meas, 
                            r=r_pred
                            )

    ax = us[["calc_mpc", "calc_mhe"]].plot()
    us[["act"]].plot(ax=ax, linestyle="dashed")
    ax.legend()
    plt.show()  

    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Ph")
    fig.tight_layout()
    plt.show()
    # plot diff_Q, which drives the learning:
    df = boptest.get_data(tf=k*mpc.dt)

    # parameter evolution plot ####:
    mhe.df.index = dt_index[-len(mhe.df):]
    fig, ax = plt.subplots(8, 1, figsize=(8, 10))
    (mhe.df.Ci/3.6E6).plot(ax=ax[0], color="k")  # to kWh/C
    (mhe.df.Ce/3.6E6).plot(ax=ax[1], color="k")  # to kWh/C
    (mhe.df.n).plot(ax=ax[2], color="k")  # to kWh/C
    (mhe.df.Rie*1000).plot(ax=ax[3], color="k")  # to K/kW
    (mhe.df.Rea*1000).plot(ax=ax[4], color="k")  # to K/kW
    (mhe.df.UA_nom).plot(ax=ax[5], color="k")  # to K/kW
    mhe.df.Ai.plot(ax=ax[6], color="k")
    mhe.df.eta.plot(ax=ax[7], color="k")

    ax[0].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[1].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[2].set_ylabel(r"[-]")
    ax[3].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[4].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[5].set_ylabel(r"Cond. [$\frac{kW}{K}$]")
    ax[6].set_ylabel(r"Area [$m^2$]")
    ax[7].set_ylabel(r"$\eta$ [-]")

    ax[0].legend([r"$C_i$"])
    ax[1].legend([r"$C_e$"])
    ax[2].legend([r"$n$"])
    ax[3].legend([r"$R_{ia}$"])
    ax[4].legend([r"$R_{ea}$"])
    ax[5].legend([r"$UA_{nom}$"])
    ax[6].legend([r"$A_w$"])
    ax[7].legend([r"$\eta$"])

    ax[0].axes.get_xaxis().set_visible(False)
    ax[1].axes.get_xaxis().set_visible(False)
    ax[2].axes.get_xaxis().set_visible(False)
    ax[3].axes.get_xaxis().set_visible(False)
    ax[4].axes.get_xaxis().set_visible(False)
    ax[5].axes.get_xaxis().set_visible(False)
    ax[6].axes.get_xaxis().set_visible(False)
    fig.tight_layout()
    plt.show()
    
    # plot I elem against parameter value: 
    #fishers.index = mhe.df.index
    #ax = mhe.df.Ria.plot()
    #ax1 = ax.twinx()
    #fishers.Ria.plot(ax=ax1, color="k")
    #plt.show()
    
    #ax = mhe.df.Ci.plot()
    #ax1 = ax.twinx()
    #fishers.Ci.plot(ax=ax1, color="k")
    #plt.show()
