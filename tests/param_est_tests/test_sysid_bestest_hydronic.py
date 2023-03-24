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
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF
from matplotlib import rc
from ocp.covar_solve import CovarianceSolver
import os
import matplotlib.pyplot as plt
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path, get_data_path
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    cfg_path = os.path.join(opt_config_base, "3R3C_bestest_hydronic.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = False

    boptest = Boptest(
                      boptest_cfg,
                      name="bestest_hydronic"
                      )
    
    sampling_time = "15min"
      
    data_path = os.path.join(get_data_path(), "data_bestest_hydronic.csv")
    
    if GENERATE_DATA:
        
        prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"))
        prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        dt_index = prbs.index
        prbs.Ph /= 5
        prbs = prbs.Ph
        prbs = prbs.resample(sampling_time).first()
        prbs.index = range(len(prbs.index))
        # baseline control for sysid:
        N = len(prbs)
        
        
        #u_measured = []
        for n in range(N):
            u_0 = pd.Series(index=['Tset'], data=[288.15 + prbs.loc[n]*15])
            _, y_meas, u_meas = boptest.evolve(u=u_0)
            #u_measured.append(u_meas)
            
            
        data = boptest.get_data(tf=N*boptest.h, downsample=False)
        #data_path = os.path.join(get_data_path(), "data_bestest_hydronic.csv")
        data.to_csv(data_path)
    
    else:
        data = pd.read_csv(data_path)
    
    # plot: here:
    
    #ax = data.Ti.plot(color="r")
    #data.oveTSetHea_u.plot(color="y", drawstyle="steps-post", ax=ax)
    #plt.show()
    


    """ 
    Possible to turn the following Modelica-function into casadi?
        
    function regStep
        "Approximation of a general step, such that the characteristic is continuous and differentiable"
        extends Modelica.Icons.Function;
        input Real x "Abscissa value";
        input Real y1 "Ordinate value for x > 0";
        input Real y2 "Ordinate value for x < 0";
        input Real x_small(min=0) = 1e-5
            "Approximation of step for -x_small <= x <= x_small; x_small >= 0 required";
        output Real y "Ordinate value to approximate y = if x > 0 then y1 else y2";
    algorithm
            y := smooth(1, if x >  x_small then y1 else
                            if x < -x_small then y2 else
                            if x_small > 0 then (x/x_small)*((x/x_small)^2 - 3)*(y2-y1)/4 + (y1+y2)/2 else (y1+y2)/2);
    end regStep;
    
    
    x = ca.MX.sym("x")
    y1 = ca.MX.sym("y1")
    y2 = ca.MX.sym("y2")
    x_small = ca.MX.sym("x_small")
    _y = ca.MX.sym("y")
    
    y = ca.tanh(ca.if_else(x > x_small, y1, ca.if_else(x < -x_small, y2, ca.if_else(x_small > 0, (x/x_small)*(ca.power((x/x_small), 2) - 3)*(y2-y1)/4 + (y1+y2)/2, (y1+y2)/2))))
    
    y_jac = ca.jacobian(y, x)
    
    F = ca.Function("regStep", [x,y1,y2,x_small], [y], ["x", "y1", "y2", "x_small"], ["y"])
    
    ys = []
    _y1 = -1
    _y2 = 1
    
    _x_small = 1E-5
    for _x in range(-50, 50):
        __x = _x*0.1
        y_val = F(__x, _y1, _y2, _x_small)
        ys.append(float(y_val))
    plt.plot(ys)
    
    
    param_guess = ca.DM([0.01,0.1,1E6,1E7,2])
    lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    ubp = ca.DM([0.1,1,1E7,1E8,50])

    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)
    params = {}
    covar = {}
    dt = 900 
    

    """
    