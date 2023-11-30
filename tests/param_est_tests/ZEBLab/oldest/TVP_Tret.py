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

    cfg_path = os.path.join("configs", "Tret_if_else_hold_rise_fall.json")
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
    stop = pd.Timestamp("2022-12-18 00:00")
    data = data.loc[start:stop]
    
    data.drop(columns=["_time"], inplace=True)
    data = data.resample(rule="5min").mean()
    
    data["m_flow"] = data.V_flow_219*1.293
    data["delta_m_flow"] = (data.m_flow - data.m_flow.shift(1))
    data["delta_m_flow"].fillna(method="bfill", inplace=True)
    # resample

    normed = (data.delta_m_flow.resample(rule="5min").mean()/data.delta_m_flow.max()).resample("5min").ffill()
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
    Tdata = pd.read_csv("ZEBLab_year_5m.csv", index_col=0)
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
    
    ax = data.val_pos_219.plot(drawstyle="steps-post")
    (normed*data.val_pos_219.max()).plot(ax=ax, color="y", linewidth=1.5, drawstyle="steps-post")
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
    m_flow_bool = (data.m_flow.resample(rule="5min").mean().astype(bool).astype(int)).resample("5min").ffill()
    data["m_flow_bool"] = m_flow_bool
    data["m_flow_weight"] = m_flow_bool + 0.01
    
    #data["y1"] = data["m_flow"]
    data["u_val"] = data.val_pos_219
    data["Ti"] = Tdata["Ti"] + 273.15
    data["Tsup"] = Tdata["Tsup"] + 273.15
    data["Tret"] = Tdata["Tret"] + 273.15
    data["Ta"] = Tdata["Ta"] + 273.15
    data["y1"] = data["Tret"]
    data["rise"] = data["normed"]
    # filter deltaT:
    deltaT[deltaT < 0] = 0
    data["deltaT"] = deltaT


    N = len(data)
    dt = (data.index[1] - data.index[0]).seconds
    # set range index for identification:
    data.index = range(0,N*dt,dt)


    param_guess = np.array([-15 + 273.15,
                            30 + 273.15,
                            0.5,
                            15 + 273.15,
                            1E-2,
                            1E3,
                            1E-2,
                            1E5])
    lbp = param_guess
    ubp = param_guess
    
    
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    lbp[0] = -20 + 273.15
    ubp[0] = -10 + 273.15
    lbp[1] = 25 + 273.15
    ubp[1] = 40 + 273.15
    lbp[2] = 0.01
    ubp[2] = 0.6
    lbp[3] = 10 + 273.15
    ubp[3] = 20 + 273.15
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
    #lbp[len_p-1] = 1E1
    #ubp[len_p-1] = 1E5
    """
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
    
    x_guess = data.Tret.values
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(1)
        R = ca.DM.eye(1)
        sol, params = param_est.solve(
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      covar=ca.veccat(R)
                                      )

        ax = sol["Tret"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
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

