"""Load results once; extract plotting data without mutating coordinators."""
from copy import deepcopy
import pandas as pd
from ocp.config import Config
from ocp.coordinator import Coordinator


def load_coordinators(base_config, meta_config, results_dir='results_local', selected=None):
    base = Config()(base_config)
    meta = Config()(meta_config)
    names = list(meta) if selected is None else list(selected)
    missing = set(names) - set(meta)
    if missing:
        raise KeyError(f'Unknown controller configurations: {sorted(missing)}')
    result = {}
    for name in names:
        entry = meta[name]
        cfg = deepcopy(base)
        for key, value in entry.items():
            if key != 'cost':
                cfg['controller'][key] = value
        cfg['environment']['config']['maps']['r']['cost'] = entry['cost']
        result[name] = Coordinator.read_result(cfg, _path=results_dir)
    return result


def valve_trajectories(coordinators, valve='rad_219', shift=-1):
    """Match the control-to-time alignment used in the original scripts."""
    return pd.concat(
        {name: coord.res[valve].shift(shift).copy()
         for name, coord in coordinators.items()}, axis=1
    ).sort_index()


def one_step_metrics(coordinators, start=None, stop=None, slack_weight=1e2):
    """Existing objective-based prediction metrics, with cumulative sums reset at start."""
    from ocp.tests.mpc_tests.twin_rooms_emulator.energy_squared_min_new_interface.utils import one_step_cost_pred
    return {
        name: one_step_cost_pred(coord, start=start, stop=stop,
                                 slack_weight=slack_weight)
        for name, coord in coordinators.items()
    }
