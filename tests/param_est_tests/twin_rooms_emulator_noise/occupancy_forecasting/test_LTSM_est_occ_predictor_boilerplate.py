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
import torch.nn as nn
import torch.optim as optim
import torch.utils.data as data
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path

if __name__ == "__main__":


    data_path = "twin_rooms_emulator_normal_op_60min.csv"
    df = pd.read_csv(data_path, index_col=0)   
    df.index = pd.to_datetime(
        (pd.to_timedelta(df.index).astype(np.int64) + (86400*11)*1e9)
    )
    df = df.bfill()
    df["dt_index"] = df.index
    df["t_in_week"] = df["dt_index"].apply(lambda x: x.dayofweek*24 + x.hour)
    df.index = range(len(df.index))
    df["n_occ"] = df["phi_int"]
    #df = df.dropna(axis=0)

    timeseries = df[["n_occ"]].values.astype('float32')
    
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
            feature = dataset[i:i+lookback].T
            target = dataset[i+1:i+2] # only next element 
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
               lookback, # input size
               50, # hidden size
               1, # output size
               num_layers=1
               )
    optimizer = optim.Adam(model.parameters(), lr=1e-5)
    loss_fn = nn.MSELoss()
    loader = data.DataLoader(data.TensorDataset(X_train, y_train), shuffle=True, batch_size=64)
    
    n_epochs = 2000
    for epoch in range(n_epochs):
        model.train()
        for X_batch, y_batch in loader:
            y_pred = model(X_batch)
            loss = loss_fn(y_pred, y_batch)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()
        # Validation
        #if epoch % 100 != 0:
        #    continue
        model.eval()
        with torch.no_grad():
            y_pred = model(X_train)
            train_rmse = np.sqrt(loss_fn(y_pred, y_train))
            y_pred = model(X_test)
            test_rmse = np.sqrt(loss_fn(y_pred, y_test))
        print("Epoch %d: train RMSE %.4f, test RMSE %.4f" % (epoch, train_rmse, test_rmse))
    
    with torch.no_grad():
        # shift train predictions for plotting
        train_plot = np.ones_like(timeseries) * np.nan
        y_pred = model(X_train)
        #y_pred = y_pred[:, -1, :]
        y_pred = y_pred[:,0]
        #train_plot[lookback:train_size] = model(X_train)[:, -1, :]
        train_plot[lookback:train_size] = model(X_train)[:,0].detach().numpy() 
        # shift test predictions for plotting
        test_plot = np.ones_like(timeseries) * np.nan
        test_plot[train_size+lookback:len(timeseries)] = model(X_test)[:, -1, :]
    # plot
    plt.plot(timeseries)
    plt.plot(train_plot, c='r')
    plt.plot(test_plot, c='g')
    plt.show()
    print(model)
        
    
    
