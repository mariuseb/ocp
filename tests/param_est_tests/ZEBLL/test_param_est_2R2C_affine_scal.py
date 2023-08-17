#from ast import Param
from ocp.param_est import ParameterEstimation
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
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

if __name__ == "__main__":
    
    cfg_path = os.path.join(get_opt_config_path(), "2R2C_orig.json")
    #cfg_path = os.path.join(get_opt_config_path(), "2R2C.json")
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
    
    #y_data = y_data.iloc[0:50]
    
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
    
    """
    kwargs = {
        "x_nom": 30,
        "x_nom_b": 273.15,
        "u_nom": [5000, 100, 30],
        "u_nom_b": [0, 0, 273.15],
        "y_nom": 30,
        "y_nom_b": 273.15,
        "v_nom": 1,
        "v_nom_b": 0,
    }
    """
    kwargs = {
        "x_nom": 300,
        "u_nom": 5000,
        "y_nom": 300,
        "v_nom": 1
    }
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "y_nom": 1,
        "v_nom": 1
    }
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess,
                             **kwargs) as param_est:
        
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
    
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend()
        plt.show()
        print(params)
        
        # test eval of alt obj:

           
        x_vals = param_est.scaled_sol_df[param_est.dae.x].values.flatten()
        u_vals = param_est.scaled_sol_df[param_est.dae.u].values.flatten()
        y_vals = param_est.scaled_sol_df[list(param_est.dae.y.keys())].values.flatten()
        s_vals = param_est.scaled_sol_df[param_est.dae.s_names].values.flatten()
        v_vals = param_est.scaled_sol_df[param_est.dae.v_names].values.flatten()
        
        # sample fisher information:
        alt_obj_val = param_est.alt_obj_func(
                                            params/param_est.scale,
                                            x_vals,
                                            u_vals,
                                            y_vals,
                                            s_vals,
                                            v_vals,
                                            ca.vec(R),
                                            ca.vec(Q)
                                            )
         
        obj_val = param_est.obj_func(
                                    params/param_est.scale,
                                    x_vals,
                                    u_vals,
                                    y_vals,
                                    s_vals,
                                    v_vals,
                                    ca.vec(R),
                                    ca.vec(Q)
                                    )
         
        x_gap_val = param_est.x_gaps(
                                        params/param_est.scale,
                                        x_vals,
                                        u_vals,
                                        y_vals,
                                        s_vals,
                                        v_vals,
                                        ca.vec(R),
                                        ca.vec(Q)
                                    )

        x_vals = param_est.sol_df[param_est.dae.x].values.flatten()
        u_vals = param_est.sol_df[param_est.dae.u].values.flatten()
        y_vals = param_est.sol_df[list(param_est.dae.y.keys())].values.flatten()
        s_vals = param_est.sol_df[param_est.dae.s_names].values.flatten()
        v_vals = param_est.sol_df[param_est.dae.v_names].values.flatten()
   
        y_gap_val = param_est.y_gaps(
                                        params/param_est.scale,
                                        x_vals,
                                        u_vals,
                                        y_vals,
                                        s_vals,
                                        v_vals,
                                        ca.vec(R),
                                        ca.vec(Q)
                                    )
        # How is this one compared to s?
        #print(x_gap_val)
        x_gaps = np.array(x_gap_val)
        y_gaps = np.array(y_gap_val)
        #fig, ax = plt.subplots(1,1)
        #ax.plot(x_gaps[0], color="r")
        #ax.plot(s_vals[0], color="b")
        #plt.show()
        fig, ax = plt.subplots(1,1)
        ax.plot(y_gaps[0], color="r")
        ax.plot(v_vals[0], color="b")
        plt.show()
        
        print(alt_obj_val)
        print(obj_val)
        
        # get fisher information:
        covar_p, fisher_p = param_est.get_covar_p(params.values/param_est.p_nom, R, Q)
        T = np.linalg.inv(np.diag(param_est.p_nom))
        print(covar_p, fisher_p)
        