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
#from utils import quick_plot
from copy import deepcopy
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    base = Config()("base_config_scaled.json")
    traverse_dict(
        base
    )
    base["days"] = 31 + 28 + 31 + 30 + 31 + 30
    base["days"] = 30
    #base["days"] = 1
    # start April 1st:
    #base["environment"]["config"]["start_time"] = 0
    base["environment"]["config"]["start_time"] = 31*86400 + 28*86400 + 31*86400 + 30*86400 + 31*86400
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
    #quick_plot(coord)
    
    ax = coord.res[["AHU219_reaTSupAir_y", "Ta"]].plot(drawstyle="steps-post")
    coord.res[["AHU219_reaTinHex_y"]].plot(linestyle="dashed", ax=ax, color="r", drawstyle="steps-post")
    ax.legend(loc="upper left")
    ax1 = ax.twinx()
    #coord.res[["fan_219"]].plot(drawstyle="steps-post", ax=ax1, color="g")
    coord.res[["AHU219_reaUhex_y"]].plot(drawstyle="steps-post", ax=ax1, color="g")
    ax1.legend(loc="upper right")
    plt.show()

    print("tail")