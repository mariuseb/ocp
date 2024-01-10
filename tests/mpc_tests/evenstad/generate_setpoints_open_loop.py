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
from ocp.mpc import MPC
from pprint import pprint
from matplotlib import rc
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from ocp.frost_function import get_metno_data, get_stations, get_observations
from ocp.functions import functions
# text:
rc('mathtext', default='regular')

# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.result_generator import ResultGenerator
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path

PLOT = True

if __name__ == "__main__":

    """
    Needed data is read below:
    """
    
    weather = pd.read_csv("weather_data_open_loop_test.csv", index_col=0)
    weather["T_sup_air"] = weather["Tsup_air"]
    #weather["Ta"] += 273.15
    #weather["T_sup_air"] += 273.15
    weather.index = pd.to_datetime(weather.index)
    spot = pd.read_excel("spot.xlsx", index_col=0)["Price"]
    spot = spot.apply(lambda x: x.replace(",", ".")).astype(float)
    spot.index = range(len(spot.index))
    
    def filter_weekend(ndx):
        if ndx.dayofweek == 4:
            if ndx.hour >= 18:
                return True
            else:
                return False
        elif ndx.dayofweek == 2:
            if ndx.hour < 18:
                return True
            else:
                return False
        elif ndx.dayofweek in (5,6,0,1):
            return True
        else:
            return False
    
    dt_index = pd.Series(weather.index)
    #weather["weeknd"] = dt_index.apply(filter_weekend)
    weather["weekday"] = dt_index.apply(lambda x: x.dayofweek)
    weeknd = (dt_index.apply(lambda x: True if x.dayofweek in (5,6) else False)).astype(int)
    weeknd.index = weather.index
    # boolean series for the two additional modes:
    weather["vent_on"] = (weather["V_flow_sup_air"] > 20000).astype(int)
    weather["weekend"] = weeknd
    
    """
    Need ekf (warm-up), 
    mpc (optimal control) objects 
    """
    ekf_path = "configs/2R2C_det_vent_EKF.json"
    mpc_path = "configs/2R2C_det_vent_MPC.json"
    
    """
    Test, use two days to warm-up the model 
    and retrieve x0.
    """
    params_base = pd.read_csv("2R2C_params_week.csv", index_col=0)
    params_week = pd.read_csv("2R2C_params_weekend.csv", index_col=0)
    params = pd.read_csv("2R2C_all_params.csv", index_col=0)
    params = params.loc[["Rie","Rea","Ci","Ce","Ai","Ae","alpha_vent"]]
    result_gen = ResultGenerator(
                             #config="configs/3R3C_det_vent_207_cond_weekend_full_tvp.json",
                             config="configs/2R2C_det_vent.json",
                             params=params,
                             dt=3600
                            )
    start = pd.Timestamp("2023-02-06 01:00")
    stop = pd.Timestamp("2023-02-08 16:00")
    
    x0 = [weather["Ti"].iloc[0], weather["Ti"].iloc[0]-1]
    data = weather.loc[start:stop]
    one_step, filt, results = result_gen.simulate_one_step(
        x0,
        data,
        ekf_config=ekf_path,
        p_base=params
    )
    print(one_step)
    
    """
    plot measured vs. one-step pred.
    """
    ax = data.Ti.plot(color="r")
    one_step.Ti.plot(ax=ax, color="k")
    plt.show()
    
    x0 = one_step[["Ti", "Te"]].iloc[-1].values + 273.15
    """
    Now, with x0 obtained from kalman warm-up,
    calculate optimal set-points.
    """
    kwargs = {
        "x_nom": 300,
        "u_nom": 1E5,
        "r_nom": 300,
        #"p_nom": [1E-3,1E-3,1E6,1E7,1,1,10,1,300],
        "y_nom": 300,
        #"slack": Trues
        "slack": False
    }
    params = params.values.flatten()
    
    mpc = MPC(config=mpc_path,
            param_guess=params, 
            **kwargs)  # to remove, replace with N
    
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ["Ti"],
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    
    start = pd.Timestamp("2023-02-08 16:00")
    stop = pd.Timestamp("2023-02-09 18:00")
    
    data = weather.loc[start:stop]
    # add spot price:
    P_spot = spot.loc[16:42]
    P_spot.index = data.index
    data["P_spot"] = P_spot
    # to Kelvin:
    data["Ta"] += 273.15
    data["Ti"] += 273.15
    data["T_sup_air"] += 273.15
    k = 16 # hr*dt
    lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
    data = data[mpc.r_names + ["Ti"]]
    # solve for Ti, phi_h:
    sol, u, x0  = mpc.solve(
                        data,
                        x0=x0,
                        lbx=lbx,
                        ubx=ubx,
                        params=params,
                        codegen=True
                        )
    sol.index = data.index
    ax = sol.Ti.plot(color="r")
    data.Ti.plot(ax=ax, color="k")
    ax.legend(["Optimal set-point", "Original"])
    plt.show()
    
    start = pd.Timestamp("2023-02-08 18:00")
    stop = pd.Timestamp("2023-02-09 17:00")
    Tset = sol["Ti"].loc[start:stop]
    Tset.columns = ["Tset"]
    Tset.to_csv("To_SAUTER_test.csv", index=True)
    
    
    
    
    
    