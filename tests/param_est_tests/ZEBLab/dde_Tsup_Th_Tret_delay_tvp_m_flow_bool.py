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
data = data.resample(rule="5min").mean()
y_data = data.bfill() 
y_data["u_val_set"] = y_data.val_pos_219
#y_data["m_flow"] = (y_data.V_flow_219/y_data.V_flow_219.max())
#y_data["m_flow"] = y_data.V_flow_219
#y_data["y1"] = y_data["m_flow"]
# take only time point between 0400 and 1100
start = pd.Timestamp("2022-12-13 00:00")
stop = pd.Timestamp("2022-12-16 00:00")
y_data = y_data.loc[start:stop]

index_selection = [ndx for ndx in y_data.index if ndx.hour in range(4,14)]
y_data = y_data.loc[index_selection]
#data = data.iloc[0:1000]

N = len(y_data)
dt = (y_data.index[1] - y_data.index[0]).seconds
# set range index for identification:
y_data["dt_index"] = y_data.index
y_data.index = range(0,N*dt,dt)

# only tau, delay
param_guess = np.array([500,
                        -15 + 273.15,
                        45 + 273.15,
                        0.7,
                        293,
                        5,
                        5,
                        5,
                        5,
                        5,
                        5,
                        1E-2,
                        1E1,
                        1E-2,
                        1E3,
                        1E-2,
                        1E2,
                        1E-2,
                        1E2,
                        2500
                        ])

lbp = 0.0001*param_guess
ubp = 10000*param_guess
len_p = param_guess.shape[0]
lbp[0] = 500
ubp[0] = 500
lbp[0] = 300
ubp[0] = 10000
lbp[len_p-1] = 50
ubp[len_p-1] = 100000
lbp[1] = -20 + 273.15
ubp[1] = -10 + 273.15
lbp[2] = 35 + 273.15
ubp[2] = 50 + 273.15
lbp[3] = 1E-3
ubp[3] = 1.5
lbp[4] = 290
ubp[4] = 300
lbp[5] = 0
ubp[5] = 20
lbp[6] = 0
ubp[6] = 20
lbp[7] = 0
ubp[7] = 20
lbp[8] = 0
ubp[8] = 20
lbp[9] = 0
ubp[9] = 20
lbp[10] = 0
ubp[10] = 20
# constrain in particular Th to physically meaningful values:
x_guess = np.array([
                y_data.Tsup,
                y_data.Tsup,
                y_data.Tsup,
                y_data.Tsup,
                y_data.Tret,
                y_data.Tret,
                y_data.Tret
                ])
lbx = 0.9*x_guess
ubx = 1.1*x_guess

# limits on Tret:
#lbx[0:1] = 290
#lbx[1:2] = -1
#lbx[2:3] = 290
#ubx[2:3] = 310

cfg_path = "configs/Tsup_Th_Tret_DDE_tvp_delay_m_flow_open.json"

with ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=param_guess) as param_est:

    Q = ca.DM.eye(7)
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
                                    lbx=lbx,
                                    ubx=ubx,
                                    x_guess=x_guess,
                                    #Th_anti_bias=True,
                                    covar=ca.veccat(Q, R)
                                    )

    #k = params["k"]
    sol.index = y_data.dt_index
    #ax = (k*sol["x2"]) .plot(color="r")
    ax = sol["y3"].plot(color="k", linewidth=0.75)
    sol["Tsup"].plot(color="r", linestyle="dashed", ax=ax, linewidth=0.75)
    ax1 = ax.twinx()
    sol["valve_open"].plot(color="g", ax=ax1, linestyle="dashed")
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
    ax = sol[["Tsup", "x1", "x2", "Th", "x3", "x4", "Tret"]].plot(linewidth=0.75)
    sol[["y2", "y3"]].plot(ax=ax, color="k", linewidth=0.75)
    plt.show()
    
    """
    model deltaT vs. measured
    """
    deltaT = sol["Tsup"] - sol["Tret"]
    ax = deltaT.plot(color="k", linewidth=0.75)
    (sol["y3"] - sol["y2"]).plot(ax=ax, linewidth=0.75)
    ax1 = ax.twinx()
    sol[["valve_open"]].plot(ax=ax1, color="g", linewidth=0.5, drawstyle="steps-post")
    plt.show()
    
    print(params)






