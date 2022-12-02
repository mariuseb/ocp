#from ast import Param
from ocp.mpc import MPC
from ocp.mhe import MHE
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF
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
    
    mpc_cfg = os.path.join(opt_config_base, "5R4C_MPC.json")
    mhe_cfg = os.path.join(opt_config_base, "5R4C_MHE.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "5R4C_EKF.json")

    # pass in config?
    """
    params = params_init = ca.DM([0.0015,
                                  0.0116,
                                  1.33E6,
                                  6.64E6,
                                  5.53])
    """
    params = params_init = ca.DM([1.849250e-03,
                                2.272471e-02,
                                1.635863e+06,
                                5.224896e+06,
                                2.614794e+00,
                                2.152017e-03,
                                2.313056e-02,
                                1.637696e+06,
                                4.246618e+06,
                                2.086985e+00])
    
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
    #lb_night = 289.15
    #ub_night = 301.15
    #lb_day = 293.15
    #ub_day = 296.15
    lb_night = {"Ti1": 289.15, "Ti2": 289.15}
    ub_night = {"Ti1": 301.15, "Ti2": 301.15}
    lb_day = {"Ti1": 293.15, "Ti2": 293.15}
    ub_day = {"Ti1": 296.15, "Ti2": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    mhe.y_names,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([295.05, 293.15, 295.05, 293.15])
    
    # sim horizon: 2 days
    days = 14
    K = days*24*bounds.t_h
    
    # mhe settings:
    P0 = ca.DM.eye(7)
    lbp = ca.DM([0.001,0.001,1E5,1E5,0.1,0.001,0.001,0.001,0.001,1E5,1E5,0.1])
    ubp = ca.DM([10,10,1E8,1E8,50,10,10,10,10,1E8,1E8,50])
    Q = ca.DM.eye(4)
    R = ca.DM.eye(2)

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
            y_data["y1"] = y_data.Ti1
            y_data["y2"] = y_data.Ti2
            
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

    """
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
    """
    
    plt.rcParams.update({'font.size': 11})
    
    res = boptest.get_data(tf=K*boptest.h)
    fig = plt.figure(figsize=(10,6))
    #ax = fig.add_subplot(111)
    axes = []
    ax1 = fig.add_subplot(211)
    ax2 = fig.add_subplot(212)
    axes.append(ax1)
    axes.append(ax2)
    
    # colors
    colors = iter(plt.cm.rainbow(np.linspace(0, 1, 5)))
    #for i in range(n):
    #c = next(colors)
    #plt.plot(x, y, c=c)
    
    dt_index = pd.Timestamp("2020-01-01 00:00") + res.index
    
    temps = ["Ti1", "Ti2"]
    
    for temp, ax in zip(temps, axes):
        l1 = ax.plot(dt_index, (res[[temp]]-273.15), color=next(colors), label="$T_i$")
        ax1 = ax.twinx()
        #l2 = res.phi_h.plot(ax=ax1, color="k", linestyle="--")
        #l2 = ax1.plot(res.index, res.phi_h, color="k", linestyle="dashed", label="$\phi_h$")
        l2 = ax1.plot(dt_index, res.phi_h, color=next(colors), label="$\phi_h$")
        
        #ax.legend([l1, l2], , loc=0)
        ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d %H:%M'))
        fig.autofmt_xdate()
        #ax.legend(["Ti"])
        #ax1.legend(["phi_h"])
        # plot bounds:
        #bounds_plt = pd.concat([bounds]*days)
        bounds_plt = bounds.get_full(days)
        bounds_plt.index = res.index
        #bounds_plt[("lb", "Ti")].plot(ax=ax, drawstyle="steps")
        #bounds_plt[("ub", "Ti")].plot(ax=ax, drawstyle="steps")
        l3 = ax.plot(dt_index, (bounds_plt[("lb", temp)]-273.15), color="k", drawstyle="steps", label="$T_{i}^{lb}$")
        l4 = ax.plot(dt_index, (bounds_plt[("ub", temp)]-273.15), color="k", drawstyle="steps", label="$T_{i}^{ub}$")
        lns = l1+l2+l3+l4
        labs = [l.get_label() for l in lns]
        ax.legend(lns, labs, loc='upper center', ncol=4)
        _min, _max = ax.get_ylim()
        ax.set_ylim([_min, _max+1])
        _min, _max = ax1.get_ylim()
        ax1.set_ylim([_min, _max+1000])
        
        ax.set_ylabel(r"Temperature [$^\circ$C]")
        ax1.set_ylabel(r"Power [W]")
        
    fig.tight_layout()
    plt.show()    
    print(res)