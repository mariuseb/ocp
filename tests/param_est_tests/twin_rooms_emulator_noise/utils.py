#%% 
import pandas as pd

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
    y_data.index = pd.to_timedelta(y_data.index)
    
    y_data = y_data.resample(rule=rule).mean()
    
    y_data["dt_index"] = y_data.index
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = range(len(y_data.index))
    y_data.index *= dt
    #y_data = y_data[4*24:2*4*24]
    N = len(y_data)

    return y_data, N, dt
    



    