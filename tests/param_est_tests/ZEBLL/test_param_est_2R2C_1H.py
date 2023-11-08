#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.covar_solve_old import CovarianceSolver
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
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

if __name__ == "__main__":
    
    cfg_path = os.path.join(get_opt_config_path(), "2R2C.json")
    data_path = os.path.join(get_data_path(), "data_ZEBLL_PRBS.csv")
    ekf_config = os.path.join(get_opt_config_path(), "2R2C_EKF.json")
    
    data = pd.read_csv(data_path)
    # dt is 30 seconds:
    data.index = pd.TimedeltaIndex(data["Unnamed: 0"])
    data.index.name = "time"

    # try with 15 min, 5 min anything that might give a decent model
    # heat: resample with mean, i.e. integration
    # temperatures, solar irr: instantaneous sampling
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
        
    else:
        
        y_data = data
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*30, 30)
    
    """
    fig, ax = plt.subplots(2,1)
    (y_data.Ti-273.15).plot(color="k", ax=ax[0])
    y_data.phi_h.plot(color="k", ax=ax[1])
    ax[0].set_ylabel(r"Temperature [$^\circ$C]")
    ax[1].set_ylabel(r"Power [W]")
    fig.tight_layout()
    plt.show()
    """
    
    #y_data = y_data.iloc[0:10]
    
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    param_guess = ca.DM([0.01,0.1,1E6,1E7,2])
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,1,1E7,1E8,50])
    #param_guess = ca.DM([0.001,0.009,1,1E6,1E7,1])
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    #    with ParameterEstimation(config=cfg_path,
    #                             data=y_data,
    #                             param_guess=param_guess) as param_est:
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        #Q[0,0] = 6.55919266e-01
        #Q[1,1] = 4.52496393e-01
        #Q[1,0] = 0.01
        #Q[0,1] = 0.01
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        #grad_f = ca.gradient(param_est.nlp["f"], param_est.nlp["x"])
        #grad_f_f = ca.Function("grad_f", [param_est.nlp["x"]], [grad_f])
        
        """
        from cvxpy with first solution:
        [[6.55919266e-01 5.26466051e-12]
        [5.26466051e-12 4.52496393e-01]]
        
        params after first solve:
        Rie    1.532625e-03
        Rea    1.160423e-02
        Ci     1.328633e+06
        Ce     6.644898e+06
        Ai     5.578587e+00
        
        params after second solve:
        Rie    1.567088e-03
        Rea    1.160390e-02
        Ci     1.337609e+06
        Ce     6.747752e+06
        Ai     5.132032e+00m here we k
                        
        Does it change the physical parameters any???    
            
        """
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )
    
        # true residuals:
        w = param_est.x_gaps(sol[param_est.x_names].values.flatten(),
                        0,
                        y_data[param_est.u_names].values.flatten(),
                        params.values,
                        0,
                        0,
                        y_data[param_est.y_names].values.flatten(),
                        0)
    
        v = param_est.y_gaps(sol[param_est.x_names].values.flatten(),
                         0,
                         y_data[param_est.u_names].values.flatten(),
                         params.values,
                         0,
                         0,
                         y_data[param_est.y_names].values.flatten(),
                         0)
    
        w = np.array(w)
        v = np.array(v)
        
        W = pd.DataFrame(w.T, columns = param_est.w_names)
        V = pd.DataFrame(v.T, columns = param_est.v_names)
    
        pprint(params)
        
        #v = sol[["v1"]].values.T
        #w = sol[["w1", "w2"]].values.T
        
        covar_est = CovarianceSolver(v, w)
        R, Q = covar_est.solve()
        
        
        # function for one-step ahead residuals
        # compare with CTSM-R:s
        # compare with CTSM-R:
        # param_est.one_step_residual(x0, params, y_data, R=R, Q=Q)
        
        # do one simulation of this with Q = R = I.
        # then do one with Q, R obtained from CTSM-R
        """
        Q:
        p_11 = -1.412111e+01 
        p_22 = -5.157392e+00 
        
        formulated as np.exp(p_xx)
        
        R:
        e_11 = -6.087085e+00 
        
        dt = 900
        
        For interpretation of noise covariances:
        see Appendix in https://www.ctsm.info/building2.pdf
        
        Try with params iden. from CTSM-R:
        params:
        Ti0           Te0            Aw            Ce            Ci           e11           p11           p22           Rea 
        2.940592e+02  2.931072e+02  7.559631e+00  6.130762e+06  1.301290e+06 -6.087085e+00 -1.412111e+01 -5.157392e+00  1.151022e-02 
                Rie 
        1.389899e-03 
        """
        p_11 = -1.412111E1 
        p_22 = -5.157392E0 
        e_11 = -6.087085E0  
        dt = 900
        
        Q_ctsm = ca.DM(np.diag([np.exp(p_11), np.exp(p_22)]))
        #Q = ca.DM(np.diag([np.sqrt(np.exp(p_11)), np.sqrt(np.exp(p_22))]))
        #R = ca.DM(np.diag([np.sqrt(np.exp(e_11))]))
        R_ctsm = ca.DM(np.diag([np.exp(e_11)]))
         
        x0_ipopt = sol[["Ti", "Te"]].iloc[0].values # this is ~model prediction (can get exact)
        x0_ctsm = np.array([2.940592e02, 2.931072e+2])
        
        params_ctsm = np.array([1.389899e-03, 1.151022e-02, 1.301290e+06, 6.130762e+06, 7.559631e+00])
        
        res_ctsm = param_est.one_step_residual(ekf_config, x0_ctsm, params_ctsm, y_data, R=R_ctsm, Q=Q_ctsm)
        res_ipopt = param_est.one_step_residual(ekf_config, x0_ipopt, params, y_data, R=R, Q=Q)
        
        # plot ctsm:
        res_ctsm.res.plot()
        plt.show()
        # plot ipopt:
        res_ipopt.res.plot()
        plt.show()
        
        #truth = y_data["Ti"].iloc[1:]
        #truth.index = res.index
        #ax = truth.plot(color="black", linestyle="dashed")
        #res.y_pred.plot(ax=ax, color="r")
        #plt.show()
        
        # transpose:
        
        
        ax = sol["Ti"].plot(color="grey")
        ax = y_data["Ti"].plot(color="black", linestyle="dashed")
        ax.legend(["Estimated", "True"])
        plt.show()
        
        #assert(ca.norm_inf(p_sol-true_params)<1e-8)