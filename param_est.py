import casadi as ca
import pandas as pd
import numpy as np
#pd.set_option("display.precision", 8)
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
from ocp.filters import EKF, KalmanBucy
import re

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
        #self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(self.nlp_v,
        #                                                self.nlp_s) 
        if "f" not in self.nlp: #and isinstance(self.obj_string, str):
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
            self.set_nlp_obj(arrival_cost=False)
    
        #self.set_bounds(y=self.Y,
        #                u=self.U)
        #self.separate_data(data)
        #self.set_bounds()
        #self._init_solver()
        #self.set_hess_obj()
        
    def get_nlp_obj(self, v, w):
        """ 
        Objective for sysid.
        """          
        # define Q, R here:
        """
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
        """     
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
        
        #self.nlp["x"] = ca.vertcat(self.nlp["x"], ca.veccat(self.Q, self.R))
        """
        return 0.5*ca.dot(ca.mtimes(ca.sqrt(ca.inv(self.R)),
                                    v),
                            ca.mtimes(v.T,
                                      ca.sqrt(ca.inv(self.R))).T) \
                + \
                0.5*ca.dot(ca.mtimes(ca.sqrt(ca.inv(self.Q)),
                                     w),
                            ca.mtimes(w.T,
                                      ca.sqrt(ca.inv(self.Q))).T), \
                ca.veccat(self.Q, self.R)
        """        
        return 0.5*ca.dot(ca.mtimes(self.R, v), ca.mtimes(v.T, self.R).T) + \
            0.5*ca.dot(ca.mtimes(self.Q, w), ca.mtimes(w.T, self.Q).T), \
          ca.veccat(self.Q, self.R)
                
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
        self.nlp["p"] = ca.veccat(self.Q, self.R)
        
        """
        if arrival_cost:
            last_x = self.nlp_x[0:self.n_x]
            p = self.strategy.F.p
            costate = ca.vertcat(p, last_x)
            arrival_cost = (costate - self.costate_prior).T@self.P0@(costate - self.costate_prior)
            self.nlp["f"] += arrival_cost
            self.nlp["p"] = ca.veccat(self.P0, self.Q, self.R, self.costate_prior)    
        else:
        """
        #self.nlp["p"] = ca.veccat(self.Q, self.R)    
    
    
    def get_nlp_obj(self, w, v):
        y_inds = self.nlp_parser["y"]["range"]
        x_inds = self.nlp_parser["x"]["range"]
        v_inds = self.nlp_parser["v"]["range"]
        #z_inds = self.nlp_parser["z"]["range"]
        
        #x1 = self.nlp_parser["x"]["boundary_vars"][x_inds["a"]:x_inds["b"]:self.dae.n_x]
        #x1 = self.nlp["x"][x_inds["a"]:x_inds["b"]:self.dae.n_x]
        #x1 = self.nlp_parser["x"]["boundary_vars"][0:-1:self.dae.n_x]
        #y_Ti = self.nlp["x"][y_inds["a"]:y_inds["b"]:self.dae.n_y]
        v1 = self.nlp["x"][v_inds["a"]:v_inds["b"]:self.dae.n_y]
        v2 = self.nlp["x"][(v_inds["a"]+1):v_inds["b"]:self.dae.n_y]
        # what to do with this? 
        #eta = self.dae.dae.var("eta")
        #v1 = v1/eta
        
        """
        diff = v_inds["b"] - v_inds["a"]
        v1_start = v_inds["a"]
        v1_stop = v1_start + int(diff/2)
        v2_start = v1_stop
        v2_stop = v_inds["b"]
        
        v1 = self.nlp["x"][v1_start:v1_stop]
        v2 = self.nlp["x"][v2_start:v2_stop]
        """
        
        #v1 = self.nlp["x"][v_inds["a"]:(v_inds["a"] + int((v_inds["b"]/2)))]
        #v2 = self.nlp["x"][int((v_inds["a"]/2)):v_inds["b"]]
        
        # CORRECT for v single:
        
        #v = self.nlp["x"][v_inds["a"]:v_inds["b"]]
        
        
        
        #z1 = self.nlp["x"][z_inds["a"]:z_inds["b"]]
        #y_Ph = self.nlp["x"][y_inds["a"]+1:y_inds["b"]:self.dae.n_y]
        
        # For Gauss-Newton:
        #self.res = y_Ti - x1
        
        
        #res_Ph = y_Ph - z1
        
        #return 0.5*ca.dot(v1, v1) + 0.5*ca.dot(v2, v2), 0 #+ 0.5*ca.dot(v2, v2), 0 # + 0.5*ca.dot(res_Ph, res_Ph), 0
        #return 0.5*ca.dot(v, v), 0
        #return 0.5*ca.dot(v1, v1) + 0.5*ca.dot(v2, v2), 0
        #return 0.5*ca.dot(v2, v2), 0
        #return 0.5*ca.dot(v1, v1) + 0.01*ca.dot(v2, v2), 0
        return 0.5*ca.dot(v1, v1), 0
        #return 0.5*ca.dot(v1, v1) + 0.001*ca.dot(v2, v2), 0
    
    """
    def get_nlp_obj(self, w, v):
        y_inds = self.nlp_parser["y"]["range"]
        x_inds = self.nlp_parser["x"]["range"]
        z_inds = self.nlp_parser["z"]["range"]
        
        x1 = self.nlp["x"][x_inds["a"]:x_inds["b"]:self.dae.n_x]
        y_Ti = self.nlp["x"][y_inds["a"]:y_inds["b"]:self.dae.n_y]
        z1 = self.nlp["x"][z_inds["a"]:z_inds["b"]]
        y_Ph = self.nlp["x"][y_inds["a"]+1:y_inds["b"]:self.dae.n_y]
        
        res_Ti = y_Ti - x1
        res_Ph = y_Ph - z1
        
        return 0.5*ca.dot(res_Ti, res_Ti) + 0.5*ca.dot(res_Ph, res_Ph), 0
    
    def get_nlp_obj(self, w, v):
        y_inds = self.nlp_parser["y"]["range"]
        x_inds = self.nlp_parser["x"]["range"]
        r_inds = self.nlp_parser["r"]["range"]
        u_inds = self.nlp_parser["u"]["range"]
        
        x1 = self.nlp["x"][x_inds["a"]:x_inds["b"]:self.dae.n_x]
        y = self.nlp["x"][y_inds["a"]:y_inds["b"]]
        
        r1 = self.nlp["x"][r_inds["a"]:r_inds["b"]:self.dae.n_r]
        u = self.nlp["x"][u_inds["a"]:u_inds["b"]]
        
        res_y = y-x1
        res_u = u-r1
        
        return 0.5*ca.dot(res_y, res_y) + 5*ca.dot(res_u, res_u), 0
    """
             
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
            
        
        #self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        #self.R_square_root = ca.sqrt(ca.inv(self.R))
        
        self.R_square_root = self.R_sqrt_inv(self.R)
        self.Q_square_root = self.Q_sqrt_inv(self.Q)
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
        #p = ca.vertcat(*self.dae.dae.p)
        p = self.integrator.p
        w = ca.vec(self.nlp_s)
        v = ca.vec(self.nlp_v)
        #w = ca.vec(self.get("s"))
        #v = ca.vec(self.get("v"))
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
                                   [p,
                                    x,
                                    u,
                                    y,
                                    w,
                                    v,
                                    ca.vec(R),
                                    ca.vec(Q)
                                    ],
                                    [res_x],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["p", "x", "u", "y", "w", "v", "R", "Q"],
                                    ["hess_obj"]
                                  )
        self.y_gaps = ca.Function(
                                  "y_gaps",
                                   [p,
                                    x,
                                    u,
                                    y,
                                    w,
                                    v,
                                    ca.vec(R),
                                    ca.vec(Q)
                                    ],
                                    [res_y],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["p", "x", "u", "y", "w", "v", "R", "Q"],
                                    ["hess_obj"]
                                  )
        
        #self.alt_obj = 0.5*ca.dot(
        """
        self.alt_obj = 0.5*ca.dot(
                             ca.mtimes(self.R_square_root,
                                       res_y),
                             ca.mtimes((res_y).T,
                                       self.R_square_root).T) \
                            + \
                  0.5*ca.dot(
                            ca.mtimes(self.Q_square_root,
                                      res_x),
                            ca.mtimes(res_x.T,
                                      self.Q_square_root).T)
        """
        dim_x = self.dae.n_x
        dim_x_nlp = self.nlp_parser["x"]["dim"]
        s1 = res_x[0:(dim_x_nlp-dim_x):dim_x]
        s2 = res_x[1:(dim_x_nlp-dim_x):dim_x]
        self.alt_obj = 0.5*ca.dot(res_y, res_y)@self.R[0,0] + \
                       0.5*ca.dot(s1, s1)@self.Q[0,0] + \
                       0.5*ca.dot(s2, s2)@self.Q[1,1]
        """
        + \
        ((self.N-1)/2)*self.log_det_Q(self.Q) \
        + \
        (self.N/2)*self.log_det_R(self.R)
        """
    
        self.alt_obj_func = ca.Function("alt_obj",
                                            [p,
                                             x,
                                             u,
                                             y,
                                             w,
                                             v,
                                             ca.vec(R),
                                             ca.vec(Q)
                                             ],
                                            [self.alt_obj],
                                            #self.dae.p + ["x", "u", "y", "R", "Q"],
                                            ["p", "x", "u", "y", "w", "v", "R", "Q"],
                                            ["hess_obj"]
                                        )           
        self.obj_func = ca.Function("alt_obj",
                                            [p,
                                             x,
                                             u,
                                             y,
                                             w,
                                             v,
                                             ca.vec(R),
                                             ca.vec(Q)
                                             ],
                                            [self.nlp["f"]],
                                            #self.dae.p + ["x", "u", "y", "R", "Q"],
                                            ["p", "x", "u", "y", "w", "v", "R", "Q"],
                                            ["hess_obj"]
                                        )           
        
        """
        hess_expr =  ca.hessian(self.nlp["f"],
                                ca.vertcat(p,
                                           x,
                                           u,
                                           y,
                                           w,
                                           v,
                                           ca.vec(R),
                                           ca.vec(Q)
                                           )
                                )[0]             
        """
        hess_expr =  ca.hessian(self.alt_obj,
                                ca.vertcat(p,
                                           x,
                                           u,
                                           y,
                                           w,
                                           v,
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
                                      w,
                                      v,
                                      ca.vec(R),
                                      ca.vec(Q)
                                      ],
                                    [hess_expr],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["p", "x", "u", "y", "w", "v", "R", "Q"],
                                    ["hess_obj"]
                                    )           
       
                
    
    def get_covar_p(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """
        x_vals = self.sol_df[self.dae.x].values.flatten()
        u_vals = self.sol_df[self.dae.u].values.flatten()
        y_vals = self.sol_df[list(self.dae.y.keys())].values.flatten()
        s_vals = self.sol_df[self.dae.s_names].values.flatten()
        v_vals = self.sol_df[self.dae.v_names].values.flatten()
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 u_vals,
                                 y_vals,
                                 s_vals,
                                 v_vals,
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
                
    def get_covar_p(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """
        x_vals = self.scaled_sol_df[self.dae.x].values.flatten()
        u_vals = self.scaled_sol_df[self.dae.u].values.flatten()
        y_vals = self.scaled_sol_df[list(self.dae.y.keys())].values.flatten()
        s_vals = self.scaled_sol_df[self.dae.s_names].values.flatten()
        v_vals = self.scaled_sol_df[self.dae.v_names].values.flatten()
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 u_vals,
                                 y_vals,
                                 s_vals,
                                 v_vals,
                                 ca.vec(R),
                                 ca.vec(Q)
                                 )
        
        hess_val = np.array(hess_val)
        
        # array of scalings: (only linear, not affine)
        """
        scale_array = np.hstack([self.scale, 
                                    np.repeat(self.x_nom, self.nlp_parser["x"]["dim"]),
                                    np.repeat(self.u_nom, self.nlp_parser["u"]["dim"]),
                                    np.repeat(self.y_nom, self.nlp_parser["y"]["dim"]),
                                    np.repeat(self.s_nom, self.nlp_parser["s"]["dim"]),
                                    np.repeat(self.v_nom, self.nlp_parser["v"]["dim"]),
                                    np.repeat(1, R.shape[0]*R.shape[1]),
                                    np.repeat(1, Q.shape[0]*Q.shape[1])]
                                )
        """
        # construct T, the transformation matrix: 
        #T = np.linalg.inv(np.diag(scale_array) )
        #hess_val_scaled = T.T@hess_val@T
        param_dim = self.nlp_parser["p"]["dim"]
        fisher = hess_val[:param_dim,:param_dim]
        #fisher_scaled = hess_val_scaled[:param_dim,:param_dim]
        
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
    
    def add_path_constraints(
                            self,
                            x0=None,
                            lbx=None,
                            ubx=None
                            ):
        
        x_info = self.nlp_parser["x"]
        x = self.nlp["x"][x_info["range"]["a"]:x_info["range"]["b"]]
        
        #lbx = np.append(x0, lbx)
        #ubx = np.append(x0, ubx)
        
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
        
        # assumes all previous constraints are of equality nature.
        # TODO: fix.
        
        lbg = np.array([0]*self.nlp_parser.g.shape[0])
        ubg = np.array([0]*self.nlp_parser.g.shape[0])
        
        self.lbg = np.append(lbg, lbx)
        self.ubg = np.append(ubg, ubx)
        
        #self.nlp["g"] = ca.vertcat(self.nlp["orig_g"], path_constr)
        self.nlp["g"] = ca.vertcat(self.nlp_parser.g, path_constr)
        
      
    def one_step_residual(self, cfg, x0, params, y_data, R=None, Q=None):
        """
        Evolve one-step ahead predictions with EKF,
        return the residual.
        """
        # alternative constructor that takes ocp dae?
        ekf = KalmanBucy(cfg)
        ekf.set_params(params)
        ekf.set_Q(Q)
        ekf.set_R(R)
        
        
        # set R, Q? P0?
        N = len(y_data)
        
        result = pd.DataFrame(
                              index=range(N-1),
                              columns=["res", "y_pred"]
                              )
        
        F = self.integrator.one_sample
        
        for n in range(N-1):
            
            # noiseless model prediction:
            x_pred = F(x0,
                       0,
                       y_data[self.dae.u].iloc[n].values,
                       params,
                       np.array([0, 0]),
                       0)
            
            # filtering of prediction:s
            x0 = ekf.estimate(
                              x_pred,
                              y=y_data[ekf.dae.y_names].iloc[n+1].values,
                              u=y_data[ekf.dae.u].iloc[n].values,
                              r=y_data[ekf.dae.r_names].iloc[n].values
                              )
            #result.loc[n, "res"] = float(y_data[ekf.dae.y_names].iloc[n+1] - x_pred[0])
            result.loc[n, "res"] = (y_data[ekf.dae.y_names].iloc[n+1].values - np.array(x_pred[0,0]))[0][0]
            result.loc[n, "y_pred"] = np.array(x_pred[0, 0])[0][0]
            
        return result
                
        
                            
    def solve(
              self,
              data,
              param_guess,
              covar=None,
              lbp=None,
              ubp=None,
              lbx=None,
              ubx=None,
              Ti_gt_Te=False,
              Th_gt_Ti=False,
              Ci_gt_Ch=False,
              Ce_gt_Ch=False,
              x_guess=None,
              return_raw_sol=False
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
            
        #self.nlp["f"], self.nlp["p"] = self.get_nlp_obj(self.nlp_v,
        #                                        self.nlp_w) 
        
        #self.set_hess_obj()
        
        #self.nlp["f"] = self.alt_obj
        
        # set Q, R on nlp x
        #self.nlp["x"] = ca.vertcat(
        #                          self.nlp["x"],
        #                          ca.veccat(ca.vec(self.Q), 
        #                                    self.R)
        #                          )
        
        #self.x0 = np.append(self.x0, covar)
        
        # generate x guess: two methods: repeat or freq-based
        # -> own method
        #y_info = self.bounds["y"]["lb"]
        #y = self.bounds["y"]["lb"]
        
        ####################### method ###########################
        
        #y = self.data[self.y_names].values.flatten()
        
        # check overlap:
        """
        try:
            y_x_overlap = [name for name in self.y_names if self.dae.y[name].name() in self.dae.x]
            y = self.data[y_x_overlap].values.flatten()
            x_guess = y
            
            # TODO: handle edge-cases, e.g. n_y = 2 and n_x = 3
            #diff = self.integrator.dae.n_x - self.integrator.dae.n_y
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
                    x_guess = ca.horzcat(x_guess, y)
        except ZeroDivisionError:
            x_guess = None
        """
        # TODO: fix extending x_guess for the case of collocation
        if x_guess is None:        
            x_guess = self.generate_x_guess()
        
        ##########################################################
        
        self.separate_data(
                          data,
                          lbp=lbp,
                          ubp=ubp,
                          lbx=lbx,
                          ubx=ubx,
                          x_guess=x_guess,
                          param_guess=param_guess
                          )
        
        self.set_bounds()
        #self.set_hess_obj()
        #self.nlp["f"] = self.alt_obj
        
        """
        For parameter estimation problems,
        we require all u and r to be given.
        """
        
        in_data = set(data.columns[data.columns.isin(self.u_names)])
        diff = list(set(self.u_names).difference(in_data))
        if diff != list():
            raise ValueError("Missing entries for: {}".format(diff))
                
        if lbx is not None and ubx is not None:
            # TODO: modularize 'add_path_constraints', 
            # all subclasses are using it.
            self.add_path_constraints(
                                      lbx=(lbx - self.x_nom_b)/self.x_nom,
                                      ubx=(ubx - self.x_nom_b)/self.x_nom
                                      )
        else:
            self.lbg = np.array([0]*self.nlp_parser.g.shape[0])
            self.ubg = np.array([0]*self.nlp_parser.g.shape[0])
        
        if Ti_gt_Te:
            """
            Follows a generalizable pattern: 
                x_n > x_m 
            """
            Ti = self.get("Ti")
            Te = self.get("Te")
            constr = Ti - Te
            self.nlp["g"] = ca.vertcat(self.nlp["g"], constr)
            self.lbg = np.concatenate([self.lbg,
                                       np.array([0]*constr.shape[0])])
            self.ubg = np.concatenate([self.ubg,
                                       np.array([np.inf]*constr.shape[0])])
        if Th_gt_Ti:
            """
            Follows a generalizable pattern: 
                x_n > x_m 
            """
            Ti = self.get("Ti")
            Th = self.get("Th")
            constr = Th - Ti
            self.nlp["g"] = ca.vertcat(self.nlp["g"], constr)
            self.lbg = np.concatenate([self.lbg,
                                       np.array([0]*constr.shape[0])])
            self.ubg = np.concatenate([self.ubg,
                                       np.array([np.inf]*constr.shape[0])])
        if Ci_gt_Ch:
            """
            Assuming Ci is TVP.
            """
            Ci = self.get("Ci")
            Ch = self.get("Ch")
            constr = Ci - Ch
            self.nlp["g"] = ca.vertcat(self.nlp["g"], constr)
            self.lbg = np.concatenate([self.lbg,
                                       np.array([0]*constr.shape[0])])
            self.ubg = np.concatenate([self.ubg,
                                       np.array([np.inf]*constr.shape[0])])
        if Ce_gt_Ch:
            """
            Assuming Ci is TVP.
            """
            Ce = self.get("Ce")
            Ch = self.get("Ch")
            constr = Ce - Ch
            self.nlp["g"] = ca.vertcat(self.nlp["g"], constr)
            self.lbg = np.concatenate([self.lbg,
                                       np.array([0]*constr.shape[0])])
            self.ubg = np.concatenate([self.ubg,
                                       np.array([np.inf]*constr.shape[0])])

        self.prepare_solver()
        
        # check jac_g_x
        """
        jac_g_x = ca.jacobian(self.nlp["g"], self.nlp["x"])
        jac_g_x_ = ca.Function("jac_g_x", [self.nlp["x"]], [jac_g_x],
                               ["x"], ["jac_g_x"])
        jac_g_x_sx = jac_g_x_.expand()
        
        # test eval:
        test_sx = np.array(jac_g_x_sx(self.x0))
        test_mx = np.array(jac_g_x_(self.x0))
        print(np.isnan(test_mx).any())
        print(np.isnan(test_sx).any())
        
        solver_func = self.solver.get_function("nlp_jac_g")
        test_ = solver_func(self.x0, 0)[0]
        print(np.isnan(test_).any())
        
        #np.where(self.x0 == 0)
        self.x0[np.where(self.x0 == 0)] = 0.01
        test_ = solver_func(self.x0, 0)[0]
        print(np.isnan(test_).any())
        
        np.where(test_sx == np.nan)
        """
        
        solution = self.solver(
                               x0=self.x0,
                               lbg=self.lbg, # option for path-constraints?
                               ubg=self.ubg, # --"--
                               lbx=self.lbx,
                               ubx=self.ubx,
                               p=covar
                               )
        """        
        solution = self.solver(
                               x0=self.x0,
                               lbg=0, # option for path-constraints?
                               ubg=0, # --"--
                               lbx=self.lbx,
                               ubx=self.ubx,
                               )
        """
        
        self.sol_df, params = self.parse_solution(solution)
        if return_raw_sol:
            return self.sol_df, params, solution
        else:
            return self.sol_df, params