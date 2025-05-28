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
rc('mathtext', default='regular')
if __name__ == "__main__":
    
    coord = Coordinator(
        "coordinator.json"
    )
    coord.run()
    
    fig, axes, res = coord.plot_temperatures()
    plt.show()
    
    print(coord)
