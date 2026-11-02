"""Deterministic discovery, and explicit freezing, of operating points."""
from dataclasses import dataclass
import pandas as pd


@dataclass(frozen=True)
class Event:
    name: str
    time: pd.Timedelta
    reason: str


def rank_policy_spread(controls, start, stop, window='6h',
                       active_threshold=0.05, morning=None,
                       require_interior=False):
    """Rank timestamps by smoothed cross-controller valve spread.

    Assumes a TimedeltaIndex, as in the original coordinator results.
    Rolling uses the preceding window (not a centered window).
    Ties are resolved chronologically for reproducibility.
    """
    frame = controls.loc[start:stop].dropna(how='any')
    if frame.empty:
        raise ValueError('No aligned control data in the requested interval')
    smoothed = frame.rolling(window, min_periods=1).mean()
    spread = smoothed.max(axis=1) - smoothed.min(axis=1)
    mask = smoothed.max(axis=1) > active_threshold
    if morning is not None:
        first_hour, last_hour = morning
        hours = frame.index.components.hours
        mask &= (hours >= first_hour) & (hours <= last_hour)
    if require_interior:
        mask &= ((frame > 0.2) & (frame < 0.8)).any(axis=1)
    ranked = pd.DataFrame({'spread': spread[mask]})
    ranked['time'] = ranked.index
    return ranked.sort_values(['spread', 'time'], ascending=[False, True])['spread']


def event_from_rank(ranking, rank=0, offset='0min', name='selected', reason=''):
    if rank >= len(ranking):
        raise IndexError(f'Rank {rank} not available ({len(ranking)} candidates)')
    return Event(name, ranking.index[rank] + pd.Timedelta(offset), reason)
