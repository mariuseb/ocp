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
from ocp.filters import EKF
from matplotlib import rc
from ocp.covar_solve import CovarianceSolver
import os
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    cfg_path = os.path.join(opt_config_base, "5R4C_full.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = False

    boptest = Boptest(
                      boptest_cfg,
                      name="ZEBLL"
                      )
    
    sampling_time = "15min"
      
    data_path = os.path.join(get_data_path(), "data_ZEBLL_PRBS_twozone.csv")
    
    if GENERATE_DATA:
        
        prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"), sep=";")
        prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        prbs.Ph /= 5
        prbs = prbs.Ph
        prbs = prbs.resample(sampling_time).first()
        prbs.index = range(len(prbs.index))
        # baseline control for sysid:
        N = len(prbs)
        
        
        #u_measured = []
        for n in range(N):
            u_0 = pd.Series(index=['phi_h', 'phi_h2'], data=[prbs.loc[n]*3000, prbs.loc[n]*3000])
            _, y_meas, u_meas = boptest.evolve(u=u_0)
            #u_measured.append(u_meas)
            
            
        data = boptest.get_data(tf=N*boptest.h, downsample=False)
        data_path = os.path.join(get_data_path(), "data_ZEBLL_PRBS_twozone.csv")
        data.to_csv(data_path)
        
    else:
        
        data = pd.read_csv(data_path)
        # dt is 30 seconds:
        data.index = pd.TimedeltaIndex(data["Unnamed: 0"])
        data.index.name = "time"

        # try with 15 min, 5 min anything that might give a decent model
        # heat: resample with mean, i.e. integration
        # temperatures, solar irr: instantaneous sampling
        
    downsample = True
    #sampling_time = "15min"
    dt = 900 #?
    
    #u_meas = pd.DataFrame(np.array(u_measured))
    
        
    if downsample:
        
        heat = data[["phi_h", "phi_h2", "phi_s"]]
        heat = heat.resample(sampling_time).mean()

        rest = data[["Ti1", "Ti2", "Ta"]]
        rest = rest.resample(sampling_time).first()

        y_data = pd.merge(heat, rest, left_index=True, right_index=True)
        y_data["y1"] = y_data.Ti1
        y_data["y2"] = y_data.Ti2
        y_data.index = np.arange(0, len(y_data)*900, 900)
        data_path = os.path.join(get_data_path(), "data_ZEBLL_15min_PRBS_twozone.csv")
        y_data.to_csv(data_path)
        
    else:
        
        y_data = data
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*30, 30)
    
    y_data.index = range(0, dt*len(y_data), dt)
    y_data["y1"] = y_data.Ti1
    y_data["y2"] = y_data.Ti2
    
    #y_data = y_data.iloc[0:100]
    
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    
    # rewrite: # full or reduced...s
    #param_guess = ca.DM([0.1,0.1,1E6,1E6,2,0.1,0.1,1E6,1E6,2])
    #lbp = ca.DM([0.001,0.001,1E5,1E5,0.1,0.001,0.001,1E5,1E5,0.1])
    #ubp = ca.DM([10,10,1E8,1E8,50,10,10,1E8,1E8,50])
    param_guess = ca.DM([0.1,0.1,1E6,1E6,2,0.1,0.1,0.1,0.1,1E6,1E6,2])
    lbp = ca.DM([0.001,0.001,1E5,1E5,0.1,0.001,0.001,0.001,0.001,1E5,1E5,0.1])
    ubp = ca.DM([10,10,1E8,1E8,50,10,10,10,10,1E8,1E8,50])
    
    param_est = ParameterEstimation(config=cfg_path, N=N, dt=dt, param_guess=param_guess)
    #param_est = ParameterEstimation(config=cfg_path, N=N, dt=dt)
        
    Q = ca.DM.eye(4)
    R = ca.DM.eye(2)
    # provide Q, R in solve here:
    # provide lb, ub for p here:
    #lbx = np.array([y_data[["y1", "y2"]]])s
    lbx = np.repeat((y_data[["y1", "y2"]].values - 10), 2)
    ubx = np.repeat((y_data[["y1", "y2"]].values + 10), 2)
    
    
    sol, params = param_est.solve(
                                  y_data,
                                  param_guess,
                                  lbp=lbp,
                                  ubp=ubp,
                                  lbx=lbx,
                                  ubx=ubx,
                                  covar=ca.veccat(Q, R)
                                  )
    
    
    # simulate to find true residuals:
    w = param_est.x_gaps(sol[param_est.x_names].values.flatten(),
                         0,
                         y_data[param_est.u_names].values.flatten(),
                         params.values,
                         0,
                         0,
                         y_data[param_est.y_names].values.flatten(),
                         0)
    
    v = param_est.y_gaps(sol[param_est.x_names].values.flatten(),
                         0,
                         y_data[param_est.u_names].values.flatten(),
                         params.values,
                         0,
                         0,
                         y_data[param_est.y_names].values.flatten(),
                         0)
    
    w = np.array(w)
    v = np.array(v)
    
    W = pd.DataFrame(w.T, columns = param_est.w_names)
    V = pd.DataFrame(v.T, columns = param_est.v_names)
    
    W_est = np.cov(w)
    
    import scipy as scipy
    w_sample = scipy.linalg.sqrtm(W_est).dot(np.random.randn(4, N))
    
    w_sample_df = pd.DataFrame(w_sample.T, columns = param_est.w_names)
    
    # compare w to w_sample:
    ax = W.w1.plot(color="k", drawstyle="steps")
    w_sample_df.w1.plot(color="r", drawstyle="steps")
    plt.show()
    
    W_sample = np.cov(w_sample)
    
    _v = sol[["v1", "v2"]].values.T
    _w = sol[["w1", "w2", "w3", "w4"]].values.T
    
    # plot y1 against Ti1
    ax = sol.Ti1.plot(color="r")
    ax.plot(y_data.y1, color="b")
    ax = sol.Ti2.plot(color="r")
    ax.plot(y_data.y2, color="b")
    
    covar_est = CovarianceSolver(v, w)
    
    #R, Q = covar_est.solve(warmstart=True,
    #                       R=np.array(R),
    #                       Q=np.array(Q))
    
    R, Q = covar_est.solve()
    
    pprint(R)
    pprint(Q)
    
    sol, params_sec = param_est.solve(
                                      y_data,
                                      params,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      covar=ca.veccat(Q, R)
                                      )
            
    pprint(params_sec)