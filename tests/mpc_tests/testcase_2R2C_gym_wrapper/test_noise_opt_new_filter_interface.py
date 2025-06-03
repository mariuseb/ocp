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
    p_nom = param_est.p_nom
    # covar estimation:
    covar_kwargs = dict()
    covar_kwargs["p_nom"] = p_nom
    y_data = y_data[:-1]      
    #y_data = y_data.iloc[200:300]
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
    P0 = np.eye(2)*np.diag([1E-2, 1E-2])**2
    #P0 = np.eye(3)
    P0_guess = P0.flatten()
    Q_guess = np.array(
        ca.veccat(
                ca.DM.eye(covar_solver.ekf.dae.n_x),
                )
        ).flatten()*1e-3
    #Q_guess = (np.eye(3)*np.diag([-8.28, -5.666, -5.712])).flatten()
    #R_guess = np.array(ca.DM.eye(covar_solver.ekf.dae.n_y)).flatten()*-5
    R_guess = np.array(ca.DM.eye(covar_solver.ekf.dae.n_y)).flatten()*1e-3
    #R_guess = (np.eye(1)*np.diag([-12.4])).flatten()
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
    

    