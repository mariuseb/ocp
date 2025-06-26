#from ast import Param
from ocp.mpc import MPC
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
import pandas as pd
#import os
from pathlib import Path
from ocp.mpc_agent import MPCAgent
from ocp.customGymEnv import CustomGymEnv
rc('mathtext', default='regular')

        
if __name__ == "__main__":
    
    params = pd.read_csv(
         "full_model_4R4C.csv", index_col=0
    ).values.flatten()
    
    mpc_cfg = Path(
        "mpc_configs",
        "4R4C_MPC_energy_squared.json"
    )
    ekf_cfg = Path(
        "ekf_configs",
        "4R4C_2meas_EKF_adj.json"
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
    
    mpc = MPCAgent(
        mpc_cfg,
        "ocp.kalman.ExtendedKalmanFilter",
        ekf_cfg,
        params
    )
    
    
    mpc.predict()
    
    

