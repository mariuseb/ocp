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
    data_path = os.path.join("ZEBLab_year_60m.csv")

    data = pd.read_csv(data_path, index_col=0)
    # leave out last:
    data = data[:-1]
    data.index = pd.to_datetime(data.index).tz_localize(None)
    
    #start = pd.Timestamp("2022-12-05 00:00")
    #stop = pd.Timestamp("2022-12-10 00:00")
    #start = pd.Timestamp("2023-03-06 00:00")
    #stop = pd.Timestamp("2023-03-13 00:00")
    #stop = pd.Timestamp("2023-02-02 00:00")
    
    #data = data.loc[start:stop]
    
    # linearly interpolate nan's
    data = data.interpolate()
    
    """
    Go from l/h to kg/s for power calculation
    Water rho ~ 1000 kg/m^3, hence l/h to kg/s ~1/3600
    Ph ≃ cp_water*m_flow*ΔT,
        where cp_water ≃ 4200 [J/(kg*K)]
        
    Air rho ~ 1.225 kg/m^3.
    Given volume flow is in m^3/h.
    Want kg/s.
    cp_air ~ 1000 [J/(kg*K )]
    
    """
    cp_water = 4200
    cp_air = 1000
    data.V_flow_219 /= 3600
    data.V_ext_air_219 *= (1.225/3600)
    data.V_sup_air_219 *= (1.225/3600)
    data.V_flow_220 /= 3600
    data["phi_h_219"] = cp_water*data["V_flow_219"]*(data['T_sup_219'] - data['T_ret_219'])
    #data["phi_h_220"] = cp_water*data["V_flow_220"]*(data['T_sup_220'] - data['T_ret_220'])
    data["P_rad_219"][data["P_rad_219"] > 2] = 2
    data["V_flow_219"][data["V_flow_219"] > 0.04] = 0.04
    
    # do a plot of phi_h vs 219 temps
    temps_219_cols = [col for col in data.columns if "T_219" in col]
    #temps_219 = data[temps_219_cols]
    temps_219 = data[temps_219_cols].mean(axis=1)
    
    # set for identification:
    data["phi_h"] = data["phi_h_219"]
    data["Ti"] = temps_219 # take avg (of different heights?)
    #data["Ti"] = data['T_219_TR4']
    data["phi_s"] = data["I_ver"] # + data["I_hor"]
    data["Ta"] = data["T_amb"]
    data["T_ext_air"] = data["T_ext_air_219"]
    data["T_sup_air"] = data["T_sup_air_219"]
    data["V_ext_air"] = data["V_ext_air_219"]
    data["V_sup_air"] = data["V_sup_air_219"]
    data["y1"] = data["Ti"]
    # vent ca.
    data["P_vent_in_219"] = cp_air*data["V_sup_air_219"]*(data['T_sup_air_219'] - temps_219)
    data["P_vent_out_219"] = cp_air*data["V_ext_air_219"]*(temps_219 - data['T_ext_air_219'])
    # plot temp:
    ax = temps_219.plot()
    data["T_ext_air_219"].plot(color="m")
    data["T_sup_air_219"].plot(color="g")
    ax1 = ax.twinx()
    data["phi_h_219"].plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="r")
    data["P_vent_in_219"].plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    data["phi_s"].plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="y")
    #data["P_vent_out_219"].plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    #data["P_vent_out_219"].plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="y")
    ax.legend(loc="upper left")
    ax1.legend(loc="upper right")
    plt.show()
    
    val_219 = data["val_219"].sort_values(ascending=True)
    flow_219 = data["V_flow_219"][val_219.index]
    val_219.index = range(len(val_219))
    flow_219.index = range(len(val_219))
    ax = flow_219.plot(color="k", linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    val_219.plot(ax=ax1, color="r", linewidth=3, drawstyle="steps-post")
    ax.legend(["flow [kg/s]"], loc="upper left")
    ax1.legend(["valve [%]"], loc="upper right")
    
    plt.show()
    
    val_219 = data["val_219"]
    flow_219 = data["V_flow_219"][val_219.index]
    #val_219.index = range(len(val_219))
    #flow_219.index = range(len(val_219))
    ax = flow_219.plot(color="k", linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    val_219.plot(ax=ax1, color="r", linewidth=1, drawstyle="steps-post")
    ax.legend(["flow [kg/s]"], loc="upper left")
    ax1.legend(["valve [%]"], loc="upper right")
    
    plt.show()

    val_219 = data["val_219"]
    flow_219 = data["P_rad_219"][val_219.index]
    #val_219.index = range(len(val_219))
    #flow_219.index = range(len(val_219))
    ax = flow_219.plot(color="k", linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    val_219.plot(ax=ax1, color="r", linewidth=1, drawstyle="steps-post")
    ax.legend(["flow [kg/s]"], loc="upper left")
    ax1.legend(["valve [%]"], loc="upper right")
    
    plt.show()
    
    val_219 = data["val_219"].sort_values(ascending=True)
    flow_219 = data["P_rad_219"][val_219.index]
    val_219.index = range(len(val_219))
    flow_219.index = range(len(val_219))
    ax = flow_219.plot(color="k", linestyle="dashed", drawstyle="steps-post")
    ax1 = ax.twinx()
    val_219.plot(ax=ax1, color="r", linewidth=3, drawstyle="steps-post")
    ax.legend(["flow [kg/s]"], loc="upper left")
    ax1.legend(["valve [%]"], loc="upper right")
    
    plt.show()
    
    """
    Function equalPercentage
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
    
    

    # TODO: enable calling this function in model defintion
    """
    First: construct the function outside initialization,
    pass it as a separate object, which must be part of 
    namespace when init'ing DAE object.
    """

    functions = {
                 "equalPercentge": equalPercentage
                 }
    
    N = len(data)
    dt = (data.index[1] - data.index[0]).seconds
    # set range index for identification:
    data.index = range(0,N*dt,dt)

    param_guess = ca.DM([
                    0.5,
                    100,
                    1E-4,
                    0.05])
    
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    # set ub of all resistances to 1
    #for i in range(3):
    #    ubp[i] = 1
    len_p = param_guess.shape[0]
    lbp[len_p-1] = 0.001
    ubp[len_p-1] = 1



    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(3)
        #Q[0,0] = 6.55919266e-01
        #Q[1,1] = 4.52496393e-01
        #Q[1,0] = 0.01
        #Q[0,1] = 0.01
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        #grad_f = ca.gradient(param_est.nlp["f"], param_est.nlp["x"])
        #grad_f_f = ca.Function("grad_f", [param_est.nlp["x"]], [grad_f])

        """
        Rie           5.002394e-01
        Rea           1.357341e+01
        Rih           2.553686e+00
        Ci            1.632427e+07
        Ch            5.946360e+08
        Ce            8.986151e+07
        Ai            2.764484e+01
        alpha_vent    5.115932e-01

        """
        sol, params = param_est.solve(
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )

        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend()
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
