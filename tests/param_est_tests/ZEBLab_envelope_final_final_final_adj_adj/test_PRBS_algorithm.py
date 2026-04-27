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
    #start = pd.Timestamp("2024-01-01 00:00")
    #stop = pd.Timestamp("2025-01-01 06:00")
    stop = pd.Timestamp("2024-02-01 00:00")
    sampling_rate = "15min"
    
    # interpolate away nan's, see if good enough:
    y_data, dt, N = zeb_data.get_dataset(
                                        start=start, 
                                        stop=stop,
                                        sampling_rate=sampling_rate
                                        )
    # causality shift:
    #y_data["phi_h"] = y_data["phi_h"].shift(1).fillna(0)
    y_data.index = y_data.dt_index
    normal_op_phi = y_data.phi_h
    
    #prbs_like = pd.Series([])
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
    # 
    non_zero_but_not_one = non_zero_lengths.loc[non_zero_lengths != 1]

    # 4. Get 2 longest
    longest_n = non_zero_lengths.nlargest(N)
    #shortest_m = non_zero_but_not_one.nsmallest(M)
    shortest_m_ = non_zero_lengths.nsmallest(M)
    shortest_m_not_one = non_zero_but_not_one.nsmallest(M)
    shortest_m = pd.concat([shortest_m_, shortest_m_not_one])
    shortest_m = shortest_m.sample(frac=1)
    print(longest_n)
    print(shortest_m)
    
    ### actual PRBS:
    data_path = os.path.join("ZEBLab_dec24_jan25_1m.csv")
    zeb_data = ZEBData(data_path)
    start = pd.Timestamp("2025-01-01 00:00")
    stop = pd.Timestamp("2025-12-31 00:00")
    sampling_rate = "15min"
    y_data, dt, _N = zeb_data.get_dataset(
                                        start=start, 
                                        stop=stop,
                                        sampling_rate=sampling_rate
                                        )
    actual_prbs = y_data.phi_h
    
    # 1. Mask non-zero values
    _mask = actual_prbs.ne(0)

    # 2. Identify blocks
    _block_id = (~_mask).cumsum()

    # 3. Filter for non-zeros and count sequence lengths
    _non_zero_lengths = actual_prbs[_mask].groupby(_block_id[_mask]).size()
    print(_non_zero_lengths)

        
    """
    for n in range(N):
        index = block_id[block_id == longest_n.index[n]].index
        if n == 0:
            new_start = index[0] - pd.Timedelta(hours=5)
        else:
            start_pad = rng.normal(
                loc=mean_padding, scale=1.0, size=1
            )
            start_pad = int(start_pad)
            new_start = index[0] - pd.Timedelta(minutes=15*start_pad)
            
        stop_pad = rng.normal(
            loc=mean_padding, scale=1.0, size=1
        )
        stop_pad = int(stop_pad)
        new_stop = index[-1] + pd.Timedelta(minutes=15*stop_pad)
            
        index = pd.date_range(
            start=new_start,
            end=new_stop,
            freq=sampling_rate
        )
        to_add = s.loc[index[0]:index[-1]]
        #to_add.index = range(len(to_add.index))
        prbs_like = pd.concat([
            prbs_like, to_add
        ])
    """
    
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
            to_add = orig_s.loc[index[0]:index[-1]]
            #to_add.index = range(len(to_add.index))
            new_s = pd.concat([
                new_s, to_add
            ])
        return new_s
    
    long_seq = pd.Series([])
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
    long_seq.index = range(len(long_seq.index))
        
    short_seq = pd.Series([])
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
    short_seq.index = range(len(short_seq.index))
    
    prbs_like = pd.concat([long_seq, short_seq])
    
    prbs_like.index = range(len(prbs_like.index))
    actual_prbs.index = range(len(actual_prbs.index))
    normal_op_phi.index = range(len(normal_op_phi.index))
    
    kwargs = {
        "drawstyle": "steps-post"
    }
    
    fig, axes = plt.subplots(3,2, figsize=(12,15))
    
    row = axes[0,:]
    row[0].set_title("Original PRBS")
    actual_prbs.plot(ax=row[0], **kwargs)
    row[1].psd(actual_prbs, **kwargs)
    row[1].set_ylim([10,80])
    row[1].set_yticks(range(10,90,10))
    
    
    row = axes[1,:]
    row[0].set_title("Normal op.")
    normal_op_phi.plot(ax=row[0], **kwargs)
    row[1].psd(normal_op_phi, **kwargs)
    row[1].set_ylim([10,80])
    row[1].set_yticks(range(10,90,10))
    
    row = axes[2,:]
    row[0].set_title("PRBS-like")
    prbs_like.plot(ax=row[0], **kwargs)
    row[1].psd(prbs_like, **kwargs)
    row[1].set_yticks(range(10,90,10))
    
    plt.show()
    
    print("tail")