import cvxpy as cp
import numpy as np
import casadi as ca
from abc import ABC, abstractmethod, ABCMeta
from ocp.rl_sdp import RL_SDP
import pandas as pd
from pprint import pprint
#import pandas as pd
#import os
#from ocp.tests.utils import get_data_path
#import mosek

"""
Define an abstract RL class that sets up
the needed sensitivity functions
from the symbolic MPC and MHE problems.

With this, TD(0)-methods is 
straightforward to implement.
"""

class RL(metaclass=ABCMeta):
    """
    To TD(0)-steps, we need the derivative:
        dQ/dθ = ∂Q/∂θ + ∂Q/∂x0*∂x0/∂θ + ∂Q/∂p*∂p/∂θ 
        
    For the time being consider only 
    the MHE problem to be parametric,
    hence we have ∂Q/∂θ = 0.
    
    ∂Q/∂x0 and ∂Q/∂p can be trivially 
    obtained by differentiating the 
    Lagrangian of the MPC problem.
    
    ∂p/∂θ and ∂x0/∂θ requires application
    of the IFT on the KKT-residual of the
    MHE problem.
    
    NOTE: we start by only having:
        - P = θ
    i.e. only tuning the arrival cost.
    
    Next targets for learning:
        - Q, R of MHE
        - lbp, ubp of MHE
        
    Some notation:
        - MHE-NLP:
            * NLP arising from transcription of MHE
        - MPC-NLP:
            * NLP arising from transcription of MPC
        - g_hat:
            * Equality constraints of MHE-NLP
        - g:
            * Equality constraints of MPC-NLP
        - h_hat:
            * Inequality constraints of MHE-NLP
        - h:
            * Inequality constraints of MPC-NLP
        - w_hat: 
            * Primal of MHE-NLP
        - w: 
            * Primal of MPC-NLP
        - λ_hat:
            * Dual of g_hat
        - λ:
            * Dual of g
        - μ_hat:
            * Dual of h_hat
        - μ:
            * Dual of h
        - z:
            * the tuple {w, λ, μ}
        - z_hat:
            * the tuple {w_hat, λ_hat, μ_hat}
      
      
    NOTE: implement first for only equality constraints.      
    
    NOTE: might as well go ahead and do for h as well.
        Need:
            function for pruning NLP to find inequality constraints:
                - just iterate through g and mark indices where lbg != ubg
            BUT - doesn't this mean that Function instances should change
                each time the active set changes? seems so
                
    Refactor this code to:
        - only set up now Function instances when the active set
        changes in one or both of MHE-NLP, MPC-NLP.
    """
    def __init__(self, mpc, mhe, **config):
        """
        """
        self.alpha = config.pop("alpha", 0.01)
        self.gamma = config.pop("gamma", 0.99)
        
        self._init_mpc_params(mpc)
        #self._init_mhe_params(mhe, p, Q, R, P0)
        self.h_active_inds = {0: [np.inf]}
        self.k = 1
        #self.set_F_dQ_dz(mpc)

        # extract base inds for h(w, p)
        self.base_inds_mhe = []
        self.not_base_inds_mhe = []
        for name in ("p", "v", "w", "x", "z"):
            self.base_inds_mhe.extend(list(
                                    range(mhe.nlp_parser.vars[name]["range"]["a"],
                                            mhe.nlp_parser.vars[name]["range"]["b"]
                                            )
                                        )
                                )
        for name in ("u", "r", "y"):
            self.not_base_inds_mhe.extend(list(
                                    range(mhe.nlp_parser.vars[name]["range"]["a"],
                                            mhe.nlp_parser.vars[name]["range"]["b"]
                                            )
                                        )
                                )
        
        self._init_MHE_sens(mhe)
        self.sens = pd.DataFrame(columns=mpc.dae.p + mpc.dae.x)
        self.sens_Q = pd.DataFrame(columns=mhe.dae.x*mhe.dae.n_x)
        self.sens_R = pd.DataFrame(columns=mhe.dae.y_names*mhe.dae.n_y)
        self.sens_sdp = pd.DataFrame(columns=mpc.dae.p + mpc.dae.x)
        self.sens_mhe = pd.DataFrame(columns=mpc.dae.p + mpc.dae.x)
        
        # epsilon as well?
        # needed for both Q and SARSA
        #self.mhe_nlp = mhe.nlp
        #self.mpc_nlp = mhe.nlp
        #self.mpc_parser = mpc.nlp_parser
        #self.mhe_parser = mhe.nlp_parser
        #self._init_mpc_params(mpc)
        #self._init_mhe_params(mhe)
        #self.set_F_dQ_dz(mpc)
        
    def _init_mpc_params(self, mpc):
        """
        Scrape relevant params
        from MPC problem.
        """
        self.x_bounds = mpc.nlp_parser["x"]["range"]
        self.p_bounds = mpc.nlp_parser["p"]["range"]
        self.u_bounds = mpc.nlp_parser["u"]["range"]
        self.dim_x = mpc.dae.n_x
        self.dim_p = mpc.dae.n_p
        self.dim_u = mpc.dae.n_u
        
    def _init_MHE_sens(self, mhe):
    #def get_MHE_sens(self, mhe, p_val, Q_val, R_val, P0_val):
        """
        .
        """
        self.mhe = mhe
        self.nlp = nlp = mhe.nlp
        g = nlp["g"]
        f = nlp["f"]
        p = nlp["p"]
        self.w_hat = w_hat = nlp["x"]
        #sol = mhe.solution

        # symnolic params:
        _p = mhe.costate_prior # new name, e.g. z?
        _Q = mhe.Q
        _R = mhe.R
        _P0 = mhe.P0

        # assemble Lagrangian:
        lambda_hat = ca.MX.sym("lambda_hat", g.shape[0]) # symbolic duals for equality constraints
        
        # find num inequality constraints
        # only on x for now:
        
        """
        TODO: 
        inspect this.
        Also, do not re-init these functions unecessarily
        """
        self.inact_x_inds  = np.array(
                                      [
                                       mhe.lbx
                                       < 
                                       mhe.solution["x"]
                                      ],
                                      dtype=bool
                                      ).flatten()
        
        # These are inactive by default (not decision variables):
        #self.inact_x_inds[[ndx for ndx in self.not_base_inds_mhe]] = True
        
        #self.act_x_inds = np.array([mhe.lbx == mhe.solution["x"]], dtype=bool).flatten()
        
        """
        For the MHE-problem, what are decision variables? 
        
        Only: p, v, w, x, z
        So extract those:
        (Can set this in __init__)
        """
        
        #x_map = {ndx: w_hat[ndx] for ndx, val in enumerate(inact_x) if not val}
        #h_active_inds = ca.DM([ndx for ndx if not()])
        #self.h_active_inds[self.k] = [ndx for ndx, val in enumerate(self.inact_x_inds) if not val]
        #h_active = ca.vertcat(*self.h_active_inds[self.k])
        #self.k += 1
        
        h_active_inds = [ndx for ndx, val in enumerate(self.inact_x_inds) if not val]
        #_h_active_inds = [ndx for ndx, val in enumerate(self.act_x_inds) if val]
        #h_active_inds = [w_hat[ndx] for ndx in h_active_inds]
        h_active = ca.vertcat(*[w_hat[ndx] for ndx in h_active_inds])
        self.h_active_inds[self.k] = h_active_inds
        
        
        # TODO: clean up:
        # if no h_active, then skip all consideration of inequalities

        # check if active set has changed::
        if h_active_inds != self.h_active_inds[self.k-1]:
        
            # no g yet:
            #inact_g = np.array([mhe.lbx < mhe.solution["x"]], dtype=bool).flatten()
            if h_active.shape[0] == 0:
                self.mu_hat = mu_hat = ca.Sparsity(0,0)
                #h_active = ca.sym.MX("zero")
                #self.mu_hat = 0
                
                self.z_hat = z_hat = ca.vertcat(w_hat, lambda_hat)
                L = f - ca.mtimes(lambda_hat.T, g)
                self.jac_h_w = ca.Sparsity(0,0)
                self.n_jac_h_w = n_jac_h_w = 0
            else:
                self.mu_hat = mu_hat = ca.MX.sym("mu_hat", h_active.shape[0]) # ------""------ inequality constraints
                self.z_hat = z_hat = ca.vertcat(w_hat, lambda_hat, mu_hat)
                L = f - ca.mtimes(lambda_hat.T, g) - ca.mtimes(mu_hat.T, h_active)  # lagrangian
                self.jac_h_w = ca.jacobian(h_active, w_hat)
                self.n_jac_h_w = n_jac_h_w = self.jac_h_w.shape[0]
            #L = f
            # z_hat: (w_hat, lambda_hat, mu_hat):
            
            # gradient
            grad_L_w = ca.jacobian(L, w_hat) # transpose this
            # hessian
            hess_L_w = ca.hessian(L, w_hat)[0]
    
            R = ca.vertcat(grad_L_w.T, g, h_active)
            # params:
            #theta = ca.veccat(_p, _Q, _R, _P0)
            theta = ca.veccat(_P0, _Q, _R, _p)
            dR_dtheta = ca.jacobian(R, theta)
            
            self.dR_dtheta_func = ca.Function("dRdTheta", [theta, z_hat], [dR_dtheta], ["theta", "z_hat"], ["dR_dtheta"])
            
            self.jac_g_w = ca.jacobian(g, w_hat)
            
            n_hess = hess_L_w.shape[0]
            n_jac_g_w = self.jac_g_w.shape[0]
            
            # prepare for KKT-matrix:
            self.n_KKT = n_hess + n_jac_g_w + n_jac_h_w
        
            self.L_start = 0
            self.L_stop = self.G_start_row = w_hat.shape[0]
            # eq. constraints:
            self.G_stop_row = self.H_start_row = self.G_start_row + self.nlp["g"].shape[0]
            self.G_start_col = 0
            self.G_stop_col = self.G_start_col + self.jac_g_w.shape[1]
            # G.T
            self.GT_start_col = self.L_stop
            self.GT_stop_col = self.GT_start_col + self.jac_g_w.shape[0]
            # ineq. constraints:
            self.H_stop_row = self.H_start_row + mu_hat.shape[0]
            self.H_start_col = 0
            self.H_stop_col = self.H_start_col + self.jac_h_w.shape[1]
            # H.T
            self.HT_start_col = self.GT_stop_col
            self.HT_stop_col = self.HT_start_col + self.jac_h_w.shape[0]
        
            # set the functions:
            #self.R_func = ca.Function("R", [z_hat, _p, _Q, _R, _P0], [R], ["z_hat", "p", "Q", "R", "P0"], ["R"])
            #self.hess_L = ca.Function("hess_L", [w_hat, _p, _Q, _R, _P0, lambda_hat], [hess_L_w], ["w_hat", "p", "Q", "R", "P0", "lambda_hat"], ["hess_L_w"])
            #self.J_g_w = ca.Function("JgW", [w_hat, _p, _Q, _R, _P0, lambda_hat], [self.jac_g_w], ["w_hat", "p", "Q", "R", "P0", "lambda_hat"], ["jac_g_w"])
            #if n_jac_h_w > 0:
            #self.J_h_w = ca.Function("JhW", [w_hat, _p, _Q, _R, _P0, mu_hat], [self.jac_h_w], ["w_hat", "p", "Q", "R", "P0", "mu_hat"], ["jac_h_w"])
            # else:
            #    self.J_h_w = ca.Function("JhW", [w_hat, _p, _Q, _R, _P0, mu_hat], [0], ["w_hat", "p", "Q", "R", "P0", "mu_hat"], ["jac_h_w"])
            
            # rearrange function arguments:
            self.R_func = ca.Function("R", [z_hat, _P0, _Q, _R, _p], [R], ["z_hat", "P0", "Q", "R", "p"], ["R"])
            self.hess_L = ca.Function("hess_L", [w_hat, _P0, _Q, _R, _p, lambda_hat], [hess_L_w], ["w_hat", "P0", "Q", "R", "p", "lambda_hat"], ["hess_L_w"])
            self.J_g_w = ca.Function("JgW", [w_hat, _P0, _Q, _R, _p, lambda_hat], [self.jac_g_w], ["w_hat", "P0", "Q", "R", "p", "lambda_hat"], ["jac_g_w"])
            #if n_jac_h_w > 0:
            self.J_h_w = ca.Function("JhW", [w_hat, _P0, _Q, _R, _p, mu_hat], [self.jac_h_w], ["w_hat", "P0", "Q", "R", "p", "mu_hat"], ["jac_h_w"])
        
        # increment:
        self.k += 1
        
    def get_MHE_sens(self, mhe, sol, p_val, Q_val, R_val, P0_val):
        
        # refs:
        w_hat = self.w_hat
        jac_g_w = self.jac_g_w
        jac_h_w = self.jac_h_w
        mu_hat = self.mu_hat
        
        # evaluate mhe solution with sqpmethod + qrqp:
        
        """
        sol = mhe.sqp_solver(
                        x0=sol["x"],
                        #x0=self.x0,
                        lbg=0,
                        ubg=0,
                        lbx=mhe.lbx,
                        ubx=mhe.ubx,
                        p=mhe.p_val
                )
        """

        lam_x = np.array(sol["lam_x"])
        w_hat_val = sol["x"]
        # get numerical z_hat from mhe solution:
        
        # TODO: monitor active set
        mu_val = ca.DM(
                        [val for i, val in enumerate(lam_x)
                        if not self.inact_x_inds[i]]
                       )
        
        z_hat_val = ca.vertcat(w_hat_val,
                               sol["lam_g"],
                               mu_val)
        
        #_R_val = self.R_func(z_hat_val, p_val, Q_val, R_val, P0_val)
        
        #hess_L_val = self.hess_L(sol["x"], p_val, Q_val, R_val, P0_val, sol["lam_g"])
        #jac_g_w_val = self.J_g_w(sol["x"], p_val, Q_val, R_val, P0_val, sol["lam_g"])
        
        # rearrange:
        
        hess_L_val = self.hess_L(sol["x"], P0_val, Q_val, R_val, p_val, sol["lam_g"])
        jac_g_w_val = self.J_g_w(sol["x"], P0_val, Q_val, R_val, p_val, sol["lam_g"])
        
        if self.n_jac_h_w > 0:
            jac_h_w_val = self.J_h_w(sol["x"], P0_val, Q_val, R_val, p_val, mu_val)
        else:
            jac_h_w_val = ca.DM([0])
        
        # test dR_dtheta:
        dR_dtheta_val = self.dR_dtheta_func(ca.veccat(P0_val, Q_val, R_val, p_val), z_hat_val)
        
        
        # try to construct simplified KKT-matrix:
        #KKT_num = ca.DM.zeros(self.n_KKT, self.n_KKT)
        """
        KKT_num = np.zeros((self.n_KKT, self.n_KKT))
        
        L_start = 0
        L_stop = G_start_row = w_hat.shape[0]
        # eq. constraints:
        G_stop_row = H_start_row = G_start_row + self.nlp["g"].shape[0]
        G_start_col = 0
        G_stop_col = G_start_col + jac_g_w.shape[1]
        # G.T
        GT_start_col = L_stop
        GT_stop_col = GT_start_col + jac_g_w.shape[0]
        # ineq. constraints:
        H_stop_row = H_start_row + mu_hat.shape[0]
        H_start_col = 0
        H_stop_col = H_start_col + jac_h_w.shape[1]
        # H.T
        HT_start_col = GT_stop_col
        HT_stop_col = HT_start_col + jac_h_w.shape[0]
        """   
        # set numeric KKT:
        KKT_num = np.zeros((self.n_KKT, self.n_KKT))
        
        KKT_num[self.L_start:self.L_stop,
                self.L_start:self.L_stop] = np.array(hess_L_val)
        # set jac_G:
        KKT_num[self.G_start_row:self.G_stop_row, 
                self.G_start_col:self.G_stop_col] = np.array(jac_g_w_val)
        # set the transpose of jac_G (grad_G):
        KKT_num[self.L_start:self.L_stop,
                self.GT_start_col:self.GT_stop_col] = np.array(jac_g_w_val.T)
        # set jac_H:
        KKT_num[self.H_start_row:self.H_stop_row,
                self.H_start_col:self.H_stop_col] = np.array(jac_h_w_val)
        # set the transpose of jac_H (grad_H):
        KKT_num[self.L_start:self.L_stop,
                self.HT_start_col:self.HT_stop_col] = np.array(jac_h_w_val.T)
        
        # evaluate jac_R
        # we know this inverse must exist:
        #dR_dz_inv = ca.Function("dRdZInv", [KKT_symbolic], [ca.inv(KKT_symbolic)])
        
        #dz_dtheta = ca.mtimes(ca.inv(KKT_num), dR_dtheta_val)
        dz_dtheta = np.linalg.inv(KKT_num)@dR_dtheta_val
        
        # extract dx_-1/d_theta and dp/d_theta
        
        x_init_stop = self.mhe.nlp_parser["x"]["range"]["b"]
        x_init_start = x_init_stop - self.mhe.dae.n_x
        dx_init_dtheta = dz_dtheta[x_init_start:x_init_stop, :]
        
        p_start = self.mhe.nlp_parser["p"]["range"]["a"]
        p_stop = self.mhe.nlp_parser["p"]["range"]["b"]
        dp_dtheta = dz_dtheta[p_start:p_stop, :]
        
        return dx_init_dtheta, dp_dtheta
        
        # dR/dtheta:
        
        
        # now construct KKT as DM from the various components:
        
        
        #dR_dz = ca.MX

        #R = ca.vertcat(dL_dw_expr, g, h_active)

        # want R as expression:
        #self.R = ca.jacobian(R)
        
        
    def get_g_index(self):
        """
        Get index of equality constraints.
        """
        pass
        
        
        
    def set_F_dQ_dz(self, mpc):
        """
        Set the function for obtaining:
            * ∂Q/∂w
            
        TODO: include inequality constraints.
        """
        nlp = mpc.nlp
        g = nlp["g"]
        
        # TODO: check this outside this function,
        # prior to setting up new function objects
        
        # get inequality constraint indices:
        
        """
        bools = mpc.lbg != mpc.ubg
        h_inds = [ndx for ndx, val in enumerate(bools) if val]
        self.g_inds = g_inds = [ndx for ndx, val in enumerate(bools) if not val]
        
        start = mpc.nlp_parser["x"]["range"]["a"] + mpc.dae.n_x
        stop = mpc.nlp_parser["x"]["range"]["b"]
        
        # extract x trajectory from solution:
        h_active_inds_lb = [h_ind for bool, h_ind in zip(np.array(mpc.solution["x"][start:stop] > mpc.lbg[h_inds]).flatten(), h_inds) if not bool]
        # NOTE: obviously more clever way of doing this..
        h_active_inds_ub = [h_ind for bool, h_ind in zip(np.array(mpc.solution["x"][start:stop] < mpc.ubg[h_inds]).flatten(), h_inds) if not bool]
        
        self.h_active_inds = h_active_inds = np.append(h_active_inds_lb, h_active_inds_ub)
        
        mu = ca.MX.sym("mu", len(h_active_inds))
        
        g_eq = g[g_inds]
        h = g[h_active_inds]
        """
        #_lambda = ca.MX.sym("lambda", g_eq.shape[0])
        _lambda = ca.MX.sym("lambda", g.shape[0])
        # lagrangian of MPC-NLP:
        
        #L = nlp["f"] - ca.mtimes(_lambda.T, g_eq) - ca.mtimes(mu.T, h)
        L = nlp["f"] - ca.mtimes(_lambda.T, g)
        # primal:
        w = nlp["x"]
        # primal-dual:
        #z = ca.vertcat(w, _lambda, mu)
        z = ca.vertcat(w, _lambda, mpc.nlp["p"])
        # take gradient:
        dL_dw = ca.gradient(L, z)
        # set as function:
        self.F_dL_dw = ca.Function("FdLdw", [z], [dL_dw])
        
    
    """ 
    The below seems to be wrong..
    
    Need to reformulate the problem, 
    setting x_k and p_k as parameters
    in parametric NLP.
    """
    
    def get_dQ_dx0(self, dQ_dz):
        return dQ_dz[self.x_bounds["a"]:(self.x_bounds["a"] + self.dim_x)]
        
    def get_dQ_dp(self, dQ_dz):
        return dQ_dz[self.p_bounds["a"]:self.p_bounds["b"]]
    
    """
    def get_MPC_sens(self, sol):
        #z_val = ca.vertcat(sol["x"], sol["lam_g"][self.g_inds], sol["lam_g"][self.h_active_inds])
        
        z_val = ca.vertcat(sol["x"], sol["lam_g"], sol["p"])
        dQ_dz = self.F_dL_dw(z_val)
        
        return self.get_dQ_dx0(dQ_dz).T, self.get_dQ_dp(dQ_dz).T
    """
    
    def get_MPC_sens(self, mpc, sol):
        """
        Evaluate nlp-solution with sqpmethod + qrqp
        to get more accurate sensitivities.
    
        """
        x0_start, x0_stop = self.x_bounds["a"], (self.x_bounds["a"] + self.dim_x)
        p_start, p_stop = self.p_bounds["a"], self.p_bounds["b"]
        u_start, u_stop = self.u_bounds["a"], (self.u_bounds["a"] + self.dim_u)
        
        """
        sqp_sol = mpc.sqp_solver(
                                x0=sol["x"],
                                #x0=self.x0,
                                lbg=mpc.lbg,
                                ubg=mpc.ubg,
                                lbx=mpc.lbx,
                                ubx=mpc.ubx
                                #p=self.p_val
                        )
        """
        
        #return sqp_sol["lam_x"][x0_start:x0_stop].T, sqp_sol["lam_x"][p_start:p_stop].T #, sqp_sol["lam_x"][u_start:u_stop].T
        return sol["lam_x"][x0_start:x0_stop].T, sol["lam_x"][p_start:p_stop].T #, sqp_sol["lam_x"][u_start:u_stop].T
        
    def get_MHE_sens_obj(self, mhe, sol):
        """
        Evaluate nlp-solution with sqpmethod + qrqp
        to get more accurate sensitivities.
        
        sqp_sol = mhe.sqp_solver(
                                x0=sol["x"],
                                #x0=self.x0,
                                lbg=0,
                                ubg=0,
                                lbx=mhe.lbx,
                                ubx=mhe.ubx,
                                p=mhe.p_val
                                )
        """
        #return sqp_sol["lam_p"].T
        return sol["lam_p"].T
        
    
    def get_MPC_sens_jsolver(self, mpc, sol):
        """
        Get sensitivities from MPC problem,
        using Function generated from SQP-solver.
        """
        #dQ_dp_nlp = mpc.jsolver_sqp(x0=sol["x"], lam_x0=sol['lam_x'], lam_g0=sol['lam_g'],
        #            lbx=mpc.lbx, ubx=mpc.ubx, lbg=mpc.lbg, ubg=mpc.ubg, p=mpc.p_val)
        
        # prepare arguments for adj solver
        sol = mpc.solution
        
        nadj = mpc.nlp["p"].shape[0]
        adj_f = [ca.DM.zeros(sol['f'].sparsity()) for i in range(nadj)]
        adj_g = [ca.DM.zeros(sol['g'].sparsity()) for i in range(nadj)]
        adj_x = [ca.DM.zeros(sol['x'].sparsity()) for i in range(nadj)]
        
        adj_f[0][0] = 1
        
        sol_adj = mpc.sqp_adj(out_x=sol['x'], 
                              out_lam_g=sol['lam_g'],
                              out_lam_x=sol['lam_x'],
                              out_f=sol['f'],
                              out_g=sol['g'],
                              lbx=mpc.lbx,
                              ubx=mpc.ubx,
                              lbg=mpc.lbg,
                              ubg=mpc.ubg,
                              adj_f=ca.horzcat(*adj_f),
                              adj_g=ca.horzcat(*adj_g),
                              p=0,
                              adj_x=ca.horzcat(*adj_x))

        dQ_dp_nlp = mpc.jsolver_ipopt(x0=sol["x"],
                                      lam_x0=sol['lam_x'],
                                      lam_g0=sol['lam_g'],
                                      lbx=mpc.lbx,
                                      ubx=mpc.ubx,
                                      lbg=mpc.lbg,
                                      ubg=mpc.ubg,
                                      p=mpc.p_val)
        return dQ_dp_nlp
    
    
    def get_MHE_sens_hsolver(self, mhe, sol):
        """
        Get sensitivities from MPC problem,
        using Function generated from SQP-solver.
        """
        #dQ_dp_nlp = mpc.jsolver_sqp(x0=sol["x"], lam_x0=sol['lam_x'], lam_g0=sol['lam_g'],
        #            lbx=mpc.lbx, ubx=mpc.ubx, lbg=mpc.lbg, ubg=mpc.ubg, p=mpc.p_val)
        
        # prepare arguments for adj solver
        sol = mhe.solution
        
        sqp_sol = mhe.sqp_solver(
                        x0=sol["x"],
                        #x0=self.x0,
                        lbg=0,
                        ubg=0,
                        lbx=mhe.lbx,
                        ubx=mhe.ubx
                        #p=self.p_val
                )

        dQ_dp_dp = mhe.hsolver_ipopt(x0=sol["x"],
                                      lam_x0=sol['lam_x'],
                                      lam_g0=sol['lam_g'],
                                      lbx=mhe.lbx,
                                      ubx=mhe.ubx,
                                      lbg=0,
                                      ubg=0,
                                      p=mhe.p_val)
        return dQ_dp_dp
        
    
    def solve_SDP():
        pass
    
