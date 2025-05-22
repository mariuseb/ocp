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
#from result_generator import ResultGenerator, plot_residuals
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

def prepare_est(data, A=66.7):
    param_guess = {
                "Rie": 
                {
                    "init": 1e-2
                },
                "Rea":
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
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12]*1 + [1E3,1E3],
        "u_nom_b ": [289.15]*1 + [0]*2,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
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
             
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    data.y1.values.flatten(),
                    data.y1.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess
    return param_guess, kwargs, lbx, ubx, x_guess
    
    

if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    cfg_path = os.path.join("configs", "2R2C.json")
    data_path = os.path.join(
                            "twin_rooms_emulator_PRBS.csv"
                            )
    y_data, N, dt = prepare_data(data_path)
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(y_data)
    
    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=True,
                    **deepcopy(kwargs)
                    ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
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
        #sol["phi_s"].plot(drawstyle="steps-post",ax=ax1)
        #sol["phi_h"].plot(drawstyle="steps-post",ax=ax1)
        plt.close()
        params.to_csv("envelope_model_2R2C.csv", index=True)
        sol.to_csv("simulation_traj_2R2C.csv", index=True)
        print(params) 

    
    

    