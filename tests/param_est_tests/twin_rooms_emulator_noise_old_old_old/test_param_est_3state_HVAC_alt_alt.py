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
#ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
#sys.path.append(ocp_path)
rc('text', usetex=True)
    
if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    cfg_path = os.path.join("configs", "3state_HVAC_alt_alt_alt.json")
    data_path = os.path.join(
                            "twin_rooms_emulator_PRBS_mod_1min.csv"
                            )
    y_data, N, dt = prepare_data(
        data_path,
        rule="5min",
        integrate_inputs=False
    )
    y_data = y_data[0:12*24]
    N = len(y_data)
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(
        y_data, 
        load_optimal_rad_params=False,
        load_optimal_env_params=False,
        load_optimal_traj=False,
        n_x=3,
        hvac=True
    )
    """
    p_nom = pd.read_csv("p_nom_4R4C.csv", index_col=0)
    kwargs["p_nom"] = list(p_nom.values.flatten())
    kwargs["p_nom_b"] = [0]*len(kwargs["p_nom"])
    kwargs["p_nom"][-5] = 12
    kwargs["p_nom"][-4] = 12
    kwargs["p_nom_b"][-4] = 289.15
    kwargs["p_nom"][-2] = 12
    kwargs["p_nom_b"][-2] = 289.15
    """
    
    Prad_dim = 3000
    param_guess["Prad_dim"] = {
        "init": Prad_dim,
        "lb": Prad_dim,
        "ub": Prad_dim
    }
    kwargs["x_nom"] = [12]*2 + [1e-1]
    kwargs["x_nom_b"] = [289.15]*2 + [0]
    kwargs["z_nom"] = [1e-1,12,2.5E3]
    kwargs["z_nom_b"] = [0,289.15,0]
    kwargs["r_nom"] += [12]
    kwargs["r_nom_b"] += [289.15]
    kwargs["y_nom"] = [1e-1,2.5E3,12,12]
    kwargs["y_nom_b"] = [0,0,289.15,289.15]
    
    kwargs = {
        "slack": False
    }
    
    #param_guess["Ai"]["ub"] = 10
    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=True,
                    functions=functions,
                    **deepcopy(kwargs),
                    ) as param_est:

        Q = ca.DM.eye(param_est.n_x)
        R = ca.DM.eye(param_est.n_y)
        R[0,0] = 1e-1
        #R[1,1] = 1
        R[1,1] = 0
        #R[3,3] = 1e-1
        #R[4,4] = 1e-1
        #R[2,2] = 0
        R[2,2] = 1e-2
        R[3,3] = 1e-2
        #R[2,2] = 0
        #R[3,3] = 0
        
        P0 = np.eye(param_est.n_p + param_est.n_x)*1e-2
        P0[
           param_est.n_p:(param_est.n_p + param_est.n_x),
           param_est.n_p:(param_est.n_p + param_est.n_x)
           ] = 0
        #P0[2,2] = 0
        #P0[5,5] = 1
        
        lbp = param_est.get_lbp(1e-3)
        ubp = param_est.get_ubp(1e3)
        p0 = param_est.p0
        sol, params, raw_sol = param_est.solve(
            y_data,
            p0,
            lbp=lbp,
            ubp=ubp,
            #lbx=lbx,
            #ubx=ubx,
            x_guess=x_guess,
            covar=ca.veccat(Q, R),
            codegen=False,
            P0=P0,
            x_N=x_guess[-1,-param_est.n_x:],
            return_raw_sol=True
        )
        p_nom = param_est.p_nom
        sol.index = y_data.dt_index
        
        fig, axes = plt.subplots(4,1, sharex=True)
        ax = axes[0]
        sol["rad_flo"].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
        sol["rad_flo_set"].plot(ax=ax, color="g", linewidth=0.75, drawstyle="steps-post")
        sol["y2"].plot(ax=ax, color="k", linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        
        ax = axes[1]
        sol["Tsup"].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        sol["y5"].plot(ax=ax, color="k", linewidth=0.75, drawstyle="steps-post")
        sol["m_val_bool"].plot(ax=ax1, color="g", linewidth=0.75, drawstyle="steps-post")
        
        ax = axes[2]
        sol["Tret"].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        sol["y4"].plot(ax=ax, color="k", linewidth=0.75, drawstyle="steps-post")
        sol["m_flow_bool"].plot(ax=ax1, color="g", linewidth=0.75, drawstyle="steps-post")

        ax = axes[3]
        sol["Prad"].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
        #ax1 = ax.twinx()
        sol["y3"].plot(ax=ax, color="k", linewidth=0.75, drawstyle="steps-post")
        sol["m_flow_bool"].plot(ax=ax1, color="g", linewidth=0.75, drawstyle="steps-post")
    
        plt.show()
        
        params.to_csv("3state_hvac_model_full_dataset_params.csv", index=True)
        sol.to_csv("3state_hvac_model_full_dataset_traj.csv", index=True)
        #p_nom = pd.Series(
        #    data=param_est.p_nom,
        #    index=params.index
        #)
        #p_nom.to_csv("p_nom_4R4C.csv", index=True)
        print(params) 

    
    

    