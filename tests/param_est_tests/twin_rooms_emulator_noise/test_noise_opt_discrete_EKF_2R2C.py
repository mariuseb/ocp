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
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from pandas.plotting import autocorrelation_plot
from ocp.filters_old import KalmanBucy
from ocp.utils import prepare_data, ZEBData
from ocp.covar_solver import CovarianceSolver
from copy import deepcopy
from result_generator import ResultGenerator, plot_residuals
from utils import prepare_data
from test_param_est_envelope_2R2C import prepare_est
from ocp.result_generator import mse
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)


if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    data_path = os.path.join(
                        "twin_rooms_emulator_PRBS.csv"
                        )
    y_data, N, dt = prepare_data(data_path)
    y_data["phi_h"] = y_data["Prad"]
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(y_data)
    params = pd.read_csv("envelope_model_2R2C.csv", index_col=0)
    sol = pd.read_csv("simulation_traj_2R2C.csv", index_col=0)
    cfg_path = os.path.join("configs", "2R2C.json")
    ekf_config = pathlib.Path(
        os.path.join("ekf_configs", "2R2C_envelope_EKF.json") 
    )       
    #covar_kwargs = kwargs
    """
    Param est object:
    """
    for k, v in param_guess.items():
        v["init"] = float(params.loc[k])
        v["lb"] = float(params.loc[k])
        v["ub"] = float(params.loc[k])
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
    covar_solver = CovarianceSolver(
        ekf_config,
        len(y_data),
        params.values.flatten(),
        method="single_shooting",
        **kwargs
    )
    x0 = sol[["Ti", "Te"]].iloc[0].values
    covar_sol, x0, P0, Q_df, R_df, raw_sol = covar_solver.solve(
        y_data,
        x0_guess=x0
    )
    
    R, Q = R_df.values.reshape((
        covar_solver.n_y, \
        covar_solver.n_y
        )), \
        Q_df.values.reshape((
            covar_solver.n_x, \
            covar_solver.n_x
    ))
    
    u, r, p, y, z = covar_solver.prepare_variable_wise(
        y_data,
        scaling=False
    )
    kalman_map = covar_solver.F_map
    
    M = covar_solver.M
    res_opt = kalman_map(
        x0=x0,
        P0=P0,
        u=u.T,
        p=p*covar_solver.p_nom,
        r=r.T,
        y=y.T,
        Q=Q,
        R=R
    )
    x_pred_opt = pd.DataFrame(
        data=np.array(res_opt["x_prior"]).T,
        columns=covar_solver.x
    )
    
    # 'correct' noise parameters:
    Q = np.eye(covar_solver.n_x)
    R = np.eye(covar_solver.n_y)
    res_nonopt = kalman_map(
        x0=x0,
        P0=P0,
        u=u.T,
        p=p*covar_solver.p_nom,
        r=r.T,
        y=y.T,
        Q=Q,
        R=R
    )
    x_pred_nonopt = pd.DataFrame(
        data=np.array(res_nonopt["x_prior"]).T,
        columns=covar_solver.x
    )
    
    val_data = y_data[1:]
    val_data.index = range(len(val_data.index))
    
    mse_opt = mse( 
        val_data[["Ti"]].values,
        x_pred_opt[["Ti"]].values,
    )
    
    mse_nonopt = mse( 
        val_data[["Ti"]].values,
        x_pred_nonopt[["Ti"]].values,
    )
    
    fig, ax = plt.subplots(1,1)
    frames = [x_pred_opt, x_pred_nonopt, val_data]
    
    var = "Ti"
    kwargs = {
        "drawstyle": "steps-post",
        "linewidth": 0.75
    }
    for frame in frames:
        frame[var].plot(ax=ax,**kwargs)
    #val_data[var + "_true"].plot(ax=ax,**kwargs,color="k",linestyle="dashed")
    ax.legend(["opt", "nonopt", "measured"])
    
    plt.show()
    
    print(Q)
    
    

    