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
    x_bnd = (np.asarray([[290.15], [280]]), np.asarray([[300.15], [320]]))  # bounds of state
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
        #self.x = np.asarray([293.15, 293.15]).reshape(self.nx, 1)
        #self.df = pd.DataFrame(columns=["phi_h", "Ta", "phi_s"])
        return self.x.T, {}

    def get_stage_cost(self, state: npt.NDArray[np.floating], action: float) -> float:
        """Computes the stage cost `L(s,a)`."""
        lb, ub = self.x_bnd
        return float(
            0.5 * 1E1 * np.square(state[0] - 295.15).sum()
            + 0.5 * (action/kwargs["u_nom"])**2
            + self.w.T @ np.maximum(0, lb - state)
            + self.w.T @ np.maximum(0, state - ub)
        )
        
    def set_state(self):
        self.x = np.asarray([295.65, 295.15]).reshape(self.nx, 1)
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
    
    #mpc_cfg = os.path.join("configs", "1R1C_MPC.json")
    mpc_cfg = os.path.join("2R2C_MPC.json")
    #mhe_cfg = os.path.join("2R2C_MHE.json")
    #params = [1.3e-2,1.3E6]
    #params = [1e-2,1e-1,1e5,1e6,1]
    #params = [1]*5
    params = np.array([1e-2,1e-1,1e6,5e6,1])*2
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
                "lr": 1e-2,
                #"lr": 1e-6,
                #"lr": 5e-2,
                #"lr": 5e-3,
                "tr": 1e-2,
                "train_params": {
                    "iterations": 1,
                    "batch_size": 64
                },
                "constrained_updates": False
            }
        }

    # init mpc agent:
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
    #K = int(2e4)
    max_ep = int(100)
    #max_ep = K
    #episodes = int(K/max_ep)
    env = MonitorEpisodes(TimeLimit(LtiSystem(), max_episode_steps=max_ep))
    
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

    #obs = state = x0 = np.array([293.15, 293.15])
    #obs = state = x0 = np.array([293.15])
    obs, _ = state, _ = x0, _ = env.set_state()
    days = 365
    K = days*24*bounds.t_h # tot timesteps
    rewards = []
    np.random.seed(0)
    #policy_params = np.array([0]*mpc.P.shape[0])
    policy_params = np.random.normal(
                                     loc=0.01,
                                     scale=1e-2,
                                     size=(mpc.P.shape[0] - mpc.n_p)
                                     )
    policy_params = np.zeros(
                            shape=(mpc.P.shape[0] - mpc.n_p)
                            )
    policy_params = np.append(policy_params, np.array(params))
    # slack weight:
    #policy_params[-1] = 1e4
    
    """
    First test:
    
    See if we can run the parametric MPC for some days,
    w/o any parameter updates.
    
    DONE, and works.
    
    Find out how to set parameters of nlp
    in a reasonable way.
    -> good for now.
    
    First:
        - consider only ONE rollout.
        
    TODO: add data to buffer
    Make sure forecast is length N+1,
    so we can calculate both q(s,a) and v(s+)
    """
    
    max_len_buffer = int(1e5)
    #max_len_buffer = int(1)
    # to store experiences:
    replay_buffer = ReplayBuffer(max_len_buffer, seed)
    rollout_return = 0
    
    """
    Batch-mode training,
    update policy parameters
    every B timesteps.
    """
    B = 1E2
    rollout_buffer = BasicBuffer()
    t_returns = []
    
    """
    Main loop:
    cols = list(
                map(
                    lambda x: "theta" + str(x), 
                    range(mpc.P.shape[0])
                    )
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
    #R_labs = create_labels("R", mpc.n_x)
    cols = W_labs
    cols.extend(S_labs)
    cols.extend(f_labs)
    cols.extend(["V0"])
    #cols.extend(b_labs)
    cols.extend(["x_below[0]", "x_below[1]", "x_above[0]", "x_above[1]"])
    cols.extend(["Rie", "Rea", "Ci", "Ce", "Ai"])
    #cols.extend(R_labs)
    policy_history = pd.DataFrame(columns=cols)
    
    mpc.codegen_solvers()
    mpc.learning_module.grad_q_history.columns = policy_history.columns
    mpc.learning_module.grad_v_history.columns = policy_history.columns
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
    for k in range(K):
        policy_history.loc[k] = policy_params
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N) 
        """
        sol, u_0, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params,
                               codegen=False
                               )
        Order:
        Pbounds = (p_lbx, p_ubx, p_lbu, p_ubu)
        P = (Pf, P, Pbounds)
        
        Note: bounds on u are stored in mpc object.
        """
        
        mpc.prepare_forward(
                            data[0:mpc.N],
                            prev_sol=raw_sol,
                            x0=obs,
                            lbx=lbx,
                            ubx=ubx,
                            model_params=params,
                            policy_params=policy_params
                            )
        
        """
        TODO: duplicate handling of x0:
        """
        action, add_info, sol, raw_sol = mpc.act_forward(obs)   
        next_obs, reward, done, _, _ = env.step(float(action))
        # simple case, no estimation, i.e. x == s:
        next_state = next_obs
        # modify action to fit in buffer:
        action = action.values.flatten()
        rollout_buffer.push(
                state,
                obs,
                action,
                reward,
                next_state,
                next_obs,
                data,
                add_info,
                raw_sol,
                sol,
                mpc.p_val
            )
        rollout_return += reward
        state = next_state.copy()
        obs = next_obs.copy()
        
        # in trouble:
        if mpc.nlp_solver.stats()["return_status"] != 'Solve_Succeeded':
            print(action)
        
        if (k+1) % B == 0:
            
            """
            TODO: solve for value function in next state.
            """
            
            replay_buffer.push(rollout_buffer.buffer)
            t_returns.append(rollout_return)
            policy_params = mpc.train(replay_buffer)
            rollout_buffer = BasicBuffer()
            rollout_return = 0
            _,_ = env.reset()
        
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
    X_set = np.repeat(np.array([295.0621]),K)
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
    fig.tight_layout()
    plt.show()
    print(data)
