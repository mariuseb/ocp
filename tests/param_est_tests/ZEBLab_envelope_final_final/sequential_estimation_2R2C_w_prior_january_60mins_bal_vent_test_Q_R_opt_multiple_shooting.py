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

    cfg_path = os.path.join("configs", "2R2C_int_gains_sep_bal_vent.json")
    #ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_int_gains_sep_bal_vent.json"
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
                    "alpha_int_lig":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_int_plugs":
                    {
                        "init": 1,
    #                    "lb": 1E-3,
                        "ub": 1
                    }
    }


    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        #"z_nom": [1e-2,1e-1,1E6,1E6],
        #"z_nom_b": [0]*4,
        "u_nom": [12]*7 + [1E3,1E3,1E3,1E3,10,10],
        "u_nom_b ": [289.15]*7 + [0]*6,
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
        "alpha_vent_sup": 1,
        "alpha_vent_ext": 1,
        "alpha_int_plugs": 1,
        "alpha_int_lig": 1  
    }
    
    for name, value in priors.items():
        param_guess[name]["init"] = value 
        if not name.endswith("_a"):
            param_guess[name]["lb"] = value*1E-3 
            param_guess[name]["ub"] = value*1E3 
        #else:
        #    param_guess[name]["lb"] = -value*1E3 
        #    param_guess[name]["ub"] = value*1E3 

    #param_guess["alpha_int_lig"]["ub"] = 1
    param_guess["alpha_vent_sup"]["ub"] = 1.1
    param_guess["alpha_vent_ext"]["ub"] = 1.1
    
    results = {}
    #start = pd.Timestamp("2024-01-01 00:00")
    #start = pd.Timestamp("2023-11-15 00:00")
    #start = pd.Timestamp("2023-12-02 00:00")
    start = pd.Timestamp("2024-01-01 00:00")
    
    alpha0 = 0.5
    #alpha0 = 0.1
    decay_rate = 0.2
    params_hist = pd.DataFrame(columns=list(param_guess.keys()))
    plot = False
    
    # clean P_rad_219:
    Data.data.P_rad_219[Data.data.P_rad_219 < 0] = 0
    #Data.data.P_rad_219 = Data.data.P_rad_219.shift(-1)
    
    stop = start + pd.Timedelta(days=2) 
    y_data = Data.get_dataset(start=start, stop=stop)
    y_data = y_data.groupby(pd.Grouper(freq='60min')).mean().dropna()
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    param_est = Estimation(config=cfg_path,
                N=N,
                dt=dt,
                param_guess=param_guess,
                arrival_cost=True,
                **kwargs,
                )
    param_est.set_hess_obj()
    p0 = param_est.p0
    
    metrics = pd.DataFrame(columns=
                           ["mse",
                            "rmse",
                            "nrmse",
                            "cv-rmse",
                            "r2",
                            "aic",
                            "bic"]
                           )
    
    for delta_day in range(1):
        
        stop = start + pd.Timedelta(days=2)
        y_data = Data.get_dataset(start=start, stop=stop)
        
        if not y_data.Ti.isna().any():
            """
            Skip if any holes in temperature
            """    
            y_data = y_data.bfill()
            y_data = y_data.groupby(pd.Grouper(freq='60min')).mean().dropna()
            y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
            
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
        
    
            x_guess = np.array([
                            y_data.Ti.values.flatten(),
                            y_data.Ti.values.flatten() - 2
                            ])
            lbx = 0.7*x_guess
            ubx = 2*x_guess

            param_guess["alpha_vent_sup"]["ub"] = 1.1
            param_guess["alpha_vent_ext"]["ub"] = 1.1
            
                
            Q = ca.DM.eye(2)
            R = ca.DM.eye(1)
            P0 = ca.DM.eye(param_est.n_p + param_est.n_x)*1
            #for n in (1,3,5,7):
            #    P0[n,n] = 0
            for n in range(param_est.n_p, param_est.n_p + param_est.n_x):
                P0[n,n] = 0
            #P0[9,9] = 1E3
            if delta_day == 0:
                lbp = param_est.get_lbp(1e-2)
                ubp = param_est.get_ubp(1e2)
            else:
                lbp = p0
                ubp = p0
                
            
            sol, params = param_est.solve(
                        y_data,
                        #param_est.p0,
                        p0,
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
                                    map_eval=True,
                                    chained_eval=True
                                    )            
            plt.show(block=True)
            #plt.close()
            
            """
            Instead of using rule-of-thumb Q,R,
            use symbolic EKF to find optimal Q,R.
            
            Log-likelihood needs to be conditioned 
            on one-step ahead prediction now.
            
            Try to set up optimization problem here:
            """
            ekf = KalmanDAE(ekf_config)
            F = ekf.one_sample_feedback_adj
            # multiple shooting discretization:
            M = param_est.N - 1
            F_map = F.map(M)
            # set up variables:
            X = ca.MX.sym("X", (ekf.n_x, M+1))
            #Z = ca.MX.sym("Z", (ekf.n_z, M))
            P = ca.MX.sym("P", (ekf.n_x, (M+1)*ekf.n_x))
            U = ca.MX.sym("U", (ekf.n_u, M))
            r = ca.MX.sym("r", (ekf.n_r, M))
            p = ca.MX.sym("p", ekf.n_p)
            Y = ca.MX.sym("Y", (ekf.n_y, M))
            # start with non-tvp Q, R
            #Q = ca.MX.sym("Q", ca.Sparsity.diag(ekf.n_x))
            #R = ca.MX.sym("R", ca.Sparsity.diag(ekf.n_y))
            Q = ca.MX.sym("Q", (ekf.n_x, ekf.n_x))
            R = ca.MX.sym("R", (ekf.n_y, ekf.n_y))
            # propagate:
            res = F_map(
                x0=X[:, :-1],
                #z0=Z,
                P_prev=P[:, :-ekf.n_x],
                u=U,
                r=r,
                p=ca.repmat(p,1,M),
                y=Y,
                Q=ca.repmat(Q,1,M),
                R=ca.repmat(R,1,M),
                dt=3600
            )
            # for objective function:
            V_N = res["V_k"]
            e_N = res["e_k"]
            # for shooting constraints:
            P_hat = res["P_hat"]
            x_hat = res["x_hat"]
            # shooting constraints:
            x_constr = ca.veccat(x_hat - X[:, 1:])
            P_constr = ca.veccat(P_hat - P[:, ekf.n_x:])

            obj = 0
            for n in range(M): # only 1-dim:
                #obj += ca.inv(V_N[n])@ca.dot(e_N[n], e_N[n])
                obj += e_N[n].T@ca.inv(V_N[n])@e_N[n]
                #obj += param_est.log_det_R(V_N[n])
                #obj += ca.log(ca.det((V_N[n])))
                obj += ca.log(V_N[n])
                
            # first, fix P0
            _p = ca.veccat(U,r,p,Y)
            V = ca.veccat(X,P,Q,R)
            g = ca.vertcat(x_constr, P_constr, Q[1,0], Q[0,1])
            # add constraints on off-diagonal elems for Q:
            lbg = np.zeros(g.shape[0])
            ubg = np.zeros(g.shape[0])
            
            ll_nlp = {
                "f": obj,
                "x": V,
                "g": g,
                "p": _p
            }
            ll_solver = ca.nlpsol("ll_solver",  "ipopt", ll_nlp, param_est.opt)
            
            # construct numerical bounds for ll-opt:
            p_val = np.concatenate([
                y_data[param_est.u_names][0:M].values.flatten(),
                y_data[param_est.r_names][0:M].values.flatten(),
                params.values,
                y_data[param_est.y_names][0:M].values.flatten()
            ])
            
            _x_guess = sol[["Ti", "Te"]].values.flatten()
            _lbx = 0.5*_x_guess
            _ubx = 1.5*_x_guess
            
            P_guess = np.array(ca.veccat(ca.DM.eye(ekf.dae.n_x), ca.repmat(ca.DM.ones(ekf.dae.n_x**2), 1, M))).flatten()
            lbP = -1000*P_guess
            lbP[0] = 0
            lbP[3] = 0
            lbP[4::3] = 0
            ubP = 1000*P_guess
            
            Q_guess = np.array(ca.DM.eye(ekf.dae.n_x)).flatten()
            R_guess = np.array(ca.DM.eye(ekf.dae.n_y)).flatten()
            
            x0 = np.concatenate([_x_guess, P_guess, Q_guess, R_guess])
            lbx = np.concatenate([_lbx, lbP, Q_guess*0, R_guess*0])
            ubx = np.concatenate([_ubx, ubP, Q_guess*1000, R_guess*1000])
            
            _sol = ll_solver(x0=x0,
                             lbx=lbx,
                             ubx=ubx,
                             p=p_val)
            
            # obtain one-step ahead estimate:
            result_gen.simple_one_step_plot(
                                            y_data,
                                            x0, 
                                            p_base=params,
                                            #p_mod=p_mod,
                                            p_tvp=params.values,
                                            tvp=False,
                                            ekf_config=ekf_config,
                                            cond_series=y_data.vent,
                                            plot=plot,
                                            map_eval=True,
                                            switch=None,
                                            symbolic_estimate=True
                                            )   
            plt.show(block=True)
            #plt.close()
            train_metrics = result_gen.report_metrics("training")
            
            """
            Split validation in two:
            """
            
            y_data = Data.get_dataset(
                            start = stop,
                            stop = stop + pd.Timedelta(days=0.5)
                            )  
                      
            if y_data.Ti.isna().any():
                # check what happens
                print(params)
                
            y_data_raw = y_data.bfill()
            y_data_raw.index.name = "time"
            y_data = y_data_raw.groupby(pd.Grouper(freq='60min')).mean() #.dropna(axis=1)
            y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
            x0 = result_gen.filtered[result_gen.x].iloc[-1]
            #x0 = sol[result_gen.x].iloc[-1]
            result_gen.simple_sim_plot(
                            y_data,
                            x0,
                            #plot=plot,
                            plot=plot,
                            map_eval=True,
                            #symbolic_estimate=True
                            )
            plt.show(block=True)
            plt.close()
            test_metrics = result_gen.report_metrics("validation (bic, aic not valid)")
            
            results[delta_day] = {
                 #"params": params,
                 #"train_metrics": train_metrics,
                 "test_metrics": test_metrics
            }       
            
            metrics.loc[delta_day, :] = test_metrics.loc[metrics.columns].values.flatten()
            
            result_gen.simple_one_step_plot(
                                            y_data,
                                            x0, 
                                            p_base=params,
                                            #p_mod=p_mod,
                                            p_tvp=params.values,
                                            tvp=False,
                                            ekf_config=ekf_config,
                                            cond_series=y_data.vent,
                                            plot=plot,
                                            map_eval=True,
                                            switch=None,
                                            symbolic_estimate=True
                                            )   
            plt.show(block=True)
            #plt.close()
            train_metrics = result_gen.report_metrics("training")
            y_data = Data.get_dataset(
                            start = stop + pd.Timedelta(days=0.5),
                            stop = stop + pd.Timedelta(days=1)
                            )  
                      
            if y_data.Ti.isna().any():
                # check what happens
                print(params)
                
            y_data_raw = y_data.bfill()
            y_data_raw.index.name = "time"
            y_data = y_data_raw.groupby(pd.Grouper(freq='60min')).mean() #.dropna(axis=1)
            y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
            x0 = result_gen.filtered[result_gen.x].iloc[-1]
            #x0 = sol[result_gen.x].iloc[-1]
            result_gen.simple_sim_plot(
                            y_data,
                            x0,
                            #plot=plot,
                            plot=plot,
                            map_eval=True,
                            #symbolic_estimate=True
                            )
            plt.show(block=True)
            plt.close()
            
            test_metrics = result_gen.report_metrics("validation (bic, aic not valid)")
            
            results[delta_day + 0.5] = {
                 #"params": params,
                 "train_metrics": train_metrics,
                 "test_metrics": test_metrics
            }      
            
            metrics.loc[delta_day+0.5, :] = test_metrics.loc[metrics.columns].values.flatten() 
            
            
            param_guess = {
                k: {
                    "init": params.loc[k],
                    "lb": 1e-2*params.loc[k],
                    "ub": 1e2*params.loc[k]
                    }
                for k in params.index
            }
            params_hist.loc[delta_day] = params
            # advance 1 day:
            start = start + pd.Timedelta(days=1)
    
            if float(test_metrics.loc["nrmse"]) > 1:
                # check what happens
                print(params)
            p0 = params.values
            
    print(params)