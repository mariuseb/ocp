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
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC.json")
    mhe_cfg = os.path.join(opt_config_base, "2R2C_MHE.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF.json")

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
    ekf = KalmanBucy(ekf_cfg)
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
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    mhe.y_names,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([294.05, 293.15])
    
    # sim horizon: 2 days
    days = 14
    K = days*24*bounds.t_h
    
    # mhe settings:
    #P0 = ca.DM.eye(7)*1E-16
    # Ce
    #P0[3,3] = 1E32
    #P0[4,4] = 1E32
    #P0[5,5] = 1E32
    #P0[6,6] = 1E32
    #P0[0,0] = 1
    #P0[1,1] = 1
    #P0[2,2] = 1
    params_lb = ca.DM([0.001,0.01,1E5,1E6,1])
    params_ub = ca.DM([0.1,0.1,1E7,1E8,50])
    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        #ref = np.append(x0[0],ref)
        #data["Ti_ref"] = ref
        
        sol, u, x0 = mpc.solve(
                               data,
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params
                               #ref=True
                               )

        data, y_meas, u_meas = boptest.evolve(u=u)
        
        # need to leave out first (non-estimated from EKF)
        if k >= (mhe.N - 1):
            # get labelled data:
            #stop_time = (k+1)*boptest.h 
            stop_time = (k+1)*boptest.h 
            start_time = stop_time - (mhe.N - 1)*boptest.h
            #start_time = stop_time - mhe.N*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti
            
            if k == (mhe.N - 1):
                x_N = ekf.df.iloc[-mhe.N+1].values
            else:
                x_N = sol_mhe.iloc[1][mhe.x_names].values
                
            
            #if k > (27+94):
            #    print(y_data)
            
            sol_mhe, params = mhe.solve(
                                        y_data,
                                        params,
                                        lbp=params_lb,
                                        ubp=params_ub,
                                        covar=ca.veccat(Q, R),
                                        arrival_cost=False,
                                        x_N=x_N
                                        )
            
            params = params.values
            
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
            
            params_lb = params*0.7
            params_ub = params*1.3
            
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
    
    #dt_index = pd.Timestamp("2020-01-01 00:00") + res.index
    
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
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