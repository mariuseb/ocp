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
#from ocp.filters import KalmanBucy
from utils import read_single_series
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

def _solve_rosenbrock():
    # Declare variables
    x = ca.SX.sym("x")
    y = ca.SX.sym("y")
    z = ca.SX.sym("z")

    # Formulate the NLP
    f = x**2 + 100*z**2
    g = z + (1-x)**2 - y
    nlp = {'x': ca.vertcat(x,y,z), 'f':f, 'g':g}

    # Create an NLP solver
    solver = ca.nlpsol(
        "solver", 
        "ipopt",
        nlp,
        {"ipopt.print_level": 0}
    )
    # Solve the Rosenbrock problem
    res = solver(
        x0 =[2.5,3.0,0.75],
        ubg=0,
        lbg=0)

if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    _solve_rosenbrock()

    data = pd.read_csv("20036.csv", index_col=0)
    data.index = pd.to_datetime(
        data.index
    )
    #cfg_path = "configs/2R2C_envelope_heating_Tsup_air_b_occ.json"
    cfg_path = "configs/2R2C_envelope_heating_Tsup_air.json"

    data = data.rename(columns={
        "Romtemperatur": "Ti",
        "Klimagulvventil": "phi_h",
        '+01=360.005-RT404 Temperaturgiver - Tilluft': "Tsup_air"
    })
    data["Ta"] += 273.15
    data["Ti"] += 273.15
    data["Tsup_air"] += 273.15

    """
    ax = data.Ti.plot(drawstyle="steps-post")
    data.Ta.plot(drawstyle="steps-post", ax=ax, color="g")
    ax1 = ax.twinx()
    data.phi_h.plot(ax=ax1, drawstyle="steps-post", color="r")
    plt.show()
    """

    #start = pd.Timestamp("2026-01-28 12:00")
    start = pd.Timestamp("2026-02-04 12:00")
    #start = pd.Timestamp("2026-02-11 12:00")
    stop = start + pd.Timedelta(days=7)
    #sampling_rate = "5min"
     

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
                    },
                    "alpha_int":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1.5
                    },
                    "alpha_vent":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "phi_int_base":
                    {
                        "init": 1000,
                        "lb": 100,
                        "ub": 2000
                    },

    }

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12,12,1,1E3,1E3,1E3],
        "u_nom_b ": [289.15,289.15,1,0,0,0],
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

    y_data = data.loc[start:stop].resample(rule="15min").mean()
    #_data = pd.read_csv("CO2_results_2nd_week.csv", index_col=0)
    _data = pd.read_csv("CO2_results.csv", index_col=0)
    _data.index = pd.to_datetime(
        _data.index
    )
    dt = 900
    N = len(y_data)

    V_sup_air = read_single_series(
         "data_20036/Soneregulering - Summering luftmengde tilluft.csv"
    )
    V_ext_air = read_single_series(
         "data_20036/Soneregulering - Summering luftmengde avtrekk.csv"
    )

    y_data["y1"] = y_data["Ti"]
    y_data["n_occ"] = _data["n_occ"]
    #y_data["n_occ"] = 0
    y_data["b_occ"] = _data["b_occ"]
    y_data["phi_int"] = y_data["n_occ"]*100
    # already in %: assume Pdim = 2000 W
    y_data["phi_h"] *= 20
    y_data["m_flow_air"] = ((V_sup_air.loc[start:stop]/3600)*1.204).resample("15min").mean()

    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess
    
    """
    params = pd.read_csv(
        #"params_1st_week_no_n_occ.csv",
        #"params_1st_week_b_occ.csv",
        "params_1st_week_n_occ.csv",
        index_col=0
    ).squeeze()

    param_guess = {k: {"init": params.loc[k]} for k in params.index}
    """

    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    arrival_cost=True
                    ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        P0 = np.eye(param_est.n_p + param_est.n_x)*0
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
                                      codegen=False,
                                      P0=P0,
                                      x_N=x_guess[-1,-param_est.n_x:]
                                      )

        sol.index = y_data.index
        ax = sol["Ti"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        sol["phi_h"].plot(color="y", ax=ax1, linewidth=0.75, drawstyle="steps-post")
        #(sol["phi_int_base"]*sol["b_occ"]*sol["alpha_vent"]).plot(color="b", ax=ax1, linewidth=0.75, drawstyle="steps-post")
        sol["phi_int"].plot(color="b", ax=ax1, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"], loc="upper left")
        ax1.legend(["phi_h", "phi_int"], loc="upper right")
        plt.show()
        #params.to_csv("params_1st_week_b_occ.csv", index=True)
        #params.to_csv("params_1st_week_n_occ.csv", index=True)
    # dump for plots:
    print(params)