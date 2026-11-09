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
#META_CONFIG = 'config_meta_mhe_baseline_adaptive_onetime_fixed_alpha.json'
META_CONFIG = 'config_meta_mhe_baseline_adaptive_reduced_no_alpha.json'
META_CONFIG = 'config_meta_mhe_baseline_adaptive_onetime_fixed_no_alpha.json'
META_CONFIG = 'config_meta_mhe_baseline_adaptive_initial.json'
META_CONFIG = "config_meta_mhe_baseline_adaptive_fixed_constant.json"
META_CONFIG = 'config_meta_mhe_baseline_adaptive_initial_alpha.json'
RESULTS_DIR = 'results_revised'
OUTPUT_DIR = Path('paper_figures/year')
START = pd.Timedelta(days=22)
STOP = pd.Timedelta(days=28)
STOP = pd.Timedelta(days=292)
STOP = pd.Timedelta(days=365)

# Explicit event chosen for the paper; change only after inspecting ranking.
# Timestamp and rationale are saved alongside the figure.
EVENT = Event('morning_example', pd.Timedelta(days=20, hours=11, minutes=45),
              'Frozen example; verify against monthly controller trajectories')

events = {
    "non_alpha": 
        {
            "morning_interior": 
                {
                    #"require_interior": True,
                    #"require_all_interior": False,
                    "require_interior": False,
                    "require_all_interior": True,
                    "morning": (6,8),
                    #"index": 11,
                    "index": 0,
                    "window": "15min"
                },
            "anticipatory":
                {
                    "require_interior": False,
                    "require_all_interior": False,
                    "morning": (1,5),
                    "index": 0,
                    "window": "6h"
                    #"days": range(15,28)
                },
            "unrestricted":
                {
                    "require_all_interior": True,
                    "require_interior": False,
                    "morning": None,
                    "index": 0,
                    "window": "15min"
                    #"days": range(15,28)
                },
        },
    "alpha": {
            "morning_interior": 
                {
                    #"require_interior": True,
                    #"require_all_interior": False,
                    "require_interior": False,
                    "require_all_interior": True,
                    "morning": (6,8),
                    #"index": 11,
                    "index": 0,
                    "window": "15min"
                },
            "anticipatory":
                {
                    "require_interior": False,
                    "require_all_interior": False,
                    "morning": (1,5),
                    "index": 0,
                    "window": "6h"
                    #"days": range(15,28)
                },
            "unrestricted":
                {
                    "require_all_interior": True,
                    "require_interior": False,
                    "morning": None,
                    "index": 0,
                    "window": "15min"
                    #"days": range(15,28)
                },
        },
    "const": {
            "morning_interior": 
                {
                    "require_interior": False,
                    #"require_all_interior": False,
                    "require_all_interior": True,
                    #"index": 11,
                    "morning": None,
                    "index": -1,
                    "window": "15min"
                },
            "anticipatory":
                {
                    "require_interior": False,
                    "require_all_interior": False,
                    "morning": (1,5),
                    "index": 0,
                    "window": "6h"
                    #"days": range(15,28)
                },
            "unrestricted":
                {
                    "require_all_interior": True,
                    "require_interior": False,
                    "morning": None,
                    "index": 0,
                    "window": "15min"
                    #"days": range(15,28)
                },
        },
}

def save(fig, filename):
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    fig.savefig(OUTPUT_DIR / filename, bbox_inches='tight')
    plt.close(fig)


