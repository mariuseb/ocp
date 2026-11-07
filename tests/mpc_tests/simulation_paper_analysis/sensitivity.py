"""Four-by-five MPC first-action sensitivity figure.

Use in run_month.py:
    from sensitivity import sensitivity_figure
    save(sensitivity_figure(coords, EVENT.time), 'sensitivity.pdf')

A nominal re-solve is checked against the stored control before any sweep.
Failures are reported rather than silently interpreted as zero control.
"""
from copy import deepcopy
import warnings

import matplotlib.pyplot as plt
from matplotlib.colors import BoundaryNorm
from matplotlib.cm import ScalarMappable
import numpy as np
import pandas as pd

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

# Sweep ranges are inferred jointly from all five controllers at the event.
# (x parameter, y parameter, x label, y label)
SWEEPS = (
    ('Ce', 'Ci', r'$C_e$ [J/K]', r'$C_i$ [J/K]'),
    ('Rea', 'Rie', r'$R_{ea}$ [K/W]', r'$R_{ie}$ [K/W]'),
    ('Te', 'Ti', r'$T_e$ [°C]', r'$T_i$ [°C]'),
    ('Prad_nom', 'n', r'$P_{\mathrm{rad,nom}}$ [W]', r'$n$ [-]'),
)
# Minimum half-width as a fraction of the median nominal value (positive parameters).
# These prevent nearly identical nominal estimates from collapsing the sweep.
MIN_REL_HALF_WIDTH = {
    'Ce': .50, 'Ci': .50, 'Rea': .50, 'Rie': .50,
    'Prad_nom': .50, 'n': .50,
}
# Physical lower bounds, where appropriate.
LOWER_BOUNDS = {
    'Ce': 1e-9, 'Ci': 1e-9, 'Rea': 1e-9, 'Rie': 1e-9,
    'Prad_nom': 1e-9, 'n': 1e-6,
}
LEVELS = [0, .025, .05, .1, .2, .3, .4, .5, .6, .7, .8, .9, 1]


def _origin_index(coord, event_time):
    index = coord.res.index
    if not isinstance(index, pd.TimedeltaIndex):
        index = coord.res.dt_index
    matches = np.flatnonzero(index == event_time)
    if len(matches) != 1:
        raise ValueError(f'Event {event_time}: expected one prediction origin, found {len(matches)}')
    i = int(matches[0])
    if i >= len(coord.controller.preds) or i >= len(coord.controller.forecasts):
        raise IndexError(f'No prediction/forecast for event index {i}')
    return i


def _context(coord, event_time):
    agent = coord.controller
    i = _origin_index(coord, event_time)
    pred = agent.preds[i]
    params = pred.loc[0, agent.p].astype(float).copy()
    x0 = pred.loc[0, ['Ti', 'Te']].to_numpy(dtype=float)
    forecast = deepcopy(agent.forecasts[i])
    lbx, ubx = agent.get_bounds_from_forecast(forecast)
    return dict(coord=coord, agent=agent, i=i, pred=pred, params=params,
                x0=x0, forecast=forecast, lbx=lbx, ubx=ubx)


def _solve(ctx, params, x0):
    agent = ctx['agent']
    lbu, ubu = agent.get_explicit_lb_ub_u()
    lbu, ubu = np.array(lbu, copy=True), np.array(ubu, copy=True)
    # This matches the original experiment. Check the control-vector layout
    # if your MPC input ordering changes.
    if 'Prad_nom' in params.index:
        ubu[0:-1:3] = float(params['Prad_nom']) / 2500.0
    sol, u_prime, _, raw = agent.mpc.solve(
        deepcopy(ctx['forecast']), x0=np.asarray(x0, dtype=float).copy(),
        lbx=deepcopy(ctx['lbx']), ubx=deepcopy(ctx['ubx']),
        ubu=ubu, lbu=lbu, params=params.copy(),
        codegen=agent.mpc.codegen, return_raw_sol=True, qp=False,
    )
    first = sol[agent.mpc.u_names].iloc[0]
    valve = float(agent.hammerstein_transform(first, params=params)['rad_219'])
    if not np.isfinite(valve):
        raise ValueError('Non-finite valve action')
    return valve


def _stored_valve(ctx, event_time, step=pd.Timedelta(minutes=15)):
    res = ctx['coord'].res
    # Original experiment compares against the action saved at t + one sample.
    index = res.index if isinstance(res.index, pd.TimedeltaIndex) else res.dt_index
    matches = np.flatnonzero(index == event_time + step)
    if len(matches) != 1:
        raise ValueError('Stored next-step valve action not found')
    return float(res['rad_219'].iloc[int(matches[0])])


