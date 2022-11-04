import cvxpy as cp
import numpy as np
import pandas as pd
import os
from ocp.tests.utils import get_data_path

sol = pd.read_csv(os.path.join(get_data_path(), "test.csv"))

# Generate a random SDP.
n = 3
p = 3
np.random.seed(1)
C = np.random.randn(n, n)
A = []
b = []
for i in range(p):
    A.append(np.random.randn(n, n))
    b.append(np.random.randn())

# Define and solve the CVXPY problem.
# Create a symmetric matrix variable.
X = cp.Variable((n,n), symmetric=True)
# The operator >> denotes matrix inequality.
constraints = [X >> 0]
constraints += [
    cp.trace(A[i] @ X) == b[i] for i in range(p)
]
prob = cp.Problem(cp.Minimize(cp.trace(C @ X)),
                  constraints)
prob.solve()

# Print result.
print("The optimal value is", prob.value)
print("A solution X is")
print(X.value)

# own problem:
w1 = sol.w1.values
w2 = sol.w2.values

w = np.vstack([w1,w2])


n = 2
N = len(sol) - 1

Q = cp.Variable((n,n), symmetric=True)
Z = cp.Variable((n,n), symmetric=True)
t = cp.Variable((1,1))

constr_matrix = cp.Variable((2*n, 2*n), symmetric=False)
#constr_matrix[0:2, 0:2] = Q
#constr_matrix[0:2, 2:4] = Z
#constr_matrix[2:4, 0:2] = Z.T
#constr_matrix[2:4, 2:4] = cp.diag(Z)

constraints = [Q >> 0]
constraints += [constr_matrix[0:2, 0:2] == Q]
constraints += [constr_matrix[0:2, 2:4] == Z]
constraints += [constr_matrix[2:4, 0:2] == Z.T]
constraints += [constr_matrix[2, 2] == cp.diag(Z)[0]]
constraints += [constr_matrix[3, 3] == cp.diag(Z)[1]]

constraints += [constr_matrix >= 0]

# Z is lower triangular:
constraints += [Z[0,1] == 0]
constraints += [t >= (cp.log(Z[0,0]) + cp.log(Z[1,1]))]

#constraints = [Q >> 0]
#constr_matrix = np.array([[Q, Z], [Z.T, cp.diag(Z)]])
#constraints += [constr_matrix <= 0]

prob = cp.Problem(cp.Minimize(cp.matrix_frac(w, Q) + t), # + cp.log_det(Q)),
                 constraints)
prob.solve(verbose=True)
print("The optimal value is", prob.value)
print("A solution Q is")
print(Q.value)
#constraints += [Q[i, j] == Q[j, i] if 
#                for i in range(n)
#                for j in range(n)]
