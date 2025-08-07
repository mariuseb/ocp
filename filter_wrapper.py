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
from copy import deepcopy
from ocp.functions import functions
from scipy.linalg import expm
from ocp.config import Config
from typing import Tuple, Union
import numpy.typing as npt
import importlib
import pathlib

class FilterWrapper(object):
    """
    Abstraction layer over FilterPy and
    own implementations for use in 
    Coordinator.
    """
    def __init__(
        self,
        cfg: Union[Config, dict, pathlib.Path],
        _type: str
    ) -> None:
        if not isinstance(cfg, Config):
            cfg = Config()(cfg)
        elems = _type.split(".")
        #module = __import__(".".join(elems[:-1]))
        module = importlib.import_module(".".join(elems[:-1]))
        _init = getattr(module, elems[-1])
        dae_cfg = cfg["model"]
        dae_cfg["functions"] = functions
        self.dae = dae = DAE(
            dae_cfg
        )
        if "filterpy" in module.__name__:
            dim_x = dae.n_x
            dim_u = dae.n_u + dae.n_r
            dim_z = dae.n_y
            self.filter = _init(
                dim_x=dim_x,
                dim_u=dim_u,
                dim_z=dim_z        
            )
            self.set_dynamics_filterpy(cfg)
            # TODO: modularize:
            self.set_covariances(cfg)
            self.set_x0(cfg["x0"])
        else: # own implementations
            self.filter = _init(
                **dict(
                    deepcopy(cfg)
                    )
                )
    
    def set_x0(self, x0):
        self.filter.x = x0
    
    @property
    def x_current(self):
        return self.filter.x
     
    @property
    def u(self):
        return self.dae.u

    @property
    def r(self):
        return self.dae.r_names
    
    @property
    def x(self):
        return self.dae.x
            
    def set_covariances(self, cfg):
        self.filter.P = cfg["P0"]
        self.filter.R = cfg["R"]
        self.filter.Q = cfg["Q"]
        
    def set_dynamics_filterpy(self, cfg):
        self.filter.F = self.dae.get_Ad(
            cfg["dt"],
            p=cfg["parameters"]
        )
        self.filter.B = self.dae.get_Bd(
            cfg["dt"],
            p=cfg["parameters"]
        )
        self.filter.H = self.dae.get_C()
        
    def predict(
        self,
        u: npt.NDArray[np.float64],
        r: npt.NDArray[np.float64]
    ) -> Tuple[
        npt.NDArray[np.float64],
        npt.NDArray[np.float64]
    ]:
        kf_u = np.concatenate([
            u,
            r
        ])
        self.filter.predict(kf_u)
        return self.filter.x, self.filter.P
        
    
    def update(
        self,
        y: npt.NDArray[np.float64]
    ) -> Tuple[
        npt.NDArray[np.float64],
        npt.NDArray[np.float64]
    ]: 
        self.filter.update(y)
        return self.filter.x, self.filter.P