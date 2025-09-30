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

    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    Data = ZEBData(data_path)
    """
    Hyper-parameters for run:
    """
    start = pd.Timestamp("2023-11-15 00:00")
    stop = pd.Timestamp("2023-11-29 00:00")
    N_days = 1
    days = 1
    sampling_rate = "15min"
    plot = True
    cfg_path = os.path.join(
                            "configs", 
                            "2R2C_int_gains_sep_bal_vent.json"
                            )
    data, dt, N = Data.get_dataset(
        start,
        stop,
        sampling_rate="15min"
    )
    param_est = Estimation(config=cfg_path,
                N=N,
                dt=dt,
                param_guess=param_guess,
                arrival_cost=True,
                **kwargs,
                )
    
    ######### meta-params ########
    prior_weight = 0
    lbp = param_est.get_lbp(1e-2)
    ubp = param_est.get_ubp(1e2)
    y_data = data
    p0 = param_est.p0
    P0 = ca.DM.eye(param_est.n_p + param_est.n_x)*prior_weight
    Q, R = ca.DM.eye(param_est.n_x), ca.DM.eye(param_est.n_y)
    x_guess = np.array([
                y_data.y1.values.flatten(),
                y_data.y1.values.flatten() - 2
                ])
    for n in range(param_est.n_p, param_est.n_p + param_est.n_x):
        P0[n,n] = 0
    lbx = 0.7*x_guess
    ubx = 2*x_guess
    ##############################
    sol, params = param_est.solve(
            y_data,
            #param_est.p0,
            p0,
            lbp=lbp,
            ubp=ubp,
            lbx=lbx,
            ubx=ubx,
            x_guess=x_guess,
            x_N = np.array([293.15]*param_est.n_x), # not used
            P0=P0,
            covar=ca.veccat(Q, R),
            codegen=False
            )
    
    params_sol = params.copy()
    # integrator, H:
    F = param_est.integrator.one_sample.map(N)
    H = param_est.strategy.h_map
    """
    Steps:
    - Do ONE Ipopt solve
    Brute-force sensitivity analysis from *w (optimal NLP-solution):
    
    for n in N:
        for j in J.
            - Simulate
            - Use x from simulation to find meas. gaps ('v')
            - Calculate obj-function (including prior)
    
    Then: 
    - Do it scaled
    """
    
    #x = np.arange(1e-3,1e-1,1e-3) # Rie
    #z = np.arange(1e-3,1e-1,1e-3) # Rea
    
    x = np.arange(1e6,1e7,1e6) # Ci
    z = np.arange(1.1e7,2e7,1e6) # Ce
    
    x = np.arange(1e6,1e7,1e6) # Ci
    z = np.arange(1e7,1e8,1e7) # Ce
    
    #relative_pos_Rie = param_est.dae.p.index("Rie")
    #relative_pos_Rea = param_est.dae.p.index("Rea")
    relative_pos_Rie = param_est.dae.p.index("Ci")
    relative_pos_Rea = param_est.dae.p.index("Ce")
    
    x0 = sol.iloc[1][["Ti", "Te"]].values
    p_nom = param_est.p_nom
    
    for i, _x in enumerate(x):
        sub_y = np.array([])
        for _z in z:
            # simulate with p0
            p = params.values
            p[relative_pos_Rie] = _x
            p[relative_pos_Rea] = _z
            x_sim = F(
                x0=x0,
                u=data[param_est.u_names].values.T,
                p=p
            )["xf"]
            v_sim = H(
                y=data[param_est.y_names].values.T,
                x=x_sim,
                u=data[param_est.u_names].values.T,
                p=p,
                v=0
            )["h"]
            obj_value = ca.dot(
                v_sim, v_sim
            ) + \
            prior_weight*ca.dot(
                p0/p_nom - p/p_nom, p0/p_nom - p/p_nom
            )
            sub_y = np.append(sub_y, obj_value)
            print(v_sim)
        if i == 0: 
            y = sub_y
        else:
            y = np.vstack([y, sub_y])
            
    """
    Get objective values for different values of Rie, Rea.
    """
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
