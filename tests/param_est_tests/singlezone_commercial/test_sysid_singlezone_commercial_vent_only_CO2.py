#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.mpc import MPC

import numpy as np
import json
import casadi as ca
import ocp
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF
from matplotlib import rc
from pprint import pprint
#from ocp.covar_solve import CovarianceSolver
import os
import matplotlib.pyplot as plt
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_hydronic_gn.json")
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_Tsup_linear.json")
    #cfg_path = os.path.join(opt_config_base, "2R3C_bestest_Tsup_DAE.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_bestest_Tsup_linear_UAnom_1meas.json")
    #cfg_path = os.path.join("configs", "4R2C_inf_DAE.json")
    #cfg_path = os.path.join("configs", "2R2C_rad_pump_DAE.json")
    #cfg_path = os.path.join("configs", "2R2C_func_DAE.json")
    #cfg_path = os.path.join("configs", "2R2C_orig.json")
    #cfg_path = os.path.join("configs", "4R2C_inf_vent.json")
    cfg_path = os.path.join("configs", "vent_only_CO2.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = False
    PLOT = False

    boptest = Boptest(
                      boptest_cfg,
                      name="singlezone_commercial"
                      )
    
    sampling_time = "15min"
      
    #data_path = os.path.join(get_data_path(), "data_singlezone_commercial_only_CO2.csv")
    data_path = os.path.join(get_data_path(), "data_singlezone_commercial_only_CO2_normal_op.csv")
    
    if GENERATE_DATA:
        
        prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"), sep=";")
        prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        dt_index = prbs.index
        prbs.Ph /= 5
        prbs = prbs.Ph
        prbs = prbs.round(0)
        prbs = prbs.resample(sampling_time).first()
        prbs.index = range(len(prbs.index))
        # baseline control for sysid:
        N = len(prbs)
        
        
        #u_measured = []
        count = 0
        for n in range(N):
            u_0 = pd.Series(index=['dh_Tsup'], data=[283.15 + prbs.loc[n]*50])
            #u_0["TsetHea"] = 283.15 + prbs.loc[n]*20
            #u_0["TsetHea"] = 318.15
            #u_0["dh_pump"] = prbs.loc[n]
            u_0["dh_pump"] = 0
            u_0["ahu_pump_sup"] = prbs.loc[n]*count + 0.03*(1 - prbs.loc[n])
            u_0["ahu_pump_ret"] = prbs.loc[n]*count + 0.03*(1 - prbs.loc[n])
            #u_0["ahu_pump_sup"] = prbs.loc[n]
            #u_0["ahu_pump_ret"] = prbs.loc[n]
            #u_0["oveValCoi"] = prbs.loc[n]
            #u_0["ahu_pump_sup"] = 0.01
            #u_0["ahu_pump_ret"] = 0.01
            #u_0["ahu_Tsup"] = 288.15 + prbs.loc[n]*25
            u_0["ahu_Tsup"] = 288.15 + prbs.loc[n]*25
            #u_0["ahu_Tsup"] = 288.15
            
            if prbs.loc[n] > 0:
                count += 1
            if count > 97:
                count = 0            
            try:
                _, y_meas, u_meas = boptest.evolve()
            except TypeError:
                print(y_meas)
            #u_measured.append(u_meas)
  
        data = boptest.get_data(tf=N*boptest.h, downsample=False)
        # check
       # ax = data.Ti.plot()
       # data.oveTSetSup_u.plot(ax=ax, color="r", drawstyle="steps-post")
        data.to_csv(data_path)
    
    else:
        data = pd.read_csv(data_path, index_col=0)
    
    data["Pvent"] -= data["Prad"]
    
    data["Prad"] = data["Prad"].shift(-1) 
    #data["Ptot"] = data["Ptot"].shift(-1) 
    data["Pvent"] = data["Pvent"].shift(-1) 
    #data["CO2_in"] = data["CO2_in"].shift(-1) 
    data["n_occ"] = data["n_occ"].shift(-1) 
    data["dh_pump"] = data["dh_pump"].shift(-1) 
    #data["oveValCoi"] = data["oveValCoi"].shift(-1) 
    data["ahu_pump_sup"] = data["ahu_pump_sup"].shift(-1) 
    data["ahu_pump_ret"] = data["ahu_pump_ret"].shift(-1) 
    #data["ahu_reaTCoiSup"] = data["ahu_reaTCoiSup"].shift(-1) 
    #data["ahu_reaTCoiRet"] = data["ahu_reaTCoiRet"].shift(-1) 
    #data["ahu_reaTSupAir"] = data["ahu_reaTSupAir"].shift(-1) 
    # unsure whether to pull this back or not:
    #data["ahu_reaTRetAir"] = data["ahu_reaTRetAir"].shift(-1) 
    data["ahu_reaTHeaRec"] = data["ahu_reaTHeaRec"].shift(-1) 
    data["ahu_reaFloSupAir"] = data["ahu_reaFloSupAir"].shift(-1)
    data["ahu_reaFloExtAir"] = data["ahu_reaFloExtAir"].shift(-1)
    y_data = data.iloc[:-2]
    # TODO: need to modularize this:
    y_data["y1"] = y_data["CO2_in"]
    #y_data["y5"] = y_data["ahu_reaFloSupAir"]
    #y_data["y6"] = y_data["ahu_reaTCoiSup"]
    #y_data["y2"] = y_data["Ph"]
    
    if PLOT:

        # AHU, air-side, plots:
        fig, ax = plt.subplots(3,1, sharex=True)
        y_data.Ti.plot(ax=ax[0], drawstyle="steps-post")
        y_data.ahu_reaTRetAir.plot(ax=ax[0], drawstyle="steps-post")
        y_data.ahu_reaTHeaRec.plot(ax=ax[0], drawstyle="steps-post")
        (y_data.Ta + (y_data.ahu_reaTRetAir - y_data.Ta)*0.58).plot(ax=ax[0], drawstyle="steps-post")
        y_data.Ta.plot(ax=ax[0], drawstyle="steps-post")
        ax[0].legend(["Ti", "Tret", "Trec", "Trec_model", "Ta"])
        y_data.ahu_pump_sup.plot(ax=ax[1], drawstyle="steps-post")
        y_data.ahu_pump_ret.plot(ax=ax[1], drawstyle="steps-post")
        y_data.Pvent.plot(ax=ax[2], drawstyle="steps-post")
        plt.show()
        
        # power balances
        y_data["Ph_water"] = y_data["oveValCoi"]*2*1000*25*(y_data["ahu_reaTCoiSup"] - y_data["ahu_reaTCoiRet"])
        y_data["Ph_air"] = y_data.ahu_reaFloSupAir*32*1*30*(y_data["ahu_reaTSupAir"] - y_data["ahu_reaTHeaRec"])
        ax = y_data.Ph_water.plot(drawstyle="steps-post")
        y_data.Ph_air.plot(ax=ax, drawstyle="steps-post")
        y_data.Pvent.plot(ax=ax, drawstyle="steps-post")
        ax1 = ax.twinx()
        data.Ti.plot(color="r", ax=ax1)
        
        ax.legend()
        plt.show()

    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    param_guess = ca.DM([
                        4.222012e-05,
                        1.757842e-04,
                        1E-3,
                        0.5,
                        8.126425e+07,
                        2.732098e+09,
                        2.800931e+02,
                        2,
                        1000*25,
                        1*30,
                        0.9,
                        0.9
                        ])
    param_guess = ca.DM([
                        3E-5,
                        418,
                        0.2,
                        6E-4
                        ])

    
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        }
    
    x_guess = np.array([y_data.CO2_in.values.flatten()])
                        #, y_data.ahu_reaTSupAir.values.flatten()])
    x_guess = x_guess.T.flatten()
    #y_data = y_data[:3]
    #N = len(y_data)
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        
        Q = ca.DM.eye(1)
        R = ca.DM.eye(1)
        #R[1,1] = 1E-8
        #R[2,2] = 1E-8
        
        #R[2,2] = 1E-10
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        
        param_est.nlp["f"] = \
            R[0,0]*ca.dot(v1, v1)
                
        #param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      x_guess=x_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )    
    
    sol.index = y_data.index
    ax = sol.y1.plot(drawstyle="steps-post", color="b")
    ax.plot(y_data.index, sol.CO2_in, drawstyle="steps-post", color="k", linestyle="dashed")
    ax1 = ax.twinx()
    plt.show()
    print(params)
