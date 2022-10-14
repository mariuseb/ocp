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
from sysid.shooting import MultipleShooting, SingleShooting
import copy

#from tables import Col
#from integrators import RungeKutta4, Cvodes, IRK
import sysid.integrators as integrators
from sysid.dae import DAE
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
        
        # mostly for sysid:
        param_guess = kwargs.pop("param_guess", None)
        
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
        #self.data = data

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
        if param_guess is None:
            self.scale = ca.repmat(ca.DM([1]), len(self.dae.p))
        else:
            self.scale = self.get_scale(param_guess)

        if self.method == "multiple_shooting":
            self.strategy = MultipleShooting(self.integrator, N, self.scale)
        elif self.method == "single_shooting":
            self.strategy = SingleShooting(integrator)

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
  
    
    def _init_solver(self):
        self.solver = nlpsol(
                            "solver", \
                             "ipopt", \
                             self.nlp, \
                             #dict(hess_lag=hessLag, \
                             dict(
                                  jit=self.with_jit, \
                                  compiler=self.compiler, \
                                  **self.opt)
                            )
    
                
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
            if bound_dict["ub"] is None:
                
                if k == "p": # positive semi-definite params
                    val = 0
                else:
                    val = -np.inf
                    
                lbx = np.append(lbx, np.repeat([val], v["dim"]))
                ubx = np.append(ubx, np.repeat([np.inf], v["dim"]))
                x0 = np.append(x0, np.repeat([0], v["dim"]))
            else:
                lbx = np.append(lbx, bound_dict["lb"])
                ubx = np.append(ubx, bound_dict["ub"])
                
                if k == "x":
                    
                    #lslack = MX.sym("lslack", v["dim"], 1)
                    #uslack = MX.sym("uslack", v["dim"], 1)
                    #self.slack = slack = MX.sym("slack", v["dim"], 1)
                    #lbx = lbx - lslack
                    #ubx = ubx + uslack
                    
                    # add slack to x in nlp:
                    #self.nlp["x"][v["range"]["a"]:v["range"]["b"]] = self.nlp["x"][v["range"]["a"]:v["range"]["b"]] + slack
                    pass 
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
                x0 = np.append(x0, bound_dict["lb"])
    
        # add to nlp parser
        #self.nlp_parser.vars["uslack"] = uslack_dict
        #self.nlp_parser.vars["lslack"] = lslack_dict
        #self.nlp_parser.vars["slack"] = slack_dict
         
        self.lbx = lbx       
        self.ubx = ubx       
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
        return np.array(
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
            
        varnames = self.dae.order
        
        if lbp is not None or ubp is not None or p_init is not None:
            
            varnames = list(set(varnames).difference(set("p")))
            bounds["p"] = {}
    
            bounds["p"]["ub"] = ubp/self.scale
            bounds["p"]["lb"] = lbp/self.scale
            
            if p_init is None:
                bounds["p"]["x0"] = lbp/self.scale
            else:
                bounds["p"]["x0"] = p_init/self.scale
        
        if lbx is not None and ubx is not None or x_init is not None:
            
            varnames = list(set(varnames).difference(set("x")))
            bounds["x"] = {}
    
            bounds["x"]["ub"] = ubx
            bounds["x"]["lb"] = lbx
            bounds["x"]["x0"] = x_init
                 
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
                    
                    bounds[varname]["lb"] = \
                        bounds[varname]["ub"] = \
                            bounds[varname]["x0"] = \
                                ca.DM(vals)
                                
                except KeyError:
                    
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
        sol_x = np.array(solution["x"]).flatten()
    
        #for i, name in enumerate(self.dae.order):
        for i, (name, d) in enumerate(self.nlp_parser.vars.items()):
            
            sub_parser = parser[name]
            start, stop = sub_parser["range"]["a"], \
                            sub_parser["range"]["b"]
            attr_name = "n_" + name
            
            if name != "p":
                _vals = np.array(sol_x[start:stop]).reshape((self.N, getattr(self, attr_name)))
            else:
                #scale = self.get_scale()
                params = np.array(sol_x[start:stop]*self.scale).flatten()
                _vals = np.tile(
                                (np.array(
                                         params)).reshape((1,self.n_p)), self.N).reshape(
                                         (self.N, self.n_p)
                                )
                
            #all_vals = np.append(all_vals, vals)
            try:
                vals = np.hstack((vals, _vals))
            except UnboundLocalError:
                vals = _vals
          
        #all_names = self.dae.all_names + ["us1", "us2", "ls1", "ls2"]
        all_names = self.dae.all_names
                
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
        



        

class MPC(OCP):
    """
    Solve for optimal control action N steps into 
    the future, subject to the model:
        
        dx/dt = f(x, z, u, p)  (1)
        0 = g(x, z, u, p)      (2)
        
    i.e. solve the optimization problem:

        min_(x,z,u) J(x,z,u) 
            s.t. 1, 2
            x_lb <= x <= x_ub
            z_lb <= z <= z_ub
            u_lb <= u <= u_ub
            p = p_fixed
        
        where J is some cost function defined
        over the horizon N.
    
    more specifically DAE-systems of index 1.
    
    (Arguments as listed for OCP)
    """
    def __init__(self, **kwargs):
        
        super().__init__(**kwargs) # does all the work.
        
        #self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(self.nlp_u)
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, self.nlp_lslack, self.nlp_uslack)
        
        #self.set_bounds(y=self.Y,
        #                u=self.U)
        #self.set_bounds()
        #self._init_solver()
        
    #def get_nlp_obj(self, u, slack):
    def get_nlp_obj(self, u):
        """ 
        Objective for MPC.
        
        Start off with something
        simple:
            Minimum control effort
            
        Try next:
            Reference tracking.
            
        And further next:
            Combination of 
            the two.
        """          
        return 0.5*ca.dot(u, u) # + 0.01*ca.dot(slack, slack)
    
    def add_path_constraints(
                            self,
                            x0=None,
                            lbx=None,
                            ubx=None
                            ):
        
        x_info = self.nlp_parser["x"]
        x = self.nlp["x"][x_info["range"]["a"]:x_info["range"]["b"]]
        
        lbx = np.append(x0, lbx)
        ubx = np.append(x0, ubx)
        
        #uslack = MX.sym("uslack", x_info["dim"])
        #lslack = MX.sym("lslack", x_info["dim"])
        
        #slack = ca.vertcat(uslack, lslack)
        
        #upper_constr = x - ubx - uslack
        #lower_constr = lbx - x - lslack#, 
        path_constr = x
        #lower_constr = x
        #lower_constr = lbx - x
        
        #lbg = np.array([0]*self.nlp["orig_g"].shape[0])
        #ubg = np.array([0]*self.nlp["orig_g"].shape[0])
        lbg = np.array([0]*self.nlp_parser.g.shape[0])
        ubg = np.array([0]*self.nlp_parser.g.shape[0])
        
        self.lbg = np.append(lbg, lbx)
        self.ubg = np.append(ubg, ubx)
        
        #self.nlp["g"] = ca.vertcat(self.nlp["orig_g"], path_constr)
        self.nlp["g"] = ca.vertcat(self.nlp_parser.g, path_constr)
        
        
        #self.nlp["x"] = ca.vertcat(self.nlp["x"], slack)
        
        """
        parser = self.nlp_parser
        
        uslack_dict = {}
        uslack_dict["dim"] = x_info["dim"]
        uslack_dict["range"] = {}
        uslack_dict["range"]["a"] = parser["r"]["range"]["b"]
        uslack_dict["range"]["b"] = parser["r"]["range"]["b"] + uslack_dict["dim"]
        
        lslack_dict = {}
        lslack_dict["dim"] = x_info["dim"]
        lslack_dict["range"] = {}
        lslack_dict["range"]["a"] = self.nlp_parser.vars["r"]["range"]["b"]
        lslack_dict["range"]["b"] = self.nlp_parser.vars["r"]["range"]["b"] + lslack_dict["dim"]
        
        self.nlp_parser.vars["uslack"] = uslack_dict
        self.nlp_parser.vars["lslack"] = lslack_dict
        """
        #self.lbx = np.append(self.lbx, np.array([0]*slack.shape[0]))
        #self.ubx = np.append(self.ubx, np.array([np.inf]*slack.shape[0]))
        #self.x0 = np.append(self.x0, np.array([1E-6]*slack.shape[0]))
    
        #return slack    
    
    def solve(
              self,
              data,
              x0=None,
              lbx=None,
              ubx=None,
              params=None,
              ):
        """
        todo
        """
        self.data = data
        # let pure 'x' be unbounded
        self.separate_data(
                          data,
                          lbp=params,
                          ubp=params,
                          p_guess=params
                          #x0=x0
                          )  
        
        self.set_bounds()
        
        # add lbx and ubx as path constraints on g:
        
        # ADD: option for slack:
        self.add_path_constraints(x0=x0, lbx=lbx, ubx=ubx)
        
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, slack)
        self.nlp["f"] = self.get_nlp_obj(self.nlp_u)
                
        self._init_solver()
        
        #slack_lb = ca.DM(self.lbx)[0:50] - self.nlp["x"][-50:]
        #slack_ub = ca.DM(self.ubx)[0:50] + self.nlp["x"][-50:]
        #lbx = ca.vertcat(slack_lb, self.lbx[50:])
        #ubx = ca.vertcat(slack_ub, self.ubx[50:])
              
        solution = self.solver(
                               x0=self.x0,
                               lbg=self.lbg,
                               ubg=self.ubg,
                               lbx=self.lbx,
                               ubx=self.ubx,
                               )
        
        ########################## parse solution ######################################
        
        sol_df, params = self.parse_solution(solution)
        
        #################################################################################
        
        return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[self.dt, self.x_names].values
    
