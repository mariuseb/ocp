#from ast import Param
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
pd.set_option('display.max_columns', 500)
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF, KalmanBucy
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_sha.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF_sha.json")


    """
    Rie    2.362086e-02
    Rea    7.711501e-02
    Ci     2.362108e+06
    Ce     2.362093e+07
    Ai     8.265265e+00
    # pass in config?
    params = ca.DM([0.0015,
                    0.0116,
                    1.33E6,
                    6.64E6,
                    5.53])
    """
    
    params = ca.DM([2.362086e-02,
                    7.711501e-02,
                    2.362108e+06,
                    2.362093e+07,
                    8.265265e+00])
    
    mpc = MPC(
              config=mpc_cfg
              #N=N,
              #dt=dt
              ) # to remove, replace with N
    
    ekf = KalmanBucy(ekf_cfg)
    # set params:
    ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="ZEBLL_sha"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 297.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([295.15, 293.15])
    
    # sim horizon: 2 days
    days = 28
    K = days*24*bounds.t_h

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        sol, u, x0 = mpc.solve(
                               data,
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params
                               )

        data, y_meas, u_meas = boptest.evolve(u=u)
        
        
        #if k == 100:
        #    print(sol)
        
        x0 = ekf.estimate(
                          x0, 
                          y=y_meas, 
                          u=u_meas, 
                          r=data.iloc[0].values
                          )

    #plt.rcParams.update({'font.size': 11})
    
    
    plt.rcParams.update({'font.size': 11})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, solar=True)
    res = boptest.get_data(tf=K*boptest.h).iloc[:-1]
    res.index = dt_index
    
    # separate plot for shading:
    
    #res
    
    #(res.u_sha*5000).plot(ax=axes[1])
    #(res.phi_s).plot(ax=axes[1])
    
    #ax = ekf.df.Ti.plot()
    #res.
    
    plt.show()     