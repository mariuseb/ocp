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
from ocp.nn import ParamDataset, NN, LSTMModel, Trainer, get_train_config
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
    data["n_occ"] = data["phi_int"]
    #data = data.dropna(axis=0)

    timeseries = data[["n_occ"]].values.astype('float32')
    
    # train-test split for time series
    #train_size = int(len(timeseries) * 0.67)
    M = train_size = 24*28
    test_size = len(timeseries) - train_size
    train, test = timeseries[:train_size], timeseries[train_size:]
    
    def create_dataset(dataset, lookback):
        """Transform a time series into a prediction dataset
        
        Args:
            dataset: A numpy array of time series, first dimension is the time steps
            lookback: Size of window for prediction
        """
        X, y = [], []
        for i in range(len(dataset)-lookback):
            feature = dataset[i:i+lookback]
            target = dataset[i+1:i+lookback+1]
            X.append(feature)
            y.append(target)
        return torch.tensor(X), torch.tensor(y)
    
    lookback = 24
    X_train, y_train = create_dataset(train, lookback=lookback)
    X_test, y_test = create_dataset(test, lookback=lookback)
    

    #y_nn_scl = y_nn/y_scale
    #y_nn_scl = y_nn
    
    #x, y = torch.tensor(x_nn_scl.values), torch.tensor(y_nn_scl.values)
    """
    y = torch.tensor(y_nn_scl.values)
    lookback = 24
    tensor_list = []
    for n in range(lookback, M-lookback):
        input = y[n-lookback:n].T
        tensor_list.append(input)
    x = torch.cat(tensor_list)
    x = x.unsqueeze(0)
    y = y[lookback:-lookback]
    y = y.unsqueeze(0)
    x = x.to(torch.float32)
    y = y.to(torch.float32)
    """
    
    # init custom dataset and train:
    y_scale = 1
    split = "train"
    train_dataset = ParamDataset(split, X_train, y_train)
    #model = NN(x_nn.shape[1], y_nn.shape[1], x_scale=float(x_nn_max.iloc[0]))
    #max_mass_flow = data.coi_flo.max()
    model = LSTMModel(
               24, # input size
               50, # hidden size
               1, # output size
               num_layers=1
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
    tensor_list = []
    len_x = x.shape[1]
    for n in range(len_x):
        output = model(x[n])
        tensor_list.append(output)
    model_y = torch.cat(tensor_list)
    """
    model_y = model(X_train)
    
    y_hat_df = pd.DataFrame(
                            data=model_y.detach().numpy().squeeze(),
                            columns=["n_occ"]
                            )
    y_hat_df *= y_scale
    y_hat_df[["n_occ_true"]] = y_train.detach().numpy().squeeze()
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
    
    
    
