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


"""
def quick_plot(coord, start=None, stop=None):
    res = coord.res
    #res = coord.env._res
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
    res.Tsup_set_219.plot(ax=ax, drawstyle="steps-post", color="y")
    res.AHU219_reaTSupAir_y.plot(ax=ax, drawstyle="steps-post", color="r", linestyle="dashed")
    ax1 = ax.twinx()
    res.cost.plot(ax=ax1, drawstyle="steps-post", color="b", linestyle="dashed")
    ax = axes[1]
    #ax1 = ax.twinx()
    #res.Prad.plot(ax=ax, drawstyle="steps-post", color="r")
    res.Prad_calc.plot(ax=ax, drawstyle="steps-post", color="r")
    #res.Pvent.plot(ax=ax, drawstyle="steps-post", color="r", linestyle="dashed")
    (-res.Pcoo).shift(-1).plot(ax=ax, drawstyle="steps-post", color="b")
    try: 
        res["Prad_model"] = np.nan
        res["Ti_model"] = np.nan
        for i, df in coord.controller.preds.items():
            #res["Prad_model"][i] = df["Prad"][0]
            #res["Ti_model"][i+1] = df["Ti"][1]
            res.loc[res.index[i], "Prad_model"] = df.loc[0, "Prad"]
            res.loc[res.index[i+1], "Ti_model"] = df.loc[1, "Ti"]
        res.Prad_model.plot(ax=ax, drawstyle="steps-post", color="g")
        ax1 = ax.twinx()
        res.rad_219.shift(-1).plot(ax=ax1, drawstyle="steps-post", color="k")
        #res.sha_219.shift(-1).plot(ax=ax1, drawstyle="steps-post", color="k", linestyle="dashed")
        ax = axes[0]
        res.Ti_model.plot(ax=ax, drawstyle="steps-post", color="g")
    #res.rad_219.plot(ax=ax1, drawstyle="steps-post", color="k")
    except KeyError:
        print("Baseline run..")
    plt.show(block=False)
    return res
"""

def get_cumulative_devs(df):
    df["tot_cost"] = df["slack_act"] + \
    df["cost_act"]
    #df["tot_pred"] = np.nan
    df["tot_pred"] = df["slack_pred"] + \
        df["cost_pred"]
    # cumulative:
    df["cost_pred_cum"] = df["cost_pred"].cumsum()
    df["cost_act_cum"] = df["cost_act"].cumsum()
    df["cost_delta_cum"] = \
        df["cost_act_cum"] - \
            df["cost_pred_cum"]

    df["cost_dev"] = df["cost_act"] - df["cost_pred"]
    df["cost_dev_abs"] = df["cost_dev"].abs()
    df["cost_dev_abs_cum"] = df["cost_dev_abs"].cumsum()

    df["slack_pred_cum"] = df["slack_pred"].cumsum()
    df["slack_act_cum"] = df["slack_act"].cumsum()
    df["slack_delta_cum"] = \
        df["slack_act_cum"] - \
            df["slack_pred_cum"]
    
    df["slack_dev"] = df["slack_act"] - df["slack_pred"]
    df["slack_dev_abs"] = df["slack_dev"].abs()
    df["slack_dev_abs_cum"] = df["slack_dev_abs"].cumsum()
    
    df["tot_pred_cum"] = df["tot_pred"].cumsum()
    df["tot_cost_cum"] = df["tot_cost"].cumsum()
    df["tot_delta_cum"] = \
        df["tot_cost_cum"] - \
            df["tot_pred_cum"]

    df["tot_dev"] = df["tot_cost"] - df["tot_pred"]
    df["tot_dev_abs"] = df["tot_dev"].abs()
    df["tot_dev_abs_cum"] = df["tot_dev_abs"].cumsum()
    return df

