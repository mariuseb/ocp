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
        "coordinator_2R2C_env.json"
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
    obs_env = obs[:2]
    coord.controller.params[-2] = obs[-1] - obs[-2]
    action_env, _ = coord.controller.predict(obs_env, forecast)
    sol_env = coord.controller.preds[0]
    
    """
    Radiator coordinator:
    """
    coord = Coordinator(
        "coordinator_2R2C_rad.json"
    )
    # forecast operations:
    forecast["Ti_ENV"] = np.nan
    forecast["Prad_ENV"] = np.nan
    forecast["Ti_ENV"][0:len(sol_env)] = sol_env["Ti"]
    forecast["Prad_ENV"][0:len(sol_env)] = sol_env["Prad"]
    obs_rad = obs[2:]
    #coord.controller.params[-1] = sol_env["rad_flo"][0]
    action_rad, _ = coord.controller.predict(obs_rad, forecast)
    
    
    """
    forecast.index = forecast["dt_index"]
    sol_rad = coord.controller.preds[0]
    sol_env.index = forecast.index[0:len(sol_env)]
    sol_rad.index = forecast.index[0:len(sol_env)]
    
    ax = sol_env["Ti"].plot(drawstyle="steps-post", color="k")
    forecast["Ti_lb"].plot(drawstyle="steps-post", color="b")
    plt.show()

    sol_nondecomp = pd.read_csv("non_decomposed.csv", index_col=0)
    sol_nondecomp.index = forecast.index[0:len(sol_nondecomp)]

    ax = sol_rad["Prad"].plot(drawstyle="steps-post", color="k")
    #sol_env["Prad"].plot(drawstyle="steps-post", color="r")
    sol_nondecomp["Prad"].plot(drawstyle="steps-post", color="b")
    #ax.legend(["rad", "env", "non"])
    ax.legend(["rad", "non"])
    plt.show()

    ax = sol_env["Ti"].plot(drawstyle="steps-post", color="k")
    sol_nondecomp["Ti"].plot(drawstyle="steps-post", color="b")
    forecast["Ti_lb"].plot(drawstyle="steps-post", color="r", linewidth=0.75)
    ax.legend(["decomp", "non", "lb"])
    plt.show()
    
    ax = sol_rad["rad_219"].plot(drawstyle="steps-post", color="k")
    sol_nondecomp["rad_219"].plot(drawstyle="steps-post", color="b")
    ax.legend(["decomp", "non"])
    plt.show()
    """
    
    print(coord)
