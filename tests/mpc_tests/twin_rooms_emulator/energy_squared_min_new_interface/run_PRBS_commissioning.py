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
from utils import quick_plot, plot_parameter_evolution
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    _path = "results_local"
    base = Config()("base_config_scaled.json")
    #base["days"] = 31 + 28 + 31 + 30 + 31 
    base["days"] = 14
    #meta = Config()("config_meta_only_mhe_shading.json")
    #meta = Config()("config_meta_test.json")
    meta = Config()("config_meta_only_mhe.json")
    #meta = Config()("config_meta_mhe_baseline_adaptive.json")
    x0 = np.array([
        295.15, 293.15
    ])
    v = meta["mhe_cost_free_rad_hist"]
    cfg = deepcopy(base)
    cfg["control"] = "PRBS"
    for _k, _v in v.items():
        if _k != "cost":
            cfg["controller"][_k] = _v
    cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]
    coord = Coordinator(
        cfg
    )
    # deploy control:
    res = coord.run_PRBS()
    coord.run_baseline_control(reset=False)
    kpis = coord.get_custom_kpis()
    coord.write_result(_path=_path)   
    print("tail")
    plot_parameter_evolution(coord, "params_result/2R2C_params_jan.csv")
    """
    read_coords = {}
    for k, v in cfgs.items():
        coord = Coordinator.read_result(v, _path=_path)
        read_coords[k] = coord
        quick_plot(coord)
        print(k + " kpis:")
        print(coord.kpis)
        plt.show()
    """