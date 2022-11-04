from casadi import *
import json
from dae import DAE
from integrators import RungeKutta4, IRK
import pandas as pd
import os
import numpy
import subprocess
import time
import pprint
"""
Test simple parameter identification problem
with collocation-based multiple shooting.

Handling of quadrature:
  - take X at shooting gaps
"""

########################## SIMULATE ####################

# collocation settings:
order = 2
method = "legendre"

with open("param_est_config_ms.json", "r") as file:
    config = json.load(file)
    
model = config["model"]
#dt = config["dt"]
#N = config["N"]
dt = 0.0016390755613833797
N = 100
n_steps = config["integrator"]["n_steps"]

# generate some data:
numpy.random.seed(0)
u_data = DM(0.1*numpy.random.random(N))

# create a dae
dae = DAE(model)    
# integrator:
#Coll = IRK(dt, dae, order, n=3, method=method)
int_cfg = config["integrator"]
int_cfg["dt"] = dt
Coll = IRK(dae, **int_cfg)

# true parameters:
x0 = DM([0,0])
param_truth = DM([5.625e-6,2.3e-4,1,4.69])
X = Coll.simulate(x0, u_data, param_truth)

# measurement data
y_data = X[0,:].T
###################################################

df = pd.DataFrame()
#dt = np.arange(0, config["dt"]*len(df), config["dt"])
df["u1"] = np.array(u_data).flatten()
df["y1"] = np.array(y_data).flatten()
df.index = np.arange(0, dt*N, dt)


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
  opt = {
    "verbose": 0,
    "ipopt.linear_solver": "ma27",
    "ipopt.max_iter": 1000,
    "ipopt.print_level": 5,
    "ipopt.ma57_pre_alloc": 10,
    #"ipopt.hessian_approximation": "limited-memory",
    "ipopt.ma57_automatic_scaling" : "yes"}
  
  hessLag = Function('nlp_hess_l',{'x':V,'lam_f':sigma, 'hess_gamma_x_x':sigma*H},
                     ['x','p','lam_f','lam_g'], ['hess_gamma_x_x'],
                     dict(jit=with_jit, compiler=compiler))
  
  return nlpsol("solver", \
                "ipopt", \
                nlp, \
                dict(hess_lag=hessLag, \
                jit=with_jit, \
                compiler=compiler, \
                **opt),
                )
########################################################

# multiple-shooting: 

with_jit = True
fs = 1/dt

# All states become decision variables
X = MX.sym("X", 2, N)
# All process noise -"-
W = MX.sym("W", 2, N)
# measurement noise:
v = MX.sym("v", N)

# create an algebraic variable corresponding to the measurement:
scale = vertcat(1e-6,1e-4,1,1)
param_guess = DM([5,2,1,5])
params = vertcat(*dae.dae.p)

#p_coll_symbolic = vertcat(u_data.T, scale*repmat(params, 1, N), W)
coll_one_step = Coll.one_sample.map(N, "openmp")
#Xn = coll_one_step(x0=X, p=p_coll_symbolic)["xf"]
Xn = coll_one_step(x0=X, u=u_data.T,  p=scale*repmat(params, 1, N), w=W)["xf"]
#Xn = irk_map["xf"]
#Vn = irk_map["zf"]
#Xn = coll_mapped["xf"]
#Xn = coll_mapped["xf"]
#e_coll = coll_mapped["qf"].T

#Xn.generate_dependencies("icfn.c")



# gaps at sfinite elements:
#gaps = Xn[:,:-1]-X[:,1:]
#gaps = Xn[:,(order-1):-1:order]-X[:,1:]

#e = y_data - Xn[0,(order-1)::order].T


# process noise: add to gaps
#w = MX.sym("v", 2, N-1)

#v = MX.sym("v", N)
X_gaps = Xn[:,:-1]-X[:,1:] # - w # add 'w' to gap
#V_gaps = Vn[:,:-1]-v[:,1:]
#V_gaps = Vn.T - v
# how to get this from h?
#e_gaps = y_data - Xn[0,:].T - v

h_map = Coll.h.map(N, "openmp")

h_gaps = h_map(x=Xn, y=y_data, v=v)["h"]

#h_gaps = Coll.g(x=Xn, y=y_data, v=v)

# try to generate code for the N-step integrator:
#C = CodeGenerator("gen.c")
#C.add(coll_one_step)
#C.add(h_map)
#C.generate()


# objective:
#e = y_data - Xn[0,:].T;

g = vertcat(vec(X_gaps), vec(h_gaps))

# add v, w as decision variables:
#V = veccat(params, X, v, W)
V = veccat(X, params, W, v)

# residual for v: define dummy entry to match with W:
#dummy_v = MX.zeros(N)

#v_tot = horzcat(v, dummy_v).T

# now we can define residual as:
#residual = W + v_tot

nlp = {'x': V, 'f': 0.5*dot(v,v) + 0.5*dot(W, W), 'g': g}

with open('script.txt', 'wt') as out:
    pp = pprint.PrettyPrinter(indent=4,stream=out)
    pp.pprint(nlp)

# Multipleshooting allows for careful initialization
yd = np.diff(y_data,axis=0)*fs
X_guess = horzcat(y_data , vertcat(yd, yd[-1])).T
X_coll_guess = horzcat(y_data , vertcat(yd, yd[-1])).T

#x0 = veccat(param_guess,X_guess,X_coll_guess)
# add zeros as init for v,w
#x0 = veccat(param_guess,X_guess, repmat(DM(0), 1, N), repmat(DM(0), 2, N))
x0 = veccat(X_guess, param_guess, repmat(DM(0), 2, N), repmat(DM(0), 1, N))

#solver = gauss_newton(residual, nlp, V)

solver = nlpsol("solver","ipopt", nlp, dict(jit=True, compiler="shell"))

"""
gen_opts = {}
solver.generate_dependencies("nlp.c", gen_opts)
start = time.time()
subprocess.Popen("gcc -fPIC -shared -O1 nlp.c -o nlp.so", shell=True).wait()
print("Compile time was: {}".format(time.time()-start))
"""

sol = solver(x0=x0,lbg=0,ubg=0)

print(sol["x"][200:204]*scale)

assert(norm_inf(sol["x"][:4]*scale-param_truth)<1e-8)
