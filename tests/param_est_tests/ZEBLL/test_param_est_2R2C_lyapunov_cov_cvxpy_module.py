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
from ocp.filters import KalmanBucy
from ocp.covar_solver import CovarianceSolver
import scipy
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    cfg_path = os.path.join("configs", "2R2C.json")
    ekf_config = os.path.join("configs", "2R2C_EKF.json")
    data_path = os.path.join(get_data_path(), "data_ZEBLL_PRBS.csv")

    data = pd.read_csv(data_path)
    # dt is 30 seconds:
    data.index = pd.TimedeltaIndex(data["Unnamed: 0"])
    data.index.name = "time"

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
        
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]

    param_guess = ca.DM([0.01,0.1,1E6,1E7,2])
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,1,1E7,1E8,50])

    # create the smoother.
    param_est = ParameterEstimation(config=cfg_path,
                                    N=N,
                                    dt=dt,
                                    param_guess=param_guess)
    # create the filter:
    ekf = KalmanBucy(ekf_config)

    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)
    
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

    x = [293.15, 293.15]
    p = params.values
    A = scipy.linalg.expm(ekf.jac_f(x,0,0,p,0,0,0,0)*dt)
    C = np.array(ekf.jac_h(x,0,0,p,0,0,0,0))
    e = sol_["Ti"] - sol_["y1"]
    e = e.values
    e = e.reshape((e.shape[0], 1))

    covar_solver = CovarianceSolver(param_est.N, A, C.T)
    R, Q = covar_solver.solve(e)
    print(R, Q)
