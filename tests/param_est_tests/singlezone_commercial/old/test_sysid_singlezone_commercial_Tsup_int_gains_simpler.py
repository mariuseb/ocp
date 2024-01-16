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
    #cfg_path = os.path.join("configs", "4R2C_inf_DAE.json")
    #cfg_path = os.path.join("configs", "2R2C_rad_pump_DAE.json")
    #cfg_path = os.path.join("configs", "2R2C_func_DAE.json")
    #cfg_path = os.path.join("configs", "2R2C_orig.json")
    cfg_path = os.path.join("configs", "4R2C_inf_Tsup_int_gains.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")

    GENERATE_DATA = False
    PLOT = True

    boptest = Boptest(
                      boptest_cfg,
                      name="singlezone_commercial"
                      )
    
    sampling_time = "15min"
    data_path = os.path.join(get_data_path(), "data_singlezone_commercial_radiator.csv")
    
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
        count = 0
        for n in range(N):
            u_0 = pd.Series(index=['dh_Tsup'], data=[283.15 + prbs.loc[n]*50])
            u_0["TsetHea"] = 283.15 + prbs.loc[n]*20
            #u_0["TsetHea"] = 318.15
            #u_0["dh_pump"] = prbs.loc[n]
            #u_0["dh_pump"] =  prbs.loc[n]*0.01*count
            rand = np.random.random(1)[0]
            #u_0["dh_pump"] =  prbs.loc[n]*rand
            u_0["dh_pump"] = prbs.loc[n]*rand
            #u_0["rad_val"] =  prbs.loc[n]*0.01*count
            u_0["rad_val"] =  prbs.loc[n]
            #u_0["ahu_pump_sup"] = 0.05
            #u_0["ahu_pump_ret"] = 0.05
            u_0["ahu_pump_sup"] = 0.01
            u_0["ahu_pump_ret"] = 0.01
            #u_0["ahu_pump_sup"] = prbs.loc[n]
            #u_0["ahu_pump_ret"] = prbs.loc[n]
            #u_0["oveValCoi"] = prbs.loc[n]
            #u_0["ahu_pump_sup"] = 0.01
            #u_0["ahu_pump_ret"] = 0.01
            #u_0["ahu_Tsup"] = 288.15 + prbs.loc[n]*25
            #u_0["ahu_Tsup"] = 288.15 + prbs.loc[n]*25
            #u_0["ahu_Tsup"] = 294.15
            
            """
            if prbs.loc[n] > 0:
                count += 1
            if count > 98:
                count = 0            
            """
            _, y_meas, u_meas = boptest.evolve(u=u_0)            
            
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
    
    
    
    
    # AHU plots:
    
    # when Tsup is below Ti, set Tsup == Ti:
    #y_data["Tsup"] = y_data["oveTSetSup_u"]
    #ndx = y_data[(y_data.Tsup - y_data.Ti) <= 0].index
    #y_data["Tsup"].loc[ndx] = y_data["Ti"].loc[ndx]
    #y_data = data[:4]
    data["Prad"] = data["Prad"].shift(-1) 
    data["Ptot"] = data["Ptot"].shift(-1) 
    data["Tret"] = data["Tret"].shift(-1) 
    data["Tsup"] = data["Tsup"].shift(-1) 
    data["rad_flo"] = data["rad_flo"].shift(-1) 
    #data["Pvent"] = data["Pvent"].shift(-1) 
    data["n_occ"] = data["n_occ"].shift(-1) 
    data["dh_pump"] = data["dh_pump"].shift(-1) 
    data["rad_val"] = data["rad_val"].shift(-1) 
    data["oveValCoi"] = data["oveValCoi"].shift(-1) 
    data["ahu_pump_sup"] = data["ahu_pump_sup"].shift(-1) 
    data["ahu_pump_ret"] = data["ahu_pump_ret"].shift(-1) 
    data["ahu_reaTCoiSup"] = data["ahu_reaTCoiSup"].shift(-1) 
    data["ahu_reaTCoiRet"] = data["ahu_reaTCoiRet"].shift(-1) 
    data["ahu_reaTSupAir"] = data["ahu_reaTSupAir"].shift(-1) 
    # unsure whether to pull this back or not:
    #data["ahu_reaTRetAir"] = data["ahu_reaTRetAir"].shift(-1) 
    data["ahu_reaTHeaRec"] = data["ahu_reaTHeaRec"].shift(-1) 
    data["ahu_reaFloSupAir"] = data["ahu_reaFloSupAir"].shift(-1)
    #data["ahu_reaFloExtAir"] = data["ahu_reaFloExtAir"].shift(-1)
    y_data = data[:-2]
    
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["Prad"]
    #y_data["y2"] = y_data["Ph"]
    
    if PLOT:
        """
        ax = data.dh_pump.plot(drawstyle="steps-post")
        ax1 = ax.twinx()
        (-data.Prad).plot(ax=ax1, color="r", drawstyle="steps-post")
        plt.show()
        
        # sort descending valve, power:
        valve = data.dh_pump.sort_values(ascending=False)
        power = -data.loc[valve.index].Prad.shift(-1)
        valve.index = range(len(valve.index))
        power.index = range(len(valve.index))
        
        ax = valve.plot(drawstyle="steps-post", color="r")
        ax1 = ax.twinx()
        power.plot(ax=ax1, drawstyle="steps-post")
        plt.show()
        """
        
        valve = data.dh_pump.sort_values(ascending=False)
        flow = data.loc[valve.index].Prad
        valve.index = range(len(valve.index))
        flow.index = range(len(valve.index))
        
        ax = valve.plot(drawstyle="steps-post", color="r")
        ax1 = ax.twinx()
        flow.plot(ax=ax1, drawstyle="steps-post")
        plt.show()
        
        
        ax = data.Ti.plot(color="r")
        #data.dh_Tsup.plot(color="m", drawstyle="steps-post", ax=ax)
        data.TsetHea.plot(color="k", drawstyle="steps-post", ax=ax)
        # plot also solar
        ax1 = ax.twinx()
        ax1 = data.phi_s.plot(color="y")
        ax.legend()
        ax1.legend()
        plt.show()
        
        # check of Ph, dh_pump
        ax = y_data.Prad.plot(drawstyle="steps-post")
        (y_data*y_data.Prad.max()).dh_pump.plot(ax=ax, drawstyle="steps-post", linestyle="dashed")
        ax1 = ax.twinx()
        y_data.Ti.plot(color="r")
        plt.show()
        
        # Prad plot
        Prad_model = (data.dh_pump**1.06)*((338.15 - data.Ti)**1)*8500
        ax = Prad_model.plot(color="k", drawstyle="steps-post", linestyle="dashed")
        #ax1 = ax.twinx()
        (y_data.Prad*0.87).plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax)
        ax1 = ax.twinx()
        y_data.dh_pump.plot(ax=ax1, color="b", drawstyle="steps-post", linestyle="dashed")
        ax.legend()
        plt.show()
        
    N = len(y_data)
    dt = y_data.index[1] - y_data.index[0]
    
    #param_guess = ca.DM([0.1,0.1,1E7,1E8,50,1.05,39.10,0.90])
    #param_guess = ca.DM([0.01,0.01,1E8,1E9,100,1.05,3900.10,0.90])
    param_guess = ca.DM([
                        4.222012e-05,
                        1.757842e-04,
                        1E-5,
                        338.15,
                        0.5,
                        7.126425e+07,
                        2.732098e+09,
                        2.800931e+02,
                        1,
                        6500,
                        8.705905e-01
                        ])
    
    lbp = param_guess*0.01
    ubp = param_guess*100
    len_p = param_guess.shape[0]
    #lbp[len_p-2] = 0.99*param_guess[len_p-2]
    #ubp[len_p-2] = 1.01*param_guess[len_p-2]
    lbp[3] = 320
    ubp[3] = 350
    lbp[4] = 0
    ubp[4] = 1
    #lbp[len_p-1] = 8.705905e-01
    #ubp[len_p-1] = 8.705905e-01
    lbp[len_p-1] = 0.7
    ubp[len_p-1] = 1.0
    #lbp[len_p-3] = 1.24
    #ubp[len_p-3] = 1.24
    lbp[len_p-3] = 0.2
    ubp[len_p-3] = 2
    
    """
    Function regNonZeroPower
    """
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
        function equalPercentage
            "Valve opening characteristics for equal percentage valve"
            extends Modelica.Icons.Function;

            input Real y "Valve opening signal, y=1 is fully open";
            input Real R "Rangeability, R=50...100 typically";
            input Real l(min=0, max=1) "Valve leakage, l=Kv(y=0)/Kv(y=1)";
            input Real delta "Range of significant deviation from equal percentage law";
            output Real phi "Ratio actual to nominal mass flow rate, phi=Cv(y)/Cv(y=1)";
        protected 
            Real a "Polynomial coefficient";
            Real b "Polynomial coefficient";
            Real c "Polynomial coefficient";
            Real d "Polynomial coefficient";
            Real logR "=log(R)";
            Real z "Auxiliary variable";
            Real q "Auxiliary variable";
            Real p "Auxiliary variable";
        algorithm 
            if y < delta/2 then
                phi := l + y * (R^(delta-1) - l) / delta;
            else
                if (y > (3/2 * delta)) then
                    phi := R^(y-1);
                else
                    logR := Modelica.Math.log(R);
                    z := (3*delta/2);
                    q := delta*R^z*logR;
                    p := R^z;
                    a := (q - 2*p + 2*R^delta)/(delta^3*R);
                    b := (-5*q + 12*p - 13*R^delta + l*R)/(2*delta^2*R);
                    c := (7*q - 18*p + 24*R^delta - 6*l*R)/(4*delta*R);
                    d := (-3*q + 8*p - 9*R^delta + 9*l*R)/(8*R);
                    phi  := d + y * ( c + y * ( b + y * a));
                end if;
            end if;
    """
    """
    Function equalPercentage
    """
    y = ca.MX.sym("y")
    R = ca.MX.sym("R")
    l = ca.MX.sym("l")
    delta = ca.MX.sym("delta")
    # protected:
    logR = ca.log(R)
    z = (3*delta/2)
    q = delta*(R**z)*logR
    p = R**z
    a = (q - 2*p + 2*(R**delta))/((delta**3)*R)
    b = (-5*q + 12*p - 13*(R**delta) + l*R)/(2*(delta**2)*R)
    c = (7*q - 18*p + 24*(R**delta) - 6*l*R)/(4*delta*R)
    d = (-3*q + 8*p - 9*(R**delta) + 9*l*R)/(8*R)
    # expressions:
    phi_if = (l + y*(R**(delta-1) - l))/delta
    phi_else_else = d + y*(c+y*(b+y*a))
    phi_else_if = R**(y-1)
    
    # output
    else_expr = ca.if_else(y > (3/2)*delta, phi_else_if, phi_else_else)
    expr =  ca.if_else(y < delta/2, phi_if, else_expr)
    equalPercentage = ca.Function(
                                  "equalPercentage", 
                                  [y,R,l,delta],
                                  [expr]
                                  #["x", "n", "delta"],
                                  #["y"]
                                  )
    
    
    """
    R = 100
    l = 0.05
    delta = 0.50
    
    test = equalPercentage(0.5, R, 1E-4, delta)
    print(test)
    
    # test over x \in [0, ..., 10]
    xs = np.arange(0,1,step=0.01)
    #xs = np.append(xs, np.arange(1,10,step=1))
    y = np.array([])
    for x in xs:
        y = np.append(y, equalPercentage(1-x, R, l, delta))
        #y = np.append(y, equalPercentage(x, R, l, delta))
    y = 1 - y
    plt.plot(xs, y)  
    plt.show()
    """
    
    # TODO: enable calling this function in model defintion
    """
    First: construct the function outside initialization,
    pass it as a separate object, which must be part of 
    namespace when init'ing DAE object.
    """

    functions = {
                 "regNonZeroPower": regNonZeroPower,
                 "equalPercentge": equalPercentage
                 }
    kwargs = {
        "x_nom": 300,
        "x_nom_b": 0,
        "u_nom": [300,3E6],
        "r_nom": [300,300],
        "p_nom": [1E-5,1E-4,1E8,1E9,1E2,1,1E3,1,300],
        "y_nom": [300,3E6],
    }
    kwargs = {
        "x_nom": 300,
        "u_nom": [300,3E6],
        "r_nom": 300,
        "p_nom": [1E-5,1E-4,1E8,1E9,1E2,1,1E3,1,300],
        "y_nom": [300,3E6],
    }
    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12,3E6],
        "u_nom_b": [289.15,0],
        "r_nom": [12,300],
        "r_nom_b": [289.15,0],
        "p_nom": [1E-5,1E-4,1E8,1E9,1E2,1,1E3,1,12],
        "p_nom_b": [0,0,0,0,0,0,0,0,289.15],
        "y_nom": [12,3E6],
        "y_nom_b": [289.15,0]
    }
    
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "r_nom": 1,
        #"p_nom": [1E-5,1E-4,1E-5,300,1,1E8,1E9,1E2,1,1E3,1,1],
        "y_nom": 1,
        }
    

    x_guess = np.array(
                        [
                         y_data.Ti.values.flatten(),
                         y_data.Ti.values.flatten()#,
                         #y_data.Tsup.values.flatten()
                         ]
                      )
                    #, y_data.ahu_reaTSupAir.values.flatten()])
    x_guess = x_guess.T.flatten()
    
    with ParameterEstimation(config=cfg_path,
                             functions=functions,
                             N=N,
                             dt=dt,
                             param_guess=param_guess,
                             **kwargs) as param_est:
                             #as param_est:
        
        
        #param_guess[-1] = dT_nom
        #param_guess[-1] = dT_nom
        #param_guess[5] = 250
        #x = ca.DM([293.15, 293.15])
        #u = ca.DM([303.15, 0, 0])
        #z = ca.DM([5000])
        #sol = param_est.integrator.G(x0=z, p=ca.vertcat(x, u, param_guess))
        Q = ca.DM.eye(2)
        #R = ca.DM.eye(2)
        R = ca.DM.eye(2)
        R[1,1] = 1E-9
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        v_inds = param_est.nlp_parser["v"]["range"]
        v1 = param_est.nlp["x"][v_inds["a"]:v_inds["b"]:param_est.dae.n_y]
        v2 = param_est.nlp["x"][(v_inds["a"]+1):v_inds["b"]:param_est.dae.n_y]
        # what to do with this? 
        eta = param_est.dae.dae.var("eta")
        v2 = v2/eta
        param_est.nlp["f"] = R[1,1]*ca.dot(v2, v2) \
                             + \
                             R[0,0]*0.5*ca.dot(v1, v1)
        param_est.res = ca.vertcat(ca.sqrt(R[0,0])*v1, ca.sqrt(R[1,1])*v2)
        sol, params = param_est.solve(
                                      y_data,
                                      param_guess,
                                      lbp=lbp,
                                      ubp=ubp,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R)
                                      )    
        
        ax = sol["Ti"].plot(color="r")
        sol["y1"].plot(color="k", ax=ax)
        ax.set_ylim([290,315])
        ax.legend()
        plt.show()
        print(params)
        
        
    
    # compare inferred heat with measured:  
    Prad_model = sol["v2"] + sol["y2"]*params["eta"]
    ax = Prad_model.plot(color="k", drawstyle="steps-post", linestyle="dashed")
    #ax1 = ax.twinx()
    (y_data.Prad*params["eta"]).plot(color="r", drawstyle="steps-post", linestyle="dashed", ax=ax)
    #ax.legend(["deltaT"])
    ax.legend(["Prad_inf", "Prad"], loc="upper left")
    #ax1.legend(["Ph"])
    plt.show()
    print(data)
    

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
    