#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
#from ocp.param_est import ParameterEstimation
#from ocp.mhe import MHE
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
from ocp.filters import KalmanBucy
from utils import prepare_data, ZEBData, quick_plot
from result_generator import ResultGenerator
from ocp.filters import KalmanDAE
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

    cfg_path = os.path.join("configs", "2R2C_int_gains_sep_bal_vent_NL.json")
    ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_int_gains_sep_bal_vent.json"
    #data_path = os.path.join("ZEBLab_jan_mar24_1m.csv")
    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    #data_path = os.path.join("ZEBLab_nov23_1m.csv")
    ekf = KalmanDAE(ekf_config)
    Data = ZEBData(data_path)

    ### for first pass:
    param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rea":
                    {
                        "init": 1e-1
                    },
                    "Ci":
                    {
                        "init": 1e6
                    },
                    "Ce":
                    {
                        "init": 1e6,
                        "ub": 1e9
                    },
                    "Ai":
                    {
                        "init": 10
                    },
                    "cp_air":
                    {
                        "init": 1,
                        "lb": 1,
                        "ub": 1
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
                    "alpha_int_lig":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_int_plugs":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    }
    }


    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12]*6 + [1E3,1E3,1E3,1E3,10],
        "u_nom_b ": [289.15]*6 + [0]*5,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    A = 60
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ai": 10, # m²
        "alpha_vent": 1,
        "alpha_int_plugs": 1,
        "alpha_int_lig": 1  
    }
    
    results = {}
    #start = pd.Timestamp("2024-01-01 00:00")
    start = pd.Timestamp("2023-11-15 00:00")
    #start = pd.Timestamp("2024-01-01 00:00")
    
    alpha0 = 0.5
    #alpha0 = 0.1
    decay_rate = 0.2
    params_hist = pd.DataFrame(columns=list(param_guess.keys()))
    plot = True
        
    for delta_day in range(20):
        
        stop = start + pd.Timedelta(days=14)
        y_data = Data.get_dataset(start=start, stop=stop)
        
        if not y_data.Ti.isna().any():
            """
            Skip if any holes in temperature
            """    
            y_data = y_data.bfill()
            y_data = y_data.groupby(pd.Grouper(freq='5min')).mean().dropna()
            
            """
            ax = y_data[["Ti"]].plot()
            ax1 = ax.twinx()
            y_data[["phi_s"]].plot(ax=ax1, color="y")
            y_data[["phi_h"]].plot(ax=ax1, color="r")
            y_data[["V_sup_air"]].plot(ax=ax1, color="m")
            y_data[["phi_int_plugs"]].plot(ax=ax1, color="k")
            y_data[["phi_int_lig"]].plot(ax=ax1, color="b")
            plt.show()
            
            fig, axes = plt.subplots(1,1,sharex=True)
            quick_plot(axes, y_data)
            plt.show(block=False)
            """
            N = len(y_data)
            dt = (y_data.index[1] - y_data.index[0]).seconds
            # set range index for identification:
            y_data.index = range(0,N*dt,dt)
        
            for name, value in priors.items():
                param_guess[name]["init"] = value 
                if name != "cp_air":
                    param_guess[name]["lb"] = value*1E-3 
                    param_guess[name]["ub"] = value*1E3 
                else:
                    param_guess[name]["lb"] = value 
                    param_guess[name]["ub"] = value 
    
            #param_guess["alpha_int_lig"]["ub"] = 1
            param_guess["alpha_vent"]["ub"] = 1.5
    
            x_guess = np.array([
                            y_data.Ti.values.flatten(),
                            y_data.Ti.values.flatten() - 2
                            ])
            lbx = 0.7*x_guess
            ubx = 2*x_guess

            with Estimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=param_guess,
                            arrival_cost=True,
                            **kwargs,
                            ) as param_est:
                
                Q = ca.DM.eye(2)
                R = ca.DM.eye(1)
                P0 = ca.DM.eye(param_est.n_p + param_est.n_x)
                # no weighting of states:
                for n in range(param_est.n_p, param_est.n_p + param_est.n_x):
                    P0[n,n] = 0
                
                        
                lbp = param_est.get_lbp(1e-2)
                ubp = param_est.get_ubp(1e2)
                
                sol, params = param_est.solve(
                                            y_data,
                                            param_est.p0,
                                            #params.values,
                                            lbp=lbp,
                                            ubp=ubp,
                                            lbx=lbx,
                                            ubx=ubx,
                                            x_guess=x_guess,
                                            x_N = np.array([293.15,293.15]), # not used
                                            P0=P0,
                                            covar=ca.veccat(Q, R),
                                            codegen=True
                                            )
                
            result_gen = ResultGenerator(
                                config=cfg_path,
                                params=params,
                                slack=False,
                                dt=param_est.dt
                                )
        
            x0 = sol[result_gen.x].iloc[0]
        
            result_gen.simple_sim_plot(
                                    y_data,
                                    x0,
                                    plot=plot,
                                    map_eval=True
                                    )            
            plt.show(block=True)
            #plt.close()
            # obtain one-step ahead estimate:
            
            result_gen.simple_one_step_plot(
                                            y_data,
                                            x0, 
                                            p_base=params,
                                            #p_mod=p_mod,
                                            p_tvp=params.values,
                                            tvp=False,
                                            ekf_config=ekf_config,
                                            cond_series=y_data.V_sup_air,
                                            plot=plot,
                                            map_eval=True
                                            )   
            plt.show(block=True)
            #plt.close()
            train_metrics = result_gen.report_metrics("training")
            y_data = Data.get_dataset(
                            start = stop,
                            stop = stop + pd.Timedelta(days=1)
                            )  
                      
            if y_data.Ti.isna().any():
                # check what happens
                print(params)
                
            y_data_raw = y_data.bfill()
            y_data_raw.index.name = "time"
            y_data = y_data_raw.groupby(pd.Grouper(freq='5min')).mean() #.dropna(axis=1)
            x0 = result_gen.filtered[result_gen.x].iloc[-1]
            #x0 = sol[result_gen.x].iloc[-1]
            result_gen.simple_sim_plot(
                            y_data,
                            x0,
                            plot=plot,
                            map_eval=True
                            )
            plt.show(block=True)
            plt.close()
            test_metrics = result_gen.report_metrics("validation (bic, aic not valid)")
            
            if float(test_metrics.loc["mse"]) > 1:
                # check what happens
                print(params)
            
            param_guess = {
                k: {
                    "init": params.loc[k],
                    "lb": 1e-2*params.loc[k],
                    "ub": 1e2*params.loc[k]
                    }
                for k in params.index
            }
            results[start.day] = {
                 #"params": params,
                 "train_metrics": train_metrics,
                 "test_metrics": test_metrics
            }       
            params_hist.loc[delta_day] = params
            # advance 1 day:
            start = start + pd.Timedelta(days=1)
    
        
    print(params)