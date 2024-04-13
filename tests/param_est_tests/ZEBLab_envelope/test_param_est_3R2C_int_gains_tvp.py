#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
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

    cfg_path = os.path.join("configs", "3R2C_det_vent_tvp_int_gains_no_conns.json")
    #data_path = os.path.join("ZEBLab_2years_60m.csv")
    data_path = os.path.join("ZEBLab_nov23_1m.csv")

    zeb_data = ZEBData(data_path)
    
    start = pd.Timestamp("2023-11-14 00:00")
    stop = pd.Timestamp("2023-11-28 00:00")
    
    y_data = zeb_data.get_dataset(start=start, stop=stop)

    #y_data = prepare_data(data)
    y_data = y_data.bfill()
    y_data = y_data.resample(rule="1H").mean()
    # some temps missing?:

    fig, axes = plt.subplots(1,1,sharex=True)
    quick_plot(axes, y_data)
    plt.show()
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification:
    y_data.index = range(0,N*dt,dt)

    
    param_guess = np.array([1e-02,
                    1e-02,
                    1e-01, 
                    1e-01,
                    1E6, #1E6,
                    1E6, #1E6,
                    1E7, #1E7,
                    1E6, #1E6,
                    10,
                    10,
                    0.5,
                    0.5
                    ])
    
    param_guess = np.array([
                        0.0034386028710360578,
                        -0.0007839966071162144,
                        0.05470369872270893,
                        -0.03787554503264528,
                        10976347.421861785,
                        2524850.3819319685,
                        23152204.231900185,
                        -23052204.183144476,
                        3.7348667225948384,
                        0.009999905100061376,
                        10.541674646868394,
                        0.5
                        ])
    
    lbp = 1e-3*param_guess
    ubp = 1e3*param_guess
    lbp[-1] = 1E-3
    ubp[-1] = 1
    
    lbp[1] = -100
    lbp[3] = -100
    # Ci_a
    lbp[5] = -1E8
    ubp[5] = 1E8
    # Ce_a:
    lbp[7] = -1E8
    ubp[7] = 1E8
    
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.9*x_guess
    ubx = 1.1*x_guess

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "z_nom": [1E7,1E6,1E-2,1E-1],
        "u_nom": [12]*2 + [1E3,1E3,50,1,1,1E3],
        "u_nom_b ": [289.15]*2 + [0]*6,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }

    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess,
                             **kwargs,
                             ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=False
                                      )

        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend(["model", "measured"])
        plt.show()
        params.to_csv("results/params_envelope_tvp_2R2C_vent.csv", index=True)
        print(params)
    # dump for plots:
    sol.to_csv("results/tvp_in_training_traj_2R2C_vent.csv", index=True)
    
    """
    For time-varying EKF:
    """
    p_base = params.loc[["Rie",
                        "Rea",
                        "Ci",
                        "Ce",
                        "Ai",
                        "Ae",
                        "alpha_vent",
                        "R_121_e",
                        "R_321_e",
                        "R_320_e",
                        "R_121_i",
                        "R_321_i",
                        "R_320_i"
                        ]]
    
    p_mod = params.loc[["Rie_a",
                        "Rea_a",
                        "Ci_a",
                        "Ce_a",
                        "Ai",
                        "Ae",
                        "alpha_vent",
                        "R_121_e",
                        "R_321_e",
                        "R_320_e",
                        "R_121_i",
                        "R_321_i",
                        "R_320_i"
                        ]]
    # set last three to zero:
    p_mod[4:] = 0
    p_base.to_csv("results/tvp_params_base_2R2C_vent.csv", index=True)
    p_mod.to_csv("results/tvp_params_mod_2R2C_vent.csv", index=True)
    print(params)