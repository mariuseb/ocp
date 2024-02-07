import casadi as ca
import numpy as np
from ocp.dae import DAE
from ocp.integrators import RK4
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
    
    dot(u)_k = − (N / d) * (u_k − u_k−1), ∀k ∈ [1, . . . , N]:
    
    with:
    
    x(t − d) ≈ u_N 

We generate the symbolic DAE first, then simulate.

"""

N = 10
d = 1
U = ca.SX.sym("U", N)
U_dot = ca.SX.sym("U_dot", N)
for n in range(1, N):
    U_dot[n] = (-N/d)*(U[n] - U[n-1])
U_dot[0] = -U[N-1]

#print("U:")
#print(U)
print("U_dot:")
pprint(U_dot)

"""
Generate the config-file:

Auto-complete missing vars 
to empty vectors.
"""

dae = {
    "ode": U_dot,
    "x": U,
    "u": ca.SX.sym("u", 0, 0),
    "p": ca.SX.sym("p", 0, 0),
    "r": ca.SX.sym("r", 0, 0),
    "z": ca.SX.sym("z", 0, 0),
    "s": ca.SX.sym("s", 0, 0),
    "y": ca.SX.sym("y", 0, 0),
    "w": ca.SX.sym("w", 0, 0),
    "v": ca.SX.sym("w", 0, 0)
    
}

dt=0.1
rk4 = RK4(dae, dt=dt, n_steps=1)
print(rk4)

"""
Simulate:
"""

x0 = ca.DM([0]*N)
x0[0] = 1
xsim = rk4.simulate(x0=x0, N=(10/dt))
res = pd.DataFrame(
                    data=np.array(xsim).T, 
                    columns=list(map(lambda x: "u_" + str(x), range(N)))
                   )
ax = res.plot()
plt.show()
print(xsim)





