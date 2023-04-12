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
        
        self.slack = slack = kwargs.pop("slack", False)
        ref = kwargs.pop("ref", False)
        
        super().__init__(**kwargs) # does all the work.
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, ref=ref)
        
        
        # TODO: with single shooting, form slack on N instead x.shape
        if slack:
            #self.s = s = ca.MX.sym("s",
            #                        self.nlp_parser["x"]["dim"])
            #self.s = s = ca.MX.sym("s",
            #                        (self.N-1)*self.n_x)
            self.s = s = ca.MX.sym("s",
                                    self.N*self.n_x)
            
            self.nlp["x"] = ca.vertcat(self.nlp["x"],
                                       s)
            
            dim = s.shape[0]*s.shape[1]
            # modify nlp parser:
            self.nlp_parser.vars["s"] = {
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
            self.n_s = self.n_x
            self.slack_names = list(map(lambda x: "s" + str(x+1), range(self.n_s)))
            
        self.nlp["f"] = self.get_nlp_obj(self.nlp_u, self.nlp_z, ref=ref, slack=slack)
        
        #self.add_pseudo_params()
        
        #self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(self.nlp_u)
        #self.nlp["f"] = self.get_nlp_obj(self.nlp_u, self.nlp_lslack, self.nlp_uslack)
        
        #self.set_bounds(y=self.Y,
        #                u=self.U)
        #self.set_bounds()
        #self._init_solver()
      
      
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
                #return 0.5*ca.dot(u, u) # + 0.01*ca.dot(slack, slack)
                return 0.5*ca.dot(z, z) # + 0.01*ca.dot(slack, slack)
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
                self.lbx[0:self.n_x] = x0
                self.ubx[0:self.n_x] = x0
                self.x0[0:self.n_x] = x0
                
            #x = self.nlp["x"][(x_info["range"]["a"] + self.n_x):x_info["range"]["b"]]
            
            # path limits:
            
            #self.uslack = uslack = ca.MX.sym("uslack", x_info["dim"])
            #self.lslack = lslack = ca.MX.sym("lslack", x_info["dim"])
            
            # move this to nlp dict somehow: ? init ?
            # slack var:
            #self.slack = slack = ca.MX.sym("s", x_info["dim"])
            
            # add to nlp dict:
            #self.nlp["x"] = ca.vertcat(self.nlp["x"], slack)
            
            # path constraint:
            h_x = x
            # add bounds, -inf and inf in dim(s) and 0 for x0
            if self.slack:
                
                assert self.n_x == self.n_s

                self.lbx = np.append(self.lbx, np.repeat([-np.inf], self.nlp_parser.vars["s"]["dim"]))
                self.ubx = np.append(self.ubx, np.repeat([np.inf], self.nlp_parser.vars["s"]["dim"]))
                self.x0 = np.append(self.x0, np.repeat([0], self.nlp_parser.vars["s"]["dim"]))
                
                h_x += self.s[self.n_s:]
                
            # modify x0 with feasible value for sqp:
            #self.x0[x_info["range"]["a"]:x_info["range"]["b"]] = lbx
                
            #slack = ca.vertcat(uslack, lslack)
            
            #upper_constr = x - ubx - uslack
            #lower_constr = lbx - x - lslack#, 
            
            #lower_constr = x["x"] = ca.vertcat(self.nlp["x"], slack)
            
            #lower_constr = lbx - x
            
            #lbg = np.array([0]*self.nlp["orig_g"].shape[0])
            #ubg = np.array([0]*self.nlp["orig_g"].shape[0])
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
            
            #if self.slack:
                    
            #    self.lbx = np.append(self.lbx, np.repeat([-np.inf], x_info["dim"]))
            #    self.ubx = np.append(self.ubx, np.repeat([np.inf], x_info["dim"]))
            #    self.x0 = np.append(self.x0, np.repeat([0], x_info["dim"]))
                
            #    h_x += self.s
            
        #elif self.strategy.name == "Collocation":
        #    raise NotImplementedError("Just expand bounds to fit with collocation.")
        
        
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
              return_raw_sol=False
              ):
        """
        todo
        """
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
        self.add_path_constraints(
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
