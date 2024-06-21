#from ast import Param

import sys
import os
import pathlib
#ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
#sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
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
from utils import prepare_data
from ocp.functions import functions
from pandas.plotting import autocorrelation_plot
import numpy as np
import scipy.fft as sf
import matplotlib.pyplot as plt
import matplotlib.ticker as tck
import matplotlib.ticker as plticker
# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates

if __name__ == "__main__":

    """
    Proof of concept for grey-box SYSID, ZEB Lab.
    Use room 219 first.
    """

    cfg_path = os.path.join("configs", "Tsup_Tret_m_flow_TVP.json")
    #data_path = os.path.join("ZEBLab_year_15m_T_last.csv")
    data = pd.read_csv("boptest_results_MPC_EKF_N=24.csv", index_col=0)
    # bfill:
    #data.index *= 3600
    data.index = pd.to_datetime(data.index, unit="s").round("1min")
    data.index = data.index.tz_localize(None)
    # take subset of data:
    start = pd.Timestamp("1970-01-01 00:00")
    stop = pd.Timestamp("1970-01-02 18:00")
    #start = pd.Timestamp("1970-01-02 18:00")
    #stop = pd.Timestamp("1970-01-07 18:00")
    data = data.loc[start:stop]
    
    #data = data.resample("5min").mean()
    #data = data[data.T_219_TR1 <= 22]
    #data = data[data.V_sup_air_219 > 0]
    # Read values, select columns, convert to numpy array
    #df = pd.read_excel(fp)
    df = data
    df["mins"] = range(len(df))
    #df = df.take([3, 1, 4], axis=1)
    data = df.to_numpy()

    # Sort by date, extract columns in invidual views, remove DC offset
    #data = data[data[:,0].argsort()]
    year = df.mins.values
    spots = df.Ti
    #spots[spots > 0] = 0
    spots = spots - spots.mean()
    
    spots = spots.values
    # CUT overheating:

    # Get positive DFT of AQI
    N = year.shape[0]
    X = sf.rfft(spots) / N
    freqs = sf.rfftfreq(n=N, d=1) # unit = 1/12 of sampling period

    # cut out first / last:
    freqs = freqs[1:]
    X = X[1:]

    # Plot signal
    fig, axes = plt.subplots(figsize=(15,3), ncols=2)
    ax=axes[0]
    ax.plot(year, spots)
    ax.xaxis.set_major_locator(tck.MultipleLocator(50))
    #ax.grid()

    # Plot DFT
    ax=axes[1]
    extent = len(freqs)
    ax.set_xlabel("$n * T_{s}$")
    ax.stem(freqs[:extent], abs(X[:extent]))
    ticks = ax.get_xticks()
    dfreq = ticks[1] - ticks[0]
    ticks = np.arange(ticks[0], ticks[-1] + dfreq, dfreq/2)
    ticks = ticks[2:-3]
    #ticks = np.concatenate([np.array([-0.2]), ticks, np.array([0.7, 0.8])])
    #loc = plticker.MultipleLocator(base=0.1) # this locator puts ticks at regular intervals
    #ax.xaxis.set_major_locator(loc)
    ax.set_xticks(ticks)
    ax.set_xticklabels([f'{1/tick:.1f}' if tick!=0 else '$\infty$' for tick in ticks])
    ax.invert_xaxis()
    ax.grid()
    ylim = (-0.0407554498380634, 0.8558644465993315)
    ax.set_ylim(ylim)
    plt.show()
    
    print(data)