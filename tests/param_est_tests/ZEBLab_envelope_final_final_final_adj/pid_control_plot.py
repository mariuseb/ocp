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
from ocp.mpc import MPC
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
import matplotlib.pyplot as plt
from copy import deepcopy
import matplotlib.dates as mdates
from ocp.functions import functions
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

SMALL_SIZE = 14
MEDIUM_SIZE = 16
BIGGER_SIZE = 16
MARKERSIZE = 5
LINEWIDTH=0.6

plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
plt.rc('axes', labelsize=SMALL_SIZE)    # fontsize of the x and y labels
plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title

if __name__ == "__main__":

    """
    Check of resampling facilities.
    """
    
    data_path = os.path.join("ZEBLab_nov23_1m.csv")
    Data = ZEBData(data_path)
    """
    Hyper-parameters for run:
    """
    #start = pd.Timestamp("2024-01-01 00:00")
    #start = pd.Timestamp("2023-11-23 04:00")
    #stop = start + pd.Timedelta(days=0.5) + pd.Timedelta(hours=1)
    #start = pd.Timestamp("2023-11-15 04:00")
    #stop = start + pd.Timedelta(days=0.5) + pd.Timedelta(hours=1)
    start = pd.Timestamp("2023-11-15 07:08")
    stop = pd.Timestamp("2023-11-15 11:30")
    #stop = start + pd.Timedelta(days=0.5) + pd.Timedelta(hours=1)
    #stop = start + pd.Timedelta(days=70) + pd.Timedelta(hours=1)
    
    test, dt, N = Data.get_dataset(
        start=start,
        stop=stop,
        sampling_rate="1min"
    )
    test.index = test.dt_index
    """
    Conceptual plot of PID-control.
    """
    kwargs = {
              "linewidth": LINEWIDTH,
              "markersize": MARKERSIZE,
              }
    test["delT"] = test.Ti - test.Tset
    #test["delT"][start:(start + pd.Timedelta(hours=2))] = np.nan
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    mark_freq = 30
    ax.plot(test.dt_index.values, 
            test.Ti.values,
            color="k",
            linestyle="dashed",
            markevery=list(range(0, int(len(test.dt_index.values)), mark_freq)),
            marker="s",
            drawstyle="steps-post",
            **deepcopy(kwargs))
    ax.plot(test.dt_index.values,
            test.Tset.values,
            color="k",
            drawstyle="steps-post",
            **deepcopy(kwargs))
    ax1 = ax.twinx()
    ax1.plot(test.dt_index.values,
             test.delT.values,
             color="k",
             markevery=list(range(int(mark_freq/2), int(len(test.dt_index.values)), mark_freq)),
             drawstyle="steps-post",
            # marker="*",
             marker="v",
             **deepcopy(kwargs))
    ax_lims = ax.get_ylim()
    ax_lims = ax.set_ylim([19, ax_lims[1] + 1])
    ax1_lims = ax1.get_ylim()
    ax1.set_yticks([0,2])
    #ax.set_ylim([ax_lims[0], ax_lims[0] + (ax1_lims[1] - ax1_lims[0])])
    #ax1.set_ylim([ax1_lims[0], ax1_lims[0] + (ax_lims[1] - ax_lims[0])])
    #ax1.set_ylim([ax1_lims[1] - (ax_lims[1] - ax_lims[0]), ax1_lims[1]])
    ax1.set_ylim([-1 - 1, (ax_lims[1] - ax_lims[0] - 2)])
    ax.legend(["$T_{i}$", "$T_{set}$"], ncol=2, loc="upper left")
    ax1.legend(["$\Delta{T}_{set,i}$"], loc="upper right")
    ax.set_ylabel("Temperature [\\textdegree C]")
    
    
    ax = axes[1]
    ax.plot(test.dt_index.values, 
            (test.V_flow_219/test.V_flow_219.max()).values,
            color="k",
            drawstyle="steps-post",
            **deepcopy(kwargs))
    ax.plot(test.dt_index.values, 
            (test.val_pos_219).values/100,
            color="k",
            linestyle="dashed",
            drawstyle="steps-post",
            **deepcopy(kwargs))
    ax.set_ylabel("[-]")
    ax.legend(["$V_{flo}$", "$u_{val}^{contr}$"], ncol=2, loc="upper right")
    for label in ax.get_xticklabels(which='major'):
        label.set(rotation=0, horizontalalignment='right')
    for label in ax.get_xticklabels(which='minor'):
        label.set(rotation=0, horizontalalignment='right')
    #ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d %H:%M'))
    #ax.xaxis.set_minor_formatter(mdates.DateFormatter('%b-%d %H:%M'))
    ax.xaxis.set_major_formatter(mdates.DateFormatter('%H:%M'))
    ax.xaxis.set_minor_formatter(mdates.DateFormatter('%H:%M'))
    """
    #ax.minorticks_off()
    # Rotates and right-aligns the x labels so they don't crowd each other.
    """
    fig.tight_layout()
    plt.savefig("plots/existing_control.png")
    plt.show()
     
    # PID simulation test
    cfg = os.path.join("mpc_configs", "LimPID_symb.json")
    kwargs = {
        "slack": False
    }
    
    params = np.array([0.1, 500])
    y_data = test
    N = len(y_data)
    param_est = Estimation(config=cfg,
                        param_guess=params,
                        N=N,
                        dt=dt,
                        functions=functions, 
                        **deepcopy(kwargs))  # to remove, replace with N
    
    test["_y"] = test.val_pos_219/100
    test["y1"] = test["_y"]
    x_guess = test["_y"].values
    
    sol, params = param_est.solve(
                                test,
                                params,
                                x_guess=x_guess,
                                lbp=1*params,
                                ubp=1*params,
                                covar=ca.veccat(1,1)
                                )
        
    print("head")

    