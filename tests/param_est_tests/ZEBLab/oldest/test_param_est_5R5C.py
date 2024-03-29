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

    cfg_path = os.path.join("configs", "5R5C_det.json")
    data_path = os.path.join("ZEBLab_year_60m.csv")

    data = pd.read_csv(data_path, index_col=0)
    # leave out last:
    data = data[:-1]
    data.index = pd.to_datetime(data.index).tz_localize(None)
    
    start = pd.Timestamp("2022-12-06 00:00")
    stop = pd.Timestamp("2022-12-10 00:00")
    #stop = pd.Timestamp("2023-02-02 00:00")
    
    data = data.loc[start:stop]
    
    # linearly interpolate nan's
    data = data.interpolate()
    
    """
    Go from l/h to kg/s for power calculation
    Water rho ~ 1 kg/m^3, hence l/h to kg/s ~1/3600
    Ph ≃ cp_water*m_flow*ΔT,
        where cp_water ≃ 4200 [J/(kg*K)]
    """
    cp_water = 4200
    data.V_flow_219 /= 3600
    data.V_flow_220 /= 3600
    data["phi_h_219"] = cp_water*data["V_flow_219"]*(data['T_sup_219'] - data['T_ret_219'])
    #data["phi_h_220"] = cp_water*data["V_flow_220"]*(data['T_sup_220'] - data['T_ret_220'])
    
    # do a plot of phi_h vs 219 temps
    temps_219_cols = [col for col in data.columns if "T_219" in col]
    #temps_219 = data[temps_219_cols]
    temps_219 = data[temps_219_cols].mean(axis=1)
    ax = temps_219.plot()
    ax1 = ax.twinx()
    data["phi_h_219"].plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="r")
    plt.show()
    
    data["phi_h"] = data["phi_h_219"]
    data["Ti"] = temps_219 # take avg (of different heights?)
    #data["Ti"] = data['T_219_TR4']
    data["phi_s"] = data["I_ver"]
    data["Ta"] = data["T_amb"]
    data["y1"] = data["Ti"]
    
    N = len(data)
    dt = (data.index[1] - data.index[0]).seconds
    # set range index for identification:
    data.index = range(0,N*dt,dt)

    param_guess = ca.DM([1.55283967e-02,
                    2.71222840e-01, 
                    5.36453127e-02,
                    5.36453127e-02,
                    5.36453127e-02,
                    8.45898126e+05,
                    1.78899445e+06, 
                    1.18504937e+07,
                    1.18504937e+05,
                    1.18504937e+05,
                    6.42261677e-01])
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    #ubp[1] = 0.1
    
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    data.Ti.values.flatten(),
                    data.Ti.values.flatten(),
                    data.Ti.values.flatten(),
                    data.Ti.values.flatten(),
                    data.Ti.values.flatten()
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess


    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(5)
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
        from cvxpy with first solution:
        [[6.55919266e-01 5.26466051e-12]
        [5.26466051e-12 4.52496393e-01]]

        params after first solve:
        Rie    1.532625e-03
        Rea    1.160423e-02
        Ci     1.328633e+06
        Ce     6.644898e+06
        Ai     5.578587e+00

        params after second solve:
        Rie    1.567088e-03
        Rea    1.160390e-02
        Ci     1.337609e+06
        Ce     6.747752e+06
        Ai     5.132032e+00m here we k

        Does it change the physical parameters any???

        """
        sol, params = param_est.solve(
                                      data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      covar=ca.veccat(Q, R)
                                      )

        ax = sol["Ts"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend()
        plt.show()
        print(params)

