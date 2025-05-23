#from ast import Param
from ocp.mpc import MPC
import numpy as np
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.tests.utils import get_boptest_config_path
from matplotlib import rc
import pandas as pd
#import os
from pathlib import Path
from copy import deepcopy
from typing import Tuple
from ocp.mpc_agent import MPCAgent
from ocp.filters import KalmanDAE
from ocp.boptestGymEnv import BoptestGymEnv
rc('mathtext', default='regular')

        
if __name__ == "__main__":
    
    ################## ALL below should be part of config ######################
    
    cols = pd.MultiIndex.from_product(
        [["lb", "ub"], ["Ti", "Te"]],
        names=['bound', 'y']
    )
    bounds = pd.DataFrame(
        columns=cols,
        data = [[293.15, 296.15, -np.inf, np.inf]]
    )
    params = np.array([
        1e-3,
        1e-2,
        1E6,
        1E7
    ])
    
    mpc_cfg = Path(
        "mpc_configs",
        "2R2C_MPC.json"
    )
    ekf_cfg = Path(
        "ekf_configs",
        #"2R2C_EKF.json"
        "2R2C_EKF_2meas.json"
    )
    maps = {
        "r" : {"Ta": "TDryBul",
               "Ti_lb": "LowerSetp[1]",
               "Ti_ub": "UpperSetp[1]",
               "cost": "PriceElectricPowerHighlyDynamic"
              },
        "u" : {"phi_h": "oveAct"},
        "y":  {
            "Ti": "TRooAir",
            "Te":  "TRooEnv"
        }
    }
    env = BoptestGymEnv(
        url                  = 'http://docker-web-1:80',
        testcase             = 'testcase_2R2C',
        actions              = ['oveAct_u'],
        observations         = {
                                #'time':(0,604800),
                                'TRooAir_y':(280.,310.),
                                'TRooEnv_y':(280.,310.),
                                #'TDryBul':(265,303),
                                #'LowerSetp[1]':(280.,310.),
                                #'UpperSetp[1]':(280.,310.)
                                }, 
        predictive_period    = 0, 
        regressive_period    = None, 
        maps                 = maps,
        random_start_time    = False,
        max_episode_length   = 24*3600,
        warmup_period        = 0,
        step_period          = 900
    )
    # Add wrappers to normalize state and action spaces (Optional)
    #env = NormalizedObservationWrapper(env)
    #env = NormalizedActionWrapper(env)  
    mpc = MPCAgent(
        mpc_cfg,
        ekf_cfg,
        params
    )
    days = 1
    K = days*24*int(3600/mpc.mpc.dt)
    
    ###########################################################################
    
    obs0, _ = env.reset()
    # augment obs w/ extra state:
    #x0 = np.append(obs, [293.15])
    x0 = obs0
    for k in range(K):
        #lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        forecast = env.get_forecast(mpc.dt, mpc.N)
        action, _ = mpc.predict(x0, forecast)
        obs, reward, terminated, truncated, info = env.step(action)
        x0 = mpc.x0_from_obs(obs)
    
    fig, axes, res = env.plot_temperatures(K, bounds)
    plt.show()
    
    res_nofilter = pd.read_csv("results_1_day_2R2C_no_filtering.csv", index_col=0)
    res_nofilter.index = pd.to_datetime(
        res_nofilter.index
    )
    res.to_csv("results_1_day_2R2C")
    
    ax = res.Ti.plot(color="b", drawstyle="steps-post")
    res_nofilter.Ti.plot(color="r", drawstyle="steps-post")
    plt.show()
    
    ax = res.phi_h.plot(color="b", drawstyle="steps-post")
    res_nofilter.phi_h.plot(color="r", drawstyle="steps-post")
    plt.show()
    
    est_df = mpc.ekf.df.copy()
    est_df.loc[0] = obs0
    est_df = est_df.sort_index()
    est_df.index = res.index
    
    fig, axes = plt.subplots(2,1)
    ax = axes[0]
    res["Ti"].plot(ax=ax, drawstyle="steps-post", color="k")
    est_df["Ti"].plot(ax=ax, drawstyle="steps-post", color="r")
    ax.legend(["meas", "filtered"])
    ax = axes[1]
    res["Te"].plot(ax=ax, drawstyle="steps-post", color="k")
    est_df["Te"].plot(ax=ax, drawstyle="steps-post", color="r")
    ax.legend(["meas", "filtered"])
    plt.show()
    
    
    
    print(env)
