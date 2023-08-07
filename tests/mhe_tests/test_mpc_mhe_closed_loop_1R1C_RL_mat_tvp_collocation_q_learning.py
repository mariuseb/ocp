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

    mpc_cfg = os.path.join(opt_config_base, "1R1C_MPC.json")
    mhe_cfg = os.path.join(opt_config_base, "1R1C_MHE.json")
    ekf_cfg = os.path.join(opt_config_base, "1R1C_EKF.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    params = ca.DM([
                    0.005,
                    6.32308e+06
                    ])

    kwargs = {
        "x_nom": 300,
        "u_nom": 5000,
        "r_nom": 300,
        "y_nom": 300,
        "slack": True
        #"slack": False
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
        name="testcase1_wea"
    )
    # first forecast:
    data = boptest.forecast()

    # init conditions, state bounds:
    N = mpc.N
    # batch size:
    B = 1
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
    days = 21
    K = days*24*bounds.t_h

    # mhe settings:
    P0 = ca.DM.eye(mpc.n_p + mpc.n_x)
    # P0 = ca.DM.zeros(7)

    # variance of parameters -> low
    # variance of x_hat_-1 -> high
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-16
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-16
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-8
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-8
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-4
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-4
    #P0[:mhe.n_p, :mhe.n_p] *= 1E-2
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-2
    P0[:mhe.n_p, :mhe.n_p] *= 1E-16
    P0[mhe.n_p:, mhe.n_p:] *= 1E-16
    #P0[:mhe.n_p, :mhe.n_p] *= 5E-1
    #P0[mhe.n_p:, mhe.n_p:] *= 5E-1
    #P0[:mhe.n_p, :mhe.n_p] *= 0
    #P0[mhe.n_p:, mhe.n_p:] *= 0
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

        """
        if not all(mpc.get_scale(np.array(params).flatten()) == np.array(mpc.p_nom).flatten()):
            # keep df:
            df = mhe.df
            # new mhe object:
            mpc = MPC(config=mpc_cfg,
                      param_guess=params,
                      **deepcopy(kwargs))
            mhe = MHE(config=mhe_cfg,
                      param_guess=params, 
                      **deepcopy(kwargs))
            # set df for estimation history:
            mhe.df = df
        """
        sol_mpc, u, x0, raw_sol = mpc.solve(
            data_mpc,
            x0=x0,
            lbx=lbx,
            ubx=ubx,
            params=params,
            return_raw_sol=True
            # ref=True
        )
        # for L_k eval, as L(x_k, u_k)
        try:
            y_prev = y_meas
        except:
            y_prev = x0[0]
        #lbx_prev = lbx
        
        data, y_meas, u_meas = boptest.evolve(u=u)

        # realized stage cost at k=0:
        """
        TODO:
            - function object for stage cost in
            MPC class.
        """

        # if we violate constraint, should result in drastic delta_theta
        # L_k = 0.5*(u_meas/mpc.u_nom)**2

        # heavy penalization on (lb) constraint violation:
        # if y_meas[0] < lbx[2]:
        #    L_k = 0.5*(u_meas/mpc.u_nom)**2 +# 1E6*(lbx[2] - y_meas[0])
        # else:
        # if k == 719:
        #    P0 = ca.DM.eye(7)*1E-16

        # TODO: need to rethink this:
        # TODO: incorporate slack in objective
        # evaluate stage cost STAGE-WISE
        #s_act = max(lbx[mpc.n_x] - y_meas, 0)
        #s_act = max(lbx[0] - y_prev, 0)
        #s_act = max(lbx[0] - y_meas, 0)
        #s_act = max(max(lbx[0] - y_meas, 0), max(y_meas - ubx[0], 0))
        s_act = max(max(lbx[0] - y_prev, 0), max(y_prev - ubx[0], 0))
        #if s_act > 0:
        #    print(s_act)
        # TODO: modularize:
        l_k = 0.5*(sol_mpc["phi_h"].iloc[0]/mpc.u_nom)**2 + \
              1E5*sol_mpc["s1"].iloc[0]**2
        L_k = 0.5*(u_meas/mpc.u_nom)**2 + \
              1E5*s_act**2
        #l_k = 0.5*(sol_mpc["phi_h"].iloc[0]/mpc.u_nom)**2
        #L_k = 0.5*(u_meas/mpc.u_nom)**2
        
        gains.loc[k, "L_k"] = float(L_k)
        gains.loc[k, "l_k"] = float(l_k)
        #gains.loc[k, "cons"] = max(float(lbx[2] - y_meas[0]), 0)

        # for RL step:
        lbx, ubx, ref = bounds.get_bounds(k+1, mpc.N)
        index = data_mpc.index
        data_rl = data.iloc[1:(mpc.N+1)]
        data_rl.index = index
        # append ref
        # ref = np.array([294.15]*11)
        ref = np.append(x0[0], ref)
        data_rl["Ti_ref"] = ref

        sol_mpc_RL, u_RL, x0_RL, raw_sol_RL = mpc.solve(
            data_rl,
            x0=x0,
            lbx=lbx,
            ubx=ubx,
            params=params,
            return_raw_sol=True
            # ref=True
        )

        # does this really make sense for a cyclic process ??
        diff_Q = gamma*raw_sol_RL["f"] - raw_sol["f"]

        """
        Do MPC at from k=0 to k=N+1.
        Then:
            Q_0 = f_MPC_{N+1} - L_{n+1}
            Q_1 = f_MPC_{N+1} - L_{0}
            
        Avoid solving the problem twice.
        """
        # this is objective dependant:
        # Q_0 = raw_sol["f"] - (sol_mpc.iloc[-1]["phi_h"]/mpc.u_nom)**2
        # Q_1 = raw_sol["f"] - (sol_mpc.iloc[0]["phi_h"]/mpc.u_nom)**2
        # diff_Q = Q_1*gamma - Q_0

        gains.loc[k, "diff_Q"] = float(diff_Q)
        # if k == 122:
        #    print(k)

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
            try:
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
                    P0=P0,
                    x_N=x_N,
                    arrival_cost=True,
                    return_raw_sol=True
                )
                
                # TODO: replace -> get P_theta:
                #covar_p = mhe.get_covar_p(params/mhe.p_nom, R, Q)[1]
                #covar_x = mhe.get_covar_x(params/mhe.p_nom, R, Q)[1]
                fisher = mhe.get_fisher(params/mhe.p_nom, R, Q)
                fishers.loc[k] = np.diag(fisher)
                
                #if k == 150:
                #    print(fisher)
                
                if not mhe.solver.stats()["return_status"] == "Solve_Succeeded":
                    print(sol_mhe)
            except ValueError:
                print(k)
            try:
                costate_prior = ca.vertcat(
                    params_init/mhe.p_nom, x_N/mhe.x_nom)
                del_theta = rl.step(mpc,
                                    mhe,
                                    costate_prior,
                                    # ca.sqrt(ca.inv(Q)),
                                    # ca.sqrt(ca.inv(R)),
                                    # ca.sqrt(Q),
                                    # ca.sqrt(R),
                                    Q,
                                    R,
                                    # ca.sqrt(ca.inv(P0)),
                                    # ca.sqrt(P0),
                                    # P0 + del_P0_accum,
                                    P0,
                                    diff_Q,
                                    L_k,
                                    #abs(L_k-l_k),
                                    k,
                                    del_P0_accum) #,
                """
                del_theta = rl.step(mpc,
                                    mhe,
                                    costate_prior,
                                    # ca.sqrt(ca.inv(Q)),
                                    # ca.sqrt(ca.inv(R)),
                                    # ca.sqrt(Q),
                                    # ca.sqrt(R),
                                    Q,
                                    R,
                                    # ca.sqrt(ca.inv(P0)),
                                    # ca.sqrt(P0),
                                    # P0 + del_P0_accum,
                                    P0,
                                    diff_Q,
                                    L_k,
                                    #abs(L_k-l_k),
                                    k,
                                    del_P0_accum) #,
                                    #alpha=0.03/(k-mhe.N+2))
                """

            except RuntimeError:  # rootfinder fail
                print(costate_prior)

            except NameError:

                rl = Qlearning(mpc, mhe, **{"gamma": 0.99, "alpha": 0.03})
                b = 1

                del_P0_accum = np.zeros((P0.shape[0], P0.shape[1]))

                # ignore first step
                del_theta = rl.step(mpc,
                                    mhe,
                                    costate_prior,
                                    # ca.sqrt(ca.inv(Q)),
                                    # ca.sqrt(ca.inv(R)),
                                    Q,
                                    R,
                                    # ca.sqrt(ca.inv(P0)),
                                    # P0 + del_P0_accum,
                                    P0,
                                    diff_Q,
                                    L_k,
                                    k,
                                    del_P0_accum)
                
                del_theta = np.zeros((P0.shape[0], P0.shape[1]))

            #del_P0 = ca.diag(ca.DM(np.diag(np.array(del_theta))))
            #del_P0 = ca.diag(ca.DM(np.diag(np.array(del_theta))))
            #del_P0 = del_theta*np.linalg.inv(fisher)
            #del_P0 = del_theta*fisher
            del_P0 = del_theta
            #deltas[k] = del_P0
            deltas.loc[k, :] = np.diag(del_theta)
            #thetas.loc[k, :] = np.diag(P0)
            

            del_P0_accum += del_P0   
            if b == B:  # update, reset del_P0_accum
                P0 += del_P0_accum
                #P0 -= del_P0_accum
                b = 0
                del_P0_accum = np.zeros((P0.shape[0], P0.shape[1]))
            
                P0_arr = np.array(P0)
                # clip below zero:
                if (np.array(P0) < 0).any():
                    ndx = np.where(P0 < 0)
                    P0_arr[ndx] = 1E-16
                    #P0_arr[ndx] = 1E-4
                    #P0_arr[ndx] = 0.5
                    #P0_arr[ndx] = 1E-2
                    #P0_arr[ndx] = 1
                # clip above one:
                #if (np.array(P0) > 1).any():
                #    ndx = np.where(P0 > 1)
                #    P0_arr[ndx] = 1
                #if (np.array(P0) > 1).any():
                #    ndx = np.where(P0 > 1)
                #    P0_arr[ndx] = 1
                P0 = ca.DM(P0_arr)
                    
            thetas.loc[k, :] = np.diag(P0)
                    
            b += 1
                
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

    plt.rcParams.update({'font.size': 11})

    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    plt.show()
    # plot diff_Q, which drives the learning:
    df = boptest.get_data(tf=k*mpc.dt)
    df.index = gains.index
    ax = (df.phi_h/(mpc.u_nom)).plot()
    gains.diff_Q.plot(ax=ax)
    plt.show()

    # parameter evolution plot ####:
    mhe.df.index = dt_index[-len(mhe.df):]
    fig, ax = plt.subplots(2, 1, figsize=(8, 10))
    (mhe.df.Ci/3.6E6).plot(ax=ax[0], color="k")  # to kWh/C
    #(mhe.df.Ce/3.6E6).plot(ax=ax[1], color="k")  # to kWh/C
    (mhe.df.Ria*1000).plot(ax=ax[1], color="k")  # to K/kW
    #(mhe.df.Rea*1000).plot(ax=ax[3], color="k")  # to K/kW
    #mhe.df.Ai.plot(ax=ax[2], color="k")

    ax[0].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    #ax[1].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[1].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    #ax[3].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    #ax[2].set_ylabel(r"Area [$m^2$]")

    ax[0].legend([r"$C_i$"])
    #ax[1].legend([r"$C_e$"])
    ax[1].legend([r"$R_{ia}$"])
    #ax[3].legend([r"$R_{ea}$"])
    #ax[2].legend([r"$A_w$"])

    ax[0].axes.get_xaxis().set_visible(False)
    #ax[1].axes.get_xaxis().set_visible(False)
    #ax[2].axes.get_xaxis().set_visible(False)
    #ax[3].axes.get_xaxis().set_visible(False)
    
    plt.show()
    
    # plot I elem against parameter value: 
    #fishers.index = mhe.df.index
    ax = mhe.df.Ria.plot()
    ax1 = ax.twinx()
    fishers.Ria.plot(ax=ax1, color="k")
    plt.show()
    
    ax = mhe.df.Ci.plot()
    ax1 = ax.twinx()
    fishers.Ci.plot(ax=ax1, color="k")
    plt.show()