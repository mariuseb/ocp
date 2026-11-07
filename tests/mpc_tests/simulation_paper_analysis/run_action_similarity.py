"""Run valve-action similarity analysis on one CSV file per execution.

Expected CSV format (wide): timestamp, Continuous, Periodic, Fixed, Initial guess
Each controller column contains realized valve opening in [0, 1].

Run: python run_action_similarity.py --regime alpha
Or:  python run_action_similarity.py --regime non_alpha
"""
import argparse
from pathlib import Path

import pandas as pd

from action_similarity import (
    action_similarity_summary,
    plot_action_similarity,
    plot_rolling_action_disagreement,
)


def read_controls(path: Path, time_column=None) -> pd.DataFrame:
    """Read a wide CSV, using the first column as timestamps by default."""
    raw = pd.read_csv(path, index_col=0)
    raw.index = pd.to_timedelta(raw.index)
    return raw


def main(regime='alpha', data_dir='.', output_dir='action_similarity_figures',
         reference='Fixed', window='7D', active_threshold=0.05,
         time_column=None):
    """Analyze one price regime per run: 'alpha' or 'non_alpha'."""
    import matplotlib.pyplot as plt

    if regime not in ('alpha', 'non_alpha'):
        raise ValueError("regime must be 'alpha' or 'non_alpha'")

    data_dir = Path(data_dir)
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    actions = read_controls(data_dir / f'controls_{regime}.csv', time_column)
    regimes = {regime: actions}

    fig, _ = plot_action_similarity(regimes)
    fig.savefig(output_dir / f'action_similarity_all_{regime}.pdf', bbox_inches='tight')
    plt.close(fig)

    fig, _ = plot_action_similarity(regimes, active_threshold=active_threshold)
    fig.savefig(output_dir / f'action_similarity_active_{regime}.pdf', bbox_inches='tight')
    plt.close(fig)

    """
    actions.index = pd.to_datetime(
        actions.index, 
        origin="2024-01-01",
        freq="15min"
    )
    """
    fig, _ = plot_rolling_action_disagreement(actions, window=window, reference="baseline_cost_hist")
    fig.savefig(output_dir / f'rolling_disagreement_{regime}.pdf', bbox_inches='tight')
    plt.close(fig)

    summary = action_similarity_summary(regimes, active_threshold=active_threshold)
    summary.to_csv(output_dir / f'action_similarity_summary_{regime}.csv', index=False)
    print(summary.round(3).to_string(index=False))
    print(f'\nSaved results to {output_dir.resolve()}')
    return summary


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--regime', choices=['alpha', 'non_alpha'], default='non_alpha')
    parser.add_argument('--data-dir', default='.')
    parser.add_argument('--output-dir', default='action_similarity_figures')
    parser.add_argument('--reference', default='NS3031')
    parser.add_argument('--window', default='7D')
    parser.add_argument('--active-threshold', type=float, default=0.05)
    parser.add_argument('--time-column', default=None)
    args = parser.parse_args()
    main(**vars(args))
