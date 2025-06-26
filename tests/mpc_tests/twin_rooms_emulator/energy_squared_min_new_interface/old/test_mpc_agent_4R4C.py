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
    coord.env.time = 172800
    forecast = coord.env.get_forecast(
        coord.controller_dt,
        coord.controller_horizon
    )
    #forecast = forecast[1:]
    #forecast.drop(columns=["Ti_lb", "Ti_ub"], inplace=True)
    #forecast["Ti_ref"] = 295.15
    
    obs, _ = coord.env.reset()
    obs[-1] = 295.15
    action, _ = coord.controller.predict(obs, forecast)
    
    sol = coord.controller.preds[0]    
    sol.to_csv("non_decomposed.csv", index=True)
    print(coord)
