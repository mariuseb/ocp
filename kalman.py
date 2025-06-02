#from lib.core.ocp import OCP
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import pdb
import casadi as ca
import os
import json
from ocp.dae import DAE
import ocp.integrators as integrators
from abc import ABC, abstractmethod, ABCMeta
from copy import deepcopy
from scipy.linalg import expm
import numpy.typing as npt
from typing import Union, Dict, Tuple
#import pathlib
from ocp.config import Config
#from ocp.integrator_factory import integrator_factory
#from pathlib import Path
from ocp.filters_abstract import AbstractKalmanFilter, DiscreteTimeCovarianceDynamics

# NOTE: discrete-time covariance:

class KalmanFilter(
    AbstractKalmanFilter, 
    DiscreteTimeCovarianceDynamics
):
    """
    A concrete implementation of the
    Kalman filter.
    """
    def __init__(self, *args, **kwargs):
       super(KalmanFilter, self).__init__(
           *args,
           **kwargs
        )
       #self.set_one_sample_state()
       #self.set_one_sample_state_covariance(
       #    self.n_x
       #)
       self.set_dynamics()
       
    def set_dynamics(
        self
    ) -> None:
        self.A = self.dae.get_Ad(
            self.dt, 
            p=self.params
        )
        self.B = self.dae.get_Bd(
            self.dt, 
            p=self.params
        )
        self.C = self.dae.get_C()
    
    def _set_one_sample_state(
        self
    ):
        """
        KF yields simplified
        state dynamics. Set 
        up ca.Function that
        reflects this.
        """
        # concatenate u, r:
        n_u = self.n_u + self.n_r
        A = ca.SX.sym("A", self.n_x, self.n_x)
        B = ca.SX.sym("A", n_u, n_u)
        x0 = ca.SX.sym("x0", self.n_x)
        u = ca.SX.sym("u", n_u)
        next_state_expr = A@x0 + B@u
        self.one_sample_state = ca.Function(
            "one_sample_state",
            [A, B, x0, u],
            [next_state_expr],
            ["A", "B", "x0", "u"],
            ["x"]
        )
    
    
    # TODO: make this compliant
    # w/ _set_one_sample_feedback
    def predict_state(
        self,
        u: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        self.x = np.array(
            self.one_sample_state(
                self.A,
                self.B,
                self.x,
                u
            ),
            dtype=np.float64
        ).flatten()
        return self.x
        
    def predict_state_covariance(
        self,
        u: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        self.P = np.array(
            self.one_sample_state_covariance(
                self.A,
                self.P,
                self.Q
            ),
            dtype=np.float64
        )
        return self.P
        
    def update_state(
        self,
        y: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        V = np.array(
            self.output_covariance(
                self.C,
                self.P,
                self.R
            ),
            dtype=np.float64
        )
        self.K = np.array(
            self.kalman_gain( 
                self.C,
                self.P,
                V
            ),
            dtype=np.float64
        )
        self.x = np.array(
            self.state_correction(
                y,
                self.x,
                self.C,
                self.K
            ),
            dtype=np.float64
        ).flatten()
        return self.x
    
    def update_state_covariance(
        self,
        y: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        self.P = np.array(
            self.state_covariance_correction(
                self.C,
                self.P,
                self.K
            ),
            dtype=np.float64
        )
        return self.P

    def predict(
        self,
        u: npt.NDArray[np.float64]
    ) -> Tuple[
        npt.NDArray[np.float64],
        npt.NDArray[np.float64]
    ]:   
        x = self.predict_state(u)
        P = self.predict_state_covariance(u)
        return x, P
    
    def update(
        self,
        y: npt.NDArray[np.float64]
    ) -> Tuple[
        npt.NDArray[np.float64],
        npt.NDArray[np.float64]
    ]:   
        x = self.update_state(y)
        P = self.update_state_covariance(y)
        return x, P
    
    """
    Full pass (numerical or symbolic).
    """
    def estimate(
        
    ) -> :
    