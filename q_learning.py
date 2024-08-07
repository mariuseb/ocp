from ocp.replay_buffer import ReplayBuffer
import pandas as pd

class Qlearning:
    def __init__(self, mpc, learning_params, seed):
        # hyperparameters
        self.mpc = mpc
        self._parse_agent_params(**learning_params)
        self.q_failures = 0
        self.n_eps = 0
        self.delJ_history = pd.DataFrame(columns=list(
                map(
                    lambda x: "theta" + str(x), 
                    range(self.mpc.P.shape[0])
                    )
                )
        )
        self.grad_q_history = pd.DataFrame(columns=list(
                map(
                    lambda x: "theta" + str(x), 
                    range(self.mpc.P.shape[0])
                    )
                )
        )
        self.grad_q_history_ipopt = pd.DataFrame(columns=list(
                map(
                    lambda x: "theta" + str(x), 
                    range(self.mpc.P.shape[0])
                    )
                )
        )
        self.td_avg_error = pd.DataFrame(columns=["td_avg_error"])
        self.v_q_errors = pd.DataFrame(columns=["v_q_error"])
        self.rewards = pd.DataFrame(columns=["r"])
        self.td_error = pd.DataFrame(columns=["td_error"])
        self.td_error_avg = pd.DataFrame(columns=["td_error_avg"])
        self.r_hats = pd.DataFrame(columns=["r_hat"])
        self.r_hat = 0

    def train(self, replay_buffer: ReplayBuffer):
        """
        Updates Qfn parameters by using (random) data from replay_buffer

        Parameters
        ----------
        replay_buffer : ReplayBuffer object
            Class instance containing all past data

        Returns
        -------
        dict : {l_theta: parameters of Qfn,
                TD_error: observed TD_error}

        """
        td_avg = 0
        td_error_avg = 0
        batch_size = min(self.batch_size, replay_buffer.size)
        train_it = min(self.iterations, int(3.0 * replay_buffer.size / batch_size))
        #train_it = 1

        for it in range(train_it):
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
                _
            #) = replay_buffer.sample(batch_size)
            ) = replay_buffer.flatten_buffer()

            del_J = 0.0
            for j, state in enumerate(states):
                
                state = states[j]
                action = actions[j]
                R = Rs[j]
                next_state = next_states[j]
                V_next = V_nexts[j]
                Q_curr = Q_currs[j]
                dQdP = dQdPs[j]
                dPidP = dPidPs[j]
                
                # TD error
                v_q_error = self.mpc.gamma*V_next - Q_curr
                td_target = R + v_q_error
                """
                R hat estimation:
                
                Two options:
                    1.) As in Sutton & Barto, pg. 251 (10.3).
                    2.) Running average.
                
                """
                td_target_r_hat = td_target - self.r_hat
                td_error_avg += td_target_r_hat
                self.r_hat = self.r_hat + td_target_r_hat*self.mpc.beta
                self.r_hats.loc[len(self.rewards), :] = self.r_hat       
                #
                self.v_q_errors.loc[len(self.v_q_errors), :] = v_q_error
                self.rewards.loc[len(self.rewards), :] = R
                
                #if (abs(grad_q[:,-self.mpc.n_p:]) > 1).any():
                    # reject model parameter gradient if bigger than 1
                #    grad_q[:,-self.mpc.n_p:] = 0
                # estimate of dJ
                #dQdP = dQdP.clip(min=-1E3, max=1E3)
                
                self.grad_q_history.loc[len(self.grad_q_history), :] = dQdP.flatten()
                #del_J -= td_target*grad_q.T
                del_J -= td_target*dQdP.T
                """
                Change to td_target_r_hat,
                i.e. deviation from expected 
                reward. 
                """
                #del_J += td_target_r_hat*dQdP.T
                td_avg += td_target
                # save all iterations:
                if abs(td_target) > 1: 
                    print(td_target)
                self.td_error.loc[len(self.td_error), :] = td_target
                #del_J = del_J/batch_size
                
            self.delJ_history.loc[len(self.delJ_history), :] = del_J.flatten()
            self.td_error_avg.loc[len(self.td_error_avg), :] = td_error_avg/batch_size
            # RL update step
            self.mpc.param_update(del_J, constrained_updates=self.constrained_updates)
            self.n_eps += 1
            #self.lr = self.lr - 0.01*self.lr
        self.td_avg_error.loc[len(self.td_avg_error), :] = td_avg / train_it
        print(f"Averaged TD error: {td_avg / train_it}")

    def _parse_agent_params(self, lr, tr, train_params, constrained_updates=False):
        self.lr = lr
        self.tr = tr
        self.iterations = train_params["iterations"]
        self.batch_size = train_params["batch_size"]
        self.constrained_updates = constrained_updates
