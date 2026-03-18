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
        columns=["r", "Q(s_k, a_k)", "V(s_k+1)", "td-error"] + dQ_cols
    )
    est = coord.controller.estimator
    """
    unwrapped run-loop:
    """
    #alpha = 1e2
    alpha = 1e3
    gamma = 1
    P0 = np.eye(3)
    obs, _ = coord.env.reset()
    if obs is not None: # first x0 is passed:
        obs = x0
    K = int(coord.days*24*int(3600/coord.dt))
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
            Q, R, _P0, lbp, ubp, p0 = coord.controller.get_estimation_parameters()
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
            
        obs = coord.controller.x0_from_obs(
            k, 
            obs
        )
        
    # analysis:
    
    """
    gamma = 1
    alpha = 1
    buffer.loc[:, "V(s_k+1)"] = buffer.loc[:, "Q(s_k, a_k)"].shift(1)[:-1] - buffer.loc[:, "r"][1:]
    #buffer.loc[:, "V(s_k+1)"] = buffer.loc[:, "Q(s_k, a_k)"] + buffer.loc[:, "r"]
    # check only 1 element:
    buffer.loc[:, "param_step"] = 0
    for k in range(est.N-1,est.N-1+len(buffer)):
        Q_k = buffer.loc[k, "Q(s_k, a_k)"]
        V_k_plus = buffer.loc[k, "V(s_k+1)"]
        r = buffer.loc[k, "r"]
        td_error = r + gamma*V_k_plus - Q_k
        buffer.loc[k, "td-error"] = td_error
        buffer.loc[k, "param_step"] = alpha*td_error*buffer.loc[k, "dQdp[0]"]
    """
    
    # get env result:
    coord.res = coord.env.get_results(
        coord.days*24*int(3600/coord.dt)*coord.dt
    )

    fig, axes, res = coord.plot_temperatures()
    plt.show()
    
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    kwargs = {"drawstyle": "steps-post"}
    buffer.r.plot(ax=ax, color="r", **kwargs)
    ax1 = ax.twinx()
    coord.controller.params_history[["Ci"]].plot(ax=ax1, **kwargs)
    plt.show()
    
    #fig, axes = coord.plot_one_step_predictions(res)
    #plt.show()

    print(coord)
