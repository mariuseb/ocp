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
from utils import quick_plot, plot_parameter_evolution
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_2R2C_MHE_min_energy.json")
    traverse_dict(
        cfg
    )
    cfg["days"] = 7
    coord = Coordinator(
        # "coordinator_boptest.json"
        cfg
    )
    x0 = np.array([
        295.15, 293.15
    ])
    coord.run(x0=x0)
    coord.write_result()
    
    quick_plot(coord)
    
    plot_parameter_evolution(coord, "params_result/2R2C_params_jan.csv")
    
    print("tail")