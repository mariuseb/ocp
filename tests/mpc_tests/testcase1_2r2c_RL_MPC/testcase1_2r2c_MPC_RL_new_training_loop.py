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
mpc_cfg = os.path.join("2R2C_MPC.json")
#mhe_cfg = os.path.join("2R2C_MHE.json")
#params = [1.3e-2,1.3E6]
#params = [1e-2,1e-1,1e5,1e6,1]
#params = [1]*5
params = [1e-2,1e-1,1e6,5e6,1]
_mpc = MPC(
          config=mpc_cfg,
          param_guess=params,
          **deepcopy(kwargs),
        )

kwargs = {
    "x_nom": 1,
    "u_nom": 1,
    "r_nom": 1,
    "slack": False
}
kwargs = {
    "x_nom": 10,
    "x_nom_b": 290.15,
    "u_nom": 3000,
    "r_nom": [10,1],
    "r_nom_b": [290.15,0],
    #""p_nom": [1, 1],
    #"slack": Trues
    "slack": False
}
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

    nx = 2  # number of states
    nu = 1  # number of inputs
    nr = 2  # number of disturbances
    
    #A = np.asarray([[0.9, 0.0], [0.25, 1.1]])  # state-space matrix A
    #B = np.asarray([[0.0813], [0.2]])  # state-space matrix B
    A = Ad
    B = Bd[:,:1]
    R = Bd[:,1:]
    x_bnd = (np.asarray([[295.15], [280]]), np.asarray([[300.15], [320]]))  # bounds of state
    a_bnd = (-3000, 3000)  # bounds of control input
    w = np.asarray([[1e2], [1e2]])  # penalty weight for bound violations
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
            0.5 * 1E1 * np.square((state[0] - kwargs["x_nom_b"])/kwargs["x_nom"] - 0.75).sum()
            + 0.5 * (action/kwargs["u_nom"])**2
            + self.w.T @ np.maximum(0, lb - state)
            + self.w.T @ np.maximum(0, state - ub)
        )
        
    def set_state(self):
        self.x = np.asarray([296.15, 296.15]).reshape(self.nx, 1)
        return self.x, {}
        
    def get_history(self, N: int):
        return self.df.iloc[-N:]
        
    def step(
        self, action: ca.DM
    ) -> tuple[npt.NDArray[np.floating], float, bool, bool, dict[str, Any]]:
        """Steps the LTI system."""
        action = float(action)
        x_new = self.A @ self.x + self.B * action + self.R @ np.asarray([280.15, 0]).reshape(self.nr, 1)
        #x_new[0] += self.np_random.uniform(*self.e_bnd)
        r = self.get_stage_cost(self.x, action)
        self.x = x_new
        # store for MHE:
        #self.df.iloc[len(self.df)] = np.array([action*kwargs["u_nom"], 280.15, 0])
        return x_new.T, r, False, False, {}


 

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("2R2C_MPC.json")
    # perturb = 3
    perturb = 0.5
    params = np.array([1e-2,1e-1,1e6,5e6,1])*perturb
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
                "lr": 1e-3,
                #"lr": 1e-6,
                #"lr": 5e-2,
                #"lr": 5e-3,
                "tr": 1,
                "train_params": {
                    "iterations": 1,
                    "batch_size": 64
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
                "r_nom": [20,1],
                "r_nom_b": [280.15,0],
                "p_nom": [1e-2,1e-1,1e6,5e6,1],
                #"p_nom": [1]*5,
                "sl_nom": 20,
                #"slack": Trues
                "slack": False
              }
    #kwargs = {}
    mpc = MPCfunapprox(
                        agent_params,
                        config=mpc_cfg,
                        param_guess=params, 
                        functions=functions,
                        model_params_in_policy=True,
                        **deepcopy(kwargs)
                        )  # to remove, replace with N
    
    #url = 'http://bacssaas_boptest:5000'
    # Use gym env:
    B = 1
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
    lb_night = {"Ti": 295.15}
    ub_night = {"Ti": 300.15}
    lb_day = {"Ti": 295.15}
    ub_day = {"Ti": 300.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ["Ti"],
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)

    state, _ = env.set_state()    
    days = 30
    K = days*24*bounds.t_h # tot timesteps
    rewards = []
    np.random.seed(0)
    policy_params = np.zeros(
                            shape=(mpc.P.shape[0] - mpc.n_p)
                            )
    policy_params[-1] = (295.15 - kwargs["x_nom_b"])/kwargs["x_nom"]
    policy_params = np.append(policy_params, np.array(params))
    
    """
    policy_params = np.random.normal(
                                     loc=0.01,
                                     scale=1e-2,
                                     size=(mpc.P.shape[0] - mpc.n_p)
                                     )
    """
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
    #cols.extend(["V0"])
    #cols.extend(b_labs)
    cols.extend(["x_below[0]", "x_below[1]", "x_above[0]", "x_above[1]"])
    cols.extend(ref_labs)
    cols.extend(["Rie", "Rea", "Ci", "Ce", "Ai"])
    policy_history = pd.DataFrame(columns=cols)
    
    max_len_buffer = int(B)
    #max_len_buffer = int(1)
    # only store from previous episode:
    replay_buffer = ReplayBuffer(max_len_buffer, seed)
    rollout_buffer = BasicBuffer()
    rollout_return = 0
    t_returns = []
    
    mpc.codegen_solvers()
    mpc.learning_module.grad_q_history.columns = policy_history.columns
    #mpc.learning_module.grad_v_history.columns = policy_history.columns
    mpc.learning_module.grad_q_history_ipopt.columns = policy_history.columns
    
    r = np.array([
             [280.15]*(mpc.N+1),
             [0]*(mpc.N+1)
             ]
             ).reshape(
                (
                LtiSystem.nr, 
                (mpc.N+1)
                )
            )
    data = pd.DataFrame(data=r.T, columns=["Ta", "phi_s"])
    raw_sol = None
    env.reset()
    
    """
    First state value, V(s0), calculate here:
    """
    lbx, ubx, ref = bounds.get_bounds(0, mpc.N) 
    v_mpc, add_info, vsol, raw_v_sol, action, x0 = mpc.V_value(
                                                        state, 
                                                        params,
                                                        policy_params,
                                                        data,
                                                        lbx, 
                                                        ubx,
                                                        ) # state value, gives the action
    
    """
    Perturbation-based exploration:
        - draw offset from normal distribution
    """
    #decay = 0.999
    decay = 1
    for k in range(K):
        policy_history.loc[k] = policy_params
        #lbx, ubx, ref = bounds.get_bounds(k, mpc.N) 
        """
        TODO: duplicate handling of x0:
        """
        #action, add_info, sol, raw_sol = mpc.act_forward(obs)   
        """
        Get Q(s,a) and ∇Q.
        Only change from V(s) is fixed u0.
        """
        q_mpc, add_info, qsol, raw_q_sol = mpc.Q_value(
                                                    state, 
                                                    action
                                                    ) # state value, gives the action
        dQdP = mpc.dQdP(
                        raw_q_sol,
                        optimal=add_info["optimal"]
                        )
        # normal-centered pert. on action:
        action = action + np.random.normal(0, 50*(decay**k))
        # step with perturbed action:
        next_obs, reward, done, _, _ = env.step(float(action))
        # simple case, no estimation, i.e. x == s:
        next_state = next_obs
        
        # modify action to fit in buffer:
        action = action.values.flatten()
        """
        TODO: rewrite buffer to only take:  
            - Q(s,a)
            - V(s+)
            - ∇Q(s,a)
            - R
        Then we do the Q-learning update:
            tau <- -R + gamma*V(s+) - Q(s,a)
            theta_new <- theta_old + tau*∇Q(s,a)
        """
        rollout_return += reward
        state = next_state.copy()
        """
        Get V(s+).
        """
        lbx, ubx, ref = bounds.get_bounds(k+1, mpc.N) 
        v_mpc, add_info, vsol, raw_v_sol, action, x0 = mpc.V_value(
                                                                state, 
                                                                params,
                                                                policy_params,
                                                                data,
                                                                lbx, 
                                                                ubx,
                                                                ) # state value, gives the action 
        rollout_buffer.push(
                state,
                action,
                reward,
                next_state,
                v_mpc,
                q_mpc,
                dQdP,
                0, # no policy gradient yet, ignore dPi
                action
            )  
        # in trouble:
        if mpc.nlp_solver.stats()["return_status"] != 'Solve_Succeeded':
            print(action)
        """
        Possible batch update:
        """
        if (k+1) % B == 0:
            """
            TODO: solve for value function in next state.
            """
            replay_buffer.push(rollout_buffer.buffer)
            t_returns.append(rollout_return)
            policy_params = mpc.train(replay_buffer)
            rollout_buffer = BasicBuffer()
            rollout_return = 0

        if (k+1) % max_ep_len == 0:
            env.reset()
        
        # get forecast in separate step:
        #data = boptest.forecast()
        # save rewards for easy plotting:
        rewards.append(reward)
        
    plt.rcParams.update({'font.size': 12})
    #data = boptest.get_data(tf=K*mpc.dt)
    
    X = np.array(env.observations).squeeze()
    X = X.reshape(-1, X.shape[-1]).T
    U = np.array(env.actions).flatten()
    R = np.array(env.rewards).flatten()

    _, axs = plt.subplots(3, 1, constrained_layout=True, sharex=True)
    axs[0].plot(X[0])
    X_set = np.repeat(np.array([295.15]),K)
    axs[0].plot(X_set, color="r", linestyle="dashed")
    axs[1].plot(X[1])
    for i in range(2):
        axs[0].axhline(env.x_bnd[i][0], color="r")
        axs[1].axhline(env.x_bnd[i][1], color="r")
        axs[2].axhline(env.a_bnd[i], color="r")
    axs[2].plot(U, color="b", linestyle="dashed")
    axs[0].set_ylabel("$s_1$")
    axs[1].set_ylabel("$s_2$")
    axs[2].set_ylabel("$a$")
    
    _, axs = plt.subplots(2, 1, constrained_layout=True, sharex=True)
    axs[0].plot(mpc.learning_module.td_error, "o", markersize=1)
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
    
    print(data)
