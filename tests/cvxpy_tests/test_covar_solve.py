from ocp.covar_solve import CovarianceSolver
import pandas as pd
from ocp.tests.utils import get_data_path
import os
import numpy as np
from cvxpygen import cpg

sol = pd.read_csv(os.path.join(get_data_path(), "test.csv"))

# Generate a random SDP.

# own problem:
#w1 = sol.w1.values[0:10]
#w2 = sol.w2.values[0:10]
w = sol[["w1", "w2"]].iloc[0:1000].T
v = sol[["v1"]].iloc[0:1000].T

#w = np.vstack([w1,w2])

#v = sol[["v1"]].values.T
#w = sol[["w1", "w2"]].values.T

covar_est = CovarianceSolver(v, w)
cpg.generate_code(covar_est.prob, code_dir="custom_solve", solver="SCS")
os.system("python custom_solve/setup.py")
from custom_solve.cpg_solver import cpg_solve
covar_est.prob.register_solve('cpg', cpg_solve)
R, Q = covar_est.solve()