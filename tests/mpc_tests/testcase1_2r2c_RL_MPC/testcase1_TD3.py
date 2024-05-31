# %%
#from ast import Param
from ocp.parametric_mpc import ParametricMPC, MPCfunapprox
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
#from ocp.boptest_api import Boptest
#from pprint import pprint
#from ocp.filters import EKF, KalmanBucy
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from ocp.functions import functions
from copy import deepcopy
#from project1_boptest_gym.examples.test_and_plot import plot_results
#from project1_boptest_gym.boptestGymEnv import BoptestGymEnv
from ocp.q_learning import Qlearning
from ocp.reinforce import REINFORCE
from ocp.replay_buffer import BasicBuffer, ReplayBuffer
import gymnasium as gym
import numpy.typing as npt
from typing import Any, Optional
from mpcrl.wrappers.envs import MonitorEpisodes
from mpcrl.util.seeding import mk_seed
from mpcrl import LearnableParameter, LearnableParametersDict, LstdQLearningAgent
from mpcrl.optim import NetwonMethod, GradientDescent
from mpcrl.util.control import dlqr, forward_euler
from csnlp import Solution, multistart, scaling, wrappers
from mpcrl.wrappers.agents import Log, RecordUpdates
from gymnasium.wrappers import TimeLimit
from pprint import pprint

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

import numpy as np
import matplotlib.pyplot as plt


"""
Creating the sinusoidal dist:
"""
days = 99
F = 96
t = np.linspace(0, 1, 96)
signal = np.sin(2*np.pi*F*t)
_r_forecast = signal*10 + 290.15
r_forecast = np.tile(_r_forecast[1:], days)
r_forecast = np.concatenate([_r_forecast, r_forecast])
#plt.plot(t, signal)
#plt.show()

"""
from matplotlib.pyplot import plot, legend
def shift(n, N): 
    s = np.zeros(N) 
    s[n] = 1.0 
    return np.fft.fft(s)  
t = np.linspace(0, 2*np.pi,1000) 
v0 = np.sin(t)                                                                                               
S = shift(1000//4, 1000)  # shift by pi/4
VS = np.fft.fft(v0)*S 
vs = np.fft.ifft(VS)
plot(t, v0 , label='original' )
plot(t,vs.real,label='shifted in frequency domain')
legend()
plt.show()
"""

# Additional functions
def rollout_sample(env, agent, n_steps = 50, mode="train"):
    state, obs = env.reset()
    agent.reset(obs)
    rollout_return = 0
    rollout_buffer = BasicBuffer()

    for _ in range(n_steps):
        action, add_info = agent.act_forward(obs, mode=mode)
        next_state, next_obs, reward, _ = env.step(action)
        if mode == "train":
            rollout_buffer.push(
                state, obs, action, reward, next_state, next_obs, add_info
            )
        rollout_return += reward
        state = next_state.copy()
        obs = next_obs.copy()
    return rollout_return, rollout_buffer


"""
Set up MPC, simplest way
to obtain integrator:
"""
kwargs = {
    "x_nom": 1,
    "u_nom": 1,
    "r_nom": 1,
    "slack": False
}
mpc_cfg = os.path.join("1R1C_MPC.json")
#mhe_cfg = os.path.join("2R2C_MHE.json")
#params = [1.3e-2,1.3E6]
#params = [1e-2,1e-1,1e5,1e6,1]
#params = [1]*5
#params = [1e-2,1e-1,1e6,5e6,1]
params = [1e-2,1e6]
_mpc = MPC(
          config=mpc_cfg,
          param_guess=params,
          **deepcopy(kwargs),
        )
"""
From this, we can get
properly scaled A, B
matrices.
"""
dt = 900
Ad = _mpc.get_Ad(dt, p=params)
Bd = _mpc.get_Bd(dt, p=params)

