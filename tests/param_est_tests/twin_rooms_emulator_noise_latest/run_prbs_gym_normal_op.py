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
    prbs = prbs.Ph
    prbs = prbs.round(0)
    prbs = prbs.resample(sampling_time).first()
    prbs.index = range(len(prbs.index))
    # baseline control for sysid:
    N = len(prbs)
    return prbs, N
    

if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_normal_op.json")
    traverse_dict(
        cfg
    )
    coord = Coordinator(
        # "coordinator_boptest.json"
        cfg
    )
    env = coord.env
    sampling_time = "15min"
    dt = int(sampling_time.strip("min"))*60
    
    prbs, N = prepare_prbs(
        "PRBS_modified.csv", sampling_time=sampling_time
    )
    obs, _ = env.reset()
    meas = env.measurement_vars+env.predictive_vars
    acts = env.actions
    
    M = 24*56 #
    M = 7*96 
    #M = 10
    res = pd.DataFrame(
        columns=acts+meas,
        index=range(M)
    )
    res.loc[0, meas] = obs
    res.loc[:] = np.nan
    
    for n in range(M):
        action = pd.DataFrame(data=[None]).iloc[0]
        #res.loc[n, acts] = float(action.iloc[0])
        obs, reward, terminated, truncated, info = env.step(action)
        
    # map to OCP-names:
    res_ocp = res.rename(
        columns=env.maps.boptest_to_ocp
    )
    res_ocp.index *= dt
    res_ocp.index = pd.to_timedelta(
        res_ocp.index, unit="s"
    )
    
    _res = env.get_results(tf=M*dt) 
    _res["rad_219"] = _res.rad_219.shift(-1)
    _res["Prad"] = _res.Prad.shift(-1)
    _res["Prad_calc"] = (_res[["Qrad"]].diff(1)/1000)
    #_res.index = res_ocp.index
    #res_ocp[["Prad", "rad_flo"]] = res_ocp[["Prad", "rad_flo"]].shift(-1)
    #res_ocp["rad_219"] = _res["rad_219"].shift(-1)
    
    
    
    """
    res_ocp["rad_flo_calc"] = res_ocp["rad_flo_acc"].diff(1)/1000
    res_ocp["Prad_calc"] = (res_ocp[["Qrad"]].diff(1)/1000)
    res_ocp["Prad_calc_2"] = (res_ocp["Tsup"] - res_ocp["Tret"])*4200*res_ocp["rad_flo"]
    res_ocp[["Prad_calc", "Prad", "Prad_calc_2"]].plot(drawstyle="steps-post")
    plt.show()
    res_ocp["Prad_calc"] = res_ocp["Prad_calc"].shift(-1)
    res_ocp["rad_flo_calc"] = res_ocp["rad_flo_calc"].shift(-1)
    res_ocp.to_csv("twin_rooms_emulator_normal_op_%s.csv" % (sampling_time, ), index=True)
    _res.rad_219
    """
    
    _res.to_csv("twin_rooms_emulator_normal_op_%s.csv" % (sampling_time, ), index=True)
    
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    _res["Ti"].plot(ax=ax, drawstyle="steps-post")
    ax1 = ax.twinx()
    _res["Prad"].plot(ax=ax1, color="k", drawstyle="steps-post")
    _res["Prad_calc"].plot(ax=ax1, color="r", linestyle="dashed", drawstyle="steps-post")
    ax = axes[1]
    ax1 = ax.twinx()
    _res["Ta"].plot(ax=ax, color="g", drawstyle="steps-post")
    _res["rad_219"].plot(ax=ax1, color="k", drawstyle="steps-post")
    
    plt.show()
    
    print(res_ocp)
        
    
