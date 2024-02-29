# %%
#from ast import Param
from ocp.parametric_mpc import ParametricMPC, MPCfunapprox
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
    params = [1e-2,1e6]
    
    """
    No state observer needed for this example.
    
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    """
    
    kwargs = {
        "x_nom": 30,
        "x_nom_b": 280.15,
        "u_nom": 10000,
        "r_nom": 30,
        "r_nom_b": 280.15,
        #"p_nom": [1e-3,1e7],
        #"slack": Trues
        "slack": False
    }

    seed = 1
    agent_params= {
            "gamma": 0.9,
            "opt_params": {
                "cost_defn": ["fullW", "fullR"],
                "cost_wt": [[1.0, 1.0, 1.0, 1.0], [0.1, 0.1]],
                "horizon": 10
            },
            "eps": 0.25,
            "learning_params": {
                "lr": 5e-3,
                #"lr": 5e-2,
                "tr": 0.2,
                "train_params": {
                    "iterations": 1,
                    "batch_size": 128
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
    # Use gym env from Javiers code instead:
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

    obs = state = np.array([293.15])
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
    so we can calculate both q and v_+
    """
    
    max_len_buffer = int(1e5)
    # to store experiences:
    replay_buffer = ReplayBuffer(max_len_buffer, seed)
    rollout_return = 0
    
    """
    Batch-mode training,
    update policy parameters
    every B timesteps.
    """
    B = 96
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
    b_labs = create_labels("b", mpc.n_x)
    f_labs = create_labels("f", mpc.n_x + mpc.n_u)
    #R_labs = create_labels("R", mpc.n_x)
    cols = W_labs
    cols.extend(b_labs)
    cols.extend(f_labs)
    cols.extend(["V0"])
    cols.extend(["x_below", "x_above"])
    cols.extend(["R", "C"])
    #cols.extend(R_labs)
    policy_history = pd.DataFrame(columns=cols)
    
    #mpc.codegen_solvers()
    lbx, ubx, ref = bounds.get_bounds(0, mpc.N) 
    """
    Solve MPC problem with R = [1-3, ... , 1E-1]
    """
    
    sqp_opts = dict(
                    qpsol='qrqp',
                    #qpsol='qrqp',
                    qpsol_options=dict(print_iter=False,error_on_fail=False), 
                    print_time=True,
                    #regularize=True,
                    min_step_size=1E-8,
                    bound_consistency=True,
                    #clip_inactive_lam=True,
                    calc_lam_p=True
                    )
    sqp_sol = ca.nlpsol("sqpsolver",
                        "sqpmethod",
                        mpc.vnlp_prob,
                        sqp_opts
                        )
    
    
    R = np.arange(10, 1100, step=10)*1E-3
    f = []
    lam_R = []
    #mpc.codegen_solvers()
    lam_p = pd.DataFrame(columns=["R", "C", "f"])
    for r in R:
        params[0] = r
        policy_params[-2] = r
        mpc.prepare_forward(
                            data[0:mpc.N],
                            x0=obs,
                            lbx=lbx,
                            ubx=ubx,
                            model_params=params,
                            policy_params=policy_params
                            )
        action, add_info, sol, raw_sol = mpc.act_forward(obs)  
        dVdP_from_sol = raw_sol["lam_p"][mpc.nPf:-mpc.nPbounds].full().flatten()
        dVdP = mpc.dVdP(
                        add_info["soln"],
                        mpc.pf_val,
                        mpc.pp_val,
                        mpc.p_bounds
                        )
        """
        sqp_sol = sqp_sol(x0=raw_sol["x"],
                          lbx=mpc.lbx, 
                          ubx=mpc.ubx,
                          lbg=mpc.lbg_vcsd,
                          ubg=mpc.ubg_vcsd 
                          )
        """
        #f.append(raw_sol["f"])
        print(sqp_sol)
        lam_p.loc[r] = np.concatenate([dVdP_from_sol[-2:], np.array(raw_sol["f"]).flatten()])
      
    """
    Projected solution from p.
    """  
    
    print(data)
