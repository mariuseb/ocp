import cvxpy as cp
import numpy as np
#import pandas as pd
#import os
#from ocp.tests.utils import get_data_path
#import mosek

"""
class CovarianceSolver(object):

    def __init__(
                 self,
                 v: np.array,
                 w: np.array
                 ):
        
        self.w = w
        self.v = v
        self.n_x = self.get_n_x(w)
        self.n_y = self.get_n_y(v)
        self.setup_problem()
        
    def setup_problem(self):
        # vars:
        self.Q = Q = cp.Variable((self.n_x, self.n_x), symmetric=True)
        self.R = R = cp.Variable((self.n_y, self.n_y), symmetric=True)
        # constraints.
        constraints = [Q >> 0]
        constraints += [R >> 0]
        
        for i in range(self.n_x):
            for j in range(self.n_x):
                if i != j:
                    constraints += [Q[i,j] == 0]

        for i in range(self.n_y):
            for j in range(self.n_y):
                if i != j:
                    constraints += [R[i,j] == 0]
                    
        self.prob = cp.Problem(cp.Minimize(
                                           cp.matrix_frac(self.w, Q) + cp.matrix_frac(self.v, R)
                                          ), # + cp.log_det(Q)),
                               constraints)
        
    def solve(self, \
              warmstart=False,
              **kwargs):
        
        if warmstart:
            self.R.value = kwargs.pop("R")
            self.Q.value = kwargs.pop("Q")
        
        self.prob.solve(method='cpg',
                        #solver=cp.SCS
                        #mosek_params = 
                        #    {
                        #     mosek.dparam.optimizer_max_time: 1000.0,
                        #     mosek.iparam.intpnt_solve_form: mosek.solveform.dual
                        #    },
                        #save_file = 'dump.opf',
                        warm_start=True,
                        verbose = True)
        
        return self.R.value, self.Q.value
            
    def get_n_x(self, w):
        return w.shape[0]
    
    def get_n_y(self, v):
        return v.shape[0]
"""

class CovarianceSolver(object):
    """
    Given residuals v, w,
    solve for covariance
    matrices Q, R.
    """
    def __init__(
                 self,
                 v: np.array,
                 w: np.array,
                 alpha=10000
                 ):
        
        self.w = w
        self.v = v
        self.n_x = self.get_n_x(w)
        self.n_y = self.get_n_y(v)
        self.alpha = alpha
        self.setup_problem()
        
    def setup_problem(self):
        # vars:
        self.S = S = cp.Variable(shape=(self.n_y, self.n_y), PSD=True)
        self.P = P = cp.Variable(shape=(self.n_x, self.n_x), PSD=True)

        # constraints.
        #constraints = [Q >> 0]
        #constraints += [R >> 0]
        
        V = np.cov(self.v)
        W = np.cov(self.w)
        
        if V.shape == (): # scalar
            S_term = cp.log_det(S) - cp.trace(S*V)
        else:
            S_term = cp.log_det(S) - cp.trace(S@V)
        
        if W.shape == (): # scalar
            P_term = cp.log_det(P) - cp.trace(P*W)
        else:
            P_term = cp.log_det(P) - cp.trace(P@W)
            
            
        obj = cp.Maximize(S_term + P_term)
        
        
        #constraints = [cp.sum(cp.abs(S)) <= self.alpha]
        #constraints += [cp.sum(cp.abs(P)) <= self.alpha]
        
        # impose diagonality:
        
        for i in range(self.n_x):
            for j in range(self.n_x):
                if i != j:
                    try:
                        constraints += [P[i,j] == 0]
                    except UnboundLocalError:
                        constraints = [P[i,j] == 0]

        for i in range(self.n_y):
            for j in range(self.n_y):
                if i != j:
                    constraints += [S[i,j] == 0]
                    
        self.prob = cp.Problem(obj, constraints)
        
    def solve(self, \
              warmstart=False,
              **kwargs):
        
        if warmstart:
            self.S.value = np.linalg(kwargs.pop("R"))
            self.P.value = np.linalg(kwargs.pop("Q"))
        
        self.prob.solve(solver=cp.SCS,
                        #mosek_params = 
                        #    {
                        #     mosek.dparam.optimizer_max_time: 1000.0,
                        #     mosek.iparam.intpnt_solve_form: mosek.solveform.dual
                        #    },
                        #save_file = 'dump.opf',
                        warm_start=warmstart,
                        verbose = True)
        
        R_hat = np.linalg.inv(self.S.value)
        Q_hat = np.linalg.inv(self.P.value)
        
        #R_hat[abs(R_hat) <= 1e-4] = 0
        #Q_hat[abs(Q_hat) <= 1e-4] = 0
        R_hat = np.diag(np.diag(R_hat))
        Q_hat = np.diag(np.diag(Q_hat))
        
        return R_hat, Q_hat
            
    def get_n_x(self, w):
        return w.shape[0]
    
    def get_n_y(self, v):
        return v.shape[0]

# own problem:
"""
w1 = sol.w1.values
w2 = sol.w2.values

w = np.vstack([w1,w2])

n_x = 2
n_y = 1 
N = len(sol) - 1

Q = cp.Variable((n_x, n_x), symmetric=True)
R = cp.Variable((n_y, n_y), symmetric=True)

#Z = cp.Variable((n,n), symmetric=True)
#t = cp.Variable((1,1))

#constr_matrix = cp.Variable((2*n, 2*n), symmetric=False)
#constr_matrix[0:2, 0:2] = Q
#constr_matrix[0:2, 2:4] = Z
#constr_matrix[2:4, 0:2] = Z.T
#constr_matrix[2:4, 2:4] = cp.diag(Z)

#constraints = [Q >> 0]
#constraints += [constr_matrix[0:2, 0:2] == Q]
#constraints += [constr_matrix[0:2, 2:4] == Z]
#constraints += [constr_matrix[2:4, 0:2] == Z.T]
#constraints += [constr_matrix[2, 2] == cp.diag(Z)[0]]
#constraints += [constr_matrix[3, 3] == cp.diag(Z)[1]]

#constraints += [constr_matrix >= 0]

# Z is lower triangular:
#constraints += [Z[0,1] == 0]
#constraints += [t >= (cp.log(Z[0,0]) + cp.log(Z[1,1]))]

constraints = [Q >> 0]
#constraints += [R >> 0]
#constr_matrix = np.array([[Q, Z], [Z.T, cp.diag(Z)]])
#constraints += [constr_matrix <= 0]

# off-diagonal elements to zero.
for i in range(n_x):
    for j in range(n_x):
        if i != j:
            constraints += [Q[i,j] == 0]

for i in range(n_y):
    for j in range(n_y):
        if i != j:
            constraints += [R[i,j] == 0]
            #constraints += [Q[i,j] == 0]

#prob = cp.Problem(cp.Minimize(cp.matrix_frac(w, Q) + t), # + cp.log_det(Q)),
#                 constraints)
prob = cp.Problem(cp.Minimize(cp.matrix_frac(w, Q)), # + cp.log_det(Q)),
                 constraints)
prob.solve(verbose=True)
print("The optimal value is", prob.value)
print("A solution Q is")
print(Q.value)
#constraints += [Q[i, j] == Q[j, i] if 
#                for i in range(n)
#                for j in range(n)]
"""