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
    x0 = np.array([305.15])

    Q, R, P0, lbp, ubp, p0 = coord.controller.get_estimation_parameters()
    y_data = pd.read_csv("test.csv", index_col=0)
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
    # : scaling, P0, Q, R, costate_prior, x, v, p, p0, dQdp
    est = coord.controller.estimator
    # test:
    #hsolver = est.solver.factory('h', est.solver.name_in(), ['hess:f:p:p'])
    jac_solver = est.sqp_solver.factory('h', est.solver.name_in(), ['jac:x:p'])
    # 
    jac_x_p_val = jac_solver( 
        x0=est.x0,
        lbg=est.lbg, # option for path-constraints?
        ubg=est.ubg, # --"--
        lbx=est.lbx,
        ubx=est.ubx,
        #p=ca.veccat(_P0, covar, ca.vertcat(param_guess, x_N))
        p=est.p_val
    )["jac_x_p"]

    solver_kwargs = dict(
        x0=est.x0,
        lbg=est.lbg, # option for path-constraints?
        ubg=est.ubg, # --"--
        lbx=est.lbx,
        ubx=est.ubx,
        #p=ca.veccat(_P0, covar, ca.vertcat(param_guess, x_N))
        p=est.p_val
    )

    _jac_x_p_val = est.get_jac_p_x0_nlp_p(
        **solver_kwargs
    )

    """
    Now, what are the sensitivies of p, x0 w.r.t (P0, Q0, R0)?
    They can be exctracted as follows:
    """
    start = est.nlp_parser.vars["x"]["range"]["a"]
    x_range = (start, start + est.n_x)
    start = est.nlp_parser.vars["p"]["range"]["a"]
    p_range = (start, start + est.n_p)
    jac_x0_p = jac_x_p_val[x_range[0]:x_range[1], :]
    jac_p_p = jac_x_p_val[p_range[0]:p_range[1], :]
    
    #print(dQdp_val)
    
    # try to change P0 slightly:
    h = 1e-4
    P0[0,0] += h
    #P0[1,1] = 1e-2
    
    # solve:
    _sol, _params, _raw_sol = coord.controller.estimator.solve(
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
    
    

    # how much does 1st parameter change?
    print((_raw_sol["x"][p_range[0]] - raw_sol["x"][p_range[0]])/h)
    print(jac_p_p[0][0])
    print(_jac_x_p_val[1][0])
    
    print(coord)
