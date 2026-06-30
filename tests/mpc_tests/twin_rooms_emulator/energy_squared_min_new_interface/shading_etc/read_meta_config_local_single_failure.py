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
    base = Config()("base_config_scaled_shading_failure.json")
    base["days"] = 7 
    meta = Config()("config_meta_only_mhe_shading_failure.json")

    values = {}

    #v = meta["baseline_cost_hist"]
    v = meta["mhe_cost_free_rad_hist"]
    #v = meta["adaptive_cost_free_rad_hist"]
    cfg = deepcopy(base)
    for _k, _v in v.items():
        if _k != "cost":
            cfg["controller"][_k] = _v
    cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]
    coord = Coordinator.read_result(cfg, _path=_path)
    plot_parameter_evolution(coord, "params_result/2R2C_params_jan.csv")
    quick_plot(coord)
    plt.show()
    kpis, lb, ub = coord.get_custom_kpis(return_discomf=True)
    print(kpis)

    ax = coord.res[["AHU219_reaTSupAir_y", "Tsup_set_219"]].plot(drawstyle="steps-post", color=["r", "b"])
    coord.res[["Ta"]].plot(drawstyle="steps-post", ax=ax, linestyle="dashed")
    plt.show()

    #value = get_value_function_error(coord)

    print("tail")