#from ast import Param
from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from ocp.tests.utils import get_opt_config_path
from ocp.functions import functions
from ocp.integrators import idas, IRK
from ocp.dae import DAE
import os
import ocp

pd.set_option('display.max_rows', 500)
pd.set_option('display.max_columns', 500)
pd.set_option('display.width', 1000)

if __name__ == "__main__":
    
    
    cfg_path = os.path.join(get_opt_config_path(),
                            "2R2C_MPC_func.json")
    cfg_path_idas = os.path.join(get_opt_config_path(),
                                 "2R2C_MPC_map_test.json")
    data_path = os.path.join(ocp.__path__[0],
                             "tests",
                             "data",
                             "MPC_open_loop_test.csv")
    
    data = pd.read_csv(data_path, index_col=0)
    #data = data[0:3]
    N = len(data)
    dt = data.index[1] - data.index[0]
    
    params = ca.DM([6.987636e-04,
                    3.184517e-03,
                    5.407161e+06,
                    4.533857e+07,
                    2.767623e+01,
                    3.915722e+01])
    x0 = np.array([293.15, 292.15])
    z0 = np.array([0])
    lbx = np.array([290.15, 10]*(N-1))
    ubx = np.array([296.15, 500]*(N-1))
    
    # first, check whether we can simulate the system
    with open(cfg_path) as file:
      config = json.load(file)
    
    model = config["model"]
    model.pop("alg")
    model.pop("z")
    #dt = config["dt"]
    dt = 900
    #N = config["N"]
    N = 100
    #n_steps = config["n_steps"]

    # generate some data:
    np.random.seed(0)
    u_data = 293.15 + ca.DM(50*np.random.random(N))

    model["functions"] = functions
    # create a dae
    dae = DAE(model)    
    # integrator:
    cfg = config["integrator"]
    cfg.pop("name")
    cfg["dt"] = 900
    #Coll = IRK(dae, **cfg)
    IDA = idas(dae, **cfg)
    
    X = x0
    
    #z0 = functions["regNonZeroPower"](params[5]*(u_data[0]-x0[0]), 1.24, 0.05)
    reg_nonzero = functions["regNonZeroPower"]
    
    UA = params[5]
    z0 = UA*reg_nonzero((u_data[0] - x0[0]), 1.24, 0.05)
    Z = np.array(z0)
    
    res = pd.DataFrame(columns=["Ti", "Te", "Ph", "Tsup"])
    for n in range(N):
        Fk = IDA.one_sample(x0=X, u=u_data[n], p=ca.vertcat(params, data[dae.r_names].iloc[n]))
        #Fk = IDA.one_sample(x0=X, z0=Z, u=u_data[n], p=ca.vertcat(params, data[dae.r_names].iloc[n]))
        #Fk = IDA.one_sample(x0=X, z0=Z, u=u_data[n], p=ca.vertcat(params, data[dae.r_names].iloc[n]))
        #X = IDA.one_sample(X, 0, u_data[n], param_truth, 0, 0)["xf"]
        #xf = Coll.one_sample(X, u_data[n], param_truth[0], param_truth[1], param_truth[2], param_truth[3])
        X = Fk["xf"]
        Z = Fk["zf"]
        #res = np.append(res, X[0])
        #res.loc[n] = 0
        Ph = UA*reg_nonzero((u_data[n] - X[0]), 1.24, 0.05)
        vals = np.concatenate((np.array(X).flatten(), Ph.full().flatten(), np.array(u_data[n]).flatten()))
        res.loc[n] = vals
        #res[["Ti", "Te"]].loc[n] = np.array(X).flatten()
        #res[["Ph"]].loc[n] = Ph.full().flatten()
        #res[["Tsup"]].loc[n] = np.array(u_data[n]).flatten()
        
    ######################## HERE, test IRK for DAE systems ##########################
    
    with open(cfg_path) as file:
      config = json.load(file)
    
    model = config["model"]
    #model.pop("alg")
    #model.pop("z")
    dt = 900
    #N = config["N"]
    N = 100
    #n_steps = config["n_steps"]

    # generate some data:
    np.random.seed(0)
    u_data = 293.15 + ca.DM(50*np.random.random(N))

    model["functions"] = functions
    # create a dae
    dae = DAE(model)    
    # integrator:
    cfg = config["integrator"]
    cfg.pop("name")
    cfg["degree"] = 3
    cfg["method"] = "radau"
    cfg["n_steps"] = 1
    cfg["dt"] = 900
    Coll = IRK(dae, **cfg)
    #IDA = idas(dae, **cfg)
    
    X = x0
    
    #z0 = functions["regNonZeroPower"](params[5]*(u_data[0]-x0[0]), 1.24, 0.05)
    reg_nonzero = functions["regNonZeroPower"]
    
    UA = params[5]
    #z0 = UA*reg_nonzero((u_data[0] - x0[0]), 1.24, 0.05)
    #Z = np.array([z0]*3).flatten()
    
    res_irk = pd.DataFrame(columns=["Ti", "Te", "Ph", "Ph_rf", "Tsup"])
    for n in range(N):
        #Fk = IDA.one_sample(x0=X, u=u_data[n], p=ca.vertcat(params, data[dae.r_names].iloc[n]))
        #Fk = Coll.one_sample(x0=X, z0=Z, u=u_data[n], p=ca.vertcat(params, data[dae.r_names].iloc[n]))
        #z0 = UA*reg_nonzero((u_data[n] - X[0]), 1.24, 0.05)
        #Z = np.array([z0]*3).flatten()
        #Fk = Coll.one_sample(x=X, z=Z, u=u_data[n], p=params, r=data[dae.r_names].iloc[n], s=0)
        Fk = Coll.one_sample(x=X, z=0, u=u_data[n], p=params, r=data[dae.r_names].iloc[n], s=0)
        Zk_minus_1 = Coll.G(z=0, x=X, u=u_data[n], p=params, r=data[dae.r_names].iloc[n], v=0)
        #Fk = IDA.one_sample(x0=X, z0=Z, u=u_data[n], p=ca.vertcat(params, data[dae.r_names].iloc[n]))
        #X = IDA.one_sample(X, 0, u_data[n], param_truth, 0, 0)["xf"]
        #xf = Coll.one_sample(X, u_data[n], param_truth[0], param_truth[1], param_truth[2], param_truth[3])
        X = Fk["xf"]
        # eventually, report Ph:
        #Z = Fk["zf"]
        #res = np.append(res, X[0])
        #res.loc[n] = 0
        #vals = np.concatenate((np.array(X).flatten(), np.array(u_data[n]).flatten()))
        Ph = UA*reg_nonzero((u_data[n] - X[0]), 1.24, 0.05)
        vals = np.concatenate((np.array(X).flatten(), Ph.full().flatten(), Zk_minus_1["g"].full().flatten(), np.array(u_data[n]).flatten()))
        res_irk.loc[n] = vals

    
    # comparison:
    ax = res[["Ti"]].plot(color="r")
    res_irk[["Ti"]].plot(color="b", ax=ax, linestyle="dashed")
    plt.show()
    
    ax = res_irk[["Ph"]].plot(color="r")
    res_irk[["Ph_rf"]].plot(color="b", ax=ax, linestyle="dashed")
    plt.show()


    # measurement data
    #y_data = X[0,:].T
    y_data = res
    
    mpc_map = MPC(
              functions=functions,
              config=cfg_path,
              N=N,
              dt=dt
              ) # to remove, replace with N
    

    
    sol_map, u, x = mpc_map.solve(
                         data,
                         x0=x0,
                         lbx=lbx,
                         ubx=ubx,
                         params=params
                         )

    # here: calculate Ph as from radiator model:
    ax = sol_map["Ti"].plot(color="grey")
    
    """
    mpc = MPC(
              config=cfg_path_idas,
              N=N,
              dt=dt
              ) # to remove, replace with N
    
    sol, u, x = mpc.solve(
                         data,
                         x0=x0,
                         lbx=lbx,
                         ubx=ubx,
                         params=params
                         )

    ax = sol["Ti"].plot(color="grey")
    """    