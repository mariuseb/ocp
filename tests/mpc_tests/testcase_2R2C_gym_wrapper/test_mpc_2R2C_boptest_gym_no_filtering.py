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
        data = [[293.15, -np.inf, 296.15, np.inf]]
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
        "2R2C_EKF.json"
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
    obs, _ = env.reset()
    # augment obs w/ extra state:
    #x0 = np.append(obs, [293.15])

    cols = pd.MultiIndex.from_product(
        [["model", "emu"], ["Ti", "Te"]],
        names=['type', 'state']
    )
    temps = pd.DataFrame(
        columns=cols,
    )

    for k in range(K):
        #lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        forecast = env.get_forecast(mpc.dt, mpc.N)
        action, _ = mpc.predict(obs, forecast)
        obs, reward, terminated, truncated, info = env.step(action)
        temps.loc[k, "model"] = mpc.preds[k][mpc.mpc.x()].iloc[1].values
        temps.loc[k, "emu"] = obs
        #x0 = np.append(obs, mpc.preds[mpc.i-1].iloc[1]["Te"])
    
    fig, axes, res = env.plot_temperatures(K, bounds)
    res.to_csv("results_1_day_2R2C_no_filtering.csv")
    plt.show()
    print(env)
