#from ast import Param
from ocp.mpc import MPC
from ocp.ocp import is_single_shooting
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
from ocp.functions import functions
from ocp.shooting import SingleShooting
from datetime import datetime
from ocp.dae import DAE
import ocp.integrators as integrators
import casadi as ca
import matplotlib.pyplot as plt
rc('mathtext', default='regular')

ConfigArg = Union[pathlib.Path, dict, Config]



class AbstractMPCAgent(metaclass=ABCMeta): 
    
    def __init__(
        self,
        mpc_cfg: ConfigArg,
        hammerstein_cfg: ConfigArg,
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
            functions=functions,
            **self.get_mpc_scaling(self.scaling)
        )  # to remove, replace with N
        if hammerstein_cfg is None: # trivial map
            # create trivial map
            self.hstein = ca.Function(
                "G",
                [
                    self.mpc.dae.var("u"),
                    ca.vertcat( 
                        self.mpc.dae.var("z"), 
                        self.mpc.dae.var("p")
                    )
                ],
                [self.mpc.dae.var("u")],
                ["u'", "p"],
                ["u"]
            )
            self.decomposed = False
        else: # construct from provided cfg
            ###### TODO: own function: #######
            dae = DAE(hammerstein_cfg["model"])
            integr_cfg = hammerstein_cfg.pop("integrator")
            integr_name = integr_cfg.pop("name")
            integr_klass = getattr(integrators, integr_name)
            # set dt as from data:
            integr_cfg["dt"] = hammerstein_cfg["dt"]
            # init integrator:
            self.H_integrator = integr_klass(dae, **integr_cfg) 
            self.hstein = self.H_integrator.G_u
            ##################################
            self.decomposed = True
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
        # TODO: fix for n_u > 1
        if hasattr(self, "H_integrator"):
            self.actions = pd.DataFrame(
                columns=[self.H_integrator.dae.u]
            )
        else:
            self.actions = pd.DataFrame(
                columns=[self.mpc.u()]
            )
            
        for n in range(self.mpc.delay):
            self.actions.loc[n,:] = 0
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
        if "slack" not in mpc_scaling:
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
        if self.mpc.delay > 0:
            last_n_u = self.get_u_bounds_for_delay(self.mpc.delay)
        else:
            last_n_u = None
        sol, u_prime, x0, raw_sol = self.mpc.solve(
            forecast,
            x0=obs,
            lbx=lbx,
            ubx=ubx,
            params=self.params,
            codegen=self.mpc.codegen,
            return_raw_sol=True, 
            last_n_u=last_n_u
        )
        """
        Assume hammerstein block to only depend on z:
        if all(u_prime.values < 10):
            u = np.array([0]*self.mpc.n_u)
        else:
            # Hammerstein-Wiener:
        """
        if hasattr(self, "H_integrator"):
            try:
                u_val = np.array([
                    self.hstein(
                        1E-8,
                        ca.vertcat(
                            u_prime.values,
                            self.params
                        )
                    )]
                )
            except RuntimeError: # rootfinder fail:
                u_val = np.array([0]*self.mpc.n_u)
            u = u_prime.copy()
            u.index = [self.H_integrator.dae.u]
            u.loc[:] = u_val
        # non-decomposed:
        else:
            u = u_prime
         
        if not self.mpc.solver.stats()["success"]:
            #print(sol)
            pass
        # store current raw sol:
        self.raw_sol = raw_sol
        # store forecast, opt result:
        self.forecasts[self.i] = forecast
        # NB! what about delay here? need to pre-fill actions?
        self.actions.loc[self.i+self.mpc.delay] = np.nan
        self.actions.loc[self.i+self.mpc.delay, :] = u.values
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
                _lbx = np.array([-1e8]*_len)
            if ub_key in forecast.columns:
                _ubx = bounds_forecast[ub_key].values
            else:
                _ubx = np.array([1e8]*_len)
            #lbx = np.append(lbx, _lbx)
            lbs.append(_lbx)
            ubs.append(_ubx)
            #ubx = np.append(ubx, _ubx)
        lbx = np.array(lbs).T.flatten()
        ubx = np.array(ubs).T.flatten()
        return lbx, ubx
    
    def get_u_bounds_for_delay(self, n: int):
        #action_diff = n - len(self.actions)
        #if action_diff > 0: # TODO: fix for n > 1 and u != valve
        #    return np.array([[0]]*self.mpc.n_u)
        #else:
        return self.actions[
            self.i+self.mpc.delay-n:self.i+self.mpc.delay
        ].values
        
        
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
        include_all: bool = False,
        backshift: list = [],
        integrate_replace: dict[str, str] = {}
    ):         
        tf = k*self.dt
        #tf = k*self.dt + self.dt
        if include_all:
            ts = 0 
        else:
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
        y_data["phi_int"] = y_data["InternalGainsRad[1]"] + y_data["InternalGainsLat[1]"] + y_data["InternalGainsCon[1]"]
        return y_data
            
    """
    TODO: modularize:
    """
    def get_estimation_parameters(
        self
    ):
        Q = ca.DM.eye(self.estimator.n_x)*0
        R = ca.DM.eye(self.estimator.n_y)
        try: # TODO: to config:
            #R[1,1] = 1e-5 # config / learnable
            R[1,1] = -5 # config / learnable
            #R[2,2] = 1e-5 # config / learnable
        except:
            pass
        #P0 = np.eye(self.estimator.n_p + self.estimator.n_x)*1e-8 # config / learnable
        #P0 = np.eye(self.estimator.n_p + self.estimator.n_x)*0 # config / learnable
        #P0 = np.eye(self.estimator.n_p + self.estimator.n_x)*1 # config / learnable
        P0 = np.eye(self.estimator.n_p + self.estimator.n_x)*0 # config / learnable

        P0[
        self.estimator.n_p:(self.estimator.n_p + self.estimator.n_x),
        self.estimator.n_p:(self.estimator.n_p + self.estimator.n_x)
        ] = -5 # config setting: opts (0, EKF smoothing update, identity, learnable)
        
        lbp = self.estimator.get_lbp(1e-3)
        ubp = self.estimator.get_ubp(1e3)
        p0 = self.estimator.p0
        return Q, R, P0, lbp, ubp, p0
    
    
    ### TODO: simulate with existing model
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
        if self.ests == {}:
            if self.estimator.n_x == 3:
                x_guess = np.array([
                        y_data.y1.values.flatten(),
                        y_data.y1.values.flatten() - 2,
                        y_data.y1.values.flatten() - 280
                ])
            elif self.estimator.n_x == 2:
                x_guess = np.array([
                        y_data.y1.values.flatten(),
                        y_data.y1.values.flatten() - 2
                ])
            elif self.estimator.n_x == 1:
                x_guess = np.array([
                        y_data.y1.values.flatten()
                ])
            else: 
                raise ValueError(".")
            #if isinstance(self.estimator.strategy, SingleShooting):
            if is_single_shooting(self.estimator.strategy):
                last_x_guess = x_guess[:,0]
                x_guess = last_x_guess.reshape((1,self.estimator.n_x))
            else:
                last_x_guess = x_guess[-1,-self.estimator.n_x:]
            return x_guess, last_x_guess
        else:
            #last_est = self.ests[self.i-1]
            last_est = self.ests[self.i - self.adapt_frequency]
            x_guess = last_est[self.estimator.x()][1:].values.reshape(
                (self.estimator.n_x, self.estimator.N-1)
            )
            last_x_guess = x_guess[:, 0]
            # simulate for last guess:
            F = self.estimator.integrator.one_sample
            first_x_guess = np.array(
                F(
                    x0=x_guess[:,-1],
                    z=y_data.loc[self.estimator.N-2, self.estimator.z_names].values,
                    u=y_data.loc[self.estimator.N-2, self.estimator.u_names].values,
                    p=self.params,
                    r=y_data.loc[self.estimator.N-2, self.estimator.r_names].values,
                    d=y_data.loc[self.estimator.N-2, self.estimator.d_names].values
                )["xf"]
            )
            # TODO: fix
            x_guess = np.hstack([x_guess, first_x_guess])
            return x_guess, last_x_guess
    
    
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
        #if self.re_estimation_clause(env.i):
        #if self.re_estimation_clause(k):
        if self.re_estimation_clause(self.i):
            # estimate, set params:
            Q, R, P0, lbp, ubp, p0 = self.get_estimation_parameters()
            y_data = self.get_y_data(
                env,
                self.i,
                #k,
                backshift=env.maps.u,
                integrate_replace=self.integrate_replace
            )
            x_guess, last_x_guess = self.generate_x_guess(
                y_data
            )
            # solve:
            sol, params, raw_sol = self.estimator.solve(
                                        y_data,
                                        p0,
                                        lbp=lbp,
                                        ubp=ubp,
                                        x_guess=x_guess,
                                        covar=ca.veccat(Q, R),
                                        codegen=self.estimator.codegen,
                                        return_raw_sol=True,
                                        P0=P0,
                                        #x_N=x_guess[-1,-self.estimator.n_x:]
                                        x_N=last_x_guess
                                        ) 
            
            """
            ax = sol["rad_219"].plot(color="k", drawstyle="steps-post")
            ax1 = ax.twinx()
            sol["Prad"].plot(drawstyle="steps-post", ax=ax1)
            plt.show()
            
            ax = sol["y1"].plot(color="k", drawstyle="steps-post")
            sol["Ti"].plot(drawstyle="steps-post", ax=ax)
            plt.show()
            """

            # store solution:
            self.ests[k] = sol
            # only change parameters if estimator succeeded:
            if self.estimator.solver.stats()["success"]:
                self.estimator.p0 = params.values
                # from t = k, the parameters are:
                self.params_history.loc[k, :] = params
                # set parameters globally on agent:
                self.params = params.values
                # set parameters on filter:
                self.filter.filter.params = params.values
                # print status:
                status = "succeeded"
                """
                TODO: make more modular:
                """
                if self.decomposed:
                    """
                    u_range = self.mpc.nlp_parser.vars["u"]["range"]
                    self.mpc.ubx[
                        u_range["a"]:u_range["b"]
                    ] = (params["Prad_nom"]/self.scaling["u_nom"])
                    self.mpc.bounds["u"]["ub"] = np.array(
                        [params["Prad_nom"]/self.scaling["u_nom"]]*self.mpc.N
                    )
                    """
                    self.mpc.bounds_cfg["u"]["ubu"] = \
                         [params["Prad_nom"]]
            else:
                status = "failed"
            print("\r", end='\n')
            #print("\033[1A", end="")
            #print("Estimator solve %s 
            print("%s: Estimator solve %s %s" % \
                    (
                     datetime.now().strftime('%Y-%m-%d %H:%M:%S'), \
                     str(k+1),
                     status
                     ), 
                    flush=True, end='')
            print("\033[1A", end="")
            #print("\033[2A", end="")
        
        
    
 
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
            truncate_scaling=False,
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
        self.adapt_frequency = 1
        super().__init__(
            *args,
            **kwargs
        )
        #self.estimator = MHE(
        self.estimator = Estimation(
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
        #mhe_scaling["u_nom"] = [1]
        #mhe_scaling["u_nom_b"] = [0]
        # TODO: revert back:
        #mhe_scaling["slack"] = False
        # TODO: modularize y:
        """
        try:
            mhe_scaling["y_nom"] = mhe_scaling["x_nom"]
            mhe_scaling["y_nom_b"] = mhe_scaling["x_nom_b"]
        except KeyError:
            pass
        """
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
        # TODO: implement AdaptiveGDSolver
        #if self.re_estimation_clause(k):
        if False:
            # latest estimation, latest state:
            x_post_mhe = self.ests[k][self.x()].iloc[-1].values.flatten()
            return x_post_mhe
        return x_post_ekf
            
    
    
class PredictiveAdaptiveAgent(AdaptiveMPCAgent):
    """
    This agent predicts (2,3, ..., M)-steps ahead
    w/ fixed data.
    
    TODO: fix variable horizons.
    """
    def __init__(
        self,
        *args,
        **kwargs
    ) -> None: 
        super().__init__(
            *args,
            **kwargs
        )
        self.F = self.mpc.integrator.chain_integrator()
        self.F_map = self.F.mapaccum(self.mpc.N-1)
    
    def predict(
        self,
        obs: npt.NDArray[Any],
        forecast: pd.DataFrame,
        deterministic: bool = True
    ) -> Tuple[pd.Series, bool]:
        
        sim_forecast = forecast[0:self.mpc.N-1]
        
        """
        Simulate:
        
        TODO: modular way obtain z_guess for integrator
        """
        res = self.F_map(
            x0=obs,
            r=sim_forecast[self.mpc.r_names].values.T,
            p=self.params
        )
        pred = pd.DataFrame(
            columns=self.mpc.x(),
            index=range(1,self.mpc.N),
            data=np.array(
                res["x"]
            ).T
        )
        pred.loc[0] = obs
        pred = pred.sort_index()
        # store forecast, opt result:
        self.forecasts[self.i] = forecast[0:self.mpc.N]
        self.preds[self.i] = pred
        self.i += 1
        return pd.Series([]), False
    
    
    
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