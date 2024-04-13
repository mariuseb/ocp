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

    cfg_path = os.path.join("configs", "vent_only_CO2.json")
    data_path = os.path.join("ZEBLab_nov23_1m.csv")

    zeb_data = ZEBData(data_path)
    
    start = pd.Timestamp("2023-11-14 00:00")
    stop = pd.Timestamp("2023-11-28 00:00")
    
    y_data = zeb_data.get_dataset(start=start, stop=stop)

    #y_data = prepare_data(data)
    y_data = y_data.bfill()
    y_data = y_data.resample(rule="1H").mean()
    night_inds = [
                  ndx for ndx in y_data.index \
                  if \
                  ndx.hour < 6 or \
                  ndx.hour > 19
                 ]
    y_data["n_occ"] = 0
    y_data["y7"] = y_data["n_occ"]
    y_data["occ_weight"] = 0
    # at night, assume zero:
    y_data.loc[night_inds, "occ_weight"] = 5e3
    # some temps missing?:

    fig, axes = plt.subplots(1,1,sharex=True)
    quick_plot(axes, y_data)
    plt.show()
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification:
    y_data.index = range(0,N*dt,dt)

    
    param_guess = np.array([
                    3e-3,
                    450,
                    0.5, 
                    6e-3
                    ])
    
    lbp = 1e-2*param_guess
    ubp = 1e2*param_guess
    lbp[1] = 300
    ubp[1] = 460
    lbp[2] = 0.1
    ubp[2] = 3
    
    len_p = param_guess.shape[0]
    
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.CO2_in
                    ])
    lbx = 0.1*x_guess
    ubx = 2*x_guess

    kwargs = {
        "x_nom": 300,
        "x_nom_b": 400,
        "z_nom": [10,10,10,10],
        "r_nom": 1,
        "u_nom": [10]*4,
        "y_nom": [300,10],
        "y_nom_b": [400,0],
        #"slack": True
        "slack": False
    }

    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess,
                             #**kwargs,
                             ) as param_est:

        Q = ca.DM.eye(1)
        R = ca.DM.eye(2)
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      #lbx=lbx,
                                      #ubx=ubx,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=False
                                      )

        sol.index = y_data.dt_index
        
        fig, axes = plt.subplots(2,1,sharex=True)
        ax = axes[0]
        sol["CO2_in"].plot(color="r", ax=ax)
        sol["y6"].plot(color="k", linestyle="dashed", ax=ax)
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        sol["n_occ"].plot(ax=ax1, drawstyle="steps-post")
        ax1.legend(loc="upper left")
        
        ax = axes[1]
        sol["n_mech"].plot(ax=ax, drawstyle="steps-post")
        sol["n_air"].plot(ax=ax, drawstyle="steps-post")
        sol["n_nat"].plot(ax=ax, drawstyle="steps-post")
        ax.legend()
        
        plt.show()
        
        print(params)