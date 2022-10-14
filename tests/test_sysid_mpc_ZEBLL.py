#from ast import Param
from sysid.param_est import MPC, ParameterEstimation
import numpy as np
import json
import casadi as ca
import sysid.dae as dae
import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from boptest_api import Boptest
from pprint import pprint
from sysid.filters import EKF
from utils import Bounds
    

if __name__ == "__main__":
    
    mpc_cfg = "2R2C_MPC.json"
    boptest_cfg = "ZEBLL_config.json"
    ekf_cfg = "2R2C_EKF.json"

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
    lb_night = 289.15
    ub_night = 301.15
    lb_day = 293.15
    ub_day = 296.15
    
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
    
    cfg_path = "2R2C.json"
    y_data = boptest.get_data(tf=N*boptest.h) #, downsample=False)
    y_data.index = range(0, mpc.dt*N, mpc.dt)
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
    
    ekf.set_params(params)    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    days = 14
    K = days*24*bounds.t_h
    # estimated state at sysid horizon end:
    x0 = sol.iloc[-1][mpc.dae.x].values
        
    for k in range(K):
        
        lbx, ubx = bounds.get_bounds(k, mpc.N)
        
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
    
    # get data only for MPC operation:s
    res = boptest.get_data(ts=(N+1)*boptest.h, tf=(K+N)*boptest.h)
    ax = res.Ti.plot(color="k")
    ax1 = ax.twinx()
    res.phi_h.plot(ax=ax1, color="k", linestyle="--")
    ax.legend(["Ti"])
    ax1.legend(["phi_h"])
    # plot bounds:
    #bounds_plt = pd.concat([bounds]*days)
    bounds_plt = bounds.get_full(days)
    bounds_plt.index = res.index
    bounds_plt[("lb", "Ti")].plot(ax=ax, drawstyle="steps")
    bounds_plt[("ub", "Ti")].plot(ax=ax, drawstyle="steps")
    
    plt.show()    
    #assert(ca.norm_inf(p_sol-true_params)<1e-8)