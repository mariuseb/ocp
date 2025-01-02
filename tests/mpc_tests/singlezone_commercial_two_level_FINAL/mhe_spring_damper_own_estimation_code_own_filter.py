#
#     MIT No Attribution
#
#     Copyright (C) 2010-2023 Joel Andersson, Joris Gillis, Moritz Diehl, KU Leuven.
#
#     Permission is hereby granted, free of charge, to any person obtaining a copy of this
#     software and associated documentation files (the "Software"), to deal in the Software
#     without restriction, including without limitation the rights to use, copy, modify,
#     merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
#     permit persons to whom the Software is furnished to do so.
#
#     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
#     INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
#     PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
#     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#     OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
#     SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

# For documentation about this examples, check http://docs.casadi.org/documents/mhe_spring_damper.pdf

from casadi import *
import numpy as NP
import matplotlib.pyplot as plt
import time
from casadi.tools import *
from ocp.mhe import MHE
from ocp.filters import KalmanDAE
from scipy import linalg #, matrix
import numpy as np
import pandas as pd
plt.interactive(True)

NP.random.seed(0)

# Settings of the filter
N = 10 # Horizon length
dt = 0.05; # Time step

sigma_p = 0.005 # Standard deviation of the position measurements
sigma_w = 0.1 # Standard deviation for the process noise
R = DM(1/sigma_p**2) # resulting weighting matrix for the position measurements
Q = DM(1/sigma_w**2) # resulting weighting matrix for the process noise
Q_mhe = DM.eye(2)
Q_mhe[0,0] = Q
Q_mhe[1,1] = Q
R_mhe = R


Nsimulation = 1000 # Lenght of the simulation

# Parameters of the system
m = 1 # The weight of the mass
k = 1 # The spring constant
c = 0.5 # The damping of the system
# The state
x = SX.sym("x")
dx = SX.sym("dx")
states = vertcat(x, dx)
Nstates = states.size()[0] # Number of states

# The control input
F = SX.sym("F")
controls = vertcat(F)
Ncontrols = controls.size()[0] # Number of control inputs

# Disturbances
w1 = SX.sym("w1")
w2 = SX.sym("w2")
disturbances = vertcat(w1,w2)
Ndisturbances = disturbances.size()[0] # Number of disturbances

# Measurements
y = SX.sym("y")
measurements = vertcat(y)
Nmeas = measurements.size()[0] # Number of measurements


# Create Structure for the entire horizon

# Structure that will be degrees of freedom for the optimizer
#shooting = struct_symSX([(entry("X",repeat=N,struct=states),entry("W",repeat=N-1,struct=disturbances))])
# Structure that will be fixed parameters for the optimizer
#parameters = struct_symSX([(entry("U",repeat=N-1,struct=controls),entry("Y",repeat=N,struct=measurements),entry("S",shape=(Nstates,Nstates)),entry("x0",shape=(Nstates,1)))])
#S = parameters["S"]
#x0 = parameters["x0"

# Define the ODE right hand side
k = SX.sym("k")
c = SX.sym("c")
m = SX.sym("m")
parameters = vertcat(k,c,m)
rhs = vertcat(dx+w1, (-k*x-c*dx+F)/m+w2)

x0 = SX.sym("x0", Nstates, 1)
S = SX.sym("S", Nstates, Nstates)

f = Function('f', [states,controls,disturbances,parameters],[rhs])

# Build an integrator for this system: Runge Kutta 4 integrator
k1 = f(states,controls,disturbances,parameters)
k2 = f(states+dt/2.0*k1,controls,disturbances,parameters)
k3 = f(states+dt/2.0*k2,controls,disturbances,parameters)
k4 = f(states+dt*k3,controls,disturbances,parameters)

states_1 = states+dt/6.0*(k1+2*k2+2*k3+k4)
phi = Function('phi', [states, controls, disturbances,parameters], [states_1], ['x', 'u', 'd', 'p'], ['x1'])
PHI = phi.factory('PHI', ['x', 'u', 'd', 'p'], ['jac:x1:x'])
# Define the measurement system
h = Function('h', [states], [x], ['x'], ['y']) # We have measurements of the position
H = h.factory('H', ['x'], ['jac:y:x'])
# Build the multiple shooting constraints
g = []
X = SX.sym("X", Nstates, N)
U = SX.sym("U", Ncontrols, N-1)
W = SX.sym("W", Ndisturbances, N-1)
Y = SX.sym("Y", Nmeas, N)

