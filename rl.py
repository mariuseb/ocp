import cvxpy as cp
import numpy as np
import casadi as ca
from abc import ABC, abstractmethod, ABCMeta
from ocp.rl_sdp import RL_SDP
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
        self.set_F_dQ_dz(mpc)
        self._init_MHE_sens(mhe)
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
        self.dim_x = mpc.dae.n_x
        self.dim_p = mpc.dae.n_p
        
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
        self.inact_x_inds  = np.array([mhe.lbx < mhe.solution["x"]], dtype=bool).flatten()
        
        #x_map = {ndx: w_hat[ndx] for ndx, val in enumerate(inact_x) if not val}
        #h_active_inds = ca.DM([ndx for ndx if not()])
        h_active = ca.vertcat(*[w_hat[ndx] for ndx, val in enumerate(self.inact_x_inds) if not val])
        # no g yet:
        #inact_g = np.array([mhe.lbx < mhe.solution["x"]], dtype=bool).flatten()
        
        self.mu_hat = mu_hat = ca.MX.sym("mu_hat", h_active.shape[0]) # ------""------ inequality constraints
        L = f - ca.mtimes(lambda_hat.T, g) - ca.mtimes(mu_hat.T, h_active)  # lagrangian
        #L = f
        # z_hat: (w_hat, lambda_hat, mu_hat):
        self.z_hat = z_hat = ca.vertcat(w_hat, lambda_hat, mu_hat)
        
        grad_L_w = ca.jacobian(L, w_hat) # transpose this
        
        hess_L_w = ca.hessian(L, w_hat)[0]

        R = ca.vertcat(grad_L_w.T, g, h_active)
        
        # params:
        theta = ca.veccat(_p, _Q, _R, _P0)
        dR_dtheta = ca.jacobian(R, theta)
        
        self.dR_dtheta_func = ca.Function("dRdTheta", [theta, z_hat], [dR_dtheta], ["theta", "z_hat"], ["dR_dtheta"])
        
        self.jac_g_w = ca.jacobian(g, w_hat)
        self.jac_h_w = ca.jacobian(h_active, w_hat)
        
        n_hess = hess_L_w.shape[0]
        n_jac_g_w = self.jac_g_w.shape[0]
        n_jac_h_w = self.jac_h_w.shape[0]
        
        self.n_KKT = n_hess + n_jac_g_w + n_jac_h_w
        
        # END
        
        #KKT_symbolic = ca.MX.sym("KKT", n_KKT, n_KKT)
        
        # set the functions:
        self.R_func = ca.Function("R", [z_hat, _p, _Q, _R, _P0], [R], ["z_hat", "p", "Q", "R", "P0"], ["R"])
        self.hess_L = ca.Function("hess_L", [w_hat, _p, _Q, _R, _P0, lambda_hat], [hess_L_w], ["w_hat", "p", "Q", "R", "P0", "lambda_hat"], ["hess_L_w"])
        self.J_g_w = ca.Function("JgW", [w_hat, _p, _Q, _R, _P0, lambda_hat], [self.jac_g_w], ["w_hat", "p", "Q", "R", "P0", "lambda_hat"], ["jac_g_w"])
        self.J_h_w = ca.Function("JhW", [w_hat, _p, _Q, _R, _P0, mu_hat], [self.jac_h_w], ["w_hat", "p", "Q", "R", "P0", "mu_hat"], ["jac_h_w"])
        
        # mhe params fixed in this call:
        
    def get_MHE_sens(self, sol, p_val, Q_val, R_val, P0_val):
        
        # refs:
        w_hat = self.w_hat
        jac_g_w = self.jac_g_w
        jac_h_w = self.jac_h_w
        mu_hat = self.mu_hat
        
        
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
        hess_L_val = self.hess_L(sol["x"], p_val, Q_val, R_val, P0_val, sol["lam_g"])
        jac_g_w_val = self.J_g_w(sol["x"], p_val, Q_val, R_val, P0_val, sol["lam_g"])
        jac_h_w_val = self.J_h_w(sol["x"], p_val, Q_val, R_val, P0_val, mu_val)
        
        # test dR_dtheta:
        dR_dtheta_val = self.dR_dtheta_func(ca.veccat(p_val, Q_val, R_val, P0_val), z_hat_val)
        
        
        # try to construct simplified KKT-matrix:
        #KKT_num = ca.DM.zeros(self.n_KKT, self.n_KKT)
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
        
        
        
        # set hessian
        KKT_num[L_start:L_stop, L_start:L_stop] = np.array(hess_L_val)
        # set jac_G:
        KKT_num[G_start_row:G_stop_row, G_start_col:G_stop_col] = np.array(jac_g_w_val)
        # set the transpose of jac_G (grad_G):
        KKT_num[L_start:L_stop, GT_start_col:GT_stop_col] = np.array(jac_g_w_val.T)
        # set jac_H:
        KKT_num[H_start_row:H_stop_row, H_start_col:H_stop_col] = np.array(jac_h_w_val)
        # set the transpose of jac_H (grad_H):
        KKT_num[L_start:L_stop, HT_start_col:HT_stop_col] = np.array(jac_h_w_val.T)
        
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
        
        
        
    def set_F_dQ_dz(self, mpc):
        """
        Set the function for obtaining:
            * ∂Q/∂w
        """
        nlp = mpc.nlp
        g = nlp["g"]
        _lambda_hat = ca.MX.sym("lambda", g.shape[0])
        # lagrangian of MPC-NLP:
        L = nlp["f"] - ca.mtimes(_lambda_hat.T, g)
        # primal:
        w = nlp["x"]
        # primal-dual:
        z = ca.vertcat(w, _lambda_hat)
        # take gradient:
        dL_dw = ca.gradient(L, z)
        # set as function:
        self.F_dL_dw = ca.Function("FdLdw", [z], [dL_dw])
        
    
    def get_dQ_dx0(self, dQ_dz):
        return dQ_dz[self.x_bounds["a"]:(self.x_bounds["a"] + self.dim_x)]
        
    def get_dQ_dp(self, dQ_dz):
        return dQ_dz[self.p_bounds["a"]:self.p_bounds["b"]]
    
    def get_MPC_sens(self, sol):
        """
        Get sensitivities
        from MPC problem.
    
        """
        z_val = ca.vertcat(sol["x"], sol["lam_g"])
        dQ_dz = self.F_dL_dw(z_val)
        
        return self.get_dQ_dx0(dQ_dz).T, self.get_dQ_dp(dQ_dz).T
    
    def step(self, mpc, mhe, p, Q, R, P0, diff_Q, L_k):
        #self._init_mpc_params(mpc)
        #self._init_mhe_params(mhe, p, Q, R, P0)
        self._init_MHE_sens(mhe)
        self.set_F_dQ_dz(mpc)
        dQ_dx_init, dQ_dp = self.get_MPC_sens(mpc.solution)
        dx_init_dtheta, dp_dtheta = self.get_MHE_sens(mhe.solution, p, Q, R, P0)
        
        # get grad(Q)_theta
        #grad_Q_theta = ca.mtimes(dQ_dx_init, dx_init_dtheta) + ca.mtimes(dQ_dp, dp_dtheta)
        grad_Q_theta = dQ_dx_init@dx_init_dtheta + dQ_dp@dp_dtheta
        
        # solve SDP for Δθ
        dim_P0 = P0.shape[0]*P0.shape[1]
        # last elems:
        start = grad_Q_theta.shape[1] - dim_P0
        stop = grad_Q_theta.shape[1]
        grad_Q_P0 = np.array(grad_Q_theta[start:stop])
        
        alpha_delta_k = self.alpha*float(L_k + diff_Q)
        alpha_delta_grad_Q = alpha_delta_k*grad_Q_P0
        
        # try to recover covariance step:
        alpha_delta_grad_Q_mat = alpha_delta_grad_Q.reshape((P0.shape[0], P0.shape[1]))
        
        
        # times alpha
        # first: create the SDP.
        #self.sdp = RL_SDP(mpc.dae.n_x, mpc.dae.n_y, mpc.dae.n_p)
        #self.sdp.setup_problem(alpha_delta_grad_Q)
        
        #sol = self.sdp.solve(P0)
        
        #if sol is None:
        return alpha_delta_grad_Q
        #else:
        #return sol
        # transform P0 to actual in call:
        #del_theta = self.sdp.solve(np.power(P0, -2))
        
        #return alpha_delta_grad_Q
    
    def solve_SDP():
        pass
    
class Qlearning(RL):
    pass
        


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
