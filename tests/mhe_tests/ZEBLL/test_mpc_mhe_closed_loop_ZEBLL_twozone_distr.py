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
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC.json")
    mhe_cfg = os.path.join(opt_config_base, "2R2C_MHE.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF.json")

    # pass in config?
    
    params_N = params_S = ca.DM([0.0015,
                                  0.0116,
                                  1.33E6,
                                  6.64E6,
                                  5.53])/2
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
    """
    
    # two instances for each block 
    mpcN = MPC(config=mpc_cfg) # to remove, replace with N
    mpcS = MPC(config=mpc_cfg) # to remove, replace with N
    mheN = MHE(config=mhe_cfg)
    mheS = MHE(config=mhe_cfg)
    # for first N iterations:
    ekfN = EKF(ekf_cfg)
    ekfS = EKF(ekf_cfg)
    # set params:
    ekfN.set_params(params_N)
    ekfS.set_params(params_S)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="ZEBLL"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpcN.N
    #dt = mpc.dt
    #lb_night = 289.15
    #ub_night = 301.15
    #lb_day = 293.15
    #ub_day = 296.15
    #lb_night = {"Ti1": 289.15, "Ti2": 289.15}
    #ub_night = {"Ti1": 301.15, "Ti2": 301.15}
    #lb_day = {"Ti1": 293.15, "Ti2": 293.15}
    #ub_day = {"Ti1": 296.15, "Ti2": 296.15}
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    # bounds equal for both zones
    bounds = Bounds(mpcN.dt,
                    mpcN.dae.x,
                    mheN.y_names,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0_N = x0_S = np.array([295.05, 293.15])
    
    # sim horizon: 2 days
    days = 14
    K = days*24*bounds.t_h
    
    # mhe settings:
    P0 = ca.DM.eye(7)
    #lbp = ca.DM([0.001,0.001,1E5,1E5,0.1,0.001,0.001,0.001,0.001,1E5,1E5,0.1])
    #ubp = ca.DM([10,10,1E8,1E8,50,10,10,10,10,1E8,1E8,50])
    #Q = ca.DM.eye(4)
    #R = ca.DM.eye(2)
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,0.1,1E7,1E8,50])
    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)

    # north zone map:
    north_map = {"phi_h2": "phi_h", "Ti2": "Ti"}
    south_map = {"phi_h": "phi_h", "Ti1": "Ti"}


    for k in range(K):
        
        lbx, ubx = bounds.get_bounds(k, mpcN.N)
        
        # two solves:
        sol_N, u_N, x0_N = mpcN.solve(
                                        data,
                                        x0=x0_N,
                                        lbx=lbx,
                                        ubx=ubx,
                                        params=params_N
                                        )
        sol_S, u_S, x0_S = mpcN.solve(
                                        data,
                                        x0=x0_S,
                                        lbx=lbx,
                                        ubx=ubx,
                                        params=params_S
                                        )
        
        u_N.index = ["phi_h2"]
        
        u = pd.concat([u_N, u_S])
        data, y_meas, u_meas = boptest.evolve(
                                              u=u,
                                              y_as_array=False,
                                              u_as_array=False
                                              )
        
        if k >= mheN.N:
            # get labelled data:
            stop_time = k*boptest.h
            start_time = stop_time - (mheN.N-1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            
            # split data
            
            rest = y_data[["Ta", "phi_s"]]
            
            y_data_N = y_data[list(north_map.keys())]
            y_data_S = y_data[list(south_map.keys())]
            
            y_data_N = pd.merge(y_data_N, rest, left_index=True, right_index=True)
            y_data_S = pd.merge(y_data_S, rest, left_index=True, right_index=True)
            
            y_data_N = y_data_N.rename(columns=north_map)
            y_data_S = y_data_S.rename(columns=south_map)
            
            
            y_data_N["y1"] = y_data_N.Ti
            y_data_S["y1"] = y_data_S.Ti
            #y_data["y2"] = y_data.Ti2
            
            if k == mheN.N:
                x_N_N = ekfN.df.iloc[-mheN.N].values
                x_N_S = ekfS.df.iloc[-mheS.N].values
            else:
                x_N_N = solN.iloc[1][mheN.x_names].values
                x_N_S = solS.iloc[1][mheS.x_names].values
                
            solN, params_N = mheN.solve(
                                    y_data_N,
                                    params_N,
                                    lbp=params_N*0.5,
                                    ubp=params_N*1.5,
                                    covar=ca.veccat(Q, R),
                                    P0=P0,
                                    x_N=x_N_N
                                    )
            params_N = params_N.values
                
            solS, params_S = mheS.solve(
                                    y_data_S,
                                    params_S,
                                    lbp=params_S*0.5,
                                    ubp=params_S*1.5,
                                    covar=ca.veccat(Q, R),
                                    P0=P0,
                                    x_N=x_N_S
                                    )
            params_S = params_S.values
            
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
            
            x0_N = ekfN.estimate(
                              x0_N, 
                              y=np.array(y_meas["TRoo2_y"]), 
                              u=np.array(u_meas["oveActN"]), 
                              r=data.iloc[0].values
                              )
            
            x0_S = ekfS.estimate(
                              x0_S, 
                              y=np.array(y_meas["TRoo1_y"]),
                              u=np.array(u_meas["oveActS"]), 
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
        l3 = ax.plot(dt_index, (bounds_plt[("lb", "Ti")]-273.15), color="k", drawstyle="steps", label="$T_{i}^{lb}$")
        l4 = ax.plot(dt_index, (bounds_plt[("ub", "Ti")]-273.15), color="k", drawstyle="steps", label="$T_{i}^{ub}$")
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