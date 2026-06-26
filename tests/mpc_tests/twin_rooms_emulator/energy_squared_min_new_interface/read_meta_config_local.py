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
from utils import quick_plot, get_value_function_error, plot_parameter_evolution
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    _path = "results_local"
    base = Config()("base_config_scaled_shading.json")
    base["days"] = 31 + 28 + 31 + 30 + 31
    #meta = Config()("config_meta_test.json")
    #meta = Config()("config_meta_only_baseline.json")
    meta = Config()("config_meta_mhe_baseline_shading.json")
    
    read_coords = {}
    values = {}
    for k, v in meta.items():
        cfg = deepcopy(base)
        for _k, _v in v.items():
            if _k != "cost":
                cfg["controller"][_k] = _v
        cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]

        coord = Coordinator.read_result(cfg, _path=_path)
        values[k] = get_value_function_error(coord)
        read_coords[k] = coord
        quick_plot(coord)
        print(k + " kpis:")
        print(coord.kpis)
        #plt.show()

    coord = read_coords["baseline_cost_hist"]
    coord = read_coords["mhe_cost_free_rad_hist"]
    plot_parameter_evolution(coord, "params_result/2R2C_params_jan.csv")
    print("tail")

    # params at k = 12258:
    coord.controller.params_history.loc[12258].to_csv("params_result/before_failure.csv", index=True)

    ax = coord.controller.params_history.alpha_int.plot()
    ax1 = ax.twinx()
    coord.controller.params_history.Ai.plot(ax=ax1, color="k")
    plt.show()

    fig, axes = plt.subplots(2,1, sharex=True)
    for i, (k, v) in enumerate(values.items()):
        ax = axes[i]
        v[["Ti_ol", "Prad_ol"]].resample(
            rule="1D").mean().plot(
                drawstyle="steps-post",
                ax=ax
            )
        ax.set_title(k)
        print(k + ":")
        print(v.sum())

    for ax in axes: 
        ax.set_ylim(0, 80)

    plt.show()

    print("tail")