#from ast import Param
from ocp.estimation import Estimation
from ocp.mpc import MPC

import numpy as np
import json
import casadi as ca
import ocp
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api_old import Boptest
from pprint import pprint
#from ocp.filters import EKF
from matplotlib import rc
from pprint import pprint
#from ocp.covar_solve import CovarianceSolver
import os
import matplotlib.pyplot as plt
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
from utils import sanitize_index, read_single_series
import re

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
    cfg_path = "configs/vent_only_CO2_revised.json"

    b_occ = read_single_series(
        "data_20036/Status bevegelsesdetektor.csv",
    )
    b_occ.index = b_occ.index.round("1min")
    b_occ.dropna(inplace=True)
    b_occ = b_occ.reindex(
        index=pd.date_range(start=b_occ.index[0], end=b_occ.index[-1], freq="1min")
    )
    b_occ = b_occ.ffill()
    b_occ = b_occ.resample(rule="5min").asfreq()

    V_sup_air = read_single_series(
         "data_20036/Soneregulering - Summering luftmengde tilluft.csv",
    )
    V_ext_air = read_single_series(
         "data_20036/Soneregulering - Summering luftmengde avtrekk.csv",
    )

    data = data.rename(columns={
        "Romtemperatur": "Ti",
        "Klimagulvventil": "phi_h",
        "Co2 Nivå": "CO2_in"
    })
    data["Ta"] += 273.15
    data["Ti"] += 273.15

    #start = pd.Timestamp("2026-01-28 12:00")
    start = pd.Timestamp("2026-02-04 12:00")
    start = pd.Timestamp("2026-02-11 12:00")
    stop = start + pd.Timedelta(days=7)
    sampling_rate = "5min"
     

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
    }
    param_guess = ca.DM([
                        3E-5,
                        418,
                        0.2,
                        6E-4
                        ])

    
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        "slack": True
        }
    

    y_data = data.loc[start:stop]
    y_data["b_occ"] = b_occ.loc[start:stop]

    test = V_sup_air.loc[start:stop].index
    diff = y_data.index.difference(test)
    y_data = y_data.drop(diff)

    y_data["V_sup_air"] = (V_sup_air.loc[start:stop]/3600)*1.204
    y_data["n_mech"] = (V_ext_air.loc[start:stop]/3600)*1.204
    y_data["y1"] = y_data["CO2_in"]

    ax = y_data.CO2_in.plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    y_data.b_occ.plot(ax=ax1, drawstyle="steps-post", color="r")
    plt.show(block=False)

    x_guess = np.array([
        y_data.CO2_in.values.flatten()
        #y_data.b_occ.values.flatten(),
    ])
    N = len(y_data)
    dt = 300
    x_guess = x_guess.T.flatten()
    #y_data = y_data[:3]
    #N = len(y_data)
    with Estimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess,
                             algebraic_slack=True,
                             **kwargs) as param_est:
                             #as param_est:
        
        Q = ca.DM.eye(1)
        R = ca.DM.eye(1)
        #R[1,1] = 1E-8
        #R[2,2] = 1E-8
        
        #R[2,2] = 1E-10
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        """
        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        
        param_est.nlp["f"] = \
            R[0,0]*ca.dot(v1, v1)
        """     
        lbp[1] = 380
        ubp[1] = 430
        #param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      x_guess=x_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R),
                                      codegen=False
                                      )    
    
    sol.index = y_data.index
    fig, ax = plt.subplots(1,1,sharex=True)
    #ax = axes[0]
    ax.plot(
        y_data.index, 
        sol.CO2_in, 
        drawstyle="steps-post", 
        color="r"
    )
    ax.plot(
        y_data.index, 
        sol.y1, 
        drawstyle="steps-post", 
        color="k", 
        linestyle="dashed"
    )
    ax1 = ax.twinx()
    ax1.plot(
        y_data.index, 
        sol.n_occ, 
        drawstyle="steps-post", 
        color="b", 
        linestyle="dashed"
    )
    """
    ax1.plot(
        y_data.index, 
        sol.b_occ, 
        drawstyle="steps-post", 
        color="k", 
        linestyle="dashed"
    )
    """
    sol.to_csv("CO2_results_2nd_week.csv", index=True)
    ax.legend(["CO2_in", "CO2_measured", "b_occ"])
    plt.show()
    print(params)
    
params.to_csv("CO2_model.csv", index=True) 
