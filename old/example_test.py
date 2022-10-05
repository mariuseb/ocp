from casadi import *
import casadi as ca
import numpy as np
import matplotlib.pyplot as plt
from pprint import pprint
import pandas as pd

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
N = 10  # Number of samples
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
N_steps_per_sample = 1
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

with_jit = False

############ Create a Gauss-Newton solver ##########
def gauss_newton(e,nlp,V):
  J = jacobian(e,V)
  H = triu(mtimes(J.T, J))
  sigma = MX.sym("sigma")
  #hessLag = Function('nlp_hess_l',{'x':V,'lam_f':sigma, 'hess_gamma_x_x':sigma*H},
  #                   ['x','p','lam_f','lam_g'], ['hess_gamma_x_x'],
  #                   dict(jit=with_jit, compiler=compiler))
  hessLag = None
  return nlpsol("solver","ipopt", nlp, dict(hess_lag=hessLag, jit=with_jit, compiler=compiler))

############ Identifying the simulated system: single shooting strategy ##########

# Note, it is in general a good idea to scale your decision variables such
# that they are in the order of ~0.1..100
X_symbolic = all_samples(x0, u_data, repmat(params*scale,1,N))

e = y_data-X_symbolic[0,:].T;
nlp = {'x':params, 'f':0.5*dot(e,e)}

#solver = gauss_newton(e,nlp, params)
solver = nlpsol("solver","ipopt", nlp)

sol = solver(x0=param_guess)

print(sol["x"]*scale)

#assert(norm_inf(sol["x"]*scale-param_truth)<1e-8)

############ Identifying the simulated system: multiple shooting strategy ##########

# All states become decision variables
X = MX.sym("X", 2, N)

Xn = one_sample.map(N, 'openmp')(X, u_data.T, repmat(params*scale,1,N))

gaps = Xn[:,:-1]-X[:,1:]

e = y_data-Xn[0,:].T;

V = veccat(params, X)

nlp = {'x':V, 'f':0.5*dot(e,e),'g': vec(gaps)}

# Multipleshooting allows for careful initialization
yd = np.diff(y_data,axis=0)*fs
X_guess = horzcat(y_data , vertcat(yd,yd[-1])).T;

x0 = veccat(param_guess,X_guess)

solver = gauss_newton(e,nlp, V)

sol = solver(x0=x0,lbg=0,ubg=0)

print(sol["x"][:4]*scale)

#assert(norm_inf(sol["x"][:4]*scale-param_truth)<1e-8)

###########################################################
############# Collocation transcription ###################
###########################################################

# Degree of interpolating polynomial
d = 2
# finite elements:
K = 4

# Get collocation points
tau_root = np.append(0, ca.collocation_points(d, 'legendre'))

# Coefficients of the collocation equation
C = np.zeros((d+1,d+1))

# Coefficients of the continuity equation
D = np.zeros(d+1)

# Coefficients of the quadrature function
B = np.zeros(d+1)

ps = []

# Construct polynomial basis
for j in range(d+1):
    # Construct Lagrange polynomials to get the polynomial basis at the collocation point
    p = np.poly1d([1])
    for r in range(d+1):
        if r != j:
            p *= np.poly1d([1, -tau_root[r]]) / (tau_root[j]-tau_root[r])

    ps.append(p)
    # Evaluate the polynomial at the final time to get the coefficients of the continuity equation
    D[j] = p(1.0)

    # Evaluate the time derivative of the polynomial at all collocation points to get the coefficients of the continuity equation
    pder = np.polyder(p)
    for r in range(d+1):
        C[j,r] = pder(tau_root[r])

    # Evaluate the integral of the polynomial to get the coefficients of the quadrature function
    pint = np.polyint(p)
    B[j] = pint(1.0)

# Time horizon
#T = 10.
T = N/1/fs
h = T/N

#N = 10000  # Number of samples
fs = 1/300 # Sampling frequency [hz]

data = pd.read_csv("inputPRBS1.csv", sep=";")
#data = data[0:10]
# to SI:
data["Ta"] += 273.15
data["Ps"] *= 1000
data["Ph"]*= 1000
data["yTi"] += 273.15

replace = {"yTi": "Ti", "Ph": "phi_h", "Ps": "phi_s"}
data.rename(columns=replace, inplace=True) 

N = len(data)

