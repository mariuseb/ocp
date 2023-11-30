#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
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

    cfg_path = os.path.join("configs", "Tret_Tsup_Th_Prad_alt_alt.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    data = pd.read_csv("ZEBLab_valve_year_1m.csv")
    
    """
    Try to plot.
    """
    
    
    data.V_flow_219[data["V_flow_219"] > 0.005] = 0.005
    # bfill:
    data.index = pd.to_datetime(data._time)
    data.index = data.index.tz_localize(None)
    # take subset of data:
    start = pd.Timestamp("2022-12-14 00:00")
    stop = pd.Timestamp("2022-12-21 00:00")
    data = data.loc[start:stop]
    
    data.drop(columns=["_time"], inplace=True)
    data = data.resample(rule="15min").mean()
    
    data["m_flow"] = data.V_flow_219*1.293
    data["delta_m_flow"] = (data.m_flow - data.m_flow.shift(1))
    data["delta_m_flow"].fillna(method="bfill", inplace=True)
    # resample

    normed = (data.delta_m_flow.resample(rule="15min").mean()/data.delta_m_flow.max()).resample("5min").ffill()
    normed[normed < 0] = 0
    #normed[normed < 0] = normed[normed < 0].astype(bool).astype(int)*(-1)
    normed[normed > 0] = normed[normed > 0].astype(bool).astype(int)
    data["normed"] = normed
    #normed.plot(ax=ax1, color="y", linewidth=0.75, linestyle="dashed", drawstyle="steps-post")
    #ax1.legend(["rise","hold","fall","delta_m_flow"])

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
    Sort data by val_219, plot flow as function of it.
    """
    Tdata = pd.read_csv("ZEBLab_year_15m.csv", index_col=0)
    Tdata = prepare_data(Tdata)
    Tdata = Tdata[1:-1]
    Tdata.index = pd.to_datetime(Tdata.index)
    Tdata.index = Tdata.index.tz_localize(None)
    Tdata = Tdata.interpolate()
    Tdata[Tdata.Ti > 30] = 30
    deltaT = Tdata.Tset - Tdata.Ti
    deltaT.loc[start:stop]
    
    val_219 = data["val_pos_219"].sort_values(ascending=True)
    flow_219 = data["V_flow_219"][val_219.index]
    flow_219.index = val_219.values
    
    Tdata[Tdata["Tsup"] > 45] = 45
    Tdata[Tdata["Tret"] > 35] = 35
    # take out subset of data:
    Tdata = Tdata.loc[start:stop]
    
    data["u_val_set"] = data.val_pos_219
    
    Tdata["fall"] = 0
    Tdata["fall"].loc[Tdata.Tret < Tdata.Ti] = 1
    Tdata["delta_Tret"] = (Tdata.Tret - Tdata.Tret.shift(1))
    Tdata["delta_Tret"].fillna(method="bfill", inplace=True)
    Tdata["delta_Tsup"] = (Tdata.Tsup - Tdata.Tsup.shift(1))
    Tdata["delta_Tsup"].fillna(method="bfill", inplace=True)
    data["delta_u_val"] = (data.u_val_set - data.u_val_set.shift(1))
    data["delta_u_val"].fillna(method="bfill", inplace=True)
    data["delta_m_flow"][data.delta_m_flow > 0.003] = 1
    data["delta_m_flow"][data.delta_m_flow < 1] = 0
    Tdata["Tsup_rise"] = 0
    Tdata["Tsup_rise"][Tdata.delta_Tsup > 5] = 1
    Tdata["Tret_rise"] = 0
    Tdata["Tret_rise"][Tdata.delta_Tret > 2] = 1
    Tdata["Tret_below"] = (Tdata.Tret_rise + Tdata.fall)
    
    m_flow_bool = (data.m_flow.resample(rule="15min").mean().astype(bool).astype(int)).resample("5min").ffill()
    data["m_flow_bool"] = m_flow_bool
    data["m_flow_weight"] = m_flow_bool + 0.01
    #data["m_flow_weight"] = 1
    data["rise"] = data["normed"]
    data["fall"] = Tdata["fall"]
    data["m_flow_ss"] = data.m_flow_bool - data.fall - data.delta_m_flow
    data["m_flow_ss"][data.m_flow_ss < 0] = 0
    data["Tret_rise"] = Tdata["Tret_rise"]
    
    # plot Tret lagged against Tret:
    
    ax = (Tdata.Tret - Tdata.Tret.shift(1)).plot(color="r", linestyle="dashed", linewidth=0.7, drawstyle="steps-post")
    Tdata.Tret.plot(color="b", linestyle="dashed", linewidth=0.7, drawstyle="steps-post")
    ax1 = ax.twinx()
    data.fall.plot(ax=ax1, color="k", linestyle="dashed", linewidth=0.7, drawstyle="steps-post")
    data.normed.plot(ax=ax1, color="r", linestyle="dashed", linewidth=0.7, drawstyle="steps-post")
    plt.show()
    
    data.index = Tdata.index
    #ax = data.val_pos_219.plot(drawstyle="steps-post")
    ax = (data.m_flow_ss).plot(color="y", linewidth=1.0, drawstyle="steps-post")
    (data.m_flow_bool).plot(ax=ax, color="b", linewidth=1.0, drawstyle="steps-post")
    #(data.m_flow_ss*data.val_pos_219.max()).plot(ax=ax, color="y", linewidth=1.5, drawstyle="steps-post")
    ax1 = ax.twinx()
    #data.V_flow_219.plot(ax=ax1, color="r", linestyle="dashed", drawstyle="steps-post")
    Tdata.Tsup.plot(ax=ax1, color="r", linestyle="dashed", linewidth=0.7, drawstyle="steps-post")
    Tdata.Tret.plot(ax=ax1, color="b", linestyle="dashed", linewidth=0.7, drawstyle="steps-post")
    plt.show()

    # TODO: enable calling this function in model defintion
    """
    First: construct the function outside initialization,
    pass it as a separate object, which must be part of 
    namespace when init'ing DAE object.
    """
    
    """
    data["m_flow_bool"] = 0
    gr_th_zero = data.m_flow[data.m_flow > data.m_flow.max()/3].astype(bool).astype(int)
    data["m_flow_bool"].loc[gr_th_zero.index] = gr_th_zero
    """
    
    """
    Resample m_flow_bool:
    """
    
    #data["y1"] = data["m_flow"]
    data["u_val"] = data.val_pos_219
    data["Ti"] = Tdata["Ti"] + 273.15
    data["Tsup"] = Tdata["Tsup"] + 273.15
    data["Tret"] = Tdata["Tret"] + 273.15
    data["Ta"] = Tdata["Ta"] + 273.15
    data["y1"] = data["Tret"]
    data["y2"] = data["Tsup"]
    data["y3"] = Tdata["Prad"]
    data["Prad"] = Tdata["Prad"]
    data["y4"] = data.V_flow_219*1.293
    #data["u_val_set"] = data.val_pos_219
    # filter deltaT:
    deltaT[deltaT < 0] = 0
    data["deltaT"] = deltaT


    N = len(data)
    dt = (data.index[1] - data.index[0]).seconds
    # set range index for identification:
    data.dt_index = data.index
    data.index = range(0,N*dt,dt)


    param_guess = np.array([2.57183229e+02,
                            3.15299160e+02,
                            3.10036364e-01,
                            2.88150000e+02,
                            6.19735396e-03,
                            9.99999980e+01, 
                            1.22869700e-01,
                            9.99999980e+00,
                            9.26307579e-02,
                            5.00000505e+00, 
                            1.09435372e+04,
                            5.00000505e+05,
                            7.16220373e-01, 
                            7.16220372e+05,
                            5.68598285e-02,
                            5.68598303e+04,
                            5.00000505e+00,
                            8.96831731e+01, 
                            8.21285365e+00,
                            4.74941309e+00,
                            4.74941309e+00,
                            1.29494112e+00,
                            1.00000006e-01,
                            1.50050001e+02,
                            3.23250326e+00,
                            1.71000001e+04])
    #                        1.1,
    #                        0.05])
    #lbp = param_guess
    #ubp = param_guess3
    
    
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    lbp[0] = -20 + 273.15
    ubp[0] = -10 + 273.15
    lbp[1] = 40 + 273.15
    ubp[1] = 47 + 273.15
    #lbp[8] = 25 + 273.15
    #ubp[8] = 40 + 273.15
    lbp[2] = 0.1
    ubp[2] = 0.6
    lbp[3] = 10 + 273.15
    ubp[3] = 20 + 273.15
    
    #lbp[8] = 1E-3
    # Csup_st:
    """
    ubp[6] = 1
    lbp[6] = 1E-6
    ubp[7] = 10*param_guess[7]
    lbp[7] = 0.1*param_guess[7]
    ubp[8] = 10*param_guess[8]
    lbp[8] = 0.1*param_guess[8]
    """
    
    # set ub of all resistances to 1
    #for i in range(3):
    #    ubp[i] = 1
    len_p = param_guess.shape[0]
    lbp[len_p-1] = 4200
    ubp[len_p-1] = 30000
    
    ubp[len_p-3] = 300
    
    lbp[len_p-4] = 0.1
    ubp[len_p-4] = 10
    lbp[len_p-5] = 0.1
    ubp[len_p-5] = 10
    lbp[len_p-6] = 0.1
    ubp[len_p-6] = 10
    lbp[len_p-7] = 0.1
    ubp[len_p-7] = 10
    lbp[len_p-8] = 0.1
    ubp[len_p-8] = 10
    # Cret:
    lbp[len_p-9] = 1E3
    """
    lbp[len_p-1] = 0.05
    ubp[len_p-1] = 0.05
    lbp[len_p-2] = 1
    ubp[len_p-2] = 1.5
    #lbp = 0.001*param_guess
    #ubp = 1000*param_guess
    # set ub of all resistances to 1
    #for i in range(3):
    #    ubp[i] = 1
    #lbp[len_p-2] = 7
    #ubp[len_p-2] = 7
    lbp[len_p-4] = 1
    ubp[len_p-4] = 1000
    lbp[len_p-3] = 1E-6
    ubp[len_p-3] = 1E-1
    lbp[len_p-2] = 1E-6
    ubp[len_p-2] = 1E-1
    """
    
    """
    lbp[len_p-2] = 7
    ubp[len_p-2] = 7
    """    
    
    #x_guess = data[["Tret", "Tsup", "Tsup","u_val_set"]]
    #x_guess.columns = ["Tret", "Tsup", "Th", "u_val"]
    x_guess = data[["Tret", "Tsup", "Tsup"]]
    x_guess.columns = ["Tret", "Tsup", "Th"]
    x_guess["Th"] = (x_guess["Tsup"] + x_guess["Tret"])/2
    lbx = x_guess.copy()
    #lbx.u_val *= 0
    lbx *= 0.8
    
    ubx = x_guess.copy()
    ubx *= 1.2
    
    x_guess = x_guess.values
    lbx = lbx.values
    ubx = ubx.values
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(3)
        R = ca.DM.eye(2)
        #R[2,2] = 0
        #R[3,3] = 0
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
        sol["rise"].plot(ax=ax1, color="y", linewidth=0.75, linestyle="dashed", drawstyle="steps-post")
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
        
        plt.show()
        """
        ax = axes[2]
        sol["m_flow"].plot(ax=ax, drawstyle="steps-post")
        
        sol.index = data.dt_index
        data.index = data.dt_index
        ax = sol.Prad.resample(rule="1H").mean().plot(drawstyle="steps-post")
        sol.y3.resample(rule="1H").mean().plot(drawstyle="steps-post", color="m")
        plt.show()
        autocorrelation_plot(sol.v3)
        plt.show()
        """ 
        print(params)
        
        
    """
    param_est = ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=params)
    I = param_est.integrator
    print(I)
    #x0 = [293.15,293.15,0]
    x0 = sol[I.dae.x].iloc[0].values
    xs = np.array([])
    p = params(data.m_flow - data.m_flow.shift(1)).plot(drawstyle="steps-post")
    for n in range(N):
        xs = np.append(xs, np.array(x0))
        u = data[I.dae.u_names].iloc[n].values
        r = data[I.dae.r_names].iloc[n].values
        z = sol[I.dae.z].iloc[n].values
        x0 = I.one_sample(x0,z,u,p,0,r)
        #x0 = I.one_sample(x0,0,ca.vertcat(p, r),u,0,0,0)[0]
    res = pd.DataFrame(data=xs.reshape(N, 3), columns=["Ti", "Te", "Th"])
    #res = pd.DataFrame(data=xs.reshape(N,2), columns=["Ti", "Te"])
    res.index = data.index
    ax = res.Ti.plot(color="r")
    data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    plt.show()
    print(p)
    """  

