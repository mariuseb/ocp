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
    Q[0,0] = -100
    P0[0,0] = -100
    P0[1,1] = -100
    P0[2,2] = -100
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
    # store p at time instant:
    raw_sol["p"] = est.p_val
    # 
    grad_f_x = est.get_grad_f_x( 
        #x0=est.x0,
        raw_sol["x"],
        raw_sol["p"]
    )

    """
    sanity check: is it close to zero? 

    NB! Arrival cost to -high, Q to -high

    yes, close to zero.

    we will see if this is enough.
    """ 

    print(grad_f_x)