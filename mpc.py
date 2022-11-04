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
#import pprint
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
