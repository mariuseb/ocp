import cvxpy as cp
import numpy as np
from cvxpy.expressions.constants.parameter import Parameter
from cvxpy.atoms.affine import reshape
#import pandas as pd
#import os
#from ocp.tests.utils import get_data_path
#import mosek

"""
Define a solver for finding the RL-step
on theta (parametric MHE-MPC), by solving
a semi-definite program (SDP) to ensure
positive semi-definiteness of the resulting
matrices.

First step is to formulate the problem
only to take steps on the arrival cost
parametrization:

min_{delta_theta} 0.5*||delta_theta||^2 - 
        alpha*delta_k*grad(Q)_theta(nlp_sol)^T@(delta_theta)

st. 
off diagnoal elements in P(theta + delta_theta) -> 0

where theta = vec(P(theta)).

Extending this to handle e.g. steps
also on the covariance matrices, i.e.:

min_{delta_theta} 0.5*||delta_theta||^2 - 
        alpha*delta_k*grad(Q)_theta(nlp_sol)^T@(delta_theta)

st. 
P(theta + delta_theta) => 0
Q(theta + delta_theta) => 0
R(theta + delta_theta) => 0

where theta = vec(P(theta), Q(theta), R(theta))
should be straightforward.
"""

class RL_SDP(object):
    """
    Given the gradient of Q evaluated 
    at the NLP solution x_k, u_k,
        (with dim(..) = 1xdim(theta))
    solve for step delta_theta such that 
    resulting weighting matrices remain
    positive semi-definite.
    """
    def __init__(
                 self,
                 n_x,
                 n_y,
                 n_p
                 ):
        self.n_x = n_x
        self.n_y = n_y
        self.n_p = n_p
        self.n_P = (n_p + n_x)
        
        #self.setup_problem()
        
    def setup_problem(self, alpha_delta_grad_Q):
        # vars:
        #self.P = P = cp.Variable(shape=(self.n_P, self.n_P), PSD=True)
        #self.P0 = P0 = cp.Parameter(shape=(self.n_P**2, 1))
        #self.del_theta = del_theta = cp.Variable(shape=(self.n_P**2, 1))
        #self.P = P = cp.Variable(shape=(self.n_P, self.n_P), PSD=True)
        self.P0 = P0 = cp.Parameter(shape=(self.n_P, self.n_P))
        self.del_theta = del_theta = cp.Variable(shape=(self.n_P, self.n_P))
        #self.P = P = cp.Variable(shape=(self.n_P, self.n_P), PSD=True)
        self.P = P = cp.Variable(shape=(self.n_P, self.n_P), PSD=True)
        # reshape P temporarily for easier iteration through:
        #P_flat = P.reshape()
        
        #P_step = cp.Variable(shape=(self.n_P, 1))
        
        # NB: rewrite to enforce this as constraint.
        
        # reshape P0, P
        #P0_reshaped = P0.reshape((self.n_P**2))
        #P_reshaped = reshape.reshape(P, (self.n_P**2, 1))
        
        constraints = []
        for row in range(self.n_P):
            for col in range(self.n_P):
                if row != col:
                    constraints.append(P[row, col] == 0)
                #P_step[n] = P[n] + del_theta[n]
                #constraints.append(P_reshaped[n] == P0[n] + del_theta[n])
                constraints.append(P[row, col] == P0[row, col] + del_theta[row, col])
                if row == col:
                    constraints.append(P0[row, col] + del_theta[row, col] >= 0)
            
            
            
        #self.P_step = P_step.reshape((self.n_P, self.n_P))
            
        # constraints.
        #constraints = [self.P_step >> 0]
        #constraints += [R >> 0]
        
        # objective:
        obj = cp.Minimize(0.5*cp.power(cp.norm(del_theta, 2), 2) - alpha_delta_grad_Q@reshape.reshape(del_theta, (self.n_P**2, 1)))
                    
        self.prob = cp.Problem(obj, constraints)
        
    def solve(self, \
              P_val,
              warmstart=False,
              ):
        
        #if warmstart:
        #    self.S.value = np.linalg(kwargs.pop("R"))
        #    self.P.value = np.linalg(kwargs.pop("Q"))
        
        # reshape op
        
        self.P0.value = np.array(P_val)
        
        self.prob.solve(solver=cp.SCS,
                        #mosek_params = 
                        #    {
                        #     mosek.dparam.optimizer_max_time: 1000.0,
                        #     mosek.iparam.intpnt_solve_form: mosek.solveform.dual
                        #    },
                        #save_file = 'dump.opf',
                        warm_start=warmstart,
                        verbose = True)
        
        #R_hat = np.linalg.inv(self.S.value)
        #Q_hat = np.linalg.inv(self.P.value)
        
        #R_hat[abs(R_hat) <= 1e-4] = 0
        #Q_hat[abs(Q_hat) <= 1e-4] = 0
        #R_hat = np.diag(np.diag(R_hat))
        #Q_hat = np.diag(np.diag(Q_hat))
        #return R_hat, Q_hat
        return self.del_theta.value
            
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