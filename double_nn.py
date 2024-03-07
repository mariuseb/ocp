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
    def __init__(self, config, rad_model, coi_model, train_dataset):
        self.config = config
        self.rad_model = rad_model
        self.coi_model = coi_model
        self.optimizer = None
        self.train_dataset = train_dataset
        

        # determine the device we'll train on
        if config.device == 'auto':
            self.device = 'cuda' if torch.cuda.is_available() else 'cpu'
        else:
            self.device = config.device
        self.rad_model = self.rad_model.to(self.device)
        self.coi_model = self.coi_model.to(self.device)
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
        rad_model, coi_model, config = self.rad_model, self.coi_model, self.config

        # setup the optimizer
        # self.optimizer = model.configure_optimizers(config) # different weight decays
        
        """
        optimizer = optim.Adam([
                                {'params': network1.parameters()},
                                {'params': network2.parameters(), 'lr': 1e-3}
                                ], lr=1e-4)

        # ...

        loss = loss1 + loss2
        loss.backward()
        optimizer.step()
        """
        
        self.optimizer = torch.optim.AdamW(
                                           [
                                            {'params': rad_model.parameters()},
                                            {'params': coi_model.parameters()}
                                           ],
                                           lr=config.learning_rate,
                                           betas=config.betas
                                           ) # same weight decays

        # setup the dataloader
        train_loader = DataLoader(
            self.train_dataset,
            sampler=torch.utils.data.RandomSampler(self.train_dataset, replacement=True, num_samples=int(1e10)),
            shuffle=False,
            pin_memory=True,
            batch_size=config.batch_size,
            num_workers=config.num_workers,
        )

        rad_model.train()
        coi_model.train()
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
            rad_output = rad_model(x)
            coi_output = coi_model(x)            
            
            """
            TODO:
                - normalize regularization objectives.
                (boundary conditions)
            """
            
            rad_flo_max_reg_op = rad_model.y_scale
            coi_flo_max_reg_op = coi_model.y_scale
            gamma = (coi_flo_max_reg_op/rad_flo_max_reg_op)
            
            self.loss = (gamma**2)*self.criterion(rad_output, y[:,0]) + \
                self.criterion(coi_output, y[:,1])

            # backprop and update the parameters
            rad_model.zero_grad(set_to_none=True)
            coi_model.zero_grad(set_to_none=True)
            self.loss.backward()
            #self.loss.backward()
            torch.nn.utils.clip_grad_norm_(rad_model.parameters(), config.grad_norm_clip)
            torch.nn.utils.clip_grad_norm_(coi_model.parameters(), config.grad_norm_clip)
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
            if self.loss < 1E-3:
            #if self.loss < 1E-2:
                break


