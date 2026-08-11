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

""
def quick_plot(
    coord, 
    start=None, 
    stop=None, 
    sampling="15min",
    axes=None
):
    res = coord.res
    #res = coord.env._res
    res.index = res.dt_index
    # causality shift:
    #res["Prad_calc"] = (res.Qrad.diff(1)/1000).shift(-1)
    # what are the preds of Prad?
    #for i, df in coord.controller.preds.items():
    #    res["Prad_model"][i] = df["Prad"][0]
    
    if not hasattr(coord.res, "Prad_calc"):
        res = coord.modify_res_obj(coord.res)
    else:
        res = coord.res
    if start is None:
        start = res.index[0]
    if stop is None:
        stop = res.index[-1]
    res = res.loc[start:stop]

    if axes is None:
        fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    res.Ti.resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="m")
    res.Ti_lb.resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="k")
    res.Ti_ub.resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="k")
    res.Tsup_set_219.resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="y")
    res.AHU219_reaTSupAir_y.resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="r", linestyle="dashed")
    ax1 = ax.twinx()
    res.cost.resample(rule=sampling).mean().plot(ax=ax1, drawstyle="steps-post", color="b", linestyle="dashed")
    ax = axes[1]
    #ax1 = ax.twinx()
    #res.Prad.plot(ax=ax, drawstyle="steps-post", color="r")
    res.Prad_calc.resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="r")
    #res.Pvent.plot(ax=ax, drawstyle="steps-post", color="r", linestyle="dashed")
    (-res.Pcoo).shift(-1).resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="b")
    """
    try: 
        res["Prad_model"] = np.nan
        res["Ti_model"] = np.nan
        for i, df in coord.controller.preds.items():
            #res["Prad_model"][i] = df["Prad"][0]
            #res["Ti_model"][i+1] = df["Ti"][1]
            res.loc[res.index[i], "Prad_model"] = df.loc[0, "Prad"]
            res.loc[res.index[i+1], "Ti_model"] = df.loc[1, "Ti"]
    """
    res.Prad_model.resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="g")
    ax1 = ax.twinx()
    res.rad_219.shift(-1).resample(rule=sampling).mean().plot(ax=ax1, drawstyle="steps-post", color="k")
    #res.sha_219.shift(-1).plot(ax=ax1, drawstyle="steps-post", color="k", linestyle="dashed")
    ax = axes[0]
    res.Ti_model.resample(rule=sampling).mean().plot(ax=ax, drawstyle="steps-post", color="g")
    #res.rad_219.plot(ax=ax1, drawstyle="steps-post", color="k")
    #except KeyError:
    #    print("Baseline run..")
    #plt.show(block=False)
    #return fig, axes


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

    df["tot_dev_total"] = df["tot_cost"] - df["tot_pred"]
    df["tot_dev"] = df["cost_dev_abs"] + df["slack_dev_abs"]
    #df["tot_dev_abs"] = df["tot_dev_alt"].abs()
    df["tot_dev_total_abs"] = df["tot_dev_total"].abs()
    df["tot_dev_abs_cum"] = df["tot_dev"].cumsum()
    return df

"""
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
"""


