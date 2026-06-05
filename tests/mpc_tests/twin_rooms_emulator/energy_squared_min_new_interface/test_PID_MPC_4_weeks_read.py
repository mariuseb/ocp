#from ast import Param
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
#import os
#from pathlib import Path
#from ocp.mpc_agent import MPCAgent
#from ocp.boptestGymEnv import BoptestGymEnv
#from ocp.customGymEnv import CustomGymEnv
from ocp.coordinator import Coordinator
import pandas as pd
from ocp.config import Config, traverse_dict
from utils import quick_plot
from pprint import pprint
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_2R2C.json")
    traverse_dict(
        cfg
    )
    
    # limits:
    start = pd.Timedelta('14 days 00:00:00')
    
    
    # make cfg differ from MPC run:
    cfg["control"] = "PID"
    coord_pid = Coordinator.read_result(cfg)
    quick_plot(coord_pid)
    kpis_pid = coord_pid.get_custom_kpis(start=start)
    # remove control:
    cfg.pop("control")
    # first, with 'old' params:
    cfg["controller"]["parameters"] = 'params_result/2R2C_params.csv'
    coord_mpc_old = Coordinator.read_result(cfg)
    quick_plot(coord_mpc_old)
    kpis_mpc_old = coord_mpc_old.get_custom_kpis(start=start)
    # then, with new params:
    cfg["controller"]["parameters"] = 'params_result/2R2C_params_jan.csv'
    coord_mpc = Coordinator.read_result(cfg)
    quick_plot(coord_mpc)
    kpis_mpc = coord_mpc.get_custom_kpis(start=start)
    
    cfg = Config()("coordinator_boptest_2R2C_adaptive_NL.json")
    traverse_dict(
        cfg
    )
    coord_ad_mpc = Coordinator.read_result(cfg)
    quick_plot(coord_ad_mpc)
    kpis_ad_mpc = coord_ad_mpc.get_custom_kpis(start=start)
    
    
    
    """
    Parameter plot:
    
    Plot parameter evolution against PRBS-params
    """
    p = coord_mpc.controller.p
    _params_PRBS = pd.Series(
        index=p,
        data=coord_mpc.controller.params,
    )
    hist = coord_ad_mpc.controller.params_history
    params_PRBS = pd.DataFrame(_params_PRBS).T
    params_PRBS.index = [hist.index[0]]
    for ndx in hist.index:
        params_PRBS.loc[ndx, :] = params_PRBS.iloc[0, :]
    
    fig, axes = plt.subplots(7,1, sharex=True, figsize=(10,12))
    for i, name in enumerate(p):
        hist[name].plot(
            ax=axes[i], 
            color="k", 
            linestyle="dashed",
            drawstyle="steps-post"
        )
        params_PRBS[name].plot(
            ax=axes[i], 
            color="k", 
            drawstyle="steps-post"
        )
        axes[i].set_title(name)
    plt.show()
    
    
    print("tail")