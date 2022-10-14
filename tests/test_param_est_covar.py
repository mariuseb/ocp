#from ast import Param
from lib2to3.pygram import python_symbols
from sysid.param_est import ParameterEstimation
import numpy as np
import json
import casadi as ca
import sysid.dae as dae
import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint


pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option('display.width', 1000)

def prepare_data(path, sampling_time="15min"):
    """
    Prepare data for sysid experiment.
    """
    data = pd.read_csv(path)
    # dt is 30 seconds:
    data.index = pd.TimedeltaIndex(data["Unnamed: 0"])
    data.index.name = "time"
    downsample = True
    sampling_time = "15min"
    dt = 900
    
    if downsample:
        
        heat = data[["phi_h", "phi_s"]]
        heat = heat.resample(sampling_time).mean()

        rest = data[["Ti", "Ta"]]
        rest = rest.resample(sampling_time).first()

        y_data = pd.merge(heat, rest, left_index=True, right_index=True)
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*900, 900)
        y_data.to_csv(path.rstrip(".csv") + "_15min.csv")
    else:
        
        y_data = data
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*30, 30)
        
    return y_data

if __name__ == "__main__":
    
    cfg_path = "2R2C.json"
    
    ################### PRBS ######################
    
    data_path = "data/data_ZEBLL_PRBS.csv"
    
    y_data = prepare_data(data_path)
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    # TODO: heuristic for initial guesses:
    param_guess = ca.DM([0.01,0.1,1E6,1E7,2])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    #ubp = ca.DM([0.1,1,1E7,1E8,50])
    lbp = param_guess/10
    ubp = param_guess*10
    
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )
    
        #pprint(params)
        
        #ax = sol["Ti"].plot(color="grey")
        #ax = y_data["Ti"].plot(color="black", linestyle="dashed")
        #ax.legend(["Estimated", "True"])
        #plt.show()
        
    params_vals = ca.DM(params.values)
    params_PRBS = params
    
    P0 = param_est.get_initial_arrival_cost_weight(params_vals, R, Q)
    covar_prbs, fisher_prbs = param_est.get_covar_p(params_vals, R, Q)
    covar_x_prbs, fisher_x_prbs = param_est.get_covar_x(params_vals, R, Q)
    
    ################### HYSTERESIS ########################
    
    data_path = "data/data_ZEBLL_hysteresis.csv"
    
    y_data = prepare_data(data_path)
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )
    
        #pprint(params)
        
        #ax = sol["Ti"].plot(color="grey")
        #ax = y_data["Ti"].plot(color="black", linestyle="dashed")
        #ax.legend(["Estimated", "True"])
        #plt.show()
        
    params_vals = ca.DM(params.values)
    
    covar_hys, fisher_hys = param_est.get_covar_p(params_vals, R, Q)
    covar_x_hys, fisher_x_hys = param_est.get_covar_x(params_vals, R, Q)
    #Q = ca.DM(2,2)
    #Q[0,0] = 2
    #Q[1,0] = 10
    #Q[1,1] = -4
    #Q[0,1] = 3
    
    # log det test:
    #log_det_Q = param_est.log_det_Q(param_est.Q)
    #hess_log_det_Q = ca.hessian(log_det_Q, ca.vec(param_est.Q))
    #hess_func = ca.Function("hess_log_det_Q",
    #                        [ca.vec(param_est.Q)],
    #                        [hess_log_det_Q[0]]) 
    
    ###### TODO: add log(det(Q)) + log(det(R))
    ###### for Fisher information calculation
    
    #std_dev = ca.sqrt(covar)   
    #fisher_diag_hys = ca.diag(ca.sqrt(ca.inv(covar_hys.values)))
    #fisher_diag_hys_norm = fisher_diag_hys/params.values
    
    #fisher_diag_prbs = ca.diag(ca.inv(ca.sqrt(covar_prbs.values)))
    #fisher_diag_prbs_norm = fisher_diag_prbs/params_PRBS.values

    fisher_diag_hys = ca.diag(fisher_hys.values)
    fisher_diag_prbs = ca.diag(fisher_prbs.values)
    fisher_diag_hys_norm = fisher_diag_hys/params.values
    
    fisher_diag_prbs_norm = fisher_diag_prbs/params_PRBS.values

    print(covar_prbs)
    print(covar_hys)
    
    """
    obj_f = param_est.alt_obj
    x_info = param_est.nlp_parser["x"]
    p_info = param_est.nlp_parser["p"]
    u_info = param_est.nlp_parser["u"]
    y_info = param_est.nlp_parser["y"]
    #p = param_est.nlp["x"][p_info["range"]["a"]:p_info["range"]["b"]]
    x = param_est.nlp["x"][x_info["range"]["a"]:x_info["range"]["b"]]
    u = param_est.nlp["x"][u_info["range"]["a"]:u_info["range"]["b"]]
    y = param_est.nlp["x"][y_info["range"]["a"]:y_info["range"]["b"]]
    p = param_est.dae.dae.p
    # Q:
    Q_num = Q
    R_num = R
    Q = param_est.Q
    R = param_est.R
    
    hess_expr = ca.hessian(obj_f, ca.vertcat(*p, x, u, y, ca.vec(R), ca.vec(Q)))[0]
    
    # actual objective function can only be used
    # to find covariance of noise estimates..
    hess_obj = ca.Function(
                           "hess_obj",
                            p + [x, u, y, ca.vec(R), ca.vec(Q)],
                           [hess_expr],
                           param_est.dae.p + ["x", "u", "y", "R", "Q"],
                           ["hess_obj"]
                           )
    
    hess_val = hess_obj(params_vals[0],
                        params_vals[1],
                        params_vals[2],
                        params_vals[3],
                        params_vals[4],
                        sol[param_est.dae.x].values.flatten(),
                        sol[param_est.dae.u].values.flatten(),
                        sol[param_est.dae.y].values.flatten(),
                        ca.vec(R_num),
                        ca.vec(Q_num)
                        )
    # covariance of the parameters:    
    covar = ca.inv(hess_val[:5,:5])
    """