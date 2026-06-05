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
from utils import quick_plot, plot_parameter_evolution, get_value_function_error
from pprint import pprint
rc('mathtext', default='regular')

kwargs = {
    "drawstyle": "steps-post",
    "linewidth": 0.75
}

if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_2R2C.json")
    traverse_dict(
        cfg
    )
    
    # limits:
    start = pd.Timedelta('90 days 00:00:00')
    
    cfg = Config()("coordinator_boptest_2R2C_adaptive_4_months.json")
    traverse_dict(
        cfg
    )
    coord_ad_mpc = Coordinator.read_result(cfg)
    quick_plot(coord_ad_mpc)
    kpis_ad_mpc = coord_ad_mpc.get_custom_kpis(start=start)
    
    cfg = Config()("coordinator_boptest_2R2C_4_months.json")
    traverse_dict(
        cfg
    )
    coord_mpc = Coordinator.read_result(cfg)
    quick_plot(coord_mpc)
    kpis_mpc = coord_mpc.get_custom_kpis(start=start)

    plot_parameter_evolution( 
        coord_ad_mpc, "params_result/2R2C_params_jan.csv"
    )

    value_ad = get_value_function_error(coord_ad_mpc, 12)
    value = get_value_function_error(coord_mpc, 12)
    
    sampling_time = "1D"
    # plot value function errors:
    fig, axes = plt.subplots(2,1,sharex=True)
    ax = axes[0]
    col = "Ti_ol"
    value_ad[col].resample(sampling_time).mean().plot(ax=ax, color="r", **kwargs)
    value[col].resample(sampling_time).mean().plot(ax=ax, color="k", **kwargs)
    ax.legend(["ad", "fixed"])
    col = "Prad_ol"
    ax = axes[1]
    value_ad[col].resample(sampling_time).mean().plot(ax=ax, color="r", **kwargs)
    value[col].resample(sampling_time).mean().plot(ax=ax, color="k", **kwargs)
    ax.legend(["ad", "fixed"])
    plt.show()
    
    fig, axes = plt.subplots(2,1,sharex=True)
    ax = axes[0]
    col = "Ti_ol"
    (value_ad[col]*value_ad["Prad_act"]).resample(sampling_time).mean().plot(ax=ax, color="r", **kwargs)
    (value[col]*value_ad["Prad_act"]).resample(sampling_time).mean().plot(ax=ax, color="k", **kwargs)
    ax.legend(["ad", "fixed"])
    plt.show()
    
    # sum of errors:
    print("fixed: ")
    print(value.sum())
    print("adaptive: ")
    print(value_ad.sum())
    
    """
    What about 'being right when it counts'?
    
    We multiply open-loop error with 
    """
    
    
    print("tail")