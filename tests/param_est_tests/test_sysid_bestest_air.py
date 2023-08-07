#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.mpc import MPC

import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF, KalmanBucy
from matplotlib import rc
from ocp.functions import functions
import os
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    data_path = get_data_path()
    
    cfg_path = os.path.join(opt_config_base, "3R2C_bestest_air_ufan.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_func_DAE.json")
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_air_oneway.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    prbs_path = os.path.join(data_path, "inputPRBS1.csv")

    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_air"
                      )

    GENERATE_DATA = False
    data_path = os.path.join(get_data_path(), "data_bestest_air_normal_op.csv")
    
    N = 7*24*4
    if GENERATE_DATA:
        # local control 
        for n in range(N):
            data, y_meas, u_meas = boptest.evolve()
        
        y_data = boptest.get_data(tf=N*boptest.h) #, downsample=False)
        y_data["y1"] = y_data.Ti
        y_data["y2"] = y_data.Ph
        y_data.to_csv(data_path)
    else:
        y_data = pd.read_csv(data_path, index_col=0)
        
    ############ PLOT DATA #############
    
    ax = y_data["y1"].plot()
    ax1 = ax.twinx()
    y_data["Tsup"].plot(ax=ax, color="y", drawstyle="steps-post")
    y_data["Ta"].plot(ax=ax, color="k")
    y_data["Ph"].plot(ax=ax1, color="r", linestyle="dashed", drawstyle="steps")
    ax.legend(["Ti", "Tsup", "Ta"], loc="upper left")
    ax1.legend(["Ph"])
    plt.show() 
    ### set Tsup = Ti where Tsup < Ti
    y_data["Tsup"].loc[(y_data["Tsup"] < y_data["Ti"])] = y_data["Ti"]
    
    ####################################
    #y_data = data
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]  
    #param_guess = ca.DM([0.01,0.01,1E6,1E7,5,1.05,39.10,0.90])
    #param_guess = ca.DM([0.01,0.01,0.01,0.01,1E6,1E7,1E6,5])
    #param_guess = ca.DM([0.01,0.01,100,1E6,1E7,5,1.1])
    param_guess = ca.DM([0.01,0.01,0.01,1E6,1E7,5])
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    #lbp[len_p-1] = 0.87
    #ubp[len_p-1] = 1
    #lbp[len_p-1] = 1
    #ubp[len_p-1] = 1.3
    #lbp[len_p-2] = 1
    #ubp[len_p-2] = 2
    
    # feed in x_guess:
    x_guess = y_data[["Ti", "y1"]]
    x_guess["Ts"] = y_data["Tsup"]
    x_guess["Ts"].iloc[-1] = x_guess["Ts"].iloc[-2]
    x_guess = x_guess.values
    
    kwargs = {
        "oneWayHeating": 
        functions["oneWayHeating"],
        "regNonZeroPower":
        functions["regNonZeroPower"],  
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12, 1],
        "u_nom_b": [289.15, 0],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0]
        }
    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess, 
                             **kwargs) as param_est:
   
        Q = ca.DM.eye(2)
        #Q = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(1)
        #R[1,1] = 1E-5
        #R[1,1] = 1E-12

        #v_inds = param_est.nlp_parser["v"]["range"]
        #v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        #v2 = param_est.nlp["x"][(v_inds["a"]+1):v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        #eta = param_est.dae.dae.var("eta")
        #v2 = v2/eta
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-4*ca.dot(v2, v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-8*ca.dot(v2, v2)
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      #x_guess=x_guess,
                                      covar=ca.veccat(Q, R)
                                      )
        
        # test eval of H mapped
        h_func = param_est.strategy.h_map
        # extract data for eval:
        #y = sol[["y1", "y2"]]
        y = sol[["y1"]]
        x = sol[["Ti", "Te"]]
        u = sol[["Tsup"]]
        p = sol[param_est.dae.p]
        
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend()
        plt.show()
        print(params)
        
    # compare inferred heat with measured:  
    #UA_nom = params["UA_nom"]
    #n = params["n"]
    #ax = (UA_nom*((y_data.Tsup-y_data.Ti)**n)).plot(color="k", drawstyle="steps-post")
    #Ph_inf = (sol["Tsup"] - sol["Ti"])**(sol["n"].iloc[0])*(sol["u_fan"]*sol["UA_is"])
    Ph_inf = (sol["Tsup"] - sol["Ti"])*(sol["u_fan"]/sol["Ris"])
    Ph_inf.iloc[-1] = 0
    #ax1 = ax.twinx()
    ax = Ph_inf.plot(color="k", linestyle="dashed")
    y_data["Ph"].plot(ax=ax, color="r")
    #(y_data.Ph*params["eta"]).plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax)
    #ax.legend(["deltaT"])
    ax.legend(["Ph_inf", "Ph"], loc="upper left")
    #ax1.legend(["Ph"])
    plt.show()
    print(params)