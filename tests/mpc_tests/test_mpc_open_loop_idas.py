#from ast import Param
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from ocp.tests.utils import get_opt_config_path
import os
import ocp

pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option('display.width', 1000)

if __name__ == "__main__":
    
    
    cfg_path = os.path.join(get_opt_config_path(), "2R2C_MPC_map_test.json")
    cfg_path_idas = os.path.join(get_opt_config_path(), "2R2C_MPC_idas.json")
    data_path = os.path.join(ocp.__path__[0], "tests", "data", "MPC_open_loop_test.csv")
    
    data = pd.read_csv(data_path, index_col=0)
    #data = data[0:3]
    N = len(data)
    dt = data.index[1] - data.index[0]

    params = ca.DM([0.0015,
                    0.0116,
                    1.33E6,
                    6.64E6,
                    5.53])
    
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    # define r - references for OCP problem.
    #N = 
    #data = data.iloc[0:2]
    
    mpc_rk4 = MPC(
              config=cfg_path,
              N=N,
              dt=dt
              ) # to remove, replace with N
    
    x0 = np.array([291.15, 291.15])

    lbx = np.array([290.15, 10]*(N-1))
    ubx = np.array([296.15, 500]*(N-1))
    
    sol_rk4, u, x = mpc_rk4.solve(
                         data,
                         x0=x0,
                         lbx=lbx,
                         ubx=ubx,
                         params=params
                         )

    ax = sol_rk4["Ti"].plot(color="grey")
    
    mpc_idas = MPC(
              config=cfg_path_idas,
              N=N,
              dt=dt
              ) # to remove, replace with N
    
    sol_idas, u, x = mpc_idas.solve(
                         data,
                         x0=x0,
                         lbx=lbx,
                         ubx=ubx,
                         params=params
                         )

    ax = sol_idas["Ti"].plot(color="grey")
    