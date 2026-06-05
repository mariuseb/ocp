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
from ocp.boptest_api_old import Boptest
import random
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path

if __name__ == "__main__":


    data_path = "twin_rooms_emulator_normal_op_60min.csv"
    data = pd.read_csv(data_path, index_col=0)   
    data.index = pd.to_datetime(
        (pd.to_timedelta(data.index).astype(np.int64) + (86400*11)*1e9)
    )
    data = data.bfill()
    data["dt_index"] = data.index
    data["t_in_week"] = data["dt_index"].apply(lambda x: x.dayofweek*24 + x.hour)
    data.index = range(len(data.index))
    #data = data.dropna(axis=0)

    data["phi_int"].plot(drawstyle="steps-post", color="k")
    data["n_occ"] = data["phi_int"]
    plt.show()
    """
    Split after ~7 days:
    """
    M = 24*28
    y_scale = data[["n_occ"]].max().values
    train = data[:M]
    test = data[M:]
    
    x_nn = train[["t_in_week"]] #[:-M+1]
    #x_scale = (x_nn.max()-x_nn.min())
    #x_scale = 1
    y_nn = train[["n_occ"]] #[:-M+1]
    #y_scale = 1
    #y_scale = y_nn.max().max()
    y_scale = y_nn.max().max()
    #y_scale = 1
    
    #x_nn_scl = x_nn/x_scale
    x_nn_min = x_nn.min().min()
    x_nn_max = x_nn.max().max()
    #x_nn_scl = x_nn
    x_nn_scl = (x_nn - x_nn_min)/(x_nn_max - x_nn_min)
    y_nn_scl = y_nn/y_scale
    #y_nn_scl = y_nn
    
    x, y = torch.tensor(x_nn_scl.values), torch.tensor(y_nn_scl.values)
    
    # init custom dataset and train:
    split = "train"
    train_dataset = ParamDataset(split, x, y)
    #model = NN(x_nn.shape[1], y_nn.shape[1], x_scale=float(x_nn_max.iloc[0]))
    #max_mass_flow = data.coi_flo.max()
    model = NN(
               x_nn.shape[1],
               y_nn.shape[1],
               x_scale=1,
               y_scale=y_scale,
               hidden_dim=50
               )
    train_config = get_train_config()
    trainer = Trainer(train_config, model, train_dataset)
    # set seed:
    #random.seed(0)
    #np.random.seed(0)
    #torch.manual_seed(0)
    #torch.use_deterministic_algorithms(True)
    trainer.run()

    """
    Training fit:
    """
    
    model_y = model(x)
    
    y_hat_df = pd.DataFrame(
                            data=model_y.detach().numpy(),
                            columns=["n_occ"]
                            )
    y_hat_df *= y_scale
    y_hat_df[["n_occ_true"]] = y.detach().numpy()
    y_hat_df[["n_occ_true"]] *= y_scale
    
    fig, ax = plt.subplots(2,1, sharex=True)
    y_hat_df[["n_occ", "n_occ_true"]].plot(ax=ax[0])
    ax[0].legend()
    plt.show()

    """
    Validation fit:
    """
    
    x_nn = test[["t_in_week"]] #[:-M+1]
    y_nn = test[["n_occ"]] #[:-M+1]
    x_nn_scl = (x_nn - x_nn_min)/(x_nn_max - x_nn_min)
    #x_nn_scl = x_nn
    y_nn_scl = y_nn/y_scale
    
    x, y = torch.tensor(x_nn_scl.values), torch.tensor(y_nn_scl.values)
    
    model_y = model(x)
    
    y_hat_df = pd.DataFrame(
                            data=model_y.detach().numpy(),
                            columns=["n_occ"]
                            )
    y_hat_df *= y_scale
    y_hat_df[["n_occ_true"]] = y.detach().numpy()
    y_hat_df[["n_occ_true"]] *= y_scale
    
    fig, ax = plt.subplots(2,1, sharex=True)
    y_hat_df[["n_occ", "n_occ_true"]].plot(ax=ax[0])
    ax[0].legend()
    plt.show()
    print(model)
    
    torch.save(model, "rad_coi_flo_map_new.pth")
    
    
    
