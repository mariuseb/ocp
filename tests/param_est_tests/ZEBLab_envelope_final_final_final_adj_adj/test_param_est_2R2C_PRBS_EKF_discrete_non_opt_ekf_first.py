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
from ocp.filters import KalmanBucy, KalmanDAE
from ocp.utils import prepare_data, ZEBData
from ocp.covar_solver_cont import CovarianceSolverContinuous
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
    ekf_config = os.path.join("configs/ekf_configs", "2R2C_envelope_EKF.json") 
    P0 = np.eye(2)*np.diag([0.026, 0.666])**2
    ekf = KalmanDAE(ekf_config, P0=P0)
    Q_guess = np.array(
        ca.veccat(
                ca.DM.eye(ekf.dae.n_x),
                )
        ).flatten()*1e-3
    R_guess = np.array(ca.DM.eye(ekf.dae.n_y)).flatten()*1e-3

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
     

    ekf.set_Q(Q)
    ekf.set_R(R)
    # first state:
    x0 = sol[["Ti", "Te"]].iloc[0].values
    
    result = pd.DataFrame(
                        index=range(N),
                        columns=["res", "y_pred","y_meas"] + ekf.dae.x + ekf.p_cols
                        )
    result.loc[0, "y_pred"] = float(np.array(x0)[0])
    result.loc[0, "y_meas"] = y_data[ekf.dae.y_names].iloc[0].values
    I = param_est.integrator.one_sample
    
    for n in range(N-1):   
        
        u = y_data[ekf.dae.u_names].iloc[n].values
        r = y_data[ekf.dae.r_names].iloc[n].values
    
        x_pred = I(x0,0,u,params,r,0)
        result.loc[n+1, "y_pred"] = float(np.array(x_pred)[0])
        #x_pred = I(x0,z_pred,u,p,r)
        
        #xs = np.append(xs, np.array(x_pred))    
        # filtering of prediction:s
        residual_cols = list(map(lambda x: x + "_res", ekf.y))

        x0, z0, h0 = ekf.estimate(
                                x_pred,
                                #z=z_pred,
                                z=np.array([]),
                                p=params.values,
                                y=y_data[ekf.dae.y_names].iloc[n+1].values,
                                u=y_data[ekf.dae.u].iloc[n].values,
                                r=y_data[ekf.dae.r_names].iloc[n].values
                            )
        result.loc[n+1, "y_meas"] = float(y_data[ekf.dae.y_names].iloc[n+1].values)
        result.loc[n+1, ekf.dae.x] = x0

    # last iteration, only prediction:
    result.loc[n, ekf.y] = h0
    #result.loc[n, "x_filt"] = float(x0[0])
    # set filtered values:
    result.loc[n, ekf.dae.x] = x0

    
    
    

    