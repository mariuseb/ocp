#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
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
    kwargs = {
        "linewidth": 0.75,
        "drawstyle": "steps-post"
    }
    y_data.Ti.plot(
        ax=ax, 
        color="k",
        **kwargs
    )
    y_data.Tset_Hea.plot(
        ax=ax, color="b",
        **kwargs
    )
    ax.legend()
    ax1 = ax.twinx()
    y_data.phi_h.plot(
        ax=ax1,
        **kwargs
    )
    dT = (y_data.Tsup_air - y_data.Ti)
    P_vent = y_data.Vsup_air*dT*1000
    P_vent.plot(
        ax=ax1,
        **kwargs
    )
    y_data["occ_hea"].plot(
        ax=ax1,
        **kwargs
    )
    plt.show()
    

if __name__ == "__main__":

    """
    sysid using normal data
    """
    cfg_path = os.path.join("configs", "2R2C_occ_vent.json")
    data_path = "30023_data.csv"

    data = pd.read_csv(
        data_path,
        index_col=0
    )
    data.index = pd.to_datetime(
        data.index
    )
    
    start = pd.Timestamp("2024-12-15 00:00").tz_localize("Europe/Oslo")
    stop = pd.Timestamp("2024-12-22 00:00").tz_localize("Europe/Oslo")
    sampling_rate = "15min"
    
    y_data = data.resample(rule="15min").mean()
    
    columns = {
        "Klimagulvventil": "u_val",
        "Romtemperatur": "Ti",
        "Effective Heating Setpoint": "Tset_Hea",
        "+01=360.004-RT404 Temperaturgiver - Tilluft": "Tsup_air",
        "Soneregulering - Summering luftmengde tilluft": "Vsup_air"
    }
    y_data.rename(
        columns=columns,
        inplace=True
    )
    y_data["occ"] = (y_data["Tset_Hea"] > 19.5).astype(int)
    y_data["occ_hea"] = y_data["occ"]*1000
    y_data["valve_on"] = (y_data["Tset_Hea"] > 19.0).astype(int)
    y_data["Vsup_air"] *= 1.225/3600
    y_data["Tsup_air"] += 0
    y_data["u_val"] /= 100 # % to 0,1
    y_data["u_val"] = y_data["u_val"]*y_data["valve_on"]
    y_data["phi_h"] = y_data["u_val"]*2000 # % to 0,1
    
    y_data["y1"] = y_data["Ti"]
    
    fig, axes = plt.subplots(1,1,sharex=True)
    quick_plot(axes, y_data)
    plt.show()
    
    y_data = y_data.loc[start:stop]
    N = len(y_data)
    dt = 900
    y_data["dt_index"] = y_data.index
    y_data.index = range(len(y_data.index))
    y_data.index *= dt

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
                        "init": 10,
                        "ub": 30
                    },
                    "cp_air":
                    {
                        "init": 1000,
                        "lb": 1000,
                        "ub": 1000
                    },
                    "Pint_nom":
                    {
                        "init": 1000,
                        "lb": 500,
                        "ub": 5000
                    },
                    "alpha_vent":
                    {
                        "init": 1,
                        "lb": 0.01,
                        "ub": 1
                    },
                    "Prad_nom":
                    {
                        "init": 2000,
                        "lb": 2000,
                        "ub": 2000
                    }
    }

    kwargs = {
        #"slack": True
        "slack": False
    }
    A = 70
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
    }
    for name, value in priors.items():
        param_guess[name]["init"] = value 
        param_guess[name]["lb"] = value*1E-3 
        param_guess[name]["ub"] = value*1E3 

    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess


    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    arrival_cost=True
                    ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        P0 = np.eye(param_est.n_p + param_est.n_x)*1e-2
        P0[
           param_est.n_p:(param_est.n_p + param_est.n_x),
           param_est.n_p:(param_est.n_p + param_est.n_x)
           ] = 0
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
                                      x_N=np.array([293.15, 293.15]),
                                      P0=P0,
                                      codegen=False
                                      )

        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        plt.show()
    # dump for plots:
    params.to_csv("params_2R2C_occ_vent.csv", index=True)
    print(params)