class MHE(OCP):
    def __init__(self, **kwargs):
        """
        Almost equal to regular sysid,
        though we drop statistics for now.
        """
        super(MHE, self).__init__(**kwargs)
        self.df = pd.DataFrame(columns=self.dae.p)
        
    # skip this:
    def set_hess_obj(self):
        pass
    
    # TODO: P0 as parameter in NLP
    def get_nlp_obj(self, v, w, P0, x_N, p0):
        """ 
        Objective for mhe.
        """          
        # define Q, R here:
        self.Q_SX = ca.SX.sym("Q", self.n_x, self.n_x)
        self.R_SX = ca.SX.sym("R", self.n_y, self.n_y)
        # actual:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        
        self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
                                   [self.Q_SX],
                                   [ca.sqrt(ca.inv(self.Q_SX))],
                                   ["Q"],
                                   ["Q_sqrt_inv"])

        #self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
        #                            [Q0, Q1, Q2, Q3],
        #                            [ca.sqrt(ca.inv(self.Q))],
        #                            ["Q"],
        #                            ["Q_sqrt_inv"])
        
        self.R_sqrt_inv = ca.Function("R_sqrt_inv",
                                     [self.R_SX],
                                     [ca.sqrt(ca.inv(self.R_SX))],
                                     ["R"],
                                     ["R_sqrt_inv"])
            
        #self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        #self.R_square_root = ca.sqrt(ca.inv(self.R))
        
        
        self.R_square_root = self.R_sqrt_inv(self.R)
        self.Q_square_root = self.Q_sqrt_inv(self.Q)
        
        # arrival cost:
        self.P0_sqrt = ca.sqrt(P0)
        last_x = self.nlp_x[0:self.n_x]
        p = self.dae.dae.p
        costate = ca.vertcat(*p, last_x)
        costate_num = ca.vertcat(p0, x_N)
        """
        return 0.5*ca.dot(ca.mtimes(self.R_square_root,
                                    v),
                            ca.mtimes(v.T,
                                      self.R_square_root).T) \
                + \
                0.5*ca.dot(ca.mtimes(self.Q_square_root,
                                     w),
                            ca.mtimes(w.T,
                                      self.Q_square_root).T) + \
                0.5*ca.dot(ca.mtimes(
                                     self.P0_sqrt,
                                     (costate - costate_num)
                                     ),
                            ca.mtimes(
                                      (costate - costate_num
                                      ).T,
                                      self.P0_sqrt).T), \
                ca.veccat(self.Q, self.R)
        """
        return 0.5*ca.dot(ca.mtimes(self.R_square_root,
                                    v),
                            ca.mtimes(v.T,
                                      self.R_square_root).T) \
                + \
                0.5*ca.dot(ca.mtimes(self.Q_square_root,
                                     w),
                            ca.mtimes(w.T,
                                      self.Q_square_root).T), \
                ca.veccat(self.Q, self.R)
        
    def solve(
              self,
              data,
              param_guess,
              covar=None,
              lbp=None,
              ubp=None,
              P0=None,
              x_N=None
              ):
        """
        Set initials for v, w to 0
        """
        self.data = data           
        self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(self.nlp_v,
                                                self.nlp_w, P0, x_N, param_guess) 
        
        
        y = self.data[self.y_names].values.flatten()
                    
        x_guess = y
        
        diff = self.integrator.dae.n_x - self.integrator.dae.n_y
        
        for n in range(diff):
            x_guess = horzcat(x_guess, y)
        
        self.separate_data(
                          data,
                          lbp=lbp,
                          ubp=ubp,
                          x_guess=x_guess,
                          param_guess=param_guess
                          )
        
        self.set_bounds()
        self._init_solver()
                     
        solution = self.solver(
                               x0=self.x0,
                               lbg=0, # option for path-constraints?
                               ubg=0, # --"--
                               lbx=self.lbx,
                               ubx=self.ubx,
                               p=covar
                               )
        
        self.sol_df, params = self.parse_solution(solution)
        
        k = len(self.df)
        self.df.loc[k*self.dt, :] = params.values
        
        return self.sol_df, params
    
