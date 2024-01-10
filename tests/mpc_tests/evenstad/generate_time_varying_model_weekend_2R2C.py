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

    cfg_path = "configs/2R2C_det_vent_single_tvp.json"
    df = pd.read_csv("evenstad_data_2023/evenstad_all_data.csv", index_col=0)
    df.index = df["dt_index"] = pd.to_datetime(df.index)
    temp_cols = [col for col in df.columns if "Ti_" in col 
                 and "office" not in col
                 and "113" not in col
                 and "101" not in col]
    df["Ti"] = df["Ti_117"]
    
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
    all_data = df.resample(rule="1H").asfreq()
    all_data["phi_h"] = phi_h # to Watts
    all_data["Tsup"] = all_data["Tsup_water_west"]
    all_data["Tret"] = all_data["Tret_water_west"]
    all_data["m_flow_water"] = (all_data["Tsup"] - all_data["Tret"])*4200/(all_data["phi_h"])
    all_data["y1"] = all_data["Ti"]
    all_data["y2"] = all_data["phi_h"]
    
    all_data = all_data.bfill()
    #all_data = all_data.loc['2023-04-04 00:00:00':'2023-04-07 23:00:00']   
    
    if PLOT:
    
        # plot valve opening vs. m_flow inferred:
        """
        ax = all_data.valve.plot(color="k", drawstyle="steps-post")
        ax1 = ax.twinx()
        all_data.m_flow_water.plot(color="r", ax=ax1, drawstyle="steps-post")
        plt.show()
        
        #all_data = all_data.loc['2023-04-04 00:00:00':'2023-04-08 23:00:00']   
        all_data = all_data.loc['2023-02-20 00:00:00':'2023-02-28 23:00:00']   
        all_data = all_data.bfill()
        
        ax = all_data.Ti.plot(color="k", drawstyle="steps-post")
        ax1 = ax.twinx()
        all_data.phi_h.plot(color="r", ax=ax1, drawstyle="steps-post")
        plt.show()
        
        ax = all_data.valve.plot(color="k", drawstyle="steps-post")
        ax1 = ax.twinx()
        all_data.phi_h.plot(color="r", ax=ax1, drawstyle="steps-post")
        plt.show()
        
        UA_nom = 300
        ax = all_data.phi_h.plot(linestyle="dashed")
        (((all_data.Tsup - all_data.Tret)**1.5)*UA_nom).plot(ax=ax) 
        df.P_vent.plot(ax=ax, linewidth=1, color="k")
        ax1 = ax.twinx()
        df.Ta.plot(ax=ax1, color="g")
        plt.show()
        """
        # main points: 
        fig, axes = plt.subplots(4,1, sharex=True)
        ax = axes[0]        
        all_data[temp_cols].plot(drawstyle="steps-post", ax=ax)
        all_data["Ti"].plot(linewidth=2, color="k", ax=ax)
        ax = axes[1]
        all_data.phi_h.plot(color="r", ax=ax, drawstyle="steps-post")
        ax.legend(["Heating power"])
        ax = axes[2]
        all_data.Ta.plot(color="g", ax=ax, drawstyle="steps-post")
        ax.legend(["Ambient temperature"])
        ax = axes[3]
        all_data.phi_s.plot(color="y", ax=ax, drawstyle="steps-post")
        ax.legend(["Solar global"])
        plt.show()
    
    
    """
    Data selection:
    
        - we try to stitch together weekdays across weeks,
        see what turns out.
        - same with weekends.
    

    """
    
    def filter_weekend(ndx):
        if ndx.dayofweek == 4:
            if ndx.hour >= 18:
                return True
            else:
                return False
        elif ndx.dayofweek == 2:
            if ndx.hour < 18:
                return True
            else:
                return False
        elif ndx.dayofweek in (5,6,0,1):
            return True
        else:
            return False
    
    dt_index = pd.Series(all_data.index)
    #all_data["weeknd"] = dt_index.apply(filter_weekend)
    all_data["weekday"] = dt_index.apply(lambda x: x.dayofweek)
    weeknd = (dt_index.apply(lambda x: True if x.dayofweek in (5,6) else False)).astype(int)
    weeknd.index = all_data.index
    # boolean series for the two additional modes:
    all_data["vent_on"] = (all_data["V_flow_sup_air"] > 20000).astype(int)
    all_data["weeknd"] = weeknd
    
    start = pd.Timestamp("2023-01-30 00:00")
    stop = pd.Timestamp("2023-02-06 00:00")
    y_data = all_data.loc[start:stop]
    y_data = y_data.interpolate()
    y_data = y_data.bfill()

    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0,N*dt, dt)

    param_guess = np.array([1e-02,
                    1e-02,
                    1e-02,
                    1e-01, 
                    1e-01,
                    1e-01,
                    1E6,
                    1E6,
                    1E6,
                    5E6,
                    1E6,
                    1E6,
                    6.42261677e-01,
                    1,
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
    lbp[1] = -100
    lbp[2] = -100
    lbp[4] = -100
    lbp[5] = -100
    # Ci_a
    lbp[7] = -1E10
    lbp[8] = -1E10
    #ubp[7] = 5E8
    #ubp[8] = 5E8
    # Ce_a:
    lbp[10] = -1E10
    lbp[11] = -1E10
    len_p = param_guess.shape[0]
    #lbp[len_p-1] = 1E-3
    #ubp[len_p-1] = 1000
    
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten() - 2 #,
                    #y_data.Ti.values.flatten() + 5
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess

    ax = y_data.vent_on.plot(color="r", drawstyle="steps-post")
    y_data.weeknd.plot(ax=ax, color="b", drawstyle="steps-post")
    ax.legend()
    plt.show()

    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             functions=functions,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        #R[1,1] = 1E-11
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        #grad_f = ca.gradient(param_est.nlp["f"], param_est.nlp["x"])
        #grad_f_f = ca.Function("grad_f", [param_est.nlp["x"]], [grad_f])
        
        sol, params, raw_sol = param_est.solve(
                                        y_data,
                                        param_guess,
                                        lbp=lbp,
                                        ubp=ubp,
                                        lbx=lbx,
                                        ubx=ubx,
                                        x_guess=x_guess,
                                        Te_anti_bias=True,
                                        #Th_anti_bias=True,
                                        covar=ca.veccat(Q, R),
                                        return_raw_sol=True
                                        )
        fig, axes = plt.subplots(2,1,sharex=True)
        ax = axes[0]
        sol.index = y_data.dt_index
        sol["Ti"].plot(color="r", ax=ax, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, drawstyle="steps-post")
        ax.legend(["Ti_model", "Ti_measured"])
        ax = axes[1]
        sol[["Ti", "Te"]].plot(ax=ax)
        ax.legend(["Ti", "Te"])
        plt.show()
        #pd.set_option("display.precision", 1)
        print(params)
        
        # validate with unseen data:

    start = pd.Timestamp("2023-02-13 00:00")
    stop = pd.Timestamp("2023-02-27 00:00")
    
    y_data = all_data.loc[start:stop]
    y_data = y_data.interpolate()
    y_data = y_data.bfill()
    
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
    p_base = params[["Ce", "Ci", "Rie", "Rea"]].values
    p_mod = params[["Ce_a2", "Ci_a2", "Rie_a2", "Rea_a2"]].values
    z_guess = p_base
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
    res.index = y_data.index
    y_data.index = y_data.index
    ax = res.Ti.plot(color="r")
    y_data.Ti.plot(color="k", linestyle="dashed", ax=ax)
    y_data.Ta.plot(color="b", linestyle="dashed", linewidth=0.75, ax=ax)
    ax1 = ax.twinx()
    y_data.weeknd.plot(ax=ax1, color="y", drawstyle="steps-post", linewidth=0.75)
    (y_data.phi_h/y_data.phi_h.max()).plot(ax=ax1, color="g", linewidth=0.75)
    ax.legend(["model", "measured"])
    plt.show()
    print(p)
    """
    Write params to text-files:
    """
    p_base = pd.DataFrame(params[["Ce", "Ci", "Rie", "Rea"]])
    p_mod = pd.DataFrame(params[["Ce_a2", "Ci_a2", "Rie_a2", "Rea_a2"]])
    p_mod.index = p_base.index
    p_base.to_csv("2R2C_params_week.csv", index=True)
    params.to_csv("2R2C_all_params.csv", index=True)
    (p_base + p_mod).to_csv("2R2C_params_weekend.csv", index=True)
    