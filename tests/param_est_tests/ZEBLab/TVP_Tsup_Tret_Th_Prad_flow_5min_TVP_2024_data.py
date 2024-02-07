#from ast import Param

import sys
import os
import pathlib
#ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
#sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from matplotlib import rc
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from utils import prepare_data
from ocp.functions import functions
from pandas.plotting import autocorrelation_plot
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    """
    Proof of concept for grey-box SYSID, ZEB Lab.
    Use room 219 first.
    """

    cfg_path = os.path.join("configs", "Tret_Tsup_Th_Prad_flow_TVP.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    data = pd.read_csv("ZEBLab_2024_1m.csv", index_col=0)
    # bfill:
    data.index = pd.to_datetime(data.index)
    data.index = data.index.tz_localize(None)
    # take subset of data:
    start = pd.Timestamp("2023-12-14 00:00")
    stop = pd.Timestamp("2023-12-20 00:00")
    data = data.loc[start:stop]
    
    #data.drop(columns=["_time"], inplace=True)
    data = data.resample(rule="5min").mean()
    
    val_cmd = data["val_cmd_219"]
    val_pos = data["val_pos_219"]/100
    flow = data["V_flow_219"]

    fig, axes = plt.subplots(3,1, sharex=True)
    ax = axes[0]

    val_cmd.plot(ax=ax, color="k", drawstyle="steps-post")
    val_pos.plot(ax=ax, color="r", linestyle="dashed", drawstyle="steps-post")
    ax.legend(loc="upper right")

    ax1 = ax.twinx()
    flow.plot(ax=ax1, color="b", drawstyle="steps-post")
    ax1.legend(loc="upper left")

    Tdev = data["T_set"] - data["T_219_TR3"]
    Tdev[Tdev < 0] = 0
    ax = axes[1]
    Tdev.plot(ax=ax, color="r", drawstyle="steps-post")
    ax.legend(["Tset - Ti"])

    ax = axes[2]
    data.P_rad_219.plot(ax=ax, drawstyle="steps-post")
    
    plt.show()
    
    
    data = prepare_data(data)


    val_219 = data["val_pos_219"].sort_values(ascending=True)
    flow_219 = data["V_flow_219"][val_219.index]

    val_219.index = range(len(val_219))
    flow_219.index = range(len(val_219))
    ax = flow_219.plot(color="k", linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    val_219.plot(ax=ax1, color="r", linewidth=3, drawstyle="steps-post")
    #(normed*val_219.max()).plot(ax=ax1, color="y", linewidth=1.5, drawstyle="steps-post")
    
    ax.legend(["flow [kg/s]"], loc="upper left")
    ax1.legend(["valve [%]"], loc="upper right")
    plt.show()
    
    """
    Separate training and validation.
    """
    
    Prad = data.Prad.resample(rule="1H").mean()
    gt_zero = Prad[Prad > 0]
    r = gt_zero.copy()
    r.index += pd.Timedelta(hours=1)
    l = gt_zero.copy()
    l.index -= pd.Timedelta(hours=1)
    gt_zero_index = list(set(list(gt_zero.index) + list(r.index) + list(l.index)))
    #gt_zero = gt_zero.resample(rule="1min").asfreq()
    
    index_selection = [
                       ndx
                       for ndx in data.index 
                       if 
                       ndx.floor("1H") in gt_zero_index
                       ]
    data = data.loc[index_selection]
      
    start_train = pd.Timestamp("2023-12-14 00:00")
    stop_train = pd.Timestamp("2023-12-17 00:00")
    stop_val = pd.Timestamp("2023-12-20 00:00")
    validation_data = data.loc[stop_train:stop_val]
    data = data.loc[start_train:stop_train]

    N = len(data)
    dt = (data.index[1] - data.index[0]).seconds
    # set range index for identification:
    data.dt_index = data.index
    data.index = range(0,N*dt,dt)

    """
    param_guess = np.array([-15 + 273.15,   # Ta_dim
                            43 + 273.15,    # T_set_sub_b
                            4.17885968e-01, # T_set_sub_a
                            2.91191613e-01, # Rsup
                            2.12932524e+02, # Csup
                            1.73304875e-02, # Rih
                            1E-2,           # Rrh
                            1E-2,           # Rsh
                            4.16250843e-03, # Rir
                            1.21318902e+04, # Ch
                            1.93865427e-02, # Rsup_hold
                            1.70267331e+05, # Csup_hold
                            6.93865427e-02, # Rret
                            4.70267331e+02, # Cret
                            3.41729662,     # deltaT_h
                            1.87655371e-01, # deltaT_sup
                            1.66649997e+00, # deltaT_ret
                            1.19874920e+02, # tau
                            7.00000002e-03, # m_flow_nom
                            1.69461662e+04])# cp_water
    """
    param_guess = np.array([2.57052111e+02,
                            3.15325352e+02,
                            3.65584143e-01,
                            1.27270613e-02,
                            2.12932526e+03,
                            1.95214909e-02,
                            1.49316424e-01, 
                            1.00000001e+00,
                            2.08146236e-01,
                            7.54500251e+03,
                            1.80225470e-02,
                            1.70267131e+02,
                            4.49148948e-01,
                            9.65810459e+02,
                            5.30764595e+00, 
                            9.63231276e-01,
                            8.33333318e+01,
                            5.94313309e+02,
                            7.53148927e-03,
                            2.29344233e+04])
    
    lbp = 1E-3*param_guess
    ubp = 1E3*param_guess
    
    lbp[0] = -20 + 273.15
    ubp[0] = -10 + 273.15
    lbp[1] = 40 + 273.15
    ubp[1] = 47 + 273.15
    lbp[2] = 0.2
    ubp[2] = 0.8
    
    len_p = param_guess.shape[0]
    lbp[len_p-1] = 2000
    ubp[len_p-1] = 50000
    lbp[len_p-2] = 0.002
    ubp[len_p-2] = 0.04
    lbp[len_p-3] = 10
    ubp[len_p-3] = 1000
    #lbp[len_p-4] = 7
    #ubp[len_p-4] = 7
    # force deltaT_h low:
    #lbp[len_p-6] = 2.90
    lbp[len_p-6] = 0.1
    ubp[len_p-6] = 10
    lbp[len_p-5] = 0.1
    ubp[len_p-5] = 10

    x_guess = data[["Tret", "Tsup", "Tsup","u_val_set"]]
    x_guess.columns = ["Tret", "Tsup", "Th", "u_val"]
    #x_guess = data[["Tret", "Tsup", "Tsup"]]
    #x_guess.columns = ["Tret", "Tsup", "Th"]
    x_guess["Th"] = (x_guess["Tsup"] + x_guess["Tret"])/2
    lbx = x_guess.copy()
    lbx.u_val = 0
    lbx *= 0.9
    
    ubx = x_guess.copy()
    ubx.u_val = 1
    ubx *= 1.1
    
    x_guess = x_guess.values
    lbx = lbx.values
    ubx = ubx.values
    
    """
    kwargs = {
        "x_nom": [12,12,12,1],
        "x_nom_b": [289.15,289.15,289.15,0],
        "z_nom": [12,1E3,1E-2], 
        "z_nom_b": [289.15,0,0],
        "u_nom": [12,12,1,1,1,1],
        "u_nom_b": [289.15,289.15,0,0,0,0],
        #"r_nom": [12,300,1E6,1E6,1E6],
        #"r_nom_b": [289.15,0,0,0,0],
        #"p_nom": [1E-5,1E-4,1E8,1E9,1E2,1,1E3,1,12],
        #"p_nom_b": [0,0,0,0,0,0,0,0,289.15],
        "y_nom": [12,12,1E3,1E-2],
        "y_nom_b": [289.15,289.15,0,0]
    }
    """
    
    kwargs = dict()
    x_guess = x_guess.flatten()
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess,
                             **kwargs) as param_est:

        Q = ca.DM.eye(4)
        R = ca.DM.eye(4)
        R[0,0] = 1E-1
        R[1,1] = 1E-1
        R[2,2] = 1E-4
        R[3,3] = 1E-1
        
        v2 = param_est.get("v2")
        v3 = param_est.get("v3")
        v4 = param_est.get("v4")
        v5 = param_est.get("v5")
        
        R_MX = param_est.R
        
        param_est.res = ca.vertcat(
            #ca.sqrt(R_MX[0,0])*v1,
            #ca.sqrt(R_MX[1,1])*v2,
            ca.sqrt(R_MX[2,2])*v4
            #ca.sqrt(R_MX[3,3])*v4
        ).T
        
        sol, params = param_est.solve(
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      #lbx=lbx,
                                      #ubx=ubx,
                                      covar=ca.veccat(Q,R),
                                      codegen=True
                                      )
        
        sol.index = data.index

        ax = sol["Tret"].plot(color="r")
        sol["y2"].plot(color="k", ax=ax)
        #sol["Tset_sup"].plot(color="y", ax=ax)
        sol["Ti"].plot(color="m", linewidth=0.5, linestyle="dashed", ax=ax)
        sol["Ta"].plot(color="b", linewidth=0.5, linestyle="dashed", ax=ax)
        ax1 = ax.twinx()
        (sol["m_flow_bool"]).plot(ax=ax1, color="m", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
        #(sol["m_flow_bool"] - sol["fall"]).plot(ax=ax1, color="m", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
        #(sol["fall"]).plot(ax=ax1, color="m", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
        plt.show()
        
        ax = sol["Tsup"].plot(color="r")
        sol["y3"].plot(color="k", ax=ax)
        #sol["Tset_sup"].plot(color="y", ax=ax)
        sol["Ti"].plot(color="m", linewidth=0.5, linestyle="dashed", ax=ax)
        sol["Ta"].plot(color="b", linewidth=0.5, linestyle="dashed", ax=ax)
        ax1 = ax.twinx()
        #sol["u_val"].plot(ax=ax1, drawstyle="steps-post")
        #sol["rise"].plot(ax=ax1, linestyle="dashed", drawstyle="steps-post")
        #sol["hold"].plot(ax=ax1, marker="v", drawstyle="steps-post")
        #sol["fall"].plot(ax=ax1, drawstyle="steps-post")
        """
        plot delta_m_flow.
        sol["rise"].plot(ax=ax1, color="y", linewidth=0.75, linestyle="dashed", drawstyle="steps-post")
        ax1.legend(["rise","hold","fall","delta_m_flow"])
        """

        plt.show()
        print(params)
        
        ax = sol[["Tret", "Th", "Tsup", "Ti"]].plot()
        plt.show()
        
        autocorrelation_plot(sol.v2)
        plt.show()
        """
        Plot (sorted) heating curve.
        """
        
        Tsup = sol["Tsup"].sort_values(ascending=False)
        Tsup_act = sol["y3"][Tsup.index]
        Tsup.index = range(len(Tsup.index))
        Tsup_act.index = range(len(Tsup_act.index))
        Tsup_act = pd.DataFrame(Tsup_act)
        Tsup_act["time"] = Tsup_act.index
        ax = Tsup.plot(color="k", linewidth=0.5)
        Tsup_act.plot(kind="scatter" ,x="time", y="y3", ax=ax, color="r")
        ax.legend()
        plt.show()
        
        
        fig, axes = plt.subplots(3,1, sharex=True)
        ax = axes[0]
        sol["Prad"].plot(ax=ax,linewidth=0.75, drawstyle="steps-post", color="k")
        data["y4"].plot(ax=ax, linewidth=0.75, drawstyle="steps-post", color="r", linestyle="dashed")
        
        deltaT = sol["Tsup"] - sol["Tret"]
        truth = sol["y3"] - sol["y2"]
        ax = axes[1]
        deltaT.plot(ax=ax, drawstyle="steps-post")
        truth.plot(ax=ax, drawstyle="steps-post", color="r")
        ax.legend(["model","truth"])
        
        ax = axes[2]
        sol["m_flow"].plot(ax=ax, drawstyle="steps-post")
        plt.show()
        
        """
        Resampled plot.
        """
        sol.index = data.dt_index
        data.index = data.dt_index
        ax = sol.Prad.resample(rule="1H").mean().plot(drawstyle="steps-post")
        sol.y4.resample(rule="1H").mean().plot(drawstyle="steps-post", color="m")
        plt.show()
        
        autocorrelation_plot(sol.v4)
        plt.show()
        
        autocorrelation_plot(sol.v4.resample(rule="1H").mean())
        plt.show()
        
        sol.v4.resample(rule="1H").mean().hist()
        plt.show()
        
        params.to_csv("results_HVAC/params_HVAC_model_tvp.csv", index=True)
        sol.to_csv("results_HVAC/sol_HVAC_model_tvp.csv", index=True)
        
        print(params)
        
        
    """
    Need to test in-sample to
    verify that root-finding of
    z works.
    """
    
    param_est = ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess)
    I = param_est.integrator
    print(I)
    #x0 = [293.15,293.15,0]
    # in-sample, use first identified state:
    x0 = sol[I.dae.x].iloc[-1].values
    xs = np.array([])
    zs = np.array([])
    p = params #(data.m_flow - data.m_flow.shift(1)).plot(drawstyle="steps-post")
    g = I.g
    G = I.G # Newton-solver for algebraic system of equations
    # guess for z for the Newton-solver:
    z_guess = [310, 0, 0]
    v = [0,0,0,0]
    # "set" dataset
    data = validation_data
    N = len(data)
    for n in range(N):
        xs = np.append(xs, np.array(x0))
        u = data[I.dae.u_names].iloc[n].values
        r = data[I.dae.r_names].iloc[n].values
        
        #z = sol[I.dae.z].iloc[n].values
        # separate root-finding problem for values of z:
        z = G(z_guess, x0, u, p, v, 0, 0, 0)
        zs = np.append(zs, np.array(z))
        x0 = I.one_sample(x0,z,u,p,0,r,0)
        z_guess = z
        #x0 = I.one_sample(x0,0,ca.vertcat(p, r),u,0,0,0)[0]
    res_x = pd.DataFrame(data=xs.reshape(N, 4), columns=["Tret", "Tsup", "Th", "u_val"])
    res_z = pd.DataFrame(data=zs.reshape(N, 3), columns=["T_set_sup", "Prad", "m_flow"])
    #res = pd.DataFrame(data=xs.reshape(N,2), columns=["Ti", "Te"])
    res = pd.merge(res_x, res_z, left_index=True, right_index=True)
    res.index = data.index
    ax = res.Prad.plot(color="k", linewidth=0.5, drawstyle="steps-post")
    #sol.Prad.plot(color="k", linestyle="dashed", ax=ax, linewidth=0.5, drawstyle="steps-post")
    (data.y4).plot(color="r", linestyle="dashed", ax=ax, linewidth=0.5, drawstyle="steps-post")
    plt.show()
    
    #sol.index = data.dt_index
    #data.index = data.dt_index
    ax = res.Prad.resample(rule="1H").mean().plot(drawstyle="steps-post")
    data.y4.resample(rule="1H").mean().plot(drawstyle="steps-post", color="m")
    plt.show()
    
    print(p)
