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
import pandas as pd
from ocp.config import Config, traverse_dict
from utils import quick_plot
from pprint import pprint
from sklearn.metrics import mean_squared_error
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_2R2C.json")
    cfg = Config()("coordinator_boptest_2R2C_adaptive_NL.json")
    traverse_dict(
        cfg
    )
    coord_mpc = Coordinator.read_result(cfg)
    quick_plot(coord_mpc)
    kpis_mpc = coord_mpc.get_custom_kpis()
    
    
    
    print("tail")