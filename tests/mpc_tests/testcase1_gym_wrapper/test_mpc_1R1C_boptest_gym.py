#from ast import Param
from ocp.mpc import MPC
import numpy as np
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.tests.utils import get_boptest_config_path
from matplotlib import rc
import pandas as pd
import os
from copy import deepcopy
from typing import Tuple
from ocp.mpc_agent import MPCAgent
from ocp.boptestGymEnv import BoptestGymEnv
rc('mathtext', default='regular')

        
if __name__ == "__main__":
    
    cols = pd.MultiIndex.from_product(
        [["lb", "ub"], ["Ti"]],
        names=['bound', 'y']
    )
    bounds = pd.DataFrame(
        columns=cols,
        data = [[293.15, 296.15]]
    )
    
    mpc_cfg = os.path.join(
        "mpc_configs",
        "1R1C_MPC.json"
    )
    ekf_cfg = os.path.join(
        "ekf_configs",
        "1R1C_EKF.json"
    )
    maps = {
        "r" : {"Ta": "TDryBul",
               "Ti_lb": "LowerSetp[1]",
               "Ti_ub": "UpperSetp[1]",
               "cost": "PriceElectricPowerHighlyDynamic"
              },
        "u" : {"phi_h": "oveAct"},
        "y":  {"Ti": "TRooAir"}
    }
    env = BoptestGymEnv(
        url                  = 'http://docker-web-1:80',
        testcase             = 'testcase1',
        actions              = ['oveAct_u'],
        observations         = {
                                #'time':(0,604800),
                                'TRooAir_y':(280.,310.),
                                #'TDryBul':(265,303),
                                #'LowerSetp[1]':(280.,310.),
                                #'UpperSetp[1]':(280.,310.)
                                }, 
        predictive_period    = 0, 
        regressive_period    = None, 
        maps                 = maps,
        random_start_time    = False,
        max_episode_length   = 1e6,
        warmup_period        = 0,
        step_period          = 60
    )
    # Add wrappers to normalize state and action spaces (Optional)
    #env = NormalizedObservationWrapper(env)
    #env = NormalizedActionWrapper(env)  
    mpc = MPCAgent(
        mpc_cfg,
        ekf_cfg,
        np.array([1e-2, 1E6])
    )
    days = 1
    K = days*24*int(3600/mpc.mpc.dt)
    
    obs, _ = env.reset()
    
    for k in range(K):
        #lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        forecast = env.get_forecast(mpc.dt, mpc.N)
        action, _ = mpc.predict(obs, forecast)
        obs, reward, terminated, truncated, info = env.step(action)
    
    fig, axes, dt_index = env.plot_temperatures(K, bounds)
    plt.show()
