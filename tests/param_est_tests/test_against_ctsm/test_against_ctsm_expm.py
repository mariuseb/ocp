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
from ocp.filters import KalmanBucy, KalmanDAE
from utils import prepare_data, ZEBData, quick_plot
from result_generator import ResultGenerator
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

    cfg_path = os.path.join("configs", "2R2C_simple.json")
    #ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_int_gains_sep_bal_vent.json"
    ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_simple.json"
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
        "u_nom": [12]*6 + [1E3,1E3,10],
        "u_nom_b ": [289.15]*6 + [0]*3,
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
    plot = True
    
    # clean P_rad_219:
    Data.data.P_rad_219[Data.data.P_rad_219 < 0] = 0
    #Data.data.P_rad_219 = Data.data.P_rad_219.shift(-1)
    
    stop = start + pd.Timedelta(days=1) 
    y_data = Data.get_dataset(start=start, stop=stop)
    y_data = y_data.groupby(pd.Grouper(freq='5min')).mean().dropna()
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

    y_data = y_data.bfill()
    y_data = y_data.groupby(pd.Grouper(freq='5min')).mean().dropna()
    y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
    
    #plt.close()
    
    """
    Instead of using rule-of-thumb Q,R,
    use symbolic EKF to find optimal Q,R.
    
    Log-likelihood needs to be conditioned 
    on one-step ahead prediction now.
    
    Try to set up optimization problem here:
    """
    params = pd.read_csv("parameters.csv", index_col=0).squeeze()
    params_sd = pd.read_csv("parameter_sd.csv", index_col=0).squeeze()
    one_step_pred = pd.read_csv("one_step_pred.csv", index_col=0).shift(-1)
    one_step_pred.index = range(len(one_step_pred))
    one_step_pred_sd = pd.read_csv("one_step_pred_sd.csv", index_col=0)
    
    P0 = np.diag(one_step_pred_sd.iloc[0].values**2)
    
    one_step_pred_sd = one_step_pred_sd.shift(-1)
    one_step_pred_sd.index = range(len(one_step_pred_sd))
    one_step_pred_var =  one_step_pred_sd**2  # sd -> covar**2
    
    ekf = KalmanBucy(ekf_config)
    F = ekf.one_sample_feedback_adj
    # multiple shooting discretization:
    M = param_est.N - 1
    F_map = F.mapaccum("simulator", M, [0,1], [0,1])
    """
    Proof-of-correctness for Kalman filter
    implementations.
    """
    x0 = params.loc[["Ti0", "Te0"]].values
    #P0 = np.diag(params_sd.loc[["Ti0", "Te0"]].values**2)
    #P0 = np.diag(one_step_pred_sd.loc[1].values**2)
    
    _params = params.loc[param_est.dae.p].values
    Rval = np.array(params["e11"])
    Qval = np.diag(params.loc[["p11", "p22"]])
    
    res = F_map(
        x0=x0,
        #z0=Z,
        P_prev=P0,
        u=y_data[param_est.u_names][0:M].values.T,
        r=y_data[param_est.r_names][0:M].values.T,
        p=ca.repmat(_params,1,M),
        y=y_data[param_est.y_names][1:M+1].values.T,
        Q=ca.repmat(Qval,1,M),
        R=ca.repmat(Rval,1,M)
    ) 
    x_pred = pd.DataFrame(
                          data=np.array(res["x_pred"]).T,
                          columns=["Ti", "Te"],
                          )
    x_pred["Ti_correct"] = one_step_pred["Ti"].iloc[:len(x_pred)]
    n_x = ekf.dae.n_x
    P_hat = pd.DataFrame(
                         data=np.array(res["P_apriori"].reshape((n_x*n_x, M))).T,
                         columns=[
                                  "p" + str(j) + str(i)
                                  for j in range(1,n_x+1)
                                  for i in range(1,n_x+1)
                                  ],
                         )
    P_hat = np.sqrt(P_hat)
    P_hat["p11_true"] = one_step_pred_sd["Ti"]
    P_hat["p22_true"] = one_step_pred_sd["Te"]
    
    """
    Set up optimization problem:
    """
    
    # set up variables:
    X0 = ca.MX.sym("X0", (ekf.n_x, 1))
    #Z = ca.MX.sym("Z", (ekf.n_z, M))
    P = ca.MX.sym("P", (ekf.n_x, ekf.n_x))
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
        x0=X0,
        #z0=Z,
        P_prev=P[:, :-ekf.n_x],
        u=U,
        r=r,
        p=ca.repmat(p,1,M),
        y=Y,
        Q=ca.repmat(Q,1,M),
        R=ca.repmat(R,1,M),
        #dt=300
    )
    # for objective function:
    V_N = res["V_k"]
    e_N = res["e_k"]
    # for shooting constraints:
    P_hat = res["P_hat"]
    x_hat = res["x_hat"]
    loglik = res["loglik"]
    # shooting constraints:
    #x_constr = ca.veccat(x_hat - X[:, 1:])
    #P_constr = ca.veccat(P_hat - P[:, ekf.n_x:])

    obj = 0
    for n in range(M): # only 1-dim:
        #obj += ca.inv(V_N[n])@ca.dot(e_N[n], e_N[n])
        #obj += e_N[n].T@ca.inv(V_N[n])@e_N[n]
        #obj += param_est.log_det_R(V_N[n])
        #obj += ca.log(ca.det((V_N[n])))
        #obj += ca.log(V_N[n])
        obj += loglik[n]
        
    # first, fix P0
    _p = ca.veccat(U,r,p,Y)
    V = ca.veccat(X0,P,Q,R)
    #g = ca.vertcat(x_constr, P_constr, Q[1,0], Q[0,1])
    g = ca.vertcat(Q[1,0], Q[0,1])
    # add constraints on off-diagonal elems for Q:
    #lbg = np.zeros(g.shape[0])
    #ubg = np.zeros(g.shape[0])
    lbg = np.ones(g.shape[0])*-1000
    ubg = np.ones(g.shape[0])*1000
    
    ll_nlp = {
        "f": obj,
        "x": V,
        "g": g,
        "p": _p
    }
    opts = param_est.opt
    #opts["ipopt.tol"] = 1e-10
    opts["verbose"] = False
    opts["ipopt.linear_solver"] = "ma57"
    ll_solver = ca.nlpsol("ll_solver",  "ipopt", ll_nlp, opts)
    
    # construct numerical bounds for ll-opt:
    p_val = np.concatenate([
        y_data[param_est.u_names][0:M].values.flatten(),
        y_data[param_est.r_names][0:M].values.flatten(),
        _params,
        y_data[param_est.y_names][1:M+1].values.flatten()
    ])
    
    #_x_guess = sol[["Ti", "Te"]].iloc[0].values.flatten()
    _x_guess = np.array([20.48625, 18.56523])
    _lbx = 0.99*_x_guess
    _ubx = 1.01*_x_guess
    
    P_guess = np.array(ca.DM.eye(ekf.dae.n_x)).flatten()
    #P_guess = np.diag([3532.547, 3581.484]).flatten()
    P_guess = P0.flatten()
    
    """
    Test one-sample Wiener integrator:
    """
    wiener_I = ekf.one_sample_wiener
    res = wiener_I(
        P0=ca.DM.zeros(n_x,n_x),
        x0=x0,
        u=y_data[param_est.u_names].iloc[0].values.T,
        r=y_data[param_est.r_names].iloc[0].values.T,
        p=_params,
        y=y_data[param_est.y_names].iloc[1].values.T,
        Ps=1,
        sigma=Qval,
        dt=300
    )
    #P_guess[1] = 0
    #P_guess[2] = 0
    #lbP = 1E-5*P_guess
    lbP = 1E-5*P_guess
    ubP = 1E3*P_guess
    
    Q_guess = Qval.flatten()
    R_guess = Rval.flatten()
    Q_guess = np.array(ca.DM.eye(ekf.dae.n_x)).flatten()*-10
    R_guess = np.array(ca.DM.eye(ekf.dae.n_y)).flatten()*-10
    
    _x0 = np.concatenate([_x_guess, P_guess, Q_guess, R_guess])
    #lbx = np.concatenate([_lbx, lbP, Q_guess*0.1, R_guess*1E-4])
    lbx = np.concatenate([_lbx, lbP, 5*Q_guess, 5*R_guess])
    ubx = np.concatenate([_ubx, ubP, -1*Q_guess, -1*R_guess])
    #lbx = np.concatenate([_lbx, lbP, -5E1*Q_guess, -5E1*R_guess])
    #ubx = np.concatenate([_ubx, ubP, 1E1*Q_guess, 1E1*R_guess])
    
    #Q_guess *= -10
    #R_guess *= -10

    _sol = ll_solver(x0=_x0,
                        lbx=lbx,
                        ubx=ubx,
                        #ubg=ubg,
                        #lbg=lbg,
                        p=p_val
                        )
    
    Q = np.diag(np.array([_sol["x"][-5], _sol["x"][-2]]).flatten())
    P0 = np.diag(np.array([_sol["x"][2], _sol["x"][5]]).flatten())
    R = np.diag(np.array([_sol["x"][-1]]).flatten())
    #R = np.array([0.12E-1])
    #Q = np.diag([1,1])
    #R = np.diag([1])
    print(Q, R, P0)
        
    res = F_map(
        x0=x0,
        #z0=Z,
        P_prev=P0,
        u=y_data[param_est.u_names][0:M].values.T,
        r=y_data[param_est.r_names][0:M].values.T,
        p=ca.repmat(_params,1,M),
        y=y_data[param_est.y_names][1:M+1].values.T,
        Q=ca.repmat(Q,1,M),
        R=ca.repmat(R,1,M)
    ) 
    x_pred = pd.DataFrame(
                          data=np.array(res["x_pred"]).T,
                          columns=["Ti", "Te"],
                          )
    x_pred["Ti_correct"] = one_step_pred["Ti"].iloc[:len(x_pred)]
    n_x = ekf.dae.n_x
    P_hat = pd.DataFrame(
                         data=np.array(res["P_apriori"].reshape((n_x*n_x, M))).T,
                         columns=[
                                  "p" + str(j) + str(i)
                                  for j in range(1,n_x+1)
                                  for i in range(1,n_x+1)
                                  ],
                         )
    P_hat["p11_true"] = one_step_pred_sd["Ti"]
    P_hat["p22_true"] = one_step_pred_sd["Te"]
    
    print(x0)
