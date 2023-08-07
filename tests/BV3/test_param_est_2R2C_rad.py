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
from ocp.functions import functions
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

if __name__ == "__main__":
    
    data = pd.read_csv("bv3_5splines.csv", index_col=1)
    data.index = pd.to_datetime(data.index)
    extr = pd.read_csv("PRBSData_5min.csv", index_col=0)
    extr.index = pd.to_datetime(extr.index)
    rad_temps = extr[[
                      col for col in extr.columns if 
                      "T" in col and "Rad" in col
                    ]]
    rad_temps = rad_temps.resample(rule="15min").asfreq()
    # align with previous data:
    rad_temps = rad_temps.iloc[0:len(data)]
    rad_temps.index = data.index
    # one radiator, merge supply temps:
    data["Tsup"] = rad_temps[["TsRadE", "TsRadW"]].mean(axis=1)
    # TODO: merge radiator temps with above data
    # rename data
    data = data.rename(
                        columns={"qh": "Ph",
                                 "yTi": "y1",
                                 "Isol": "phi_s",
                                 "Te": "Ta"
                                 }
                      )
    
    # filter out < 0 vals for Ph:
    data.Ph[data.Ph < 0] = 0
    # cut-off at 4E3 [W]:
    data.Ph[data.Ph > 4E4] = 4E4
    """
    Create a weighting array for Ph:
    when Ph is zero, do not care about 
    residual on radiator model.
    """
    v2_weight = ca.DM((data.Ph > 0).astype(int)*1E-1)
    _v2_weight = ca.DM((data.Ph == 0).astype(int)*1E-1)
    v2_weight = v2_weight + _v2_weight
    
    data["Ti"] = data.y1
    data["y2"] = data.Ph
    # to Kelvin:
    data["Ti"] += 273.15
    data["Ta"] += 273.15
    data["Tsup"] += 273.15
    data["y1"] += 273.15
    
    cfg_path = "2R2C_rad_alt.json"
    #y_data = data.iloc[0:10]
    y_data = data
    N = len(y_data)
    dt = 900
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    param_guess = ca.DM([0.01,0.01,1E7,1E8,5,1.05,1E3,1])
    #param_guess = ca.DM([0.1,0.1,0.1,1E6,1E7,1E5,5,39.1])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    #ubp = ca.DM([0.1,0.1,1E7,1E8,50])
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    lbp[len_p-1] = 1
    ubp[len_p-1] = 1
    #lbp[len_p-2] = 900
    lbp[len_p-3] = 1
    ubp[len_p-3] = 2
    

    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) \
                             as param_est:
                             #**kwargs) as param_est:
        
        
        #param_guess[-1] = dT_nom
        #param_guess[-1] = dT_nom
        #param_guess[5] = 250
        #x = ca.DM([293.15, 293.15])
        #u = ca.DM([303.15, 0, 0])
        #z = ca.DM([5000])
        #sol = param_est.integrator.G(x0=z, p=ca.vertcat(x, u, param_guess))
        
        
        Q = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(2)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        v2 = param_est.nlp["x"][(v_inds["a"]+1):v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        eta = param_est.dae.dae.var("eta")
        v2 = v2/eta
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-4*ca.dot(v2, v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + ca.dot(v2_weight*v2, v2_weight*v2)
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )
        
        # test eval of H mapped
        h_func = param_est.strategy.h_map
        # extract data for eval:
        y = sol[["y1", "y2"]]
        x = sol[["Ti", "Te"]]
        u = sol[["Tsup"]]
        p = sol[param_est.dae.p]
        
        
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", linestyle="dashed", ax=ax)
        ax.legend()
        plt.show()
        print(params)
        
    
    # compare inferred heat with measured:  
    UA_nom = 1E3
    UA_nom = params["UA_nom"]
    #UA_nom = 1E3
    n = params["n"]
    ax = (UA_nom*((y_data.Tsup-y_data.Ti)**n)).plot(color="k", drawstyle="steps-post")
    #ax1 = ax.twinx()
    (y_data.Ph*params["eta"]).plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax)
    #ax.legend(["deltaT"])
    ax.legend(["Ph_inf", "Ph"], loc="upper left")
    #ax1.legend(["Ph"])
    plt.show()
    