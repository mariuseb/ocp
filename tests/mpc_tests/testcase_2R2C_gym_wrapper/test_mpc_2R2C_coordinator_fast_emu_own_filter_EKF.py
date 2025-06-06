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
        "coordinator_own_EKF.json"
    )
    coord.run()
    
    fig, axes, res = coord.plot_temperatures()
    plt.show()
    
    res = coord.env.get_results(tf=1e6)
    res.to_csv("14_days_EKF.csv", index=True)
    
    filterpy_x = pd.read_csv("filterpy_x_history_2days.csv", index_col=0)
    filterpy_P = pd.read_csv("filterpy_P_history_2days.csv", index_col=0)
    
    print(coord)
