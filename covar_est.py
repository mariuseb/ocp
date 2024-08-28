import casadi as ca
import pandas as pd
import numpy as np
#from ocp.ocp import OCP
#from ocp.filters import EKF, KalmanBucy
#import re
#from typing import Union

class CovarianceEstimation(object):
    
    """
    Functionality to generate
    estimate of covariance, 
    both for states and parameters.
    
    Based on taking differentiating
    the complete data likelihood twice, 
    which yields an estimate of the
    Fisher information matrix (FIM), 
    which has a analytical relationship with
    the covariance. 
    
    This can be used e.g. in further estimation,
    either as part of a moving horizon estimation
    scheme or as a part of a fixed frequency update
    of parameters in a MPC scheme.  
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
        p = self.integrator.p
        y = ca.vec(self.nlp_y)
        v = ca.vec(self.nlp_v)
        r = ca.vec(self.nlp_r)
        #s = ca.vec(self.sigma)
        
        R = self.R
        Q = self.Q
              
        # residual x:
        res_x = self.nlp_parser.x_gaps
        # residual y:
        res_y = self.nlp_parser.h_gaps
        
        self.x_gaps = ca.Function(
                                  "x_gaps",
                                   [
                                    x,
                                    z,
                                    u,
                                    p,
                                    r,
                                    ca.vec(R),
                                    ca.vec(Q)
                                    ],
                                    [res_x],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["x", "z", "u", "p", "r", "R", "Q"],
                                    ["hess_obj"]
                                  )
        self.y_gaps = ca.Function(
                                  "y_gaps",
                                   [
                                    x,
                                    z,
                                    u,
                                    p,
                                    r,
                                    y,
                                    v,
                                    ca.vec(R),
                                    ca.vec(Q)
                                    ],
                                    [res_y],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["x", "z", "u", "p", "r", "y", "v", "R", "Q"],
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
        dim_y = self.dae.n_y
        dim_x_nlp = self.nlp_parser["x"]["dim"]
        dim_y_nlp = self.nlp_parser["y"]["dim"]
        """
        s1 = res_x[0:(dim_x_nlp-dim_x):dim_x]
        s2 = res_x[1:(dim_x_nlp-dim_x):dim_x]
        s3 = res_x[2:(dim_x_nlp-dim_x):dim_x]
        self.alt_obj = 0.5*ca.dot(res_y, res_y)@self.R[0,0] + \
                       0.5*ca.dot(s1, s1)@self.Q[0,0] + \
                       0.5*ca.dot(s2, s2)@self.Q[1,1] + \
                       0.5*ca.dot(s3, s3)@self.Q[2,2] + \
                        + \
                        ((self.N-1)/2)*self.log_det_Q(self.Q) \
                        + \
                        (self.N/2)*self.log_det_R(self.R)
        """
        self.alt_obj = 0
        """
        'Equation noise':
        """
        for n in range(dim_x):
            s_n_contrib = res_x[n:(dim_x_nlp-dim_x):dim_x]
            self.alt_obj += 0.5*ca.dot(s_n_contrib, s_n_contrib)@self.Q[n,n]
        """
        Measurement noise:
        """
        for n in range(dim_y):
            v_n_contrib = res_y[n:(dim_y_nlp-dim_y):dim_y]
            self.alt_obj += 0.5*ca.dot(v_n_contrib, v_n_contrib)@self.R[n,n]
        
        """
        Regularization of noise weightings:
        """
        self.alt_obj += ((self.N-1)/2)*self.log_det_Q(self.Q) \
                        + \
                        (self.N/2)*self.log_det_R(self.R)

    
        self.alt_obj_func = ca.Function("alt_obj",
                                            [
                                            x,
                                            z,
                                            u,
                                            p,
                                            r,
                                            y,
                                            v,
                                             ca.vec(R),
                                             ca.vec(Q)
                                             ],
                                            [self.alt_obj],
                                            #self.dae.p + ["x", "u", "y", "R", "Q"],
                                            ["x", "z", "u", "p", "r", "y", "v", "R", "Q"],
                                            ["hess_obj"]
                                        )           
        
        """
        self.obj_func = ca.Function("alt_obj",
                                            [
                                            x,
                                            z,
                                            u,
                                            p,
                                            r,
                                            y,
                                            v,
                                            s,
                                            ca.vec(R),
                                            ca.vec(Q)
                                             ],
                                            [self.nlp["f"]],
                                            #self.dae.p + ["x", "u", "y", "R", "Q"],
                                            ["x", "z", "u", "p", "r", "y", "v", "s", "R", "Q"],
                                            ["hess_obj"]
                                        )           
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
        hess_expr =  ca.hessian(self.nlp["f"],
                                ca.vertcat(
                                            p,
                                            x,
                                            z,
                                            u,
                                            r,
                                            y,
                                            v,
                                            s,
                                           ca.vec(R),
                                           ca.vec(Q)
                                           )
                                )[0]             
        """
        
        alt_hess_expr =  ca.hessian(self.alt_obj,
                                ca.vertcat(
                                            p,
                                            x,
                                            z,
                                            u,
                                            r,
                                            y,
                                            v,
                                           ca.vec(R),
                                           ca.vec(Q)
                                           )
                                )[0]             
        
        self.hess_obj = ca.Function(
                                    "hess_obj",
                                     [
                                        p,
                                        x,
                                        z,
                                        u,
                                        r,
                                        y,
                                        v,
                                        #s,
                                      ca.vec(R),
                                      ca.vec(Q)
                                      ],
                                    [alt_hess_expr],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    #["p", "x", "z", "u", "r", "y", "v", "s", "R", "Q"],
                                    ["p", "x", "z", "u", "r", "y", "v", "R", "Q"],
                                    ["hess_obj"]
                                    )
                
    def get_covar_p(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """
        x_vals = self.scaled_sol_df[self.dae.x].values.flatten()
        z_vals = self.scaled_sol_df[self.dae.z].values.flatten()
        u_vals = self.scaled_sol_df[self.dae.u].values.flatten()
        r_vals = self.scaled_sol_df[self.dae.r_names].values.flatten()
        y_vals = self.scaled_sol_df[list(self.dae.y.keys())].values.flatten()
        v_vals = self.scaled_sol_df[self.dae.v_names].values.flatten()
        s_vals = self.scaled_sol_df.iloc[1:][self.slack_names].values.flatten()
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 z_vals,
                                 u_vals,
                                 r_vals,
                                 y_vals,
                                 v_vals,
                                 s_vals,
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
                
    def get_covar_p_unscaled(self, params, R, Q):
        """
        Get covariance of parameter estimates.
        """
        x_vals = self.sol_df[self.dae.x].values.flatten()
        z_vals = self.sol_df[self.dae.z].values.flatten()
        u_vals = self.sol_df[self.dae.u].values.flatten()
        r_vals = self.sol_df[self.dae.r_names].values.flatten()
        y_vals = self.sol_df[list(self.dae.y.keys())].values.flatten()
        v_vals = self.sol_df[self.dae.v_names].values.flatten()
        #s_vals = self.sol_df.iloc[1:][self.slack_names].values.flatten()
        
        # sample fisher information:
        hess_val = self.hess_obj(
                                 params,
                                 x_vals,
                                 z_vals,
                                 u_vals,
                                 r_vals,
                                 y_vals,
                                 v_vals,
                                 #s_vals,
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
        fisher = np.linalg.inv(np.diag(np.sqrt(np.diag(fisher))*self.p_nom))
        #fisher_scaled = hess_val_scaled[:param_dim,:param_dim]
        
        """
        return pd.DataFrame(data=np.array(ca.inv(fisher)),
                            index=self.dae.p,
                            columns=self.dae.p), \
                pd.DataFrame(data=np.array(fisher),
                            index=self.dae.p,
                            columns=self.dae.p)
        """ 
        return pd.DataFrame(data=fisher,
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