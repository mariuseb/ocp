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
#from scipy.linalg import expm


class CovarianceSolver(object):
    """
    Given residuals v, w,
    solve for covariance
    matrices Q, R.
    """
    def __init__(
                 self,
                 N: int,
                 A: np.array,
                 C: np.array,
                 parametric=False,
                 **kwargs
                 ):
        
        self.N = N
        self.A = A
        self.C = C
        self.parametric = parametric
        if parametric:
            self.setup_problem_parametric(N)
        else:
            e = kwargs.pop("e")
            self.setup_problem(N, e)
            
        
    def setup_problem(self, N, e):
        """
        Setup covariance estimation problem.
        Use discrete-time Lyapnuov equation,
        Kalman filter to estimate covariance
        along optimized trajectory.
        
        Target:
            - Find target matrices Q, R
            that maximizes the likelihood
            of the obtained trajectory x_hat.
        """
        
        A = self.A
        C = self.C
        
        self.nx = nx = A.shape[0]
        self.ny = ny = np.count_nonzero(C)
        
        self.constr = constr = []
        self.Q = Q = cp.Variable((nx, nx), PSD=True)
        self.R = R = cp.Variable((ny, ny), PSD=True)
        
        # constrain off-diagonals to zero:
        for i in range(nx):
            for j in range(nx):
                if i != j:
                    constr += [Q[i,j] == 0]
        # positive elements on diagonal for R:
        for i in range(ny):
            constr += [R[i,i] >= 0]
            
        # state covariances
        Ps = []
        P = cp.Variable((nx, nx), PSD=True)
        Ps.append(P)
        
        # output/innovation information matrices:
        Ss = []
        # objective:
        cost = 0
        
        for t in range(N-1):
            #cost += cp.sum_squares(x[:, t + 1]) + cp.sum_squares(u[:, t])
            P = cp.Variable((nx, nx), PSD=True)
            Ps.append(P)
            S = cp.Variable((ny, ny), PSD=True)
            Ss.append(S)
            constr += [Ps[t+1] == A @ Ps[t] @ A.T + Q]
            constr += [Ss[t] == C.T @ Ps[t+1] @ C + R]
            """
            Use matrix fraction:
            
                cp.matrix_frac(x, P)
                (x^T @ P^-1 @ x)
                
            where P is a variable
            and x problem data.
            """
            E = e[t,:].reshape((ny, 1))
            sub_expr = cp.log_det(S) - E.T @ S @ E
            cost += sub_expr
            
        self.problem = cp.Problem(cp.Maximize(cost), constr)
        
    def setup_problem_parametric(self, N):
        """
        Setup covariance estimation problem.
        Use discrete-time Lyapnuov equation,
        Kalman filter to estimate covariance
        along optimized trajectory.
        
        Target:
            - Find target matrices Q, R
            that maximizes the likelihood
            of the obtained trajectory x_hat.
        """
        
        A = self.A
        C = self.C
        
        self.nx = nx = A.shape[0]
        self.ny = ny = np.count_nonzero(C)
        
        self.constr = constr = []

        self.Q = Q = cp.Variable((nx, nx), PSD=True)
        self.R = R = cp.Variable((ny, ny), PSD=True)
        
        # constrain off-diagonals to zero:
        for i in range(nx):
            for j in range(nx):
                if i != j:
                    constr += [Q[i,j] == 0]
        # positive elements on diagonal for R:
        for i in range(ny):
            constr += [R[i,i] >= 0]
        
        # state covariances
        Ps = []
        P = cp.Variable((nx, nx), PSD=True)
        Ps.append(P)
        
        # output/innovation information matrices:
        Ss = []
        # objective:
        cost = 0
        #S = cp.Variable((ny*N, ny*N), PSD=True)
        self.Es = Es = []
        
        for t in range(N-1):
            #cost += cp.sum_squares(x[:, t + 1]) + cp.sum_squares(u[:, t])
            P = cp.Variable((nx, nx), PSD=True)
            Ps.append(P)
            S = cp.Variable((ny, ny), PSD=True)
            Ss.append(S)
            #s = S[t:t+ny, t:t+ny]
            
            constr += [Ps[t+1] == A @ Ps[t] @ A.T + Q]
            constr += [S == C.T @ Ps[t+1] @ C + R]
        
            E = cp.Parameter((ny, ny))
            sub_expr = cp.log_det(S) - cp.trace(S @ E)
            cost += sub_expr
            Es.append(E)
        
        self.problem = cp.Problem(cp.Maximize(cost), constr)
    """
    def setup_problem_parametric(self, N):
    """
    Setup covariance estimation problem.
    Use discrete-time Lyapnuov equation,
    Kalman filter to estimate covariance
    along optimized trajectory.
    
    Target:
        - Find target matrices Q, R
        that maximizes the likelihood
        of the obtained trajectory x_hat.
    """
    
    A = self.A
    C = self.C
    
    self.nx = nx = A.shape[0]
    self.ny = ny = np.count_nonzero(C)
    
    self.constr = constr = []

    self.Q = Q = cp.Variable((nx, nx), PSD=True)
    self.R = R = cp.Variable((ny, ny), PSD=True)
    
    # constrain off-diagonals to zero:
    for i in range(nx):
        for j in range(nx):
            if i != j:
                constr += [Q[i,j] == 0]
    # positive elements on diagonal for R:
    for i in range(ny):
        constr += [R[i,i] >= 0]
    
    # state covariances
    Ps = []
    P = cp.Variable((nx, nx), PSD=True)
    Ps.append(P)
    
    # output/innovation information matrices:
    Ss = []
    # objective:
    cost = 0
    #S = cp.Variable((ny*N, ny*N), PSD=True)
    #self.Es = Es = []
    
    self.E = E = cp.Parameter((ny*N, ny*N))
    self.S = S = cp.Variable((ny*N, ny*N), PSD=True)
    self.inds = inds = range(ny*N)
    
    start = 0
    for t in range(N-1):
    #cost += cp.sum_squares(x[:, t + 1]) + cp.sum_squares(u[:, t])
    P = cp.Variable((nx, nx), PSD=True)
    Ps.append(P)
    #Ss.append(S)
    #s = S[t:t+ny, t:t+ny]
    """
    Discrete-time Lyapunov equation:
    
        P_k = A_k @ P_k-1 @ A_k^T + Q
        
    """
    constr += [Ps[t+1] == A @ Ps[t] @ A.T + Q]
    start += ny
    stop = start + ny
    sub_inds = range(start,stop)
    compl = [ndx for ndx in inds if ndx not in sub_inds]
    s = S[start:stop,start:stop]
    """
    Set off-diagonal to zero on S.
    Same for E.
    """
    for ndx in compl:
        constr += [S[start:stop,ndx] == 0]
        #E[start:stop,ndx].value = 0
        #constr += [E[start:stop,ndx] == 0]
    # set rest of here to zero by constraint:
    """
    Output covariance:
    
        S_k = C.T @ P_k @ C + R
    """
    constr += [s == C.T @ Ps[t+1] @ C + R]
            
    cost = cp.log_det(S) - cp.trace(S @ E)
    self.problem = cp.Problem(cp.Maximize(cost), constr)
    """            
        
    def solve(self, \
              e=None,
              warmstart=False,
              **kwargs):
        """
            e: measurement residual.
        """
        if self.parametric:
            assert e is not None
            for i, E in enumerate(self.Es):
                error = e[i,:].reshape((self.ny, 1))
                E.value = error @ error.T
        
        if warmstart:
            self.R.value = kwargs.pop("R", np.diag([1]*self.ny))
        
        self.problem.solve(solver=cp.SCS,
                           max_iters=int(1e4),
                           use_indirect=True,
                           warm_start=warmstart,
                           verbose = True)
        
        R_hat = self.R.value
        Q_hat = self.Q.value
    
        R_hat = np.diag(np.diag(R_hat))
        Q_hat = np.diag(np.diag(Q_hat))
        
        return R_hat, Q_hat
            
    def solve(self, \
              e=None,
              warmstart=False,
              **kwargs):
        """
            e: measurement residual.
        """
        if self.parametric:
            
            assert e is not None
            ny = self.ny
            self.E.value = e
            
            """
            for t in range(self.N-1):     
                sub_inds = range(t,t+ny)
                start, stop = sub_inds[0], sub_inds[-1]
                # square error to get smaple covariance:
                error = e[t,:].reshape((ny, 1))
                E_value = error @ error.T
                # set value on parameter:
                E[start:stop,start:stop].value = E_value
                compl = [ndx for ndx in inds if ndx not in sub_inds]
            for ndx in compl:
                E[start:stop,ndx].value = 0
            """
        
        if warmstart:
            self.R.value = kwargs.pop("R", np.diag([1]*self.ny))
        
        self.problem.solve(solver=cp.SCS,
                           max_iters=int(1e4),
                           use_indirect=True,
                           warm_start=warmstart,
                           verbose = True)
        
        R_hat = self.R.value
        Q_hat = self.Q.value
    
        R_hat = np.diag(np.diag(R_hat))
        Q_hat = np.diag(np.diag(Q_hat))
        
        return R_hat, Q_hat
            
    def get_n_x(self, w):
        return w.shape[0]
    
    def get_n_y(self, v):
        return v.shape[0]
