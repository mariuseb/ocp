from collections import OrderedDict
import json
import copy
import os
from ocp.config import Config
from ocp.customGymEnv import CustomGymEnv
from ocp.boptestGymEnv import BoptestGymEnv
from ocp.mpc_agent import MPCAgent, AdaptiveMPCAgent
from typing import Union, Sequence
from copy import deepcopy
import numpy.typing as npt
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sys

"""
Simulation coordinator.
"""

def get_env_class(name):
    current_module = sys.modules[__name__]
    return getattr(current_module, name)

class ParameterReader(object):
    def __call__(self, parameters):
        if not isinstance(
            parameters,
            list
        ):
            assert isinstance(parameters, str)
            parameters = pd.read_csv(
                parameters,
                index_col=0
        ).values.flatten()
        return parameters
    
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
    ) -> Union[MPCAgent, AdaptiveMPCAgent]:
        """
        Assume structurally identical model for:
            - mpc
            - mhe
            - ekf
            - est
        """
        adaptive = config.pop("adaptive", False)
        # TODO: rewrite more modular:
        mpc_scaling = deepcopy(
            config["scaling"]
        )
        # no y in mpc-problem:
        mpc_scaling.pop("y_nom", None)
        mpc_scaling.pop("y_nom_b", None)
        mpc_scaling["slack"] = True
        if not adaptive:
            return MPCAgent(
                config["mpc_config_file"],
                config["filter_type"],
                config["filter_config_file"],
                ParameterReader()(config["parameters"]),
                config["scaling"]
            )
        else: # adaptive, which type?
            est_scaling = deepcopy(
            config["scaling"]
            )
            if config["adaptive_type"] == "deterministic":
                return AdaptiveMPCAgent(
                    config["mpc_config_file"],
                    config["filter_type"],
                    config["filter_config_file"],
                    ParameterReader()(config["parameters"]),
                    est_scaling,
                    config_file=config["est_config_file"],
                    adapt_parameters=config["adapt_parameters"],
                    integrate_replace=config["integrate_replace"],
                    adapt_frequency=config["adapt_frequency"],
                    adapt_N=config["adaptive_N"],
                    allow_variable_N=config["allow_variable_N"]
                )
            elif config["adaptive_type"] == "mhe":
                return mheMPCAgent(
                    config["mpc_config_file"],
                    config["filter_type"],
                    config["filter_config_file"],
                    ParameterReader()(config["parameters"]),
                    est_scaling,
                    integrate_replace=config["integrate_replace"],
                    config_file=config["est_config_file"],
                    adapt_parameters=config["adapt_parameters"]
                )
            else:
                raise ValueError("Unknown adaptive agent type " + \
                                 config["type"] + " passed")
                
        
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
        try:
            config["config"]["parameters"] = ParameterReader()(
                config["config"]["parameters"]
            )
        except KeyError: # no parameters passed
            assert config["type"] == "BoptestGymEnv"
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
    
    def plot_temperatures(self, heat_key="phi_h"):
        return self.env.plot_temperatures(
            tf=self.days*24*int(3600/self.dt)*self.dt,
            heat_key=heat_key
        )
    
    # TODO: generalize:
    def plot_one_step_predictions(
        self, res: pd.DataFrame
    ):
        res["Prad_calc"] = (res["Qrad"].diff(1)/1000).shift(-1)
        results = res[["Ti", "Prad_calc", "rad_219", "Prad"]]
        results["Ti_pred"] = np.nan
        results["Prad_pred"] = np.nan
        for k, v in self.controller.preds.items():
            results.loc[results.index[k+1], "Ti_pred"] = self.controller.preds[k].loc[1, "Ti"]
            results.loc[results.index[k], "Prad_pred"] = self.controller.preds[k].loc[0, "Prad"]            
        fig, axes = plt.subplots(2,1, sharex=True)
        ax = axes[0]    
        results[["Ti", "Ti_pred"]].plot(ax=ax, drawstyle="steps-post")
        ax = axes[1]
        ax = results[["Prad_calc", "Prad_pred", "Prad"]].plot(drawstyle="steps-post")
        return fig, axes
        
    def run(self, x0=None): 
        obs, _ = self.env.reset()
        if obs is not None: # first x0 is passed:
            obs = x0
            
        K = int(self.days*24*int(3600/self.dt))
        for k in range(K):
            # TODO: forecast optional:
            forecast = self.env.get_forecast(
                self.controller_dt,
                self.controller_horizon
            )
            self.controller.adaptive_callback(k, self.env)
            action, _ = self.controller.predict(obs, forecast)
            if not self.controller.mpc.solver.stats()["success"]:
                print(action)
            obs, reward, terminated, truncated, info = self.env.step(action)
            # TODO: filtering optional:
            obs = self.controller.x0_from_obs(obs)
        
