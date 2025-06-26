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
from ocp.config import Config, traverse_dict, get_json_hash
rc('mathtext', default='regular')
import pickle



if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_2R3C_pickling.json")
    traverse_dict(
        cfg
    )
    coord = Coordinator(
        cfg
    )
    x0 = np.array([
        293.15, 
        293.15,
        16
    ])
    coord.run(x0=x0)
    coord.write_result()
    
    fig, axes, res = coord.plot_temperatures(
        heat_key="Prad"
    )
    plt.show()
    
    coord_read = Coordinator.read_result(cfg)
    
    fig, axes, res = coord_read.plot_temperatures(
        heat_key="Prad"
    )
    plt.show()
    
    coord_read.run(x0=x0)
    
    print(coord_read == coord)
    
    print(coord)