#from casadi import *
#import casadi as ca
#from abc import ABC, abstractmethod, ABCMeta
import numpy as np
from ocp.integrators import *
from ocp.dae import DAE

class IntegratorFactory(object):
    def __init__(self):
        self._builders = {}
        
    def register_builder(self, key, builder):
            self._builders[key] = builder

    def create(self, key, **kwargs):
        builder = self._builders.get(key)
        if not builder:
            raise ValueError(key)
        return builder(
            DAE(kwargs["model"]),
            **kwargs["integrator"]
        )
 
integrator_factory = IntegratorFactory()
integrator_factory.register_builder("RK4", RK4)
integrator_factory.register_builder("IRK", IRK)
integrator_factory.register_builder("Cvodes", Cvodes)
integrator_factory.register_builder("idas", idas)