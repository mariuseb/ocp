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
import scipy
from copy import deepcopy
np.set_printoptions(precision=2)

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
    params = params_init = ca.DM([0.0015,
                                  0.0116,
                                  1.33E6,
                                  6.64E6,
                                  5.53])
    

    """
    kwargs = {
              "x_nom": 300,
              "u_nom": 5000,
              "r_nom": 300,
              "y_nom": 300
              }
    """
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": 5000,
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0],
        "y_nom": 12,
        "y_nom_b": 289.15,
        #"slack": True
        "slack": False
    }
    
    
    mpc = MPC(config=mpc_cfg, param_guess=params, **deepcopy(kwargs)) # to remove, replace with N
    #mhe = MHE(config=mhe_cfg, param_guess=params)
    #kwargs["slack"] = False
    mhe = MHE(config=mhe_cfg, param_guess=params, **kwargs)
    
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
    x0 = x_N = np.array([294.05, 293.15])
    
    # sim horizon: 2 days
    days = 2
    K = days*24*bounds.t_h
    
    # mhe settings:
    P0 = ca.DM.eye(7)
    
    # variance of parameters -> low
    # variance of x_hat_-1 -> high
    # order in P0 -> [p, x_hat_-1]
    #P0[:mhe.n_p,:mhe.n_p] *= 1E-32
    #P0[:mhe.n_p,:mhe.n_p] *= 1E32
    #P0[mhe.n_p:, mhe.n_p:] *= 1E32
    #P0 *= 1E-7
    #P0 *= 1E-9
    P0 *= 0
    
    #params_lb = ca.DM([0.001,0.01,1E5,1E6,1])
    #params_ub = ca.DM([0.1,0.1,1E7,1E8,50])
    #params_lb = params*0.7
    #params_ub = params*1.3
    params_lb = params
    params_ub = params
    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        # append reference:
        #ref = np.append(x0[0],ref)
        #data["Ti_ref"] = ref
        
        sol_mpc, u, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params #,
                               #ref=True
                               )

        data, y_meas, u_meas = boptest.evolve(u=u)
        
        if k >= (mhe.N - 1):
            # get labelled data:
            stop_time = (k+1)*boptest.h 
            start_time = stop_time - (mhe.N - 1)*boptest.h
            #start_time = stop_time - mhe.N*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti
            
            if k == (mhe.N - 1):
                try:
                    x_N = ekf.df.iloc[-mhe.N+1].values
                except IndexError:
                    pass
            else:
                x_N = sol_mhe.iloc[1][mhe.x_names].values
                
            sol_mhe, params = mhe.solve(
                                    y_data,
                                    params,
                                    lbp=params_lb,
                                    ubp=params_ub,
                                    covar=ca.veccat(Q, R),
                                    P0=P0,
                                    x_N=x_N,
                                    arrival_cost=True
                                    )
            
            #params = params.values
            #params_lb = params*0.7
            #params_ub = params*1.3

            
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

    plt.rcParams.update({'font.size': 12})

    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    fig.tight_layout()
    plt.show()

    # parameter evolution plot ####:
    mhe.df.index = dt_index[-len(mhe.df):]
    fig, ax = plt.subplots(5, 1, figsize=(8, 10))
    (mhe.df.Ci/3.6E6).plot(ax=ax[0], color="k")  # to kWh/C
    (mhe.df.Ce/3.6E6).plot(ax=ax[1], color="k")  # to kWh/C
    (mhe.df.Rie*1000).plot(ax=ax[2], color="k")  # to K/kW
    (mhe.df.Rea*1000).plot(ax=ax[3], color="k")  # to K/kW
    mhe.df.Ai.plot(ax=ax[4], color="k")

    ax[0].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[1].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[2].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[3].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[4].set_ylabel(r"Area [$m^2$]")

    ax[0].legend([r"$C_i$"])
    ax[1].legend([r"$C_e$"])
    ax[2].legend([r"$R_{ia}$"])
    ax[3].legend([r"$R_{ea}$"])
    ax[4].legend([r"$A_w$"])

    ax[0].axes.get_xaxis().set_visible(False)
    ax[1].axes.get_xaxis().set_visible(False)
    ax[2].axes.get_xaxis().set_visible(False)
    ax[3].axes.get_xaxis().set_visible(False)
    fig.tight_layout()
    plt.show()