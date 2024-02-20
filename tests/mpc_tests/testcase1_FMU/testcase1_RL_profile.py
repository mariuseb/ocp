from project1_boptest_gym.boptestGymEnv import BoptestGymEnv, \
                                            NormalizedActionWrapper, \
                                            NormalizedObservationWrapper, \
                                            DiscretizedActionWrapper, \
                                            DiscretizedObservationWrapper
from stable_baselines3 import DQN
import numpy as np
import json
import casadi as ca
import pandas as pd
import matplotlib.pyplot as plt
from ocp.tests.utils import get_boptest_config_path
from matplotlib import rc
import os
from project1_boptest_gym.examples.test_and_plot import plot_results
# manually search perceptron hyperparameters for binary classification
import cProfile as profile
import pstats

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    url = 'http://bacssaas_boptest:5000'
    # Use gym env from Javiers code instead:
    boptest = BoptestGymEnv(boptest_cfg,
                            name                  = "testcase1",
                            url                   = url,
                            actions               = ['oveAct_u'],
                            observations          = {'TRooAir_y':(280.,310.)}, 
                            #observations          = {'TRooAir_y':(280.,310.), 'TDryBul':(280.,310.)}, 
                            random_start_time     = False,
                            max_episode_length    = 1e6*3600,
                            #predictive_period     = 3600,
                            predictive_period     = 900,
                            warmup_period         = 0,
                            step_period           = 900)
    """
    Normalize, as RL agent has been trained on
    normalized environment.
    """
    boptest = NormalizedObservationWrapper(boptest)
    boptest = NormalizedActionWrapper(boptest)  
    boptest = DiscretizedActionWrapper(boptest, n_bins_act=200)

    #model.learn(total_timesteps=int(3E4)) # progress_bar=True)
    # pre-trained:
    rl_agent = DQN.load("dqn_testcase1")
    boptest.reset()
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    #dt = mpc.dt
    lb_night = {"Ti": 293.15}
    ub_night = {"Ti": 296.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    x0 = boptest.observation(np.array([293.15]))
    # sim horizon: 2 days
    days = 3
    K = days*24*4

    prof = profile.Profile()
    prof.enable()

    rewards = []
    for k in range(int(K)):
        action, _ = rl_agent.predict(x0)
        x0, reward, done, _, _ = boptest.step(action)
        # save rewards:
        rewards.append(reward)
    
    prof.disable()
    
    with open('profile_RL_testcase1.txt', 'w+') as stream:
        stats = pstats.Stats(prof, stream=stream).strip_dirs().sort_stats("cumtime")
        stats.print_stats(100)
    
    plot_results(
                 boptest,
                 rewards,
                 points=None
                 #,
                 #N=K
                 )    
    print(data)
