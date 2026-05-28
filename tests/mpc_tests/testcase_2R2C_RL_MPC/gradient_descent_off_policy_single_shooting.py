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
    
    coord = Coordinator(
        #"coordinator_mpc_mhe_single_shooting_unscaled.json"
        #"coordinator_mpc_mhe_single_shooting_simple_scaling.json"
        "coordinator_mpc_mhe_single_shooting_N=96.json"
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
    
    grad_f_p.append(
        ca.gradient(f, x)
    )
    
    p = ca.vertcat(*_p)
    F_grad_f_p = ca.Function(
        "gradFp",
        [x,u,p,r,y],
        [ca.vertcat(*grad_f_p)],
        ["x","u","p","r","y"],
        ["grad_f_p"]
    )
    #F_grad_f_p.generate('f.c')

    # TODO: obtain correct values here:
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
    y_data = pd.read_csv("data_p=0.5p*.csv", index_col=0)
    y_data = y_data[:-1]
    x_guess, last_x_guess = coord.controller.generate_x_guess(
        y_data
    ) 
    Q, R, P0, lbp, ubp, p0 = coord.controller.get_estimation_parameters()
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
    x, u, p, r, y = get_nlpsol_vals(
        coord.controller.estimator
    )
    alpha = 1e-4
    grad_f_p_buffer = pd.DataFrame(columns=names + ["Ti", "Te"])
    k = 0
    while True:
        """
        Gradient descent solver:
        """        
        # eval gradient:
        # NOTE: only (x, p) changes each iteration:
        """
        x, u, p, r, y = get_nlpsol_vals(
            coord.controller.estimator
        )
        """
        grad_f_p_eval = np.array(
            F_grad_f_p(
                x, u, p, r, y    
            )
        ).flatten()
        inf_norm_grad = max(
            abs(
                grad_f_p_eval
            )
        )
        # GD steps:
        p = p - alpha*grad_f_p_eval[0:len(p)]
        x = x - alpha*grad_f_p_eval[len(p):]
        # add to buffer:
        grad_f_p_buffer.loc[k] = grad_f_p_eval
        print("\r", end='')
        #print("\033[2A", end="")
        #print("\033[1A", end="")
        print("%s: Gradient solve %s. ||df/dx||_∞ : %s" % \
            (
                datetime.now().strftime('%Y-%m-%d %H:%M:%S'), \
                str(k+1),
                inf_norm_grad
            ), 
            flush=True, end='')
        #print("\033[1A", end="")
        k += 1
    print(coord)
    
    

