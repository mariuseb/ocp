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
                            "data_bestest_hydronic_normal_op.csv"
                            )    
    N = 672*8

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
        
    #r_names = ["Ta", "phi_s"]
    data["rad_val"] = data["rad_val"].shift(-1) 
    data["rad_flo"] = data["rad_flo"].shift(-1) 
    
    """
    Split:
    """
    M = 672*4
    train = data[:M]
    test = data[M:(N-2)]
    
    x_nn = train[["rad_val"]] #[:-M+1]
    #x_scale = (x_nn.max()-x_nn.min())
    x_scale = 1
    y_nn = train[["rad_flo"]] #[:-M+1]
    #y_scale = y_nn.max().values[0]
    y_scale = 1
    
    x_nn_scl = x_nn/x_scale
    x_nn_min = x_nn.min()
    x_nn_max = x_nn.max()
    x_nn_scl = (x_nn - x_nn_min)/(x_nn_max - x_nn_min)
    #x_nn_scl = x_nn
    #y_nn_scl = y_nn/y_scale
    y_nn_scl = y_nn
    
    x, y = torch.tensor(x_nn_scl.values), torch.tensor(y_nn_scl.values)
    
    # init custom dataset and train:
    split = "train"
    train_dataset = ParamDataset(split, x, y)
    model = NN(x_nn.shape[1], y_nn.shape[1], x_scale=float(x_nn_max.iloc[0]))
    train_config = get_train_config()
    trainer = Trainer(train_config, model, train_dataset)
    trainer.run()

    """
    Training fit:
    """
    
    model_y = model(x)
    
    y_hat_df = pd.DataFrame(
                            data=model_y.detach().numpy(),
                            columns=["rad_flo"]
                            )
    y_hat_df["true"] = y.detach().numpy()
    y_hat_df *= y_scale
    y_hat_df[["rad_flo", "true"]].plot()
    plt.show()

    """
    Validation fit:
    """
    
    x_nn = test[["rad_val"]] #[:-M+1]
    #x_scale = (x_nn.max()-x_nn.min())
    y_nn = test[["rad_flo"]] #[:-M+1]
    #y_scale = y_nn.max().values[0]
    
    #x_nn_scl = x_nn/x_scale
    #x_nn_min = x_nn.min()
    #x_nn_max = x_nn.max()
    x_nn_scl = (x_nn - x_nn_min)/(x_nn_max - x_nn_min)
    #x_nn_scl = x_nn
    y_nn_scl = y_nn/y_scale
    
    x, y = torch.tensor(x_nn_scl.values), torch.tensor(y_nn_scl.values)
    
    model_y = model(x)
    
    y_hat_df = pd.DataFrame(
                            data=model_y.detach().numpy(),
                            columns=["rad_flo"]
                            )
    y_hat_df["true"] = y.detach().numpy()
    y_hat_df *= y_scale
    y_hat_df[["rad_flo", "true"]].plot()
    plt.show()
    print(model)
    
    torch.save(model, "val_flo_map.pth")
    
    
    
