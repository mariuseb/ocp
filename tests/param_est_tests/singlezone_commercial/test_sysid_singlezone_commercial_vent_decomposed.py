#%% 
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
from ocp.functions import functions
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    #cfg_path = os.path.join("configs", "4R3C_vent_n_power_eff_non_linear.json")
    cfg_path = os.path.join("configs", "3R2C_vent_simple.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = False
    GENERATE_DATA_NORMAL_OP = False
    PLOT = True

    boptest = Boptest(
                      boptest_cfg,
                      name="singlezone_commercial"
                      )
    
    sampling_time = "15min"
      
    data_path = os.path.join(get_data_path(), "data_bestest_hydronic_PRBS.csv")
    
    if GENERATE_DATA:
        
        np.random.seed(42)
        
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
        #k = 0.05
        for n in range(N):
            # no radiator:
            u_0 = pd.Series(index=['rad_val'], data=[0])
            k = np.random.random(1)[0]
            # full air volume:
            u_0["ahu_pump_sup"] = prbs.loc[n]
            u_0["ahu_pump_ret"] = prbs.loc[n]
            # max temperature:
            u_0["oveTSupSet"] = 288.15 + prbs.loc[n]*255
                    
            try:
                _, y_meas, u_meas = boptest.evolve(u=u_0)
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
    
    """
    # plot: here:
    data = data[4:]
    
    # Radiator:    
    
    # AHU
    ax = (data["ahu_reaTCoiSup_y"]-273.15).plot()
    (data["ahu_reaTHeaRec_y"]-273.15).plot(ax=ax)
    (data.Ti-273.15).plot(ax=ax, linestyle="dashed")
    data["ahu_reaTRetAir_y"].plot(ax=ax, drawstyle="steps-post")
    data["ahu_reaTSupAir_y"].plot(ax=ax, drawstyle="steps-post")
    ax.legend()
    plt.show()
    
    ax = (data.oveTSetSup_u-data.Ti).plot(color="k")
    ax1 = ax.twinx()
    data.Ph.plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax1)
    ax.legend(["deltaT"])
    ax1.legend(["Ph"])
    plt.show()
    """
    data["Prad"] = data["Prad"].shift(-1) 
    #data["Ptot"] = data["Ptot"].shift(-1) 
    data["Pvent"] = data["Pvent"].shift(-1) 
    data["dh_pump"] = data["dh_pump"].shift(-1) 
    data["oveValCoi"] = data["oveValCoi"].shift(-1) 
    data["ahu_pump_sup"] = data["ahu_pump_sup"].shift(-1) 
    data["ahu_pump_ret"] = data["ahu_pump_ret"].shift(-1) 
    data["ahu_reaTCoiSup"] = data["ahu_reaTCoiSup"].shift(-1) 
    data["ahu_reaTCoiRet"] = data["ahu_reaTCoiRet"].shift(-1) 
    #data["Tsup_air"] = data["Tsup_air"].shift(-1) 
    data["oveTSupSet"] = data["oveTSupSet"].shift(-1) 
    
    """
    Adjust:
    """
    data.oveTSupSet[data.oveTSupSet == 288.15] += 15
    data["m_flow_weight"] = data["ahu_pump_sup"] + 0.01 
    
    # unsure whether to pull this back or not:
    #data["ahu_reaTRetAir"] = data["ahu_reaTRetAir"].shift(-1) 
    #data["ahu_reaTHeaRec"] = data["ahu_reaTHeaRec"].shift(-1) 
    data["Ta"] = data["Ta"].shift(-1) 
    data["phi_s"] = data["phi_s"].shift(-1) 
    data["ahu_reaFloSupAir"] = data["ahu_reaFloSupAir"].shift(-1)
    y_data = data[:-2]
    # TODO: need to modularize this:
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["Pvent"]
    y_data["y3"] = y_data["ahu_reaTHeaRec"]
    y_data["y4"] = y_data["ahu_reaFloSupAir"]
    y_data["y5"] = y_data["ahu_reaTRetAir"]
    y_data["y6"] = y_data["Tsup_air"]
    #y_data["y5"] = y_data["ahu_reaFloSupAir"]
    #y_data["y6"] = y_data["ahu_reaTCoiSup"]
    #y_data["y2"] = y_data["Ph"]
    
    
    if PLOT:

        # AHU, air-side, plots:
        fig, ax = plt.subplots(3,1, sharex=True)
        y_data.Ti.plot(ax=ax[0], linestyle="dashed", drawstyle="steps-post")
        y_data.ahu_reaTRetAir.plot(ax=ax[0], drawstyle="steps-post")
        y_data.ahu_reaTHeaRec.plot(ax=ax[0], drawstyle="steps-post")
        y_data.Tsup_air.plot(ax=ax[0], drawstyle="steps-post")
        y_data.oveTSupSet.plot(ax=ax[0], drawstyle="steps-post")
        (y_data.Ta + (y_data.ahu_reaTRetAir - y_data.Ta)*0.75).plot(ax=ax[0], drawstyle="steps-post")
        y_data.Ta.plot(ax=ax[0], drawstyle="steps-post")
        ax[0].legend(["Ti", "Tret", "Trec", "Tsup", "oveTSupSet", "Trec_model", "Ta"])
        y_data.ahu_pump_sup.plot(ax=ax[1], drawstyle="steps-post")
        y_data.ahu_pump_ret.plot(ax=ax[1], drawstyle="steps-post")
        y_data.Pvent.plot(ax=ax[2], drawstyle="steps-post")
        plt.show()
        
        # only TRec
        ax = data.ahu_reaTHeaRec.plot(color="k")
        ax1 = ax.twinx()
        data.ahu_pump_sup .plot(color="y", ax=ax1)
        plt.show()
        
        # power balances
        y_data["Ph_water"] = y_data["oveValCoi"]*2*1000*25*(y_data["ahu_reaTCoiSup"] - y_data["ahu_reaTCoiRet"])
        y_data["Ph_air"] = y_data.ahu_reaFloSupAir*32*1*30*(y_data["Tsup_air"] - y_data["ahu_reaTHeaRec"])
        ax = y_data.Ph_water.plot(drawstyle="steps-post")
        y_data.Ph_air.plot(ax=ax, drawstyle="steps-post")
        y_data.Pvent.plot(ax=ax, drawstyle="steps-post")
        ax1 = ax.twinx()
        data.Ti.plot(color="r", ax=ax1)
        
        ax.legend()
        plt.show()
        
        
        # when Tsup is below Ti, set Tsup == Ti:
        #y_data["Tsup"] = y_data["oveTSetSup_u"]
        #ndx = y_data[(y_data.Tsup - y_data.Ti) <= 0].index
        #y_data["Tsup"].loc[ndx] = y_data["Ti"].loc[ndx]
        #y_data = data[:4]
        
        #y_data["Tsup"].loc[ndx] += 1.01

    """
    ax = (y_data.Tsup-y_data.Ti).plot(color="k")
    ax1 = ax.twinx()
    y_data.Ph.plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax1)
    ax.legend(["deltaT"])
    ax1.legend(["Ph"])
    plt.show()
    """

    
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    #param_guess = ca.DM([0.1,0.1,1E7,1E8,50,1.05,39.10,0.90])
    #param_guess = ca.DM([0.01,0.01,1E8,1E9,100,1.05,3900.10,0.90])
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
    
    param_guess = np.array([
                        5.473643e-05,
                        2.470447e-04,
                        1.616113e-03,
                        1.319700e-01,
                        4.549e+07,
                        2.499e+09,
                        1.040476e+02,
                        32,
                        0.5,
                        500,
                        1.5,
                        300,
                        900,
                        1000,
                        0.99,
                        0.5,
                        0.75
                        ])
    
    param_guess = np.array([
                        5.473643e-05,
                        2.470447e-04,
                        1.616113e-03,
                        1.319700e-01,
                        4.549e+07,
                        2.499e+09,
                        1.040476e+02,
                        1000
                        ])
    
    
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    # rho_int:
    lbp[3] = 0
    ubp[3] = 1
    lbp[len_p-1] = 990
    ubp[len_p-1] = 1010
    #ubp[7] = 338.15
    """
    # eta_hex:
    lbp[len_p-1] = 0.30
    ubp[len_p-1] = 0.99
    lbp[len_p-2] = 0.30
    ubp[len_p-2] = 0.99
    lbp[len_p-3] = 0.65
    ubp[len_p-3] = 1
    #lbp[len_p-3] = 1.0
    #ubp[len_p-3] = 1.0
    lbp[len_p-4] = 900
    ubp[len_p-4] = 1100
    lbp[len_p-5] = 10
    ubp[len_p-5] = 10000
    lbp[len_p-6] = 290
    ubp[len_p-6] = 305
    lbp[len_p-7] = 1
    ubp[len_p-7] = 3
    lbp[len_p-8] = 300
    ubp[len_p-8] = 1000
    lbp[len_p-9] = 0.3
    ubp[len_p-9] = 0.7
    """
    
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [1,1,12,1,1,12],
        "u_nom_b": [0,0,289.15,0,0,289.15],
        "r_nom": [12,300,1E6,1E6,1E6],
        "r_nom_b": [289.15,0,0,0,0],
        "y_nom": [12],
        "y_nom_b": [289.15]
    }
    
    x_guess = np.array(
                       [
                        y_data.Ti.values.flatten(),
                        y_data.Ti.values.flatten()
                        #y_data.Tsup_air.values.flatten(),
                        #(1 - y_data.ahu_pump_sup.values).flatten()
                       ]
                       )
    x_guess = x_guess.T.flatten()
    #y_data = y_data[:3]
    #N = len(y_data)
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        #param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      x_guess=x_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )    
        
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", linestyle="dashed", ax=ax)
        ax.set_ylim([290,310])
        ax.legend()
        plt.show()    
        
        print(params)
    
    """
    Continue with normal operation for e.g. a week.

    Try to identify separate HVAC-model with results.
    """
    boptest = Boptest(
                    boptest_cfg,
                    name="singlezone_commercial"
                    )
    
    data_path = os.path.join(get_data_path(), "data_bestest_hydronic_normal_op.csv")

    if GENERATE_DATA_NORMAL_OP:
        
        for n in range(N):
            # no radiator:
            """
            Turn off radiator, see how ventilation responds
            """
            u_0 = pd.Series(index=['rad_val'], data=[0])
                    
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

        print(data)
        res = boptest.get_data(tf=N*boptest.h)
        # correction for wrong map:
        res["Pvent"] -= res["Prad"]
        # shift control signal:
        #res["ahu_pump_sup"] = res["ahu_pump_sup"].shift(-1) 
        
        """
        Make some plots of pump speeds etc.
        """
        flow = res[["ahu_reaFloSupAir", "ahu_pump_sup"]]
        flow = flow.sort_values(ascending=True, by="ahu_pump_sup")
        flow.index = range(len(flow.index))
        ax = flow.ahu_pump_sup.plot(color="k")
        ax1 = ax.twinx()
        flow.ahu_reaFloSupAir.plot(ax=ax1, color="r", linestyle="dashed")
        plt.show()
        
    else:
        data = pd.read_csv(data_path, index_col=0)
        
    
    cfg_path = "configs/n_power_simple.json"
    
    param_guess = np.array([
                    32,
                    1.5
                    ])
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    lbp[0] = 10
    ubp[0] = 50
    lbp[1] = 0.5
    ubp[1] = 5
    
    data["Prad"] = data["Prad"].shift(-1) 
    #data["Ptot"] = data["Ptot"].shift(-1) 
    data["Pvent"] = data["Pvent"].shift(-1) 
    data["dh_pump"] = data["dh_pump"].shift(-1) 
    data["oveValCoi"] = data["oveValCoi"].shift(-1) 
    data["ahu_pump_sup"] = data["ahu_pump_sup"].shift(-1) 
    data["ahu_pump_ret"] = data["ahu_pump_ret"].shift(-1) 
    data["ahu_reaTCoiSup"] = data["ahu_reaTCoiSup"].shift(-1) 
    data["ahu_reaTCoiRet"] = data["ahu_reaTCoiRet"].shift(-1) 
    #data["Tsup_air"] = data["Tsup_air"].shift(-1) 
    data["oveTSupSet"] = data["oveTSupSet"].shift(-1) 
    
    """
    Adjust:
    """
    data.oveTSupSet[data.oveTSupSet == 288.15] += 15
    data["m_flow_weight"] = data["ahu_pump_sup"] + 0.01 
    
    # unsure whether to pull this back or not:
    #data["ahu_reaTRetAir"] = data["ahu_reaTRetAir"].shift(-1) 
    #data["ahu_reaTHeaRec"] = data["ahu_reaTHeaRec"].shift(-1) 
    data["Ta"] = data["Ta"].shift(-1) 
    data["phi_s"] = data["phi_s"].shift(-1) 
    data["ahu_reaFloSupAir"] = data["ahu_reaFloSupAir"].shift(-1)
    y_data = data[:-1]
    # TODO: need to modularize this:
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["Pvent"]
    y_data["y3"] = y_data["ahu_reaTHeaRec"]
    y_data["y4"] = y_data["ahu_reaFloSupAir"]
    y_data["y5"] = y_data["ahu_reaTRetAir"]
    y_data["y6"] = y_data["Tsup_air"]
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess) as param_est:
                             #as param_est:
        Q = ca.DM.eye(0)
        R = ca.DM.eye(1)
        #param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )    
        
        ax = sol["ahu_reaFloSupAir"].plot(color="r")
        sol["y4"].plot(color="k", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    
        
        print(params)
        
    """
    Plot sorted:
    """
    flow = sol[["ahu_reaFloSupAir", "ahu_pump_sup", "y4"]]
    flow = flow.sort_values(ascending=True, by="ahu_pump_sup")
    flow.index = range(len(flow.index))
    ax = flow.ahu_pump_sup.plot(color="k")
    ax1 = ax.twinx()
    flow.ahu_reaFloSupAir.plot(ax=ax1, color="r", linestyle="dashed")
    flow.y4.plot(ax=ax1, color="b", linestyle="dashed")
    plt.show()