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
#from ocp.boptestGymEnv import BoptestGymEnv
from ocp.customGymEnv import CustomGymEnv
from filterpy.kalman import KalmanFilter
from filterpy.common import Q_discrete_white_noise
from ocp.gym_utils import plot_temperatures
rc('mathtext', default='regular')

def init_filterpy(
    mpc_agent,
    init_obs,
    dt=900
):
    my_filter = KalmanFilter(dim_x=2, dim_z=2, dim_u=2)
    my_filter.x = init_obs
    my_filter.F = mpc_agent.mpc.get_Ad(
        dt,
        p=mpc_agent.mpc.p0
    )
    my_filter.B = mpc_agent.mpc.get_Bd(
        dt,
        p=mpc_agent.mpc.p0
    )
    my_filter.H = np.eye(2)
    my_filter.P *= 1E-16
    my_filter.R = np.eye(2)
    my_filter.Q = Q_discrete_white_noise(dim=2, dt=0.1, var=0.0) # process uncertainty
    return my_filter
        
if __name__ == "__main__":
    
    ################## ALL below should be part of config ######################
    
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
    
    # consider no model mismatch:
    env = CustomGymEnv(
        mpc_cfg, # TODO: own configuration for env
        900,
        params,
        maps
    )
    
    # Add wrappers to normalize state and action spaces (Optional)
    #env = NormalizedObservationWrapper(env)
    #env = NormalizedActionWrapper(env)  
    mpc = MPCAgent(
        mpc_cfg,
        ekf_cfg,
        params
    )
    days = 2
    K = days*24*int(3600/mpc.mpc.dt)
    
    ###########################################################################
    obs, _ = env.reset()
    kf = init_filterpy(
        mpc,
        obs,
    )

    for k in range(K):
        #lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        forecast = env.get_forecast(mpc.dt, mpc.N)
        action, _ = mpc.predict(obs, forecast)
        obs, reward, terminated, truncated, info = env.step(action)

    
    fig, axes, res = plot_temperatures(env.res, K)
    plt.show()
    
    print(env)
