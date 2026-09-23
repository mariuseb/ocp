import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D


# =====================================================================
# Semantic colour scheme
# =====================================================================

C_TI = "tab:orange"
C_CONTEXT = "tab:green"
C_COST = "goldenrod"
C_PRAD = "r"
C_VALVE = "b"
C_SOLAR = "m"
C_BOUND = "k"
C_TK = "k"


CONTROLLER_NAMES = {
    "mhe_cost_free_rad_hist": "Continuous adaptation",
    "adaptive_cost_free_rad": "Periodic adaptation",
    "baseline_cost_hist": "Fixed model",
}


# =====================================================================
# Result preparation
# =====================================================================

def _prepare_res(coord, start=None, stop=None):

    res = coord.res
    res.index = res.dt_index

    if not hasattr(coord.res, "Prad_calc"):
        res = coord.modify_res_obj(coord.res)
    else:
        res = coord.res

    res.index = res.dt_index

    if start is None:
        start = res.index[0]

    if stop is None:
        stop = res.index[-1]

    return res.loc[start:stop]


# =====================================================================
# Timedelta tick formatting
# =====================================================================

def _set_elapsed_time_ticks(
    axes,
    start,
    stop,
    interval="12h",
):

    first_tick = start.ceil("6h")

    elapsed_ticks = pd.timedelta_range(
        start=first_tick,
        end=stop,
        freq=interval,
    )

    labels = [
        f"Day {td.days}\n"
        f"{td.components.hours:02d}:{td.components.minutes:02d}"
        for td in elapsed_ticks
    ]

    fractions = [
        (td - start) / (stop - start)
        for td in elapsed_ticks
    ]

    for ax in axes:

        xmin, xmax = ax.get_xlim()

        tick_positions = [
            xmin + frac * (xmax - xmin)
            for frac in fractions
        ]

        ax.set_xticks(tick_positions)
        ax.set_xticklabels(labels)


def _elapsed_to_axis_x(ax, value, start, stop):
    """Map a Timedelta onto the current numeric x-axis coordinates."""
    xmin, xmax = ax.get_xlim()
    frac = (value - start) / (stop - start)
    return xmin + frac * (xmax - xmin)

# =====================================================================
# Publication operating-point plot
# =====================================================================

