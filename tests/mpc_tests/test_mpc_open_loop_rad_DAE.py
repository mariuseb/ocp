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
from ocp.functions import functions

pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option('display.width', 1000)

if __name__ == "__main__":
    
    
    cfg_path = os.path.join(get_opt_config_path(),
                            "2R2C_MPC_func.json")
    data_path = os.path.join(ocp.__path__[0],
                             "tests",
                             "data",
                             "MPC_open_loop_test.csv")
    
    data = pd.read_csv(data_path, index_col=0)
    #data = data[0:3]
    N = len(data)
    dt = data.index[1] - data.index[0]
    
    params = ca.DM([6.987636e-04,
                    3.184517e-03,
                    5.407161e+06,
                    4.533857e+07,
                    2.767623e+01,
                    3.915722e+01])
    
    x0 = np.array([293.15, 292.15])
    z0 = np.array([0])
    lbx = np.array([290.15, 10]*(N-1))
    ubx = np.array([296.15, 500]*(N-1))
    # provide lbx, ubx as dataframes:
    
    mpc = MPC(
            functions=functions,
            config=cfg_path,
            N=N,
            dt=dt
            ) # to remove, replace with N
    
    # add Tsup constraint: 
    # Tsup >= Ti for all t in T
    # TODO: method for extracting DAE-var from the NLP-problem:
    # e.g. Tsup = mpc.get("Tsup")
    # useful in e.g. adding constraints dynamically
    Tsup = mpc.get("Tsup")
    #Ti = mpc.get("Ti")[:-1]
    Ti = mpc.get("Ti")
    
    # create the constraint:
    g_add = Tsup - Ti
    
    # new function: mpc.prepare - then solve 
    
    mpc.prepare_solve(data,
                     x0=x0,
                     lbx=lbx,
                     ubx=ubx,
                     params=params
                     )
    
    #mpc.lbg = np.append(mpc.lbg, np.zeros(g_add.shape[0]))
    #mpc.ubg = np.append(mpc.ubg, np.array([np.inf]*g_add.shape[0]))
    #mpc.nlp["g"] = ca.vertcat(mpc.nlp["g"], g_add)
    mpc.add_h()
    # provide x0, state bounds
    sol, u, x = mpc._solve()

    #pprint(params)
    
    ax = sol["Ti"].plot(color="grey")
    
    reg_nonzero = functions["regNonZeroPower"]
    test = params[5]*reg_nonzero(244.15 - 290.15, 1.24, 0.05)
    print(test)
    #ax = y_data["Ti"].plot(color="black", linestyle="dashed")
    #ax.legend(["Estimated", "True"])
    #plt.show()
    
    # compute Ph by 'by hand'?
    
    #assert(ca.norm_inf(p_sol-true_params)<1e-8)