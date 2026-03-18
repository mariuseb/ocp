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

def get_dQdp(est):
    nlp = est.nlp
    dQdp_expr = ca.gradient(nlp["f"], nlp["p"])
    dQdp = ca.Function(
        "dQdp",
        [
            est.P0, est.Q, est.R, \
            est.costate_prior, est.get_nlp_var("x"), \
            est.get_nlp_var("v"), est.integrator.p, \
            est.get_nlp_var("y"), est.get_nlp_var("u"), est.get_nlp_var("r")
        ],
        [dQdp_expr],
        ["P0", "Q", "R", "costate_prior", "x", "v", "p", "y", "u", "r"], 
        ["dQdp"]
    )
    return dQdp_expr, dQdp

def eval_dQdp(
    scaling, P0, Q, R, x, v, p, p0, y, u, r, x_N, dQdp
):
    #x_N = (x[-1] - scaling["x_nom_b"])/scaling["x_nom"]
    #x_N = (x_N - scaling["x_nom_b"])/scaling["x_nom"]
    p_scaled = p0/get_scale(p0)
    res = dQdp(
        P0, Q, R, 
        np.concatenate([p_scaled, x_N]), 
        (x - scaling["x_nom_b"])/scaling["x_nom"], 
        v, 
        p_scaled,
        y, u, r.reshape((int(r.shape[0]/y.shape[0]), y.shape[0]))
    )
    return res


if __name__ == "__main__":
    
    coord = Coordinator(
        "coordinator_mpc_mhe_wrong_model_no_arrival_cost.json"
    )
    x0 = np.array([305.15])
    """
    rewards:
    """
    expr, dQdp = get_dQdp(
        coord.controller.estimator
    )
    dQ_cols = list(
        map(lambda x: "dQdp[" + str(x) + "]", \
        range(coord.controller.estimator.nlp["p"].shape[0]))
    )
    buffer = pd.DataFrame(
        columns=["r"] + dQ_cols
    )
    
    """
    unwrapped run-loop:
    """
    alpha = 1e-4
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
            Q, R, P0, lbp, ubp, p0 = coord.controller.get_estimation_parameters()
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
        buffer.loc[k, "r"] = \
            (obs[0] - coord.controller.preds[k]["Ti"].iloc[1])**2
        # store gradients:
        if coord.controller.re_estimation_clause(coord.controller.i-1):
            # : scaling, P0, Q, R, costate_prior, x, v, p, p0, dQdp
            est = coord.controller.estimator
            # test:
            #hsolver = est.solver.factory('h', est.solver.name_in(), ['hess:f:p:p'])
            #grad_solver = est.solver.factory('h', est.solver.name_in(), ['grad:f:p'])
            # 
            dQdp_val = eval_dQdp(
                est.scale_dict, est.P0_val, \
                np.array([1]), np.array([1]), \
                sol["Ti"].values[0], \
                sol["v1"].values, \
                params.values, \
                est.p0, \
                #sol[est.y_names].values, \
                #sol[est.u_names].values, \
                #sol[est.r_names].values
                est.bounds["y"]["x0"], \
                est.bounds["u"]["x0"], \
                est.bounds["r"]["x0"], \
                est.x_N_val, \
                dQdp,
                
            )
            print(dQdp_val)
            """
            grad_f_p_val = grad_solver( 
                x0=est.x0,
                lbg=est.lbg, # option for path-constraints?
                ubg=est.ubg, # --"--
                lbx=est.lbx,
                ubx=est.ubx,
                #p=ca.veccat(_P0, covar, ca.vertcat(param_guess, x_N))
                p=est.p_val
            )
            print(grad_f_p_val)
            """
            #######################################################
        obs = coord.controller.x0_from_obs(
            k, 
            obs
        )
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
