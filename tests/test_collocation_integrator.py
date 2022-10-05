from casadi import *
import json
from dae import DAE
from integrators import RungeKutta4, Collocation
import pandas as pd
import os
import numpy
import matplotlib.pyplot as plt

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
  Coll = Collocation(dt, dae, order, n=3, method=method)

  # true parameters:
  x0 = DM([0,0])
  param_truth = DM([5.625e-6,2.3e-4,1,4.69])

  #X = Coll.simulate(x0, u_data, param_truth)
  X = x0
  res = np.array([])
  for n in range(N):
    X = Coll.one_sample(X, vertcat(u_data[n], param_truth))
    #xf = Coll.one_sample(X, u_data[n], param_truth[0], param_truth[1], param_truth[2], param_truth[3])
    #X = xf[0]
    res = np.append(res, X[0])

  # measurement data
  #y_data = X[0,:].T
  y_data = res
  ###################################################

  df = pd.DataFrame()
  #dt = np.arange(0, config["dt"]*len(df), config["dt"])
  df["u1"] = np.array(u_data).flatten()
  df["y_own"] = np.array(y_data).flatten()
  df.index = np.arange(0, config["dt"]*N, config["dt"])

  ##################### built-in #############################

  #order = 2
  #method = "legendre"
  grid = numpy.append(0, collocation_points(order, method))*dt

  Coll = integrator('F','collocation',
                    {'x':vertcat(*dae.dae.x),
                    'p':vertcat(*dae.dae.u, *dae.dae.p), 
                    'ode': vertcat(*dae.dae.ode)},
                    {'tf':dt,
                    'grid':grid})

  p_coll = vertcat(u_data.T, repmat(param_truth, 1, N))
  coll_simulate = Coll.mapaccum(N)

  sim_res = coll_simulate(x0=x0, p=p_coll)

  x_data_coll = np.array(sim_res["xf"])
  #y_data_coll = x_data_coll[0,:]
  #x1_data_coll = x_data_coll[0]
  y_data_coll = x_data_coll[0]
  y_data_coll = y_data_coll[(order-1)::order]

  df["y_builtin"] = y_data_coll

  df[["y_builtin", "y_own"]].plot()
  plt.show()

  # check that own collocation integrator yields sane result.

