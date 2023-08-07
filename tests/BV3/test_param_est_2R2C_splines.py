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
    
    data = pd.read_csv("bv3_5splines.csv", index_col=1)
    # TODO: merge radiator temps with above data
    # rename data
    data = data.rename(
                        columns={"qh": "phi_h",
                                 "yTi": "y1",
                                 "Isol": "phi_s",
                                 "Te": "Ta"
                                 }
                      )
    data["Ti"] = data.y1
    cfg_path = "2R2C_splines.json"
    N = len(data)
    dt = 900
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    #param_guess = ca.DM([0.01,0.01,1E7,1E7,1,1,1,1,1])
    param_guess = ca.DM([0.1,0.1,1E7,1E7,0.2,1,1,1,1,1])
    #ubp = ca.DM([0.1,1,1E7,1E8,50])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = param_guess*1000
    lbp = param_guess*0.001
    lbp[4] = 0.01
    ubp[4] = 1
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    #    with ParameterEstimation(config=cfg_path,
    #                             data=y_data,
    #                             param_guess=param_guess) as param_est:
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        #Q[0,0] = 6.55919266e-01
        #Q[1,1] = 4.52496393e-01
        #Q[1,0] = 0.01
        #Q[0,1] = 0.01
        R = ca.DM.eye(1)
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

        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", linestyle="dashed", ax=ax)
        ax.legend()
        plt.show()
        print(params)
        