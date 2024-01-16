#from ast import Param
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
#import sysid.dae as dae
#import sysid.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from ocp.boptest_api import Boptest
from pprint import pprint
from ocp.filters import EKF, KalmanBucy
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from copy import deepcopy
from ocp.functions import functions

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("mpc_configs", "4R2C_MPC_vent_no_water_CO2_rad.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    ekf_cfg = os.path.join("ekf_configs", "4R2C_EKF_vent_no_water_CO2_rad.json")

    # pass in config?
    """
    ventilation system + envelope:
	Rie                   7.700676e-05
	Rea                   9.575273e-04
	Ria                   4.163556e-04
	rho_int               2.807976e-01
	Ci                    3.812187e+07
	Ce                    2.903745e+09
	Ai                    6.198831e+01
	m_flow_air_nom_sup    3.340057e+01
	m_flow_air_nom_ret    2.794511e+01
	cp_air                1.000000e+03
	eta_hex1              9.906089e-01
	eta_hex2              7.593239e-01
	n                     1.817090e+00
	n2                    1.778674e+00
	
    radiator system + envelope:
        Rie        3.883925e-05
        Rea        3.518385e-04
        Ria        7.275522e-04
        Tsup       3.400522e+02
        rho_int    3.307209e-01
        Ci         7.300194e+07
        Ce         2.835459e+09
        Ai         2.071233e+02
        n          1.000000e+00
        UA_nom     7.970504e+03
        eta        8.701288e-01
        
    only CO2:
        c            0.000029
        CO2_out    417.696296
        n_inf        1.233673
        c_occ        0.000621
        
    combined rad/vent:
    Rie                   4.206026e-05
    Rea                   6.192792e-04
    Ria                   4.797176e-04
    rho_int              -1.658390e-09
    Ci                    7.399603e+07
    Ce                    2.823996e+09
    Ai                    2.209604e+02
    m_flow_air_nom_sup    3.996869e+01
    m_flow_air_nom_ret    3.417110e+01
    dh_Tsup               3.400000e+02
    cp_air                1.000000e+03
    UA_nom                7.722262e+03
    eta_hex1              9.813310e-01
    eta_hex2              9.500827e-01
    eta_hex3              8.500000e-01
    n                     1.767463e+00
    n2                    1.793476e+00
    n3                    1.000000e+00
        
    parameters of combined model:
        "Rie",
        "Rea",
        "Ria",
        "rho_int",
        "Ci",
        "Ce",
        "Ai",
        "m_flow_air_nom_sup",
        "m_flow_air_nom_ret",
        "dh_Tsup",
        "cp_air",
        "UA_nom",
        "eta_hex1",
        "eta_hex2",
        "eta_hex3",
        "n",
        "n2",
        "n3",
        "c",
        "CO2_out",
        "n_inf",
        "c_occ"
    
    params = ca.DM([
        3.883925e-05,
        3.518385e-04,
        7.275522e-04,
        3.307209e-01,
        7.300194e+07,
        2.835459e+09,
        2.071233e+02,
        3.340057e+01,
        2.794511e+01,
        3.400522e+02,
        1.000000e+03,
        7.970504e+03,
        9.906089e-01,
        7.593239e-01,
        8.701288e-01,
        1.817090e+00,
        1.778674e+00,
        1.000000e+00,
        0.000029,
        417.696296,
        1.233673,
        0.000621
                ])
    """
    
    params = ca.DM([
        4.206026e-05,
        6.192792e-04,
        4.797176e-04,
        1E-5,
        7.399603e+07,
        2.823996e+09,
        2.209604e+02,
        3.996869e+01,
        3.417110e+01,
        3.400000e+02,
        1.000000e+03,
        7.722262e+03,
        9.813310e-01,
        9.500827e-01,
        8.500000e-01,
        1.767463e+00,
        1.793476e+00,
        1.000000e+00,
        0.000029,
        417.696296,
        1.233673,
        0.000621
                ])
    
    kwargs = {
        "x_nom": 12,
        "x_nom_b ": 289.15,
        "z_nom": [12,1E5,12,40],
        "z_nom_b": [289.15,0,289.15,0],
        "r_nom": [12,300,1E5,1E5,1E5],
        "r_nom_b": [289.15,0,0,0,0],
        "u_nom": [1,1,12],
        "u_nom_b ": [0,0,289.15],
        #"p_nom": [1E-5,1E-4,1E-5,1E8,1E9,1E2,1,1E3,1,1],
        #"p_nom_b": [0,0,0,0,0,0,0,0,289.15],
        #"slack": True
        "slack": False
    }
    
    kwargs = {
        "x_nom": 1,
        "u_nom": 1,
        "z_nom": 1,
        "r_nom": 1,
        "y_nom": 1,
        #"slack": Trues
        "slack": False
    }
    kwargs = {
        "x_nom": 300,
        "z_nom": [300,1E6,300,1,1,1,1,1,1E6],
        "r_nom": [300,300,1E6,1E6,1E6,1],
        "u_nom": [1,1,300,1],
        #"p_nom": [1E-5,1E-4,1E-5,1E8,1E9,1E2,1,1E3,1,1],
        #"p_nom_b": [0,0,0,0,0,0,0,0,289.15],
        #"slack": True
        "slack": True
    }
    
    mpc = MPC(config=mpc_cfg,
              functions=deepcopy(functions),
              param_guess=params, 
              **deepcopy(kwargs))  # to remove, replace with N
    
    
    ekf = KalmanBucy(ekf_cfg,
                     functions=deepcopy(functions)
                     )
    # set params:
    ekf.set_params(params)
    
    boptest = Boptest(
                      boptest_cfg,
                      name="singlezone_commercial"
                      )
    # first forecast:
    data = boptest.forecast()
    
    # init conditions, state bounds:
    N = mpc.N
    #dt = mpc.dt
    lb_night = {"Ti": 289.15}
    ub_night = {"Ti": 301.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    
    bounds = Bounds(mpc.dt,
                    mpc.dae.x,
                    ekf.y,
                    lb_night=lb_night,
                    ub_night=ub_night,
                    lb_day=lb_day,
                    ub_day=ub_day)
    
    # TODO: shouldn't have to fine-tune these:
    #x0 = np.array([293.05, 290.15])
    x0 = np.array([293.15, 293.15, 420])
    
    # sim horizon: 2 days
    days = 1
    K = days*24*bounds.t_h
    time = pd.DataFrame(columns=["time"])
    u_hist = pd.DataFrame(columns=mpc.dae.u)
    y_hist = pd.DataFrame(columns=ekf.y)

    for k in range(K):
        
        lbx, ubx, ref = bounds.get_bounds(k, mpc.N)
        # modify ub of CO2:
        ubx[2:-1:3] = 800
        ubx[-1] = 800
        
        sol, u, x0, raw_sol  = mpc.solve(
                               data[0:mpc.N],
                               x0=x0,
                               lbx=lbx,
                               ubx=ubx,
                               params=params,
                               codegen=True,
                               return_raw_sol=True
                               )
        
        #if raw_sol["f"] > 1E6:
        #    print(sol)
        # do not want heat from radiator:
        #u["dh_pump"] = 0
        
        if mpc.solver.stats()["return_status"] != "Solve_Succeeded":
            print(sol)
            res = boptest.get_data(tf=K*boptest.h)
        
        """
        if k == 14:
            print(sol) 
        if k == 25:
            print(sol)
        
        
        time.loc[k] = mpc.solver.stats()["t_wall_total"]
        """
        
        # turn off ventilation:
        """
        u = pd.Series(
                         data=[0.03],
                         index=["ahu_pump_sup"]
                         )
        #u.loc["oveCO2ZonSet"] = 1000
        u = pd.Series(
                         data=[1000.0],
                         index=["oveCO2ZonSet"]
                         )
        u.loc["ahu_pump_sup"] = 0.03
        u.loc["ahu_pump_ret"] = 0.03
        #u.loc["ahu_Tsup"] = 288.15
        #u.loc["oveValCoi"] = 0.01
        #u["dh_pump"] = 1
        """
        #u.loc["ahu_pump_sup"] *= 3
        #u.loc["ahu_pump_ret"] *= 3
        
        #data, y_meas, u_meas = boptest.evolve(u=u)
        data, y_meas, u_meas = boptest.evolve(
                                              u=u, 
                                              y_as_array=False,
                                              u_as_array=False
                                              )
        u_hist.loc[k*mpc.dt] = u
        y_hist.loc[mpc.dt*k] = [y_meas[name] for name in ekf.y]
        
        # input z as from model prediction:
        z_model = sol[ekf.dae.z].iloc[0].values
        u_model = sol[ekf.dae.u].iloc[0].values
        r_pred = data[ekf.dae.r_names].iloc[0].values
        
        # TODO: check if constraint active 
        y_z_meas = [y_meas[name] for name in ekf.y]
        x0 = ekf.estimate(
                          x0, 
                          z=z_model,
                          y=y_z_meas, 
                          u=u_model, 
                          r=r_pred
                          )
        
    plt.rcParams.update({'font.size': 12})
    fig, axes, dt_index = boptest.plot_temperatures(K, days, bounds, heat_key="Pvent")
    fig.tight_layout()
    plt.show()   
    res = boptest.get_data(tf=K*boptest.h)
    ax = res.n_occ.plot()
    res.CO2_in.plot(ax=ax)
    ax.legend()
    plt.show()
    print(res)
    
    """
    Look at deviation: ahu_pump_<x> vs. real
    """
    ax = (res.ahu_pump_sup**1.817*33.4).plot(drawstyle="steps-post")
    res.ahu_reaFloSupAir.plot(drawstyle="steps-post", ax=ax)
    ax.legend()
    plt.show()
    ax = (res.ahu_pump_ret**1.77*27.95).plot(drawstyle="steps-post")
    res.ahu_reaFloExtAir.plot(drawstyle="steps-post", ax=ax)
    ax.legend()
    plt.show()
    
    # look at Prad vs. Pvent
    ax = res.Pvent.plot(drawstyle="steps-post")
    res.Prad.plot(drawstyle="steps-post", ax=ax)
    plt.show()
    
    # look at Prad vs. Prad computed

    """
    plt.rcParams.update({'font.size': 11})
    
    fig = plt.figure(figsize=(10,6))
    ax = fig.add_subplot(111)
    
    # colors
    colors = iter(plt.cm.rainbow(np.linspace(0, 1, 5)))
    #for i in range(n):
    #c = next(colors)
    #plt.plot(x, y, c=c)
    
    dt_index = pd.Timestamp("2020-01-01 00:00") + res.index
    
    #l1 = res.Ti.plot(ax=ax, color="k")
    #l1 = ax.plot(res.index, res.Ti, color="k", label="$T_i$")
    l1 = ax.plot(dt_index, (res.Ti-273.15), color=next(colors), label="$T_i$")
    ax1 = ax.twinx()
    #l2 = res.phi_h.plot(ax=ax1, color="k", linestyle="--")
    #l2 = ax1.plot(res.index, res.phi_h, color="k", linestyle="dashed", label="$\phi_h$")
    l2 = ax1.plot(dt_index, res.phi_h, color=next(colors), label="$\phi_h$")
    
    #ax.legend([l1, l2], , loc=0)
    ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d %H:%M'))
    fig.autofmt_xdate()
    #ax.legend(["Ti"])
    #ax1.legend(["phi_h"])
    # plot bounds:
    #bounds_plt = pd.concat([bounds]*days)
    bounds_plt = bounds.get_full(days)
    bounds_plt.index = res.index
    #bounds_plt[("lb", "Ti")].plot(ax=ax, drawstyle="steps")
    #bounds_plt[("ub", "Ti")].plot(ax=ax, drawstyle="steps")
    l3 = ax.plot(dt_index, (bounds_plt[("lb", "Ti")]-273.15), color="k", drawstyle="steps", label="$T_{i}^{lb}$")
    l4 = ax.plot(dt_index, (bounds_plt[("ub", "Ti")]-273.15), color="k", drawstyle="steps", label="$T_{i}^{ub}$")
    lns = l1+l2+l3+l4
    labs = [l.get_label() for l in lns]
    ax.legend(lns, labs, loc='upper center', ncol=4)
    _min, _max = ax.get_ylim()
    ax.set_ylim([_min, _max+1])
    _min, _max = ax1.get_ylim()
    ax1.set_ylim([_min, _max+1000])
    
    ax.set_ylabel(r"Temperature [$^\circ$C]")
    ax1.set_ylabel(r"Power [W]")
    
    fig.tight_layout()
    plt.show()    
    """