def plot_operating_context(
    read_coords,
    start=None,
    stop=None,
    operating_point=None,
    sampling="15min",
    filename=None,
    controller_names=None,
    figsize=(10.5, 7.5),
):

    if controller_names is None:
        controller_names = CONTROLLER_NAMES

    results = {
        key: _prepare_res(
            coord,
            start=start,
            stop=stop,
        )
        for key, coord in read_coords.items()
    }

    if len(results) != 3:
        raise ValueError(
            "This figure currently expects exactly three controllers."
        )

    # =================================================================
    # Figure layout
    # =================================================================

    fig = plt.figure(figsize=figsize)

    gs = fig.add_gridspec(
        nrows=4,
        ncols=2,
        height_ratios=[0.70, 1.0, 1.0, 1.0],
        hspace=0.15,
        wspace=0.42,
    )

    ax_weather = fig.add_subplot(gs[0, 0])
    ax_price = fig.add_subplot(gs[0, 1])

    thermal_axes = []
    prad_axes = []
    valve_axes = []

    for row in range(3):

        if row == 0:

            ax_T = fig.add_subplot(
                gs[row + 1, 0],
                sharex=ax_weather,
            )

            ax_u = fig.add_subplot(
                gs[row + 1, 1],
                sharex=ax_price,
            )

        else:

            ax_T = fig.add_subplot(
                gs[row + 1, 0],
                sharex=thermal_axes[0],
                sharey=thermal_axes[0],
            )

            ax_u = fig.add_subplot(
                gs[row + 1, 1],
                sharex=valve_axes[0],
                sharey=valve_axes[0],
            )

        ax_P = ax_T.twinx()

        thermal_axes.append(ax_T)
        prad_axes.append(ax_P)
        valve_axes.append(ax_u)

    # =================================================================
    # Weather
    # =================================================================

    res_context = next(iter(results.values()))

    Ta = (
        res_context.Ta
        .resample(rule=sampling)
        .mean()
    )

    Ta.plot(
        ax=ax_weather,
        drawstyle="steps-post",
        color=C_CONTEXT,
        linewidth=1.3,
        legend=False,
    )

    ax_weather.set_ylabel(
        r"$T_a$ [°C]",
        color=C_CONTEXT,
    )

    ax_weather.tick_params(
        axis="y",
        colors=C_CONTEXT,
    )

    ax_solar = ax_weather.twinx()

    solar = (
        res_context.phi_s
        .resample(rule=sampling)
        .mean()
    )

    solar.plot(
        ax=ax_solar,
        drawstyle="steps-post",
        color=C_SOLAR,
        linewidth=1.1,
        legend=False,
    )

    ax_solar.set_ylabel(
        r"$I_{\mathrm{sol}}$ [W/m$^2$]",
        color=C_SOLAR,
    )

    ax_solar.tick_params(
        axis="y",
        colors=C_SOLAR,
    )

    ax_weather.set_title(
        "Weather",
        fontsize=10,
    )

    # =================================================================
    # Economic conditions
    # =================================================================

    cost = (
        res_context.cost
        .resample(rule=sampling)
        .mean()
    )

    cost.plot(
        ax=ax_price,
        drawstyle="steps-post",
        color=C_COST,
        linewidth=1.3,
        legend=False,
    )

    ax_price.set_ylabel(
        "Economic signal",
        color=C_COST,
    )

    ax_price.tick_params(
        axis="y",
        colors=C_COST,
    )

    ax_price.set_title(
        "Economic conditions",
        fontsize=10,
    )
    
    for ax_u in valve_axes:
        ax_u.set_zorder(10)
        ax_u.patch.set_visible(False)

    # =================================================================
    # Controller rows
    # =================================================================

    for row, (key, res) in enumerate(results.items()):

        name = controller_names.get(key, key)

        ax_T = thermal_axes[row]
        ax_P = prad_axes[row]
        ax_u = valve_axes[row]

        # -------------------------------------------------------------
        # Thermal response
        # -------------------------------------------------------------

        Ti = (
            res.Ti
            .resample(rule=sampling)
            .mean()
        )

        Ti_lb = (
            res.Ti_lb
            .resample(rule=sampling)
            .mean()
        )

        Ti_ub = (
            res.Ti_ub
            .resample(rule=sampling)
            .mean()
        )

        Prad = (
            res.Prad_calc
            .resample(rule=sampling)
            .mean()
        )

        Prad.plot(
            ax=ax_P,
            drawstyle="steps-post",
            color=C_PRAD,
            linestyle="-",
            linewidth=0.75,
            legend=False,
            zorder=1,
        )

        Ti.plot(
            ax=ax_T,
            drawstyle="steps-post",
            color=C_TI,
            linewidth=1.4,
            legend=False,
            zorder=4,
        )

        Ti_lb.plot(
            ax=ax_T,
            drawstyle="steps-post",
            color=C_BOUND,
            linestyle=":",
            linewidth=1.0,
            legend=False,
            zorder=3,
        )

        Ti_ub.plot(
            ax=ax_T,
            drawstyle="steps-post",
            color=C_BOUND,
            linestyle=":",
            linewidth=1.0,
            legend=False,
            zorder=3,
        )

        # Temperature axis above power axis
        ax_T.set_zorder(ax_P.get_zorder() + 1)
        ax_T.patch.set_visible(False)

        ax_T.set_ylabel(r"$T_i$ [°C]")

        ax_P.set_ylabel(
            r"$P_{\mathrm{rad}}$ [W]",
            color=C_PRAD,
        )

        ax_P.tick_params(
            axis="y",
            colors=C_PRAD,
        )

        ax_T.text(
            -0.20,
            0.5,
            name,
            transform=ax_T.transAxes,
            rotation=90,
            va="center",
            ha="center",
            fontsize=9,
            fontweight="bold",
        )

        # -------------------------------------------------------------
        # Control action
        # -------------------------------------------------------------

        valve = (
            res.rad_219
            .shift(-1)
            .resample(rule=sampling)
            .mean()
        )

        valve.plot(
            ax=ax_u,
            drawstyle="steps-post",
            color=C_VALVE,
            linestyle="--",
            linewidth=0.75,
            legend=False,
        )

        ax_u.set_ylim(0, 1.05)

        # -------------------------------------------------------------
        # Operating point
        # -------------------------------------------------------------

        if operating_point is not None:

            x_op = _elapsed_to_axis_x(
                ax_T,
                operating_point,
                start,
                stop,
            )

            ax_T.axvline(
                x_op,
                color=C_TK,
                linestyle="-",
                linewidth=1.5,
                zorder=10,
            )

            ax_u.axvline(
                x_op,
                color=C_TK,
                linestyle="-",
                linewidth=1.5,
                zorder=10,
            )

    # =================================================================
    # Force valve y-axis labels/ticks on LEFT for every row
    # =================================================================

    for ax_u in valve_axes:
        
        ax_u.set_ylabel(
            r"$u_{\mathrm{val}}$ [-]",
            color=C_VALVE,
        )

        ax_u.yaxis.set_label_position("left")
        ax_u.yaxis.tick_left()
        #ax_u.yaxis.set_label_coords(-0.12, 0.5)
        ax_u.minorticks_off()

        ax_u.set_ylim(0, 1.05)
        ax_u.set_yticks([0.0, 0.5, 1.0])
        ax_u.set_yticklabels(["0", "0.5", "1.0"])

        ax_u.tick_params(
            axis="y",
            colors=C_VALVE,
            labelleft=True,
            labelright=False,
        )

    # =================================================================
    # Operating point in context panels
    # =================================================================

    if operating_point is not None:

        x_op = _elapsed_to_axis_x(
            ax_T,
            operating_point,
            start,
            stop,
        )
        
        ax_weather.axvline(
            #operating_point,
            x_op,
            color=C_TK,
            linestyle="-",
            linewidth=1.5,
            zorder=10,
        )

        ax_price.axvline(
            #operating_point,
            x_op,
            color=C_TK,
            linestyle="-",
            linewidth=1.5,
            zorder=10,
        )

    # =================================================================
    # Titles
    # =================================================================

    thermal_axes[0].set_title(
        "Thermal response",
        fontsize=10,
    )

    valve_axes[0].set_title(
        "Control action",
        fontsize=10,
    )

    # =================================================================
    # X-axis
    # =================================================================

    primary_axes = (
        [ax_weather, ax_price]
        + thermal_axes
        + valve_axes
    )

    _set_elapsed_time_ticks(
        primary_axes,
        start=start,
        stop=stop,
        interval="12h",
    )

    for ax in primary_axes:
        ax.set_xlabel("")

    ax_weather.tick_params(
        axis="x",
        labelbottom=False,
    )

    ax_price.tick_params(
        axis="x",
        labelbottom=False,
    )

    for ax in thermal_axes[:-1]:
        ax.tick_params(
            axis="x",
            labelbottom=False,
        )

    # Keep only bottom-row x labels in control column
    for ax in valve_axes[:-1]:
        ax.tick_params(
            axis="x",
            labelbottom=False,
        )

    # =================================================================
    # Legends
    # =================================================================

    thermal_handles = [
        Line2D(
            [0], [0],
            color=C_TI,
            linewidth=1.4,
            label=r"$T_i$",
        ),
        Line2D(
            [0], [0],
            color=C_BOUND,
            linestyle=":",
            linewidth=1.0,
            label="Bounds",
        ),
        Line2D(
            [0], [0],
            color=C_PRAD,
            linestyle="-",
            linewidth=1.1,
            label=r"$P_{\mathrm{rad}}$",
        ),
    ]

    control_handles = [
        Line2D(
            [0], [0],
            color=C_VALVE,
            linestyle="--",
            linewidth=1.0,
            label=r"$u_{\mathrm{val}}$",
        ),
    ]

    thermal_axes[0].legend(
        handles=thermal_handles,
        loc="upper left",
        frameon=False,
        fontsize=8,
    )

    valve_axes[0].legend(
        handles=control_handles,
        loc="upper right",
        frameon=False,
        fontsize=8,
    )

    # =================================================================
    # Cleanup
    # =================================================================

    for ax in primary_axes:
        ax.grid(False)
        ax.spines["top"].set_visible(False)

    for ax in prad_axes:
        ax.grid(False)
        ax.spines["top"].set_visible(False)

    ax_solar.grid(False)
    ax_solar.spines["top"].set_visible(False)

    #fig.align_ylabels(thermal_axes)

    fig.subplots_adjust(
        left=0.14,
        right=0.88,
        bottom=0.09,
        top=0.95,
    )


    # =================================================================
    # Export
    # =================================================================

    if filename is not None:

        fig.savefig(
            filename,
            bbox_inches="tight",
        )

    return fig, {
        "weather": ax_weather,
        "solar": ax_solar,
        "price": ax_price,
        "thermal": thermal_axes,
        "power": prad_axes,
        "valve": valve_axes,
    }