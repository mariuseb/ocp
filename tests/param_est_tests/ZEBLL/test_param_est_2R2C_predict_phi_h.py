#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
from ocp.mpc import MPC
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
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    cfg_path = os.path.join("configs", "2R2C.json")
    data_path = os.path.join(get_data_path(), "data_ZEBLL_PRBS.csv")
    ekf_config = os.path.join(get_opt_config_path(), "2R2C_EKF.json")

    data = pd.read_csv(data_path)
    # dt is 30 seconds:
    data.index = pd.TimedeltaIndex(data["Unnamed: 0"])
    data.index.name = "time"

    # try with 15 min, 5 min anything that might give a decent model
    # heat: resample with mean, i.e. integration
    # temperatures, solar irr: instantaneous sampling
    downsample = True
    sampling_time = "15min"
    dt = 900

    if downsample:

        heat = data[["phi_h", "phi_s"]]
        heat = heat.resample(sampling_time).mean()

        rest = data[["Ti", "Ta"]]
        rest = rest.resample(sampling_time).first()

        y_data = pd.merge(heat, rest, left_index=True, right_index=True)
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*900, 900)

    else:

        y_data = data
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*30, 30)

    """
    fig, ax = plt.subplots(2,1)
    (y_data.Ti-273.15).plot(color="k", ax=ax[0])
    y_data.phi_h.plot(color="k", ax=ax[1])
    ax[0].set_ylabel(r"Temperature [$^\circ$C]")
    ax[1].set_ylabel(r"Power [W]")
    fig.tight_layout()
    plt.show()
    """

    #y_data = y_data.iloc[0:3]

    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]

    param_guess = np.array([0.01,0.1,1E6,1E7,2])
    lbp = np.array([0.001,0.01,1E5,1E6,1])
    ubp = np.array([0.1,1,1E7,1E8,50])

    """
    First, obtain model:
    """

    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)

        sol_, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )

        ax = sol_["Ti"].plot(color="r")
        sol_["y1"].plot(color="k", ax=ax)
        ax.legend()
        plt.show()
        print(params)
        
    """
    Now, with obtained model, calculate required heating power
    to maintain e.g. a constant indoor temperature of 21 degrees C.
    """

    sol_ = y_data[:-1]
    params = params.values.flatten()
    """
    params = np.array([
                       2.00864277e-03,
                       1.12677891e-02,
                       1.55227947e+06,
                       8.14531899e+06,
                       8.81851190e+00
                       ])
    """
    sol_[["Ti"]] = 21 + 273.15
    sol_["Te"] = sol_.Ti
    lbx = sol_[["Ti", "Te"]][1:]
    ubx = sol_[["Ti", "Te"]][1:]
    x_guess = sol_[["Ti", "Te"]].values
    lbx["Te"] -= 20
    ubx["Te"] += 20
    lbx["Ti"] -= 5
    ubx["Ti"] += 5
    lbx = lbx.values
    ubx = ubx.values
    
    cfg_path = os.path.join("configs", "2R2C_MPC.json")
    x0 = np.array([292.15, 293.15])
    data = sol_
    data["Ti_ref"] = 21 + 273.15
    data = data[["Ti_ref","Ta","phi_s"]]
    
    with MPC(
             config=cfg_path,
             param_guess=params
             ) as mpc:

        sol, u, x0 = mpc.solve(
                                data,
                                x0=x0,
                                lbx=lbx,
                                ubx=ubx,
                                params=params
                                )

        fig, axes = plt.subplots(2,1)
        sol.Ti.plot(ax=axes[0], color="r")
        sol.Ti_ref.plot(ax=axes[0], color="k", linestyle="dashed")
        axes[0].legend(["Ti_ref", "Ti"])
        axes[0].set_ylim([290, 300])
        sol.phi_h.plot(ax=axes[1], color="y")
        axes[1].legend(["phi_h"])
        plt.show()
        print(sol.phi_h)
    