import random
import numpy as np
from collections import deque


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

    def push(self, state, obs, action, reward, next_state, next_obs, data, info):
        experience = (
            state,
            obs,
            action,
            np.array([reward]),
            next_state,
            next_obs,
            data,
            info,
        )
        self.buffer.append(experience)

    def sample(self):
        transition = random.sample(self.buffer, 1)
        state, obs, action, reward, next_state, next_obs, data, info = transition
        return (state, obs, action, reward, next_state, next_obs, data, info)


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
        obs_batch = []
        action_batch = []
        reward_batch = []
        next_state_batch = []
        next_obs_batch = []
        data_batch = []
        info_batch = []

        for _ in range(batch_size):
            rollout = random.sample(self.buffer, 1)[0]
            (
                state,
                obs,
                action,
                reward,
                next_state,
                next_obs,
                data,
                info,
            ) = random.sample(rollout, 1)[0]
            state_batch.append(state)
            obs_batch.append(obs)
            action_batch.append(action)
            reward_batch.append(reward)
            next_state_batch.append(next_state)
            next_obs_batch.append(next_obs)
            data_batch.append(data)
            info_batch.append(info)
        return (
            state_batch,
            obs_batch,
            action_batch,
            reward_batch,
            next_state_batch,
            next_obs_batch,
            data_batch,
            info_batch,
        )

    def flatten_buffer(self):
        state_batch = []
        obs_batch = []
        action_batch = []
        reward_batch = []
        next_state_batch = []
        next_obs_batch = []
        data_batch = []
        info_batch = []

        for i in range(len(self.buffer)):
            for j in range(len(self.buffer[i])):
                (
                    state,
                    obs,
                    action,
                    reward,
                    next_state,
                    next_obs,
                    data,
                    info,
                ) = self.buffer[i][j]
                state_batch.append(state)
                obs_batch.append(obs)
                action_batch.append(action)
                reward_batch.append(reward)
                next_state_batch.append(next_state)
                next_obs_batch.append(next_obs)
                data_batch.append(data)
                info_batch.append(info)
        return (
            state_batch,
            obs_batch,
            action_batch,
            reward_batch,
            next_state_batch,
            next_obs_batch,
            data_batch,
            info_batch,
        )

