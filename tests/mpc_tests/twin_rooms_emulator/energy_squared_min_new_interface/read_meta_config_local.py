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
from utils import quick_plot
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    _path = "results_local"
    base = Config()("base_config_scaled.json")
    base["days"] = 120
    meta = Config()("config_meta_test.json")
    
    read_coords = {}
    for k, v in meta.items():
        cfg = deepcopy(base)
        for _k, _v in v.items():
            if _k != "cost":
                cfg["controller"][_k] = _v
        cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]

        coord = Coordinator.read_result(cfg, _path=_path)
        read_coords[k] = coord
        #quick_plot(coord)
        print(k + " kpis:")
        print(coord.kpis)
        #plt.show()
    