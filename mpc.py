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
        
        super().__init__(**kwargs) # does all the work.
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, ref=ref)
         
        # TODO: with single shooting, form slack on N instead of x.shape
        if self.slack:
            #self.s = s = ca.MX.sym("s",
            #                        self.nlp_parser["x"]["dim"])
            #self.s = s = ca.MX.sym("s",
            #                        (self.N-1)*self.n_x)
            self.sl = sl = ca.MX.sym("s",
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
        self.set_nlp_obj()
        
        # set up lbg, ubg:
        self.lbg = np.array([0]*self.nlp_parser.g.shape[0])
        self.ubg = np.array([0]*self.nlp_parser.g.shape[0])
        
        self.add_h() 
        self.add_path_constraints_symbolically()
        # add h:
        
        #self.add_pseudo_params()
        
        #self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(self.nlp_u)
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, self.nlp_lslack, self.nlp_uslack)
        
        #self.set_bounds(y=self.Y,
        #                u=self.U)
        #self.set_bounds()
        #self._init_solver()
        
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
        """
        Parse MHE objective as passed in from config file.
        """
        
        # initialize the parameters needed for the objective:
        """
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        self.P0 = ca.MX.sym("P0", ca.Sparsity.diag(self.n_x + self.n_p))
        self.costate_prior = ca.MX.sym("costate_prior", self.n_x + self.n_p)
        """
        
        """
        a = ca.MX.sym("a")
        d = ca.MX.sym("d")
        c1 = ca.MX.sym("c1")
        c2 = ca.MX.sym("c2")
        V0 = ca.MX.sym("V0")
        
        # TODO: fix for collocation:
        #Ti = self.get("Ti")
        # temp fix for n_x == 1:
        # TODO: boundary vars for all discretization strategies:
        Ti = self.nlp_parser.vars["x"]["boundary_vars"]
        phi_h = self.get("phi_h")
        sl = self.sl
        """
        
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
            try:
                exec(f'obj_expr =' + obj_string, vals)
            except: # temp fix
                # TODO: more solid logic here 
                vals["Ti"] = vals["Ti"][0:-1:(self.integrator.d+1)].T
                vals["E"] = vals["E"][0:-1:(self.integrator.d+1)].T
                exec(f'obj_expr =' + obj_string, vals)
            obj_expr = vals["obj_expr"]
        # TODO: extra parameter for last state:
        else: # build objective 'by hand':
            raise ValueError("error")
            """
            obj_expr = 0
            for n in range(self.N-1):
                residual = (Ti[n] - 0.5)
                obj_expr += (self.gamma**n)*a*ca.dot(phi_h[n], phi_h[n])
                obj_expr += (self.gamma**n)*d*ca.dot(residual, residual)
                #obj_expr += Ti[n]*c1
            last_residual = (Ti[self.N-1] - 0.5)
            obj_expr += (self.gamma**(self.N-1))*a*ca.dot(last_residual, last_residual)
            if self.slack:
                obj_expr += 1E3*ca.dot(sl, sl)
            """
            
        #self.nlp["p"] = ca.vertcat(a, d, c1, c2, V0)

        #wf = ca.MX.sym("wf", self.dae.n_x, self.N)
        #wf = ca.MX.sym("wf", self.N, self.dae.n_x)
        #vals["wf"] = wf
        
        #theta = ca.MX.sym("theta", x1.shape[0], x1.shape[1])
        #wf = ca.MX.sym("wf", x1.shape[0], x1.shape[1])
        
        # TODO: avoid hard-coding of objective here:
        
        """
        for n in range(self.N-1):
            #obj_expr += (Ti[n] - 0.5)*c1
            obj_expr += Ti[n]*c1
            obj_expr += phi_h[n]*c2
        obj_expr += V0
        """
        
        self.nlp["f"] = obj_expr
        #self.nlp["f"] = vals["obj_expr"]
        #self.nlp["f"] = vals["obj_expr"] + theta.T@(x1 - 4/12)
        #self.nlp["p"] = theta
        #self.nlp["p"] = wf
        #self.nlp["p"] = ca.veccat(self.R, self.Q)
        
    def add_pseudo_params(self):
        """ Add pseudo-params. """
        x0_p = ca.MX.sym("x0_p", self.n_x)
        p_p = ca.MX.sym("p_p", self.n_p)
        
        nlp_p = ca.vertcat(x0_p, p_p)
        
        # add constraints:
        self.x0_start = self.nlp_parser["x"]["range"]["a"]
        self.x0_stop = self.nlp_parser["x"]["range"]["a"] + self.n_x
        self.p_start = self.nlp_parser["p"]["range"]["a"]
        self.p_stop = self.nlp_parser["p"]["range"]["b"]
        
        p_equals_p = p_p - self.nlp["x"][self.p_start:self.p_stop]
        x0_equals_x0 = x0_p - self.nlp["x"][self.x0_start:self.x0_stop]
        
        self.nlp_parser.g = ca.vertcat(self.nlp["g"], p_equals_p, x0_equals_x0)
        self.nlp["p"] = nlp_p
           
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
    
    """
    def add_path_constraints(
                            self,
                            x0=None,
                            lbx=None,
                            ubx=None
                            #slack=False
                            ):
        # TODO: refactor 
        
        #if isinstance(self.strategy, MultipleShooting):
        if self.strategy.name in ("MultipleShooting", "Collocation"):
            x_info = self.nlp_parser["x"]
            
            if self.strategy.name == "MultipleShooting":
                #x = self.nlp["x"][(x_info["range"]["a"] + self.n_x):x_info["range"]["b"]]
                x = self.nlp["x"][(x_info["range"]["a"]):x_info["range"]["b"]]
                lbx = np.append(x0, lbx)
                ubx = np.append(x0, ubx)
            else:
                # TODO: expand bounds to all collocation points
                # Collocation
                d = self.strategy.d
                #x = self.nlp["x"][x_info["range"]["a"]:x_info["range"]["b"]:(d+1)]
                x = x_info["boundary_vars"]
                
                # set bounds on x0: (to be set as parameter in parametric NLP !!)
                #self.lbx[0:self.n_x] = x0
                #self.ubx[0:self.n_x] = x0
                self.x0[0:self.n_x] = x0
                lbx = np.append(x0, lbx)
                ubx = np.append(x0, ubx)
                
            h_x = x
            # add bounds, -inf and inf in dim(s) and 0 for x0
            if self.slack:
                
                assert self.n_x == self.n_sl
   
                #self.lbx = np.append(self.lbx, np.repeat([-np.inf], self.nlp_parser.vars["sl"]["dim"]))
                self.lbx = np.append(self.lbx, np.repeat([0], self.nlp_parser.vars["sl"]["dim"]))
                self.ubx = np.append(self.ubx, np.repeat([np.inf], self.nlp_parser.vars["sl"]["dim"]))
                self.x0 = np.append(self.x0, np.repeat([0], self.nlp_parser.vars["sl"]["dim"]))
                
                #h_x += self.sl[self.n_sl:]
                
                # introduce extra params here:
                #h_x += self.sl
                #b_up = ca.MX.sym("b_up", self.sl.shape[1])
                #b_down = ca.MX.sym("b_down", self.sl.shape[1])
                b = ca.MX.sym("b", self.sl.shape[1])
                for n in range(self.N):
                    #h_x[n:n+1] += (self.sl[n:n+1] + b_up - b_down)
                    h_x[n:n+1] += (self.sl[n:n+1] + b)
                
                # keep b as parameter:
                self.nlp["p"] = ca.vertcat(self.nlp["p"], b)
                #self.nlp["p"] = ca.vertcat(b_up, b_down)
                
            lbg = np.array([0]*self.nlp_parser.g.shape[0])
            ubg = np.array([0]*self.nlp_parser.g.shape[0])
            
            self.lbg = np.append(lbg, lbx)
            self.ubg = np.append(ubg, ubx)
            
            #self.nlp["g"] = ca.vertcat(self.nlp["orig_g"], path_constr)
            #self.nlp["g"] = ca.vertcat(self.nlp_parser.g, path_constr)
            
            self.nlp["g"] = ca.vertcat(self.nlp_parser.g, h_x)
            
        #elif isinstance(self.strategy, SingleShooting):
        elif self.strategy.name == "SingleShooting":
            
            # just use N?
            len_x_bounds = self.nlp_parser.x_bounds_g[1] - self.nlp_parser.x_bounds_g[0] - 1
            len_g_wo_x_bounds = self.nlp_parser.g.shape[0] - len_x_bounds 
            lbg = np.array([0]*len_g_wo_x_bounds)
            ubg = np.array([0]*len_g_wo_x_bounds)
            
            self.lbg = np.append(lbx, lbg)
            self.ubg = np.append(ubx, ubg)
            
            self.nlp["g"] = self.nlp_parser.g
            if self.slack: # check   
                
                assert self.n_x*self.N == self.s.shape[0]*self.s.shape[1]
                
                self.nlp["g"][self.nlp_parser.x_bounds_g[0]:self.nlp_parser.x_bounds_g[1]-1] += self.s[self.n_x:(self.n_x*self.N)]
                
                self.lbx = np.append(self.lbx, np.repeat([-np.inf], self.n_x*(self.N-1)))
                self.ubx = np.append(self.ubx, np.repeat([np.inf], self.n_x*(self.N-1)))
                self.x0 = np.append(self.x0, np.repeat([0], self.n_x*(self.N-1)))
                
                
            
            # set x0 (state):
            x_info = self.nlp_parser["x"]
            x_start = x_info["range"]["a"]
            x_stop = x_info["range"]["b"]
            self.lbx[x_start:x_stop] = x0
            self.ubx[x_start:x_stop] = x0
    """
          
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
            self.x0[start:stop] = x0    
            # set bounds for x0:
            self.lbx[start:stop] = x0    
            self.ubx[start:stop] = x0    
            
            lbg = np.append(self.lbg, np.append(x0, lbx))
            ubg = np.append(self.ubg, np.append(x0, ubx))
            
            return lbg, ubg
            
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
              return_raw_sol=False
              ):
        self.data = data
        # let pure 'x' be unbounded
        
        
        # TODO: data separation depending on discretization::
        
        self.separate_data(
                          data,
                          lbp=params,
                          ubp=params,
                          p_guess=params
                          #x0=x0
                          )  
        
        self.set_bounds()
        
        
        # for parametric sensitivities:
        #self.add_pseudo_params()
        
        # add lbx and ubx as path constraints on g:
        # ADD: option for slack:
        #self.add_path_constraints(x0=x0, lbx=lbx, ubx=ubx)
        
        # TODO: only do this once (symbolically):: 
        lbg, ubg = self.add_path_constraints(
                                            x0=(x0 - self.x_nom_b)/self.x_nom,
                                            lbx=(lbx - self.x_nom_b)/self.x_nom,
                                            ubx=(ubx - self.x_nom_b)/self.x_nom,
                                            )
                                            #slack=slack)
        
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, slack)
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, ref=ref, slack=slack)
        if not hasattr(self, "solver"):      
            self._init_solver()
        
        #slack_lb = ca.DM(self.lbx)[0:50] - self.nlp["x"][-50:]
        #slack_ub = ca.DM(self.ubx)[0:50] + self.nlp["x"][-50:]
        #lbx = ca.vertcat(slack_lb, self.lbx[50:])
        #ubx = ca.vertcat(slack_ub, self.ubx[50:])
             
        # get value of p (of nlp): 
        #self.p_val = np.append(self.x0[self.x0_start:self.x0_stop],
        #                 self.x0[self.p_start:self.p_stop])
        
        # large number -> inf/-inf
        self.lbx = np.array([val if abs(val) < 1e8 else -np.inf for val in self.lbx])
        self.ubx = np.array([val if val < 1e8 else np.inf for val in self.ubx])
          
        self.p_val = np.append((x0 - self.x_nom_b)/self.x_nom, params/self.scale)
              
        sol = self.solver(
                            x0=self.x0,
                            lbg=self.lbg,
                            ubg=self.ubg,
                            lbx=self.lbx,
                            ubx=self.ubx
                            #p=params*self.scale
                            #p=self.p_val
                         )
        sol["p"] = self.p_val
        
        
        """
        sqp_sol = self.sqp_solver(
                               #x0=sol["x"],
                               x0=self.x0,
                               lbg=self.lbg,
                               ubg=self.ubg,
                               lbx=self.lbx,
                               ubx=self.ubx
                               #p=self.p_val
                               )
        self.sqp_sol = sqp_sol
        """
        
        ########################## parse solution ######################################
        
        sol_df, params = self.parse_solution(sol)
        
        #################################################################################
        if not return_raw_sol:
            return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[self.dt, self.x_names].values
        else:
            return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[self.dt, self.x_names].values, sol
    
    def solve(
              self,
              data,
              x0=None,
              lbx=None,
              ubx=None,
              params=None,
              return_raw_sol=False,
              codegen=False,
              p_val=None
              ):
        lbg, ubg = self.prepare_solve(data,x0=x0,lbx=lbx,ubx=ubx,params=params)
        return self._solve(lbg=lbg, ubg=ubg, return_raw_sol=return_raw_sol, codegen=codegen, p_val=p_val)
    
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
            vals["expr_dict"] = expr_dict
            exec(f'expr_dict[%s] =' % (i,) + expr_string, vals)
            #exec(f'expr_dict[%s] =' % (i,) + expr_string, vals)
            #print(expr_dict)
            
            """
            Now, add this constraint to nlp.g
            add also corresponding entries for lbg and ubg
            """
            
            expr = expr_dict[i]
            self.nlp["g"] = ca.vertcat(self.nlp["g"], expr)
            self.lbg = np.append(self.lbg, np.array([elem["lhs"]]*expr.shape[0]))
            self.ubg = np.append(self.ubg, np.array([elem["rhs"]]*expr.shape[0]))
            
        
        """
        expr_string = self.h_exprs["body"][0]
        vals = {}
        for symbol in self.h_exprs["symbols"]:
            vals[symbol] = self.get(symbol)
            
        vals["expr_dict"] = expr_dict
            
        exec(f'expr_dict["0"] =' + expr_string, vals)
        
        print(expr_dict)
        """    
        
    
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
        
        # for parametric sensitivities:
        #self.add_pseudo_params()
        
        # add lbx and ubx as path constraints on g:
        # ADD: option for slack:
        #self.add_path_constraints(x0=x0, lbx=lbx, ubx=ubx)
        
        # TODO: only do this once (symbolically):: 
        lbg, ubg = self.add_path_constraints(
                                            x0=(x0 - self.x_nom_b)/self.x_nom,
                                            lbx=(lbx - self.x_nom_b)/self.x_nom,
                                            ubx=(ubx - self.x_nom_b)/self.x_nom,
                                            )
                                            #slack=slack)
        
        
        """
        Try to add parameter here:
        """
        
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, slack)
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, ref=ref, slack=slack)
        
        #slack_lb = ca.DM(self.lbx)[0:50] - self.nlp["x"][-50:]
        #slack_ub = ca.DM(self.ubx)[0:50] + self.nlp["x"][-50:]
        #lbx = ca.vertcat(slack_lb, self.lbx[50:])
        #ubx = ca.vertcat(slack_ub, self.ubx[50:])
             
        # get value of p (of nlp): 
        #self.p_val = np.append(self.x0[self.x0_start:self.x0_stop],
        #                 self.x0[self.p_start:self.p_stop])
        
        # large number -> inf/-inf
        self.lbx = np.array([val if abs(val) < 1e8 else -np.inf for val in self.lbx])
        self.ubx = np.array([val if val < 1e8 else np.inf for val in self.ubx])
          
        self.p_val = np.append((x0 - self.x_nom_b)/self.x_nom, params/self.scale)
        # add data-independent constraints:   
        # TODO: fix this: 
        #self.add_h() 

        return lbg, ubg

        # add c1, c2 to constraints:
        """
        self.nlp["g"] = ca.vertcat(self.nlp["g"], self.nlp["p"][0])
        self.nlp["g"] = ca.vertcat(self.nlp["g"], self.nlp["p"][1])
        self.lbg = np.append(self.lbg, [0, 0])
        self.ubg = np.append(self.ubg, [np.inf, np.inf])
        """
              
    def _solve(
               self,
               lbg=None,
               ubg=None,
               return_raw_sol=False,
               codegen=False,
               p_val=None
              ):
        
        # TODO: parameter re-init solver
        if not hasattr(self, "solver"):      
            self._init_solver()

        gen_code_filename = self.get_c_code_name()
        if codegen and not os.path.exists(gen_code_filename):
            self.pregenerate_c_code(gen_code_filename)
            
        #if self.slack:
        #    self.x0 = np.append(self.x0, np.repeat([0], self.s.shape[0]))
        self.lbg_current = lbg
        self.ubg_current = ubg
        
        # code-generate this function-object:
        if p_val is None:
            sol = self.solver(
                                x0=self.x0,
                                lbg=lbg,
                                ubg=ubg,
                                lbx=self.lbx,
                                ubx=self.ubx,
                            )
        else:
            sol = self.solver(
                                x0=self.x0,
                                lbg=lbg,
                                ubg=ubg,
                                lbx=self.lbx,
                                ubx=self.ubx,
                                #p=params*self.scale
                                p=p_val
                            )
        sol["p"] = self.p_val
        
        """
        sqp_sol = self.sqp_solver(
                               #x0=sol["x"],
                               x0=self.x0,
                               lbg=self.lbg,
                               ubg=self.ubg,
                               lbx=self.lbx,
                               ubx=self.ubx
                               #p=self.p_val
                               )
        self.sqp_sol = sqp_sol
        """
        
        ########################## parse solution ######################################
        
        sol_df, params = self.parse_solution(sol)
        
        #################################################################################
        if not return_raw_sol:
            return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[self.dt, self.x_names].values
        else:
            return sol_df, sol_df.loc[0, self.u_names], sol_df.loc[self.dt, self.x_names].values, sol
