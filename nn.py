import os
import sys
import json
import random
import math
import numpy as np
import argparse
import time
from collections import defaultdict
import gymnasium as gym
from PIL import Image
import matplotlib.pyplot as plt

import torch
import torch.optim as optim
import torch.nn as nn
from torch.nn import functional as F
from torch.utils.data import Dataset
from torch.utils.data.dataloader import DataLoader
import pandas as pd
from collections import deque
import random
import numpy as np

class ParamDataset(Dataset):
    def __init__(self, split, x, y):
        assert split in {'train', 'test'}
        assert x.shape[0] == y.shape[0]
        self.x_data = x
        self.y_data = y
    
    def __len__(self):
        return len(self.x_data)

    def __getitem__(self, idx):
        x = self.x_data[idx]
        y = self.y_data[idx]
        return x, y

class NN(nn.Module):
    """ A simple neural network."""
    def __init__(self, state_dim, action_dim, x_scale=1, y_scale=None, max_flow=1, hidden_dim=20):
        super(NN, self).__init__()
        self.x_scale = x_scale
        self.y_scale = y_scale
        self.max_flow = max_flow
        self.fc1 = nn.Linear(state_dim, hidden_dim)
        self.fc2 = nn.Linear(hidden_dim, hidden_dim)
        self.fc3 = nn.Linear(hidden_dim, action_dim)
        self.double()

    def forward(self, x):
        x = torch.as_tensor(x).double()
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        """
        Assumes normalization:
        """
        return F.relu(self.fc3(x))
    
    from collections import namedtuple
    


# Train configs
def get_train_config():
    train_config = {}
    # device to train on
    train_config['device'] = 'cpu'
    # dataloder parameters
    train_config['num_workers'] = 0
    # optimizer parameters
    #train_config['max_iters'] = 20000
    train_config['max_iters'] = 1E5
    train_config['batch_size'] = 128
    #train_config['learning_rate'] = 4e-5
    train_config['learning_rate'] = 1e-2
    train_config['betas'] = (0.9, 0.95)
    train_config['weight_decay'] = 0.1 # only applied on matmul weights
    train_config['grad_norm_clip'] = 1.0
    
    train_config = argparse.Namespace(**train_config)
    return train_config


