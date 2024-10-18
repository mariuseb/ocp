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
from utils import prepare_data, ZEBData, quick_plot
from result_generator import ResultGenerator
from ocp.filters import KalmanDAE
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
        "z_nom": [1e-2,1e-1,1E6,1E6],
        "z_nom_b": [0]*4,
        "u_nom_b ": [289.15]*7 + [0]*7,
        "u_nom": [12]*7 + [1E3,1E3,1E3,1E3,10,10,1,1],
        "u_nom_b ": [289.15]*7 + [0]*8,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    A = 60
    
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
        "alpha_vent_sup": 1,
        "alpha_vent_ext": 1,
        "alpha_int_plugs": 1,
        "alpha_int_lig": 1  
    }
    
    for name, value in priors.items():
        param_guess[name]["init"] = value 
        param_guess[name]["lb"] = value*1E-3 
        param_guess[name]["ub"] = value*1E3 

    #param_guess["alpha_int_lig"]["ub"] = 1
    param_guess["alpha_vent_sup"]["ub"] = 1.1
    param_guess["alpha_vent_ext"]["ub"] = 1.1

    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    Data = ZEBData(data_path)
    Data.data.T_sup_air_219.loc["2023-12-06 14:30":"2023-12-06 20:00"] = np.nan
    Data.data.T_ext_air_219.loc["2023-12-06 14:30":"2023-12-06 20:00"] = np.nan
    Data.data.T_sup_air_219.loc["2023-12-18 06:58":"2023-12-18 17:34"] = np.nan
    Data.data.T_ext_air_219.loc["2023-12-18 06:58":"2023-12-18 17:34"] = np.nan
    """
    Hyper-parameters for run:
    """
    #start = pd.Timestamp("2024-01-01 00:00")
    start = pd.Timestamp("2024-01-01 00:00")
    #start = pd.Timestamp("2023-11-15 00:00")
    N_days = 14
    days = 14
    #N_days = 1
    #days = 1
    sampling_rate = "60min"
    plot = False
    cfg_path = os.path.join(
                            "configs", 
                            "2R2C_int_gains_sep_bal_vent_vent.json"
                            )
    ekf_config = os.path.join(
                              "configs",
                              "ekf_configs",
                              "2R2C_envelope_EKF_int_gains_sep_bal_vent_tvp_vent.json"
                              )

    dt, N = Data.get_meta_for_parest(
                                     start,
                                     days,
                                     sampling_rate
                                     )
    result_gen = ResultGenerator(
                        config=cfg_path,
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

    (fig, axes, train_metrics, val_metrics, params_hist) = \
        result_gen.half_day_validation_runner(ekf_config,
                                              start,
                                              N_days,
                                              days,
                                              param_guess,
                                              param_est,
                                              Data,
                                              plot=plot,
                                              prior_weight=1e-2, 
                                              journal_plot=True              
                                              )

    """
    SMALL_SIZE = 10
    MEDIUM_SIZE = 10
    BIGGER_SIZE = 12
    MARKERSIZE = 4
    LINEWIDTH=0.75

    plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
    plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
    plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
    plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
    plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
    plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
    plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title
    for n in range(N_days*2):
        #axes[n, 0].set_xticklabels([])
        #axes[n, 1].set_xticklabels([])
        if n > 0: # remove y-ticks:
            axes[0, n].set_yticklabels([])
            axes[1, n].set_yticklabels([])
        if n < N_days*2 - 1: # remove y-ticks:
            #pass
            twin = axes[0, n].get_shared_x_axes().get_siblings(axes[0,n])[0]
            twin.set_yticklabels([])
            twin = axes[1, n].get_shared_x_axes().get_siblings(axes[1,n])[0]
            twin.set_yticklabels([])
            #axes[0, n].set_ticklabels([])
            #axest[1, n].set_yticklabels([])
            
        axes[0, n].set_xticklabels([])
        axes[0, n].set_xlabel("")
        axes[1, n].set_xlabel("")
    fig.tight_layout()
    plt.show()
    ax = result_gen.val_res[["Ti_onestep"]].plot(linewidth=LINEWIDTH, drawstyle="steps-post") #, marker="v", markersize=MARKERSIZE)
    result_gen.val_res[["y1"]].plot(linewidth=LINEWIDTH, drawstyle="steps-post", linestyle="dashed", ax=ax) #, marker="<", markersize=MARKERSIZE)
    result_gen.val_res[["Ti_sim"]].plot(linewidth=LINEWIDTH, drawstyle="steps-post", linestyle="dashed", ax=ax, marker="*", markersize=MARKERSIZE)
    
    for ind in extra_inds:
        plt.axvline(x=ind, color='k', linewidth=0.5, label='axvline - full height')
    ax.legend(["$\\hat{x}_{k|k-1}$", "$y_{N}$", "$x_{K|K-M}$"])
    plt.show()
    """
    result_gen.make_journal_plot_alt("training_jan_2024")
    result_gen.make_data_plot_alt("training_jan_2024")
    result_gen.make_journal_plot_alt("half_day_jan_2024", training=False)
    #val_metrics.index = pd.Series(val_metrics.index).apply(lambda x: round(x, 2))
    val_metrics.index = range(len(val_metrics.index))
    metric_columns = ["mse", "rmse", "nrmse", "cv-rmse", "mbe", "r2"] 
    #pd.set_option("display.precision", 2)
    #print(val_metrics[metric_columns].to_latex( float_format="%.3f"))
    print(val_metrics[metric_columns].to_latex( float_format="%.3f"))
    print(train_metrics[metric_columns].to_latex( float_format="%.3f"))
    print(param_est)