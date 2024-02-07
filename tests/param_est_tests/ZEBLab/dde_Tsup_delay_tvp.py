import casadi as ca
import numpy as np
from ocp.dae import DAE
from ocp.integrators import RK4, IRK
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from ocp.param_est import ParameterEstimation
from utils import prepare_data
import os

data = pd.read_csv("ZEBLab_2024_1m.csv")
data.index = pd.to_datetime(data._time)
data.index = data.index.tz_localize(None)

"""
Plot valve command vs. actual
"""
val_cmd = data["val_cmd_219"]
val_pos = data["val_pos_219"]/100
flow = data["V_flow_219"]

fig, axes = plt.subplots(3,1, sharex=True)
ax = axes[0]

val_cmd.plot(ax=ax, color="k", drawstyle="steps-post")
val_pos.plot(ax=ax, color="r", linestyle="dashed", drawstyle="steps-post")
ax.legend(loc="upper right")

ax1 = ax.twinx()
flow.plot(ax=ax1, color="b", drawstyle="steps-post")
ax1.legend(loc="upper left")

Tdev = data["T_set"] - data["T_219_TR3"]
Tdev[Tdev < 0] = 0
ax = axes[1]
Tdev.plot(ax=ax, color="r", drawstyle="steps-post")
ax.legend(["Tset - Ti"])

ax = axes[2]
data.P_rad_219.plot(ax=ax, drawstyle="steps-post")

plt.show()

data = prepare_data(data)
data = data.resample(rule="5min").mean()
y_data = data.bfill() 
#y_data["u_val_set"] = y_data.val_cmd_219
#y_data["m_flow"] = (y_data.V_flow_219/y_data.V_flow_219.max())
#y_data["m_flow"] = y_data.V_flow_219
#y_data["y1"] = y_data["m_flow"]
# take only time point between 0400 and 1100
#start = pd.Timestamp("2022-12-13 00:00")
#stop = pd.Timestamp("2022-12-16 00:00")
start = pd.Timestamp("2023-12-13 00:00")
#stop = pd.Timestamp("2023-12-06 00:00")
stop = pd.Timestamp("2023-12-20 00:00")
y_data = y_data.loc[start:stop]

# TODO: 'algorithm' to find only non-zero power entries, rounding to limits
Prad = data.Prad.resample(rule="1H").mean()
gt_zero = Prad[Prad > 0]
r = gt_zero.copy()
r.index += pd.Timedelta(hours=1)
l = gt_zero.copy()
l.index -= pd.Timedelta(hours=1)
gt_zero_index = list(set(list(gt_zero.index) + list(r.index) + list(l.index)))
#gt_zero = gt_zero.resample(rule="1min").asfreq()


#index_selection = [ndx for ndx in y_data.index if ndx.hour in range(7,12)]
#index_selection = [ndx for ndx in y_data.index if 
#                   ndx.floor("1H") in gt_zero_index]
#index_selection = list(gt_zero.index)
#y_data = y_data.loc[index_selection]
#data = data.iloc[0:1000]

N = len(y_data)
dt = (y_data.index[1] - y_data.index[0]).seconds
# set range index for identification:
y_data["dt_index"] = y_data.index
y_data.index = range(0,N*dt,dt)

# only tau, delay
param_guess = np.array([500,
                        -15 + 273.15,
                        #45 + 273.15,
                        47 + 273.15,
                        0.6,
                        292,
                        500,
                        250,
                        1E-3,
                        100
                        ])

lbp = 1E-2*param_guess
ubp = 1E2*param_guess
len_p = param_guess.shape[0]
lbp[len_p-1] = 50
ubp[len_p-1] = 100000
lbp[1] = -20 + 273.15
ubp[1] = -10 + 273.15
#lbp[2] = 35 + 273.15
lbp[2] = 35 + 273.15
ubp[2] = 50 + 273.15
lbp[3] = 0.2
ubp[3] = 1.5
lbp[4] = 290
ubp[4] = 294
# constrain in particular Th to physically meaningful values:
x_guess = np.array([
                y_data.Tsup,
                y_data.Tsup,
                y_data.Tsup,
                y_data.m_flow.values/y_data.m_flow.max(),
                y_data.m_flow.values/y_data.m_flow.max()
                ])
x_guess = y_data[["Tsup", "Tsup", "Tsup","u_val_set", "u_val_set"]].values
lbx = x_guess.copy()
ubx = x_guess.copy()
"""
lbx[1:2] = -1*x_guess[1:2]
ubx[1:2] = 2.0*x_guess[1:2]
lbx[2:3] = -1*x_guess[2:3]
ubx[2:3] = 2.0*x_guess[2:3]
"""
lbx[3:4] = -1*x_guess[3:4]
ubx[3:4] = 2.0*x_guess[3:4]
lbx[4:5] = -1*x_guess[3:4]
ubx[4:5] = 2.0*x_guess[3:4]

