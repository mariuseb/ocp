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
from ocp.functions import functions
import os
import re
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    data_path = get_data_path()
    
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_air_ufan_1meas.json")
    cfg_path = os.path.join("configs", "3R2C_bestest_air_ufan_1meas.json")
    #cfg_path = os.path.join(opt_config_base, "3R2C_bestest_air_ufan_HVAC_env.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_air.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_air.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_func_DAE.json")
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_air_oneway.json")
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_air_oneway.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    prbs_path = os.path.join(data_path, "inputPRBS1.csv")

    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_air"
                      )

    GENERATE_DATA = False
    PLOT_DATA = False
    sampling_freq = "30s"
    data_path = os.path.join("data", "data_bestest_air_simple_normal_op.csv")
    repeats = 1
    N = 6*24*4*repeats - 24*repeats
    #N = 10
    
    if GENERATE_DATA:
        prbs = pd.read_csv(prbs_path, sep=";")
        index = pd.to_datetime(prbs.t, origin="2020-02-01 00:00", unit="h").round("s")
        prbs.index = index
        U = prbs.Ph/5
        U = pd.DataFrame(U.resample(rule="15min").mean().round())
        #U = pd.DataFrame(data=np.tile(U.values, 2), index=U.index, columns=["phi_h", "u_sha"])
        #_u = pd.DataFrame(data=U.values, index=U.index, columns=["phi_h"])
        _u = pd.DataFrame(data=U.values, index=U.index, columns=["Tset"])
        _u = pd.concat([_u]*repeats)
        
        _u *= 25
        _u += 288.15 
        #_u *= 2000
        
        #_u["u_fan"] = U
        # of time steps:
        #N = 24*4 + 1
        # local control 
        # baseline control for sysid:
        for n in range(N):
            u = _u.iloc[n]
            #data, y_meas, u_meas = boptest.evolve(u=u)
            data, y_meas, u_meas = boptest.evolve()
        
        #y_data = boptest.get_data(tf=N*boptest.h, downsample=False)
        #raw_data = boptest.get_results(tf=N*boptest.h, ts=0)
        y_data = boptest.get_results(tf=N*boptest.h, ts=0)
        
        # 30 s data:
        y_data.index = pd.TimedeltaIndex(y_data.index*30, unit="s")
        forecast_df = boptest.forecast_df
        forecast_df.index = pd.TimedeltaIndex(forecast_df.index, unit="s")
        forecast_df = forecast_df.resample(rule="30s").ffill()
        #forecast_df = forecast_df.resample(rule="30s").interpolate()
        y_data = y_data[:len(forecast_df)]
        y_data.index = forecast_df.index
        y_data = pd.merge(y_data, forecast_df, left_index=True, right_index=True)
        boptest_to_ocp = {v: k for k, v in boptest.boptest_to_ocp.items()}
        y_data.rename(columns = boptest_to_ocp, inplace=True)
        y_data.index = y_data.time
        
        y_data["y1"] = y_data.Ti
        y_data["y2"] = y_data.Te
        # efficiency:
        #y_data["phi_h"] = y_data["phi_h"].shift(-1).ffill().bfill()*0.99
        y_data["Tset"] = y_data["Tset"].shift(-1).ffill().bfill()
        y_data["u_fan"] = y_data["u_fan"].shift(-1).ffill().bfill()
        y_data = y_data.iloc[:-1]
        #y_data = y_data.iloc[4*24:]
        #y_data["y2"] = y_data.phi_h
        
        #y_data = y_data.iloc[:-1]
        y_data.to_csv(data_path)
    else:
        y_data = pd.read_csv(data_path, index_col=0)
        
    #y_data["y1"] = y_data["Ti"]
    #y_data["y2"] = y_data["phi_h"]
    #y_data["Tset"] = y_data["Tset"].shift(-1).ffill().bfill()
    #y_data["phi_h"] = y_data["phi_h"].shift(-1).ffill().bfill()
    
    ############ PLOT DATA #############
    if PLOT_DATA:
        ax = y_data["Ti"].plot()
        y_data["Te"].plot(ax=ax, color="m")
        ax1 = ax.twinx()
        y_data["Tset"].plot(ax=ax, color="y", drawstyle="steps-post")
        y_data["Ta"].plot(ax=ax, color="k")
        y_data["Ph"].plot(ax=ax1, color="r", linestyle="dashed", drawstyle="steps-post")
        #y_data["Pc"].plot(ax=ax1, color="b", linestyle="dashed", drawstyle="steps")
        #y_data["u_turnon"].plot(ax=ax1, color="g", drawstyle="steps")
        #y_data["u_fan"].plot(ax=ax1, color="k", drawstyle="steps")
        ax.legend(["Ti", "Te", "Tset", "Ta"], loc="upper left")
        ax1.legend(["Ph"], loc="upper right")
        #ax1.legend(["Ph", "u_turnon", "u_fan"])
        plt.show() 
    
    ####################################
    #y_data = data
    # remove nan after warmup:
    y_data.index = pd.TimedeltaIndex(y_data.index, unit="s")
    rest_cols = [col for col in y_data.columns if col != "Ph"]
    phi_h = y_data["Ph"].resample(rule=sampling_freq).mean()
    rest = y_data[rest_cols].resample(rule=sampling_freq).asfreq()
    #y_data = y_data.resample(rule="1min").asfreq()
    y_data = pd.merge(phi_h, rest, left_index=True, right_index=True)
    y_data.index = range(len(y_data.index))
    sampling_freq_num = re.findall(r'\d+', sampling_freq)
    assert len(sampling_freq_num) == 1
    y_data.index *= int(sampling_freq_num[0])
    
    N = len(y_data)-1
    dt = y_data.index[1] - y_data.index[0]  
    #param_guess = ca.DM([0.01,0.01,1E6,1E7,5,1.05,39.10,0.90])
    #param_guess = ca.DM([0.01,0.01,0.01,0.01,1E6,1E7,1E6,5])
    #param_guess = ca.DM([0.01,0.01,100,1E6,1E7,5,1.1])
    #param_guess = ca.DM([0.001,0.01,2E5,1E6,5])
    #param_guess = ca.DM([0.01,0.01,2E5,5E6,5,500,1.1,0.9])
    #param_guess = ca.DM([0.001,0.01,2E5,1E6,5,500,1.1])
    #param_guess = ca.DM([0.01,0.01,0.01,2E5,1E6,1E5,5,500])
    #param_guess = ca.DM([0.01,0.01,0.1,2E5,1E6,5,500])
    # GIVES good fit:
    #param_guess = ca.DM([0.01,0.01,1,1E5,1E6,5,500])
    param_guess = ca.DM([0.001,0.01,1E6,5E6,5,500,0.1,120])
    
    param_guess = ca.DM([
                        2.230834e-04,
                        2.253021e-03,
                        4.756271e+06,
                        2.237779e+07,
                        2.943147e-01,
                        2.479899e+03
                        ])
    
    #lbp = param_guess*0.001
    #ubp = param_guess*1000
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    #lbp[len_p-1] = 120
    #ubp[len_p-1] = 120
    #lbp[len_p-2] = 0.1
    #ubp[len_p-2] = 0.1
    #lbp[len_p-1] = 0.85
    #ubp[len_p-1] = 1
    
    # (Tsup - Ti)*u_turnon*u_fan*b
    
    # feed in x_guess:
    x_guess = y_data[["Ti", "y1"]]
    x_guess["Ts"] = y_data["Tsup"]
    x_guess["Ts"].iloc[-1] = x_guess["Ts"].iloc[-2]
    x_guess = x_guess.values
    
    kwargs = {
        "oneWayHeating": 
        functions["oneWayHeating"],
        "regNonZeroPower":
        functions["regNonZeroPower"]
    }
    
    """
    Before doing the parameter estimation, try doing a
    simulation of the system.
    """
    param_est = ParameterEstimation(config=cfg_path,
                                    functions=functions,
                                    N=N,
                                    dt=dt,
                                    param_guess=param_guess, 
                                    **kwargs)
    cfg_path = os.path.join("configs", "3R2C_bestest_air_ufan_1meas.json")
    cfg_path_ = os.path.join("configs", "double_PI_FMU.json")
    p_ = [0.1, 120]
    
    dae = ca.DaeBuilder('pi', 'FMUs/LimPID/LimPID.fmutmp')
    #dae = ca.DaeBuilder('Simple2R2C', 'Simple2R2C_PI')
    dae.disp(True)
    #ode = dae.create('f', ['x','u','p'], ['ode'], {"verbose": True})
    #name_in = ['x', 'p', 'u']
    aux = dae.p()
    #name_in = ['x', 'p', 'u']
    name_in = ['x','u']
    name_out = ['ydef']
    #ode = dae.create('f', ['t', 'x', 'z', 'p', 'u'], ['ode','alg','ydef'], {"verbose": True})
    pi_y = dae.create('pi_y', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "openmp"})
    #name_in = ['x','u']
    name_out = ['ode']
    pi_ode = dae.create('pi_ode', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "openmp"})
    
    """
    kwargs = {
        "oneWayHeating": 
        functions["oneWayHeating"],
        "regNonZeroPower":
        functions["regNonZeroPower"],
        "pi_fmu":
        ode
    }
    
    
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12],
        "u_nom_b": [289.15],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0]
    }
    """
    
    functions["pi_ode"] = pi_ode
    functions["pi_y"] = pi_y
    
    param_est_ = ParameterEstimation(config=cfg_path_,
                                    functions=functions,
                                    N=N,
                                    dt=dt,
                                    param_guess=p_, 
                                    **kwargs)
    I = param_est.integrator
    I_PI_ode = param_est_.integrator
    print(I)
    #x0 = [293.15,293.15,0]
    #x0 = [297.0,296.15,0]
    #x0 = [297.0,296.15]
    #x0 = y_data[["Ti","Te"]].iloc[0]
    xs = np.array([])
    us = np.array([])
    xs_ = np.array([])
    p = param_guess
    _x0 = [0]
    
    y_data = y_data[(4*24):]
    N = len(y_data) - 1
    x0 = y_data[["Ti","Te"]].iloc[0]
    T_high = 313.15
    T_low = 294.15
    for n in range(N+1):
        xs = np.append(xs, np.array(x0))
        xs_ = np.append(xs_, np.array(_x0))
        u = y_data[I.dae.u_names].iloc[n].values
        r = y_data[I.dae.r_names].iloc[n].values
        # inputs for PI control:
        u_ = y_data[I_PI_ode.dae.u_names].iloc[n].values
        r_ = y_data[I_PI_ode.dae.r_names].iloc[n].values
        x0 = I.one_sample(x0,0,u,p,0,r) 
        #x0 = I.one_sample(x0,0,ca.vertcat(p, r),u,0,0,0)[0]
        #_x0 = I_PI.one_sample(_x0,0,ca.vertcat(p_, r_),u_,0,0,0)[0]
        y_PI = float(I_PI_ode.g(_x0,0,u_,p_,r_))
        """
        if y_PI < 0:
            y_PI = 0
        elif y_PI > 1:
            y_PI = 1
        """
        #T_low = y_data["Ti_lb"].iloc[0]
        _x0 = I_PI_ode.one_sample(_x0,0,u_,p_,0,r_)
        #y_PI = I_PI_ode.h(0,0,_x0,0,u_,p_,r_)
        u0 = np.array([y_PI*(T_high - T_low) + T_low, y_PI])
        #u0 = np.array([y_PI*(T_high - T_low) + T_low, y_PI])
        us = np.append(us, np.array(u0))
    #res = pd.DataFrame(data=xs.reshape(N, 3), columns=["Ti", "Te", "E"])
    res = pd.DataFrame(data=xs.reshape(N+1, 2), columns=["Ti", "Te"])
    res_ = pd.DataFrame(data=us.reshape(N+1, 2), columns=["Tsup", "u_fan"])
    _res_ = pd.DataFrame(data=xs_.reshape(N+1, 1), columns=["E"])
    res.index = y_data.index
    res_.index = y_data.index
    ax = res.Ti.plot(color="r")
    y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    plt.show()
    
    #res_ = pd.DataFrame(data=xs.reshape(N+1, 2), columns=["Tsup", "u_fan"])
    ax = res_.Tsup.plot()
    #y_data._y.plot(color="k", linestyle="dashed", ax=ax)
    y_data.Tsup.plot(color="k", linestyle="dashed", ax=ax)
    plt.show()
    print(res_)
    
    #ax = (res["Ti"] - y_data.Ti).plot()
    #plt.show()