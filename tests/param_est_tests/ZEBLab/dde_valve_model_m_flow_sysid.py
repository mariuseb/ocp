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
y_data = data.bfill() 
y_data["u_val_set"] = y_data.val_pos_219
#y_data["m_flow"] = (y_data.V_flow_219/y_data.V_flow_219.max())
#y_data["m_flow"] = y_data.V_flow_219
#y_data["y1"] = y_data["m_flow"]
# take only time point between 0400 and 1100
start = pd.Timestamp("2022-12-14 00:00")
stop = pd.Timestamp("2022-12-18 00:00")
y_data = y_data.loc[start:stop]

index_selection = [ndx for ndx in y_data.index if ndx.hour in range(4,12)]
y_data = y_data.loc[index_selection]
#data = data.iloc[0:1000]

N = len(y_data)
dt = (y_data.index[1] - y_data.index[0]).seconds
# set range index for identification:
y_data["dt_index"] = y_data.index
y_data.index = range(0,N*dt,dt)

# only tau, delay
param_guess = np.array([150,0.03])

lbp = 0.1*param_guess
ubp = 10*param_guess
len_p = param_guess.shape[0]
lbp[len_p-1] = 0.003
ubp[len_p-1] = 0.1
# constrain in particular Th to physically meaningful values:
x_guess = np.array([
                y_data.m_flow.values,
                y_data.m_flow.values
                ])
lbx = 0.0*x_guess
ubx = 2.0*x_guess

cfg_path = "configs/DDE_valve_2state_m_flow.json"

with ParameterEstimation(config=cfg_path,
                            N=N,
                            dt=dt,
                            param_guess=param_guess) as param_est:

    Q = ca.DM.eye(2)
    R = ca.DM.eye(1)

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
                                    covar=ca.veccat(Q, R)
                                    )

    #k = params["k"]
    sol.index = y_data.dt_index
    #ax = (k*sol["x2"]) .plot(color="r")
    ax = sol["m_flow"].plot(color="r")
    sol["y5"].plot(color="k", ax=ax)
    ax1 = ax.twinx()
    sol["u_val_set"].plot(color="g", ax=ax1, linestyle="dashed")
    ax.legend(["model", "measured"])
    ax1.legend()
    
    ylim = ax.get_ylim()
    ylim_1 = ax1.get_ylim()
    frac_ylim = ylim[0]/ylim[1]
    ax1.set_ylim([frac_ylim*ylim_1[1], ylim_1[1]])
    
    plt.show()
    print(params)