param_truth = DM([1e-2, 1e-1, 1e-3, 3.6e6, 1.224e7, 20, 20])
param_guess = DM([1e-2, 1e-1, 1e-3, 3.6e6, 1.224e7, 20, 20])
#scale = ca.vertcat(1e-1, 1e-1, 1e-1, 1e6, 1e7, 1e1, 1e1)
scale = ca.vertcat(1,1,1,1,1,1,1)

############ MODELING #####################
Ti  = MX.sym('Ti')
Te = MX.sym('Te')
phi_h  = MX.sym('phi_h')
phi_s  = MX.sym('phi_s')
Ta  = MX.sym('Ta')

states = vertcat(Ti,Te)
controls = vertcat(phi_h, phi_s, Ta)

phi_h_data = data.phi_h
phi_s_data = data.phi_s
Ta_data = data.Ta
# merge:
u_data = ca.horzcat(phi_h_data.values.T, phi_s_data.values.T, Ta_data.values.T)
y_data = data.Ti

#Ti0 = MX.sym("Ti0")
#Te0 = MX.sym("Te0")
Rie = MX.sym("Rie")
Ria = MX.sym("Ria")
Rea = MX.sym("Rea")
Ci = MX.sym("Ci")
Ce = MX.sym("Ce")
Ae = MX.sym("Ae")
Ai = MX.sym("Ai")

Y = MX.sym("Y")

#params = vertcat(Ti0, Te0, Rie, Ria, Rea, Ci, Ce, Ae, Ai)
params = vertcat(Rie, Ria, Rea, Ci, Ce, Ae, Ai)

ode = vertcat((Te - Ti)/(Rie*Ci) + phi_h*(1/Ce) + (Ta - Ti)/(Ria*Ci) + Ai*(phi_s/Ci), \
              (Ti - Te)/(Rie*Ce) + (Ta - Te)/(Rea*Ce) + Ae*(phi_s/Ce))


T = N/1/fs
h = T/N

"""
x  = MX.sym('x')
dx = MX.sym('dx')

# measurement, for quadrature:
Y = MX.sym("Y")
# meas noise, algebraic:
v = MX.sym("v")
# process noise:
#v1 = MX.sym("v1")
#v2 = MX.sym("v2")

# meas noise, now add constraint:
#sigma = MX.sym("sigma")

# control, fixed:
U  = MX.sym('U')

states = vertcat(x,dx)
controls = vertcat(U)

M = MX.sym("M")
c = MX.sym("c")
k = MX.sym("k")
k_NL = MX.sym("k_NL")

params = vertcat(M,c,k,k_NL)

#xdot = vertcat(dy + v1, (U-k_NL*y**3-k*y-c*dy)/M + v2)
#xdot = vertcat(dy, (U-k_NL*y**3-k*y-c*dy)/M)
ode = vertcat(dx, (U-k_NL*x**3-k*x-c*dx)/M)
"""

grid = np.array([])
for n in range(N):
  grid = np.append(grid, tau_root + n)

grid = grid*h

F = ca.integrator('F','collocation', \
                  {'x': states, \
                  'p': ca.vertcat(controls, params), \
                  'ode': ode}, \
                  {'tf': h, \
                  'grid': np.append(tau_root, 1,)*h})

# 'grid': np.append(tau_root, 1,)*h})

_y0 = DM([293.15, 293.15])
_y = np.array([])

for k in range(u_data.shape[0]):
    #print('u=[{}]'.format(u_data[k]))
    _y0 = F(x0=_y0, p=vertcat(u_data[k, :].T, param_truth))['xf']
    _y0 = _y0[:, -1]
    _y = np.append(_y, _y0)

fig, ax = plt.subplots(1,1)
#ax.plot(X_measured[0, :].full().T, color="k", linestyle="dashed")
ax.plot(_y[0:-1:2], color="b")
plt.show()


# recast X_measured as from collocation:
y_data = DM(_y[0:-1:2])

#L = vertcat((1/2)*v**2)
L = vertcat((1/2)*(Y - Ti)**2)
#R = vertcat(Y - y)

# constraint:
#G = Y - x - v
#G = Y - x - v

