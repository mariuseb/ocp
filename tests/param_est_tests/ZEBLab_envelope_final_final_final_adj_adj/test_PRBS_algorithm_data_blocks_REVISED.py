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
        mean_padding=5,
        start_pad=80,
        stop_pad=100
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
        stop_pad=60
    )

    tot_seq = long_seq + short_seq
    
    # release shooting contraints at these indices:
    merge_inds = []
    tot_data = pd.DataFrame()
    n_x = 2
    #for i, seq in enumerate(long_seq):
    for i, seq in enumerate(tot_seq):
        if i < len(tot_seq) - 1:
            base_ind = len(tot_data) + len(seq) - 1
            for n in range(n_x):
                merge_inds.append(
                    base_ind*n_x + n
                )
        tot_data = pd.concat([tot_data, y_data.loc[seq[0]:seq[-1]]])
        
    N = len(tot_data)
    dt, _N = zeb_data.get_meta_for_parest(
                                start,
                                1,
                                sampling_rate
                                )

    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    tot_data.Ti.values.flatten(),
                    tot_data.Ti.values.flatten() - 2
                    ])
    lbx = 0.7*x_guess
    ubx = 2.0*x_guess
    
    param_est = Estimation(
        config=cfg_path,
        N=N,
        dt=dt,
        param_guess=param_guess,
        arrival_cost=True,
        **kwargs
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
    covar = ca.veccat(Q, R)
    """
    Before solving, 'release' g / shooting 
    constraints at merge_inds.
    """
    param_est.presolve(
        tot_data,
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
    for ind in merge_inds:
        param_est.lbg[ind] = -1E3
        param_est.ubg[ind] = 1E3
        
    solution = param_est.solver(
        x0=param_est.x0,
        lbg=param_est.lbg,
        ubg=param_est.ubg,
        lbx=param_est.lbx,
        ubx=param_est.ubx,
        p=param_est.p_val
    )
    sol_df, params = param_est.parse_solution(
        solution
    )
    
    print("tail")
    