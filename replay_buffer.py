import random
import numpy as np
from collections import deque

"""
A general buffer that stores
everything needed for both
value-based and policy gradient methods.
"""

class BasicBuffer:
    """
    Simple buffer class to store all experiences

    ...

    Attributes
    ----------
    buffer : list of tuples
        Experiences stored as a list of tuples
    """

    def __init__(self):
        self.buffer = []

    def push(
             self, 
             state,
             action,
             R,
             next_state,
             V_next,
             Q_curr,
             dQdP,
             dPidP,
             action_mean,
             next_action=None
            ):
        experience = (
             state,
             action,
             R,
             next_state,
             V_next,
             Q_curr,
             dQdP,
             dPidP,
             action_mean,
             next_action
        )
        self.buffer.append(experience)

    def sample(self):
        transition = random.sample(self.buffer, 1)
        state, action, R, next_state, V_next, Q_curr, dQdP, dPidP, action_mean, next_action = transition
        return state, action, R, next_state, V_next, Q_curr, dQdP, dPidP, action_mean, next_action


class ReplayBuffer:
    """
    Replay buffer class, enabling random batch sampling

    ...

    Attributes
    ----------
    buffer : deque object
        Experiences stored as a list of rollouts
        Each rollout has its own list of experiences

    size : int
        Current size of the buffer

    max_size : int
        Maximum size of the replay buffer

    """

    def __init__(self, max_size, seed):
        self.max_size = max_size
        self.buffer = deque(maxlen=max_size)
        self.size_list = deque(maxlen=max_size)
        self.size = 0
        random.seed(seed)

    def __len__(self):
        return len(self.buffer)

    def push(self, rollout):
        """
        Add rollout to replay buffer

        Parameters
        ----------
        rollout :
            Data from a full rollout

        """
        self.size_list.append(len(rollout))
        self.size = sum(self.size_list)
        self.buffer.append(rollout)

    def sample(self, batch_size):
        """
        Sample batch_size number of experiences from all the available ones

        Parameters
        ----------
        batch_size : int
            Number of experiences required to be sampled

        Returns
        -------
        list of tuples, each a randomly sampled experience

        """
    
        state_batch = []
        action_batch = []
        R_batch = []
        next_state_batch = []
        V_next_batch = []
        Q_curr_batch = []
        dQdP_batch = []
        dPidP_batch = []
        action_mean_batch = []
        next_action_batch = []

        for _ in range(batch_size):
            rollout = random.sample(self.buffer, 1)[0]
            (
                state,
                action,
                R,
                next_state,
                V_next,
                Q_curr,
                dQdP,
                dPidP,
                action_mean,
                next_action
            ) = random.sample(rollout, 1)[0]
            state_batch.append(state)
            action_batch.append(action)
            R_batch.append(R)
            next_state_batch.append(next_state)
            V_next_batch.append(V_next)
            Q_curr_batch.append(Q_curr)
            dQdP_batch.append(dQdP)
            dPidP_batch.append(dPidP)
            action_mean_batch.append(action_mean)
            next_action_batch.append(next_action)
        return (
                state_batch,
                action_batch,
                R_batch,
                next_state_batch,
                V_next_batch,
                Q_curr_batch,
                dQdP_batch,
                dPidP_batch,
                action_mean_batch,
                next_action_batch
        )

    def flatten_buffer(self):
        state_batch = []
        action_batch = []
        R_batch = []
        next_state_batch = []
        V_next_batch = []
        action_batch = []
        Q_curr_batch = []
        dQdP_batch = []
        dPidP_batch = []
        action_mean_batch = []
        next_action_batch = []

        for i in range(len(self.buffer)):
            for j in range(len(self.buffer[i])):
                (
                state,
                action,
                R,
                next_state,
                V_next,
                Q_curr,
                dQdP,
                dPidP,
                action_mean,
                next_action
                ) = self.buffer[i][j]
                state_batch.append(state)
                action_batch.append(action)
                R_batch.append(R)
                next_state_batch.append(next_state)
                V_next_batch.append(V_next)
                Q_curr_batch.append(Q_curr)
                dQdP_batch.append(dQdP)
                dPidP_batch.append(dPidP)
                action_mean_batch.append(action_mean)
                next_action_batch.append(next_action)
        return (
            state_batch,
            action_batch,
            R_batch,
            next_state_batch,
            V_next_batch,
            Q_curr_batch,
            dQdP_batch,
            dPidP_batch,
            action_mean_batch,
            next_action_batch
        )

