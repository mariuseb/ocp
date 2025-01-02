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
    _sol = pd.read_csv("solution_LTV_nov_2023_daytime_15min.csv", index_col=0).squeeze()
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
    params["alpha_vent_ext"] = param_guess["alpha_vent_ext"]["init"]
    _params = params.loc[ekf.dae.p].values
    
    """
    Proof-of-correctness for
    Kalman filter implementations.
    """
    x0 = params.loc[["Ti0", "Te0"]].values
    #P0 = np.diag(params_sd.loc[["Ti0", "Te0"]].values**2)
    #P0 = np.diag(one_step_pred_sd.loc[1].values**2)
    params["alpha_vent_ext"] = param_guess["alpha_vent_ext"]["init"]
    _params = params.loc[ekf.dae.p].values
    
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "z_nom": [1e-2,1e-1,1E6,1E6],
        "z_nom_b": [0]*4,
        #"p_nom": OCP.get_scale(_params),
        "p_nom": [1e-2]*4 + [1e6]*4 + [1,1,1e-3,1,1],
        "u_nom": [12]*7 + [1E3,1E3,1E3,1E3,10,10,1,1,1],
        "u_nom_b ": [289.15]*7 + [0]*9,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"P_nom": [[1e-6,1e-6],[1e-6,1e-2]]  
        "P_nom": [[1e-3,1e-3],[1e-3,1e-3]]  
    }
    
    covar_solver = CovarianceSolverContinuous(
        ekf_config,
        cfg_path,
        y_data,
        param_guess,
        method="single_shooting",
        **kwargs
    )
    # set z vals:
    _sol = _sol[:len(y_data)]
    _sol.index = y_data.index
    y_data[covar_solver.param_est.z_names] = _sol[covar_solver.param_est.z_names]
    
    x0_guess = params.loc[["Ti0", "Te0"]].values
    P0 = np.eye(2)*1e-3 # + 1e-2
    P0_guess = P0.flatten()
    Q_guess = np.array(
        ca.veccat(
                  ca.DM.eye(ekf.dae.n_x),
                  ca.DM.eye(ekf.dae.n_x)
                  )
        ).flatten()*-1
    R_guess = np.array(ca.DM.eye(ekf.dae.n_y)).flatten()*-1
    
    _params = params.loc[covar_solver.param_est.dae.p].values
    
    Qs = {}
    
    sol, Q_df, R = covar_solver.solve(
                                    y_data, 
                                    _params,
                                    x0_guess,
                                    P0_guess,
                                    Q_guess,
                                    R_guess,     
                                    )
    Qs["0"] = {
               "Q": Q_df,
               "R": R,
               "sol": sol
              }

    # need to simulate (one day) to find next P0:
    ekf = KalmanBucy(ekf_config)
    M = 97
    F = ekf.one_sample_feedback_adj
    F_map = F.mapaccum("simulator", M, [0,1], [3,7])
    # simulate:
    res = F_map(
        x_0=x0,
        #z0=Z,
        P_0=sol[["p11", "p12", "p21", "p22"]].values.reshape((2,2)),
        u=y_data[ekf.dae.u_names][0:M].values.T,
        #u_shift=y_data[ekf.dae.u_names][1:M+1].values.T,
        r=y_data[ekf.dae.r_names][0:M].values.T,
        p=ca.repmat(_params,1,M),
        y=y_data[ekf.dae.y_names][0:M].values.T,
        Q=ca.repmat(Q_df.values.flatten(),1,M),
        #Q=ca.repmat(Qval,1,M),
        R=ca.repmat(R.flatten(),1,M)
    ) 
    P0 = res["P_10"][:,-ekf.n_x:]

    # second solve:

    start = pd.Timestamp("2023-11-16 00:00")
    stop = start + pd.Timedelta(days=1) 
    y_data, dt, N  = Data.get_dataset(
                              start=start,
                              stop=stop,
                              sampling_rate="15min"
                              )
    
    H = np.eye(9)*1E-3
    y_data[covar_solver.param_est.z_names] = _sol[covar_solver.param_est.z_names]
    
    # exchange P0 constraint: # know it is last:
    P0 = np.array(P0).flatten()
    covar_solver.exchange_P0_constraint(P0)
    
    sol, Q_df, R = covar_solver.solve(
                                    y_data, 
                                    _params,
                                    x0_guess,
                                    P0,
                                    Q_df.values.flatten(),
                                    R.flatten(),     
                                    H=H
                                    )
    Qs["1"] = {
               "Q": Q_df,
               "R": R,
               "sol": sol
              }
    
    # third solve:
    
    res = F_map(
        x_0=x0,
        #z0=Z,
        P_0=sol[["p11", "p12", "p21", "p22"]].values.reshape((2,2)),
        u=y_data[ekf.dae.u_names][0:M].values.T,
        #u_shift=y_data[ekf.dae.u_names][1:M+1].values.T,
        r=y_data[ekf.dae.r_names][0:M].values.T,
        p=ca.repmat(_params,1,M),
        y=y_data[ekf.dae.y_names][0:M].values.T,
        Q=ca.repmat(Q_df.values.flatten(),1,M),
        #Q=ca.repmat(Qval,1,M),
        R=ca.repmat(R.flatten(),1,M)
    ) 
    P0 = res["P_10"][:,-ekf.n_x:]

    # second solve:

    start = pd.Timestamp("2023-11-17 00:00")
    stop = start + pd.Timedelta(days=1) 
    y_data, dt, N  = Data.get_dataset(
                              start=start,
                              stop=stop,
                              sampling_rate="15min"
                              )
    
    H = np.eye(9)*1E-3
    y_data[covar_solver.param_est.z_names] = _sol[covar_solver.param_est.z_names]
    
    # exchange P0 constraint: # know it is last:
    P0 = np.array(P0).flatten()
    covar_solver.exchange_P0_value(P0)
    
    sol, Q_df, R = covar_solver.solve(
                                    y_data, 
                                    _params,
                                    x0_guess,
                                    P0,
                                    Q_df.values.flatten(),
                                    R.flatten(),     
                                    H=H
                                    )
    Qs["2"] = {
               "Q": Q_df,
               "R": R,
               "sol": sol
              }
    
    
    print(sol)
    
    
    
