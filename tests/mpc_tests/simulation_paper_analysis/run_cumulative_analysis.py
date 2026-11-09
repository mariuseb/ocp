"""Run from the same directory as your existing analysis scripts.

Example: python -m mpc_paper_analysis.run_month
Adjust the CONFIG constants to match the monthly campaign.
"""
from pathlib import Path
import json
import matplotlib.pyplot as plt
import pandas as pd

from data import load_coordinators, valve_trajectories, one_step_metrics
from events import Event, rank_policy_spread
from ocp.tests.mpc_tests.twin_rooms_emulator.energy_squared_min_new_interface.utils import quick_plot, \
    plot_parameter_evolution, \
    one_step_cost_pred, \
    get_value_function_error_all_N
from sensitivity import sensitivity_figure
from figures import (policy_spread_distribution, operating_context,
                      cumulative_one_step_objective,
                      cumulative_errors_over_N,
                      cumulative_prediction_deviation)

BASE_CONFIG = 'base_config_scaled.json'
#META_CONFIG = 'config_meta_mhe_baseline_adaptive_onetime_fixed_no_alpha.json'
META_CONFIG = 'config_meta_mhe_baseline_adaptive_onetime_fixed_alpha.json'
META_CONFIG = 'config_meta_mhe_baseline_adaptive_onetime_fixed_no_alpha.json'
META_CONFIG = 'config_meta_mhe_baseline_adaptive.json'
META_CONFIG = 'config_meta_mhe_baseline_adaptive_initial.json'
META_CONFIG = "config_meta_mhe_baseline_adaptive_fixed_const.json"
META_CONFIG = 'config_meta_mhe_baseline_adaptive_initial_alpha.json'
META_CONFIG = 'config_meta_mhe_baseline_adaptive_alpha.json'
META_CONFIG = "config_meta_mhe_baseline_adaptive_const.json"
META_CONFIG = 'config_meta_mhe_baseline_adaptive.json'
RESULTS_DIR = 'results_revised'
OUTPUT_DIR = Path('paper_figures/year_test')
START = pd.Timedelta(days=14)
START = pd.Timedelta(days=15)
STOP = pd.Timedelta(days=365)

NAME_MAP = {
    "baseline_cost_hist": "Fixed",
    "adaptive_cost_free_rad": "Periodic",
    "mhe_cost_free_rad_hist": "Continuous",
    "onetime_cost_free_rad": "One-time",
    "NS3031": "Initial guess",
}

def get_name_map(suffix=""):
    return {
        f"{key}{suffix}": value
        for key, value in NAME_MAP.items()
    }


def save(fig, filename):
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    fig.savefig(OUTPUT_DIR / filename, bbox_inches='tight')
    plt.close(fig)

def prediction_errors_over_N(coords, start, stop):
    errors_by_N = {}

    for name, coord in coords.items():
        devs = get_value_function_error_all_N(
            coord,
            start=start,
            stop=stop,
        )

        errors_by_N[name] = pd.DataFrame({
            key: frame.sum(axis=0)
            for key, frame in devs.items()
        })

    return errors_by_N

def main():
    coords = load_coordinators(BASE_CONFIG, META_CONFIG, RESULTS_DIR)
    metrics = one_step_metrics(
        coords, start=START, stop=STOP
    )
    deltas = pd.DataFrame(columns=metrics.keys())
    for k, v in metrics.items():
        deltas[k] = metrics[k]["tot_cost_cum"].diff(1)

    EVENT = Event(
        "",
        pd.Timedelta("176 days 14:15:00"),
        #pd.Timedelta("0 days 14:15:00"),
        ''
    )

    window_start = max(START, EVENT.time - pd.Timedelta(days=1))
    window_stop = min(STOP, EVENT.time + pd.Timedelta(days=2))
    op_fig, axes = operating_context(
        coords, window_start, window_stop, EVENT.time
    )
    plt.show()

    #alpha = ""
    #alpha_str = "_alpha" if alpha else ""
    suffix = "_" + META_CONFIG.rstrip(".json").split("_")[-1]
    if suffix == "_adaptive":
        suffix = ""
    NAME_MAP = get_name_map(suffix)
    
    save(
        cumulative_prediction_deviation(
            metrics,
            name_map=NAME_MAP
        ), 
        'cumulative_prediction_deviation' + suffix + '.pdf'
    )
    save(
        cumulative_one_step_objective(
            metrics,
            name_map=NAME_MAP
        ), 
        'cumulative_objective_realization' + suffix + '.pdf'
    )
    
    errors_by_N = prediction_errors_over_N(
        coords, 
        start=START,
        stop=STOP
    )
    save(
        #cumulative_prediction_deviation(metrics), 
        cumulative_errors_over_N(
            errors_by_N,
            name_map=NAME_MAP
        ), 
        'cumulative_errors_over_N'  + suffix + '.pdf'
    )


if __name__ == '__main__':
    main()