lbx[3:4] -= 1
ubx[3:4] += 2
lbx[4:5] -= 1
ubx[4:5] += 2

lbx[0:1] = 0.8*x_guess[0:1]
ubx[0:1] = 1.2*x_guess[0:1]
lbx[1:2] = 0.8*x_guess[0:1]
ubx[1:2] = 1.2*x_guess[0:1]
lbx[2:3] = 0.8*x_guess[0:1]
ubx[2:3] = 1.2*x_guess[0:1]


#cfg_path = "configs/Tsup_Th_Tret_DDE_tvp_delay_simple.json"
#cfg_path = "configs/Tsup_Th_Tret_DDE_tvp_delay_simpler.json"
#cfg_path = "configs/Tsup_m_flow_DDE_delay_Tsup.json"
cfg_path = "configs/Tsup_DDE.json"

with ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=param_guess) as param_est:

    #Q = ca.DM.eye(3)
    Q = ca.DM.eye(5)
    R = ca.DM.eye(2)

    """
    Prior to solving, 
    add constraint:
    Ce - Ci >= 0
    
    Ce_b = param_est.get("Ce_b")
    Ci_b = param_est.get("Ci_b")
    constr = Ce_b - Ci_b
    
    param_est.nlp["g"] = ca.vertcat(param_est.nlp["g"], constr)
    param_est.lbg
    
    TODO: figure out how to do it nicely
    """
    
    sol, params = param_est.solve(
                                    y_data,
                                    param_guess,
                                    lbp=lbp,
                                    ubp=ubp,
                                    #lbx=lbx,
                                    #ubx=ubx,
                                    x_guess=x_guess,
                                    #Th_anti_bias=True,
                                    covar=ca.veccat(Q, R),
                                    codegen=True
                                    )

    #k = params["k"]
    sol.index = y_data.dt_index
    #ax = (k*sol["x2"]) .plot(color="r")
    ax = sol["y3"].plot(color="k", linewidth=0.75)
    sol[["Tsup", "Tset_sup"]].plot(linestyle="dashed", ax=ax, linewidth=0.75)
    ax1 = ax.twinx()
    #sol["m_flow_bool"].plot(color="g", ax=ax1, linestyle="dashed")
    sol["u_val_set"].plot(color="g", ax=ax1, linestyle="dashed")
    ax.legend(["measured", "model"])
    ax1.legend()
    """
    ylim = ax.get_ylim()
    ylim_1 = ax1.get_ylim()
    frac_ylim = ylim[0]/ylim[1]
    ax1.set_ylim([frac_ylim*ylim_1[1], ylim_1[1]])
    """
    
    plt.show()
    
    """
    ax = sol["Tset_ret"].plot(color="k", drawstyle="steps-post")
    sol["Tret"].plot(color="r", linestyle="dashed", ax=ax)
    plt.show()
    """
    resid = sol.v3[sol.m_flow_bool > 0]
    resid.index = range(len(resid))
    resid.hist(bins=50)
    plt.show()
    
    """
    Plot (sorted) heating curve.
    """
    
    Tsup = sol.Tsup[sol.valve_open > 0].sort_values(ascending=False)
    Tsup_act = sol["y3"][Tsup.index]
    Tsup.index = range(len(Tsup.index))
    Tsup_act.index = range(len(Tsup_act.index))
    Tsup_act = pd.DataFrame(Tsup_act)
    Tsup_act["time"] = Tsup_act.index
    ax = Tsup.plot(color="k", linewidth=0.5)
    Tsup_act.plot(kind="scatter",x="time", y="y3", ax=ax, color="r")
    ax.legend()
    plt.show()
    
    """
    Trajectories, measurements.
    """
    
    fig, axes = plt.subplots(2,1, sharex=True)
    sol = sol[10:]
    ax = axes[0]
    sol[["Tsup", "Tset_sup"]].plot(ax=ax, linewidth=0.75)
    sol[["y3"]].plot(ax=ax, color="k", linewidth=0.75)
    ax1 = ax.twinx()
    sol["m_flow_bool"].plot(ax=ax1, color="y")
    ax = axes[1]
    (sol["Ta"]-273.15).plot(ax=ax, color="g")
    ax1 = ax.twinx()
    u_val = data["val_pos_219"].loc[sol.index[0]:sol.index[-1]]
    u_val.plot(ax=ax1, color="b")
    plt.show()
    
    print(params)




