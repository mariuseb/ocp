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

    # pass in config?
    """
    params = params_init = ca.DM([0.0015,
                                  0.0116,
                                  1.33E6,
                                  6.64E6,
                                  5.53])
    """
    params = ca.DM([0.00100015, 
                    0.0129768, 
                    1.32308e+06,
                    9.54074e+07,
                    2.19846])
    
    mpc = MPC(config=mpc_cfg) # to remove, replace with N
    #mhe = MHE(config=mhe_cfg, param_guess=params)
    #mhe = MHE(config=mhe_cfg, param_guess=params)
    mhe = MHE(config=mhe_cfg)
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
    B = 100
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
    days = 14
    K = days*24*bounds.t_h
    
    # mhe settings:
    P0 = ca.DM.eye(7)
    
    # variance of parameters -> low
    # variance of x_hat_-1 -> high
    # order in P0 -> [p, x_hat_-1]
    #P0[:mhe.n_p,:mhe.n_p] *= 1E-32
    #P0[:mhe.n_p,:mhe.n_p] *= 1E32
    #P0[mhe.n_p:, mhe.n_p:] *= 1E32
    #P0[:mhe.n_p,:mhe.n_p] *= 1E-16
    #P0[mhe.n_p:, mhe.n_p:] *= 1E-16
    P0[:mhe.n_p,:mhe.n_p] *= 1E-16
    P0[mhe.n_p:, mhe.n_p:] *= 1E-16
    #P0 *= 1E-32
    
    #params_lb = ca.DM([0.001,0.01,1E5,1E6,1])
    #params_ub = ca.DM([0.1,0.1,1E7,1E8,50])
    params_lb = params*0.7
    params_ub = params*1.3
    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        #ref = np.array([294.15]*11)
        # append reference:
        ref = np.append(x0[0],ref)
        
        data_mpc = data.iloc[0:mpc.N]
        data_mpc["Ti_ref"] = ref
        
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
        L_k = 0.5*u_meas**2
        
        # for RL step:
        lbx, ubx, ref = bounds.get_bounds(k+1, mpc.N)
        index = data_mpc.index
        data_rl = data.iloc[1:(mpc.N+1)]
        data_rl.index = index
        # append ref
        #ref = np.array([294.15]*11)
        ref = np.append(x0[0],ref)
        data_rl["Ti_ref"] = ref
        
        sol_mpc_RL, u_RL, x0_RL, raw_sol_RL = mpc.solve(
                                                        data_rl,
                                                        x0=x0,
                                                        lbx=lbx,
                                                        ubx=ubx,
                                                        params=params,
                                                        return_raw_sol=True
                                                        #ref=True 
                                                     )  
        
        
        diff_Q = gamma*raw_sol_RL["f"] - raw_sol["f"]
        
        
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
                
            sol_mhe, params = mhe.solve(
                                    y_data,
                                    params,
                                    lbp=params_lb,
                                    ubp=params_ub,
                                    covar=ca.veccat(Q, R),
                                    P0=P0,
                                    x_N=x_N,
                                    arrival_cost=True
                                    )
            
            #mhe_params = ca.veccat(ca.vertcat(params, x_N), Q, R, P0)
            try:
                #pr = cProfile.Profile()
                #pr.enable()
                del_theta = rl.step(mpc, 
                                    mhe, 
                                    ca.vertcat(params_init, x_N),
                                    #ca.sqrt(ca.inv(Q)), 
                                    #ca.sqrt(ca.inv(R)), 
                                    #ca.sqrt(Q), 
                                    #ca.sqrt(R), 
                                    Q,
                                    R,
                                    #ca.sqrt(ca.inv(P0)),
                                    #ca.sqrt(P0),
                                    P0,
                                    #P0,
                                    diff_Q,
                                    L_k)
                #pr.disable()
                #s = io.StringIO()
                #sortby = SortKey.CUMULATIVE
                #ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
                #ps.print_stats()
                #pr.print_stats()
                
            except NameError:
                
                rl = Qlearning(mpc, mhe, **{"gamma": 0.99, "alpha": 0.03})
                b = 0
                del_theta = rl.step(mpc, 
                                    mhe, 
                                    ca.vertcat(params_init, x_N),
                                    #ca.sqrt(ca.inv(Q)), 
                                    #ca.sqrt(ca.inv(R)), 
                                    Q,
                                    R,
                                    #ca.sqrt(ca.inv(P0)),
                                    P0,
                                    #P0,
                                    diff_Q,
                                    L_k)
                del_P0_accum = np.zeros((P0.shape[0], P0.shape[1]))
            
            # reshape del_theta:
            del_P0 = del_theta.reshape((P0.shape[0], P0.shape[1]))
            
            #_P0 = ca.sqrt(ca.inv(P0))
            #P0 = ca.power(_P0, -2)
            #del_P0 = ca.power(_del_P0, -2)
            del_P0_diag = ca.diag(ca.DM(np.diag(np.array(del_P0))))
            #del_P0 = ca.diag(ca.DM(np.diag(np.array(del_theta))))
            
            if b == B:
            #P0 += del_P0_diag
                P0 += del_P0_accum
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
            
            ### EKF update of P0 ###
            # (should be N time steps lagged?)
            """
            x0 = ekf.estimate(
                              x0, 
                              y=y_meas, 
                              u=u_meas, 
                              r=data.iloc[0].values
                              )
            P0 = ekf.P_prev
            """
            #########################
        else:
            
            x0 = ekf.estimate(
                              x0, 
                              y=y_meas, 
                              u=u_meas, 
                              r=data.iloc[0].values
                              )

    """
    res = boptest.get_data(tf=K*boptest.h)
    ax = res.Ti.plot(color="k")
    ax1 = ax.twinx()
    res.phi_h.plot(ax=ax1, color="k", linestyle="--")
    ax.legend(["Ti"])
    ax1.legend(["phi_h"])
    # plot bounds:
    #bounds_plt = pd.concat([bounds]*days)
    bounds_plt = bounds.get_full(days)
    bounds_plt.index = res.index
    bounds_plt[("lb", "Ti")].plot(ax=ax, drawstyle="steps")
    bounds_plt[("ub", "Ti")].plot(ax=ax, drawstyle="steps")
    
    plt.show()    
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