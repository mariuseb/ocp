#from ast import Param
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
#import os
#from pathlib import Path
#from ocp.mpc_agent import MPCAgent>
#from ocp.boptestGymEnv import BoptestGymEnv
#from ocp.customGymEnv import CustomGymEnv
from ocp.coordinator import Coordinator
import pandas as pd
from filterpy.common import Q_discrete_white_noise
rc('mathtext', default='regular')
if __name__ == "__main__":
    
    """
    rng = np.random.default_rng(np.random.MT19937(seed=0))
    gen = rng.multivariate_normal(
        [0,0],
        [[1,0],[0,1]]
    )
    print(gen)
    """
    
    coord = Coordinator(
        "coordinator_mpc_mhe_wrong_model_no_arrival_cost.json"
    )
    x0 = np.array([305.15])
    coord.run(x0=x0)
    
    fig, axes, res = coord.plot_temperatures()
    plt.show()
    
    #fig, axes = coord.plot_one_step_predictions(res)
    #plt.show()

    print(coord)
