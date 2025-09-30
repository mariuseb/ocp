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
from matplotlib import cm
from matplotlib.ticker import LinearLocator
from mpl_toolkits.mplot3d import Axes3D
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
    
    
    def calculate_sens(prior_weight):
    
        ######### meta-params ########
        lbp = param_est.get_lbp(1e-8)
        ubp = param_est.get_ubp(1e8)
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
        sol, params, raw_sol = param_est.solve(
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
                codegen=False,
                return_raw_sol=True
                )
        
        params_sol = params.copy()
        # integrator, H:
        F = param_est.integrator.one_sample.mapaccum(N-1)
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
        
        x = np.arange(-1e7,1e7,1e6) # Ci
        z = np.arange(-1e8,1e8,1e7) # Ce
        
        x = np.arange(-1e7,1e7,1e5) # Ci
        z = np.arange(-1e8,1e8,1e6) # Ce
        
        x = np.arange(-10e6,10e6,1e6) # Ci
        z = np.arange(-10e7,10e7,1e7) # Ce
        
        x = np.arange(1e6,20e6,1e6) # Ci
        z = np.arange(1e7,20e7,1e7) # Ce
        
        x = np.arange(1e5,1e7,1e5) # Ci
        z = np.arange(1e6,1e8,1e6) # Ce
        
        #x = np.arange(1e6,3e6,1e6) # Ci
        #z = np.arange(1e7,3e7,1e7) # Ce
        
        x[x == 0] = 1e7
        z[z == 0] = 1e8
        
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
                    u=data[param_est.u_names][:-1].values.T,
                    p=p
                )["xf"]
                x_sim =  ca.horzcat(x0, x_sim)
                v_sim = H(
                    y=data[param_est.y_names].values.T,
                    x=x_sim,
                    u=data[param_est.u_names].values.T,
                    p=p,
                    v=0
                )["h"]
                obj_value = ca.dot(
                    v_sim/12, v_sim/12
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
                
        # Make data 3D-compliant:
        x, z = np.meshgrid(x, z)
        
        ret = {
            "x": x,
            "z": z,
            "y": y
        }
        return ret
        
    points = dict()
    points[1] = calculate_sens(1)
    points[0] = calculate_sens(0)
    
        
    #plt.gca().ticklabel_format(axis='y', style='sci', scilimits=(0, 0))
    
    def normalize_axis(ax, existing_ticks, which=None):
        #custom_y_ticks = [0, 1e8]
        #custom_y_ticks = list(np.arange(1e7,1.1e8,1e7))
        custom_labels = ['']*len(existing_ticks)
        custom_labels[0] = 0
        custom_labels[-1] = 1
        #custom_y_labels = ['0', '1']
        method = getattr(ax, "set_" + which + "ticks")
        #ax.set_yticks(existing_ticks, labels=custom_labels)
        method(existing_ticks, labels=custom_labels)
        
        # Get all x-tick labels
        axis = getattr(ax, which + "axis")
        ticks = axis.get_major_ticks()
        for tick in ticks: 
            tick.label1.set_visible(False)
        ticks[0].label1.set_visible(True)
        ticks[-1].label1.set_visible(True)
    
    def plot_surface(x, y, z, index, title):
        #ax = fig.add_subplot((1,2,index), projection='3d')
        subplot_arg = int("12" + str(index+1))
        ax = fig.add_subplot(subplot_arg, projection='3d')
        surf = ax.plot_surface(
            x, z, y,
            #cmap=cm.summer,
            #cmap="Greys",
            cmap=cm.jet,
            linewidth=0,
            antialiased=True,
            #computed_zorder=False
        )
        # Customize the z axis.
        zlims = ax.get_zlim()
        #ax.set_zlim(0, zlims[1])
        ax.set_zlim(0, 100)
        ax.zaxis.set_major_locator(LinearLocator(11))
        # A StrMethodFormatter is used automatically
        ax.zaxis.set_major_formatter('{x:.00f}')
        #ax.ticklabel_format(style='sci',scilimits=(0,0),axis='both')
        # Add a color bar which maps values to colors.
        #if prior_weight == 1:
        #    fig.colorbar(surf, shrink=0.5, aspect=5)
        #ax.set_zlabel("$f(x,p)$")
        ax.set_xlabel("$p_1$", rotation=0)
        ax.set_ylabel("$p_2$", rotation=0)
        #ax.set_yticklabels([0, 1e8])
        #ax.set_xticklabels([0, 1e7])
        
        #ax.grid(True)
        #custom_x_ticks = [0, 1e7]
        custom_x_ticks = list(np.arange(1e6,1.1e7,1e6))
        custom_y_ticks = list(np.arange(1e7,1.1e8,1e7))
        custom_z_ticks = list(np.arange(0,100,10))
        normalize_axis(ax, custom_x_ticks, which="x")
        normalize_axis(ax, custom_y_ticks, which="y")
        normalize_axis(ax, custom_z_ticks, which="z")

        ax.tick_params(axis='x', pad=-5) # Set pad to 0 for minimum distance
        ax.tick_params(axis='z', pad=0) # Set pad to 0 for minimum distance
        ax.tick_params(axis='y', pad=-5) # Set pad to 0 for minimum distance
        ax.xaxis.labelpad = -12 # Adjust X-axis label distance
        ax.yaxis.labelpad = -12 # Adjust Y-axis label distance
        ax.zaxis.labelpad = -12 # Adjust Y-axis label distance
        ax.set_title(title)
        return ax
    
    fig = plt.figure()
    wo_prior = points[0]
    ax1 = plot_surface(
        wo_prior["x"], 
        wo_prior["y"],
        wo_prior["z"],
        0,
        #"$f(w) = \| v \|_{S}^{2}$"
        "$f(x,p) = V_{N|0}(x,p)$"
    )
    w_prior = points[1]
    ax2 = plot_surface(
        w_prior["x"], 
        w_prior["y"],
        w_prior["z"],
        1,
        #"$f(w) = \| v \|_{S}^{2} + \| \overline{p} \|_{P}^{2}$"
        #"$f(w) = \| v \|_{S}^{2} + \Pi(p)$"
        "$f(x,p) = V_{N|0}(x,p) + \Pi(p)$"
    )
    fig.tight_layout()
    plt.show()
       
    print("head")
