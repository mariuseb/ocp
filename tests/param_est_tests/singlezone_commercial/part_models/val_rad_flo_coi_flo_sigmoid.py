#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
from ocp.mhe import MHE
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
import torch
from ocp.functions import functions
from ocp.nn import ParamDataset, NN, Trainer, get_train_config
from ocp.boptest_api import Boptest
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates
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
                            "data_bestest_hydronic_normal_op_rad_coi.csv"
                            )    
    N = 168*4
    k = 0
    
    if GENERATE_DATA_NORMAL_OP:
        
        for n in range(N):
            # no radiator:
            """
            Turn off radiator, see how ventilation responds
            #u_0 = pd.Series(index=['rad_val'], data=[0])
            """
            u_0 = pd.Series(
                            index=['ahu_pump_sup','ahu_pump_ret'], 
                            data=[0.03,0.03]
                            )
            #u_0.loc["rad_val"] = 0.01*k 
            #k += 1
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
        flow = res[["ahu_reaFloSupAir", "ahu_pump_sup"]]
        flow = flow.sort_values(ascending=True, by="ahu_pump_sup")
        flow.index = range(len(flow.index))
        ax = flow.ahu_pump_sup.plot(color="k")
        ax1 = ax.twinx()
        flow.ahu_reaFloSupAir.plot(ax=ax1,101 color="r", linestyle="dashed")
        plt.show()
        """
      
      
    else:
        data = pd.read_csv(data_path, index_col=0)   
    
    data.index = range(len(data.index))
    #data = data[96*2:-3]
    data = data[:-1]
    data = data.dropna(axis=0)
        
    #r_names = ["Ta", "phi_s"]
    data["rad_val"] = data["rad_val"].shift(-1) 
    data["rad_flo"] = data["rad_flo"].shift(-1) 
    data["coi_val"] = data["coi_val"].shift(-1) 
    data["coi_flo"] = data["coi_flo"].shift(-1) 
    data["y6"] = data["rad_flo"]
    data["y7"] = data["coi_flo"]
    data["y8"] = data["coi_flo"] + data["rad_flo"]
    
    fig, axes = plt.subplots(3,1, sharex=True)
    data["rad_val"].plot(ax=axes[0], color="r")
    ax1 = axes[0].twinx()
    data["rad_flo"].plot(ax=ax1, color="k")
    axes[0].legend(loc="upper left")
    ax1.legend(loc="upper right")
    data["coi_val"].plot(ax=axes[1], color="r")
    ax1 = axes[1].twinx()
    data["coi_flo"].plot(ax=ax1, color="k")
    axes[1].legend(loc="upper left")
    ax1.legend(loc="upper right")
    ax = axes[2]
    data.y8.plot(ax=ax)
    plt.show()

    dt = boptest.h
    data.index = range(0,(N-1)*dt,dt)
    data = data.loc[[ndx for ndx in data.index if ndx % 900 == 0]]
    N = len(data)
    dt = (data.index[1] - data.index[0])
    # set range index for identification:

    param_guess = np.array([
                    7,
                    0.05])

    param_guess = np.array([
                            1,
                            1,
                            8,
                            2,
                            6
                            ])
    
    lbp = 1E-2*param_guess
    ubp = 1E2*param_guess
    lbp[0] = 1
    ubp[0] = 2
    lbp[1] = 1
    ubp[1] = 2
    lbp[2] = 7
    ubp[2] = 10
    lbp[3] = 0.4
    ubp[3] = 3
    lbp[4] = 2
    ubp[4] = 8
    len_p = param_guess.shape[0]
    
    cfg_path = os.path.join("configs", "double_valve_power_curves.json")
    
    """
    Train-test split:
    M = 672*1
    y_scale = data[["rad_flo","coi_flo"]].max().values
    train = data[:M]
    test = data[M:(N-2)]
    N = M
    """
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess) as param_est:
                             #as param_est:
        Q = ca.DM.eye(0)
        R = ca.DM.eye(3)
        #R[0,0] = 1E-9
        #R[1,1] = 1E-10
        #param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      #train,
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
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
    
    
