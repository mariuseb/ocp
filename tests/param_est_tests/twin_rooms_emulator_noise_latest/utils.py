#%% 
import pandas as pd
import numpy as np

def prepare_data(
    data_path, 
    rule="15min", 
    integrate_inputs=True
):
    data = pd.read_csv(data_path, index_col=0)
    y_map = {
        "Ti_219": "Ti",
        "Prad_219": "Prad",
        "Prad_calc": "Prad_calc",
        "rad_flo_calc": "rad_flo_calc",
        "rad_219": "rad_219",
        "Tsup_air": "Tsup_air",
        "reaRadTRet219_y": "Tret",
        "reaRadTSup219_y": "Tsup",
        "reaRadFlow219_y": "rad_flo",
        "weatherStation_reaWeaTDryBul_y": "Ta",
        "weatherStation_reaWeaHGloHor_y": "phi_s",
        "fan_219_y": "fan_219",
        "fan_ret_219_y": "fan_ret",
        "phi_int": "phi_int"
        
    }
    try:
        y_data = data.rename(columns=y_map)[
                list(y_map.values())
            ]
        y_data["phi_int"] *= 66.7
    except:
        y_data = data
    #y_data = y_data[60:]
    #y_data["Prad_calc"] = 4200*y_data["rad_flo"]*(y_data["Tsup"] - y_data["Tret"])
    #y_data["rad_flo"] = y_data["rad_flo"].shift(-1)
    #y_data["Prad"] = y_data["Prad"].shift(-1)
    #y_data["rad_flo"] = y_data["rad_flo_calc"]
    y_data["Prad"] = y_data["Prad_calc"]
    y_data["dT"] = y_data["Tsup"] - y_data["Tret"]

    y_data.index = pd.to_timedelta(y_data.index)
    if integrate_inputs:
        integrate_names = ["Prad","rad_flo", "phi_s","Ta","Tsup","Tret"] 
    else:
        integrate_names = [] 
    freq_names = [col for col in y_data.columns if col not in integrate_names]
    integrate = y_data[integrate_names]
    freq = y_data[freq_names]
    
    #y_data = y_data[:-1]
    integrate = integrate.resample(rule=rule).mean()
    freq = freq.resample(rule=rule).asfreq()
    y_data = pd.merge(
        integrate,
        freq,
        left_index=True,
        right_index=True
    )

    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["rad_flo"]
    y_data["y3"] = y_data["Prad"]
    y_data["y4"] = y_data["Tret"]
    y_data["y5"] = y_data["Tsup"]
    y_data["y6"] = y_data["dT"]
    y_data["m_val_bool"] = (((y_data["rad_219"].round(4) > 0)).astype(int) + \
        ((y_data["rad_flo"].round(4) > 0)).astype(int)).astype(bool).astype(int) + 1e-2
    y_data["m_flow_bool"] = ((y_data["rad_flo"].round(4) > 0)).astype(int) + 1e-2
    y_data = y_data[:-1]
    #y_data["rad_flo"] = y_data["rad_flo"].shift(-1)
    #y_data["Prad"] = y_data["Prad"].shift(-1)
    
    y_data["dt_index"] = y_data.index
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = range(len(y_data.index))
    y_data.index *= dt
    #y_data = y_data[4*24:2*4*24]
    #y_data = y_data[-96:]
    #y_data = y_data[0:12*24]
    #y_data[4:]
    N = len(y_data)

    return y_data, N, dt
    


