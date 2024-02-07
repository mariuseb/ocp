import casadi as ca
import numpy as np
from ocp.dae import DAE
from ocp.integrators import RK4, IRK
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from ocp.param_est import ParameterEstimation
from utils import prepare_data

"""
MATLAB code:

function [ udot] = mydde(t, u) 
    d=1;
    N=20;
    udot=zeros(N,1);
    for k=2:N
        udot(k)=-N/d*(u(k)-u(k-1));
    end 
    udot(1)= - u(N); 
    end

[tout,uout]=ode15s(@mypde, [0 10], u0) 
figure(1);
plot(tout,yout);
figure(2);
surf(tout,linspace(0,1,20),uout)    

"""

"""

Model a simple time delay:

    dot(x)(t) = − x(t − d)
    
    with d the delay, as:
    
    dot(u)_k = − (N / d) * (u_k − u_k−1), ∀k ∈ [1, . . . , N-1]:
    
    with:
    
    x(t − d) ≈ u_N 
    
Reformulate the time delay model to:

    dot(u)(t) = u(t − d)
    x(t) = u(t)
    

We generate the symbolic DAE first, then simulate.

"""

data = pd.read_csv("ZEBLab_dec_2022_1m.csv")
data.index = pd.to_datetime(data._time)
data.index = data.index.tz_localize(None)
data = prepare_data(data)
#data = data.resample(rule="5min").mean()
y_data = data.bfill() 
y_data["u_val_set"] = y_data.val_pos_219
#y_data["m_flow"] = (y_data.V_flow_219/y_data.V_flow_219.max())
#y_data["m_flow"] = y_data.V_flow_219
#y_data["y1"] = y_data["m_flow"]
# take only time point between 0400 and 1100
start = pd.Timestamp("2022-12-13 00:00")
stop = pd.Timestamp("2022-12-15 00:00")
y_data = y_data.loc[start:stop]

index_selection = [ndx for ndx in y_data.index if ndx.hour in range(4,11)]
y_data = y_data.loc[index_selection]
#data = data.iloc[0:1000]

N = len(y_data)
dt = (y_data.index[1] - y_data.index[0]).seconds
# set range index for identification:
y_data["dt_index"] = y_data.index
y_data.index = range(0,N*dt,dt)

# only tau, delay
param_guess = np.array([1500,
                        -15 + 273.15,
                        45 + 273.15,
                        0.8,
                        293,
                        1,
                        1,
                        60,
                        500,
                        0.03,
                        300
                        ])

lbp = 0.001*param_guess
ubp = 1000*param_guess
len_p = param_guess.shape[0]
lbp[0] = 100
ubp[0] = 3000
lbp[1] = -20 + 273.15
ubp[1] = -10 + 273.15
lbp[2] = 35 + 273.15
ubp[2] = 50 + 273.15
lbp[3] = 0.1
ubp[3] = 1.5
lbp[4] = 285
ubp[4] = 295
lbp[5] = 0
ubp[5] = 5
lbp[6] = 0
ubp[6] = 5
#lbp[len_p-3] = 200
#ubp[len_p-3] = 1000
lbp[len_p-2] = 3E-3
ubp[len_p-2] = 0.1
# Tsup delay, turn-on:
lbp[len_p-1] = 100
ubp[len_p-1] = 500
# Tsup delay, turn-off:
lbp[len_p-3] = 500
ubp[len_p-3] = 100000
lbp[len_p-4] = 100
ubp[len_p-4] = 500
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
lbx[1:2] = -1
ubx[1:2] = 2.0
lbx[2:3] = -1
ubx[2:3] = 2.0

lbx[0:1] = 0.8*x_guess[0:1]
ubx[0:1] = 1.2*x_guess[0:1]

# limits on Tret:
#lbx[0:1] = 290
#lbx[1:2] = -1
#lbx[2:3] = 290
#ubx[2:3] = 310

cfg_path = "configs/Tsup_m_flow_DDE_delay_Tsup_valve_open_tvp.json"

with ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=param_guess) as param_est:

    Q = ca.DM.eye(5)
    R = ca.DM.eye(2)
    #R[0,0] = 1E-1
    
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
    sol["Tsup"].plot(color="r", linestyle="dashed", ax=ax, linewidth=0.75)
    ax1 = ax.twinx()
    sol["m_flow_bool"].plot(color="g", ax=ax1, linestyle="dashed", drawstyle="steps-post")
    sol["valve_open"].plot(color="b", ax=ax1, linestyle="dashed", drawstyle="steps-post")
    ax.legend(["measured", "model"])
    ax1.legend()
    
    """
    ylim = ax.get_ylim()
    ylim_1 = ax1.get_ylim()
    frac_ylim = ylim[0]/ylim[1]
    ax1.set_ylim([frac_ylim*ylim_1[1], ylim_1[1]])
    """
    
    plt.show()
    
    ax = sol["m_flow"].plot(color="r")
    sol["y5"].plot(color="k", ax=ax)
    ax1 = ax.twinx()
    #sol["u_val_set"].plot(color="g", ax=ax1, linestyle="dashed")
    ax.legend(["model", "measured"])
    ax1.legend()
    
    ylim = ax.get_ylim()
    ylim_1 = ax1.get_ylim()
    frac_ylim = ylim[0]/ylim[1]
    ax1.set_ylim([frac_ylim*ylim_1[1], ylim_1[1]])
    
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
    
    Tsup = sol.Tsup[sol.m_flow_bool > 0].sort_values(ascending=False)
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
    Tsup delays, measurement.
    """
    ax = sol[["x1", "x2", "Tset_sup", "Tsup"]].plot()
    sol[["y3"]].plot(ax=ax, color="k", linewidth=0.5)
    plt.show()
    
    print(params)






