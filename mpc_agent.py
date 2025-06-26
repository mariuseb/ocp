#from ast import Param
from ocp.mpc import MPC
from ocp.mhe import MHE
#from ocp.filters import KalmanDAE
import numpy as np
import numpy.typing as npt
from matplotlib import rc
import pandas as pd
from copy import deepcopy
from typing import Tuple, Any, Union
#import os
import numpy.typing as npt
import pathlib
from ocp.filter_wrapper import FilterWrapper
from ocp.estimation import Estimation
from itertools import product
from ocp.config import Config
from abc import ABCMeta, abstractmethod
from gymnasium import Env
import casadi as ca
import matplotlib.pyplot as plt
rc('mathtext', default='regular')

ConfigArg = Union[pathlib.Path, dict, Config]

class AbstractMPCAgent(metaclass=ABCMeta): 
    
    def __init__(
        self,
        mpc_cfg: ConfigArg,
        filter_type: str,
        filter_cfg: ConfigArg,
        params: npt.NDArray[Any],
        scaling: dict
    ) -> None:
        self.params = params
        self.scaling = scaling
        self.mpc = MPC(
            config=mpc_cfg,
            param_guess=self.params,
            **self.get_mpc_scaling(self.scaling)
        )  # to remove, replace with N
        if not isinstance(filter_cfg, Config):
            filter_cfg = Config()(filter_cfg)
        if "parameters" not in filter_cfg.keys():
            filter_cfg["parameters"] = self.params
        self.filter = FilterWrapper(
            filter_cfg,
            filter_type
        )
        self.i = 0
        self.preds = dict()
        self.forecasts = dict()
        self._init_state_history()
        self._init_covar_history()
     
    @staticmethod
    def get_mpc_scaling(scaling):
        mpc_scaling = deepcopy(
            scaling
        )
        # no y in mpc-problem:
        mpc_scaling.pop(
            "y_nom", None
        )
        mpc_scaling.pop(
            "y_nom_b", None
        )
        # slack by def., TODO: setting
        mpc_scaling["slack"] = True
        return mpc_scaling
        
    def _init_state_history(
        self
    ) -> None:
        cols = pd.MultiIndex.from_product(
            [["prior", "posterior"], self.x()],
            names=['', 'state']
        )
        self.state_history = pd.DataFrame(
            columns=cols
        )
    
    def _init_covar_history(
        self
    ) -> None:
        self.ps = list(
            map(
                lambda x: "p_" + str(x[0]) + str(x[1]),
                product(range(1,self.n_x+1), range(1,self.n_x+1)
                )
            )
        )
        cols = pd.MultiIndex.from_product(
            [["prior", "posterior"], self.ps],
            names=['', 'covariance']
        )
        self.covar_history = pd.DataFrame(
            columns=cols
        )
        
        
    @property
    def dt(self):
        return self.mpc.dt
    
    @property
    def x(self):
        return self.mpc.x
    
    @property
    def p(self):
        return self.mpc.dae.p
    
    @property
    def n_x(self):
        return self.mpc.n_x
    
    @property
    def N(self):
        return self.mpc.N
        
    def predict(
        self,
        obs: npt.NDArray[Any],
        forecast: pd.DataFrame,
        deterministic: bool = True
    ) -> Tuple[pd.Series, bool]:
        
        forecast = forecast[0:self.mpc.N]
        forecast["Ti_ref"] = 295.15
        # get bounds:
        """
        bounds_forecast = forecast[1:]
        lbx = bounds_forecast[
            list(map(lambda x: x + "_lb", self.ekf.y))
        ].values.flatten()
        ubx = bounds_forecast[
            list(map(lambda x: x + "_ub", self.ekf.y))
        ].values.flatten()
        lbx, ubx = self.fill_x_bounds(lbx, ubx)
        """
        lbx, ubx = self.get_bounds_from_forecast(forecast)
        sol, u, x0, raw_sol = self.mpc.solve(
            forecast,
            x0=obs,
            lbx=lbx,
            ubx=ubx,
            params=self.params,
            codegen=False,
            return_raw_sol=True
        )
        if not self.mpc.solver.stats()["success"]:
            print(sol)
        # store current raw sol:
        self.raw_sol = raw_sol
        # store forecast, opt result:
        self.forecasts[self.i] = forecast
        self.preds[self.i] = sol
        self.i += 1
        return u, False
    
    def get_bounds_from_forecast(
        self, 
        #lbx: npt.NDArray[Any],
        #ubx: npt.NDArray[Any]
        forecast: pd.DataFrame
    ) -> Tuple[npt.NDArray[Any], npt.NDArray[Any]]:
        """
        Fill bounds on non-measured states.
        """
        
        bounds_forecast = forecast[1:]
        """
        non_meas = list(
            set(self.ekf.dae.x
        ).difference(
            set(self.ekf.y))
        )
        """
        _len = self.mpc.N - 1
        #lbx, ubx = np.array([]), np.array([])
        lbs, ubs = [], []
        for state in self.mpc.x():
            lb_key = state + "_lb"
            ub_key = state + "_ub"
            if lb_key in forecast.columns:
                _lbx = bounds_forecast[lb_key].values
            else:
                _lbx = np.array([-np.inf]*_len)
            if ub_key in forecast.columns:
                _ubx = bounds_forecast[ub_key].values
            else:
                _ubx = np.array([np.inf]*_len)
            #lbx = np.append(lbx, _lbx)
            lbs.append(_lbx)
            ubs.append(_ubx)
            #ubx = np.append(ubx, _ubx)
        lbx = np.array(lbs).T.flatten()
        ubx = np.array(ubs).T.flatten()
        return lbx, ubx
    
    def store_filtering_history(
        self,
        x: npt.NDArray[np.float64],
        P: npt.NDArray[np.float64],
        _type: str
    ) -> None:
        assert _type in ("prior", "posterior")
        self.state_history.loc[
            self.i, (_type, self.x())
        ] = x
        self.covar_history.loc[
            self.i, (_type, self.ps)
        ] = P.flatten()
        
    
    def x0_from_obs(
        self,
        k: int,
        obs: npt.NDArray[Any]
    ) -> npt.NDArray[np.float64]:  
        """
        TODO: store prior, posterior 
        of state and covariance.
        """
        _iter = self.i-1
        u = self.preds[
            _iter
        ].iloc[0][
            self.filter.u
        ].values
        r = self.forecasts[
            _iter
        ].iloc[0][
            self.filter.r
        ].values
        x_prior, P_prior = self.filter.predict(
            u,
            r
        )
        self.store_filtering_history(
            x_prior,
            P_prior,
            "prior"
        )
        x_posterior, P_posterior = self.filter.update(
            obs
        )
        self.store_filtering_history(
            x_posterior,
            P_posterior,
            "posterior"
        )
        return x_posterior

    def param_guess_from_array(
        self, 
        adapt_parameters: list[str]
    ) -> dict[str, dict[str, float]]:
        param_guess = {}
        for p, val in zip(self.p, self.params):
            if p in adapt_parameters:
                scale = 1E3
            else:
                scale = 1
            param_guess[p] = {
                "init": val,
                "lb": (1/scale)*val,
                "ub": scale*val
            }
        return param_guess
    
    @abstractmethod
    def adaptive_callback(
            self,
            k: int, 
            env: Env
    ):
        pass
    
    

