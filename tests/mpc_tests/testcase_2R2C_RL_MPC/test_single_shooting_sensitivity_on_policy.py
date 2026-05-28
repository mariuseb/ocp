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
rc('mathtext', default='regular')
if __name__ == "__main__":
    
    """
    rng = np.random.default_rng(np.random.MT19937(seed=0))
    gen = rng.multivariate_normal(
        [0,0],
        [[1,0],[0,1]]
    )
    print(gen)
    """
    
    
    coord = Coordinator(
        #"coordinator_mpc_mhe_single_shooting_unscaled.json"
        #"coordinator_mpc_mhe_single_shooting_simple_scaling.json"
        "coordinator_mpc_mhe_single_shooting.json"
    )
    x0 = np.array([293.15, 293.15])
    #_p = coord.controller.estimator.get_nlp_var("p")
    x = coord.controller.estimator.get_nlp_var("x")
    u = coord.controller.estimator.get_nlp_var("u")
    r = coord.controller.estimator.get_nlp_var("r")
    y = coord.controller.estimator.get_nlp_var("y")
    f = coord.controller.estimator.nlp["f"]
    names = ["Rie", "Rea", "Ci", "Ce"]
    _p = []
    grad_f_p = []
    for name in names:
        p_symbol = getattr(
            coord.controller.estimator.integrator.dae, name
        )
        _p.append(
            p_symbol
        )
        grad_f_p_ = ca.gradient(f, p_symbol)    
        grad_f_p.append(grad_f_p_)
    
    p = ca.vertcat(*_p)
    F_grad_f_p = ca.Function(
        "gradFp",
        [x,u,p,r,y],
        [ca.vertcat(*grad_f_p)],
        ["x","u","p","r","y"],
        ["grad_f_p"]
    )
    #F_grad_f_p.generate('f.c')

    def get_nlpsol_vals(ocp):
        x = ocp.x0[ocp.nlp_parser.vars["x"]["range"]["a"]:
            ocp.nlp_parser.vars["x"]["range"]["b"]]
        u = ocp.x0[ocp.nlp_parser.vars["u"]["range"]["a"]:
            ocp.nlp_parser.vars["u"]["range"]["b"]]
        p = ocp.x0[ocp.nlp_parser.vars["p"]["range"]["a"]:
            ocp.nlp_parser.vars["p"]["range"]["b"]]
        r = (ocp.x0[ocp.nlp_parser.vars["r"]["range"]["a"]:
             ocp.nlp_parser.vars["r"]["range"]["b"]]).reshape((ocp.N, ocp.n_r)).T
        y = (ocp.x0[ocp.nlp_parser.vars["y"]["range"]["a"]:
            ocp.nlp_parser.vars["y"]["range"]["b"]]).reshape((ocp.N, ocp.n_y)).T
        return x, u, p, r, y
        
    
    """
    unwrapped run-loop:
    """
    alpha = 1e-4
    obs, _ = coord.env.reset()
    if obs is not None: # first x0 is passed:
        obs = x0
    K = int(coord.days*24*int(3600/coord.dt))
    grad_f_p_buffer = pd.DataFrame(columns=names)
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
            coord.controller.estimator.presolve(
                y_data,
                p0,
                lbp=lbp,
                ubp=ubp,
                x_guess=x_guess,
                covar=ca.veccat(Q, R),
                codegen=False,
                P0=P0,
                x_N=last_x_guess
            )
            """
            Gradient descent solver:
            """        
            # eval gradient:
            x, u, p, r, y = get_nlpsol_vals(
                coord.controller.estimator
            )
            grad_f_p_eval = np.array(
                F_grad_f_p(
                    x, u, p, r, y    
                )
            ).flatten()
            # add to buffer:
            grad_f_p_buffer.loc[k] = grad_f_p_eval
            
            """
            # normalize params:
            params = coord.controller.params/coord.controller.mpc.p_nom
            # gradient descent:
            params = params - alpha*grad_f_p_eval
            # un-normalize:
            params = params*coord.controller.mpc.p_nom
            # set values:
            coord.controller.estimator.p0 = params
            # from t = k, the parameters are:
            coord.controller.params_history.loc[k, :] = params
            # set parameters globally on agent:
            coord.controller.params = params
            # set parameters on filter:
            coord.controller.filter.filter.params = params
            """
            
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
    # get all data for sysid tests:
    y_data = coord.controller.get_y_data(
        coord.env,
        coord.controller.i,
        include_all=True,
        backshift=coord.env.maps.u,
        integrate_replace=coord.controller.integrate_replace
    )
    y_data.to_csv("data_p=0.5p*.csv", index=True)
    # get env result:
    coord.res = coord.env.get_results(
        coord.days*24*int(3600/coord.dt)*coord.dt
    )
    
    fig, axes, res = coord.plot_temperatures()
    plt.show()
    
    #fig, axes = coord.plot_one_step_predictions(res)
    #plt.show()

    print(coord)
    
    

