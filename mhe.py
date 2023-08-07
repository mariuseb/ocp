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
import subprocess
import os
import re
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
        self.df = pd.DataFrame(columns=self.dae.p + self.dae.x)
        # covariance matrices:
        #self.R = ca.MX.sym("R", ca.Sparsity.diag(self.n_y))
        #self.Q = ca.MX.sym("Q", ca.Sparsity.diag(self.n_x))
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        #self.R = ca.MX.sym("R", 1, 1)
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        #self.set_hess_obj()
        
    # skip this:
    def set_hess_obj(self):
        """
        For covariance estimation.
        
        (negative log-likelihood) 
        """ 
        
        self.Q_SX = ca.SX.sym("Q", self.n_x, self.n_x)
        self.R_SX = ca.SX.sym("R", self.n_y, self.n_y)
        #self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        #self.R = ca.MX.sym("R", self.n_y, self.n_y)
        #### set up log(det) - Functions:
        Q_SX = self.Q_SX
        R_SX = self.R_SX
        
        """
        self.R_sqrt_inv = ca.Function("R_sqrt_inv",
                                     [self.R_SX],
                                     [ca.sqrt(ca.inv(self.R_SX))],
                                     ["R"],
                                     ["R_sqrt_inv"])
        
        self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
                                     [self.Q_SX],
                                     [ca.sqrt(ca.inv(self.Q_SX))],
                                     ["Q"],
                                     ["Q_sqrt_inv"])
        """ 
        
        #self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        #self.R_square_root = ca.sqrt(ca.inv(self.R))
        
        #self.R_square_root = self.R_sqrt_inv(self.R_SX)
        #self.Q_square_root = self.Q_sqrt_inv(self.Q_SX)
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
        
        """
        x = ca.vec(self.nlp_x)*self.x_nom
        z = ca.vec(self.nlp_z)*self.x_nom
        u = ca.vec(self.nlp_u)*self.u_nom
        p = ca.vertcat(*self.dae.dae.p)*self.p_nom
        w = ca.vec(self.nlp_w)*self.w_nom
        v = ca.vec(self.nlp_v)*self.v_nom
        y = ca.vec(self.nlp_y)*self.y_nom
        r = ca.vec(self.nlp_r)*self.r_nom
        """        
        x = ca.vec(self.nlp_x)
        z = ca.vec(self.nlp_z)
        u = ca.vec(self.nlp_u)
        p = ca.vertcat(*self.dae.dae.p)
        w = ca.vec(self.nlp_w)
        v = ca.vec(self.nlp_v)
        y = ca.vec(self.nlp_y)
        r = ca.vec(self.nlp_r)
        
        R = self.R
        Q = self.Q
        
        
        # residual x:
        res_x = self.nlp_parser.x_gaps
        # residual y:
        res_y = self.nlp_parser.h_gaps
        
        self.x_gaps = ca.Function(
                                  "x_gaps",
                                  [x, z, u, p, w, v, y, r],
                                  [res_x],
                                  ["x", "z", "u", "p", "w", "v", "y", "r"],
                                  ["res_x"]
                                  )
        self.y_gaps = ca.Function(
                                  "y_gaps",
                                  [x, z, u, p, w, v, y, r],
                                  [res_y],
                                  ["x", "z", "u", "p", "w", "v", "y", "r"],
                                  ["res_y"]
                                  )
        
        #self.alt_obj = 0.5*ca.dot(
        self.alt_obj = 0.5*ca.dot(
                             ca.mtimes(self.R,
                                       res_y),
                             ca.mtimes(res_y.T,
                                       self.R).T) \
                            + \
                  0.5*ca.dot(
                            ca.mtimes(self.Q,
                                      res_x),
                            ca.mtimes(res_x.T,
                                      self.Q).T) \
                            #- \
                            #((self.N-1)/2)*self.log_det_Q(self.Q) \
                            #- \
                            #(self.N/2)*self.log_det_R(self.R)
        
        #self.res_obj = ca.Function("objective", [res_y, res_x, R, Q], [self.alt_obj],
        #                           ["res_y", "res_x", "R", "Q"], ["residual"])     
        # [x, z, u, p, w, v, y, r],     
        self.res_obj = ca.Function("objective",
                                   [x, z, u, p, w, v, y, r, ca.vec(R), ca.vec(Q)],
                                   [self.alt_obj],
                                   ["x", "z", "u", "p", "w", "v", "y", "r", "R", "Q"],
                                   ["residual"])
          
        hess_expr, jac_expr =  ca.hessian(self.alt_obj,
                                ca.vertcat(p,
                                           x,
                                           u,
                                           y,
                                           w,
                                           v,
                                           r,
                                           ca.vec(R),
                                           ca.vec(Q)
                                           )
                                )       
        """
        jac_expr =  ca.jacobian(self.alt_obj,
                                ca.vertcat(p,
                                           x,
                                           u,
                                           y,
                                           r,
                                           ca.vec(R),
                                           ca.vec(Q)
                                           )
                                )             
        """    
        self.hess_obj = ca.Function(
                                    "hess_obj",
                                     [p,
                                      x,
                                      u,
                                      w,
                                      v,
                                      y,
                                      r,
                                      ca.vec(R),
                                      ca.vec(Q)
                                      ],
                                    [hess_expr],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["p", "x", "u", "w", "v", "y", "r", "R", "Q"],
                                    ["hess_obj"]
                                    )           
        self.jac_obj = ca.Function(
                                    "jac_obj",
                                     [p,
                                      x,
                                      u,
                                      y,
                                      r,
                                      ca.vec(R),
                                      ca.vec(Q)
                                      ],
                                    [jac_expr.T],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["p", "x", "u", "y", "r", "R", "Q"],
                                    ["jac_obj"]
                                    )    
        
        #res_x = ca.MX.sym("res_x", res_x.shape[0], res_x.shape[1])
        #res_y = ca.MX.sym("res_x", res_y.shape[0], res_y.shape[1])
        """
        alt_obj = 0.5*ca.dot(
                             ca.mtimes(self.R,
                                       res_y),
                             ca.mtimes(res_y.T,
                                       self.R).T) \
                            + \
                  0.5*ca.dot(
                            ca.mtimes(self.Q,
                                      res_x),
                            ca.mtimes(res_x.T,
                                      self.Q).T) \
                            #- \
                            #((self.N-1)/2)*self.log_det_Q(self.Q) \
                            #- \
                            #(self.N/2)*self.log_det_R(self.R)
        """
        
       
    def eval_res_obj(self, sol_df, params, R, Q):
        """
        Evaluate residual.
        """
        x_vals =  self.sol_df[self.dae.x].values.flatten()/self.x_nom
        u_vals =  self.sol_df[self.dae.u].values.flatten()/self.u_nom
        y_vals =  self.sol_df[self.dae.y].values.flatten()/self.y_nom
        r_vals =  self.sol_df[self.dae.r_names].values.flatten()/self.r_nom
        
        obj_value = self.res_obj(
                                x_vals,
                                0,
                                u_vals,
                                params,
                                0,
                                0,
                                y_vals,
                                r_vals,
                                ca.vec(R),
                                ca.vec(Q)
                                  )
        # x_residual:
        """
        res_x = self.x_gaps(
                            x_vals,
                            0,
                            u_vals,
                            params,
                            0,
                            0,
                            y_vals,
                            r_vals,
                            ca.vec(R),
                            ca.vec(Q)
                            )
        res_y = self.y_gaps(
                            x_vals,
                            0,
                            u_vals,
                            params,
                            0,
                            0,
                            y_vals,
                            r_vals,
                            ca.vec(R),
                            ca.vec(Q)
                            )

        obj_value = self.res_obj(res_y, res_x, R, Q)
        """
        
        return obj_value
                
    def get_fisher(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """

        x_vals =  self.sol_df[self.dae.x].values.flatten()/self.x_nom
        u_vals =  self.sol_df[self.dae.u].values.flatten()/self.u_nom
        y_vals =  self.sol_df[self.dae.y].values.flatten()/self.y_nom
        r_vals =  self.sol_df[self.dae.r_names].values.flatten()/self.r_nom
        w_vals =  self.sol_df[self.dae.w_names].values.flatten()/self.w_nom
        v_vals =  self.sol_df[self.dae.v_names].values.flatten()/self.v_nom
        """
        x_vals =  self.sol_df[self.dae.x].values.flatten()
        u_vals =  self.sol_df[self.dae.u].values.flatten()
        y_vals =  self.sol_df[self.dae.y].values.flatten()
        r_vals =  self.sol_df[self.dae.r_names].values.flatten()
        w_vals =  self.sol_df[self.dae.w_names].values.flatten()
        v_vals =  self.sol_df[self.dae.v_names].values.flatten()
        """
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 #params.values*self.scale,
                                 params.values,
                                 x_vals,
                                 u_vals,
                                 w_vals,
                                 v_vals,
                                 y_vals,
                                 r_vals,
                                 ca.vec(R),
                                 ca.vec(Q)
                                 )
        
        param_dim = self.nlp_parser["p"]["dim"]
        
        fisher_p = hess_val[:param_dim,:param_dim]
        
        x_start, x_stop = self.nlp_parser["x"]["range"]["a"] + self.nlp_parser["p"]["dim"], \
                    self.nlp_parser["x"]["range"]["b"] + self.nlp_parser["p"]["dim"]
            
        fisher_x = hess_val[(x_stop-self.n_x):x_stop,(x_stop-self.n_x):x_stop]
        
        fisher = np.vstack([fisher_p, np.zeros((1, self.n_p)) ] )
        fisher = np.column_stack([fisher, np.zeros((self.n_p + self.n_x, 1))] )
        #fisher[self.n_p:(self.n_p + self.n_x),
        #       self.n_p:(self.n_p + self.n_x)] = fisher_x
        fisher[self.n_p:(self.n_p + self.n_x),
               self.n_p:(self.n_p + self.n_x)] = 1
        
        return np.diag(np.diag(fisher))
                    
        
        
        
       
    def get_covar_p(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """
        x_vals =  self.sol_df[self.dae.x].values.flatten()/self.x_nom
        u_vals =  self.sol_df[self.dae.u].values.flatten()/self.u_nom
        y_vals =  self.sol_df[self.dae.y].values.flatten()/self.y_nom
        r_vals =  self.sol_df[self.dae.r_names].values.flatten()/self.r_nom
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 u_vals,
                                 y_vals,
                                 r_vals,
                                 ca.vec(R),
                                 ca.vec(Q)
                                 )
        jac_val = self.jac_obj(
                                params,
                                x_vals,
                                u_vals,
                                y_vals,
                                r_vals,
                                ca.vec(R),
                                ca.vec(Q)
                                ).T
        
        param_dim = self.nlp_parser["p"]["dim"]
        
        fisher_p = hess_val[:param_dim,:param_dim]
        jac_p = jac_val[:param_dim]
        
        x_start, x_stop = self.nlp_parser["x"]["range"]["a"] + self.nlp_parser["p"]["dim"], \
                    self.nlp_parser["x"]["range"]["b"] + self.nlp_parser["p"]["dim"]
                    
        jac_x = jac_val[x_start:x_stop]
        """
        return pd.DataFrame(data=np.array(ca.inv(fisher)),
                            index=self.dae.p,
                            columns=self.dae.p), \
                pd.DataFrame(data=np.array(fisher),
                            index=self.dae.p,
                            columns=self.dae.p)
        """        
        return pd.DataFrame(data=np.array(jac_p),
                            index=self.dae.p,
                            columns=["val"]), \
                pd.DataFrame(data=np.array(fisher_p),
                            index=self.dae.p,
                            columns=self.dae.p), \
                pd.DataFrame(data=np.array(jac_x)[:self.dae.n_x],
                            columns=["val"])
                
                
    def get_covar_x(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """
        x_vals =  self.sol_df[self.dae.x].values.flatten()/self.x_nom
        u_vals =  self.sol_df[self.dae.u].values.flatten()/self.u_nom
        y_vals =  self.sol_df[self.dae.y].values.flatten()/self.y_nom
        r_vals =  self.sol_df[self.dae.r_names].values.flatten()/self.r_nom
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 u_vals,
                                 y_vals,
                                 r_vals,
                                 ca.vec(R),
                                 ca.vec(Q)
                                 )
        
        x_start, x_stop = self.nlp_parser["x"]["range"]["a"] + self.nlp_parser["p"]["dim"], \
                            self.nlp_parser["x"]["range"]["b"] + self.nlp_parser["p"]["dim"]
        
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
        #self.R = ca.MX.sym("R", ca.Sparsity.diag(self.n_y))
        #self.Q = ca.MX.sym("Q", ca.Sparsity.diag(self.n_x))
        
        #self.P0_sqrt_inv = ca.sqrt(ca.inv(P0))
        #self.P0_sqrt_inv = ca.MX.sym("P0", self.n_x + self.n_p, self.n_x + self.n_p)
        #dim_P0 = self.n_x + self.n_p
        #self.P0 = ca.MX.sym("P0", dim_P0, dim_P0)
        self.P0 = ca.MX.sym("P0", ca.Sparsity.diag(self.n_x + self.n_p))
        #self.P0_sqrt_inv = ca.MX.sym("P0", self.n_x + self.n_p, self.n_x + self.n_p)
        # arrival cost:
        #self.P0_sqrt = ca.sqrt(P0)
        
        #P0_sqrt_inv = ca.sqrt(ca.inv(self.P0))
        #R_sqrt_inv = ca.sqrt(ca.inv(self.R))
        #Q_sqrt_inv = ca.sqrt(ca.inv(self.Q))
        #R_sqrt_inv = ca.sqrt(ca.inv(self.R))
        #Q_sqrt_inv = ca.sqrt(ca.inv(self.Q))
        #P0_sqrt = ca.sqrt(self.P0)
        #R_sqrt = ca.sqrt(self.R)
        #Q_sqrt = ca.sqrt(self.Q)
        
        #v = v/self.v_nom
        #w = w/self.w_nom
        
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
        nlp_obj = ca.dot(ca.mtimes(w, w.T), self.Q) + \
                  ca.dot(ca.mtimes(v, v.T), self.R)
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
            
            #last_x = self.nlp_x[0:self.n_x]*self.x_nom
            #p = ca.vertcat(*self.dae.dae.p)*self.p_nom
            last_x = self.nlp_x[0:self.n_x]
            p = ca.vertcat(*self.dae.dae.p)
            costate = ca.vertcat(p, last_x)
            
            # define this as parameter:
            #costate_prior = ca.vertcat(p0, x_N)
            self.costate_prior = ca.MX.sym("costate_prior", self.n_x + self.n_p)


            # TODO: take steps directly on P0, not sqrt(P0)    
            """
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
            """
            arrival_cost = (costate - self.costate_prior).T@self.P0@(costate - self.costate_prior)
            #arrival_cost = (self.P0@(costate - self.costate_prior).T)@(self.P0@(costate - self.costate_prior))
            #arrival_cost = ((self.P0@(costate - self.costate_prior)).T)@(self.P0@(costate - self.costate_prior))
            #P0 = (ca.MX.eye(self.n_x + self.n_p) - ca.expm(-self.P0))
            #P0 = ca.expm(self.P0)
            #arrival_cost = ((self.P0@(costate - self.costate_prior)).T)@(self.P0@(costate - self.costate_prior))
            #arrival_cost = ((P0@(costate - self.costate_prior)).T)@(P0@(costate - self.costate_prior))
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
        
    def get_nlp_obj(self, w, v, P0, x_N, p0, arrival_cost=False):
        """
        TODO: make sure this is not called every iteration.
        
        Modified.
        """
        
        # covariance matrices:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        
        self.P0 = ca.MX.sym("P0", ca.Sparsity.diag(self.n_x + self.n_p))
        self.costate_prior = ca.MX.sym("costate_prior", self.n_x + self.n_p)
        
        y_inds = self.nlp_parser["y"]["range"]
        x_inds = self.nlp_parser["x"]["range"]
        v_inds = self.nlp_parser["v"]["range"]
        s_inds = self.nlp_parser["s"]["range"]
        
        #x1 = self.nlp["x"][x_inds["a"]:x_inds["b"]:self.dae.n_x]
        #y_Ti = self.nlp["x"][y_inds["a"]:y_inds["b"]:self.dae.n_y]
        v1 = self.nlp["x"][v_inds["a"]:v_inds["b"]:self.dae.n_y]
        v2 = self.nlp["x"][(v_inds["a"]+1):v_inds["b"]:self.dae.n_y]
        #v2 = self.nlp["x"][(v_inds["a"]+1):v_inds["b"]:self.dae.n_y]
        #w1 = self.nlp["x"][s_inds["a"]:s_inds["b"]:self.dae.n_x]
        #w2 = self.nlp["x"][(s_inds["a"]+1):s_inds["b"]:self.dae.n_x]
        
        eta = self.dae.dae.var("eta")
        v2 /= eta
        #nlp_obj = 0.5*ca.dot(v1, v1) + 1E-6*ca.dot(v2, v2)
        #nlp_obj = 0.5*ca.dot(v1, v1)
        nlp_obj = ca.mtimes(ca.dot(v1, v1), self.R[0,0]) + \
                  ca.mtimes(ca.dot(v2, v2), self.R[1,1])
        #          ca.mtimes(ca.dot(w1, w1), self.Q[0,0]) + \
        #          ca.mtimes(ca.dot(w2, w2), self.Q[1,1])        
                  
        if arrival_cost:
            
            #last_x = self.nlp_x[0:self.n_x]*self.x_nom
            #p = ca.vertcat(*self.dae.dae.p)*self.p_nom
            last_x = self.nlp_x[0:self.n_x]
            #p = ca.vertcat(*self.dae.F.p)
            p = self.strategy.F.p
            costate = ca.vertcat(p, last_x)
            
            # define this as parameter:
            #costate_prior = ca.vertcat(p0, x_N)
            #self.costate_prior = ca.MX.sym("costate_prior", self.n_x + self.n_p)


            # TODO: take steps directly on P0, not sqrt(P0)    
            """
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
            """
            arrival_cost = (costate - self.costate_prior).T@self.P0@(costate - self.costate_prior)
            #arrival_cost = (self.P0@(costate - self.costate_prior).T)@(self.P0@(costate - self.costate_prior))
            #arrival_cost = ((self.P0@(costate - self.costate_prior)).T)@(self.P0@(costate - self.costate_prior))
            #P0 = (ca.MX.eye(self.n_x + self.n_p) - ca.expm(-self.P0))
            #P0 = ca.expm(self.P0)
            #arrival_cost = ((self.P0@(costate - self.costate_prior)).T)@(self.P0@(costate - self.costate_prior))
            #arrival_cost = ((P0@(costate - self.costate_prior)).T)@(P0@(costate - self.costate_prior))
            nlp_obj += arrival_cost
            
            return nlp_obj, ca.veccat(self.P0, self.Q, self.R, self.costate_prior)    
        
        #self.res = y_Ti - x1
        #return 0.5*ca.dot(v1, v1) + 0.01*ca.dot(v2, v2), 0
        #return nlp_obj, ca.veccat(self.P0, self.Q, self.R, self.costate_prior)
        return nlp_obj, ca.veccat(self.Q, self.R)
    
    
    def set_nlp_obj(self, arrival_cost=False):
        """
        Parse MHE objective as passed in from config file.
        
        Modularize this method as we go. 
        """
        
        # initialize the parameters needed for the objective:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        self.P0 = ca.MX.sym("P0", ca.Sparsity.diag(self.n_x + self.n_p))
        self.costate_prior = ca.MX.sym("costate_prior", self.n_x + self.n_p)
        
        symbols = set(re.findall("|".join(self.dae.all_names), self.obj_string))
        vals = dict()
        for symbol in symbols:
            vals[symbol] = self.get(symbol)
        obj_string = self.obj_string.replace("dot", "ca.dot")
        vals["ca"] = ca
        vals["R"] = self.R
        vals["Q"] = self.Q
    
        exec(f'obj_expr =' + obj_string, vals)
        
        self.nlp["f"] = vals["obj_expr"]
        self.nlp["p"] = ca.veccat(self.R, self.Q)
        
        # TODO: reshuffle ordering of MHE parameters ...
        if arrival_cost:
            last_x = self.nlp_x[0:self.n_x]
            p = self.strategy.F.p
            costate = ca.vertcat(p, last_x)
            arrival_cost = (costate - self.costate_prior).T@self.P0@(costate - self.costate_prior)
            self.nlp["f"] += arrival_cost
            self.nlp["p"] = ca.veccat(self.P0, self.Q, self.R, self.costate_prior)    
        else:
            self.nlp["p"] = ca.veccat(self.Q, self.R)    
   
    """
    def __del__(self):
        for file in self.c_files:
            print("Deleting %s..." % file)
            os.remove(file)
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
              arrival_cost=False,
              return_raw_sol=False,
              codegen=False
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
        """
        self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(
                                                        self.nlp_v,
                                                        self.nlp_w, 
                                                        P0,
                                                        x_N,
                                                        param_guess,
                                                        arrival_cost=arrival_cost
                                                        ) 
        self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(
                                                        0,
                                                        0, 
                                                        P0,
                                                        x_N,
                                                        param_guess,
                                                        arrival_cost=arrival_cost
                                                        ) 
        """

        if "f" not in self.nlp:
            """
            self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(
                                                            0,
                                                            0,
                                                            P0,
                                                            x_N,
                                                            param_guess,
                                                            arrival_cost=arrival_cost
                                                            ) 
            """
            self.set_nlp_obj(arrival_cost=arrival_cost)
        ##################################################
        
        """
        y_x_overlap = [name for name in self.y_names if self.dae.y[name].name() in self.dae.x]
        y = self.data[y_x_overlap].values.flatten()
        
        # Assume order of y and x correspond
        # TODO: fix for arbitrary order:
        # TODO: do only once:
        if isinstance(self.y_nom, list):
            # get offset from 
            stop = len(y_x_overlap)
            y_nom = self.y_nom[0:stop]
            y_nom_b = self.y_nom_b[0:stop]
            
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
        """
              
        x_guess = self.generate_x_guess()
        self.separate_data(
                          data,
                          lbp=lbp,
                          ubp=ubp,
                          #lbx=0.5*x_guess,
                          #ubx=1.5*x_guess,
                          x_guess=x_guess,
                          param_guess=param_guess
                          )
        
        self.set_bounds()
        #self._init_solver()
        if arrival_cost:        
            p0 = param_guess/self.p_nom
            x_N = (x_N - self.x_nom_b)/self.x_nom
            #p0 = param_guess
            #x_N = x_N
            costate_prior = ca.vertcat(p0, x_N)
            p = ca.veccat(P0, covar, costate_prior)       
        else:
            p = ca.veccat(covar)
        self.p_val = p # store
        
        if not hasattr(self, "solver"):      
            self._init_solver()
        # with p=covar
        
        # TODO: branching on arrival cost:
        
        gen_code_filename = self.get_c_code_name()
        if codegen and not os.path.exists(gen_code_filename):
            self.pregenerate_c_code(gen_code_filename)
                
        solution = self.solver(
                            x0=self.x0,
                            lbg=0, # option for path-constraints?
                            ubg=0, # --"--
                            lbx=self.lbx,
                            ubx=self.ubx,
                            #p=ca.veccat(_P0, covar, ca.vertcat(param_guess, x_N))
                            p=p
                            #p=0
                            )
        
        self.sol_df, params = self.parse_solution(solution)
        
        k = len(self.df) + self.N - 1
        self.df.loc[k*self.dt, :] = np.append(params.values, self.sol_df[self.x_names].iloc[-1])
                
        if not return_raw_sol:
            return self.sol_df, params
        else:
            return self.sol_df, params, solution
    