class MPCAgent(AbstractMPCAgent):
    """
    Fixed-model MPC agent. Requires no additional
    functionality beyond ABC implementations.
    """
    def adaptive_callback(
            self,
            k: int, 
            env: Env
    ):
        pass
 
class AbstractAdaptiveAgent(AbstractMPCAgent, metaclass=ABCMeta):
    def __init__(
        self,
        *args,
        adapt_parameters: list[str] = [],
        est_scaling: dict = {},
        integrate_replace: dict[str, str] = dict()
    ) -> None: 
        super().__init__(*args)
        self.adapt_parameters = adapt_parameters
        self.params_history = pd.DataFrame(
            columns=self.p
        )
        self.integrate_replace = integrate_replace
        self.est_scaling = est_scaling
        self.ests = dict()
    
    def get_y_data(
        self,
        env: Env,
        k: int,
        backshift: list = [],
        integrate_replace: dict[str, str] = {}
    ):         
        tf = k*self.dt
        ts = tf - (self.adapt_N-1)*self.dt
        data = env.get_results(tf, ts=ts)
        y_data = data.rename(
            columns=env.maps.boptest_to_ocp
        )
        for replace_var, orig_var in integrate_replace.items():
            # TODO: pass conversion factor:
            y_data[replace_var] = (y_data[orig_var].diff(1)/1000).shift(-1)
        for var in backshift:
            y_data[var] = y_data[var].shift(-1)
        y_data = y_data.fillna(0)
        y_data.index = range(len(y_data.index))
        for y, var in self.estimator.y.items():
            y_data[y] = y_data[var]
        return y_data
            
    """
    TODO: modularize:
    """
    def get_estimation_parameters(
        self
    ):
        Q = ca.DM.eye(self.estimator.n_x)
        R = ca.DM.eye(self.estimator.n_y)
        R[1,1] = 1e-5 # config / learnable
        P0 = np.eye(self.estimator.n_p + self.estimator.n_x)*1 # config / learnable

        P0[
        self.estimator.n_p:(self.estimator.n_p + self.estimator.n_x),
        self.estimator.n_p:(self.estimator.n_p + self.estimator.n_x)
        ] = 0 # config setting: opts (0, EKF smoothing update, identity, learnable)
        
        lbp = self.estimator.get_lbp(1e-3)
        ubp = self.estimator.get_ubp(1e3)
        p0 = self.estimator.p0
        return Q, R, P0, lbp, ubp, p0
    
    def generate_x_guess(
        self,
        y_data: pd.DataFrame
    ):
        """
        TODO: options: by
            - simulation w/ current model to fill missing,
            - measurements and filling heuristics.
            - ekf filtering history
        """
        x_guess = np.array([
                y_data.y1.values.flatten(),
                y_data.y1.values.flatten() - 2,
                y_data.y1.values.flatten() - 280
        ])
        return x_guess
    
    
    @abstractmethod
    def re_estimation_clause(
            self,
            k: int
    ) -> bool | NotImplementedError:
        return NotImplementedError("")
    
    def adaptive_callback(
            self,
            k: int, 
            env: Env
    ):
        """
        k starts at zero:
        """
        if self.re_estimation_clause(k):
            # estimate, set params:
            Q, R, P0, lbp, ubp, p0 = self.get_estimation_parameters()
            y_data = self.get_y_data(
                env,
                k,
                backshift=env.maps.u,
                integrate_replace=self.integrate_replace
            )
            x_guess = self.generate_x_guess(
                y_data
            )
            # solve:
            sol, params = self.estimator.solve(
                                        y_data,
                                        p0,
                                        lbp=lbp,
                                        ubp=ubp,
                                        x_guess=x_guess,
                                        covar=ca.veccat(Q, R),
                                        codegen=False,
                                        P0=P0,
                                        x_N=x_guess[-1,-self.estimator.n_x:]
                                        ) 
            self.estimator.p0 = params.values
            # from t = k, the parameters are:
            self.params_history.loc[k, :] = params
            # store solution:
            self.ests[k] = sol
            # set parameters globally on agent:
            self.params = params.values
        
        
    
 