# Continuous time dynamics
#f = ca.Function('f', [x, params, U], [xdot], ['x', 'p', 'U'], ['xdot'])
f = ca.Function('f', [states, params, controls], [ode], ['x', 'p', 'U'], ['xdot'])
#l = ca.Function('l', [x, Y], [L1], ['x', 'Y'], ['L1'])
#l = ca.Function('l', [v], [L], ['v'], ['L'])
l = ca.Function('l', [states, Y], [L], ['states', 'Y'], ['L'])
#l = ca.Function('l', [sigma, noise], [L1, L2], ['sigma', 'noise'], ['L1', 'L2'])
#_g = ca.Function('g', [Y, states, v], [G], ['Y', 'states', 'v'], ['G'])
#r_func = ca.Function('l', [x, Y], [R], ['x', 'Y'], ['R'])

# Control discretization
#N = 20 # number of control intervals



# Start with an empty NLP
w1=[]
w2=[]
w3=[]
# initials:
w1_0 = []
w2_0 = []
w3_0 = []
####################
# split lbs and ubs:
lbw1 = []
ubw1 = []
lbw2 = []
ubw2 = []
lbw3 = []
ubw3 = []
#####################
J = 0
g=[]
lbg = []
ubg = []

X_phase = []

# For plotting x and u given w
x_plot = []
u_plot = []

# "Lift" initial conditions
Xn = Xnk = ca.MX.sym('X0', 2)
w1.append(Xn)
lbw1.append([-np.inf, -np.inf])
ubw1.append([np.inf, np.inf])
w1_0.append(list(np.array([y_data[k], y_data[k]]).flatten()))
x_plot.append(Xn)

X_phase.append(Xn)

# Formulate the NLP
for n in range(N-1):
    # controls, fixed
    # New NLP variable for the control
    #Uk = ca.MX.sym('U_' + str(k))
    #w.append(Uk)
    #lbw.append([-1])
    #ubw.append([1])
    #w0.append([0])
    #u_plot.append(Uk)

    for k in range(K):

      # State at collocation points
      Xkc = []
      Ykc = []
      Vkc = []
      
      for j in range(d):
          # path constraint for states:
          Xnkj = ca.MX.sym('X_'+ str(n) + '_' + str(k) + '_' + str(j), 2)
          Xkc.append(Xnkj)
          w1.append(Xnkj)
          lbw1.append([-np.inf, -np.inf])
          ubw1.append([np.inf,  np.inf])
          #w1_0.append([y_data[k], y_data[k]])
          w1_0.append(list(np.array([y_data[n], y_data[n]]).flatten()))
          
          # measurement:
          Ynkj = ca.MX.sym('Y_' + str(n) + '_' + str(k) + '_' + str(j), 1)
          Ykc.append(Ynkj)
          w2.append(Ynkj)
          # path constraints?
          lbw2.append(list(np.array([y_data[n]]).flatten()))
          ubw2.append(list(np.array([y_data[n]]).flatten()))
          w2_0.append(list(np.array([y_data[n]]).flatten()))
          
          # measurement noise:
          Vnkj = ca.MX.sym('V_' + str(n) + '_' + str(k) + '_' + str(j), 1)
          Vkc.append(Vnkj)
          w3.append(Vnkj)
          # path constraints?
          lbw3.append([-np.inf])
          ubw3.append([np.inf])
          w3_0.append([0])

      # Loop over collocation points
      Xnk_end = D[0]*Xnk
      for j in range(1,d+1):
        # Expression for the state derivative at the collocation point
        xp = C[0,j]*Xnk
        for r in range(d): xp = xp + C[r+1,j]*Xkc[r]

        # Append collocation equations
        fj = f(Xkc[j-1], params*scale, u_data[n, :].T)
        g.append(h*fj - xp)
        lbg.append([0, 0])
        ubg.append([0, 0])
        
        # enforce algebraic constraints at collocation points:
        #_gj = _g(Ykc[j-1], Xkc[j-1], Vkc[j-1])
        #g.append(_gj)
        #lbg.append([0])
        #ubg.append([0])

        # Add contribution to the end state
        Xnk_end = Xnk_end + D[j]*Xkc[j-1];

        # quadrature:
        #qj = l(Vkc[j-1])
        qj = l(Xkc[j-1], y_data[n])
        
        # Add contribution to quadrature function
        J = J + B[j]*qj*h

      # New NLP variable for state at end of interval
      
      # TODO: constraint for measurement at interval ends? 
      
      if k == K - 1:
            break
      
      Xnk = ca.MX.sym('X_'+ str(n) + '_' + str(k+1), 2)
      w1.append(Xnk)
      lbw1.append([-np.inf, -np.inf])
      ubw1.append([np.inf,  np.inf])
      w1_0.append(list(np.array([y_data[n], y_data[n]]).flatten()))
      x_plot.append(Xnk)

      # Add equality constraint
      g.append(Xnk_end-Xnk)
      lbg.append([0, 0])
      ubg.append([0, 0])
    
    Xn = Xnk = ca.MX.sym('X_'+ str(n+1), 2)
    w1.append(Xn)
    lbw1.append([-np.inf, -np.inf])
    ubw1.append([np.inf,  np.inf])
    w1_0.append(list(np.array([y_data[n+1], y_data[n+1]]).flatten()))
    x_plot.append(Xn)

    # Add equality constraint
    g.append(Xnk_end-Xn)
    lbg.append([0, 0])
    ubg.append([0, 0])
    
    X_phase.append(Xn)

