#from ast import Param
from ocp.mpc import MPC
import numpy as np
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.tests.utils import get_boptest_config_path
from matplotlib import rc
import pandas as pd
import os
from copy import deepcopy
from typing import Tuple
from ocp.mpc_agent import MPCAgent
rc('mathtext', default='regular')

        
if __name__ == "__main__":
    
    mpc_cfg = os.path.join(
        "mpc_configs",
        "1R1C_MPC.json"
    )
    bop_config_base = get_boptest_config_path()
    boptest_cfg = os.path.join(
        bop_config_base,
        "ZEBLL_config.json"
    )
    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1"
                      )
    mpc = MPCAgent(
        mpc_cfg
    )
    forecast = boptest.get_forecast()
    obs = np.array([293.15])
    days = 1
    K = days*24*int(3600/mpc.mpc.dt)
    
    for k in range(K):
        #lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        action, _ = mpc.predict(obs, forecast)
        forecast, obs, u_meas = boptest.evolve(u=action)
        
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days)
    plt.show()    
    fig.tight_layout()
