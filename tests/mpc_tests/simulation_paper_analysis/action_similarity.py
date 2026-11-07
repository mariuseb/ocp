"""Analysis and plotting of realized MPC valve-action similarity.

All actions must be normalized to [0, 1]. Each DataFrame has a DatetimeIndex
and one column per controller. Pairs are compared at common timestamps.
"""
from itertools import combinations

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


def pairwise_action_distance(actions: pd.DataFrame, active_threshold=None) -> pd.DataFrame:
    """Mean absolute valve-action differences for all controller pairs.

    When active_threshold is set, retain times when either controller is active.
    """
    names = list(actions.columns)
    distances = pd.DataFrame(np.nan, index=names, columns=names, dtype=float)
    for a in names:
        distances.loc[a, a] = 0.0
    for a, b in combinations(names, 2):
        pair = actions[[a, b]].dropna()
        if active_threshold is not None:
            pair = pair[(pair[a] > active_threshold) | (pair[b] > active_threshold)]
        d = (pair[a] - pair[b]).abs().mean()
        distances.loc[a, b] = distances.loc[b, a] = d
    return distances


def plot_action_similarity(regimes: dict, active_threshold=None, figsize=None, vmax=None):
    """Plot one pairwise distance matrix per regime, with a shared color scale."""
    if not regimes:
        raise ValueError('At least one price regime is required.')
    matrices = {name: pairwise_action_distance(df, active_threshold)
                for name, df in regimes.items()}
    n = len(matrices)
    fig, axes = plt.subplots(1, n, figsize=figsize or (4.7*n, 4.5),
                             squeeze=False, constrained_layout=True)
    axes = axes.ravel()
    if vmax is None:
        values = np.concatenate([m.to_numpy().ravel() for m in matrices.values()])
        finite = values[np.isfinite(values)]
        vmax = max(float(finite.max()) if len(finite) else 0.0, 0.01)
    for ax, (name, matrix) in zip(axes, matrices.items()):
        im = ax.imshow(matrix.to_numpy(), cmap='viridis', vmin=0, vmax=vmax)
        labels = list(matrix.columns)
        ax.set_xticks(range(len(labels)), labels, rotation=40, ha='right')
        ax.set_yticks(range(len(labels)), labels)
        ax.set_title(name)
        for i in range(len(labels)):
            for j in range(len(labels)):
                v = matrix.iat[i, j]
                if np.isfinite(v):
                    ax.text(j, i, f'{v:.3f}', ha='center', va='center',
                            color='white' if v > 0.5*vmax else 'black', fontsize=9)
    fig.colorbar(im, ax=list(axes), shrink=0.75,
                 label='Mean absolute valve-opening difference [-]')
    return fig, axes


def plot_rolling_action_disagreement(actions: pd.DataFrame, window='7D',
                                     reference='NS3031', figsize=(10, 4)):
    """Rolling pairwise action MAE relative to one reference controller."""
    if reference not in actions.columns:
        raise ValueError(f'Reference {reference!r} not found: {list(actions.columns)}')
    #if not isinstance(actions.index, pd.DatetimeIndex):
    #    raise TypeError('A DatetimeIndex is required for time-based rolling windows.')
    actions = actions.sort_index()
    fig, ax = plt.subplots(figsize=figsize)
    for name in actions.columns:
        if name == reference:
            continue
        diff = (actions[name] - actions[reference]).abs()
        ax.plot(diff.rolling(window, min_periods=1).mean(), label=name, linewidth=1.7)
    ax.set(xlabel='Time', ylabel='Mean absolute valve-opening difference [-]',
           title=f'Rolling disagreement relative to {reference} ({window})')
    ax.grid(alpha=0.2)
    ax.legend(frameon=False)
    fig.tight_layout()
    return fig, ax


def action_similarity_summary(regimes: dict, active_threshold=0.05,
                              agreement_tolerance=0.10) -> pd.DataFrame:
    """Summarize full-year and active-period disagreement for each pair."""
    rows = []
    for regime, actions in regimes.items():
        for a, b in combinations(actions.columns, 2):
            pair = actions[[a, b]].dropna()
            diff = (pair[a] - pair[b]).abs()
            active = (pair[a] > active_threshold) | (pair[b] > active_threshold)
            rows.append(dict(regime=regime, controller_a=a, controller_b=b,
                             n_samples=len(pair), MAE_all=diff.mean(),
                             MAE_active=diff.loc[active].mean(),
                             agreement_fraction=(diff <= agreement_tolerance).mean(),
                             active_fraction=active.mean()))
    return pd.DataFrame(rows)
