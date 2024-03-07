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
import l4casadi as l4c
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    #cfg_path = os.path.join("configs", "4R3C_vent_n_power_eff_non_linear.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA_NORMAL_OP = False
    PLOT = True
    
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
                            "data_bestest_hydronic_normal_op_60s.csv"
                            )    
    data_path = os.path.join(
                            get_data_path(), 
                            "data_bestest_hydronic_normal_op.csv"
                            )    
    N = 24*7*4

    if GENERATE_DATA_NORMAL_OP:
        
        for n in range(N):
            # no radiator:
            """
            Turn off radiator, see how ventilation responds
            """
            #u_0 = pd.Series(index=['rad_val'], data=[0])
            u_0 = pd.Series(
                            index=['ahu_pump_sup','ahu_pump_ret'], 
                            data=[0.03,0.03]
                            )
                    
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
    
    dt = y_data.index[1] - y_data.index[0]
    
    """
    Plot radiator energy
    """
    #flow = data[["rad_val", "Prad", "ahu_pump_sup"]]
    flow = data[["rad_val", "rad_flo"]]
    flow = flow.sort_values(ascending=True, by="rad_val")
    flow.index = range(len(flow.index))
    ax = flow.rad_val.plot(color="k")
    ax1 = ax.twinx()
    #flow.Prad.plot(ax=ax1, color="r", linestyle="dashed")
    #flow.ahu_pump_sup.plot(ax=ax, color="b")
    flow.rad_flo.plot(ax=ax1, color="b")
    plt.show()
    
    y_data = y_data.loc[[ndx for ndx in y_data.index if ndx % 900 == 0]]
    ax = data["Tsup"].plot(color="r")
    data["Tret"].plot(color="y", ax=ax)
    ax1 = ax.twinx()
    data["rad_val"].plot(ax=ax1)
    plt.show()

    cfg_path = "configs/Tret_double_valve_power_curves.json"
    param_guess = np.array([
                            1.2,
                            1.2,
                            100,
                            1,
                            7,
                            1,
                            7,
                            290.15,
                            30,
                            295.5,
                            5,
                          ]) 
    lbp = param_guess*0.01
    ubp = param_guess*100
    lbp[0] = 1
    ubp[0] = 1.5
    lbp[1] = 1
    ubp[1] = 1.5
    # tau air:
    lbp[3] = 1
    ubp[3] = 1000
    lbp[5] = 1
    ubp[5] = 2
    len_p = param_guess.shape[0]
    # temperatures:
    lbp[len_p-1] = 30
    ubp[len_p-1] = 50
    lbp[len_p-2] = 290.5
    ubp[len_p-2] = 298.5
    lbp[len_p-3] = 5
    ubp[len_p-3] = 10
    lbp[len_p-4] = 285.15
    ubp[len_p-4] = 298.5
    
    
    y_data = y_data.iloc[96*2:]
    N = len(y_data)
    
    kwargs = {
        "x_nom":[12,12],
        "x_nom_b ": [289.15,289.15],
        "z_nom": [1,1,1,1,12,12],
        "z_nom_b": [0,0,0,0,289.15,289.15],
        "r_nom": [12,300,1E5,1E5,1E5],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [1,1,1,1],
        "u_nom_b ": [0,0,0,0],
        "y_nom": [1,1,1,12,12],
        "y_nom_b": [0,0,0,289.15,289.15],
        #"slack": True
        "slack": False
    }
    
    y_data["rad_val_weight"] = y_data.rad_val.astype(bool) + 0.01
    y_data["coi_val_weight"] = y_data.coi_val.astype(bool) + 0.01
    
    x_guess = y_data[["Tret", "Tret_coi"]].values
    lbx = 0.8*x_guess
    ubx = 1.2*x_guess
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        Q = ca.DM.eye(2)
        R = ca.DM.eye(5)
        R[3,3] = 1E-2
        R[4,4] = 1E-2
        #param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      lbx=lbx,
                                      ubx=ubx,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )       

        fig, axes = plt.subplots(3,1, sharex=True)
        ax = axes[0]
        sol["rad_flo"].plot(color="r", ax=ax)
        sol["y6"].plot(color="k", linestyle="dashed", ax=ax)
        ax = axes[1]
        sol["coi_flo"].plot(color="r", ax=ax)
        sol["y7"].plot(color="k", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax = axes[2]
        sol["tot_flo"].plot(color="r", ax=ax)
        sol["y8"].plot(color="k", linestyle="dashed", ax=ax)
        ax.legend()
        plt.show()   


        ax = sol["Tret"].plot(color="r", linewidth=0.75)
        sol["y9"].plot(color="k", linewidth=0.75, linestyle="dashed", ax=ax)
        #sol["y9"].plot(color="k", linewidth=0.75, linestyle="dashed", ax=ax)
        ax1 = ax.twinx()
        #sol["rad_val_on"].plot(linestyle="dashed", linewidth=0.75, drawstyle="steps-post", ax=ax1, color="b")
        sol["rad_val"].plot(linestyle="dashed", ax=ax1, color="y", linewidth=0.75)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    

        ax = sol["Tret_coi"].plot(color="r", linewidth=0.75)
        sol["y10"].plot(color="k", linewidth=0.75, linestyle="dashed", ax=ax)
        #sol["y9"].plot(color="k", linewidth=0.75, linestyle="dashed", ax=ax)
        ax1 = ax.twinx()
        #sol["rad_val_on"].plot(linestyle="dashed", linewidth=0.75, drawstyle="steps-post", ax=ax1, color="b")
        sol["coi_val"].plot(linestyle="dashed", ax=ax1, color="y", linewidth=0.75)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()      
    
        print(params)
        
    """
    Plot sorted:
    """