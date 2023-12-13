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
from pandas.plotting import autocorrelation_plot
from ocp.filters import KalmanBucy
from utils import prepare_data
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    """
    Proof of concept for grey-box SYSID, ZEB Lab.
    Use room 219 first.
    """

    cfg_path = os.path.join("configs", "2R2C_det_vent_tvp_vent_cond_no_constr_no_adj_conns.json")
    #cfg_path = os.path.join("configs", "2R2C_det_vent_tvp_vent_cond.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    data_path = os.path.join("ZEBLab_2years_60m.csv")
    #data_path = os.path.join("ZEBLab_year_60m_old.csv")

    all_data = pd.read_csv(data_path, index_col=0)
    # leave out last:
    all_data = all_data[:-1]
    all_data.index = pd.to_datetime(all_data.index).tz_localize(None)
    all_data["P_rad_219"][all_data["P_rad_219"] > 2.0] = 2.0
    
    start = pd.Timestamp("2023-11-14 00:00")
    stop = pd.Timestamp("2023-11-28 00:00")
    #stop = pd.Timestamp("2023-11-13 00:00")
    #start = pd.Timestamp("2022-12-01 00:00")
    
    data = all_data.loc[start:stop]
    #data = data.interpolate()
    
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
        
    y_data = prepare_data(data)
    # some temps missing:
    y_data.phi_h = y_data.phi_h.ffill()
    y_data = y_data.bfill()
    #y_data["vent_on"] = (y_data["V_sup_air"] > 10).astype(int) 
    
    ax = y_data.Ti.plot()
    for col in ["T_207", "T_211", "T_213", "T_217"]:
        y_data[col].plot(ax=ax, linewidth=0.5)
    ax.legend()
    ax1 = ax.twinx()
    #data["phi_h_219"].plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="r")
    y_data.phi_h.plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    ax1.legend(["calculated from OE16 V_flow, delta T", ""])
    plt.show()
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification:
    y_data.index = range(0,N*dt,dt)

    param_guess = np.array([1e-02,
                    1e-02,
                    1e-01, 
                    1e-01,
                    1E6, #1E6,
                    1E6, #1E6,
                    1E7, #1E7,
                    1E6, #1E6,
                    10,
                    10,
                    0.5])
    
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    #lbp[1] = -1
    #ubp[1] = 1
    # constrain Rih to force Ch down:
    #ubp[3] = 1E-2
    #lbp[3] = 1E-5
    #ubp[3] = 10000
    #lbp[4] = 1E-4
    lbp[1] = 0
    lbp[1] = -100
    #
    lbp[3] = 0
    lbp[3] = -100
    #lbp[5] = -100
    #lbp[5] = 0
    #lbp[5] = -100
    #
    #lbp[5] = -1E7
    # Ci_a:
    lbp[5] = 0
    lbp[5] = -1E8
    ubp[5] = 1E8
    
    # Ce_a:
    lbp[7] = 0
    lbp[7] = -1E8
    ubp[7] = 1E8
    #lbp[9] = -1E9
    # Ch:
    #lbp[11] = 1E5
    #lbp[7] = 0
    len_p = param_guess.shape[0]
    #lbp[len_p-1] = 1E-3
    #ubp[len_p-7] = 1
    
    # constrain Ch:
    #ubp[len_p-3] = 1E8
    # constrain Ce_b:
    #lbp[7] = 1E6
    #ubp[7] = 1E9
    # set ub of all resistances to 1
    #for i in range(5):
    #    ubp[i] = 1
    
    # connections are weak,
    # let upper bound be large   
    #for n in range(1,4):
    #    ubp[len_p-n] = 1E4
    
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess


    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:

        Q = ca.DM.eye(2)
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
                                      #Ti_gt_Te=True,
                                      #Th_gt_Ti=True,
                                      #Ce_gt_Ch=True,
                                      #Ce_gt_Ci=True,
                                      x_guess=x_guess,
                                      Te_anti_bias=True,
                                      #Th_anti_bias=True,
                                      covar=ca.veccat(Q, R)
                                      )

        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.legend(["model", "measured"])
        plt.show()
        params.to_csv("results/params_envelope_tvp_2R2C_vent_no_conns.csv", index=True)
        print(params)
    # dump for plots:
    sol.to_csv("results/tvp_in_training_traj_2R2C_vent_no_conns.csv", index=True)

    """
    Take out validation data:
    """
    #start = pd.Timestamp("2023-11-27 00:00")
    start = stop # of training
    stop = pd.Timestamp("2023-12-05 00:00")
    
    data = all_data.loc[start:stop]
    data = data.interpolate()
    y_data = prepare_data(data)
    
    # constrain Ch:
    #ubp[len_p-3] = 1E8
    # constrain Ce_b:
    #lbp[7] = 1E6
    
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
    zs = np.array([])
    p = params #(data.m_flow - data.m_flow.shift(1)).plot(drawstyle="steps-post")
    g = I.g
    G = I.G # Newton-solver for algebraic system of equations
    # guess for z for the Newton-solver:
    #p_base = params[["Ce", "Ci", "Ch", "Rie", "Rea", "Ria", "Rih"]].values
    p_base = params[["Rie","Rea","Ci","Ce","Ai","Ae","alpha_vent"]].values
    p_mod = params[["Rie_a","Rea_a","Ci_a","Ce_a","Ai","Ae","alpha_vent"]].values
    # set last three to zero:
    p_mod[-3:] = [0,0,0]
    z_guess = params[["Ce", "Ci", "Rie", "Rea"]].values
    v = [0]
    N = len(y_data)
    for n in range(N):
        xs = np.append(xs, np.array(x0))
        u = y_data[I.dae.u_names].iloc[n].values
        r = y_data[I.dae.r_names].iloc[n].values
        
        #z = sol[I.dae.z].iloc[n].values
        # separate root-finding problem for values of z:
        z = G(z_guess, x0, u, p, v, 0, 0, 0)
        zs = np.append(zs, np.array(z))
        x0 = I.one_sample(x0,z,u,p,0,r,0)
        z_guess = z
        
    res = pd.DataFrame(data=xs.reshape(N, 2), columns=["Ti", "Te"])
    res.index = data.index
    y_data.index = data.index
    ax = res.Ti.plot(color="r")
    y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    y_data.Ta.plot(color="b", linestyle="dashed", linewidth=0.75, ax=ax)
    ax1 = ax.twinx()
    y_data.weeknd.plot(ax=ax1, color="y", linewidth=0.75)
    (y_data.phi_h/y_data.phi_h.max()).plot(ax=ax1, color="g", linewidth=0.75)
    ax.legend(["model", "measured"])
    plt.show()
    #ax = (res["Ti"] - data.Ti).plot()
    #plt.show()
    res.to_csv("results/tvp_validation_traj_2R2C_vent_no_conns.csv", index=True)
    
    """
    For time-varying EKF:
    """
    p_base = params.loc[["Rie",
                        "Rea",
                        "Ci",
                        "Ce",
                        "Ai",
                        "Ae",
                        "alpha_vent"
                        ]]
    
    p_mod = params.loc[["Rie_a",
                        "Rea_a",
                        "Ci_a",
                        "Ce_a",
                        "Ai",
                        "Ae",
                        "alpha_vent",
                        ]]
    # set last three to zero:
    p_mod[4:] = 0
    p_base.to_csv("results/tvp_params_base_2R2C_vent_no_conns.csv", index=True)
    p_mod.to_csv("results/tvp_params_mod_2R2C_vent_no_conns.csv", index=True)
    
    """
    Publication plots:
        - training fit (w/ power plotted on right side)
        - 
    """
    
    """
    SMALL_SIZE = 12
    MEDIUM_SIZE = 14
    BIGGER_SIZE = 16

    plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
    plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
    plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
    plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
    plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
    plt.rc('legend', fontsize=MEDIUM_SIZE)    # legend fontsize
    plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title
    
    from utils import journal_plot
    journal_plot(sol, "plots/training_fit.pdf")
    # append simulation result to validation data:
    y_data[res.columns] = res
    journal_plot(y_data, "plots/validation_fit.pdf")
    
    # look at autocorrelation of simulation error:
    autocorrelation_plot(sol.v1)
    plt.show()
    # look at distribution of simulation error:
    sol.v1.hist()
    plt.show()
    """