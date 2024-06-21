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
    data = pd.read_csv("ZEBLab_2024_1m.csv", index_col=0)
    # bfill:
    data.index = pd.to_datetime(data.index)
    data.index = data.index.tz_localize(None)
    # take subset of data:
    start = pd.Timestamp("2023-12-01 00:00")
    stop = pd.Timestamp("2023-12-20 00:00")
    data = data.loc[start:stop]
    
    data = data.resample("1h").mean()
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
    spots = df.T_219_TR1
    spots = spots - spots.mean()
    spots[spots > 0] = 0
    
    spots = spots.values
    # CUT overheating:

    # Get positive DFT of AQI
    N = year.shape[0]
    X = sf.rfft(spots) / N
    freqs = sf.rfftfreq(n=N, d=1) # unit = 1/12 of sampling period

    # Plot signal
    fig, axes = plt.subplots(figsize=(15,3), ncols=2)
    ax=axes[0]
    ax.plot(year, spots)
    ax.xaxis.set_major_locator(tck.MultipleLocator(50))
    #ax.grid()

    # Plot DFT
    ax=axes[1]
    extent = 5000#N
    ax.set_xlabel('period, hours')
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
    plt.show()
    
    print(data)