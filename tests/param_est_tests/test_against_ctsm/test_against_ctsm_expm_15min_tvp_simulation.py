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
    #ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_int_gains_sep_bal_vent.json"
    ekf_config = os.path.join(
                              "configs",
                              "ekf_configs",
                              "2R2C_envelope_EKF_int_gains_sep_bal_vent_tvp_vent_covar_tvp.json"
                              )
    #data_path = os.path.join("ZEBLab_jan_mar24_1m.csv")
    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    #data_path = os.path.join("ZEBLab_nov23_1m.csv")
    ekf = KalmanDAE(ekf_config)
    Data = ZEBData(data_path)

    params = pd.read_csv("parameters_LTV_nov_2023_daytime_15min.csv", index_col=0).squeeze()
    sol = pd.read_csv("solution_LTV_nov_2023_daytime_15min.csv", index_col=0).squeeze()
    _param_guess = params.to_dict()
    param_guess = dict()
    for k, v in _param_guess.items():
        param_guess[k] = {"init": v}
    
    start = pd.Timestamp("2023-11-15 00:00")
    stop = start + pd.Timedelta(minutes=15) 
    y_data, dt, N  = Data.get_dataset(
                              start=start,
                              stop=stop,
                              sampling_rate="15min"
                              )
    
    param_est = Estimation(config=cfg_path,
                N=N,
                dt=dt,
                param_guess=param_guess,
                arrival_cost=True
                )
    param_est.set_hess_obj()
    p0 = param_est.p0
      
    """
    y_data = y_data.bfill()
    y_data = y_data.groupby(pd.Grouper(freq='15min')).mean().dropna()
    y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
    
    Instead of using rule-of-thumb Q,R,
    use symbolic EKF to find optimal Q,R.
    
    Log-likelihood needs to be conditioned 
    on one-step ahead prediction now.
    
    Try to set up optimization problem here:
    """
    params = pd.read_csv("tvp_parameters.csv", index_col=0).squeeze()
    params_sd = pd.read_csv("tvp_parameter_sd.csv", index_col=0).squeeze()
    one_step_pred = pd.read_csv("tvp_one_step_pred.csv", index_col=0).shift(-1)
    one_step_pred.index = range(len(one_step_pred))
    one_step_pred_sd = pd.read_csv("tvp_one_step_pred_sd.csv", index_col=0)
    
    P0 = np.diag(one_step_pred_sd.iloc[0].values**2)
    
    one_step_pred_sd = one_step_pred_sd.shift(-1)
    one_step_pred_sd.index = range(len(one_step_pred_sd))
    one_step_pred_var =  one_step_pred_sd**2  # sd -> covar**2
    
    ekf = KalmanBucy(ekf_config)
    F = ekf.one_sample_feedback_adj
    # multiple shooting discretization:
    M = param_est.N - 1
    F_map = F.mapaccum("simulator", M, [0,1], [0,1])
    """
    Proof-of-correctness for
    Kalman filter implementations.
    """
    x0 = params.loc[["Ti0", "Te0"]].values
    #P0 = np.diag(params_sd.loc[["Ti0", "Te0"]].values**2)
    #P0 = np.diag(one_step_pred_sd.loc[1].values**2)
    params["alpha_vent_ext"] = param_guess["alpha_vent_ext"]["init"]
    _params = params.loc[param_est.dae.p].values
    Rval = np.array(params["e11"])
    Qval = np.concatenate(
                [   
                np.diag(params.loc[["p11", "p22"]]),
                np.diag(params.loc[["p11_vent", "p22_vent"]])
                ]
            )
    res = F_map(
        x0=x0,
        #z0=Z,
        P_prev=P0,
        u=y_data[param_est.u_names][0:M].values.T,
        r=y_data[param_est.r_names][0:M].values.T,
        p=ca.repmat(_params,1,M),
        y=y_data[param_est.y_names][1:M+1].values.T,
        Q=ca.repmat(Qval.flatten(),1,M),
        R=ca.repmat(Rval,1,M)
    ) 
    x_pred = pd.DataFrame(
                          data=np.array(res["x_pred"]).T,
                          columns=["Ti", "Te"],
                          )
    x_pred["Ti_correct"] = one_step_pred["Ti"].iloc[:len(x_pred)]
    n_x = ekf.dae.n_x
    P_hat = pd.DataFrame(
                         data=np.array(res["P_apriori"].reshape((n_x*n_x, M))).T,
                         columns=[
                                  "p" + str(j) + str(i)
                                  for j in range(1,n_x+1)
                                  for i in range(1,n_x+1)
                                  ],
                         )
    P_hat = np.sqrt(P_hat)
    P_hat["p11_true"] = one_step_pred_sd["Ti"]
    P_hat["p22_true"] = one_step_pred_sd["Te"]
    print(P_hat)
