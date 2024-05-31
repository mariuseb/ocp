#from nn_function_approximator import QNetwork, copy_net_param, update_net_param
from ocp.replay_buffer import ReplayBuffer
import numpy as np
import pandas as pd


class REINFORCE:
    def __init__(self, ocp, agent_params, seed):
        # hyperparameters
        self.ocp = ocp
        self._parse_agent_params(**agent_params)
        #self.update_step = 0
        #self.delay_step = 2
        self.rng = np.random.default_rng(seed)
        
        self.grad_a_history = pd.DataFrame(columns=list(
                map(
                    lambda x: "theta" + str(x), 
                    range(self.ocp.P.shape[0])
                    )
                )
        )

    def get_action_batch(self, state_list, infos=None, act_wt=None, mode="update"):
        act_list = []
        for j, state in enumerate(state_list):
            soln = infos[j]["soln"] if infos is not None else None
            act, _ = self.ocp.act_forward(state, soln=soln, p_val=act_wt, mode=mode)
            act_list.append(act)
        return act_list

    def train(self, replay_buffer: ReplayBuffer, sigma: int):
        #batch_size = min(self.batch_size, replay_buffer.size)
        #train_it = min(self.iterations, int(5.0 * replay_buffer.size / batch_size))

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
        ) = replay_buffer.flatten_buffer()
    
        dJ = 0.0
        G = 0 # cumulative rewards
        # TODO: check if consecutive:
        for j, state in enumerate(states):   
            r = Rs[j]             
            G += r*self.ocp.gamma**j
            dPidP = dPidPs[j]
            action = actions[j]
            action_mean = action_means[j]
            action_dev = action - action_mean                
            grad_log_prob_Pi = (1/sigma)*(action_dev/self.ocp.u_nom)*(dPidP.flatten())
            # keep history:
            self.grad_a_history.loc[len(self.grad_a_history), :] = dPidP.flatten()
            # accumulate:
            dJ += G*grad_log_prob_Pi
            # Param update
            self.ocp.param_update(
                dJ,
                constrained_updates=self.constrained_updates,
            )     
        return {"l_theta": self.ocp.p_val}

    def _parse_agent_params(
        self,
        #load_pretrained_net,
        #tau,
        #critic_lr,
        lr,
        tr,
        train_params,
        constrained_updates=False,
    ):
        #self.load_pretrained_net = load_pretrained_net
        #self.tau = tau
        #self.critic_lr = critic_lr
        self.lr = lr
        self.tr = tr
        self.iterations = train_params["iterations"]
        self.batch_size = train_params["batch_size"]
        self.constrained_updates = constrained_updates