def get_value_function_error_all_N(
    coord,
    slack_weight=1e2,
    start=None,
    stop=None,
):
    preds = coord.controller.preds
    N_max = coord.controller.N
    res = coord.res.copy()

    if stop is not None:
        res = res.loc[:stop]

    res["Prad"] = res["Prad"].shift(-1)
    res["Pcoo"] = -res["Pcoo"].shift(-1)

    s_real = get_slack_viol(
        coord,
        res,
        slack_weight=slack_weight,
    ).to_numpy()

    ti_real = res["Ti"].to_numpy()
    ti_lb = res["Ti_lb"].to_numpy()
    ti_ub = res["Ti_ub"].to_numpy()
    prad_real = res["Prad"].to_numpy() / 2.5e3
    pcoo_real = res["Pcoo"].to_numpy() / 2.5e3
    price = res["cost"].to_numpy()

    n_times = min(len(preds), len(res) - N_max)
    horizons = np.arange(1, N_max)

    cost_dev = np.empty((n_times, N_max - 1))
    cost_preds = np.empty((n_times, N_max - 1))
    cost_acts = np.empty((n_times, N_max - 1))
    slack_preds = np.empty((n_times, N_max - 1))
    slack_dev = np.empty((n_times, N_max - 1))
    total_dev = np.empty((n_times, N_max - 1))

    """
    cost_dev = np.empty((n_times, N_max))
    cost_preds = np.empty((n_times, N_max))
    slack_preds = np.empty((n_times, N_max))
    slack_dev = np.empty((n_times, N_max))
    total_dev = np.empty((n_times, N_max))
    """

    # Step-specific squared prediction errors.
    temperature_error = np.empty((n_times, N_max - 1))
    temperature_error_near_bound = np.empty((n_times, N_max - 1))
    power_error = np.empty((n_times, N_max - 1))
    wrong_side_error = np.empty((n_times, N_max - 1))
    temperature_error_l1 = np.empty((n_times, N_max - 1))
    power_error_l1 = np.empty((n_times, N_max - 1))
    temperature_error_near_bound = np.full(
        (n_times, N_max - 1),
        np.nan
    )
    temperature_error_near_bound_l1 = np.full(
        (n_times, N_max - 1),
        np.nan
    )

    slack_error_missed_all = np.zeros(
        (n_times, N_max - 1)
    )

    slack_error_false_all = np.zeros(
        (n_times, N_max - 1)
    )
    slack_error_both_all = np.zeros(
        (n_times, N_max - 1)
    )
    missed_count = np.zeros(
        (n_times, N_max - 1)
    )
    false_count = np.zeros(
        (n_times, N_max - 1)
    )
    both_count = np.zeros(
        (n_times, N_max - 1)
    )
    slack_obj_error_missed_all = np.zeros(
        (n_times, N_max - 1)
    )
    slack_obj_error_false_all = np.zeros(
        (n_times, N_max - 1)
    )
    slack_obj_error_both_all = np.zeros(
        (n_times, N_max - 1)
    )
    #temperature_error = np.empty((n_times, N_max))
    #power_error = np.empty((n_times, N_max))

    for i in range(n_times-1):
        pred = preds[i]

        # Power applies over stages 0, ..., N_max - 2.
        power_slice = slice(i, i + N_max - 1)

        prad_pred_stage = (
            pred["Prad"].to_numpy()[:N_max - 1] / 2.5e3
        )
        pcoo_pred_stage = (
            pred["coo_219"].to_numpy()[:N_max - 1] / 2.5e3
        )

        total_power_pred_stage = (
            prad_pred_stage + pcoo_pred_stage
        )
        total_power_act_stage = (
            prad_real[power_slice] + pcoo_real[power_slice]
        )

        # Stagewise predicted and realized economic objective.
        cost_pred_stage = (
            total_power_pred_stage * price[power_slice]
        )
        cost_act_stage = (
            total_power_act_stage * price[power_slice]
        )

        # Temperature/slack applies at states 1, ..., N_max - 1.
        state_slice = slice(i + 1, i + N_max)

        slack_pred_stage = (
            slack_weight
            * pred["s1"].to_numpy()[1:N_max] ** 2
        )
        slack_act_stage = s_real[state_slice]

        # Objective values for every horizon N = 1, ..., N_max - 1.
        cost_pred = np.cumsum(cost_pred_stage)
        cost_act = np.cumsum(cost_act_stage)

        slack_pred = np.cumsum(slack_pred_stage)
        slack_act = np.cumsum(slack_act_stage)

        if i == 30:
            print(i)

        cost_dev[i] = np.abs(cost_act - cost_pred)
        cost_preds[i] = cost_pred
        cost_acts[i] = cost_act
        slack_preds[i+1] = slack_pred
        slack_dev[i+1] = np.abs(slack_act - slack_pred)
        """
        total_dev[i] = np.abs(
            (cost_pred + slack_pred)
            - (cost_act + slack_act)
        )
        """
        total_dev[i] = (
            #np.abs(cost_act - cost_pred) + \
            #    np.abs(slack_act - slack_pred)
            cost_dev[i] + slack_dev[i]
        )

        # Pure, step-specific temperature prediction error.
        ti_pred_stage = pred["Ti"].to_numpy()[1:N_max]
        temperature_error[i] = np.cumsum(
            ((ti_pred_stage - ti_real[state_slice])/12) ** 2
        )
        temperature_error_l1[i] = np.abs(
            ti_pred_stage - ti_real[state_slice]
        )

        # near-bound evaluation:
        T_act = ti_real[state_slice]
        Tmin = ti_lb[state_slice]
        Tmax = ti_ub[state_slice]
        T_pred = ti_pred_stage
        eps = 0.1
        near_bound = (
            (np.abs(T_act - Tmin) <= eps)
            | (np.abs(T_act - Tmax) <= eps)
            | (np.abs(T_pred - Tmin) <= eps)
            | (np.abs(T_pred - Tmax) <= eps)
        )
        near_bound_sq_error = np.full(N_max - 1, np.nan)
        near_bound_abs_error = np.full(N_max - 1, np.nan)

        near_bound_sq_error[near_bound] = (
            T_pred[near_bound] - T_act[near_bound]
        ) ** 2

        near_bound_abs_error[near_bound] = np.abs(
            T_pred[near_bound] - T_act[near_bound]
        )

        temperature_error_near_bound[i] = near_bound_sq_error
        temperature_error_near_bound_l1[i] = near_bound_abs_error
        # Pure, step-specific total-power prediction error.
        power_error[i] = np.cumsum(
            (total_power_pred_stage - total_power_act_stage) ** 2
        )
        power_error_l1[i] = np.abs(
            total_power_pred_stage - total_power_act_stage
        )

        # predicted comfort status:
        # Comfort-status masks
        act_below = T_act < Tmin
        pred_below = T_pred < Tmin

        act_above = T_act > Tmax
        pred_above = T_pred > Tmax

        act_viol = act_below | act_above
        pred_viol = pred_below | pred_above

        # 1) Actual violation, prediction says no violation
        missed_violation = act_viol & ~pred_viol

        # 2) Prediction says violation, actual is within bounds
        false_violation = ~act_viol & pred_viol

        # 3) Both predict/realize a violation
        both_violate = act_viol & pred_viol

        slack_act_mag = (
            np.maximum(Tmin - T_act, 0)
            + np.maximum(T_act - Tmax, 0)
        )
        slack_pred_mag = (
            np.maximum(Tmin - T_pred, 0)
            + np.maximum(T_pred - Tmax, 0)
        )
        slack_error = np.abs(
            slack_act_mag - slack_pred_mag
        )

        slack_error_missed = np.zeros(N_max - 1)
        slack_error_false = np.zeros(N_max - 1)
        slack_error_both = np.zeros(N_max - 1)

        slack_error_missed[missed_violation] = (
            slack_error[missed_violation]
        )

        slack_error_false[false_violation] = (
            slack_error[false_violation]
        )

        slack_error_both[both_violate] = (
            slack_error[both_violate]
        )
        slack_error_missed_all[i] = slack_error_missed
        slack_error_false_all[i] = slack_error_false
        slack_error_both_all[i] = slack_error_both

        missed_count[i] = missed_violation.astype(float)
        false_count[i] = false_violation.astype(float)
        both_count[i] = both_violate.astype(float)

        slack_obj_act = slack_weight * slack_act_mag**2
        slack_obj_pred = slack_weight * slack_pred_mag**2

        slack_obj_error = np.abs(
            slack_obj_act - slack_obj_pred
        )
        slack_obj_error_missed = np.zeros(N_max - 1)
        slack_obj_error_false = np.zeros(N_max - 1)
        slack_obj_error_both = np.zeros(N_max - 1)

        slack_obj_error_missed[missed_violation] = \
            slack_obj_error[missed_violation]

        slack_obj_error_false[false_violation] = \
            slack_obj_error[false_violation]

        slack_obj_error_both[both_violate] = \
            slack_obj_error[both_violate]
        
        slack_obj_error_missed_all[i] = slack_obj_error_missed
        slack_obj_error_false_all[i] = slack_obj_error_false
        slack_obj_error_both_all[i] = slack_obj_error_both

    power_index = res.index[:n_times] + pd.to_datetime("2024-01-01")
    #state_index = res.index[1:n_times+1] + pd.to_datetime("2024-01-01")
    columns = pd.Index(horizons, name="N")

    temperature_near_bound_mse = np.nanmean(
        temperature_error_near_bound,
        axis=0
    )

    temperature_near_bound_rmse = np.sqrt(
        temperature_near_bound_mse
    )

    temperature_near_bound_mae = np.nanmean(
        temperature_error_near_bound_l1,
        axis=0
    )

    near_bound_count = ~np.isnan(temperature_error_near_bound)
    near_bound_count = near_bound_count.astype(int)

    result = {
        "cost": pd.DataFrame(
            cost_dev, index=power_index, columns=columns
        ),
        "cost_pred": pd.DataFrame(
            cost_preds, index=power_index, columns=columns
        ),
        "cost_act": pd.DataFrame(
            cost_acts, index=power_index, columns=columns
        ),
        "slack": pd.DataFrame(
            slack_dev, index=power_index, columns=columns
        ),
        "slack_pred": pd.DataFrame(
            slack_preds, index=power_index, columns=columns
        ),
        "total": pd.DataFrame(
            total_dev, index=power_index, columns=columns
        ),
        "temperature": pd.DataFrame(
            temperature_error, index=power_index, columns=columns
        ),
        "temperature_near_bound_mse": pd.DataFrame(
            temperature_error_near_bound, index=power_index, columns=columns
        ),
        "near_bound_count": pd.DataFrame(
            near_bound_count, index=power_index, columns=columns
        ),
        "slack_error_missed": pd.DataFrame(
            slack_error_missed_all, index=power_index, columns=columns
        ),
        "slack_error_false": pd.DataFrame(
            slack_error_false_all, index=power_index, columns=columns
        ),
        "slack_error_both": pd.DataFrame(
            slack_error_both_all, index=power_index, columns=columns
        ),
        "slack_obj_error_missed": pd.DataFrame(
            slack_obj_error_missed_all, index=power_index, columns=columns
        ),
        "slack_obj_error_false": pd.DataFrame(
            slack_obj_error_false_all, index=power_index, columns=columns
        ),
        "slack_obj_error_both": pd.DataFrame(
            slack_obj_error_both_all, index=power_index, columns=columns
        ),
        "missed_count": pd.DataFrame(
            missed_count, index=power_index, columns=columns
        ),
        "false_count": pd.DataFrame(
            false_count, index=power_index, columns=columns
        ),
        "both_count": pd.DataFrame(
            both_count, index=power_index, columns=columns
        ),
        "wrong_side_error": pd.DataFrame(
            wrong_side_error, index=power_index, columns=columns
        ),
        "power": pd.DataFrame(
            power_error, index=power_index, columns=columns
        ),
        "temperature_l1": pd.DataFrame(
            temperature_error_l1, index=power_index, columns=columns
        ),
        "power_l1": pd.DataFrame(
            power_error_l1, index=power_index, columns=columns
        ),
    }

    start = start + pd.to_datetime("2024-01-01")
    if start is not None:
        result = {
            name: frame.loc[start:]
            for name, frame in result.items()
        }

    #result.index = pd.to_datetime("2024-01-01") + result.index
    return result

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

            """
            print("old :", pred["s1"].iloc[1])
            print("new :", pred["s1"].to_numpy()[1])

            print("old slack pred:",
                slack_weight * pred["s1"].iloc[1]**2)

            print("new slack pred:",
                slack_weight * pred["s1"].to_numpy()[1]**2) 
            """
            next_ndx = res.index[i+1]
            # Calculate 0-step predicted energy cost:
            onestep.loc[ndx, "cost_pred"] = (
                    pred["Prad"].iloc[0]/2500 + \
                    pred["coo_219"].iloc[0]/2500
                )*res["cost"].iloc[i]
            # Calculate 1-step predicted slack term:
            if i == 30:
                print(i)
            onestep.loc[next_ndx, "slack_pred"] = \
                slack_weight*pred["s1"].iloc[1]**2
        except KeyError:
            onestep.loc[ndx, "cost_pred"] = np.nan
            onestep.loc[ndx, "slack_pred"] = np.nan
        # Calculate 0-step actual energy cost:
        onestep.loc[ndx, "cost_act"] = (
            res.loc[ndx, "Prad"]/2500 + res.loc[ndx, "Pcoo"]/2500
        )*res["cost"].iloc[i]
        #if pred["Prad"].iloc[0] > 100:
        #    print(pred)
    #onestep["Prad_act"] = res["Prad"][:-N]/2500
    onestep["slack_act"] = slack_viol

    if start is not None:
        onestep_before_acc = onestep.copy()
        onestep = onestep.loc[start:]
        onestep_before_acc.index = pd.to_datetime("2024-01-01") + onestep_before_acc.index
    else:
        onestep_before_acc = None

    onestep = get_cumulative_devs(
        onestep
    )
    #onestep = onestep.fillna(0)
    #onestep.index = onestep.index.to_pydatetime()
    onestep.index = pd.to_datetime("2024-01-01") + onestep.index
    #return onestep[:-1].astype(float)
    return onestep.astype(float)

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