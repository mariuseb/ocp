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
from ocp.shooting import MultipleShooting, SingleShooting
import copy

#from tables import Col
#from integrators import RungeKutta4, Cvodes, IRK
import ocp.integrators as integrators
from ocp.dae import DAE
#from shooting import MultipleShooting
#from callback import ProcessIdCallback
import os
#from shooting import Collocation
#from sysid.ocp import OCP
#import typing


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

        config = kwargs.pop("config")
        #data = kwargs.pop("data")
        N = kwargs.pop("N", None)
        dt = kwargs.pop("dt", None)
        
        # new:
        self.slack_names = []
        
        # mostly for sysid:
        param_guess = kwargs.pop("param_guess", None)    
        #scale_nlp = kwargs.pop("scale_nlp", False)
            
        # TODO: include all entities
        #if scale_nlp:
        self.x_nom = kwargs.pop("x_nom", 1)
        self.y_nom = kwargs.pop("y_nom", 1)
        self.r_nom = kwargs.pop("r_nom", 1)
        self.u_nom = kwargs.pop("u_nom", 1)
       
            
        
        if isinstance(config, str) or isinstance(config, os.PathLike):
            with open(config, "r") as f:
                config = json.load(f)

        if N is None: # look in config
            self.N = N = config["N"]
        else:
            self.N = N
        
        if dt is None: # look in config
            self.dt = dt = config["dt"]
        else:
            self.dt = dt
        
        self.dae = dae = DAE(config["model"])
        # mainly on 
        self.bounds_cfg = config.pop("bounds", None)
        #self.data = data

        # special:
        if param_guess is not None:
            self.p_nom = self.scale = self.get_scale(param_guess)
        else:
            self.p_nom = self.scale = ca.repmat(ca.DM([1]), len(self.dae.p))
        
        #if isinstance(data, pd.DataFrame):
        #    self.dt = dt = data.index[1] - data.index[0]
            # need?
        #    N = len(data)

        self.method = config.pop("method")
        integr_cfg = config.pop("integrator")

        if self.method in (
                           "multiple_shooting",
                           "single_shooting"
                           ): # haven't implemented SS yet
            
            integr_name = integr_cfg.pop("name")
            integr_klass = getattr(integrators, integr_name)
            # set dt as from data:
            integr_cfg["dt"] = dt
            # init integrator:
            self.integrator = integr_klass(dae, **integr_cfg) 
        else: 
            raise ValueError("Only multiple shooting implemented.")
         
        # for discretization:
        #if param_guess is None:
            #self.scale = ca.repmat(ca.DM([1]), len(self.dae.p))
        #else:
            #self.scale = self.get_scale(param_guess)

        self.w_nom = 1/(self.x_nom/self.integrator.dt)
        self.v_nom = 1/self.x_nom

        if self.method == "multiple_shooting":
            
            self.strategy = MultipleShooting(self.integrator, 
                                             N,
                                            **{
                                                "x_nom": self.x_nom,
                                                "y_nom": self.y_nom,
                                                "p_nom": self.p_nom,
                                                "r_nom": self.r_nom,
                                                "u_nom": self.u_nom,
                                                "w_nom": self.w_nom,
                                                "v_nom": self.v_nom
                                              }
                                            )
            
        elif self.method == "single_shooting":
            
            self.strategy = SingleShooting(self.integrator)

        if config["codegen"]:
            self.with_jit = True
            self.compiler = "shell"
        else:
            self.with_jit = False
            self.compiler = ""
        
        # NOTE: generalize:
        #self.separate_data(data)
        
        # transcribe:
        self.nlp, self.nlp_parser = self.strategy.transcribe_nlp()
        self.opt = config["opt"]
        # get duals:
        self.opt["calc_multipliers"] = True
  
    
    def _init_solver(self, init_qp_solver=True):
        
        self.solver = ca.nlpsol(
                                "solver", \
                                "ipopt", \
                                self.nlp, \
                                #dict(hess_lag=hessLag, \
                                dict(
                                    jit=self.with_jit, \
                                    compiler=self.compiler, \
                                    **self.opt)
                            )
        
        if init_qp_solver:
            
            opts = dict(
                        qpsol='qrqp',
                        qpsol_options=dict(print_iter=False,error_on_fail=False), 
                        print_time=False
                        )
            
            self.qp_solver = ca.nlpsol('solver',
                                       'sqpmethod',
                                       self.nlp,
                                       opts)
                
    def set_bounds(self):
        
        #(x, z, u, p, w, v, y)
        
        bounds = copy.deepcopy(self.bounds)
          
        # bounds:
        x = bounds.pop("x")
        z = bounds.pop("z")
        u = bounds.pop("u")
        p = bounds.pop("p")
        w = bounds.pop("w")
        v = bounds.pop("v")
        y = bounds.pop("y")
        r = bounds.pop("r")
        
        # use this and fill rest with -inf and inf
        lbx = np.array([])
        ubx = np.array([])
        x0 = np.array([])
        
        for bound_dict, (k, v) in zip((x, z, u, p, w, v, y, r), self.nlp_parser.vars.items()):
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
                    
            else:
                if k == "p":
                    print(bound_dict["x0"])
                x0 = np.append(x0, bound_dict["x0"])
                    #else:
                    #lbx = np.append(lbx, bound_dict["lb"])
                    #ubx = np.append(ubx, bound_dict["ub"])
                
                    #if k == "x":
                    
                    #lslack = MX.sym("lslack", v["dim"], 1)
                    #uslack = MX.sym("uslack", v["dim"], 1)
                    #self.slack = slack = MX.sym("slack", v["dim"], 1)
                    #lbx = lbx - lslack
                    #ubx = ubx + uslack
                    
                    # add slack to x in nlp:
                    #self.nlp["x"][v["range"]["a"]:v["range"]["b"]] = self.nlp["x"][v["range"]["a"]:v["range"]["b"]] + slack
                    #      pass 
                    # add to nlp struct
                    #self.nlp["x"] = ca.veccat(self.nlp["x"], lslack, uslack)
                    #self.nlp["x"] = ca.veccat(self.nlp["x"], slack)
                    # add to nlp_parser:
                    #slack_dict = {}
                    #slack_dict["dim"] = slack.shape[0]
                    #slack_dict["range"] = {}
                    #slack_dict["range"]["a"] = self.nlp_parser.vars["r"]["range"]["b"]
                    #slack_dict["range"]["b"] = self.nlp_parser.vars["r"]["range"]["b"] + slack_dict["dim"]
                    
                    #uslack_dict = {}
                    #uslack_dict["dim"] = uslack.shape[0]
                    #uslack_dict["range"] = {}
                    #uslack_dict["range"]["a"] = lslack_dict["range"]["b"]
                    #uslack_dict["range"]["b"] = lslack_dict["range"]["b"] + uslack_dict["dim"]
                # set lb to initial guess:
                #x0 = np.append(x0, bound_dict["lb"])
    
        # add to nlp parser
        #self.nlp_parser.vars["uslack"] = uslack_dict
        #self.nlp_parser.vars["lslack"] = lslack_dict
        #self.nlp_parser.vars["slack"] = slack_dict
         
        #self.lbx = lbx       
        #self.ubx = ubx       
        
        # nan issue:
        lbx = np.nan_to_num(lbx, nan=0)
        ubx = np.nan_to_num(ubx, nan=0)
        
        # rounding issue
        self.lbx = lbx.round(7)       
        self.ubx = ubx.round(7)       
        self.x0 = x0
        
        # add to slacks:
        #self.lbx = np.append(self.lbx, [-np.inf]*slack.shape[0])
        #self.lbx = np.append(self.lbx, [-np.inf]*uslack.shape[0])
        #self.ubx = np.append(self.ubx, [np.inf]*slack.shape[0])
        #self.ubx = np.append(self.ubx, [np.inf]*uslack.shape[0])
        #self.x0 = np.append(self.x0, [0]*slack.shape[0])
        #self.x0 = np.append(self.x0, [0]*uslack.shape[0])
        #return lbx, ubx
        
    #def set_x_guess(self, )
            
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
                                        np.floor(
                                                np.log10(
                                                        np.abs(param_guess)
                                                        )
                                                )
                                    )
                                )
                        ).flatten()
        
        #prefix = param_guess/dec_scale
        #ceiled = np.ceil(prefix)
        #return np.multiply(ceiled, dec_scale)
        return dec_scale
      
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
                sym_var = sym_var.reshape((dim_var, self.N))
        
        return sym_var
        
    
    @property
    def nlp_v(self):
        return self.get_nlp_var("v")
    
    @property
    def nlp_w(self):
        return self.get_nlp_var("w")

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
        return ca.vertcat(*self.dae.dae.p)
    
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

    @property
    def x_names(self):
        return list(map(lambda x: x.name(), self.dae.dae.x))
     
    @property
    def z_names(self):
        return list(map(lambda x: x.name(), self.dae.dae.z))
     
    @property
    def p_names(self):
        return list(map(lambda x: x.name(), self.dae.dae.p))

    @property
    def w_names(self):
        return self.dae.w_names

    @property
    def v_names(self):
        return self.dae.v_names

    @property
    def r_names(self):
        return self.dae.r_names
    
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
            
        varnames = self.dae.order
        
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
        
        if lbx is not None and ubx is not None or x_init is not None:
            
            varnames = list(set(varnames).difference(set("x")))
            bounds["x"] = {}
    
    
            # TODO: bounds on x here:
            
            # None:
            bounds["x"]["ub"] = ubx
            bounds["x"]["lb"] = lbx
            # not None:
            bounds["x"]["x0"] = x_init/self.x_nom
                 
        for varname in varnames:
            
            bounds[varname] = {}
            names = getattr(self, varname + "_names")
            
            if len(names) == 0:
        
                bounds[varname]["lb"] = \
                    bounds[varname]["ub"] =  \
                        bounds[varname]["x0"] = \
                            None
                #bounds[varname]["ub"] = None
                
            else:
                try:    
                    vals = data[names].values
                    vals = vals.reshape((self.nlp_parser[varname]["dim"], 1))
                    
                    try:
                        scale = getattr(self, varname + "_nom")
                    except AttributeError:
                        scale = 1    
                    
                    bounds[varname]["lb"] = \
                        bounds[varname]["ub"] = \
                            bounds[varname]["x0"] = \
                                ca.DM(vals)/scale
                                
                except KeyError:
                    # not in data.
                    # in bounds_cfg?
                    if bounds_cfg is not None and varname in bounds_cfg:
                        
                        # self.set_bounds expects array that fits nlp:
                        #np.repeat([-np.inf], v["dim"]
                        
                        #dim = self.nlp_parser[varname]["dim"]
                        dim = int(self.nlp_parser[varname]["dim"]/len(getattr(self.dae, varname)))
                        
                        scale = self.u_nom
                        
                        bounds[varname]["lb"] = \
                                bounds[varname]["x0"] = \
                                    np.array(bounds_cfg[varname]["lb" + varname]*dim)
                                    #p.tile(dim, bounds_cfg[varname]["lb" + varname])/scale
                        #np.tile(bounds_cfg[varname]["lb" + varname], dim)/scale
                        
                        # tile here:            
                        #bounds[varname]["ub"] = np.tile(dim, bounds_cfg[varname]["ub" + varname])/scale
                        bounds[varname]["ub"] = np.array(bounds_cfg[varname]["ub" + varname]*dim)
                                    
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
        pass
        self.clean_up_jit()
        
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
                #scale = self.get_scale()
                params = np.array(sol_x[start:stop]*self.scale).flatten()
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
                except AttributeError:
                    scale = 1
                    
                _vals = np.array(sol_x[start:stop]*scale).reshape((self.N, getattr(self, attr_name)))
                
            #all_vals = np.append(all_vals, vals)
            try:
                vals = np.hstack((vals, _vals))
            except UnboundLocalError:
                vals = _vals
          
        #all_names = self.dae.all_names + ["us1", "us2", "ls1", "ls2"]
        
        # slack?
        all_names = self.dae.all_names + self.slack_names
                
        sol_df = pd.DataFrame(
                              columns = 
                              all_names, 
                              data = vals
                             )
        # return time-series, params  
        sol_df.index = self.data.index 
        
        """
        params = {
                  name: val
                  for name, val
                  in zip(self.dae.p, params)
                  }
        """
        
        return sol_df, pd.Series(data=params, index=self.dae.p)
        



        

