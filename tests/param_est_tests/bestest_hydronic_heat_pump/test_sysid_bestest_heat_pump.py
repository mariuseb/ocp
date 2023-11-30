#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.mpc import MPC

import numpy as np
import json
import casadi as ca
import ocp
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF
from matplotlib import rc
from pprint import pprint
#from ocp.covar_solve import CovarianceSolver
import os
import matplotlib.pyplot as plt
from ocp.functions import functions
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.prbs import randomizer_prbs_4, randomizer_prbs_6
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_hydronic_gn.json")
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_Tsup_linear.json")
    #cfg_path = os.path.join(opt_config_base, "2R3C_bestest_Tsup_DAE.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_bestest_Tsup_linear_UAnom_1meas.json")
    cfg_path = os.path.join(opt_config_base, "ALG_func_DAE.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = True

    #boptest = Boptest(
    #                  boptest_cfg,
    #                  name="bestest_heat_pump"
    #                 )
    
    sampling_time = "15min"
      
    data_path = os.path.join(get_data_path(), "data_bestest_hydronic.csv")
    
    if GENERATE_DATA:
        
        prbs_6 = randomizer_prbs_6()
        prbs_4 = randomizer_prbs_4()
        # presumed time constants: 15 mins, 4H, 20H
        #prbs = pd.Series(data=np.concatenate((np.array(prbs_6), np.repeat(prbs_6, 4), np.repeat(prbs_4, 80))))
        #prbs = pd.Series(data=np.concatenate((np.repeat(prbs_6, 2), np.repeat(prbs_4, 4))))
        prbs_short = pd.Series(data=(np.repeat(prbs_6, 2)))
        prbs_long = pd.Series(data=np.repeat(prbs_4, 1))
        prbs_short.index *= 3600
        prbs_long.index *= 20*3600
        prbs_short.index = pd.TimedeltaIndex(prbs_short.index, unit="s").round(freq="S")
        prbs_long.index = pd.TimedeltaIndex(prbs_long.index, unit="s").round(freq="S")
        prbs_long = prbs_long.resample(rule="60min").ffill()
        prbs = pd.concat([prbs_short, prbs_long])
        prbs.to_csv("PRBS_1H.csv", index=True)
        #prbs = prbs.resample(rule="1H").mean()
        #prbs.index = range(len(prbs.index))
        # 20 hrs -> concat prbs_4 80 times to get long periods
        #prbs_6 = pd.DataFrame(data=np.repeat(prbs_4, 80))
        """
        prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"), sep=";")
        prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        dt_index = prbs.index
        prbs.Ph /= 5
        prbs = prbs.Ph
        prbs = prbs.round(1)
        prbs = prbs.resample(sampling_time).first()
        """
        # baseline contr5ol for sysid:
        N = len(prbs)
        
        
        #u_measured = []
        count = 98
        for n in range(N):
            u_0 = pd.Series(index=['Tsup'], data=[293.15 + prbs.loc[n]*50])
            u_0["Tset"] = 278.15 + prbs.loc[n]*30
            #u_0["TsetHea"] = 318.15
            frac = count*0.01
            u_0["pum"] = prbs.loc[n]
            u_0["fan"] = prbs.loc[n]*frac
            u_0["ove_hp"] = prbs.loc[n]*frac
            if count > 99:
                count = 1
            count += 1
            _, y_meas, u_meas = boptest.evolve(u=u_0)
            #u_measured.append(u_meas)
            
            
        data = boptest.get_data(tf=N*boptest.h, downsample=False)
        # check
       # ax = data.Ti.plot()
       # data.oveTSetSup_u.plot(ax=ax, color="r", drawstyle="steps-post")
        data.to_csv(data_path)
    
    else:
        data = pd.read_csv(data_path, index_col=0)
    
    # plot: here:
    
    """
    ax = data.Ti.plot(color="r")
    data.oveTSetSup_u.plot(color="y", drawstyle="steps-post", ax=ax)
    data.oveTSetHea_u.plot(color="k", drawstyle="steps-post", ax=ax)
    plt.show()
    
    ax = (data.oveTSetSup_u-data.Ti).plot(color="k")
    ax1 = ax.twinx()
    data.Ph.plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax1)
    ax.legend(["deltaT"])
    ax1.legend(["Ph"])
    plt.show()
    """
    
    y_data = data[:-1]
    
    speed = y_data.ove_hp.sort_values(ascending=False)
    power = y_data["reaQHeaPumCon_y"].loc[speed.index]
    speed.index = range(len(speed.index))
    power.index = range(len(power.index))
    ax = speed.plot()
    ax1 = ax.twinx()
    power.plot(ax=ax1, color="r")
    plt.show()
    
    #y_data = data[:3]
    # when Tsup is below Ti, set Tsup == Ti:
    y_data["Tsup"] = y_data["oveTSetSup_u"]
    ndx = y_data[(y_data.Tsup - y_data.Ti) <= 0].index
    y_data["Tsup"].loc[ndx] = y_data["Ti"].loc[ndx]
    #y_data = data[:4]
    #y_data["y1"] = y_data["Ti"]
    y_data["y1"] = y_data["Ph"]
    #y_data["y2"] = y_data["Ph"]
    
    #y_data["Tsup"].loc[ndx] += 1.01

    """
    ax = (y_data.Tsup-y_data.Ti).plot(color="k")
    ax1 = ax.twinx()
    y_data.Ph.plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax1)
    ax.legend(["deltaT"])
    ax1.legend(["Ph"])
    plt.show()
    """

    
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    #param_guess = ca.DM([0.01,0.01,1E6,5E6,1E6,5,0.004,20])
    #param_guess = ca.DM([0.01,0.1,1E6,5E6,1E5,5,39.1])
    #param_guess = ca.DM([0.01,0.1,0.01,0.01,1E6,5E6,1E5,5])
    #param_guess = ca.DM([0.01,0.01,1E6,1E6,1E4,5,0.01])
    #param_guess = ca.DM([0.01,0.01,1E6,1E7,5,1.24,39.1,0.86])
    #param_guess = ca.DM([0.01,0.01,1E6,1E7,5,1.05,39.10,0.90])
    param_guess = ca.DM([1.05,39.10,0.90])
    param_guess = ca.DM([0.7,10,0.90])
    #param_guess = ca.DM([0.1,0.1,0.1,1E6,1E7,1E5,5,39.1])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    #ubp = ca.DM([0.1,0.1,1E7,1E8,50])
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    lbp[len_p-1] = 0.5
    ubp[len_p-1] = 1
    lbp[len_p-3] = 0.2
    ubp[len_p-3] = 2
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    
    cfg_path = os.path.join(opt_config_base, "ALG_func_DAE.json")
    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) \
                             as param_est:
                             #**kwargs) as param_est:
        
        
        #param_guess[-1] = dT_nom
        #param_guess[-1] = dT_nom
        #param_guess[5] = 250
        #x = ca.DM([293.15, 293.15])
        #u = ca.DM([303.15, 0, 0])
        #z = ca.DM([5000])
        #sol = param_est.integrator.G(x0=z, p=ca.vertcat(x, u, param_guess))
        
        
        #Q = ca.DM.eye(2)
        Q = ca.DM.eye(0)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        
        # set objective manually, here:
        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        eta = param_est.dae.dae.var("eta")
        v1 = v1/eta
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1)
        
        
        sol_rad, params_rad = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )
    
    cfg_path = os.path.join(opt_config_base, "2R2C_envelope.json")
    y_data["y1"] = y_data["Ti"]
        
    param_guess = ca.DM([0.01,0.1,1E6,1E7,5])
    lbp = param_guess*0.01
    ubp = param_guess*100
        
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,    
                             dt=dt,
                             param_guess=param_guess) \
                             as param_est:
                             #**kwargs) as param_est:
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        
        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1)
        
        
        sol_env, params_env = param_est.solve(
                                                y_data,
                                                param_guess,
                                                lbp=lbp,
                                                ubp=ubp,
                                                covar=ca.veccat(Q, R)
                                            )
        
        
    param_guess = ca.DM([0.01,0.01,1E6,1E7,5,1.05,39.10,0.90])
    #param_guess = ca.DM([0.1,0.1,0.1,1E6,1E7,1E5,5,39.1])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    #ubp = ca.DM([0.1,0.1,1E7,1E8,50])
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    lbp[len_p-1] = 0.87
    ubp[len_p-1] = 1
    lbp[len_p-3] = 1
    ubp[len_p-3] = 2

    cfg_path = os.path.join(opt_config_base, "2R2C_func_DAE.json")
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["Ph"]
    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) \
                             as param_est:
                             #**kwargs) as param_est:
        Q = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        v2 = param_est.nlp["x"][(v_inds["a"]+1):v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        eta = param_est.dae.dae.var("eta")
        v2 = v2/eta
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-4*ca.dot(v2, v2)
        
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )
        
    print(params_rad)
    print(params_env)
    print(params)