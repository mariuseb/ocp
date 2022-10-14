#from ast import Param
from sysid.param_est import MPC
import numpy as np
import json
import casadi as ca
import sysid.dae as dae
import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from boptest_api import Boptest
from pprint import pprint
from sysid.filters import EKF

pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option('display.width', 1000)

if __name__ == "__main__":
    
    mpc_cfg = "3R3C_MPC.json"
    boptest_cfg = "testcase5_config.json"
    ekf_cfg = "3R3C_EKF.json"

    """
            "Rie",
            "Rea",
            "Rih",
            "Ria",
            "Ci",
            "Ch",
            "Ce",
            "Ai",
            "Ae
    """
    # pass in config?
    params = ca.DM([
                    0.0006,
                    0.0057,
                    0.001,
                    0.1,
                    1668600.0,
                    4E5,
                    1.224E7,
                    10,
                    10])
    
    mpc = MPC(
              config=mpc_cfg
              #N=N,
              #dt=dt
              ) # to remove, replace with N
    
    ekf = EKF(ekf_cfg)
    # set params:
    ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="testcase5"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    x0 = np.array([293.05, 293.15, 298.15])
    # TODO: provide lbx, ubx as dataframes:
    lbx = np.array([290.15, 10, 10]*(N-1))
    ubx = np.array([297.15, 500, 500]*(N-1))
    

    # sim horizon: 2 days
    K = 2*24*4

    for k in range(K):
   
        sol, u, x0 = mpc.solve(
                               data,
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params
                               )
    
        data, y_meas, u_meas = boptest.evolve(u=u)
            
        x0 = ekf.estimate(
                          x0, 
                          y=y_meas, 
                          u=u_meas, 
                          r=data.iloc[0].values
                          )



    #pprint(params)
    #ax = sol["Ti"].plot(color="grey")
    res = boptest.get_data(tf=K*boptest.h)
    ax = res.TRooAir_y.plot(color="k")
    ax1 = ax.twinx()
    res.PHea_y.plot(ax=ax1, color="k", linestyle="--")
    ax.legend(["Ti", "phi_h"])
    plt.show()
    #ax = y_data["Ti"].plot(color="black", linestyle="dashed")
    #ax.legend(["Estimated", "True"])
    #plt.show()
    
    #assert(ca.norm_inf(p_sol-true_params)<1e-8)