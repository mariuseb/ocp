# %%
#from ast import Param
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
#from ocp.boptest_api import Boptest
#from pprint import pprint
#from ocp.filters import EKF, KalmanBucy
from matplotlib import rc
import os
from copy import deepcopy
#from project1_boptest_gym.examples.test_and_plot import plot_results
#from project1_boptest_gym.boptestGymEnv import BoptestGymEnv
import gymnasium as gym
import numpy.typing as npt
from typing import Any, Optional, Union
from gymnasium.wrappers import TimeLimit
from pprint import pprint
from pathlib import Path
from ocp.config import Config
from typing import Union, Dict, List
from ocp.integrator_factory import integrator_factory
from ocp.gym_utils import get_forecast_df, BoptestGymABC
from ocp.maps import BoptestMaps

"""
integrator: Union[Path, dict] = dict(),
model: Union[Path, dict] = dict(),
step_period: int = 900,
parameters: npt.NDArray[np.floating] = np.array([]),
maps: Dict[str, Dict[str, str]] = dict(),
"""

class CustomGymEnv(gym.Env, BoptestGymABC):
    """A simple simulator."""
    
    def __init__(
        self,
        integrator: Union[
            Path, dict
        ] = dict(),
        model: Union[
            Path, dict
        ] = dict(),
        step_period: int = 900,
        parameters: npt.NDArray[np.floating] = np.array([]),
        maps: Dict[str, Dict[str, str]] = dict(),
        R: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        Q: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        resource_path: Path = Path("Resources")
    ):
        self.step_period = integrator["dt"] = step_period
        self.params = parameters
        self.integrator = integrator_factory.create(
            integrator["name"],
            model=model,
            integrator=integrator
        )
        self.maps = BoptestMaps(
            maps
        )
        self.data = get_forecast_df(
            resource_path,
            self.step_period
        )
        # set time:
        self.time = 0
        # set empty history:
        self.res = pd.DataFrame(
            columns=self.x + self.u # + self.r # + self.bound_cols
        )
        self.init_rng()
        self.handle_noise(
            R,
            Q
        )

    def handle_noise(
        self,
        R: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        Q: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
    ):
        # set noise:
        if R is None:
            self.R = np.eye(self.integrator.dae.n_y)*0
        else:
            self.R = R
        if Q is None:
            self.Q = np.eye(self.integrator.dae.n_x)*0
        else:
            self.Q = Q
            
    def sample_Q(self):
        return self.rng.multivariate_normal(
            [0]*self.integrator.dae.n_x,
            self.Q
        )
    
    def sample_R(self):
        return self.rng.multivariate_normal(
            [0]*self.integrator.dae.n_y,
            self.R
        )
        
    def init_rng(self):
        self.rng = np.random.default_rng(np.random.MT19937(seed=0))

    @property
    def F(self) -> ca.Function:
        return self.integrator.one_sample
    
    @property
    def n_x(self) -> int:
        return self.integrator.nx
    
    @property
    def r(self) -> List[str]:
        return self.integrator.dae.r_names
    
    @property
    def u(self) -> List[str]:
        return self.integrator.dae.u
    
    @property
    def x(self) -> List[str]:
        return self.integrator.dae.x
    
    @property
    def boptest_to_ocp(self) -> Dict[str, str]:
        return self.maps.boptest_to_ocp
                 
    def reset(
        self,
        *,
        seed: Optional[int] = None,
        options: Optional[dict[str, Any]] = None,
    ) -> tuple[npt.NDArray[np.floating], dict[str, Any]]:
        """Resets the state of the LTI system."""
        super().reset(seed=seed, options=options)
        s, _ = self.set_state(np.array([293.15]*self.n_x))
        # TODO: keep history:
        #self.df = pd.DataFrame(columns=["phi_h", "Ta", "phi_s"])
        self.store_current_state()
        return s, {}

    """
    def get_stage_cost(self, state: npt.NDArray[np.floating], action: float) -> float:
        lb, ub = self.x_bnd
        return float(
            0.5 * 1E1 * np.square((state[0] - kwargs["x_nom_b"])/kwargs["x_nom"] - 0.75).sum()
            + 0.5 * (action/kwargs["u_nom"])**2
            + self.w.T @ np.maximum(0, lb - state)
            + self.w.T @ np.maximum(0, state - ub)
        )
    """
        
    def set_state(self, obs):
        #self.x = np.asarray([296.15, 296.15]).reshape(self.nx, 1)
        self.s = obs
        return self.s, {}
        
    def get_forecast(
        self,
        dt: int,
        N: int 
    ) -> pd.DataFrame:
        return self.data.loc[
            self.time:(self.time + self.step_period*N)
        ].rename(
            columns=self.boptest_to_ocp   
        )
        
    def _get_results(
        self,
        tf,
        ts=0,
        resample=True
    ) -> pd.DataFrame:
        return self.res.loc[ts:tf].rename(
            columns=self.boptest_to_ocp
        )
        
    """
    def get_bound_cols(
        self,
    ):
        return [col for col in self.data.columns if "Setp" in col]
    """
    
    def store_current_state(
        self
    ):
        self.res.loc[self.time] = np.nan
        self.res.loc[self.time, self.x] = self.s
        
    def store_controls(
        self, 
        action: npt.NDArray[np.floating]
    ):
        self.res.loc[self.time, self.u] = action
    
    def store_disturbance(
        self, 
        r: npt.NDArray[np.floating]
    ):
        self.res.loc[self.time, self.r] = r
    
    def store_bounds(
        self, 
        bounds: npt.NDArray[np.floating]
    ):
        self.res.loc[self.time, self.bound_cols] = bounds
        
    def step(
        self,
        action: npt.NDArray[np.floating]
    ) -> tuple[
        npt.NDArray[np.floating],
        float,
        bool, 
        bool,
        dict[str, Any]
    ]:
        r = self.data.rename(
                columns=self.boptest_to_ocp
            ).loc[self.time, self.r].values
        """
        self.store_disturbance(r)
        self.store_bounds(
            self.data[self.bound_cols].rename(
                columns=self.boptest_to_ocp
            ).loc[self.time].values
        )
        """
        self.store_controls(action)
        s_prime = np.array(
            self.F(
            self.s,
            np.array([]),
            action, 
            self.params,
            r,
            np.array([])
            )
        ).flatten()
        self.s = s_prime
        self.time += self.step_period
        self.store_current_state()
        # stage cost zero for now:
        # add noise. first process, then measurement
        s_prime += self.sample_Q()
        # store?
        s_prime += self.sample_R()
        # store?
        return s_prime, 0, False, False, {}


 