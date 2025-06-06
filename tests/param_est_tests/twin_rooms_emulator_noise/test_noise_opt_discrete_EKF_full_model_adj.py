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
                        "twin_rooms_emulator_PRBS.csv"
                        )
    y_data, N, dt = prepare_data(data_path)
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(y_data)
    params = pd.read_csv("full_model_4R4C.csv", index_col=0)
    p_nom = pd.read_csv("p_nom_4R4C.csv", index_col=0)
    sol = pd.read_csv("simulation_traj_4R4C.csv", index_col=0)
    sol.index = y_data.index
    #y_data["Prad_to_env"] = sol["Prad_to_env"]
    y_data["rad_flo"] = sol["rad_flo"]
    y_data["Prad"] = sol["Prad"]
    y_data["Tset_sup"] = sol["Tset_sup"]
    
    #y_data = y_data[:10]
    #N = len(y_data)

    """
    """
    kwargs["z_nom"] = []
    kwargs["z_nom_b"] = []
    kwargs["y_nom"] = [12,12]
    kwargs["y_nom_b"] = [289.15,289.15]
    #kwargs = {}
    kwargs["p_nom"] = p_nom.values.flatten()
    #kwargs["p_nom"] = 1
    
    ekf_config = pathlib.Path(
        os.path.join("ekf_configs", "4R3C_2meas_EKF_adj.json") 
    )       
    covar_solver = CovarianceSolver(
        ekf_config,
        len(y_data),
        params.values.flatten(),
        method="single_shooting",
        **kwargs
    )
    
    x0 = sol[["Ti", "Te", "Tret", "Tsup"]].iloc[0].values
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
    """
    """

    u, r, p, y, z = covar_solver.prepare_variable_wise(
        y_data,
        scaling=False
    )
    
    """
    One step:
    
    #F = covar_solver.ekf.one_sample_state
    
    #covar_solver.ekf.one_sample_state
    z0 = y_data[covar_solver.ekf.dae.z].iloc[0]
    
    res_df = pd.DataFrame(
        columns=covar_solver.ekf.dae.x + covar_solver.ekf.dae.z
    )
    res_df.loc[0, covar_solver.ekf.dae.x] = x0 
    
    for n in range(N-1):
        _u, _r, _y, _z = u[n], r[n], y[n], z[n]
        res = covar_solver.ekf.one_sample_state(
            x0=x0,
            z0=_z,
            #z0=_z,
            #z0=z0,
            #P0=P0,
            u=_u,
            p=p, #*p_nom.values.flatten(),
            r=_r,
            #y=_y,
            #Q=Q,
            #R=R
        )
        
        z_check = covar_solver.ekf.integrator.G(
            _z, x0, _u, p, _r
        )
        
        x_prior, z_ = res["x"], res["z"]
        #res_df.loc[n, ] = np.concatenate([x_prior, z_]).flatten()
        res_df.loc[n, covar_solver.ekf.dae.z] = np.array(z_).flatten()
        res_df.loc[n+1, covar_solver.ekf.dae.x] = np.array(x_prior).flatten()
        A = covar_solver.ekf.jac_f_x(
            x0,z_,_u,p,_r,_y,0,0,0
        )
        # obtain linearization of h(x) (usually just [1, 0, ..., 0]):
        C = covar_solver.ekf.jac_h(
            x0,z_,_u,p,_r,_y,0,0,0
        )
        Ad = ca.expm(A*covar_solver.ekf.dt)
        P_prior = covar_solver.ekf.one_sample_state_covariance(
            Ad, P0, Q
        )
        V = covar_solver.ekf.output_covariance(
            C, P_prior, R
        )
        K = covar_solver.ekf.kalman_gain(
            C, P_prior, V
        )
        state_corr = covar_solver.ekf.state_correction(
            _y, x_prior, C, K
        )
        x_posterior, e = state_corr[0], state_corr[1]
        P_posterior = covar_solver.ekf.state_covariance_correction(
            C, K, P_prior
        )
        x0 = x_posterior
        loglik = (1/2)*(covar_solver.ekf.log_det_R(V) + e.T@ca.inv(V)@e + covar_solver.ekf.n_y*ca.log(2*ca.pi))
    res_df.index = y_data.index
    """
    
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
    
    

    