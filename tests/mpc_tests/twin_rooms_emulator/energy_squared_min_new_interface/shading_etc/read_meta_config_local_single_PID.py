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
from utils import quick_plot, plot_parameter_evolution, \
                get_value_function_error, one_step_cost_pred
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    _path = "results_local"
    base = Config()("base_config_scaled.json")
    base["days"] = 30
    #meta = Config()("config_meta_test.json")
    meta = Config()("config_meta_only_mhe.json")
    meta = Config()("config_meta_only_baseline.json")
    

    values = {}

    v = meta["baseline_cost_hist"]
    #v = meta["mhe_cost_free_rad_hist"]
    #v = meta["adaptive_cost_free_rad_hist"]
    cfg = deepcopy(base)
    for _k, _v in v.items():
        if _k != "cost":
            cfg["controller"][_k] = _v
    cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]
    coord = Coordinator.read_result(cfg, _path=_path)
    quick_plot(coord)
    plt.show()
    kpis, lb, ub = coord.get_custom_kpis(return_discomf=True)
    print(kpis)

    cfg["control"] = "PID"
    coord_pid = Coordinator.read_result(cfg, _path=_path)
    kpis_pid, lb, ub = coord_pid.get_custom_kpis(return_discomf=True)
    quick_plot(coord_pid)

    #plot_parameter_evolution(coord, "params_result/2R2C_params_jan.csv")

    one_step_cost = one_step_cost_pred(coord)

    #value = get_value_function_error(coord)

    print("tail")