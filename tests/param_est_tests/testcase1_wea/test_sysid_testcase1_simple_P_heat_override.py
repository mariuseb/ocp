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
    
    cfg_path = os.path.join(opt_config_base, "2R2C_testcase1_P.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    prbs_path = os.path.join(data_path, "inputPRBS1.csv")

    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1_wea"
                      )

    GENERATE_DATA = True
    PLOT_DATA = True
    data_path = os.path.join(get_data_path(), "data_testcase1_wea_P.csv")
    repeats = 1
    
    if GENERATE_DATA:
        prbs = pd.read_csv(prbs_path, sep=";")
        index = pd.to_datetime(prbs.t, origin="2020-02-01 00:00", unit="h").round("s")
        prbs.index = index
        U = prbs.Ph/5
        U = pd.DataFrame(U.resample(rule="15min").mean().round())
        #U = pd.DataFrame(data=np.tile(U.values, 2), index=U.index, columns=["phi_h", "u_sha"])
        #_u = pd.DataFrame(data=U.values, index=U.index, columns=["Tset"])
        _u = pd.DataFrame(data=U.values, index=U.index, columns=["phi_h"])
        _u = pd.concat([_u]*repeats)
        
        #_u *= 12
        #_u += 288.15 
        _u *= 2000
        
        #_u["u_fan"] = U
        # of time steps:
        N = 6*24*4*repeats - 24*repeats
        # local control 
        # baseline control for sysid:
        for n in range(N):
            u = _u.iloc[n]
            data, y_meas, u_meas = boptest.evolve(u=u)
            #data, y_meas, u_meas = boptest.evolve()
        
        y_data = boptest.get_data(tf=N*boptest.h) #, downsample=False)
        y_data["y1"] = y_data.Ti
        y_data["y2"] = y_data.phi_h
        y_data = y_data[:-1]
        y_data.to_csv(data_path)
    else:
        y_data = pd.read_csv(data_path, index_col=0)
        
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["phi_h"]
    
    ############ PLOT DATA #############
    if PLOT_DATA:
        ax = y_data["Ti"].plot()
        ax1 = ax.twinx()
        y_data["Tset"].plot(ax=ax, color="y", drawstyle="steps-post")
        y_data["Ta"].plot(ax=ax, color="k")
        y_data["phi_h"].plot(ax=ax1, color="r", linestyle="dashed", drawstyle="steps-post")
        #y_data["Pc"].plot(ax=ax1, color="b", linestyle="dashed", drawstyle="steps")
        #y_data["u_turnon"].plot(ax=ax1, color="g", drawstyle="steps")
        #y_data["u_fan"].plot(ax=ax1, color="k", drawstyle="steps")
        ax.legend(["Ti", "Tset", "Ta"], loc="upper left")
        ax1.legend(["Ph"], loc="upper right")
        #ax1.legend(["Ph", "u_turnon", "u_fan"])
        plt.show() 
    
    ####################################
    #y_data = data
    # remove nan after warmup:
    #y_data = y_data[1:]
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]  
    
    #param_guess = ca.DM([0.01,0.01,1E6,6E5,2000])
    param_guess = ca.DM([0.01,0.01,1E6,5E6])
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    
    kwargs = {
        "oneWayHeating": 
        functions["oneWayHeating"],
        "regNonZeroPower":
        functions["regNonZeroPower"]
    }

    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess, 
                             **kwargs) as param_est:
   
        #Q = ca.DM.eye(3)
        Q = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(1)
        #R = ca.DM.eye(1)
        #R[1,1] = 1E-5
        #R[1,1] = 1E-12

        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        v2 = param_est.nlp["x"][(v_inds["a"]+1):v_inds["b"]:param_est.dae.n_y]
        #v3 = param_est.nlp["x"][(v_inds["a"]+2):v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        #eta = param_est.dae.dae.var("eta")
        #v2 = v2/eta
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-8*ca.dot(v2, v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-12*ca.dot(v2, v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-6*ca.dot(v2,v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-16*ca.dot(v2,v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-8*ca.dot(v2, v2)
        #u_active = y_data["phi_h"].astype(bool).astype(int).values
        #v2 = v2*u_active
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1) #+ 1E-8*ca.dot(v2, v2) # + 1E-12*ca.dot(v3, v3)
        #param_est.res = ca.vertcat(v1,v2)
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      #x_guess=x_guess,
                                      covar=ca.veccat(Q, R)
                                      )
        
        # Temperature
        
        fig, axes = plt.subplots(2,2)
        
        sol["Ti"].plot(color="r", ax=axes[0,0])
        sol["y1"].plot(color="k", linestyle="dashed", ax=axes[0,0])
        #ax.legend(["Ti", "y1"], loc="upper left")
        #ax1 = ax.twinx()
        
        ax = sol["phi_h"].plot(color="y", ax=axes[0,1])
        #(sol["y2"] - sol["v2"]).plot(color="b", linestyle="dashed", ax=axes[0,1])
        #sol["Tset"].plot(color="y", linestyle="dashed", ax=ax)
        #ax1.legend(["phi_h", "kp*(Tset - Ti)"], loc="upper right")
        #plt.show()
        
        # plot residuals:
        ax = sol["v1"].plot(ax=axes[1,0])
        # ax = sol["v2"].plot(ax=axes[1,1])
        plt.show()
        
        
        # Fan regulation:
        # Tsup regulation:
        # Heat
        """
        ax = sol["Ph"].plot(color="r")
        Ph_inf = sol["v2"] - sol["y2"]*sol["eta"]
        (-Ph_inf).plot(color="k", linestyle="dashed", ax=ax)
        ax.legend()
        plt.show()
        """
        
    print(params)