# Concatenate vectors
w1 = ca.vertcat(*w1)
w2 = ca.vertcat(*w2)
w3 = ca.vertcat(*w3)
g = ca.vertcat(*g)
x_plot = ca.horzcat(*x_plot)
u_plot = ca.horzcat(*u_plot)

w0 = np.array([])
#for arr in (w1_0, w2_0, w3_0):
#      w0 = np.append(w0, np.concatenate(arr))

for arr in (w1_0, ):
      w0 = np.append(w0, np.concatenate(arr))

lbw = np.array([])
for arr in (lbw1,): # lbw2, lbw3):
      lbw = np.append(lbw, np.concatenate(arr))
lbw = np.append(lbw, [-np.inf, -np.inf, -np.inf, -np.inf, -np.inf, -np.inf, -np.inf])
      
ubw = np.array([])
for arr in (ubw1, ): # ubw2, ubw3):
      ubw = np.append(ubw, np.concatenate(arr))
ubw = np.append(ubw, [np.inf, np.inf, np.inf, np.inf, np.inf, np.inf, np.inf])
#w0 = np.concatenate(w1_0, w2_0, w3_0)
#lbw = np.concatenate(lbw1, lbw2, lbw3)
#ubw = np.concatenate(ubw1, ubw2, ubw3)
lbg = np.concatenate(lbg)
ubg = np.concatenate(ubg)


# Create an NLP solver
#prob = {'f': J, 'x': ca.vertcat(*w1, *w2, *w3, params), 'g': g}
#V = ca.vertcat(w1, w2, w3, params)
V = ca.vertcat(w1, params)
#V = ca.vertcat(*w1, *w2, *w3, params)

#obj = 0
#for i, x in enumerate(X_phase):
#      obj += (1/2)*(x[0] - y_data[i])*(x[0] - y_data[i])

prob = {'f': J, 'x': V, 'g': g}
solver = ca.nlpsol('solver', 'ipopt', prob, {"ipopt": {"linear_solver": "ma86"}})

#solver = gauss_newton(vertcat(*res), prob, V)

# Function to get x and u trajectories from w
#trajectories = ca.Function('trajectories', [w], [x_plot, u_plot], ['w'], ['x', 'u'])

# Solve the NLP
#w0_opt = np.zeros((1, ca.vertcat(*w1, *w2, *w3).shape[0]))
#w0_opt = np.zeros((1, ca.vertcat(*w1,*w4).shape[0]))

# TODO:
# careful init?
#yd = np.diff(y_data,axis=0)*fs
#X_guess = horzcat(y_data , vertcat(yd,yd[-1])).T;

#w0_opt = np.zeros((1, ca.vertcat(*w1, *w2, *w3).shape[0]))

# add params guess:
x0_opt = np.append(w0, (param_guess).full().T)

sol = solver(x0=x0_opt, lbx=lbw, ubx=ubw, lbg=0, ubg=0)
print(sol["x"][-7:]*scale)
#print(sol["x"][-4:])
#len_meas = ca.vertcat(*w4).shape[0]
len_noise = w3.shape[0]
len_meas = w2.shape[0]
len_state = w1.shape[0]
x_opt = sol["x"][:-7].full().T.reshape((states.shape[0], (N-1)*(d+1)*K + 1), order="F")
#x_opt = sol["x"][:-(4 + len_meas + len_noise)].full().T.reshape((states.shape[0], (N-1)*(d+1)*K + 1), order="F")
#meas_opt = sol["x"][len_state:-(4 + len_noise)].full().T.reshape((1, (N-1)*(d*K)), order="F")
#noise_opt = sol["x"][(len_state + len_meas):-4].full().T.reshape((1, (N-1)*(d*K)), order="F")
#y_opt = sol["x"][len_state:(len_state + len_meas)].full().T.reshape((1, (N-1)*(d+1) + 1), order="F")
#x_opt = sol["x"][:-(len_noise + len_sigma + 4)].full().T.reshape((x.shape[0], (N-1)*(d+1) + 1), order="F")
#v_opt = sol["x"][len_state:(len_state+len_noise)].full().T.reshape((noise.shape[0], (N-1)*d), order="F")
#sigma_opt = sol["x"][(len_state+len_noise):(len_state+len_noise+len_sigma)].full().T.reshape((sigma.shape[0], N), order="F")
#x_opt = sol["x"][:-4].full().T[0]
#x_opt, u_opt = trajectories(sol['x'])
#x_opt = x_opt.full() # to numpy array
#u_opt = u_opt.full() # to numpy array