for i in range(N-1):
  _X = X[:,i]
  _U = U[:,i]
  _W = W[:,i]
  g.append(phi(_X, _U, _W, parameters) - X[:,i+1])
  
nlp_p = veccat(Y, U, parameters, x0, S)
nlp_x = veccat(X, W)
  
obj = 0

# Build the objective
# First the arrival cost
#obj += mtimes([(shooting["X",0]-parameters["x0"]).T,S,(shooting["X",0]-parameters["x0"])])
obj += (X[:,0] - x0).T@S@(X[:,0] - x0)
#Next the cost for the measurement noise
for i in range(N):
    vm = h(X[:, i]) - Y[:, i]
    obj += vm.T@R@vm
#And also the cost for the process noise
for i in range(N-1):
    obj += W[:,i].T@Q@W[:,i]


# Formulate the NLP
nlp = {'x': nlp_x, 'p':nlp_p, 'f': obj, 'g':vertcat(*g)}

# Make a simulation to create the data for the problem
params = np.array([1,0.5,1])
simulated_X = DM.zeros(Nstates,Nsimulation)
simulated_X[:,0] = DM([1,0]) # Initial state
t = NP.linspace(0,(Nsimulation-1)*dt,Nsimulation) # Time grid
simulated_U = DM(cos(t[0:-1])).T # control input for the simulation
simulated_U[:,int(Nsimulation/2):] = 0.0
simulated_U = horzcat(simulated_U, DM([0]))
simulated_W = DM(sigma_w*NP.random.randn(Ndisturbances,Nsimulation-1)) # Process noise for the simulation
for i in range(Nsimulation-1):
  simulated_X[:,i+1] = phi(simulated_X[:,i], simulated_U[:,i], simulated_W[:,i], params)
#Create the measurements from these states
simulated_Y = DM.zeros(Nmeas,Nsimulation) # Holder for the measurements
for i in range(Nsimulation):
  simulated_Y[:,i] = h(simulated_X[:,i])
# Add noise the the position measurements
simulated_Y += sigma_p*NP.random.randn(simulated_Y.shape[0],simulated_Y.shape[1])

#The initial estimate and related covariance, which will be used for the arrival cost
sigma_x0 = 0.01
P = sigma_x0**2*DM.eye(Nstates)
x0 = simulated_X[:,0] + sigma_x0*NP.random.randn(Nstates,1)
# Create the solver
opts = {"ipopt.print_level":5, "print_time": False, 'ipopt.max_iter':100}
nlpsol = nlpsol("nlpsol", "ipopt", nlp, opts)

"""
Create a MHE object with own code:
"""
cfg_path = "mhe_configs/mass_spring_damper_MHE.json"
mhe = MHE(config=cfg_path,
          #param_guess=params[:-2], 
          param_guess=params, 
          arrival_cost=True)


# Create a holder for the estimated states and disturbances
estimated_X= DM.zeros(Nstates,Nsimulation)
estimated_W = DM.zeros(Ndisturbances,Nsimulation-1)


# For the first instance we run the filter, we need to initialize it.
"""
current_parameters = parameters(0)
current_parameters["U",lambda x: horzcat(*x)] = simulated_U[:,0:N-1]
current_parameters["Y",lambda x: horzcat(*x)] = simulated_Y[:,0:N]
current_parameters["S"] = linalg.inv(P) # Arrival cost is the inverse of the initial covariance
current_parameters["x0"] = x0
initialisation_state = shooting(0)
initialisation_state["X",lambda x: horzcat(*x)] = simulated_X[:,0:N]
"""

x_guess = np.concatenate([np.array(simulated_X[:,0:N].T).flatten(), np.array([0,0]*(N-1))])
#p = veccat([simulated_Y[:,0:N], simulated_U[:,0:N-1], params, x0, inv(P)])
p = np.array(veccat(simulated_Y[:,0:N], simulated_U[:,0:N-1], params, x0, inv(P))).flatten()

#res = nlpsol(p=p, x0=initialisation_state, lbg=0, ubg=0)
res = nlpsol(p=p, x0=x_guess, lbg=0, ubg=0)

