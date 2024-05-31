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
    
    cfg_path = os.path.join("configs", "2R2C_det.json")
    data_path = "data"
    #ekf_config = os.path.join(get_opt_config_path(), "2R2C_EKF.json")
    
    data1 = pd.read_csv("evenstad1_jan.csv", skiprows=[1,2,3], header=0, index_col=0)
    data2 = pd.read_csv("evenstad2_jan.csv",  skiprows=[1,2,3], header=0, index_col=0)
    data = pd.merge(data1, data2, left_index=True, right_index=True)
    temp_cols = [col for col in data.columns if "RT" in col \
        and "OE" not in col \
        and "40" not in col \
        and "50" not in col \
        #and "90" not in col \
        and "XS" not in col
            ]
    
    # resample to hour:
    weather = pd.read_csv("faavang.csv", index_col=0)
    weather.index = pd.to_datetime(weather.index).tz_localize(None)
    weather.columns = ["Ta", "phi_s"]
    data.index = pd.to_datetime(data.index)
    data = data.resample(rule="1H").asfreq()
    
    temps = data[temp_cols]
    #ax = temps.mean(axis=1).plot()
    ax = data["CE_36_01_RT43"].plot(drawstyle="steps-post")
    #outside = data["CE_36_01_RT90"]
    outside = weather.Ta
    #outside = -outside.abs()
    outside.plot(drawstyle="steps-post", ax=ax)
    data["CE_36_01_RT43XS"].plot(color="m", drawstyle="steps-post")
    ax1 = ax.twinx()
    #power = data["CE_HT_432_02XF53_INN_KWt"].apply(lambda x: str(x).replace(" ", "")).astype(float).diff()
    power = data["CE_32_01_OE50wh"].apply(lambda x: str(x).replace(" ", "")).astype(float).diff()
    mass_flow = data["3424_CE_ES_320_00_OE51m3"].apply(lambda x: str(x).replace(" ", "")).astype(float).diff()
    temp_diff = data["3424_CE_ES_320_00_OE51rt40"] - data["3424_CE_ES_320_00_OE51rt50"]
    power_inf = mass_flow*temp_diff*4.2
    #power.plot(ax=ax1, color="k")
    #power_inf.plot(ax=ax1, color="k", linestyle="dashed", drawstyle="steps-post")
    power.plot(ax=ax1, color="k", linestyle="dashed", drawstyle="steps-post")
    plt.show()
    # dt is 30 seconds:
    #data.index = pd.TimedeltaIndex(data["Unnamed: 0"])
    #data.index.name = "time"

    # try with 15 min, 5 min anything that might give a decent model
    # heat: resample with mean, i.e. integration
    # temperatures, solar irr: instantaneous sampling
    downsample = False
    sampling_time = "15min"
    dt = 900
    
    """
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
    
    fig, ax = plt.subplots(2,1)
    (y_data.Ti-273.15).plot(color="k", ax=ax[0])
    y_data.phi_h.plot(color="k", ax=ax[1])
    ax[0].set_ylabel(r"Temperature [$^\circ$C]")
    ax[1].set_ylabel(r"Power [W]")
    fig.tight_layout()
    plt.show()
    """
    
    #y_data = y_data.iloc[0:3]
    
    y_data = data
    y_data["phi_s"] = weather.phi_s
    y_data["Ti"] = data["CE_36_01_RT43"]
    y_data["Ta"] = outside
    y_data["phi_h"] = power*1000 # to W
    y_data["y1"] = y_data["Ti"]
    
    
    y_data = y_data[1:]
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0,N*dt, dt)
    
    param_guess = ca.DM([0.001,1,1E8,1E9,50])
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    #ubp = ca.DM([0.1,1,1E7,1E8,50])
    lbp = 0.0001*param_guess
    ubp = 1000*param_guess
    #param_guess = ca.DM([0.001,0.009,1,1E6,1E7,1])
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    #    with ParameterEstimation(config=cfg_path,
    #                             data=y_data,
    #                             param_guess=param_guess) as param_est:
    x_guess = np.array([
                        y_data.Ti.values.flatten(),
                        y_data.Ti.values.flatten()
                        ])
    lbx = 0.9*x_guess
    ubx = 1.1*x_guess
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             lbx=lbx,
                             ubx=ubx,
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
                                      y_data,
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
        