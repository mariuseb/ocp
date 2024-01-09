import casadi as ca
import numpy as np
from ocp.dae import DAE
from ocp.integrators import RK4, IRK
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint

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
data = data.iloc[0:1000]
data["u"] = data.val_pos_219
data["x"] = (data.V_flow_219/data.V_flow_219.max())

"""
Compare actual valve operation against simulation.
"""

N = 10 # for now only 
d = 300
U = ca.SX.sym("U", N)
X = ca.SX.sym("X", 1)
U_dot = ca.SX.sym("U_dot", N)
for n in range(1, N):
    U_dot[n] = -(N/d)*(U[n] - U[n-1])
# tau_X -> large
tau = 0.5
U_dot[0] = 1/tau*(X - U[N-1])

#print("U:")
#print(U)
print("U_dot:")
pprint(U_dot)

"""
Generate the config-file:

Auto-complete missing
vars to empty vectors.
"""

dae_u = {
        "ode": U_dot,
        "x": U,
        #"x": U[:(N-1)],
        "u": X,
        #"u": ca.SX.sym("u", 0, 0),
        "p": ca.SX.sym("p", 0, 0),
        "r": ca.SX.sym("r", 0, 0)
        }

dt = 1
rk4 = RK4(dae_u, dt=dt, n_steps=1)
print(rk4)

# Simulate:
K = 300*100
x0 = ca.DM([0]*(N))
#x0[0] = 1
u = ca.repmat(ca.DM(1), 1, int(K/dt))
xsim = rk4.simulate(x0=x0,u=u,N=(K/dt))
res = pd.DataFrame(
                    data=np.array(xsim).T, 
                    columns=list(map(lambda x: "u_" + str(x), range(N))),
                    index=np.arange(0,K,dt)
                   )

ax = res.plot()
plt.show()
print(xsim)





