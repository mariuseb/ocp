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

TABLE_INDS = ["tdis [Kh]", "energy [kWh]", "peak power [kW]", "cost [EUR]"]

def generate_latex_table(
    table: pd.DataFrame,
    caption: str,
    label: str
):
    """
    return table.style.to_latex(
        #index=True,
        position_float="centering",
        #float_format="{:.2f}".format,
        caption=caption,
        label=label
    )
    """
    latex_code = table.to_latex(
        index=True,
        #position_float="centering",
        float_format="{:.2f}".format,
        caption=caption,
        label=label
    )
    latex_code = latex_code.replace(
        r"\begin{table}", "\\begin{table}\n\\centering"
    )
    latex_code = latex_code.replace(
        r"$J_{tot}$", "\\midrule\nObjective function components & & & \\\\\n\\midrule\n$J_{tot}$"
    )
    latex_code = latex_code.replace(
        r"Thermal discomfort [Kh]", "Physical KPIs & & & \\\\\n\\midrule\nThermal discomfort [Kh]"
        #r"Thermal discomfort [Kh]", "\\midrule \n Physical KPIs & & & \\\\ \n \\midrule \n Thermal discomfort [Kh]"
    )
    return latex_code

def create_table(
    kpis: dict,
    read_coords: dict,
    onesteps: dict,
    starts = None
):
    table = pd.DataFrame(
        index=TABLE_INDS,
    )
    for k in read_coords:
        table.loc[:, k.split("_")[0]] = kpis[k]
        if starts is None:
            table.loc["total_obj", k.split("_")[0]] = onesteps[k].tot_cost.sum()
            table.loc["cost_obj", k.split("_")[0]] = onesteps[k].cost_act.sum()
            table.loc["comf_obj", k.split("_")[0]] = onesteps[k].slack_act.sum()
        else:
            table.loc["total_obj", k.split("_")[0]] = onesteps[k].tot_cost.loc[
                starts[k]:
            ].sum()
            table.loc["cost_obj", k.split("_")[0]] = onesteps[k].cost_act.loc[
                starts[k]:
            ].sum()
            table.loc["comf_obj", k.split("_")[0]] = onesteps[k].slack_act.loc[
                starts[k]:
            ].sum()

    table.loc["comp_time", :] = np.nan
    return table

if __name__ == "__main__":
    
    """
    Read PRBS result here:
    """
    # boilerplate:
    base = Config()("base_config_scaled.json")
    traverse_dict(
        base
    )
    base["days"] = 0
    meta = Config()("config_meta_only_baseline.json")
    for k, v in meta.items():
        cfg = deepcopy(base)
        for _k, _v in v.items():
            if _k != "cost":
                cfg["controller"][_k] = _v
        cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]
    # make cfg differ from MPC run:
    cfg["control"] = "PRBS"
    coord_prbs = Coordinator.read_result(cfg, _path="results_local")
    print(coord_prbs.kpis)
    onestep_prbs = one_step_cost_pred(
        coord_prbs
    )

    ################################################################

    _path = "results_local"
    base = Config()("base_config_scaled.json")
    #base["days"] = 28
    base["days"] = 31 + 28 + 31 + 30 + 31 
    base["days"] = 365
    # July 1st:
    stop_day = 182
    
    starts = {
        "adaptive_cost_free_rad": pd.Timedelta(days=8),
        "baseline_cost_hist": pd.Timedelta(days=8),
        "mhe_cost_free_rad_hist": pd.Timedelta(days=8)
    }

    stop = pd.Timedelta(days=stop_day)
    meta = Config()("config_meta_mhe_baseline_adaptive.json")
    results = {}
    read_coords = {}
    onesteps = {}

    kpis_tot = {}
    kpis_op = {}

    for k, v in meta.items():
        cfg = deepcopy(base)
        for _k, _v in v.items():
            if _k != "cost":
                cfg["controller"][_k] = _v
        cfg["environment"]["config"]["maps"]["r"]["cost"] = v["cost"]

        coord = Coordinator.read_result(cfg, _path=_path)
        read_coords[k] = coord
        #kpis[k] = coord.kpis
        kpis_tot[k] = coord.get_custom_kpis(stop=stop)
        kpis_op[k] = coord.get_custom_kpis(
            start=starts[k],
            stop=stop
        )
    for k, v in read_coords.items():
        onesteps[k] = one_step_cost_pred(
            v,
            stop=stop
        )
    # table 
    table_op = create_table(
        kpis_op,
        read_coords,
        onesteps,
        starts=starts
    )
    table_tot = create_table(
        kpis_tot,
        read_coords,
        onesteps
    )

    """
    We have:
        table_comm = table_tot - table_op

    Then, table_comm[baseline] needs to be adjusted,
    which implies a new entry table_tot[baseline].
    """

    # adjust:
    table_init = table_tot - table_op
    table_init.loc[TABLE_INDS, "baseline"] = coord_prbs.kpis.values
    table_init.loc["total_obj", "baseline"] = onestep_prbs.tot_cost.sum()
    table_init.loc["cost_obj", "baseline"] = onestep_prbs.cost_act.sum()
    table_init.loc["comf_obj", "baseline"] = onestep_prbs.slack_act.sum()
    # adjust total:
    table_tot.loc[:, "baseline"] = \
         table_init.loc[:, "baseline"] + table_op.loc[:, "baseline"]
    
    """
    Get labels publication-ready:
    """
    labels = {
        "tdis [Kh]": "Thermal discomfort [Kh]",
        "energy [kWh]": "Energy [kWh]",
        "peak power [kW]": "Peak power [kW]",
        "cost [EUR]": "Operating cost [EUR]",
        "total_obj": "$J_{tot}$",
        "cost_obj": "$J_{cost}$",
        "comf_obj": "$J_{comf}$",
        "comp_time": "$t_{comp}$",
    }
    columns = {
        "adaptive": "Periodic",
        "baseline": "Fixed",
        "mhe": "Continuous" 
    }  
    order = ["Fixed", "Periodic", "Continuous"]

    tables = {
        "init": table_init,
        "op":  table_op,
        "tot": table_tot
    }
    for k, table in tables.items():
        table = table.rename(
            index=labels,
            columns=columns
        )
        tables[k] = table[order]

    table_init = tables["init"]
    table_op = tables["op"]
    table_tot = tables["tot"]

    latex_init = generate_latex_table(
        table_init,
        "Results deployment period",
        "tab:kpi_deployment"    
    )
    print(latex_init)
    latex_op = generate_latex_table(
        table_op,
        "Results operational period",
        "tab:kpi_operational"    
    )
    print(latex_op)
    latex_tot = generate_latex_table(
        table_tot,
        "Results overall period",
        "tab:kpi_overall"    
    )
    print(latex_tot)

    print("tail")