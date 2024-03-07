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
    N = 24*7*60*2
    
    if GENERATE_DATA_NORMAL_OP:
        
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
            u_0 = pd.Series(index=['oveTSupSet'], data=[294.15])
                  
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
    data["Tsup_air"] = data["Tsup_air"].shift(-1) 
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
    integrate = ["rad_flo", "coi_flo", "Pvent", "Prad"]
    for name in integrate:
        y_data[name] = data[name].resample(rule="15min").mean()
        
    """
    Cut out first week, initialization has some strange behaviour:
    """
    M = 24*7*4
    y_data = y_data[M:-1]
    N = len(y_data)  
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0, N*dt, dt)
    """
    Set measurements:
    """
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
    """
    Plot ventilation energy
    """
    if PLOT:
    
        #ax = y_data["Tsup_air"].plot(color="r")
        #(y_data["ahu_reaTHeaRec"] + y_data["Pvent"]*1E-4).plot(ax=ax)
        ax = y_data["Tret_coi"].plot(color="k")
        y_data["ahu_reaTCoiSup"].plot(color="r", ax=ax)
        ax1 = ax.twinx()
        y_data["ahu_pump_sup"].plot(color="y", linestyle="dashed", ax=ax1)
        #y_data["Pvent"].plot(color="k", linestyle="dashed", ax=ax1)
        #(y_data["ahu_pump_sup"]*y_data["Pvent"].max()).plot(color="y", linestyle="dashed", ax=ax1)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    
        
        ax = y_data["Tret"].plot(color="k")
        y_data["Tsup"].plot(color="r", ax=ax)
        ax1 = ax.twinx()
        y_data["rad_val"].plot(color="y", linestyle="dashed", ax=ax1)
        #y_data["Pvent"].plot(color="k", linestyle="dashed", ax=ax1)
        #(y_data["ahu_pump_sup"]*y_data["Pvent"].max()).plot(color="y", linestyle="dashed", ax=ax1)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()  
        
        ax = y_data["rad_val"].plot(color="k")
        ax1 = ax.twinx()
        y_data["rad_val"].plot(color="y", linestyle="dashed", ax=ax1)
        #y_data["Pvent"].plot(color="k", linestyle="dashed", ax=ax1)
        #(y_data["ahu_pump_sup"]*y_data["Pvent"].max()).plot(color="y", linestyle="dashed", ax=ax1)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    

        ax = y_data["coi_val"].plot(color="k")
        ax1 = ax.twinx()
        y_data["coi_flo"].plot(color="y", linestyle="dashed", ax=ax1)
        #y_data["Pvent"].plot(color="k", linestyle="dashed", ax=ax1)
        #(y_data["ahu_pump_sup"]*y_data["Pvent"].max()).plot(color="y", linestyle="dashed", ax=ax1)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    

        """
        Plot sorted mass flow against TCoiRet
        """
        flow = y_data[y_data.coi_flo > 1E-4]
        flow = flow.sort_values(by="coi_flo", ascending=True)
        flow.index = range(len(flow.index))
        ax = flow.coi_flo.plot(color="r")
        ax1 = ax.twinx()
        #flow.ahu_reaTCoiRet.plot(color="k", ax=ax1)
        #flow.ahu_reaTCoiSup.plot(color="r", ax=ax1)
        (flow.ahu_reaTCoiSup-flow.Tret_coi).plot(color="k", ax=ax1)
        #flow.ahu_reaTCoiSup.plot(color="k", ax=ax1)
        plt.show()
        
        """
        Do the same, but for radiator.
        """
        
        flow = y_data[y_data.rad_flo > 1E-2]
        flow = flow.sort_values(by="rad_flo", ascending=True)
        flow.index = range(len(flow.index))
        ax = flow.rad_flo.plot(color="r")
        ax1 = ax.twinx()
        #flow.Tret.plot(color="k", ax=ax1)
        flow.Tsup.plot(color="k", ax=ax1)
        #(flow.Tsup-flow.Tret).plot(color="b", ax=ax1)
        plt.show()
        
        """
        Do the same, except on 
        valve opening -> mass flow.
        """
        flow = y_data[y_data.rad_flo > 1E-2]
        flow = flow.sort_values(by="rad_flo", ascending=True)
        flow.index = range(len(flow.index))
        ax = flow.rad_val.plot(color="r")
        ax.legend()
        ax1 = ax.twinx()
        #flow.Tret.plot(color="k", ax=ax1)
        flow.rad_flo.plot(color="k", ax=ax1)
        #(flow.Tsup-flow.Tret).plot(color="b", ax=ax1)
        plt.show()
        
        flow = y_data[y_data.coi_flo > 1E-2]
        flow = flow.sort_values(by="coi_flo", ascending=True)
        flow.index = range(len(flow.index))
        ax = flow.coi_val.plot(color="r")
        ax.legend()
        ax1 = ax.twinx()
        #flow.Tret.plot(color="k", ax=ax1)
        flow.coi_flo.plot(color="k", ax=ax1)
        #(flow.Tsup-flow.Tret).plot(color="b", ax=ax1)
        plt.show()



    kwargs = {
        "z_nom": [12,1E6,1E6,1,1,1,1,12],
        "z_nom_b": [289.15,0,0,0,0,0,0,289.15],
        "r_nom": [12,300,1E5,1E5,1E5],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [12,12,1,1,12,1,1,1E6,12,12],
        "u_nom_b ": [289.15,289.15,0,0,289.15,0,0,0,289.15,289.15],
        "y_nom": [1E6,1E6,1,1,1,12,12],
        "y_nom_b": [0,0,0,0,0,289.15,289.15],
        #"slack": True
        "slack": False
    }
        
    #kwargs = dict()
    #y_data = y_data.loc[[ndx for ndx in y_data.index if ndx % 900 == 0]]
    
    cfg_path = "configs/Tsup_air_Tret_coi_Prad_rad.json"
    param_guess = np.array([
                            1E-5,
                            1E-5,
                            1E3,
                            1E1,
                            1E6,
                            0.5,
                            300.15
                          ]) 
    param_guess = np.array([
                            1E-5,
                            290.15,
                            4200,
                            0.999,
                            0.999,
                            1e-2,
                            1.2,
                            1.2,
                            1,
                            7,
                            2,
                            1,
                            335.15
                          ]) 
    lbp = param_guess*1e-2
    ubp = param_guess*1e2
    len_p = param_guess.shape[0]
    
    # cp_water:
    lbp[2] = 4200
    ubp[2] = 4200
    lbp[3] = 0.999
    ubp[3] = 0.999
    lbp[4] = 0.9
    ubp[4] = 1
    lbp[5] = 1e-6
    ubp[5] = 1e2
    
    lbp[len_p-1] = 330.15
    ubp[len_p-1] = 340.15
    lbp[len_p-2] = 1E-3
    ubp[len_p-2] = 10
    lbp[len_p-3] = 1
    ubp[len_p-3] = 10
    lbp[len_p-4] = 1
    ubp[len_p-4] = 1
    lbp[len_p-5] = 3
    ubp[len_p-5] = 10
    lbp[len_p-6] = 1
    ubp[len_p-6] = 9
    lbp[len_p-7] = 1
    ubp[len_p-7] = 10
    #lbp[len_p-8] = 1
    #ubp[len_p-8] = 2
    
    x_guess = y_data["Tsup_air"].values
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        Q = ca.DM.eye(0)
        R = ca.DM.eye(7)
        #R[0,0] =2 1E-9
        R[0,0] = 1E-9
        R[1,1] = 1E-9
        R[5,5] = 1E-2
        R[6,6] = 1E-2
        #param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )       
          
        y = param_est.dae.y
        fig, axes = plt.subplots(7,1, sharex=True)
        for i, (meas, var) in enumerate(y.items()):
            ax = axes[i]
            sol[meas].plot(ax=ax, color="k", linestyle="dashed", linewidth=0.75)
            sol[var.name()].plot(ax=ax, color="r", linewidth=0.75)
            ax.legend()
    
        plt.show()
        
        ax = sol[meas].plot(color="k", linestyle="dashed", linewidth=0.75)
        sol["ahu_reaTHeaRec"].plot(ax=ax, color="y", linewidth=0.75)
        sol[var.name()].plot(ax=ax, color="r", linewidth=0.75)
        ax.legend()
        

        print(params)