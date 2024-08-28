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

    cfg_path = os.path.join("configs", "2R2C_int_gains.json")
    #cfg_path = os.path.join("configs", "2R2C_det_vent_tvp_vent_cond_no_constr.json")
    #data_path = os.path.join("ZEBLab_2years_60m.csv")
    data_path = os.path.join("ZEBLab_jan24_1m.csv")

    Data = ZEBData(data_path)
    #Data.data = Data.data.bfill()
    #Data.data.index.name = "time"
    #Data.data = Data.data.groupby(pd.Grouper(freq='60min')).mean().dropna()
    start = pd.Timestamp("2024-01-01 00:00")
    stop = pd.Timestamp("2024-01-15 00:00")
    
    y_data = Data.get_dataset(start=start, stop=stop)

    #y_data = prepare_data(data)
    y_data = y_data.bfill()
    #y_data = y_data.resample(rule="1H").mean()
    y_data = y_data.groupby(pd.Grouper(freq='5min')).mean().dropna()
    # some temps missing?:

    fig, axes = plt.subplots(1,1,sharex=True)
    quick_plot(axes, y_data)
    plt.show()
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification:
    y_data.index = range(0,N*dt,dt)
    
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
                        "init": 1e6,
                        "ub": 1e9
                    },
                    "Ai":
                    {
                        "init": 10
                    },
                    "cp_air":
                    {
                        "init": 1000,
                        "lb": 1000,
                        "ub": 1000
                    },
                    "alpha_vent":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_int":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    }
    }
 
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2*x_guess

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12]*6 + [1E3,1E3,1E3,10],
        "u_nom_b ": [289.15]*6 + [0]*4,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    A = 60
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ai": 10, # m²
        "alpha_vent": 1,
        "alpha_int": 1
        
    }
    for name, value in priors.items():
        param_guess[name]["init"] = value 
        param_guess[name]["lb"] = value*1E-3 
        param_guess[name]["ub"] = value*1E3 
    
    with Estimation(config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    arrival_cost=True,
                    **kwargs,
                    ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        P0 = ca.DM.eye(param_est.n_p + param_est.n_x)
        for n in range(6,10):
            P0[n,n] = 0
        
        lbp = param_est.get_lbp(1e-2)
        ubp = param_est.get_ubp(1e2)
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_est.p0,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      x_guess=x_guess,
                                      x_N = np.array([293.15,293.15]), # not used
                                      P0=P0,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )

        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend(["model", "measured"])
        plt.show()
        params.to_csv("results/2R2C_vent_w_prior.csv", index=True)
        print(params)
    # dump for plots:
    sol.to_csv("results/linear_in_2R2C_w_prior.csv", index=True)
    print(params)