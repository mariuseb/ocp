from collections import OrderedDict
import json
import copy
import os
from ocp.config import Config
from ocp.customGymEnv import CustomGymEnv
from ocp.boptestGymEnv import BoptestGymEnv
from ocp.mpc_agent import MPCAgent
from typing import Union
import sys

"""
Simulation coordinator.
"""

def get_env_class(name):
    current_module = sys.modules[__name__]
    return getattr(current_module, name)

class Coordinator(object):
    def __init__(self,  config) -> None:
        cfg = Config()(config)
        self.days = cfg["days"]
        self.sampling_time = cfg["sampling_time"]
        self.controller = self._init_controller(
            cfg["controller"]
        )
        self.env = self._init_env(
            cfg["environment"]
        )
        
    def _init_controller(
        self,
        config
    ) -> MPCAgent:
        return MPCAgent(
            config["mpc_config_file"],
            config["ekf_config_file"],
            config["parameters"]
        )
        
    def _init_env(
        self,
        config
    ) -> Union[CustomGymEnv, BoptestGymEnv]:
        #_type = config.pop("type")
        klass = get_env_class(config["type"])
        """
        return CustomGymEnv(
            config["config"],
            self.dt,
            config["parameters"],
            config["maps"]
        )
        """
        if "step_period" not in config["config"]:
            config["config"]["step_period"] = self.dt
        return klass(
            **config["config"]
        )
    
    @property
    def dt(self):
        return int(self.sampling_time.rstrip("min"))*60

    @property
    def controller_horizon(self):
        return self.controller.mpc.N
    
    @property
    def controller_dt(self):
        return self.controller.mpc.dt
    
    def plot_temperatures(self):
        return self.env.plot_temperatures(
            tf=self.days*24*int(3600/self.dt)*self.dt
        )
        
    def run(self): 
        obs, _ = self.env.reset()
        K = self.days*24*int(3600/self.dt)
        for k in range(K):
            # TODO: forecast optional:
            forecast = self.env.get_forecast(
                self.controller_dt,
                self.controller_horizon
            )
            action, _ = self.controller.predict(obs, forecast)
            obs, reward, terminated, truncated, info = self.env.step(action)
            # TODO: filtering optional:
            obs = self.controller.x0_from_obs(obs)
        
