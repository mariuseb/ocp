from argparse import ArgumentError
import casadi as ca
from casadi import *
from abc import ABC, abstractmethod, ABCMeta
import pandas as pd
#pd.set_option("display.precision", 8)
import numpy as np
#np.set_printoptions(precision=10)
import json
import sys
import pdb
import pprint
from shooting import MultipleShooting, SingleShooting

#from tables import Col
#from integrators import RungeKutta4, Cvodes, IRK
import integrators
from dae import DAE
#from shooting import MultipleShooting
#from callback import ProcessIdCallback
import os
#from shooting import Collocation
#from sysid.ocp import OCP
#import typing


class ParameterEstimation(object):
    """
    Estimate parameters of a system
    on the form:
        
        dx/dt = f(x, u, p) + w  (1)
        y = h(x) + v            (2)
        
    i.e. solve the optimization problem:

        min_(v,w,p) ||v||_R^{n} + ||w||_Q^{n}
            s.t. 1, 2
            p_lb <= p <= p_ub
        
        where n is some norm-funtion (1-norm, 2-norm, Hubert penaly)
    
    (TODO: expand to handle problems on the form:
            dx/dt = f(x, z, u, p, w)  (1)
            0 = g(x, z, u, p, w)      (2)
            y = h(x, p, v)            (3)
     
    more specifically DAE-systems of index 1.)
    
    
    parameters:
        model: 
            dict - describes the system structure
        method: 
            str - (multiple_shooting, single_shooting,
                   collocation)
        integrator: 
            dict - functional integrating system 1-2 
                   from t=k to t=k+1
        opt:
            dict - solver settings (for ipopt)
        codegen:
            bool - jit-compilation for 
                   function-evaluations
        
        or
            config-file containing all of the above
            
        ##################################################
        
        data:
            pd.DataFrame - describes measurement data, 
                           sampling time
        
        Q:
            casadi.DM - weighting of process noise
        R:
            casadi.DM - weighting of measurement noise

    """
    def __init__(
                self, 
                config,
                data,
                param_guess,
                Q=None,
                R=None
                ):
        
        if isinstance(config, str) or isinstance(config, os.PathLike):
            with open(config, "r") as f:
                config = json.load(f)

        self.dae = dae = DAE(config["model"])
        self.data = data

        # NOTE: review this. 
        # option to also provide via constructor?
        if isinstance(data, pd.DataFrame):
            self.dt = dt = data.index[1] - data.index[0]
            # need?
            N = len(data)

        self.method = config.pop("method")
        integr_cfg = config.pop("integrator")

        if self.method in ("multiple_shooting",
                           "single_shooting"): # haven't implemented SS yet
            
            integr_name = integr_cfg.pop("name")
            integr_klass = getattr(integrators, integr_name)
            # set dt as from data:
            integr_cfg["dt"] = dt
            # init integrator:
            self.integrator = integr_klass(dae, **integr_cfg) 
        else: 
            """
            collocation method:
                not sure if there is a point in implementing this,
                as cpu time will explode for large problems without
                map-operations
            """
            pdb.set_trace()

        if R is None:
            self.R = ca.DM.eye(self.dae.n_y)
        
        if Q is None:
            self.Q = ca.DM.eye(self.dae.n_x)
            
        # for discretization:
        self.scale = self.get_scale(param_guess)

        # separate data:
        self.U, self.Y = self.separate_data(data)

        if self.method == "multiple_shooting":
            #self.strategy = MultipleShooting(self.integrator, self.U, self.Y, self.Q, self.R, N, scale)
            self.strategy = MultipleShooting(self.integrator, self.Q, self.R, N, self.scale)
        elif self.method == "single_shooting":
            self.strategy = SingleShooting(integrator, data, Q, R)

        if config["codegen"]:
            self.with_jit = True
            compiler = "shell"
        else:
            self.with_jit = False
            compiler = ""
        
        """
        NOTE: shooting should return variable ordering
        for setting bounds.
        """
        self.nlp, self.nlp_parser = self.strategy.transcribe_nlp()
                
        '''         
        with open('module.txt', 'w+') as out:
        pp = pprint.PrettyPrinter(indent=4,stream=out)
        pp.pprint(self.nlp)  
        '''
    
        self.opt = opt = config["opt"]
        
        # ?
        #self.set_bounds(y=self.Y,
        #                u=self.U)
        self.set_bounds(y=self.Y,
                        u=self.U)
        
        self.solver = nlpsol(
                            "solver", \
                             "ipopt", \
                             self.nlp, \
                             #dict(hess_lag=hessLag, \
                             dict(
                                  jit=self.with_jit, \
                                  compiler=compiler, \
                                  **opt)
                            )
        
        
    """
    Below, need to do some work:
    
    First, make it work for only 
    parameter estimation.
    """
    def set_bounds(self, **kwargs):
        
        #(x, z, u, p, w, v, y)
        
        x = kwargs.pop("x", None)
        z = kwargs.pop("z", None)
        u = kwargs.pop("u", None)
        p = kwargs.pop("p", None)
        w = kwargs.pop("w", None)
        v = kwargs.pop("v", None)
        y = kwargs.pop("y", None)
        
        
        # use this and fill rest with -inf and inf
        lbx = np.array([])
        ubx = np.array([])
        x0 = np.array([])
        
        for arr, (k, v) in zip((x, z, u, p, w, v, y), self.nlp_parser.vars.items()):
        #for arr, (k, v) in zip((x, z, p, w, v), self.nlp_parser.vars.items()):
            if arr is None:
                lbx = np.append(lbx, np.repeat([-np.inf], v["dim"]))
                ubx = np.append(ubx, np.repeat([np.inf], v["dim"]))
                x0 = np.append(x0, np.repeat([0], v["dim"]))
            else:
                lbx = np.append(lbx, arr)
                ubx = np.append(ubx, arr)
                x0 = np.append(x0, arr)
         
        self.lbx = lbx       
        self.ubx = ubx       
        self.x0 = x0
        #return lbx, ubx
        
    #def set_x_guess(self, )
            
    def solve(self, param_guess, nlp_p):
        """
        Handle bounds etc. later.
        
        Set initials for v, w to 0
        """
        #x_guess = repmat(self.Y, 1, self.n_x)
        
        # TODO: logic for generating guesses of unmeasured states? 
        
        if self.Y.shape[1] != self.integrator.dae.n_x:
            # do this ( n_x - n_y) times:
            yd = np.diff(self.Y,axis=0)*1/self.dt
            x_guess = horzcat(self.Y, vertcat(yd, yd[-1])).T
        else:
            x_guess = self.Y.T
        
        
        x0 = self.x0 
           
        p_start, p_stop = self.nlp_parser.vars["p"]["range"]["a"], self.nlp_parser.vars["p"]["range"]["b"]
        x_start, x_stop = self.nlp_parser.vars["x"]["range"]["a"], self.nlp_parser.vars["x"]["range"]["b"]
        
        x0[p_start:p_stop] = np.array(param_guess).flatten()/self.get_scale(param_guess)
        x0[x_start:x_stop] = np.array(ca.veccat(x_guess)).flatten()
                
        solution = self.solver(x0=x0, lbg=0, ubg=0, lbx=self.lbx, ubx=self.ubx, p=nlp_p)
        
        parser = self.nlp_parser.vars    
        sol_x = np.array(solution["x"]).flatten()
    
        for i, name in enumerate(self.dae.order):
            
            sub_parser = parser[name]
            start, stop = sub_parser["range"]["a"], sub_parser["range"]["b"]
            attr_name = "n_" + name
            
            if name != "p":
                _vals = np.array(sol_x[start:stop]).reshape((self.N, getattr(self, attr_name)))
            else:
                #scale = self.get_scale()
                params = sol_x[start:stop]
                _vals = np.tile(
                               (np.array(
                                         sol_x[start:stop]*self.scale)).reshape((1,self.n_p)), self.N).reshape(
                                         (self.N, self.n_p)
                                )
                
            #all_vals = np.append(all_vals, vals)
            try:
                vals = np.hstack((vals, _vals))
            except UnboundLocalError:
                vals = _vals
                
        sol_df = pd.DataFrame(
                              columns = 
                              [self.dae.all_names], 
                              data = vals
                             ) 
        # return time-series, params   
        return sol_df, params
        
        
    def get_scale(self, param_guess):
        """
        For numerical conditioning.
        """
        return np.array(list(map(lambda x: 10**x, np.floor(np.log10(np.abs(param_guess)))))).flatten()
        
    @property
    def N(self):
        return len(self.data)
        
    @property
    def n_y(self):
        return self.dae.n_y
        
    @property
    def n_x(self):
        return self.dae.n_x

    @property
    def n_p(self):
        return self.dae.n_p

    @property
    def n_u(self):
        return self.dae.n_u
        
    @property
    def n_z(self):
        return self.dae.n_z
    
    @property
    def n_w(self):
        return self.dae.n_w
    
    @property
    def n_v(self):
        return self.dae.n_v
        
    @property
    def p(self):
        return vertcat(*self.dae.dae.p)
    
    @property
    def x(self):
        return self.dae.dae.x
    
    @property
    def u(self):
        return self.dae.dae.u

    @property
    def u_names(self):
        return list(map(lambda x: x.name(), self.dae.dae.u))
     
    @property
    def y_names(self):
        return list(map(lambda x: x.name(), self.dae.dae.y))
    
    def separate_data(self, data):
        return ca.DM(data[self.u_names].values), ca.DM(data[self.y_names].values)
    
        
    def get_files_before(self):
        """
        Get files in $PWD before jitting.
        """
        if self.with_jit:
            self.before_jit = self.get_files()

    def clean_up_jit(self):
        """
        Clean up after code-gen.
        """
        if self.with_jit:
            
            after_jit = self.get_files()
            
            if self.before_jit != after_jit:
                # CaSADi has not done cleanup
                diff = set(after_jit).difference(set(self.before_jit))
                assert all(filename.split(".")[-1] in ("so", "o", "c") for filename in diff)
                for file in diff:
                    os.remove(file)
                else:
                    # Eventually, output such as this should go to logger.
                    print("Cleaned up JIT-files")
        

    @staticmethod
    def get_files():
        return os.listdir(os.getcwd())

    def __enter__(self):
        self.get_files_before()
        return self
    
    def __exit__(self, *a):
        pass
        self.clean_up_jit()
