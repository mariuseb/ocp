#%% 
import pandas as pd
import numpy as np

def prepare_data(data_path, rule="15min"):
    data = pd.read_csv(data_path, index_col=0)
    y_map = {
        "Ti_219": "Ti",
        "Prad_219": "Prad",
        "rad_219": "rad_219",
        "reaRadTRet219_y": "Tret",
        "reaRadTSup219_y": "Tsup",
        "reaRadFlow219_y": "rad_flo",
        "weatherStation_reaWeaTDryBul_y": "Ta",
        "weatherStation_reaWeaHGloHor_y": "phi_s"
        
    }
    y_data = data.rename(columns=y_map)[
            list(y_map.values())
        ]
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["rad_flo"]
    y_data["y3"] = y_data["Prad"]
    y_data["y4"] = y_data["Tret"]
    y_data["y5"] = y_data["Tsup"]
    y_data["m_flow_bool"] = ((y_data["rad_flo"].round(4) > 0)).astype(int) + 1e-2
    #y_data["m_flow_bool"] = 1
    y_data.index = pd.to_timedelta(y_data.index)
    
    y_data = y_data.resample(rule=rule).mean()
    
    y_data["dt_index"] = y_data.index
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = range(len(y_data.index))
    y_data.index *= dt
    #y_data = y_data[4*24:2*4*24]
    #y_data = y_data[-96:]
    N = len(y_data)

    return y_data, N, dt
    


def prepare_est(
        data,
        A=66.7,
        load_optimal_rad_params=False,
        load_optimal_env_params=False,
        load_optimal_traj=False
    ):
    kwargs = {
    
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [1],
        "u_nom_b ": [0],
        "r_nom": [12,2.5E3,1],
        "r_nom_b": [289.15,0,0],
        "z_nom": [1e-1,12,2.5E3],
        "z_nom_b": [0,289.15,0],
        "y_nom": [12,1e-1,2.5E3,12,12],
        "y_nom_b": [289.15,0,0,289.15,289.15],
        #"slack": True
        "slack": False
    }
    if load_optimal_env_params:
        params = pd.read_csv("envelope_model_alt_rad_first.csv", index_col=0)
        param_guess = dict()
        for k in params.index:
            param_guess[k] = {
                "init": float(params.loc[k]),
                "lb": float(params.loc[k]),
                "ub": float(params.loc[k])
            }
    else: 
        param_guess = {
                    "Rie": 
                    {
                        "init": 1e-2
                    },
                    "Rea":
                    {
                        "init": 1e-1
                    },
                    "Ria":
                    {
                        "init": 1e-1
                    },
                    "Ci":
                    {
                        "init": 1e6
                    },
                    "Ce":
                    {
                        "init": 1e6
                    },
                    "Ai":
                    {
                        "init": 10
                    }
        }
        priors = {
            "Rie": 0.250/A, # m²K / W 
            "Rea": 2.250/A, # m²K / W 
            "Ci": 9.50*3600*A, # Wh / m²K
            "Ce": 112*3600*A, # Wh / m²K
            "Ai": 2, # m²
            }
        
        for name, value in priors.items():
            param_guess[name]["init"] = value 
            if not name.startswith("alpha"):
                param_guess[name]["lb"] = value*1E-3 
                param_guess[name]["ub"] = value*1E3 
            else:
                param_guess[name]["lb"] = value
                param_guess[name]["ub"] = value
            
    if load_optimal_rad_params:
        params_rad = pd.read_csv("rad_model_PRBS.csv", index_col=0)
        param_guess_rad = dict()
        for k in params_rad.index:
            param_guess_rad[k] = {
                "init": float(params_rad.loc[k]),
                "lb": float(params_rad.loc[k]),
                "ub": float(params_rad.loc[k])
            }
            
    else:
        param_guess_rad = {
                        "n": 
                        {
                            "init": 1.5,
                            "ub": 3.0,
                            "lb": 0.1
                        },
                        "rad_flo_nom":
                        {
                            "init": 0.01,
                            "lb": 0.09, 
                            "ub": 0.15
                        },
                        "cp_water":
                        {
                            "init": 4200,
                            "lb": 4199, 
                            "ub": 4201
                        },
                        "Csup":
                        {
                            "init": 1E5,
                        },
                        "Rsup":
                        {
                            "init": 1e-3,
                        },
                        "Risup":
                        {
                            "init": 1e-3,
                        },
                        "Riret":
                        {
                            "init": 1e-3,
                        },
                        "Rret":
                        {
                            "init": 1e-3,
                        },
                        "Cret":
                        {
                            "init": 1E4,
                        },
                        "Tsup_offset":
                        {
                            "init": 1,
                            "lb": -5, 
                            "ub": 20
                        },
                        "Tsupret_offset":
                        {
                            "init": 1,
                            "lb": -5, 
                            "ub": 20
                        },
                        "Tret_offset":
                        {
                            "init": 1,
                            "lb": -5, 
                            "ub": 20
                        },
                        "Tset_sup_a":
                        {
                            "init": 2/3,
                            "lb": 0.1,
                            "ub": 10,
                        },
                        "Tset_sup_b":
                        {
                            "init": 273.15 + 50,
                            "lb": 273.15 + 40,
                            "ub": 273.15 + 60,
                        },
                        "Ta_dim":
                        {
                            "init": 273.15 - 20,
                            "lb": 273.15 - 20,
                            "ub": 273.15 - 20,
                        },
                        "Prad_dim":
                        {
                            "init": 1E4,
                            "lb": 1E4,
                            "ub": 1E4,
                        }
        }
    param_guess = {
        **param_guess,
        **param_guess_rad
    }
    
    if load_optimal_traj:
        sol_env = pd.read_csv(
            "solution_alt_rad_first.csv",
             index_col=0
        ) 
        sol_rad = pd.read_csv(
            "trajectory_rad_model_PRBS.csv", 
            index_col=0
        ) 
        sol_env["Trad_RAD"] = sol_rad["Trad"]
        x_guess = np.array([
            sol_env["Ti"].values.flatten(),
            sol_env["Te"].values.flatten(),
            sol_rad["Trad"].values.flatten(), 
            sol_rad["Tsup"].values.flatten()
        ])
        lbx = 1.0*x_guess
        ubx = 1.0*x_guess
    else:
        # constrain in particular Th to physically meaningful values:
        x_guess = np.array([
                        data.y1.values.flatten(),
                        data.y1.values.flatten() - 2,
                        data.y4.values.flatten(),
                        data.y5.values.flatten()
                        ])
        lbx = 0.7*x_guess
        ubx = 2.0*x_guess
        
    return param_guess, kwargs, lbx, ubx, x_guess


    