################## TEST for Q, R free ###########################

class ParameterEstimation(OCP):
    """
    Estimate parameters of a system
    on the form:
        
        dx/dt = f(x, z, u, p, w)  (1)
        0 = g(x, z, u, p, w)      (2)
        y = h(x, p, v)            (3)
        
    i.e. solve the optimization problem:

        min_(v,w,p) ||v||_R^{n} + ||w||_Q^{n}
            s.t. 1, 2, 3
            p_lb <= p <= p_ub
        
        where n is some norm-funtion (1-norm, 2-norm, Hubert penalty)
    
    more specifically DAE-systems of index 1.
    
    (Arguments as listed for OCP)
    """
    def __init__(self, **kwargs):
        
        #params = kwargs["param_guess"]
        #data = kwargs["data"]
        
        super().__init__(**kwargs) # does all the work.
        
        #self.nlp["f"]= self.get_nlp_obj(self.nlp_v, self.nlp_w) 
        
        #self.set_bounds(y=self.Y,
        #                u=self.U)
        #self.separate_data(data)
        #self.set_bounds()
        #self._init_solver()
        
    def get_nlp_obj(self, v, w):
        """ 
        Objective for sysid.
        """          
        # define Q, R here:
        #self.Q_SX = ca.SX.sym("Q", self.n_x, self.n_x)
        #self.R_SX = ca.SX.sym("R", self.n_y, self.n_y)
        # actual:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        
        #self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
        #                           [self.Q_SX],
        #                           [ca.sqrt(ca.inv(self.Q_SX))],
        #                           ["Q"],
        #                           ["Q_sqrt_inv"])

        #self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
        #                            [Q0, Q1, Q2, Q3],
        #                            [ca.sqrt(ca.inv(self.Q))],
        #                            ["Q"],
        #                            ["Q_sqrt_inv"])
        
        #self.R_sqrt_inv = ca.Function("R_sqrt_inv",
        #                             [self.R_SX],
        #                             [ca.sqrt(ca.inv(self.R_SX))],
        #                             ["R"],
        #                             ["R_sqrt_inv"])
            
        #self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        #self.R_square_root = ca.sqrt(ca.inv(self.R))
        
        #self.R_square_root = self.R_sqrt_inv(self.R)
        #self.Q_square_root = self.Q_sqrt_inv(self.Q)
        
        self.R_square_root = ca.sqrt(ca.inv(self.R))
        self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        
        self.nlp["x"] = ca.vertcat(self.nlp["x"], ca.veccat(self.Q, self.R))
        
        return 0.5*ca.dot(ca.mtimes(ca.sqrt(ca.inv(self.R)),
                                    v),
                            ca.mtimes(v.T,
                                      ca.sqrt(ca.inv(self.R))).T) \
                + \
                0.5*ca.dot(ca.mtimes(ca.sqrt(ca.inv(self.Q)),
                                     w),
                            ca.mtimes(w.T,
                                      ca.sqrt(ca.inv(self.Q))).T)
                
    def set_hess_obj(self):
        """
        For covariance estimation.
        
        (negative log-likelihood) 
        """ 
        #### set up log(det) - Functions:
        Q_SX = self.Q_SX
        R_SX = self.R_SX
        
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
         
        x = ca.vec(self.nlp_x)
        z = ca.vec(self.nlp_z)
        u = ca.vec(self.nlp_u)
        y = ca.vec(self.nlp_y)
        p = ca.vertcat(*self.dae.dae.p)
        R = self.R
        Q = self.Q
        
        
        # residual x:
        res_x = self.nlp_parser.x_gaps
        # residual y:
        res_y = self.nlp_parser.h_gaps
        
        #self.alt_obj = 0.5*ca.dot(
        alt_obj = 0.5*ca.dot(
                             ca.mtimes(self.R_square_root,
                                       res_y),
                             ca.mtimes(res_y.T,
                                       self.R_square_root).T) \
                            + \
                  0.5*ca.dot(
                            ca.mtimes(self.Q_square_root,
                                      res_x),
                            ca.mtimes(res_x.T,
                                      self.Q_square_root).T) \
                            + \
                  ((self.N-1)/2)*self.log_det_Q(self.Q) \
                            + \
                  (self.N/2)*self.log_det_R(self.R)
                  
          
        hess_expr =  ca.hessian(alt_obj,
                                ca.vertcat(p,
                                           x,
                                           u,
                                           y,
                                           ca.vec(R),
                                           ca.vec(Q)
                                           )
                                )[0]             
        
        self.hess_obj = ca.Function(
                                    "hess_obj",
                                     [p,
                                      x,
                                      u,
                                      y,
                                      ca.vec(R),
                                      ca.vec(Q)
                                      ],
                                    [hess_expr],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["p", "x", "u", "y", "R", "Q"],
                                    ["hess_obj"]
                                    )           
       

        
                            
    def solve(
              self,
              data,
              param_guess,
              covar=None,
              lbp=None,
              ubp=None
              ):
        
        #Set initials for v, w to 0
        self.data = data
        
        #x_guess = repmat(self.Y, 1, self.n_x)
        
        # TODO: logic for generating guesses of unmeasured states? 
        
        # this is for the spring mass damper:
        
        ''' if self.Y.shape[1] != self.integrator.dae.n_x:
            # do this ( n_x - n_y) times:
            yd = np.diff(self.Y,axis=0)*1/self.dt
            x_guess = horzcat(self.Y, vertcat(yd, yd[-1])).T
        else:
            x_guess = self.Y.T '''
            
        #if self.Y.shape[1] != self.integrator.dae.n_x:
            # do this ( n_x - n_y) times:
            
        self.nlp["f"] = self.get_nlp_obj(self.nlp_v, self.nlp_w) 
        
        #self.set_hess_obj()
        
        # generate x guess: two methods: repeat or freq-based
        # -> own method
        #y_info = self.bounds["y"]["lb"]
        #y = self.bounds["y"]["lb"]
        
        ####################### method ###########################
        
        y = self.data[self.y_names].values.flatten()
                    
        x_guess = y
        
        # TODO: handle edge-cases, e.g. n_y = 2 and n_x = 3
        diff = self.integrator.dae.n_x - self.integrator.dae.n_y
        
        for n in range(diff):
            x_guess = horzcat(x_guess, y)

        ##########################################################
        
        self.separate_data(
                          data,
                          lbp=lbp,
                          ubp=ubp,
                          x_guess=x_guess,
                          param_guess=param_guess
                          )
        
        self.set_bounds()
        self._init_solver()
        
        ### add Q, R to self.x0 #####
        covar_constr = []
        n_x = self.n_x
        n_y = self.n_y
        Q = self.Q
        R = self.R

        for i in range(n_x):
            for j in range(n_x):
                if i != j:
                    covar_constr.append(Q[i,j] - Q[j,i])
                    
        for i in range(n_y):
            for j in range(n_y):
                if i != j:
                    covar_constr.append(R[i,j] - R[j,i])
                    
        self.x0 = np.append(self.x0, covar)           
        self.lbx = np.append(self.lbx, np.array([-np.inf]*5))           
        self.ubx = np.append(self.ubx, np.array([np.inf]*5))           
        
        #self.nlp["g"] = ca.vertcat(self.nlp["g"], *covar_constr)                
          
        grad_f = ca.gradient(self.nlp["f"], self.nlp["x"])
        grad_f_f = ca.Function("grad_f", [self.nlp["x"]], [grad_f])
        val = grad_f_f(self.x0)
        
        solution = self.solver(
                               x0=self.x0,
                               lbg=0, # option for path-constraints?
                               ubg=0, # --"--
                               lbx=self.lbx,
                               ubx=self.ubx,
                               )
        
        self.sol_df, params = self.parse_solution(solution)
        
        return self.sol_df, params
    
    
