# %%
#from ast import Param
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
import cProfile as profile
import pstats

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("configs", "1R1C_FMU.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    params = []
    
    """
    No state observer needed for this example.
    
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    """
    
    dae = ca.DaeBuilder('pi', 'FMUs/SimpleRC/SimpleRC.fmutmp')
    dae.disp(True)
    aux = dae.p()
    name_in = ['x','u']
    name_out = ['ode']
    ode = dae.create(
                    'ode', name_in, name_out, {
                                                "verbose": False, 
                                                "aux": aux,
                                                "parallelization": "serial"
                                                }
                     )
    functions["ode"] = ode
    
    kwargs = {
        "x_nom": 30,
        "x_nom_b": 280.15,
        "u_nom": 10000,
        "r_nom": 30,
        "r_nom_b": 280.15,
        #"slack": Trues
        "slack": False
    }
    
    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              functions=functions,
              **deepcopy(kwargs))  # to remove, replace with N
    # 'Old' way of creating a Boptest 'env':
    """
    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1"
                      )
    """
    url = 'http://bacssaas_boptest:5000'
    # Use gym env from Javiers code instead:
    boptest = BoptestGymEnv(boptest_cfg,
                            name                  = "testcase1",
                            url                   = url,
                            bypass_forecast       = True,
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

    x0 = np.array([293.15])
    
    # sim horizon: 2 days
    days = 1
    K = days*24*bounds.t_h

    hist = pd.DataFrame(columns=["pred", "act"])
    rewards = []
    
    prof = profile.Profile()
    prof.enable()
    
    for k in range(K):
        """
        TODO: transform to RL API.
        DONE.
        """
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)   
        sol, u_0, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params,
                               codegen=False
                               )
        #data, y_meas, u_meas = boptest.evolve(u=u)
        """ 
        For 'fair' baselining of MPC and RL,
        round to nearest action as in DQN policy.
        """
        action = [round(u_0["phi_h"], -1)] # -> 21 discrete actions
        # step:
        x0, reward, done, _, _ = boptest.step(action)
        # get forecast in separate step:
        data = boptest.forecast()
        hist.loc[k] = [sol.loc[1].Ti, x0[0]]
        # save rewards:
        rewards.append(reward)
    
    prof.disable()
    
    with open('profile_FMU_MPC_testcase1.txt', 'w+') as stream:
        stats = pstats.Stats(prof, stream=stream).strip_dirs().sort_stats("cumtime")
        stats.print_stats(1000)
    
    plt.rcParams.update({'font.size': 12})
    data = boptest.get_data(tf=K*mpc.dt)
    
    plot_results(
                 boptest,
                 rewards
                 )
    
    print(data)
