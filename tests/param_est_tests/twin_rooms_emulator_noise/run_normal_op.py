#%% 
#from ast import Param
from ocp.param_est import ParameterEstimation
from ocp.mpc import MPC

import numpy as np
import json
import casadi as ca
import ocp
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api_old import Boptest
from pprint import pprint
#from ocp.filters import EKF
from matplotlib import rc
from pprint import pprint
#from ocp.covar_solve import CovarianceSolver
import os
import matplotlib.pyplot as plt
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.functions import functions
#from ocp.nn import ParamDataset, NN
#import torch
from ocp.ocp import ParamGuess
#import l4casadi as l4c
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    #wea = pd.read_csv("weather.csv", index_col=0)
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    #cfg_path = os.path.join("configs", "4R3C_vent_n_power_eff_non_linear.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = True
    PLOT = False
    
    """
    Normal operation for e.g. a week.

    Try to identify separate HVAC-model with results.
    """
    boptest = Boptest(
                    boptest_cfg,
                    name="twin_rooms_emulator"
                    #name="testcase1"
                    )
    data_path = os.path.join(
                            "twin_rooms_emulator_normal_op.csv"
                            )

    
    if GENERATE_DATA:
        
        sampling_time = "15min"
        #prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"), sep=";")
        prbs = pd.read_csv("PRBS_modified.csv", sep=",", index_col=0)
        #prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        #dt_index = prbs.index
        prbs.index = pd.to_timedelta(prbs.index)
        prbs.Ph /= 100
        prbs = prbs.Ph
        prbs = prbs.round(0)
        prbs = prbs.resample(sampling_time).first()
        prbs.index = range(len(prbs.index))
        # baseline control for sysid:
        N = len(prbs)
        #N = 10
        # run prbs:
        for n in range(N):
            try:
                #_, y_meas, u_meas = boptest.evolve(u=u_0)
                _, y_meas, u_meas = boptest.evolve()
            except TypeError:
                print(y_meas)
            #u_measured.append(u_meas)
        data = boptest.get_results(tf=N*boptest.h + 672*boptest.h, resample=False)
        #data = boptest.get_data(tf=N*boptest.h + 672*boptest.h, downsample=False)
        data.to_csv(data_path)
        res = boptest.get_data(tf=N*boptest.h)
    else:
        data = pd.read_csv(data_path, index_col=0)
    print(data)
    