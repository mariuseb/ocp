import os
import sys
import pathlib
import casadi as ca
import numpy as np
import pandas as pd
from ocp.estimation import Estimation
from prepare_data import AHU_map

REV_AHU_MAP = dict()
for k, v in AHU_map.items():
    for room in v:
        REV_AHU_MAP[room] = k


PARAM_GUESS = {
    "Rie": {"init": 1e-2},
    "Rea": {"init": 1e-1},
    "Ci": {"init": 1e6},
    "Ce": {"init": 1e6},
    "Ai": {"init": 10},
    "alpha_int": {"init": 1, "lb": 1e-3, "ub": 1.5},
    "alpha_vent": {"init": 1, "lb": 1e-3, "ub": 1},
    "phi_int_base": {"init": 1000, "lb": 100, "ub": 2000},
}
#CONFIG_PATH = "configs/2R2C_envelope_heating_Tsup_air.json"
CONFIG_PATH = "configs/2R2C_envelope_heating_Tsup_air.json"


def load_room_data(
    room, 
    occupancy_path=None, 
    airflow_path=None
):
    """Load and preprocess one room's master dataset once.

    Optional auxiliary CSVs support the old split-file data layout.
    Prefer storing these signals in the master dataset eventually.
    """
    path = os.path.join(
        "data_voldslokka", room + ".csv"
    )
    data = pd.read_csv(
        path, index_col=0, parse_dates=True
    ).sort_index()
    data = data.rename(columns={
        "Romtemperatur": "Ti",
        "Klimagulvventil": "phi_h",
        f"""+01={REV_AHU_MAP[room]}-RT404 Temperaturgiver - Tilluft""": "Tsup_air",
    })

    for col in ("Ta", "Ti", "Tsup_air"):
        data[col] = data[col] + 273.15

    # Existing valve convention: percent opening -> nominal heating power (W).
    data["phi_h"] = data["phi_h"] * 20

    if occupancy_path is not None:
        occupancy = pd.read_csv(occupancy_path, index_col=0, parse_dates=True)
        data = data.join(occupancy[["n_occ", "b_occ"]], how="left")
    else:
        data["phi_int"] = 0

    if airflow_path is not None:
        airflow = pd.read_csv(airflow_path, index_col=0, parse_dates=True)
        # Expects a single column of supply airflow in m3/h.
        data["m_flow_air"] = airflow.iloc[:, 0] * 1.204 / 3600
    else:
        data["m_flow_air"] = 0

    return data


def prepare_identification_data(
    data,
    start, 
    days=7, 
    sampling="15min"
):
    """Select and resample an identification interval."""
    start = pd.Timestamp(start)
    stop = start + pd.Timedelta(days=days)
    # Half-open interval avoids counting the boundary twice in adjacent windows.
    window = data.loc[(data.index >= start) & (data.index < stop)]
    if window.empty:
        raise ValueError(f"No data in identification window {start} to {stop}")

    y_data = window.resample(sampling).mean()
    y_data["y1"] = y_data["Ti"]
    if "n_occ" in y_data:
        y_data["phi_int"] = y_data["n_occ"] * 100

    required = ["Ti", "Ta", "Tsup_air", "phi_h", "y1", "phi_int", "m_flow_air"]
    missing = [col for col in required if col not in y_data]
    if missing:
        raise ValueError(f"Missing required identification signals: {missing}")
    if y_data[required].isna().any().any():
        counts = y_data[required].isna().sum()
        raise ValueError(f"NaNs in identification window:\n{counts[counts > 0]}")
    return y_data


def run_identification(
    y_data, 
    config=CONFIG_PATH, 
    param_guess=None,
    dt=900
):
    """Estimate parameters for one prepared window; return (solution, parameters)."""
    if param_guess is None:
        param_guess = PARAM_GUESS

    x_guess = np.array([
        y_data["Ti"].to_numpy(),
        y_data["Ti"].to_numpy() - 2,
    ])
    lbx = 0.7 * x_guess
    ubx = 2.0 * x_guess

    with Estimation(
        config=config,
        N=len(y_data),
        dt=dt,
        param_guess=param_guess,
        arrival_cost=True,
    ) as estimator:
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        P0 = np.zeros((estimator.n_p + estimator.n_x,) * 2)
        solution, params = estimator.solve(
            y_data,
            estimator.p0,
            lbp=estimator.get_lbp(1e-3),
            ubp=estimator.get_ubp(1e3),
            lbx=lbx,
            ubx=ubx,
            x_guess=x_guess,
            covar=ca.veccat(Q, R),
            codegen=False,
            P0=P0,
            x_N=x_guess[-1, -estimator.n_x:],
        )
    solution.index = y_data.index
    return solution, params


def validate_model(data, params, start, days=7):
    """TODO: forward simulate with fitted params and compute validation RMSE."""
    raise NotImplementedError("Connect your forward simulation interface here")


def run_windows(data, starts, identification_days=7, validation_start=None,
                validation_days=7):
    """Run independent identification windows and collect fitted parameters."""
    results = {}

    for start in starts:
        y_data = prepare_identification_data(data, start, days=identification_days)
        solution, params = run_identification(y_data)

        result = {"solution": solution, "params": params}
        if validation_start is not None:
            result["rmse"] = validate_model(
                data, params, validation_start, days=validation_days
            )
        results[pd.Timestamp(start)] = result

    return results


if __name__ == "__main__":
    data = load_room_data(
        "20001"
        #occupancy_path="CO2_results.csv",
        # Supply-air flow can instead be supplied in the master dataset.
    )

    starts = [
        "2026-02-04 12:00",
        "2026-02-11 12:00",
    ]

    results = run_windows(data, starts, identification_days=7)
    for start, result in results.items():
        print(start)
        print(result["params"])