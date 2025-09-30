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
from ocp.filters import KalmanBucy
from ocp.utils import prepare_data, ZEBData, quick_plot
from result_generator import ResultGenerator, plot_residuals
from ocp.filters import KalmanDAE
from pandas.plotting import autocorrelation_plot
from utils import _solve_rosenbrock
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
    _solve_rosenbrock()
    param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rie_w": 
                    {
                        "init": 1e-2
                    },
                    "Rie_v": 
                    {
                        "init": 1e-2
                    },
                    "Rea":
                    {
                        "init": 1e-1
                    },
                    "Rea_w":
                    {
                        "init": 1e-1
                    },
                    "Rea_v":
                    {
                        "init": 1e-1
                    },
                    "Ci":
                    {
                        "init": 1e6
                    },
                    "Ci_w":
                    {
                        "init": 1e6
                    },
                    "Ci_v":
                    {
                        "init": 1e6
                    },
                    "Ce":
                    {
                        "init": 1e6
                    },
                    "Ce_w":
                    {
                        "init": 1e6
                    },
                    "Ce_v":
                    {
                        "init": 1e6
                    },
                    "Ai":
                    {
                        "init": 10
                    },
                    "Ai_high":
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
                    "alpha_occ":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 5
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
        "z_nom": [1e-2,1e-1,1E6,1E6,10],
        "z_nom_b": [0]*5,
        #"z_nom": [1e-2,1e-1,1E6,1E6],
        #"z_nom_b": [0]*4,
        "u_nom": [12]*7 + [1E3,1E3,1E3,1E3,10,10,1,1,1,1],
        "u_nom_b ": [289.15]*7 + [0]*10,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    A = 66
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rie_w": 0.250/A, # m²K / W 
        "Rie_v": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Rea_w": 2.250/A, # m²K / W 
        "Rea_v": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ci_w": 9.50*3600*A, # Wh / m²K
        "Ci_v": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ce_w": 112*3600*A, # Wh / m²K
        "Ce_v": 112*3600*A, # Wh / m²K
        "Ai": 10, # m²
        "Ai_high": 10, # m²
        "alpha_vent_sup": 1,
        "alpha_vent_ext": 1e-4,
        #"alpha_vent_sup": 1e-4,
        #"alpha_vent_ext": 1e-4,
        "alpha_int": 1,
        "alpha_occ": 1
    }
    for name, value in priors.items():
        #if name not in ("Ai", "alpha_int"):
        param_guess[name]["init"] = value 
        param_guess[name]["lb"] = value*1E-3 
        param_guess[name]["ub"] = value*1E3 
        """
        else: 
            param_guess[name]["init"] = value 
            param_guess[name]["lb"] = value*0.99
            param_guess[name]["ub"] = value*1.01
        """
            

    #param_guess["alpha_int_lig"]["ub"] = 1.0
    #param_guess["alpha_int_plugs"]["ub"] = 1.0
    param_guess["alpha_vent_sup"]["ub"] = 1.0
    param_guess["alpha_vent_ext"]["ub"] = 1.0
    param_guess["alpha_int"]["ub"] = 1.0
    param_guess["alpha_occ"]["ub"] = 1.0

    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    Data = ZEBData(data_path)
    Data.data.loc["2023-11-16 09:20":"2023-11-16 09:51", "T_219_TR2"] = np.nan
    Data.data.loc["2023-12-06 14:30":"2023-12-06 17:00", "T_sup_air_219"] = np.nan
    Data.data.loc["2023-12-08 08:00":"2023-12-08 09:15", "T_sup_air_219"] = np.nan
    Data.data.loc["2023-12-06 14:30":"2023-12-06 20:00", "T_ext_air_219"] = np.nan
    Data.data.loc["2023-12-18 06:58":"2023-12-18 17:34", "T_ext_air_219"] = np.nan
    
    """
    Hyper-parameters for run:
    """
    #start = pd.Timestamp("2024-01-01 00:00")
    start = pd.Timestamp("2023-11-15 00:00")
    #N_days = 14
    N_days = 14
    days = 14
    
    #N_days = 1
    #days = 1
    sampling_rate = "15min"
    plot = True
    cfg_path = os.path.join(
                            "configs", 
                            "2R2C_int_gains_sep_bal_vent_vent_solar_tvp.json"
                            )
    ekf_config = os.path.join(
                              "configs",
                              "ekf_configs",
                              "2R2C_envelope_EKF_int_gains_sep_bal_vent_tvp_vent_solar_tvp_covar_tvp.json"
                              )
    dt, N = Data.get_meta_for_parest(
                                     start,
                                     days,
                                     sampling_rate
                                     )
    result_gen = ResultGenerator(
                        config=cfg_path,
                        ekf_config=ekf_config,
                        params=param_guess,
                        slack=False,
                        dt=dt
                        )    
    param_est = Estimation(config=cfg_path,
                N=N,
                dt=dt,
                param_guess=param_guess,
                arrival_cost=True,
                **kwargs,
                )

    (fig, axes, train_metrics, val_metrics, params_hist, theta_hist) = \
        result_gen.var_day_validation_runner(ekf_config,
                                              start,
                                              N_days,
                                              days,
                                              param_guess,
                                              param_est,
                                              Data,
                                              plot=plot,
                                              prior_weight=1, 
                                              #prior_weight=1e-5, 
                                              journal_plot=True,
                                              sampling_rate=sampling_rate,
                                              covar_solve=False,
                                              num_segments=1,
                                              control_validation=False,
                                              reidentification=True
                                              #R=R,
                                              #Q=Q,
                                              #P0x=P0,
                                              #x0_opt=x0
                                              #covar_solve=False
                                              )
    
    res = result_gen.val_res
    prbs_res = pd.read_csv("prbs_val_nov.csv", index_col=0)
    prbs_res["Ti_sim"] = prbs_res["Ti_sim"].astype(float)
    
    result_gen.make_journal_plot_alt("whole_day_nov_2023", training=False, ref_result=prbs_res)  
      
    res = result_gen.val_res
    res["Ti_res"] = res["y1"] - res["Ti_onestep"]
    res["v1"] = res["y1"] - res["Ti_sim"]
    plot_residuals(res, res, "covar_non_opt")
    result_gen.make_data_plot_alt("training_data_nov_2023_day0")
    result_gen.make_journal_plot_alt("training_nov_2023_day0")
    result_gen.make_journal_plot_alt("training_nov_2023_day13", day=13)
    result_gen.make_data_plot_alt("training_data_nov_2023_day13", day=13)
    
#    result_gen.make_journal_plot_alt("whole_day_jan_2024", training=False)
    result_gen.residuals.to_csv("to_CTSMR/residuals_config1_dataset1.csv")
    params_hist.to_csv("params_config1_dataset1.csv")
    train_metrics.to_csv("metrics/train_metrics_config1_dataset1.csv")
    val_metrics.to_csv("metrics/val_metrics_config1_dataset1.csv")
      
    ax = Data.data.T_amb.plot() 
    ax1 = ax.twinx()
    Data.data.I_ver.plot(ax=ax1, color="y") 
    Data.data.I_hor.plot(ax=ax1, color="m")
    plt.show() 
    
    print(val_metrics)