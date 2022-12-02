import cvxpy as cp
import numpy as np
import scipy as scipy
import pandas as pd
from ocp.tests.utils import get_data_path
import os
import numpy as np
#from cvxpygen import cpg

sol = pd.read_csv(os.path.join(get_data_path(), "test.csv"))

v = sol[["v1"]].values.T
w = sol[["w1", "w2"]].values.T

# Dimension of meas, state:
n_y = v.shape[0]
n_x = w.shape[0]

# Number of samples, y_i
N = len(sol)

# Create sparse, symmetric PSD matrix S
#A = np.random.randn(n, n)  # Unit normal gaussian distribution.
#A[scipy.sparse.rand(n, n, 0.85).todense().nonzero()] = 0  # Sparsen the matrix.
#Strue = A.dot(A.T) + 0.05 * np.eye(n)  # Force strict pos. def.

# Create the covariance matrix associated with S.
#R = np.linalg.inv(Strue)

# Create samples y_i from the distribution with covariance R.
#y_sample = scipy.linalg.sqrtm(R).dot(np.random.randn(n, N))

# Calculate the sample covariance matrix.
#Y = np.cov(y_sample)

# The alpha values for each attempt at generating a sparse inverse cov. matrix.
alphas = [10]

# Empty list of result matrixes S
Ss = []

# Solve the optimization problem for each value of alpha.
for alpha in alphas:
    # Create a variable that is constrained to the positive semidefinite cone.
    S = cp.Variable(shape=(n_y,n_y), PSD=True)
    P = cp.Variable(shape=(n_x, n_x), PSD=True)

    V = np.cov(v)
    W = np.cov(w)

    # Form the logdet(S) - tr(SY) objective. Note the use of a set
    # comprehension to form a set of the diagonal elements of S*Y, and the
    # native sum function, which is compatible with cvxpy, to compute the trace.
    # TODO: If a cvxpy trace operator becomes available, use it!
    #obj = cp.Maximize(cp.log_det(S) - sum([(S@v)[i, i] for i in range(n_y)]) + \
    #                  cp.log_det(P) - sum([(P@w)[i, i] for i in range(n_x)]))
    obj = cp.Maximize(cp.log_det(S) - cp.trace(S*V) + \
                      cp.log_det(P) - cp.trace(P@W))

    # Set constraint.
    constraints = [cp.sum(cp.abs(S)) <= alpha]
    constraints += [cp.sum(cp.abs(P)) <= alpha]

    # Form and solve optimization problem
    prob = cp.Problem(obj, constraints)
    #prob.solve(solver=cp.CVXOPT)
    prob.solve(solver=cp.SCS, verbose=True)
    if prob.status != cp.OPTIMAL:
        raise Exception('CVXPY Error')

    # If the covariance matrix R is desired, here is how it to create it.
    R_hat = np.linalg.inv(S.value)
    Q_hat = np.linalg.inv(P.value)
    # Threshold S element values to enforce exact zeros:
    #S = S.value
    #S[abs(S) <= 1e-4] = 0
    R_hat[abs(R_hat) <= 1e-4] = 0
    Q_hat[abs(Q_hat) <= 1e-4] = 0
    

    # Store this S in the list of results for later plotting.
    #Ss += [S]

    #print('Completed optimization parameterized by alpha = {}, obj value = {}'.format(alpha, obj.value))
    
#import matplotlib.pyplot as plt
print(R_hat)
print(Q_hat)
# Show plot inline in ipython.

# Plot properties.
#plt.rc('text', usetex=True)
#plt.rc('font', family='serif')

# Create figure.
#plt.figure()
#plt.figure(figsize=(12, 12))

# Plot sparsity pattern for the true covariance matrix.
#plt.subplot(2, 2, 1)
#plt.spy(Strue)
#plt.title('Inverse of true covariance matrix', fontsize=16)

# Plot sparsity pattern for each result, corresponding to a specific alpha.
#for i in range(len(alphas)):
#    plt.subplot(2, 2, 2+i)
#    plt.spy(Ss[i])
#    plt.title('Estimated inv. cov matrix, $\\alpha$={}'.format(alphas[i]), fontsize=16)
    
#plt.show()