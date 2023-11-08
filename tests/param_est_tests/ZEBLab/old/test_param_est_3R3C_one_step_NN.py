#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
from ocp.mhe import MHE
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
import torch
from nn import ParamDataset, NN, Trainer, get_train_config
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

    #cfg_path = os.path.join("configs", "3R3C_vent_sup_det_tvp.json")
    cfg_path = os.path.join("configs", "3R3C_vent_ext_det.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    data_path = os.path.join("ZEBLab_year_15m.csv")

    data = pd.read_csv(data_path, index_col=0)
    # leave out last:
    data = data[:-1]
    data.index = pd.to_datetime(data.index).tz_localize(None)
    
    #start = pd.Timestamp("2022-12-05 00:00")
    #stop = pd.Timestamp("2022-12-10 00:00")
    start = pd.Timestamp("2023-03-06 00:00")
    stop = pd.Timestamp("2023-03-13 00:00")
    #stop = pd.Timestamp("2023-02-02 00:00")
    
    data = data.loc[start:stop]
    
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
    
    #data = data.iloc[:10]
    N = len(data)
    dt = (data.index[1] - data.index[0]).seconds
    # set range index for identification:
    data.index = range(0,N*dt,dt)
    
    temp_cols = [col for col in data.columns if col.startswith("T")]
    data[temp_cols] += 273.15
    data["y1"] += 273.15

    
    """
    params = ca.DM([1.55283967e-02,
                    2.71222840e-01, 
                    5.36453127e-02,
                    8.45898126e+05,
                    1.18504937e+07,
                    1.78899445e+06, 
                    6.42261677e-01,
                    0.5])
    """
    
    params = ca.DM([2.28170243e-05, 
                    9.72357621e-04,
                    5.36447144e-05, 
                    2.90739651e+07,
                    2.19546393e+08,
                    1.45126172e+08, 
                    2.37429786e+02,
                    1.00131069e-03])
    
    len_p = params.shape[0]
    lbp = 0.2*params
    ubp = 5*params
    #lbp[len_p-1] = 1E-5
    #ubp[len_p-1] = 1

    """
    First estimation, over entire horizon.
    """
    x_guess = np.array([
                data.Ti.values.flatten(),
                data.Ti.values.flatten(),
                data.Ti.values.flatten()
                ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12, 12, 2000, 2000, 50],
        "u_nom_b": [289.15, 289.15, 0, 0, 0],
        #"p_nom": [1E-5,1E-4,1E-5,1E8,1E9,1E2,1,1E3,1,1],
        #"p_nom_b": [0,0,0,0,0,0,0,0,289.15],
        #"slack": True
        "slack": False,
        "arrival_cost": True
    }
    """
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=params,
                             **kwargs) as param_est:

        Q = ca.DM.eye(3)
        R = ca.DM.eye(1)

        sim_sol, params = param_est.solve(
                                      data,
                                      params,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      lbx=lbx,
                                      ubx=ubx,
                                      covar=ca.veccat(Q, R)
                                      )
        sim_sol.to_csv("sim_sol.csv", index=True)
        ax = sim_sol["Ti"].plot(color="r")
        sim_sol["y1"].plot(color="k", ax=ax)
        ax.legend()
        plt.show()
        covar, fisher = param_est.get_covar_p(params/param_est.p_nom, R, Q)
        print(params)
    """ 
    sim_sol = pd.read_csv("sim_sol.csv", index_col=0)
    p_nom = np.array([2.e-04, 3.e-03, 2.e-04, 2.e+08, 5.e+07, 8.e+08, 9.e+01, 3.e-04])
    fisher = np.array([
                       3.09521,
                       3.79386,
                       0.559847,
                       0.40202,
                       472.579,
                       4.67514e-06,
                       181.658,
                       7.8722e-15
                       ])
    P = ca.DM(np.diag(np.append(fisher, np.array([0,0,0]))))
    params = params_orig = np.array([
                       1.07035987e-04,
                       2.57535680e-03,
                       1.43969927e-04,
                       1.17787782e+08,
                       4.39092756e+07, 
                       7.25630867e+08,
                       8.78650589e+01,
                       2.00752695e-04
                       ])
    # get covariance !!
    Q = ca.DM.eye(3)
    R = ca.DM.eye(1)
    M = 2
    
    """
    param_est = ParameterEstimation(config=cfg_path,
                                    N=M,
                                    dt=dt,
                                    param_guess=params)
    """
    
    param_est = MHE(config="configs/MHE_3R3C_vent_ext_det.json",
                    N=M,
                    dt=dt,
                    param_guess=params,
                    **kwargs)
    missed = []
    
    RUN = True
    
    if RUN:
        # M -> prediction horizon length
        for n in range(N-(M-1)):
            y_data = data[n:n+(M)]
            x_guess = np.array([
                            y_data.Ti.values.flatten(),
                            y_data.Ti.values.flatten(),
                            y_data.Ti.values.flatten()
                            ])
            lbx = 0.7*x_guess
            ubx = 2.0*x_guess
            
            
            """
            try:
                lbx[0:3, 0] = \
                    ubx[0:3, 0] = \
                        x_guess[0:3, 0] = \
                            sol[param_est.x_names].iloc[1].values
                            #sol[param_est.x_names].iloc[1].values
            except NameError:
                pass
            """
            
            """
            Evolve EKF in paralell to get evolution of state covariance.
            """
            
             
            sol, params, raw_sol = param_est.solve(
                                                y_data,
                                                params_orig,
                                                lbp=lbp,
                                                ubp=ubp,
                                                lbx=lbx,
                                                ubx=ubx,
                                                covar=ca.veccat(Q, R),
                                                return_raw_sol=True,
                                                arrival_cost=True,
                                                P0=P/param_est.p_nom,
                                                x_N=sim_sol[param_est.x()].iloc[n]
                                                )
            # reset bounds on p:
            #lbp = 0.8*params
            #ubp = 1.2*params
            if param_est.solver.stats()["return_status"] != "Solve_Succeeded":
                missed.append(n)
            ndx = n*dt
            #ndx = n
            try:
                par_df.loc[ndx] = params
                x_df.loc[ndx] = sol[param_est.x_names].iloc[0].values
            except NameError:
                par_df = pd.DataFrame(columns=params.index)
                x_df = pd.DataFrame(columns=param_est.x_names)
                par_df.loc[ndx] = params
                x_df.loc[ndx] = sol[param_est.x_names].iloc[0].values
            
        else:
            par_df.to_csv("params.csv", index=True)
            x_df.to_csv("states.csv", index=True)
            # plot fit, should be perfect:
            ax = x_df["Ti"].plot(color="r")
            data["y1"].plot(color="k", ax=ax)
            ax.legend()
            plt.show()
            print(params)
    else:
        par_df = pd.read_csv("params.csv", index_col=0)
        x_df = pd.read_csv("states.csv", index_col=0)
        
    r_names = ["Ta", "phi_s"]
    x_nn = data[r_names][:-M+1]
    x_scale = (x_nn.max()-x_nn.min())
    y_nn = par_df
    y_scale = y_nn.max()
    
    #x_nn_scl = x_nn/x_scale
    x_nn_min = x_nn.min()
    x_nn_max = x_nn.max()
    x_nn_scl = (x_nn - x_nn_min)/(x_nn_max - x_nn_min)
    y_nn_scl = y_nn/y_scale
    
    x, y = torch.tensor(x_nn_scl.values), torch.tensor(y_nn_scl.values)
    
    # init custom dataset and train:
    split = "train"
    train_dataset = ParamDataset(split, x, y)
    model = NN(x_nn.shape[1], y_nn.shape[1])
    train_config = get_train_config()
    trainer = Trainer(train_config, model, train_dataset)
    trainer.run()

    # now, take a visual look at e.g. Ci as a function of inputs:
    model_y = model(x)
    y_hat_df = pd.DataFrame(index=par_df.index,
                            data=model_y.detach().numpy(),
                            columns=par_df.columns)
    y_hat_df *= y_scale
    
    """
    # look at e.g. Ce
    ax = par_df.Ce.plot(color="k")
    y_hat_df.Ce.plot(color="r", linestyle="dashed")
    plt.show()
    """
    
    # look at all params:
    fig, _axes = plt.subplots(4,2, sharex=True)
    axes = _axes.flatten()
    p = param_est.p_names
    for ax, name in zip(axes, p):
        par_df[name].plot(ax=ax, color="k")
        y_hat_df[name].plot(ax=ax, color="r", linestyle="dashed")
        ax.set_title(name)
    plt.show()
    
    """
    Validation
    
    Open question:
        - open-loop or closed-loop?
    
    We do open-loop for now,
    i.e. no feedback on state predictions
    obtained from parameters p_k in timestep
    t = t_k.
    """
    param_est = ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt)
    I = param_est.integrator
    print(I)
    x0 = x_df.iloc[0].values
    # store simulated values:
    xs = np.array([])
    #p = y_hat_df.mean()
    for n in range(N-M+1):
        xs = np.append(xs, np.array(x0))
        u = data[I.dae.u_names].iloc[n].values
        r = data[I.dae.r_names].iloc[n].values
        #z = sol[I.dae.z].iloc[n].values
        # take p from NN-model:
        #u_nn = torch.tensor(u/x_scale)
        #u_nn = torch.tensor((u - x_nn_min)/(x_nn_max - x_nn_min))
        #p = model(u_nn).detach().numpy()*y_scale
        p = par_df.iloc[n]
        x0 = x_df.iloc[n]
        x0 = I.one_sample(x0,0,u,p.values,0,r)
        #x0 = I.one_sample(x0,0,ca.vertcat(p, r),u,0,0,0)[0]
    res_table = pd.DataFrame(data=xs.reshape(N-M+1, 3), columns=["Ti", "Te", "Th"])
    res_table.index = data[:-M+1].index

    # start anew:
    x0 = x_df.iloc[0].values
    # store simulated values:
    xs = np.array([])
    for n in range(N-M+1):
        xs = np.append(xs, np.array(x0))
        u = data[I.dae.u_names].iloc[n].values
        r = data[I.dae.r_names].iloc[n].values
        #z = sol[I.dae.z].iloc[n].values
        # take p from NN-model:
        u_nn = data[r_names].iloc[n].values
        u_nn = torch.tensor((u_nn - x_nn_min)/(x_nn_max - x_nn_min))
        p = model(u_nn).detach().numpy()*y_scale
        #p = par_df.iloc[n]
        x0 = I.one_sample(x0,0,u,p.values,0,r)
        #x0 = I.one_sample(x0,0,ca.vertcat(p, r),u,0,0,0)[0]
    res = pd.DataFrame(data=xs.reshape(N-M+1, 3), columns=["Ti", "Te", "Th"])
    #res = pd.DataFrame(data=xs.reshape(N,2), columns=["Ti", "Te"])
    res.index = data[:-M+1].index
    ax = res.Ti.plot(color="r")
    res_table.Ti.plot(color="y")
    data.Ti[:-1].plot(color="k", linestyle="dashed", ax=ax)
    ax.legend(["NN", "table", "truth"])
    plt.show()
    print(p)