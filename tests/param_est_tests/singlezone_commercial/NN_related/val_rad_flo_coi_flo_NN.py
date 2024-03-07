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
from ocp.double_nn import ParamDataset, NN, Trainer, get_train_config
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
    N = 672*8

    if GENERATE_DATA_NORMAL_OP:
        
        for n in range(N):
            # no radiator:
            """
            Turn off radiator, see how ventilation responds
            #u_0 = pd.Series(index=['rad_val'], data=[0])
            u_0 = pd.Series(
                            index=['ahu_pump_sup','ahu_pump_ret'], 
                            data=[0.03,0.03]
                            )
            """
                    
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
        flow.ahu_reaFloSupAir.plot(ax=ax1, color="r", linestyle="dashed")
        plt.show()
        """
        
        
    else:
        data = pd.read_csv(data_path, index_col=0)   
        
    #r_names = ["Ta", "phi_s"]
    data["rad_val"] = data["rad_val"].shift(-1) 
    data["rad_flo"] = data["rad_flo"].shift(-1) 
    data["coi_val"] = data["coi_val"].shift(-1) 
    data["coi_flo"] = data["coi_flo"].shift(-1) 
    
    fig, axes = plt.subplots(2,1, sharex=True)
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
    plt.show()
    
    
    
    """
    Split:
    """
    M = 672*4
    #y_scale = data[["coi_flo"]].max().max()
    data = data[672:len(data)-2]
    #y_scale = data[["rad_flo","coi_flo"]].max().values
    y_scale = data[["rad_flo","coi_flo"]].max().max()
    #train = data[:M]
    #test = data[M:(N-2)]
    train = data.sample(M).sort_index()
    test_index = [ndx for ndx in data.index if ndx not in train.index]
    test = data.loc[test_index]
    
    x_nn = train[["rad_val","coi_val"]] #[:-M+1]
    #x_scale = (x_nn.max()-x_nn.min())
    #x_scale = 1
    y_nn = train[["rad_flo","coi_flo"]] #[:-M+1]
    #y_scale = 1
    #y_scale = y_nn.max().max()
    #y_scale = y_nn.max()
    
    #x_nn_scl = x_nn/x_scale
    x_nn_min = x_nn.min() #.min()
    x_nn_max = x_nn.max() #.max()
    x_nn_scl = x_nn
    #x_nn_scl = (x_nn - x_nn_min)/(x_nn_max - x_nn_min)
    y_nn_scl = y_nn/y_scale
    #y_nn_scl = y_nn
    
    x, y = torch.tensor(x_nn_scl.values), torch.tensor(y_nn_scl.values)
    
    # init custom dataset and train:
    split = "train"
    train_dataset = ParamDataset(split, x, y)
    #model = NN(x_nn.shape[1], y_nn.shape[1], x_scale=float(x_nn_max.iloc[0]))
    #max_mass_flow = data.coi_flo.max()
    
    """
    Two networks:
    """
    
    rad_model = NN(
               x_nn.shape[1],
               1, 
               x_scale=x_nn_max.values,
               y_scale=data["rad_flo"].max(),
               max_flow=1
               )
    coi_model = NN(
               x_nn.shape[1],
               1, 
               x_scale=x_nn_max.values,
               y_scale=data["coi_flo"].max(),
               max_flow=1
               )
    train_config = get_train_config()
    trainer = Trainer(train_config, rad_model, coi_model, train_dataset)
    trainer.run()

    """
    Training fit:
    """
    
    rad_model_y = rad_model(x)
    coi_model_y = coi_model(x)
    
    data = np.array([
                     rad_model_y.detach().numpy().flatten(), 
                     coi_model_y.detach().numpy().flatten()
                     ])
    y_hat_df = pd.DataFrame(
                            data=data.T,
                            columns=["rad_flo","coi_flo"]
                            )
    y_hat_df *= y_scale
    y_hat_df[["rad_flo_true", "coi_flo_true"]] = y.detach().numpy()
    y_hat_df[["rad_flo_true", "coi_flo_true"]] *= y_scale
    
    fig, ax = plt.subplots(2,1, sharex=True)
    y_hat_df[["rad_flo", "rad_flo_true"]].plot(ax=ax[0])
    ax[0].legend()
    y_hat_df[["coi_flo", "coi_flo_true"]].plot(ax=ax[1])
    ax[1].legend()
    plt.show()

    """
    Validation fit:
    """
    
    x_nn = test[["rad_val","coi_val"]] #[:-M+1]
    #x_scale = (x_nn.max()-x_nn.min())
    y_nn = test[["rad_flo","coi_flo"]] #[:-M+1]
    #y_scale = y_nn.max().values[0]
    
    #x_nn_scl = x_nn/x_scale
    x_nn_min = x_nn.min()
    x_nn_max = x_nn.max()
    x_nn_scl = (x_nn - x_nn_min)/(x_nn_max - x_nn_min)
    #x_nn_scl = x_nn
    y_nn_scl = y_nn/y_scale
    
    x, y = torch.tensor(x_nn_scl.values), torch.tensor(y_nn_scl.values)
    
    rad_model_y = rad_model(x)
    coi_model_y = coi_model(x)
    
    data = np.array([
                     rad_model_y.detach().numpy().flatten(), 
                     coi_model_y.detach().numpy().flatten()
                     ])
    y_hat_df = pd.DataFrame(
                            data=data.T,
                            columns=["rad_flo","coi_flo"]
                            )
    y_hat_df *= y_scale
    y_hat_df[["rad_flo_true", "coi_flo_true"]] = y.detach().numpy()
    y_hat_df[["rad_flo_true", "coi_flo_true"]] *= y_scale
    
    fig, ax = plt.subplots(2,1, sharex=True)
    y_hat_df[["rad_flo", "rad_flo_true"]].plot(ax=ax[0])
    ax[0].legend()
    y_hat_df[["coi_flo", "coi_flo_true"]].plot(ax=ax[1])
    ax[1].legend()
    plt.show()
    
    torch.save(rad_model, "rad_flo_map.pth")
    torch.save(coi_model, "coi_flo_map.pth")
    
    
    
