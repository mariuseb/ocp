#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
from ocp.mhe import MHE
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
from ocp.filters import KalmanBucy
from utils import prepare_data, ZEBData, quick_plot
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
    Proof of concept for grey-box SYSID, ZEB Lab.
    Use room 219 first.
    """

    #cfg_path = os.path.join("configs", "2R2C.json")
    cfg_path = os.path.join("configs", "2R2C_det_vent_tvp_vent_no_conns.json")
    #data_path = os.path.join("ZEBLab_2years_60m.csv")
    data_path = os.path.join("ZEBLab_jan24_1m.csv")

    Data = ZEBData(data_path)
    #Data.data = Data.data.bfill()
    #Data.data.index.name = "time"
    #Data.data = Data.data.groupby(pd.Grouper(freq='60min')).mean().dropna()
    start = pd.Timestamp("2024-01-01 00:00")
    stop = pd.Timestamp("2024-01-29 00:00")
    
    y_data = Data.get_dataset(start=start, stop=stop)

    #y_data = prepare_data(data)
    y_data = y_data.bfill()
    #y_data = y_data.resample(rule="1H").mean()
    y_data = y_data.groupby(pd.Grouper(freq='5min')).mean().dropna()
    # some temps missing?:

    fig, axes = plt.subplots(1,1,sharex=True)
    quick_plot(axes, y_data)
    plt.show()
    
    ax = y_data.Tset.plot(drawstyle="steps-post")
    y_data.Ti.plot(drawstyle="steps-post", ax=ax)
    ax1 = ax.twinx()
    y_data.phi_s.plot(drawstyle="steps-post", ax=ax1, color="y")
    y_data.phi_h.plot(drawstyle="steps-post", ax=ax1, color="r", linewidth=0.5)
    y_data.phi_int.plot(drawstyle="steps-post", ax=ax1, color="b", linewidth=0.5)
    plt.show()
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification:
    y_data.index = range(0,N*dt,dt)
    
    param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rie_a": 
                    {
                        "init": 1e-2,
                        "lb": -1,
                        "ub": 1
                    },
                    "Rea":
                    {
                        "init": 1e-2
                    },
                    "Rea_a":
                    {
                        "init": 1e-2,
                        "lb": -1,
                        "ub": 1
                    },
                    "Ci":
                    {
                        "init": 1e6
                    },
                    "Ci_a":
                    {
                        "init": 1e6,
                        "lb": -1e7,
                        "ub": 1e7
                    },
                    "Ce":
                    {
                        "init": 1e6,
                        "ub": 1e8
                    },
                    "Ce_a":
                    {
                        "init": 1e6,
                        "lb": -1e8,
                        "ub": 1e8
                    },
                    "Ai":
                    {
                        "init": 10
                    },
                    "Ae":
                    {
                        "init": 10
                    },
                    "cp_air":
                    {
                        "init": 1000,
                        "lb": 1000,
                        "ub": 1000
                    },
                    "alpha_vent":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_int":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_vent_1":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_vent_2":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "R_121_e":
                    {
                        "init": 1
                    },
                    "R_321_e":
                    {
                        "init": 1
                    },
                    "R_320_e":
                    {
                        "init": 1
                    },
                    "R_121_i":
                    {
                        "init": 1e-1
                    },
                    "R_321_i":
                    {
                        "init": 1e-1
                    },
                    "R_320_i":
                    {
                        "init": 1e-1
                    }
    }
 
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2*x_guess

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "z_nom": [1e-2,1e-2,1e6,1e6],
        "z_nom_b": [0]*4,
        "u_nom": [12]*6 + [1E3,1E3,10],
        "u_nom_b ": [289.15]*6 + [0]*3,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }

    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess,
                             **kwargs,
                             ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        
        lbp = param_est.get_lbp(1e-2)
        ubp = param_est.get_ubp(1e2)
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=False
                                      )
        p0 = param_est.p0
        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend(["model", "measured"])
        plt.show()
        print(params)
    
    """
    Test MHE.
    
    Assume area = 60 m^2
    """
    A = 60
    """
    Wh -> J : 3600 s/h
    """
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ai": 10, # m²
        "alpha_vent": 1
        
    }
    for name, value in priors.items():
        param_guess[name]["init"] = value 
        param_guess[name]["lb"] = value*1E-3 
        param_guess[name]["ub"] = value*1E3 
    
    with MHE(config=cfg_path,
            N=N,
            dt=dt,
            param_guess=param_guess,
            arrival_cost=True, # because costate needs to be re-defined
            **kwargs,
            ) as mhe:

        
        lbp = param_est.get_lbp(1e-2)
        ubp = param_est.get_ubp(1e2)
        
        """
        Get all parameters, define custom
        costate suitable for tvp.
        """
        costate_aux = {
                   name: mhe.dae.dae.var(name) 
                   for name in mhe.dae.p
                   }
        
        p_aux = ca.vertcat(
            costate_aux["Rie"],
            costate_aux["Rie"] + costate_aux["Rie_a"],
            costate_aux["Rea"],
            costate_aux["Rea"] + costate_aux["Rea_a"],
            costate_aux["Ci"],
            costate_aux["Ci"] + costate_aux["Ci_a"],
            costate_aux["Ce"],
            costate_aux["Ce"] + costate_aux["Ce_a"],
            costate_aux["Ai"],
            costate_aux["alpha_vent"],
            costate_aux["cp_air"],
            
        )
        
        p_aux_prior = np.array([])
        for name, val in costate_aux.items():
            if name.endswith("_a"):
                val = param_guess[name.replace("_a", "")]["init"]
            else:
                val = param_guess[name]["init"]
                
            p_aux_prior = np.concatenate(
                                        [p_aux_prior,
                                        np.array([val])]
                                        )

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        P0 = ca.DM.eye(p_aux_prior.shape[0] + mhe.n_x)*1e-1
        for n in range(10,13):
            P0[n,n] = 0
        for n in (1,3,5,7):
            P0[n,n] = 1e3
        P0[9,9] = 1E3
        
        sol_mhe, params_mhe = mhe.solve(
                                      y_data,
                                      p0,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      x_guess=x_guess,
                                      x_N=np.array([293.15,293.15]), # not used
                                      p_aux=p_aux,
                                      p_aux_prior=p_aux_prior,
                                      P0=P0,
                                      covar=ca.veccat(Q, R),
                                      codegen=False
                                      )

        sol.index = y_data.dt_index
        ax = sol_mhe["Ti"].plot(color="r")
        sol_mhe["y1"].plot(color="k", ax=ax)
        ax.legend(["model", "measured"])
        plt.show()
        params_mhe.to_csv("results/params_2R2C_vent_tvp_w_prior.csv", index=True)
        print(params_mhe)
    # dump for plots:
    sol_mhe.to_csv("results/sol_2R2C_vent_tvp_w_prior.csv", index=True)
    print(params)
    
    """
    For time-varying EKF:
    """
    p_base = params_mhe.loc[["Rie",
                        "Rea",
                        "Ci",
                        "Ce",
                        "Ai",
                        "cp_air",
                        "alpha_vent"
                        ]]
    
    p_mod = params_mhe.loc[["Rie_a",
                        "Rea_a",
                        "Ci_a",
                        "Ce_a",
                        "Ai",
                        "cp_air",
                        "alpha_vent"
                        ]]
    # set last three to zero:
    p_mod[4:] = 0
    p_base.to_csv("results/tvp_params_base_2R2C_vent_jan24_w_prior.csv", index=True)
    p_mod.to_csv("results/tvp_params_mod_2R2C_vent_jan24_w_prior.csv", index=True)
    print(params)