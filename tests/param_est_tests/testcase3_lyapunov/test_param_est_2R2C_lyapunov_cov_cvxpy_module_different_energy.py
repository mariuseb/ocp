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
from ocp.boptest_api import Boptest
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from ocp.filters import KalmanBucy, KalmanDAE
from ocp.covar_solver import CovarianceSolver
import scipy
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    bop_config_base = get_boptest_config_path()
    cfg_path = os.path.join("configs", "2R2C_twozone_SYSID.json")
    ekf_config = os.path.join("configs", "2R2C_twozone_EKF.json")
    data_path = os.path.join(get_data_path(), "data_ZEBLL_PRBS.csv")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    
    GENERATE_DATA = False
    PLOT = True

    boptest = Boptest(
                      boptest_cfg,
                      name="testcase3"
                      )
    
    sampling_time = "60min"
      
    data_path = os.path.join(get_data_path(), "data_testcase3.csv")
    
    if GENERATE_DATA:
        
        np.random.seed(42)
        sigma = np.array([[10, 0.1]])
        prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"), sep=";")
        prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        dt_index = prbs.index
        prbs.Ph /= 5
        prbs = prbs.Ph
        prbs = prbs.round(0)
        prbs = prbs.resample(sampling_time).first()
        prbs.index = range(len(prbs.index))
        # baseline control for sysid:
        N = len(prbs)
        # shorten data:
        #N = 200
        
        
        #u_measured = []
        for n in range(N):
            u_0 = pd.Series(index=['phi_h_sou', 'phi_h_nor'], data=[prbs.loc[n]*5E2, prbs.loc[n]*5E2])
            #u_0["ahu_Tsup"] = 288.15
            #try:
            _, y_meas, u_meas = boptest.evolve(u=u_0)
            #except TypeError:
            #print(y_meas)
            #u_measured.append(u_meas)
        
        ny = len(y_meas)
        noise = np.random.normal(0,1,ny*(N+1)).reshape((ny, N+1))
        data = boptest.get_data(tf=N*boptest.h, downsample=False)
        data[list(boptest.y.keys())] += (noise*sigma.T).T
        data.to_csv(data_path)
    
    else:
        data = pd.read_csv(data_path, index_col=0)
        
    if PLOT:
        fig, axes = plt.subplots(2,1, sharex=True)
        data.Ti_sou.plot(ax=axes[0])
        ax1 = axes[0].twinx()
        data.phi_h_sou.plot(ax=ax1, color="r", drawstyle="steps-post")
        data.Ti_nor.plot(ax=axes[1])
        ax1 = axes[1].twinx()
        data.phi_h_nor.plot(ax=ax1, color="r", drawstyle="steps-post")
        plt.show()
    
    y_data = data.iloc[1:-1]
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    y_data["y1"] = y_data.Ti_sou
    y_data["y2"] = y_data.Ti_nor

    #param_guess = ca.DM([1E-1, 1E5, 1E-1, 1E5])
    
    # set really wrong params for north-side:
    
    #param_guess = ca.DM([1E-1, 1E5, 1E1, 1E2])
    param_guess = ca.DM([1E-0, 1E4, 1E-0, 1E4])
    param_guess = ca.DM([1E0, 1.5E4, 1E-0, 1.6E4])
    lbp = 1E-2*param_guess
    ubp = 1E2*param_guess

    # create the smoother.
    param_est = ParameterEstimation(config=cfg_path,
                                    N=N,
                                    dt=dt,
                                    param_guess=param_guess)
    # create the filter:
    #ekf = KalmanBucy(ekf_config)
    ekf = KalmanDAE(ekf_config)

    Q = ca.DM.eye(2)
    R = ca.DM.eye(2)
    
    sol, params = param_est.solve(
                                y_data,
                                param_guess,
                                lbp=lbp,
                                ubp=ubp,
                                covar=ca.veccat(Q, R)
                                 )

    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    sol["Ti_sou"].plot(ax=ax, color="r")
    sol["y1"].plot(color="k", ax=ax, linestyle="dashed")
    ax.legend(["model", "measured"])
    ax = axes[1]
    sol["Ti_nor"].plot(ax=ax, color="r")
    #sol["Ti_nor"].plot(ax=ax, color="y", linestyle="dashed")
    sol["y2"].plot(color="k", ax=ax, linestyle="dashed")
    ax.legend(["model", "measured"])
    plt.show()
    print(params)
    

    """
    Specify and solve problem using cvxpy.

    Discrete-time Lyapunov equation determines
    the state covariance:

        APA^{{H}} - P + Q = 0
        
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
    A = scipy.linalg.expm(ekf.jac_f_x(x,0,0,p,0,0,0,0)*dt)
    C = np.array(ekf.jac_h(x,0,0,p,0,0,0,0))
    x = sol[["Ti_sou", "Ti_nor"]]
    y = sol[["y1", "y2"]]
    y.columns = x.columns
    e = x - y
    e = e.values
    e = e.reshape((e.shape[0], A.shape[0]))

    covar_solver = CovarianceSolver(param_est.N,
                                    A, 
                                    C.T,
                                    #e.T,
                                    parametric=True
                                    )
    R, Q = covar_solver.solve(e=e)
    """
    R, Q = covar_solver.solve(
                              warmstart=True,
                              R=np.diag([1.65e-4, 6.19])
                              )
    """
    
    # try to re-estimate with new R:
    #R = ca.DM(np.linalg.inv(R))
    R = ca.DM(R)
    # normalize:
    #R = R/sum(np.diag(R))
    
    lbp = 1E-2*params
    ubp = 1E2*params
    param_guess = params.values 
    sol, params = param_est.solve(
                                y_data,
                                param_guess,
                                lbp=lbp,
                                ubp=ubp,
                                covar=ca.veccat(Q, R)
                                 )
    
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    sol["Ti_sou"].plot(ax=ax, color="r")
    sol["y1"].plot(color="k", ax=ax, linestyle="dashed")
    ax.legend(["model", "true"])
    ax = axes[1]
    sol["Ti_nor"].plot(ax=ax, color="r")
    sol["y2"].plot(color="k", ax=ax, linestyle="dashed")
    ax.legend(["model", "true"])
    plt.show()
    print(params)

    x = sol[["Ti_sou", "Ti_nor"]]
    y = sol[["y1", "y2"]]
    y.columns = x.columns
    e = x - y
    e = e.values
    e = e.reshape((e.shape[0], A.shape[0]))
    
    #covar_solver = CovarianceSolver(param_est.N, A, C.T, e.T)
    R, Q = covar_solver.solve(e=e)
    print(R)
    print(Q)