def quick_plot(coord, start=None, stop=None, title=""):
    
    if not hasattr(coord.res, "Prad_calc"):
        res = coord.modify_res_obj(coord.res)
    else:
        res = coord.res
    if start is None:
        start = res.index[0]
    if stop is None:
        stop = res.index[-1]
    res = res.loc[start:stop]

    fig, axes = plt.subplots(2,1, sharex=True)
    fig.suptitle(title)
    ax = axes[0]
    res.Ti.plot(ax=ax, drawstyle="steps-post", color="m")
    res.Ti_lb.plot(ax=ax, drawstyle="steps-post", color="k")
    res.Ti_ub.plot(ax=ax, drawstyle="steps-post", color="k")
    res.Tsup_set_219.plot(ax=ax, drawstyle="steps-post", color="y")
    res.AHU219_reaTSupAir_y.plot(ax=ax, drawstyle="steps-post", color="r", linestyle="dashed")
    ax1 = ax.twinx()
    res.cost.plot(ax=ax1, drawstyle="steps-post", color="b", linestyle="dashed")
    ax = axes[1]
    #ax1 = ax.twinx()
    #res.Prad.plot(ax=ax, drawstyle="steps-post", color="r")
    res.Prad_calc.plot(ax=ax, drawstyle="steps-post", color="r")
    #res.Pvent.plot(ax=ax, drawstyle="steps-post", color="r", linestyle="dashed")
    (-res.Pcoo).shift(-1).plot(ax=ax, drawstyle="steps-post", color="b")
    res.Prad_model.plot(ax=ax, drawstyle="steps-post", color="g")
    ax1 = ax.twinx()
    res.rad_219.shift(-1).plot(ax=ax1, drawstyle="steps-post", color="k")
    #res.sha_219.shift(-1).plot(ax=ax1, drawstyle="steps-post", color="k", linestyle="dashed")
    ax = axes[0]
    res.Ti_model.plot(ax=ax, drawstyle="steps-post", color="g")
    #res.rad_219.plot(ax=ax1, drawstyle="steps-post", color="k")
    plt.show(block=False)
    return fig, axes
    
def get_value_function_error(coord, N=None, slack_weight=1E2, start=None, stop=None):
    preds = coord.controller.preds
    if N is None:
        N = coord.controller.N
    else:
        assert N < coord.controller.N
    res = coord.res.copy()
    
    if stop is not None:
        res = res.loc[:stop]

    res["Prad"] = res["Prad"].shift(-1)
    res["Pcoo"] = -res["Pcoo"].shift(-1)
    s_real = get_slack_viol(
        coord, 
        res,
        slack_weight=slack_weight
    )
    value = pd.DataFrame(columns=[
        "Ti_ol", "Prad_ol", "cost_pred", "cost_act", "slack_pred", "slack_act"
    ])
    #res = res[:-N]
    # all metrics scaled:
    for i, ndx in enumerate(res[:-N].index):
        stop_ndx = res.index[i+N-1]
        # temperature RMSE, compounded rollout (i.e., open-loop error):
        value.loc[ndx, "Ti_ol"] = mean_squared_error(
            (res["Ti"].loc[ndx:stop_ndx].values - 289.15)/12, 
            (preds[i].loc[:N-1, "Ti"].values - 289.15)/12, 
        )*slack_weight
        # power RMSE, compounded rollout (i.e., open-loop error):
        value.loc[ndx, "Prad_ol"] = mean_squared_error(
            res["Prad"].loc[ndx:stop_ndx].values/2.5E3, 
            preds[i].loc[:N-1, "Prad"].values/2.5E3, 
        )
        # cost predicted:
        value.loc[ndx, "cost_pred"] = (
            (
                (preds[i].loc[:N-1, "Prad"].values/2.5E3) + \
                (preds[i].loc[:N-1, "coo_219"].values/2.5E3)
            )*res.loc[ndx:stop_ndx, "cost"].values
        ).sum()
        # cost actual:
        value.loc[ndx, "cost_act"] = (
            (
                (res.loc[ndx:stop_ndx, "Prad"].values/2.5E3) + \
                (res.loc[ndx:stop_ndx, "Pcoo"].values/2.5E3)
            )*res.loc[ndx:stop_ndx, "cost"].values
        ).sum()
        # slack predicted:
        value.loc[ndx, "slack_pred"] = \
             slack_weight*preds[i]["s1"].iloc[1]**2
        # slack realized:
        value.loc[ndx, "slack_act"] = s_real.loc[ndx:stop_ndx].sum()
    value["Prad_act"] = res["Prad"][:-N]/2.5E3

    if start is not None:
        value_before_acc = value.copy()
        value = value.loc[start:]

    value = get_cumulative_devs(
        value
    )
    #onestep = onestep.fillna(0)
    #onestep.index = onestep.index.to_pydatetime()
    value.index = pd.to_datetime("2024-01-01") + value.index
    value_before_acc.index = pd.to_datetime("2024-01-01") + value_before_acc.index
    #return onestep[:-1].astype(float)
    return value.astype(float), value_before_acc.astype(float)


