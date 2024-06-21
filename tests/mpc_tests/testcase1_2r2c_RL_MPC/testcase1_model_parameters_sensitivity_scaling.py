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
from gymnasium.wrappers import TimeLimit
from pprint import pprint
from math import floor, log10

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
days = 1000
F = 24
t = np.linspace(0, 1, F)
signal = np.sin(2*np.pi*F*t)
_r_forecast = signal*10 + 280.15
r_forecast = np.tile(_r_forecast[1:], days)
r_forecast = np.concatenate([_r_forecast, r_forecast])
#plt.plot(t, signal)
#plt.show()

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
            + self.w.T @ np.maximum(0, lb - state)
            + self.w.T @ np.maximum(0, state - ub)
        )
        
    def set_state(self):
        self.x = np.asarray([293.65]).reshape(self.nx, 1)
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
    
    mpc_cfg = os.path.join("1R1C_MPC_sens_test.json")
    perturb = 1.0
    
    dQdR_df = pd.DataFrame(columns=["dQdR_fd", "dQdR", "dev","perc_dev"])
    
    
    for r in np.arange(0.006,0.036,0.001):
    
        params = np.array([r,1E6])*perturb
        #params[-1] = 1e6
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
                "beta": 1e-5,
                "learning_params": {
                    "lr": 1e-6,
                    #"lr": 0,
                    #"lr": 1e-6,
                    #"lr": 5e-2,
                    #"lr": 5e-3,
                    "tr": 1,
                    "train_params": {
                        "iterations": 1,
                        "batch_size": 96
                    },
                    "constrained_updates": False
                }
            }

        # init mpc agent:
        kwargs = {
            "p_nom": [1,1],
            "x_nom_b": 0,
            "x_nom": 1,
            "u_nom": 1
        }
        kwargs = {
                    "x_nom": 20,
                    "x_nom_b": 280.15,
                    "u_nom": 3000,
                    #"u_nom_b": 3000,
                    "r_nom": [20],
                    "r_nom_b": [280.15],
                    "p_nom": [r,1E6],
                    #"p_nom": [1,1],
                    #"p_nom": [1]*5,
                    "sl_nom": 20,
                }
        mpc = MPCfunapprox(
                            agent_params,
                            config=mpc_cfg,
                            param_guess=params, 
                            functions=functions,
                            model_params_in_policy=True,
                            rl_algorithm="Qlearning",
                            **deepcopy(kwargs)
                            )  # to remove, replace with N
        
        #url = 'http://bacssaas_boptest:5000'
        # Use gym env:
        B = 24
        max_ep_len = int(B)
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
        
        x_ref_val = (293.15 - kwargs["x_nom_b"])/kwargs["x_nom"]
        policy_params[-1] = x_ref_val
        policy_params = np.append(policy_params, np.array(params)/np.array(kwargs["p_nom"]))
        #policy_params = np.append(policy_params, np.array(params))
        
        """
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
        #b_labs = create_labels("b", mpc.n_x)
        b_labs = create_labels("b", mpc.n_x*(mpc.N-1))
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
        
        #mpc.codegen_solvers()
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
        sigma = 25
        
        lbx, ubx, ref = bounds.get_bounds(0, mpc.N) 
        k = 0
        
        x_model = pd.DataFrame(columns=["model", "act"])
        
        C = 1E6
        params = [r, C]
        policy_history[-2] = r
        v_mpc, add_info, vsol, raw_v_sol, action, x0 = mpc.V_value(
                                                                    state, 
                                                                    params,
                                                                    policy_params,
                                                                    all_data[k:(k+mpc.N)],
                                                                    lbx, 
                                                                    ubx,
                                                                    ) # state value, gives the action                    
        q_mpc, add_info, qsol, raw_q_sol = mpc.Q_value(
                                                    state, 
                                                    action
                                                    ) # state value, gives the action    
        
        dQdP = mpc.dQdP(
                        raw_q_sol,
                        optimal=add_info["optimal"]
                        )
        
        eps = 1e-16
        _r = params[0]
        Rs = np.arange(_r - eps, _r + 2*eps, eps)
        
        res = pd.DataFrame(columns=["v_mpc"])
        for __r in Rs:
            """
            Solve explicitly with given R.
            
            Compare to sensitivity obtained at
            R = 0.01
            
            If no match, iterate on sensitivity
            calculation until match.
            """
            policy_params[-2:] = np.array([__r, C])/np.array(kwargs["p_nom"])
            params[0] = __r  
            (
                v_mpc, 
                add_info,
                vsol,
                raw_v_sol,
                action,
                x0
            ) = mpc.V_value(
                            state, 
                            params,
                            policy_params,
                            all_data[k:(k+mpc.N)],
                            lbx, 
                            ubx,
                            ) # state value, gives the action
            res.loc[round(__r, 16)] = v_mpc
        
        __r = __r - eps
        fd = float((res.loc[round(__r + eps, 16)] - res.loc[round(__r - eps, 16)])/(2*eps))
        dQdR = float(dQdP[:,-2]/float(kwargs["p_nom"][0]))
        dev = fd - dQdR
        perc_dev = (dev/fd)*100
        print(
            "Deviation is: " + \
            str(dev) + \
            ", or " + str(perc_dev) + " %."
            )
        dQdR_df.loc[r] = [fd, dQdR, dev, perc_dev]
        
    print(dQdR_df)

