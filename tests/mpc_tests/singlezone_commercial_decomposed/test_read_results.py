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

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
        
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("mpc_configs", "6R4C_MPC_ENV_no_CO2.json")
    mhe_cfg = os.path.join("mhe_configs", "6R4C_MHE_ENV_no_CO2.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "6R4C_EKF_ENV_no_CO2.json")

    params_hvac = pd.read_csv("HVAC_model_latest.csv", index_col=0)
    #params_hvac = pd.read_csv("HVAC_DAE_model_latest.csv", index_col=0)
    params_env = pd.read_csv("envelope_model_latest_6R4C.csv", index_col=0)
    #params_env = pd.read_csv("envelope_model_latest_6R4C.csv", index_col=0)
    params_CO2 = pd.read_csv("CO2_model.csv", index_col=0)
    params_CO2.rename(index={"c": "c1"}, inplace=True)
    params = pd.concat([params_hvac, params_env, params_CO2])
    _params = params[~params.index.duplicated(keep='first')]
    params = _params.to_dict()["0"]
    params_dict = {k: {"init": v} for k, v in params.items()}

    kwargs = {
        "x_nom": [12,12,12,12],
        "x_nom_b": [289.15,289.15,289.15,289.15],
        "z_nom": [1E6,1],
        "z_nom_b": [0,0],
        "r_nom": [12,300,1E6,1E6,1E6,1],
        "r_nom_b": [289.15,0,0,0,0,0],
        "u_nom": [1],
        "u_nom_b ": [0],
        #"y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        #"y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        #"slack": True
        "slack": False
    }

    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params_dict, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    N = 24
    boptest_filename = "boptest_results_MPC_EKF_N=%s.csv" % \
                       (str(N, ))
    x_model_filename = "model_predictions_MPC_EKF_N=%s.csv" % \
                       (str(N, ))
    res = pd.read_csv(boptest_filename, index_col=0)
    x_model = pd.read_csv(x_model_filename, index_col=0)
    
    fig, axes = plt.subplots(3,2, sharex=False)
    #res = res.iloc[:-1]
    x_model = x_model
    x_model.index = res.index
    
    for name, ax in zip(mpc.x_names, axes.flatten()):
        try:
            x_model[name].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
            res[name].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75, drawstyle="steps-post")
        except KeyError:
            pass
        ax.set_title(name)
        ax.set_xticklabels([])
    #fig.tight_layout()
    plt.show()
    print(mpc)