# Trainer  
class Trainer:
    def __init__(self, config, model, train_dataset):
        self.config = config
        self.model = model
        self.optimizer = None
        self.train_dataset = train_dataset
        

        # determine the device we'll train on
        if config.device == 'auto':
            self.device = 'cuda' if torch.cuda.is_available() else 'cpu'
        else:
            self.device = config.device
        self.model = self.model.to(self.device)
        print("running on device", self.device)

        # variables that will be assigned to trainer class later for logging and etc
        self.iter_num = 0
        self.iter_time = 0.0
        self.iter_dt = 0.0
        
        # define loss
        self.criterion = torch.nn.MSELoss()
        
        # callbacks
        self.callbacks = defaultdict(list)
        # callback: print training time and loss
        def batch_end_callback(trainer):
            if trainer.iter_num % 100 == 0:
                print(f"iter_dt {trainer.iter_dt * 1000:.2f}ms; iter {trainer.iter_num}: train loss {trainer.loss.item():.8f}")
        self.callbacks['on_batch_end'] = [batch_end_callback]
        
    def trigger_callbacks(self, onevent: str):
        for callback in self.callbacks.get(onevent, []):
            callback(self)

    def run(self):
        model, config = self.model, self.config

        # setup the optimizer
        # self.optimizer = model.configure_optimizers(config) # different weight decays
        self.optimizer = torch.optim.AdamW(model.parameters(), lr=config.learning_rate, betas=config.betas) # same weight decays

        # setup the dataloader
        train_loader = DataLoader(
            self.train_dataset,
            sampler=torch.utils.data.RandomSampler(self.train_dataset, replacement=True, num_samples=int(1e10)),
            shuffle=False,
            pin_memory=True,
            batch_size=config.batch_size,
            num_workers=config.num_workers,
        )

        model.train()
        self.iter_num = 0
        self.iter_time = time.time()
        data_iter = iter(train_loader)
        #criterion = torch.nn.MSELoss()
        while True:

            # fetch the next batch (x, y) and re-init iterator if needed
            try:
                batch = next(data_iter)
            except StopIteration:
                # restart a new epoch
                data_iter = iter(train_loader)
                batch = next(data_iter)
            batch = [t.to(self.device) for t in batch]
            x, y = batch

            # forward the model
            #logits, self.loss = model(x, y)
            output = model(x)
            zero_tensor = torch.tensor([[0]]*config.batch_size, dtype=torch.float64)
            constraint = torch.dot(model(zero_tensor).flatten(), model(zero_tensor).flatten())
            self.loss = self.criterion(output, y) + constraint

            # backprop and update the parameters
            model.zero_grad(set_to_none=True)
            self.loss.backward()
            #self.loss.backward()
            torch.nn.utils.clip_grad_norm_(model.parameters(), config.grad_norm_clip)
            self.optimizer.step()

            self.trigger_callbacks('on_batch_end')
            self.iter_num += 1
            tnow = time.time()
            self.iter_dt = tnow - self.iter_time
            self.iter_time = tnow

            # termination conditions
            if config.max_iters is not None and self.iter_num >= config.max_iters:
                break

    def run(self):
        model, config = self.model, self.config

        # setup the optimizer
        # self.optimizer = model.configure_optimizers(config) # different weight decays
        self.optimizer = torch.optim.AdamW(model.parameters(), lr=config.learning_rate, betas=config.betas) # same weight decays

        # setup the dataloader
        train_loader = DataLoader(
            self.train_dataset,
            sampler=torch.utils.data.RandomSampler(self.train_dataset, replacement=True, num_samples=int(1e10)),
            shuffle=False,
            pin_memory=True,
            batch_size=config.batch_size,
            num_workers=config.num_workers,
        )

        model.train()
        self.iter_num = 0
        self.iter_time = time.time()
        data_iter = iter(train_loader)
        #criterion = torch.nn.MSELoss()
        while True:

            # fetch the next batch (x, y) and re-init iterator if needed
            try:
                batch = next(data_iter)
            except StopIteration:
                # restart a new epoch
                data_iter = iter(train_loader)
                batch = next(data_iter)
            batch = [t.to(self.device) for t in batch]
            x, y = batch

            # forward the model
            #logits, self.loss = model(x, y)
            output = model(x)
            #max_mass_flow = model.max_mass_flow
            #max_mass_flow = model.y_scale
            """
            Create the constraints:
            """
            rad_flo_max = 9.17
            coi_flo_max = 9.04
            
            rad_flo_max_reg_op = model.y_scale[0]
            coi_flo_max_reg_op = model.y_scale[1]
            
            zero_tensor = torch.tensor([[0,0]]*config.batch_size, dtype=torch.float64)
            first_one_tensor = torch.tensor([[1,0]]*config.batch_size, dtype=torch.float64)
            second_one_tensor = torch.tensor([[0,1]]*config.batch_size, dtype=torch.float64)
            both_ones_tensor = torch.tensor([[1,1]]*config.batch_size, dtype=torch.float64)
            first_35_perc_tensor = torch.tensor([[0.35,0]]*config.batch_size, dtype=torch.float64)
            first_54_perc_tensor = torch.tensor([[0.5376,0]]*config.batch_size, dtype=torch.float64)
            
            
            first_mass_flow = torch.tensor([[rad_flo_max, 0]]*config.batch_size, dtype=torch.float64)
            second_mass_flow = torch.tensor([[0, coi_flo_max]]*config.batch_size, dtype=torch.float64)
            #both_ones_mass_flow = torch.tensor([[max_mass_flow]]*config.batch_size, dtype=torch.float64)
            both_ones_mass_flow = torch.tensor([[
                                                rad_flo_max_reg_op, 
                                                coi_flo_max_reg_op]]*config.batch_size,
                                               dtype=torch.float64
                                               )
            perc_rad_mass_flow = torch.tensor([[6.85/9,0]]*config.batch_size, dtype=torch.float64)
            perc_coi_mass_flow = torch.tensor([[0,1.688/9]]*config.batch_size, dtype=torch.float64)
            
            zero_model_output = model(zero_tensor)
            _zero_model_output = zero_model_output[:,0] + \
                                        zero_model_output[:,1]
            zero_together_constraint = torch.dot(
                                        _zero_model_output.flatten(), \
                                        _zero_model_output.flatten()
                                        )
            zero_first_constraint = torch.dot(
                                        zero_model_output[:,0].flatten(), \
                                        zero_model_output[:,0].flatten()
                                        )
            zero_second_constraint = torch.dot(
                                        zero_model_output[:,1].flatten(), \
                                        zero_model_output[:,1].flatten()
                                        )
            
            first_model_output = model(first_one_tensor)
            first_residual = first_model_output - first_mass_flow
            first_constraint = torch.dot(
                                         first_residual.flatten(),
                                         first_residual.flatten()
                                         )
            
            second_model_output = model(second_one_tensor)
            second_residual = second_model_output - second_mass_flow
            second_constraint = torch.dot(
                                          second_residual.flatten(),
                                          second_residual.flatten()
                                          )
            
            both_ones_model_output = model(both_ones_tensor)
            #_both_ones_model_output = both_ones_model_output[:,0] + \
            #                            both_ones_model_output[:,1]
            both_residual = both_ones_model_output - both_ones_mass_flow
            both_ones_constraint = torch.dot(
                                             both_residual.flatten(),
                                             both_residual.flatten()
                                             )
            
            first_35_perc_model_output = model(first_35_perc_tensor)
            #_both_ones_model_output = both_ones_model_output[:,0] + \
            #                            both_ones_model_output[:,1]
            perc_rad_residual = first_35_perc_model_output - perc_rad_mass_flow
            perc_rad_constraint = torch.dot(
                                             perc_rad_residual.flatten(),
                                             perc_rad_residual.flatten()
                                             )
            
            first_54_perc_model_output = model(first_54_perc_tensor)
            #_both_ones_model_output = both_ones_model_output[:,0] + \
            #                            both_ones_model_output[:,1]
            perc_coi_residual = first_54_perc_model_output - perc_coi_mass_flow
            perc_coi_constraint = torch.dot(
                                             perc_coi_residual.flatten(),
                                             perc_coi_residual.flatten()
                                             )
            
            linear_first_residual = (x[:,0]*output[:, 0]**0.2 - y[:,0])
            linear_second_residual = (x[:,1]*output[:, 1] - y[:,1])
            linear_first = torch.dot(
                linear_first_residual, linear_first_residual
            )
            linear_second = torch.dot(
                linear_second_residual, linear_second_residual
            )**0.3
            
            """
            TODO:
                - normalize regularization objectives.
                (boundary conditions)
            """
            rad_out = output[:,0]
            coi_out = output[:,1]
            rad_max = self.model.y_scale[0]
            coi_max = self.model.y_scale[1]
            gamma = (coi_max/rad_max)
            """
            self.loss = self.criterion(rad_out, y[:,0]) + \
                self.criterion(coi_out, y[:,1]) + \
                1E-4*linear_first + \
                1E-4*zero_together_constraint + \
                1E-4*zero_first_constraint + \
                1E-4*zero_second_constraint # + \
            """
            self.loss = 5e-2*self.criterion(rad_out, y[:,0]) + \
                5e-2*self.criterion(coi_out, y[:,1]) + \
            3e-4*linear_first
                #1E-4*linear_second
            # + \              
            #self.loss = self.criterion(output, y) # + \
                        #1E-2*zero_together_constraint + \
                        #1E-2*zero_first_constraint + \
                        #1E-2*zero_second_constraint # + \
                        #1E-1*first_constraint + \
                        #1E-1*second_constraint + \
                        #1E-1*both_ones_constraint # + \
                        #1E-1*perc_rad_constraint + \
                        #1E-1*perc_coi_constraint

            # backprop and update the parameters
            model.zero_grad(set_to_none=True)
            self.loss.backward()
            #self.loss.backward()
            torch.nn.utils.clip_grad_norm_(model.parameters(), config.grad_norm_clip)
            self.optimizer.step()

            self.trigger_callbacks('on_batch_end')
            self.iter_num += 1
            tnow = time.time()
            self.iter_dt = tnow - self.iter_time
            self.iter_time = tnow

            # termination conditions
            if config.max_iters is not None and self.iter_num >= config.max_iters:
                break
            """
            try with loss tolerance 1E-3:
            """
            if self.loss < 1e-4:
            #if self.loss < 2E-2:
                break


