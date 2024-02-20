#from argparse import ArgumentError
import casadi as ca
#from casadi import *
#from abc import ABC, abstractmethod, ABCMeta
import pandas as pd
#pd.set_option("display.precision", 8)
import numpy as np
#np.set_printoptions(precision=10)
#import json
#import sys
#import pdb
from pprint import pprint
#from sysid.shooting import MultipleShooting, SingleShooting
#import copy
import subprocess
from copy import deepcopy
import re

#from tables import Col
#from integrators import RungeKutta4, Cvodes, IRK
#import sysid.integrators as integrators
#from sysid.dae import DAE
#from shooting import MultipleShooting
#from callback import ProcessIdCallback
#import os
#from shooting import Collocation
#from sysid.ocp import OCP
#import typing
from ocp.ocp import OCP
import os
from ocp.shooting import MultipleShooting, SingleShooting, Collocation

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
        
        ref = kwargs.pop("ref", False)
        
        super().__init__(**kwargs)
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, ref=ref)
        # TODO: with single shooting, form slack on N instead of x.shape
        if self.slack:
            
            self.sl = sl = ca.MX.sym("sl",
                                    self.N*self.n_x)
            
            self.nlp["x"] = ca.vertcat(self.nlp["x"],
                                       sl)

            dim = sl.shape[0]*sl.shape[1]
            # modify nlp parser:
            self.nlp_parser.vars["sl"] = {
                                        "range":
                                                {
                                                 "a":
                                                    self.nlp_parser["r"]["range"]["b"],
                                                 "b": 
                                                    self.nlp_parser["r"]["range"]["b"] + \
                                                        dim
                                                },
                                        "dim": dim
                                        }
            self.n_sl = self.n_x
            self.slack_names = list(map(lambda x: "s" + str(x+1), range(self.n_sl)))
            
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, self.nlp_z, ref=ref, slack=slack)
        if "f" not in self.nlp:
            self.set_nlp_obj()
        
        # set up lbg, ubg:
        self.lbg = np.array([0]*self.nlp_parser.g.shape[0])
        self.ubg = np.array([0]*self.nlp_parser.g.shape[0])
        
        self.add_h() 
        #self.add_path_constraints_symbolically()
        # TOOD: add settings:
        self.prepare_solver()
    
        
        
    def add_path_constraints_symbolically(self):
        """
        Add constraints for state path.
        """
        x_info = self.nlp_parser["x"]
        nx = self.n_x
        
        if self.strategy.name == "MultipleShooting":
            #x = self.nlp["x"][(x_info["range"]["a"] + self.n_x):x_info["range"]["b"]]
            x = self.nlp["x"][(x_info["range"]["a"]):x_info["range"]["b"]]
            #lbx = np.append(x0, lbx)
            #ubx = np.append(x0, ubx)
        elif self.strategy.name == "Collocation":
            # TODO: expand bounds to all collocation points
            # Collocation
            #d = self.strategy.d
            #x = self.nlp["x"][x_info["range"]["a"]:x_info["range"]["b"]:(d+1)]
            x = x_info["boundary_vars"]
            
            # set bounds on x0: (to be set as parameter in parametric NLP !!)
            #self.lbx[0:self.n_x] = x0
            #self.ubx[0:self.n_x] = x0
            #self.x0[0:self.n_x] = x0
            #lbx = np.append(x0, lbx)
            #ubx = np.append(x0, ubx)
        else:
            raise ValueError("Not implemented for single shooting yet.. ")
            
        #h_x = x
        # add bounds, -inf and inf in dim(s) and 0 for x0
        #b = ca.MX.sym("b", self.n_x)
        h_x = []
        
        if self.slack:    
            assert self.n_x == self.n_sl

            #self.lbx = np.append(self.lbx, np.repeat([-np.inf], self.nlp_parser.vars["sl"]["dim"]))
            #self.lbx = np.append(self.lbx, np.repeat([0], self.nlp_parser.vars["sl"]["dim"]))
            #self.ubx = np.append(self.ubx, np.repeat([np.inf], self.nlp_parser.vars["sl"]["dim"]))
            #self.x0 = np.append(self.x0, np.repeat([0], self.nlp_parser.vars["sl"]["dim"]))
            
            #h_x += self.sl[self.n_sl:]
            
            # introduce extra params here:
            #h_x += self.sl
            #b_up = ca.MX.sym("b_up", self.sl.shape[1])
            #b_down = ca.MX.sym("b_down", self.sl.shape[1])
            
            
            # TODO: this should be conditional:
            #b = ca.MX.sym("b", self.sl.shape[1])
            for n in range(self.N):
                #h_x[n:n+1] += (self.sl[n:n+1] + b_up - b_down)
                #h_x[n:n+1] += (self.sl[n:n+1] + b)
                expr = x[(n*nx):((n*nx) + nx)] + self.sl[(n*nx):((n*nx) + nx)] # + b
                h_x.append(expr)
        else:
            for n in range(self.N):
                #h_x[n:n+1] += (self.sl[n:n+1] + b_up - b_down)
                #h_x[n:n+1] += b
                expr = x[(n*nx):((n*nx) + nx)] # + b
                h_x.append(expr)
                        
        # keep b as parameter:
        #self.nlp["p"] = ca.vertcat(self.nlp["p"], b)
        #self.nlp["p"] = ca.vertcat(b_up, b_down)
        
        #self.lbg = np.append(lbg, lbx)
        #self.ubg = np.append(ubg, ubx)
    
        # Add numerical values for path constraint each solve:        
        self.nlp["g"] = ca.vertcat(self.nlp["g"], *h_x)
        
        
    ### should work for reading from config:  
    def set_nlp_obj(self):
        
        if self.use_objective_from_cfg:
            matchers = self.dae.all_names
            symbols = set([s for s in matchers if s in self.obj_string])
            #symbols = set(re.findall("|".join(self.dae.all_names), self.obj_string))
            vals = dict()
            for symbol in symbols:
                vals[symbol] = self.get(symbol)
            obj_string = self.obj_string.replace("dot", "ca.dot")
            obj_string = obj_string.replace("sqrt", "ca.sqrt")
            vals["ca"] = ca
            try:
                vals["sl"] = self.sl
            except AttributeError:
                assert self.slack is False
            
            if self.slack:
                assert "sl" in obj_string
            #vals["R"] = self.R
            #vals["Q"] = self.Q
            #vals["a"] = a
            #vals["d"] = d
            #vals["c1"] = c1
            #vals["c2"] = c2
            #vals["V0"] = V0
            # exec objective:
            
            """
            TODO: fix:
            """
            try:
                exec(f'obj_expr =' + obj_string, vals)
            except: # temp fix
                # TODO: more solid logic here 
                if "Ti" in vals:
                    vals["Ti"] = vals["Ti"][0:-1:(self.integrator.d+1)].T
                if "E" in vals:
                    vals["E"] = vals["E"][0:-1:(self.integrator.d+1)].T
                #vals["E"] = vals["E"][0:-1:(self.integrator.d+1)].T
                if self.functions is not None:
                    for k, v in self.functions.items():
                        vals[k] = v
                exec(f'obj_expr =' + obj_string, vals)
            obj_expr = vals["obj_expr"]
        # TODO: extra parameter for last state:
        else: # build objective 'by hand':
            raise ValueError("error")
        
        self.nlp["f"] = obj_expr
        
    #def get_nlp_obj(self, u, slack):
    def get_nlp_obj(self, u, z, ref=False, slack=False):
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
        if not ref:
            #return 0.5*ca.dot(u, u) # + 0.01*ca.dot(slack, slack)
            #return 0.5*ca.dot(u[0, :], u[0, :]) # + 0.01*ca.dot(slack, slack)
            if slack:
                #l_expr = 0.5*ca.dot(u, u) + \
                #         1E5*ca.dot(self.s, self.s)
                
                #dim_u = 
                
                # only for function instance:
                #return 0.5*ca.dot(u, u) + 1E5*ca.dot(self.s, self.s)
                
                
                u = ca.MX.sym("u", self.n_u)
                s = ca.MX.sym("s", self.n_s)
                
                # stage cost:
                self.L = ca.Function("L",
                                     [u, s],
                                     [0.5*u.T@u + 1E8*s.T@s],
                                     ["u", "s"],
                                     ["L"])
                
                # value function:
                self.V = self.L.map(self.N-1)
                
                dim_s = self.nlp_parser.vars["s"]["dim"]
                s_sym = self.s[0:(dim_s-self.n_s)]
                
                V_call = self.V(self.nlp_u.reshape((self.n_u, self.N-1)),
                                s_sym.reshape((self.n_s, self.N-1)))
                
                sqrt_call = ca.sqrt(V_call)
                
                last_s = self.s[dim_s-self.n_s:]
                
                return ca.mtimes(sqrt_call, sqrt_call.T) + 1E8*last_s.T@last_s
                
                         
                
            else:
                return 0.5*ca.dot(u, u) # + 0.01*ca.dot(slack, slack)
                #return 0.5*ca.dot(z, z) # + 0.01*ca.dot(slack, slack)
        else: # reference tracking
            
            # how to know which state to track?
    
            x_bounds = self.nlp_parser["x"]["range"]
            r_bounds = self.nlp_parser["r"]["range"]
            x_ref = self.nlp["x"][x_bounds["a"]:x_bounds["b"]:self.dae.n_x]
            # need modular way to find the shift in r:
            r_ref = self.nlp["x"][(r_bounds["a"]+2):r_bounds["b"]:self.dae.n_r]
            delta = x_ref - r_ref
            return 0.5*ca.dot(delta, delta) # + 0.05*ca.dot(u, u)
            
        # add slew rate:
        #u_slew = (u[1:] - u[:-1])
        #return 0.5*ca.dot(u, u) - 0.01*ca.dot(u_slew, u_slew) # + 0.01*ca.dot(slack, slack)
          
    def add_path_constraints(
                            self,
                            x0=None,
                            lbx=None,
                            ubx=None
                            #slack=False
                            ):
        """
        TODO: this method now both sets and returns
        values. FIX
        
        TODO: two different methods=?
        """
        
        #if isinstance(self.strategy, MultipleShooting):
        if self.strategy.name in ("MultipleShooting", "Collocation"):
        
            x_info = self.nlp_parser["x"]
            start = x_info["range"]["a"]
            stop = start + self.n_x
            # set x0:
            #self.x0[0:self.n_x] = x0    
            # set bounds for x0:
            self.x0[start:stop] = x0  
            
            if not self.slack:  
                self.lbx[start:stop] = x0    
                self.ubx[start:stop] = x0    
                
            lbg = np.append(self.lbg, np.append(x0, lbx))
            ubg = np.append(self.ubg, np.append(x0, ubx))
            
            return lbg, ubg
            
        #elif isinstance(self.strategy, SingleShooting):
        elif self.strategy.name == "SingleShooting":
            raise ValueError("Not implemented for single shooting yet..")
        
    def add_path_constraints(
                            self,
                            x0=None,
                            lbx=None,
                            ubx=None
                            #slack=False
                            ):
        """
        Alternative implementation.
        
        Sets x, u bounds on variables
        directly (lbx, ubx).
        
        Easier RL implementation / 
        sensitivity calculations
        """
        
        #if isinstance(self.strategy, MultipleShooting):
        if self.strategy.name in ("MultipleShooting", "Collocation"):
        
            x_info = self.nlp_parser["x"]
            start = x_info["range"]["a"]
            stop = start + self.n_x
            # set x0:
            #self.x0[0:self.n_x] = x0    
            # set bounds for x0:
            self.x0[start:stop] = x0  
            
            self.lbx[start:stop] = x0    
            self.ubx[start:stop] = x0    
            """
            if not self.slack:  
                self.lbx[start:stop] = x0    
                self.ubx[start:stop] = x0    
            """
            start = stop
            stop = x_info["range"]["b"]
            
            self.lbx[start:stop] = lbx
            self.ubx[start:stop] = ubx
            
        #elif isinstance(self.strategy, SingleShooting):
        elif self.strategy.name == "SingleShooting":
            raise ValueError("Not implemented for single shooting yet..")
    
    def solve(
              self,
              data,
              x0=None,
              lbx=None,
              ubx=None,
              params=None,
              return_raw_sol=False,
              codegen=False,
              p_val=None,
              sqp=False
              ):
        #lbg, ubg = self.prepare_solve(data,x0=x0,lbx=lbx,ubx=ubx,params=params)
        self.prepare_solve(data,x0=x0,lbx=lbx,ubx=ubx,params=params)
        return self._solve(lbg=self.lbg,
                           ubg=self.ubg,
                           return_raw_sol=return_raw_sol,
                           p_val=p_val,
                           sqp=sqp,
                           codegen=codegen)
    
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
            
            """
            Now, add this constraint to nlp.g
            add also corresponding entries for lbg and ubg
            
            TODO: more solid logic here
            """
            
            expr = expr_dict[i]
            #if self.method == "collocation":
                #expr = expr.T
            self.nlp["g"] = ca.vertcat(self.nlp["g"], expr) # TODO: .T?
            self.lbg = np.append(self.lbg, np.array([elem["lhs"]]*expr.shape[0]))
            self.ubg = np.append(self.ubg, np.array([elem["rhs"]]*expr.shape[0]))
            
    
    def prepare_solve(self,
                    data,
                    x0=None,
                    lbx=None,
                    ubx=None,
                    params=None,
                    ):
        self.data = data
        self.separate_data(
                          data,
                          lbp=params,
                          ubp=params,
                          p_guess=params
                          #x0=x0
                          )  
        self.set_bounds()
        # TODO: only do this once (symbolically):: 
        """
        lbg, ubg = self.add_path_constraints(
                                            x0=(x0 - self.x_nom_b)/self.x_nom,
                                            lbx=(lbx - self.x_nom_b)/self.x_nom,
                                            ubx=(ubx - self.x_nom_b)/self.x_nom,
                                            )
        """
        self.add_path_constraints(
                                 x0=(x0 - self.x_nom_b)/self.x_nom,
                                 lbx=(lbx - self.x_nom_b)/self.x_nom,
                                 ubx=(ubx - self.x_nom_b)/self.x_nom,
                                )
        # large number -> inf/-inf
        #self.lbx = np.array([val if abs(val) < 1e8 else -np.inf for val in self.lbx])
        #self.ubx = np.array([val if val < 1e8 else np.inf for val in self.ubx])
        #return lbg, ubg
              
    def _solve(
               self,
               lbg=None,
               ubg=None,
               return_raw_sol=False,
               p_val=None,
               sqp=False,
               codegen=False
              ):
        
        # TODO: parameter re-init solver
        """
        if not hasattr(self, "solver"):      
            self._init_solver()

        #gen_code_filename = self.get_c_code_name()

        if codegen and not os.path.exists(self.gen_code_filename):
            self.pregenerate_c_code(self.gen_code_filename)
        """
        
        #if self.slack:
        #    self.x0 = np.append(self.x0, np.repeat([0], self.s.shape[0]))
        self.lbg_current = lbg
        self.ubg_current = ubg
        
        # code-generate this function-object:
        """
        TODO: remove sqp-solver
        """
        if sqp is True:
            solver = self.sqp_solver
        else:
            solver = self.solver
            
        self.prepare_solver(codegen=codegen)
        if p_val is None:
            sol = solver(
                        x0=self.x0,
                        lbg=self.lbg,
                        ubg=self.ubg,
                        lbx=self.lbx,
                        ubx=self.ubx,
                        )
        else:
            sol = solver(
                        x0=self.x0,
                        lbg=self.lbg,
                        ubg=self.ubg,
                        lbx=self.lbx,
                        ubx=self.ubx,
                        #p=params*self.scale
                        p=p_val
                        )
        
        ########################## parse solution ######################################
        
        sol_df, params = self.parse_solution(sol)
        
        #################################################################################
        if not return_raw_sol:
            #return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[self.dt, self.x_names].values
            return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[1, self.x_names].values
        else:
            #return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[self.dt, self.x_names].values, sol
            return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[1, self.x_names].values, sol
