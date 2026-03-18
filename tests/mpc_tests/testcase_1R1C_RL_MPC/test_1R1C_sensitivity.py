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
    grad_solver = est.sqp_solver.factory('h', est.solver.name_in(), ['grad:f:p'])
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
    grad_f_p_val = grad_solver( 
        x0=est.x0,
        lbg=est.lbg, # option for path-constraints?
        ubg=est.ubg, # --"--
        lbx=est.lbx,
        ubx=est.ubx,
        #p=ca.veccat(_P0, covar, ca.vertcat(param_guess, x_N))
        p=est.p_val
    )["grad_f_p"]
    #print(dQdp_val)
    
    # try to change P0:
    h = 1e-3
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
    print((_raw_sol["f"] - raw_sol["f"])/h)
    print(grad_f_p_val[0])
    
    print(coord)
