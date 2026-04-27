#from ast import Param

#import sys
import os
#import pathlib
#ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
#sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
from ocp.estimation import Estimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
#import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from matplotlib import rc
#from ocp.tests.utils import get_opt_config_path, get_data_path
#import os
from pandas.plotting import autocorrelation_plot
#from ocp.filters_old import KalmanBucy
from ocp.utils import prepare_data, ZEBData
#from ocp.covar_solver_cont_old import CovarianceSolverContinuous
from ocp.covar_solver import CovarianceSolver
from copy import deepcopy
from result_generator import ResultGenerator, plot_residuals
import matplotlib.dates as mdates
from scipy.signal import welch
rc('text', usetex=True)

param_guess = {
                "Rie": 
                {
                    "init": 1e-2
                },
                "Rea":
                {
                    "init": 1e-1
                },
                "Ci":
                {
                    "init": 1e6
                },
                "Ce":
                {
                    "init": 1e6
                },
                "Ai":
                {
                    "init": 10
                }
}

kwargs = {
    "x_nom": 12,
    "x_nom_b": 289.15,
    "u_nom": [12]*1 + [1E3,1E3],
    "u_nom_b ": [289.15]*1 + [0]*2,
    "y_nom": [12],
    "y_nom_b": [289.15],
    #"slack": True
    "slack": False
}
A = 60

priors = {
    "Rie": 0.250/A, # m²K / W 
    "Rea": 2.250/A, # m²K / W 
    "Ci": 9.50*3600*A, # Wh / m²K
    "Ce": 112*3600*A, # Wh / m²K
    "Ai": 10, # m²
}
for name, value in priors.items():
    param_guess[name]["init"] = value 
    param_guess[name]["lb"] = value*1E-3 
    param_guess[name]["ub"] = value*1E3 


