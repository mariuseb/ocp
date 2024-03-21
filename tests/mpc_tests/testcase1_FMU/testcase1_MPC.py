from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from ocp.functions import functions
from copy import deepcopy
from project1_boptest_gym.examples.test_and_plot import plot_results
from project1_boptest_gym.boptestGymEnv import BoptestGymEnv

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("configs", "1R1C_MPC.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    params = [1E-2,1E6]
    kwargs = dict()

    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              functions=functions,
              **deepcopy(kwargs))  # to remove, replace with N
    # 'Old' way of creating a Boptest 'env':
    """
    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1"
                      )
    """
    url = 'http://bacssaas_boptest:5000'
    # Use gym env from Javiers code instead:
    boptest = BoptestGymEnv(boptest_cfg,
                            name                  = "testcase1",
                            url                   = url,
                            actions               = ['oveAct_u'],
                            observations          = {'TRooAir_y':(280.,310.)}, 
                            #observations          = {'TRooAir_y':(280.,310.), 'TDryBul':(280.,310.)}, 
                            random_start_time     = False,
                            max_episode_length    = 24*3600,
                            #predictive_period     = 3600,
                            predictive_period     = mpc.dt*mpc.N,
                            warmup_period         = 0,
                            step_period           = 900)
    boptest.reset()
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 293.15}
    ub_night = {"Ti": 296.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ["Ti"],
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)

    x0 = np.array([293.15])
    
    # sim horizon: 2 days
    days = 3
    K = days*24*bounds.t_h

    hist = pd.DataFrame(columns=["pred", "act"])
    rewards = []
    for k in range(K):
        """
        TODO: transform to RL API.
        DONE.
        """
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)   
        sol, u_0, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params,
                               codegen=False
                               )
        #data, y_meas, u_meas = boptest.evolve(u=u)
        """ 
        For 'fair' baselining of MPC and RL,
        round to nearest action as in DQN policy.
        """
        action = [round(u_0["phi_h"], -1)] # -> 21 discrete actions
        # step:
        x0, reward, done, _, _ = boptest.step(action)
        # get forecast in separate step:
        data = boptest.forecast()
        hist.loc[k] = [sol.loc[1].Ti, x0[0]]
        # save rewards:
        rewards.append(reward)
        
    plt.rcParams.update({'font.size': 12})
    
    plot_results(
                 boptest,
                 rewards
                 )
    
    print(data)
