#from ast import Param
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF, KalmanBucy
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from copy import deepcopy
from pprint import pprint

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    #mpc_cfg = os.path.join(opt_config_base, "1R1C_MPC_slack.json")
    mpc_cfg = os.path.join("mpc_configs", "1R1C_MPC.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_idas.json")
    #mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_map_test.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    # pass in config?
    """
    params = ca.DM([0.0015,
                    0.0116,
                    1.33E6,
                    6.64E6,
                    5.53])
    params = ca.DM([
                    2.008534e-03,
                    1.126790e-02,
                    1.552069e+06,
                    8.145441e+06,
                    8.818424e+00
                    ])
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 5000,
        "r_nom": [12, 100],
        "r_nom_b": [289.15, 0],
        "y_nom": 12,
        "y_nom_b": 289.15,
        #"slack": True
        "slack": True
    }
    params = ca.DM([
                    1E-2,
                    1E6
                    ])
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        #"slack": True
        "slack": True
    }
    """
    
    kwargs = {
        "p_nom": [1e-2, 1e6]
    }
    #params = ca.DM([
    #                0.008,
    #                1.2E6
    #                ])
    params = ca.DM([
                    0.01,
                    1E6
                    ])   
    kwargs = dict()
    
    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(3600,
                    mpc.dae.x,
                    ["Ti"],
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([293.15])
    days = 7
    K = days*24*bounds.t_h
    
    for k in range(K):    
        data, y_meas, u_meas = boptest.evolve()

    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    # plot reference for easy visualization
    #ref = np.repeat([22], len(dt_index))
    #axes[0].plot(dt_index, ref, color="r", linestyle="dashed")    
    plt.show()    
    fig.tight_layout()