# Get the solution
#solution = shooting(res["x"])
#estimated_X[:,0:N] = solution["X",lambda x: horzcat(*x)]
#estimated_W[:,0:N-1] = solution["W",lambda x: horzcat(*x)]

#P0 = current_parameters["S"]
P0 = DM.eye(mhe.n_p + mhe.n_x)*0
P0[mhe.n_p:(mhe.n_p + mhe.n_x),mhe.n_p:(mhe.n_p + mhe.n_x)] = linalg.inv(P)
x_N = x0
#x_N = initialisation_state["X", 0]
y_data = pd.DataFrame(index=np.arange(0,N*dt, dt))
y_data["F"] = np.array(simulated_U[:,0:N]).flatten()
y_data["y1"] = np.array(simulated_Y[:,0:N]).flatten()
#x_guess = np.array([0,0]*N)
x_guess = np.array(simulated_X[:,0:N]).T.flatten()
# Solve with own code:
sol_mhe, params, raw_sol_mhe = mhe.solve(
    y_data,
    params,
    lbp=params,
    ubp=params,
    covar=veccat(Q_mhe, R_mhe),
    P0=P0,
    x_N=x_N,
    #lbx=lbx,
    #ubx=ubx,
    x_guess=x_guess,
    return_raw_sol=True,
    codegen=False
)
# N == 2: DM([0.995637, -0.000156111, 0.0658033, 0.00163179, 0.998926, 6.22639e-05])
estimated_X[:,0:N] = sol_mhe[mhe.x_names].values.T
estimated_W[:,0:N-1] = sol_mhe[mhe.d_names].iloc[0:mhe.N-1].values.T

# manual evaluation of objective (which of the above is correct?)
# simulate using x0:
#rk4 = mhe.integrator.get_one_sample()
#x1 = rk4(x0, 0, simulated_U[:,0:N-1], params, 0, np.array([0,0]))
#obj_test = 

known_sol = pd.read_csv("mass_spring_damper_mhe.csv")

"""
Here, set up EKF:
"""
ekf_cfg = "ekf_configs/mass_spring_damper_EKF.json"
ekf = KalmanDAE(
                ekf_cfg,
                P0=P
                )

def smoothing_estimate(x0, y0, sol_mhe, P, R, Q):
    H0 = H(x0)
    K = mtimes([P, H0.T, linalg.inv(mtimes([H0, P, H0.T]) + R)])
    
    P = mtimes((DM.eye(Nstates) - mtimes(K,H0)),P)
    #h0 = h(solution["X",0])
    h0 = h(sol_mhe[mhe.x_names].iloc[0].values)
    res_y = y0 - h0
    res_x = x0 - sol_mhe[mhe.x_names].iloc[0].values
    residual = res_y - H0@res_x
    x0 = x0 + K@residual
    F = PHI(
            sol_mhe[mhe.x_names].iloc[0].values,
            sol_mhe[mhe.u_names].iloc[0].values,
            sol_mhe[mhe.u_names].iloc[0],
            params
            )
    P = mtimes([F, P, F.T]) + linalg.inv(Q)
    
    x0 = phi(
              x0, 
              sol_mhe[mhe.u_names].iloc[0].values,
              sol_mhe[mhe.u_names].iloc[0],
              params
              )
    
    return x0, _x0, P, res_x, res_y, residual, K, F
      
