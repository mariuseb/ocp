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
from ocp.nn import ParamDataset, NN
import torch
#import l4casadi as l4c
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    #cfg_path = os.path.join("configs", "4R3C_vent_n_power_eff_non_linear.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA_NORMAL_OP = False
    PLOT = False
    
    """
    Normal operation for e.g. a week.

    Try to identify separate HVAC-model with results.
    """
    boptest = Boptest(
                    boptest_cfg,
                    name="singlezone_commercial"
                    )
    data_path = os.path.join(
                            get_data_path(), 
                            "data_bestest_hydronic_normal_op_60s_test_rad.csv"
                            )    
    data_path = os.path.join(
                        get_data_path(), 
                        "data_bestest_hydronic_normal_op_60s.csv"
                        )    
    data_path = os.path.join(
                            get_data_path(), 
                            "data_bestest_hydronic_normal_op.csv"
                            )    
    data_path = os.path.join(
                            get_data_path(), 
                            "data_bestest_air_prbs_op.csv"
                            )    
    data_path = os.path.join(
                        get_data_path(), 
                        "data_bestest_air_normal_op.csv"
                        )     
    
    
    if GENERATE_DATA_NORMAL_OP:
        
        sampling_time = "15min"
        prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"), sep=";")
        prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        dt_index = prbs.index
        prbs.Ph /= 5
        prbs = prbs.Ph
        prbs = prbs.round(0)
        prbs = prbs.resample(sampling_time).ffill()
        prbs.index = range(len(prbs.index))
        # baseline control for sysid:
        N = len(prbs)
        
        for n in range(N):
            u_0 = pd.Series(index=['oveTSupSet'], data=[288.15 + 25*prbs.iloc[n]])
            try:
                _, y_meas, u_meas = boptest.evolve(u=u_0)
            except TypeError:
                print(y_meas)
            #u_measured.append(u_meas)
            
            
        data = boptest.get_data(tf=N*boptest.h, downsample=False)
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
    
    # leave out first two days:
    #data = data[2*60*24:]

    # correction for wrong map (Qtot maps to Pvent..):
    data["Pvent"] -= data["Prad"]
    
    data["Prad"] = data["Prad"].shift(-1) 
    #data["Ptot"] = data["Ptot"].shift(-1) 
    data["Pvent"] = data["Pvent"].shift(-1) 
    data["dh_pump"] = data["dh_pump"].shift(-1) 
    #data["oveValCoi"] = data["oveValCoi"].shift(-1) 
    data["coi_val"] = data["coi_val"].shift(-1) 
    data["coi_flo"] = data["coi_flo"].shift(-1) 
    data["rad_val"] = data["rad_val"].shift(-1) 
    data["rad_flo"] = data["rad_flo"].shift(-1) 
    #data["Tret_coi"] = data["Tret_coi"].shift(-1)
    #data["Tsup"] = data["Tsup"].shift(-1) 
    #data["Tret"] = data["Tret"].shift(-1) 
    data["ahu_pump_sup"] = data["ahu_pump_sup"].shift(-1) 
    data["ahu_pump_ret"] = data["ahu_pump_ret"].shift(-1) 
    data["ahu_reaTCoiSup"] = data["ahu_reaTCoiSup"].shift(-1) 
    #data["ahu_reaTCoiRet"] = data["ahu_reaTCoiRet"].shift(-1) 
    #data["Tsup_air"] = data["Tsup_air"].shift(-1) 
    data["oveTSupSet"] = data["oveTSupSet"].shift(-1) 
    
    """
    Adjust:
    """
    data.oveTSupSet[data.oveTSupSet == 288.15] += 15
    data["m_flow_weight"] = data["ahu_pump_sup"] + 0.01 
    data["ahu_pump_sup_on"] = data["ahu_pump_sup"].astype(bool).astype(int)
    
    # unsure whether to pull this back or not:
    #data["ahu_reaTRetAir"] = data["ahu_reaTRetAir"].shift(-1) 
    data["ahu_reaTHeaRec"] = data["ahu_reaTHeaRec"].shift(-1) 
    data["Ta"] = data["Ta"].shift(-1) 
    data["phi_s"] = data["phi_s"].shift(-1) 
    data["ahu_reaFloSupAir"] = data["ahu_reaFloSupAir"].shift(-1)
    #y_data = data[:-1]
    y_data = data.iloc[:-1]
    # TODO: need to modularize this:
    y_data["y1"] = y_data["Prad"]
    y_data["y2"] = y_data["Pvent"]
    y_data["y3"] = y_data["ahu_reaTHeaRec"]
    y_data["y4"] = y_data["ahu_reaFloSupAir"]
    y_data["y5"] = y_data["ahu_reaTRetAir"]
    y_data["y6"] = y_data["rad_flo"]
    y_data["y7"] = y_data["coi_flo"]
    y_data["y8"] = y_data["rad_flo"] + y_data["coi_flo"]
    y_data["y9"] = y_data["Tret"]
    y_data["y10"] = y_data["Tret_coi"]
    y_data["y11"] = y_data["Tsup_air"]
    y_data["ahu_pump_sup_on"] = y_data["ahu_pump_sup"].astype(bool).astype(int)
    dt = y_data.index[1] - y_data.index[0]
    y_data.index = range(len(y_data.index))
    

    data = data.iloc[:-1]
    data.index = pd.TimedeltaIndex(data.index, unit="s")
    y_data = data.resample(rule="15min").asfreq()
    # special handling of these:_
    integrate = ["rad_flo", "coi_flo", "Pvent", "Prad"]
    for name in integrate:
        y_data[name] = data[name].resample(rule="15min").mean()
    dt = (y_data.index[1] - y_data.index[0]).seconds
    N = len(y_data)
    y_data.index = np.arange(0, N*dt, dt)
    y_data["y11"] = y_data["Tsup_air"]
    """
    Plot ventilation energy
    """
    fig, axes = plt.subplots(2,1,sharex=True)
    ax = axes[0]
    y_data.Tsup_air.plot(ax=ax, color="r", drawstyle="steps-post", linewidth=0.75)
    y_data.Ti.plot(ax=ax, color="k", drawstyle="steps-post", linewidth=0.75)
    y_data.ahu_reaTHeaRec.plot(ax=ax, color="y", drawstyle="steps-post", linewidth=0.75)
    ax1 = ax.twinx()
    #y_data.coi_flo.plot(ax=ax1, linewidth=0.75)
    y_data.Pvent.plot(ax=ax1, linewidth=0.75)
    ax = axes[1]
    y_data.ahu_pump_sup.plot(ax=ax, color="y", drawstyle="steps-post", linewidth=0.75)
    plt.show()

    kwargs = {
        #"x_nom": [12],
        #"x_nom_b": [289.15],
        "z_nom": [12],
        "z_nom_b": [289.15],
        "r_nom": [12,300,1E5,1E5,1E5],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [12,12,1,1,12,1,1,1E6,12,12],
        "u_nom_b ": [289.15,289.15,0,0,289.15,0,0,0,289.15,289.15],
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    
    
    #kwargs = dict()
    #y_data = y_data.loc[[ndx for ndx in y_data.index if ndx % 900 == 0]]
    
    
    M = 1*24*4
    #y_data = y_data[M:-1]
    #y_data = y_data[M:-1]
    y_data = y_data[:-1]
    N = len(y_data)
    cfg_path = "configs/Tsup_air_simple_ALG.json"
    param_guess = {
                "UA_rec_nom": 
                {
                    "init": 1E-5,
                    #"lb": 43500.780921,
                    #"ub": 43500.780921
                },
                "k":
                {
                    "init": 1e-1, 
                    "lb": 1e-1,
                    "ub": 1e-1
                },
                "n":
                {
                    "init": 0.33,
                    "lb": 0.33,
                    "ub": 0.33
                },
                "ahu_pump_sup_thres":
                {
                    "init": 1e-2, 
                    "lb": 1e-2,
                    "ub": 1e-2
                }
                }
    
    
    #lbp = param_guess*1e-3
    #ubp = param_guess*1e3
    #len_p = param_guess.shape[0]
    
    #lbp[2] = 1E1
    #ubp[2] = 1E7
    #lbp[len_p-2] = 285.15
    #ubp[len_p-2] = 295.15
    #lbp[len_p-2] = 1e-8
    #ubp[len_p-2] = 1
    #lbp[len_p-1] = 1
    #ubp[len_p-1] = 3
    
    x_guess = y_data["Tsup_air"].values
    kwargs = dict()
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt, 
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        Q = ca.DM.eye(0)
        R = ca.DM.eye(1)
        lbp = param_est.get_lbp(1e-3)
        ubp = param_est.get_ubp(1e3)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )       
        sol.index = y_data.index
        ax = sol["Tsup_air"].plot(color="r")
        sol["y11"].plot(color="k", linestyle="dashed", ax=ax)
        sol["ahu_reaTHeaRec"].plot(color="g", linestyle="dashed", ax=ax)
        #y_data["ahu_reaTHeaRec"].plot(color="b", linestyle="dashed", ax=ax)
        #y_data["ahu_reaTHeaRec"].plot(color="m", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax1 = ax.twinx()
        ax.legend()
        #y_data["Pvent"].plot(ax=ax1, color= "y")
        plt.show()    
        
        ax = sol["Tsup_air"].plot(color="r")
        #y_data["ahu_reaTHeaRec"].plot(ax=ax)
        y_data["y11"].plot(ax=ax, color="y")
        ax1 = ax.twinx()
        y_data["Pvent"].plot(color="k", linestyle="dashed", ax=ax1)
        #(y_data["ahu_pump_sup"]*y_data["Pvent"].max()).plot(color="y", ax=ax1)
        #(y_data["ahu_pump_ret"]*y_data["Pvent"].max()).plot(color="b", linestyle="dashed", ax=ax1)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    
    
        print(params)
        
    """
    Plot sorted:
    """