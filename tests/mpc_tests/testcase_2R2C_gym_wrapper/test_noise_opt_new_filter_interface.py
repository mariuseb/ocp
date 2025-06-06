#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
import pandas as pd
import numpy as np
from ocp.covar_solver import CovarianceSolver
import casadi as ca
from ocp.result_generator import mse
import matplotlib.pyplot as plt


if __name__ == "__main__":
    """
    sysid using PRBS.
    """
    y_data = pd.read_csv(
        "2_days_KF_correct_noise.csv"
    )
    ekf_config = pathlib.Path(
        os.path.join("ekf_configs", "2R2C_EKF_2meas.json") 
    )       
    covar_solver = CovarianceSolver(
        ekf_config,
        len(y_data),
        method="single_shooting"
    )
    covar_sol, x0, P0, Q_df, R_df, raw_sol = covar_solver.solve(
        y_data
    )
    """
    For comparison: what is the true state? Need to keep it.
    """
    R, Q =  R_df.values.reshape((
        covar_solver.n_x, \
        covar_solver.n_x
        )), \
        Q_df.values.reshape((
            covar_solver.n_y, \
            covar_solver.n_y
    ))
    
    u, r, p, y, z = covar_solver.prepare_variable_wise(
        y_data
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
    Q = np.eye(2)*1e-3
    R = np.eye(2)*1e-4
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
        val_data[["Ti_true", "Te_true"]].values,
        x_pred_opt.values,
    )
    
    mse_nonopt = mse( 
        val_data[["Ti_true", "Te_true"]].values,
        x_pred_nonopt.values,
    )
    
    fig, axes = plt.subplots(1,2)
    ax = axes[0]
    frames = [x_pred_opt, x_pred_nonopt, val_data]
    
    var = "Ti"
    kwargs = {
        "drawstyle": "steps-post",
        "linewidth": 0.75
    }
    for frame in frames:
        frame[var].plot(ax=ax,**kwargs)
    val_data[var + "_true"].plot(ax=ax,**kwargs,color="k",linestyle="dashed")
    ax.legend(["opt", "nonopt", "measured", "true"])
    
    ax = axes[1]
    var = "Te"
    for frame in frames:
        frame[var].plot(ax=ax, **kwargs)
    val_data[var + "_true"].plot(ax=ax,**kwargs,color="k",linestyle="dashed")
    ax.legend(["opt", "nonopt", "measured", "true"])
    
    plt.show()
    
    
    
    print(mse_opt, mse_nonopt)
    
    
    

    