#from ast import Param
from sysid.param_est import MPC
import numpy as np
import json
import casadi as ca
import sysid.dae as dae
import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint

pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option('display.width', 1000)

if __name__ == "__main__":
    
    cfg_path = "2R2C_MPC.json"
    
    data = pd.read_csv("data/MPC_open_loop_test.csv", index_col=0)
    N = len(data)
    dt = data.index[1] - data.index[0]
    """
    params from sysid
    {
    'Ai': 1.1059672260410933,
    'Ce': 1328602.3889595442,
    'Ci': 265684.08023168304,
    'Rea': 0.05802319706174586,
    'Rie': 0.0076640644144334805
    }
    
    {'Ai': 24.737700973356706,
    'Ce': 34369824.43630946,
    'Ci': 18410162.88441206,
    'Rea': 2.422295506220097,
    'Rie': 0.2992415849374104}
        
    {'Ai': 79.74990321028896,
    'Ce': 36727730.098839864,
    'Ci': 69299540.2951021,
    'Rea': 0.30505068447324885,
    'Rie': 0.5273836270276967}
    
    {'Ai': 69.06802862429473,
    'Ce': 17850476.345011726,
    'Ci': 25668359.385177102,
    'Rea': 0.17388954066535392,
    'Rie': 0.13935995905515083}
    
    {'Ai': 76.99401283628858,
    'Ce': 26836768.315925296,
    'Ci': 62673561.834388,
    'Rea': 0.23917930774084062,
    'Rie': 0.3552039051978394}
        
        
    {'Ai': 25.24175536842973,
    'Ce': 34788336.997017704,
    'Ci': 18355314.326669514,
    'Rea': 2.4724722774267383,
    'Rie': 0.30153421605592834}
    
    {'Ai': 5.53054284895422,
    'Ce': 6644341.559550903,
    'Ci': 1328608.5782424035,
    'Rea': 0.011603856649445713,
    'Rie': 0.001532631195210798}
    
    params = ca.DM([0.002,
                    0.01,
                    5E6,
                    2E7,
                    12])
        
    """
    params = ca.DM([0.0015,
                    0.0116,
                    1.33E6,
                    6.64E6,
                    5.53])
    
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    # define r - references for OCP problem.
    #N = 
    #data = data.iloc[0:2]
    
    mpc = MPC(
              config=cfg_path,
              N=N,
              dt=dt
              ) # to remove, replace with N
    
    x0 = np.array([291.15, 291.15])
    #lbx = np.array([290.15]*(len(data)*2))
    #ubx = np.array([296.15]*(len(data)*2))
    lbx = np.array([290.15, 10]*(N-1))
    ubx = np.array([296.15, 500]*(N-1))
    
    # provide lbx, ubx as dataframes:
    
    # TODO: slacks on comfort constraints:
    
    # provide x0, state bounds
    sol = mpc.solve(
                    data,
                    x0=x0,
                    lbx=lbx,
                    ubx=ubx,
                    params=params
                    )

    #pprint(params)
    
    ax = sol["Ti"].plot(color="grey")
    #ax = y_data["Ti"].plot(color="black", linestyle="dashed")
    #ax.legend(["Estimated", "True"])
    #plt.show()
    
    #assert(ca.norm_inf(p_sol-true_params)<1e-8)