class ParameterEstimation(OCP):
    """
    Estimate parameters of a system
    on the form:
        
        dx/dt = f(x, z, u, p, w)  (1)
        0 = g(x, z, u, p, w)      (2)
        y = h(x, p, v)            (3)
        
    i.e. solve the optimization problem:

        min_(v,w,p) ||v||_R^{n} + ||w||_Q^{n}
            s.t. 1, 2, 3
            p_lb <= p <= p_ub
        
        where n is some norm-funtion (1-norm, 2-norm, Hubert penalty)
    
    more specifically DAE-systems of index 1.
    
    (Arguments as listed for OCP)
    """
    def __init__(self, **kwargs):
        
        #params = kwargs["param_guess"]
        #data = kwargs["data"]
        
        super().__init__(**kwargs) # does all the work.
        
        self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(self.nlp_v,
                                                        self.nlp_w) 
        
        #self.set_bounds(y=self.Y,
        #                u=self.U)
        #self.separate_data(data)
        #self.set_bounds()
        #self._init_solver()
        
    def get_nlp_obj(self, v, w):
        """ 
        Objective for sysid.
        """          
        # define Q, R here:
        self.Q_SX = ca.SX.sym("Q", self.n_x, self.n_x)
        self.R_SX = ca.SX.sym("R", self.n_y, self.n_y)
        # actual:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        
        self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
                                   [self.Q_SX],
                                   [ca.sqrt(ca.inv(self.Q_SX))],
                                   ["Q"],
                                   ["Q_sqrt_inv"])

        #self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
        #                            [Q0, Q1, Q2, Q3],
        #                            [ca.sqrt(ca.inv(self.Q))],
        #                            ["Q"],
        #                            ["Q_sqrt_inv"])
        
        self.R_sqrt_inv = ca.Function("R_sqrt_inv",
                                     [self.R_SX],
                                     [ca.sqrt(ca.inv(self.R_SX))],
                                     ["R"],
                                     ["R_sqrt_inv"])
            
        #self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        #self.R_square_root = ca.sqrt(ca.inv(self.R))
        
        self.R_square_root = self.R_sqrt_inv(self.R)
        self.Q_square_root = self.Q_sqrt_inv(self.Q)
        
        return 0.5*ca.dot(ca.mtimes(self.R_square_root,
                                    v),
                            ca.mtimes(v.T,
                                      self.R_square_root).T) \
                + \
                0.5*ca.dot(ca.mtimes(self.Q_square_root,
                                     w),
                            ca.mtimes(w.T,
                                      self.Q_square_root).T), \
                ca.veccat(self.Q, self.R)
                
    def set_hess_obj(self):
        """
        For covariance estimation.
        
        (negative log-likelihood) 
        """ 
        #### set up log(det) - Functions:
        Q_SX = self.Q_SX
        R_SX = self.R_SX
        
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
         
        x = ca.vec(self.nlp_x)
        z = ca.vec(self.nlp_z)
        u = ca.vec(self.nlp_u)
        y = ca.vec(self.nlp_y)
        p = ca.vertcat(*self.dae.dae.p)
        R = self.R
        Q = self.Q
        
        
        # residual x:
        res_x = self.nlp_parser.x_gaps
        # residual y:
        res_y = self.nlp_parser.h_gaps
        
        #self.alt_obj = 0.5*ca.dot(
        alt_obj = 0.5*ca.dot(
                             ca.mtimes(self.R_square_root,
                                       res_y),
                             ca.mtimes(res_y.T,
                                       self.R_square_root).T) \
                            + \
                  0.5*ca.dot(
                            ca.mtimes(self.Q_square_root,
                                      res_x),
                            ca.mtimes(res_x.T,
                                      self.Q_square_root).T) \
                            + \
                  ((self.N-1)/2)*self.log_det_Q(self.Q) \
                            + \
                  (self.N/2)*self.log_det_R(self.R)
                  
          
        hess_expr =  ca.hessian(alt_obj,
                                ca.vertcat(p,
                                           x,
                                           u,
                                           y,
                                           ca.vec(R),
                                           ca.vec(Q)
                                           )
                                )[0]             
        
        self.hess_obj = ca.Function(
                                    "hess_obj",
                                     [p,
                                      x,
                                      u,
                                      y,
                                      ca.vec(R),
                                      ca.vec(Q)
                                      ],
                                    [hess_expr],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["p", "x", "u", "y", "R", "Q"],
                                    ["hess_obj"]
                                    )           
       
    def get_covar_p(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """
        x_vals =  self.sol_df[self.dae.x].values.flatten()
        u_vals =  self.sol_df[self.dae.u].values.flatten()
        y_vals =  self.sol_df[self.dae.y].values.flatten()
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 u_vals,
                                 y_vals,
                                 ca.vec(R),
                                 ca.vec(Q)
                                 )
        
        param_dim = self.nlp_parser["p"]["dim"]
        
        fisher = hess_val[:param_dim,:param_dim]
        
        return pd.DataFrame(data=np.array(ca.inv(fisher)),
                            index=self.dae.p,
                            columns=self.dae.p), \
                pd.DataFrame(data=np.array(fisher),
                            index=self.dae.p,
                            columns=self.dae.p)
                
    def get_covar_x(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """
        x_vals =  self.sol_df[self.dae.x].values.flatten()
        u_vals =  self.sol_df[self.dae.u].values.flatten()
        y_vals =  self.sol_df[self.dae.y].values.flatten()
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 u_vals,
                                 y_vals,
                                 ca.vec(R),
                                 ca.vec(Q)
                                 )
        
        x_start, x_stop = self.nlp_parser["x"]["range"]["a"], \
                            self.nlp_parser["x"]["range"]["b"]
        
        fisher = np.array(hess_val[x_start:x_stop,x_start:x_stop])
        
        #names = np.repeat(self.dae.x, self.N, axis=1)
        names = np.repeat(np.array([self.dae.x]),
                          self.N,
                          axis=0)
        
        ns = list(map(lambda x: str(x), list(range(self.N))))
        
        x_names = []
        for name_tup, num in zip(names, ns):
            for name in name_tup:
                x_names.append(name + num)
        
        #def namer(*args, y):
        #    ret = []
        #    for s in enumerate(args):
        #        ret.append(s + y)
        #    return ret
        
        #vector_namer = np.vectorize(namer)
        #vector_namer(names, ns)
        
        return pd.DataFrame(data=np.array(np.linalg.inv(fisher)),
                            index=x_names,
                            columns=x_names), \
                pd.DataFrame(data=fisher,
                            index=x_names,
                            columns=x_names)

    # TODO: get full covariance matrix:
    """
    def get_covar_full(self, params, R, Q):

        x_vals =  self.sol_df[self.dae.x].values.flatten()
        u_vals =  self.sol_df[self.dae.u].values.flatten()
        y_vals =  self.sol_df[self.dae.y].values.flatten()
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 u_vals,
                                 y_vals,
                                 ca.vec(R),
                                 ca.vec(Q)
                                 )
        
        x_start, x_stop = self.nlp_parser["x"]["range"]["a"], \
                            self.nlp_parser["x"]["range"]["b"]
        
        fisher = np.array(hess_val[x_start:x_stop,x_start:x_stop])
        
        #names = np.repeat(self.dae.x, self.N, axis=1)
        names = np.repeat(np.array([self.dae.x]),
                          self.N,
                          axis=0)
        
        ns = list(map(lambda x: str(x), list(range(self.N))))
        
        x_names = []
        for name_tup, num in zip(names, ns):
            for name in name_tup:
                x_names.append(name + num)
        
        return pd.DataFrame(data=np.array(np.linalg.inv(fisher)),
                            index=x_names,
                            columns=x_names), \
                pd.DataFrame(data=fisher,
                            index=x_names,
                            columns=x_names)   
    """                
    
    def get_initial_arrival_cost_weight(self, params, R, Q):
        """
        For mhe.
        """
        covar_p, fisher_p = self.get_covar_p(params, R, Q)
        covar_x, fisher_x = self.get_covar_x(params, R, Q)
        #dim_x = self.nlp_parser["x"]["dim"]
        covar_last_x = covar_x.iloc[-self.n_x:,-self.n_x:]
        diag_covar_p = np.diag(covar_p.values)
        diag_covar_x = np.diag(covar_last_x.values)
        
        P0 = pd.DataFrame(
                          data=np.diag(np.append(diag_covar_p, diag_covar_x)),
                          index=list(covar_p.index) + list(covar_last_x.index),
                          columns=list(covar_p.index) + list(covar_last_x.index)
                          )
        
        return P0
        
                            
    def solve(
              self,
              data,
              param_guess,
              covar=None,
              lbp=None,
              ubp=None
              ):
        """
        Set initials for v, w to 0
        """
        self.data = data
        
        #x_guess = repmat(self.Y, 1, self.n_x)
        
        # TODO: logic for generating guesses of unmeasured states? 
        
        # this is for the spring mass damper:
        
        ''' if self.Y.shape[1] != self.integrator.dae.n_x:
            # do this ( n_x - n_y) times:
            yd = np.diff(self.Y,axis=0)*1/self.dt
            x_guess = horzcat(self.Y, vertcat(yd, yd[-1])).T
        else:
            x_guess = self.Y.T '''
            
        #if self.Y.shape[1] != self.integrator.dae.n_x:
            # do this ( n_x - n_y) times:
            
        self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(self.nlp_v,
                                                self.nlp_w) 
        
        self.set_hess_obj()
        
        # generate x guess: two methods: repeat or freq-based
        # -> own method
        #y_info = self.bounds["y"]["lb"]
        #y = self.bounds["y"]["lb"]
        
        ####################### method ###########################
        
        y = self.data[self.y_names].values.flatten()
                    
        x_guess = y
        
        # TODO: handle edge-cases, e.g. n_y = 2 and n_x = 3
        diff = self.integrator.dae.n_x - self.integrator.dae.n_y
        
        for n in range(diff):
            x_guess = horzcat(x_guess, y)

        ##########################################################
        
        self.separate_data(
                          data,
                          lbp=lbp,
                          ubp=ubp,
                          x_guess=x_guess,
                          param_guess=param_guess
                          )
        
        self.set_bounds()
        self._init_solver()
                
        solution = self.solver(
                               x0=self.x0,
                               lbg=0, # option for path-constraints?
                               ubg=0, # --"--
                               lbx=self.lbx,
                               ubx=self.ubx,
                               p=covar
                               )
        
        self.sol_df, params = self.parse_solution(solution)
        
        return self.sol_df, params