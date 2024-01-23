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
                            "data_bestest_hydronic_normal_op.csv"
                            )    
    N = 563

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
                _, y_meas, u_meas = boptest.evolve(u=u_0)
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
    
    cfg_path = "configs/n_power_mass_flow_TRec_Tret_Prad_non_linear.json"
    param_guess = np.array([
                    32,
                    1.5,
                    1000,
                    0.999,
                    0.75,
                    0.6,
                    0.6,
                    290,
                    1.5,
                    1.3,
                    2,
                    4200,
                    0.99,
                    80,
                    1E-4,
                    0.05
                    ])
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    lbp[0] = 10
    ubp[0] = 50
    lbp[1] = 0.5
    ubp[1] = 5
    lbp[2] = 990
    ubp[2] = 1010
    lbp[3] = 0.90
    ubp[3] = 1
    lbp[4] = 0.6
    ubp[4] = 1
    lbp[5] = 0.6
    ubp[5] = 1
    lbp[6] = 0.3
    ubp[6] = 0.7
    lbp[7] = 285
    ubp[7] = 295    
    lbp[8] = 0.5
    ubp[8] = 100
    lbp[9] = 1
    ubp[9] = 5
    lbp[10] = 1
    ubp[10] = 300
    lbp[11] = 4000
    ubp[11] = 4400
    lbp[12] = 0.90
    ubp[12] = 1
    lbp[13] = 50
    ubp[13] = 100
    lbp[14] = 1E-8
    ubp[14] = 1
    lbp[15] = 1E-8
    ubp[15] = 1
    
    # correction for wrong map (Qtot maps to Pvent..):
    data["Pvent"] -= data["Prad"]
    
    data["Prad"] = data["Prad"].shift(-1) 
    #data["Ptot"] = data["Ptot"].shift(-1) 
    data["Pvent"] = data["Pvent"].shift(-1) 
    data["dh_pump"] = data["dh_pump"].shift(-1) 
    data["oveValCoi"] = data["oveValCoi"].shift(-1) 
    data["rad_val"] = data["rad_val"].shift(-1) 
    data["rad_flo"] = data["rad_flo"].shift(-1) 
    data["Tsup"] = data["Tsup"].shift(-1) 
    data["Tret"] = data["Tret"].shift(-1) 
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
    data["ahu_reaTHeaRec"] = data["ahu_reaTHeaRec"].shift(-1) 
    data["Ta"] = data["Ta"].shift(-1) 
    data["phi_s"] = data["phi_s"].shift(-1) 
    data["ahu_reaFloSupAir"] = data["ahu_reaFloSupAir"].shift(-1)
    y_data = data[:-1]
    # TODO: need to modularize this:
    y_data["y1"] = y_data["Prad"]
    y_data["y2"] = y_data["Pvent"]
    y_data["y3"] = y_data["ahu_reaTHeaRec"]
    y_data["y4"] = y_data["ahu_reaFloSupAir"]
    y_data["y5"] = y_data["ahu_reaTRetAir"]
    y_data["y6"] = y_data["rad_flo"]
    
    dt = y_data.index[1] - y_data.index[0]
    
    """
    Plot radiator energy
    """
    flow = data[["rad_val", "Prad", "ahu_pump_sup"]]
    flow = flow.sort_values(ascending=True, by="rad_val")
    flow.index = range(len(flow.index))
    ax = flow.rad_val.plot(color="k")
    ax1 = ax.twinx()
    flow.Prad.plot(ax=ax1, color="r", linestyle="dashed")
    flow.ahu_pump_sup.plot(ax=ax, color="b")
    plt.show()
    
    """
    Test equalPercentage
    """
    equalPercentage = functions["equalPercentage"]
    R = 50
    l = 0.05
    delta = 0.05
    
    test = equalPercentage(0.5, R, l, delta)
    print(test)
    
    # test over x \in [0, ..., 10]
    xs = np.arange(0,1,step=0.01)
    #xs = np.append(xs, np.arange(1,10,step=1))
    y = np.array([])
    for x in xs:
        y = np.append(y, equalPercentage(1-x, R, l, delta))
        #y = np.append(y, equalPercentage(x, R, l, delta))
    y = 1 - y
    plt.plot(xs, y)  
    plt.show()
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess) as param_est:
                             #as param_est:
        Q = ca.DM.eye(0)
        R = ca.DM.eye(6)
        R[0,0] = 1E-9
        R[1,1] = 1E-10
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
        
        ax = sol["Pvent"].plot(color="r")
        sol["y2"].plot(color="k", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    

        ax = sol["ahu_reaTHeaRec"].plot(color="r")
        sol["y3"].plot(color="k", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax.legend()
        ax1 = ax.twinx()
        sol["y4"].plot(color="b", ax=ax1)
        plt.show()    

        ax = sol["ahu_reaTRetAir"].plot(color="r")
        sol["y5"].plot(color="k", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    

        ax = sol["Prad"].plot(color="r")
        sol["y1"].plot(color="k", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    
        
        ax = sol["rad_flo"].plot(color="r")
        sol["y6"].plot(color="k", linestyle="dashed", ax=ax)
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