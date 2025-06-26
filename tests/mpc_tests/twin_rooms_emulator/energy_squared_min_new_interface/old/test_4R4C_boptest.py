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
rc('mathtext', default='regular')

def prepare_one_step_params(path):
    one_step_params = pd.read_csv(
        path,
        index_col=0
    )
    r_cols = [
        col for col in one_step_params.index \
        if "r" in col and "T" not in col
    ]
    q_cols = [
        col for col in one_step_params.index \
        if "q" in col
    ]
    R = one_step_params.loc[
        r_cols
    ].values.reshape(
        (2,2)
    )
    Q = one_step_params.loc[
        q_cols
    ].values.reshape(
        (4,4)
    )
    x0 = one_step_params.loc[["Ti", "Te", "Tret", "Tsup"]].values.flatten()
    return x0, Q, R

if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_ref_tracking.json")
    traverse_dict(
        cfg
    )
    x0, Q, R = prepare_one_step_params(
        "one_step_params.csv"
    )
    cfg["controller"]["filter_config_file"]["R"] = R
    cfg["controller"]["filter_config_file"]["Q"] = Q
    cfg["controller"]["filter_config_file"]["x0"] = x0
    coord = Coordinator(
        # "coordinator_boptest.json"
        cfg
    )
    #x0 = np.array([
    #    293.15, 293.15, 293.15, 293.15
    #])
    coord.run(x0=x0)
    fig, axes, res = coord.plot_temperatures(heat_key="Prad")
    plt.show()
    print(coord)
    
    results = res[["Ti", "Prad", "Tret", "Tsup", "rad_flo"]][:-1]
    results["Ti_pred"] = np.nan
    results["rad_flo_pred"] = np.nan
    results["Prad_pred"] = np.nan
    results["Tsup_pred"] = np.nan
    results["Tret_pred"] = np.nan
    for k, v in coord.controller.preds.items():
        results.loc[results.index[k+1], "Ti_pred"] = coord.controller.preds[k].loc[1, "Ti"]
        results.loc[results.index[k+1], "Tret_pred"] = coord.controller.preds[k].loc[1, "Tret"]
        results.loc[results.index[k+1], "Tsup_pred"] = coord.controller.preds[k].loc[1, "Tsup"]
        results.loc[results.index[k], "Prad_pred"] = coord.controller.preds[k].loc[0, "Prad"]
        results.loc[results.index[k], "rad_flo_pred"] = coord.controller.preds[k].loc[0, "rad_flo"]
        
    fig, axes = plt.subplots(5,1, sharex=True)
    
    ax = axes[0]    
    results[["Ti", "Ti_pred"]].plot(ax=ax, drawstyle="steps-post")
    #ax1 = ax.twinx()
    #results["Prad"].plot(ax=ax1, drawstyle="steps-post", color="g")
    
    ax = axes[1]
    results[["Tret", "Tret_pred"]].plot(ax=ax, drawstyle="steps-post")
    #ax1 = ax.twinx()
    #results["Prad"].plot(ax=ax1, drawstyle="steps-post", color="g")
    
    ax = axes[2]
    results[["Tsup", "Tsup_pred"]].plot(ax=ax, drawstyle="steps-post")
    #ax1 = ax.twinx()
    #results["Prad"].plot(ax=ax1, drawstyle="steps-post", color="g")
    
    ax = axes[3]
    deltaT_pred = results["Tsup_pred"] - results["Tret_pred"]
    deltaT = results["Tsup"] - results["Tret"]
    deltaT_pred.plot(ax=ax, drawstyle="steps-post")
    deltaT.plot(ax=ax, drawstyle="steps-post")
    
    ax = axes[4]
    results["rad_flo"].plot(ax=ax, drawstyle="steps-post")
    results["rad_flo_pred"].plot(ax=ax, drawstyle="steps-post")
    plt.show()
        
    ax = results[["Prad", "Prad_pred"]].plot(drawstyle="steps-post")
    #ax = results[["Prad"]].plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    #res["rad_219"][:-1].plot(ax=ax1, drawstyle="steps-post", color="g")
    plt.show()

    print(results)