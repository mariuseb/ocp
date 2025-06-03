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
       
    @property
    def A(self):
        return self._A

    @property
    def B(self):
        return self._B
    
    @property
    def C(self):
        return self._C
    
    @A.setter
    def A(self, A: npt.NDArray[np.float64]):
        self._A = A

    @B.setter
    def B(self, B: npt.NDArray[np.float64]):
        self._B = B
    
    @C.setter
    def C(self, C: npt.NDArray[np.float64]):
        self._C = C
    
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
        
class ExtendedKalmanFilter(
    AbstractKalmanFilter, 
    DiscreteTimeCovarianceDynamics
):
    """
    A concrete implementation of the
    Kalman filter.
    """
    def __init__(self, *args, **kwargs):
       super(ExtendedKalmanFilter, self).__init__(
           *args,
           **kwargs
        )
       self.__set_one_sample_state_feedback()
    
    def _set_one_sample_state(
        self
    ):
        """
        For the EKF, we need
        the full state dynamics:
        """
        self.one_sample_state = \
            self.integrator.one_sample
    
    @property
    def A(self):
        return self.dae.get_Ad(
            self.dt, 
            p=self.params,
            x=self.x_prev  
        )
    
    @property
    def C(self):
        return self.dae.get_C()
    
    """
    @property
    def one_sample_state_covariance(self):
        return self._one_sample_state_covariance
    
    @one_sample_state_covariance.setter
    def one_sample_state_covariance(
        self,
        one_sample_state_covariance: ca.Function
    ): # Abstract setter
        self._one_sample_state_covariance = one_sample_state_covariance
    """
    
    # TODO: make this compliant
    # w/ _set_one_sample_feedback
    def predict_state(
        self,
        u: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        # store x_prev for A:
        self.x_prev = self.x
        self.x = np.array(
            self.one_sample_state(
                self.x,
                0, # ignore z for now
                u[:self.n_u],
                self.params,
                u[self.n_u:],
                0
            ),
            dtype=np.float64
        ).flatten()
        return self.x
    
    def _init_symbols_one_sample(
        self
    ):
        x0 = ca.MX.sym("x0", self.n_x)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("u", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)
        Q = ca.MX.sym("Q", self.n_x, self.n_x)
        R = ca.MX.sym("R", self.n_y, self.n_y)
        P0 = ca.MX.sym("P0", self.n_y, self.n_y)
        return x0, u, p, r, y, Q, R, P0
    
    def __set_one_sample_state_feedback(
        self
    ) -> None:
        x0, u, p, r, y, Q, R, P0 = self._init_symbols_one_sample()
        x_prior = self.one_sample_state(
            x0, 0, u, p, r, 0
        )
        # obtain df/dx linearized at t=k-1:
        A = self.jac_f_x(
            x0,0,u,p,r,y,ca.MX(),ca.MX(),ca.MX()
        )
        # obtain linearization of h(x) (usually just [1, 0, ..., 0]):
        C = self.jac_h(
            x0,0,u,p,r,y,ca.MX(),ca.MX(),ca.MX()
        )
        Ad = ca.expm(A*self.dt)
        P_prior = self.one_sample_state_covariance(
            Ad, P0, Q
        )
        V = self.output_covariance(
            C, P_prior, R
        )
        K = self.kalman_gain(
            C, P_prior, V
        )
        state_corr = self.state_correction(
            y, x_prior, C, K
        )
        x_posterior, e = state_corr[0], state_corr[1]
        P_posterior = self.state_covariance_correction(
            C, K, P_prior
        )
        loglik = (1/2)*(self.log_det_R(V) + e.T@ca.inv(V)@e + self.n_y*ca.log(2*ca.pi))
        self.one_sample_state_feedback = ca.Function(
            "F",
            [x0, P0, u, p, r, y, Q, R],
            [x_posterior, P_posterior, loglik],
            ["x0","P0","u","p","r","y","Q","R"],
            ["x_posterior", "P_posterior", "loglik"],
        )
        
        