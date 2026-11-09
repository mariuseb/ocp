#from ast import Param
from ocp.mpc import MPC
from ocp.ocp import get_scale
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api_old import Boptest
from pprint import pprint
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from copy import deepcopy
#from pprint import pprint

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    mpc_cfg = "2R2C_MPC_peak_double.json"
    params = pd.read_csv(
        "params_1st_week_n_occ.csv", 
        index_col=0
    ).squeeze()
    p_scale = get_scale(params.values)
    p_scale[-1] = 1
    data = pd.read_csv(
        "test_forecast.csv", 
        index_col=0
    )
    data.index = pd.to_datetime(
        data.index, unit="s"
    )
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [1000,1000],
        "z_nom": [1000],
        "r_nom": [12,1000,1],
        "r_nom_b": [289.15,0,0],
        "p_nom": p_scale,
        "slack": True
    }
    mpcs = {}
    for i in range(1):
        mpcs[i] = MPC(
            config=mpc_cfg,
            param_guess=params.values, 
            **deepcopy(kwargs)
        )  # to remove, replace with N
    mpc = mpcs[0]

    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 295.15}
    ub_day = {"Ti": 297.15}
    
    bounds = Bounds(
        mpc.dt,
        ["Ti", "Te", "Ti", "Te"],
        ["Ti"],
        lb_night=lb_night,
        ub_night=ub_night,
        lb_day=lb_day,
        ub_day=ub_day
    )
    k = 0
    lbx, ubx, ref = bounds.get_bounds(0, mpc.N)
    x0s = {
        0: np.array([293.15, 291.15, 291.15, 291.15])
    }
    sols = {}
    
    for i in range(1):
        x0 = x0s[i]
        mpc = mpcs[i]
        sol, u, _x0, raw_sol = mpc.solve(
            data,
            x0=x0,
            lbx=lbx,
            ubx=ubx,
            params=params,
            return_raw_sol=True,
            codegen=False
        )
        sol.index = data.index
        sols[i] = sol

    fig, axes = plt.subplots(2,1, sharex=True)

    for i in range(2):
        ax = axes[i]
        sol["Ti" + str(i+1)].plot(drawstyle="steps-post", ax=ax)
        data["Ti_ub"].plot(drawstyle="steps-post", color="k", linewidth=2, ax=ax)
        data["Ti_lb"].plot(drawstyle="steps-post", color="k", linewidth=2, ax=ax)
        ax1 = ax.twinx()
        (sol["Prad" + str(i+1)]/1000).plot(drawstyle="steps-post", color="r", ax=ax1)
        (sol["cost"]).plot(drawstyle="steps-post", color="y", ax=ax1)
    for ax in axes:
        ax.set_ylim([288,302])
    plt.show()
    print("tail")
