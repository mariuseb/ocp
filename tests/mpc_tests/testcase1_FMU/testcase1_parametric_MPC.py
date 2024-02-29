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


if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("configs", "1R1C_MPC.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    # start off with 'very' wrong params:
    params = [3.2e-2, 2.5e6]
    #params = [0.7e-2, 1.3e6]
    params = [1e-2, 1e6]
    #params = [2e-2, 2e6]
    #params = [1e-2, 1e6]
    
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
                "lr": 5e-3,
                #"lr": 1e-6,
                #"lr": 5e-2,
                #"lr": 5e-3,
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
    kwargs["slack"] = True
    cfg = deepcopy(mpc.config)
    cfg["objective"] = "dot(phi_h, phi_h) + 1E2*dot(sl, sl)"
    mpc_orig = MPC(
                    config=cfg,
                    param_guess=params, 
                    functions=functions,
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

    obs = state = x0 = np.array([293.15])
    days = 3
    K = days*24*bounds.t_h # tot timesteps
    rewards = []
    np.random.seed(0)
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

    
    for k in range(K):
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
        if not all(sol["Ti"][0] == obs):
            print("help")
        if k == 15:
            sol_orig, u_0, x0 = mpc_orig.solve(
                                    data[0:mpc.N],
                                    x0=obs,
                                    lbx=lbx,
                                    ubx=ubx,
                                    params=params,
                                    codegen=False
                                    )
            print("yes")
            
        obs = next_obs.copy()
          
        # in trouble:
        if mpc.nlp_solver.stats()["return_status"] != 'Solve_Succeeded':
            print(action)
        
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
    
    
    print(data)
