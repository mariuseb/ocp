#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from matplotlib import rc
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    cfg_path = os.path.join("configs", "2R2C.json")
    data_path = os.path.join(get_data_path(), "data_ZEBLL_PRBS.csv")
    ekf_config = os.path.join(get_opt_config_path(), "2R2C_EKF.json")

    data = pd.read_csv(data_path)
    # dt is 30 seconds:
    data.index = pd.TimedeltaIndex(data["Unnamed: 0"])
    data.index.name = "time"

    # try with 15 min, 5 min anything that might give a decent model
    # heat: resample with mean, i.e. integration
    # temperatures, solar irr: instantaneous sampling
    downsample = True
    sampling_time = "15min"
    dt = 900

    if downsample:

        heat = data[["phi_h", "phi_s"]]
        heat = heat.resample(sampling_time).mean()

        rest = data[["Ti", "Ta"]]
        rest = rest.resample(sampling_time).first()

        y_data = pd.merge(heat, rest, left_index=True, right_index=True)
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*900, 900)

    else:

        y_data = data
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*30, 30)

    """
    fig, ax = plt.subplots(2,1)
    (y_data.Ti-273.15).plot(color="k", ax=ax[0])
    y_data.phi_h.plot(color="k", ax=ax[1])
    ax[0].set_ylabel(r"Temperature [$^\circ$C]")
    ax[1].set_ylabel(r"Power [W]")
    fig.tight_layout()
    plt.show()
    """

    #y_data = y_data.iloc[0:100]

    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]

    param_guess = ca.DM([0.01,0.1,1E6,1E7,2])
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,1,1E7,1E8,50])
    #param_guess = ca.DM([0.001,0.009,1,1E6,1E7,1])
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)

    #    with ParameterEstimation(config=cfg_path,
    #                             data=y_data,
    #                             param_guess=param_guess) as param_est:

    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(2)
        #Q[0,0] = 6.55919266e-01
        #Q[1,1] = 4.52496393e-01
        #Q[1,0] = 0.01
        #Q[0,1] = 0.01
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        #grad_f = ca.gradient(param_est.nlp["f"], param_est.nlp["x"])
        #grad_f_f = ca.Function("grad_f", [param_est.nlp["x"]], [grad_f])

        """
        from cvxpy with first solution:
        [[6.55919266e-01 5.26466051e-12]
        [5.26466051e-12 4.52496393e-01]]

        params after first solve:
        Rie    1.532625e-03
        Rea    1.160423e-02
        Ci     1.328633e+06
        Ce     6.644898e+06
        Ai     5.578587e+00

        params after second solve:
        Rie    1.567088e-03
        Rea    1.160390e-02
        Ci     1.337609e+06
        Ce     6.747752e+06
        Ai     5.132032e+00m here we k

        Does it change the physical parameters any???

        """
        sol_, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )
        
        ax = sol_["Ti"].plot(color="r")
        sol_["y1"].plot(color="k", ax=ax)
        ax.legend()
        plt.show()
        print(params)
        
        #taus = param_est.get_taus(p=params.values)
        A = param_est.get_Ad(p=params.values)
        #print(taus)

"""
Specify and solve problem using cvxpy.

Discrete-time Lyapunov equation determines
the state covariance:

    APA^{{H}} - X + Q = 0
    
where A is the linearization of the ODE.

Entities (all discrete-time):
    Q - process noise covariance
    R - measurement noise covariance
    S - output/innovation covariance
    P - state estimate covariance
    

TODO:
    - create covariance solver class.

    - test on simple integrator testcase,
    where one zone gets PRBS and one not.    

"""

import numpy as np
from scipy.linalg import expm
import cvxpy as cp

np.random.seed(1)
nx = 2
ny = 1
#m = 2
T = N-1
# linear system:
#A = expm(A*dt)
C = np.array([1,0])


constr = []

Q = cp.Variable((nx, nx), PSD=True)
constr += [Q[0,1] == 0]
constr += [Q[1,0] == 0]

R = cp.Variable((ny, ny), PSD=True)
#R = cp.Variable((ny, ny))
#P = cp.Variable((nx, nx, T))
e = sol_["Ti"] - sol_["y1"]
e = e.values
e = e.reshape((e.shape[0], 1))
cost = 0
Ps = []
#P0 = np.diag([1e-8,1e-4])
P = cp.Variable((nx, nx), PSD=True)
Ps.append(P)
Ss = []
for t in range(T):
    #cost += cp.sum_squares(x[:, t + 1]) + cp.sum_squares(u[:, t])
    P = cp.Variable((nx, nx), PSD=True)
    Ps.append(P)
    S = cp.Variable((ny, ny), PSD=True)
    Ss.append(S)
    constr += [Ps[t+1] == A @ Ps[t] @ A.T + Q]
    constr += [Ss[t] == C.T @ Ps[t+1] @ C + R]
    #cost += e[t].T * S[t] * e[t] + cp.log_det(S[t])
    #cost += e[t].T * cp.inv(S[t]) * e[t] + cp.log(S[t])
    """
    Use matrix fraction:
    
        cp.matrix_frac(x, P)
        (x^T @ P^-1 @ x)
        
    where P is a variable
    and x problem data.
    """
    #sub_expr = cp.matrix_frac(e[t], S) # + cp.log(S)
    #cost += sub_expr
    
    sub_expr = cp.log(S) - e[t].T @ S @ e[t]
    cost += sub_expr
    #constr += [x[:, t + 1] == A @ x[:, t] + B @ u[:, t], cp.norm(u[:, t], "inf") <= 1]

# sums problem objectives and concatenates constraints.
#constr += [x[:, T] == 0, x[:, 0] == x_0]
#problem = cp.Problem(cp.Minimize(cost), constr)
problem = cp.Problem(cp.Maximize(cost), constr)

#from cvxpygen import cpg
#cpg.generate_code(problem, code_dir='lyapunov_solver', solver='SCS')
#from lyapunov_solver.cpg_solver import cpg_solve
#problem.register_solve('cpg', cpg_solve)
#opts = {"max_iters": 1E6}
opts = dict()
problem.solve(solver=cp.SCS, verbose=True, **opts)
#problem.solve(method="cpg", verbose=True, **opts)
for P in Ps:
    try:
        print(P.value)
    except:
        pass
for S in Ss:
    try:
        print(S.value)
    except:
        pass
print(Q.value)

"""
import matplotlib.pyplot as plt

f = plt.figure()

ax = f.add_subplot(411)
plt.plot(u[0, :].value)
plt.ylabel(r"$(u_t)_1$", fontsize=16)
plt.yticks(np.linspace(-1.0, 1.0, 3))
plt.xticks([])

# Plot (u_t)_2.
plt.subplot(4, 1, 2)
plt.plot(u[1, :].value)
plt.ylabel(r"$(u_t)_2$", fontsize=16)
plt.yticks(np.linspace(-1, 1, 3))
plt.xticks([])

# Plot (x_t)_1.
plt.subplot(4, 1, 3)
x1 = x[0, :].value
plt.plot(x1)
plt.ylabel(r"$(x_t)_1$", fontsize=16)
plt.yticks([-10, 0, 10])
plt.ylim([-10, 10])
plt.xticks([])

# Plot (x_t)_2.
plt.subplot(4, 1, 4)
x2 = x[1, :].value
plt.plot(range(51), x2)
plt.yticks([-25, 0, 25])
plt.ylim([-25, 25])
plt.ylabel(r"$(x_t)_2$", fontsize=16)
plt.xlabel(r"$t$", fontsize=16)
plt.tight_layout()
plt.show()
"""