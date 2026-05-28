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
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_2R2C.json")
    traverse_dict(
        cfg
    )
    coord = Coordinator(
        # "coordinator_boptest.json"
        cfg
    )
    x0 = np.array([
        293.15, 293.15
    ])
    coord.run(x0=x0)
    
    """
    fig, axes, res = coord.plot_temperatures(
        heat_key="Prad"
    )
    plt.show()
    fig, axes = coord.plot_one_step_predictions(
        res
    )
    """
    
    res = coord.res
    res.index = res.dt_index
    
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    res.Ti.plot(ax=ax, drawstyle="steps-post", color="m")
    res.Ti_lb.plot(ax=ax, drawstyle="steps-post", color="k")
    ax = axes[1]
    ax1 = ax.twinx()
    res.Prad.plot(ax=ax, drawstyle="steps-post", color="r")
    res.rad_219.plot(ax=ax1, drawstyle="steps-post", color="k")
    
    plt.show()
    
    print(coord)