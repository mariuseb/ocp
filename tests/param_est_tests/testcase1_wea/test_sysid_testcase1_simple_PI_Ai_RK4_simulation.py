#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.mpc import MPC
import re
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
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    data_path = get_data_path()
    
    cfg_path = os.path.join(opt_config_base, "2R2C_testcase1_PI_Ai_Cvodes.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_testcase1_PI_.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    prbs_path = os.path.join(data_path, "inputPRBS1.csv")

    boptest = Boptest(
                      boptest_cfg,
                      name="testcase1_wea"
                      )
    
    GENERATE_DATA = False
    PLOT_DATA = False
    sampling_freq = "900s"
    data_path = os.path.join(get_data_path(), "data_testcase1_wea_P.csv")
    repeats = 1
    N = 6*24*4*repeats - 24*repeats
    
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
            data, y_meas, u_meas = boptest.evolve(u=u)
            #data, y_meas, u_meas = boptest.evolve()
        
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
        y_data = pd.merge(y_data, forecast_df, left_index=True, right_index=True)
        boptest_to_ocp = {v: k for k, v in boptest.boptest_to_ocp.items()}
        y_data.rename(columns = boptest_to_ocp, inplace=True)
        y_data.index = y_data.time
        
        y_data["y1"] = y_data.Ti
        # efficiency:
        y_data["phi_h"] = y_data["phi_h"].shift(-1).ffill().bfill()*0.99
        y_data["Tset"] = y_data["Tset"].shift(-1).ffill().bfill()
        y_data = y_data.iloc[:-1]
        y_data["y2"] = y_data.phi_h
        
        #y_data = y_data.iloc[:-1]
        y_data.to_csv(data_path)
    else:
        y_data = pd.read_csv(data_path, index_col=0)
        
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["phi_h"]
    #y_data["Tset"] = y_data["Tset"].shift(-1).ffill().bfill()
    #y_data["phi_h"] = y_data["phi_h"].shift(-1).ffill().bfill()
    
    ############ PLOT DATA #############
    if PLOT_DATA:
        ax = y_data["Ti"].plot()
        ax1 = ax.twinx()
        y_data["Tset"].plot(ax=ax, color="y", drawstyle="steps-post")
        y_data["Ta"].plot(ax=ax, color="k")
        y_data["phi_h"].plot(ax=ax1, color="r", linestyle="dashed", drawstyle="steps-post")
        #y_data["Pc"].plot(ax=ax1, color="b", linestyle="dashed", drawstyle="steps")
        #y_data["u_turnon"].plot(ax=ax1, color="g", drawstyle="steps")
        #y_data["u_fan"].plot(ax=ax1, color="k", drawstyle="steps")
        ax.legend(["Ti", "Tset", "Ta"], loc="upper left")
        ax1.legend(["Ph"], loc="upper right")
        #ax1.legend(["Ph", "u_turnon", "u_fan"])
        plt.show() 
    
    ####################################
    
    #raw_data = boptest.get_results(tf=N*boptest.h, ts=0)
    #smooth_factor = raw_data["PHea_y"].max()/y_data.phi_h.max()
    
    #y_data = data
    # remove nan after warmup:
    #y_data = y_data[1:]
    
    # keep for comparison
    #data = y_data.copy()
    
    y_data.index = pd.TimedeltaIndex(y_data.index, unit="s")
    rest_cols = [col for col in y_data.columns if col != "phi_h"]
    phi_h = y_data["phi_h"].resample(rule=sampling_freq).mean()
    rest = y_data[rest_cols].resample(rule=sampling_freq).asfreq()
    #y_data = y_data.resample(rule="1min").asfreq()
    y_data = pd.merge(phi_h, rest, left_index=True, right_index=True)
    y_data.index = range(len(y_data.index))
    sampling_freq_num = re.findall(r'\d+', sampling_freq)
    assert len(sampling_freq_num) == 1
    y_data.index *= int(sampling_freq_num[0])
    
    N = len(y_data)-1
    dt = y_data.index[1] - y_data.index[0]  
    
    # control action is zero:
    #y_data["Tset"].loc[(y_data["Ti"] > y_data["Tset"])] = y_data["Ti"]
    
    to_zero_indices = [ndx for ndx in y_data.index if not y_data.loc[ndx, "phi_h"]]
    y_data["Tset"].loc[to_zero_indices] = y_data["Ti"].loc[to_zero_indices]
    
    #param_guess = ca.DM([0.01,0.01,1E6,6E5,2000])
    #param_guess = ca.DM([0.01,0.01,1E6,5E6,5,2000])
    #param_guess = ca.DM([0.01,0.01,1E6,5E6,2000])
    #param_guess = ca.DM([0.01,0.01,1E6,5E6,2000/4.66])
    #param_guess = ca.DM([0.01,0.01,1E6,5E6,5])
    #param_guess = ca.DM([0.01,0.01,1E6,5E6,0])
    param_guess = ca.DM([0.01,0.01,1E6,5E6,0,100,(1/3)])
    lbp = param_guess*0.7
    ubp = param_guess*1.3
    #lbp = param_guess*0.99
    #ubp = param_guess*1.01
    len_p = param_guess.shape[0]
    
    kwargs = {
        "oneWayHeating": 
        functions["oneWayHeating"],
        "regNonZeroPower":
        functions["regNonZeroPower"],
    }
    """
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12],
        "u_nom_b": [289.15],
        "r_nom": [12, 300],
        "r_nom_b": [289.15, 0]
    }
    """
    
    param_est = ParameterEstimation(config=cfg_path,
                                    functions=functions,
                                    N=N,
                                    dt=dt,
                                    param_guess=param_guess, 
                                    **kwargs)
    I = param_est.integrator
    """
    Try to open FMU,
    and create an
    integrator from it.
    """
    #dae = ca.DaeBuilder('Simple2R2C', 'Simple2R2C_PI_OM_inputs/Simple2R2C_PI_OM_inputs.fmutmp')
    #dae = ca.DaeBuilder('Simple2R2C', 'Simple2R2C/Simple2R2C.fmutmp')
    dae = ca.DaeBuilder('Simple2R2C_SimplePI', 'Simple2R2C_SimplePI/Simple2R2C_SimplePI.fmutmp')
    #dae = ca.DaeBuilder('Simple2R2C', 'Simple2R2C_PI')
    dae.disp(True)
    #ode = dae.create('f', ['x','u','p'], ['ode'], {"verbose": True})
    #name_in = ['x', 'p', 'u']
    aux = dae.p()
    #name_in = ['x', 'p', 'u']
    name_in = ['x', 'u']
    name_out = ['ode']
    #ode = dae.create('f', ['t', 'x', 'z', 'p', 'u'], ['ode','alg','ydef'], {"verbose": True})
    ode = dae.create('test', name_in, name_out, {"verbose": False, "aux": aux,
                                              "parallelization": "openmp"})
    tgrid = [0,dt]
    #_N = 1
    #tgrid = [dt*1/N*(i+1) for i in range(_N)]
    opts = {
            "abstol": 1E-6,
            "reltol"  : 1E-6,
            "max_order": 5,
            "linear_multistep_method": "bdf",
            "nonlinear_solver_iteration": "newton",
            "verbose": True
            }
    #F = ca.integrator('F', 'cvodes', ode, tgrid[0], tgrid[1:], opts)
    # create RK4 integrator from ODE function:
    
    fs = 1/dt
    Ti  = ca.MX.sym('Ti')
    Te = ca.MX.sym('Te')
    E  = ca.MX.sym('E')
    
    Ta = ca.MX.sym('Ta')
    phi_s = ca.MX.sym('phi_s')
    Tset  = ca.MX.sym('Tset')
    #phi_h  = ca.MX.sym('phi_h')


    #states = ca.vertcat(Ti,Te,E)
    states = ca.vertcat(Ti,Te,E)
    #controls = ca.vertcat(Ta,phi_h,phi_s)
    controls = ca.vertcat(Ta,Tset,phi_s)
    ############ Creating a simulator ##########
    N_steps_per_sample = 1
    DT = 1/fs/N_steps_per_sample

    # Build an integrator for this system: Runge Kutta 4 integrator
    k1 = ode(states, controls)
    k2 = ode(states + DT/2.0*k1, controls)
    k3 = ode(states + DT/2.0*k2, controls)
    k4 = ode(states + DT*k3, controls)

    states_final = states + DT/6.0*(k1 + 2*k2 + 2*k3 + k4)

    # Create a function that simulates one step propagation in a sample
    one_step = ca.Function('one_step',[states,controls],[states_final]);

    X = states;

    for i in range(N_steps_per_sample):
        X = one_step(X,controls)

    # Create a function that simulates all step propagation on a sample
    one_sample_FMU = ca.Function('one_sample',
                                 [states,controls],
                                 [X],
                                 ["x0", "u"],
                                 ["xf"])
    #F.disp(True)
    one_sample_FMU.disp(True)
    one_sample_map = one_sample_FMU.mapaccum(N)
    
    x0 = [293.15,293.15,0]
    #x0 = [293.15,293.15]
    """
    xs = np.array([])
    p = param_guess
    for n in range(N):
        xs = np.append(xs, np.array(x0))
        u = y_data[I.dae.u_names].iloc[n].values
        r = y_data[I.dae.r_names].iloc[n].values
        x0 = one_sample_FMU(x0,ca.vertcat(r,u))
        #x0 = F(x0,0,0,ca.vertcat(r,u),0,0,0)[0]
    #res = pd.DataFrame(data=xs.reshape(N, 3), columns=["Ti", "Te", "E"])
    res = pd.DataFrame(data=xs.reshape(N, 2), columns=["Te", "Ti"])
    res.index = y_data.index
    ax = res.Ti.plot(color="r")
    y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    plt.show()
    """
    u = y_data[I.dae.u_names].iloc[:-1].values.T
    res = one_sample_map(x0, u)
    res = np.array(res).T 
    res = np.vstack([np.array(x0), res])
    #res = pd.DataFrame(data=np.array(res).reshape(N, 2), columns=["Ti", "Te"])
    res = pd.DataFrame(data=res, columns=["Te", "Ti","E"], index=range(N+1))
    res.index = y_data.index
    ax = res["Ti"].plot()
    y_data["FMU_Ti"] = FMU_Ti = res.Ti
    y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    plt.show()
    ax = (res["Ti"] - y_data.Ti).plot()
    plt.show()
    
    # CVode FMU
    ode = dae.create('f', ['t', 'x', 'z', 'p', 'u'], ['ode','alg','ydef'], {"verbose": True})
    #ode = dae.create('test', name_in, name_out, {"verbose": False, "aux": aux,
    #                                          "parallelization": "openmp"})
    tgrid = [0,dt]
    #_N = 10
    #tgrid = [dt*1/_N*(i) for i in range(_N+1)]
    opts = {
            "abstol": 1E-8,
            "reltol"  : 1E-8,
            "max_order": 5,
            "linear_multistep_method": "bdf",
            "nonlinear_solver_iteration": "newton",
            "verbose": False
            }
    #F = ca.integrator('F', 'cvodes', ode, tgrid[0], tgrid[1:], opts)
    F = ca.integrator('F', 'cvodes', ode, tgrid[0], tgrid[1:], opts)
    res = np.array([])
    p = param_guess
    for n in range(N+1):
        res = np.append(res, np.array(x0))
        u = y_data[I.dae.u_names].iloc[n].values
        r = y_data[I.dae.r_names].iloc[n].values
        x0 = F(x0,0,0,ca.vertcat(r,u),0,0,0)[0]
        #x0 = (x0,0,0,ca.vertcat(r,u),0,0,0)[0]
    #res = pd.DataFrame(data=xs.reshape(N, 3), columns=["Ti", "Te", "E"])
    res = res.reshape((N+1, 3))
    #res = pd.DataFrame(data=np.array(res).reshape(N, 2), columns=["Ti", "Te"])
    res = pd.DataFrame(data=res, columns=["Te","Ti","E"], index=range(N+1))
    res.index = y_data.index
    ax = res.Ti.plot(color="r")
    Cvode_FMU = res.Ti
    y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    plt.show()
    
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
    I = param_est.integrator
    print(I)
    #x0 = [293.15,293.15,0]
    x0 = [293.15,293.15,0]
    xs = np.array([])
    p = param_guess
    for n in range(N+1):
        xs = np.append(xs, np.array(x0))
        u = y_data[I.dae.u_names].iloc[n].values
        r = y_data[I.dae.r_names].iloc[n].values
        #x0 = I.one_sample(x0,0,u,p,0,r)
        x0 = I.one_sample(x0,0,ca.vertcat(p, r),u,0,0,0)[0]
    #res = pd.DataFrame(data=xs.reshape(N, 3), columns=["Ti", "Te", "E"])
    res = pd.DataFrame(data=xs.reshape(N+1, 3), columns=["Ti", "Te", "E"])
    res.index = y_data.index
    ax = res.Ti.plot(color="r")
    y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    plt.show()
    ax = (res["Ti"] - y_data.Ti).plot()
    plt.show()
    
    # cross-error between symbolic Cvodes and FMU RK4:
    cross = (res.Ti - FMU_Ti)
    FMU = FMU_Ti - y_data.Ti
    Cvode = res.Ti - y_data.Ti
    Cvode_FMU_res = Cvode_FMU - y_data.Ti
    residuals = pd.DataFrame(data=[cross, FMU, Cvode, Cvode_FMU_res], index=["cross","FMU","Cvode","Cvode_FMU"]).T
    residuals.plot()
    plt.show()
    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess, 
                             **kwargs) as param_est:
   
        #Q = ca.DM.eye(3)
        Q = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(1)
        #R = ca.DM.eye(1)
        #R[1,1] = 1E-5
        #R[1,1] = 1E-12

        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        v2 = param_est.nlp["x"][(v_inds["a"]+1):v_inds["b"]:param_est.dae.n_y]
        #v3 = param_est.nlp["x"][(v_inds["a"]+2):v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        #eta = param_est.dae.dae.var("eta")
        #v2 = v2/eta
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-8*ca.dot(v2, v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-12*ca.dot(v2, v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-6*ca.dot(v2,v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-16*ca.dot(v2,v2)
        #param_est.nlp["f"] = 0.5*ca.dot(v1, v1) + 1E-8*ca.dot(v2, v2)
        #u_active = y_data["phi_h"].astype(bool).astype(int).values
        #v2 = v2*u_active
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1) # + 1E-6*ca.dot(v2, v2) # + 1E-12*ca.dot(v3, v3)
        #param_est.res = ca.vertcat(v1,v2)
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      #x_guess=x_guess,
                                      covar=ca.veccat(Q, R)
                                      )
        
        # Temperature
        
        fig, axes = plt.subplots(3,2)
        
        sol["Ti"].plot(color="r", ax=axes[0,0])
        sol["y1"].plot(color="k", linestyle="dashed", ax=axes[0,0])
        axes[0,0].legend(["Ti", "y1"], loc="upper left")
        #ax1 = ax.twinx()
        
        #sol["phi_h"].plot(color="y", ax=axes[0,1])
        #(sol["y2"] - sol["v2"]).plot(color="b", linestyle="dashed", ax=axes[0,1])
        #sol["Tset"].plot(color="y", linestyle="dashed", ax=ax)
        axes[0,1].legend(["phi_h", "kp*(Tset - Ti)"], loc="upper right")
        #plt.show()
        
        # plot residuals:
        sol["v1"].plot(ax=axes[1,0])
        #sol["v2"].plot(ax=axes[1,1])
        (sol["Tset"] - sol["Ti"]).plot(ax=axes[2,1])
        #(sol["phi_h"]).plot(ax=axes[2,0], drawstyle="steps-post")

        plt.show()
        
        
        # Fan regulation:
        # Tsup regulation:
        # Heat
        """
        ax = sol["Ph"].plot(color="r")
        Ph_inf = sol["v2"] - sol["y2"]*sol["eta"]
        (-Ph_inf).plot(color="k", linestyle="dashed", ax=ax)
        ax.legend()
        plt.show()
        """
        
    print(params)