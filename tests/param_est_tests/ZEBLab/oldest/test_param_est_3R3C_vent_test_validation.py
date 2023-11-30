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

    cfg_path = os.path.join("configs", "3R3C_det_vent.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    data_path = os.path.join("ZEBLab_year_60m.csv")

    all_data = pd.read_csv(data_path, index_col=0)
    # leave out last:
    all_data = all_data[:-1]
    all_data.index = pd.to_datetime(all_data.index).tz_localize(None)
    all_data["P_rad_219"][all_data["P_rad_219"] > 2.0] = 2.0
    
    start = pd.Timestamp("2023-03-06 00:00")
    stop = pd.Timestamp("2023-03-13 00:00")
    
    data = all_data.loc[start:stop]
    data = data.interpolate()
    
    """
    Go from l/h to kg/s for power calculation
    Water rho ~ 1 kg/m^3, hence l/h to kg/s ~1/3600
    Ph ≃ cp_water*m_flow*ΔT,
        where cp_water ≃ 4200 [J/(kg*K)]
    """
    
    """
    TODO:
        - make convenience functions for some
        manipulation of the data.
    """
    
    def prepare_data(data):
        """
        Prepare data for identification.
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
        (data["P_rad_219"]*1000).plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
        ax1.legend(["calculated from OE16 V_flow, delta T", ""])
        plt.show()
        
        #y_data = data[["phi_h_219"]]
        y_data = data[["P_rad_219"]]*1000
        y_data.columns = ["phi_h"]
        
        # ventilation:
        y_data["T_ext_air"] = data["T_ext_air_219"]
        y_data["T_sup_air"] = data["T_sup_air_219"]
        y_data["V_ext_air"] = data["V_ext_air_219"]
        y_data["V_sup_air"] = data["V_sup_air_219"]
        
        #data["phi_h"] = data["phi_h_219"]
        y_data["Ti"] = temps_219 # take avg (of different heights?)
        #data["Ti"] = data['T_219_TR4']
        y_data["phi_s"] = data["I_ver"]
        y_data["Ta"] = data["T_amb"]
        y_data["y1"] = y_data["Ti"]
        
        return y_data
    
    y_data = prepare_data(data)
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification:
    y_data.index = range(0,N*dt,dt)

    param_guess = np.array([1.55283967e-02,
                    2.71222840e-01, 
                    5.36453127e-03,
                    5.36453127e-02,
                    1E6,
                    5E6,
                    1E6, 
                    6.42261677e-01,
                    0.5])
    
    lbp = 0.01*param_guess
    ubp = 100*param_guess
    lbp[1] = -1
    ubp[1] = 1
    # constrain Rih to force Ch down:
    #ubp[3] = 1E-2
    #lbp[3] = 1E-6
    #
    len_p = param_guess.shape[0]
    lbp[len_p-1] = 1E-3
    ubp[len_p-1] = 1
    # window area
    lbp[len_p-2] = 1
    # constrain Ch:
    #ubp[len_p-3] = 1E8
    # constrain Ce_b:
    #lbp[7] = 1E6
    #ubp[7] = 1E9
    # set ub of all resistances to 1
    #for i in range(5):
    #    ubp[i] = 1
    
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2,
                    y_data.Ti.values.flatten() + 5
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess


    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(3)
        R = ca.DM.eye(1)

        """
        Prior to solving, 
        add constraint:
        Ce - Ci >= 0
        
        Ce_b = param_est.get("Ce_b")
        Ci_b = param_est.get("Ci_b")
        constr = Ce_b - Ci_b
        
        param_est.nlp["g"] = ca.vertcat(param_est.nlp["g"], constr)
        param_est.lbg
        
        TODO: figure out how to do it nicely
        """
        
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      Ti_gt_Te=True,
                                      Th_gt_Ti=True,
                                      Ce_gt_Ch=True,
                                      covar=ca.veccat(Q, R)
                                      )

        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend(["model", "measured"])
        plt.show()
        print(params)
    # dump for plots:
    sol.to_csv("NL_in_training_traj.csv", index=True)

    """
    Take out validation data:
    """
    start = pd.Timestamp("2023-03-13 00:00")
    stop = pd.Timestamp("2023-03-27 00:00")
    
    data = all_data.loc[start:stop]
    data = data.interpolate()
    y_data = prepare_data(data)
    
    param_est = ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=np.array(params))
    I = param_est.integrator
    print(I)
    """
    Adjacent data, 
    extract last estimated state
    """
    x0 = sol[I.dae.x].iloc[-1].values
    #x0 = sol[I.dae.x].iloc[0].values
    xs = np.array([])
    p = params
    
    N = len(y_data)
    
    for n in range(N):
        xs = np.append(xs, np.array(x0))
        u = y_data[I.dae.u_names].iloc[n].values
        r = y_data[I.dae.r_names].iloc[n].values
        """
        Simple solution to p/z problem for now:
        Check if V_sup_air > 0. If so, then add
        modifiers.
        """
        z = 0
        #z_alt = sol[I.dae.z].iloc[n].values
        #zs.loc[n] = [z[0], z_alt[0]]
        x0 = I.one_sample(x0,z,u,p,0,r,0)
        
    res = pd.DataFrame(data=xs.reshape(N, 3), columns=["Ti", "Te", "Th"])
    res.index = data.index
    y_data.index = data.index
    ax = res.Ti.plot(color="r")
    y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    ax.legend(["model", "measured"])
    plt.show()
    #ax = (res["Ti"] - data.Ti).plot()
    #plt.show()
    res.to_csv("NL_validation_traj.csv", index=True)
    print(p)