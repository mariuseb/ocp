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
from utils import prepare_data, ZEBData, quick_plot
from result_generator import ResultGenerator
from ocp.filters import KalmanDAE
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
    Check of resampling facilities.
    """
    
    data_path = os.path.join("ZEBLab_nov23_feb24_1m.csv")
    Data = ZEBData(data_path)
    """
    Hyper-parameters for run:
    """
    #start = pd.Timestamp("2024-01-01 00:00")
    start = pd.Timestamp("2023-11-15 00:00")
    stop = start + pd.Timedelta(days=1)
    
    test, dt, N = Data.get_dataset(
        start=start,
        stop=stop,
        sampling_rate="1min"
    )
    
    """
    Check difference between walking through and summing phi_h,
    and re-sampling.
    """
    
    sampling_rate = "60min"
    
    test.index = test.dt_index
    test_1H_pd = test.groupby(pd.Grouper(freq=sampling_rate)).mean().dropna()
    test_1H_pd["phi_h_man"] = 0
    

    for n in range(24):
        phi_h_sum = 0
        for m in range(60):
            phi_h_sum += test["phi_h"].iloc[n*60 + m - 1]
        test_1H_pd["phi_h_man"].iloc[n] = phi_h_sum/60
        
    # resample back to 1 min using ffill:
    test_1min = test_1H_pd.resample(rule="1min").ffill()
    test_1min["phi_h_real"] = test["phi_h"]
    test_1min["Ti_real"] = test["Ti"]
    # inspect 07:35-08:00
    start = pd.Timestamp("2023-11-15 06:00")
    stop = pd.Timestamp("2023-11-15 08:00")
    test_1min.loc[start:stop, ["phi_h", "phi_h_man", "phi_h_real", "Ti", "Ti_real"]]
    
    print(test_1min["phi_h_sum"])