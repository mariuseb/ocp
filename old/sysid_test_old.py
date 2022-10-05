from casadi import *
import json
from dae import DAE
from integrators import RungeKutta4
import pandas as pd
import os
import numpy

# In this example, we fit a nonlinear model to measurements
#
# This example uses more advanced constructs than the vdp* examples:
# Since the number of control intervals is potentially very large here,
# we use memory-efficient Map and MapAccum, in combination with
# codegeneration.
#
# We will be working with a 2-norm objective:
# || y_measured - y_simulated ||_2^2
#
# This form is well-suited for the Gauss-Newton Hessian approximation.

############ SETTINGS #####################
"""
N = 10000  # Number of samples
fs = 610.1 # Sampling frequency [hz]

param_truth = DM([5.625e-6,2.3e-4,1,4.69])
param_guess = DM([5,2,1,5])
scale = vertcat(1e-6,1e-4,1,1)

############ MODELING #####################
y  = MX.sym('y')
dy = MX.sym('dy')
u  = MX.sym('u')

states = vertcat(y,dy);
controls = u;

M = MX.sym("x")
c = MX.sym("c")
k = MX.sym("k")
k_NL = MX.sym("k_NL")

params = vertcat(M,c,k,k_NL)

rhs = vertcat(dy , (u-k_NL*y**3-k*y-c*dy)/M)

# Form an ode function
ode = Function('ode',[states,controls,params],[rhs])

############ Creating a simulator ##########
N_steps_per_sample = 10
dt = 1/fs/N_steps_per_sample

# Build an integrator for this system: Runge Kutta 4 integrator
k1 = ode(states,controls,params)
k2 = ode(states+dt/2.0*k1,controls,params)
k3 = ode(states+dt/2.0*k2,controls,params)
k4 = ode(states+dt*k3,controls,params)

states_final = states+dt/6.0*(k1+2*k2+2*k3+k4)

# Create a function that simulates one step propagation in a sample
one_step = Function('one_step',[states, controls, params],[states_final]);

X = states;

for i in range(N_steps_per_sample):
  X = one_step(X, controls, params)

# Create a function that simulates all step propagation on a sample
one_sample = Function('one_sample',[states, controls, params], [X])

############ Simulating the system ##########
all_samples = one_sample.mapaccum("all_samples", N)

# Choose an excitation signal
numpy.random.seed(0)
u_data = DM(0.1*numpy.random.random(N))

x0 = DM([0,0])
X_measured = all_samples(x0, u_data, repmat(param_truth,1,N))

y_data = X_measured[0,:].T
"""

#print(os.getcwd())

with open("sysid/param_est_config_ms.json", "r") as file:
    config = json.load(file)

model = config["model"]
dt = config["dt"]
N = config["N"]
n_steps = config["n_steps"]

# generate some data:
numpy.random.seed(0)
u_data = DM(0.1*numpy.random.random(N))

# create a dae
dae = DAE(model)    
# integrator:
RK4 = RungeKutta4(dt, n_steps, dae)

# true parameters:
x0 = DM([0,0])
param_truth = DM([5.625e-6,2.3e-4,1,4.69])
X = RK4.simulate(x0, u_data, param_truth)

# measurement data
y_data = X[0,:].T
###################################################

df = pd.DataFrame()
#dt = np.arange(0, config["dt"]*len(df), config["dt"])
df["u1"] = np.array(u_data).flatten()
df["y1"] = np.array(y_data).flatten()
df.index = np.arange(0, config["dt"]*N, config["dt"])


# You may add some noise here
#y_data+= 0.001*numpy.random.random(N)
# When noise is absent, the fit will be perfect.

# Use just-in-time compilation to speed up the evaluation
if Importer.has_plugin('clang'):
  with_jit = True
  compiler = 'clang'
elif Importer.has_plugin('shell'):
  with_jit = True
  compiler = 'shell'
else:
  print("WARNING; running without jit. This may result in very slow evaluation times")
  with_jit = False
  compiler = ''

