#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
#from ocp.param_est import ParameterEstimation
#from ocp.mhe import MHE
from ocp.estimation import Estimation
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
from ocp.utils import prepare_data, ZEBData, quick_plot
from result_generator import ResultGenerator, plot_residuals
from ocp.filters import KalmanDAE
from pandas.plotting import autocorrelation_plot
from utils import _solve_rosenbrock
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
    _solve_rosenbrock()
    param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rie_w": 
                    {
                        "init": 1e-2
                    },
                    "Rie_v": 
                    {
                        "init": 1e-2
                    },
                    "Rea":
                    {
                        "init": 1e-1
                    },
                    "Rea_w":
                    {
                        "init": 1e-1
                    },
                    "Rea_v":
                    {
                        "init": 1e-1
                    },
                    "Ci":
                    {
                        "init": 1e6
                    },
                    "Ci_w":
                    {
                        "init": 1e6
                    },
                    "Ci_v":
                    {
                        "init": 1e6
                    },
                    "Ce":
                    {
                        "init": 1e6
                    },
                    "Ce_w":
                    {
                        "init": 1e6
                    },
                    "Ce_v":
                    {
                        "init": 1e6
                    },
                    "Ai":
                    {
                        "init": 10
                    },
                    "Ai_high":
                    {
                        "init": 10
                    },
                    "cp_air":
                    {
                        "init": 1,
                        "lb": 1,
                        "ub": 1
                    },
                    "alpha_vent_sup":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_vent_ext":
                    {
                        "init": 1E-4
                    },
                    "alpha_int":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_occ":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 5
                    },
                    "alpha_int_lig":
                    {
                        "init": 1,
                        "lb": 1E-3,
                        "ub": 1
                    },
                    "alpha_int_plugs":
                    {
                        "init": 1,
    #                    "lb": 1E-3,
                        "ub": 1
                    }
    }

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "z_nom": [10],
        "z_nom_b": [0],
        "u_nom": [12]*7 + [1E3,1E3,1E3,1E3,10,10,1,1,1,1],
        "u_nom_b ": [289.15]*7 + [0]*10,
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    A = 60
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rie_w": 0.250/A, # m²K / W 
        "Rie_v": 0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Rea_w": 2.250/A, # m²K / W 
        "Rea_v": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Ci_w": 9.50*3600*A, # Wh / m²K
        "Ci_v": 9.50*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ce_w": 112*3600*A, # Wh / m²K
        "Ce_v": 112*3600*A, # Wh / m²K
        "Ai": 10, # m²
        "Ai_high": 10, # m²
        "alpha_vent_sup": 0.5,
        "alpha_vent_ext": 1e-4,
        "alpha_int": 1,
        "alpha_occ": 1
    }
    for name, value in priors.items():
        param_guess[name]["init"] = value 
        param_guess[name]["lb"] = value*1E-3 
        param_guess[name]["ub"] = value*1E3 

    #param_guess["alpha_int_lig"]["ub"] = 1.0
    #param_guess["alpha_int_plugs"]["ub"] = 1.0
    param_guess["alpha_vent_sup"]["ub"] = 1.0
    param_guess["alpha_vent_ext"]["ub"] = 1.0
    param_guess["alpha_int"]["ub"] = 1.0

    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    Data = ZEBData(data_path)
    Data.data.loc["2023-11-16 09:20":"2023-11-16 09:51", "T_219_TR2"] = np.nan
    Data.data.loc["2023-12-06 14:30":"2023-12-06 20:00", "T_sup_air_219"] = np.nan
    Data.data.loc["2023-12-06 14:30":"2023-12-06 20:00", "T_ext_air_219"] = np.nan
    Data.data.loc["2023-12-18 06:58":"2023-12-18 17:34", "T_sup_air_219"] = np.nan
    Data.data.loc["2023-12-18 06:58":"2023-12-18 17:34", "T_ext_air_219"] = np.nan
    """
    Hyper-parameters for run:
    """
    #start = pd.Timestamp("2024-01-01 00:00")
    start = pd.Timestamp("2023-11-15 00:00")
    #N_days = 14
    N_days = 1
    days = 1
    
    #N_days = 1
    #days = 1
    sampling_rate = "15min"
    plot = True
    cfg_path = os.path.join(
                            "configs", 
                            "2R2C_int_gains_sep_bal_vent_solar_tvp.json"
                            )
    ekf_config = os.path.join(
                              "configs",
                              "ekf_configs",
                              "2R2C_envelope_EKF_int_gains_sep_bal_vent_solar_tvp_covar_tvp.json"
                              )
    dt, N = Data.get_meta_for_parest(
                                     start,
                                     days,
                                     sampling_rate
                                     )
    result_gen = ResultGenerator(
                        config=cfg_path,
                        ekf_config=ekf_config,
                        params=param_guess,
                        slack=False,
                        dt=dt
                        )    
    param_est = Estimation(config=cfg_path,
                N=N,
                dt=dt,
                param_guess=param_guess,
                arrival_cost=True,
                **kwargs,
                )
    
    #val_metrics = pd.read_csv("test_var_day_runner.csv")
    (fig, axes, train_metrics, val_metrics, params_hist, theta_hist) = \
        result_gen.var_day_validation_runner(ekf_config,
                                              start,
                                              N_days,
                                              days,
                                              param_guess,
                                              param_est,
                                              Data,
                                              plot=plot,
                                              prior_weight=0, 
                                              #prior_weight=1e-5, 
                                              journal_plot=True,
                                              sampling_rate=sampling_rate,
                                              covar_solve=False,
                                              num_segments=1,
                                              control_validation=False,
                                              reidentification=True
                                              #R=R,
                                              #Q=Q,
                                              #P0x=P0,
                                              #x0_opt=x0>
                                              #covar_solve=False
                                              )
        
    # get the objective:
    nlp_obj_expr = param_est.nlp["f"]
    nlp_vars = param_est.nlp["x"]
    nlp_params = param_est.nlp["p"]
    # create function:
    nlp_obj = ca.Function(
        "f",
        [nlp_vars, nlp_params],
        [nlp_obj_expr],
        ["x", "p"],
        ["f"]
    )
    
    """
    Get objective values for different values of Rie, Rea.
    """
    
    relative_pos_Rie = param_est.dae.p.index("Rie")
    relative_pos_Rea = param_est.dae.p.index("Rea")
    p_start, p_stop = param_est.nlp_parser.vars["p"]["range"]["a"], param_est.nlp_parser.vars["p"]["range"]["b"]
    v_start, v_stop = param_est.nlp_parser.vars["v"]["range"]["a"], param_est.nlp_parser.vars["v"]["range"]["b"]
    len_p = p_stop - p_start
    n_x = param_est.n_x
    x0_nlp = np.array(param_est.raw_sol["x"]).flatten()
    p0_nlp = np.array(param_est.p_val).flatten()
    len_p_nlp = p0_nlp.shape[0]
    
    nlp_Rie_x_pos = p_start + relative_pos_Rie
    nlp_Rea_x_pos = p_start + relative_pos_Rea
    nlp_Rie_p_pos = len_p_nlp - len_p - n_x + relative_pos_Rie
    nlp_Rea_p_pos = len_p_nlp - len_p - n_x + relative_pos_Rea
    Rie_start_scaled = x0_nlp[nlp_Rie_x_pos]
    Rea_start_scaled = x0_nlp[nlp_Rea_x_pos]
    
    # start with 10 elems for each:
    x = np.arange(0.1,1,0.1) # Rie
    z = np.arange(0.1,1,0.1) # Rea
    y = np.array([[]])
    for i, _x in enumerate(x):
        sub_y = np.array([])
        for _z in z:
            # copy x:
            x0_at_point = x0_nlp.copy()
            lbx_at_point = param_est.lbx.copy() 
            ubx_at_point = param_est.ubx.copy() 
            # set Rie on x:
            x0_at_point[nlp_Rie_x_pos] = _x
            lbx_at_point[nlp_Rie_x_pos] = _x
            ubx_at_point[nlp_Rie_x_pos] = _x
            # set Rea on x:
            x0_at_point[nlp_Rea_x_pos] = _z
            # copy p:
            p_at_point = p0_nlp.copy()
            # set Rie on p:
            p_at_point[nlp_Rie_p_pos] = _x
            # set Rea on p:
            p_at_point[nlp_Rea_p_pos] = _z
            # f-value:
            """
            f_value = nlp_obj(
                x0_at_point,
                p_at_point
            )
            """
            sol = param_est.solver(
                x0=x0_at_point,
                lbx=lbx_at_point,
                ubx=ubx_at_point,
                lbg=param_est.lbg,
                ubg=param_est.ubg,
                p=p_at_point
            )
            sub_y = np.append(sub_y, float(sol["f"]))
            
        #sub_y = sub_y.reshape((1, sub_y.shape[0]))
        #y = np.append(y, sub_y, axis=1)
        if i == 0: 
            y = sub_y
        else:
            y = np.vstack([y, sub_y])
            
            
    import matplotlib.pyplot as plt
    import numpy as np

    from matplotlib import cm
    from matplotlib.ticker import LinearLocator

    fig, ax = plt.subplots(subplot_kw={"projection": "3d"})

    # Make data.
    #X = np.arange(-5, 5, 0.25)
    #Y = np.arange(-5, 5, 0.25)
    x, z = np.meshgrid(x, z)
    #R = np.sqrt(X**2 + Y**2)
    #Z = np.sin(R)

    # Plot the surface.
    surf = ax.plot_surface(x ,z , y, cmap=cm.coolwarm,
                        linewidth=0, antialiased=False)

    # Customize the z axis.
    #ax.set_zlim(-1.01, 1.01)
    ax.zaxis.set_major_locator(LinearLocator(10))
    # A StrMethodFormatter is used automatically
    ax.zaxis.set_major_formatter('{x:.02f}')

    # Add a color bar which maps values to colors.
    fig.colorbar(surf, shrink=0.5, aspect=5)

    plt.show()
    
    print(x)
    """
    import matplotlib.pyplot as plt
    import numpy as np

    from matplotlib import cm
    from matplotlib.ticker import LinearLocator

    fig, ax = plt.subplots(subplot_kw={"projection": "3d"})

    # Make data.
    X = np.arange(-5, 5, 0.25)
    Y = np.arange(-5, 5, 0.25)
    X, Y = np.meshgrid(X, Y)
    R = np.sqrt(X**2 + Y**2)
    Z = np.sin(R)

    # Plot the surface.
    surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm,
                        linewidth=0, antialiased=False)

    # Customize the z axis.
    ax.set_zlim(-1.01, 1.01)
    ax.zaxis.set_major_locator(LinearLocator(10))
    # A StrMethodFormatter is used automatically
    ax.zaxis.set_major_formatter('{x:.02f}')

    # Add a color bar which maps values to colors.
    fig.colorbar(surf, shrink=0.5, aspect=5)

    plt.show()
    """