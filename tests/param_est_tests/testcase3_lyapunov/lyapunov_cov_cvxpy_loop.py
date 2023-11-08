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
from ocp.filters import KalmanBucy
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
      
    data_path = os.path.join(get_data_path(), "data_bestest_hydronic.csv")
    
    if GENERATE_DATA:
        
        prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"), sep=";")
        prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        dt_index = prbs.index
        prbs.Ph /= 5
        prbs = prbs.Ph
        prbs = prbs.round(0)
        prbs = prbs.resample(sampling_time).first()
        prbs.index = range(len(prbs.index))
        # baseline control for sysid:
        #N = len(prbs)
        N = 168*2
        # shorten data:
        #N = 200
        
        
        #u_measured = []
        for n in range(N):
            #u_0 = pd.Series(index=['phi_h_sou', 'phi_h_nor'], data=[prbs.loc[n]*2E3, prbs.loc[n]*2E3])
            #u_0["ahu_Tsup"] = 288.15
            #try:
            #_, y_meas, u_meas = boptest.evolve(u=u_0)
            _, y_meas, u_meas = boptest.evolve()
            #except TypeError:
            #print(y_meas)
            #u_measured.append(u_meas)
        
        data = boptest.get_data(tf=N*boptest.h, downsample=False)
        data.to_csv(data_path)
    
    else:
        data = pd.read_csv(data_path, index_col=0)
    
    # add noise:
    #data = data.iloc[0:4]
    np.random.seed(42)
    N = len(data)-1
    sigma = np.array([[0.1, 0.1]])
    y = list(boptest.y.keys())
    ny = len(y)
    noise = np.random.normal(0,1,ny*(N+1)).reshape((ny, N+1))
    data[y] += (noise*sigma.T).T
        
    if PLOT:
        fig, axes = plt.subplots(2,1, sharex=True)
        data.Ti_sou.plot(ax=axes[0])
        ax1 = axes[0].twinx()
        data.phi_h_sou.plot(ax=ax1, color="r", drawstyle="steps-post")
        data.Ti_nor.plot(ax=axes[1])
        ax1 = axes[1].twinx()
        data.phi_h_nor.plot(ax=ax1, color="r", drawstyle="steps-post")
        plt.show()
    
    y_data = data[:-1]
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    y_data["y1"] = y_data.Ti_sou
    y_data["y2"] = y_data.Ti_nor


    Q = ca.DM.eye(2)
    R = ca.DM.eye(2)
    
    param_guess = ca.DM([1E-0, 1E4, 1E-0, 1E4])
    param_guess = ca.DM([1E0, 1.5E4, 1E-0, 1.6E4])
    #param_guess = ca.DM([1E0, 1E5, 1E-0, 1E5])
    param_guess = ca.DM([1E-2, 1E6, 1E-2, 1E6])
    lbp = 1E-2*param_guess
    ubp = 1E2*param_guess
    
    param_est = ParameterEstimation(config=cfg_path,
                                    N=N,
                                    dt=dt,
                                    param_guess=param_guess)
    # create the filter:
    ekf = KalmanBucy(ekf_config)
    
    """
    Iterate until delta params is below tolerance.
    After first compilation, both problems should
    solve quite fast.
    """
        
    delta_p = np.inf
    tol = 1e-2
    
    delta_ps = pd.DataFrame(columns=["delta_p"])
    ps = pd.DataFrame(columns=param_est.dae.dae.p())
    Rs = pd.DataFrame(columns=["r11", "r22"])
    sols = {}
    k = 0
    while delta_p >= tol:
        sol, params = param_est.solve(
                                    y_data,
                                    param_guess,
                                    lbp=lbp,
                                    ubp=ubp,
                                    covar=ca.veccat(Q, R)
                                    )
        sols[k] = sol
        """
        Calculate delta_p
        to determine convergence.
        """
        p = params = params.values
        new_norm = np.linalg.norm(params, 2)
        old_norm = np.linalg.norm(param_guess, 2)
        delta_p = abs((new_norm - old_norm)/old_norm)
        # keep:
        delta_ps.loc[k] = delta_p
        ps.loc[k] = params
        # need these for lyapunov equation:
        A = scipy.linalg.expm(ekf.jac_f(sol[param_est.x()].iloc[0].values,
                                        0,
                                        0,
                                        p,
                                        0,
                                        0,
                                        0,
                                        0)*dt
                              )
        C = np.array(ekf.jac_h(sol[param_est.x()].iloc[0].values,
                               0,
                               0,
                               p,
                               0,
                               0,
                               0,
                               0
                               )
                     )
        
        # get trajectories, residuals:
        x = sol[param_est.x()]
        y = sol[param_est.dae.dae.y()]
        y.columns = x.columns
        e = x - y
        e = e.values
        """
        error = e.reshape((e.shape[0], A.shape[0]))
        E = np.zeros((ny*N, ny*N))
        start = 0
        for n in range(N):
            e = error[n,:].reshape((ny, 1))
            E[start:start+ny,start:start+ny] = e @ e.T
            start += ny
        """
        
        """
        covar_solver = CovarianceSolver(param_est.N,
                                        A, 
                                        C.T,
                                        #parametric=True
                                        e=e
                                        )
        R, Q = covar_solver.solve()
        """
        try:
            R, Q = covar_solver.solve(e=e)
        except NameError:
            covar_solver = CovarianceSolver(param_est.N,
                                            A, 
                                            C.T,
                                            parametric=True,
                                            e=e
                                            )
            R, Q = covar_solver.solve(e=e)
            #R, Q = covar_solver.solve(e=E)
            #R, Q = covar_solver.solve()
        
        R = ca.DM(R)
        # normalize:
        Rs.loc[k] = np.diag(R)
        R = R/sum(np.diag(R))
        # new bounds:
        lbp = 1E-2*params
        ubp = 1E2*params
        param_guess = params 
        # count
        k += 1
    
    print(ps)
    print(delta_ps)
    print(Rs)
    
    # plot trajectories after:
        
    """
    fig, axes = plt.subplots(2,1, sharex=True)
    ax = axes[0]
    sol["Ti_sou"].plot(ax=ax, color="r")
    sol["y1"].plot(color="k", ax=ax, linestyle="dashed")
    ax.legend(["model", "true"])
    ax = axes[1]
    sol["Ti_nor"].plot(ax=ax, color="r")
    sol["Ti_nor"].plot(ax=ax, color="y", linestyle="dashed")
    sol["y2"].plot(color="k", ax=ax, linestyle="dashed")
    ax.legend(["model", "true"])
    plt.show()
    print(params)
    """
    