def _common_grid(contexts, parameter, *, points=11, margin=.25,
                 state_half_width=1.0):
    """A single event-specific grid shared by all controller panels.

    All controllers use exactly the same grid. Nominal points are evaluated
    separately, not inserted into controller-specific grids.
    Temperatures are in kelvin here; conversion is only for axis labels.
    """
    if parameter in ('Te', 'Ti'):
        idx = 1 if parameter == 'Te' else 0
        nominal = np.array([c['x0'][idx] for c in contexts.values()], dtype=float)
        half_floor = state_half_width
    else:
        missing = [name for name, c in contexts.items()
                   if parameter not in c['params'].index]
        if missing:
            raise KeyError(f'{parameter} missing in controllers: {missing}')
        nominal = np.array([float(c['params'][parameter]) for c in contexts.values()])
        half_floor = MIN_REL_HALF_WIDTH[parameter] * abs(.5 * (nominal.min() + nominal.max()))
    if not np.isfinite(nominal).all():
        raise ValueError(f'Non-finite nominal {parameter}: {nominal}')
    spread = float(nominal.max() - nominal.min())
    half_width = max(.5 * spread * (1 + 2 * margin), half_floor)
    midpoint = .5 * (nominal.min() + nominal.max())
    lo, hi = midpoint - half_width, midpoint + half_width
    if parameter in LOWER_BOUNDS:
        lo = max(lo, LOWER_BOUNDS[parameter])
    if hi <= lo:
        raise ValueError(f'Invalid sweep bounds for {parameter}: {lo}, {hi}')
    return np.linspace(lo, hi, points)


def _nominal_xy(ctx, first, second):
    if (first, second) == ('Te', 'Ti'):
        return float(ctx['x0'][1]), float(ctx['x0'][0])
    p = ctx['params']
    missing = [name for name in (first, second) if name not in p.index]
    if missing:
        raise KeyError(f'Missing parameters {missing} in model; cannot sweep this pair')
    return float(p[first]), float(p[second])


def _sweep(ctx, first, second, xs, ys, *, controller_name, strict=True, progress=None, results_df=None, u_nominal=np.nan):
    nominal_x, nominal_y = _nominal_xy(ctx, first, second)
    Z = np.full((len(ys), len(xs)), np.nan)
    failures = []
    for j, y in enumerate(ys):
        for i, x in enumerate(xs):
            params = ctx['params'].copy()
            x0 = ctx['x0'].copy()
            if (first, second) == ('Te', 'Ti'):
                x0[:] = [y, x]  # solver state ordering [Ti, Te]
            else:
                params.loc[first], params.loc[second] = x, y
            error = None
            try:
                Z[j, i] = _solve(ctx, params, x0)
            except Exception as exc:
                error = str(exc)
                failures.append((float(x), float(y), error))
            finally:
                if results_df is not None:
                    u = float(Z[j, i])
                    results_df.loc[len(results_df)] = dict(
                        controller=controller_name, sweep=f'{first}/{second}',
                        x_name=first, y_name=second,
                        x_value=float(x), y_value=float(y),
                        u_star=u, u_nominal=u_nominal,
                        delta_u=u-u_nominal,
                        is_nominal=False, success=error is None,
                        error=error,
                    )
                if progress is not None:
                    progress["done"] += 1
                    done = progress["done"]
                    if done == 1 or done % progress["every"] == 0 or done == progress["total"]:
                        print(f'Sensitivity: {done:5d} / {progress["total"]} '
                              f'({100 * done / progress["total"]:5.1f}%) | '
                              f'{first}/{second} | {LABELS.get(controller_name, controller_name)}',
                              flush=True)
    if failures:
        message = (f'{controller_name} {first}/{second}: {len(failures)} of '
                   f'{Z.size} solves failed; first: {failures[0]}')
        if strict:
            raise RuntimeError(message)
        warnings.warn(message)
    return xs, ys, Z, (nominal_x, nominal_y)


