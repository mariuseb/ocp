from ocp.boptestGymEnv import BoptestGymEnv, NormalizedActionWrapper, NormalizedObservationWrapper, DiscretizedActionWrapper, DiscretizedObservationWrapper
from stable_baselines3 import A2C, DQN
from ocp.examples.test_and_plot import test_agent
from copy import deepcopy
#import torch

# BOPTEST case address
#url = 'http://127.0.0.1:5001'
#url = 'http://bacssaas_boptest:5000'
url = 'http://docker-web-1:80'

# Instantite environment
env = BoptestGymEnv(
        url                  = url,
        testcase             = 'testcase1',
        actions              = ['oveAct_u'],
        observations         = {
                                'time':(0,604800),
                                'TRooAir_y':(280.,310.),
                                'TDryBul':(265,303),
                                'LowerSetp[1]':(280.,310.),
                                'UpperSetp[1]':(280.,310.)
                                }, 
        predictive_period    = 24*3600, 
        regressive_period    = None, 
        random_start_time    = False,
        max_episode_length   = 24*3600,
        warmup_period        = 0,
        step_period          = 900
)

# Add wrappers to normalize state and action spaces (Optional)
env = NormalizedObservationWrapper(env)
env = NormalizedActionWrapper(env)  
#env = DiscretizedActionWrapper(env, n_bins_act=20)
#env = DiscretizedObservationWrapper(env, n_bins_obs=100)

# Instantiate and train an RL algorithm

model = A2C('MlpPolicy', env)

"""
model = DQN('MlpPolicy',
            env,
            verbose=1,
            train_freq=1,
            gradient_steps=1,
            gamma=0.99,
            exploration_fraction=0.2,
            exploration_final_eps=0.07,
            target_update_interval=10,
            max_grad_norm=100,
            learning_starts=1,
            buffer_size=1000,
            batch_size=1,
            learning_rate=4e-4,
            policy_kwargs=dict(net_arch=[256, 256]),
            seed=2
            )
"""


#model.learn(total_timesteps=int(1e5))
#model.learn(total_timesteps=int(1000))
#model.learn(total_timesteps=int(1000))
before = deepcopy(model.get_parameters()["policy"])

model.learn(total_timesteps=int(1E3))
#model.learn(total_timesteps=int(1E4), progress_bar=True)
#print(model)
#model.save("a2c_testcase1")
# Test trained agent
observations, actions, rewards, kpis = test_agent(env, model, 
                                                  start_time=0, 
                                                  episode_length=1*24*3600,
                                                  #episode_length=1,
                                                  warmup_period=24*3600,
                                                  plot=True)
after = model.get_parameters()["policy"]
for k, v in after.items():
    print("After: ")
    print(v)
    print("Before: ")
    print(before[k])
print(model)