class Qlearning(RL):
    def step(self, mpc, mhe, p, Q, R, P0, diff_Q, R_k_plus_1, k, del_P0_accum, alpha=None):
            #self._init_mpc_params(mpc)
        #self._init_mhe_params(mhe, p, Q, R, P0)
        #try:
        ### check if active set has changed ###
        self._init_MHE_sens(mhe)
        #self.set_F_dQ_dz(mpc)
        dQ_hat_dtheta = self.get_MHE_sens_obj(mhe, mhe.solution)
        dQ_dx_init, dQ_dp = self.get_MPC_sens(mpc, mpc.solution)
        #dQ_dp_nlp = self.get_MPC_sens_jsolver(mpc, mpc.solution)
        dx_init_dtheta, dp_dtheta = self.get_MHE_sens(mhe, mhe.solution, p, Q, R, P0)
        # get grad(Q)_theta
        #grad_Q_theta = ca.mtimes(dQ_dx_init, dx_init_dtheta) + ca.mtimes(dQ_dp, dp_dtheta)
        grad_Q_theta = dQ_dx_init@dx_init_dtheta + dQ_dp@dp_dtheta
        
        
        # solve SDP for Δθ
        dim_P0 = P0.shape[0]*P0.shape[1]
        dim_Q = Q.shape[0]*Q.shape[1]
        dim_R = R.shape[0]*R.shape[1]
        # last elems:
        #start = grad_Q_theta.shape[1] - dim_P0
        #stop = grad_Q_theta.shape[1]
        
        # correction: P0 first elems:
        # next Q, then R
        start_P0 = 0
        stop_P0 = dim_P0
        stop_Q = stop_P0 + dim_Q
        stop_R = stop_Q + dim_R
        grad_Q_P0 = np.array(grad_Q_theta[start_P0:stop_P0])
        grad_Q_Q = np.array(grad_Q_theta[stop_P0:stop_Q])
        grad_Q_R = np.array(grad_Q_theta[stop_Q:stop_R])
        
        # for MHE-obj:
        grad_Q_hat_P0 = np.array(dQ_hat_dtheta[start_P0:stop_P0]).reshape((P0.shape[0], P0.shape[1]))
        
        alpha_grad_Q_hat_P0 = self.alpha*grad_Q_hat_P0
        alpha_grad_Q_hat_P0_mat = alpha_grad_Q_hat_P0.reshape((P0.shape[0], P0.shape[1]))
        
        # overwrite learning rate
        if alpha is None:
            alpha_delta_k = self.alpha*float(R_k_plus_1 + diff_Q)
        else:
            alpha_delta_k = alpha*float(R_k_plus_1 + diff_Q)
            
        alpha_delta_grad_Q_P0 = alpha_delta_k*grad_Q_P0
        alpha_delta_grad_Q_Q = alpha_delta_k*grad_Q_Q
        alpha_delta_grad_Q_R = alpha_delta_k*grad_Q_R
        
        grad_Q_P0_mat = grad_Q_P0.reshape((P0.shape[0], P0.shape[1]))
        # try to recover covariance step:
        alpha_delta_grad_Q_P0_mat = alpha_delta_grad_Q_P0.reshape((P0.shape[0], P0.shape[1]))
        alpha_delta_grad_Q_Q_mat = alpha_delta_grad_Q_Q.reshape((Q.shape[0], Q.shape[1]))
        alpha_delta_grad_Q_R_mat = alpha_delta_grad_Q_R.reshape((R.shape[0], R.shape[1]))
        
        # keep Ce sens:
        self.sens.loc[k, :] = np.diag(grad_Q_P0_mat)
        self.sens_Q.loc[k, :] = np.array(grad_Q_Q)
        self.sens_R.loc[k, :] = np.array(grad_Q_R)
        
        #self.sens.loc[k, :] = np.diag(grad_Q_P0_mat)
        self.sens_mhe.loc[k, :] = np.diag(grad_Q_hat_P0)
        
        return alpha_delta_grad_Q_P0_mat, \
               alpha_delta_grad_Q_Q_mat, \
               alpha_delta_grad_Q_R_mat
                
        #except:
        #    return np.zeros((P0.shape[0], P0.shape[1]))
        # times alpha
        # first: create the SDP.
        
        
        #self.sdp = RL_SDP(mpc.dae.n_x, mpc.dae.n_y, mpc.dae.n_p)
        #self.sdp.setup_problem(alpha_delta_grad_Q)
        
        #sol = self.sdp.solve(P0)
        #self.sens_sdp.loc[k, :] = np.diag(sol)
        #sol = None
        #if sol is None:
            #return alpha_delta_grad_Q_mat
            # return 0?
        #    return np.zeros((mpc.dae.n_x + mpc.dae.n_p, mpc.dae.n_x + mpc.dae.n_p))
        #else:
        #    self.sens_sdp.loc[k, :] = np.diag(sol)
            #return sol
        # transform P0 to actual in call:
        #del_theta = self.sdp.solve(np.power(P0, -2))
        
        # filter, such that theta remains pos.def.
        # 
        
        #return alpha_grad_Q_hat_P0_mat
        
        """
        if ((np.array(P0) + alpha_delta_grad_Q_mat + del_P0_accum) >= 0).all():
            
            return alpha_delta_grad_Q_mat
        
        else:
            # if any negative elements of P0, then
            # reset information (less confidence in model):
            #return -P0 + 1e-16
            ndx = np.where((np.array(P0) + alpha_delta_grad_Q_mat + del_P0_accum) < 0)
            alpha_delta_grad_Q_mat[ndx] = 1e-16
            alpha_delta_grad_Q_mat[ndx] -= (np.array(P0)[ndx] + del_P0_accum[ndx])
            return alpha_delta_grad_Q_mat
        """
        
