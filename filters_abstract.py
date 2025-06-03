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
from ocp.integrator_factory import integrator_factory
from pathlib import Path

class DiscreteTimeCovarianceDynamics(object):
    """ . """
    
    def _set_one_sample_state_covariance(
        self
    ):
        # TODO: this belongs to a general discrete-time filter class???
        # concatenate u, r:
        n_x = self.n_x
        A = ca.SX.sym(
            "A",
            n_x,
            n_x
        )
        P0 = ca.SX.sym(
            "P0", 
            n_x,
            n_x
        )
        Q = ca.SX.sym(
            "Q",
            n_x,
            n_x
        )
        next_state_covariance_expr = A@P0@A.T + Q
        self._one_sample_state_covariance = ca.Function(
            "one_sample_state",
            [A, P0, Q],
            [next_state_covariance_expr],
            ["A", "P0", "Q"],
            ["x"]
        )

class AbstractKalmanFilter(metaclass=ABCMeta):
    
    @abstractmethod 
    def __init__(
        self,
        dt: int,
        integrator: dict,
        model: dict,
        parameters: 
            npt.NDArray[np.floating] 
            = np.array([]),
        R: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        Q: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        x0: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        P0: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
    ):
        self.dt = dt
        self.params = parameters
        self.integrator = integrator_factory.create(
            integrator["name"],
            model=model,
            integrator=integrator
        )
        self.init_vars()
        self.init_filter(
            R=R,
            Q=Q,
            x0=x0,
            P0=P0
        )
    
    """
    @property
    @abstractmethod
    def one_sample_state(self):
        raise NotImplementedError
    
    @one_sample_state.setter
    @abstractmethod # The innermost decorator
    def one_sample_state(
        self,
        one_sample_state: ca.Function
    ): # Abstract setter
        pass

    @property
    @abstractmethod
    def one_sample_state_covariance(self):
        raise NotImplementedError
    
    @one_sample_state_covariance.setter
    @abstractmethod # The innermost decorator
    def one_sample_state_covariance(
        self,
        one_sample_state_covariance: ca.Function
    ): # Abstract setter
        pass
    
    @property
    @abstractmethod
    def x(self):
        raise NotImplementedError
    
    
    @x.setter
    @abstractmethod # The innermost decorator
    def x(self, x: npt.NDArray[np.float64]): # Abstract setter
        pass
    
    @property
    @abstractmethod
    def P(self):
        raise NotImplementedError
    
    
    @P.setter
    @abstractmethod # The innermost decorator
    def P(self, P: npt.NDArray[np.float64]): # Abstract setter
        pass
    """
    @property
    @abstractmethod
    def A(self):
        raise NotImplementedError
    
    @property
    @abstractmethod
    def C(self):
        raise NotImplementedError
    
    """
    @property
    @abstractmethod
    def one_sample_state_covariance(self):
        raise NotImplementedError
    
    @one_sample_state_covariance.setter
    @abstractmethod # The innermost decorator
    def one_sample_state_covariance(
        self,
        one_sample_state_covariance: ca.Function
    ): # Abstract setter
        pass
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
       
    def _set_output_covariance(
        self
    ):
        # concatenate u, r:
        C = ca.SX.sym("C", self.n_y, self.n_y)
        P = ca.SX.sym("P", self.n_x, self.n_x)
        R = ca.SX.sym("Q", self.n_y, self.n_y)
        output_covariance_expr = C@P@C.T + R
        self.output_covariance = ca.Function(
            "output_covariance",
            [C, P, R],
            [output_covariance_expr],
            ["C", "P", "R"],
            ["V"]
        )
        
    def _set_kalman_gain(
        self
    ):
        # concatenate u, r:
        C = ca.SX.sym("C", self.n_y, self.n_y)
        P = ca.SX.sym("P", self.n_x, self.n_x)
        V = ca.SX.sym("Q", self.n_y, self.n_y)
        #R = ca.SX.sym("Q", self.n_y, self.n_y)
        kalman_gain_expr = P@C.T@ca.inv(V)
        self.kalman_gain = ca.Function(
            "kalman_gain",
            [C, P, V],
            [kalman_gain_expr],
            ["C", "P", "V"],
            ["K"]
        )
        
    def _set_state_correction(
        self
    ):
        # concatenate u, r:
        y = ca.SX.sym("y", self.n_y)
        x = ca.SX.sym("x", self.n_x)
        C = ca.SX.sym("C", self.n_y, self.n_y)
        K = ca.SX.sym("K", self.n_x, self.n_x)
        #R = ca.SX.sym("Q", self.n_y, self.n_y)
        e = y - C@x
        state_correction_expr = x + K@e
        self.state_correction = ca.Function(
            "state_correction",
            [y, x, C, K],
            [state_correction_expr, e],
            ["y", "x_prior", "C", "K"],
            ["x_post", "e"]
        )

    def _set_state_covar_correction(
        self
    ):
        # concatenate u, r:
        C = ca.SX.sym("C", self.n_y, self.n_y)
        K = ca.SX.sym("K", self.n_x, self.n_x)
        P = ca.SX.sym("K", self.n_x, self.n_x)
        #R = ca.SX.sym("Q", self.n_y, self.n_y)
        state_covariance_correction_expr = \
            (ca.SX.eye(self.n_x) - K@C)@P
        self.state_covariance_correction = ca.Function(
            "state_correction",
            [C, K, P],
            [state_covariance_correction_expr],
            ["C", "K", "P_prior"],
            ["P_post"]
        )
      
    """
    def _set_one_sample_feedback(
        self
    ) -> None:
        # Initializations:
        x0 = ca.SX.sym("x0", self.n_x)
        u = ca.SX.sym("u", self.n_u)
        p = ca.SX.sym("p", self.n_p)
        y = ca.SX.sym("y", self.n_y)
        Q = ca.SX.sym("Q", self.n_x, self.n_x)
        R = ca.SX.sym("R", self.n_y, self.n_y)
        P0 = ca.SX.sym("P0", self.n_y, self.n_y)
        # Function-calls:
        # if predict 
        x_prior = self.one_sample_state(
            ...
        )
        P_prior = self.one_sample_state_covariance(
            A, P0, Q
        )
    """  
            
    def init_filter(
        self,
        R: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        Q: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        x0: Union[
            npt.NDArray[np.floating],
            None
        ] = None,
        P0: Union[
            npt.NDArray[np.floating],
            None
        ] = None,        
    ):
        if R is not None:
            self.R = R
        if Q is not None:
            self.Q = Q
        if x0 is not None:
            self.x = x0
        if P0 is not None:
            self.P = P0
            
        hidden_setters = [
            getattr(self, name) for name in dir(self)
            #name for name in dir(self)
            if name.startswith("_set_") \
                or \
                name.startswith("_init_")
                and \
            callable(getattr(self, name))
        ]
        for method in hidden_setters:
            method()
     
    def __setattr__(self, name, value):
        if name in ("Q", "R", "P", "x"):
            value = np.array(value)
            if name in ("Q", "P"):
                shape = (self.n_x, self.n_x)
            elif name == "R":
                shape = (self.n_y, self.n_y)
            else: # x
                shape = (self.n_x, )
            assert value.shape == shape, "The shape of " + \
                f"""{name} should be {shape}, not {value.shape}"""
        super(AbstractKalmanFilter, self).__setattr__(name, value)
    
    @abstractmethod
    def predict_state(
        self,
        u: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        pass
    
    
    """
    @abstractmethod
    def predict(
        self,
        u: npt.NDArray[np.float64],
        #r: npt.NDArray[np.float64]
    ) -> Tuple[
        npt.NDArray[np.float64],
        npt.NDArray[np.float64]
    ]:   
        pass
    
    @abstractmethod
    def update(
        self,
        y: npt.NDArray[np.float64]
    ) -> Tuple[
        npt.NDArray[np.float64],
        npt.NDArray[np.float64]
    ]:   
        pass
        
    @abstractmethod
    def predict_state_covariance(
        self,
        u: npt.NDArray[np.float64],
    ) -> npt.NDArray[np.float64]:
        pass
    
    @abstractmethod
    def update_state(
        self,
        y: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        pass
    
    @abstractmethod
    def update_state_covariance(
        self,
        y: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        pass
    """
    
    @property
    def dae(self) -> DAE:
        return self.integrator.dae
    
    @property
    def f(self) -> ca.Function:
        return self.integrator.f
    
    @property
    def h(self) -> ca.Function:
        return ca.Function(
            "h",
            [self.x_symbolic, self.z_symbolic],
            [self.h_expr],
            ["x", "z"],
            ["h"]
        ) 
    
    @property
    def f_expr(self) -> Union[ca.MX, ca.SX]:
        return ca.vertcat(self.integrator.ode)

    @property
    def g_expr(self) -> Union[ca.MX, ca.SX]:
        return ca.vertcat(self.integrator.g_expr)
    
    @property
    def h_expr(self) -> Union[ca.MX, ca.SX]:
        #self.h_expr = ca.vertcat(self.integrator.h_expr)
        # CORRECTION:
        return ca.vertcat(*self.dae.dae.ydef())
    
    #@property
    #def y(self):
    #    return [y.name() for y in self.dae.y.values() if not isinstance(y, (float, int))]

    @property
    def n_y(self):
        return self.integrator.ny
    
    @property
    def n_x(self):
        return self.integrator.nx

    @property
    def n_u(self):
        return self.integrator.nu
    
    @property
    def n_r(self):
        return self.integrator.nr
    
    @property
    def n_d(self):
        return self.integrator.nd
    
    @property
    def n_z(self):
        return self.integrator.nz
    
    @property
    def n_p(self):
        return self.integrator.np

    @property
    def x_symbolic(self):
        return self.integrator.x
    
    @property
    def z_symbolic(self):
        return self.integrator.z
    
    @property
    def u_symbolic(self):
        return self.integrator.u

    @property
    def jac_f_x_expr(self):
        return ca.jacobian(self.f_expr, self.x_symbolic)

    @property
    def jac_f_u_expr(self):
        return ca.jacobian(self.f_expr, self.u_symbolic)
    
    @property
    def jac_g_z_expr(self):
        try:
            return ca.jacobian(self.g_expr, self.z_symbolic)
        except RuntimeError:
            return ca.MX()
        
    @property
    def jac_f_z_expr(self):
        try:
            return ca.jacobian(self.f_expr, self.z_symbolic)
        except RuntimeError:
            return ca.MX()
    
    @property
    def jac_g_x_expr(self):
        try:
            return ca.jacobian(self.g_expr, self.x_symbolic)
        except RuntimeError:
            return ca.MX()

    @property
    def jac_h_x(self):
        #return ca.jacobian(self.h_expr, self.x_symbolic)      
        # CORRRECTION:
        #return ca.jacobian(self.h_expr, ca.vertcat(self.x_symbolic, self.z_symbolic))
        return ca.jacobian(self.h_expr, ca.vertcat(self.x_symbolic))
    
    def init_vars(self):
        all_vars = []
        all_names = []
        for name in self.integrator.all_vars:
            var = getattr(self.integrator, name)
            if isinstance(var, (ca.MX, ca.SX)):
                all_vars.append(var)
            else:
                all_vars.append(ca.MX())
            all_names.append(name)        
        self.all_vars = all_vars
        self.all_names = all_names
        
    def _init_jac_f_x(self):
        self.jac_f_x = ca.Function(
            'jac_f_x',
            self.all_vars,
            [self.jac_f_x_expr],
            self.all_names,
            ['jac_f_x']
        ) 
    
    def _init_jac_f_u(self):
        self.jac_f_u = ca.Function(
            'jac_f_u',
            self.all_vars,
            [self.jac_f_u_expr],
            self.all_names,
            ['jac_f_u']
        ) 
    
    def _init_jac_f_z(self):
        self.jac_f_z = ca.Function(
            'jac_f_z',
            self.all_vars,
            [self.jac_f_z_expr],
            self.all_names,
            ['jac_f_z']
        ) 
        
    def _init_jac_g_x(self):
        self.jac_g_x = ca.Function(
            'jac_g_x',
            self.all_vars,
            [self.jac_g_x_expr],
            self.all_names,
            ['jac_g_x']
        ) 
    
    def _init_jac_g_z(self):
        self.jac_g_z = ca.Function(
            'jac_g_z',
            self.all_vars,
            [self.jac_g_z_expr],
            self.all_names,
            ['jac_g_z']
        ) 
        
    def _init_jac_h_x(self):
        self.jac_h = ca.Function(
            'jac_h',
            self.all_vars,
            [self.jac_h_x],
            self.all_names,
            ['jac_h']
        )
        
    def _set_log_det(
            self,
        ):
        """
        For covariance estimation.
        (negative log-likelihood) 
        """ 
        Q_SX = ca.SX.sym(
            "Q",
            self.n_x,
            self.n_x
        )
        R_SX = ca.SX.sym(
            "R",
            self.n_y, 
            self.n_y
        )
        # for Q:
        self.log_det_Q = ca.Function(
            "log_det_Q",
            [Q_SX],
            [ca.trace(ca.log(ca.qr(Q_SX)[1]))],
            ["Q"],
            ["log(det(Q))"]                        
        )
        # for R:
        self.log_det_R = ca.Function(
            "log_det_R",
            [R_SX],
            [ca.trace(ca.log(ca.qr(R_SX)[1]))],
            ["Q"],
            ["log(det(R))"]                        
        )
        #return log_det_Q, log_det_R
    
    def predict_state_covariance(
        self,
        u: npt.NDArray[np.float64]
    ) -> npt.NDArray[np.float64]:
        self.P = np.array(
            self.one_sample_state_covariance(
                self.A, # might need to take at previous state
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
        """
        self.x = np.array(
            self.state_correction(
                y,
                self.x,
                self.C,
                self.K
            ),
            dtype=np.float64
        ).flatten()
        """
        state_corr = self.state_correction(
            y,
            self.x,
            self.C,
            self.K
            
        )
        self.x = np.array(
            state_corr[0],
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
        x, e = self.update_state(y)
        P = self.update_state_covariance(y)
        return x, P
        
    
    