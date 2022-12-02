#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.covar_solve import CovarianceSolver
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
    
    cfg_path = os.path.join(get_opt_config_path(), "2R2C.json")
    data_path = os.path.join(get_data_path(), "data_ZEBLL_PRBS.csv")
    
    data = pd.read_csv(data_path)
    # dt is 30 seconds:
    data.index = pd.TimedeltaIndex(data["Unnamed: 0"])
    data.index.name = "time"

    # try with 15 min, 5 min anything that might give a decent model
    # heat: resample with mean, i.e. integration
    # temperatures, solar irr: instantaneous sampling
    downsample = True
    sampling_time = "15min"
    dt = 900
    
    if downsample:
        
        heat = data[["phi_h", "phi_s"]]
        heat = heat.resample(sampling_time).mean()

        rest = data[["Ti", "Ta"]]
        rest = rest.resample(sampling_time).first()

        y_data = pd.merge(heat, rest, left_index=True, right_index=True)
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*900, 900)
        
    else:
        
        y_data = data
        y_data["y1"] = y_data.Ti
        y_data.index = np.arange(0, len(y_data)*30, 30)
    
    """
    fig, ax = plt.subplots(2,1)
    (y_data.Ti-273.15).plot(color="k", ax=ax[0])
    y_data.phi_h.plot(color="k", ax=ax[1])
    ax[0].set_ylabel(r"Temperature [$^\circ$C]")
    ax[1].set_ylabel(r"Power [W]")
    fig.tight_layout()
    plt.show()
    """

    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    param_guess = ca.DM([0.01,0.1,1E6,1E7,2])
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,1,1E7,1E8,50])

    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)
    params = {}
    covar = {}
        
    for i in range(3):

        param_est = ParameterEstimation(config=cfg_path,
                                        N=N,
                                        dt=dt,
                                        param_guess=param_guess)
        
        sol, param_guess = param_est.solve(
                                           y_data,
                                           param_guess,
                                           lbp=lbp,
                                           ubp=ubp,
                                           covar=ca.veccat(Q, R)
                                           )
        
        v = sol[["v1"]].values.T
        w = sol[["w1", "w2"]].values.T
        
        covar_est = CovarianceSolver(v, w)
        
        #R, Q = covar_est.solve(warmstart=True,
        #                       R=np.array(R),
        #                       Q=np.array(Q))
        
        R, Q = covar_est.solve()
        
        #Q[0,1] = 0
        #Q[1,0] = 0
        
        params[str(i)] = param_guess
        covar[str(i)] = {"R": R, "Q": Q}
        
    ax = sol["Ti"].plot(color="grey")
    ax = y_data["Ti"].plot(color="black", linestyle="dashed")
    ax.legend(["Estimated", "True"])
    plt.show()