from ast import Param
from param_est import ParameterEstimation
import numpy as np
import json
import casadi as ca
import dae
import integrators
import pandas as pd

def generate_data(cfg_path, x0, true_params):
    """
    Generate experiment data.
    """

    # simulation settings:
    dt = 0.0016390755613833797
    N = 10000

    with open(cfg_path, "r") as file:
        config = json.load(file)
        
    model_cfg = config.pop("model")
    # create a dae
    model = dae.DAE(model_cfg)    

    # set up integrator
    int_cfg = config.pop("integrator")
    name = int_cfg.pop("name")
    int_cfg["dt"] = dt

    Integrator = getattr(integrators, name)(model, **int_cfg)

    # generate some data:
    np.random.seed(0)
    u_data = ca.DM(0.1*np.random.random(N))

    y_data = Integrator.simulate(x0, u_data, true_params)
    #y_data = X[0,:].T

    # data:
    df = pd.DataFrame()
    df["u1"] = np.array(u_data).flatten()
    df["y1"] = np.array(y_data[0, :]).flatten()
    df["y2"] = np.array(y_data[1, :]).flatten()
    df.index = np.arange(0, dt*N, dt)

    # return df:
    return df

if __name__ == "__main__":
    
    cfg_path = "param_est_config_ms_double.json"
    
    x0 = ca.DM([0,0])    
    true_params = ca.DM([5.625e-6,2.3e-4,1,4.69])
    y_data = generate_data(cfg_path, x0, true_params)
    
    y_data = y_data.iloc[0:100]
    
    param_guess = ca.DM([5e-6,2e-4,1,5])
    param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    sol = param_est.solve(param_guess)
    
    scale = param_est.get_scale(param_guess)
    print(sol["x"][:4]*scale)
    assert(ca.norm_inf(sol["x"][:4]*scale-true_params)<1e-8)