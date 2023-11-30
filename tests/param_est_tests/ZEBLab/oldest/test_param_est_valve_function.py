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

    cfg_path = os.path.join("configs", "valve.json")
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
    start = pd.Timestamp("2022-12-01 00:00")
    stop = pd.Timestamp("2023-03-31 00:00")
    data = data.loc[start:stop]
    
    data.drop(columns=["_time"], inplace=True)
    data = data.resample(rule="1H").mean()


    val_219 = data["val_pos_219"].sort_values(ascending=True)
    flow_219 = data["V_flow_219"][val_219.index]

    val_219.index = range(len(val_219))
    flow_219.index = range(len(val_219))
    ax = flow_219.plot(color="k", linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    val_219.plot(ax=ax1, color="r", linewidth=3, drawstyle="steps-post")
    ax.legend(["flow [kg/s]"], loc="upper left")
    ax1.legend(["valve [%]"], loc="upper right")
    plt.show()

    """
    Sort data by val_219, plot flow as function of it.
    """
    Tdata = pd.read_csv("ZEBLab_year_60m.csv", index_col=0)
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
    
    
    ax = data.val_pos_219.plot(drawstyle="steps-post")
    ax1 = ax.twinx()
    data.V_flow_219.plot(ax=ax1, color="r", linestyle="dashed", drawstyle="steps-post")
    plt.show()

    
    """
    Buildings Function equalPercentage
    """
    
    y = ca.MX.sym("y")
    R = ca.MX.sym("R")
    l = ca.MX.sym("l")
    delta = ca.MX.sym("delta")
    # protected:
    logR = ca.log(R)
    z = (3*delta/2)
    q = delta*(R**z)*logR
    p = R**z
    a = (q - 2*p + 2*(R**delta))/((delta**3)*R)
    b = (-5*q + 12*p - 13*(R**delta) + l*R)/(2*(delta**2)*R)
    c = (7*q - 18*p + 24*(R**delta) - 6*l*R)/(4*delta*R)
    d = (-3*q + 8*p - 9*(R**delta) + 9*l*R)/(8*R)
    # expressions:
    phi_if = (l + y*(R**(delta-1) - l))/delta
    phi_else_else = d + y*(c+y*(b+y*a))
    phi_else_if = R**(y-1)
    
    # output
    else_expr = ca.if_else(y > (3/2)*delta, phi_else_if, phi_else_else)
    expr =  ca.if_else(y < delta/2, phi_if, else_expr)
    equalPercentage = ca.Function(
                                  "equalPercentage", 
                                  [y,R,l,delta],
                                  [expr]
                                  #["x", "n", "delta"],
                                  #["y"]
                                  )
    R = 100
    l = 0.0001
    delta = 1E-4
    test = equalPercentage(0.5, R, 1E-4, delta)
    print(test)
    
    # test over x \in [0, ..., 10]
    xs = np.arange(0,1,step=0.001)
    #xs = np.append(xs, np.arange(1,10,step=1))
    y = np.array([])
    for x in xs:
        y = np.append(y, equalPercentage(1-x, R, l, delta))
        #y = np.append(y, equalPercentage(x, R, l, delta))
    y = 1 - y
    plt.plot(xs, y)  
    plt.show()
    

    # TODO: enable calling this function in model defintion
    """
    First: construct the function outside initialization,
    pass it as a separate object, which must be part of 
    namespace when init'ing DAE object.
    """
    data["m_flow"] = data.V_flow_219*1.293
    data["m_flow_bool"] = data["m_flow"].astype(bool).astype(int)
    data["u_val"] = data.val_pos_219
    data["y1"] = data["m_flow"]
    # filter deltaT:
    deltaT[deltaT < 0] = 0
    data["deltaT"] = deltaT

    functions = {
                 "equalPercentage": equalPercentage
                 }
    
    N = len(data)
    dt = (data.index[1] - data.index[0]).seconds
    # set range index for identification:
    data.index = range(0,N*dt,dt)

    param_guess = np.array([
                    7,
                    0.05])

    param_guess = np.array([
                    100,
                    1E-4,
                    1E-4,
                    0.005*1.293])
    
    lbp = param_guess
    ubp = param_guess
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    # set ub of all resistances to 1
    #for i in range(3):
    #    ubp[i] = 1
    len_p = param_guess.shape[0]
    #lbp[len_p-2] = 7
    #ubp[len_p-2] = 7
    lbp[len_p-4] = 1
    ubp[len_p-4] = 1000
    lbp[len_p-3] = 1E-6
    ubp[len_p-3] = 1E-1
    lbp[len_p-2] = 1E-6
    ubp[len_p-2] = 1E-1
    """
    lbp[len_p-1] = 0.001
    ubp[len_p-1] = 0.005*1.293
    lbp[len_p-2] = 7
    ubp[len_p-2] = 7
    """    
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess,
                             functions=functions) as param_est:

        Q = ca.DM.eye(1)
        R = ca.DM.eye(1)
        sol, params = param_est.solve(
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(R)
                                      )

        fig, axes = plt.subplots(2,1, sharex=True)
        
        ax = axes[0]
        sol["m_flow"].plot(ax=ax, color="r", linewidth=0.75, drawstyle="steps-post")
        ax1 = ax.twinx()
        sol["u_val"].plot(ax=ax1, color="b", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", linestyle="dashed", ax=ax, drawstyle="steps-post")
        ax.legend(["model_flow", "measured"], loc="upper left")
        ax1.legend(["valve"], loc="upper right")
        
        ax = axes[1]
        data["deltaT"].plot(ax=ax, drawstyle="steps-post")
        plt.show()
        print(params)
        
        error = sol["m_flow"] - sol["y1"]
        #error[error < 2E-4] = 0
        autocorrelation_plot(error)
        plt.show()
        
        """
        Plot function model predictions,
        plot measured valve openings.
        """
        u_val = sol.u_val.sort_values()
        m_flow = sol["m_flow"][u_val.index]
        y1 = sol["y1"][u_val.index]
        # set index
        m_flow.index = u_val.values
        y1.index = u_val.values
       
        m_flow = pd.DataFrame(m_flow)
        m_flow["y1"] = y1
        m_flow["u_val"] = u_val.values
        
        # plot:
        ax = m_flow.m_flow.plot()
        # measured:
        m_flow.plot.scatter(ax=ax, x="u_val", y="y1", color="k")
        plt.show()
        
        
        
    param_est = ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=params)
    I = param_est.integrator
    print(I)
    #x0 = [293.15,293.15,0]
    x0 = sol[I.dae.x].iloc[0].values
    xs = np.array([])
    p = params
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

