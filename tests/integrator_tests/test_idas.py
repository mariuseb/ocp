import casadi as ca
import json
from ocp.dae import DAE
from ocp.integrators import RK4, IRK, idas, Cvodes
import pandas as pd
import os
import numpy as np
import matplotlib.pyplot as plt
from ocp.tests.utils import get_opt_config_path

"""
NOTE:
The casadi built-in integrator seems to
adjust finite elements based on order.
Need order > 1 or n (finite elems) very high to match
performance.
"""

if __name__ == "__main__":

  # order, method:
  order = 2
  method = "radau"

  path = os.path.join(get_opt_config_path(), "param_est_config_coll.json")
  
  with open(path) as file:
      config = json.load(file)

  model = config["model"]
  #dt = config["dt"]
  dt = 0.0016390755613833797
  #N = config["N"]
  N = 100
  #n_steps = config["n_steps"]

  # generate some data:
  np.random.seed(0)
  u_data = ca.DM(0.1*np.random.random(N))

  # create a dae
  dae = DAE(model)    
  # integrator:
  cfg = config["integrator"]
  cfg["dt"] = dt
  cfg["tgrid"] = [dt]
  #Coll = IRK(dae, **cfg)
  IDA = idas(dae, **cfg)
  #IDA = Cvodes(dae, **cfg)

  # true parameters:
  x0 = ca.DM([0,0])
  param_truth = ca.DM([5.625e-6,2.3e-4,1,4.69])

  #X = Coll.simulate(x0, u_data, param_truth)
  X = x0
  res = np.array([])
  for n in range(N):
    X = IDA.one_sample(x0=X, z0=0, u=u_data[n], p=param_truth)["xf"]
    #xf = Coll.one_sample(X, u_data[n], param_truth[0], param_truth[1], param_truth[2], param_truth[3])
    #X = xf[0]
    res = np.append(res, X[0])

  # measurement data
  #y_data = X[0,:].T
  y_data = res
  ###################################################

  df = pd.DataFrame()
  #dt = np.arange(0, config["dt"]*len(df), config["dt"])
  #df["u1"] = np.array(u_data).flatten()
  df["y_own"] = np.array(y_data).flatten()
  df.index = np.arange(0, cfg["dt"]*N, cfg["dt"])

  ##################### RK4 ##################################
  
  RK4 = RK4(dae, **cfg)

  # true parameters:
  param_truth = ca.DM([5.625e-6,2.3e-4,1,4.69])
  #X = RK4.simulate(x0, u_data, param_truth)
  sim_res = np.array([])
  X = x0
  for n in range(N):
    #X = RK4.one_sample(x0=X, z0=0, u=u_data[n], p=param_truth)["xf"]
    X = RK4.one_sample(X, 0, u_data[n], param_truth, 0, 0)
    #xf = Coll.one_sample(X, u_data[n], param_truth[0], param_truth[1], param_truth[2], param_truth[3])
    #X = xf[0]
    sim_res = np.append(sim_res, X[0])
  
  # measurement data
  Y = X[0,:].T
  
  #df["y_builtin"] = Y.full()
  df["y_builtin"] = sim_res
  ax = df[["y_builtin"]].plot()
  df[["y_own"]].plot(ax=ax, linestyle="dashed")
  plt.show()
  
  ##################### built-in #############################

  """
  order = 1
  #method = "legendre"
  #grid = np.append(0, ca.collocation_points(order, method))*dt
  grid = np.arange(0, (N)*dt, dt)

  x = []
  u = []
  p = []
  for name in dae.dae.x():
        x.append(dae.dae.var(name))
  for name in dae.dae.u():
        u.append(dae.dae.var(name))
  for name in dae.dae.p():
        p.append(dae.dae.var(name))


  Coll = ca.integrator('F','cvodes',
                      {'x': ca.vertcat(*x),
                      'p': ca.vertcat(*p), 
                      'u': ca.vertcat(*u),
                      'ode': ca.vertcat(*dae.dae.ode())},
                      0,
                      grid[1:],
                      {"abstol": 1E-5})
                      #{"collocation_scheme": "radau",
                      # "interpolation_order": 1,
                      # "number_of_finite_elements": 1})
  
  #Coll.print_options()

  p_coll = ca.vertcat(ca.repmat(param_truth, 1, N-1))
  #coll_simulate = Coll.mapaccum(N)

  #args = (x0, u_data.T, p_coll)

  #sim_res = Coll(args, 0, grid[1:])
  sim_res = Coll(x0=x0, p=p_coll, u=u_data[:-1])

  x_data_coll = np.array(sim_res["xf"])
  #y_data_coll = x_data_coll[0,:]
  #x1_data_coll = x_data_coll[0]
  y_data_coll = x_data_coll[0]
  y_data_coll = y_data_coll[(order-1)::order]
  
  df["y_builtin"] = y_data_coll
  df[["y_builtin", "y_own"]].plot()
  plt.show()
  """

  # check that own collocation integrator yields sane result.

