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
from utils import prepare_data
from ocp.functions import functions
#from result_generator import ResultGenerator, plot_residuals
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

def prepare_est(
        data,
        A=66.7,
        load_optimal_rad_params=False,
        load_optimal_env_params=False,
        load_optimal_traj=False
    ):
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [1],
        "u_nom_b ": [0],
        "r_nom": [12,1E4,1],
        "r_nom_b ": [289.15,0,0],
        "z_nom": [1e-1,1E4],
        "z_nom_b ": [0,0],
        "y_nom": [12,1e-1,1E4],
        "y_nom_b": [289.15,0,0],
        #"slack": True
        "slack": False
    }
    if load_optimal_env_params:
        params = pd.read_csv("envelope_model_alt_rad_first.csv", index_col=0)
        param_guess = dict()
        for k in params.index:
            param_guess[k] = {
                "init": float(params.loc[k]),
                "lb": float(params.loc[k]),
                "ub": float(params.loc[k])
            }
    else: 
        param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rea":
                    {
                        "init": 1e-1
                    },
                    "Ria":
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
                    }
        }
        priors = {
            "Rie": 0.250/A, # m²K / W 
            "Rea": 2.250/A, # m²K / W 
            "Ci": 9.50*3600*A, # Wh / m²K
            "Ce": 112*3600*A, # Wh / m²K
            "Ai": 2, # m²
            }
        
        for name, value in priors.items():
            param_guess[name]["init"] = value 
            if not name.startswith("alpha"):
                param_guess[name]["lb"] = value*1E-3 
                param_guess[name]["ub"] = value*1E3 
            else:
                param_guess[name]["lb"] = value
                param_guess[name]["ub"] = value
            
    if load_optimal_rad_params:
        params_rad = pd.read_csv("rad_model_PRBS.csv", index_col=0)
        param_guess_rad = dict()
        for k in params_rad.index:
            param_guess_rad[k] = {
                "init": float(params_rad.loc[k]),
                "lb": float(params_rad.loc[k]),
                "ub": float(params_rad.loc[k])
            }
            
    else:
        param_guess_rad = {
                        "n": 
                        {
                            "init": 1.5,
                            "ub": 3.0,
                            "lb": 0.1
                        },
                        "rad_flo_nom":
                        {
                            "init": 0.01,
                            "lb": 0.09, 
                            "ub": 0.15
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
                        "Risup":
                        {
                            "init": 1e-3,
                        },
                        "Rirad":
                        {
                            "init": 1e-3,
                        },
                        "Crad":
                        {
                            "init": 1E5,
                        },
                        "Tsup_offset":
                        {
                            "init": 1,
                            "lb": -5, 
                            "ub": 20
                        },
                        "dT_nom":
                        {
                            "init": 12,
                            "lb": 1, 
                            "ub": 30
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
    param_guess = {
        **param_guess,
        **param_guess_rad
    }
    
    if load_optimal_traj:
        sol_env = pd.read_csv(
            "solution_alt_rad_first.csv",
             index_col=0
        ) 
        sol_rad = pd.read_csv(
            "trajectory_rad_model_PRBS.csv", 
            index_col=0
        ) 
        sol_env["Trad_RAD"] = sol_rad["Trad"]
        x_guess = np.array([
            sol_env["Ti"].values.flatten(),
            sol_env["Te"].values.flatten(),
            sol_rad["Trad"].values.flatten(), 
            sol_rad["Tsup"].values.flatten()
        ])
        lbx = 1.0*x_guess
        ubx = 1.0*x_guess
    else:
        # constrain in particular Th to physically meaningful values:
        x_guess = np.array([
                        data.y1.values.flatten(),
                        data.y1.values.flatten() - 2,
                        #data.y1.values.flatten() + 2,
                        #data.y5.values.flatten()
                        ])
        lbx = 0.7*x_guess
        ubx = 2.0*x_guess
        
    return param_guess, kwargs, lbx, ubx, x_guess
    
    

if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    cfg_path = os.path.join("configs", "2R2C_2meas.json")
    data_path = os.path.join(
                            "twin_rooms_emulator_PRBS.csv"
                            )
    y_data, N, dt = prepare_data(data_path)
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(
        y_data, 
        load_optimal_rad_params=False,
        load_optimal_env_params=False,
        load_optimal_traj=False
    )
    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=True,
                    functions=functions,
                    **deepcopy(kwargs),
                    ) as param_est:

        Q = ca.DM.eye(param_est.n_x)
        R = ca.DM.eye(param_est.n_y)
        #R[0,0] = 0
        R[1,1] = 1e-2
        R[2,2] = 1e-7
        #R[3,3] = 0
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
                                      lbx=lbx,
                                      ubx=ubx,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=True,
                                      P0=P0,
                                      x_N=x_guess[-1,-param_est.n_x:]
                                      )
        p_nom = param_est.p_nom
        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        plt.show()
        ax = sol["Prad"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y3"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        plt.show()
        plt.close()
        #params.to_csv("full_model_4R4C.csv", index=True)
        #sol.to_csv("simulation_traj_4R4C.csv", index=True)
        print(params) 

    
    

    