"""
TODO: consider intermediate abstract superclass for
adaptive agents.
"""
    
class AdaptiveMPCAgent(AbstractAdaptiveAgent):
    def __init__(
        self,
        *args,
        adapt_frequency: int = 0,
        adapt_N: int = 0,
        **kwargs,
    ) -> None: 
        config_file = kwargs.pop("config_file")
        super().__init__(*args, **kwargs)
        self.adapt_frequency = adapt_frequency
        self.adapt_N = adapt_N
        self.estimator = Estimation(
            config=config_file,
            N=adapt_N,
            dt=self.dt,
            param_guess=self.param_guess_from_array(
                self.adapt_parameters    
            ),
            truncate_scaling=True,
            arrival_cost=True,
            **self.get_est_scaling(
                self.scaling
            )
        )
        
    @staticmethod
    def get_est_scaling(scaling):
        est_scaling = deepcopy(
            scaling
        )
        # deterministic --> no slack:
        est_scaling["slack"] = False
        return est_scaling
        
        
    def re_estimation_clause(
            self,
            k: int
        ):
        return ((k+1) % self.adapt_frequency == 0) and ((k+1) >= self.adapt_N)
            
            
class MheMPCAgent(AbstractAdaptiveAgent):
    def __init__(
        self,
        *args,
        **kwargs
    ) -> None: 
        config_file = kwargs.pop("config_file")
        super().__init__(
            *args,
            **kwargs
        )
        self.estimator = MHE(
            config=config_file,
            param_guess=self.param_guess_from_array(
                self.adapt_parameters    
            ),
            arrival_cost=True,
            **self.get_mhe_scaling(
                self.scaling
            )
        )
        self.adapt_N = self.estimator.N
        self.params_history = pd.DataFrame(
            columns=self.p
        )
        
    @staticmethod
    def get_mhe_scaling(scaling):
        mhe_scaling = deepcopy(
            scaling
        )
        # stochastic --> slack:
        mhe_scaling["slack"] = True
        return mhe_scaling
    
    def re_estimation_clause(
            self,
            k: int
        ):
        return (k+1) >= self.adapt_N
    
    
    def x0_from_obs(
        self,
        k: int,
        obs: npt.NDArray[Any]
    ):
        """
        Update the EKF in any case s.t. 
        updates of covariance can be retrieved.
        """
        x_post_ekf = super().x0_from_obs(k, obs)
        if self.re_estimation_clause(k):
            # latest estimation, latest state:
            x_post_mhe = self.ests[k][self.x()].iloc[-1].values.flatten()
            return x_post_mhe
        return x_post_ekf
            
    
    
    
    
    
    """
    @property
    @abstractmethod
    def estimator(self):
        raise NotImplementedError("")
    
    @property
    @abstractmethod
    def adapt_N(self):
        raise NotImplementedError("")
    """