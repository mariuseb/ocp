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
from ocp.estimation import Estimation
from ocp.coordinator import Coordinator
from datetime import datetime
from ocp.ocp import get_scale
rc('mathtext', default='regular')


if __name__ == "__main__":
    
    coord = Coordinator(
        "coordinator_mpc_mhe_wrong_model.json"
    )
    x0 = np.array([293.15])

    est = coord.controller.estimator
    
    dJ_cols = list(
        map(lambda x: "dJdp[" + str(x) + "]", \
        range(coord.controller.estimator.nlp["p"].shape[0]))
    )
    P0_dim = est.n_x + est.n_p
    P0_cols = list(
        map(lambda x: "dJdp[" + str(x) + "]", \
        range((P0_dim)**2))
    )
    dP0_cols = list(
        map(lambda x: "dP0[" + str(x) + "]", \
        range((P0_dim)**2))
    )
    #buffer = pd.DataFrame(
    #    columns=["P[0,0]", "P[1,1]", "P[2,2]"] + dJ_cols
    #)
    buffer = pd.DataFrame(
        columns=dJ_cols
    )
    steps = pd.DataFrame(
        columns=dP0_cols
    )
    sol_kwargs = dict()
    raw_sols = dict()
    dx_dp = dict()
    grad_f_x = dict()
    H_step_preds = dict()
    

    pred_scaling = coord.controller.scaling
    pred_scaling["slack"] = False

    param_guess = {
        "Ci": {
            "init": 1e6,
        },
        "Ria": {
            "init": 1e-2
        }
    }

    """
    This is the predictive estimator:
    """

    pred_est = Estimation(
        config="mhe_configs/1R1C_MHE_det.json",
        param_guess=param_guess,
        need_sensitivities=True,
        truncate_scaling=False,
        arrival_cost=False,
        **pred_scaling
    )
    #alpha = 1e2
    #alpha = 1e-2
    alpha = 1e-1
    gamma = 0.99
    B = 1
    H = 8
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
    b = 0
    for k in range(K):
        # TODO: forecast optional:
        forecast = coord.env.get_forecast(
            coord.controller_dt,
            coord.controller_horizon
        )
        forecast["Ti_ref"] = 296.15
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
                integrate_replace=coord.controller.integrate_replace,
                from_boptest=True
            )
            y_data["Ti_ref"] = 296.15
            x_guess, last_x_guess = coord.controller.generate_x_guess(
                y_data
            )
            #lbp = ubp = p0
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

        # store gradients: 
        if coord.controller.re_estimation_clause(coord.controller.i-1):
            # TODO: store this at each time instant:
            kwargs = dict(
                x0=est.x0,
                lbg=est.lbg, # option for path-constraints?
                ubg=est.ubg, # --"--
                lbx=est.lbx,
                ubx=est.ubx,
                p=est.p_val
            )
            raw_sol["p"] = np.array(
                est.p_val
            ).flatten()
            raw_sol["covar"] = np.array(
                ca.veccat(Q, R)
            ).flatten()
            # store:
            sol_kwargs[k] = kwargs
            raw_sols[k] = raw_sol
            # dx/d(nlp_p) can be evaluated at once:
            dx_dp[k] = est.get_jac_p_x0_nlp_p(
                **kwargs
            )
            #H_step_preds[k] = (coord.controller.preds[k]["Ti"].iloc[:H] - 289.15)/12
            H_step_preds[k] = coord.controller.preds[k]["Ti"].iloc[:H]
            # dJ_pred/dx is delayed by H steps
            try:
                """
                assemble input for the H-step predictor.
                what is tricky now is: what must be changed
                from the raw solution, and what stays. 

                Initial feeling: we keep (x0, p) --> x_N
                We assume perfect forecast, but need to
                obtain data in the interval [k, k+H].
                """

                # NOTE: we do not use this
                # directly, this is just to 
                # check if we are far enough
                # along
                H_step_pred = H_step_preds[k-H]
                y_data_pred = y_data[-H-1:-1]

                """
                Pre-solve prediction estimator with
                most recent y_data. 

                Fill in (x0, p) from raw_sol at k-H.
                
                This will give a gradient that points
                in direction of increased prediction 
                performance w.r.t (x0, p).
                """
                pred_est.presolve(
                    y_data_pred,
                    p0,
                    covar=ca.veccat(Q, R),
                    lbp=lbp,
                    ubp=ubp,
                    lbx=est.lbx,
                    ubx=est.ubx,
                    P0=P0,
                    x_N=np.array([]),
                    x_guess=y_data_pred["Ti"].values.reshape((pred_est.N, 1))
                )
                # TODO: verify correctness of this:
                pred_est.x0[pred_est.x_range[0]:pred_est.x_range[1]] = \
                    raw_sols[k-H]["x"][est.x_range[0]:est.x_range[1]]
                pred_est.x0[pred_est.p_range[0]:pred_est.p_range[1]] = \
                    np.array(raw_sols[k-H]["x"][est.p_range[0]:est.p_range[1]]).flatten()
                p_k_minus_H = raw_sols[k-H]["covar"]
                grad_f_x_val = pred_est.get_grad_f_x(
                    pred_est.x0,
                    p_k_minus_H
                )
                grad_f_x[k-H] = grad_f_x_val
                buffer.loc[k-H, :] = np.array(grad_f_x_val.T)@np.array(dx_dp[k-H])
                #print("success")
                if ((k + 1) % B == 0) and (k > est.N + B + H - 2): # do mini-batch over last B gradients:
                    # only step on P0 for now:
                    """
                    P0_step = (
                        buffer[P0_cols].iloc[-B:].sum()
                        #buffer[P0_cols].iloc[-B:].sum()/B
                    ).values.reshape(
                        (P0_dim, P0_dim)
                    ).astype(float)
                    """
                    P0_step = (
                        buffer[P0_cols].iloc[-B:].sum()
                        #buffer[P0_cols].iloc[-B:].sum()/B
                    ).values.astype(float)
                    #P0_step = np.clip(P0_step, -1, 1)
                    #P0_step = np.clip(P0_step, -0.05, 1)
                    P0 = P0 - alpha*P0_step.reshape(
                        (P0_dim, P0_dim)
                    )
                    steps.loc[k, :] = alpha*P0_step
            #except (KeyError, ValueError):
            except KeyError:
                print("test")

        obs = coord.controller.x0_from_obs(
            k, 
            obs
        )
        
    # analysis:
    """
    for k in range(est.N-1,est.N-1+len(buffer)):
        Q_k = buffer.loc[k, "Q(s_k, a_k)"]
        V_k_plus = buffer.loc[k, "V(s_k+1)"]
        r = buffer.loc[k, "r"]
        td_error = r + gamma*V_k_plus - Q_k
        buffer.loc[k, "td-error"] = td_error
        #buffer.loc[k, "param_step"] = alpha*td_error*buffer.loc[k, "dQdp[0]"]
    """

    # get env result:
    coord.res = coord.env.get_results(
        coord.days*24*int(3600/coord.dt)*coord.dt
    )
    fig, axes, res = coord.plot_temperatures()
    plt.show()
    
    #coord.write_result()
    
    hist = coord.controller.params_history
    hist["Ria_act"] = 1e-2
    hist["Ci_act"] = 1e6
    #hist["Ria_act"].loc[672:] = 2e-2
    #hist["Ci_act"].loc[672:] = 2e6

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
    
    #hist.to_csv("params_hist_meta_learning.csv", index=True)
    hist_no_RL = pd.read_csv("params_hist_no_meta_learning.csv", index_col=0)
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
