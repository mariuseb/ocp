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

    cfg_path = "configs/3R3C_det_tvp_novent_wknd.json"
    cfg_path = "configs/3R3C_det_tvp_vent.json"
    df = pd.read_csv("evenstad_data_2023/evenstad_all_data.csv", index_col=0)
    df.index = df["dt_index"] = pd.to_datetime(df.index)
    temp_cols = [col for col in df.columns if "Ti_" in col 
                 and "office" not in col
                 and "113" not in col
                 and "101" not in col]
    df["Ti"] = df["Ti_117"]
    #df["Ti"] = df[temp_cols].mean(axis=1)
    #df["Ti"] = df.Tret_air
    #temp_cols.append("Ti")
    df["wknd"] = df.index.weekday
    df["wknd"] = df["wknd"].apply(lambda x: 1 if x in (5,6) else 0)
    df['hourofweek'] = df.index.dayofweek * 24 + df.index.hour
    df["wknd"] = df["hourofweek"].apply(lambda x: 0 if x in range(12, 107) else 1)
    # ventilation:
    
    rho_air = 1.204 # [kg/m^3]
    cp_air = 1000 # [J/kg*K]
    
    # trim ventilation:
    #df.V_flow_sup_air[df.V_flow_sup_air < 20000] = 0
    df["V_sup_air"] = df.V_flow_sup_air/3600
    df["T_sup_air"] = df.Tsup_air
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
    data = df.resample(rule="1H").asfreq()
    # try to filter out circulation loss:
    #phi_h[phi_h < 5000] = 0
    data["phi_h"] = phi_h # to Watts
    data["Tsup"] = data["Tsup_water_west"]
    data["Tret"] = data["Tret_water_west"]
    data["m_flow_water"] = (data["Tsup"] - data["Tret"])*4200/(data["phi_h"])
    data["y1"] = data["Ti"]
    #data["y2"] = data["phi_h"]
    
    data = data.bfill()
    y_data = data.loc['2023-04-04 00:00:00':'2023-04-12 23:00:00']   
    #y_data = data.loc['2023-02-01 00:00:00':'2023-02-14 23:00:00']   
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
    
    
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0,N*dt, dt)
    
    param_guess = np.array([1.55281972e-05,
                            5.53819695e-06,
                            2.15400003e-03,
                            6.72895737e-04,
                            5.36425760e+01,
                            1.32547199e+08,
                            8.67452493e+08,
                            1.54554619e+09,
                            9.84544197e+08,
                            3.09109338e+05,
                            1.73150990e+01,
                            5.00500002e-01])
    
    
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    lbp[1] = -1.01
    ubp[1] = 1.01
    # constrain Rea:
    #ubp[2] = 1E2
    #lbp[2] = 1E-4
    #
    lbp[6] = -1E9
    ubp[6] = 1E9
    #lbp[7] = 1E6
    #ubp[7] = 1E10
    lbp[8] = -1E10
    ubp[8] = 1E10
    len_p = param_guess.shape[0]
    lbp[len_p-1] = 1E-3
    ubp[len_p-1] = 1
    # window area
    #lbp[len_p-2] = 1
    # constrain Ch:
    #ubp[len_p-3] = 1E8
    # constrain Ce_b:
    #lbp[7] = 1E6
    #ubp[7] = 1E9
    
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
                                        Ti_gt_Te=True,
                                        Th_gt_Ti=True,
                                        Ce_gt_Ch=True,
                                        return_raw_sol=True
                                        )
        fig, axes = plt.subplots(1,1,sharex=True)
        ax = axes
        #sol.index = y_data.dt_index
        sol["Ti"].plot(color="r", ax=ax, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, drawstyle="steps-post")
        ax.legend(["Ti_model", "Ti_measured"])
        plt.show()
        print(params)
        """
        print("Time constants are:")
        taus = param_est.get_taus(params.values)
        print("Ti: %s hours" % (str(int(taus[0]))))
        print("Te: %s hours" % (str(int(taus[1]))))
        print("Th: %s hours" % (str(int(taus[2]))))
        """
        
        
        # validate with unseen data:

        start = pd.Timestamp('2023-04-13 00:00:00')
        stop = pd.Timestamp('2023-04-20 00:00:00')
        #start = pd.Timestamp('2023-03-01 00:00:00')
        #stop = pd.Timestamp('2023-03-08 00:00:00')
        y_data = data.loc[start:stop]
        
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
        p_base = params[["Ce", "Ci", "Rie_b"]].values
        p_mod = params[["Ce_a", "Ci_a", "Rie_a"]].values
        #zs = pd.DataFrame(columns=["comp", "sol"])
        
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
            if y_data["V_sup_air"].iloc[n] > 10:
                z = p_base + p_mod
            else:
                z = p_base
                
            #z_alt = sol[I.dae.z].iloc[n].values
            #zs.loc[n] = [z[0], z_alt[0]]
            x0 = I.one_sample(x0,z,u,p,0,r)
            
        res = pd.DataFrame(data=xs.reshape(N, 3), columns=["Ti", "Te", "Th"])
        #res.index = data.index
        #y_data.index = data.index
        #non_tvp = pd.read_csv("NL_validation_traj.csv", index_col=0)
        #non_tvp.index = y_data.Time
        #y_data.index = y_data.Time
        res.index = y_data.index
        # plot:
        fig, ax = plt.subplots(1,1)
        res.Ti.plot(ax=ax, color="r")
        #non_tvp["Tis"].plot(color="b", linewidth=1, linestyle="dashed", ax=ax)
        y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
        ax.legend(["model", "measured"])
        #ax.legend(["TVP model", "NL model", "measured"])
        ax.set_ylabel("Temperature [$^\circ$C]")
        fig.tight_layout()
        plt.show()