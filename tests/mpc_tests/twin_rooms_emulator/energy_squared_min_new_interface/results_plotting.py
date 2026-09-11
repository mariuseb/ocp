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
from ocp.tests.mpc_tests.twin_rooms_emulator.energy_squared_min_new_interface.utils import quick_plot, \
    plot_parameter_evolution, \
    one_step_cost_pred, \
    get_value_function_error_all_N
import matplotlib.dates as mdates
from matplotlib.ticker import MaxNLocator
from pathlib import Path
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    _path = "results_local"
    base = Config()("base_config_scaled.json")
    #base["days"] = 28
    #base["days"] = 31 + 28 + 31 + 30 + 31 
    base["days"] = 365
    #base["days"] = 28
    #base["days"] = 2
    stop_day = 182
    #stop_day = 14
    #stop_day = 28

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
    errors_by_N = {}
    for k, v in meta.items():
        cfg = deepcopy(base)
        for _k, _v in v.items():
            if _k != "cost":
                cfg["controller"][_k] = _v
        cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]

        coord = Coordinator.read_result(cfg, _path=_path)
        """
        values[k], _ = get_value_function_error(
            coord, start=start, stop=stop
        )
        """
        values[k] = devs = get_value_function_error_all_N(
            coord, start=start, stop=stop
        )
        errors_by_N[k] = pd.DataFrame({
            #name: frame.sum(axis=0) 
            name: frame.sum(axis=0) 
            for name, frame in devs.items()
        })

        onesteps[k] = one_step_cost_pred(
            coord, start=start, stop=stop
        )
        read_coords[k] = coord
        #kpis[k] = coord.kpis
        kpis[k] = coord.get_custom_kpis(stop=stop)
        print(k + " kpis:")
        print(kpis[k])
        #plt.show()

    onestep = onesteps["baseline_cost_hist"]
    onestep_ad = onesteps["adaptive_cost_free_rad"]
    onestep_mhe = onesteps["mhe_cost_free_rad_hist"]
    

    value = values["baseline_cost_hist"]
    value_ad = values["adaptive_cost_free_rad"]
    value_mhe = values["mhe_cost_free_rad_hist"]

    control = pd.DataFrame(
        columns=read_coords.keys()
    )
    for k, v in read_coords.items():
        control[k] = v.res["rad_219"]

    control.rename(
        columns={
            "mhe_cost_free_rad_hist":  "cont",
            "adaptive_cost_free_rad": "per",
            "baseline_cost_hist": "fixed"
        },
        inplace=True
    )   
    control = control.loc[
        pd.Timedelta(days=15):stop
    ]
    
    ### morning operating point:
    morning = (control.index.components.hours >= 6) & (control.index.components.hours <= 10)
    morning.index = control.index
    interior = (
        (control > 0.2) &
        (control < 0.8)
    ).any(axis=1)
    spread = control.max(axis=1) - control.min(axis=1)
    """
    candidates = (
        control.loc[morning & interior]
        .sort_values(ascending=False)
    )
    """
    candidates = (
        spread[morning & interior]
        .sort_values(ascending=False)
    )
    candidates.head(10)
        
    #control = control.resample(rule="2h").mean()
    control = control.rolling("6h").mean()
    diff = pd.DataFrame(
        columns=["cont-per", "per-fixed", "cont-fixed"]
    )
    diff["cont-per"] = (control["cont"] - control["per"]).abs()
    diff["per-fixed"] = (control["per"] - control["fixed"]).abs()
    diff["cont-fixed"] = (control["cont"] - control["fixed"]).abs()
    diff["max-min"] = (
        control.max(axis=1) - \
        control.min(axis=1)
    ).abs()

    active = control.max(axis=1) > 0.05
    active_diff = diff["max-min"].loc[active]

    fig, ax = plt.subplots(figsize=(5, 3.5))
    ax.hist(active_diff, bins=np.linspace(0, 1, 21))
    ax.set_xlabel(r"Policy spread $d_{\max}$")
    ax.set_ylabel("Count")
    fig.tight_layout()
    plt.show()

    active_diff.describe(
        percentiles=[0.25, 0.5, 0.75, 0.9, 0.95, 0.99]
    )

    almost_one = active_diff[active_diff > 0.8]

    hard_6h = active_diff[active_diff > 0.4]

    """
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    diff[["cont-per", "per-fixed", "cont-fixed"]].plot(drawstyle="steps-post", ax=ax)
    ax = axes[1]
    diff["max-min"].plot(drawstyle="steps-post", ax=ax)
    plt.show()
    """
    
    exact_time = pd.Timedelta(days=20, hours=11, minutes=45)  
      
    exact_time = candidates.index[1]
    int_ndx = coord.res.index.get_loc(exact_time)
    p = coord.controller.p
    for k, v in read_coords.items():
        print(k)
        pred = v.controller.preds[int_ndx]
        print(pred.loc[0, p])


    """
    Try to reconstruct MPC solution at 'exact_time'.
    """
    
    """
    mpc_agent = read_coords["baseline_cost_hist"].controller
    params = mpc_agent.preds[int_ndx].loc[0, p]
    res = read_coords["baseline_cost_hist"].res
    u_star = res["rad_219"].loc[exact_time]
    sol = mpc_agent.preds[int_ndx]
    forecast = mpc_agent.forecasts[int_ndx]
    lbx, ubx = mpc_agent.get_bounds_from_forecast(forecast)
    # leave out lbu, ubu for now 
    # take x0 from existing MPC solution:

    reas = [1e-2,2e-2,params.loc["Rea"],3e-2,4e-2,5e-2,6e-2,7e-2,8e-2,9e-2]
    ries = [1e-3,2e-3,params.loc["Rie"],3e-3,4e-3,5e-3,6e-3,7e-3,8e-3,9e-3]

    obs = sol[["Ti", "Te"]].iloc[0]

    # keep first 6hs:

    """
    """
    us = pd.DataFrame(columns=range(24))
    new_params = params.copy()
    for rea in reas:
    
        new_params["Rea"] = rea
        new_sol, u_prime, x0, raw_sol = mpc_agent.mpc.solve(
            forecast,
            x0=obs,
            lbx=lbx,
            ubx=ubx,
            params=new_params,
            codegen=mpc_agent.mpc.codegen,
            return_raw_sol=True, 
            qp=False
        )
        for i in range(24):
            u_prime.loc["Prad"] = new_sol.loc[i, "Prad"]
            u_new = mpc_agent.hammerstein_transform(
                u_prime
            )["rad_219"]
            us.loc[rea, i] = u_new

    new_index = pd.TimedeltaIndex(us.columns*900, unit="s")
    us.columns = new_index
    us = us.T

    us_2h = us.resample("2h").mean()

    ax = us.plot(drawstyle="steps-post")
    ax.set_ylabel("$u^{*}$")
    ax.set_xlabel("$R_{ea}$")
    plt.show()
    us = pd.DataFrame()
    new_params = params.copy()
    for rea in reas:
        new_params["Rea"] = rea
        for rie in ries:
            new_params["Rie"] = rie
            new_sol, u_prime, x0, raw_sol = mpc_agent.mpc.solve(
                forecast,
                x0=obs,
                lbx=lbx,
                ubx=ubx,
                params=new_params,
                codegen=mpc_agent.mpc.codegen,
                return_raw_sol=True, 
                qp=False
            )
            u_new = mpc_agent.hammerstein_transform(
                u_prime
            )["rad_219"]
            us.loc[rea, rie] = u_new

    Rie_vals = us.columns.to_numpy()
    Rea_vals = us.index.to_numpy()

    Rie_grid, Rea_grid = np.meshgrid(Rie_vals, Rea_vals)

    U = us.to_numpy()
    U_plot = np.clip(U, 0.0, 1.0)

    """
    """
    fig = plt.figure(figsize=(8, 6))
    ax = fig.add_subplot(111, projection="3d")

    surf = ax.plot_surface(
        Rie_grid,
        Rea_grid,
        U,
        cmap="viridis",
        edgecolor="none",
        alpha=0.9
    )

    fig, ax = plt.subplots(figsize=(6, 5))

    cf = ax.contourf(
        Rie_grid,
        Rea_grid,
        U_plot,
        levels=np.linspace(0, 1, 11),
        cmap="viridis",
        vmin=0,
        vmax=1
    )
    
    fixed_pred = read_coords["baseline_cost_hist"].controller.preds[int_ndx]
    cont_pred = read_coords["mhe_cost_free_rad_hist"].controller.preds[int_ndx]
    per_pred = read_coords["adaptive_cost_free_rad"].controller.preds[int_ndx]
    u_stars = {}
    for k, v in read_coords.items():
        u_stars[k] = v.res.loc[exact_time, "rad_219"]

    points = {
        "Continuous": {
            "color": "red",
            "values": 
                cont_pred.loc[0, ["Rie", "Rea"]].values
        },
        "Periodic": {
            "color": "red",
            "values": 
                per_pred.loc[0, ["Rie", "Rea"]].values
        },
        "Fixed": {
            "color": "red",
            "values": 
                fixed_pred.loc[0, ["Rie", "Rea"]].values
        },
    }
    eps = 0.1
    for orig, (k, v) in zip(read_coords.keys(), points.items()):
        ax.scatter(
            v["values"][0],
            v["values"][1],
            #u_stars[orig] + eps,
            s=100,
            marker="o",
            color="black",
            label=k
        )

    ax.set_xlabel(r"$R_{ie}$")
    ax.set_ylabel(r"$R_{ea}$")
    #ax.set_zlabel(r"$u^\star_{\mathrm{rad}}$")

    #fig.colorbar(surf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")
    fig.colorbar(cf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")

    plt.show()

    """

    def sweep_params(first, second, coord, int_ndx, ax, title, state=False):

        us = pd.DataFrame()
        u_primes = pd.DataFrame()
        params = coord.controller.preds[int_ndx].loc[0, p]
        new_params = params.copy()
        first_values = first["values"]
        second_values = second["values"]
        for _first in first_values:
            if not state:
                new_params[
                    first["name"]
                ] = _first
            for _second in second_values:
                if not state:
                    new_params[
                        second["name"]
                    ] = _second

                """
                if first["name"] == "Prad_nom":
                    lbu, ubu = coord.controller.get_explicit_lb_ub_u()
                    ubu[0:-1:3] = _first/2500
                    print("pass")
                else:
                    ubu = None
                    lbu = None
                """
                lbu, ubu = coord.controller.get_explicit_lb_ub_u()
                ubu[0:-1:3] = new_params.loc["Prad_nom"]/2500
                #print("pass")
                
                if not state:
                    obs = coord.controller.preds[int_ndx].loc[0, ["Ti", "Te"]].values
                else:
                    obs = np.array([_second, _first])
                    
                mpc_agent = coord.controller
                forecast = mpc_agent.forecasts[int_ndx]
                lbx, ubx = mpc_agent.get_bounds_from_forecast(forecast)
                new_sol, u_prime, x0, raw_sol = mpc_agent.mpc.solve(
                    forecast,
                    x0=obs,
                    lbx=lbx,
                    ubx=ubx,
                    ubu=ubu,
                    lbu=lbu,
                    params=new_params,
                    codegen=mpc_agent.mpc.codegen,
                    return_raw_sol=True, 
                    qp=False
                )
                u_new = mpc_agent.hammerstein_transform(
                    u_prime,
                    params=new_params
                )["rad_219"]
                us.loc[_first, _second] = u_new
                u_primes.loc[_first, _second] = u_prime["Prad"]

        first_u_vals = us.index.to_numpy()
        second_u_vals = us.columns.to_numpy()

        first_grid, second_grid = np.meshgrid(
            first_u_vals, second_u_vals
        )

        U = us.to_numpy()
        U_plot = np.clip(U, 0.0, 1.0)
        
        #fig, ax = plt.subplots(figsize=(6, 5))

        cf = ax.contourf(
            first_grid,
            second_grid,
            U_plot,
            levels=np.linspace(0, 1, 11),
            cmap="viridis",
            vmin=0,
            vmax=1
        )
        values = coord.controller.preds[int_ndx].loc[
            0, [first["name"], second["name"]]
        ].values
        #eps = 0.1
 
        ax.scatter(
            values[0],
            values[1],
            #u_stars[orig] + eps,
            s=30,
            marker="o",
            color="black",
            label=k
        )
        

        #ax.set_xlabel(r"$C_{e}$")
        #ax.set_ylabel(r"$C_{i}$")
        ax.set_xlabel(first["label"])
        ax.set_ylabel(second["label"])
        ax.set_title(title)
        #ax.set_zlabel(r"$u^\star_{\mathrm{rad}}$")

        #fig.colorbar(surf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")
        fig.colorbar(cf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")
        return us, u_primes

    ces = np.arange(0.1e7,1.1e8,1e7)
    cis = np.arange(0.1e6,1.1e7,1e6)
    #ces = np.arange(1e6,1.1e7,1e6)
    #cis = np.arange(1e5,1.1e6,1e5)
    #ces = np.arange(1e8,1e9,1e8)
    #cis = np.arange(1e7,1e8,1e7)
    Tes = np.arange(293.15,295.35,0.2)
    Tis = np.arange(293.15,295.35,0.2)

    #obs = sol[["Ti", "Te"]].iloc[0]

    """

    Prads = np.arange(1500,2500,100)
    ns = np.arange(0.1,1.1,0.1)
    Prads = np.arange(1000,10000,1000)
    ns = np.arange(0.1,2.8,0.3)

    first = {
        "values": Prads,
        "name": "Prad_nom",
        "label": "$P_{rad}$"
    }
    second = {
        "values": ns,
        "name": "n",
        "label": "$n$"
    }
    obs = sol[["Ti", "Te"]].iloc[0]
    """

    first = {
        "values": ces,
        "name": "Ce",
        "label": "$C_e$"
    }
    second = {
        "values": cis,
        "name": "Ci",
        "label": "$C_i$"
    }
    fig, axes = plt.subplots(1,3, figsize=(18, 5))
    us = {}
    u_primes = {}
    for i, (k, v) in enumerate(read_coords.items()):
        # first, second, coord, int_ndx, ax, title
        us[k], u_primes[k] = sweep_params(
            first, 
            second,
            v, 
            int_ndx,
            axes[i],
            k,
            state=False
        )
    plt.show(block=False)
    print("tail")
    # (Prad, n):
    
    first = {
        "values": Tes,
        "name": "Te",
        "label": "$T_e$"
    }
    second = {
        "values": Tis,
        "name": "Ti",
        "label": "$T_i$"
    }
    fig, axes = plt.subplots(1,3, figsize=(18, 5))
    us = {}
    u_primes = {}
    for i, (k, v) in enumerate(read_coords.items()):
        # first, second, coord, int_ndx, ax, title
        us[k], u_primes[k] = sweep_params(
            first, 
            second,
            v, 
            int_ndx,
            axes[i],
            k,
            state=True
        )
    plt.show(block=False)
    print("tail")
    
    u_stars = {}
    for k, v in read_coords.items():
        u_stars[k] = v.res.loc[exact_time + pd.Timedelta(minutes=15), "rad_219"]
    """
    
    Prads = np.arange(1000,10000,1000)
    ns = np.arange(0.1,2.8,0.3)
    obs = sol[["Ti", "Te"]].iloc[0]
    us = pd.DataFrame()
    new_params = params.copy()
    for Prad in Prads:
        new_params["Prad_nom"] = Prad
        for n in ns:
            new_params["n"] = n
            new_sol, u_prime, x0, raw_sol = mpc_agent.mpc.solve(
                forecast,
                x0=obs,
                lbx=lbx,
                ubx=ubx,
                params=new_params,
                codegen=mpc_agent.mpc.codegen,
                return_raw_sol=True, 
                qp=False
            )
            u_new = mpc_agent.hammerstein_transform(
                u_prime
            )["rad_219"]
            us.loc[Prad, n] = u_new

    Prad_vals = us.columns.to_numpy()
    n_vals = us.index.to_numpy()

    Prad_grid, n_grid = np.meshgrid(Rie_vals, Rea_vals)

    U = us.to_numpy()
    U_plot = np.clip(U, 0.0, 1.0)
    """

    """
    fig = plt.figure(figsize=(8, 6))
    ax = fig.add_subplot(111, projection="3d")

    surf = ax.plot_surface(
        Rie_grid,
        Rea_grid,
        U,
        cmap="viridis",
        edgecolor="none",
        alpha=0.9
    )

    fig, ax = plt.subplots(figsize=(6, 5))

    cf = ax.contourf(
        Prad_grid,
        n_grid,
        U_plot,
        levels=np.linspace(0, 1, 11),
        cmap="viridis",
        vmin=0,
        vmax=1
    )
    
    fixed_pred = read_coords["baseline_cost_hist"].controller.preds[int_ndx]
    cont_pred = read_coords["mhe_cost_free_rad_hist"].controller.preds[int_ndx]
    per_pred = read_coords["adaptive_cost_free_rad"].controller.preds[int_ndx]
    u_stars = {}
    for k, v in read_coords.items():
        u_stars[k] = v.res.loc[exact_time, "rad_219"]

    points = {
        "Continuous": {
            "color": "red",
            "values": 
                cont_pred.loc[0, ["Prad", "n"]].values
        },
        "Periodic": {
            "color": "red",
            "values": 
                per_pred.loc[0, ["Prad", "n"]].values
        },
        "Fixed": {
            "color": "red",
            "values": 
                fixed_pred.loc[0, ["Prad", "n"]].values
        },
    }
    eps = 0.1
    for orig, (k, v) in zip(read_coords.keys(), points.items()):
        ax.scatter(
            v["values"][0],
            v["values"][1],
            #u_stars[orig] + eps,
            s=100,
            marker="o",
            color="black",
            label=k
        )

    ax.set_xlabel(r"$P_{rad}$")
    ax.set_ylabel(r"$n$")
    #ax.set_zlabel(r"$u^\star_{\mathrm{rad}}$")

    #fig.colorbar(surf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")
    fig.colorbar(cf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")

    plt.show()
    """

    
    # equivalence of MPC solution:
    """
    assert (new_sol == sol).all().all()
    u_new = mpc_agent.hammerstein_transform(
        u_prime
    )["rad_219"]
    assert (u_star.round(5) == u_new.round(5))
    """
    


    start = pd.Timedelta(days=20)
    #start = pd.Timedelta(days=48)
    stop = start + pd.Timedelta(days=3)
    fig, axess = plt.subplots(6,1, sharex=True)
    for i, (k, v) in enumerate(read_coords.items()):
        """
        fig, axes = quick_plot(
            v, start=start, stop=stop, sampling="1h"
        )
        """
        _start = 2*i
        _stop = _start + 2
        axes = axess[_start:_stop]
        quick_plot(
            v, start=start, stop=stop, sampling="15min", axes=axes
        )
        for ax in axes:
            ax.set_title(k)
        #fig.suptitle(k)
    plt.show(block=False)
    print("head")
    """
    'Break-even' point w.r.t. n in N.

    Plot cumulative deviation of all n's,
    e.g. for economic prediction:
    """

    """
    slack_severity = dict()
    #for k, v in values.items():
    for k, v in errors_by_N.items():
        slack_error_missed = v["slack_error_missed"]
        slack_error_false = v["slack_error_false"]
        slack_error_both = v["slack_error_both"]
        missed_count = v["missed_count"]
        false_count = v["false_count"]
        both_count = v["both_count"]
        # Mean slack-error severity conditional on event occurrence
        slack_severity_missed = np.divide(
            slack_error_missed,
            missed_count,
            out=np.full_like(slack_error_missed, np.nan, dtype=float),
            where=missed_count > 0,
        )

        slack_severity_false = np.divide(
            slack_error_false,
            false_count,
            out=np.full_like(slack_error_false, np.nan, dtype=float),
            where=false_count > 0,
        )

        slack_severity_both = np.divide(
            slack_error_both,
            both_count,
            out=np.full_like(slack_error_both, np.nan, dtype=float),
            where=both_count > 0,
        )
        result = {
            "slack_severity_missed": slack_severity_missed,
            "slack_severity_false": slack_severity_false,
            "slack_severity_both": slack_severity_both
        }
        slack_severity[k] = pd.DataFrame().from_dict(
            result
        )

    for k, v in slack_severity.items():
        print(k)
        pprint(v)

    slack_obj_severity = dict()
    #for k, v in values.items():
    for k, v in errors_by_N.items():
        slack_error_missed = v["slack_obj_error_missed"]
        slack_error_false = v["slack_obj_error_false"]
        slack_error_both = v["slack_obj_error_both"]
        missed_count = v["missed_count"]
        false_count = v["false_count"]
        both_count = v["both_count"]
        # Mean slack-error severity conditional on event occurrence
        slack_severity_missed = np.divide(
            slack_error_missed,
            missed_count,
            out=np.full_like(slack_error_missed, np.nan, dtype=float),
            where=missed_count > 0,
        )

        slack_severity_false = np.divide(
            slack_error_false,
            false_count,
            out=np.full_like(slack_error_false, np.nan, dtype=float),
            where=false_count > 0,
        )

        slack_severity_both = np.divide(
            slack_error_both,
            both_count,
            out=np.full_like(slack_error_both, np.nan, dtype=float),
            where=both_count > 0,
        )
        result = {
            "slack_severity_missed": slack_severity_missed,
            "slack_severity_false": slack_severity_false,
            "slack_severity_both": slack_severity_both
        }
        slack_obj_severity[k] = pd.DataFrame().from_dict(
            result
        )

    for k, v in slack_obj_severity.items():
        print(k)
        pprint(v)
    """

    colors = {
        #"Fixed"      : "#3A3A3A",   # dark gray
        "Fixed"      : "#4D4D4D",   # dark gray
        "Periodic"   : "#0072B2",   # blue
        #"Continuous" : "#E69F00"   # orange
        "Continuous" : "#E69F00"   # orange
    }
    elems = {
        "temperature": "(a) Temperature",
        "slack": "(b) Comfort objective",
        "power": "(c) Power",
        "cost": "(d) Economic objective"
    }

    kwargs = {
        "drawstyle": "steps-post",
        "linewidth": 2.2
    }

    
    fig, axes = plt.subplots(2,2, sharex=True, sharey=False)

    for (k, v), ax in zip(elems.items(), axes.flatten()):
        errors_by_N["adaptive_cost_free_rad"][k].plot(
            ax=ax,
            color=colors["Periodic"], 
            **kwargs
        )
        errors_by_N["mhe_cost_free_rad_hist"][k].plot(
            ax=ax,
            color=colors["Continuous"],
            **kwargs
        )
        errors_by_N["baseline_cost_hist"][k].plot(
            ax=ax,
            color=colors["Fixed"],
            **kwargs
        )
        ax.set_title(v)
        ax.set_xlabel("")

    fig.legend(["Periodic", "Continuous", "Fixed"], loc='upper center', ncol=3)
    fig.supxlabel("Prediction horizon $N$")
    fig.supylabel("Cumulative prediction error")
    dir_path = Path(__file__).resolve().parent
    fig.savefig(
        dir_path / "cumulative_errors_over_N.pdf"
    )
    plt.show()

    """

    ### checks:

    #ax = values["mhe_cost_free_rad_hist"]["slack"][1].plot()
    slack_pred = onestep_mhe["slack_pred"][:-1].copy()
    slack_pred_ = values["mhe_cost_free_rad_hist"]["slack_pred"][1].copy()
    slack_pred_.index = slack_pred.index
    fig, ax = plt.subplots(1,1)
    slack_pred.plot(ax=ax)
    slack_pred_.plot(ax=ax)
    ax.legend(["old", "all_N_version"])
    plt.show()

    slack_dev = onestep_mhe["slack_dev"][:-1].copy().abs()
    slack_dev_ = values["mhe_cost_free_rad_hist"]["slack"][1].copy()
    slack_dev_.index = slack_dev.index
    fig, ax = plt.subplots(1,1)
    slack_dev.plot(ax=ax)
    slack_dev_.plot(ax=ax)
    ax.legend(["old", "all_N_version"])
    plt.show()
    
    cost_pred = onestep_mhe["cost_pred"][:-2].copy().abs()
    cost_pred_ = values["mhe_cost_free_rad_hist"]["cost_pred"][1][:-1].copy()
    cost_pred_.index = cost_pred.index
    fig, ax = plt.subplots(1,1)
    cost_pred.plot(ax=ax, drawstyle="steps-post")
    cost_pred_.plot(ax=ax, drawstyle="steps-post")
    ax.legend(["old", "all_N_version"])
    plt.show()

    cost_act = onestep_mhe["cost_act"][:-2].copy().abs()
    cost_act_ = values["mhe_cost_free_rad_hist"]["cost_act"][1][:-1].copy()
    cost_act_.index = cost_act.index
    fig, ax = plt.subplots(1,1)
    cost_act.plot(ax=ax, drawstyle="steps-post")
    cost_act_.plot(ax=ax, drawstyle="steps-post")
    ax.legend(["old", "all_N_version"])
    plt.show()

    cost_dev = onestep_mhe["cost_dev"][:-2].copy().abs()
    cost_dev_ = values["mhe_cost_free_rad_hist"]["cost"][1][:-1].copy()
    cost_dev_.index = cost_dev.index
    fig, ax = plt.subplots(1,1)
    cost_dev.plot(ax=ax, drawstyle="steps-post")
    cost_dev_.plot(ax=ax, drawstyle="steps-post")
    ax.legend(["old", "all_N_version"])
    plt.show()

    tot_dev_abs = onestep_mhe["tot_dev"][:-2].copy().abs()
    tot_dev_abs_ = values["mhe_cost_free_rad_hist"]["total"][1][:-1].copy()
    tot_dev_abs_.index = tot_dev_abs.index
    fig, ax = plt.subplots(1,1)
    tot_dev_abs.plot(ax=ax, drawstyle="steps-post")
    tot_dev_abs_.plot(ax=ax, drawstyle="steps-post")
    ax.legend(["old", "all_N_version"])
    plt.show()
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