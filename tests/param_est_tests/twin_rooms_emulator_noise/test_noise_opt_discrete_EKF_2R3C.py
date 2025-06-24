import sys
import os
import pathlib
import os
import json
import numpy as np
import casadi as ca
import pandas as pd
import matplotlib.pyplot as plt
from ocp.estimation import Estimation
from pprint import pprint
from matplotlib import rc
from copy import deepcopy
from utils import prepare_data, prepare_est
from ocp.functions import functions
from ocp.covar_solver import CovarianceSolver
from ocp.result_generator import mse
#ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
#sys.path.append(ocp_path)
rc('text', usetex=True)

if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    data_path = os.path.join(
                        "twin_rooms_emulator_PRBS_new_15min.csv"
                        )
    y_data, N, dt = prepare_data(data_path)
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(y_data)
    params = pd.read_csv("envelope_model_2R3C_alt_alt.csv", index_col=0)
    p_nom = pd.read_csv("p_nom_2R3C.csv", index_col=0)
    sol = pd.read_csv("simulation_traj_2R3C_alt_alt.csv", index_col=0)
    sol.index = y_data.index

    kwargs["z_nom"] = []
    kwargs["z_nom_b"] = []
    kwargs["y_nom"] = 12
    kwargs["y_nom_b"] = 289.15
    kwargs = {}
    kwargs["p_nom"] = p_nom.values.flatten()
    #kwargs["p_nom"] = 1
    
    ekf_config = pathlib.Path(
        os.path.join("ekf_configs", "2R3C_EKF.json") 
    )       
    covar_solver = CovarianceSolver(
        ekf_config,
        len(y_data),
        params.values.flatten(),
        method="single_shooting",
        **kwargs
    )
    
    x0 = x0_sim = sol[["Ti", "Te", "dT"]].iloc[0].values
    covar_solver.ekf.Q *= 1
    covar_solver.ekf.R *= 1
    covar_solver.ekf.P *= 1
    
    #Q, R, P0 = covar_solver.ekf.Q, covar_solver.ekf.R, covar_solver.ekf.P
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
        z0=z.T,
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
        z0=z.T,
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
    
    #val_data = y_data[1:]
    val_data = y_data.copy()
    val_data.index = range(len(val_data.index))
    
    x_pred_opt.index = sol.index[1:]
    x_pred_opt.loc[0] = x0.flatten()
    x_pred_opt.sort_index(inplace=True)
    #x_pred_opt["Prad"] = sol["rad_flo"]*sol["cp_water"]*(x_pred_opt["Tsup"] - x_pred_opt["Tret"])
    val_data.index = sol.index
    
    mse_opt = mse( 
        val_data[["Ti"]].values,
        x_pred_opt[["Ti"]].values,
    )
    
    x_pred_nonopt.index = sol.index[1:]
    x_pred_nonopt.loc[0] = x0_sim
    x_pred_nonopt.sort_index(inplace=True)
    #x_pred_nonopt["Prad"] = sol["rad_flo"]*sol["cp_water"]*(x_pred_nonopt["Tsup"] - x_pred_nonopt["Tret"])
    mse_nonopt = mse( 
        val_data[["Ti"]].values,
        x_pred_nonopt[["Ti"]].values,
    )
    
    fig, axes = plt.subplots(2,1, sharex=True)
    frames = [x_pred_opt, x_pred_nonopt, val_data]
    #frames = [x_pred_opt, val_data]
    
    ax = axes[0]
    
    var = "Ti"
    kwargs = {
        "drawstyle": "steps-post",
        "linewidth": 0.75
    }
    for frame in frames:
        frame[var].plot(ax=ax,**kwargs)
    #val_data[var + "_true"].plot(ax=ax,**kwargs,color="k",linestyle="dashed")
    ax.legend(["opt", "nonopt", "measured"])
    #ax.legend(["opt", "measured"])

    plt.show()
    
    x0 = pd.Series(
        index=covar_solver.x,
        data=x0.flatten()
    )
    
    one_step_params = pd.concat(
        [Q_df.squeeze(), R_df.squeeze(), x0]
    )
    one_step_params.to_csv("one_step_params.csv", index=True)
    
    print(Q)
    
    

    