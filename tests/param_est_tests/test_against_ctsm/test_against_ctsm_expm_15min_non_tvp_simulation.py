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
                    "2R2C_simple.json"
                    )
    #
    #ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_simple.json"
    #ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_int_gains_sep_bal_vent.json"
    
    ekf_config = os.path.join(
                              "configs",
                              "ekf_configs",
                              "2R2C_envelope_EKF_int_gains_sep_bal_vent_tvp_vent.json"
                              )
    ekf_config = os.path.join(
                              "configs",
                              "ekf_configs",
                              "2R2C_envelope_EKF_int_gains_sep_bal_vent_tvp_vent_covar_tvp.json"
                              )
    #data_path = os.path.join("ZEBLab_jan_mar24_1m.csv")
    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    #data_path = os.path.join("ZEBLab_nov23_1m.csv")
    #ekf = KalmanDAE(ekf_config)
    Data = ZEBData(data_path)

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
    F = ekf.one_sample_feedback_adj
    # multiple shooting discretization:
    M = N - 1
    F_map = F.mapaccum("simulator", M, [0,1], [3,7])
    """
    Proof-of-correctness for
    Kalman filter implementations.
    """
    x0 = params.loc[["Ti0", "Te0"]].values
    #P0 = np.diag(params_sd.loc[["Ti0", "Te0"]].values**2)
    #P0 = np.diag(one_step_pred_sd.loc[1].values**2)
    params["alpha_vent_ext"] = param_guess["alpha_vent_ext"]["init"]
    _params = params.loc[ekf.dae.p].values
    Rval = np.array(params["e11"])
    Qval = np.concatenate(
                [   
                np.diag(params.loc[["p11", "p22"]]),
                np.diag(params.loc[["p11_vent", "p22_vent"]])
                ]
            )
    #Qval = np.diag(np.ones(2)*-1)
    res = F_map(
        x_0=x0,
        #z0=Z,
        P_0=P0,
        u=y_data[ekf.dae.u_names][0:M].values.T,
        #u_shift=y_data[ekf.dae.u_names][1:M+1].values.T,
        r=y_data[ekf.dae.r_names][0:M].values.T,
        p=ca.repmat(_params,1,M),
        y=y_data[ekf.dae.y_names][0:M].values.T,
        Q=ca.repmat(Qval.flatten(),1,M),
        #Q=ca.repmat(Qval,1,M),
        R=ca.repmat(Rval,1,M)
    ) 
    x_pred = pd.DataFrame(
                          data=np.array(res["x_10"]).T,
                          columns=["Ti", "Te"],
                          )
    x_pred["Ti_correct"] = one_step_pred["Ti"].iloc[:len(x_pred)]
    n_x = ekf.dae.n_x
    P_hat = pd.DataFrame(
                         data=np.array(res["P_10"].reshape((n_x*n_x, M))).T,
                         columns=[
                                  "p" + str(j) + str(i)
                                  for j in range(1,n_x+1)
                                  for i in range(1,n_x+1)
                                  ],
                         )
    P_hat = np.sqrt(P_hat)
    P_hat["p11_true"] = one_step_pred_sd["Ti"]
    P_hat["p22_true"] = one_step_pred_sd["Te"]
    P_hat.index = y_data.index[:-1]
    # shorten by 1
    y_data = y_data[:-1]
    y_data_R = y_data_R[:-1]
    # loglik:
    P_hat["loglik"] = np.array(res["loglik"]).flatten()
    P_hat["loglik_R"] = y_data_R["loglik"]
    P_hat["e_k"] = np.array(res["e_k"]).flatten()
    
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    P_hat[["p11"]].plot(ax=ax,color="y")
    P_hat[["p11_true"]].plot(ax=ax, linestyle="dashed")
    ax1 = ax.twinx()
    y_data.stepQi.plot(ax=ax1, color="r", drawstyle="steps-post")
    y_data_R.stepQi.plot(ax=ax1, color="k", drawstyle="steps-post")
    ax.legend(loc="upper left")
    ax1.legend(["stepQi", "stepQi_R"], loc="upper right")
    
    # loglik:
    ax = axes[1]
    P_hat["loglik"].plot(ax=ax)
    P_hat["loglik_R"].plot(ax=ax)
    ax.legend(["loglik", "loglik_R"])
    
    plt.show()

    print(sum(P_hat["loglik"]))    
    print(P_hat)
