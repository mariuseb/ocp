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
from copy import deepcopy
from pprint import pprint
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    base = Config()("base_config.json")
    meta = Config()("config_meta.json")
    x0 = np.array([
        293.15, 293.15, 16
    ])
    cfgs = {}
    for k, v in meta.items():
        cfg = deepcopy(base)
        # fill missing:
        for _k, _v in v.items():
            cfg["controller"][_k] = _v
        cfgs[k] = cfg
    
    read_coords = {}
    
    for k, v in cfgs.items():
        coord = Coordinator.read_result(v)
        read_coords[k] = coord
        
    for k, v in read_coords.items():   
        print("")     
        print("")     
        print(k + " kpis:")
        print(v.kpis)
        
    for k, v in read_coords.items():        
        fig, axes, res = v.plot_temperatures(
            heat_key="Prad"
        )
        fig.suptitle(k)
        plt.show()
    
    pprint(cfgs)
    