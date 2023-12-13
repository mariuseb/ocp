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

    cfg_path = os.path.join("configs", "3R3C_det_vent_all_conns.json")
    sol = pd.read_csv("L_in_training_traj.csv", index_col=0)
    params = pd.DataFrame(pd.read_csv("params_envelope_linear.csv", index_col=0))

    data_path = os.path.join("ZEBLab_year_60m.csv")
    all_data = pd.read_csv(data_path, index_col=0)
    # leave out last:
    all_data = all_data[:-1]
    all_data.index = pd.to_datetime(all_data.index).tz_localize(None)
    all_data["P_rad_219"][all_data["P_rad_219"] > 2.0] = 2.0
    
    #start = pd.Timestamp("2023-11-20 00:00")
    #stop = pd.Timestamp("2023-11-27 00:00")
    #start = pd.Timestamp("2022-12-01 00:00")
    #stop = pd.Timestamp("2022-12-15 00:00")
    
    #data = all_data.loc[start:stop]
    #data = data.interpolate()

    """
    Take out validation data:
    """
    start = pd.Timestamp("2023-11-20 00:00")
    stop = pd.Timestamp("2023-11-27 00:00")
    #start = pd.Timestamp("2023-11-27 00:00")
    #stop = pd.Timestamp("2023-12-04 00:00")
    
    data = all_data.loc[start:stop]
    data = data.interpolate()
    y_data = prepare_data(data)
    
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification:
    y_data.index = range(0,N*dt,dt)
    # constrain Ch:
    #ubp[len_p-3] = 1E8
    # constrain Ce_b:
    #lbp[7] = 1E6
    
    param_est = ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=params.values.flatten())
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
    p = params.values.flatten() #(data.m_flow - data.m_flow.shift(1)).plot(drawstyle="steps-post")
    g = I.g
    G = I.G # Newton-solver for algebraic system of equations
    # guess for z for the Newton-solver:
    #p_base = params[["Ce", "Ci", "Ch", "Rie", "Rea", "Ria", "Rih"]].values
    p_base = params.loc[["Rie",
                         "Rea",
                         "Rih",
                         "Ria",
                         "Ci",
                         "Ce",
                         "Ch",
                         "Ai",
                         "Ae",
                         "alpha_vent",
                         "Rig",
                         "R_121_e",
                         "R_321_e",
                         "R_320_e",
                         "R_121_i",
                         "R_321_i",
                         "R_320_i"
                         ]
                        ].values.flatten()
    # set last three to zero:
    #p_mod[-10:] = [0]*10
    #z_guess = params.loc[["Ce", "Ci", "Ch", "Rie", "Rea", "Ria", "Rih"]].values.flatten()
    v = [0]
    N = len(y_data)
    for n in range(N):
        xs = np.append(xs, np.array(x0))
        u = y_data[I.dae.u_names].iloc[n].values
        r = y_data[I.dae.r_names].iloc[n].values
        
        #z = sol[I.dae.z].iloc[n].values
        # separate root-finding problem for values of z:
        #z = G(z_guess, x0, u, p, v, 0, 0, 0)
        #zs = np.append(zs, np.array(z))
        x0 = I.one_sample(x0,0,u,p,0,r,0)
        #z_guess = z
        
    res = pd.DataFrame(data=xs.reshape(N, 3), columns=["Ti", "Te", "Th"])
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
    res.to_csv("L_validation_traj.csv", index=True)
    
    """
    Publication plots:
        - training fit (w/ power plotted on right side)
        - 
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
    
    
    """
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
    
    """
    Get one-step ahead error (simulate one-step ahead 
    with Kalman feedback):
    
    TODO: create config-file for Kalman filter of
    time-varying model.
    -> quick solution: two different filters.
    
    Create external loop for one-step prediction.
    """
    cfg = "configs/ekf_configs/4R3C_envelope_EKF.json"
    ekf = KalmanBucy(cfg)
    
    """
    Q = np.diag([1,1,1])
    R = np.diag([1])
    ekf_base.set_Q(Q)
    ekf_base.set_R(R)
    ekf_weeknd.set_Q(Q)
    ekf_weeknd.set_R(R)
    """
    
    # set R, Q? P0?
    N = len(y_data)
    
    result = pd.DataFrame(
                            index=range(N-1),
                            columns=["res", "y_pred","y_meas","x_filt"]
                            )
    
    
    #start = pd.Timestamp("2023-11-20 00:00")
    #stop = pd.Timestamp("2023-11-24 00:00")
    
    #data = all_data.loc[start:stop]
    #data = data.interpolate()
    #y_data = prepare_data(data)
    
    I = ekf.integrator.one_sample
    x0 = sol[ekf.dae.x].iloc[0].values
    #x0 = sol[ekf.dae.x].iloc[-1].values
    
    p = p_base
    for n in range(N-1):
        
        u = y_data[ekf.dae.u_names].iloc[n].values
        r = y_data[ekf.dae.r_names].iloc[n].values
            
        # noiseless model prediction:
        x_pred = I(x0,0,u,p,0,r,0)
        
        # filtering of prediction:s
        x0 = ekf.estimate(
                          x_pred,
                          p=p,
                          y=y_data[ekf.dae.y_names].iloc[n+1].values,
                          u=y_data[ekf.dae.u].iloc[n].values,
                          r=y_data[ekf.dae.r_names].iloc[n].values
                          )
        #result.loc[n, "res"] = float(y_data[ekf.dae.y_names].iloc[n+1] - x_pred[0])
        result.loc[n, "res"] = (y_data[ekf.dae.y_names].iloc[n+1].values - np.array(x_pred[0,0]))[0][0]
        #result.loc[n, "y_pred"] = np.array(x_pred[0, 0])[0][0]
        result.loc[n, "y_pred"] = float(x_pred[0])
        result.loc[n, "y_meas"] = float(y_data[ekf.dae.y_names].iloc[n+1].values)
        result.loc[n, "x_filt"] = x0[0]
        
    ax = result["y_meas"].plot(color="k", linewidth=0.5)
    result["y_pred"].plot(color="r", linestyle="dashed", linewidth=0.5, ax=ax)
    plt.show()
    
    """
    autocorrelation_plot(result.res)
    plt.show()
    
    result.res.hist(bins=30)
    plt.show()
        
    sol.v1.hist(bins=30)
    plt.show()
    """
    
    """
    Plot residuals over fitted normal distributions.
    """
    from utils import plot_residuals
    plot_residuals(result, sol, "Residuals, training")
    
    #import pandas as pd
    import rpy2
    import rpy2.robjects as robjects
    
    r = robjects.r
    r.X11()

    #r.layout(r.matrix(robjects.IntVector([1,2,3,2]), nrow=2, ncol=2))
    #r.plot(r.runif(10), y, xlab="runif", ylab="foo/bar", col="red")

    """
    acf(x, lag.max = NULL,
        type = c("correlation", "covariance", "partial"),
        plot = TRUE, na.action = na.fail, demean = TRUE, ...)
    """

    r.acf(robjects.FloatVector(result.res), 
        lag_max=8*24,
        #type = robjects.StrVector(["correlation", "covariance", "partial"]),
        plot = True)


    r.cpgram(robjects.FloatVector(result.res), main="Cumulated periodogram")

    """
    acf(Dat$residuals, lag.max=8*24, main="ACF of residuals")
    title(main=as.character(match.call())[2],line=-2,cex.main=2)
    ## The periodogram is the estimated energy spectrum in the signal
    spec.pgram(Dat$residuals, main="Raw periodogram")
    ## The cumulated periodogram 
    cpgram(Dat$residuals, main="Cumulated periodogram")
    """
    
    print(p)