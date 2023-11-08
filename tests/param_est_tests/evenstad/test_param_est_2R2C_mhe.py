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
from ocp.frost_function import get_metno_data, get_stations, get_observations
# text:
rc('mathtext', default='regular')

# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

if __name__ == "__main__":

    cfg_path = "configs/3R3C_det.json"
    df = pd.read_csv("evenstad_data_2023/evenstad_data_mar_apr.csv", index_col=0)
    df.index = df["dt_index"] = pd.to_datetime(df.index)
    temp_cols = [col for col in df.columns if "Ti_" in col 
                 and "office" not in col
                 and "113" not in col]
    
    
    # resample to 1H:
    
    # set names:
    df["Ti"] = df[temp_cols].mean(axis=1)
    # 'filter' out circulation loss:
    #df.P_water[df.P_water < 5] = 0
    phi_h = df["P_water"].resample(rule="1H").mean()
    y_data = df.resample(rule="1H").asfreq()
    y_data["phi_h"] = phi_h*1000 # to Watts
    y_data["y1"] = y_data["Ti"]
    
    # plot:
    
    y_data = y_data.loc['2023-02-20 00:00:00':'2023-02-27 23:00:00']   
    y_data = y_data.bfill()
    
    ax = y_data.Ti.plot(color="k", drawstyle="steps-post")
    ax1 = ax.twinx()
    y_data.phi_h.plot(color="r", ax=ax1, drawstyle="steps-post")
    plt.show()
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0,N*dt, dt)
    param_guess = ca.DM([#
                2.288896e-04,
                2.933085e-03,
                2.933085e-03,
                1.353292e+07,
                1.613305e+08,
                1.613305e+07,
                3.137043e+02
                         ])
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    #ubp = ca.DM([0.1,1,1E7,1E8,50])
    len_p = param_guess.shape[0]
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    
    """
    lbp[len_p-1] = 4200
    ubp[len_p-1] = 4200
    for i in range(2,8):
        lbp[len_p-i] = 0
        ubp[len_p-i] = 1
    lbp[len_p-6] = 0.1
    ubp[len_p-6] = 0.9
    lbp[len_p-7] = 0.1
    ubp[len_p-7] = 0.9
    """
    #param_guess = ca.DM([0.001,0.009,1,1E6,1E7,1])
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    #    with ParameterEstimation(config=cfg_path,
    #                             data=y_data,
    #                             param_guess=param_guess) as param_est:
    x_guess = np.array([
                        y_data.Ti.values.flatten(),
                        y_data.Ti.values.flatten(),
                        y_data.Ti.values.flatten()
                        #y_data.Ti1.values.flatten(),
                        #y_data.Ti1.values.flatten()
                        ])
    lbx = 0.7*x_guess
    ubx = 1.3*x_guess
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(3)
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
        Ai     5.132032e+00
                        
        Does it change the physical parameters any???    
            
        """
        sol, params, raw_sol = param_est.solve(
                                        y_data,
                                        param_guess,
                                        lbp=lbp,
                                        ubp=ubp,
                                        lbx=lbx,
                                        ubx=ubx,
                                        x_guess=x_guess,
                                        covar=ca.veccat(Q, R),
                                        return_raw_sol=True
                                        )
        fig, axes = plt.subplots(1,1,sharex=True)
        ax = axes
        sol.index = y_data.dt_index
        sol["Ti"].plot(color="r", ax=ax, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, drawstyle="steps-post")
        ax.legend()
        plt.show()
        print(params)
        
        # validate with unseen data:

        """
        F = param_est.integrator.one_sample.mapaccum(len(test))
        x0 = sol[["Ti", "Te", "Ti1", "Te1"]].iloc[0].values
        #x0 = ca.DM([test.Ti[0], test.Ti[0], test.Ti1[0], test.Ti1[0]])
        #x0 = ca.DM([test.Ti[0], test.Ti[0] - 15, test.Ti1[0], test.Ti1[0] - 15])
        u_data = test[param_est.dae.u].values.T
        p_data = ca.repmat(params.values, 1, len(test))
        #p_data = ca.repmat(param_guess, 1, len(test))
        z_data = ca.repmat(1, 1, len(test))
        res = F(x0=x0, z=z_data, u=u_data, p=p_data, s=0, r=0)
        Ti_res = res["xf"][0, :]
        Ti1_res = res["xf"][2, :]
        test_res = pd.DataFrame(columns=["y1", "y2", "Ti_res", "Ti1_res"])
        test_res["y1"] = test.y1
        #test_r#es["y2"] = test.y2
        test_res["Ti_res"] = np.array(Ti_res).flatten()
        #test_res["Ti1_res"] = np.array(Ti1_res).flatten()
        test_res.plot()
        plt.show()
        print(test_res)
        """