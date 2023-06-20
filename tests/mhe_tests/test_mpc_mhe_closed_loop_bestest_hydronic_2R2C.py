# from ast import Param
import io
import pstats
import cProfile
import matplotlib.dates as mdates
from pstats import SortKey
from ocp.mpc import MPC
from ocp.mhe import MHE
from ocp.dae import DAE
from ocp.param_est import ParameterEstimation
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
np.set_printoptions(precision=2)
#pd.set_option('display.height', 500)
pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option("display.precision", 16)
#import math
# profiling:
# import pdb

# text:
rc('mathtext', default='regular')
# datetime:
# plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"


if __name__ == "__main__":
    """
    Here, we keep the radiator model as obtained from
    a SID experiment fixed. Let the envelope parameters
    fluctuate.
    """

    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join(opt_config_base, "2R2C_MPC_hydronic.json")
    dae_cfg = os.path.join(opt_config_base, "rootfinder_DAE.json")
    mhe_cfg = os.path.join(opt_config_base, "2R2C_MHE_hydronic.json")
    #mhe_cfg_no_eta = os.path.join(opt_config_base, "2R2C_MHE_func_no_eta.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    #ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF_func_no_eta.json")
    ekf_cfg = os.path.join(opt_config_base, "2R2C_EKF_hydronic.json")

    # pass in config?
    """
    Rie       1.922773e-03
    Rea       8.390597e-03
    Ci        1.781685e+06
    Ce        2.050836e+07
    Ai        6.062751e+00
    n         1.156362e+00
    UA_nom    5.387476e+01
    eta       8.700000e-01
    
    params = ca.DM([1E-2,
                    1E-1,
                    1E6, 
                    1E7,
                    2,
                    1.156362e+00,
                    5.387476e+01,
                    8.700000e-01])
    
    params = ca.DM([1.922773e-03,
                    8.390597e-03,
                    1.781685e+06, 
                    2.050836e+07,
                    6.062751e+00,
                    1.156362e+00,
                    5.387476e+01])
    params = ca.DM([1.922773e-03,
                    8.390597e-03,
                    1.781685e+06, 
                    2.050836e+07,
                    6.062751e+00,
                    1.156362e+00,
                    5.387476e+01,
                    8.700000e-01])
    params = ca.DM([1.922773e-03,
                    8.390597e-03,
                    1.781685e+06, 
                    2.050836e+07,
                    6.062751e+00,
                    1.156362e+00,
                    5.387476e+01,
                    1])
    params_no_eta = ca.DM([1.922773e-03,
                    8.390597e-03,
                    1.781685e+06, 
                    2.050836e+07,
                    6.062751e+00,
                    1.156362e+00,
                    5.387476e+01])
    params = ca.DM([1.922773e-03,
                    8.390597e-03,
                    1.781685e+06, 
                    2.050836e+07,
                    6.062751e+00,
                    1.156362e+00,
                    5.387476e+01])
    """
    params = ca.DM([1.922773e-03,
                    8.390597e-03,
                    1.781685e+06, 
                    2.050836e+07,
                    6.062751e+00,
                    ])
    
    rad_params = ca.DM([1.156362e+00,
                        5.387476e+01,
                        8.700000e-01])
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        #"slack": Trues
        "slack": False
    }
    
    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N

    with open(dae_cfg, "r") as f:
        dae_config = json.load(f)
    dae_config["model"]["functions"] = deepcopy(functions)
    dae = DAE(dae_config["model"])
        
    # create a rootfinder for Tsup:
    Tsup = dae.dae.var("Tsup")
    n = dae.dae.var("n")
    UA_nom = dae.dae.var("UA_nom")
    eta = dae.dae.var("eta")
    Ph = dae.dae.var("Ph")
    Ti = dae.dae.var("Ti")
    p = ca.vertcat(n, UA_nom, eta, Ph, Ti)
    Tsup = ca.rootfinder(
                         'Tsup',
                         'newton', 
                         dict(x=Tsup, p=p, g=dae.dae.alg()[0])
                         )
    
    mhe = MHE(config=mhe_cfg,
              functions=deepcopy(functions),
              #param_guess=params[:-2], 
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    """
    mhe_no_eta = MHE(config=mhe_cfg_no_eta,
                    functions=deepcopy(functions),
                    param_guess=params[:-1], 
                    **deepcopy(kwargs))  # to remove, replace with N
    """
    
    ekf = KalmanBucy(ekf_cfg,
                     functions=deepcopy(functions)
                     )
    # set params:
    ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_hydronic"
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
    #params_mhe = params[:-2]
    #params_lb = params[:-2]
    #params_ub = params[:-2]
    #params_lb = params
    #params_ub = params
    params_lb = 0.7*params
    params_ub = 1.3*params
    #params_lb[4] *= 1
    #params_ub[4] *= 1
    #params_lb[4] *= 0.7
    #params_ub[4] *= 1.3
    Q = ca.DM.eye(mpc.n_x)
    Q[0,0] = 1
    Q[1,1] = 1
    R = ca.DM.eye(mhe.n_y)
    #R[1,1] = 1E-8
    #R[1,1] = 1E-10

    fishers = pd.DataFrame(columns=(mpc.p_names + mpc.x_names))
    days = 2
    K = days*24*bounds.t_h

    x0 = np.array([294.05, 293.15])
    us = pd.DataFrame(columns=["calc_mpc", "act"])
    obj_vals = pd.DataFrame(columns=["full", "no_eta"])
    
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

        """
        Order of inputs for rootfinder:
            n
            UA_nom
            eta
            Ph
            Ti
        """
        #p0 = ca.vertcat(rad_params, sol["Ph"].iloc[0], sol["Ti"].iloc[0])
        if sol["Ph"].iloc[0] < 1:
            # set Tsup = Ti
            u = pd.Series(sol["Ti"].iloc[0], index=["Tsup"])
        else:
            p0 = ca.vertcat(rad_params, sol["Ph"].iloc[0], sol["Ti"].iloc[0])
            # guess for Tsup
            u_model = sol["Ph"].iloc[0]
            x0 = float((u_model/5000)*50 + 293.15)
            u_val = float(Tsup(x0=x0,p=p0)["x"])
            u = pd.Series(u_val, index=["Tsup"])
            
        #if u.isna().all():
        #    print(u)

        data, y_meas, u_meas = boptest.evolve(u=u)
        # keep u's:
        us.loc[k, "calc_mpc"] = sol["Ph"].iloc[0]
        us.loc[k, "act"] = y_meas[1]

        if k >= (mhe.N - 1):
            # get labelled data:
            stop_time = (k+1)*boptest.h
            start_time = stop_time - (mhe.N - 1)*boptest.h
            y_data = boptest.get_data(ts=start_time, tf=stop_time)
            y_data["y1"] = y_data.Ti
            y_data["y2"] = y_data.Ph

            if k == (mhe.N - 1):
                x_N = ekf.df[mhe.x_names].iloc[-mhe.N+1].values
            else:
                x_N = sol_mhe.iloc[1][mhe.x_names].values

            params_init = params  # keep
            # check if parameter scale has changed:
            # NOTE: drop this for now:
            
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
            
            sol_mhe, params, raw_sol_mhe = mhe.solve(
                y_data,
                params,
                lbp=params_lb,
                ubp=params_ub,
                covar=ca.veccat(Q, R),
                P0=P0,
                x_N=x_N,
                arrival_cost=False,
                return_raw_sol=True,
                codegen=False
            )
            """
            sol_mhe_no_eta, params_no_eta, raw_sol_mhe_no_eta = mhe_no_eta.solve(
                y_data,
                params_no_eta,
                lbp=params_lb[:-1],
                ubp=params_ub[:-1],5
                covar=ca.veccat(Q, R),
                P0=P0,
                x_N=x_N,
                arrival_cost=False,
                return_raw_sol=True,
                codegen=True
            )
            
            equals = (sol_mhe_no_eta == sol_mhe[[col for col in sol_mhe.columns if col != "eta"]])
            if not equals.all().all():
                print(equals)
            
            obj_vals.loc[k, ["full", "no_eta"]] = np.array(
                                                            [
                                                            raw_sol_mhe["f"],
                                                            raw_sol_mhe_no_eta["f"]
                                                            ]
                                                           ).flatten()
            
            # try to evaluate h:

            h = mhe.strategy.h_map
            y = sol_mhe[mhe.y_names].values.T
            x = sol_mhe[mhe.x_names].values.T
            u = sol_mhe[mhe.u_names].values.T
            p = sol_mhe[mhe.p_names].values.T
            v = sol_mhe[mhe.v_names].values.T
            r = sol_mhe[mhe.r_names].values.T
            
            h_eval = h(y, x, 0, u, p, v, r)
            print(h_eval.T)
            ax = sol_mhe.y1.plot()
            sol_mhe["Ti"].plot(ax=ax)
            ax.legend()
            plt.show()
            """
                  
            params = params.values
            #params_no_eta = params_no_eta.values
            #params_lb = params
            #params_ub = params
            params_lb = 0.7*params
            params_ub = 1.3*params
            #params_lb[4] *= 1
            #params_ub[4] *= 1
            #params_lb[4] *= 0.7
            #params_ub[4] *= 1.3
            #params_lb = params*0.99
            #params_ub = params*1.01
            x0 = sol_mhe.iloc[-1][mhe.x_names].values
            #x0 = sol_mhe_no_eta.iloc[-1][mhe.x_names].values
            #us.loc[k, "calc_mhe"] = sol_mhe["Ph"].iloc[-1]
            
        else: # TODO: issue: ekf warmup
            #z_model = sol[ekf.dae.z].iloc[1].values
            r_pred = data[ekf.dae.r_names].iloc[0].values
            x0 = ekf.estimate(
                            x0, 
            #               z=z_model,
                            y=y_meas, 
                            u=u_meas, 
                            r=r_pred
                            )

    ax = us[["calc_mpc"]].plot()
    us[["act"]].plot(ax=ax, linestyle="dashed")
    ax.legend()
    plt.show()  

    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Ph")
    fig.tight_layout()
    plt.show()
    
    # plot diff_Q, which drives the learning:
    #df = boptest.get_data(tf=k*mpc.dt)

    #ax = mhe.df.Ti.plot()
    #df.Ti.plot(ax=ax)
    #plt.show()
    # parameter evolution plot ####:
    #mhe.df.index = dt_index[-len(mhe.df):]
    
    #ax = mhe.df.Ai.plot()
    #plt.show()
    #print(params_mhe)
    
    mhe.df.index = dt_index[-len(mhe.df):]
    fig, ax = plt.subplots(5,1, figsize=(8,10))
    (mhe.df.Ci/3.6E6).plot(ax=ax[0], color="k") # to kWh/C
    (mhe.df.Ce/3.6E6).plot(ax=ax[1], color="k") # to kWh/C
    (mhe.df.Rie*1000).plot(ax=ax[2], color="k") # to K/kW
    (mhe.df.Rea*1000).plot(ax=ax[3], color="k") # to K/kW
    mhe.df.Ai.plot(ax=ax[4], color="k")
    
    ax[0].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[1].set_ylabel(r"Cap. [$\frac{kWh}{K}$]")
    ax[2].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[3].set_ylabel(r"Res. [$\frac{K}{kW}$]")
    ax[4].set_ylabel(r"Area [$m^2$]")
    
    ax[0].legend([r"$C_i$"])
    ax[1].legend([r"$C_e$"])
    ax[2].legend([r"$R_{ie}$"])
    ax[3].legend([r"$R_{ea}$"])
    ax[4].legend([r"$A_w$"])
    
    ax[0].axes.get_xaxis().set_visible(False)
    ax[1].axes.get_xaxis().set_visible(False)
    ax[2].axes.get_xaxis().set_visible(False)
    ax[3].axes.get_xaxis().set_visible(False)
    
    plt.show()
    print(params)
