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
from matplotlib.ticker import MaxNLocator, ScalarFormatter, FuncFormatter
from pathlib import Path
from operating_point_plot import plot_operating_context, CONTROLLER_NAMES

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
        control[k] = v.res["rad_219"].shift(-1)

    control.rename(
        columns={
            "mhe_cost_free_rad_hist":  "cont",
            "adaptive_cost_free_rad": "per",
            "baseline_cost_hist": "fixed"
        },
        inplace=True
    )  
    day = 0 
    control_orig = control.loc[
        pd.Timedelta(days=day):stop
    ]
    day = 15
    control = control.loc[
        pd.Timedelta(days=day):stop
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
        
    #control = control.resample(rule="6h").mean()
    #control = control.rolling("15min").mean()
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
    plt.show(block=False)

    active_diff.describe(
        percentiles=[0.25, 0.5, 0.75, 0.9, 0.95, 0.99]
    )

    almost_one = active_diff[active_diff > 0.8]
    hard_6h = active_diff[active_diff > 0.4]
    # need this:
    p = coord.controller.p

    """
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    diff[["cont-per", "per-fixed", "cont-fixed"]].plot(drawstyle="steps-post", ax=ax)
    ax = axes[1]
    diff["max-min"].plot(drawstyle="steps-post", ax=ax)
    plt.show()
    """
    
    """
    # 'true' difference:
    exact_time = pd.Timedelta(days=20, hours=11, minutes=45)  
    # same as:
    exact_time = hard_6h.sort_values(ascending=False).index[0] - \
        pd.Timedelta(hours=2, minutes=30)
    # morning anticipation:
    #int_ndx = coord.res.index.get_loc(exact_time)
    int_ndx = control_orig.index.get_loc(exact_time)
    for k, v in read_coords.items():
        print(k)
        pred = v.controller.preds[int_ndx]
        print(pred.loc[0, p])


    start = pd.Timedelta(days=20)
    #start = pd.Timedelta(days=48)
    stop = start + pd.Timedelta(days=3)
    
    operating_point = pd.Timedelta(days=22) + pd.Timedelta(
        hours=6,
        minutes=15,
    )

    fig = plot_operating_context(
        read_coords,
        start=start,
        stop=stop,
        operating_point=exact_time,
        #operating_point=operating_point,
        #operating_point=None,
        sampling="15min",
        filename="OP20.pdf",
    )
    plt.show(block=False)

    """

    exact_time = candidates.index[1]
    int_ndx = control_orig.index.get_loc(exact_time)
    start = pd.Timedelta(days=35)
    #start = pd.Timedelta(days=48)
    stop = start + pd.Timedelta(days=3)

    fig = plot_operating_context(
        read_coords,
        start=start,
        stop=stop,
        operating_point=exact_time,
        #operating_point=None,
        sampling="15min",
        filename="OP36.pdf",
    )
    plt.show(block=False)
    
    """
    fig, axess = plt.subplots(6,1, sharex=True)
    for i, (k, v) in enumerate(read_coords.items()):
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
    
    def sweep_params(
        first,
        second,
        coord,
        int_ndx,
        ax,
        title,
        alpha=1.0,
        H=1,
        state=False,
        first_label="",
        second_label="",
    ):

        us = pd.DataFrame()
        u_primes = pd.DataFrame()
        params = coord.controller.preds[int_ndx].loc[0, p]
        new_params = params.copy()
        first_values = first["values"]
        second_values = second["values"]
        mpc_agent = coord.controller
        forecast = mpc_agent.forecasts[int_ndx]
        lbx, ubx = mpc_agent.get_bounds_from_forecast(forecast)
        
        # transform price:
        mean = mpc_agent.preds[int_ndx]["cost"].mean()
        new_price = mean + alpha*(mpc_agent.preds[int_ndx]["cost"] - mean)
        forecast["cost"] = new_price.values

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
                    
                #mpc_agent = coord.controller
                #forecast = mpc_agent.forecasts[int_ndx]
                #lbx, ubx = mpc_agent.get_bounds_from_forecast(forecast)
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
                """
                u_new = mpc_agent.hammerstein_transform(
                    u_prime,
                    params=new_params
                )["rad_219"]
                """
                u_new = pd.Series(name="rad_219")
                for h in range(H):
                    u_new.loc[k] = mpc_agent.hammerstein_transform(
                        new_sol[mpc_agent.mpc.u_names].loc[h],
                        params=new_params
                    )["rad_219"]
                us.loc[_first, _second] = u_new.mean()
                u_primes.loc[_first, _second] = u_prime["Prad"]

        first_u_vals = us.index.to_numpy()
        second_u_vals = us.columns.to_numpy()
        
        if state:
            first_u_vals = first_u_vals - 273.15
            second_u_vals = second_u_vals - 273.15
        

        first_grid, second_grid = np.meshgrid(
            first_u_vals, second_u_vals
        )

        U = us.to_numpy().T
        U_plot = np.clip(U, 0.0, 1.0)
        
        #fig, ax = plt.subplots(figsize=(6, 5))

        levels = [
            0, 0.025, 0.05, 0.1, 0.2,
            0.3, 0.4, 0.5, 0.6, 0.7,
            0.8, 0.9, 1.0
        ]

        cf = ax.contourf(
            first_grid,
            second_grid,
            U_plot,
            levels=np.linspace(0, 1, 11),
            #levels=levels,
            cmap="viridis",
            vmin=0,
            vmax=1
        )
        """
        cf = ax.pcolormesh(
            first_grid,
            second_grid,
            U_plot,
            levels=np.linspace(0, 1, 11),
            cmap="viridis",
            vmin=0,
            vmax=1
        )
        """
        values = coord.controller.preds[int_ndx].loc[
            0, [first["name"], second["name"]]
        ].values
        
        if state:
            values -= 273.15
        
        #eps = 0.1
        print(title + ":")
        print(first["name"] + ": " + str(values[0]))
        print(second["name"] + ": " + str(values[1]))
        ax.scatter(
            values[0],
            values[1],
            #u_stars[orig] + eps,
            edgecolor="white",
            linewidth=1.0,
            s=30,
            marker="o",
            color="black",
            label=k
        )
        

        #ax.set_xlabel(r"$C_{e}$")
        #ax.set_ylabel(r"$C_{i}$")
        ax.set_xlabel(
            first_label
        )
        ax.set_ylabel(
            second_label
        )
        ax.set_title(title)
        #ax.set_zlabel(r"$u^\star_{\mathrm{rad}}$")

        #fig.colorbar(surf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")
        #fig.colorbar(cf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")
        return us, u_primes, cf

    ces = np.arange(0.1e7,1.1e8,1e7)
    cis = np.arange(0.1e6,1.1e7,1e6)
    reas = [1e-2,2e-2,3e-2,4e-2,5e-2,6e-2,7e-2,8e-2,9e-2]
    ries = [1e-3,2e-3,3e-3,4e-3,5e-3,6e-3,7e-3,8e-3,9e-3]
    #ces = np.arange(2.5e7,3.1e7,0.1e7)
    #cis = np.arange(2.8e6,3.4e6,0.1e6)
    #ces = np.arange(1e6,1.1e7,1e6)
    #cis = np.arange(1e5,1.1e6,1e5)
    #ces = np.arange(1e8,1e9,1e8)
    #cis = np.arange(1e7,1e8,1e7)
    #Tes = np.arange(292.15,294.35,0.2)
    #Tis = np.arange(293.15,295.35,0.2)
    #Tes = np.arange(290.15,292.35,0.2)
    #Tis = np.arange(290.15,292.35,0.2)
    
    """
    obs = read_coords[
        "baseline_cost_hist"
    ].controller.preds[int_ndx][
        ["Te", "Ti" ]
    ].iloc[0].values
    
    Cs = read_coords[
        "baseline_cost_hist"
    ].controller.preds[int_ndx][
        ["Ce", "Ci" ]
    ].iloc[0].values
    """
    
    obs_all = pd.DataFrame(
        index=list(read_coords.keys()),
        columns=["Te", "Ti"]
    )
    
    for k, v in read_coords.items():
        obs_all.loc[k, ["Te", "Ti"]] = v.controller.preds[int_ndx][
            ["Te", "Ti" ]
        ].iloc[0]
    
    obs = obs_all.mean().values
    
    
    Cs_all = pd.DataFrame(
        index=list(read_coords.keys()),
        columns=["Ce", "Ci"]
    )

    for k, v in read_coords.items():
        Cs_all.loc[k, ["Ce", "Ci"]] = v.controller.preds[int_ndx][
            ["Ce", "Ci" ]
        ].iloc[0]
    
    Cs = Cs_all.mean().values
    
    Rs_all = pd.DataFrame(
        index=list(read_coords.keys()),
        columns=["Rea", "Rie"]
    )

    for k, v in read_coords.items():
        Rs_all.loc[k, ["Rea", "Rie"]] = v.controller.preds[int_ndx][
            ["Rea", "Rie" ]
        ].iloc[0]
    
    Rs = Rs_all.mean().values
    
    #Tes = np.arange(290.15,292.35,0.2)
    #Tis = np.arange(290.15,292.35,0.2)
    
    # (Ti, Te):
    
    delta = 0.35
    n_segments = 7
    Tes = np.concatenate(
        [
         np.arange(obs[0] - delta, obs[0], delta/n_segments),
         np.arange(obs[0], obs[0] + delta, delta/n_segments)
        ]
    )
    Tis = np.concatenate(
        [
         np.arange(obs[1] - delta, obs[1], delta/n_segments),
         np.arange(obs[1], obs[1] + delta, delta/n_segments)
        ]
    )

    # (Ci, Ce):

    delta = 2e7
    n_segments = 5
    ces = np.concatenate(
        [
         np.arange(Cs[0] - delta, Cs[0], delta/n_segments),
         np.arange(Cs[0], Cs[0] + delta, delta/n_segments)
        ]
    )
    delta = 2e6
    cis = np.concatenate(
        [
         np.arange(Cs[1] - delta, Cs[1], delta/n_segments),
         np.arange(Cs[1], Cs[1] + delta, delta/n_segments)
        ]
    )
    
    # (Rie, Rea):

    delta = 1e-2
    n_segments = 10
    reas = np.concatenate(
        [
         np.arange(Rs[0] - delta, Rs[0], delta/n_segments),
         np.arange(Rs[0], Rs[0] + delta, delta/n_segments)
        ]
    )
    delta = 1e-3
    ries = np.concatenate(
        [
         np.arange(Rs[1] - delta, Rs[1], delta/n_segments),
         np.arange(Rs[1], Rs[1] + delta, delta/n_segments)
        ]
    )

    # test version:
    Prads = [1500, 2000]
    ns = [1,2]
    
    #cis = [1e6,1e7]
    #ces = [1e7,1e8]
    
    #Tis = [290,295]
    #Tes = [290,295]
    
    reas = [1e-2,2e-2]
    ries = [1e-3,2e-3]
    
    ###
    
    reas = [1e-2,2e-2,3e-2,4e-2,5e-2,6e-2,7e-2,8e-2,9e-2,1e-1,1.1e-1,1.2e-1,1.3e-1]
    ries = [1e-3,2e-3,3e-3,4e-3,5e-3,6e-3,7e-3,8e-3,9e-3,1e-2,1.1e-2,1.2e-2]
    
    Prads = np.arange(1500,2600,100)
    ns = np.arange(0.1,3.1,0.3)
    
    #Tes = np.arange(290.15,292.35,0.2)
    #Tis = np.arange(290.15,292.35,0.2)
    
    #ces = np.arange(0.1e7,1.1e8,1e7)
    #cis = np.arange(0.1e6,1.1e7,1e6)
    
    """
    H-analysis:
    """
    first = {
        "values": reas,
        "name": "Rea",
        "label": "$R_{ea}$"
    }
    second = {
        "values": ries,
        "name": "Rie",
        "label": "$R_{ie$"
    }
    
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
    
    
    # Resampling open-loop planning:
    fig, axes = plt.subplots(4,3, figsize=(18, 5))
    #_fig, _axes = plt.subplots(1,3, figsize=(18, 5))
    
    for i, H in enumerate((1,2,4,8)):
    #for i, H in enumerate((1,8)):
    
        us = {}
        u_primes = {}
        for j, (k, v) in enumerate(read_coords.items()):
            # first, second, coord, int_ndx, ax, title
            us[k], u_primes[k], _ = sweep_params(
                first, 
                second,
                v, 
                int_ndx,
                axes[i,j],
                k,
                H=H,
                state=False
            )
    plt.show(block=False)
    print("tail")
    
    
    all_params ={
        "Cs": {
            "first": {
                "values": ces,
                "name": "Ce",
                #"label": "$C_e \\, [10^{8} \\frac{\\text{J}}{\\text{K}}]$"
                "label": "$C_e \\, [10^{8} \\, \\mathrm{J/K}]$"
            },
            "second": {
                "values": cis,
                "name": "Ci",
                "label": "$C_i \\, [10^{7} \\, \\mathrm{J/K}]$"
            }
        },
        "Rs": {
            "first": {
                "values": reas,
                "name": "Rea",
                "label": "$R_{ea} \\, [10^{-2} \\, \\mathrm{K/W}]$"                
            },
            "second": {
                "values": ries,
                "name": "Rie",
                "label": "$R_{ie} \\, [10^{-3} \\, \\mathrm{K/W}]$"                    
            }
        },
        "Ts": {
            "first": {
                "values": Tes,
                "name": "Te",
                "label": "$T_e \\, [^\\circ\\mathrm{C}]$"
            },
            "second": {
                "values": Tis,
                "name": "Ti",
                "label": "$T_i \\, [^\\circ\\mathrm{C}]$"
            }
        },
        "Prad": {
            "first": {
                "values": Prads,
                "name": "Prad_nom",
                "label": "$P_{rad}  \\, [\\mathrm{W}]$"
            },
            "second": {
                "values": ns,
                "name": "n",
                "label": "$n  \\, [-]$"                
            }
        }
    }
    
    fig, axes = plt.subplots(4,3, figsize=(10, 6.5))
    us = {}
    u_primes = {}
    for i, (_k, pairs) in enumerate(all_params.items()):
        for j, (k, v) in enumerate(read_coords.items()):
            #if k == "baseline_cost_hist":
            if True:
                if i == 0:
                    title = CONTROLLER_NAMES[k]
                else:
                    title = ""
                if j == 0:
                    first_label = pairs["first"]["label"]
                    second_label = pairs["second"]["label"]
                else:
                    first_label = ""
                    second_label = ""
                    
                # first, second, coord, int_ndx, ax, title
                if _k == "Ts":
                    state = True
                else:
                    state = False
                us[k], u_primes[k], cf = sweep_params(
                    pairs["first"], 
                    pairs["second"],
                    v, 
                    int_ndx,
                    axes[i,j],
                    title,
                    state=state,
                    first_label=first_label,
                    second_label=second_label
                )
    # colorbar here:
    #fig.colorbar(cf, ax=ax, label=r"$u^\star_{\mathrm{rad}}$")          
    cbar = fig.colorbar(
        cf,
        ax=axes,
        location="right",
        fraction=0.025,
        pad=0.02,
    )
    cbar.set_ticks([0, 0.5, 1.0])
    cbar.set_label(r"$u_{\mathrm{val}}^\star$ [-]")
    
    # ticks:
    # Ci, Ce
    for ax in axes[0, :]:
        #ax.set_xticks([0.2e8, 0.6e8, 1.0e8])
        ax.set_yticks([0.2e7, 0.4e7])
        ax.set_xticks([0.1e8, 0.4e8])
        #ax.set_xticks([round(ces[0], 8), round(ces[-1], 8)])
        #ax.set_yticks([0.2e7, 0.6e7, 1.0e7])
        #ax.set_xticks([round(cis[0], 7), round(cis[-1], 7)])
        ax.xaxis.set_major_formatter(
            FuncFormatter(lambda x, pos: f"{x/1e8:g}")
        )
        ax.yaxis.set_major_formatter(
            FuncFormatter(lambda y, pos: f"{y/1e7:g}")
        )

    # Rie, Rea
    for ax in axes[1, :]:
        ax.set_xticks([0.02, 0.13])
        
        """
        fmt_x = ScalarFormatter(useMathText=True)
        fmt_x.set_powerlimits((-2, -2))
        ax.xaxis.set_major_formatter(fmt_x)
        """
        
        ax.set_yticks([0.002, 0.01])
        
        """
        fmt_y = ScalarFormatter(useMathText=True)
        fmt_y.set_powerlimits((-3, -3))
        ax.yaxis.set_major_formatter(fmt_y)
        """
        ax.xaxis.set_major_formatter(
            FuncFormatter(lambda x, pos: f"{x/1e-2:g}")
        )
        # R_ea: display 0.001 as 1, etc.
        ax.yaxis.set_major_formatter(
            FuncFormatter(lambda y, pos: f"{y/1e-3:g}")
        )
    
    # Te, Ti
    for ax in axes[2, :]:
        #ax.set_xticks(np.array([292.15]) - 273.15)
        #ax.set_yticks(np.array([290.15, 292.15]) - 273.15)
        ax.set_yticks(
            np.array(
                [
                    round(Tis[0] - 273.15, 1) + 0.1,
                    round(Tis[-1] - 273.15, 1) - 0.1
                ]
            )
        )
        ax.set_xticks(
            np.array(
                [
                    round(Tes[0] - 273.15, 1) + 0.1,
                    round(Tes[-1] - 273.15, 1) - 0.1
                ]
            )
        )

    # Prad, n
    for ax in axes[3, :]:
        ax.set_xticks([1500, 2500])
        
    fig.subplots_adjust(
        left=0.10,
        right=0.86,
        bottom=0.10,
        top=0.92,
        wspace=0.22,
        hspace=0.34,
    )
    
    #for ax in axes.flat:
    #    ax.xaxis.labelpad = -1
    for ax in axes.flat:
        ax.xaxis.set_label_coords(0.5, -0.08)
    
    plt.show(block=False)
    fig.savefig(
        #"PS20.pdf",
        "PS36.pdf",
        bbox_inches="tight",
    )
    print("tail")
    
    u_stars = {}
    for k, v in read_coords.items():
        u_stars[k] = v.res.loc[exact_time + pd.Timedelta(minutes=15), "rad_219"]
        #u_stars[k] = v.res.loc[exact_time, "rad_219"]

    print("mid")
    
    # equivalence of MPC solution:
    """
    assert (new_sol == sol).all().all()
    u_new = mpc_agent.hammerstein_transform(
        u_prime
    )["rad_219"]
    assert (u_star.round(5) == u_new.round(5))
    """
    
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