#Q_mhe[0,0] = 1e-8
# Now make a loop for the rest of the simulation
for i in range(1,Nsimulation-N+1):
    
  # Update the arrival cost, using linearisations around the estimate of MHE at the beginning of the horizon (according to the 'Smoothed EKF Update'): first update the state and covariance with the measurement that will be deleted, and next propagate the state and covariance because of the shifting of the horizon
  print("step %d/%d (%s)" % (i, Nsimulation-N , mhe.solver.stats()["return_status"]))
  #H0 = H(solution["X",0])
  #x0 = sol_mhe[mhe.x_names].iloc[0].values
  y0 = y_data["y1"].iloc[0]
  
  # replace this part with own EKF implementation:
  
  """
  x00, x10, P, _res_x, _res_y, _res, _K, _A = smoothing_estimate(
    x0,
    y0,
    sol_mhe,
    P,
    R_mhe,
    Q_mhe
  )
  """
  
  x00, x10, P, res_x, res_y, res, K, A = ekf.estimate_smoothing(
                                                    x0=sol_mhe.iloc[0][mhe.x_names].values, \
                                                    x0_1=x0, \
                                                    #z=sol_mhe.loc[0, mhe.z_names].values, \
                                                    u=y_data["F"].iloc[0],  
                                                    y=y0, 
                                                    p=params,
                                                    d=sol_mhe.iloc[0][mhe.d_names].values,
                                                    #Q=linalg.inv(Q),
                                                    #R=linalg.inv(R)
                                                    Q=linalg.inv(Q_mhe),
                                                    R=R_mhe
                                                    )
  # DM([0.991141, -0.000187613])
  #_x10 = phi(x00, y_data["F"].iloc[0], sol_mhe.iloc[0][mhe.d_names].values, params.values)
  # update data:
  y_data["F"] = np.array(simulated_U[:,i:i+N]).flatten()
  y_data["y1"] = np.array(simulated_Y[:,i:i+N]).flatten()
  # set arrival cost weighting:
  P0[mhe.n_p:(mhe.n_p + mhe.n_x), mhe.n_p:(mhe.n_p + mhe.n_x)] = linalg.inv(P)
  #P0[mhe.n_p:(mhe.n_p + mhe.n_x), mhe.n_p:(mhe.n_p + mhe.n_x)] = P
  x_N = x0 = x10
  # Initialize the system with the shifted solution
  #initialisation_state["W",lambda x: horzcat(*x),0:N-2] = estimated_W[:,i:i+N-2] # The shifted solution for the disturbances
  #initialisation_state["W",N-2] = DM.zeros(Ndisturbances,1) # The last node for the disturbances is initialized with zeros
  #initialisation_state["X",lambda x: horzcat(*x),0:N-1] = estimated_X[:,i:i+N-1] # The shifted solution for the state estimates
  x_guess = estimated_X[:,i:i+N-1]
  # The last node for the state is initialized with a forward simulation
  phi0 = phi(
             estimated_X[:,i],
             simulated_U[:,i+N-1],
             0,
             params
             )
  #initialisation_state["X",N-1] = phi0
  x_guess = veccat(x_guess, phi0)
  # And now initialize the solver and solve the problem
  #res = nlpsol(p=current_parameters, x0=initialisation_state, lbg=0, ubg=0)
  #solution = shooting(res["x"])

  sol_mhe, params, raw_sol_mhe = mhe.solve(
    y_data,
    params,
    lbp=params,
    ubp=params,
    covar=veccat(Q_mhe, R_mhe),
    P0=P0,
    x_N=x_N,
    #lbx=lbx,
    #ubx=ubx,
    x_guess=x_guess,
    return_raw_sol=True,
    codegen=False
  )
  # Now get the state estimate. Note that we are only interested in the last node of the horizon
  # first pass, N==2: DM([1.00241, 0.00426846, 0.00446963, 0.000110838, 1.00284, 0.00397697])
  estimated_X[:,N-1+i] = sol_mhe[mhe.x_names].values[-1]
  estimated_W[:,N-2+i] = sol_mhe[mhe.d_names].values[-2]
   
# Plot the results
plt.figure(1)
plt.clf()
plt.plot(t,vec(estimated_X[0,:]),'b--')
plt.plot(t,vec(known_sol["x"].values),'g--')
plt.plot(t,vec(simulated_X[0,:]),'r--')
plt.title("Position")
plt.xlabel('Time')
plt.legend(['Estimated position','Estimated position from example','Real position'])
plt.grid()

plt.figure(2)
plt.clf()
plt.plot(t,vec(estimated_X[0,:]-simulated_X[0,:]),'b--')
plt.title("Position error")
plt.xlabel('Time')
plt.legend(['Error between estimated and real position'])
plt.grid()

plt.show()

results = pd.DataFrame(data=np.array(estimated_X).T,
                       columns=["x", "dx"])
results.to_csv("mass_spring_damper_own_mhe_own_filter_N=10.csv", index=False)
known_sol["x_own_mhe"] = np.array(estimated_X[0,:]).flatten()

error = estimated_X[0,:]-simulated_X[0,:]
print(mtimes(error,error.T))
assert(mtimes(error,error.T)<0.01)
