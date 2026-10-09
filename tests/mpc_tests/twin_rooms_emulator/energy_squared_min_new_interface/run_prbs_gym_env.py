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
    #ove["Ti_meas"] = ove[["T_219_TR1", "T_219_TR2", "T_219_TR3", "T_219_TR4"]].mean(axis=1)
    ove["Ti_meas"] = ove[["T_219_TR3"]].mean(axis=1)
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
    #ove["int_gai_rad"] = 0
    #ove["int_gai_con"] = 0

    for n in range(N):
        hea = ove[["phi_h", "int_gai_rad", "int_gai_con", "int_gai_lat"]].iloc[n]
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

    fig, axes = plt.subplots(4,1, sharex=True)
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
    plt.show()

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
        
    
