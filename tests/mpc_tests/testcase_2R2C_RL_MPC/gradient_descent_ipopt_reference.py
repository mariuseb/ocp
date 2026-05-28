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
        "coordinator_mpc_mhe_multiple_shooting.json"
    )
    x0 = np.array([293.15, 293.15])
    # estimate, set params:
    Q, R, P0, lbp, ubp, p0 = coord.controller.get_estimation_parameters()
    y_data = pd.read_csv("data_p=0.5p*.csv", index_col=0)
    y_data = y_data[:-1]
    x_guess, last_x_guess = coord.controller.generate_x_guess(
        y_data
    ) 
    sol, params, raw_sol = coord.controller.estimator.solve(
        y_data,
        p0,
        lbp=lbp,
        ubp=ubp,
        x_guess=x_guess,
        covar=ca.veccat(Q, R),
        return_raw_sol=True,
        P0=P0,
        x_N=last_x_guess
    )
    print(coord)
    
    

