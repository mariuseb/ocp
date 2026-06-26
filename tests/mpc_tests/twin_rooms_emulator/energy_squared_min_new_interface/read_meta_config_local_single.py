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
    base = Config()("base_config_scaled_shading.json")
    base["days"] = 30
    #meta = Config()("config_meta_test.json")
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

    meta = Config()("config_meta_only_mhe.json")

    v = meta["mhe_cost_free_rad_hist"]
    cfg = deepcopy(base)
    for _k, _v in v.items():
        if _k != "cost":
            cfg["controller"][_k] = _v
    cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]
    coord_mhe = Coordinator.read_result(cfg, _path=_path)
    quick_plot(coord_mhe)
    plt.show()
    kpis_mhe, lb, ub = coord_mhe.get_custom_kpis(return_discomf=True)
    print(kpis_mhe)

    value = get_value_function_error(coord)
    value_mhe = get_value_function_error(coord_mhe)

    fig, axes = plt.subplots(2,1)
    ax = axes[0]
    value[["Ti_ol", "Prad_ol"]].plot(drawstyle="steps-post", ax=ax)
    ax = axes[1]
    value_mhe[["Ti_ol", "Prad_ol"]].plot(drawstyle="steps-post", ax=ax)
    plt.show()


    #plot_parameter_evolution(coord, "params_result/2R2C_params_jan.csv")
    one_step_cost = one_step_cost_pred(coord)

    #value = get_value_function_error(coord)

    print("tail")