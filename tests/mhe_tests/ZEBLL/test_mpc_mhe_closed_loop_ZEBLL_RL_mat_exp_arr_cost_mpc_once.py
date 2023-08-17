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
from ocp.rl import Qlearning
import os
import scipy
from copy import deepcopy
np.set_printoptions(precision=2)
# profiling:
import cProfile, pstats, io
from pstats import SortKey
#import pdb

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    # test diagonal MX etc.
    #p1 = ca.MX.sym("p1")
    #p2 = ca.MX.sym("p2")
    
    #P = ca.MX.eye(2)
    #P[0,0] = p1
    #P[1,1] = p1
    
    #P = ca.MX.sym('P',ca.Sparsity.diag(3))
    #P = ca.diag(ca.MX([p1, p2]))
    
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC.json")
    mhe_cfg = os.path.join(opt_config_base, "2R2C_MHE.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF.json")

    params = ca.DM([0.00100015, 
                    0.0129768, 
                    1.32308e+06,
                    9.54074e+07,
                    2.19846])
    
    kwargs = {
              "x_nom": 300,
              "u_nom": 5000,
              "r_nom": 300,
              "y_nom": 300
              }
    
    mpc = MPC(config=mpc_cfg, param_guess=params, **deepcopy(kwargs)) # to remove, replace with N
    mhe = MHE(config=mhe_cfg, param_guess=params, **deepcopy(kwargs))
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
    #rl = Qlearning(**{"gamma": 0.99, "alpha": 0.03})
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
    B = 12
    #B = 24
    deltas = {}
    #dt = mpc.dt
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
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([294.05, 293.15])
    
    # sim horizon: 2 days
    days = 7
    K = days*24*bounds.t_h
    
    # mhe settings:
    P0 = ca.DM.eye(7)
    
    # variance of parameters -> low
    # variance of x_hat_-1 -> high
    P0[:mhe.n_p,:mhe.n_p] *= 1E-16
    P0[mhe.n_p:, mhe.n_p:] *= 1E-16
    #P0 *= 1E-32
    
    #params_lb = ca.DM([0.001,0.01,1E5,1E6,1])
    #params_ub = ca.DM([0.1,0.1,1E7,1E8,50])
    params_lb = params*0.7
    params_ub = params*1.3
    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)
    
    constr_vio = 0
    # RL:
    gains = pd.DataFrame(columns = ["diff_Q", "L_k", "cons"])
    start = 0
    v = 0
    P0s = {}
    
    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        #ref = np.array([294.15]*11)
        # append reference:
        ref = np.append(x0[0],ref)
        
        data_mpc = data.iloc[0:mpc.N]
        data_mpc["Ti_ref"] = ref
        
        
        if not all(mpc.get_scale(np.array(params).flatten()) == np.array(mpc.p_nom).flatten()):
            # keep df:
            #df = mhe.df
            # new mhe object:
            mpc = MPC(config=mpc_cfg, param_guess=params, **deepcopy(kwargs))
            # set df for estimation history:
            #mhe.df = df
        
        sol_mpc, u, x0, raw_sol = mpc.solve(
                                        data_mpc,
                                        x0=x0,
                                        lbx=lbx,
                                        ubx=ubx,
                                        params=params,
                                        return_raw_sol=True
                                        #ref=True
                                        )
        # actual:
        data, y_meas, u_meas = boptest.evolve(u=u)
        
        # realized stage cost at k=0:
        """
        TODO:
            - function object for stage cost in
            MPC class.
        """
        
        # if we violate constraint, should result in drastic delta_theta
        #L_k = 0.5*(u_meas/mpc.u_nom)**2
        
        # heavy penalization on (lb) constraint violation:
        #if y_meas[0] < lbx[2]:
        #    L_k = 0.5*(u_meas/mpc.u_nom)**2 + 1E6*(lbx[2] - y_meas[0])
        #else:
        #if k == 719:
        #    P0 = ca.DM.eye(7)*1E-16
        
        # TODO: need to rethink this:
        # TODO: incorporate slack in objective
        # -> constr. violation yields larger change in theta
        L_k = 0.5*(u_meas/mpc.u_nom)**2

        gains.loc[k, "L_k"] = float(L_k)
        gains.loc[k, "cons"] = max(float(lbx[2] - y_meas[0]), 0)

        # for RL step:
        #lbx, ubx, ref = bounds.get_bounds(k+1, mpc.N)
        #index = data_mpc.index
        #data_rl = data.iloc[1:(mpc.N+1)]
        #data_rl.index = index
        # append ref
        #ref = np.array([294.15]*11)
        #ref = np.append(x0[0],ref)
        #data_rl["Ti_ref"] = ref
        
        """
        sol_mpc_RL, u_RL, x0_RL, raw_sol_RL = mpc.solve(
                                                        data_rl,
                                                        x0=x0,
                                                        lbx=lbx,
                                                        ubx=ubx,
                                                        params=params,
                                                        return_raw_sol=True
                                                        #ref=True 
                                                     )  
        """
        
        #diff_Q = gamma*raw_sol_RL["f"] - raw_sol["f"]
            
        """
        Do MPC at from k=0 to k=N+1.
        Then:
            Q_0 = f_MPC_{N+1} - L_{n+1}
            Q_1 = f_MPC_{N+1} - L_{0}
            
        Avoid solving the problem twice.
        """
        # this is objective dependant:
        Q_0 = raw_sol["f"] - (sol_mpc.iloc[-1]["phi_h"]/mpc.u_nom)**2
        Q_1 = raw_sol["f"] - (sol_mpc.iloc[0]["phi_h"]/mpc.u_nom)**2
        diff_Q = Q_1*gamma - Q_0
        
        gains.loc[k, "diff_Q"] = float(diff_Q)
        #if k == 122:
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
            
            params_init = params # keep
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
                    mhe = MHE(config=mhe_cfg, param_guess=params, **deepcopy(kwargs))
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
                if not mhe.solver.stats()["return_status"] == "Solve_Succeeded":
                    print(sol_mhe)
            except ValueError:
                print(k)         
            try:
                costate_prior = ca.vertcat(params_init/mhe.p_nom, x_N/mhe.x_nom)
                del_theta = rl.step(mpc, 
                                    mhe, 
                                    costate_prior,
                                    #ca.sqrt(ca.inv(Q)), 
                                    #ca.sqrt(ca.inv(R)), 
                                    #ca.sqrt(Q), 
                                    #ca.sqrt(R), 
                                    Q,
                                    R,
                                    #ca.sqrt(ca.inv(P0)),
                                    #ca.sqrt(P0),
                                    #P0 + del_P0_accum,
                                    P0,
                                    diff_Q,
                                    L_k,
                                    k)
                
            except RuntimeError: # rootfinder fail
                print(costate_prior)
                
            except NameError:
                
                rl = Qlearning(mpc, mhe, **{"gamma": 0.99, "alpha": 0.03})
                b = 0
                
                del_P0_accum = np.zeros((P0.shape[0], P0.shape[1]))
                
                del_theta = rl.step(mpc, 
                                    mhe, 
                                    costate_prior,
                                    #ca.sqrt(ca.inv(Q)), 
                                    #ca.sqrt(ca.inv(R)), 
                                    Q,
                                    R,
                                    #ca.sqrt(ca.inv(P0)),
                                    #P0 + del_P0_accum,
                                    P0,
                                    diff_Q,
                                    L_k,
                                    k)
                
            del_P0 = ca.diag(ca.DM(np.diag(np.array(del_theta))))
            deltas[k] = del_P0
            
            if b == B: # update, reset del_P0_accum
                P0 += del_P0_accum
                for k, v in deltas.items():
                    if abs(float(v[3,3])) > 1E-3:
                        print(k)
                        print(v)
                b = 0
                del_P0_accum = np.zeros((P0.shape[0], P0.shape[1]))
            else:
                # let P0 evolve in paralell:
                del_P0_accum += del_P0
                b += 1
            params = params.values
            params_lb = params*0.7
            params_ub = params*1.3
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
    
    #### parameter evolution plot ####:
    mhe.df.index = dt_index[-len(mhe.df):]
    fig, ax = plt.subplots(5,1, figsize=(8,10))
    (mhe.df.Ci/3.6E6).plot(ax=ax[0], color="k") # to kWh/C
    (mhe.df.Ce/3.6E6).plot(ax=ax[1], color="k") # to kWh/C
    (mhe.df.Rie*1000).plot(ax=ax[2], color="k") # to K/kW
    (mhe.df.Rea*1000).plot(ax=ax[3], color="k") # to K/kW
    mhe.df.Ai.plot(ax=ax[4], color="k")
    
    ax[0].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[1].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[2].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[3].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[4].set_ylabel(r"Area [$m^2$]")
    
    ax[0].legend([r"$C_i$"])
    ax[1].legend([r"$C_e$"])
    ax[2].legend([r"$R_{ie}$"])
    ax[3].legend([r"$R_{ea}$"])
    ax[4].legend([r"$A_w$"])
    
    ax[0].axes.get_xaxis().set_visible(False)
    ax[1].axes.get_xaxis().set_visible(False)
    ax[2].axes.get_xaxis().set_visible(False)
    ax[3].axes.get_xaxis().set_visible(False)
    

    plt.show()