def sensitivity_figure(coords, event_time, *, figsize=(17, 11),
                       state_delta=1.0, grid_points=11, range_margin=.25,
                       controller_order=None, labels=None, nominal_tolerance=1e-3,
                       strict=True, sample=pd.Timedelta(minutes=15),
                       progress_every=50, results_df=None, alpha=False):
    """Re-solve and plot first-action policy sensitivity, 4 rows x 5 columns.

    strict=True raises on nominal mismatches, missing parameters, and failed
    solves. Set strict=False only for diagnosing incomplete surfaces.

    Returns (fig, results_df), where results_df contains nominal and sweep
    solves, including failures. Optionally pass an existing DataFrame to
    populate it in-place during computation (e.g. for breakpoint inspection).
    """
    """
    if alpha:
        CONTROLLER_ORDER = [controller + "_alpha" for controller in CONTROLLER_ORDER]
        _LABELS = {}
        for k, v in LABELS.items():
            _LABELS[k + "_alpha"] = v
        LABELS = _LABELS
    """

    if results_df is None:
        results_df = pd.DataFrame()
    if results_df is not None:
        if not isinstance(results_df, pd.DataFrame):
            raise TypeError('results_df must be a pandas DataFrame or None')
        columns = ['controller', 'sweep', 'x_name', 'y_name', 'x_value',
                   'y_value', 'u_star', 'u_nominal', 'delta_u',
                   'is_nominal', 'success', 'error']
        results_df.drop(index=results_df.index, inplace=True)
        for column in columns:
            if column not in results_df.columns:
                results_df[column] = pd.Series(dtype='object')
    order = list(controller_order or CONTROLLER_ORDER)
    missing = [name for name in order if name not in coords]
    if missing:
        raise KeyError(f'Controllers not loaded: {missing}')
    contexts = {name: _context(coords[name], event_time) for name in order}

    # Mandatory nominal equivalence check before evaluating any sweep.
    nominal_actions = {}
    for name, ctx in contexts.items():
        recomputed = _solve(ctx, ctx['params'], ctx['x0'])
        stored = _stored_valve(ctx, event_time, sample)
        nominal_actions[name] = recomputed
        if results_df is not None:
            results_df.loc[len(results_df)] = dict(
                controller=name, sweep='nominal', x_name=None, y_name=None,
                x_value=np.nan, y_value=np.nan,
                u_star=recomputed, u_nominal=recomputed, delta_u=0.0,
                is_nominal=True, success=True, error=None,
            )
        difference = abs(recomputed - stored)
        print(f'{LABELS.get(name,name):14s}: stored={stored:.6f}, '
              f're-solved={recomputed:.6f}, |difference|={difference:.3g}')
        if difference > nominal_tolerance:
            message = (f'{name}: nominal MPC re-solve differs from stored '
                       f'action by {difference:.6g}. Check time alignment, '
                       'initial state, solver settings, bounds and forecast.')
            if strict:
                raise ValueError(message)
            warnings.warn(message)

    grids = {
        parameter: _common_grid(
            contexts, parameter, points=grid_points,
            margin=range_margin, state_half_width=state_delta,
        )
        for parameter in {p for row in SWEEPS for p in row[:2]}
    }
    for parameter in sorted(grids):
        print(f'{parameter}: sweep [{grids[parameter][0]:.6g}, '
              f'{grids[parameter][-1]:.6g}] ({grid_points} common points)')
    total = len(order) * sum(len(grids[first]) * len(grids[second])
                             for first, second, _, _ in SWEEPS)
    progress = dict(done=0, total=total, every=max(1, int(progress_every)))
    print(f'Starting {total} sensitivity solves across {len(order)} controllers.', flush=True)
    fig, axes = plt.subplots(4, len(order), figsize=figsize, squeeze=False)
    cmap = plt.get_cmap('viridis')
    norm = BoundaryNorm(LEVELS, cmap.N, clip=True)
    labels = labels or LABELS
    for col, name in enumerate(order):
        axes[0, col].set_title(LABELS.get(name, name), fontsize=11)

    #order = ['onetime_cost_free_rad']

    for row, (first, second, xlabel, ylabel) in enumerate(SWEEPS):
        xs, ys = grids[first], grids[second]
        for col, name in enumerate(order):
            ax = axes[row, col]
            ctx = contexts[name]
            xx, yy, z, (mx, my) = _sweep(
                ctx, first, second, xs, ys,
                controller_name=name, strict=strict, progress=progress,
                results_df=results_df, u_nominal=nominal_actions[name],
            )
            # Verify the nominal action independently; do not modify the
            # common sweep grid by inserting controller-specific coordinates.
            nominal_again = _solve(ctx, ctx['params'], ctx['x0'])
            if not np.isclose(nominal_again, nominal_actions[name], atol=1e-6, rtol=0):
                message = f'{name} {first}/{second}: nominal re-solve inconsistent'
                if strict:
                    raise AssertionError(message)
                warnings.warn(message)
            if first == 'Te':
                xx, mx = xx-273.15, mx-273.15
            if second == 'Ti':
                yy, my = yy-273.15, my-273.15
            X, Y = np.meshgrid(xx, yy)
            """
            """
            print("Is z NaN?: " +  str(np.isnan(z).sum()))
            """
            mesh = ax.pcolormesh(
                X, Y, z,
                cmap="viridis",
                vmin=0,
                vmax=1,
                shading="nearest",
            )
            ax.scatter(
                X, Y,
                s=5,
                c="white",
                alpha=0.5,
            )
            """
            z_plot = np.clip(z, 0.0, 1.0)
            ax.contourf(
                #X, Y, np.ma.masked_invalid(z), 
                X, Y, z_plot, 
                levels=LEVELS, cmap=cmap, norm=norm
            )
            ax.scatter(mx, my, s=26, facecolor='white', edgecolor='black',
                       linewidth=.85, zorder=5)
            ax.set_xlabel(xlabel, fontsize=9)
            if col == 0:
                ax.set_ylabel(ylabel, fontsize=9)
            ax.tick_params(labelsize=8)

    fig.subplots_adjust(left=.065, right=.895, bottom=.07, top=.95,
                        wspace=.34, hspace=.57)
    cax = fig.add_axes([.915, .18, .015, .64])
    sm = ScalarMappable(norm=norm, cmap=cmap)
    cb = fig.colorbar(sm, cax=cax, ticks=[0, .25, .5, .75, 1])
    #cb = fig.colorbar(mesh, cax=cax, ticks=[0, .25, .5, .75, 1])
    cb.set_label(r'Optimal valve opening $u_{\mathrm{val}}^\star$ [-]')
    return fig, results_df