############ Create a Gauss-Newton solver ##########
def gauss_newton(e,nlp,V):
  # objective only indirectly affected by collocation points...
  J = jacobian(e,V)
  H = triu(mtimes(J.T, J))
  sigma = MX.sym("sigma")
  hessLag = Function('nlp_hess_l',{'x':V,'lam_f':sigma, 'hess_gamma_x_x':sigma*H},
                     ['x','p','lam_f','lam_g'], ['hess_gamma_x_x'],
                     dict(jit=with_jit, compiler=compiler))
  return nlpsol("solver","ipopt", nlp, dict(hess_lag=hessLag, jit=with_jit, compiler=compiler))

############ Identifying the simulated system: single shooting strategy ##########

# Note, it is in general a good idea to scale your decision variables such
# that they are in the order of ~0.1..100

"""

X_symbolic = all_samples(x0, u_data, repmat(params*scale,1,N))

e = y_data-X_symbolic[0,:].T;
nlp = {'x':params, 'f':0.5*dot(e,e)}

solver = gauss_newton(e,nlp, params)

sol = solver(x0=param_guess)

print(sol["x"]*scale)

assert(norm_inf(sol["x"]*scale-param_truth)<1e-8)

"""

# create new integrators here:
#Coll = integrator('collocation_integrator', 'collocation', dae, {'tf':dt})

#grid = numpy.array([collocation_points(1, "legendre")])*dt
#grid = numpy.append(numpy.array([0]), numpy.array(collocation_points(1, "legendre")*dt))

with_jit = False

order = 2
method = "legendre"
grid = numpy.append(0, collocation_points(order, method))*dt

"""
Create problem only with integrator map,
i.e. with quadrature in integrator.

Integrator from casadi-docs:

  Initial conditions at t=t0
  x(t0)  = x0
  q(t0)  = 0

  Forward integration from t=t0 to t=tf
  der(x) = function(x, z, p, t)                  Forward ODE
  0 = fz(x, z, p, t)                  Forward algebraic equations
  der(q) = fq(x, z, p, t)                  Forward quadratures

  Terminal conditions at t=tf
  rx(tf)  = rx0sadi4CallE at .../casadi/core/mx.cpp:2035:
Error in Call::ad_forward for 'ompmap100_F' [OmpMap] at .../casadi/core/casadi_call.cpp:123:
Error in Function::forward for 'ompmap100_F' [OmpMap] at .../casadi/core/function.cpp:1017:
Error in Function::forward for 'F' [Collocation] at .../casadi/core/f
  rq(tf)  = 0

  Backward integration from t=tf to t=t0
  der(rx) = gx(rx, rz, rp, x, z, p, t)        Backward ODE
  0 = gz(rx, rz, rp, x, z, p, t)        Backward algebraic equations
  der(rq) = gq(rx, rz, rp, x, z, p, t)        Backward quadratures

  where we assume that both the forward and backwards integrations are index-1
  (i.e. dfz/dz, dgz/drz are invertible) and furthermore that
  gx, gz and gq have a linear dependency on rx, rz and rp.

"""

# create an algebraic variable corresponding to the measurement:
y = MX.sym("y")
# measurement "noise"
#v = MX.sym("v")
# extract position
x = dae.dae.x[0]
q = y - x


Coll = integrator('F','collocation',
                  {'x':vertcat(*dae.dae.x), 
                   #'z':y, \
                   'p':vertcat(*dae.dae.u, *dae.dae.p), 
                   #'alg':y-x,
                   #'quad': 0.5*(y-x)**2,
                  'ode': vertcat(*dae.dae.ode)},
                  {'tf':dt,
                   'grid':grid})

#y_data_coll = Coll.mapaccum(N, "openmp")(x0, vertcat(u_data, repmat(param_truth, 1, N)))
#p_coll = vertcat(u_data.T, repmat(DM(0), 1, N), repmat(param_truth, 1, N))
p_coll = vertcat(u_data.T, repmat(param_truth, 1, N))
coll_simulate = Coll.mapaccum(N)

sim_res = coll_simulate(x0=x0, p=p_coll)

