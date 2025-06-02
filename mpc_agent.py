#from ast import Param
from ocp.mpc import MPC
#from ocp.filters import KalmanDAE
import numpy as np
import numpy.typing as npt
from matplotlib import rc
import pandas as pd
from copy import deepcopy
from typing import Tuple, Any
#import os
import pathlib
from ocp.filter_wrapper import FilterWrapper
from itertools import product
rc('mathtext', default='regular')


class MPCAgent(object): 
    
    # TODO: move below to config:
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 5000,
        "r_nom": 12,
        "r_nom_b": 289.15,
        "y_nom": 12,
        "y_nom_b": 289.15,
        "slack": True
        #"slack": False
    }
    
    def __init__(
        self,
        mpc_cfg: pathlib.Path,
        filter_type: str,
        filter_cfg: pathlib.Path,
        params: npt.NDArray[Any]
    ) -> None:
        self.params = params
        self.mpc = MPC(
            config=mpc_cfg,
            param_guess=self.params,
            **deepcopy(self.kwargs)
        )  # to remove, replace with N
        """
        if ekf_cfg != "":
            self.ekf = KalmanDAE(ekf_cfg)
        """
        self.filter = FilterWrapper(
            filter_cfg,
            filter_type
        )
        self.i = 0
        self.preds = dict()
        self.forecasts = dict()
        self._init_state_history()
        self._init_covar_history()
        
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
        sol, u, x0 = self.mpc.solve(
            forecast,
            x0=obs,
            lbx=lbx,
            ubx=ubx,
            params=self.params,
            codegen=True
        )
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
        lbx, ubx = np.array([]), np.array([])
        for state in self.mpc.x():
            lb_key = state + "_lb"
            ub_key = state + "_ub"
            if lb_key in forecast.columns:
                _lbx = bounds_forecast[lb_key]
            else:
                _lbx = [-np.inf]*_len
            if ub_key in forecast.columns:
                _ubx = bounds_forecast[ub_key]
            else:
                _ubx = [np.inf]*_len    
            lbx = np.append(lbx, _lbx)
            ubx = np.append(ubx, _ubx)
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
        obs: npt.NDArray[Any]
    ):  
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