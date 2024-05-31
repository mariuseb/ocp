#from ast import Param
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
from ocp.frost_function import get_metno_data, get_stations, get_observations
from ocp.functions import functions
from ocp.tests.mpc_tests.evenstad.utils import prepare_data
# text:
rc('mathtext', default='regular')

# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

PLOT = True

if __name__ == "__main__":

    cfg_path = "configs/2R2C_det_vent.json"
    meas = pd.read_csv("Laaven_MeasData_2024-04-03___2024-04-15.csv", index_col=0)
    wea = pd.read_csv("Laaven_Weather_2024-04-03___2024-04-15.csv", index_col=0)
    
    all_data, temp_cols = prepare_data(meas)
    try:
        wea.index = all_data.index
    except:
        wea.index = pd.to_datetime(wea.index).tz_localize(None)
        wea = wea.resample(rule="5min").bfill()
    all_data = pd.merge(all_data,
                        wea, 
                        left_index=True,
                        right_index=True)
    
    if PLOT:
        # main points: 
        fig, axes = plt.subplots(4,1, sharex=True)
        ax = axes[0]        
        #all_data[temp_cols].plot(drawstyle="steps-post", ax=ax)
        all_data["Ti"].plot(linewidth=2, color="k", ax=ax)
        #all_data[temp_cols].mean(axis=1).plot(linewidth=2, color="b", ax=ax)
        #all_data[temp_cols].plot(linewidth=2, color="b", ax=ax)
        ax = axes[1]
        all_data.phi_h.plot(color="r", ax=ax, drawstyle="steps-post")
        ax.legend(["Heating power"])
        ax = axes[2]
        all_data.Ta.plot(color="g", ax=ax, drawstyle="steps-post")
        ax.legend(["Ambient temperature"])
        ax = axes[3]
        all_data.phi_s.plot(color="y", ax=ax, drawstyle="steps-post")
        ax.legend(["Solar global"])
        plt.show()
       
    """
    Data selection:
    
        - we try to stitch together weekdays across weeks,
        see what turns out.
        - same with weekends.
    
    """
    
    dt_index = pd.Series(all_data.index)
    weeknd = (dt_index.apply(lambda x: True if x.dayofweek in (5,6) else False)).astype(int)
    weeknd.index = all_data.index
    # boolean series for the two additional modes:
    all_data["vent_on"] = (all_data["V_flow_sup_air"] > 20000).astype(int)
    all_data["weeknd"] = weeknd
    all_data.to_csv(
                    "april_2024.csv", 
                    index=True
                    )
    
    
    """
    Training data selection:
    """
    start = pd.Timestamp("2024-04-04 00:00")
    stop = pd.Timestamp("2024-04-15 23:00")
    y_data = all_data.loc[start:stop]
    y_data = y_data.interpolate()
    y_data = y_data.bfill()
    # keep dt_index for now:
    y_data["dt_index"] = y_data.index

    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0,N*dt, dt)
    
    param_guess = {
                "Rie": 
                {
                    "init": 1e-2
                },
                "Rea": 
                {
                    "init": 1e-2,
                    "ub": 1,
                },
                "Ria":
                {
                    "init": 1e-1
                },
                "Rih":
                {
                    "init": 1e-2,
                    "lb": 1e-6
                },
                "Ci":
                {
                    "init": 1E6,
                    #"ub": 1E9,
                },
                "Ce":
                {
                    "init": 1E7,
                    "lb": 1E6,
                },
                "Ch":
                {
                    "init": 1E7
                },
                "Ai":
                {
                    "init": 100,
                    "ub": 300,
                    "lb": 0.1
                },
                "Ae":
                {
                    "init": 50, 
                    "lb": 0.1,
                    "ub": 200
                },
                "alpha_vent":
                {
                    "init": 0.5,
                    "lb": 1e-2,
                    "ub": 100
                }
                }
    
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2
                    #y_data.Ti.values.flatten() + 5
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess

    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        lbp = param_est.get_lbp(1e-3)
        ubp = param_est.get_ubp(1e3)
        sol, params, raw_sol = param_est.solve(
                                        y_data,
                                        param_guess,
                                        lbp=lbp,
                                        ubp=ubp,
                                        lbx=lbx,
                                        ubx=ubx,
                                        x_guess=x_guess,
                                        Te_anti_bias=True,
                                        covar=ca.veccat(Q, R),
                                        return_raw_sol=True,
                                        codegen=True
                                        )
        fig, axes = plt.subplots(2,1,sharex=True)
        ax = axes[0]
        sol.index = y_data.dt_index
        y_data.index = y_data.dt_index
        sol["Ti"].plot(color="r", ax=ax, drawstyle="steps-post")
        #y_data[temp_cols].mean(axis=1).plot(ax=ax)
        sol["y1"].plot(color="k", ax=ax, drawstyle="steps-post")
        ax.legend(["Ti_model", "Ti_measured"])
        ax = axes[1]
        sol[["Ti", "Te"]].plot(ax=ax)
        ax.legend(["Ti", "Te"])
        plt.show()
        param_est.write_tvp_kalman_files(
                    cfg_path.lstrip("configs/").rstrip(".json"),
                    params,
                    switches=["weeknd"]
                    )
        params.to_csv(
            "results/params_" + \
             cfg_path.lstrip("configs/").rstrip(".json") + \
            ".csv",
            index=True
            )
        sol.to_csv(
            "results/sol_" + \
             cfg_path.lstrip("configs/").rstrip(".json") + \
            ".csv",
            index=True
            )
        print(params)