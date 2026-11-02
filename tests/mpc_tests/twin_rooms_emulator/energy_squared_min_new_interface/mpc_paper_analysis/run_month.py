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
META_CONFIG = 'config_meta_mhe_baseline_adaptive_onetime_fixed_no_alpha.json'
RESULTS_DIR = 'results_local'
OUTPUT_DIR = Path('paper_figures/month_test')
START = pd.Timedelta(days=14)
STOP = pd.Timedelta(days=28)

# Explicit event chosen for the paper; change only after inspecting ranking.
# Timestamp and rationale are saved alongside the figure.
EVENT = Event('morning_example', pd.Timedelta(days=20, hours=11, minutes=45),
              'Frozen example; verify against monthly controller trajectories')


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
    controls = valve_trajectories(coords)
    #ranking = rank_policy_spread(controls, START, STOP, window='6h')
    ranking = rank_policy_spread(controls, START, STOP, window='15min')
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    ranking.head(50).to_csv(OUTPUT_DIR / 'event_candidates.csv', header=['policy_spread'])

    policy_fig = policy_spread_distribution(controls, START, STOP)
    save(policy_fig, 'policy_spread.pdf')

    window_start = max(START, EVENT.time - pd.Timedelta(days=1))
    window_stop = min(STOP, EVENT.time + pd.Timedelta(days=2))
    op_fig, axes = operating_context(
        coords, window_start, window_stop, EVENT.time
    )
    save(op_fig, 'operating_context.pdf')

    metrics = one_step_metrics(
        coords, start=START, stop=STOP
    )
    save(
        cumulative_one_step_objective(metrics), 
        'cumulative_1_step_objective_deviation.pdf'
    )
    errors_by_N = prediction_errors_over_N(
        coords, start=START, stop=STOP
    )
    save(
        #cumulative_prediction_deviation(metrics), 
        cumulative_errors_over_N(errors_by_N), 
        'cumulative_errors_over_N.pdf'
    )
    fig, res = sensitivity_figure(
        coords,
        EVENT.time,
        grid_points=21,
        progress_every=10,
    )
    save(
        fig,
        "sensitivity.pdf",
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
