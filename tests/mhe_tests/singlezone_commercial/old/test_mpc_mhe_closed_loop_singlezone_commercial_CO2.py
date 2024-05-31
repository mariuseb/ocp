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
    
    mpc_cfg = os.path.join("mpc_configs", "4R2C_MPC_vent_no_water.json")
    mhe_cfg = os.path.join("mhe_configs", "4R2C_MHE_vent_no_water_det.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "4R2C_EKF_vent_no_water.json")

    params = params_orig = ca.DM(
                                [
                                5.798972e-05,
                                2.470447e-02,
                                2.415008e-04,
                                3.219042e-01,
                                4.549992e+07,
                                2.500057e+09,
                                6.312371e+01,
                                3.092358e+01,
                                1.000000e+03,
                                9.906093e-01,
                                5.933963e-01
                                    ]
                                )
    kwargs = {
        "x_nom": 300,
        "u_nom": 300,
        "r_nom": 300,
        "y_nom": 300,
        #"slack": Trues
        "slack": False
    }
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
            "z_nom": [300,1E5,300,40],
            "r_nom": [300,300,1E5,1E5,1E5],
            "u_nom": [1,1,300],
            #"p_nom": [1E-5,1E-4,1E-5,1E8,1E9,1E2,1,1E3,1,1],
            #"p_nom_b": [0,0,0,0,0,0,0,0,289.15],
            #"slack": True
            "slack": False
    }
    
    #params[0:5] *= 10
    
    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    
    
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
    R[1,1] = 1E-8
    R[2,2] = 1E-4
    R[3,3] = 1E-4
    R[4,4] = 1E-4
    #R[1,1] = 1E-10
    #R = ca.DM.eye(1)

    fishers = pd.DataFrame(columns=(mpc.p_names + mpc.x_names))
    days = 3
    K = days*24*bounds.t_h

    x0 = np.array([293.15, 293.15])
    us = pd.DataFrame(columns=["calc_mpc", "act"])
    
    """
    Set MHE objective manually:
    """
    v_inds = mhe.nlp_parser["v"]["range"]
    v1 = mhe.nlp["x"][v_inds["a"]:v_inds["b"]:mhe.dae.n_y]
    v2 = mhe.nlp["x"][(v_inds["a"]+1):v_inds["b"]:mhe.dae.n_y]
    v3 = mhe.nlp["x"][(v_inds["a"]+2):v_inds["b"]:mhe.dae.n_y]
    v4 = mhe.nlp["x"][(v_inds["a"]+3):v_inds["b"]:mhe.dae.n_y]
    v5 = mhe.nlp["x"][(v_inds["a"]+4):v_inds["b"]:mhe.dae.n_y]
    #v6 = mhe.nlp["x"][(v_inds["a"]+5):v_inds["b"]:mhe.dae.n_y]
    # what to do with this? 
    #eta_rad = mhe.dae.dae.var("eta_rad")
    eta_hex1 = mhe.dae.dae.var("eta_hex1")
    eta_hex2 = mhe.dae.dae.var("eta_hex2")
    #eta_hex3 = mhe.dae.dae.var("eta_hex3")
    #v2 = v2/eta_rad
    v2 = v2/eta_hex1
    #v3 = v3/eta_hex2
    
    # when is Pvent zero?
    #vent_zero = np.array([1 if y_data.Pvent.loc[ndx] > 10 else 0 for ndx in y_data.index])
    #v4 = v4*vent_zero
    
    mhe.nlp["f"] = \
        R[0,0]*ca.dot(v1, v1) + \
        R[1,1]*ca.dot(v2, v2) + \
        R[2,2]*ca.dot(v3, v3) + \
        R[3,3]*ca.dot(v4, v4) + \
        R[4,4]*ca.dot(v5, v5) # + \
    Q_sym = ca.MX.sym("Q", mhe.n_x + mhe.n_z, mhe.n_x + mhe.n_z)
    R_sym = ca.MX.sym("R", mhe.n_y, mhe.n_y)
    #
    mhe.nlp["p"] = ca.veccat(Q_sym,R_sym)
    
    for k in range(K):

        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        
        sol, u, x0 = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params,
                               codegen=True
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
            # shift algebraic variables BACK
            #y_data["ahu_reaTRetAir"] = y_data["ahu_reaTRetAir"].shift(-1) 
            y_data["ahu_reaTHeaRec"] = y_data["ahu_reaTHeaRec"].shift(-1) 
            y_data["ahu_reaFloSupAir"] = y_data["ahu_reaFloSupAir"].shift(-1)
            y_data["ahu_pump_sup"] = y_data["ahu_pump_sup"].shift(-1) 
            y_data["ahu_pump_ret"] = y_data["ahu_pump_ret"].shift(-1) 
            y_data["oveTSupSet"] = y_data["oveTSupSet"].shift(-1) 
            y_data["Pvent"] = y_data["Pvent"].shift(-1)
            y_data["y1"] = y_data.Ti
            y_data["y2"] = y_data.Pvent
            y_data["y3"] = y_data.ahu_reaTHeaRec
            y_data["y4"] = y_data.ahu_reaFloSupAir
            y_data["y5"] = y_data.ahu_reaTRetAir

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
            sol_mhe, params = mhe.solve(
                y_data,
                params,
                lbp=params_lb,
                ubp=params_ub,
                covar=ca.veccat(Q, R),
                P0=P0,
                x_N=x_N,
                arrival_cost=False,
                codegen=True
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
            
            if (k % 96) in range(25,26):            
                params_lb = 0.7*params
                params_ub = 1.3*params
            else:
                params_lb = 0.7*params
                params_ub = params
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
    # plot diff_Q, which drives the learning:
    df = boptest.get_data(tf=k*mpc.dt)