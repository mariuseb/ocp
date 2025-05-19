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
    y_data.Prad_calc.plot(ax=ax, color="k", linestyle="dashed", drawstyle="steps-post")
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
    
if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    cfg_path = os.path.join(
        "configs",
        "radiator_model_simple_Trad_Tsup.json"
    )
    data_path = os.path.join(
                            "twin_rooms_emulator_PRBS.csv"
                            )
    data = pd.read_csv(
        data_path,
        index_col=0
    )
    data.index = pd.to_timedelta(
        data.index
    )
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
    y_data = data.rename(columns=y_map)[
            list(y_map.values())
        ]
    # shift rad_val --> 30s
    #y_data["rad_val"] = y_data["rad_val"].shift(1)
    
    
    fig, axes = plt.subplots(3,1,sharex=True)
    y_data["Prad_calc"] = y_data["rad_flo"]*4200*(y_data["Tsup"] - y_data["Tret"])
    quick_plot(axes, y_data)
    #plt.show(block=False) 
    plt.show() 
    
    fig, axes = plt.subplots(1,1,sharex=True)
    plot_valve_sorted(axes, y_data)
    #plt.show(block=False) 
    plt.show() 
    
    
    # resample mean:
    y_data = y_data.resample(rule="15min").mean()
    y_data["y1"] = y_data["rad_flo"]
    y_data["y2"] = y_data["Prad"]
    y_data["y3"] = y_data["Tret"]
    y_data["y4"] = y_data["Tsup"]
    y_data.index = pd.to_timedelta(y_data.index)
    y_data["dt_index"] = y_data.index
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = range(len(y_data.index))
    y_data.index *= dt
    #y_data["m_flow_bool"] = ((y_data["rad_flo"].round(4) > 0)).astype(int) + 1e-1
    y_data["m_flow_bool"] = ((y_data["rad_flo"].round(4) > 0)).astype(int) + 1e-2
    #y_data["m_flow_bool"] = 1
    N = len(y_data)
    # shift phi_h one time step forward:
    #y_data["phi_h"] = y_data["phi_h"].shift(-1)
    #y_data["phi_h"] = y_data["phi_h"].bfill()
    param_guess = {
                    "n": 
                    {
                        "init": 1.5,
                        "ub": 3.0,
                        "lb": 0.1
                    },
                    "tau": 
                    {
                        "init": 60,
                        "lb": 1,
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
                    "Csup":
                    {
                        "init": 1E5,
                    },
                    "Rsup":
                    {
                        "init": 1e-3,
                    },
                    "Csup_off":
                    {
                        "init": 1E5,
                    },
                    "Rsup_off":
                    {
                        "init": 1e-3,
                    },
                    "Cret":
                    {
                        "init": 1E5,
                    },
                    "Rrr":
                    {
                        "init": 1e-3,
                    },
                    "Crad":
                    {
                        "init": 1E5,
                    },
                    "Rirad":
                    {
                        "init": 1e-3,
                    },
                    "Riret":
                    {
                        "init": 1e-3,
                        "ub": 1
                    },
                    "Risup":
                    {
                        "init": 1e-3,
                    },
                    "Tsup_offset":
                    {
                        "init": 1,
                        "lb": -5, 
                        "ub": 20
                    },
                    "Tret_offset":
                    {
                        "init": 1,
                        "lb": -5, 
                        "ub": 20
                    },
                    "dh_Tsup":
                    {
                        "init": 273.15 + 47,
                        "lb": 273.15 + 35,
                        "ub": 273.15 + 55,
                    },
                    "Tset_sup_a":
                    {
                        "init": 2/3,
                        "lb": 0.1,
                        "ub": 10,
                    },
                    "Tset_sup_b":
                    {
                        "init": 273.15 + 50,
                        "lb": 273.15 + 40,
                        "ub": 273.15 + 60,
                    },
                    "Ta_dim":
                    {
                        "init": 273.15 - 20,
                        "lb": 273.15 - 20,
                        "ub": 273.15 - 20,
                    },
    }
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [1,1,12,12],
        "u_nom_b ": [0,0,289.15,289.15],
        "z_nom": [1e-1,1E3,12],
        "z_nom_b ": [0,0,289.15],
        "y_nom": [1e-1,1E3,12,12],
        "y_nom_b": [0,0,289.15,289.15],
        "slack": False
    }        
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.y3.values.flatten(),
                    #y_data.y3.values.flatten(),
                    y_data.y4.values.flatten()
                    ])

    """
    params_hvac = pd.read_csv("hvac_model.csv", index_col=0)
    #params_hvac.loc["Rirad"] = 0.00625
    for param in params_hvac.index:
        param_guess[param] = {
            "init": params_hvac.loc[param].values[0],
            "lb": params_hvac.loc[param].values[0],
            "ub": params_hvac.loc[param].values[0]
        }
    """    
    
    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=False,
                    functions=functions,
                    **deepcopy(kwargs)
                    ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(4)
        R[1,1] = 1e-7
        #R[1,1] = 1e-16
        R[2,2] = 1e-1
        R[3,3] = 1e-1
        P0 = np.eye(param_est.n_p + param_est.n_x)*1
        P0[
           param_est.n_p:(param_est.n_p + param_est.n_x),
           param_est.n_p:(param_est.n_p + param_est.n_x)
           ] = 0
        #P0[2,2] = 0
        #P0[5,5] = 0
        
        lbp = param_est.get_lbp(1e-2)
        ubp = param_est.get_ubp(1e2)
        #lbp = param_est.get_lbp(1e-3)
        #ubp = param_est.get_ubp(1e3)
        p0 = param_est.p0
        sol, params = param_est.solve(
                                      y_data,
                                      p0,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=False,
                                      #P0=P0,
                                      x_N=x_guess[-1,-param_est.n_x:]
                                      )
        p_nom = param_est.p_nom
        sol.index = y_data.dt_index
        y_data.index = y_data.dt_index
        sol["dT_model"] = sol["Tsup"] - sol["Tret"]
        sol["dT"] = sol["y4"] - sol["y3"]
        
        fig, axes = plt.subplots(5,1,sharex=True)
        ax = axes[0]
        sol["rad_flo"].plot(color="r", ax=ax, linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax = axes[1]
        sol["Prad"].plot(color="r", ax=ax, linewidth=0.75, drawstyle="steps-post")
        sol["y2"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax = axes[2]
        sol["Tret"].plot(color="r", ax=ax, linewidth=0.75, drawstyle="steps-post")
        sol["y3"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax = axes[3]
        sol["Tsup"].plot(color="r", ax=ax, linewidth=0.75, drawstyle="steps-post")
        sol["Tset_sup"].plot(color="g", ax=ax, linewidth=0.75, drawstyle="steps-post")
        sol["y4"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "Ta + 40", "measured"])
        ax = axes[4]
        sol["dT_model"].plot(color="r", ax=ax, linewidth=0.75, drawstyle="steps-post")
        sol["dT"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        plt.show()

        sol[["Prad","rad_flo","Tsup"]].to_csv("rad_model_output.csv", index=True)
        params.to_csv("hvac_model_PRBS.csv", index=True)
        print(params) 

    
    

    