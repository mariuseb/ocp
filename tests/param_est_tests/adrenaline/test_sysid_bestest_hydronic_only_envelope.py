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
from pprint import pprint
#from ocp.covar_solve import CovarianceSolver
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
    
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_hydronic_gn.json")
    #cfg_path = os.path.join(opt_config_base, "3R3C_bestest_Tsup_linear.json")
    #cfg_path = os.path.join(opt_config_base, "2R3C_bestest_Tsup_DAE.json")
    #cfg_path = os.path.join(opt_config_base, "2R2C_bestest_Tsup_linear_UAnom_1meas.json")
    #cfg_path = os.path.join("configs", "2R2C_func_DAE.json")
    cfg_path = os.path.join("configs", "2R2C_orig.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = False

    boptest = Boptest(
                      boptest_cfg,
                      name="adrenaline1"
                      )
    
    sampling_time = "15min"
      
    data_path = os.path.join(get_data_path(), "data_bestest_hydronic.csv")
    
    if GENERATE_DATA:
        
        prbs = pd.read_csv(os.path.join(get_data_path(), "inputPRBS1.csv"), sep=";")
        prbs.index = pd.TimedeltaIndex(prbs.t, unit="H").round(freq="S")
        dt_index = prbs.index
        prbs.Ph /= 5
        prbs = prbs.Ph
        prbs = prbs.round(0)
        prbs = prbs.resample(sampling_time).first()
        prbs.index = range(len(prbs.index))
        # baseline control for sysid:
        N = len(prbs)
        
        
        #u_measured = []
        for n in range(N):
            u_0 = pd.Series(index=['dh_Tsup'], data=[283.15 + prbs.loc[n]*50])
            u_0["TsetHea"] = 283.15 + prbs.loc[n]*20
            #u_0["TsetHea"] = 318.15
            u_0["dh_pump"] = prbs.loc[n]
            #u_0["ahu_pump_sup"] = prbs.loc[n] + 0.01*(1 - prbs.loc[n])
            #u_0["ahu_pump_ret"] = prbs.loc[n] + 0.01*(1 - prbs.loc[n])
            u_0["ahu_pump_sup"] = 0.01
            u_0["ahu_pump_ret"] = 0.01
            #u_0["ahu_Tsup"] = 288.15 + prbs.loc[n]*25
            u_0["ahu_Tsup"] = 288.15
            try:
                _, y_meas, u_meas = boptest.evolve(u=u_0)
            except TypeError:
                print(y_meas)
            #u_measured.append(u_meas)
            
            
        data = boptest.get_data(tf=N*boptest.h, downsample=False)
        # check
       # ax = data.Ti.plot()
       # data.oveTSetSup_u.plot(ax=ax, color="r", drawstyle="steps-post")
        data.to_csv(data_path)
    
    else:
        data = pd.read_csv(data_path, index_col=0)
    
    """
    # plot: here:
    data = data[4:]
    
    # Radiator:    
    
    # AHU
    ax = (data["ahu_reaTCoiSup_y"]-273.15).plot()
    (data["ahu_reaTHeaRec_y"]-273.15).plot(ax=ax)
    (data.Ti-273.15).plot(ax=ax, linestyle="dashed")
    data["ahu_reaTRetAir_y"].plot(ax=ax, drawstyle="steps-post")
    data["ahu_reaTSupAir_y"].plot(ax=ax, drawstyle="steps-post")
    ax.legend()
    plt.show()
    
    ax = (data.oveTSetSup_u-data.Ti).plot(color="k")
    ax1 = ax.twinx()
    data.Ph.plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax1)
    ax.legend(["deltaT"])
    ax1.legend(["Ph"])
    plt.show()
    """
    
    ax = data.Ti.plot(color="r")
    data.Tsup.plot(color="m", drawstyle="steps-post", ax=ax)
    data.TsetHea.plot(color="k", drawstyle="steps-post", ax=ax)
    # plot also solar
    ax1 = ax.twinx()
    ax1 = data.phi_s.plot(color="y")
    ax.legend()
    ax1.legend()
    plt.show()
    
    data["Ph"] = data["Ph"].shift(-1) 
    y_data = data[:-1]
    # when Tsup is below Ti, set Tsup == Ti:
    #y_data["Tsup"] = y_data["oveTSetSup_u"]
    ndx = y_data[(y_data.Tsup - y_data.Ti) <= 0].index
    y_data["Tsup"].loc[ndx] = y_data["Ti"].loc[ndx]
    #y_data = data[:4]
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["Ph"]
    #y_data["y2"] = y_data["Ph"]
    
    #y_data["Tsup"].loc[ndx] += 1.01

    """
    ax = (y_data.Tsup-y_data.Ti).plot(color="k")
    ax1 = ax.twinx()
    y_data.Ph.plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax1)
    ax.legend(["deltaT"])
    ax1.legend(["Ph"])
    plt.show()
    """

    
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    #param_guess = ca.DM([0.1,0.1,1E7,1E8,50,1.05,39.10,0.90])
    param_guess = ca.DM([0.01,0.01,1E8,1E9,100])
    lbp = param_guess*0.001
    ubp = param_guess*1000
    len_p = param_guess.shape[0]
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    #lbp[len_p-1] = 0.87
    #ubp[len_p-1] = 1
    #lbp[len_p-3] = 1
    #ubp[len_p-3] = 2
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    
    
    # test expression, with rootfinder:
    #UA_nom = 250
    #Ph = 5000
    #Ti = 20
    #Tsup = 40
    #dT_nom = 20
    #Cnom = 5000/20
    
    
    #(1 - ca.exp((-UA_nom*(Tsup - Ph/(2*Ch) - Ti)/dT_nom)**0.24)/Ch)*Ch*(Tsup - Ti)
    """
    kwargs = {
        "x_nom": 20,
        "x_nom_b": 288.15,
        "u_nom": 300,
        "r_nom": 300,
        "y_nom": 20,
        "y_nom_b": 288.15,
        #"slack": True
        "slack": True
    }
    kwargs = {
            "x_nom": 300,
            "u_nom": 300,
            "r_nom": 300,
            "y_nom": 300
             }
    """
    
    # TODO: move this!
    
    """
    Specify function here. 
    Modelica function is as follows:
    
    function regNonZeroPower
    "Power function, regularized near zero, but nonzero value for x=0"
    extends Modelica.Icons.Function;

        input Real x "Abscissa value";
        input Real n(
        min=0.000001,
        max=1.999999) "Exponent";
        input Real delta = 0.01 "Abscissa value where transition occurs";
        output Real y "Function value";
    protected
        Real a1;
        Real a3;
        Real a5;
        Real delta2;
        Real x2;
        Real y_d "=y(delta)";
        Real yP_d "=dy(delta)/dx";
        Real yPP_d "=d^2y(delta)/dx^2";
    algorithm
    if abs(x) > delta then
        y := abs(x)^n;
    else
        delta2 :=delta*delta;
        x2 :=x*x;
        y_d :=delta^n;
        yP_d :=n*delta^(n - 1);
        yPP_d :=n*(n - 1)*delta^(n - 2);
        a1 := -(yP_d/delta - yPP_d)/delta2/8;
        a3 := (yPP_d - 12 * a1 * delta2)/2;
        a5 := (y_d - delta2 * (a3 + delta2 * a1));
        y := a5 + x2 * (a3 + x2 * a1);
        assert(a5 > 0 and 0 < n and n < 2, "Delta is too small for this exponent or n is outside (0, 2).");
    end if;
    """
    
    # inputs
    x = ca.MX.sym("x")
    n = ca.MX.sym("n")
    delta = ca.MX.sym("delta")
    # protected:
    delta2 = delta*delta
    x2 = x*x
    y_d = delta**n
    yP_d = n*delta**(n-1)
    yPP_d = n*(n-1)*delta**(n-2)
    a1 = -(yP_d/delta - yPP_d)/delta2/8
    a3 = (yPP_d - 12 * a1 * delta2)/2
    a5 = (y_d - delta2 * (a3 + delta2 * a1))
    # output
    #y = ca.MX.sym("y")
    
    # expressions:
    y_if = ca.fabs(x)**n
    y_else = a5 + x2*(a3 + x2*a1)
    
    # output
    y = ca.if_else(ca.fabs(x) > delta, y_if, y_else)
    regNonZeroPower = ca.Function(
                                  "regNonZeroPower", 
                                  [x, n, delta],
                                  [y]
                                  #["x", "n", "delta"],
                                  #["y"]
                                  )
    
    """
    # test it with one input:
    test = regNonZeroPower(1, 1.24, 10)
    print(test)
    
    # test over x \in [0, ..., 10]
    xs = np.arange(0,1,step=0.01)
    #xs = np.append(xs, np.arange(1,10,step=1))
    n = 0.5
    delta = 0.01
    y = np.array([])
    for x in xs:
        y = np.append(y, regNonZeroPower(x, n, delta))

    plt.plot(xs, y)
    plt.show()
    """
    
    # TODO: enable calling this function in model defintion
    """
    First: construct the function outside initialization,
    pass it as a separate object, which must be part of 
    namespace when init'ing DAE object.
    """

    functions = {"regNonZeroPower": regNonZeroPower}
    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) \
                             as param_est:
                             #**kwargs) as param_est:
        
        
        #param_guess[-1] = dT_nom
        #param_guess[-1] = dT_nom
        #param_guess[5] = 250
        #x = ca.DM([293.15, 293.15])
        #u = ca.DM([303.15, 0, 0])
        #z = ca.DM([5000])
        #sol = param_est.integrator.G(x0=z, p=ca.vertcat(x, u, param_guess))
        
        
        Q = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        #v2 = param_est.nlp["x"][(v_inds["a"]+1):v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        #eta = param_est.dae.dae.var("eta")
        #v2 = v2/eta
        param_est.nlp["f"] = 0.5*ca.dot(v1, v1)  #+ 0*ca.dot(v2, v2)
        param_est.res = v1
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      covar=ca.veccat(Q, R)
                                      )    
        
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.set_ylim([290,310])
        ax.legend()
        plt.show()
        print(params)
        
    
    # compare inferred heat with measured:  
    UA_nom = params["UA_nom"]
    n = params["n"]
    ax = (UA_nom*((y_data.Tsup-y_data.Ti)**n)).plot(color="k", drawstyle="steps-post")
    #ax1 = ax.twinx()
    (y_data.Ph*params["eta"]).plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax)
    #ax.legend(["deltaT"])
    ax.legend(["Ph_inf", "Ph"], loc="upper left")
    #ax1.legend(["Ph"])
    plt.show()
    
















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
    