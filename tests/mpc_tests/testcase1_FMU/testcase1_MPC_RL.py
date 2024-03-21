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
from project1_boptest_gym.examples.test_and_plot import plot_results
from project1_boptest_gym.boptestGymEnv import BoptestGymEnv
from ocp.q_learning import Qlearning
from ocp.replay_buffer import BasicBuffer, ReplayBuffer

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
 

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("configs", "1R1C_MPC.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    # start off with 'very' wrong params:
    #params = [3.2e-2, 2.5e6]
    #params = [0.7e-2, 1.3e6]
    #params = [1e-2, 1e6]
    #params = [2e-2, 2e6]
    params = [3e-2, 3e6]
    
    """
    No state observer needed for this example.
    
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    """
    
    kwargs = {
        "x_nom": [30],
        "x_nom_b": [280.15],
        "u_nom": [10000],
        #"u_nom_b": 10000,
        "r_nom": [30],
        "r_nom_b": [280.15],
        "sl_nom": [30],
        #"sl_nom_b": [280.15],
        #"p_nom": [1,1],
        #"slack": Trues
        "slack": False
    }
    #kwargs = dict()

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
                "lr": 1e-5,
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
    
    url = 'http://bacssaas_boptest:5000'
    # Use gym env:
    boptest = BoptestGymEnv(boptest_cfg,
                            name                  = "testcase1",
                            url                   = url,
                            actions               = ['oveAct_u'],
                            observations          = {'TRooAir_y':(280.,310.)}, 
                            #observations          = {'TRooAir_y':(280.,310.), 'TDryBul':(280.,310.)}, 
                            random_start_time     = False,
                            max_episode_length    = 24*3600,
                            #predictive_period     = 3600,
                            predictive_period     = mpc.dt*mpc.N,
                            warmup_period         = 0,
                            step_period           = 900)
    boptest.reset()
    # first forecast:
    data = boptest.forecast()
    
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

    obs = state = x0 = np.array([293.15])
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
    
    #max_len_buffer = int(1e5)
    max_len_buffer = int(1)
    # to store experiences:
    replay_buffer = ReplayBuffer(max_len_buffer, seed)
    rollout_return = 0
    
    """
    Batch-mode training,
    update policy parameters
    every B timesteps.
    """
    B = 1
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
    cols.extend(b_labs)
    cols.extend(["x_below", "x_above"])
    cols.extend(["R", "C"])
    #cols.extend(R_labs)
    policy_history = pd.DataFrame(columns=cols)
    
    mpc.codegen_solvers()
    mpc.learning_module.grad_q_history.columns = policy_history.columns
    mpc.learning_module.grad_v_history.columns = policy_history.columns
    mpc.learning_module.grad_q_history_ipopt.columns = policy_history.columns
    
    raw_sol = None
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
        next_obs, reward, done, _, _ = boptest.step(action)
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
        
        # get forecast in separate step:
        data = boptest.forecast()
        # save rewards for easy plotting:
        rewards.append(reward)
        
    plt.rcParams.update({'font.size': 12})
    data = boptest.get_data(tf=K*mpc.dt)
    
    plot_results(
                 boptest,
                 rewards
                 )
    
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
