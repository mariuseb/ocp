#from ast import Param
import numpy as np
import casadi as ca
import matplotlib.pyplot as plt
from matplotlib import rc
#import os
#from pathlib import Path
#from ocp.mpc_agent import MPCAgent>
#from ocp.boptestGymEnv import BoptestGymEnv
#from ocp.customGymEnv import CustomGymEnv
import pandas as pd
from ocp.coordinator import Coordinator
from datetime import datetime
from ocp.ocp import get_scale
rc('mathtext', default='regular')


if __name__ == "__main__":
    
    coord = Coordinator(
        "coordinator_mpc_mhe_wrong_model_no_arrival_cost.json"
    )
    x0 = np.array([293.15])
    """
    rewards:
    """
    dQ_cols = list(
        map(lambda x: "dQdp[" + str(x) + "]", \
        range(coord.controller.estimator.nlp["p"].shape[0]))
    )
    buffer = pd.DataFrame(
        columns=["r", "Q(s_k, a_k)", "V(s_k+1)", "td-error", "td-target", "P[0,0]", "P[1,1]", "P[2,2]"] + dQ_cols
    )
    est = coord.controller.estimator
    """
    unwrapped run-loop:
    """
    #alpha = 1e2
    #alpha = 1e-2
    alpha = 1
    gamma = 0.99
    B = 9600
    H = 12
    #B = 1
    P0 = np.eye(3)*0
    #Q = np.eye(1)*1e-1
    #R = np.eye(1)*1e-1
    # new values for Q, R:
    Q = np.eye(1)*0
    R = np.eye(1)*0
    P0_step = np.eye(3)*0
    R_step = np.eye(1)*0
    Q_step = np.eye(1)*0
    #P0[2,2] = 0
    obs, _ = coord.env.reset()
    if obs is not None: # first x0 is passed:
        obs = x0
    K = int(coord.days*24*int(3600/coord.dt))
    steps = {}
    b = 0
    for k in range(K):
        # TODO: forecast optional:
        forecast = coord.env.get_forecast(
            coord.controller_dt,
            coord.controller_horizon
        )
        # temp. re-direct of stdout:
        #with open(os.devnull, 'w') as fnull:
            #with redirect_stdout(fnull):
        if coord.controller.re_estimation_clause(coord.controller.i):
            # estimate, set params:
            # estimate, set params:
            _Q, _R, _P0, lbp, ubp, p0 = coord.controller.get_estimation_parameters()
            y_data = coord.controller.get_y_data(
                coord.env,
                coord.controller.i,
                backshift=coord.env.maps.u,
                integrate_replace=coord.controller.integrate_replace
            )
            x_guess, last_x_guess = coord.controller.generate_x_guess(
                y_data
            )
            # solve:
            sol, params, raw_sol = coord.controller.estimator.solve(
                                        y_data,
                                        p0,
                                        lbp=lbp,
                                        ubp=ubp,
                                        x_guess=x_guess,
                                        covar=ca.veccat(Q, R),
                                        #codegen=False,
                                        return_raw_sol=True,
                                        P0=P0,
                                        #x_N=x_guess[-1,-coord.estimator.n_x:]
                                        x_N=last_x_guess
                                        ) 
            # store solution:
            coord.controller.ests[k] = sol
            # only change parameters if estimator succeeded:
            if coord.controller.estimator.solver.stats()["success"]:
                coord.controller.estimator.p0 = params.values
                # from t = k, the parameters are:
                coord.controller.params_history.loc[k, :] = params
                # set parameters globally on agent:
                coord.controller.params = params.values
                # set parameters on filter:
                coord.controller.filter.filter.params = params.values
                # print status:
                status = "succeeded"
            else:
                status = "failed"
            print("\r", end='\n')
            #print("\033[1A", end="")
            #print("Estimator solve %s 
            print("%s: Estimator solve %s %s" % \
                    (
                     datetime.now().strftime('%Y-%m-%d %H:%M:%S'), \
                     str(k+1),
                     status
                     ), 
                    flush=True, end='')
            print("\033[1A", end="")
            
        action, _ = coord.controller.predict(
            obs, 
            forecast
        )
        coord.validation_callback(k)
        if coord.controller.mpc.solver.stats()["success"]:
            status = "succeeded"
        else:
            status = "failed"
        print("\r", end='')
        #print("\033[2A", end="")
        #print("\033[1A", end="")
        print("%s: Controller solve %s of %s %s" % \
            (
                datetime.now().strftime('%Y-%m-%d %H:%M:%S'), \
                str(k+1),
                str(K),
                status
                ), 
            flush=True, end='')
        #print("\033[1A", end="")
        obs, reward, terminated, truncated, info = coord.env.step(
            action
        )
        # store reward:
        """
        lb = coord.controller.mpc.lbx[1]
        ub = coord.controller.mpc.ubx[1]
        scaled_obs = (obs[0] - 289.15)/12
        scaled_act = float(action.iloc[0]/1000)
        r = 1E4*max( 
            min(scaled_obs - lb, 0), \
            max(scaled_obs - ub, 0)
        )**2 + scaled_act**2
        buffer.loc[k, "r"] = r
        """
        # store gradients: 
        if coord.controller.re_estimation_clause(coord.controller.i-1):
            kwargs = dict(
                x0=est.x0,
                lbg=est.lbg, # option for path-constraints?
                ubg=est.ubg, # --"--
                lbx=est.lbx,
                ubx=est.ubx,
                p=est.p_val
            )
            try:
                grad_f_p_val = grad_solver(
                    **kwargs
                )["grad_f_p"].toarray().flatten()
            except NameError:
                grad_solver = est.sqp_solver.factory(
                    'h', est.solver.name_in(), ['grad:f:p']
                )
                grad_f_p_val = grad_solver(
                    **kwargs
                )["grad_f_p"].toarray().flatten()

            buffer.loc[k, dQ_cols] = grad_f_p_val
            # store reward:
            """
            scaled_obs = (obs[0] - 289.15)/12
            scaled_act = action/1000
            lb = coord.controller.mpc.lbx[1]
            ub = coord.controller.mpc.ubx[1]
            r = 1E4*max( 
                min(scaled_obs - lb, 0), \
                max(scaled_obs - ub, 0)
            )**2 + scaled_act**2
            r = (
                obs[0] - coord.controller.preds[k]["Ti"].iloc[1]
            )**2
            """
            _r = (
                (obs[0] - 289.15)/12 - \
                (coord.controller.preds[k]["Ti"].iloc[1] - 289.15)/12
            )**2
            buffer.loc[k, "r_1step"] = _r
            # store Q(s,a):
            buffer.loc[k, "V(s_k+1)"] = V_k_plus = float(raw_sol["f"])
            # store for V(s_k+1):
            try:
                #buffer.loc[k, "td-target"] = td_target = gamma*V_k_plus + r
                buffer.loc[k, "Q(s_k, a_k)"] = Q_k = float(raw_sol_prev["f"])
                pred = (coord.controller.preds[k-H+1]["Ti"].iloc[:H] - 289.15)/12
                actual = (y_data[-H:].Ti - 289.15)/12
                buffer.loc[k-H, "r"] = ((pred.values - actual.values)**2).sum()
                #td_error = td_target - Q_k
                #buffer.loc[k, "td-error"] = td_error
                #buffer.loc[k,"P[0,0]"] = P0[0,0]
                #buffer.loc[k,"P[1,1]"] = P0[1,1]
                #buffer.loc[k,"P[2,2]"] = P0[2,2]
                #buffer.loc[k,"Q"] = Q[0,0]
                #buffer.loc[k,"R"] = R[0,0]
                #p_step = -alpha*td_error*grad_f_p_val
                # take online gradient steps on parameters:
                # step only on P0:
                #P0_step[0,0] += p_step[0]
                #P0_step[1,1] += p_step[4]
                #P0_step[2,2] += p_step[8]
                #Q_step[0,0] += p_step[9]
                #R_step[0,0] += p_step[10]
            except NameError:
                buffer.loc[k, "V(s_k+1)"] = np.nan
                buffer.loc[k, "td-error"] = np.nan             
            # store V(s+):
            #buffer.loc[k, "V(s_k+1)"] = V_k_plus = buffer.loc[k, "Q(s_k, a_k)"] + r
            #buffer.loc[k, "V(s_k+1)"] = V_k_plus =  + r   
            raw_sol_prev = raw_sol
            
            if (k + 2) % B == 0:
                if P0[0,0] + P0_step[0,0] > 0:
                    P0[0,0] += P0_step[0,0]
                else:
                    P0[0,0] = 1e-8
                if P0[1,1] + P0_step[1,1] > 0:
                    P0[1,1] += P0_step[1,1]
                else:
                    P0[1,1] = 1e-8
                if P0[2,2] + P0_step[2,2] > 0:
                    P0[2,2] += P0_step[2,2]
                else:
                    P0[2,2] = 1e-8
                if R[0,0] + R_step[0,0] > 0:
                    R[0,0] += R_step[0,0]
                if Q[0,0] + Q_step[0,0] > 0:
                    Q[0,0] += Q_step[0,0]
                #R += R_step
                steps[b] = {
                    "P0": P0_step,
                    "Q": Q_step,
                    "R": R_step
                }
                b += 1
                P0_step = np.eye(3)*0
                R_step = np.eye(1)*0
                Q_step = np.eye(1)*0
            
        obs = coord.controller.x0_from_obs(
            k, 
            obs
        )
        #if k == 190:
            #P0 = np.eye(3)*1E5
            #P0[2,2] = 0
            #print("head")
        
    # analysis:
    
    for k in range(est.N-1,est.N-1+len(buffer)):
        Q_k = buffer.loc[k, "Q(s_k, a_k)"]
        V_k_plus = buffer.loc[k, "V(s_k+1)"]
        r = buffer.loc[k, "r"]
        td_error = r + gamma*V_k_plus - Q_k
        buffer.loc[k, "td-error"] = td_error
        #buffer.loc[k, "param_step"] = alpha*td_error*buffer.loc[k, "dQdp[0]"]
    """
    gamma = 1
    alpha = 1
    buffer.loc[:, "V(s_k+1)"] = buffer.loc[:, "Q(s_k, a_k)"].shift(1)[:-1] - buffer.loc[:, "r"][1:]
    #buffer.loc[:, "V(s_k+1)"] = buffer.loc[:, "Q(s_k, a_k)"] + buffer.loc[:, "r"]
    # check only 1 element:
    buffer.loc[:, "param_step"] = 0
    """
    
    # get env result:
    coord.res = coord.env.get_results(
        coord.days*24*int(3600/coord.dt)*coord.dt
    )
    fig, axes, res = coord.plot_temperatures()
    plt.show()
    
    #coord.write_result()
    ax = buffer[["Q(s_k, a_k)"]].plot(drawstyle="steps-post")
    buffer[["V(s_k+1)"]].plot(drawstyle="steps-post", ax=ax)
    buffer[["td-error"]].plot(drawstyle="steps-post", ax=ax)
    plt.show()
    
    
    hist = coord.controller.params_history
    hist["Ria_act"] = 1e-2
    hist["Ci_act"] = 1e6
    hist["Ria_act"].loc[672:] = 2e-2
    hist["Ci_act"].loc[672:] = 2e6

    hist_no_RL = pd.read_csv("params_hist_B=96_no_RL.csv", index_col=0)

    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    kwargs = {"drawstyle": "steps-post"}
    hist_no_RL[["Ria"]].plot(ax=ax, **kwargs, color="k")
    hist[["Ria"]].plot(ax=ax, **kwargs, linestyle="dashed")
    hist[["Ria_act"]].plot(ax=ax, **kwargs)
    #buffer.r.plot(ax=ax, color="r", **kwargs)
    #ax1 = ax.twinx()
    ax = axes[1]
    hist_no_RL[["Ci"]].plot(ax=ax, **kwargs, color="k")
    hist[["Ci"]].plot(ax=ax, **kwargs, linestyle="dashed")
    hist[["Ci_act"]].plot(ax=ax, **kwargs)
    plt.show()
    
    hist.to_csv("params_hist_B=96_RL_revised.csv", index=True)
    #hist_RL = pd.read_csv("params_hist_B=96.csv", index_col=0)
    #fig, axes = coord.plot_one_step_predictions(res)
    #plt.show()
    
    #params_hist = pd.read_csv("params_history_P0=1E3.csv", index_col=0)
    #fig, axes = plt.subplots(1,1,sharex=True)
    #params_hist["Ci"].plot(ax=axes, **kwargs)
    #coord.controller.params_history["Ci"].plot(ax=axes, **kwargs)
    #plt.show()
    
    
    #coord.controller.params_history[["Ci", "Ria"]].to_csv("params_history_P0=1E3.csv")

    print(coord)
