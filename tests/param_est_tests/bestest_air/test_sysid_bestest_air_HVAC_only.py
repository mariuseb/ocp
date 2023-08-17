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
import math
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    data_path = get_data_path()
    
    #cfg_path = os.path.join(opt_config_base, "3R2C_bestest_air_ufan_HVAC_sigmoid.json")
    cfg_path = os.path.join(opt_config_base, "3R2C_bestest_air_ufan_HVAC_only.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_func_DAE.json")
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_air_oneway.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    prbs_path = os.path.join(data_path, "inputPRBS1.csv")

    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_air"
                      )

    GENERATE_DATA = False
    PLOT_DATA = False
    data_path = os.path.join(get_data_path(), "data_bestest_air_normal_op.csv")
    
    N = 7*24*4 + 1
    #N = 1*24*4
    if GENERATE_DATA:
        # local control 
        for n in range(N):
            data, y_meas, u_meas = boptest.evolve()
        
        y_data = boptest.get_data(tf=N*boptest.h) #, downsample=False)
        y_data["y1"] = y_data.Ti
        y_data["y2"] = y_data.Ph
        y_data = y_data[:-1]
        y_data.to_csv(data_path)
    else:
        y_data = pd.read_csv(data_path, index_col=0)
        
    # DATA PRE-PROCESSING:
    y_data["Ph"] = y_data["Ph"].shift(-1).ffill().bfill()
    #u_fan_shift = y_data["u_fan"].shift(-1)
    #(y_data["Tsup"] - y_data["Ti"]) > 10
    u_shift = y_data["u_fan"].shift(-1) - y_data["u_fan"]
    y_data["u_turnon"] = (u_shift > 0.25).astype("float")
    y_data["u_turnon"] = y_data["u_turnon"].shift(1).ffill().bfill()
    y_data["y1"] = y_data["Ph"]
    y_data["y2"] = y_data["Pc"]
    
    ############ PLOT DATA #############
    if PLOT_DATA:
        ax = y_data["Ti"].plot()
        ax1 = ax.twinx()
        y_data["Tsup"].plot(ax=ax, color="y", drawstyle="steps-post")
        y_data["Ta"].plot(ax=ax, color="k")
        y_data["Ph"].plot(ax=ax1, color="r", linestyle="dashed", drawstyle="steps")
        y_data["Pc"].plot(ax=ax1, color="b", linestyle="dashed", drawstyle="steps")
        #y_data["u_turnon"].plot(ax=ax1, color="g", drawstyle="steps")
        #y_data["u_fan"].plot(ax=ax1, color="k", drawstyle="steps")
        ax.legend(["Ti", "Tsup", "Ta"], loc="upper left")
        #ax1.legend(["Ph", "u_turnon", "u_fan"])
        ax1.legend(["Ph", "Pc"])
        plt.show() 
    ### set Tsup = Ti where Tsup < Ti
    #y_data["Tsup"].loc[(y_data["Tsup"] < y_data["Ti"])] = y_data["Ti"]
    
    # hyper-params:
    
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]  
    
    ####################################
    param_guess = ca.DM([1.2,570,0.95,0.001])
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    lbp[0] = 1.00
    ubp[0] = 1.3
    lbp[1] = 500
    ubp[1] = 1000
    lbp[2] = 0.5
    ubp[2] = 1
    lbp[3] = 0
    ubp[3] = 0
    
    # feed in x_guess:
    x_guess = y_data[["Ti", "y1"]]
    x_guess["Ts"] = y_data["Tsup"]
    x_guess["Ts"].iloc[-1] = x_guess["Ts"].iloc[-2]
    x_guess = x_guess.values
    
    kwargs = {
        "oneWayHeating": 
        functions["oneWayHeating"],
        "regNonZeroPower":
        functions["regNonZeroPower"]
    }
    """
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12, 1],
        "u_nom_b": [289.15, 0],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0]
        }
    """ 
    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess, 
                             **kwargs) as param_est:
   
        Q = ca.DM.eye(0)
        #Q = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(1)
        #R[1,1] = 1E-5
        #R[1,1] = 1E-12

        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        #v2 = param_est.nlp["x"][(v_inds["a"]+1):v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        eta = param_est.dae.dae.var("eta")
        v1 = v1/eta
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1)
        #param_est.nlp["f"] = ca.sum1(ca.fabs(v1))
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
        print(params)
        
    # compare inferred heat with measured:  
    #UA_nom = params["UA_nom"]
    #n = params["n"]
    #ax = (UA_nom*((y_data.Tsup-y_data.Ti)**n)).plot(color="k", drawstyle="steps-post")
    ax = y_data["Ph"].plot(color="r")
    (-y_data["Pc"]).plot(ax=ax, color="b")
    n = sol["n"].iloc[0]
    #alpha = sol["alpha"].iloc[0]
    #Ph_inf = ((sol["Tsup"] - sol["Ti"])**(sol["n"].iloc[0]))*(sol["u_fan"]*sol["UA_is"]) - y_data["u_turnon"]*sol["u_fan"]*(sol["Tsup"] - sol["Ti"])*sol["b"]
    diff = sol["Tsup"] - sol["Ti"]
    #diff = (np.sign(diff)*np.abs(diff))**n
    diff_raised = diff.copy()
    for i in range(len(diff.index)):
        num = diff.iloc[i]
        diff_raised.iloc[i] = np.sign(num)*(np.abs(num))**n

    #diff_exp = (sol["Tsup"] - sol["Ti"]).apply(lambda x: math.exp(x*alpha))
    #Ph_inf = (diff_raised**n)*(1 + diff_exp)*(sol["u_fan"]*sol["UA_is"]) - y_data["u_turnon"]*sol["u_fan"]*(sol["Tsup"] - sol["Ti"])*sol["b"]
    Ph_inf = diff_raised*(sol["u_fan"]*sol["UA_is"]) - y_data["u_turnon"]*sol["u_fan"]*(sol["Tsup"] - sol["Ti"])*sol["b"]
    Ph_inf.plot(ax=ax, color="k", linestyle="dashed")
    plt.show()
    #Ph_inf = diff_raised*(sol["u_fan"]*sol["UA_is"]) - y_data["u_turnon"]*sol["u_fan"]*(sol["Tsup"] - sol["Ti"])*sol["b"]
    #Ph_inf = Ph_inf.fillna(0)
    #Ph_inf = (sol["Tsup"] - sol["Ti"])*(sol["u_fan"]/sol["Ris"])
    #Ph_inf.iloc[-1] = 0
    #ax1 = ax.twinx()
    #ax = Ph_inf.plot(ax=ax, color="k", linestyle="dashed")
    #(y_data.Ph*params["eta"]).plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax)
    #ax.legend(["deltaT"])
    ax.legend(["Ph", "Pc", "Ph_inf"], loc="upper left")
    #ax1.legend(["Ph"])
    plt.show()
    # check residual:
    v1_num = sum(abs(Ph_inf - y_data["Ph"]*sol["eta"] + y_data["Pc"]*sol["eta"]))
    
    #res_manual = abs(Ph_inf - y_data["Ph"]*sol["eta"] + y_data["Pc"]*sol["eta"])
    #ax = sol["v1"].plot(color="b")
    #res_manual.plot(ax=ax, color="k", linestyle="dashed")
    #plt.show()
    
    # test
    #diff = (sol["Tsup"] - sol["Ti"])
    #ax = diff.plot(color="g") 
    #(Ph_inf/400).plot(ax=ax, color="k")
    #plt.show()
    #print(params)
    
    #################### separate identification of envelope model ###########################
    # shift of Ph already done
    y_data["y1"] = y_data["Ti"]
    cfg_path = os.path.join(opt_config_base, "2R2C_envelope.json")
    param_guess = ca.DM([0.01,0.01,1E6,1E6,5])
    lbp = param_guess*0.01
    ubp = param_guess*100
        
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

        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1)
        
        sol, params = param_est.solve(
                                        y_data,
                                        param_guess,
                                        lbp=lbp,
                                        ubp=ubp,
                                        #x_guess=x_guess,
                                        covar=ca.veccat(Q, R)
                                        )
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend()
        plt.show()
        print(params)
        
    print(params)
    