import cvxpy as cp
import numpy as np
from ocp.param_est import ParameterEstimation
#import pandas as pd
#import os
#from ocp.tests.utils import get_data_path
#import mosek
import numpy as np
import cvxpy as cp
import pandas as pd
from ocp.filters import KalmanBucy, KalmanDAE
import casadi as ca
from ocp.estimation import Estimation
#from scipy.linalg import expm


class CovarianceSolverContinuous(object):
    """
    Given residuals v, w,
    solve for covariance
    matrices Q, R.
    """
    def __init__(
                 self,
                 ekf_config,
                 param_est_cfg,
                 y_data,
                 param_guess,
                 **kwargs
                 ):
        self.p_nom = kwargs.pop("p_nom", 1)
        self.P_nom = np.array(kwargs.pop("P_nom", 1))
        self.setup_problem(
                           ekf_config,
                           param_est_cfg,
                           y_data,
                           param_guess,
                           **kwargs
                           )
        
    def solve(self,
              y_data,
              params,
              x_guess,
              P_guess,
              Q_guess,
              R_guess
              ):
        """
        Solve covariance estimation 
        optimization problem.
        
        TODO: modularize depending
        on shooting method.
        """
        param_est = self.param_est
        M = self.M
        # construct numerical bounds for ll-opt:
        p_val = np.concatenate([
            y_data[param_est.u_names][0:M].values.flatten(),
            y_data[param_est.r_names][0:M].values.flatten(),
            params/self.p_nom, # physical parameters
            y_data[param_est.y_names][0:M].values.flatten(),
            y_data[param_est.z_names][0:M].values.flatten(),
        ])
        # bounds for x0_guess:
        lbx0 = 1*x_guess
        ubx0 = 1*x_guess
        
        P_nom_flat = self.P_nom_flat = np.tile(self.P_nom.flatten(), self.M+1)
        P_guess = P_guess/P_nom_flat
        # concatenate variable guesses in correct order:
        x0 = np.concatenate([
                              x_guess,
                              P_guess,
                              Q_guess, 
                              R_guess
                              ])
        # TODO: modularize depending on sign:
        """
        lbx = np.concatenate([
                              lbx0,
                              1E-2*P0_guess,
                              50*Q_guess,
                              50*R_guess
                              ])
        ubx = np.concatenate([
                              ubx0, 
                              1E2*P0_guess,
                              -10*Q_guess,
                              -10*R_guess
                              ])
        """
        lbx = np.concatenate([
                              0.5*lbx0,
                              1E-3*P_guess,
                              10*Q_guess,
                              #1*Q_guess,
                              10*R_guess
                              ])
        ubx = np.concatenate([
                              1.5*ubx0, 
                              1E3*P_guess,
                              -10*Q_guess,
                              #1*Q_guess,
                              -10*R_guess
                              ])
        
        _sol = self.ll_solver(
                              x0=x0,
                              lbx=lbx,
                              ubx=ubx,
                              ubg=self.ubg,
                              lbg=self.lbg,
                              p=p_val
                              )
        self.sol = _sol
        """
        Q = np.diag(np.array([_sol["x"][-5], _sol["x"][-2]]).flatten())
        P0 = np.diag(np.array([_sol["x"][2], _sol["x"][5]]).flatten())
        R = np.diag(np.array([_sol["x"][-1]]).flatten())
        x0 = np.array([_sol["x"][0:2]]).flatten()
        ny = self.ekf.dae.n_y
        ntheta = self.ekf.dae.n_theta
        
        # order: X,P,Q,R
        """ 
        # TODO: results parsing
        sol = pd.DataFrame()
        if self.method == "multiple_shooting":
            N = (self.M+1)
        else:
            N = 1
            
        # extract x
        x_start = 0
        x_stop = N*self.ekf.n_x
        P_start = x_stop
        P_stop = x_stop + N*self.ekf.n_x**2
        sol_x = _sol["x"][x_start:x_stop]
        # to array:        
        x = np.array(sol_x).reshape((N, self.ekf.n_x))
        # store:
        sol[self.x] = x
        # P_cols:
        P_cols = [
                "p" + str(j) + str(i)
                for j in range(1, self.n_x+1)
                for i in range(1, self.n_x+1)
                ]
        sol_P = _sol["x"][P_start:P_stop]
        P = np.array(sol_P).reshape((N, self.ekf.n_x**2))
        sol[P_cols] = P*self.P_nom.flatten()
        # Q
        Q_start = -self.n_theta - self.n_y
        Q_stop = Q_start + self.n_x**2
        # how many Q's?
        nQs = int(self.n_theta/(self.n_x**2))
        # Q_cols:
        Q_cols = [
                "q" + str(j) + str(i)
                for j in range(1, self.n_x+1)
                for i in range(1, self.n_x+1)
                ]
        Q_df = pd.DataFrame(columns=Q_cols)
        for n in range(nQs):
            Q_df.loc[n] =  np.array(_sol["x"][Q_start:Q_stop]).flatten()
            Q_start += self.n_x**2
            Q_stop += self.n_x**2
        
        R = np.array(_sol["x"][-self.n_y:])
        
        return sol, Q_df, R
        
        
    def setup_problem(
                      self,
                      ekf_config,
                      param_est_cfg,
                      y_data,
                      param_guess,
                      **kwargs,
                      ):
        """
        Setup covariance estimation problem.
        Use continuous-time Lyapnuov equation & 
        Kalman filter to evolve covariance
        along estimated trajectory, using
        fixed physical parameters from smoothing 
        problem.
        
        Target:
            - Be exact
        """
        N = len(y_data)
        try:
            dt = (y_data.index[1] - y_data.index[0]).seconds
        except: # RangeIndex
            dt = (y_data.index[1] - y_data.index[0])
            
        self.param_est = param_est = Estimation(config=param_est_cfg,
                                                N=N,
                                                dt=dt,
                                                param_guess=param_guess,
                                                arrival_cost=True,
                                                **kwargs,
                                                )
        self.ekf = ekf = KalmanBucy(ekf_config)
        F = ekf.one_sample_feedback_adj
        self.M = M = param_est.N - 1
        
        self.method = method = kwargs.pop("method", "single_shooting")
        
        # set up optimization problem:
        # set up variables:
        Z = ca.MX.sym("Z", (ekf.n_z, M))
        U = ca.MX.sym("U", (ekf.n_u, M))
        r = ca.MX.sym("r", (ekf.n_r, M))
        p = ca.MX.sym("p", ekf.n_p)
        Y = ca.MX.sym("Y", (ekf.n_y, M))
        # start with non-tvp Q, R
        #Q = ca.MX.sym("Q", ca.Sparsity.diag(ekf.n_x))
        #R = ca.MX.sym("R", ca.Sparsity.diag(ekf.n_y))
        #Q = ca.MX.sym("Q", (ekf.n_x, ekf.n_x))
        Q_mxs = ekf.reinit_symbolic_Q()
        Q = ca.veccat(*Q_mxs)
        # TODO: concat Q, Q_1, ... ,Q_N
        R = ca.MX.sym("R", (ekf.n_y, ekf.n_y))
        
        if method == "single_shooting":
            F_map = F.mapaccum(
                            "kalman_simulator",
                            M,
                            [0,1],
                            [3,7]
                            )
            # accumulate differential variables:
            X = X0 = ca.MX.sym("X0", (ekf.n_x, 1))
            P = P0 = ca.MX.sym("P", (ekf.n_x, ekf.n_x))
        elif method == "multiple_shooting":
            # do not want to accumulate:
            F_map = F.map(M, "openmp")
            # differential variables defined
            # on each time step:
            X = ca.MX.sym("X", (ekf.n_x, N))
            X0 = X[:,:-1]
            # TODO: modify this:
            P = ca.MX.sym("P", (ekf.n_x, N*ekf.n_x))
            P0 = P[:,:-ekf.n_x]


        W = ekf.one_sample_wiener
        # propagate dynamics through wiener process:
        _P0 = W(
            P0=0,
            z0=Z[:,:1],
            r=r[:,:1],
            p=self.p_nom*p,
            y=Y[:,:1],
            x0=X[:,:1],
            u=U[:,:1],
            Ps=1,
            sigma=ekf.Q_function(Q, U[:,:1]),
            dt=ekf.dt
        )["P"]
       
        # propagate through kalman simulator:
        res = F_map(
            x_0=X0,
            #z_0=Z,
            #P_0=P[:, :-end_P],
            P_0=self.P_nom*P0,
            #P_prev=P,
            u=U,
            r=r,
            p=self.p_nom*ca.repmat(p,1,M),
            y=Y,
            Q=ca.repmat(Q,1,M),
            R=ca.repmat(R,1,M),
            #dt=300
        )
        
        # for objective function:
        #V_N = res["V_k"]
        #e_N = res["e_k"]
        # for shooting constraints:
        loglik = res["loglik"]
        # TODO: shooting constraints:

        obj = 0
        for n in range(M): # only 1-dim:
            obj += loglik[n]
            
        # problem parameters:
        _p = ca.veccat(U,r,p,Y,Z)
        # problem variables
        V = ca.veccat(X,P,Q,R)
        #g = ca.vertcat(x_constr, P_constr, Q[1,0], Q[0,1])
        # add constraints on off-diagonal elems for Q:
        """
        Extract off-diagonal matrices of Q:
        """
        Q_off_diag = []
        nx = ekf.dae.n_x
        for q in Q_mxs:
            for i in range(nx):
                for j in range(nx):
                    if j != i:
                        Q_off_diag.append(q[i,j])
                        
        g = []
        if method == "multiple_shooting":
            P_10 = res["P_10"]
            x_10 = res["x_10"]
            # shooting gaps:
            x_constr = ca.veccat(x_10 - X[:, 1:])
            P_constr = ca.veccat(P_10 - self.P_nom*P[:, ekf.n_x:])
            # add to constraints:
            g.append(x_constr)
            g.append(P_constr)
         
        P0_constr = ca.veccat(self.P_nom*P[:, :ekf.n_x] - _P0)
        g.append(P0_constr)
        g.extend(Q_off_diag)
        #g = ca.vertcat(*Q_off_diag) 
        g = ca.vertcat(*g)
        #self.lbg = np.ones(g.shape[0])*-1000
        #self.ubg = np.ones(g.shape[0])*1000
        self.lbg = np.zeros(g.shape[0])
        self.ubg = np.zeros(g.shape[0])
        
        ll_nlp = {
            "f": obj,
            "x": V,
            "g": g,
            "p": _p
        }
        opts = param_est.opt
        #opts["ipopt.tol"] = 1e-10
        opts["verbose"] = False
        opts["ipopt.linear_solver"] = "ma57"
        opts["ipopt.tol"] = 3e-5
        opts["ipopt.ma57_pre_alloc"] = 10
        opts["ipopt.ma57_automatic_scaling"] = "yes"
        self.ll_solver = ca.nlpsol("ll_solver",  "ipopt", ll_nlp, opts)
        
    @property
    def n_x(self):
        return self.ekf.n_x
    
    @property
    def x(self):
        return self.ekf.dae.x
    
    @property
    def n_y(self):
        return self.ekf.n_y
    
    @property
    def n_u(self):
        return self.ekf.n_u

    @property
    def n_r(self):
        return self.ekf.n_r
    
    @property
    def n_theta(self):
        return self.ekf.dae.n_theta