#from argparse import ArgumentError
import casadi as ca
#from casadi import *
#from abc import ABC, abstractmethod, ABCMeta
import pandas as pd
#pd.set_option("display.precision", 8)
#import numpy as np
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
    def get_nlp_obj(self, v, w, P0, x_N, p0, arrival_cost=False):
        """ 
        Objective for mhe.
        """          
        # define Q, R here:
        """
        self.Q_SX = ca.SX.sym("Q", self.n_x, self.n_x)
        self.R_SX = ca.SX.sym("R", self.n_y, self.n_y)
        self.P0_SX = ca.SX.sym("R", self.n_y, self.n_y)
        # actual:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        self.P0 = ca.MX.sym("P0", self.n_x + self.n_p, self.n_x + self.n_p)
        #self.P0 = ca.MX.eye(self.n_x + self.n_p)
        
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
        
        self.P0_sqrt_inv = ca.Function("P0_sqrt_inv",
                                        [self.P0_SX],
                                        [ca.sqrt(ca.inv(self.P0_SX))],
                                        ["P0"],
                                        ["P0_sqrt_inv"])
        """        
        #self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        #self.R_square_root = ca.sqrt(ca.inv(self.R))
        
        
        #self.R_square_root = self.R_sqrt_inv(self.R)
        #self.Q_square_root = self.Q_sqrt_inv(self.Q)
        #self.R_square_root = self.R_sqrt_inv(ca.DM.eye(1))
        #self.Q_square_root = self.Q_sqrt_inv(ca.DM.eye(2))
        #self.R_sqrt_inv = ca.MX.sym("R", self.n_y, self.n_y)
        #self.Q_sqrt_inv = ca.MX.sym("Q", self.n_x, self.n_x)
        #self.R = ca.MX.sym("R", self.n_y, self.n_y)
        #self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", ca.Sparsity.diag(self.n_y))
        self.Q = ca.MX.sym("Q", ca.Sparsity.diag(self.n_x))
        
        #self.P0_sqrt_inv = ca.sqrt(ca.inv(P0))
        #self.P0_sqrt_inv = ca.MX.sym("P0", self.n_x + self.n_p, self.n_x + self.n_p)
        self.P0 = ca.MX.sym("P0", ca.Sparsity.diag(self.n_x + self.n_p))
        #self.P0_sqrt_inv = ca.MX.sym("P0", self.n_x + self.n_p, self.n_x + self.n_p)
        # arrival cost:
        #self.P0_sqrt = ca.sqrt(P0)
        
        #P0_sqrt_inv = ca.sqrt(ca.inv(self.P0))
        #R_sqrt_inv = ca.sqrt(ca.inv(self.R))
        #Q_sqrt_inv = ca.sqrt(ca.inv(self.Q))
        #P0_sqrt = ca.sqrt(self.P0)
        #R_sqrt = ca.sqrt(self.R)
        #Q_sqrt = ca.sqrt(self.Q)
        
        nlp_obj = ca.dot(ca.mtimes(self.R,
                                    v),
                            ca.mtimes(v.T,
                                      self.R).T) \
                + \
                ca.dot(ca.mtimes(self.Q,
                                     w),
                            ca.mtimes(w.T,
                                      self.Q).T)
                
        """
        nlp_obj = ca.dot(ca.mtimes(R_sqrt,
                                    v),
                            ca.mtimes(v.T,
                                      R_sqrt).T) \
                + \
                ca.dot(ca.mtimes(Q_sqrt,
                                     w),
                            ca.mtimes(w.T,
                                      Q_sqrt).T) \
        
        """
        if arrival_cost:
            
            last_x = self.nlp_x[0:self.n_x]
            p = self.dae.dae.p
            costate = ca.vertcat(*p, last_x)
            
            # define this as parameter:
            #costate_prior = ca.vertcat(p0, x_N)
            self.costate_prior = ca.MX.sym("costate_prior", self.n_x + self.n_p)

            arrival_cost = ca.dot(
                                ca.mtimes(
                                    self.P0,
                                    #P0_sqrt,
                                    (costate - self.costate_prior)
                            ),
                                ca.mtimes(
                                    (costate - self.costate_prior).T,
                                    self.P0).T
                                    #P0_sqrt).T
                            )
            nlp_obj += arrival_cost
            return nlp_obj, ca.veccat(self.P0, self.Q, self.R, self.costate_prior)    
        # return obj, params of NLP
        #return nlp_obj, ca.veccat(self.Q, self.R)
        
        # return nlp_obj, arrival cost weighting as parameters:
        return nlp_obj, ca.veccat(self.Q, self.R)
                
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
        """
        
    def solve(
              self,
              data,
              param_guess,
              covar=None,
              lbp=None,
              ubp=None,
              P0=None,
              x_N=None,
              arrival_cost=False
              ):
        """
        Set initials for v, w to 0
        """
        self.data = data   
        
        # scale:
        #param_guess /= self.scale
        #lbp /= self.scale
        #ubp /= self.scale
        
        # TODO: should be set by default in __init__        
        self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(
                                                        self.nlp_v,
                                                        self.nlp_w, 
                                                        P0,
                                                        x_N,
                                                        param_guess,
                                                        arrival_cost=arrival_cost
                                                        ) 
        
        y = self.data[self.y_names].values.flatten()
                    
        x_guess = y
        
        #diff = self.integrator.dae.n_x - self.integrator.dae.n_y
        #for n in range(diff):
        #    x_guess = ca.horzcat(x_guess, y)
        
        diff = int(self.integrator.dae.n_x/self.integrator.dae.n_y) - 1
        for n in range(diff):
            x_guess = ca.horzcat(x_guess, y)
        
        
        
        
        self.separate_data(
                          data,
                          lbp=lbp,
                          ubp=ubp,
                          x_guess=x_guess,
                          param_guess=param_guess
                          )
        
        self.set_bounds()
        self._init_solver()
        
        # with p=covar
        """
        solution = self.solver(
                               x0=self.x0,
                               lbg=0, # option for path-constraints?
                               ubg=0, # --"--
                               lbx=self.lbx,
                               ubx=self.ubx,
                               p=covar
                               )
        """
        # with p=P0       
        # NB: _P0 = sqrt(inv(P0))              
        #_P0 = ca.sqrt(ca.inv(P0))
        
        # TODO: branching on arrival cost:
        if arrival_cost:
            p = ca.veccat(P0, covar, ca.vertcat(param_guess, x_N))
        else:
            p = ca.veccat(covar)
        
        
        
        solution = self.solver(
                            x0=self.x0,
                            lbg=0, # option for path-constraints?
                            ubg=0, # --"--
                            lbx=self.lbx,
                            ubx=self.ubx,
                            #p=ca.veccat(_P0, covar, ca.vertcat(param_guess, x_N))
                            p=p
                            )
        
        self.sol_df, params = self.parse_solution(solution)
        
        k = len(self.df)
        self.df.loc[k*self.dt, :] = params.values
        
        return self.sol_df, params
    