class PolicyGradient(RL):
    def step(self, mpc, mhe, p, Q, R, P0, k, del_P0_accum, alpha=None):
            #self._init_mpc_params(mpc)
        #self._init_mhe_params(mhe, p, Q, R, P0)
        
        ### check if active set has changed ###
        self._init_MHE_sens(mhe)
        #self.set_F_dQ_dz(mpc)
        dQ_dx_init, dQ_dp, dQ_du = self.get_MPC_sens(mpc, mpc.solution)
        #dQ_dp_nlp = self.get_MPC_sens_jsolver(mpc, mpc.solution)
        #dx_init_dtheta, dp_dtheta = self.get_MHE_sens(mhe, mhe.solution, p, Q, R, P0)
        dx_init_dtheta, dp_dtheta = self.get_MHE_sens(mhe, mhe.solution, p, Q, R, P0)
        # sens of MHE objective w.r.t theta:
        dQ_hat_dtheta = self.get_MHE_sens_obj(mhe, mhe.solution)
        
        # get grad(Q)_theta
        #grad_Q_theta = ca.mtimes(dQ_dx_init, dx_init_dtheta) + ca.mtimes(dQ_dp, dp_dtheta)
        grad_Q_theta = dQ_dx_init@dx_init_dtheta + dQ_dp@dp_dtheta
        
        # solve SDP for Δθ
        dim_P0 = P0.shape[0]*P0.shape[1]
        # last elems:
        #start = grad_Q_theta.shape[1] - dim_P0
        #stop = grad_Q_theta.shape[1]
        #grad_Q_P0 = np.array(grad_Q_theta[start:stop])
        # correction: first elems:
        start = 0
        stop = dim_P0
        
        # for MHE-obj:
        grad_Q_hat_P0 = np.array(dQ_hat_dtheta[start:stop]).reshape((P0.shape[0], P0.shape[1]))
        
        grad_Q_P0 = np.array(grad_Q_theta[start:stop])
        
        grad_Q_P0_mat = self.alpha*grad_Q_P0.reshape((P0.shape[0], P0.shape[1]))
        alpha_grad_Q_hat_P0 = self.alpha*grad_Q_hat_P0
        alpha_grad_Q_hat_P0_mat = alpha_grad_Q_hat_P0.reshape((P0.shape[0], P0.shape[1]))
        
        
        # try to recover covariance step:
        #alpha_delta_grad_Q_mat = alpha_delta_grad_Q.reshape((P0.shape[0], P0.shape[1]))
        
        # keep Ce sens:
        self.sens.loc[k, :] = np.diag(grad_Q_P0_mat)
        self.sens_mhe.loc[k, :] = np.diag(alpha_grad_Q_hat_P0_mat)
        # times alpha
        # first: create the SDP.
        
        #return grad_Q_hat_P0

        #self.sdp = RL_SDP(mpc.dae.n_x, mpc.dae.n_y, mpc.dae.n_p)
        #self.sdp.setup_problem(alpha_delta_grad_Q)
        #self.sdp.setup_problem(alpha_grad_Q_hat_P0.reshape((1, P0.shape[0]*P0.shape[1])))
        
        #sol = self.sdp.solve(-(P0 + del_P0_accum))
        #sol = self.sdp.solve(P0 + del_P0_accum)
        #sol = self.sdp.solve(P0 + del_P0_accum)
        #self.sens_sdp.loc[k, :] = np.diag(sol)
        #sol = None
        #if sol is None:
        #    return np.zeros((mpc.dae.n_x + mpc.dae.n_p, mpc.dae.n_x + mpc.dae.n_p))
            #return alpha_delta_grad_Q_mat
            # return 0?
        #else:
        #hess_p_p = self.get_MHE_sens_hsolver(mhe, mhe.solution)
          
        #return alpha_grad_Q_hat_P0_mat
        
        return grad_Q_P0_mat
        
        #    self.sens_sdp.loc[k, :] = np.diag(sol)
            #return sol
        # transform P0 to actual in call:
        #del_theta = self.sdp.solve(np.power(P0, -2))
        
        # filter, such that theta remains pos.def.
        # 
        #grad_Q_P0_mat += grad_Q_hat_P0_mat
        
        #grad_Q_P0_mat = grad_Q_hat_P0_mat
        
        #result = (np.array(P0) - grad_Q_P0_mat - del_P0_accum)
        
        """
        result = (np.array(P0) + grad_Q_P0_mat + del_P0_accum)
        
        if (result >= 0).all():
            
            return grad_Q_P0_mat
        
        else:
            # if any negative elements of P0, then
            # reset information (less confidence in model):
            #return -P0 + 1e-16
            ndx = np.where(result < 0)
            #grad_Q_P0_mat[ndx] = -1e-16
            grad_Q_P0_mat[ndx] = 1e-16
            #grad_Q_P0_mat[ndx] += (np.array(P0)[ndx] + del_P0_accum[ndx])
            grad_Q_P0_mat[ndx] -= (np.array(P0)[ndx] + del_P0_accum[ndx])
            return grad_Q_P0_mat
        """

