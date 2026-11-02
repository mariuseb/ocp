"""One callable per figure type. No result loading or plt.show()."""
import matplotlib.pyplot as plt
import pandas as pd
import matplotlib.dates as mdates
from matplotlib.ticker import MaxNLocator


name_map = {
    "baseline_cost_hist": "Fixed",
    "adaptive_cost_free_rad": "Periodic",
    "mhe_cost_free_rad_hist": "Continuous",
    "onetime_cost_free_rad": "One-time",
    "NS3031": "Initial guess",
}

def policy_spread_distribution(controls, start, stop, window='6h', bins=20):
    from events import rank_policy_spread
    spread = rank_policy_spread(controls, start, stop, window=window)
    fig, ax = plt.subplots(figsize=(5, 3.3))
    ax.hist(spread, bins=bins, range=(0, 1))
    ax.set(xlabel=r'Policy spread $d_{\max}$', ylabel='Count')
    fig.tight_layout()
    return fig


def operating_context(coordinators, start, stop, operating_point,
                      sampling='15min'):
    from operating_context_updated import plot_operating_context
    # The existing function also accepts filename; we deliberately do not
    # pass it, so that saving is managed in one place by the runner.
    return plot_operating_context(
        coordinators, start=start, stop=stop,
        operating_point=operating_point, sampling=sampling,
    )


def cumulative_one_step_objective(metrics, controller_names=None):
    """Predicted vs realized objective terms, not EUR-denominated KPI costs."""
    names = list(metrics) if controller_names is None else controller_names
    fig, axes = plt.subplots(2, 1, figsize=(8, 5.5), sharex=True)
    for name in names:
        frame = metrics[name]
        axes[0].plot(frame.index, frame['cost_act_cum'], label=name)
        axes[1].plot(frame.index, frame['slack_act_cum'], label=name)
    axes[0].set_ylabel('Cumulative economic objective')
    axes[1].set_ylabel('Cumulative comfort objective')
    axes[1].set_xlabel('Time')
    fig.legend(loc='upper center', ncol=min(3, len(names)))
    fig.tight_layout(rect=(0, 0, 1, 0.92))
    return fig


def cumulative_one_step_objective(metrics, controller_names=None):
    objectives = [
        ("slack_act_cum", "Comfort"),
        ("cost_act_cum", "Economic"),
        ("total", "Total"),
    ]

    fig, axes = plt.subplots(
        1, 3, sharex=True, figsize=(10, 4)
    )
    names = list(name_map.keys())
    colors = {
        "Fixed": "#4D4D4D",
        "Periodic": "#0072B2",
        "Continuous": "#E69F00",
        "One-time": "#009E73",
        "Initial guess": "#CC79A7",
    }

    for ax, (column, title) in zip(axes, objectives):
        for name in names:
            label = name_map.get(name, name)
            frame = metrics[name]

            if column == "total":
                values = frame["slack_act_cum"] + frame["cost_act_cum"]
            else:
                values = frame[column]

            ax.plot(
                frame.index,
                values,
                drawstyle="steps-post",
                linewidth=1.8,
                color=colors.get(label),
                label=label,
            )

        ax.set_title(title)
        ax.xaxis.set_major_formatter(mdates.DateFormatter("%b"))
        ax.xaxis.set_major_locator(mdates.MonthLocator(interval=1))

    axes[0].set_ylabel("Cumulative scaled objective")

    handles, labels = axes[0].get_legend_handles_labels()

    fig.legend(
        handles,
        labels,
        ncol=5,
        loc="lower center",
        bbox_to_anchor=(0.5, 0.02),
    )

    fig.autofmt_xdate()
    fig.subplots_adjust(bottom=0.25, wspace=0.25)

    return fig


def cumulative_prediction_deviation(metrics, controller_names=None):
    names = list(metrics) if controller_names is None else controller_names
    fig, axes = plt.subplots(2, 1, figsize=(8, 5.5), sharex=True)
    for name in names:
        frame = metrics[name]
        axes[0].plot(frame.index, frame['cost_dev_abs_cum'], label=name)
        axes[1].plot(frame.index, frame['slack_dev_abs_cum'], label=name)
    axes[0].set_ylabel('Cumulative absolute cost-prediction deviation')
    axes[1].set_ylabel('Cumulative absolute comfort-prediction deviation')
    axes[1].set_xlabel('Time')
    fig.legend(loc='upper center', ncol=min(3, len(names)))
    fig.tight_layout(rect=(0, 0, 1, 0.92))
    return fig


def cumulative_errors_over_N(errors_by_N, controller_names=None):

    name_map = {
        "baseline_cost_hist": "Fixed",
        "adaptive_cost_free_rad": "Periodic",
        "mhe_cost_free_rad_hist": "Continuous",
        "onetime_cost_free_rad": "One-time",
        "NS3031": "Initial guess",
    }

    colors = {
        "Fixed": "#4D4D4D",
        "Periodic": "#0072B2",
        "Continuous": "#E69F00",
        "One-time": "#009E73",
        "Initial guess": "#CC79A7",
    }

    names = list(name_map) if controller_names is None else controller_names

    elems = {
        "temperature": "(a) Temperature",
        "slack": "(b) Comfort objective",
        "power": "(c) Power",
        "cost": "(d) Economic objective",
    }

    kwargs = {
        "drawstyle": "steps-post",
        "linewidth": 1.8,
    }

    fig, axes = plt.subplots(
        2, 2,
        sharex=True,
        sharey=False,
        figsize=(8, 6),
    )

    for (key, title), ax in zip(elems.items(), axes.flat):

        for name in names:
            label = name_map.get(name, name)

            errors_by_N[name][key].plot(
                ax=ax,
                color=colors[label],
                label=label,
                **kwargs,
            )

        ax.set_title(title)
        ax.set_xlabel("")
        ax.set_ylabel("")

    fig.supxlabel(r"Prediction horizon $N$")
    fig.supylabel("Cumulative prediction error")

    handles, labels = axes[0, 0].get_legend_handles_labels()

    fig.legend(
        handles,
        labels,
        loc="upper center",
        ncol=5,
        bbox_to_anchor=(0.5, 1.02),
    )

    fig.subplots_adjust(
        top=0.87,
        bottom=0.12,
        left=0.12,
        right=0.97,
        hspace=0.30,
        wspace=0.25,
    )

    return fig


def parameter_evolution(coordinators, parameters, names=None):
    names = list(coordinators) if names is None else names
    fig, axes = plt.subplots(len(parameters), 1, figsize=(8, 2 * len(parameters)),
                             sharex=True, squeeze=False)
    for ax, param in zip(axes[:, 0], parameters):
        for name in names:
            history = coordinators[name].controller.params_history
            if param in history:
                ax.step(history.index, history[param], where='post', label=name)
        ax.set_ylabel(param)
    fig.legend(loc='upper center', ncol=min(3, len(names)))
    fig.tight_layout(rect=(0, 0, 1, 0.95))
    return fig
