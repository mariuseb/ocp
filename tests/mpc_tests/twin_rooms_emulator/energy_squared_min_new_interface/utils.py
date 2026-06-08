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
from sklearn.metrics import mean_squared_error
import pandas as pd
from ocp.config import Config, traverse_dict
rc('mathtext', default='regular')


def quick_plot(coord):
    res = coord.res
    res.index = res.dt_index
    # causality shift:
    res["Prad_calc"] = (res.Qrad.diff(1)/1000).shift(-1)
    # what are the preds of Prad?
    #for i, df in coord.controller.preds.items():
    #    res["Prad_model"][i] = df["Prad"][0]
    
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    res.Ti.plot(ax=ax, drawstyle="steps-post", color="m")
    res.Ti_lb.plot(ax=ax, drawstyle="steps-post", color="k")
    res.Ti_ub.plot(ax=ax, drawstyle="steps-post", color="k")
    ax1 = ax.twinx()
    res.cost.plot(ax=ax1, drawstyle="steps-post", color="b", linestyle="dashed")
    ax = axes[1]
    #ax1 = ax.twinx()
    #res.Prad.plot(ax=ax, drawstyle="steps-post", color="r")
    res.Prad_calc.plot(ax=ax, drawstyle="steps-post", color="r")
    try: 
        res["Prad_model"] = np.nan
        res["Ti_model"] = np.nan
        for i, df in coord.controller.preds.items():
            #res["Prad_model"][i] = df["Prad"][0]
            #res["Ti_model"][i+1] = df["Ti"][1]
            res.loc[res.index[i], "Prad_model"] = df.loc[0, "Prad"]
            res.loc[res.index[i+1], "Ti_model"] = df.loc[1, "Ti"]
        res.Prad_model.plot(ax=ax, drawstyle="steps-post", color="g")
        ax = axes[0]
        res.Ti_model.plot(ax=ax, drawstyle="steps-post", color="g")
    #res.rad_219.plot(ax=ax1, drawstyle="steps-post", color="k")
    except KeyError:
        print("Baseline run..")
    plt.show(block=False)
    
def get_value_function_error(coord, N=None):
    preds = coord.controller.preds
    if N is None:
        N = coord.controller.N
    else:
        assert N < coord.controller.N
    res = coord.res
    value = pd.DataFrame(columns=["Ti_ol", "Prad_ol"])
    #res = res[:-N]
    for i, ndx in enumerate(res[:-N].index):
        stop_ndx = res.index[i+N-1]
        value.loc[ndx, "Ti_ol"] = mean_squared_error(
            (res["Ti"].loc[ndx:stop_ndx].values - 289.15)/12, 
            (preds[i].loc[:N-1, "Ti"].values - 289.15)/12, 
        )*1E3
        value.loc[ndx, "Prad_ol"] = mean_squared_error(
            res["Prad"].loc[ndx:stop_ndx].values/1E3, 
            preds[i].loc[:N-1, "Prad"].values/1E3, 
        )
    value["Prad_act"] = res["Prad"][:-N]/1E3
    return value

def plot_parameter_evolution(coord, PRBS_ref):
    params_PRBS = pd.read_csv(
        PRBS_ref,
        index_col=0
    )
    p = coord.controller.p
    _params_PRBS = pd.Series(
        index=p,
        data=params_PRBS.values.flatten(),
    )
    hist = coord.controller.params_history
    params_PRBS = pd.DataFrame(_params_PRBS).T
    params_PRBS.index = [hist.index[0]]
    for ndx in hist.index:
        params_PRBS.loc[ndx, :] = params_PRBS.iloc[0, :].values
    
    fig, axes = plt.subplots(8,1, sharex=True, figsize=(10,12))
    for i, name in enumerate(p):
        hist[name].plot(
            ax=axes[i], 
            color="k", 
            linestyle="dashed",
            drawstyle="steps-post"
        )
        params_PRBS[name].plot(
            ax=axes[i], 
            color="k", 
            drawstyle="steps-post"
        )
        axes[i].set_title(name)
    plt.show()