#from ast import Param
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
#import os
#from pathlib import Path
#from ocp.mpc_agent import MPCAgent
#from ocp.boptestGymEnv import BoptestGymEnv
#from ocp.customGymEnv import CustomGymEnv
from ocp.coordinator import Coordinator
from ocp.config import Config
from ocp.filter_wrapper import FilterWrapper
rc('mathtext', default='regular')
if __name__ == "__main__":
    
    cfg = Config()("ekf_configs/2R2C_EKF_2meas.json")
    kf = FilterWrapper(cfg, "filterpy.kalman.KalmanFilter")
    print(kf)
