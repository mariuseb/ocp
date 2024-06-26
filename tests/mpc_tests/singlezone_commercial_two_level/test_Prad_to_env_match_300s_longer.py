#from ast import Param
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF, KalmanDAE
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from copy import deepcopy
from ocp.functions import functions
from pprint import pprint
from ocp.param_est import ParameterEstimation

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

"""
Test ability of the reduced-order DAE-model:

    dx/dt = f_hvac(x, u, z)
        0 = g_hvac(x, u, z)
        
obtained via system identification, to match 
sequences of idealized energy flows to a 
building envelope without feedback. 

If one needs 'Prad_to_env_MPC', it is possible
to set up an open-loop optimal control problem
to generate a switching sequence to match this
as closely as possible as follows:

    min(Prad_to_env_MPC - Prad_to_env)

    s.t. 
    
    Prad_to_env - (Trad - Ti)/Rirad == 0
    and more equations..
    
With the model opbtained with 1min-level identification,
one should see small deviations.

"""    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()

    mpc_hvac_cfg = os.path.join("mpc_configs", "HVAC_MPC_no_CO2_adj_Tsup_300s_longer.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    params = pd.read_csv("HVAC_DAE_model_latest_Tsup_Tret_1min.csv", index_col=0)
    y_data = pd.read_csv("data_singlezone_commercial_normal_op_60s.csv", index_col=0)

    params.loc["Prad_to_env_lim"] = 1E6
    params.loc["Prad_to_env_MPC_1"] = 1E6
    params.loc["Prad_to_env_MPC_2"] = 1E6
    #params.loc["Trad_lim"] = 293.15
    _params = params.copy()
    params = _params.to_dict()["0"]
    params = {k: {"init": v} for k, v in params.items()}

    kwargs = {
        "x_nom": [12,12,12],
        "x_nom_b": [289.15,289.15,289.15],
        "z_nom": [1E6,10,1E6],
        "z_nom_b": [0]*3,
        "r_nom": [12,300,1E6,1E6,1E6,1,12],
        "r_nom_b": [289.15,0,0,0,0,0,289.15],
        "u_nom": [1],
        "u_nom_b ": [0],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        #"slack": True
        "slack": True
    }
    mpc_hvac = MPC(
                   config=mpc_hvac_cfg,
                   functions=deepcopy(functions),
                   param_guess=params, 
                   **deepcopy(kwargs)
                    )  # to remove, replace with N
    
    boptest = Boptest(
                      boptest_cfg,
                      name="singlezone_commercial"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    sol = pd.read_csv("HVAC_DAE_sol_latest_Tret_1min.csv", index_col=0)
    x0 = x0_hvac = sol.loc[0, ["Trad", "Tret", "Tsup"]].values
    
    lbx = np.array([280,280,280]*(mpc_hvac.N-1))
    ubx = np.array([340,340,340]*(mpc_hvac.N-1))
    
    params_hvac = mpc_hvac.p0
    #params_hvac[-1] = 194972.42237174
    params_hvac[-1] = 45000
    params_hvac[-2] = 45000
    
    """
    Test rad_val on grey-box model
    """
    start = 126000
    stop = 126000 + 3600*4
    #start = 270000
    #stop = 330000
    inds = [
            ndx for ndx in y_data.index
            if ndx % 300.0 == 0
            ]
    y_data = y_data.loc[inds]
    y_data = y_data.loc[start:stop]
    
    data = data[0:mpc_hvac.N+1]
    data["Ti"] = y_data["Ti"].iloc[0:mpc_hvac.N+1].values
    
    sol_hvac, u_hvac, x0_hvac = mpc_hvac.solve(
                                                data,
                                                x0=x0_hvac,
                                                lbx=lbx,
                                                ubx=ubx,
                                                params=params_hvac,
                                                codegen=False
                                                )
    
    u_hvac["ahu_pump_sup"] = 0.03
    u_hvac["ahu_pump_ret"] = 0.03
    
    N = mpc_hvac.N 
    
    for k in range(N-1):
        """
        Store r_pred before advancing:
        """
        u_hvac["rad_val"] = sol_hvac.loc[int(k % 300), "rad_val"]
        data, y_meas, u_meas = boptest.evolve(u=u_hvac,
                                              y_as_array=False,
                                              u_as_array=False)
        
    # get boptest results. check sum of Prad_to_env:
    res = boptest.get_data(tf=60*boptest.h)
    res["Prad_to_env"] = -res["Prad_to_env"]
    print(res)
    
    """
    How does it look?
    """
    
    res["Prad_to_env_model"] = sol_hvac["Prad_to_env_act"][1:].values
    res[["Prad_to_env", "Prad_to_env_model"]].plot()
    plt.show()
    
    sum_Prad = (res[["Prad_to_env", "Prad_to_env_model"]].sum()/3)
    
    print(res)           
    """
    Valve switching sequence obtained, test it
    on white-box emulator.
    """
    