def main():
    coords = load_coordinators(BASE_CONFIG, META_CONFIG, RESULTS_DIR)
    controls = valve_trajectories(coords)
    controls = controls.loc[START:STOP]
    #ranking = rank_policy_spread(controls, START, STOP, window='6h')
    # read kpis:
    kpis = {}
    for k, v in coords.items():
        kpis[k] = v.get_custom_kpis(
            start=START,
            stop=STOP
        )
        print(k + " kpis:")
        print(kpis[k])
    
    #alpha = "alpha"
    #suffix = "" if alpha != "alpha" else "_alpha"
    #ssuffix = "_const"
    suffix = "_" + META_CONFIG.rstrip(".json").split("_")[-1]

    prices = coords['mhe_cost_free_rad_hist' + suffix].res.cost.copy()

    alpha = "const"
    _events = events[alpha]

    point = "anticipatory"
    point = "unrestricted"
    point = "morning_interior"

    points = list(_events.keys())

    for point in points:
        kwargs = {
            "require_interior": events[alpha][point]["require_interior"],
            "require_all_interior": events[alpha][point]["require_all_interior"],
            "morning": events[alpha][point]["morning"],
            "window": events[alpha][point]["window"],
            #"days": events[alpha][point]["days"]
        }
        index = events[alpha][point]["index"]

        ranking = rank_policy_spread(
            #controls, 
            controls[[
                "mhe_cost_free_rad_hist" + suffix,
                "baseline_cost_hist" + suffix,
                "adaptive_cost_free_rad" + suffix
            ]],
            START,
            STOP,
            #window='6h',
            prices=prices,
            **kwargs
        )
        OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
        ranking.head(50).to_csv(OUTPUT_DIR / 'event_candidates.csv')
        #"header=['policy_spread'])

        policy_fig = policy_spread_distribution(controls, START, STOP)
        save(policy_fig, 'policy_spread.pdf')

        EVENT = Event(
            point,
            ranking.index[index],
            ''
        )

        window_start = max(START, EVENT.time - pd.Timedelta(days=1))
        window_stop = min(STOP, EVENT.time + pd.Timedelta(days=2))
        op_fig, axes = operating_context(
            coords, window_start, window_stop, EVENT.time
        )
        save(
            op_fig, 
            alpha + "_" + point + "_operating_context.pdf"
        )
        alpha_bool = (alpha == "alpha")

        CONTROLLER_ORDER = (
            'mhe_cost_free_rad_hist', 'adaptive_cost_free_rad',
            'onetime_cost_free_rad', 'baseline_cost_hist', 'NS3031',
        )
        LABELS = {
            'mhe_cost_free_rad_hist': 'Continuous',
            'adaptive_cost_free_rad': 'Periodic',
            'onetime_cost_free_rad': 'One-time',
            'baseline_cost_hist': 'Fixed',
            'NS3031': 'Initial guess',
        }
        CONTROLLER_ORDER = (
            'mhe_cost_free_rad_hist', 'adaptive_cost_free_rad',
            'baseline_cost_hist', 'NS3031',
        )
        LABELS = {
            'mhe_cost_free_rad_hist': 'Continuous',
            'adaptive_cost_free_rad': 'Periodic',
            'baseline_cost_hist': 'Fixed',
            'NS3031': 'Initial guess',
        }

        #if alpha_bool:
        CONTROLLER_ORDER = [controller + suffix for controller in CONTROLLER_ORDER]
        _LABELS = {}
        for k, v in LABELS.items():
            _LABELS[k + suffix] = v
        LABELS = _LABELS

        fig, res = sensitivity_figure(
            coords,
            EVENT.time,
            grid_points=10,
            progress_every=10,
            strict=False,
            controller_order=CONTROLLER_ORDER,
            labels=LABELS,
            alpha=alpha_bool
        )
        """
        save(
            fig,
            "sensitivity.pdf",
        )
        """
        save(
            fig,
            alpha + "_" + point + "_sensitivity.pdf"
        )
        (OUTPUT_DIR / 'selection.json').write_text(json.dumps({
            'base_config': BASE_CONFIG, 'meta_config': META_CONFIG,
            'results_dir': RESULTS_DIR,
            'evaluation_start': str(START), 'evaluation_stop': str(STOP),
            'event_name': EVENT.name, 'event_time': str(EVENT.time),
            'event_reason': EVENT.reason,
            'ranking_criterion': '6h trailing rolling mean, max-min across controllers, active > 0.05',
            'controller_names': list(coords),
        }, indent=2))
        print(f'Figures and selection metadata written to {OUTPUT_DIR}')


if __name__ == '__main__':
    main()
