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
# text:
rc('mathtext', default='regular')
from utils import prepare_data
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    """
    Proof of concept for grey-box SYSID, ZEB Lab.
    Use room 219 first.
    """

    cfg_path = os.path.join("configs", "heating_curve_power_algebraic.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    data_path = os.path.join("ZEBLab_year_60m.csv")

    all_data = pd.read_csv(data_path, index_col=0)
    # leave out last:
    all_data = all_data[:-1]
    all_data.index = pd.to_datetime(all_data.index).tz_localize(None)
    all_data["P_rad_219"][all_data["P_rad_219"] > 2.0] = 2.0
    
    start = pd.Timestamp("2022-12-01 00:00")
    stop = pd.Timestamp("2022-12-15 00:00")
    all_data = all_data.loc[start:stop]
    # resample to 1 min, just to see:
    all_data = all_data.resample(rule="1min").ffill()
    all_data = prepare_data(all_data)
    """
    Try to plot.
    """
    
    # read valve data:
    data = pd.read_csv("ZEBLab_Tsup_valve_year_1m.csv")
    pdata = pd.read_csv("ZEBLab_Prad_year_1m.csv")
    pdata = pdata[["P_rad_219", "_time"]]
    data = data[1:-1]
    data.index = pd.to_datetime(data._time)
    data.index = data.index.tz_localize(None)
    pdata = pdata[1:-1]
    pdata.index = pd.to_datetime(pdata._time)
    pdata.drop(columns=["_time"], inplace=True)
    pdata.index = pdata.index.tz_localize(None)
    data = data.loc[start:stop]
    pdata = pdata.loc[start:stop]
    # merge:
    data = pd.merge(pdata, data, left_index=True, right_index=True)
    data = pd.merge(data, all_data, left_index=True, right_index=True)
    
    #valve_data = pd.read_csv("ZEBLab_valve_year_1m.csv")
    """
    Try to plot.
    """
    data.Tsup[data["Tsup"] > 43] = 43
    data.Tret[data["Tret"] > 43] = 43
    data.Tsup[data["P_rad_219"] > 3.5] = 3.5
    data.V_flow_219[data["V_flow_219"] > 0.005] = 0.005
    # bfill:
    data = data.interpolate()
    #data.drop(columns=["_time"], inplace=True)

    ax = data.T_amb.plot(drawstyle="steps-post")
    data.Tsup.plot(ax=ax, color="r", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
    data.Tret.plot(ax=ax, color="k", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
    data.Ti.plot(ax=ax, color="m", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    #data["val_pos_219"].plot(drawstyle="steps-post", ax=ax1, color="b", linewidth=0.5)
    data["V_flow_219"].plot(drawstyle="steps-post", ax=ax1, color="b", linewidth=0.5)
    plt.show()
    
    ax = data.T_amb.plot(drawstyle="steps-post")
    data.Tsup.plot(ax=ax, color="r", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
    data.Tret.plot(ax=ax, color="k", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
    data.Ti.plot(ax=ax, color="m", linewidth=0.5, linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    #data["val_pos_219"].plot(drawstyle="steps-post", ax=ax1, color="b", linewidth=0.5)
    data["P_rad_219"].plot(drawstyle="steps-post", ax=ax1, color="b", linewidth=0.5)
    plt.show()

    data["m_flow_bool"] = data["V_flow_219"].astype(bool).astype(int).shift(-1)
    #data["obj_weight"] = data.m_flow_bool.copy()
    #data[data.obj_weight == 0] = 0.01
    #data["y1"] = data["Tsup"]
    data["u_val"] = data["val_pos_219"]
    data["Ta"] = data["T_amb"]
    data["Prad"] = data["P_rad_219"]*1000
    data["Ta"] += 273.15
    data["Ti"] += 273.15
    data["Tsup"] += 273.15
    data["Tret"] += 273.15
    rho_air = 1.293 # [kg/m^3]
    data["m_flow"] = data["V_flow_219"]*rho_air*(1000/3600)
    data["y1"] = data["Tret"]
    data["y2"] = data["Tsup"]
    data["y3"] = data["Prad"]
    
    # only when valve is open do we care about heating curve:
    data = data[data.m_flow_bool > 0]
    
    #start = pd.Timestamp("2023-03-06 00:00")
    #stop = pd.Timestamp("2023-03-13 00:00")
    #data = data.loc[start:stop]
    #data = data.resample(rule="10min").mean()
    
    N = len(data)
    dt = (data.index[1] - data.index[0]).seconds
    # set range index for identification:
    data.index = range(0,N*dt,dt)

    param_guess = np.array([-15 + 273.15,
                            30 + 273.15,
                            0.2,
                            45 + 273.15,
                            0.5,
                            4200])
    lbp = param_guess
    ubp = param_guess
    
    
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    lbp[0] = -20 + 273.15
    ubp[0] = -10 + 273.15
    lbp[1] = 30 + 273.15
    ubp[1] = 47 + 273.15
    lbp[2] = 0.1
    ubp[2] = 0.9
    lbp[3] = 45 + 273.15
    ubp[3] = 47 + 273.15
    lbp[4] = 0.1
    ubp[4] = 0.5
    #lbp[5] = 0.1
    #ubp[5] = 0.5
    
    # set ub of all resistances to 1
    #for i in range(3):
    #    ubp[i] = 1
    len_p = param_guess.shape[0]
    #lbp[len_p-1] = 1E1
    #ubp[len_p-1] = 1E5



    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

        """
        Test integration first.
        """

        Q = ca.DM.eye(1)
        R = ca.DM.eye(3)
        R[2,2] = 1E-6
        sol, params = param_est.solve(
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(R)
                                      )

        fig, axes = plt.subplots(3,1, sharex=True)
        
        ax = axes[0]
        Tsup = sol["Tret"].sort_values(ascending=True)
        Tsup_act = sol["y1"][Tsup.index]
        Tsup.index = range(len(Tsup.index))
        Tsup_act.index = range(len(Tsup_act.index))
        Tsup_act = pd.DataFrame(Tsup_act)
        Tsup_act["time"] = Tsup_act.index
        Tsup.plot(ax=ax, color="k", linestyle="dashed", linewidth=1.0)
        Tsup_act.plot(kind="scatter" ,x="time", y="y1", ax=ax, color="r")
        ax.legend(["model", "measured"])
        
        ax = axes[1]
        Tsup = sol["Tsup"].sort_values(ascending=False)
        Tsup_act = sol["y2"][Tsup.index]
        Tsup.index = range(len(Tsup.index))
        Tsup_act.index = range(len(Tsup_act.index))
        Tsup_act = pd.DataFrame(Tsup_act)
        Tsup_act["time"] = Tsup_act.index
        Tsup.plot(ax=ax, color="k", linewidth=0.5)
        Tsup_act.plot(kind="scatter" ,x="time", y="y2", ax=ax, color="r")
        ax.legend(["model", "measured"])
        
        ax = axes[2]
        Prad = sol["Prad"].sort_values(ascending=False)
        Prad_act = sol["y3"][Prad.index]
        Prad.index = range(len(Prad.index))
        Prad_act.index = range(len(Prad_act.index))
        Prad_act = pd.DataFrame(Prad_act)
        Prad_act["time"] = Prad_act.index
        Prad.plot(ax=ax, color="k", linewidth=0.5)
        Prad_act.plot(kind="scatter" ,x="time", y="y3", ax=ax, color="r")
        ax.legend(["model", "measured"])
        
        plt.show()
        print(params)
        
        
        
        
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

