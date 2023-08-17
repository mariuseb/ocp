#from ast import Param
from ocp.mpc import MPC
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
    #mpc_cfg = os.path.join(opt_config_base, "1R1C_MPC_slack.json")
    mpc_cfg = os.path.join(opt_config_base, "1R1C_MPC_ref_track.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_idas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_map_test.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "1R1C_EKF.json")

    # pass in config?
    """
    params = ca.DM([0.0015,
                    0.0116,
                    1.33E6,
                    6.64E6,
                    5.53])
    params = ca.DM([
                    2.008534e-03,
                    1.126790e-02,
                    1.552069e+06,
                    8.145441e+06,
                    8.818424e+00
                    ])
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 5000,
        "r_nom": [12, 100],
        "r_nom_b": [289.15, 0],
        "y_nom": 12,
        "y_nom_b": 289.15,
        #"slack": True
        "slack": True
    }
    params = ca.DM([
                    1E-2,
                    1E6
                    ])
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        #"slack": True
        "slack": True
    }
    kwargs = {
        "x_nom": 300,
        "u_nom": 5000,
        "r_nom": 300,
        "y_nom": 300,
        #"slack": True
        "slack": True
    }
    """
    
    #params = ca.DM([
    #                0.008,
    #                1.2E6
    #                ])
    params = ca.DM([
                    0.01,
                    1E6
                    ])
    params = ca.DM([
                    0.009,
                    0.9E6
                    ])
    
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 5000,
        "r_nom": 12,
        "r_nom_b": 289.15,
        "y_nom": 12,
        "y_nom_b": 289.15,
        "slack": True
        #"slack": False
    }
    
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    
    mpc = MPC(config=mpc_cfg,
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
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([294.05])
    
    # sim horizon: 2 days
    days = 120
    K = days*24*bounds.t_h
    df = pd.Series()
    #alpha = 0.03
    #alpha = 0.03
    #alpha = 0.01
    alpha = 1E-3
    #df = pd.DataFrame(columns=list(map(lambda x: "lam_p_" + str(x), range(24))))
    lam_p_cols = list(map(lambda x: "lam_p_" + str(x), mpc.dae.dae.p()))
    #lam_w_cols = list(map(lambda x: "lam_wf_" + str(x), range(N)))
    lam_w_cols = []
    #lam_b_cols = list(map(lambda x: "lam_b_" + str(x), range(N)))
    lam_b_cols = list(map(lambda x: "lam_b_" + str(x), range(1)))
    lam_c_cols = list(map(lambda x: "lam_c_" + str(x), range(2)))
    lam_cols = lam_p_cols + lam_w_cols + lam_b_cols + lam_c_cols
    #lam_cols = lam_p_cols + lam_b_cols
    b_cols = list(map(lambda x: "b_" + str(x), range(1)))
    c_cols = list(map(lambda x: "c_" + str(x), range(2)))
    p_cols = b_cols + c_cols
    cols = b_cols + c_cols + ["R_k"]
    df = pd.DataFrame(columns=cols)
    lam_df = pd.DataFrame(columns=lam_cols)
    lam_df_qrqp = pd.DataFrame(columns=lam_cols)
    #p_val = np.repeat([0.01], N)

    p_start, p_stop = mpc.nlp_parser["p"]["range"]["a"], mpc.nlp_parser["p"]["range"]["b"]
    B = 1E4
    B = 1
    b = 0
    #delta_p = 0
    #TD_0 = 0                
    delta_p = 0
    delta_theta = 0
    TD_0_p = 0
    TD_0_theta = 0
    gamma = 0.99
    # l1 slack weights:
    #p_val = np.repeat([1E2], N)
    # constraint bias:
    #p_val = np.append(p_val, np.repeat([0], N))
    #p_val = np.repeat([0], 3)
    p_val = np.array([0, 0.01, 0.01])
    df.loc[0, p_cols] = p_val
    # Need slack formulation ??
    
    # get the sensitivities of objective function w.r.t parameters manually:
    """
    p = mpc.nlp["p"]
    V = ca.Function("V_p", [p, mpc.nlp["x"], mpc.nlp["f"]],
                      ["p", "x"], ["V"])
    V_p = ca.gradient(V, p)
    """
    
    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        sol, u, x0, raw_sol = mpc.solve(
                                        data[0:mpc.N],
                                        x0=x0,
                                        lbx=lbx,
                                        ubx=ubx,
                                        params=params,
                                        return_raw_sol=True,
                                        codegen=True,
                                        p_val=p_val                             
                                        )
        lbx, ubx, ref = bounds.get_bounds(k+1, mpc.N)
        x0 = sol[mpc.x()].iloc[1].values
        # back-shift index:
        data.index -= mpc.dt
        # bootstrap, solve MPC with model prediction of next step:
        sol_RL, u_RL, x0_RL, raw_sol_RL = mpc.solve(
                                                    data[1:(mpc.N+1)],
                                                    x0=x0,
                                                    lbx=lbx,
                                                    ubx=ubx,
                                                    params=params,
                                                    return_raw_sol=True,
                                                    codegen=True,
                                                    p_val=p_val                             
                                                    )
        
        # TD-0:
        diff_Q = gamma*raw_sol_RL["f"] - raw_sol["f"]
        # take efficiency into account:
        data, y_meas, u_meas = boptest.evolve(u=u*(1/0.99))
        
        # get sensitivities anew:
        raw_sol_qrqp = mpc.sqp_solver(x0=raw_sol["x"],
                                      lbx=mpc.lbx,
                                      ubx=mpc.ubx,
                                      lbg=mpc.lbg,
                                      ubg=mpc.ubg)
    
        #df.loc[k] = mpc.solver.stats()["t_wall_total"]
        
        # compute reward signal:
        #R_k = (u_meas/5000)**2 + 1E3*max(lbx[0] - y_meas, 0)**2 + 1E3*max(y_meas - ubx[0], 0)**2
        
        # Realization of stage cost, reward signal:
        R_k = 0.01*(u_meas/5000)**2 + (y_meas - 295.15)**2
        
        # what is the sensitivity of lagrangian w.r.t p/theta?
        #delta_p = raw_sol["lam_p"]
        
        if b < B: # batch learning, accumulate:
            #delta_p += raw_sol["lam_x"][p_start:p_stop]*mpc.scale
            # iterate on wf instead:
            delta_theta += raw_sol_qrqp["lam_p"]
            delta_p += raw_sol_qrqp["lam_x"][p_start:p_stop]*mpc.scale
            TD_0_theta += alpha*delta_theta*(R_k + diff_Q)
            TD_0_p += alpha*delta_p*(R_k + diff_Q)
            #delta_p += raw_sol["lam_x"][p_start:p_stop]
            b += 1
            
            
        if b == B:
            #params = params + alpha*delta_p
            #if sum(np.array(params - alpha*delta_p > ca.DM.zeros(params.shape[0])).flatten()) == len(mpc.dae.dae.p()):
            #if sum(np.array(params + TD_0 > ca.DM.zeros(params.shape[0])).flatten()) == len(mpc.dae.dae.p()):
                #params = params - alpha*delta_p
                #params = params + TD_0
                
            if sum(np.array(params + TD_0_p > ca.DM.zeros(params.shape[0])).flatten()) == len(mpc.dae.dae.p()):
                TD_0_p = np.array(TD_0_p).flatten()
                params = params + TD_0_p
            
            if sum(np.array(p_val[1:] + TD_0_theta[1:] > ca.DM.zeros(2)).flatten()) == 2:
                TD_0_theta = np.array(TD_0_theta).flatten()
                p_val = p_val + TD_0_theta
                    
                # No parameter update yet, just keep track of
                # sensitivities:
                #params = params
                
            delta_p = 0
            delta_theta = 0
            TD_0_p = 0
            TD_0_theta = 0
            b = 0
        
        if k == 24:
            print(df)
            
        #df.loc[k, lam_cols] = np.array(raw_sol["lam_x"][p_start:p_stop]*mpc.scale).flatten()
        #df.loc[k, lam_cols] = np.array(raw_sol["lam_x"][p_start:p_stop]).flatten()
        #df.loc[k, lam_p_cols] = np.array(raw_sol["lam_x"][p_start:p_stop]*mpc.scale).flatten()
        #df.loc[k, lam_w_cols + lam_b_cols] = np.array(raw_sol["lam_p"]).flatten()
        #df.loc[k+1, b_cols] = p_val
        df.loc[k+1, p_cols] = p_val
        df.loc[k, "R_k"] = R_k[0]
        lam_df.loc[k] = np.append(
                                  np.array(raw_sol["lam_x"][p_start:p_stop]).flatten(),
                                  np.array(raw_sol["lam_p"]).flatten()
                                  )
        lam_df_qrqp.loc[k] = np.append(
                                  np.array(raw_sol_qrqp["lam_x"][p_start:p_stop]).flatten(),
                                  np.array(raw_sol_qrqp["lam_p"]).flatten()
                                  )
        #alpha *= 0.50
        # take step on p:
        # policy gradient:
        #p_val = p_val - alpha*delta_p
        # Q-learning/SARSA: Need TD(0)-error
        #p_val = p_val - alpha*R_k*delta_p 
            
        x0 = y_meas
        
        """
        ekf.set_params(params)
        
        x0 = ekf.estimate(
                          x0, 
                          y=y_meas, 
                          u=u_meas, 
                          r=data.iloc[0].values
                          )
        """

    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    # plot reference for easy visualization
    ref = np.repeat([22], len(dt_index))
    axes[0].plot(dt_index, ref, color="r", linestyle="dashed")    
    plt.show()    
    fig.tight_layout()

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