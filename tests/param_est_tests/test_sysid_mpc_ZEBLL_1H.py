#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.mpc import MPC

import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF, KalmanBucy
from matplotlib import rc
import os
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    data_path = get_data_path()
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF.json")
    prbs_path = os.path.join(data_path, "inputPRBS1.csv")

    """
    From PRBS-sysid:
    params = ca.DM([0.0015,
                    0.0116,
                    1.33E6,
                    6.64E6,
                    5.53])
    """
    params = ca.DM([0.00165302, 0.0115456, 1.38904e+06, 6.72582e+06, 4.61678])
    
    mpc = MPC(
              config=mpc_cfg
              #N=N,
              #dt=dt
              ) # to remove, replace with N
    
    ekf = KalmanBucy(ekf_cfg)
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
    N = days*24*bounds.t_h - 12
    #N = 5
    #N = 4
    
    prbs = pd.read_csv(prbs_path, sep=";")
    index = pd.to_datetime(prbs.t, origin="2020-01-01 00:00", unit="h").round("s")
    prbs.index = index
    U = prbs.Ph/5
    U = pd.DataFrame(U.resample(rule="1H").mean().round())
    U.columns = ["phi_h"]
    U["u_sha"] = U["phi_h"]
    #U = pd.DataFrame(data=np.tile(U.values, 2), index=U.index, columns=["phi_h", "u_sha"])
    _u = pd.DataFrame(index=U.index, columns=["phi_h", "u_sha"])
    U.loc[:, "phi_h"] *= 3000
    # baseline control for sysid:
    for n in range(N):
        u = U.iloc[n]
        #u.loc["phi_h"] *= 3000
        data, y_meas, u_meas = boptest.evolve(u=u)
        _u.iloc[n] = u_meas
        #if not (u.values == u_meas)[0]:
        #    print(u_meas)
        
    
    ############################## sysid ###############################
    
    #cfg_path = os.path.join(get_opt_config_path(), "2R2C_sha.json")
    cfg_path = os.path.join(get_opt_config_path(), "2R2C.json")
    y_data = boptest.get_data(tf=N*boptest.h) #, downsample=False)
    
    
    fig, ax = plt.subplots(1,1)
    ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d %H:%M'))
    fig.autofmt_xdate()
    #l1 = y_data.phi_h.plot(ax=ax, drawstyle="steps-post", label="$\phi_{s}$")
    l1 = ax.plot(index[0:-1:12][0:133], y_data.phi_h, drawstyle="steps-post", label="$\phi_{h}$")
    ax1 = ax.twinx()
    #l2 = (y_data.Ti-273.15).plot(ax=ax1, color="m", label="$\Ti_{i}$")
    l2 = ax1.plot(index[0:-1:12][0:133], (y_data.Ti-273.15), color="m", label="$T_{i}$")
    ax1.set_ylabel(r"Temperature [$^\circ$C]")
    ax.set_ylabel(r"Power [W]")
    
    lns = l1 + l2
    labs = [l.get_label() for l in lns]
    ax.legend(lns, labs, loc='upper center', ncol=2)
    
    _min, _max = ax.get_ylim()
    ax.set_ylim([_min, _max*1.2])
    _min, _max = ax1.get_ylim()
    ax1.set_ylim([_min, _max*1.2])
    plt.show()
    
    """
    phi_h = y_data.phi_h.resample(rule="15min").mean()
    Ti = y_data.Ti.resample(rule="15min").asfreq()
    
    _u = _u.iloc[:N]
    #_u.index = y.index
    #y_data.index = _u.index
    phi_h.index = _u.index
    Ti.index = _u.index
    
    
    fig, ax = plt.subplots(1,1)
    ax.plot(_u.index, _u.values, drawstyle="steps")
    ax.plot(_u.index, phi_h.values, drawstyle="steps", linestyle="dashed")
    plt.show()
    """
    #ax = y_data.phi_h.plot()
    #u.phi_h.plot(ax=ax)
    
    #y = y_data[list(boptest.y.keys())][1:]
    #y_data = y_data.iloc[:-1]
    #y.index = y_data.index
    #y_data[list(boptest.y.keys())] = y
    #y_data.index = range(0, mpc.dt*N, mpc.dt)
    #y_data = y_data.iloc[:-1]
    #y_data.index = _u.index
    #ax = _u.phi_h.plot()
    #y_data.phi_h.iloc[:-1].plot(ax=ax)                downsample=True,
    
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
    days = 7
    K = days*24*bounds.t_h
    # estimated state at sysid horizon end:
    #x0 = sol.iloc[-1][mpc.dae.x].values
    
    boptest = Boptest(
                        boptest_cfg,
                        name="ZEBLL"
                     )
    # guess:
    x0 = np.array([294.05, 293.15])
    _y = pd.DataFrame(columns=["y_meas"])
    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        #if k > 19:
        #    print(lbx)
        
        sol, u, x0 = mpc.solve(
                               data,
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params
                               )

        data, y_meas, u_meas = boptest.evolve(u=u)
        _y.loc[k+1] = y_meas
        
        #if k > 85:
        #    bounds_plt = bounds.get_full(days)
        #    print(sol)
        
        x0 = ekf.estimate(
                          x0, 
                          y=y_meas, 
                          u=u_meas, 
                          r=data.iloc[0].values
                          )
    
       
    plt.rcParams.update({'font.size': 11})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds)
    plt.show()       