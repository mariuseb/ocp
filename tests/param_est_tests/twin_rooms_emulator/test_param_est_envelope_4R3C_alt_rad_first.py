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
#from result_generator import ResultGenerator, plot_residuals
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

def quick_plot(ax, y_data):
    """
    A quick plot of the data required
    for envelope identification.
    """
    y_data.y1.plot(ax=ax, drawstyle="steps-post")
    ax.legend()
    ax1 = ax.twinx()
    y_data.Prad.plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    

if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    cfg_path = os.path.join(
        "configs", 
        "4R3C_alt.json"
    )
    data_path = os.path.join(
                            "twin_rooms_emulator_PRBS.csv"
                            )
    data = pd.read_csv(data_path, index_col=0)
    y_map = {
        "Ti_219": "Ti",
        "Prad_219": "Prad",
        "reaRadTRet219_y": "Tret",
        "reaRadTSup219_y": "Tsup",
        "reaRadFlow219_y": "rad_flo",
        "weatherStation_reaWeaTDryBul_y": "Ta",
        "weatherStation_reaWeaHGloHor_y": "phi_s"
        
    }
    y_data = data.rename(columns=y_map)[
            list(y_map.values())
        ]
    y_data["Prad_meas"] = y_data["Prad"]
    y_data["Tsup_meas"] = y_data["Tsup"]
    y_data["rad_flo_meas"] = y_data["rad_flo"]
    rad_model = pd.read_csv("trajectory_rad_model_PRBS.csv", index_col=0)
    rad_model.index = pd.to_timedelta(rad_model.index)
    y_data["Prad"] = rad_model["Prad"]
    y_data["rad_flo"] = rad_model["rad_flo"]
    y_data["Tsup"] = rad_model["Tsup"].shift(-1)
    y_data["y1"] = y_data["Ti"]
    y_data.index = pd.to_timedelta(y_data.index)
    y_data["dt_index"] = y_data.index
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = range(len(y_data.index))
    y_data.index *= dt
    N = len(y_data)
    # shift phi_h one time step forward:
    #y_data["phi_h"] = y_data["phi_h"].shift(-1)
    #y_data["phi_h"] = y_data["phi_h"].bfill()
    
    fig, axes = plt.subplots(1,1,sharex=True)
    quick_plot(axes, y_data)
    plt.show() 

    param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rirad": 
                    {
                        "init": 1e-3
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
                    "Crad":
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
                    },
                    "cp_water":
                    {
                        "init": 4200,
                        "lb": 4200,
                        "ub": 4200
                    }
    }

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [1E3,1E3,12,12,1e-1],
        "u_nom_b ": [0,0,289.15,289.15,0],
        #"z_nom": [1E3,1E3],
        #"z_nom_b ": [0,0],
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    A = 66.7
    
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
                    y_data.y1.values.flatten(),
                    y_data.y1.values.flatten() - 2,
                    #y_data.y1.values.flatten() + 2
                    rad_model["Trad"].values.flatten()
                    ])
    
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess
    
    # fix Trad:
    #lbx[2::3] = rad_model["Trad"].values.flatten()*0.99
    #ubx[2::3] = rad_model["Trad"].values.flatten()*1.01

    params_hvac = pd.read_csv("hvac_model_PRBS.csv", index_col=0)
    #params_hvac.loc["Rirad"] = 0.00625
    for param in ("Rirad","Crad"):
        param_guess[param] = {
            "init": params_hvac.loc[param].values[0],
            "lb": params_hvac.loc[param].values[0],
            "ub": params_hvac.loc[param].values[0]
        }

    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=False,
                    **deepcopy(kwargs)
                    ) as param_est:

        Q = ca.DM.eye(3)
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
        y_data.index = sol.index
        sol["Prad_meas"] = y_data["Prad_meas"]
        sol["Trad_RAD"] = rad_model["Trad"]
        sol["Prad_to_env_RAD"] = rad_model["Prad_to_env"]
        ax = sol["Ti"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        #sol["Trad"].plot(color="g", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"], loc="upper left")
        ax1 = ax.twinx()
        # P_to_rad:
        #sol["Prad_meas"] = y_data["Prad_meas"]
        sol["Prad_to_env_ENV"] = (sol["Trad"] - sol["Ti"])/sol["Rirad"]
        #sol["Psol"] = sol["Ai"]*sol["phi_s"]
        sol["Prad_ENV"] = (sol["Tsup"] - sol["Trad"])*sol["rad_flo"]*4200
        Prad_RAD = (rad_model["Tsup"] - rad_model["Trad"])*rad_model["rad_flo"]*4200
        sol["Prad_RAD"] = Prad_RAD
        #sol["Prad"].plot(drawstyle="steps-post",ax=ax1, linewidth=0.75)
        #sol["Psol"].plot(drawstyle="steps-post",ax=ax1, linewidth=0.75, color="y")
        """
        sol["Prad_ENV"].plot(drawstyle="steps-post",ax=ax1, color="g", linewidth=0.75)
        sol["Prad_RAD"].plot(drawstyle="steps-post",ax=ax1, color="m", linewidth=0.75)
        sol["Prad_meas"].plot(drawstyle="steps-post",ax=ax1, color="b", linewidth=0.75)
        sol["Prad"].plot(linestyle="dashed", drawstyle="steps-post",ax=ax1, color="k", linewidth=0.75)
        ax1.legend(["Prad_ENV", "Prad_RAD", "Prad_meas", "Prad"], loc="upper right")
        """
        plt.show()
        
        fig, axes = plt.subplots(4,1, sharex=True)
        ax = axes[0]
        sol["Prad_ENV"].plot(drawstyle="steps-post",ax=ax, color="g", linewidth=0.75)
        sol["Prad_RAD"].plot(drawstyle="steps-post",ax=ax, color="m", linewidth=0.75)
        ax.legend(["ENV", "RAD"])
        ax = axes[1]
        sol["Prad_to_env_ENV"].plot(drawstyle="steps-post",ax=ax, color="g", linewidth=0.75)
        sol["Prad_to_env_RAD"].plot(drawstyle="steps-post",ax=ax, color="m", linewidth=0.75)
        ax.legend(["ENV", "RAD"])
        ax = axes[2]
        sol["Ti"].plot(drawstyle="steps-post",ax=ax, color="g", linewidth=0.75)
        sol["y1"].plot(drawstyle="steps-post",ax=ax, color="m", linewidth=0.75)
        ax.legend(["ENV", "RAD"])
        ax = axes[3]
        sol["Trad"].plot(drawstyle="steps-post",ax=ax, color="g", linewidth=0.75)
        sol["Trad_RAD"].plot(drawstyle="steps-post",ax=ax, color="m", linewidth=0.75)
        ax.legend(["ENV", "RAD"])
        plt.show()
        
        params.to_csv("envelope_model_alt_rad_first.csv", index=True)
        sol.to_csv("solution_alt_rad_first.csv", index=True)
        print(params) 

    
    

    