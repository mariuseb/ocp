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
from scipy import stats
from utils import quick_plot, get_value_function_error, plot_parameter_evolution, one_step_cost_pred
import matplotlib.dates as mdates
from matplotlib.ticker import MaxNLocator
from pathlib import Path
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    _path = "results_local"
    base = Config()("base_config_scaled.json")
    #base["days"] = 28
    base["days"] = 31 + 28 + 31 + 30 + 31 
    base["days"] = 365
    #base["days"] = 28
    #base["days"] = 2
    stop_day = 182

    starts = {
        "adaptive_cost_free_rad": pd.Timedelta(days=8),
        "baseline": pd.Timedelta(days=8),
        "mhe": pd.Timedelta(days=8)
    }

    stop = pd.Timedelta(days=stop_day)
    start = pd.Timedelta(days=8)
    #meta = Config()("config_meta_test.json")
    meta = Config()("config_meta_only_mhe.json")
    meta = Config()("config_meta_mhe_baseline_adaptive.json")
    #meta = Config()("config_meta_mhe_baseline_shading.json")
    results = {}
    read_coords = {}
    kpis = {}
    values = {}
    onesteps = {}
    for k, v in meta.items():
        cfg = deepcopy(base)
        for _k, _v in v.items():
            if _k != "cost":
                cfg["controller"][_k] = _v
        cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]

        coord = Coordinator.read_result(cfg, _path=_path)
        values[k], _ = get_value_function_error(
            coord, start=start, stop=stop
        )
        onesteps[k], _ = one_step_cost_pred(
            coord, start=start, stop=stop
        )
        read_coords[k] = coord
        #kpis[k] = coord.kpis
        kpis[k] = coord.get_custom_kpis(stop=stop)
        print(k + " kpis:")
        print(kpis[k])
        #plt.show()

    coord_ad = read_coords["adaptive_cost_free_rad"]
    #fig, axes = quick_plot(coord_ad)

    onestep = values["baseline_cost_hist"]
    onestep_ad = values["adaptive_cost_free_rad"]
    onestep_mhe = values["mhe_cost_free_rad_hist"]
    
    """
    value = values["baseline_cost_hist"]
    value_ad = values["adaptive_cost_free_rad"]
    value_mhe = values["mhe_cost_free_rad_hist"]
    """

    fig, axes = plt.subplots(1,3, sharex=True, figsize=(10,4))
    #locator = mdates.AutoDateLocator()
    #formatter = mdates.ConciseDateFormatter(locator)

    names = ["slack_dev_abs_cum", "cost_dev_abs_cum", "tot_dev_abs_cum"]

    #ax = axes[0]

    name_map = {
        "slack": "Comfort",
        "cost": "Economic",
        "tot": "Total"
    }

    colors = {
        #"Fixed"      : "#3A3A3A",   # dark gray
        "Fixed"      : "#4D4D4D",   # dark gray
        "Periodic"   : "#0072B2",   # blue
        #"Continuous" : "#E69F00"   # orange
        "Continuous" : "#E69F00"   # orange
    }

    for i, name in enumerate(names):
        ax = axes[i]

        ax.plot(
            onestep[name].index.tolist(),
            onestep[name].values,
            drawstyle="steps-post",
            linewidth=2.2,
            #color="k",
            color=colors["Fixed"],
        )
        ax.plot(
            onestep_ad[name].index,
            onestep_ad[name].values,
            drawstyle="steps-post",
            linewidth=2.2,
            #color="b",
            color=colors["Periodic"],
        )
        ax.plot(
            onestep_mhe[name].index,
            onestep_mhe[name].values,
            drawstyle="steps-post",
            linewidth=2.2,
            #color="r",
            color=colors["Continuous"],
        )
        if i == 0:
            ax.set_ylabel("Cumulative scaled prediction error ($\\sum |J -  \\hat{J}|$)")
        
        ax.set_title(
            name_map[name.split("_")[0]]
        )
        #ax.legend(["base", "ad", "mhe"])
        #ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
        ax.xaxis.set_major_formatter(mdates.DateFormatter('%b'))
        #ax.xaxis.set_major_locator(mdates.DayLocator(interval=7)) 
        #ax.xaxis.set_major_locator(MaxNLocator(nbins=5))
        ax.xaxis.set_major_locator(mdates.MonthLocator(interval=1))
        #ax.xaxis.set_major_locator(locator)
        #ax.xaxis.set_major_formatter(formatter)
    fig.legend(["Fixed", "Periodic", "Continuous"], ncol=3, loc="lower center")
    fig.autofmt_xdate()
    # Get the absolute path of the running file
    dir_path = Path(__file__).resolve().parent
    fig.savefig(
        dir_path / "cumulative_1step_objective_pred_error.pdf"
    )
    plt.show()
    

    print("tail")