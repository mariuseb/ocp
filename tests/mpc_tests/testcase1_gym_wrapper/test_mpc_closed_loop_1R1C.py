#from ast import Param
from ocp.mpc import MPC
import numpy as np
import matplotlib.pyplot as plt
from ocp.boptest_api_old import Boptest
from pprint import pprint
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from copy import deepcopy
from pprint import pprint

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    mpc_cfg = os.path.join("mpc_configs", "1R1C_MPC.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    
    params = np.array([
                    0.01,
                    1E6
                    ])
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 5000,
        "r_nom": 12,
        "r_nom_b": 289.15,
        "y_nom": 12,
        "y_nom_b": 289.15,
        "slack": False
        #"slack": False
    }
    
    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1"
                      )
    # first forecast:
    data = boptest.get_forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ["Ti"],
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([293.15])
    days = 2
    K = days*24*bounds.t_h
    
    for k in range(K):
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        sol, u, x0, raw_sol = mpc.solve(
                                        data[0:mpc.N],
                                        x0=x0,
                                        lbx=lbx,
                                        ubx=ubx,
                                        params=params,
                                        return_raw_sol=True,
                                        codegen=True
                                        )
        data, y_meas, u_meas = boptest.evolve(u=u)
        x0 = y_meas
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    plt.show()    
    fig.tight_layout()
