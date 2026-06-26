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
from copy import deepcopy
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    base = Config()("base_config_scaled.json")
    traverse_dict(
        base
    )
    base["days"] = 30
    meta = Config()("config_meta_only_baseline.json")

    for k, v in meta.items():
        cfg = deepcopy(base)
        for _k, _v in v.items():
            if _k != "cost":
                cfg["controller"][_k] = _v
        cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]


    # make cfg differ from MPC run:
    cfg["control"] = "PID"
    coord = Coordinator(
        # "coordinator_boptest.json"
        cfg
    )
    x0 = np.array([
        293.15, 293.15
    ])
    coord.run_baseline_control()
    coord.write_result(_path="results_local")
    quick_plot(coord)
    
    print("tail")