class LtiSystem(gym.Env[npt.NDArray[np.floating], float]):
    """A simple discrete-time LTI system affected by noise."""

    nx = 1  # number of states
    nu = 1  # number of inputs
    nr = 1  # number of disturbances
    
    #A = np.asarray([[0.9, 0.0], [0.25, 1.1]])  # state-space matrix A
    #B = np.asarray([[0.0813], [0.2]])  # state-space matrix B
    A = Ad
    B = Bd[:,:1]
    R = Bd[:,1:]
    x_bnd = (np.asarray([[293.15]]), np.asarray([[296.15]]))  # bounds of state
    a_bnd = (-3000, 3000)  # bounds of control input
    w = np.asarray([[1e2]])  # penalty weight for bound violations
    e_bnd = (-0.1, 0.1 )  # uniform noise bounds

    def reset(
        self,
        *,
        seed: Optional[int] = None,
        options: Optional[dict[str, Any]] = None,
    ) -> tuple[npt.NDArray[np.floating], dict[str, Any]]:
        """Resets the state of the LTI system."""
        super().reset(seed=seed, options=options)
        #self.x = np.asarray([296.15, 296.15]).reshape(self.nx, 1)
        #self.df = pd.DataFrame(columns=["phi_h", "Ta", "phi_s"])
        return self.x.T, {}

    def get_stage_cost(self, state: npt.NDArray[np.floating], action: float) -> float:
        """Computes the stage cost `L(s,a)`."""
        lb, ub = self.x_bnd
        return float(
            0.5 * 1E2 * np.square((state[0] - kwargs["x_nom_b"])/kwargs["x_nom"] - 0.75).sum()
            + 0.5 * 1E-2 * (action/kwargs["u_nom"])**2
            #+ self.w.T @ np.maximum(0, lb - state)
            #+ self.w.T @ np.maximum(0, state - ub)
            + np.maximum(0, lb - state) @ self.w.T @ np.maximum(0, lb - state)
            + np.maximum(0, state - ub) @ self.w.T @ np.maximum(0, state - ub)
        )
        
    def set_state(self):
        self.x = np.asarray([293.15]).reshape(self.nx, 1)
        self.k = 0
        return self.x, {}
        
    def get_history(self, N: int):
        return self.df.iloc[-N:]
        
    def step(
        self, action: ca.DM
    ) -> tuple[npt.NDArray[np.floating], float, bool, bool, dict[str, Any]]:
        """Steps the LTI system."""
        action = float(action)
        x_new = self.A @ self.x + self.B * action + self.R @ np.array([r_forecast[self.k]])
        #x_new[0] += self.np_random.uniform(*self.e_bnd)
        r = self.get_stage_cost(self.x, action)
        self.x = x_new
        self.k += 1
        # store for MHE:
        #self.df.iloc[len(self.df)] = np.array([action*kwargs["u_nom"], 280.15, 0])
        return x_new.T, r, False, False, {}



 

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("1R1C_MPC_REINFORCE.json")
    # perturb = 3
    #perturb = 0.33
    perturb = 1.5
    days = 5
    #params = np.array([1e-2,1e-1,1e6,5e6,1])*perturb
    params = np.array([1e-2,1e6])*perturb
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    seed = 1
    agent_params= {
            "gamma": 1,
            "opt_params": {
                "cost_defn": ["fullW", "fullR"],
                "cost_wt": [[1.0, 1.0, 1.0, 1.0], [0.1, 0.1]],
                "horizon": 10
            },
            "eps": 0.25,
            "learning_params": {
                #"lr": 1e-2,
                #"lr": 1e-3,
                "lr": 0,
                #"lr": 0,
                #"lr": 1e-6,
                #"lr": 5e-2,
                #"lr": 5e-3,
                "load_pretrained_net": False,
                "tau": 0.02,
                "critic_lr": 5e-3,
                "tr": 1,
                "train_params": {
                    "iterations": 1,
                    "batch_size": 95
                },
                "constrained_updates": False
            }
        }

    # init mpc agent:
    kwargs = {
                "x_nom": 20,
                "x_nom_b": 280.15,
                "u_nom": 3000,
                #"u_nom_b": 3000,
                "r_nom": [20],
                "r_nom_b": [280.15],
                "p_nom": [1e-2,1e6],
                #"p_nom": [1]*5,
                "sl_nom": 20,
              }
    #kwargs = {}
    mpc = MPCfunapprox(
                        agent_params,
                        config=mpc_cfg,
                        param_guess=params, 
                        functions=functions,
                        model_params_in_policy=True,
                        rl_algorithm="TD3_learning",
                        **deepcopy(kwargs)
                        )  # to remove, replace with N
    
    #url = 'http://bacssaas_boptest:5000'
    # Use gym env:
    B = 96
    max_ep_len = int(96)
    env = MonitorEpisodes(
                          TimeLimit(
                                    LtiSystem(),
                                    max_episode_steps=max_ep_len
                                    )
                          )
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 293.15}
    ub_night = {"Ti": 296.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ["Ti"],
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)

    state, _ = env.set_state()    
    K = days*24*bounds.t_h # tot timesteps
    rewards = []
    np.random.seed(0)
    policy_params = np.random.normal(
                                     loc=0.01,
                                     scale=1e-2,
                                     size=(mpc.P.shape[0] - mpc.n_p)
                                     )
    policy_params = np.zeros(
                            shape=(mpc.P.shape[0] - mpc.n_p)
                            )
    #policy_params[-1] = (295.15 - kwargs["x_nom_b"])/kwargs["x_nom"]
    policy_params = np.append(policy_params, np.array(params))
    
    def create_labels(prefix, num):
        return list(
                    map(
                        lambda x: prefix + str(x), 
                        range(num)
                        )
                )
    W_labs = create_labels("W", mpc.n_x**2)
    S_labs = create_labels("S", mpc.n_x**2)
    b_labs = create_labels("b", mpc.n_x)
    f_labs = create_labels("f", mpc.n_x + mpc.n_u)
    ref_labs = create_labels("x_ref", 1)
    cols = W_labs
    cols.extend(S_labs)
    cols.extend(f_labs)
    cols.extend(["V0"])
    cols.extend(b_labs)
    cols.extend(["x_below[0]", "x_above[0]"])
    cols.extend(ref_labs)
    cols.extend(["R", "C"])
    policy_history = pd.DataFrame(columns=cols)
    
    max_len_buffer = int(B)
    #max_len_buffer = int(1)
    # only store from previous episode:
    replay_buffer = ReplayBuffer(max_len_buffer, seed)
    rollout_buffer = BasicBuffer()
    rollout_return = 0
    t_returns = []
    
    mpc.codegen_solvers()
    #mpc.learning_module.grad_q_history.columns = policy_history.columns
    #mpc.learning_module.grad_v_history.columns = policy_history.columns
    #mpc.learning_module.grad_q_history_ipopt.columns = policy_history.columns
    #data = pd.DataFrame(data=r.T, columns=["Ta", "phi_s"])
    all_data = pd.DataFrame(data=r_forecast, columns=["Ta"])
    raw_sol = None
    env.reset()
    
    """
    Perturbation-based exploration:
        - draw offset from normal distribution
    """
    #decay = 0.999
    decay = 1
    sigma = 0
    
    assert max_ep_len == B, \
        "Policy gradient method, only update parameters after episode completion."
    assert max_len_buffer == max_ep_len, \
        "On-policy, only update parameters based on trajectory followed using " + \
        "current policy."
    
    x_model = pd.DataFrame(columns=["model", "act"])
    
    """
    For TD3, need next action. 
    Thus, wait one iteration until
    pushing to replay buffer.
    
    This shortens the buffer by one
    entry, as the next action of the episode
    will not be available for a continuous
    learning task.
    """
    
    for k in range(K):
        policy_history.loc[k] = policy_params
        #lbx, ubx, ref = bounds.get_bounds(k, mpc.N) 
        """
        TODO: duplicate handling of x0:
        """
        #action, add_info, sol, raw_sol = mpc.act_forward(obs)   
        """
        Act forward on policy, aka. find the optimal action
        as a = argmin Q(s,a)
        """
        lbx, ubx, ref = bounds.get_bounds(0, mpc.N) 
        v_mpc, add_info, vsol, raw_v_sol, action_mean, x0 = mpc.V_value(
                                                                state, 
                                                                params,
                                                                policy_params,
                                                                all_data[k:(k+mpc.N)],
                                                                lbx, 
                                                                ubx,
                                                                ) # state value, gives the action
        """
        NOTE: does u in Pfixed have effect on dRdz?
        """
        mpc.pf_val[mpc.obs_dim:(mpc.obs_dim + mpc.action_dim)] = action_mean
        dPidP = mpc.dPidP(
                        raw_v_sol,
                        mpc.pf_val,
                        mpc.pp_val,
                        optimal=add_info["optimal"]
                        )
        # normal-centered pert. on action:
        action_mean = float(action_mean)
        action = action_mean + np.random.normal(0, sigma*(decay**k))
        #action = action_mean
        # step with perturbed action:
        next_obs, reward, done, _, _ = env.step(float(action))
        x_model.loc[k] = [x0.iloc[0], next_obs[0][0]]
        # simple case, no estimation, i.e. x == s:
        next_state = next_obs
        
        buffer_entry = (
                state,
                np.array([[action]]),
                reward,
                next_state,
                v_mpc,
                0,
                0,
                dPidP,
                action_mean
        )
        # modify action to fit in buffer:
        #action = action.values.flatten()
        rollout_return += reward
        state = next_state.copy()
        try:
            prev_buffer_entry = prev_buffer_entry + (np.array([[action_mean]]), )
            rollout_buffer.push(*prev_buffer_entry)  
        except:
            assert k % B == 0
            
        # in trouble:
        if mpc.nlp_solver.stats()["return_status"] != 'Solve_Succeeded':
            print(action)
        """
        Possible batch update:
        """
        prev_buffer_entry = deepcopy(buffer_entry)
        
        if (k+1) % B == 0:
            """
            TODO: solve for value function in next state.
            """
            replay_buffer.push(rollout_buffer.buffer)
            t_returns.append(rollout_return)
            #policy_params = mpc.train(replay_buffer, sigma)
            policy_params = mpc.train(replay_buffer)
            replay_buffer = ReplayBuffer(max_len_buffer, seed)
            rollout_buffer = BasicBuffer()
            rollout_return = 0
            # remove off-policy transition:
            del prev_buffer_entry

        if (k+1) % max_ep_len == 0:
            env.reset()
        
        # get forecast in separate step:
        #data = boptest.forecast()
        # save rewards for easy plotting:
        rewards.append(reward)
        
        
    plt.rcParams.update({'font.size': 12})
    #data = boptest.get_data(tf=K*mpc.dt)
    
    X = np.array(env.observations).squeeze()
    X = X.flatten()
    U = np.array(env.actions).flatten()
    R = np.array(env.rewards).flatten()

    _, axs = plt.subplots(2, 1, constrained_layout=True, sharex=True)
    X_set = np.repeat(np.array([295.15]),K)
    #axs[1].plot(X[1])
    for i in range(2):
        axs[0].axhline(env.x_bnd[i][0], color="r")
        #axs[1].axhline(env.x_bnd[i][1], color="r")
        axs[1].axhline(env.a_bnd[i], color="r")
        
    axs[0].plot(X, color="b", linestyle="dashed")
    axs[0].plot(X_set, color="r", linestyle="dashed")
    axs[1].plot(U, color="b", linestyle="dashed")
    axs[0].set_ylabel("$s_1$")
    #axs[1].set_ylabel("$s_2$")
    axs[1].set_ylabel("$a$")
    
    
    _, axs = plt.subplots(2, 1, constrained_layout=True, sharex=True)
    #axs[0].plot(mpc.learning_module.td_error, "o", markersize=1)
    axs[1].semilogy(rewards, "o", markersize=1)
    axs[0].set_ylabel(r"$\tau$")
    axs[1].set_ylabel("$L$")
    
            
    from math import sqrt, ceil
    n = ceil(sqrt(mpc.nP))
    fig, axes = plt.subplots(n,n)
    cols = policy_history.columns
    for i, ax in enumerate(axes.flatten()):
        try:
            ser = policy_history[cols[i]]
            ser.plot(ax=ax)
            ax.set_title(cols[i])
        except IndexError:
            pass
    #fig.tight_layout()
    plt.show()
    
    """
    Save optimal sequence:
    """
    df = pd.DataFrame(data=U, columns=["u"])
    if perturb == 1.0:
        df.to_csv("optimal_u_20_days.csv", index=True)
    else: # 
        df_opt = pd.read_csv("optimal_u_20_days.csv", index_col=0)
        df["u_opt"] = df_opt["u"]
        df["res"] = df["u_opt"] - df["u"]
        df["Ta"] = all_data["Ta"][0:len(df)]
        df["Ti"] = X[0:len(df)]
        df["Ti-Ta"] = df["Ti"] - df["Ta"]
        
        df = df.iloc[95:]
        df.index = range(len(df.index))
        
        _, axs = plt.subplots(5, 1, constrained_layout=True, sharex=True)
        #axs[0].plot(mpc.learning_module.td_error, "o", markersize=1)
        axs[0].plot(df[["u", "u_opt"]])
        axs[0].legend(["u", "u_opt"])
        axs[1].plot(df[["res"]]/max(df["res"]))
        axs[1].plot(df["Ti-Ta"]/max(df["Ti-Ta"]))
        
        """
        Reconstruct residual from knowledge about disturbance.
        """
        days = 99
        F = 96
        t = np.linspace(0, 1, 96)
    
        """
        
        y = A*sin(B(x-C)) + D
        
        p = 2*pi/B
        
        Express C in terms of p..
        
        """
        
        B = 2*np.pi*F
        
        period = 2*np.pi/B
        
        A = (df.res.max() - df.res.min())/2
        D = (df.res.max() + df.res.min())/2
        max_ndx_res = np.argmax(df.res)
        max_ndx_Ta = np.argmax(df.Ta)
        index_shift = max_ndx_res - max_ndx_Ta
        
        """
        C in terms of p:
        """
        
        C = index_shift/96*period
        signal = A*np.sin(B*(t - C)) + D
        
        axs[2].plot(df[["res"]])
        axs[2].plot(signal)
        #axs[2].plot(signal)
        #axs[2].plot(signal_C0, linestyle="dashed")
        axs[2].legend(["actual", "reconstructed"])
        axs[1].legend(["res", "Ti-Ta"])
        axs[3].plot(df["Ta"][0:len(df)])
        axs[4].plot(df["Ti"] - 293.15)
        plt.show()
    
    print(params)
