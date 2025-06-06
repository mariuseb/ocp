#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
from ocp.estimation import Estimation
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
#from ocp.tests.utils import get_opt_config_path, get_data_path
import os
#from pandas.plotting import autocorrelation_plot
#from ocp.filters import KalmanBucy
from ocp.utils import prepare_data, ZEBData
from ocp.covar_solver import CovarianceSolver
from copy import deepcopy
#from result_generator import ResultGenerator, plot_residuals
#from utils import prepare_data
from test_param_est_envelope_2R2C import prepare_est
from ocp.kalman import ExtendedKalmanFilter
from ocp.config import Config
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)


if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    data_path = os.path.join(
                        "2_days_EKF.csv"
                        )
    y_data = pd.read_csv(data_path, index_col=0)
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["Te"]
    dt = y_data.index[1] - y_data.index[0]
    N = len(y_data)
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(y_data)
    cfg_path = os.path.join("configs", "2R2C.json")
    ekf_config = os.path.join("ekf_configs", "2R2C_EKF_2meas.json") 
        
    # physical parameter estimation:
    param_est = Estimation(
        config=cfg_path,
        N=N,
        dt=dt,
        param_guess=param_guess,
        truncate_scaling=True,
        arrival_cost=True,
        **deepcopy(kwargs)
    )
    Q = ca.DM.eye(2)
    R = ca.DM.eye(2)
    P0 = np.eye(param_est.n_p + param_est.n_x)*1
    P0[
        param_est.n_p:(param_est.n_p + param_est.n_x),
        param_est.n_p:(param_est.n_p + param_est.n_x)
        ] = 0
    #P0[2,2] = 0
    #P0[5,5] = 0
    
    lbp = param_est.get_lbp(1e-3)
    ubp = param_est.get_ubp(1e3)
    p0 = param_est.p0
    sol, params = param_est.solve(
        y_data,
        p0,
        lbp=lbp,
        ubp=ubp,
        lbx=lbx,
        ubx=ubx,
        x_guess=x_guess,
        covar=ca.veccat(Q, R),
        codegen=True,
        P0=P0,
        x_N=x_guess[-1,-param_est.n_x:]
    )
    
    p_nom = param_est.p_nom
    # covar estimation:
    covar_kwargs = dict()
    covar_kwargs["p_nom"] = p_nom
    y_data = y_data[:-1]      
 
    covar_solver = CovarianceSolver(
                                    ekf_config,
                                    cfg_path,
                                    y_data,
                                    param_guess,
                                    method="single_shooting",
                                    **covar_kwargs
                                    )
    """
    P0 = np.ones(
            (covar_solver.ekf.dae.n_x,
            covar_solver.ekf.dae.n_x)
            )*1e-3 # + 1e-2
    """
    P0 = np.eye(2)*np.diag([1E-8, 1E-8])**2
    #P0 = np.eye(3)
    P0_guess = P0.flatten()
    Q_guess = np.array(
        ca.veccat(
                ca.DM.eye(covar_solver.ekf.dae.n_x),
                )
        ).flatten()*1e-3
    R_guess = np.array(ca.DM.eye(covar_solver.ekf.dae.n_y)).flatten()*1e-4
    x0 = np.array([293.15, 293.15])
    H = np.eye(8)*0
    #covar_solver.exchange_P0_constraint(P0_guess)
    params = param_est.p0
    covar_sol, Q_df, R, raw_sol = covar_solver.solve(
            y_data, 
            params,
            x0, # guess from smoothing
            P0_guess,
            Q_guess,
            R_guess, 
            H=H    
            )
    Q = Q_df.values.reshape((param_est.n_x, param_est.n_x))
    print(Q)
    

    