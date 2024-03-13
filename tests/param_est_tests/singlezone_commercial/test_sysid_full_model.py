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
                        "data_bestest_hydronic_normal_op.csv"
                        )    
    data_path = os.path.join(
                            get_data_path(), 
                            "data_bestest_hydronic_normal_op_60s.csv"
                            )    
    #N = 24*7*60*3
    N = 24*7*60*3
    #N = 24
    
    if GENERATE_DATA_NORMAL_OP:
        
        for n in range(N):                  
            try:
                _, y_meas, u_meas = boptest.evolve()
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

    
    flow = data[["reaPFan_y", "ahu_pump_sup"]]
    flow = flow.sort_values(ascending=True, by="ahu_pump_sup")
    flow.index = range(len(flow.index))
    ax = flow.ahu_pump_sup.plot(color="k")
    ax1 = ax.twinx()
    flow.reaPFan_y.plot(ax=ax1, color="r", linestyle="dashed")
    plt.show()
    
    data["Pfan"] = data["reaPFan_y"]
    # correction for wrong map (Qtot maps to Pvent..):
    data["Pvent"] -= data["Prad"]
    
    data["Prad"] = data["Prad"].shift(-1) 
    data["PFan"] = data["Pfan"].shift(-1) 
    #data["Ptot"] = data["Ptot"].shift(-1) 
    data["Pvent"] = data["Pvent"].shift(-1) 
    data["dh_pump"] = data["dh_pump"].shift(-1) 
    #data["oveValCoi"] = data["oveValCoi"].shift(-1) 
    data["coi_val"] = data["coi_val"].shift(-1) 
    data["coi_flo"] = data["coi_flo"].shift(-1) 
    data["rad_val"] = data["rad_val"].shift(-1) 
    
    """
    Resample valve openings:
    """
    
    data["rad_flo"] = data["rad_flo"].shift(-1) 
    data["Tret_coi"] = data["Tret_coi"].shift(-1)
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
    
    # unsure whether to pull this back or not:
    #data["ahu_reaTRetAir"] = data["ahu_reaTRetAir"].shift(-1) 
    data["ahu_reaTHeaRec"] = data["ahu_reaTHeaRec"].shift(-1) 
    data["Ta"] = data["Ta"].shift(-1) 
    data["phi_s"] = data["phi_s"].shift(-1) 
    data["ahu_reaFloSupAir"] = data["ahu_reaFloSupAir"].shift(-1)
    #y_data = data[:-1]
    data = data.iloc[:-1]
    data.index = pd.TimedeltaIndex(data.index, unit="s")
    y_data = data.resample(rule="15min").asfreq()
    # special handling of these:_
    integrate = ["rad_flo", "coi_flo", "Pvent", "Prad"]
    for name in integrate:
        y_data[name] = data[name].resample(rule="15min").mean()
        
    y_data["y1"] = y_data["Prad"]
    y_data["y2"] = y_data["Pvent"]
    y_data["y3"] = y_data["ahu_reaTHeaRec"]
    y_data["y4"] = y_data["ahu_reaTRetAir"]
    y_data["y5"] = y_data["ahu_reaFloSupAir"]
    y_data["y6"] = y_data["rad_flo"]
    y_data["y7"] = y_data["coi_flo"]
    y_data["y8"] = y_data["rad_flo"] + y_data["coi_flo"]
    y_data["y9"] = y_data["Tret"]
    y_data["y10"] = y_data["Tret_coi"]
    y_data["y11"] = y_data["Tsup_air"]
    y_data["y12"] = y_data["Ti"]
        
    """
    Cut out first week, initialization has some strange behaviour:
    """
    dt = (y_data.index[1] - y_data.index[0]).seconds
    M = 24*7*4
    train = y_data[M:2*M]
    test = y_data[2*M:3*M]
    #y_data = y_data[M:M+10]
    y_data = train
    N = len(y_data)  
    y_data.index = np.arange(0, N*dt, dt)
    """
    Set measurements:
    """
    y_data["ahu_pump_sup_on"] = y_data["ahu_pump_sup"].astype(bool).astype(int)
    dt = y_data.index[1] - y_data.index[0]
    y_data.index = range(len(y_data.index))
    
    
    kwargs = {
        #"x_nom": [12,12,12,12],
        #"x_nom_b": [289.15,289.15,289.15,289.15],
        "x_nom": 12,
        "x_nom_b": 289.15,
        "z_nom": [1E6,1E6,1,1,1,1,12,12,12,12,1,1],
        "z_nom_b": [0,0,0,0,0,0,289.15,289.15,289.15,289.15,0,0],
        "r_nom": [12,300,1E5,1E5,1E5],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [12,1,1,1,12],
        "u_nom_b ": [289.15,0,0,0,289.15],
        "y_nom": [1E6,1E6,12,12,1,1,1,1,12,12,12,12],
        "y_nom_b": [0,0,289.15,289.15,0,0,0,0,289.15,289.15,289.15,289.15],
        #"slack": True
        "slack": False
    }
         
    #cfg_path = "configs/Tsup_air_Tret_coi_Prad_rad_Tret_Trec.json"
    cfg_path = "configs/full_model.json"
        
    param_guess = {
                "UA_vent_air": 
                {
                    "init": 43500.780921,
                    #"lb": 43500.780921,
                    #"ub": 43500.780921
                },
                "UA_sup_nom": 
                {
                    "init": 43500.780921,
                    #"lb": 43500.780921,
                    #"ub": 43500.780921
                },
                "cp_water":
                {
                    "init": 4200,
                    "lb": 4200,
                    "ub": 4200,
                },
                "eta_hex_ahu": 
                {
                    "init": 0.999,
                    "ub": 1,
                    "lb": 0.999
                },
                "eta_hex_rad":
                {
                    "init": 0.999,
                    "ub": 1,
                    "lb": 0.999
                },
                "k":
                {
                    "init": 1e-4, 
                    "lb": 1e-4,
                    "ub": 1e-4
                },
                "m_flow_air_nom":
                {
                    "init": 32,
                    "lb": 32,
                    "ub": 32
                },
                "n":
                {
                    "init": 1.5,
                    "lb": 1,
                    "ub": 3
                },
                "n1":
                {
                    "init": 1.5,
                    "lb": 0.5,
                    "ub": 3
                },
                "n2":
                {
                    "init": 1.5,
                    "lb": 1,
                    "ub": 3
                },
                "n3": 
                {
                    "init": 1.821392,
                    #"lb": 1.821392,
                    #"ub": 1.821392
                },
                "n4": 
                {
                    "init": 0.5,
                    "lb": 0.1,
                    "ub": 3
                },
                "cp_air": 
                {
                    "init": 1000,
                    "lb": 1000,
                    "ub": 1000
                },
                "eta_hex1": 
                {
                    "init": 0.75,
                    "lb": 0.5,
                    "ub": 1.0
                },
                "eta_hex2":
                {
                    "init": 0.75,
                    "lb": 0.75,
                    "ub": 0.75
                },
                "Trec_off":
                {
                    "init": 290.15, 
                    "lb": 280.15,
                    "ub": 300.15
                },
                "ahu_pump_sup_thres":
                {
                    "init": 1e-6, 
                    "lb": 1e-6,
                    "ub": 1e-6
                },
                "Csup_nom": 
                {
                    "init":  352236.218477,
                    "lb":  352236.218477,
                    "ub":  352236.218477
                },
                "Rsupi":
                {
                    "init":  0.008363,
                    "ub":  0.008363,
                    "lb":  0.008363
                },
                "Tret_b":
                {
                    "init": 310,
                    "lb": 290,
                    "ub": 330
                },
                "Tret_a":
                {
                    "init": 6,
                    "lb": 1,
                    "ub": 6
                },
                "tau":
                {
                    "init": 100,
                },
                "rad_flo_nom":
                {
                    "init": 8, 
                    "lb": 7,
                    "ub": 10
                },
                "coi_flo_nom_b":
                {
                    "init": 8,
                    "lb": 2,
                    "ub": 10
                },
                "coi_flo_nom_a":
                {
                    "init": 7,
                    "lb": 2,
                    "ub": 10
                },
                "Tret_coi_b":
                {
                    "init": 1,
                    "lb": 0.01,
                    "ub": 10
                },
                "dh_Tsup":
                {
                    "init": 330.15,
                    "lb": 330.15,
                    "ub": 330.15
                },
                "Rie": 
                {
                    "init": 4.222012e-05
                },
                "Rea": 
                {
                    "init": 1.757842e-04
                },
                "Ria":
                {
                    "init": 1e-3
                },
                "Ci":
                {
                    "init": 8.126425e+07
                },
                "rho_int":
                {
                    "init": 0.25, 
                    "lb": 0.25,
                    "ub": 0.25
                },
                "Ce":
                {
                    "init": 2.732098e+09
                },
                "Ai":
                {
                    "init": 2.800931e+02
                }
                }
    
    x_guess = y_data[["Ti", "Ti", "Tret", "Tsup_air"]].values.flatten()
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        Q = ca.DM.eye(4)
        R = ca.DM.eye(12)
        #R[0,0] =2 1E-9
        R[0,0] = 1E-9
        R[1,1] = 1E-9
        R[2,2] = 1E-2
        R[3,3] = 1E-2
        R[4,4] = 1
        R[5,5] = 1
        R[6,6] = 1
        R[7,7] = 1
        R[8,8] = 1E-2
        R[9,9] = 1E-2
        R[10,10] = 1E-2
        #R[11,11] = 1
        lbp = param_est.get_lbp(1e-2)
        ubp = param_est.get_ubp(1e2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )       
          
        y = param_est.dae.y
        fig, _axes = plt.subplots(6,2, sharex=True)
        axes = _axes.flatten()
        for i, (meas, var) in enumerate(y.items()):
            ax = axes[i]
            sol[meas].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75)
            sol[var.name()].plot(ax=ax, color="r", linewidth=0.75)
            ax.legend()
    
        fig.tight_layout()
        plt.show()
        
        ax = sol[meas].plot(color="k", linestyle="dashed", linewidth=0.75)
        sol["ahu_reaTHeaRec"].plot(ax=ax, color="y", linewidth=0.75)
        sol[var.name()].plot(ax=ax, color="r", linewidth=0.75)
        ax.legend()
        
        print(params)
     
    params.to_csv("full_model_latest.csv", index=True)   
    """
    Repeat fixed parameter estimation,
    i.e. simulation.
    """
    y_data = test
    N = len(y_data)
    lbp = 1.0*params.values
    ubp = 1.0*params.values
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        Q = ca.DM.eye(4)
        R = ca.DM.eye(12)
        #R[0,0] =2 1E-9
        R[0,0] = 1E-9
        R[1,1] = 1E-9
        R[2,2] = 1E-2
        R[3,3] = 1E-2
        R[4,4] = 1
        R[5,5] = 1
        R[6,6] = 1
        R[7,7] = 1
        R[8,8] = 1E-2
        R[9,9] = 1E-2
        R[10,10] = 1E-2
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )       
          
        y = param_est.dae.y
        fig, _axes = plt.subplots(6,2, sharex=True)
        axes = _axes.flatten()
        for i, (meas, var) in enumerate(y.items()):
            ax = axes[i]
            sol[meas].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75)
            sol[var.name()].plot(ax=ax, color="r", linewidth=0.75)
            ax.legend()
    
        fig.tight_layout()
        plt.show()
        print(params)