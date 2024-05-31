from ocp.nn_function_approximator import QNetwork, copy_net_param, update_net_param
import numpy as np
import torch
from ocp.replay_buffer import ReplayBuffer
import torch.nn.functional as F
import torch.optim as optim
torch.set_default_dtype(torch.float64)

class TD3_learning:
    def __init__(self, ocp, agent_params, seed):
        # hyperparameters
        self.ocp = ocp
        self._parse_agent_params(**agent_params)
        self.update_step = 0
        self.delay_step = 2
        self.rng = np.random.default_rng(seed)
        torch.manual_seed(seed)

        # initialize q networks
        self.q_net1 = QNetwork(self.ocp.obs_dim, self.ocp.action_dim)
        self.q_net2 = QNetwork(self.ocp.obs_dim, self.ocp.action_dim)
        self.target_q_net1 = QNetwork(self.ocp.obs_dim, self.ocp.action_dim)
        self.target_q_net2 = QNetwork(self.ocp.obs_dim, self.ocp.action_dim)

        # copy params to target param
        copy_net_param(self.target_q_net1, self.q_net1)
        copy_net_param(self.target_q_net2, self.q_net2)

        # initialize optimizers
        self.q1_optimizer = optim.Adam(self.q_net1.parameters(), lr=self.critic_lr)
        self.q2_optimizer = optim.Adam(self.q_net2.parameters(), lr=self.critic_lr)

    def get_action_batch(self, state_list, infos=None, act_wt=None, mode="update"):
        act_list = []
        for j, state in enumerate(state_list):
            soln = infos[j]["soln"] if infos is not None else None
            act, _ = self.ocp.act_forward(state, soln=soln, p_val=act_wt, mode=mode)
            act_list.append(act)
        return act_list

    def train(self, replay_buffer: ReplayBuffer):
        batch_size = min(self.batch_size, replay_buffer.size)
        train_it = min(self.iterations, int(5.0 * replay_buffer.size / batch_size))

        for _ in range(train_it):
            (
                states,
                actions,
                Rs,
                next_states,
                V_nexts,
                Q_currs,
                dQdPs,
                dPidPs,
                action_means,
                next_actions
            ) = replay_buffer.sample(batch_size)
            obss = torch.tensor(np.array(states), dtype=torch.float64)
            actions = torch.tensor(np.array(actions), dtype=torch.float64)
            rewards = torch.tensor(np.array(Rs), dtype=torch.float64)
            next_obss = torch.tensor(np.array(next_states), dtype=torch.float64)

            # q loss
           # next_actions = self.get_action_batch(next_obss, infos=infos)
            next_actions = torch.tensor(np.array(next_actions), dtype=torch.float64)
            next_q1 = self.target_q_net1(next_obss, next_actions)
            next_q2 = self.target_q_net2(next_obss, next_actions)
            expected_q = rewards + self.ocp.gamma * torch.max(
                next_q1, next_q2
            )
            curr_q1 = self.q_net1.forward(obss, actions)
            curr_q2 = self.q_net2.forward(obss, actions)
            q1_loss = F.mse_loss(curr_q1, expected_q.detach())
            q2_loss = F.mse_loss(curr_q2, expected_q.detach())

            # update q networks
            self.q1_optimizer.zero_grad()
            q1_loss.backward()
            self.q1_optimizer.step()

            self.q2_optimizer.zero_grad()
            q2_loss.backward()
            self.q2_optimizer.step()

            # delayed update for actor and target q networks
            if self.update_step % self.delay_step == 0:
                dJ = 0.0
                for j, obs in enumerate(obss):
                    """
                    new_action, info = self.ocp.act_forward(
                        obs, soln=infos[j]["soln"], mode="update"
                    )
                    soln, pf_val, p_val = info["soln"], info["pf"], info["p"]
                    dPidP = self.ocp.dPidP(soln, pf_val, p_val)
                    """
                    dPidP = dPidPs[j]
                    new_action = actions[j]
                    new_action += self.rng.normal(scale=0, size=(self.ocp.action_dim)).clip(-0.2,0.2)
                    
                    """
                    new_action = new_action.clip(
                        self.ocp.model.action_space.low,
                        self.ocp.model.action_space.high
                    )
                    """
                
                    new_action = torch.tensor(new_action[None, :], dtype=torch.float64)
                    new_action.requires_grad_()
                    temp_q1 = self.q_net1.forward(obs[None, :], new_action)
                    temp_q1.backward()
                    grad_na = new_action.grad.numpy()
                    dJ += np.matmul(dPidP.T, grad_na.T)

                # Param update
                self.ocp.param_update(
                    dJ / batch_size,
                    constrained_updates=self.constrained_updates,
                )

                # target networks
                update_net_param(self.target_q_net1, self.q_net1, self.tau)
                update_net_param(self.target_q_net2, self.q_net2, self.tau)
            self.update_step += 1
        return {"l_theta": self.ocp.p_val}

    def _parse_agent_params(
        self,
        load_pretrained_net,
        tau,
        critic_lr,
        lr,
        tr,
        train_params,
        constrained_updates=False,
    ):
        self.load_pretrained_net = load_pretrained_net
        self.tau = tau
        self.critic_lr = critic_lr
        self.lr = lr
        self.tr = tr
        self.iterations = train_params["iterations"]
        self.batch_size = train_params["batch_size"]
        self.constrained_updates = constrained_updates
