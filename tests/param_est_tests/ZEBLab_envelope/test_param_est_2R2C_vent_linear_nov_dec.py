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
from utils import prepare_data, ZEBData
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
    y_data.Ti.plot(ax=ax)
    for col in ["T_207", "T_211", "T_213", "T_217"]:
        y_data[col].plot(ax=ax, linewidth=0.5)
    ax.legend()
    ax1 = ax.twinx()
    y_data.phi_h.plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    P_vent = y_data.V_sup_air*(y_data.T_sup_air - y_data.Ti)
    P_vent.plot(ax=ax1, color="g", linewidth=0.75)
    ax1.legend(["calculated from OE16 V_flow, delta T", ""])
    

if __name__ == "__main__":

    """
    Proof of concept for grey-box SYSID, ZEB Lab.
    Use room 219 first.
    """

    cfg_path = os.path.join("configs", "2R2C_det_vent.json")
    data_path = os.path.join("ZEBLab_nov23_1m.csv")
    old_data_path = os.path.join("ZEBLab_2years_60m.csv")

    zeb_data = ZEBData(data_path)
    zeb_data_old = ZEBData(old_data_path)
    
    start = pd.Timestamp("2023-11-14 00:00")
    stop = pd.Timestamp("2023-11-28 00:00")
    
    y_data = zeb_data.get_dataset(start=start, stop=stop)
    y_data_old = zeb_data_old.get_dataset(start=start, stop=stop)

    #y_data = prepare_data(data)
    y_data = y_data.resample(rule="1H").mean()
    # some temps missing?:
    y_data = y_data.bfill()

    fig, axes = plt.subplots(2,1,sharex=True)
    quick_plot(axes[0], y_data)
    quick_plot(axes[1], y_data_old)
    plt.show()
    
    ax = y_data.Ti.plot(color="r")
    y_data_old.Ti.plot(color="b", ax=ax)
    plt.show()
    

    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification:
    y_data.index = range(0,N*dt,dt)

    param_guess = np.array([1e-02,
                    1e-01,
                    1E6, #1E6,
                    5E6, #1E7,
                    10,
                    10,
                    0.5,
                    1E-0,
                    1E-0,
                    1E-0,
                    1E-1,
                    1E-1,
                    1E-1])
    
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    len_p = param_guess.shape[0]
    #ubp[len_p-1] = 1    
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess


    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

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
                                      Te_anti_bias=True,
                                      #Th_anti_bias=True,
                                      covar=ca.veccat(Q, R)
                                      )

        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend(["model", "measured"])
        plt.show()
        params.to_csv("results/params_envelope_2R2C_linear.csv", index=True)
        print(params)
    # dump for plots:
    sol.to_csv("results/linear_in_training_traj_2R2C.csv", index=True)