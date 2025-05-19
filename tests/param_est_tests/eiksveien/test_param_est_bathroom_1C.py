#from ast import Param

import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
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
from analyse import df, df_ene, df_dhw, plot_apt, search_tags, apt_rooms
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
    sysid using PRBS.
    """

    cfg_path = os.path.join("configs", "2R1C.json")
    data_path = os.path.join("ZEBLab_dec24_jan25_1m.csv")

    df = df.sort_index()
    apt = "H0102"
    rooms = apt_rooms[apt]
    apt_df = plot_apt(df, apt = apt)
    
    name_map = {
        '1273_563_1074_RT601': 'Ti',
        '1273_563_1073_RT601': 'Tbedr',
        '1273_563_1074_LZ001': 'phi_h'
    }
    data = apt_df.loc[:, list(name_map.keys())].rename(
        columns=name_map
    )
    # area of bathroom:
    A = 6
    # on/off to power:
    W_p_sqm = 150
    data["phi_h"] *= W_p_sqm*A
    
    start = pd.Timestamp("2025-02-10 00:00").tz_localize("Europe/Oslo")
    stop = pd.Timestamp("2025-02-17 00:00").tz_localize("Europe/Oslo")
    dt = 300
    
    y_data = data.loc[start:stop]
    N = len(y_data)
    
    # interpolate away nan's, see if good enough:
    y_data = y_data.interpolate()
    y_data["dt_index"] = y_data.index
    y_data["y1"] = y_data["Ti"]
    y_data.index = range(len(y_data.index))

    param_guess = {
                    "Rbi": 
                    {
                        "init": 1e-2
                    },
                    "Ci":
                    {
                        "init": 1e6
                    }
    }

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12, 1000],
        "u_nom_b ": [289.15, 0],
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    
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
        if param_guess.get(name) is None:
            param_guess[name] = dict()
        param_guess[name]["init"] = value 
        param_guess[name]["lb"] = value*1E-3 
        param_guess[name]["ub"] = value*1E3 

    #param_guess["alpha_int_lig"]["ub"] = 1.0
    #param_guess["alpha_int_plugs"]["ub"] = 1.0
    param_guess["alpha_vent_sup"]["ub"] = 1.0
    param_guess["alpha_vent_ext"]["ub"] = 1.0
    param_guess["alpha_int"]["ub"] = 1.0
     
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    #y_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess


    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess
                    ) as param_est:

        Q = ca.DM.eye(1)
        R = ca.DM.eye(1)
        
        lbp = param_est.get_lbp(1e-3)
        ubp = param_est.get_ubp(1e3)
        p0 = param_est.p0
        sol, params = param_est.solve(
                                      y_data,
                                      p0,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=True
                                      )

        sol.index = y_data.dt_index
        ax = sol["Ti"].plot(color="r", linewidth=0.75, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"])
        plt.show()
    # dump for plots:
    print(params)