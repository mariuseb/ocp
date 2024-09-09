import casadi as ca
import pandas as pd
import numpy as np
from ocp.ocp import OCP
from ocp.filters import KalmanBucy
import re
from typing import Union

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
        self.algebraic_slack = kwargs.pop("algebraic_slack", False)
        if self.slack:
            self.add_slack_to_shooting_gaps(algebraic_slack=self.algebraic_slack)
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
        
        
    def add_slack_to_shooting_gaps(self, algebraic_slack=False):
        """
        Write:  
            F(x, u) - x+ = s
        instead of:
            F(x, u) - x+ = 0
        
        TODO:
            - should also be accessible
            from ParameterEstimation.
           
        Only for multiple shooting for now.
        """
        if algebraic_slack:
            self.n_sl = self.n_x + self.n_z
            alg_gaps = self.nlp_parser.vars["z"]["alg_gaps"]
        else:
            self.n_sl = self.n_x
            alg_gaps = ca.MX(self.N-1)
        
        shooting_gaps = self.nlp_parser.vars["x"]["shooting_gaps"]
        #alg_gaps = self.nlp_parser.vars["z"]["alg_gaps"]
        sigma_shape = (self.N-1, self.n_sl)
        self.sigma = sigma = ca.MX.sym("sigma", sigma_shape)
        """
        Differential part:
        """
        diff_sigma = sigma[:,:self.n_x]
        new_x_gaps = shooting_gaps + diff_sigma
        #self.n_sl = self.n_x
        """
        Algebraic part:
        """
        alg_sigma = sigma[:,self.n_x:(self.n_sl)]
        new_z_gaps = alg_gaps + alg_sigma
        """
        Flatten, add new differential gaps back to NLP:
        """
        new_x_gaps = ca.veccat(new_x_gaps)
        self.nlp["g"][0:new_x_gaps.shape[0]] = new_x_gaps
        """
        Same for algebraic gaps:
        """
        new_z_gaps = ca.veccat(new_z_gaps)
        start = new_x_gaps.shape[0]
        stop = start + new_z_gaps.shape[0]
        self.nlp["g"][start:stop] = new_z_gaps
        
        """
        Add slack variable to problem definition:
        """
        self.nlp["x"] = ca.vertcat(self.nlp["x"], ca.veccat(self.sigma))
        dim = self.sigma.shape[0]*self.sigma.shape[1]
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
        #self.n_sl = self.n_x + self.n_z
        self.slack_names = list(map(lambda x: "s" + str(x+1), range(self.n_sl)))
                
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
        
        #symbols = set(re.findall("|".join(self.dae.all_names), self.obj_string))
        all_names = sorted(self.dae.all_names, reverse=True)
        symbols = re.findall("|".join(all_names), self.obj_string)
        vals = dict()
        for symbol in symbols:
            vals[symbol] = self.get(symbol)
        obj_string = self.obj_string.replace("dot", "ca.dot")
        vals["ca"] = ca
        vals["R"] = self.R
        vals["Q"] = self.Q
    
        """
        s1, s2, ... , s_{nx} are aliases for sigma[:,0] , ... , sigma[:,nx-1]
        """
        if self.slack:
            sigma = self.sigma.reshape((self.N-1, self.n_x + self.n_z))
            for n in range(self.n_x + self.n_z):
                vals["s" + str(n+1)] = sigma[:,n]
    
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
        s = ca.vec(self.sigma)
        
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
            self.alt_obj += s_n_contrib
        """
        Measurement noise:
        """
        for n in range(dim_y):
            v_n_contrib = res_y[n:(dim_y_nlp-dim_y):dim_y]
            self.alt_obj += v_n_contrib
        
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
                                        s,
                                      ca.vec(R),
                                      ca.vec(Q)
                                      ],
                                    [alt_hess_expr],
                                    #self.dae.p + ["x", "u", "y", "R", "Q"],
                                    ["p", "x", "z", "u", "r", "y", "v", "s", "R", "Q"],
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
        s_vals = self.sol_df.iloc[1:][self.slack_names].values.flatten()
        
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
    
    def add_path_constraints(
                            self,
                            x0=None,
                            lbx=None,
                            ubx=None
                            ):
        
        x_info = self.nlp_parser["x"]
        x = self.nlp["x"][x_info["range"]["a"]:x_info["range"]["b"]]

        path_constr = x
        
        lbg = np.array([0]*self.nlp_parser.g.shape[0])
        ubg = np.array([0]*self.nlp_parser.g.shape[0])
        
        self.lbg = np.append(lbg, lbx)
        self.ubg = np.append(ubg, ubx)
        
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
                
    def write_tvp_kalman_files(
                               self, 
                               config_name: str,
                               params: Union[pd.Series, pd.DataFrame], 
                               switches: list
                               ):
        """
        Write files with parameters for Kalman filter,
        where switches indicate on which input
        parameters are switched.
        
        NB: must be in correct order,
        i.e. a1 corresponding to first element
        in switches, a2 the second etc.
        """
        n_switches = len(switches)
        params_switched = [
                           ndx for ndx in params.index
                           if "_a" in ndx
                           and ndx[-1].isdigit()
                           and int(ndx[-1]) <= n_switches
                           ]
        params_base = params.loc[[
                                  ndx for ndx in params.index 
                                  if ndx not in params_switched
                                 ]]
        params_base.to_csv(
                           "results/params_" + \
                            config_name + \
                            "_base.csv"
                           )
        for i, switch in enumerate(switches):
            suffix = "a" + str(i+1)
            params_mod = params.loc[[
                                     name for name in params_switched 
                                     if name.endswith(suffix)
                                     ]]
            name_map = {
                        k: k.removesuffix("_" + suffix)
                        for k in params_mod.index
                        }
            params_mod.rename(name_map, inplace=True)
            params_mod = params_mod.reindex(params_base.index, fill_value=0)
            params_mod = params_base + params_mod
            params_mod.to_csv(
                            "results/params_" + \
                                config_name + \
                                "_mod_%s.csv" % \
                                    (switch, )
                            )
                                  
    def solve(
              self,
              data,
              param_guess,
              covar=None,
              lbp=None,
              ubp=None,
              lbx=None,
              ubx=None,
              x_guess=None,
              return_raw_sol=False,
              codegen=False
              ):
        """
        Set initials for v, w to 0
        """
        self.data = data
        
        if isinstance(param_guess, dict):
            p0 = self.param_guess.get_param_guess()
        else:
            p0 = param_guess
        
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
                          param_guess=p0
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
        
        self.add_h()
        self.prepare_solver(codegen=codegen)
        
        """
        Remove 0-lower bound on slack:
        """
        if self.slack:
            start, stop = self.nlp_parser.vars["sl"]["range"]["a"], self.nlp_parser.vars["sl"]["range"]["b"]
            self.lbx[start:stop] = -np.inf
        
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