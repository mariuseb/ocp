#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
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
from ocp.utils import prepare_data, ZEBData
from ocp.covar_solver_cont import CovarianceSolverContinuous
from copy import deepcopy
from ocp.functions import functions
#from result_generator import ResultGenerator, plot_residuals
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
import matplotlib as mpl
mpl.rcParams['lines.linewidth'] = 0.75
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

def quick_plot(axes, y_data):
    """
    A quick plot of the data required
    for radiator identification.
    """
    # temps:
    ax = axes[0]
    y_data.Tsup.plot(ax=ax, drawstyle="steps-post")
    y_data.Tret.plot(ax=ax, drawstyle="steps-post")
    ax = axes[1]
    y_data.Prad.plot(ax=ax, drawstyle="steps-post")
    ax = axes[2]
    y_data.rad_val.plot(ax=ax, drawstyle="steps-post")
    ax1 = ax.twinx()
    y_data.rad_flo.plot(ax=ax1, drawstyle="steps-post", color="k")
    ax.legend(loc="upper left")
    ax1.legend(loc="upper right")
    
def plot_valve_sorted(axes, y_data):
    """
    Sort valve inputs, radiator flow
    """
    data = y_data[["rad_flo", "rad_val"]].copy()
    data = data.resample(rule="5min").mean()
    data = data.round(5)
    data = data.loc[data.rad_flo != 0]
    data = data.sort_values(by="rad_val")
    data.index = range(len(data))
    ax = data.rad_val.plot(drawstyle="steps-post", color="k")
    ax1 = ax.twinx()
    ax = data.rad_flo.plot(ax=ax1, drawstyle="steps-post")
    plt.show()
    
    
    
    

if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    cfg_path = os.path.join("configs", "radiator_model_simple.json")
    data_path = os.path.join(
                            "twin_rooms_emulator_normal_op.csv"
                            )
    data = pd.read_csv(data_path, index_col=0)
    data.index = pd.to_timedelta(data.index)
    y_map = {
        "Ti_219": "Ti",
        "Prad_219": "Prad",
        "rad_219": "rad_val",
        "reaRadTRet219_y": "Tret",
        "reaRadTSup219_y": "Tsup",
        "reaRadFlow219_y": "rad_flo",
        "weatherStation_reaWeaTDryBul_y": "Ta",
        "weatherStation_reaWeaHGloHor_y": "phi_s"
        
    }
    """
    y_data = data.rename(columns=y_map)[
            list(y_map.values())
        ].iloc[100:(60*2*24)]
    """
    y_data = data.rename(columns=y_map)[
            list(y_map.values())
        ].iloc[100:]
    
    # shift rad_val --> 30s
    #y_data["rad_val"] = y_data["rad_val"].shift(1)
    
    fig, axes = plt.subplots(3,1,sharex=True)
    quick_plot(axes, y_data)
    plt.show() 
    
    fig, axes = plt.subplots(1,1,sharex=True)
    plot_valve_sorted(axes, y_data)
    plt.show() 
    
    # resample mean:
    y_data = y_data.resample(rule="5min").mean()
    y_data["y1"] = y_data["rad_flo"]
    y_data["y2"] = y_data["Prad"]
    y_data.index = pd.to_timedelta(y_data.index)
    y_data["dt_index"] = y_data.index
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = range(len(y_data.index))
    y_data.index *= dt
    N = len(y_data)
    # shift phi_h one time step forward:
    #y_data["phi_h"] = y_data["phi_h"].shift(-1)
    #y_data["phi_h"] = y_data["phi_h"].bfill()
    

    param_guess = {
                    "n": 
                    {
                        "init": 1.5,
                        "ub": 3.0,
                        "lb": 0.5
                    },
                    "tau": 
                    {
                        "init": 60,
                        "lb": 10,
                        "ub": 1000
                    },
                    "rad_flo_nom":
                    {
                        "init": 0.01,
                        "lb": 0.09, 
                        "ub": 0.15
                    },
                    "dTnom":
                    {
                        "init": 12,
                        "lb": 5, 
                        "ub": 30
                    },
                    "cp_water":
                    {
                        "init": 4200,
                        "lb": 4199, 
                        "ub": 4201
                    },
    }
    kwargs = {
        "slack": False
    }        
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.y1.values.flatten(),
                    ])
    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=True,
                    functions=functions,
                    **deepcopy(kwargs)
                    ) as param_est:

        Q = ca.DM.eye(1)
        R = ca.DM.eye(2)
        R[1,1] = 1e-8
        P0 = np.eye(param_est.n_p + param_est.n_x)*1
        P0[
           param_est.n_p:(param_est.n_p + param_est.n_x),
           param_est.n_p:(param_est.n_p + param_est.n_x)
           ] = 0
        #P0[2,2] = 0
        #P0[5,5] = 0
        
        lbp = param_est.get_lbp(1e-3)
        ubp = param_est.get_ubp(1e3)
        p0 = param_est.p0
        sol, params = param_est.solve(
                                      y_data,
                                      p0,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=True,
                                      P0=P0,
                                      x_N=x_guess[-1,-param_est.n_x:]
                                      )
        p_nom = param_est.p_nom
        sol.index = y_data.dt_index
        ax = sol["rad_flo"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        #sol["phi_s"].plot(drawstyle="steps-post",ax=ax1)
        #sol["phi_h"].plot(drawstyle="steps-post",ax=ax1)
        plt.show()
        print(params) 

    
    

    