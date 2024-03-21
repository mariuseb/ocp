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
from ocp.ocp import ParamGuess
#import l4casadi as l4c
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    #cfg_path = os.path.join("configs", "4R3C_vent_n_power_eff_non_linear.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = False
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
                            "data_bestest_hydronic_PRBS_op.csv"
                            )    

    
    if GENERATE_DATA:
        
        sampling_time = "15min"
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
        
        for n in range(N):
            # no radiator:
            """
            Turn off radiator, see how ventilation responds
            u_0 = pd.Series(index=['rad_val'], data=[0])
            u_0 = pd.Series(
                            index=['ahu_pump_sup','ahu_pump_ret'], 
                            data=[0.03,0.03]
                            )
            u_0.loc["rad_val"] = k*0.01
            k += 1
            """
            u_0 = pd.Series(index=['rad_val'], data=[prbs.iloc[n]])
                  
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
        
    else:
        data = pd.read_csv(data_path, index_col=0)
    
    data = data[1:]  
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
    data["rad_flo_on"] = (data.rad_flo > 1E-4).astype(int) + 0.01
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
    #data.oveTSupSet.loc[data.oveTSupSet == 288.15] = 15
    data["m_flow_weight"] = data["ahu_pump_sup"] + 0.01 
    
    # unsure whether to pull this back or not:
    #data["ahu_reaTRetAir"] = data["ahu_reaTRetAir"].shift(-1) 
    data["ahu_reaTHeaRec"] = data["ahu_reaTHeaRec"].shift(-1) 
    data["Ta"] = data["Ta"].shift(-1) 
    data["phi_s"] = data["phi_s"].shift(-1) 
    data["ahu_reaFloSupAir"] = data["ahu_reaFloSupAir"].shift(-1)
    
    data = data.iloc[:-1]
    data.index = pd.TimedeltaIndex(data.index, unit="s")
    y_data = data.resample(rule="15min").asfreq()
    integrate = ["rad_flo", "coi_flo", "Pvent", "Prad"]
    for name in integrate:
        y_data[name] = data[name].resample(rule="15min").mean()
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["Tret"]
    y_data["y3"] = y_data["Tsup_air"]
    
    #M = 24*7*4
    #y_data = y_data.iloc[M:(2*M-1)]
    #y_data = y_data[M:M+10]
    N = len(y_data)  
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0, N*dt, dt)

    """
    Plot heating power, temperature
    """
    ax = y_data.Ti.plot(color="k", linestyle="dashed", linewidth=0.75)
    ax1 = ax.twinx()
    y_data.Prad.plot(color="r", linewidth=0.75)
    y_data.Pvent.plot(color="y", linewidth=0.75)
    plt.show()

    cfg_path = "configs/7R5C.json"

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [1E6,1E6,1,1,1,12,1,12],
        "u_nom_b": [0,0,0,0,0,289.15,0,289.15],
        "r_nom": [12,300,1E6,1E6,1E6],
        "r_nom_b": [289.15,0,0,0,0],
        "y_nom": [12,12,12],
        "y_nom_b": [289.15,289.15,289.15]
    }

    """
    lbp = 1e-2*param_guess
    ubp = 1e2*param_guess
    """
    
    param_guess = ca.DM([
                    4.222012e-05,
                    1.757842e-04,
                    1e-3,
                    1000,
                    0.5,
                    8.126425e+07,
                    2.732098e+09,
                    2.800931e+02
                    ])
    
    param_guess = {"Rie": 
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
                    "Rirad":
                    {
                        "init": 1e-3
                    },
                    "Rrr":
                    {
                        "init": 1e-1
                    },
                    "Rsr":
                    {
                        "init": 1e-3
                    },
                    "rho_int":
                    {
                        "init": 0.25, 
                        "lb": 1E-6,
                        "ub": 1
                    },
                    "Ci":
                    {
                        "init": 8.126425e+07
                    },
                    "Ce":
                    {
                        "init": 2.732098e+09
                    },
                    "Crad":
                    {
                        "init": 2.732098e+06
                    },
                    "Cret":
                    {
                        "init": 2.732098e+04
                    },
                    "Csup_nom":
                    {
                        "init": 2.732098e+04
                    },
                    "Ai":
                    {
                        "init": 2.800931e+02
                    },
                    "cp_water":
                    {
                        "init": 4200,
                        "lb": 4200,
                        "ub": 4200
                    },
                    "cp_air":
                    {
                        "init": 900,
                        "lb": 1000,
                        "ub": 1100
                    },
                    "alpha_vent1":
                    {
                        "init": 0.5,
                        "lb": 1E-6,
                        "ub": 1
                    },
                    "alpha_vent2":
                    {
                        "init": 0.5,
                        "lb": 1E-6,
                        "ub": 1
                    },
                    "Tret_offset":
                    {
                        "init": 5,
                        "lb": 1,
                        "ub": 30
                    }
                    }
    
    x_guess = y_data[["Ti", "Ti", "Tret", "Tret","Tsup_air"]].values.T
    #param_guess = ParamGuess(_param_guess)    

    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        Q = ca.DM.eye(5)
        R = ca.DM.eye(3)
        R[1,1] = 1e-1
        R[2,2] = 1e-1
        #lbp = 1e-2*param_guess
        #ubp = 1e2*param_guess
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
        
        sol.index = y_data.index
        # compare model flows with measurements:
        ax = sol["y1"].plot(color="k", linewidth=0.75)
        sol["Ti"].plot(ax=ax, color="r", linestyle="dashed", linewidth=0.75)
        y_data["Tsup_air"].plot(ax=ax, color="m", linestyle="dashed", linewidth=0.75)
        #sol[var.name()].plot(ax=ax, color="r", linewidth=0.75)
        ax1 = ax.twinx()
        y_data["ahu_pump_ret"].plot(ax=ax1, color="y", linewidth=0.75, drawstyle="steps-post")
        y_data["ahu_pump_sup"].plot(ax=ax1, color="b", linewidth=0.75, drawstyle="steps-post")
        ax.legend()
        plt.show()
        
        ax = sol["y2"].plot(color="k", linewidth=0.75)
        sol["Tret"].plot(ax=ax, color="r", linestyle="dashed", linewidth=0.75)
        sol["Trad"].plot(ax=ax, color="g", linestyle="dashed", linewidth=0.75)
        plt.show()

        ax = sol["y3"].plot(color="k", linewidth=0.75)
        sol["Tsup_air"].plot(ax=ax, color="r", linestyle="dashed", linewidth=0.75)
        plt.show()
        
        print(params)
        
    params.to_csv("envelope_model_latest.csv", index=True)  