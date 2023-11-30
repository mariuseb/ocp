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
from utils import prepare_data_HVAC
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

    LOAD_SOL = False
    LOAD_PARAMS = True

    cfg_path = os.path.join("configs", "Tret_Tsup_Th_Prad_flow_TVP.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    #data = pd.read_csv("ZEBLab_valve_year_1m.csv")
    data = pd.read_csv("ZEBLab_year_5m.csv")
    data = data[:-1]
    # prep data:
    data = prepare_data_HVAC(data)
    
    val_219 = data["val_219"] #.sort_values(ascending=True)
    flow_219 = data["V_flow_219"] #[val_219.index]
    val_219.index = range(len(val_219))
    flow_219.index = range(len(val_219))
    ax = flow_219.plot(color="k", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    val_219.plot(ax=ax1, color="r", linewidth=0.5, drawstyle="steps-post")
    
    ax.legend(["flow [kg/s]"], loc="upper left")
    ax1.legend(["valve [%]"], loc="upper right")
    plt.show()

    """
    Sort data by val_219, plot flow as function of it.
    """
    
    val_219 = data["val_219"].sort_values(ascending=True)
    flow_219 = data["V_flow_219"][val_219.index]
    flow_219.index = val_219.values
    
    #ax = (data.m_flow_ss).plot(color="y", linewidth=1.0, drawstyle="steps-post")
    ax = (data.m_flow_bool).plot(color="y", linewidth=1.0, drawstyle="steps-post")
    ax1 = ax.twinx()
    data.Tsup.plot(ax=ax1, color="r", linestyle="dashed", linewidth=0.7, drawstyle="steps-post")
    data.Tret.plot(ax=ax1, color="b", linestyle="dashed", linewidth=0.7, drawstyle="steps-post")
    plt.show()

    """
    Separate training and validation.
    """
    
    start_train = pd.Timestamp("2022-12-14 00:00")
    stop_train = pd.Timestamp("2022-12-16 00:00")
    #stop_val = pd.Timestamp("2022-12-20 00:00")
    stop_val  = pd.Timestamp("2023-03-20 00:00")
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
    
    if not LOAD_PARAMS:
        param_guess = np.array([2.57052111e+02,
                                3.15325352e+02,
                                3.65584143e-01,
                                1.27270613e-02,
                                2.12932526e+04,
                                1.95214909e-02,
                                1.49316424e-01, 
                                1.00000001e+00,
                                2.08146236e-01,
                                7.54500251e+04,
                                1.80225470e-02,
                                1.70267131e+05,
                                4.49148948e-01,
                                9.65810459e+03,
                                5.30764595e+00, 
                                9.63231276e-01,
                                8.33333318e+01,
                                5.94313309e+02,
                                7.53148927e-03,
                                2.29344233e+04])
    else:
        param_guess = pd.read_csv("HVAC_params_3days.csv", index_col=0).values.flatten()
        
    lbp = 0.1*param_guess
    ubp = 10*param_guess
    
    lbp[0] = -20 + 273.15
    ubp[0] = -10 + 273.15
    lbp[1] = 40 + 273.15
    ubp[1] = 47 + 273.15
    lbp[2] = 0.2
    ubp[2] = 0.8
    
    len_p = param_guess.shape[0]
    lbp[len_p-1] = 2000
    ubp[len_p-1] = 50000
    lbp[len_p-2] = 0.004
    ubp[len_p-2] = 0.01
    lbp[len_p-3] = 10
    ubp[len_p-3] = 1000
    #lbp[len_p-4] = 7
    #ubp[len_p-4] = 7
    # force deltaT_h low:
    #lbp[len_p-6] = 2.90
    lbp[len_p-6] = 0.1
    ubp[len_p-6] = 5
    lbp[len_p-5] = 0.1
    ubp[len_p-5] = 5
    
    if not LOAD_SOL:
        x_guess = data[["Tret", "Tsup", "Tsup","u_val_set"]]
        x_guess.columns = ["Tret", "Tsup", "Th", "u_val"]
        #x_guess = data[["Tret", "Tsup", "Tsup"]]
        #x_guess.columns = ["Tret", "Tsup", "Th"]
        x_guess["Th"] = (x_guess["Tsup"] + x_guess["Tret"])/2
    else:
        x_guess = pd.read_csv("HVAC_traj_3days.csv", index_col=0)[["Tret", "Tsup", "Th", "u_val"]]
        
    lbx = x_guess.copy()
    lbx.u_val = 0
    lbx *= 0.9
    
    ubx = x_guess.copy()
    ubx.u_val = 1
    ubx *= 1.1
    
    x_guess = x_guess.values
    lbx = lbx.values
    ubx = ubx.values
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(4)
        R = ca.DM.eye(4)
        R[0,0] = 1E-1
        R[1,1] = 1E-1
        R[2,2] = 1E-4
        R[3,3] = 1E-1
        
        v1 = param_est.get("v1")
        v2 = param_est.get("v2")
        v3 = param_est.get("v3")
        v4 = param_est.get("v4")
        
        R_MX = param_est.R
        
        param_est.res = ca.vertcat(
            #ca.sqrt(R_MX[0,0])*v1,
            #ca.sqrt(R_MX[1,1])*v2,
            ca.sqrt(R_MX[2,2])*v3
            #ca.sqrt(R_MX[3,3])*v4
        ).T
        
        sol, params = param_est.solve(
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      lbx=lbx,
                                      ubx=ubx,
                                      covar=ca.veccat(Q,R)
                                      )

        ax = sol["Tret"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        #sol["Tset_sup"].plot(color="y", ax=ax)
        sol["Ti"].plot(color="m", linewidth=0.5, linestyle="dashed", ax=ax)
        sol["Ta"].plot(color="b", linewidth=0.5, linestyle="dashed", ax=ax)
        ax1 = ax.twinx()
        (sol["m_flow_bool"]).plot(ax=ax1, color="m", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
        #(sol["m_flow_bool"] - sol["fall"]).plot(ax=ax1, color="m", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
        #(sol["fall"]).plot(ax=ax1, color="m", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
        plt.show()
        
        ax = sol["Tsup"].plot(color="r")
        sol["y2"].plot(color="k", ax=ax)
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
        """
        #sol["rise"].plot(ax=ax1, color="y", linewidth=0.75, linestyle="dashed", drawstyle="steps-post")
        ax1.legend(["rise","hold","fall","delta_m_flow"])

        plt.show()
        print(params)
        
        ax = sol[["Tret", "Th", "Tsup", "Ti"]].plot()
        plt.show()
        
        autocorrelation_plot(sol.v1)
        plt.show()
        """
        Plot (sorted) heating curve.
        """
        
        Tsup = sol["Tsup"].sort_values(ascending=False)
        Tsup_act = sol["y1"][Tsup.index]
        Tsup.index = range(len(Tsup.index))
        Tsup_act.index = range(len(Tsup_act.index))
        Tsup_act = pd.DataFrame(Tsup_act)
        Tsup_act["time"] = Tsup_act.index
        ax = Tsup.plot(color="k", linewidth=0.5)
        Tsup_act.plot(kind="scatter" ,x="time", y="y1", ax=ax, color="r")
        ax.legend()
        plt.show()
        
        
        fig, axes = plt.subplots(3,1, sharex=True)
        ax = axes[0]
        sol["Prad"].plot(ax=ax,linewidth=0.75, drawstyle="steps-post", color="k")
        data["y3"].plot(ax=ax, linewidth=0.75, drawstyle="steps-post", color="r", linestyle="dashed")
        
        deltaT = sol["Tsup"] - sol["Tret"]
        truth = sol["y2"] - sol["y1"]
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
        sol.y3.resample(rule="1H").mean().plot(drawstyle="steps-post", color="m")
        plt.show()
        
        autocorrelation_plot(sol.v3)
        plt.show()
        
        autocorrelation_plot(sol.v3.resample(rule="1H").mean())
        plt.show()
        
        sol.v3.resample(rule="1H").mean().hist()
        plt.show()
        
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
    data.y3.plot(color="r", linestyle="dashed", ax=ax, linewidth=0.5, drawstyle="steps-post")
    plt.show()
    print(p)
