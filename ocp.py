#from argparse import ArgumentError
import casadi as ca
#from casadi import *
from abc import ABC, abstractmethod, ABCMeta
import pandas as pd
#pd.set_option("display.precision", 8)
import numpy as np
#np.set_printoptions(precision=10)
import json
#import sys
#import pdb
#import pprint
from ocp.shooting import MultipleShooting, SingleShooting, Collocation
import copy
import re
#from tables import Col
#from integrators import RungeKutta4, Cvodes, IRK
import ocp.integrators as integrators
from ocp.dae import DAE
#from shooting import MultipleShooting
#from callback import ProcessIdCallback
import os
import subprocess
from collections import OrderedDict
#from shooting import Collocation
#from sysid.ocp import OCP
#import typing
import hashlib
import scipy
import typing
import copy

class NumpyEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, np.integer):
            return int(obj)
        if isinstance(obj, np.floating):
            return float(obj)
        if isinstance(obj, np.ndarray):
            return obj.tolist()
        if isinstance(obj, ca.DM):
            assert (obj.shape[0] in (1, None)) \
                    or \
                   (obj.shape[1] in (1, None))
            return list(np.array(obj).flatten())
        return super(NumpyEncoder, self).default(obj)

class OCP(metaclass=ABCMeta):
    """
    Solve the optimal control problem
    subject to the model:
        
        dx/dt = f(x, z, u, p, w)  (1)
        0 = g(x, z, u, p, w)      (2)
        y = h(x, p, v)            (3)
        
    i.e. solve the optimization problem:

        min_(x,z,u,p,w,v,y) J(x,z,u,p,w,v,y)
            s.t. 1, 2
            x_lb <= x <= x_ub
            z_lb <= z <= z_ub
            u_lb <= u <= u_ub
            p_lb <= p <= p_ub
            w_lb <= w <= w_ub
            v_lb <= v <= v_ub
            y_lb <= y <= y_ub
        
        where J is some user-defined cost function.    
    
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
        param_guess:
            list/
            ca.DM/
            np.array - for numerical conditioning
    """
    
    @classmethod
    def __subclasshook__(cls, subclass):
        return (hasattr(subclass, 'get_nlp_obj') and 
                callable(subclass.get_nlp_obj))
    
    def __init__(
                self, 
                **kwargs
                ):

        self.kwargs = copy.deepcopy(kwargs)
        config = kwargs.pop("config")        
        self.functions = functions = kwargs.pop("functions", None)
        #if config["solver"] == "gauss_newton":
        #    self.gauss_newton = True
        #data = kwargs.pop("data")
        self.slack = slack = kwargs.pop("slack", False)
        self.N = N = kwargs.pop("N", None)
        self.dt = dt = kwargs.pop("dt", None)
        # new:
        self.slack_names = []
        self.c_files = []
        
        # mostly for sysid:
        param_guess = kwargs.pop("param_guess", None)    
        #scale_nlp = kwargs.pop("scale_nlp", False)
            
        # TODO: include all entities
        #if scale_nlp:
        
        self.scale_dict = OrderedDict()
        
        self.x_nom = kwargs.pop("x_nom", 1)
        self.x_nom_b = kwargs.pop("x_nom_b", 0)
        self.z_nom = kwargs.pop("z_nom", 1)
        self.z_nom_b = kwargs.pop("z_nom_b", 0)
        self.y_nom = kwargs.pop("y_nom", 1)
        self.y_nom_b = kwargs.pop("y_nom_b", 0)
        self.r_nom = kwargs.pop("r_nom", 1)
        self.r_nom_b = kwargs.pop("r_nom_b", 0)
        self.u_nom = kwargs.pop("u_nom", 1)
        self.u_nom_b = kwargs.pop("u_nom_b", 0)
        self.s_nom = kwargs.pop("s_nom", 1)
        self.v_nom = kwargs.pop("v_nom", 1)
        self.v_nom_b = kwargs.pop("v_nom_b", 0)
        self.p_nom = self.scale = kwargs.pop("p_nom", None)
        self.p_nom_b = kwargs.pop("p_nom_b", 0)
        # special:
        #if param_guess is not None:
        #if self.p_nom is None:
        #    self.p_nom = self.scale = self.get_scale(param_guess)
        if param_guess is not None and self.p_nom is None:
            self.p_nom = self.scale = self.get_scale(param_guess)
        elif param_guess is None:
            #self.p_nom = self.scale = ca.repmat(ca.DM([1]), len(self.dae.p))
            self.p_nom = self.scale = [1]
        
        self.scale_dict["x_nom"] = self.x_nom
        self.scale_dict["x_nom_b"] = self.x_nom_b
        self.scale_dict["z_nom"] = self.z_nom
        self.scale_dict["z_nom_b"] = self.z_nom_b
        self.scale_dict["y_nom"] = self.y_nom
        self.scale_dict["y_nom_b"] = self.y_nom_b
        self.scale_dict["r_nom"] = self.r_nom
        self.scale_dict["r_nom_b"] = self.r_nom_b
        self.scale_dict["u_nom"] = self.u_nom
        self.scale_dict["u_nom_b"] = self.u_nom_b
        self.scale_dict["s_nom"] = self.s_nom
        self.scale_dict["u_nom"] = self.u_nom
        self.scale_dict["u_nom_b"] = self.u_nom_b
        self.scale_dict["v_nom"] = self.v_nom
        self.scale_dict["v_nom_b"] = self.v_nom_b
        self.scale_dict["p_nom"] = list(self.p_nom)
        self.scale_dict["p_nom_b"] = self.p_nom_b
        
        
        self.use_objective_from_cfg = kwargs.pop("use_objective_from_cfg", True)
        self.gamma = kwargs.pop("gamma", 1)
       
        if isinstance(config, str) or isinstance(config, os.PathLike):
            with open(config, "r") as f:
                config = json.load(f, object_pairs_hook=OrderedDict)
        self.config = copy.deepcopy(config)
        """
        Hash config to avoid re-generating, compiling c-code.
        """
        #self.gen_code_filename = self.get_c_code_name(config)
        #self.so_filename = self.gen_code_filename.replace(".c", ".so")

        if N is None: # look in config
            self.N = N = config["N"]
        else:
            self.N = N
        
        if dt is None: # look in config
            self.dt = dt = config["dt"]
        else:
            self.dt = dt
        
        config["model"]["functions"] = functions
        ## objective:
        self.obj_string = config.pop("objective", None)
        
        assert self.gamma <= 1 and self.gamma > 0
        ##
        self.dae = dae = DAE(config["model"])
        # mainly on 
        self.bounds_cfg = config.pop("bounds", None)
        #self.data = data
        # solver tricks:
        if config["solver"] == "gauss-newton":
            self.gauss_newton = True
        else:
            self.gauss_newton = False
            

        
        #if isinstance(data, pd.DataFrame):
        #    self.dt = dt = data.index[1] - data.index[0]
            # need?
        #    N = len(data)

        self.method = config.pop("method")
        integr_cfg = config.pop("integrator")
        
        # ocp constraints (e.g. to enforce physical solutions)
        
        ################ TO OWN METHOD #######################
        _ocp = config.pop("ocp", None)
        # only deal in inequality constraints for now:
        self.h_exprs = dict()
        if _ocp is not None:
            h = _ocp.pop("h")
            """
            self.h_exprs = {
                            "lhs": [],
                            "body": [],
                            "symbols": [],
                            "rhs": []
                            }
            """
            for i, expr in enumerate(h):
                self.h_exprs[i] = {}
                # find sign. only handle one:
                if "==" in expr:
                    sign = "=="
                elif ">=" in expr:
                    sign = ">="
                elif "<=" in expr:
                    sign = "<="
                else:
                    raise ValueError("Ill-defined constraint h(x). Missing sign.")
                
                #elems = expr.split("<=")
                #if len(elems) < 2: # we picked up the the wrong sign 
                #    elems = expr.split(">=")
                #    elems = elems.reverse()
                #elif elems is None: # == sign
                #    elems = expr.split("==")
                #elems = elems.reverse()
                    
                elems = expr.split(sign)
                
                #elif len(elems) == 2: # 'standard' case
                """     
                else:
                    raise ValueError("Improve handling " + \
                                    "of inequality constraints")
                """                
                elems = list(map(lambda x: x.strip(), elems))
                matchers = self.dae.all_names
                symbols = set([s for s in matchers if s in elems[1]])
                #symbols = re.findall("|".join(self.dae.all_names), elems[1])
                
                self.h_exprs[i]["lhs"] = float(elems[0]) # needs to be a number ??
                self.h_exprs[i]["body"] = elems[1]
                self.h_exprs[i]["symbols"] = symbols
                if sign != "==":
                    if len(elems) == 3:
                        self.h_exprs[i]["rhs"] = float(elems[2])
                    elif len(elems) == 2:
                        self.h_exprs[i]["rhs"] = np.inf
                    else:
                        raise ValueError("OCP constraint error.")
                else:
                    assert len(elems) == 2
                    self.h_exprs[i]["rhs"] = self.h_exprs[i]["lhs"]
                    
            #########################################################    

        if self.method in (
                           "multiple_shooting",
                           "single_shooting",
                           "collocation"
                           ): # haven't implemented SS yet
            
            integr_name = integr_cfg.pop("name")
            integr_klass = getattr(integrators, integr_name)
            # set dt as from data:
            integr_cfg["dt"] = dt
            # init integrator:
            self.integrator = integr_klass(dae, **integr_cfg) 
        else: 
            # TODO: set "shadow"-integrator for simulation etc.
            #self.integrator = None
            #integr_cfg["dae"] = self.dae
            raise NotImplementedError("Have only implemented direct methods")
            
        #integr_cfg["dt"] = dt
         
        # for discretization:
        #if param_guess is None:
            #self.scale = ca.repmat(ca.DM([1]), len(self.dae.p))
        #else:
            #self.scale = self.get_scale(param_guess)

        #self.w_nom = 1/(self.x_nom/self.integrator.dt)
        #self.w_nom = 1/self.x_nom**2/self.integrator.dt
        #self.w_nom = 1*self.x_nom
        #self.v_nom = 1*self.x_nom
        #self.w_nom = 1/self.x_nom
        #self.w_nom = 1
        #self.v_nom = 1
        #self.v_nom = 1/5e4
        #self.w_nom = 1/5e4
        #self.v_nom = 1/1e5
        #self.w_nom = 1/1e5
        #self.v_nom = 1/1e4
        #self.w_nom = 1/1e4
        #self.v_nom = 1/1e4
        #self.w_nom = 1/1e4
        #self.v_nom = 1
        #self.w_nom = 1
        #self.w_nom_b = 0
        #self.v_nom_b = 0
        
        #
        map_eval = config.pop("map_eval", True)

        if self.method == "multiple_shooting":
            
            self.strategy = MultipleShooting(self.integrator, 
                                             N,
                                            **{
                                                "x_nom": self.x_nom,
                                                "x_nom_b": self.x_nom_b,
                                                "y_nom": self.y_nom,
                                                "y_nom_b": self.y_nom_b,
                                                "z_nom": self.z_nom,
                                                "z_nom_b": self.z_nom_b,
                                                "p_nom": self.p_nom,
                                                "p_nom_b": self.p_nom_b,
                                                "r_nom": self.r_nom,
                                                "r_nom_b": self.r_nom_b,
                                                "u_nom": self.u_nom,
                                                "u_nom_b": self.u_nom_b,
                                                "s_nom": self.s_nom,
                                                "v_nom": self.v_nom, 
                                                "v_nom_b": self.v_nom_b, 
                                                "map_eval": map_eval
                                              }
                                            )
            
        elif self.method == "single_shooting":
            
            self.strategy = SingleShooting(self.integrator,
                                           N,
                                            **{
                                                "x_nom": self.x_nom,
                                                "y_nom": self.y_nom,
                                                "p_nom": self.p_nom,
                                                "r_nom": self.r_nom,
                                                "u_nom": self.u_nom,
                                                "s_nom": self.s_nom,
                                                "v_nom": self.v_nom
                                              }
                                            )
            
        elif self.method == "collocation": # no integrator, "all-at-once" method
            # require: 
            assert isinstance(self.integrator, integrators.IRK)
            self.strategy = Collocation(
                                        self.integrator,
                                        N,
                                        **{
                                            "x_nom": self.x_nom,
                                            "x_nom_b": self.x_nom_b,
                                            "y_nom": self.y_nom,
                                            "y_nom_b": self.y_nom_b,
                                            "p_nom": self.p_nom,
                                            "p_nom_b": self.p_nom_b,
                                            #"p_nom": ca.repmat(ca.DM([1]), len(self.dae.p)),
                                            "r_nom": self.r_nom,
                                            "r_nom_b": self.r_nom_b,
                                            "z_nom": self.z_nom,
                                            "z_nom_b": self.z_nom_b,
                                            "u_nom": self.u_nom,
                                            "s_nom": self.s_nom,
                                            "v_nom": self.v_nom
                                            }
                                        )

        """
        if config["codegen"]: # TODO: clear up difference between jit and codegen.
            self.with_jit = self.codegen = True
            self.compiler = "shell"
        else:
            self.with_jit = self.codegen = False
            self.compiler = ""
        """
        self.with_jit = config.pop("with_jit", False)
        self.codegen = config.pop("codegen", False)
        self.compiler = config.pop("compiler", "shell")
        
        # NOTE: generalize:
        #self.separate_data(data)
        
        # transcribe:
        self.nlp, self.nlp_parser = self.strategy.transcribe_nlp()
        self.opt = config["opt"]
        try:
            self.set_A()
        except RuntimeError:
            print("Fix setting df/dx for DAE-models.")
            pass
        # get duals:
        #self.opt["calc_multipliers"] = True
    
    def generate_x_guess(self):
        """
        'Abstract' method
        for MHE and SID.
        (Possibly also MPC?)
        
        TODO: fix for single shooting.
        
        """
        if self.integrator.dae.n_x > 0:
            y_x_overlap = [name for name in self.y_names if self.dae.y[name].name() in self.dae.x]
            y = self.data[y_x_overlap].values.flatten()
            
            # Assume order of y and x correspond
            # TODO: fix for arbitrary order:
            # TODO: do only once:
            if isinstance(self.y_nom, list):
                # get offset from 
                stop = len(y_x_overlap)
                y_nom = self.y_nom[0:stop]
                try:
                    y_nom_b = self.y_nom_b[0:stop]
                except:
                    # scalar
                    y_nom_b = self.y_nom_b
                
            else: 
                y_nom = self.y_nom
                y_nom_b = self.y_nom_b
            
            #x_guess = y         
            x_guess = (y-y_nom_b)/y_nom
            
            #diff = self.integrator.dae.n_x - self.integrator.dae.n_y
            #for n in range(diff):
            #    x_guess = ca.horzcat(x_guess, y)
            
            # TODO: fix for multi-dimensional:
            if self.strategy.name == "Collocation":
                _x_guess = np.ones((self.n_x, ((self.N-1)*(self.strategy.d+1)+1)))     
                # if direct collocation, fill between
                for n in range(self.N-1):
                    _x_guess[:, n:(n + self.strategy.d+1)] = x_guess[n]
                last = (self.N-1)*(self.strategy.d+1)
                _x_guess[:,last:last+1] = x_guess[-1]
                x_guess = _x_guess
            else:     
                diff = int(self.integrator.dae.n_x/len(y_x_overlap)) - 1
                for n in range(diff):
                    x_guess = ca.horzcat(x_guess, (y-y_nom_b)/y_nom)
                    #x_guess = ca.horzcat(x_guess, _x_guess)
            return x_guess 
        else:
            return np.array([])
    
    
    def get_hess_lag(self, residual, nlp_x):
      # objective only indirectly affected by collocation points...
        J = ca.jacobian(residual, nlp_x)
        p = ca.veccat(self.R, self.Q)
        H = ca.triu(ca.mtimes(J.T, J))
        sigma = ca.MX.sym("sigma")
        hess_lag = ca.Function('nlp_hess_l',{'x':nlp_x,'lam_f':sigma, 'p': p,'hess_gamma_x_x':sigma*H},
                                ['x','p','lam_f','lam_g'], ['hess_gamma_x_x'],
                                dict(jit=self.with_jit, compiler=self.compiler))
        return hess_lag
            
    def _init_solver(self, init_qp_solver=True):
        
        # TODO: fix residual:
        if self.gauss_newton:
            hess_lag = self.get_hess_lag(self.res, self.nlp["x"])
        else:
            hess_lag = None

        self.solver = ca.nlpsol(
                                "solver", \
                                "ipopt", \
                                self.nlp, \
                                #dict(hess_lag=hessLag, \
                                dict(
                                    hess_lag=hess_lag,
                                    jit=self.with_jit, \
                                    compiler=self.compiler, \
                                    #ad_weight=0,
                                    **self.opt
                                    )
                            )
        #self.jsolver_ipopt = self.solver.factory('j', self.solver.name_in(), ['jac:f:p'])
        #self.hsolver_ipopt = self.jsolver_ipopt.factory('h', self.solver.name_in(), ['jac:jac_f_p:p'])
        #self.hsolver_ipopt = self.solver.factory('h', self.solver.name_in(), ['hess:f:p:p'])
        #self.sqp_adj = self.solver.reverse(1)
        
        if init_qp_solver:
            
            opts = dict(
                        qpsol='qrqp',
                        #qpsol='qrqp',
                        qpsol_options=dict(print_iter=False,error_on_fail=False), 
                        print_time=True,
                        #regularize=True,
                        #min_step_size=1E-10
                        )
        """
        self.sqp_solver = ca.nlpsol('solver',
                                    'sqpmethod',
                                    self.nlp,
                                    opts)
        """ 
            #self.jsolver_sqp = self.sqp_solver.factory('h', self.sqp_solver.name_in(), ['jac:f:p'])
            #self.sqp_adj = self.sqp_solver.reverse(1)
            #self.sqp_forward = self.sqp_solver.forward(self.nlp["p"].shape[0])
                
    def set_bounds(self, skip_u=False, slack=False):
        
        #(x, z, u, p, w, v, y)
        
        bounds = copy.deepcopy(self.bounds)
          
        # bounds:
        x = bounds.pop("x")
        z = bounds.pop("z")
        if skip_u:
            u = {
                "lb": None,
                "ub": None,
                "x0": None
            }
        else:
            u = bounds.pop("u")
        p = bounds.pop("p")
        #w = bounds.pop("w")
        """
        TODO: name collision with slack variable.
        Fix
        """
        s = bounds.pop("s")
        
        v = bounds.pop("v")
        y = bounds.pop("y")
        r = bounds.pop("r")
        w = bounds.pop("w")
        
        # use this and fill rest with -inf and inf
        lbx = np.array([])
        ubx = np.array([])
        x0 = np.array([])
        
        for bound_dict, (k, v) in zip((x, z, u, p, s, v, y, r, w), self.nlp_parser.vars.items()):
        #for arr, (k, v) in zip((x, z, p, w, v), self.nlp_parser.vars.items()):
            # TODO: check also lb
            #if bound_dict["ub"] is None:
            if all(map(lambda x: x is None, \
                   (bound_dict["ub"], bound_dict["lb"]))
                   ):
                
                ubx = np.append(ubx, np.repeat([np.inf], v["dim"]))
                lbx = np.append(lbx, np.repeat([-np.inf], v["dim"]))
                
                #if k == "p": # positive semi-definite params
                #    val = 0
                #else:
                #    val = -np.inf
            elif bound_dict["lb"] is None:
                #lbx = np.append(lbx, np.repeat([val], v["dim"]))
                lbx = np.append(lbx, np.repeat([-np.inf], v["dim"]))
                ubx = np.append(ubx, bound_dict["ub"])
            
            # only ub is None:
            elif bound_dict["ub"] is None:
                lbx = np.append(lbx, bound_dict["lb"])
                ubx = np.append(ubx, np.repeat([np.inf], v["dim"]))
            
            else:
                lbx = np.append(lbx, bound_dict["lb"])
                ubx = np.append(ubx, bound_dict["ub"])
                
            ######## handle x0 #######:
            if bound_dict["x0"] is None:
                if bound_dict["lb"] is None:
                    #if k == "v" or k == "w":
                    #    x0 = np.append(x0, np.repeat([0.01], v["dim"]))
                    #else:
                    x0 = np.append(x0, np.repeat([0], v["dim"]))
                else:
                    x0 = np.append(x0, bound_dict["lb"])
               
               
            # check if u, modify initial guess:
                    
            else:
                if k == "p":
                    print(bound_dict["x0"])
                
                #if k == "u":
                #    bound_dict["x0"] = (bound_dict["lb"] + bound_dict["ub"])/200000
                    
                x0 = np.append(x0, bound_dict["x0"])
        # nan issue:
        
        #lbx = np.nan_to_num(lbx, nan=0)
        #ubx = np.nan_to_num(ubx, nan=0)
        #x0 = np.nan_to_num(x0, nan=0)
        
        # rounding issue
        self.lbx = lbx       
        self.ubx = ubx       
        self.x0 = x0
        
        # slack: 
        if self.slack or slack:
            dim = self.nlp_parser.vars["sl"]["dim"]
            #self.lbx = np.append(self.lbx, np.repeat([-np.inf], self.nlp_parser.vars["sl"]["dim"]))
            #self.lbx = np.append(self.lbx, np.repeat([0], self.nlp_parser.vars["sl"]["dim"]))
            #self.ubx = np.append(self.ubx, np.repeat([np.inf], self.nlp_parser.vars["sl"]["dim"]))
            #self.x0 = np.append(self.x0, np.repeat([0], self.nlp_parser.vars["sl"]["dim"]))
            self.lbx = np.append(self.lbx, np.repeat([0], dim))
            self.ubx = np.append(self.ubx, np.repeat([np.inf], dim))
            self.x0 = np.append(self.x0, np.repeat([0], dim))
        
    #def set_x_guess(self, )
    def add_h(self):
        """
        Inequality constraints independent of external data.
        """
        expr_dict = {}
        for i, elem in self.h_exprs.items():
            expr_string = elem["body"]
            vals = {}
            for symbol in elem["symbols"]:
                vals[symbol] = self.get(symbol)
            # TODO: collocation logic:
            if self.method == "collocation":
                # if mix of x and z, take x only at collocation points:
                x_symbols = [symbol for symbol in elem["symbols"] if symbol in self.dae.x]
                if (
                    any(symbol in self.dae.z for symbol in elem["symbols"])
                    and 
                    any(symbol in self.dae.x for symbol in elem["symbols"])
                    ):
                    #z_symbols = [symbol for symbol in elem["symbols"] if symbol in self.dae.z]
                    #vals["Ti"] = vals["Ti"][0::(self.integrator.d+1)]                     
                    for x_ in x_symbols:
                        slices = []
                        for n in range(self.N-1):
                            offset = n*(self.integrator.d+1) + 1
                            _slice = ca.Slice(offset, offset + self.integrator.d)
                            slices.append(vals[x_][_slice])
                        vals[x_] = ca.vertcat(*slices)
                        #vals[x_] = vals[x_][1::(self.integrator.d+1)]                     
                    #for z_ in z_symbols:
                    #    vals[z_] = vals[z_][0::(self.integrator.d+1)]                       
                else: # take x-symbols at finite elements:
                    for x_ in x_symbols:
                        vals[x_] = vals[x_][0::(self.integrator.d+1)]
                    
                    
            vals["expr_dict"] = expr_dict
            exec(f'expr_dict[%s] =' % (i,) + expr_string, vals)
            #exec(f'expr_dict[%s] =' % (i,) + expr_string, vals)
            #print(expr_dict)
            
            """
            Now, add this constraint to nlp.g
            add also corresponding entries for lbg and ubg
            
            TODO: more solid logic here!
            """
            
            expr = expr_dict[i]
            #if self.method == "collocation":
                #expr = expr.T
            self.nlp["g"] = ca.vertcat(self.nlp["g"], expr) # TODO: .T?
            self.lbg = np.append(self.lbg, np.array([elem["lhs"]]*expr.shape[0]))
            self.ubg = np.append(self.ubg, np.array([elem["rhs"]]*expr.shape[0]))
    
            
    @abstractmethod
    def solve(self):
        raise NotImplementedError("ERROR.")
        
    @abstractmethod
    def get_nlp_obj(self):
        raise NotImplementedError("ERROR.")
        
    def get_scale(self, param_guess):
        """
        For numerical conditioning.
        """
        dec_scale = np.array(
                        list(
                            map(
                                lambda x: 10**x,
                                        #np.floor(
                                        np.round(
                                                np.log10(
                                                        #param_guess
                                                        np.abs(param_guess)
                                                        )
                                                )
                                    )
                                )
                        ).flatten()
        
        """
        -inf appears if parameter guess is
        zero. Replace it with 0.
        """
        dec_scale[dec_scale == -np.inf] = 0
        
        prefix = param_guess/dec_scale
        ceiled = np.ceil(prefix)
        
        """
        Replace nan with 0.
        """
        #ceiled = np.nan_to_num(ceiled)
        #return np.multiply(ceiled, dec_scale)
        #return np.array(np.multiply(ceiled, dec_scale)).flatten()
        return dec_scale
    
    def __del__(self):
        pass
        """W
        for file in self.c_files:
            print("Deleting %s..." % file)
            os.remove(file)
        """
    
    def get_c_code_name(self, config):
        """
        return "%s_solver_id_" % type(self).__name__ + \
                str(abs(hash(json.dumps(config, sort_keys=True)))) + \
                ".c"
        NOTE: built-in hash() only consistent internal to a process
        """
        import hashlib
        if "N" not in config:
            config["N"] = self.N
        if "dt" not in config:
            config["dt"] = self.dt
        
        # not Json-serializable:
        _  = self.kwargs.pop("functions", None)
        # but the rest of kwargs is:
        config["kwargs"] = self.kwargs
        config["scale_dict"] = self.scale_dict
        s = json.dumps(config, sort_keys=True, cls=NumpyEncoder)
        return "%s_solver_id_" % type(self).__name__ + \
                str(
                    int(
                        hashlib.sha256(s.encode('utf-8')).hexdigest(),
                        16) %
                    10**8
                    ) \
                + ".c"
        
        
    def pregenerate_c_code(self, gen_code_filename, **kwargs):
        """
        Requires gcc. Make sure it is installed.
        
        NOTE: only tested on Linux.
        
        TODO: test on another platform.
        """
        #so_filename = gen_code_filename.replace(".c", ".so")
        # keep names for later:
        #self.c_files.append(gen_code_filename)
        #self.c_files.append(so_filename)
        solver = kwargs.pop("solver")
        solver.generate_dependencies(gen_code_filename)
        return gen_code_filename.replace(".c", ".so")
        
    def compile_c_code(
                       self,
                       c_code_path,
                       so_path,
                       **kwargs
                       ):
        # Create a new NLP solver instance from the compiled code
        compiler = kwargs.pop("compiler", "clang")
        #flags = kwargs.pop("flags", ["-O0"])
        flags = kwargs.pop("flags", ["-Ofast"])
        if os.path.exists("_l4c_generated"):
            linkage = ["-L./", "_l4c_generated/libl4casadi_f.so"]
        else:
            linkage = []
            
        cmd_args = [compiler,"-fPIC","-shared"] + \
                    flags + \
                    linkage + \
                    [
                    c_code_path, 
                     "-o",
                     so_path
                     ]
        # compile:
        subprocess.run(cmd_args)
    
    def init_codegen_solver(self,
                            so_filename,
                            **opts):
        """
        TODO: solver name
        """
        #self.opt.pop("verbose", False)
        #self.opt.pop("ipopt.hessian_approximation")
        solver_opts = copy.deepcopy(opts)
        opts["ipopt"] = dict()
        for k, v in solver_opts.items():
            opts["ipopt"][k.replace("ipopt.", "")] = v
        # re-init solver object:
        return ca.nlpsol("solver", 
                        "ipopt",
                        so_filename,
                        opts)

    def prepare_solver(self, codegen=False, **kwargs):
        """
        Prepare solver.
        """
        if not hasattr(self, "solver"):      
            self._init_solver()
        opts = kwargs.pop("opts", dict())
        gen_code_filename = self.get_c_code_name(self.config)

        if codegen:
            if not os.path.exists(gen_code_filename):
                self.pregenerate_c_code(gen_code_filename, **kwargs)
            if not os.path.exists(self.so_filename):
                self.compile_c_code()
            self.init_codegen_solver(**opts)    
    
      
    def get_nlp_var(self, varname):
        """
        Get var from nlp-dict.
        """
        start, stop = self.nlp_parser[varname]["range"]["a"], \
                    self.nlp_parser[varname]["range"]["b"]
        sym_var = self.nlp["x"][start:stop]
        
        if varname != "p":
            if sym_var.shape[0] != self.N:
                dim_var = getattr(self, "n_" + varname)
                # TODO: explicit here:
                try:
                    sym_var = sym_var.reshape((dim_var, self.N))
                except:
                    if varname == "z" and self.method == "collocation":
                        sym_var = sym_var.reshape((dim_var, self.strategy.d*(self.N-1)))
                    elif varname != "x":
                        sym_var = sym_var.reshape((dim_var, self.N-1))
                    else: # x, collocation, fix:
                        sym_var = sym_var.reshape((dim_var, (self.N-1)*(self.strategy.d+1)+1))
                        
                    #pass
        
        return sym_var
        
    
    def get_ocp_name_and_offset(self, name):
        # TODO: include all:
        for varname in ("x", "u", "z", "p", "s", "v", "w", "r"):
            if varname in ("x", "u", "z", "p", "w"):
                varlist = getattr(self.dae.dae, varname)()
            elif varname in ("s", "v", "r"): # TODO: add v, r
                #varlist = getattr(self.dae, name[0] + "_names")
                varlist = getattr(self.dae, varname + "_names")
                #varname = name[0]
                if varname == "r":
                    print(name)
            offset = 0
            for _name in varlist:
                if _name == name:
                    return varname, offset
                offset += 1
        else:
            raise ValueError("DAE has no variable %s" % 
                             (name))
        
    def get(self, name):
        ocp_name, offset = self.get_ocp_name_and_offset(name)
        n_ocp_var = getattr(self.dae, "n_" + ocp_name)
        nlp_var = self.get_nlp_var(ocp_name)
        
        if n_ocp_var == 1:
            #ret_val = nlp_var.T
            ret_val = nlp_var
        else:
            ret_val = nlp_var[offset::n_ocp_var]
            
        # TODO: more robust handling of variable
        # length ocp variables for h 
        # (e.g. constraint only in X)
        
        #if ocp_name in ("x", "z"):
        #    ret_val = ret_val[:-1]
            
        return ret_val
    
    def get_var_at_stage(self, name, stage: int):
        """
        Get ocp variable <name> at stage n ∈ N
        
        Make working version, then optimize for
        speed later.
        
        TODO: fix for collocation
        """
        var = self.get_nlp_var(name)
        n_ocp_var = getattr(self, "n_" + name)
        if isinstance(self.method, Collocation) and name == "x":
            n_skip = self.method.d + 1
        else:
            n_skip = 1
        start = n_skip*stage
        return var[start:(start+n_ocp_var)]
         
    @property
    def nlp_v(self):
        return self.get_nlp_var("v")
    
    """
    @property
    def nlp_w(self):
        return self.get_nlp_var("w")
    """
    
    @property
    def nlp_s(self):
        return self.get_nlp_var("s")

    @property
    def nlp_u(self):
        return self.get_nlp_var("u")

    # must do the below to return
    # purely symbolic p:
    @property
    def nlp_p(self):
        return self.dae.dae.p
    
    @property
    def nlp_z(self):
        return self.get_nlp_var("z")

    @property
    def nlp_x(self):
        return self.get_nlp_var("x")
    
    @property
    def nlp_y(self):
        return self.get_nlp_var("y")
 
    @property
    def nlp_r(self):
        return self.get_nlp_var("r")

    #@property
    #def nlp_lslack(self):
    #    return self.get_nlp_var("lslack")
    
    #@property
    #def nlp_uslack(self):
    #    return self.get_nlp_var("uslack") 
    
        
    #@property
    #def N(self):
    #    return len(self.data)
        
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
    def n_s(self):
        return self.dae.n_s

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
    def n_r(self):
        return self.dae.n_r
 
    #@property
    #def n_uslack(self):
    #    return self.dae.n_x
    
    #@property
    #def n_lslack(self):
    #    return self.dae.n_x
        
    @property
    def p(self):
        return ca.vertcat(*self.dae.dae.p())
    
    @property
    def x(self):
        return self.dae.dae.x
    
    @property
    def u(self):
        return self.dae.dae.u

    @property
    def u_names(self):
        #return list(map(lambda x: x.name(), self.dae.dae.u))
        return self.dae.u
     
    @property
    def y_names(self):
        #return list(map(lambda x: x.name(), self.dae.dae.y))
        return self.dae.dae.y()

    @property
    def x_names(self):
        #return list(map(lambda x: x.name(), self.dae.dae.x))
        return self.dae.x
     
    @property
    def z_names(self):
        #return list(map(lambda x: x.name(), self.dae.dae.z))
        return self.dae.z
     
    @property
    def p_names(self):
        #return list(map(lambda x: x.name(), self.dae.dae.p))
        return self.dae.p

    @property
    def s_names(self):
        return self.dae.s_names

    @property
    def v_names(self):
        return self.dae.v_names

    @property
    def r_names(self):
        return self.dae.r_names
    
    @property
    def w_names(self):
        return self.dae.w_names
    
    def set_A(self):
        """
        Set casadi-Function that retrieves A.
        """
        self._A = _A = ca.jacobian(self.integrator.ode, self.integrator.x)
        #x =  ca.vertsplit(self.integrator.x)
        # should be state independant:
    
        self.A = ca.Function("A",
                             [self.integrator.x, self.integrator.p],
                             [_A],
                             ["x", "p"], 
                             ["A"]
                             )
        
    def get_Ad(self,
               dt: typing.Union[int, None] = None,
               **kwargs
               ):
        """
        Get discrete-time Ad.
        """
        x = kwargs.pop("x", np.ones(self.dae.dae.nx())*293.15) 
        p = kwargs.pop("p", None) 
        
        A = self.A(x=x,
                   p=p)["A"]
        if dt is None:
            dt = self.dt
        return scipy.linalg.expm(A*dt)
          
    def get_taus(self, 
                 **kwargs
                 ):
        """
        Get time constants of ODE-system.
        """
        
        x = kwargs.pop("x", np.ones(self.dae.dae.nx())*293.15) 
        p = kwargs.pop("p", None) 
        
        A = self.A(x=x,
                   p=p)["A"]
        Ad = self.get_Ad(A)
        eig_A = np.linalg.eig(Ad)
        return 1/eig_A.eigenvalues
        
    
    # TODO: generalize:
    def separate_data(
                      self,
                      data,
                      **kwargs
                      ):
        
        # TODO: handle x0
        lbp = kwargs.pop("lbp", None)
        ubp = kwargs.pop("ubp", None)
        lbx = kwargs.pop("lbx", None)
        ubx = kwargs.pop("ubx", None)
        x_init = kwargs.pop("x_guess", None)
        p_init = kwargs.pop("param_guess", None)
        
        bounds = {}
        
        bounds_cfg = self.bounds_cfg
        if bounds_cfg is None:
            bounds_cfg = dict()
            
        varnames = self.dae.order
        
        """
        The below conditions must be fulfilled as 
        a consequence of dealing with non-linear 
        optimization problems:
            - p_init not None 
            - x_init not None
            
        Bounds can be passed as either arrays
        part of config-files.
        """
        
        if lbp is not None or ubp is not None or p_init is not None:
            
            varnames = list(set(varnames).difference(set("p")))
            bounds["p"] = {}
    
            if lbp is not None:
                bounds["p"]["lb"] = lbp/self.scale
                #bounds["p"]["lb"] = lbp
            else:
                bounds["p"]["lb"] = None
                
            if ubp is not None:
                bounds["p"]["ub"] = ubp/self.scale
                #bounds["p"]["ub"] = ubp
            else:
                bounds["p"]["ub"] = None
                
            if p_init is None:
                bounds["p"]["x0"] = lbp/self.scale
            else:
                bounds["p"]["x0"] = p_init/self.scale
                
            # what if 0 in self.scale? replace here.
            #print(bounds["p"]["x0"])
            bounds["p"]["x0"] = np.nan_to_num(bounds["p"]["x0"])
            bounds["p"]["ub"] = np.nan_to_num(bounds["p"]["ub"])
            bounds["p"]["lb"] = np.nan_to_num(bounds["p"]["lb"])
        
        if lbx is not None and ubx is not None or x_init is not None:
            
            if lbx is not None:
                assert ubx is not None, "If lbx is passed as array, " + \
                    "ubx must be passed as array too."
            
            bounds["x"] = {}
    
    
            # TODO: bounds on x here:
            
            # TODO: improve logic:
            
            if isinstance(self.x_nom_b, list):
                bias = self.x_nom_b = np.tile(self.x_nom_b, self.N)
                scale = self.x_nom = np.tile(self.x_nom, self.N)
            else:
                bias = self.x_nom_b
                scale = self.x_nom
            
            if lbx is not None: # passed as array:
                bounds["x"]["ub"] = (ubx - bias)/scale
                bounds["x"]["lb"] = (lbx - bias)/scale
                #varnames = list(set(varnames).difference(set("x")))
            else:
                if "x" in bounds_cfg:
                    
                    dim = int(self.nlp_parser["x"]["dim"]/self.n_x)
                    lbx = np.hstack([bounds_cfg["x"]["lbx"] for n in range(dim)])
                    ubx = np.hstack([bounds_cfg["x"]["ubx"] for n in range(dim)])
                    bounds["x"]["lb"] = (lbx - bias)/scale
                    bounds["x"]["ub"] = (ubx - bias)/scale
                else:
                    bounds["x"]["ub"] = None
                    bounds["x"]["lb"] = None
                    
            varnames = list(set(varnames).difference(set("x")))
            """
            if lbx is not None:
                #bounds["x"]["lb"] = (lbx - self.x_nom_b)/self.x_nom
            else:
                if "x" in bounds_cfg:
                    bounds["x"]["lb"] = bounds_cfg["x"]["lbx"]
                else:
                    bounds["x"]["lb"] = None
                # not None:
            """
            #bounds["x"]["x0"] = x_init/self.x_nom
            #bounds["x"]["x0"] = (x_init - self.x_nom_b)/self.x_nom
            bounds["x"]["x0"] = (x_init - bias)/scale

        # TODO: extend with lbz, ubz
                 
        for varname in varnames:
            
            if varname == "x":
               print("yes")
                
            bounds[varname] = {}
            names = getattr(self, varname + "_names")
        
            if len(names) == 0:
                bounds[varname]["lb"] = \
                    bounds[varname]["ub"] =  \
                        bounds[varname]["x0"] = \
                            None
                #bounds[varname]["ub"] = None
                
            else:
                dim = int(self.nlp_parser[varname]["dim"]/len(names))
                try:    
                    try:
                        # these should be passed as python lists:
                        scale = getattr(self, varname + "_nom")
                        bias = getattr(self, varname + "_nom_b")
                        
                        if not isinstance(scale, list):
                            scale = [scale]*len(names)
                        if not isinstance(bias, list):
                            bias = [bias]*len(names)
                            
                        bias = np.array(bias)
                        scale = np.array(scale)
                        bias = bias.reshape((1, bias.shape[0])).T
                        bias = np.vstack([bias for n in range(dim)])
                        scale = scale.reshape((1, scale.shape[0])).T
                        scale = np.vstack([scale for n in range(dim)])
                    except (AttributeError, IndexError) as e: # fallback:
                        scale = 1    
                        bias = 0    
                    
                    vals = data[names].values
                    """
                    try:
                        vals = vals.reshape((self.nlp_parser[varname]["dim"], 1))
                    except ValueError:
                        vals = vals[:-1, :]
                        vals = vals.reshape((self.nlp_parser[varname]["dim"], 1))
                    """ 
                    
                    # original:
                    """
                    bounds[varname]["lb"] = \
                        bounds[varname]["ub"] = \
                            bounds[varname]["x0"] = \
                                (ca.DM(vals) - bias)/scale
                    vals -= bias
                    vals /= scale
                    bounds[varname]["lb"] = \
                        bounds[varname]["ub"] = \
                            bounds[varname]["x0"] = \
                                vals
                                #ca.DM(vals)/scale
                    """
                    
                    try:
                        vals = vals.reshape((self.nlp_parser[varname]["dim"], 1))
                    except ValueError:
                        vals = vals[:-1, :]
                        #if varname == "z" and isinstance(self.strategy, Collocation):
                        if varname == "z" and self.strategy.name == "Collocation":
                            vals = np.tile(vals.flatten(), self.strategy.d)
                        else:
                            vals = vals.reshape((self.nlp_parser[varname]["dim"], 1))
                    
                    #if varname == "r":
                    #    print(varname) 
                                
                    vals -= bias
                    vals /= scale
                    
                    # below leads to automatic broadcasting,
                    # do not want that.
                    #vals = vals - bias
                    #vals = vals/scale
                    """
                    bounds[varname]["lb"] = \
                        bounds[varname]["ub"] = \
                            bounds[varname]["x0"] = \
                                vals
                    """
                    bounds[varname]["x0"] = vals
                    if varname != "z":
                        bounds[varname]["lb"] = vals
                        bounds[varname]["ub"] = vals
                    else: # no bounds
                        bounds[varname]["lb"] = None
                        bounds[varname]["ub"] = None
                        
                        
                        
                                
                except KeyError:
                    # not in data.
                    # in bounds_cfg?
                    
                    # must be u, or else None is set:
                    
                    if bounds_cfg is not None and varname in bounds_cfg:
                        
                        # self.set_bounds expects array that fits nlp:
                        #np.repeat([-np.inf], v["dim"]
                        
                        #dim = self.nlp_parser[varname]["dim"]
                        n_var = getattr(self.dae, "n_" + varname)
                        #dim = int(self.nlp_parser[varname]["dim"]/(len(getattr(self.dae, varname)*n_var)))
                        #dim = int(self.nlp_parser[varname]["dim"]/(len(getattr(self.dae, varname))))
                        
                        #if varname == "z" and self.method == "collocation":
                        #    dim = self.strategy.d*dim
                        
                        nom_name = varname + "_nom"
                        bias_name = varname + "_nom_b"
                        # TODO: fix this for non-collocation:
                        #bias = getattr(self, bias_name)
                        #scale = getattr(self, nom_name)
                        #if not isinstance(bias, list):
                        #    bias = [bias]
                        
                        """
                        if varname == "z" and isinstance(self.strategy, Collocation):
                            #dim *= self.strategy.d
                            if not isinstance(bias, list):
                                bias = [bias]*dim
                            if not isinstance(scale, list):
                                scale = [scale]*dim 
                        """                          
                        #if varname == "u":
                        #    print(bias)
                        
                        """
                        if scale != 1 or bias != 0: # must be passed as correct dimension:    
                            scale = np.tile(scale, dim)
                            bias = np.tile(bias, dim)
                        """    
                        #if isinstance(scale, np.ndarray):
                        #    scale = np.tile(scale, dim)
                        #if varname == "u":
                        #    print(varname)
                        
                        
                        lb = np.array(bounds_cfg[varname]["lb" + varname]*dim)
                        ub = np.array(bounds_cfg[varname]["ub" + varname]*dim)
                        if isinstance(bias, np.ndarray):
                            lb = lb.reshape(bias.shape)
                            ub = ub.reshape(bias.shape)
                        
                        #lb_vals = np.array(bounds_cfg[varname]["lb" + varname]*dim) - bias
                        #ub_vals = np.array(bounds_cfg[varname]["ub" + varname]*dim) - bias
                        lb_vals = lb - bias
                        ub_vals = ub - bias
                        #lb_vals /= scale
                        #if varname == "z" and isinstance(self.strategy, Collocation):
                        #        lb_vals = np.tile(lb_vals.flatten(), self.strategy.d)
                        #        ub_vals = np.tile(ub_vals.flatten(), self.strategy.d)
                            
                        lb_vals = lb_vals/scale
                        
                        #bounds[varname]["lb"] = \
                        #        bounds[varname]["x0"] = \
                        #            np.array(bounds_cfg[varname]["lb" + varname]*dim)/scale
                        
                        bounds[varname]["lb"] = \
                                bounds[varname]["x0"] = \
                                    lb_vals
                                    #p.tile(dim, bounds_cfg[varname]["lb" + varname])/scale
                        #np.tile(bounds_cfg[varname]["lb" + varname], dim)/scale
                        
                        # tile here:            
                        #ub_vals /= scale
                        ub_vals = ub_vals/scale
                        #bounds[varname]["ub"] = np.tile(dim, bounds_cfg[varname]["ub" + varname])/scale
                        #bounds[varname]["ub"] = np.array(bounds_cfg[varname]["ub" + varname]*dim)/scale
                        bounds[varname]["ub"] = ub_vals
                                    
                    else:
                        bounds[varname]["lb"] = \
                            bounds[varname]["ub"] = \
                                bounds[varname]["x0"] = \
                                    None
                                    
                        
                        
                    
        # TODO: handle better. Iterate on num states.
        #if lbx is not None and ubx is not None:
        #    bounds["x"]["lb"] = np.append(x0, lbx)
        #    bounds["x"]["ub"] = np.append(x0, ubx)
            #bounds["x"]["lb"] = lbx
            #bounds["x"]["ub"] = ubx
        #return ca.DM(data[self.u_names].values), ca.DM(data[self.y_names].values)
        
        # bounds overwrite:
        self.bounds = bounds
    
        
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
                
                assert all(
                           filename.split(".")[-1]
                           in ("so", "o", "c")
                           for filename in diff
                           )
                
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
        #self.clean_up_jit()
        pass
        
    def parse_solution(self, solution):
        """ General. """  
        parser = self.nlp_parser.vars   
        
        # temporary, store nlp-solution:
        self.solution = solution
         
        sol_x = np.array(solution["x"]).flatten()
    
        #for i, name in enumerate(self.dae.order):
        # TODO: scale back from <name>_nom
        for i, (name, d) in enumerate(self.nlp_parser.vars.items()):
            
            sub_parser = parser[name]
            start, stop = sub_parser["range"]["a"], \
                            sub_parser["range"]["b"]
                            
            attr_name = "n_" + name
            
            if name == "p":
                scale = self.scale
                bias = 0
                
                if start != stop:
                    params = np.array(sol_x[start:stop]*scale).flatten()
                else:
                    #params = solution["p"]
                    params = []
                _vals = np.tile(
                                (np.array(
                                        params)).reshape((1,self.n_p)), self.N).reshape(
                                        (self.N, self.n_p)
                                )
                    
            else:
                #if name == "x":
                #    scale = self.x_nom
                #else:
                #    scale = 1
                try:
                    scale = getattr(self, name + "_nom")
                    bias = getattr(self, name + "_nom_b")
                except AttributeError:
                    scale = 1
                    bias = 0
                
                if name == "x":
                    if self.method == "multiple_shooting":
                        
                        if not isinstance(bias, (float, int)):
                            bias = self.x_nom_b.reshape((self.N, getattr(self, attr_name)))
                        _vals = np.array(sol_x[start:stop]*scale).reshape((self.N, getattr(self, attr_name))) + \
                            bias
                        if not isinstance(scale, (float, int)):
                            scale = self.x_nom.reshape((self.N, getattr(self, attr_name)))
                            
                #if self.method == "multiple_shooting" or name != "x":
                    elif self.method == "single_shooting":
                        _vals = np.array(sol_x[start:stop]*scale)
                        _vals = np.append(_vals, solution["g"][0:(self.n_x*(self.N-1))]*scale).reshape((self.N, getattr(self, attr_name)))
                    else:
                        #raise NotImplementedError("Nt implmntd.")
                        assert self.method == "collocation"
                        d = self.strategy.d
                        _vals = np.array(sol_x[start:stop]*scale).reshape(((self.N-1)*(d+1) + 1, self.n_x)) + self.x_nom_b
                        _vals = _vals[start:stop:(d+1)]
                else:
                    n_name = getattr(self, "n_" + name)
                    _vals = sol_x[start:stop]
                    if n_name == 0:
                        continue
                    
                    try:
                        _vals = _vals.reshape((self.N, getattr(self, attr_name)))
                    except ValueError:
                        """
                        Special handling of algebraic vars and collocation:
                        TODO: cleanup
                        """
                        if name in ("z","y") and self.method == "collocation":
                            # here, need to implement evaluation of polynomial for value
                            # of algebraic variables at finite elements
                            #scale = 1    
                            #bias = 0
                            
                            n_var = getattr(self.dae, "n_" + name)
                            nicp = 1 # TODO: generalize for more finite elements
                            d = self.strategy.d
                            #xA_opt = _vals.T.reshape(n_var, d*nicp*(self.N-1))
                            xA_opt = _vals.T.reshape(d*nicp*(self.N-1), n_var)
                            Da = self.strategy.Da
                            xA_plt = np.resize(np.array([],dtype=ca.MX),(n_var,(d+1)*nicp*(self.N-1)))
                            offset4=0
                            offset5=0
                            for k in range(self.N-1):
                                for i in range(nicp):
                                    for j in range(d+1):
                                        if j!=0:
                                            #xA_plt[:,offset5] = xA_opt[:,offset4]
                                            xA_plt[:,offset5] = xA_opt[offset4,:]
                                            offset4 += 1
                                            offset5 += 1
                                        else:
                                            xa0 = 0
                                            for j in range(d):
                                                #xa0 += Da[j]*xA_opt[:,offset4+j]
                                                xa0 += Da[j]*xA_opt[offset4+j,:]
                                            xA_plt[:,offset5] = xa0
                                            #xA_plt[:,offset5] = xA_opt[:,offset4]
                                            offset5 += 1
                            #print(xA_plt)
                            #_vals = xA_plt.reshape(((self.N-1)*(d+1), n_var))
                            _vals = xA_plt.T
                            _vals = _vals[0:-1:(d+1)]
                            
                            # ?
                            #scale = 1
                            #bias = 0
                        """
                        Fill extra row with nan
                        """
                        _vals = _vals.reshape((self.N-1, getattr(self, attr_name)))
                        newrow = np.repeat(np.nan, getattr(self, attr_name))
                        _vals = np.vstack([_vals, newrow])
                    # Temporary fix:
                        
                    _vals *= scale
                    _vals += bias
                    # OLD:
                    #_vals = np.array(sol_x[start:stop]*scale) #.reshape((self.N, getattr(self, attr_name)))
                    """
                    try:
                        _vals = _vals.reshape((self.N, getattr(self, attr_name)))
                    except ValueError:
                        _vals = _vals.reshape((self.N-1, getattr(self, attr_name)))
                        newrow = np.repeat(np.nan, getattr(self, attr_name))
                        _vals = np.vstack([_vals, newrow])
                    """
                    
            # reverse scaling again:
            _scaled_vals = (_vals - bias)/scale
                
            #all_vals = np.append(all_vals, vals)
            try:
                vals = np.hstack((vals, _vals))
                scaled_vals = np.hstack((scaled_vals, _scaled_vals))
            except UnboundLocalError:
                vals = _vals
                scaled_vals = _scaled_vals
                
          
        #all_names = self.dae.all_names + ["us1", "us2", "ls1", "ls2"]
        
        # slack?
        all_names = self.dae.all_names + self.slack_names
                
        sol_df = pd.DataFrame(
                              columns = 
                              all_names, 
                              data = vals
                             )
        self.scaled_sol_df = pd.DataFrame(
                                            columns = 
                                            all_names, 
                                            data = scaled_vals
                                         )
        # return time-series, params  
        #sol_df.index = self.data.index 
        """
        params = {
                  name: val
                  for name, val
                  in zip(self.dae.p, params)
                  }
        """
        return sol_df, pd.Series(data=np.array(params).flatten(), index=self.dae.p)
        



        

