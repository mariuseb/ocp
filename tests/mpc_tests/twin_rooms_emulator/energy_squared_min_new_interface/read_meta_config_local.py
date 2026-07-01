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
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    _path = "results_local"
    base = Config()("base_config_scaled.json")
    #base["days"] = 28
    base["days"] = 31 + 28 + 31 + 30 + 31 
    base["days"] = 28
    #meta = Config()("config_meta_test.json")
    meta = Config()("config_meta_only_mhe.json")
    meta = Config()("config_meta_mhe_baseline_adaptive.json")
    #meta = Config()("config_meta_mhe_baseline_shading.json")
    results = {}
    read_coords = {}
    kpis = {}
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
        print(k + " kpis:")
        print(coord.kpis)
        kpis[k] = coord.kpis
        #plt.show()

    coord_ad = read_coords["adaptive_cost_free_rad"]
    fig, axes = quick_plot(coord_ad)

    plot_parameter_evolution(coord_ad, "params_result/2R2C_params_jan.csv")

    value_ad = values["adaptive_cost_free_rad"]
    value_mhe = values["mhe_cost_free_rad_hist"]
    value = values["baseline_cost_hist"]
    res_ad = read_coords["adaptive_cost_free_rad"].res
    res_mhe = read_coords["mhe_cost_free_rad_hist"].res
    res = read_coords["baseline_cost_hist"].res

    """
    rule = "15min"
    _value = value.resample(rule=rule).mean()
    _value_mhe = value_mhe.resample(rule=rule).mean()

    fig, axes = plt.subplots(2,1)
    ax = axes[0]
    _value[["Ti_ol", "Prad_ol"]].cumsum().plot(drawstyle="steps-post", ax=ax)
    ax = axes[1]
    _value_mhe[["Ti_ol", "Prad_ol"]].cumsum().plot(drawstyle="steps-post", ax=ax)
    plt.show()
    
    fig, axes = plt.subplots(2,1)
    ax = axes[0]
    _value[["Ti_ol"]].cumsum().plot(drawstyle="steps-post", ax=ax)
    _value_mhe[["Ti_ol"]].cumsum().plot(drawstyle="steps-post", ax=ax)
    #ax = axes[1]
    plt.show()
    """

    coord_mhe = read_coords["mhe_cost_free_rad_hist"]
    onestep_mhe = one_step_cost_pred(coord_mhe)
    coord = read_coords["baseline_cost_hist"]
    onestep = one_step_cost_pred(coord)
    coord = read_coords["adaptive_cost_free_rad"]
    onestep_ad = one_step_cost_pred(coord)

    # table 
    table = pd.DataFrame(
        index=["tdis [Kh]", "energy [kWh]", "peak power [kW]", "cost [EUR]"],
    )
    for k, coord in read_coords.items():
        table.loc[:, k.split("_")[0]] = coord.kpis

    table.loc["total_obj", "baseline"] = onestep.tot_cost.sum()
    table.loc["total_obj", "mhe"] = onestep_mhe.tot_cost.sum()
    table.loc["total_obj", "adaptive"] = onestep_ad.tot_cost.sum()

    table.loc["comp_time", :] = np.nan

    latex_string = table.to_latex(
        index=True,
        float_format="{:.2f}".format,
        caption="Controller comparison",
        label="tab:performance"
    )
    print(latex_string)

    # NOTE: find the days with the most different economic cost:
    onestep_daily = onestep.cost_act.resample(rule="1D").mean()
    onestep_daily_mhe = onestep_mhe.cost_act.resample(rule="1D").mean()
    # delta:
    delta = (onestep_daily - onestep_daily_mhe).abs()
    start_ind = delta.idxmax() - pd.Timedelta(days=1)
    stop_ind = start_ind + pd.Timedelta(days=3)
    _, _ = quick_plot(coord, start=start_ind, stop=stop_ind, title="baseline")
    _, _ = quick_plot(coord_mhe, start=start_ind, stop=stop_ind, title="mhe")

    # NOTE: find the days with the most realized slack:
    slack_rea = onestep_mhe.slack_act.resample(rule="1D").mean()
    cost_rea_mhe = onestep_mhe.cost_act.resample(rule="1D").mean()
    cost_rea = onestep.cost_act.resample(rule="1D").mean()
    second_highest_index = slack_rea.nlargest(3).idxmin()
    start_ind = second_highest_index - pd.Timedelta(days=1)
    stop_ind = start_ind + pd.Timedelta(days=3)
    _, _ = quick_plot(coord, start=start_ind, stop=stop_ind, title="baseline")
    _, _ = quick_plot(coord_mhe, start=start_ind, stop=stop_ind, title="mhe")


    """
    NOTE: To find the deep winter day with the most similar starting temperature:
    """
    Ti_min = np.inf
    _d = 0
    # take 28 first days:
    for d in range(1,28):
        Ti_mhe = coord_mhe.controller.preds[96*d]["Ti"].iloc[0]
        Ti_fixed = coord.controller.preds[96*d]["Ti"].iloc[0]
        Ti_dev = abs(Ti_mhe - Ti_fixed)
        if Ti_dev < Ti_min:
            Ti_min = Ti_dev
            _d = d
    print(_d)

    # correlation 96-step open-loop loss with realized slack:
    ax = value_mhe["Ti_ol"].plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    onestep_mhe["slack_act"].plot(drawstyle="steps-post", ax=ax1, color="k")
    plt.show()
    # stronger: correlation 96-step open-loop loss with rolling, 96-step realized slack
    ax = value_mhe["Ti_ol"].plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    value_mhe["slack_act"].plot(drawstyle="steps-post", ax=ax1, color="k")
    plt.show()

    """
    Temperature / slack / comfort evaluation:
    """

    pearson_r = stats.pearsonr(
        value_mhe.Ti_ol.astype(float).values.flatten(), 
        onestep_mhe.slack_act.astype(float).values.flatten()
    )

    pearson_r = stats.pearsonr(
        value_mhe.Ti_ol.astype(float).values.flatten(), 
        value_mhe.slack_act.astype(float).values.flatten()
    )

    # 1-step dev.:
    onestep_dev_mhe = (res_mhe.Ti_model.bfill() - res_mhe.Ti).abs()[:-96]
    ax = onestep_dev_mhe.plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    onestep_mhe["slack_act"].plot(drawstyle="steps-post", ax=ax1, color="k")
    plt.show()

    _pearson_r = stats.pearsonr(
        onestep_dev_mhe.astype(float).values.flatten(), 
        onestep_mhe.slack_act.astype(float).values.flatten()
    )

    ax = onestep_mhe.slack_pred.plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    onestep_mhe["slack_act"].plot(drawstyle="steps-post", ax=ax1, color="k")
    plt.show()

    __pearson_r = stats.pearsonr(
        onestep_mhe.slack_pred.astype(float).values.flatten(), 
        onestep_mhe.slack_act.astype(float).values.flatten()
    )

    """
    Power / economic cost evaluation.
    """

    eco_cost_dev = (onestep_mhe["cost_act"] - onestep_mhe["cost_pred"]).abs()
    Prad_dev = ((res["Prad"] - res["Prad_model"]).abs()/2500)[:-96]

    # 96-step:
    ax = value_mhe["Prad_ol"].plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    eco_cost_dev.plot(drawstyle="steps-post", ax=ax1, color="k", linestyle="dashed")
    plt.show()

    pearson_r = stats.pearsonr(
        value_mhe.Prad_ol.astype(float).values.flatten(), 
        #eco_cost_dev.astype(float).values.flatten()
        onestep_mhe["cost_act"].astype(float).values.flatten()
    )

    # 0-step:
    ax = Prad_dev.plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    eco_cost_dev.plot(drawstyle="steps-post", ax=ax1, color="k", linestyle="dashed")
    plt.show()
    
    _pearson_r = stats.pearsonr(
        Prad_dev.astype(float).values.flatten(), 
        #eco_cost_dev.astype(float).values.flatten()
        onestep_mhe["cost_act"].astype(float).values.flatten()
    )

    """
    ax = Prad_dev.plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    eco_cost_dev.plot(drawstyle="steps-post", ax=ax1, color="k", linestyle="dashed")
    plt.show()
    
    __pearson_r = stats.pearsonr(
        onestep_mhe["cost_pred"].astype(float).values.flatten(),
        onestep_mhe["cost_act"].astype(float).values.flatten()
    )
    """


    """
    Total cost:

    How well does the MPC work as a N-step predictor of optimality?

    TODO: calculate N-step rolling cost, both pred and act
    insert in get_value_function_error, that already iterates
    through predictions.
    """
    ax = onestep_mhe.cost_pred.plot(drawstyle="steps-post")
    onestep_mhe["cost_act"].plot(drawstyle="steps-post", ax=ax, color="k")
    ax.legend(["cost_pred", "cost_act"])
    plt.show()

    print("tail")