#%% 
#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.mpc import MPC

import numpy as np
import json
import casadi as ca
import ocp
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api_old import Boptest
from pprint import pprint
#from ocp.filters import EKF
from matplotlib import rc
from pprint import pprint
#from ocp.covar_solve import CovarianceSolver
import os
import matplotlib.pyplot as plt
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.functions import functions
#from ocp.nn import ParamDataset, NN
#import torch
from ocp.ocp import ParamGuess
from ocp.coordinator import Coordinator
from ocp.config import Config, traverse_dict 
#import l4casadi as l4c
from sklearn.metrics import root_mean_squared_error
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    
def prepare_prbs(path, sampling_time="15min"):
    prbs = pd.read_csv(path, sep=",", index_col=0)
    prbs.index = pd.to_timedelta(prbs.index)
    prbs.Ph /= 100
    prbs = prbs.round(0)
    prbs = prbs.resample(sampling_time).first()
    prbs.index = range(len(prbs.index))
    # baseline control for sysid:
    N = len(prbs)
    return prbs, N
    

if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest.json")
    traverse_dict(
        cfg
    )
    coord = Coordinator(
        # "coordinator_boptest.json"
        cfg
    )
    env = coord.env

    """
    prbs, N = prepare_prbs(
        "PRBS_modified.csv", sampling_time="15min"
    )
    """

    ove = pd.read_csv("ZEBLab_nov_dec_23_15m.csv", index_col=0)
    ove.index = pd.to_datetime(ove.index)
    ove["phi_h"] = ove["P_rad_219"]*1000
    ove["Ti_meas"] = ove[["T_219_TR1", "T_219_TR2", "T_219_TR3", "T_219_TR4"]].mean(axis=1)
    #ove["Ti_meas"] = ove[["T_219_TR3"]].mean(axis=1)
    ove = ove.loc[
        pd.Timestamp("2023-11-15 00:00:00+01:00"):
    ]
    # try 7 days, w/o warm-up, int gains, matching init. conds.:
    N = 96*21
    #N = 96

    obs, _ = env.reset()
    meas = env.measurement_vars+env.predictive_vars
    acts = [act.replace("_u", "") for act in env.actions]
    res = pd.DataFrame(
        columns=acts+meas,
        #index=range(N+1)
        index=ove.index
    )
    res.loc[:] = np.nan
    res.iloc[0][meas] = obs
    
    """
    Internal gains assumptions:
    \\[
    \\begin{aligned}
    Q_{\\mathrm{rad}} &= 0.25P_{\\mathrm{plug}}+0.40P_{\\mathrm{lighting}}\\
    Q_{\\mathrm{conv}} &= 0.75P_{\\mathrm{plug}}+0.60P_{\\mathrm{lighting}}\\
    Q_{\\mathrm{lat}} &= 0
    \\end{aligned}
    \\]
    """

    ove["int_gai_rad"] = (0.25*ove["phi_int_219_plugs"] + 0.4*ove["phi_int_219_lig"])/66.7
    ove["int_gai_con"] = (0.75*ove["phi_int_219_plugs"] + 0.6*ove["phi_int_219_lig"])/66.7
    ove["int_gai_lat"] = 0
    ove["m_flow_AHU_219"] = ove["V_sup_air_219"]*1.204/3600
    ove["T_sup_AHU_219"] = ove["T_sup_air_219"] + 273.15
    #ove["g_corr"] = ove["presence"]*100
    ove["g_corr"] = ove["presence"]*0
    ove["corr_temp"] = ove["T_207"] + 273.15
    #ove["int_gai_rad"] = 0
    #ove["int_gai_con"] = 0

    for n in range(N):
        hea = ove[["phi_h", "int_gai_rad", "int_gai_con", "int_gai_lat", "g_corr", "corr_temp"]].iloc[n]
        #hea = ove[["phi_h", "int_gai_lat"]].iloc[n]
        #hea = ove[["phi_h"]].iloc[n]
        #res.loc[n, acts] = hea.rename(env.maps.u)
        res.loc[res.index[n], acts] = hea.rename(env.maps.u)
        obs, reward, terminated, truncated, info = env.step(hea)
        #res.loc[n+1, meas] = obs
        res.loc[res.index[n+1], meas] = obs
        
        
    # map to OCP-names:
    res_ocp = res.rename(
        columns=env.maps.boptest_to_ocp
    )
    #res_ocp["Ti_meas"] = ove["T_219_TR3"][:N+1].values
    res_ocp["Ti_meas"] = np.nan
    res_ocp["phi_s_facade"] = np.nan
    res_ocp["T_207"] = np.nan
    res_ocp["Ti_meas"][:N+1] = ove["Ti_meas"][:N+1].values
    res_ocp["T_207"][:N+1] = ove["T_207"][:N+1].values
    res_ocp["phi_s_facade"][:N+1] = ove["I_ver"][:N+1].values
    res_ocp[["Ti", "Ta"]] -= 273.15

    """
    fig, axes = plt.subplots(3,1, sharex=True)
    ax = axes[0]
    res_ocp[["Ti", "Ti_meas", "T_207"]][:N+1].plot(drawstyle="steps-post", ax=ax)
    ax1 = ax.twinx()
    res_ocp[["oveHea"]][:N+1].plot(drawstyle="steps-post", ax=ax1, color="r")
    ax = axes[1]
    res_ocp[["Ta"]][:N+1].plot(drawstyle="steps-post", ax=ax, color="g")
    ax1 = ax.twinx()
    res_ocp[["phi_s_facade"]][:N+1].plot(drawstyle="steps-post", ax=ax1, color="y")
    ax = axes[2]
    (res_ocp[["floor5Zone_Shading_oveConGai219", "floor5Zone_Shading_oveRadGai219"]][:N+1]*66.7).plot(drawstyle="steps-post", ax=ax)
    #ax1 = ax.twinx()
    #res_ocp[["phi_s_facade"]][:N+1].plot(drawstyle="steps-post", ax=ax1, color="y")
    fig.savefig("emulator_validation.pdf")
    plt.show()
    """


    import matplotlib.pyplot as plt
    import matplotlib.dates as mdates

    df = res_ocp.iloc[:N+1]

    fig, axes = plt.subplots(
        3, 1,
        figsize=(11, 8),
        sharex=True,
        gridspec_kw={"height_ratios": [1.4, 1, 1]},
        constrained_layout=True
    )

    # --- 1. Indoor temperature and radiator heating ---
    ax = axes[0]

    ax.plot(df.index, df["Ti_meas"],
            color="black", linewidth=1.5, label="Measured indoor temperature")

    ax.plot(df.index, df["Ti"],
            color="tab:blue", linewidth=1.5, label="Simulated indoor temperature")

    ax.plot(df.index, df["T_207"],
            color="tab:gray", linewidth=1.1, linestyle="--",
            label="Corridor temperature")

    ax.set_ylabel("Temperature [°C]")

    ax2 = ax.twinx()
    ax2.plot(df.index, df["oveHea"],
            color="tab:red", linewidth=1.0, alpha=0.65,
            label="Radiator heating")
    ax2.set_ylabel("Heating power [W]")

    # Combined legend
    lines1, labels1 = ax.get_legend_handles_labels()
    lines2, labels2 = ax2.get_legend_handles_labels()
    ax.legend(lines1 + lines2, labels1 + labels2,
            loc="upper right", fontsize=9, frameon=True, ncol=4)


    # --- 2. Outdoor conditions ---
    ax = axes[1]

    ax.plot(df.index, df["Ta"],
            color="tab:green", linewidth=1.3,
            label="Outdoor temperature")

    ax.set_ylabel("Outdoor temperature [°C]")

    ax2 = ax.twinx()
    ax2.plot(df.index, df["phi_s_facade"],
            color="tab:orange", linewidth=1.0, alpha=0.8,
            label="Facade solar irradiance")

    ax2.set_ylabel("Solar irradiance [W/m²]")

    lines1, labels1 = ax.get_legend_handles_labels()
    lines2, labels2 = ax2.get_legend_handles_labels()
    ax.legend(lines1 + lines2, labels1 + labels2,
            loc="upper right", fontsize=9, ncol=2)


    # --- 3. Internal heat gains ---
    ax = axes[2]

    ax.plot(
        df.index,
        df["floor5Zone_Shading_oveConGai219"] * 66.7,
        color="tab:purple",
        linewidth=1.2,
        label="Convective gains"
    )

    ax.plot(
        df.index,
        df["floor5Zone_Shading_oveRadGai219"] * 66.7,
        color="tab:brown",
        linewidth=1.2,
        label="Radiative gains"
    )

    ax.set_ylabel("Internal gains [W]")
    ax.legend(loc="upper right", fontsize=9, ncol=2)


    # --- Common formatting ---
    for ax in axes:
        ax.grid(True, alpha=0.25, linewidth=0.6)
        ax.spines["top"].set_visible(False)
        ax.tick_params(axis="both", labelsize=9)

    axes[-1].xaxis.set_major_locator(mdates.DayLocator(interval=3))
    axes[-1].xaxis.set_major_formatter(mdates.DateFormatter("%d %b %Y"))
    axes[-1].set_xlabel("Date")

    for ax in fig.axes:
        for line in ax.get_lines():
            line.set_drawstyle("steps-post")

    fig.savefig("emulator_validation_no_door_average.pdf", bbox_inches="tight")
    plt.show()

    print("Whole period:")
    mbe = (res_ocp["Ti"] - res_ocp["Ti_meas"]).iloc[:N+1].mean()
    print(f"MBE = {mbe:.3f} °C")
    rmse = root_mean_squared_error(res_ocp["Ti_meas"].values[:N+1], res_ocp["Ti"].values[:N+1])
    print(f"RMSE = {rmse:.3f} °C")
    print("Last two weeks:")
    mbe = (res_ocp["Ti"] - res_ocp["Ti_meas"]).iloc[672:N+1].mean()
    print(f"MBE = {mbe:.3f} °C")
    rmse = root_mean_squared_error(res_ocp["Ti_meas"].values[672:N+1], res_ocp["Ti"].values[672:N+1])
    print(f"RMSE = {rmse:.3f} °C")


    res_ocp.index *= 900
    res_ocp.index = pd.to_timedelta(
        res_ocp.index, unit="s"
    )
    #res_ocp[["Prad", "rad_flo"]] = res_ocp[["Prad", "rad_flo"]].shift(-1)
    """
    res_ocp["rad_flo_calc"] = res_ocp["rad_flo_acc"].diff(1)/1000
    res_ocp["Prad_calc"] = (res_ocp[["Qrad"]].diff(1)/1000)
    res_ocp["Prad_calc_2"] = (res_ocp["Tsup"] - res_ocp["Tret"])*4200*res_ocp["rad_flo"]
    res_ocp[["Prad_calc", "Prad", "Prad_calc_2"]].plot(drawstyle="steps-post")
    plt.show()
    res_ocp["Prad_calc"] = res_ocp["Prad_calc"].shift(-1)
    res_ocp["rad_flo_calc"] = res_ocp["rad_flo_calc"].shift(-1)
    res_ocp[:-2].to_csv("twin_rooms_emulator_PRBS_new_15min.csv", index=True)
    """

    fig, axes = plt.subplots(2,1)
    ax = axes[0]
    res_ocp["Ti"].plot(ax=ax, drawstyle="steps-post")
    ax1 = ax.twinx()
    #res_ocp["Prad"].plot(ax=ax1, color="k", drawstyle="steps-post")
    ax = axes[1]
    res_ocp["Ta"].plot(ax=ax, color="g", drawstyle="steps-post")
    
    plt.show()

    print(res_ocp)
        
    
