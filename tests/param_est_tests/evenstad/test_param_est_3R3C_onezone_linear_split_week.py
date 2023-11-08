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
from ocp.frost_function import get_metno_data, get_stations, get_observations
from ocp.functions import functions
# text:
rc('mathtext', default='regular')

# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

PLOT = True

if __name__ == "__main__":

    cfg_path = "configs/3R3C_det.json"
    df = pd.read_csv("evenstad_data_2023/evenstad_all_data.csv", index_col=0)
    df.index = df["dt_index"] = pd.to_datetime(df.index)
    temp_cols = [col for col in df.columns if "Ti_" in col 
                 and "office" not in col
                 and "113" not in col
                 and "101" not in col]
    #df["Ti"] = df["Ti_117"]
    df["Ti"] = df[temp_cols].mean(axis=1)
    #df["Ti"] = df.Tret_air
    #temp_cols.append("Ti")
    
    # ventilation:
    
    rho_air = 1.204 # [kg/m^3]
    cp_air = 1000 # [J/kg*K]
    
    # trim ventilation:
    #df.V_flow_sup_air[df.V_flow_sup_air < 20000] = 0
    vent_in = (df["Tsup_air"] - df["Ti"])*(df.V_flow_sup_air/3600)*rho_air*cp_air
    vent_out = (df["Ti"] - df["Tsup_air"])*(df.V_flow_exh_air/3600)*rho_air*cp_air
    vent_net = vent_in + vent_out
    #vent_out = (df["Ti"] - df["Tret_air"])*(df.V_flow_exh_air/3600)*rho_air*cp_air
    df["P_vent"] = vent_net
    
    # resample to 1H:
    
    # set names:
    df["P_water"] *= 1000
    # 'filter' out circulation loss:
    #df.P_water[df.P_water < 5] = 0
    phi_h = df["P_water"].resample(rule="1H").mean()
    y_data = df.resample(rule="1H").asfreq()
    y_data["phi_h"] = phi_h # to Watts
    y_data["Tsup"] = y_data["Tsup_water_west"]
    y_data["Tret"] = y_data["Tret_water_west"]
    y_data["m_flow_water"] = (y_data["Tsup"] - y_data["Tret"])*4200/(y_data["phi_h"])
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["phi_h"]
    
    y_data = y_data.bfill()
    y_data["week"] = y_data.dt_index.apply(lambda x: x.week)
    _dfs = y_data.groupby("week")
    dfs = dict()
    dt = (y_data.index[1] - y_data.index[0]).seconds
    N_prev = 168
    
    for i, df in _dfs:
        #dfs[i] = pd.DataFrame(df)
        data = pd.DataFrame(df)
        #if i == 3:
        # print(data)
        N = len(data)
        if N > 168:
            # backfilled, take latter part:
            data = data.iloc[168:]
            N = len(data)
            
        assert N == N_prev
        data.index = np.arange(0,N*dt, dt)
        dfs[i] = data
        N_prev = N
        #print(df)
        
        
    #y_data = y_data.loc['2023-04-04 00:00:00':'2023-04-07 23:00:00']   
    #y_data = y_data.loc['2023-02-01 00:00:00':'2023-02-28 23:00:00']   
    #y_data.to_csv("evenstad_feb.csv")
    
    if PLOT:
    
        # plot valve opening vs. m_flow inferred:
        """
        ax = y_data.valve.plot(color="k", drawstyle="steps-post")
        ax1 = ax.twinx()
        y_data.m_flow_water.plot(color="r", ax=ax1, drawstyle="steps-post")
        plt.show()
        
        #y_data = y_data.loc['2023-04-04 00:00:00':'2023-04-08 23:00:00']   
        y_data = y_data.loc['2023-02-20 00:00:00':'2023-02-28 23:00:00']   
        y_data = y_data.bfill()
        
        ax = y_data.Ti.plot(color="k", drawstyle="steps-post")
        ax1 = ax.twinx()
        y_data.phi_h.plot(color="r", ax=ax1, drawstyle="steps-post")
        plt.show()
        
        ax = y_data.valve.plot(color="k", drawstyle="steps-post")
        ax1 = ax.twinx()
        y_data.phi_h.plot(color="r", ax=ax1, drawstyle="steps-post")
        plt.show()
        
        UA_nom = 300
        ax = y_data.phi_h.plot(linestyle="dashed")
        (((y_data.Tsup - y_data.Tret)**1.5)*UA_nom).plot(ax=ax) 
        df.P_vent.plot(ax=ax, linewidth=1, color="k")
        ax1 = ax.twinx()
        df.Ta.plot(ax=ax1, color="g")
        plt.show()
        """
        # main points: 
        fig, axes = plt.subplots(4,1, sharex=True)
        ax = axes[0]        
        y_data[temp_cols].plot(drawstyle="steps-post", ax=ax)
        y_data["Ti"].plot(linewidth=2, color="k", ax=ax)
        ax = axes[1]
        y_data.phi_h.plot(color="r", ax=ax, drawstyle="steps-post")
        ax.legend(["Heating power"])
        ax = axes[2]
        y_data.Ta.plot(color="g", ax=ax, drawstyle="steps-post")
        ax.legend(["Ambient temperature"])
        ax = axes[3]
        y_data.phi_s.plot(color="y", ax=ax, drawstyle="steps-post")
        ax.legend(["Solar global"])
        plt.show()
    
    
    """
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0,N*dt, dt)
    """
    param_guess = ca.DM([#
                2.288896e-04,
                2.933085e-03,
                2.933085e-03,
                1.353292e+07,
                1.613305e+08,
                1.613305e+07,
                3.137043e+02,
                1000,
                1.5
                         ])
    param_guess = ca.DM([#
                2.288896e-02,
                2.933085e-02,
                2.933085e-02,
                2.933085e-02,
                1.353292e+07,
                1.613305e+08,
                1.613305e+07,
                3.137043e+02
                         ])
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    #ubp = ca.DM([0.1,1,1E7,1E8,50])
    len_p = param_guess.shape[0]
    lbp = 1E-2*param_guess
    ubp = 1E2*param_guess
    
    #lbp[len_p-1] = 0.5
    #ubp[len_p-1] = 2
    """
    for i in range(2,8):
        lbp[len_p-i] = 0
        ubp[len_p-i] = 1
    lbp[len_p-6] = 0.1
    ubp[len_p-6] = 0.9
    lbp[len_p-7] = 0.1
    ubp[len_p-7] = 0.9
    """
    #param_guess = ca.DM([0.001,0.009,1,1E6,1E7,1])
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    #    with ParameterEstimation(config=cfg_path,
    #                             data=y_data,
    #                             param_guess=param_guess) as param_est:
    
    results = {
        "params": dict(),
        "traj": dict()
               }
    
    for i, y_data in dfs.items():
        
        x_guess = np.array([
                            y_data.Ti.values.flatten(),
                            y_data.Ti.values.flatten(),
                            y_data.Ti.values.flatten()
                            #y_data.Ti1.values.flatten(),
                            #y_data.Ti1.values.flatten()
                            ])
        lbx = 0.3*x_guess
        ubx = 3*x_guess
        
        with ParameterEstimation(config=cfg_path,
                                N=N,
                                dt=dt,
                                functions=functions,
                                param_guess=param_guess) as param_est:
            
            Q = ca.DM.eye(3)
            #Q[0,0] = 6.55919266e-01
            #Q[1,1] = 4.52496393e-01
            #Q[1,0] = 0.01
            #Q[0,1] = 0.01
            R = ca.DM.eye(1)
            #R[1,1] = 1E-11
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
            Ai     5.132032e+00
                            
            Does it change the physical parameters any???    
                
            """
            sol, params, raw_sol = param_est.solve(
                                            y_data,
                                            param_guess,
                                            lbp=lbp,
                                            ubp=ubp,
                                            lbx=lbx,
                                            ubx=ubx,
                                            x_guess=x_guess,
                                            covar=ca.veccat(Q, R),
                                            return_raw_sol=True
                                            )
            
            results["params"][i] = params
            results["traj"][i] = sol
                    
            """
            fig, axes = plt.subplots(1,1,sharex=True)
            ax = axes
            #sol.index = y_data.dt_index
            sol["Ti"].plot(color="r", ax=ax, drawstyle="steps-post")
            sol["y1"].plot(color="k", ax=ax, drawstyle="steps-post")
            ax.legend(["Ti_model", "Ti_measured"])
            plt.show()
            pd.set_option("display.precision", 1)
            print(params)
            print("Time constants are:")
            taus = param_est.get_taus(params.values)
            print("Ti: %s hours" % (str(int(taus[0]))))
            print("Te: %s hours" % (str(int(taus[1]))))
            print("Th: %s hours" % (str(int(taus[2]))))
            """
            
            # validate with unseen data:

            """
            F = param_est.integrator.one_sample.mapaccum(len(test))
            x0 = sol[["Ti", "Te", "Ti1", "Te1"]].iloc[0].values
            #x0 = ca.DM([test.Ti[0], test.Ti[0], test.Ti1[0], test.Ti1[0]])
            #x0 = ca.DM([test.Ti[0], test.Ti[0] - 15, test.Ti1[0], test.Ti1[0] - 15])
            u_data = test[param_est.dae.u].values.T
            p_data = ca.repmat(params.values, 1, len(test))
            #p_data = ca.repmat(param_guess, 1, len(test))
            z_data = ca.repmat(1, 1, len(test))
            res = F(x0=x0, z=z_data, u=u_data, p=p_data, s=0, r=0)
            Ti_res = res["xf"][0, :]
            Ti1_res = res["xf"][2, :]
            test_res = pd.DataFrame(columns=["y1", "y2", "Ti_res", "Ti1_res"])
            test_res["y1"] = test.y1
            #test_r#es["y2"] = test.y2
            test_res["Ti_res"] = np.array(Ti_res).flatten()
            #test_res["Ti1_res"] = np.array(Ti1_res).flatten()
            test_res.plot()
            plt.show()
            print(test_res)
            """
            
    print(results)
    # make df
    params = pd.DataFrame(columns=params.index)
    for i, res in results["params"].items():
        params.loc[i] = res
        
    ax = params.Ce.plot()
    plt.show()