if __name__ == "__main__":

    """
    sysid using PRBS.
    """

    cfg_path = os.path.join("configs", "2R2C.json")
    #data_path = os.path.join("ZEBLab_dec24_jan25_1m.csv")
    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")

    zeb_data = ZEBData(data_path)
    
    start = pd.Timestamp("2024-12-21 09:30")
    stop = pd.Timestamp("2024-12-31 00:00")
    #start = pd.Timestamp("2024-12-20 09:30")
    start = pd.Timestamp("2024-12-28 06:00")
    start = pd.Timestamp("2023-11-15 00:00")
    start = pd.Timestamp("2024-01-01 00:00")
    #stop = pd.Timestamp("2025-01-01 06:00")
    stop = pd.Timestamp("2024-02-01 00:00")
    sampling_rate = "15min"
    # interpolate away nan's, see if good enough:
    y_data, dt, N = zeb_data.get_dataset(
                                        start=start, 
                                        stop=stop,
                                        sampling_rate=sampling_rate
                                        )
    y_data["Ti"] = y_data["yTi"]
    y_data.index = y_data.dt_index
    normal_op_phi = y_data.phi_h
    N = 2
    M = 10
    mean_padding = 2 # num sampling intervals
    sampling_rate = "15min"
    rng = np.random.default_rng(seed=42)
    # select phi_h:
    s = y_data["phi_h"]
    # 1. Mask non-zero values
    mask = s.ne(0)
    # 2. Identify blocks
    block_id = (~mask).cumsum()
    # 3. Filter for non-zeros and count sequence lengths
    non_zero_lengths = s[mask].groupby(block_id[mask]).size()
    non_zero_but_not_one = non_zero_lengths.loc[non_zero_lengths != 1]
    # 4. Get 2 longest
    longest_n = non_zero_lengths.nlargest(N)
    #shortest_m = non_zero_but_not_one.nsmallest(M)
    shortest_m_ = non_zero_lengths.nsmallest(M)
    shortest_m_not_one = non_zero_but_not_one.nsmallest(M)
    shortest_m = pd.concat([shortest_m_, shortest_m_not_one])
    shortest_m = shortest_m.sample(frac=1)
    #print(longest_n)
    #print(shortest_m)
    
    
    def get_padding(
        mean_padding,
        mean_fallback=False
    ):
        pad = rng.normal(
            loc=mean_padding, scale=1.0, size=1
        )
        pad = int(pad)
        if pad < 1:
            if mean_fallback:
                pad = mean_padding
            else:
                pad = 1
        return pad
    
    def merge_blocks(
        block_id,
        blocks,
        orig_s,
        new_s,
        N,
        start_pad=5,
        stop_pad=25,
        mean_padding=5
    ):
        for n in range(N):
            index = block_id[block_id == blocks.index[n]].index
            if n == 0:
                new_start = index[0] - pd.Timedelta(minutes=15*start_pad)
            else:
                pad = get_padding(
                    mean_padding,
                    mean_fallback=True
                )
                new_start = index[0] - pd.Timedelta(minutes=15*pad)
            
            if n == (N-1):
                new_stop = index[0] + pd.Timedelta(minutes=15*stop_pad)
            else:
                pad = get_padding(
                    mean_padding,
                    mean_fallback=True
                )
                new_stop = index[-1] + pd.Timedelta(minutes=15*pad)
                
            index = pd.date_range(
                start=new_start,
                end=new_stop,
                freq=sampling_rate
            )
            #to_add = orig_s.loc[index[0]:index[-1]]
            #to_add.index = range(len(to_add.index))
            new_s.append(index)
        return new_s
    
    long_seq = []
    long_seq = merge_blocks(
        block_id, 
        longest_n,
        s, 
        long_seq,
        N,
        mean_padding=15,
        start_pad=30,
        stop_pad=50
    )
    #long_seq.index = range(len(long_seq.index))
        
    short_seq = []
    short_seq = merge_blocks(
        block_id, 
        shortest_m,
        s, 
        short_seq,
        M*2,
        mean_padding=mean_padding,
        start_pad=30,
        stop_pad=25
    )
    """
    Try with two problems first (see if memory issues):
    """
    
    # same for all probs:
    
    
    probs = []
    p_vals = ca.DM()
    for seq_index in long_seq:
        data = y_data.loc[seq_index[0]:seq_index[-1]]
        N = len(data)
        dt, _N = zeb_data.get_meta_for_parest(
                                    start,
                                    1,
                                    sampling_rate
                                    )

        # constrain in particular Th to physically meaningful values:
        x_guess = np.array([
                        data.Ti.values.flatten(),
                        data.Ti.values.flatten() - 2
                        ])
        lbx = 0.7*x_guess
        ubx = 2.0*x_guess
        
        param_est = Estimation(
            config=cfg_path,
            N=N,
            dt=dt,
            param_guess=param_guess,
            arrival_cost=False
        )
        lbp = param_est.get_lbp(1e-3)
        ubp = param_est.get_ubp(1e3)
        P0 = np.eye(param_est.n_p + param_est.n_x)*1
        P0[
        param_est.n_p:(param_est.n_p + param_est.n_x),
        param_est.n_p:(param_est.n_p + param_est.n_x)
        ] = 0
        p0 = param_est.p0
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        # pre-solve:
        covar = ca.veccat(Q, R)
        p_vals = ca.veccat(p_vals, covar)
        param_est.presolve(
            data,
            p0,
            covar=covar,
            lbp=lbp,
            ubp=ubp,
            lbx=lbx,
            ubx=ubx,
            P0=P0,
            x_N=x_guess[-1,-param_est.n_x:],
            x_guess=x_guess,
        )
        probs.append(param_est)
    
    """
    How to merge the problems?
    
    Objectives can be summed.
    
    Constraints can be concatenated.
    
    p_1 = p_2 = ... = p_M needs to be enforced.
    """
    
    g_extra = []
    for i, prob in enumerate(probs):
        if i == len(probs) - 1:
            break
        p_equals_p = prob.integrator.p - probs[i+1].integrator.p
        g_extra.append(p_equals_p)
    
    f = 0
    g = ca.MX()
    x = ca.MX()
    x0 = np.array([])
    lbx = np.array([])
    ubx = np.array([])
    lbg = np.array([])
    ubg = np.array([])
    nlp_p = ca.MX()
    for i, prob in enumerate(probs):
        # scalar f
        f = f + prob.nlp["f"]
        # parameters:
        nlp_p = ca.veccat(nlp_p, prob.Q, prob.R)
        # vertcat g:
        g = ca.vertcat(g, prob.nlp["g"])
        x = ca.vertcat(x, prob.nlp["x"])
        x0 = np.concatenate([x0, prob.x0])
        lbx = np.concatenate([lbx, prob.lbx])
        ubx = np.concatenate([ubx, prob.ubx])
        lbg = np.concatenate([lbg, prob.lbg])
        ubg = np.concatenate([ubg, prob.ubg])

    # extra zeros from p=p:
    lbg_extra = np.array([])
    ubg_extra = np.array([])
    for _g in g_extra:
        lbg_extra = np.concatenate([
            lbg_extra, np.zeros(_g.shape[0])
        ])
        ubg_extra = np.concatenate([
            ubg_extra, np.zeros(_g.shape[0])
        ])
    
    nlp = {
        "f": f,
        "g": ca.vertcat(g, *g_extra),
        "x": x,
        "p": nlp_p
    }
    
    # new solver:
    solver = ca.nlpsol(
        "solver", \
        "ipopt",
        nlp,
        prob.opt
    )
    
    solution = solver(
        x0=x0,
        lbg=np.concatenate([lbg, lbg_extra]),
        ubg=np.concatenate([ubg, ubg_extra]),
        lbx=lbx,
        ubx=ubx,
        p=p_vals
    )
    
    sol_df = prob
    
    print("tail")
    
    
    """
    lbp = param_est.get_lbp(1e-3)
    ubp = param_est.get_ubp(1e3)
    P0 = np.eye(param_est.n_p + param_est.n_x)*1
    P0[
    param_est.n_p:(param_est.n_p + param_est.n_x),
    param_est.n_p:(param_est.n_p + param_est.n_x)
    ] = 0
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
                                #codegen=True,
                                P0=P0,
                                x_N=x_guess[-1,-param_est.n_x:]
                                )
    """