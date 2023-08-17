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
from ocp.filters import EKF, KalmanBucy
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
from ocp.rl import Qlearning
import os
import scipy
from copy import deepcopy
np.set_printoptions(precision=2)
#pd.set_option('display.height', 500)
pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option("display.precision", 16)
import math
# profiling:
# import pdb

# text:
rc('mathtext', default='regular')
# datetime:
# plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"


if __name__ == "__main__":

    # test diagonal MX etc.
    # p1 = ca.MX.sym("p1")
    # p2 = ca.MX.sym("p2")

    # P = ca.MX.eye(2)
    # P[0,0] = p1
    # P[1,1] = p1

    # P = ca.MX.sym('P',ca.Sparsity.diag(3))
    # P = ca.diag(ca.MX([p1, p2]))

    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()

    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC.json")
    mhe_cfg = os.path.join(opt_config_base, "2R2C_MHE.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    
    params = ca.DM([0.00100015,
                    0.0129768,
                    1.32308e+06,
                    9.54074e+07,
                    2.19846])

    kwargs = {
        "x_nom": 300,
        "u_nom": 5000,
        "r_nom": 300,
        "y_nom": 300,
        #"slack": True
        "slack": True
    }

    
    """
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        "slack": True
    }
    """
    

    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    mhe = MHE(config=mhe_cfg,
              param_guess=params, 
              **deepcopy(kwargs))
    """
    Here, init RL obj. Takes in the mhe, mpc objs
    in constructor to set up sensitivity functions.
    
    Hyper-parameters should be defined in some
    config-file/dict:
        - gamma: discount rate
        - alpha: learning rate
        
    and that is it atm.
    
    NOTE: distuingish between SARSA
    and Q-learning.
    
    TODO: implement arrival cost as:
    
    P = (I - exp(-P_theta))
    """
    gamma = 0.99
    # rl = Qlearning(**{"gamma": 0.99, "alpha": 0.03})
    # for first N iterations:
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)

    boptest = Boptest(
        boptest_cfg,
        name="ZEBLL"
    )
    # first forecast:
    data = boptest.forecast()

    # init conditions, state bounds:
    N = mpc.N
    # batch size:
    B = 24
    #B = 48
    deltas = pd.DataFrame(columns=list(map(lambda x: "theta_" + str(x), range(mpc.n_p + mpc.n_x))))
    thetas = pd.DataFrame(columns=list(map(lambda x: "theta_" + str(x), range(mpc.n_p + mpc.n_x))))
    # dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}

    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    mhe.y_names,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)

    # TODO: shouldn't have to fine-tune these:
    # x0 = np.array([293.05, 290.15])
    x0 = np.array([294.05])
    #y_prev = x0[0]
    # sim horizon: 2 days
    days = 7
    K = days*24*bounds.t_h

    # mhe settings:
    P0 = ca.DM.eye(mpc.n_p + mpc.n_x)
    # P0 = ca.DM.zeros(7)

    # variance of parameters -> lowss
    # variance of x_hat_-1 -> high
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-16
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-16
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-8
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-8
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-4
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-4
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-2
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-2
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-8
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-8
    #P0[:mhe.n_p, :mhe.n_p] *= 5E-1
    #P0[mhe.n_p:, mhe.n_p:] *= 5E-1
    P0[:mhe.n_p, :mhe.n_p] *= 0
    P0[mhe.n_p:, mhe.n_p:] *= 0
    # P0 *= 1E-32

    # params_lb = ca.DM([0.001,0.01,1E5,1E6,1])
    # params_ub = ca.DM([0.1,0.1,1E7,1E8,50])
    params_lb = params*0.7
    params_ub = params*1.3
    #params_lb = params*0.9
    #params_ub = params*1.1
    #params_lb = params*0.999
    #params_ub = params*1.001
    #params_lb = params
    #params_ub = params
    Q = ca.DM.eye(mpc.n_x)
    R = ca.DM.eye(mhe.n_y)

    constr_vio = 0
    # RL:
    fishers = pd.DataFrame(columns=(mpc.p_names + mpc.x_names))
    gains = pd.DataFrame(columns=["diff_Q", "L_k", "cons"])
    start = 0
    v = 0
    P0s = {}

    for k in range(K):

        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)

        # ref = np.array([294.15]*11)
        # append reference:
        ref = np.append(x0[0], ref)

        data_mpc = data.iloc[0:mpc.N]
        data_mpc["Ti_ref"] = ref

        sol_mpc, u, x0, raw_sol = mpc.solve(
            data_mpc,
            x0=x0,
            lbx=lbx,
            ubx=ubx,
            params=params,
            return_raw_sol=True
            # ref=True
        )
      
        data, y_meas, u_meas = boptest.evolve(u=u)

        if k >= (mhe.N - 1):
            # get labelled data:
            stop_time = (k+1)*boptest.h
            start_time = stop_time - (mhe.N - 1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti

            if k == (mhe.N - 1):
                x_N = ekf.df.iloc[-mhe.N+1].values
            else:
                x_N = sol_mhe.iloc[1][mhe.x_names].values

            params_init = params  # keep
                # check if parameter scale has changed:
            if not all(
                mhe.get_scale(np.array(params).flatten())
                ==
                np.array(mhe.p_nom).flatten()
            ):
                # keep df:
                df = mhe.df
                # new mhe object:
                mhe = MHE(config=mhe_cfg, param_guess=params,
                            **deepcopy(kwargs))
                # set df for estimation history:
                mhe.df = df
                
            sol_mhe, params, raw_mhe = mhe.solve(
                y_data,
                params,
                lbp=params_lb,
                ubp=params_ub,
                covar=ca.veccat(Q, R),
                #P0=P0,
                x_N=x_N,
                arrival_cost=False,
                return_raw_sol=True
            )

                
            params = params.values
            params_lb = params*0.7
            params_ub = params*1.3
            #params_lb = params*0.99
            #params_ub = params*1.01
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
            
        else:
            x0 = ekf.estimate(
                x0,
                y=y_meas,
                u=u_meas,
                r=data.iloc[0].values
            )

    plt.rcParams.update({'font.size': 12})

    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    fig.tight_layout()
    plt.show()
    # plot diff_Q, which drives the learning:
    df = boptest.get_data(tf=k*mpc.dt)

    # parameter evolution plot ####:
    mhe.df.index = dt_index[-len(mhe.df):]
    fig, ax = plt.subplots(5, 1, figsize=(8, 10))
    (mhe.df.Ci/3.6E6).plot(ax=ax[0], color="k")  # to kWh/C
    (mhe.df.Ce/3.6E6).plot(ax=ax[1], color="k")  # to kWh/C
    (mhe.df.Rie*1000).plot(ax=ax[2], color="k")  # to K/kW
    (mhe.df.Rea*1000).plot(ax=ax[3], color="k")  # to K/kW
    mhe.df.Ai.plot(ax=ax[4], color="k")

    ax[0].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[1].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[2].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[3].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[4].set_ylabel(r"Area [$m^2$]")

    ax[0].legend([r"$C_i$"])
    ax[1].legend([r"$C_e$"])
    ax[2].legend([r"$R_{ia}$"])
    ax[3].legend([r"$R_{ea}$"])
    ax[4].legend([r"$A_w$"])

    ax[0].axes.get_xaxis().set_visible(False)
    ax[1].axes.get_xaxis().set_visible(False)
    ax[2].axes.get_xaxis().set_visible(False)
    ax[3].axes.get_xaxis().set_visible(False)
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
