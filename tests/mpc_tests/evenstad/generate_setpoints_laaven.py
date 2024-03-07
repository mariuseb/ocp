#from ast import Param
#from ocp.param_est import ParameterEstimation
#from ocp.covar_solve import CovarianceSolver
#import casadi as ca
#import ocp.dae as dae
#import ocp.integrators as integrators
import numpy as np
import json
import pandas as pd
import matplotlib.pyplot as plt
from ocp.mpc import MPC
from pprint import pprint
from matplotlib import rc
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates
from ocp.result_generator import ResultGenerator
from ocp.tests.utils import Bounds

"""

TODO:
    - visualize the recent measurements compared to the one-step model output.
    CONNECT with:
    - visualize the optimal set-points.

TODO:
    - bounds on Tset / Ti between 14-17:

        1.) First day : as operated normally (21 degrees)

        2.) Rest: as obtained by optimal control algorithm.

    - Write only hours in set-point outfile

    - Split this script into two:

        1.) Obtains, cleans data from respective sources 
        writes to two files (estimation, optimal control)
        
        2.) Sets up the optimal control problem,
        solves, writes set-points to output-file

    - check if historical data can be gotten from same source
    as forecast.
"""

PLOT = True
setpoint_file = "To_SAUTER.csv"

if __name__ == "__main__":

    now = pd.Timestamp("01-26-2024 14:30:00").tz_localize("Europe/Oslo")
    five_today = pd.Timestamp(str(now.date()) + " 17:00").tz_localize("Europe/Oslo")

    # NOTE: you have to modify this to current date
    # to fetch 'real-time' compliant data. 
    # (i.e., if you want to generate optimal set-points
    #  for today)
    
    stop = now

    try:
        assert (now <= stop <= five_today)
        print("Script is running in real-time mode.")
    except AssertionError:
        print(
            "Script must be run between 14:00 and 17:00 " + 
            "on a given day to generate weather data " +
            "that is real-time compliant. Furthermore, " + 
            "it is the responsibility of the user to set"
            "the correct stop point for data retrieval." +
            " Currently it is set to %s, " % (str(stop), ) +
            "which means that the script is generating test data."
            )

    """
    Solve estimation problem:

    NOTE:
        - perphaps easier to re-solve
        this from t=0 each time script 
        is run?
    """
    
    now = now.tz_localize(None)
    date_string = str(now).replace(":", "-")

    weather = pd.read_csv(
                          "kalman_data/%s.csv" % (date_string, ), 
                          index_col=0
                          )
    weather.index = pd.to_datetime(weather.index)
    
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
    weather["dt_index"] = dt_index
    
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
    params_base = pd.read_csv("model_parameters/2R2C_params_week.csv", index_col=0)
    params_weekend = pd.read_csv("model_parameters/2R2C_params_weekend.csv", index_col=0)
    params = pd.read_csv("model_parameters/2R2C_all_params.csv", index_col=0)
    params = params.loc[["Rie","Rea","Ci","Ce","Ai","Ae","alpha_vent"]]
    result_gen = ResultGenerator(
                             #config="configs/3R3C_det_vent_207_cond_weekend_full_tvp.json",
                             config="configs/2R2C_det_vent.json",
                             params=params,
                             dt=3600
                            )
    
    # NOTE: use all data provided by default
    # start = pd.Timestamp("2023-02-06 01:00")
    # stop = pd.Timestamp("2023-02-08 16:00")

    x0 = [weather["Ti"].iloc[0], weather["Ti"].iloc[0]-2]
    #data = weather.loc[start:stop]
    data = weather.copy()
    # TODO: enable switch-ekf
    p_mod = params.copy()
    p_mod.loc[params_weekend.index] += params_weekend
    one_step, filt, results = result_gen.simulate_one_step(
        x0,
        data,
        ekf_config=ekf_path,
        tvp=True,
        cond_series=weather.weekend,
        p_base=params,
        p_mod=p_mod,
        switch=
            lambda x, p, p_mod: 
            p + p_mod
            if x == 1
            else
            p
        )
    # clutter because of timezone,
    # revert to original index 
    one_step.index = weather.index
    
    """
    Plot measured vs. one-step pred.
    """

    ax = data.Ti.plot(color="r")
    one_step.Ti.plot(ax=ax, color="k")
    plt.show()
    
    x0 = one_step[["Ti", "Te"]].iloc[-1].values # + 273.15
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
    lb_day = {"Ti": 294.15}
    ub_day = {"Ti": 297.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ["Ti"],
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    mpc_data = pd.read_csv(
                            "mpc_data/%s.csv" % (date_string, ), 
                            index_col=0
                           )
    mpc_data.index = pd.to_datetime(mpc_data.index)
    start = now.floor("1h").tz_localize("Europe/Oslo")
    mpc_data = mpc_data[start:]
    k = 16 # hr*dt
    lbx, ubx, ref = bounds.get_bounds(k, mpc.N)

    """
    TODO: 15, 16, 17 hours inherits
    set-points calculated day before. 
    If first run, set to 21.
    """

    """
    TODO: figure out ventilation.
    """
    mpc_data["T_sup_air"] = 294.15 
    mpc_data["V_flow_sup_air"] = 0

    # solve for Ti, phi_h:
    sol, u, _x0  = mpc.solve(
                        mpc_data,
                        x0=x0,
                        lbx=lbx,
                        ubx=ubx,
                        params=params,
                        codegen=False
                        )
    sol.index = pd.date_range(start=mpc_data.index[0],
                              end=mpc_data.index[-1],
                              freq="1h")
    data.index = weather.index
    ax = sol.Ti.plot(color="r", linewidth=0.8)
    one_step.Ti.plot(ax=ax, color="k", linewidth=0.8)
    data.Ti.plot(ax=ax, color="g", linestyle="dashed", linewidth=0.8)
    ax.legend(["Optimal set-point", "Kalman estimation of proxy Ti", "Measured proxy Ti"])
    plt.show()

    sol.index = sol.index.tz_localize(None)

    start = pd.Timestamp("%s 18:00" % (str(now.date()), ))
    stop = pd.Timestamp("%s 17:00" % (str((now + pd.Timedelta(days=1)).date()), ))
    #stop = pd.Timestamp("2023-02-09 17:00")
    Tset = (sol[["Ti"]].loc[start:stop] - 273.15)
    
    """
    Perform operations on the set-points:
        - rounding 0.5 degrees.
        - compress table to only changes
        - midnight +1 minute OR every timestep +1 minute
    """
    
    # index +1min
    Tset.index += pd.Timedelta("1min")
    # to nearest 0.5:
    Tset = Tset.apply(lambda x: round(x*2)/2)
    Tset["change"] = Tset.shift(1) - Tset
    # First set-point is change by default:
    Tset.loc[Tset.index[0], "change"] = 1
    Tset["change"] = Tset["change"].astype(bool).astype(int)
    Tset_write = Tset[Tset.change == 1][["Ti"]]
    Tset_write.columns = ["Tset"]
    # cleaner index:
    dt_index = Tset_write.index.to_series()
    hr_index = dt_index.apply(lambda x: str(x).split(" ")[1])
    Tset_write.index = hr_index
    
    Tset_write.to_csv(setpoint_file, index=True)
    print("Set-points successfully generated, written to %s" % \
        setpoint_file)
    
    
    
    
    
    