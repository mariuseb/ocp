#from ast import Param
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
import matplotlib.dates as mdates

if __name__ == "__main__":
    
    df = pd.read_csv("PRBSData_5min.csv", index_col=0)
    df.index = pd.to_datetime(df.index)
    #rad_temps = df[[col for col in df.columns if col.startswith("T") and "Rad" in col]]
    #room_temps = df[[col for col in df.columns if col.startswith("6")]]
    temp_cols = ["6S-611", "6S-617", "6S-615", "6S-614", "6S-620", "6S-613"]
    east_cols = ["6S-611", "6S-614", "6S-613"]
    west_cols = ["6S-617", "6S-615","6S-620"]
    west = df[west_cols].mean(axis=1).resample(rule="15min").asfreq()
    east = df[east_cols].mean(axis=1).resample(rule="15min").asfreq()
    #temps = pd.DataFrame(data=[west, east], columns=["Ti_west", "Ti_east"])
    temps = pd.concat([west, east], axis=1)
    temps.columns = ["Ti_west", "Ti_east"]
    power = df[['P_radE', 'P_radW']]
    power[power < 0] = 0
    # resample to 15min:
    power = power.resample(rule="15min").mean()
    extra = pd.concat([temps, power], axis=1)
    
    data = pd.read_csv("bv3_5splines.csv", index_col=1)
    
    # align axis:
    extra = extra.iloc[0:len(data)]
    extra.index = data.index
    
    data = pd.concat([data, extra], axis=1)
    
    """
    # plot temperature, power:
    s = max(data.P_radE)/max(data.phi_s)
    fig, ax = plt.subplots(2,1, sharex=True)
    #ax00 = ax[0].twinx()
    data.Ti_east.plot(ax=ax[0])
    ax0 = ax[0].twinx()
    data.P_radE.plot(ax=ax0, color="r", linestyle="dashed")
    (data.phi_s*s).plot(ax=ax0, color="y", linestyle="dashed")
    
    ax1 = ax[1].twinx()
    data.Ti_west.plot(ax=ax[1])
    data.P_radW.plot(ax=ax1, color="r", linestyle="dashed")
    (data.Isol*s).plot(ax=ax1, color="y", linestyle="dashed")
    plt.show()
    """
    
    data = data.rename(
                        columns={"qh": "phi_h",
                                 "yTi": "y1",
                                 "Isol": "phi_s",
                                 "Te": "Ta",
                                 "Ti_east": "Ti1",
                                 "Ti_west": "Ti2",
                                 "P_radE": "phi_h1",
                                 "P_radW": "phi_h2"
                                 }
                      )
    
    # TODO: merge radiator temps with above data
    # rename data
    #data["y1"] = data["Ti_east"]
    #data["y2"] = data["Ti_west"]
    data["y1"] = data["Ti1"]
    data["y2"] = data["Ti2"]
    #cfg_path = "2R2C_splines.json"
    cfg_path = "5R4C.json"
    N = len(data)
    dt = 900
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    #param_guess = ca.DM([0.01,0.01,1E7,1E7,1,1,1,1,1])
    #param_guess = ca.DM([0.1,0.1,1E7,1E7,0.2,1,1,1,1,1])
    """
        "p": [
                "Rie1",
                "Rea1",
                "Ci1",
                "Ce1",
                "Ai1",
                "Rie2",
                "Rea2",
                "Rii",
                "Ree",
                "Ci2",
                "Ce2",
                "Ai2",
                "alpha1",
                "alpha2"
        ],
    """
    param_guess = ca.DM(
                        [
                         0.1,
                         0.1,
                         1E6,
                         1E7,
                         5,
                         0.1,
                         0.1,
                         1E6,
                         1E7,
                         5,
                         0.15,
                         0.15,
                         0.01,
                         0.01
                         ]
                    )
    #ubp = ca.DM([0.1,1,1E7,1E8,50])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = param_guess*10000
    lbp = param_guess*0.0001
    len_p = param_guess.shape[0]
    lbp[len_p-3] = 0.15
    ubp[len_p-3] = 0.15
    lbp[len_p-4] = 0.15
    ubp[len_p-4] = 0.15
    lbp[5] = 1E-4
    lbp[6] = 1E-4
    lbp[0] = 1E-4
    lbp[1] = 1E-4
    
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    #    with ParameterEstimation(config=cfg_path,
    #                             data=y_data,
    #                             param_guess=param_guess) as param_est:
    
    kwargs = {
                "x_nom": 12,
                "x_nom_b": 289.15,
                "u_nom": [5000, 5000, 12, 300],
                "u_nom_b": [0, 0, 289.15, 0],
                "slack": False
            }
    
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(4)
        #Q[0,0] = 6.55919266e-01
        #Q[1,1] = 4.52496393e-01
        #Q[1,0] = 0.01
        #Q[0,1] = 0.01
        R = ca.DM.eye(2)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        #grad_f = ca.gradient(param_est.nlp["f"], param_est.nlp["x"])
        #grad_f_f = ca.Function("grad_f", [param_est.nlp["x"]], [grad_f])
        
        sol, params = param_est.solve(
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )

        """
        Rie    2.116711e-02
        Rea    1.245725e-01
        Ci     1.627226e+05
        Ce     1.403086e+08
        Ai     2.355363e+01
        """

        fig, ax = plt.subplots(2,1)
        sol["Ti1"].plot(ax=ax[0], color="r")
        sol["y1"].plot(color="k", linestyle="dashed", ax=ax[0])
        sol["Ti2"].plot(ax=ax[1], color="r")
        sol["y2"].plot(color="k", linestyle="dashed", ax=ax[1])
        ax[0].legend()
        ax[1].legend()
        plt.show()
        print(params)
        