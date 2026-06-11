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
    base["days"] = 2
    meta = Config()("config_meta_local.json")
    x0 = np.array([
        295.15, 293.15
    ])
    cfgs = {}
    for i, (k, v) in enumerate(meta.items()):
        print("###################################")
        print(
            "Running %s, %s out of %s" %
            (k, str(i+1), str(len(meta)))
        )
        print("###################################")
        cfg = deepcopy(base)
        # fill missing:
        for _k, _v in v.items():
            if _k != "cost":
                cfg["controller"][_k] = _v
        cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]
        cfgs[k] = cfg
        coord = Coordinator(
            cfg
        )
        # deploy control:
        coord.run(x0=x0)
        coord.write_result(_path=_path)   
        #pprint(cfg)
    
    read_coords = {}
    for k, v in cfgs.items():
        coord = Coordinator.read_result(v, _path=_path)
        read_coords[k] = coord
        quick_plot(coord)
        print(k + " kpis:")
        print(coord.kpis)
        plt.show()
    