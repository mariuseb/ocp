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
from ocp.utils import prepare_data, ZEBData, quick_plot
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
    cfg_path = os.path.join(
                        "configs", 
                        "2R2C_int_gains_sep_bal_vent_vent.json"
                        )
    ekf_config = os.path.join(
                              "configs",
                              "ekf_configs",
                              "2R2C_envelope_EKF_int_gains_sep_bal_vent_tvp_vent_covar_tvp.json"
                              )
    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    ekf = KalmanDAE(ekf_config)
    Data = ZEBData(data_path)
    # clean P_rad_219:
    Data.data.P_rad_219[Data.data.P_rad_219 < 0] = 0
    
    params = pd.read_csv("parameters_LTV_nov_2023_daytime_15min.csv", index_col=0).squeeze()
    sol = pd.read_csv("solution_LTV_nov_2023_daytime_15min.csv", index_col=0).squeeze()
    _param_guess = params.to_dict()
    param_guess = dict()
    for k, v in _param_guess.items():
        param_guess[k] = {"init": v}
    
    start = pd.Timestamp("2023-11-15 00:00")
    stop = start + pd.Timedelta(days=1) 
    y_data, dt, N  = Data.get_dataset(
                              start=start,
                              stop=stop,
                              sampling_rate="15min"
                              )

    params = pd.read_csv("tvp_parameters.csv", index_col=0).squeeze()
    y_data_R = pd.read_csv("y_data_day0_R.csv", index_col=0)
    y_data_R.index = y_data.index
    params_sd = pd.read_csv("tvp_parameter_sd.csv", index_col=0).squeeze()
    one_step_pred = pd.read_csv("tvp_one_step_pred.csv", index_col=0).shift(-1)
    one_step_pred.index = range(len(one_step_pred))
    one_step_pred_sd = pd.read_csv("tvp_one_step_pred_sd.csv", index_col=0)
    
    # set stepQi:
    y_data["stepQi"] = y_data_R["stepQi"]
    
    P0 = np.diag(one_step_pred_sd.iloc[0].values**2)
    
    one_step_pred_sd = one_step_pred_sd.shift(-1)
    one_step_pred_sd.index = range(len(one_step_pred_sd))
    one_step_pred_var =  one_step_pred_sd**2  # sd -> covar**2
    
    ekf = KalmanBucy(ekf_config)
    #F = ekf.one_sample_feedback_adj
    # multiple shooting discretization:
    M = N - 1
    #F_map = F.mapaccum("simulator", M, [0,1], [0,1])
    """
    Proof-of-correctness for
    Kalman filter implementations.
    """
    x0_guess = params.loc[["Ti0", "Te0"]].values
    #P0 = np.diag(params_sd.loc[["Ti0", "Te0"]].values**2)
    #P0 = np.diag(one_step_pred_sd.loc[1].values**2)
    params["alpha_vent_ext"] = param_guess["alpha_vent_ext"]["init"]
    _params = params.loc[ekf.dae.p].values
    R_guess = np.array([params["e11"]])
    Q_guess = np.concatenate(
                [   
                np.diag(params.loc[["p11", "p22"]]),
                np.diag(params.loc[["p11_vent", "p22_vent"]])
                ]
            ).flatten()
    P0_guess = P0.flatten()

    covar_solver = CovarianceSolverContinuous(
        ekf_config,
        cfg_path,
        y_data,
        param_guess
    )
    # set z vals:
    sol = sol[:len(y_data)]
    sol.index = y_data.index
    y_data[covar_solver.param_est.z_names] = sol[covar_solver.param_est.z_names]
    
    #one_step_pred_sd = pd.read_csv("tvp_one_step_pred_sd.csv", index_col=0)
    # needed for P0 guess:
    #P0 = np.diag(one_step_pred_sd.iloc[0].values**2)
    """
    x0_guess = np.array([y_data.y1[0], y_data.y1[0]])
    P0_guess = P0.flatten()
    Q_guess = np.array(
        ca.veccat(
                  ca.DM.eye(ekf.dae.n_x),
                  ca.DM.eye(ekf.dae.n_x)
                  )
        ).flatten()*-1
    R_guess = np.array(ca.DM.eye(ekf.dae.n_y)).flatten()*-10
    Q, R, P0, x0 = covar_solver.solve(
                                  y_data, 
                                  _params,
                                  x0_guess,
                                  P0_guess,
                                  Q_guess,
                                  R_guess
                                  )
    """
    _params = params.loc[covar_solver.param_est.dae.p].values
    sol = covar_solver.solve(
                            y_data, 
                            _params,
                            x0_guess,
                            P0_guess,
                            Q_guess,
                            R_guess
                            )
    print(sol)
    """
    print(Q, R)
    print(x0)
    # get discrete-time equivalents for validation:
    Q_disc = np.array([[np.sqrt(np.exp(Q[0,0]))/np.sqrt(12), 0],
                       [0, np.sqrt(np.exp(Q[1,1]))/np.sqrt(12)]])
    R_disc = np.array([[np.sqrt(np.exp(R[0,0]))]])
    """
                                  