# Plot the resulty_
#tgrid = np.linspace(0, T, N*(d+1)+1)

tgrid = np.array([])

tau_adj = tau_root/K

for n in range(N-1):
  for k in range(K):
    tgrid = np.append(tgrid, [n + k/K] + tau_adj)

tgrid = np.append(tgrid, [N-1])
tgrid = tgrid*(1/fs)

plt.figure(1)
plt.clf()

df = pd.DataFrame()
df["x"] = x_opt[0]
df["dx"] = x_opt[1]

df.index = tgrid

df["Y"] = np.nan
#df["v"] = np.nan


#df["v1"] = np.nan
#df["v2"] = np.nan
#df["sigma"] = np.nan

coll_count = 0
for ndx, dx in enumerate(df.index):
  if not ndx % ((d+1)*K):
    df["Y"].iloc[ndx] = y_data[int(ndx/((d+1)*K))] 
#    df["sigma"].iloc[ndx] = sigma_opt[0][int(ndx/(d+1))] 
#  else:
#    df["v1"].iloc[ndx] = v_opt[0][coll_count]
#    df["v2"].iloc[ndx] = v_opt[1][coll_count]
#    coll_count += 1

# noise and meas take values at collocation points ONLY
"""
coll_count = 0
for ndx, dx in enumerate(df.index):
  if ndx % (d+1):
    df["v"].iloc[ndx] = noise_opt[0][coll_count]
    df["Y"].iloc[ndx] = meas_opt[0][coll_count]
    coll_count += 1

#for ndx, dx in enumerate(df.index):
#  if not ndx % (d+1):
#    df["Y"].iloc[ndx] = y_data[int(ndx/(d+1))] 

"""

#df["Y"] = df["Y"].ffill()

t = df.index.values[0:-1:(d+1)*K]

fig, ax = plt.subplots(1,1)

ax.plot(t, df.x.iloc[0:-1:(d+1)*K], color="b")
ax.plot(t, df.Y.iloc[0:-1:(d+1)*K], color="k", linestyle="dashed")
#df.Y.iloc[0:-1].plot(ax=ax, color="k", linestyle="dashed")
#ax.plot(df.index[0:-1:3], meas_opt[0][0:-1:2], color="k", linestyle="dashed")

#df["g_check"] = df["Y"] - df["y"]

plt.show()