def prepare_est(
        data,
        A=66.7,
        load_optimal_rad_params=False,
        load_optimal_env_params=False,
        load_optimal_traj=False,
        n_x=4,
        hvac=False
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
                    "Rirad":
                    {
                        "init": 1e-3
                    },
                    "Rrrad":
                    {
                        "init": 1e-3
                    },
                    "Ci":
                    {
                        "init": 1e6
                    },
                    "Crad":
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
        params_rad = pd.read_csv("3state_hvac_model_full_dataset_params.csv", index_col=0)
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
                            "lb": 0.01
                        },
                        "rad_flo_nom":
                        {
                            "init": 0.12,
                            "lb": 0.09, 
                            "ub": 0.30
                        },
                        "cp_water":
                        {
                            "init": 4200,
                            "lb": 4199, 
                            "ub": 4201
                        },
                        "Csup":
                        {
                            "init": 1E3,
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
                            "lb": -20, 
                            "ub": 20
                        },
                        "Tsupret_offset":
                        {
                            "init": 1,
                            "lb": 1E-3, 
                            "ub": 20
                        },
                        "Tsupret_offset_b":
                        {
                            "init": 1,
                            "lb": 1E-3, 
                            "ub": 20
                        },
                        "Tsupret_offset_a":
                        {
                            "init": 2/3,
                            "lb": 1e-3,
                            "ub": 10,
                        },
                        "Tret_offset":
                        {
                            "init": 1,
                            "lb": 1E-3, 
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
                            "init": 273.15 + 47,
                            "lb": 273.15 + 40,
                            "ub": 273.15 + 60,
                        },
                        "Ta_dim":
                        {
                            "init": 273.15 - 20,
                            "lb": 273.15 - 20,
                            "ub": 273.15 - 20,
                        },
                        "Prad_b":
                        {
                            "init": 4000,
                            "lb": 1000,
                            "ub": 1E4,
                        },
                        "Prad_a":
                        {
                            "init": 33,
                            "lb": 1,
                            "ub": 200,
                        },
                        "dT_b":
                        {
                            "init": 12,
                            "lb": 6,
                            "ub": 30,
                        },
                        "dTpeak_b":
                        {
                            "init": 16,
                            "lb": 6,
                            "ub": 30,
                        },
                        "dT_a":
                        {
                            "init": 1,
                            "lb": 1e-2,
                            "ub": 10,
                        },
                        "dTpeak_a":
                        {
                            "init": 1,
                            "lb": 1e-2,
                            "ub": 10,
                        },
                        "tau":
                        {
                            "init": 1E3,
                            "lb": 10,
                            "ub": 1E6,
                        },
                        "tau_flow":
                        {
                            "init": 1E3,
                            "lb": 10,
                            "ub": 1E6,
                        },
                        "tau_b":
                        {
                            "init": 10,
                            "lb": 100,
                            "ub": 30000,
                        },
                        "tau_a":
                        {
                            "init": 200,
                            "lb": 100,
                            "ub": 10000,
                        },
                        "alpha_int":
                        {
                            "init": 0.5,
                            "lb": 1e-3,
                            "ub": 4,
                        },
                        "alpha_vent":
                        {
                            "init": 0.5,
                            "lb": 1e-3,
                            "ub": 1,
                        },
                        "cp_air":
                        {
                            "init": 1000,
                            "lb": 1000,
                            "ub": 1000,
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
        if n_x == 6:
            x_guess = np.array([
                            data.y1.values.flatten(),
                            data.y1.values.flatten() - 2,
                            data.y1.values.flatten() + 2,
                            data.y4.values.flatten(),
                            data.y5.values.flatten(),
                            data.y2.values.flatten()
                            ])
        elif n_x == 5:
            x_guess = np.array([
                            data.y1.values.flatten(),
                            data.y1.values.flatten() - 2,
                            data.y4.values.flatten(),
                            data.y5.values.flatten(),
                            data.y2.values.flatten()
                            ])
        elif n_x == 4:
            """
            x_guess = np.array([
                            data.y1.values.flatten(),
                            data.y1.values.flatten() - 2,
                            data.y4.values.flatten(),
                            data.y5.values.flatten()
                            ])
            """
            x_guess = np.array([
                            data.y1.values.flatten(),
                            data.y1.values.flatten() - 2,
                            data.y1.values.flatten() - 280,
                            data.y2
                            ])
        elif n_x == 3:
            if hvac:
                x_guess = np.array([
                                data.y4.values.flatten(),
                                data.y5.values.flatten(),
                                data.y2.values.flatten()
                                ])
            else:
                x_guess = np.array([
                                data.y1.values.flatten(),
                                data.y1.values.flatten() - 2,
                                data.y1.values.flatten() - 280
                                ])
        elif n_x == 2:
            if hvac:
                x_guess = np.array([
                                data.y4.values.flatten(),
                                data.y5.values.flatten()
                                ])
            else:
                x_guess = np.array([
                                data.y1.values.flatten(),
                                data.y1.values.flatten() - 2
                                ])
        else:
            raise ValueError
        lbx = 0.7*x_guess
        ubx = 2.0*x_guess
        
    return param_guess, kwargs, lbx, ubx, x_guess


    