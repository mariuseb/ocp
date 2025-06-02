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
        "coordinator.json"
    )
    coord.run()
    
    fig, axes, res = coord.plot_temperatures()
    plt.show()
    
    coord.controller.state_history.to_csv("filterpy_x_history_2days.csv", index=True)
    coord.controller.covar_history.to_csv("filterpy_P_history_2days.csv", index=True)
    
    print(coord)
