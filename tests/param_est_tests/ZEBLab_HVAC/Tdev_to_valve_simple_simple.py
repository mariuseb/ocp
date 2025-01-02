#from ast import Param

import sys
import os
import pathlib
#ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
#sys.path.append(ocp_path)
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
from ocp.utils import prepare_data, ZEBData, quick_plot
from ocp.functions import functions
from pandas.plotting import autocorrelation_plot
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    """
    Proof of concept for grey-box SYSID, ZEB Lab.
    Use room 219 first.
    """

    cfg_path = os.path.join("configs", "Tdev_to_valve_simple_simple.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    data_path = os.path.join("ZEBLab_nov23_oct24_1m.csv")
    Data = ZEBData(data_path)
    Tdev = Data.data.T_set - Data.data.T_219_TR3
    #Tdev[Tdev < 0] = 0
    Data.data["Tdev"] = Tdev
    #Data.data["u_val"] = Data.data.val_pos_219/100
    #Data.data["m_flow"] = Data.data.V_flow_219/Data.data.V_flow_219.max()
    # take subset of data:
    start = pd.Timestamp("2023-12-09 00:00")
    stop = pd.Timestamp("2023-12-11 00:00")
    sampling_time = "5min"
    
    Tdev = Data.data.T_set - Data.data.T_219_TR3
    Tsup = Data.data.T_sup_219
    Tret = Data.data.T_ret_219
    Ta = Data.data.T_amb
    Tdev = Tdev.resample(rule=sampling_time).mean()
    m_flow = Data.data.V_flow_219/Data.data.V_flow_219.max()
    m_flow = m_flow.resample(rule=sampling_time).mean()
    Tsup = Tsup.resample(rule=sampling_time).mean()
    Tret = Tret.resample(rule=sampling_time).mean()
    u_val = Data.data.val_pos_219/100
    u_val = u_val.resample(rule=sampling_time).mean()
    phi_h = Data.data.P_rad_219
    phi_h = phi_h.resample(rule=sampling_time).mean()
    Tdev[Tdev < 0] = 0
    fig, axes = plt.subplots(2,1,sharex=True)
    ax = axes[0]
    Tdev.plot(drawstyle="steps-post", ax=ax)
    u_val.plot(drawstyle="steps-post", ax=ax, color="m")
    m_flow.plot(drawstyle="steps-post", ax=ax, color="g")
    ax1 = ax.twinx()
    phi_h.plot(drawstyle="steps-post", ax=ax)
    
    ax = axes[1]
    Tsup.plot(drawstyle="steps-post", ax=ax)
    Tret.plot(drawstyle="steps-post", ax=ax, color="m")
    ax1 = ax.twinx()
    Ta.plot(drawstyle="steps-post", ax=ax)
    plt.show()
    
    y_data, dt, N = Data.get_dataset(
                        start=start, 
                        stop=stop, 
                        sampling_rate=sampling_time
                        )
    y_data["y2"] = y_data["u_val"]
    kwargs = {
        "slack": False
    }

    x_guess = y_data[["u_val","u_val"]].values.T
    x_guess = x_guess.flatten()
    
    param_guess = {
        "kp": 
        {
        "init": 1.2,
        "lb": 0.2,
        "ub": 10
         },
        "ki": 
        {
        "init": 900,
        "lb": 100,
        "ub": 3600
         },
        "k_aw": 
        {
        "init": 0.01,
        "lb": 1e-4,
        "ub": 1e4
         },
        "a": 
        {
        "init": 10,
        "lb": 9.99,
        "ub": 10.01
         },
        "b": 
        {
        "init": 5,
        "lb": 4.99,
        "ub": 5.01
         }
        }
    
    y_data["Tdev"][y_data.y2 == 0] = 0
    y_data["heat_mode"] = 1
    y_data["heat_mode"][y_data.y2 == 0] = 0
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        #R[0,0] = 1E-2
        #R[1,1] = 1E-2
        
        lbp = param_est.get_lbp(1e-3)
        ubp = param_est.get_ubp(1e3)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      #lbx=lbx,
                                      #ubx=ubx,
                                      covar=ca.veccat(Q,R),
                                      codegen=False
                                      )
        fig, axes = plt.subplots(2,1,sharex=True)
        sol[["E", "aw", "Tdev","u_val_cmd"]].plot(drawstyle="steps-post", ax=axes[0])
        sol[["y2"]].plot(drawstyle="steps-post", ax=axes[1])
        sol[["u_val"]].plot(drawstyle="steps-post", ax=axes[1], linestyle="dashed")
        plt.show()
        print(sol)
