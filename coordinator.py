from collections import OrderedDict
import json
import copy
import os
from ocp.config import Config
from ocp.customGymEnv import CustomGymEnv, DataEnv
from ocp.boptestGymEnv import BoptestGymEnv
from ocp.mpc_agent import MPCAgent, AdaptiveMPCAgent, MheMPCAgent, PredictiveAdaptiveAgent
from typing import Union, Sequence
from ocp.config import convert_json_to_native_types, get_json_hash
from copy import deepcopy
import numpy.typing as npt
import pickle
import matplotlib.pyplot as plt
from contextlib import redirect_stdout
from ocp.result_generator import nrmse, mse, r2_score, rmse
from datetime import datetime
import numpy as np
import pandas as pd
import sys
import requests

"""
Simulation coordinator.
"""

def recursive_to_dict(d):
    if isinstance(d, dict):
        return recursive_to_dict(d)
    elif isinstance(d, pd.DataFrame):
        return d.to_dict()
    else:
        return d

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
        return np.array(
            parameters,
            dtype=np.float64
        )
    
class Coordinator(object):
    def __init__(
            self, 
            config,
            can_run=True
        ) -> None:
        cfg = Config()(config)
        self.cfg = deepcopy(cfg)
        self.can_run = can_run
        self.days = cfg["days"]
        self.sampling_time = cfg["sampling_time"]
        self.controller = self._init_controller(
            cfg["controller"]
        )
        if can_run:
            self.env = self._init_env(
                cfg["environment"]
            )
        self.val_metrics = pd.DataFrame(
            columns=["nrmse", "rmse", "r2", "mse"]
        )
        
    def _init_controller(
        self,
        config
    ) -> Union[MPCAgent, AdaptiveMPCAgent, MheMPCAgent]:
        """
        Assume structurally identical model for:
            - mpc
            - mhe
            - ekf
            - est
        """
        adaptive = config.pop("adaptive", False)
        hstein_cfg = config.pop("hammerstein_config_file", None)
        # TODO: rewrite more modular:
        mpc_scaling = deepcopy(
            config["scaling"]
        )
        # no y in mpc-problem:
        mpc_scaling.pop("y_nom", None)
        mpc_scaling.pop("y_nom_b", None)
        mpc_scaling["slack"] = True
        args = (
            config["mpc_config_file"],
            hstein_cfg,
            config["filter_type"],
            config["filter_config_file"],
            ParameterReader()(config["parameters"]),
            config["scaling"]
        )
        if not adaptive:
            return MPCAgent(
                *args
            )
        else: # adaptive, which type?
            kwargs = dict(
                config_file=config["est_config_file"],
                adapt_parameters=config["adapt_parameters"],
                integrate_replace=config["integrate_replace"]
            )
            purely_predictive = config.pop("purely_predictive", False)
            if purely_predictive: # only one type thus far:
                return PredictiveAdaptiveAgent(
                    *args,
                    **kwargs,
                    adapt_frequency=config["adapt_frequency"],
                    adapt_N=config["adaptive_N"]
                )
            else:
                if config["adaptive_type"] == "deterministic":
                    return AdaptiveMPCAgent(
                        *args,
                        **kwargs,
                        adapt_frequency=config["adapt_frequency"],
                        adapt_N=config["adaptive_N"]
                    )
                elif config["adaptive_type"] == "mhe":
                    #kwargs["slack"] = True
                    return MheMPCAgent(
                        *args,
                        **kwargs
                    )
                
        
    def _init_env(
        self,
        config
    ) -> Union[CustomGymEnv, BoptestGymEnv]:
        #_type = config.pop("type")
        klass = get_env_class(config["type"])
        if "step_period" not in config["config"]:
            config["config"]["step_period"] = self.dt
        try:
            config["config"]["parameters"] = ParameterReader()(
                config["config"]["parameters"]
            )
        except KeyError: # no parameters passed
            assert config["type"] in ("BoptestGymEnv", "DataEnv")
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
            heat_key=heat_key,
            res=self.res
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
        
    def get_custom_kpis(self, start=None):
        """
        Get kpis for energy, cost, discomfort, peak.
        
        Missing: iaq-discomf, but skip for now as we
        leave ventilation system be.
        
        TODO: more modular
        """
        if start is not None:
            res = self.res.loc[start:]
        else:
            res = self.res
        
        _lb_vio = (res.Ti - res.Ti_lb)
        _ub_vio = (res.Ti - res.Ti_ub)
        lb_vio = _lb_vio.loc[_lb_vio < 0]
        ub_vio = _ub_vio.loc[_ub_vio > 0]
        # in Kh:
        sum_vio = abs(lb_vio.sum()) + ub_vio.sum()
        tdis = sum_vio/(3600/self.dt)
        # in kWh:
        ener_tot = (res["Qrad"].iloc[-1] - res["Qrad"].iloc[0])/3.6E6
        # in kW:
        Prad_calc = (res["Qrad"].diff(1)/1E6).shift(-1).fillna(0)
        # global peak:
        
        peak = Prad_calc.max()
        # cost in EUR:
        cost = (Prad_calc*res.cost).sum()
        return pd.DataFrame(
            index=["tdis [Kh]",
                   "energy [kWh]",
                   "peak power [kW]",
                   "cost [EUR]"
            ],
            data=[tdis, ener_tot, peak, cost],
            columns=["value"]
        )
    
    def run_baseline_control(self):
        """ Run PID for however long. """        
        obs, _ = self.env.reset()
        K = int(self.days*24*int(3600/self.dt))
        for k in range(K):
            print("\r", end='')
            #print("\033[2A", end="")
            #print("\033[1A", end="")
            print("%s: Step %s of %s %s" % \
                (
                    datetime.now().strftime('%Y-%m-%d %H:%M:%S'), \
                    str(k+1),
                    str(K),
                    "Success"
                    ), 
                flush=True, end='')
            #print("\033[1A", end="")
            obs, reward, terminated, truncated, info = self.env.step(
                pd.DataFrame(data=[None]).iloc[0]
            )
        # get env result:
        self.res = self.env.get_results(
            self.days*24*int(3600/self.dt)*self.dt
        )
        try:
            self.kpis = self.get_custom_kpis()
            requests.put('{0}/stop/{1}'.format(self.env.url, self.env.testid))
        except KeyError:
            assert isinstance(self.env, CustomGymEnv)
        
         
    def run(self, x0=None): 
        
        if self.can_run:
            obs, _ = self.env.reset()
            if obs is not None: # first x0 is passed:
                obs = x0
                
            #start_k = int(self.env.start_time/self.dt) - 1
            #K = start_k + int(self.days*24*int(3600/self.dt))
            #self.controller.i = start_k
            K = int(self.days*24*int(3600/self.dt))
            for k in range(K):
                # TODO: forecast optional:
                forecast = self.env.get_forecast(
                    self.controller_dt,
                    self.controller_horizon
                )
                # temp. re-direct of stdout:
                #with open(os.devnull, 'w') as fnull:
                    #with redirect_stdout(fnull):
                self.controller.adaptive_callback(
                    k, 
                    self.env
                )
                action, _ = self.controller.predict(
                    obs, 
                    forecast
                )
                self.validation_callback(k)
                if self.controller.mpc.solver.stats()["success"]:
                    status = "succeeded"
                else:
                    status = "failed"
                print("\r", end='')
                #print("\033[2A", end="")
                #print("\033[1A", end="")
                print("%s: Controller solve %s of %s %s" % \
                    (
                     datetime.now().strftime('%Y-%m-%d %H:%M:%S'), \
                     str(k+1),
                     str(K),
                     status
                     ), 
                    flush=True, end='')
                #print("\033[1A", end="")
                obs, reward, terminated, truncated, info = self.env.step(
                    action
                )
                #if k == 119:
                #    print(k)
                # TODO: filtering optional:
                obs = self.controller.x0_from_obs(
                    k, 
                    obs
                )
            # get env result:
            self.res = self.env.get_results(
                self.days*24*int(3600/self.dt)*self.dt
            )
            
            """
            ax = self.val_metrics.nrmse.plot(drawstyle="steps-post")
            ax1 = ax.twinx()
            res = self.res.copy()[:-1]
            res.index = self.val_metrics.index
            ax = res["phi_h"].plot(color="r", drawstyle="steps-post")
            plt.show()
            """
            self.concatenate_filtering_cols()
            try:
                self.kpis = self.get_custom_kpis()
                requests.put('{0}/stop/{1}'.format(self.env.url, self.env.testid))
            except KeyError:
                assert isinstance(self.env, CustomGymEnv)
            
        else: # TODO : log
            print("Coordinator works only as a result container. " + 
                  "TODO: get, set emulator state. Then, unpickled " +
                  "results can be used for further runs.")
    
    def concatenate_filtering_cols(self):
        for attr in ("state_history", "covar_history"):
            new_columns = []
            for ndx_tuple in getattr(self.controller, attr).columns:
                ndx = ndx_tuple[1] + "_" + ndx_tuple[0] 
                new_columns.append(ndx)
            setattr(getattr(self.controller, attr), "columns", new_columns)
    
    def __eq__(self, other):
        if isinstance(other, self.__class__):
            self_jsonstr = convert_json_to_native_types(
                self._get_containers(
                    as_ordered_dict=True
                )
            )
            other_jsonstr = convert_json_to_native_types(
                self._get_containers(
                    as_ordered_dict=True
                )
            )
            return self_jsonstr == other_jsonstr
        else:
            return False

    def validation_callback(
        self,
        k
    ):
        if isinstance(self.env, DataEnv):
            # take latest pred, forecast:
            pred = self.controller.preds[k]
            forecast = self.controller.forecasts[k]
            # TODO: validation variable modular:
            val_tuple = (
                pred["Ti"].values.flatten(), 
                forecast["Ti"].values.flatten()
            )
            self.val_metrics.loc[
                k,
                ["nrmse", "rmse", "r2", "mse"]
            ] = np.array([
                nrmse(*val_tuple),
                rmse(*val_tuple),
                r2_score(*val_tuple),
                mse(*val_tuple)
            ])
                
            
    def _get_containers(
        self,
        as_ordered_dict=False
    ):
        d = {}
        for k, v in self.controller.__dict__.items():
            if isinstance(v, (dict, pd.DataFrame)):  #and k not in ("state_history", "covar_history"):
                d[k] = v
        for k, v in self.__dict__.items():
            if isinstance(v, (dict, pd.DataFrame)):
                d[k] = v
        if as_ordered_dict:
            d = OrderedDict(d)
        return d
              
    def __getstate__(self):
        """
        Only pickle dfs, dicts:
        """
        out = self._get_containers()
        return out
    
    def __setstate__(self, d):
        """
        res and cfg on top-level,
        rest is on controller.
        
        NB! can_run=False
        """
        cfg = d.pop("cfg")
        self.__init__(
            cfg,
            can_run=False
        )
        self.res = d.pop("res")
        self.kpis = d.pop("kpis")
        # set frames, dicts:
        for k, v in d.items():
            setattr(self.controller, k, v)
            
    def write_result(self):
        name = get_json_hash(self.cfg) + ".pkl"
        path = os.path.join("results", name)
        if not os.path.exists("results"):
            os.mkdir("results")
        with open(path, 'wb') as handle:
            pickle.dump(self, handle, protocol=pickle.HIGHEST_PROTOCOL)
            
    @classmethod
    def read_result(cls, cfg: OrderedDict, path=None):
        if path is None:
            name = get_json_hash(cfg) + ".pkl"
            path = os.path.join("results", name)
        with open(path, 'rb') as handle:
            obj = pickle.load(handle)
        return obj
        
        

        