"""
Define arrival cost weighting matrix P0 as parameter in MHE NLP.

Assemble Lagrangian of the MHE NLP:
    - phi + lambda^T*g
    
where:
    phi: objective function
    g: equality constraints
    lambda: dual variables of NLP
    
Obtain:
    - gradient of Lagrangian w.r.t. primal variables of NLP 'p'.
    
Assemble:
    R = [grad(L)_p, g]
    
Obtain:
    dR/d_theta, where theta = P0 or some regularization thereof

    

nlp = mhe.nlp
g = nlp["g"]
f = nlp["f"]
p = nlp["p"]
x = nlp["x"]

_p = mhe.costate_prior # new name, e.g. z?
_Q = mhe.Q_sqrt_inv
_R = mhe.R_sqrt_inv

# assemble Lagrangian:
lambd = ca.MX.sym("lambda", g.shape[0]) # symbolic duals for equality constraints
mu = ca.MX.sym("mu", x.shape[0]) # ------""------ inequality constraints
L = f - ca.mtimes(lambd.T, g) - ca.mtimes(mu.T, x)  # lagrangian
#L = f
dL_dp_expr = ca.gradient(L, p)

R_theta = ca.vertcat(dL_dp_expr, g)

# want dR_theta/d_theta as expression:
dR_theta_d_theta = ca.jacobian(R_theta, p)







# covar needs to be symbolic:

dL_dp = ca.Function("dL_dp", [x, lambd, mu, p], [dL_dp_expr])

p_val = ca.veccat(ca.sqrt(ca.inv(P0)), ca.veccat(Q, R), ca.vertcat(params, x_N))
# test evaluation:
test = dL_dp(mhe.solution["x"], mhe.solution["lam_g"], mhe.solution["lam_x"], p_val)

_P0_own = np.array(test[:_p.shape[0]*_p.shape[0]]).reshape((_p.shape[0], _p.shape[0]))
_P0_cas = np.array(mhe.solution["lam_p"][:_p.shape[0]*_p.shape[0]]).reshape((_p.shape[0], _p.shape[0]))

#dP0_dp = scipy.linalg.fractional_matrix_power(_P0_cas, 1.5)
#dP0_dp = scipy.linalg.fractional_matrix_power(_P0_own, 1.5)

solver = mhe.solver
sol = mhe.solution   
lbw = mhe.lbx         
ubw = mhe.ubx         
lbg = 0
ubg = 0

# jacobian:
jsolver = solver.factory('g', solver.name_in(), ['jac:f:p'])
print('hsolver generated')
jsol = jsolver(x0=sol['x'], lam_x0=sol['lam_x'], lam_g0=sol['lam_g'],
            lbx=lbw, ubx=ubw, lbg=lbg, ubg=ubg, p=p_val)
print('Jacobian of f w.r.t. p:')
print(jsol['jac_f_p'])

# hessian:                    
hsolver = solver.factory('h', solver.name_in(), ['sym:hess:f:p:p'])
print('hsolver generated')
hsol = hsolver(x0=sol['x'], lam_x0=sol['lam_x'], lam_g0=sol['lam_g'],
            lbx=lbw, ubx=ubw, lbg=lbg, ubg=ubg, p=p_val)
print('Hessian of f w.r.t. p:')
print(hsol['sym_hess_f_p_p'])
"""
