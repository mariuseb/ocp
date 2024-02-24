from ocp.replay_buffer import ReplayBuffer
import pandas as pd

class Qlearning:
    def __init__(self, mpc, learning_params, seed):
        # hyperparameters
        self.mpc = mpc
        self._parse_agent_params(**learning_params)
        self.q_failures = 0
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
        self.td_error = pd.DataFrame(columns=["td_error"])

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
        batch_size = min(self.batch_size, replay_buffer.size)
        train_it = min(self.iterations, int(3.0 * replay_buffer.size / batch_size))
        #train_it = 1

        for it in range(train_it):
            (
                states,
                _,
                actions,
                rewards,
                next_states,
                _,
                datas,
                infos,
            ) = replay_buffer.sample(batch_size)

            del_J = 0.0
            for j, state in enumerate(states):
                action = actions[j]
                next_state = next_states[j]
                reward = rewards[j]
                data = datas[j]
                
                # Q value of the state-action pair
                """
                TODO: what if bounds are not fixed?
                store bounds as parameters.
                """
                self.mpc.prepare_warm_solve(
                        data[0:self.mpc.N],
                        model_params=self.mpc.params
                    )
                q, info, sol = self.mpc.Q_value(state, action)
                # Hint: we found the Q value for state and action in exercise 11
                if not self.mpc.qsolver.stats()["success"]:
                    self.q_failures += 1
                # V value of the next state
                #v_next, info_next = self.mpc.V_value(next_state, mode="update")
                self.mpc.prepare_warm_solve(
                        data[1:self.mpc.N+1],
                        model_params=self.mpc.params
                    )
                v_next, info_next = self.mpc.V_value(next_state)

                # TD error
                td_target = reward + self.mpc.gamma*v_next - q
                
                # sensitivity of Q 
                grad_q = self.mpc.dQdP(
                                       info["soln"],
                                       self.mpc.pf_val,
                                       self.mpc.pp_val,
                                       self.mpc.p_bounds,
                                       optimal=True
                                       )
                if (abs(grad_q[:,-self.mpc.n_p:]) > 1).any():
                    # reject model parameter gradient if bigger than 1
                    grad_q[:,-self.mpc.n_p:] = 0
                # estimate of dJ
                self.grad_q_history.loc[len(self.grad_q_history), :] = grad_q.flatten()
                del_J -= td_target * grad_q.T
                td_avg += td_target
                
            del_J = del_J/batch_size
            self.delJ_history.loc[len(self.delJ_history), :] = del_J.flatten()
            # RL update step
            self.mpc.param_update(del_J, constrained_updates=self.constrained_updates)
        self.td_error.loc[len(self.td_error), :] = td_avg / train_it
        print(f"Averaged TD error: {td_avg / train_it}")

    def _parse_agent_params(self, lr, tr, train_params, constrained_updates=False):
        self.lr = lr
        self.tr = tr
        self.iterations = train_params["iterations"]
        self.batch_size = train_params["batch_size"]
        self.constrained_updates = constrained_updates
