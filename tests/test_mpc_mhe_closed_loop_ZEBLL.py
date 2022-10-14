#from ast import Param
from sysid.param_est import MPC, MHE
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
    mhe_cfg = "2R2C_MHE.json"
    ekf_cfg = "2R2C_EKF.json"

    # pass in config?
    params = params_init = ca.DM([0.0015,
                                  0.0116,
                                  1.33E6,
                                  6.64E6,
                                  5.53])
    
    mpc = MPC(config=mpc_cfg) # to remove, replace with N
    mhe = MHE(config=mhe_cfg)
    # for first N iterations:
    ekf = EKF(ekf_cfg)
    # set params:
    ekf.set_params(params)
    
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
                    mhe.y_names,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([295.05, 293.15])
    
    # sim horizon: 2 days
    days = 7
    K = days*24*bounds.t_h
    
    # mhe settings:
    P0 = ca.DM.eye(7)
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,0.1,1E7,1E8,50])
    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)

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
        
        if k >= mhe.N:
            # get labelled data:
            stop_time = k*boptest.h
            start_time = stop_time - (mhe.N-1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti
            
            if k == mhe.N:
                x_N = ekf.df.iloc[-mhe.N].values
            else:
                x_N = sol.iloc[1][mhe.x_names].values
                
            sol, params = mhe.solve(
                                    y_data,
                                    params,
                                    lbp=params*0.5,
                                    ubp=params*1.5,
                                    covar=ca.veccat(Q, R),
                                    P0=P0,
                                    x_N=x_N
                                    )
            params = params.values
            
            ### EKF update of P0 ###
            # (should be N time steps lagged?)
            """
            x0 = ekf.estimate(
                              x0, 
                              y=y_meas, 
                              u=u_meas, 
                              r=data.iloc[0].values
                              )
            P0 = ekf.P_prev
            """
            #########################
        else:
            
            x0 = ekf.estimate(
                              x0, 
                              y=y_meas, 
                              u=u_meas, 
                              r=data.iloc[0].values
                              )

    res = boptest.get_data(tf=K*boptest.h)
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