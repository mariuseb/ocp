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
from ocp.covar_solver_cont_old import CovarianceSolverContinuous
from copy import deepcopy
from result_generator import ResultGenerator, plot_residuals
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

def quick_plot(ax, y_data):
    """
    A quick plot of the data required
    for envelope identification.
    """
    y_data.y1.plot(ax=ax)
    #for col in ["T_207", "T_211", "T_213", "T_217"]:
    #    y_data[col].plot(ax=ax, linewidth=0.5)
    ax.legend()
    ax1 = ax.twinx()
    y_data.phi_h.plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    #P_vent = y_data.V_sup_air*(y_data.T_sup_air - y_data.Ti)
    #P_vent.plot(ax=ax1, color="g", linewidth=0.75)
    ax1.legend(["calculated from OE16 V_flow, delta T", ""])
    

if __name__ == "__main__":

    """
    sysid using PRBS.
    """

    cfg_path = os.path.join("configs", "2R2C.json")
    data_path = os.path.join("ZEBLab_dec24_jan25_1m.csv")

    zeb_data = ZEBData(data_path)
    
    start = pd.Timestamp("2024-12-21 09:30")
    stop = pd.Timestamp("2024-12-31 00:00")
    #start = pd.Timestamp("2024-12-20 09:30")
    start = pd.Timestamp("2024-12-28 06:00")
    start = pd.Timestamp("2025-01-01 00:00")
    #stop = pd.Timestamp("2025-01-01 06:00")
    stop = pd.Timestamp("2025-12-31 00:00")
    sampling_rate = "15min"
    
    # interpolate away nan's, see if good enough:
    y_data, dt, N = zeb_data.get_dataset(
                                        start=start, 
                                        stop=stop,
                                        sampling_rate=sampling_rate
                                        )
    y_data.index = y_data.dt_index
    # shift phi_h one time step forward:
    #y_data["phi_h"] = y_data["phi_h"].shift(-1)
    #y_data["phi_h"] = y_data["phi_h"].bfill()
    
    fig, axes = plt.subplots(1,1,sharex=True)
    quick_plot(axes, y_data)
    plt.show() 

    param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rih": 
                    {
                        "init": 1e-3
                    },
                    "Rie_w": 
                    {
                        "init": 1e-2
                    },
                    "Rie_v": 
                    {
                        "init": 1e-2
                    },
                    "Rea":
                    {
                        "init": 1e-1
                    },
                    "Rea_w":
                    {
                        "init": 1e-1
                    },
                    "Rea_v":
                    {
                        "init": 1e-1
                    },
                    "Ci":
                    {
                        "init": 1e6
                    },
                    "Ch":
                    {
                        "init": 1e6
                    },
                    "Ci_w":
                    {
                        "init": 1e6
                    },
                    "Ci_v":
                    {
                        "init": 1e6
                    },
                    "Ce":
                    {
                        "init": 1e6
                    },
                    "Ce_w":
                    {
                        "init": 1e6
                    },
                    "Ce_v":
                    {
                        "init": 1e6
                    },
                    "Ai":
                    {
                        "init": 10
                    },
                    "Ai_high":
                    {
                        "init": 10
                    },
                    "cp_air":
                    {
                        "init": 1,
                        "lb": 1,
                        "ub": 1
                    },
                    "alpha_vent_sup":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_vent_ext":
                    {
                        "init": 1E-4
                    },
                    "alpha_int":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_occ":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 5
                    },
                    "alpha_int_lig":
                    {
                        "init": 1e-2,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_int_plugs":
                    {
                        "init": 1e-2,
    #                    "lb": 1E-3,
                        "ub": 1
                    }
    }

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12]*3 + [1E3,1E3],
        "u_nom_b ": [289.15]*3 + [0]*2,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    A = 60
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rie_w": 0.250/A, # m²K / W 
        "Rie_v": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Rea_w": 2.250/A, # m²K / W 
        "Rea_v": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ci_w": 9.50*3600*A, # Wh / m²K
        "Ci_v": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ce_w": 112*3600*A, # Wh / m²K
        "Ce_v": 112*3600*A, # Wh / m²K
        "Ai": 10, # m²
        "Ai_high": 10, # m²
        "alpha_vent_sup": 1e-2,
        "alpha_vent_ext": 1e-2,
        "alpha_int": 1e-2,
        "alpha_occ": 1e-2
    }
    for name, value in priors.items():
        param_guess[name]["init"] = value 
        if not name.startswith("alpha"):
            param_guess[name]["lb"] = value*1E-3 
            param_guess[name]["ub"] = value*1E3 
        else:
            param_guess[name]["lb"] = value
            param_guess[name]["ub"] = value
            
        
    #param_guess["Rea"]["ub"] = 1
    #param_guess["Ce"]["ub"] = 5e7

    #param_guess["alpha_int_lig"]["ub"] = 1.0
    #param_guess["alpha_int_plugs"]["ub"] = 1.0
    #param_guess["alpha_vent_sup"]["ub"] = 1e-3
    #param_guess["alpha_vent_ext"]["ub"] = 1e-3
    #param_guess["alpha_int"]["ub"] = 1e-3
    #param_guess["alpha_occ"]["ub"] = 1e-3
     
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.y1.values.flatten(),
                    y_data.y1.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess

    params_start = pd.DataFrame.from_dict(data=priors, orient="index")
    params_start.loc[["Rie", "Rea", "Ci", "Ce", "Ai"]].to_csv("2R2C_start.csv")

    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=True,
                    **deepcopy(kwargs)
                    ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
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
        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        sol["phi_s"].plot(drawstyle="steps-post",ax=ax1)
        sol["phi_h"].plot(drawstyle="steps-post",ax=ax1)
        plt.show()
     
     
    ekf_config = os.path.join("configs/ekf_configs", "2R2C_envelope_EKF.json") 
    #covar_kwargs = kwargs
    covar_kwargs = dict()
    covar_kwargs["p_nom"] = p_nom
    """
    covar_kwargs["P_nom"] = [
                             [1e-4]*3,
                             [1e-1]*3,
                             [1e-2]*3
                             ]
    for col in y_data.columns:
        if col.startswith("T") or col.startswith("y"):
            y_data[col] += 273.15
    """
    
    y_data = y_data[:-1]      
    #y_data = y_data.iloc[200:300]
    covar_solver = CovarianceSolverContinuous(
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
    P0 = np.eye(2)*np.diag([0.026, 0.666])**2
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
    x0 = sol[["Ti", "Te"]].iloc[0].values
    H = np.eye(covar_solver.n_theta + covar_solver.n_y)*0
    covar_solver.exchange_P0_constraint(P0_guess)
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
    # round first entry to 0:
    Q[0,0] = 0
    # one-step simulation, optimized parameters vs. non-optimized:
    result_gen = ResultGenerator(
                    config=cfg_path,
                    ekf_config=ekf_config,
                    params=param_guess,
                    slack=False,
                    dt=dt
                    )   
    # one-step simulation, plot:
    result_gen.simple_one_step_plot(
        y_data,
        covar_sol[param_est.dae.x],
        params,
        ekf_config=ekf_config,
        map_eval=True,
        symbolic_estimate=True, 
        R=R,
        Q=Q,
        P0x=P0_guess.reshape((param_est.n_x, param_est.n_x))
    )
    mse_opt = result_gen.mse(
                result_gen.filtered.y_meas, 
                result_gen.filtered.y_pred
                             )
    # write
    # one-step simulation, plot:
    Q = np.array(
                ca.DM.eye(covar_solver.ekf.dae.n_x),
        )*1e-3
    R = np.array(ca.DM.eye(covar_solver.ekf.dae.n_y))*1e-3
    result_gen.simple_one_step_plot(
        y_data,
        covar_sol[param_est.dae.x],
        params,
        ekf_config=ekf_config,
        map_eval=True,
        symbolic_estimate=True, 
        R=R,
        Q=Q,
        P0x=P0_guess.reshape((param_est.n_x, param_est.n_x))
    )
    mse_non_opt = result_gen.mse(
                result_gen.filtered.y_meas, 
                result_gen.filtered.y_pred
                             )
    print(params)
    
    

    