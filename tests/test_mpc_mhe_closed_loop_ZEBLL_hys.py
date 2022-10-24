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
from matplotlib import rc
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    mpc_cfg = "2R2C_MPC.json"
    boptest_cfg = "ZEBLL_config.json"
    mhe_cfg = "2R2C_MHE.json"
    ekf_cfg = "2R2C_EKF.json"

    # pass in config?
    """
    Using PRBS:
    params = ca.DM([0.00100015, 
                    0.0129768, 
                    1.32308e+06,
                    9.54074e+07,
                    2.19846])
    """
    
    # with hysteresis base-control:
    
    params = ca.DM([0.00100015, 
                    0.0129768, 
                    1.32308e+06,
                    9.54074e+07,
                    2.19846])
    
    #params = ca.DM([0.01,0.1,1E6,1E7,2]) 
    #params = ca.DM([0.01,0.01,1E6,1E6,1]) 
    
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
    days = 14
    K = days*24*bounds.t_h
    
    # mhe settings:
    P0 = ca.DM.eye(7)*1E32
    # Ce
    #P0[3,3] = 1E32
    #P0[4,4] = 1E32
    #P0[5,5] = 1E32
    #P0[6,6] = 1E32
    #P0[0,0] = 1
    #P0[1,1] = 1
    #P0[2,2] = 1
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,0.1,1E7,1E8,50])
    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)

    for k in range(K):
        
        lbx, ubx = bounds.get_bounds(k, mpc.N)
        
        sol_mpc, u, x0 = mpc.solve(
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
                #params_lb = params*0.999999
                #params_ub = params*1.000001
                #params_lb = params*0.99
                #params_ub = params*1.01
                
                #bds = pd.DataFrame(columns=["lb", "ub"])
                
            else:
                x_N = sol_mhe.iloc[1][mhe.x_names].values
            
            #params_lb = params*0.99
            #params_ub = params*1.01
            
            """
            if k > 2*mhe.N: # "burn-in"
            
                if params_lb[3] + params[3]*0.0005 < params[3]:
                    params_lb[3] = params_lb[3] + params[3]*0.0005
                    bds.loc[k, "lb"] = np.array(params_lb[3])[0][0]
                else:
                    params_lb[3] = params[3]
                    
                if params_ub[3] - 0.0005*params[3] > params[3]:
                    params_ub[3] = params_ub[3] - 0.0005*params[3]
                    bds.loc[k, "ub"] = np.array(params_ub[3])[0][0]
                else:
                    params_ub[3] = params[3]

            params_lb[3] = params[3]*0.5
            params_ub[3] = params[3]*1.5
            """
            #params_lb = params*0.999999
            #params_ub = params*1.000001
            
            params_lb = params*0.7
            params_ub = params*1.3
            
            # let window area drift more:
            #params_lb[4] = params[4]*0.8
            #params_ub[4] = params[4]*1.2
            # for 
            
            # let Ce drift for ~1 week:
            """
            if k < 7*24*bounds.t_h:
                params_lb[3] = params[3]*0.99
                params_ub[3] = params[3]*1.01
            else:
                params_lb[3] = params[3]*0.999999
                params_ub[3] = params[3]*1.000001
            """  
            # let Ai drift:
            #params_lb[4] = params[4]*0.99
            #params_ub[4] = params[4]*1.01
            
            sol_mhe, params = mhe.solve(
                                        y_data,
                                        params,
                                        lbp=params_lb,
                                        ubp=params_ub,
                                        covar=ca.veccat(Q, R),
                                        P0=P0,
                                        x_N=x_N
                                        )
            params = params.values
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
            
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
    ax = fig.add_subplot(111)
    
    # colors
    colors = iter(plt.cm.rainbow(np.linspace(0, 1, 5)))
    #for i in range(n):
    #c = next(colors)
    #plt.plot(x, y, c=c)
    
    dt_index = pd.Timestamp("2020-01-01 00:00") + res.index
    
    #l1 = res.Ti.plot(ax=ax, color="k")
    #l1 = ax.plot(res.index, res.Ti, color="k", label="$T_i$")
    l1 = ax.plot(dt_index, (res.Ti-273.15), color=next(colors), label="$T_i$")
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
    
    #plt.rcParams.update({'font.size': 14})
    
    #### parameter evolution plot ####:
    mhe.df.index = dt_index[-len(mhe.df):]
    fig, ax = plt.subplots(5,1, figsize=(8,10))
    (mhe.df.Ci/3.6E6).plot(ax=ax[0], color="k") # to kWh/C
    (mhe.df.Ce/3.6E6).plot(ax=ax[1], color="k") # to kWh/C
    (mhe.df.Rie*1000).plot(ax=ax[2], color="k") # to K/kW
    (mhe.df.Rea*1000).plot(ax=ax[3], color="k") # to K/kW
    mhe.df.Ai.plot(ax=ax[4], color="k")
    
    ax[0].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[1].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[2].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[3].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[4].set_ylabel(r"Area [$m^2$]")
    
    ax[0].legend([r"$C_i$"])
    ax[1].legend([r"$C_e$"])
    ax[2].legend([r"$R_{ie}$"])
    ax[3].legend([r"$R_{ea}$"])
    ax[4].legend([r"$A_w$"])
    
    ax[0].axes.get_xaxis().set_visible(False)
    ax[1].axes.get_xaxis().set_visible(False)
    ax[2].axes.get_xaxis().set_visible(False)
    ax[3].axes.get_xaxis().set_visible(False)
    
    plt.show()