x_data_coll = np.array(sim_res["xf"])
#y_data_coll = x_data_coll[0,:]
#x1_data_coll = x_data_coll[0]
y_data_coll = x_data_coll[0]
y_data_coll = y_data_coll[(order-1)::order]

# check that collocation integrator yields ca. same result as RK4:


############ Identifying the simulated system: multiple shooting strategy ##########
param_guess = DM([5,2,1,5])
#param_guess = DM([3e-6,0.5e-4,0.5,10])
#param_guess = DM([5,2,1,5])
scale = vertcat(1e-6,1e-4,1,1)
#scale = vertcat(1,1,1,1)

fs = 1/dt
params = vertcat(*RK4.dae.dae.p)

# All states become decision variables
X = MX.sym("X", 2, N)

#Xn = one_sample.map(N, 'openmp')(X, u_data.T, repmat(params*scale,1,N))
#Xn = RK4.one_sample.map(N, "openmp")(X, u_data, scale*repmat(params, 1, N))

#y_data_coll = y_data_coll.reshape((N, 1))

p_coll_symbolic = vertcat(u_data.T, scale*repmat(params, 1, N))
coll_one_step = Coll.map(N, "openmp")
coll_mapped = coll_one_step(x0=X, p=p_coll_symbolic)
Xn = coll_mapped["xf"]
#e_coll = coll_mapped["qf"].T

# gaps at finite elements:
#gaps = Xn[:,:-1]-X[:,1:]
gaps = Xn[:,(order-1):-1:order]-X[:,1:]

# orig:
#gaps = Xn[:,:-1]-X[:,1:]

# gaps at collocation points:
# requires additional variables:
X_coll = MX.sym("X_coll", 2, N)

#gaps_coll = Xn[:,0:-2:2]-X_coll[:,1:]

#gaps = Xn[:,1:-1:2]-X[:,1:],X_coll_guess# All states become decision variables

#e = y_data_coll-Xn[0,:].T;

#from shooting import CollocationCoeffs
#B, C, D, tau, debug = CollocationCoeffs({'K': order, 'method': method}).coef()

"""
for m in range(self.M):
    for tau_k in range(self.K + 1):
        l_tau_k = self.ca_l(t(i, m, tau_k), xc(i, m, tau_k), u(i), zc(i, tau_k), y(i), p())
        #self.add_cost(self.B[tau_k]*l_tau_k*self.hk[i]) (self.hk[i]/self.M)*(m + 1)
        #self.add_cost(self.B[tau_k] * l_tau_k * (self.hk[i]/self.M)*(m + 1))
        self.add_cost(self.B[tau_k] * l_tau_k * (self.hk[i]/self.M))
            
"""


# merge X, X_coll

# X at finite elements + collocation points:
#X_merged = vertcat(X, X_coll).reshape((vertcat(*dae.dae.x).shape[0],order*N))

# build objective manually:
#obj = 0
#for n in range(N):
#  for k in range(order + 1):        
#    obj += B[k]*0.5*(y_data_coll[n] - X_merged[0, n+k])**2*dt

e = y_data_coll-Xn[0,(order-1)::order].T

#V = veccat(params, X, X_coll)
V = veccat(params, X)


#obj = 0
#for n in range(N):
#  obj += e_coll[n]

#nlp = {'x':V, 'f':0.5*dot(e,e),'g': vec(vertcat(gaps, gaps_coll))}
#g = vec(vertcat(gaps, gaps_coll))
g = vec(gaps)
nlp = {'x':V, 'f':0.5*dot(e,e),'g': g}

# Multipleshooting allows for careful initialization
yd = np.diff(y_data,axis=0)*fs
X_guess = horzcat(y_data , vertcat(yd,yd[-1])).T
X_coll_guess = horzcat(y_data , vertcat(yd,yd[-1])).T

#x0 = veccat(param_guess,X_guess,X_coll_guess)
x0 = veccat(param_guess,X_guess)

#solver = gauss_newton(e,nlp, V)
solver = nlpsol("solver","ipopt", nlp)

sol = solver(x0=x0,lbg=0,ubg=0)

print(sol["x"][:4]*scale)

assert(norm_inf(sol["x"][:4]*scale-param_truth)<1e-8)
