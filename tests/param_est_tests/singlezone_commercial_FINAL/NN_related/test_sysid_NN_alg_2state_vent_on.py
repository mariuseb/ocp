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
    #y_data = data[:-1]
    y_data = data[:N]
    # TODO: need to modularize this:
    y_data["y1"] = y_data["Prad"]
    y_data["y2"] = y_data["Pvent"]
    y_data["y3"] = y_data["ahu_reaTHeaRec"]
    y_data["y4"] = y_data["ahu_reaFloSupAir"]
    y_data["y5"] = y_data["ahu_reaTRetAir"]
    y_data["y6"] = y_data["rad_flo"]
    y_data["y7"] = y_data["coi_flo"]
    
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
    Load pytorch model:
    """
    valve_model = NN(2,2)
    valve_model = torch.load("rad_coi_flo_map_new.pth")
    
    """
    Test torch model first:
    """
    x_nn = data[["rad_val", "coi_val"]] #[:-M+1]
    y_nn = data[["rad_flo", "coi_flo"]] #[:-M+1]
    #y_scale = y_nn.max().values[0]
    
    #x_nn_scl = x_nn/x_scale
    #x_nn_min = x_nn.min()
    #x_nn_max = x_nn.max()
    
    x, y = torch.tensor(x_nn.values), torch.tensor(y_nn.values)
    NN_x_scale = valve_model.x_scale
    NN_y_scale = valve_model.y_scale
    
    model_y = (valve_model(x/NN_x_scale).detach().numpy())*NN_y_scale
    y_hat_df = pd.DataFrame(
                            data=model_y,
                            columns=["rad_flo", "coi_flo"]
                            )
    y_hat_df[["rad_flo_true", "coi_flo_true"]] = y.detach().numpy()
    #y_hat_df *= y_scale
    y_hat_df[["rad_flo", "rad_flo_true"]].plot()
    plt.show()
    
    l4c_model = l4c.L4CasADi(valve_model, model_expects_batch_dim=False)
    
    x_sym = ca.MX.sym('x', 1, 2)
    rad_val_sym = ca.MX.sym('rad_val')
    coi_val_sym = ca.MX.sym('coi_val')
    
    y_sym = l4c_model(x_sym/ca.DM(NN_x_scale).T)
    f = ca.Function('y', [x_sym], [y_sym], ["rad_val"], ["rad_flo"])
    
    # add NN to functions:
    functions["NN"] = f
    
    # test function object:
    x = y_data[["rad_val", "coi_val"]].values
    y = np.array([])
    for n in range(N):
        y = np.append(y, f(x[n]))
    y_data[["rad_flo_ca", "coi_flo_ca"]] = y.reshape((N,2))*NN_y_scale
    y_data[["rad_flo_ca", "rad_flo", "y6"]].plot()
    y_data[["coi_flo_ca", "coi_flo", "y7"]].plot()
    plt.show()

    kwargs = {
        #"u_nom": [300,300,1/0.3283045346159116],
        "u_nom": [1,1,1,1,1,1,1],
        "u_nom_b": [0,0,0,0,0,0,0]
    }
    rad_scale = valve_model.y_scale[0]
    coi_scale = valve_model.y_scale[1]
    cfg_path = "configs/Pvent_Prad_NNs.json"
    param_guess = np.array([
                            4200,
                            0.9,
                            0.6,
                            1000,
                            rad_scale,
                            coi_scale
                          ]) 
    lbp = param_guess*0.01
    ubp = param_guess*100
    lbp[1] = 0.99
    ubp[1] = 1
    lbp[2] = 0.5
    ubp[2] = 1
    len_p = param_guess.shape[0]
    lbp[len_p-1] = coi_scale
    ubp[len_p-1] = coi_scale
    lbp[len_p-2] = rad_scale
    ubp[len_p-2] = rad_scale
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        Q = ca.DM.eye(0)
        R = ca.DM.eye(4)
        #R[0,0] = 1E-9
        R[0,0] = 1E-9
        R[1,1] = 1E-9
        #param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R),
                                      codegen=False
                                      )       

        ax = sol["Prad"].plot(color="r")
        sol["y1"].plot(color="k", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    

        ax = sol["Pvent"].plot(color="r")
        sol["y2"].plot(color="k", linestyle="dashed", ax=ax)
        #ax.set_ylim([290,310])
        ax.legend()
        plt.show()    
    
        print(params)
        
    """
    Plot sorted:
    """