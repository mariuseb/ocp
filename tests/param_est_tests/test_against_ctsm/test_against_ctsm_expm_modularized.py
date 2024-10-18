#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
#from ocp.param_est import ParameterEstimation
#from ocp.mhe import MHE
from ocp.estimation import Estimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from matplotlib import rc
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from pandas.plotting import autocorrelation_plot
from ocp.filters import KalmanBucy, KalmanDAE
from utils import prepare_data, ZEBData, quick_plot
from result_generator import ResultGenerator
from ocp.covar_solver_cont import CovarianceSolverContinuous
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    """
    Proof of concept for grey-box SYSID, ZEB Lab.
    Use room 219 first.
    """

    R_true = np.array([[-29.53697072]])
    Q_true = np.array(
                      [
                       [-7.37671488,  0.        ],
                       [ 0.        , -5.16612263]
                      ]
                      )


    cfg_path = os.path.join("configs", "2R2C_simple.json")
    #ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_int_gains_sep_bal_vent.json"
    ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_simple.json"
    #data_path = os.path.join("ZEBLab_jan_mar24_1m.csv")
    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    #data_path = os.path.join("ZEBLab_nov23_1m.csv")
    ekf = KalmanDAE(ekf_config)
    Data = ZEBData(data_path)

    ### for first pass:
    param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rea":
                    {
                        "init": 1e-1
                    },
                    "Ci":
                    {
                        "init": 1e6
                    },
                    "Ce":
                    {
                        "init": 1e6
                    },
                    "Ai":
                    {
                        "init": 10
                    },
                    "cp_air":
                    {
                        "init": 1,
                        "lb": 1,
                        "ub": 1
                    },
                    "alpha_vent_sup":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_vent_ext":
                    {
                        "init": 1E-4
                    },
                    "alpha_int":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_int_lig":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_int_plugs":
                    {
                        "init": 1,
    #                    "lb": 1E-3,
                        "ub": 1
                    }
    }


    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        #"z_nom": [1e-2,1e-1,1E6,1E6],
        #"z_nom_b": [0]*4,
        "u_nom": [12]*6 + [1E3,1E3,10],
        "u_nom_b ": [289.15]*6 + [0]*3,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    A = 60
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ai": 10, # m²
        "alpha_vent_sup": 1,
        "alpha_vent_ext": 1,
        "alpha_int_plugs": 1,
        "alpha_int_lig": 1  
    }
    
    for name, value in priors.items():
        param_guess[name]["init"] = value 
        if not name.endswith("_a"):
            param_guess[name]["lb"] = value*1E-3 
            param_guess[name]["ub"] = value*1E3 
        #else:
        #    param_guess[name]["lb"] = -value*1E3 
        #    param_guess[name]["ub"] = value*1E3 

    #param_guess["alpha_int_lig"]["ub"] = 1
    param_guess["alpha_vent_sup"]["ub"] = 1.1
    param_guess["alpha_vent_ext"]["ub"] = 1.1
    
    results = {}
    #start = pd.Timestamp("2024-01-01 00:00")
    #start = pd.Timestamp("2023-11-15 00:00")
    #start = pd.Timestamp("2023-12-02 00:00")
    start = pd.Timestamp("2024-01-01 00:00")
    
    alpha0 = 0.5
    #alpha0 = 0.1
    decay_rate = 0.2
    params_hist = pd.DataFrame(columns=list(param_guess.keys()))
    plot = True
    
    # clean P_rad_219:
    Data.data.P_rad_219[Data.data.P_rad_219 < 0] = 0
    #Data.data.P_rad_219 = Data.data.P_rad_219.shift(-1)
    
    stop = start + pd.Timedelta(days=1) 
    y_data = Data.get_dataset(start=start, stop=stop)
    y_data = y_data.groupby(pd.Grouper(freq='5min')).mean().dropna()

    covar_solver = CovarianceSolverContinuous(
        ekf_config,
        cfg_path,
        y_data,
        param_guess
    )
    params = pd.read_csv("parameters.csv", index_col=0).squeeze()
    _params = params.loc[covar_solver.param_est.dae.p].values
    one_step_pred_sd = pd.read_csv("one_step_pred_sd.csv", index_col=0)
    # needed for P0 guess:
    P0 = np.diag(one_step_pred_sd.iloc[0].values**2)
    
    x0_guess = np.array([20.48625, 18.56523])
    
    #P_guess = np.array(ca.DM.eye(ekf.dae.n_x)).flatten()
    #P_guess = np.diag([3532.547, 3581.484]).flatten()
    P0_guess = P0.flatten()
    Q_guess = np.array(ca.DM.eye(ekf.dae.n_x)).flatten()*-10
    R_guess = np.array(ca.DM.eye(ekf.dae.n_y)).flatten()*-10
    
    Q, R, P0 = covar_solver.solve(
                                  y_data, 
                                  _params,
                                  x0_guess,
                                  P0_guess,
                                  Q_guess,
                                  R_guess
                                  )
    
    print(Q.round(8) == Q_true.round(8))
    print(R.round(8) == R_true.round(8))
                                  
