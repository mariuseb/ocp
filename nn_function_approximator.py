import torch
import torch.nn as nn
import torch.nn.functional as F

def copy_net_param(net1, net2):
    # set net1 params equal to net2
    for target_param, param in zip(net1.parameters(), net2.parameters()):
        target_param.data.copy_(param.data)


def update_net_param(net1, net2, tau):
    # set net1 params equal to net2
    for target_param, param in zip(net1.parameters(), net2.parameters()):
        target_param.data.copy_(tau * param + (1 - tau) * target_param)

class QNetwork(nn.Module):
    def __init__(self, num_inputs, num_actions, hidden_size=64, init_w=3e-3):
        super(QNetwork, self).__init__()
        self.linear1 = nn.Linear(num_inputs + num_actions, hidden_size)
        self.linear2 = nn.Linear(hidden_size, hidden_size)
        self.linear3 = nn.Linear(hidden_size, 1)

        self.linear3.weight.data.uniform_(-init_w, init_w)
        self.linear3.bias.data.uniform_(-init_w, init_w)

    def forward(self, state, action):
        x = torch.cat([state, action], 2)
        x = F.relu(self.linear1(x))
        x = F.relu(self.linear2(x))
        x = self.linear3(x)
        return x