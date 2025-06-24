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
    sysid, radiator.
    """
    cfg_path = os.path.join("configs", "3state_HVAC_alt_alt_alt.json")
    data_path = os.path.join(
                            "twin_rooms_emulator_PRBS_mod_1min.csv"
                            )
    y_data, N, dt = prepare_data(data_path, rule="5min")
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(
        y_data, 
        load_optimal_rad_params=False,
        load_optimal_env_params=False,
        load_optimal_traj=False,
        n_x=3,
        hvac=True
    )
    y_data = y_data[:-4]
    N = len(y_data)
    #y_data["Prad"] = sol_rad["Prad"]
    _sol_rad = pd.read_csv(
        "3state_hvac_model_full_dataset_traj.csv",
        index_col=0
    )
    _sol_rad.index = pd.to_timedelta(
        _sol_rad.index
    )
    _sol_rad = _sol_rad.resample(
        rule="5min"
    ).ffill()
    kwargs = {
        "slack": False,
        #"p_nom": [1]
    }
    rad_est = Estimation(
        config=cfg_path,
        N=N,
        dt=dt,
        param_guess=param_guess,
        truncate_scaling=True,
        arrival_cost=True,
        **deepcopy(kwargs)
    )
    x0 = _sol_rad[rad_est.x_names].iloc[0].values
    #I = rad_est.integrator.one_sample.mapaccum(N-1)
    I = rad_est.integrator.chain_integrator()
    
    """
    sol_rad = I(
        x0=x0,
        #z0=_sol_rad[rad_est.z_names][:-1].values.T,
        u=y_data[rad_est.u_names][:-1].values.T,
        p=_sol_rad[rad_est.p_names].iloc[0].values/rad_est.p_nom,
        r=y_data[rad_est.r_names][:-1].values.T
    )["xf"]
    y_data = y_data[1:]
    x = np.array(sol_rad)
    Prad = 4200*(x[1] - x[0])*x[2]
    y_data["Prad_model"] = Prad
    y_data["Tsup_model"] = x[1]
    y_data["Tret_model"] = x[0]
    y_data["rad_flo_model"] = x[2]
    """
    x = np.array(x0)
    z0 =_sol_rad[rad_est.z_names].iloc[0].values.T
    for n in range(N-1):
        x0 = np.array(
            I(
                x0=x0,
                z0=z0,
                u=y_data[rad_est.u_names].iloc[n].values.T,
                p=_sol_rad[rad_est.p_names].iloc[0].values,
                r=y_data[rad_est.r_names].iloc[n].values.T
            )["x"]
        )
        x = np.vstack([x, x0.T])
        
    x = x.T
    y_data["Tsup_model"] = x[1]
    y_data["Tret_model"] = x[0]
    y_data["rad_flo_model"] = x[2]
    Prad = 4200*(x[1] - x[0])*x[2]
    y_data["Prad_model"] = Prad
    y_data.index = y_data.dt_index
    Prad_model = y_data["Prad_model"]
    Prad_model.index = y_data.dt_index
    """
    sysid, envelope.
    """
    cfg_path = os.path.join("configs", "2R2C.json")
    data_path = os.path.join(
                            "twin_rooms_emulator_PRBS_mod_1min.csv"
                            )
    y_data, N, dt = prepare_data(
        data_path,
        rule="15min",
        integrate_inputs=True
    )
    y_data["Prad_old"] = y_data["Prad"]
    Prad_model = Prad_model.resample(rule="15min").mean()
    Prad_model.index = y_data.index
    y_data["Prad"] = Prad_model
    param_guess, kwargs, lbx, ubx, x_guess = prepare_est(y_data, n_x=2)
    
    kwargs["z_nom"] = [1E4]
    kwargs["z_nom_b"] = [0]
    kwargs["y_nom"] = [12]
    kwargs["u_nom"] = [1E4]
    kwargs["y_nom_b"] = [289.15]
    kwargs["r_nom"] = [12,1E4,1]
    kwargs["r_nom_b"] = [289.15,0,0]
    
    
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
        #P0[3,3] = 1e-2
        #P0[4,4] = 1e-2
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
        #sol["phi_s"].plot(drawstyle="steps-post",ax=ax1)
        #sol["phi_h"].plot(drawstyle="steps-post",ax=ax1)
        plt.show()
        #plt.close()
        #params.to_csv("envelope_model_2R2C.csv", index=True)
        #sol.to_csv("simulation_traj_2R2C.csv", index=True)
        print(params) 

    
    

    