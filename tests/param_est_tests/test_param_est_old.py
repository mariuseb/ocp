#from ast import Param
from ocp.param_est import ParameterEstimation
import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd

def generate_data(cfg_path, x0, true_params):
    """
    Generate experiment data.
    """

    # simulation settings:
    dt = 0.0016390755613833797
    N = 100

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

    X = Integrator.simulate(x0, u_data, true_params)
    # take out last element:
    y_data = X[0,:-1].T

    # data:
    df = pd.DataFrame()
    df["u1"] = np.array(u_data).flatten()
    df["y1"] = np.array(y_data).flatten()
    df.index = np.arange(0, dt*N, dt)

    # return df:
    return df

if __name__ == "__main__":
    
    cfg_path = "param_est_config_ms.json"
    
    x0 = ca.DM([0,0])    
    true_params = ca.DM([5.625e-6,2.3e-4,1,4.69])
    y_data = generate_data(cfg_path, x0, true_params)
    
    #y_data = y_data.iloc[0:-1]
    
    param_guess = ca.DM([5e-6,2e-4,1,5])
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    with ParameterEstimation(cfg_path, y_data, param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        sol, params  = param_est.solve(param_guess, ca.veccat(Q, R))
        
        scale = param_est.get_scale(param_guess)
        
        p_start, p_stop = param_est.nlp_parser.vars["p"]["range"]["a"], param_est.nlp_parser.vars["p"]["range"]["b"]
        
        # parameters:
        p_sol = params*scale
        
        print(p_sol)
        assert(ca.norm_inf(p_sol-true_params)<1e-8)