"""
  
# Formulate the NLP
for k in range(N-1):
    # New NLP variable for the control
    #Uk = ca.MX.sym('U_' + str(k))
    #w.append(Uk)
    #lbw.append([-1])
    #ubw.append([1])
    #w0.append([0])
    #u_plot.append(Uk)

    # State at collocation points
    Xc = []
    # measurement at coll
    Yc = []
    
    # process noise at collocation points:
    Vc = []
    #Yc = []
    for j in range(d):
        Xkj = ca.MX.sym('X_'+str(k)+'_'+str(j), 2)
        Ykj = ca.MX.sym('Y_'+str(k)+'_'+str(j), 1)
        #Vkj = ca.MX.sym('V_'+str(k)+'_'+str(j), 2)
        #Ykj = ca.MX.sym('Y_'+str(k)+'_'+str(j), 2)
        Xc.append(Xkj)
        Yc.append(Ykj)
        #Vc.append(Vkj)
        #Yc.append(Ykj)
        w1.append(Xkj)
        w4.append(Ykj)
        #w2.append(Vkj)
        # note: algebraic state not decision variable
        
        #w.append(Xkj)
        #lbw.append([-0.25, -np.inf])
        #ubw.append([np.inf,  np.inf])
        #w0.append([0, 0])

    # Loop over collocation points
    
    Xk_end = D[0]*Xk
    Yk_end = D[0]*Yk
    #Yk_end = 0
    #Vk_end = D[0]*Vk
    #J += l(Xk, y_data[k])
    
    # decision variable / meas noise, on phase boundary:
    sigma_k = ca.MX.sym('sigma_'+str(k), 1)
    w3.append(sigma_k)
    
    #gj = _g(Xk, y_data[k], sigma_k)
    #g.append(gj)
    #lbg.append([0])
    #ubg.append([0])
  
    for j in range(1,d+1):
       # Expression for the state derivative at the collocation point
       xp = C[0,j]*Xk
       for r in range(d): xp = xp + C[r+1,j]*Xc[r]

       yp = C[0,j]*Yk
       for r in range(d): yp = yp + C[r+1,j]*Yc[r]
      
       # Append collocation equations
       #fj = f(Xc[j-1], params*scale, u_data[k], Vc[j-1])
       #fj = f(Xc[j-1], params*scale, u_data[k], Vc[j-1])
       fj = f(Xc[j-1], params*scale, u_data[k])
       #q1, q2 = l(Xc[j-1], y_data[k], Vc[j-1])
       #qj = l(Xc[j-1], Yc[j-1])
       #qj = (1/2)*(Xc[j-1][0] - Yc[j-1])*(Xc[j-1][0] - Yc[j-1])
       qj = l(Xc[j-1], y_data[k])
       #res.append(r_func(Xc[j-1], y_data[k]))
       #q1, q2 = l(sigma_k, Vc[j-1])
       #gj = _g()
       #gj = _g()
       g.append(h*fj - xp)
       # derivative of 
       #g.append(h*fj[0] - yp)
       #g.append(0 - yp)
       lbg.append([0, 0])
       ubg.append([0, 0])

       # Add contribution to the end state
       Xk_end = Xk_end + D[j]*Xc[j-1]
       Yk_end = Yk_end + D[j]*Yc[j-1]
       #Vk_end = Vk_end + D[j]*Vc[j-1]

       # Add contribution to quadrature function
       #J = J + B[j]*qj*h
       
       # reference tracking:
       #J = J + B[j]*q1*h
       #J = J + B[j]*q2*h
       #J = J + B[j]*qj*h
       # noise minimization:
       #J = J + B[j]*(Vc[j-1]**2)*h

    #J = J + l(Xk, y_data[k])

    # objective on finite element boundary:

    # New NLP variable for state at end of interval
    #vk = ca.MX.sym('v_' + str(k), 1)
    Xk = ca.MX.sym('X_' + str(k+1), 2)
    Yk = ca.MX.sym('Y_' + str(k+1), 1)
    w1.append(Xk)
    w4.append(Yk)
    
    #Vk = ca.MX.sym('V_' + str(k+1), 2)
    #w2.append(Vk)
    #.append(vk)
    #lbw.append([-0.25, -np.inf])
    #ubw.append([np.inf,  np.inf])
    #w0.append([0, 0])
    x_plot.append(Xk)

    # Add equality constraint
    g.append(Xk_end-Xk)
    #g.append(Yk_end-Yk)
    #g.append(Yk - y_data[k+1])
    #g.append(Xk[0] - Yk)
    J = J + l(Xk, y_data[k+1])
    #Yk = ca.MX.sym('Y_' + str(k+1), 1)
    
    #g.append(Vk_end-Vk)
    #g.append(_g(Xk, y_data[k], vk))
    #lbg.append([0, 0, 0])
    #ubg.append([0, 0, 0])
    lbg.append([0, 0, 0])
    ubg.append([0, 0, 0])
    #lbg.append([0, 0, 0, 0])
    #ubg.append([0, 0, 0, 0])
    
    #lbg.append([0, 0, 0])
    #ubg.append([0, 0, 0])
    
    #lbg.append([0, 0, 0, 0])
    #ubg.append([0, 0, 0, 0])
    
    
#else:
    #g.append(Y0 - y_data[0])
    #lbg[-1].append([0])
    #ubg[-1].append([0])
    
    #for j in range(0,d+1):   
    #   J = J + B[j]*h*(1/2)*vk**2
       
    # add noise contrib to objective
    #J += (1/2)*vk**2

# terminal sigma:
sigma_k = ca.MX.sym('sigma_'+str(k+1), 1)
w3.append(sigma_k)

  """