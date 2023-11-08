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

    #y_data = y_data.iloc[0:3]

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

"""
Specify and solve problem using rockit g
"""

from rockit import *

# Problem specification
# ---------------------

# Start an optimal control environment with a time horizon of 10 seconds
# starting from t0=0s.
#  (free-time problems can be configured with `FreeTime(initial_guess)`)
Tf = (N-1)*dt
ocp = Ocp(t0=0, T=Tf)

# Define two scalar states (vectors and matrices also supported)
Ti = ocp.state()
Te = ocp.state()

# Measurements of state
Ti_meas = y_data.Ti.values[:-1]

Ti_meas_param = ocp.parameter(grid='control')
#ocp.set_value(Ti_meas_param, Ti_meas[:-1])
ocp.set_value(Ti_meas_param, Ti_meas)

# Measurements of control
phi_h_meas = y_data.phi_h[:-1]
Ta_meas = y_data.Ta[:-1]
phi_s_meas = y_data.phi_s[:-1]

# Define one piecewise constant control input
#  (use `order=1` for piecewise linear)
phi_h = ocp.parameter(grid='control')
Ta = ocp.parameter(grid='control')
phi_s = ocp.parameter(grid='control')

ocp.set_value(phi_h, phi_h_meas)
ocp.set_value(Ta, Ta_meas)
ocp.set_value(phi_s, phi_s_meas)

# Unknown system parameters
Rie = ocp.variable()
Rea = ocp.variable()
Ci = ocp.variable()
Ce = ocp.variable()
Ai = ocp.variable()

# Initial guesses for system parameters
ocp.set_initial(Rie, 1e-2)
ocp.set_initial(Rea, 1e-2)
ocp.set_initial(Ci, 1e6)
ocp.set_initial(Ce, 1e7)
ocp.set_initial(Ai, 5)

ocp.subject_to(1e-4 <= (Rie <= 1))
ocp.subject_to(1e-4 <= (Rea <= 1))
ocp.subject_to(1e4 <= (Ci <= 1e8))
ocp.subject_to(1e5 <= (Ce <= 1e9))
ocp.subject_to(1 <= (Ai <= 100))

# Compose time-dependent expressions a.k.a. signals
#e = alpha - beta*x2**2

# Specify differential equations for states
ocp.set_der(Ti, (Te - Ti)/(Rie*Ci) + (1/Ci)*phi_h + Ai*(phi_s/Ci))
ocp.set_der(Te, (Ti - Te)/(Rie*Ce) + (Ta - Te)/(Rea*Ce))

error_sq = (Ti-Ti_meas_param)**2

# Objective: sum of error_sq
ocp.add_objective(ocp.sum(error_sq))

# Pick an NLP solver backend
opts = param_est.opt
opts["ipopt.linear_solver"] = "ma57"
ocp.solver('ipopt', param_est.opt)

# Pick a solution method
method = MultipleShooting(N=N-1, intg='rk')
ocp.method(method)

# Exploit the availability of measurements
ocp.set_initial(Ti, Ti_meas)
ocp.set_initial(Te, Ti_meas)
#ocp.set_initial(x2, x2_meas)

# Solve
sol = ocp.solve()

print("Estimated parameters = ")
print(sol.value(Rie))
print(sol.value(Rea))
print(sol.value(Ci))
print(sol.value(Ce))
print(sol.value(Ai))
t, Ti = sol.sample(Ti, grid="control")

ax = y_data["y1"].plot(color="k")
ax.plot(t, Ti, color="r", linestyle="dashed")
ax.plot(t, sol_["Ti"].values, color="y", linestyle="dashed")
ax.legend()
plt.show()

# plot trajectory:
print(params)
