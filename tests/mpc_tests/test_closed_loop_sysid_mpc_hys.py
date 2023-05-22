#from ast import Param
#from sysid.param_est import MPC, ParameterEstimation
from ocp.mpc import MPC
from ocp.filters import EKF
from ocp.param_est import ParameterEstimation
import numpy as np
import json
import casadi as ca
import os
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
rc('mathtext', default='regular')
import matplotlib.pyplot as plt
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    """
    From PRBS-sysid:
    params = ca.DM([0.0015,
                    0.0116,
                    1.33E6,
                    6.64E6,
                    5.53])
    """
    mpc = MPC(
              config=mpc_cfg
              #N=N,
              #dt=dt
              ) # to remove, replace with N
    
    ekf = EKF(ekf_cfg)
    # set params:
    #ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="ZEBLL"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    x0 = np.array([295.05, 293.15])
    
    # sim horizon: 6 days, same as PRBS
    days = 6
    N = days*24*bounds.t_h

    # baseline control for sysid:
    for n in range(N):
        data, y_meas, u_meas = boptest.evolve()
    
    ############################## sysid ###############################
    
    cfg_path = os.path.join(opt_config_base, "2R2C.json")
    y_data = boptest.get_data(tf=N*boptest.h) #, downsample=False)
    y_data.index = range(0, mpc.dt*(N+1), mpc.dt)
    y_data["y1"] = y_data.Ti
    #y_data.to_csv("data/data_ZEBLL_hysteresis.csv", index=True)
    # columns:
    
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    param_guess = ca.DM([0.01,0.1,1E6,1E7,2])
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,0.1,1E7,1E8,50])
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )
        
    ############################### MPC ###############################
    # set params of ekf:
    params = ca.DM(params.values)
    
    ekf.set_params(params)   
    
    ###################### restart emulator ###########################
    boptest = Boptest(
                      boptest_cfg,
                      name="ZEBLL"
                      )
    # first forecast:
    data = boptest.forecast()
    ###################################################################
    # init state:
    x0 = np.array([294.05, 293.15])
    
    days = 7
    K = days*24*bounds.t_h
    # estimated state at sysid horizon end:
    #x0 = sol.iloc[-1][mpc.dae.x].values
        
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
        
        x0 = ekf.estimate(
                          x0, 
                          y=y_meas, 
                          u=u_meas, 
                          r=data.iloc[0].values
                          )
    
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    fig.tight_layout()
    plt.show()