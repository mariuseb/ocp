# from ast import Param
import io
import pstats
import cProfile
import matplotlib.dates as mdates
from pstats import SortKey
from ocp.mpc import MPC
from ocp.mhe import MHE
import numpy as np
import json
import casadi as ca
# import sysid.dae as dae
# import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import KalmanBucy
from ocp.functions import functions
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
#from ocp.rl import Qlearning
import os
#import scipy
from copy import deepcopy
#np.set_printoptions(precision=2)
#pd.set_option('display.height', 500)
#pd.set_option('display.max_rows', 500)
#pd.set_option('display.max_columns', 500)
#pd.set_option("display.precision", 16)
#import math
# profiling:
# import pdb

# text:
rc('mathtext', default='regular')
# datetime:
# plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"


if __name__ == "__main__":

     
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("mpc_configs", "4R2C_MPC_vent_no_water_CO2_rad.json")
    mhe_cfg = os.path.join("mhe_configs", "4R2C_MHE_vent_rad.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "4R2C_EKF_vent_no_water_CO2_rad.json")

    params = ca.DM([
        4.206026e-05,
        6.192792e-04,
        4.797176e-04,
        1E-5,
        7.399603e+07,
        2.823996e+09,
        2.209604e+02,
        3.996869e+01,
        3.417110e+01,
        3.400000e+02,
        1.000000e+03,
        7.722262e+03,
        9.813310e-01,
        0.75,
        8.700000e-01,
        1.767463e+00,
        1.793476e+00,
        1.000000e+00,
        0.000029,
        417.696296,
        1.233673,
        0.000621
                ])
    
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        #"slack": Trues
        "slack": False
    }
    kwargs = {
        "x_nom": 300,
        "z_nom": [300,1E6,300,1,1,1,1,1,1E6],
        "r_nom": [300,300,1E6,1E6,1E6,1],
        "u_nom": [1,1,300,1],
        #"p_nom": [1E-5,1E-4,1E-5,1E8,1E9,1E2,1,1E3,1,1],
        #"p_nom_b": [0,0,0,0,0,0,0,0,289.15],
        #"slack": True
        "slack": True
    }
    
    #params[0:5] *= 10
    
    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    
    kwargs = {
        "x_nom": [12,12,800],
        "x_nom_b":[289.15,289.15,0],
        "z_nom": [12,1,1,1], 
        "z_nom_b": [289.15,0,0,0],
        "u_nom": [1E6,1E6,1,1,1,12,12,1,1],
        "u_nom_b": [0,0,0,0,0,289.15,289.15,0,0],
        "r_nom": [12,300,1E6,1E6,1E6,1],
        "r_nom_b": [289.15,0,0,0,0,0],
        #"p_nom": [1E-5,1E-4,1E8,1E9,1E2,1,1E3,1,12],
        #"p_nom_b": [0,0,0,0,0,0,0,0,289.15],
        "y_nom": [12,1E6,12,1,1,12,800,1E6],
        "y_nom_b": [289.15,0,289.15,0,0,289.15,0,0]
    }
    
    mhe = MHE(config=mhe_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    
    ekf = KalmanBucy(ekf_cfg,
                     functions=deepcopy(functions)
                     )
    # set params:
    ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="singlezone_commercial"
                      )
    
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # mhe settings:
    P0 = ca.DM.eye(mpc.n_p + mpc.n_x)
    P0[:mhe.n_p, :mhe.n_p] *= 0
    P0[mhe.n_p:, mhe.n_p:] *= 0
    # P0 *= 1E-32

    #params_lb = params*0.7
    #params_ub = params*1.3
    params_lb = params
    params_ub = params
    params_lb[0:7] = 0.7*params[0:7]
    params_ub[0:7] = 1.3*params[0:7]

    Q = ca.DM.eye(mhe.n_x + mhe.n_z)
    #Q[1,1] = 1E-3
    #Q[1,1] = 1E-2
    #Q[0,0] = 0
    #Q[1,1] = 0
    # this is the objective weighting:
    R = ca.DM.eye(mhe.n_y)

    #R[1,1] = 1E-10
    #R = ca.DM.eye(1)

    fishers = pd.DataFrame(columns=(mpc.p_names + mpc.x_names))
    days = 3
    K = days*24*bounds.t_h

    x0 = np.array([293.15, 293.15, 420])
    us = pd.DataFrame(columns=["calc_mpc", "act"])
    
    """
    Set MHE objective manually:
    """
    R[1,1] = 1E-10
    #R[2,2] = 1E-8
    # temperature:
    R[2,2] = 1E-8
    R[3,3] = 1E-8
    R[4,4] = 1E-8
    R[5,5] = 1E-8
    R[6,6] = 1E-8
    R[7,7] = 1E-10
    #R[4,4] = 1E-4
    #R[5,5] = 1E-4
    
    #R[2,2] = 1E-10
    # provide Q, R in solve here:
    # provide lb, ub for p here:
    v_inds = mhe.nlp_parser["v"]["range"]
    v1 = mhe.nlp["x"][v_inds["a"]:v_inds["b"]:mhe.dae.n_y]
    v2 = mhe.nlp["x"][(v_inds["a"]+1):v_inds["b"]:mhe.dae.n_y]
    v3 = mhe.nlp["x"][(v_inds["a"]+2):v_inds["b"]:mhe.dae.n_y]
    v4 = mhe.nlp["x"][(v_inds["a"]+3):v_inds["b"]:mhe.dae.n_y]
    v5 = mhe.nlp["x"][(v_inds["a"]+4):v_inds["b"]:mhe.dae.n_y]
    v6 = mhe.nlp["x"][(v_inds["a"]+5):v_inds["b"]:mhe.dae.n_y]
    v7 = mhe.nlp["x"][(v_inds["a"]+6):v_inds["b"]:mhe.dae.n_y]
    v8 = mhe.nlp["x"][(v_inds["a"]+7):v_inds["b"]:mhe.dae.n_y]
    #v6 = mhe.nlp["x"][(v_inds["a"]+5):v_inds["b"]:mhe.dae.n_y]
    # what to do with this? 
    #eta_rad = mhe.dae.dae.var("eta_rad")
    eta_hex1 = mhe.dae.dae.var("eta_hex1")
    eta_hex2 = mhe.dae.dae.var("eta_hex2")
    eta_hex3 = mhe.dae.dae.var("eta_hex3")
    #eta_hex3 = mhe.dae.dae.var("eta_hex3")
    #v2 = v2/eta_rad
    v2 = v2/eta_hex1
    v3 = v3/eta_hex2
    v8 = v8/eta_hex3
    #v3 = v3/eta_hex2
    
    # when is Pvent zero?
    #vent_zero = np.array([1 if y_data.Pvent.loc[ndx] > 10 else 0 for ndx in y_data.index])
    #v4 = v4*vent_zero
    
    mhe.nlp["f"] = \
        R[0,0]*ca.dot(v1, v1) + \
        R[1,1]*ca.dot(v2, v2) + \
        R[2,2]*ca.dot(v3, v3) + \
        R[3,3]*ca.dot(v4, v4) + \
        R[4,4]*ca.dot(v5, v5) + \
        R[5,5]*ca.dot(v6, v6) + \
        R[6,6]*ca.dot(v7, v7) + \
        R[7,7]*ca.dot(v8, v8)
        
    Q_sym = ca.MX.sym("Q", mhe.n_x + mhe.n_z, mhe.n_x + mhe.n_z)
    R_sym = ca.MX.sym("R", mhe.n_y, mhe.n_y)
    #
    mhe.nlp["p"] = ca.veccat(Q_sym,R_sym)

    codegen = True
    
    for k in range(K):

        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        # modify ub of CO2:
        ubx[2:-1:3] = 800
        ubx[-1] = 800
        
        sol, u, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params,
                               codegen=codegen
                               )
        # make it simple for now: no ventilation
        u["dh_pump"] = 0
        data, y_meas, u_meas = boptest.evolve(
                                        u=u, 
                                        y_as_array=False,
                                        u_as_array=False
                                        )
        # keep u's:
        #us.loc[k, "calc_mpc"] = sol["Ph"].iloc[0]
        #us.loc[k, "act"] = y_meas[1]

        if k >= (mhe.N - 1):
            # get labelled data:
            stop_time = (k+1)*boptest.h
            start_time = stop_time - (mhe.N - 1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data = y_data.loc[:, ~y_data.columns.duplicated()]
            # shift algebraic variables BACK
            #y_data["ahu_reaTRetAir"] = y_data["ahu_reaTRetAir"].shift(-1) 
            y_data["Prad"] = y_data["Prad"].shift(-1) 
            y_data["Ptot"] = y_data["Ptot"].shift(-1) 
            y_data["Pvent"] = y_data["Pvent"].shift(-1) 
            y_data["n_occ"] = y_data["n_occ"].shift(-1) 
            y_data["dh_pump"] = y_data["dh_pump"].shift(-1) 
            y_data["oveValCoi"] = y_data["oveValCoi"].shift(-1) 
            y_data["ahu_pump_sup"] = y_data["ahu_pump_sup"].shift(-1) 
            y_data["ahu_pump_ret"] = y_data["ahu_pump_ret"].shift(-1) 
            y_data["ahu_reaTCoiSup"] = y_data["ahu_reaTCoiSup"].shift(-1) 
            y_data["ahu_reaTCoiRet"] = y_data["ahu_reaTCoiRet"].shift(-1) 
            y_data["ahu_reaTSupAir"] = y_data["ahu_reaTSupAir"].shift(-1) 
            # unsure whether to pull this back or not:
            #y_data["ahu_reaTRetAir"] = y_data["ahu_reaTRetAir"].shift(-1) 
            y_data["ahu_reaTHeaRec"] = y_data["ahu_reaTHeaRec"].shift(-1) 
            y_data["ahu_reaFloSupAir"] = y_data["ahu_reaFloSupAir"].shift(-1)
            y_data["ahu_reaFloExtAir"] = y_data["ahu_reaFloExtAir"].shift(-1)
            # TODO: need to modularize this:
            y_data["y1"] = y_data["Ti"]
            y_data["y2"] = y_data["Pvent"]
            y_data["y3"] = y_data["ahu_reaTHeaRec"]
            y_data["y4"] = y_data["ahu_reaFloSupAir"]
            y_data["y5"] = y_data["ahu_reaFloExtAir"]
            y_data["y6"] = y_data["ahu_reaTRetAir"]
            y_data["y7"] = y_data["CO2_in"]
            y_data["y8"] = y_data["Prad"]

            if k == (mhe.N - 1):
                x_N = ekf.df[mhe.x_names].iloc[-mhe.N+1].values
            else:
                x_N = sol_mhe.iloc[1][mhe.x_names].values

            params_init = params  # keep
            # check if parameter scale has changed:
            # NOTE: drop this for now:
            """
            if not all(
                mhe.get_scale(np.array(params).flatten())
                ==
                np.array(mhe.p_nom).flatten()
            ):
                # keep df:
                df = mhe.df
                # new mhe object:
                # keep df:
                mhe = MHE(config=mhe_cfg,
                          functions=deepcopy(functions),
                          param_guess=params,
                          **deepcopy(kwargs))
                # set df for estimation history:
                mhe.df = df
            """ 
            
            x_guess = np.array([y_data.Ti.values.flatten(),
                                y_data.Ti.values.flatten(),
                                y_data.CO2_in.values.flatten()])
                                #, y_data.ahu_reaTSupAir.values.flatten()])
            x_guess = x_guess.T.flatten()
            lbx = 0.33*x_guess
            ubx = 3*x_guess
            
            sol_mhe, params = mhe.solve(
                y_data,
                params,
                lbp=params_lb,
                ubp=params_ub,
                lbx=lbx,
                ubx=ubx,
                x_guess=x_guess,
                covar=ca.veccat(Q, R),
                P0=P0,
                x_N=x_N,
                arrival_cost=False,
                codegen=codegen
            )
            """
            ax = sol_mhe.y1.plot()
            sol_mhe["Ti"].plot(ax=ax, linestyle="dashed")
            #sol_mhe["oveTSupSet"].plot(ax=ax, drawstyle="steps-post")
            ax1 = ax.twinx()
            sol_mhe["Pvent"].plot(ax=ax1, drawstyle="steps-post")
            ax.legend()
            plt.show()
            params_lb[0:6] = 0.7*params[0:6]
            params_ub[0:6] = 1.3*params[0:6]
            """
   
            #params = params.valuesadrenaline1
            #params_lb[0:7] = 0.7*params[0:7]
            #params_ub[0:7] = 1.3*params[0:7]
            
            """
            if (k % 96) in range(25,26):            
                params_lb = 0.7*params
                params_ub = 1.3*params
            else:
                params_lb = 0.7*params
                params_ub = params
            """ 
            #params_lb = params*0.99
            #params_ub = params*1.01
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
            #us.loc[k, "calc_mhe"] = sol_mhe["Ph"].iloc[-1]
            
        else: # TODO: issue: ekf warmup
            z_model = sol[ekf.dae.z].iloc[0].values
            u_model = sol[ekf.dae.u].iloc[0].values
            r_pred = data[ekf.dae.r_names].iloc[0].values
            # TODO: check if constraint active 
            y_z_meas = [y_meas[name] for name in ekf.y]
            x0 = ekf.estimate(
                            x0, 
                            z=z_model,
                            y=y_z_meas, 
                            u=u_model, 
                            r=r_pred
                            )

    """
    ax = us[["calc_mpc", "calc_mhe"]].plot()
    us[["act"]].plot(ax=ax, linestyle="dashed")
    ax.legend()
    plt.show()  
    """

    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Pvent")
    fig.tight_layout()
    plt.show()
    
    res = boptest.get_data(tf=K*boptest.h)
    ax = res.n_occ.plot()
    res.CO2_in.plot(ax=ax)
    ax.legend()
    plt.show()
    print(res)
    
    """
    Look at deviation: ahu_pump_<x> vs. real
    """
    
    ax = (res.ahu_pump_sup**1.817*33.4).plot(drawstyle="steps-post")
    res.ahu_reaFloSupAir.plot(drawstyle="steps-post", ax=ax)
    ax.legend()
    plt.show()
    ax = (res.ahu_pump_ret**1.77*27.95).plot(drawstyle="steps-post")
    res.ahu_reaFloExtAir.plot(drawstyle="steps-post", ax=ax)
    ax.legend()
    plt.show()
    
    # look at Prad vs. Pvent
    ax = res.Pvent.plot(drawstyle="steps-post")
    res.Prad.plot(drawstyle="steps-post", ax=ax)
    plt.show()