def get_slack_viol(coord, res, slack_weight=1E2):
    lb_vio, ub_vio = coord.get_constraint_violations(res)
    lb_vio = lb_vio.reindex(res.index).fillna(0)
    ub_vio = ub_vio.reindex(res.index).fillna(0)
    # scale. hardcode for now
    # TODO: modular scale
    slack_viol = slack_weight*((lb_vio + ub_vio)/12)**2
    #lb_vio = slack_weight*(lb_vio/12)**2
    return slack_viol

def one_step_cost_pred(coord, N=None, slack_weight=1E2, start=None, stop=None):
    preds = coord.controller.preds
    if N is None:
        N = coord.controller.N
    else:
        assert N < coord.controller.N
    
    res = coord.res.copy()

    if stop is not None:
        res = res.loc[:stop]

    res["Prad"] = res["Prad"].shift(-1)
    res["Pcoo"] = -res["Pcoo"].shift(-1)
    onestep = pd.DataFrame(columns=[
        "slack_pred", "slack_act", "cost_pred", "cost_act"
    ])
    slack_viol = get_slack_viol(
        coord, res, slack_weight=slack_weight
    )
    #lb_vio = slack_weight*(lb_vio/12)**2
    #ub_vio = slack_weight*(ub_vio/12)**2
    #res = res[:-N]
    if preds != {}:
        iter_res = res[:-N]
    else:
        iter_res = res

    for i, ndx in enumerate(iter_res.index):
    #for i, ndx in enumerate(res[:-N].index):
        """
        stop_ndx = res.index[i+N-1]
        onestep.loc[ndx, "Ti_ol"] = mean_squared_error(
            (res["Ti"].loc[ndx:stop_ndx].values - 289.15)/12, 
            (preds[i].loc[:N-1, "Ti"].values - 289.15)/12, 
        )*1E3
        onestep.loc[ndx, "Prad_ol"] = mean_squared_error(
            res["Prad"].loc[ndx:stop_ndx].values/1E3, 
            preds[i].loc[:N-1, "Prad"].values/1E3, 
        )
        """
        try:
            pred = preds[i]
            next_ndx = res.index[i+1]
            # Calculate 0-step predicted energy cost:
            onestep.loc[ndx, "cost_pred"] = (
                pred["Prad"].iloc[0]/2500 + pred["coo_219"].iloc[0]/2500
            )*res["cost"].iloc[0]
            # Calculate 1-step predicted slack term:
            onestep.loc[next_ndx, "slack_pred"] = \
                slack_weight*pred["s1"].iloc[1]**2
        except KeyError:
            onestep.loc[ndx, "cost_pred"] = np.nan
            onestep.loc[ndx, "slack_pred"] = np.nan
        # Calculate 0-step actual energy cost:
        onestep.loc[ndx, "cost_act"] = (
            res.loc[ndx, "Prad"]/2500 + res.loc[ndx, "Pcoo"]/2500
        )*res["cost"].iloc[0]
        #if pred["Prad"].iloc[0] > 100:
        #    print(pred)
    #onestep["Prad_act"] = res["Prad"][:-N]/2500
    onestep["slack_act"] = slack_viol

    if start is not None:
        onestep_before_acc = onestep.copy()
        onestep = onestep.loc[start:]

    onestep = get_cumulative_devs(
        onestep
    )
    #onestep = onestep.fillna(0)
    #onestep.index = onestep.index.to_pydatetime()
    onestep.index = pd.to_datetime("2024-01-01") + onestep.index
    onestep_before_acc.index = pd.to_datetime("2024-01-01") + onestep_before_acc.index
    #return onestep[:-1].astype(float)
    return onestep.astype(float), onestep_before_acc.astype(float)

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
    
    fig, axes = plt.subplots(9,1, sharex=True, figsize=(10,12))
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