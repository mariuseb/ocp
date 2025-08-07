#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
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
from ocp.filters_old import KalmanBucy, KalmanDAE
from ocp.utils import prepare_data, ZEBData
from ocp.covar_solver_cont_old import CovarianceSolverContinuous
from copy import deepcopy
from utils import prepare_data, prepare_est
from ocp.functions import functions
#from result_generator import ResultGenerator, plot_residuals
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates
    
    

if __name__ == "__main__":

    """
    sysid using PRBS.
    """
    cfg_path = os.path.join("configs", "5R5C_full_NL_flow.json")
    data_path = os.path.join(
                            "twin_rooms_emulator_normal_op_15min.csv"
                            )
    y_data, N, dt = prepare_data(
        data_path,
        rule="15min",
        integrate_inputs=False
    )
    y_data["Prad"] = y_data["Prad_calc"]
    y_data["rad_flo"] = y_data["rad_flo_calc"]
    y_data["rad_219"] = y_data["rad_219"].shift(-1)
    y_data = y_data.iloc[-2*96:]
    N = len(y_data)
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(y_data, n_x=5)
    """
    kwargs["z_nom"] = [1E4]
    kwargs["z_nom_b"] = [0]
    kwargs["y_nom"] = [12]
    kwargs["y_nom_b"] = [289.15]
    kwargs["r_nom"] = [12,1E4,1]
    kwargs["r_nom_b"] = [289.15,0,0]
    kwargs = {
        "slack": False
    }
    """
    #kwargs["z_nom"].extend([1000])
    #kwargs["z_nom_b"].extend([0])
    
    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=True,
                    functions=functions,
                    **deepcopy(kwargs)
                    ) as param_est:

        Q = ca.DM.eye(5)
        R = ca.DM.eye(5)
        R[0,0] = 0
        R[1,1] = 1e-1
        R[2,2] = 1e-7
        R[3,3] = 1e-2
        R[4,4] = 1e-2
        P0 = np.eye(param_est.n_p + param_est.n_x)*1e-8
        last_p_col = param_est.n_p-1
        #P0[last_p_col, last_p_col] = 0
        #P0[last_p_col-1, last_p_col-1] = 0
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
                                      #lbx=lbx,
                                      #ubx=ubx,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=True,
                                      P0=P0,
                                      x_N=x_guess[-1,-param_est.n_x:]
                                      )
        p_nom = param_est.p_nom
        sol.index = y_data.dt_index
        y_data.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        #sol["Prad"].plot(color="g", ax=ax1, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        plt.show()
        
        ax = sol["rad_flo"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y2"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        #sol["Prad"].plot(color="g", ax=ax1, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        plt.show()
        
        ax = sol["Prad"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y3"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        #sol["Prad"].plot(color="g", ax=ax1, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        plt.show()
        
        ax = sol["Tsup"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y5"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        #sol["Prad"].plot(color="g", ax=ax1, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        
        ax1 = ax.twinx()
        plt.show()

        ax = sol["Tret"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y4"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        #sol["Prad"].plot(color="g", ax=ax1, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        ax1 = ax.twinx()
        plt.show()
        
        
        env_params = ["Rie", "Rea", "Ria", "Ci", "Ce", "Ai"]
        rad_params = [ndx for ndx in params.index if ndx not in env_params]
        params[rad_params].to_csv("5state_rad_model_params.csv", index=True)
        
        print(params) 
        
        """
        sol["dT_actual"] = y_data["Tsup"] - y_data["Tret"]
        
        params_start = params.copy()
        for param in ["Ci", "Ce", "Rie", "Rea", "Ai"]:
            params_start.loc[param] = param_guess[param]["init"]
        
        #plt.close()
        params_start.to_csv("envelope_model_2R3C_start.csv", index=True)
        params.to_csv("envelope_model_2R3C_alt_alt.csv", index=True)
        sol.to_csv("simulation_traj_2R3C_alt_alt.csv", index=True)
        p_nom = pd.Series(
            data=param_est.p_nom,
            index=params.index
        )
        p_nom.to_csv("p_nom_2R3C.csv", index=True)
        """

    
    

    