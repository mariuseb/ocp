#from ast import Param
from ocp.mpc import MPC
from ocp.filters import KalmanDAE
import numpy as np
import numpy.typing as npt
from matplotlib import rc
import pandas as pd
from copy import deepcopy
from typing import Tuple, Any
import os
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
        mpc_cfg: os.PathLike,
        ekf_cfg: os.PathLike,
        params: npt.NDArray[Any]
        ) -> None:
        self.params = params
        self.mpc = MPC(
            config=mpc_cfg,
            param_guess=self.params, 
            **deepcopy(self.kwargs)
        )  # to remove, replace with N
        if ekf_cfg != "":
            self.ekf = KalmanDAE(ekf_cfg)
        self.i = 0
        self.preds = dict()
        self.forecasts = dict()
        
    @property
    def dt(self):
        return self.mpc.dt
    
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
    
    def x0_from_obs(
        self,
        obs: npt.NDArray[Any]
    ):
        """
        Generally, dim(obs) < dim(x).
        Need filtering.
        """
        x_pred = self.preds[self.i-1].iloc[1][self.ekf.dae.x].values
        # Need to generalize the below:
        u_model = self.preds[self.i-1].iloc[0][self.ekf.dae.u].values
        r_pred = self.forecasts[self.i-1].iloc[0][self.ekf.dae.r_names].values
        #y_z_meas = [y_meas[name] for name in ekf.y]
        x0, z, y = self.ekf.estimate(
                                x_pred, 
                                #z=sol.loc[0, mpc.z_names].values,
                                p=self.params,
                                y=obs, 
                                u=u_model, 
                                r=r_pred
                                )
        return x0