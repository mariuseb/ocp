#from ast import Param

#import sys
import os
#import pathlib
#ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
#sys.path.append(ocp_path)
#from ocp.param_est import ParameterEstimation
from ocp.estimation import Estimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
#import json
import casadi as ca
from matplotlib.dates import MonthLocator, YearLocator, DayLocator, HourLocator
#import ocp.dae as dae
#import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
#from pprint import pprint
from matplotlib import rc
#from ocp.tests.utils import get_opt_config_path, get_data_path
#import os
#from pandas.plotting import autocorrelation_plot
#from ocp.filters import KalmanBucy
#from analyse import df, df_ene, df_dhw, plot_apt, search_tags, apt_rooms
from read_eiksveien import _plot_apt, get_room_setpoints, \
                                get_heating_central_data, \
                                    plot_heating_central_data, plot_shift, \
                                        append_to_apt_plot, finalize_apt_df, \
                                            finalize_df, generate_door_window_openings
from analyse import df, plot_apt, apt_rooms, \
                        plot_agg_apt, north_facade, \
                            south_facade
                    # df_ene, df_dhw, search_tags
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates



if __name__ == "__main__":

    cfg_path = os.path.join("configs", "3R2C_door_window_input_air.json")
    sampling_time = "5min"
    dt = int(sampling_time.rstrip("min"))*60
    INCLUDE_DOOR_WINDOW = False
    
    start = "2025-02-13 00:00"
    stop = "2025-03-05 00:00"
    
    #start = "2024-12-05 00:00"
    #stop = "2024-12-12 00:00"
    #start = "2024-10-21 06:00"
    #stop = "2024-10-27 18:00"
    
    start_ts = pd.Timestamp(start).tz_localize("Europe/Oslo")
    stop_ts = pd.Timestamp(stop).tz_localize("Europe/Oslo")

    df, hea, room_sps = finalize_df(
        df,
        sampling_time,
        start,
        stop
    )
    
    apts = list(apt_rooms.keys())
    energy_acc = pd.DataFrame(
        index=apts,
        columns=["percent", "en_tot"]
    )
    #apts = ["H0104"]
    PLOT_APT = False
    # innreg:
    nom_flows = pd.read_excel("innreg_gulvvarme.xlsx", index_col=0)
    nom_flows_sum = nom_flows.sum()
    corr_factor = nom_flows/nom_flows.mean()
    
    for i, apt in enumerate(apts):
        #apt = "H0102"
        #apt = "H0102"
        rooms = apt_rooms[apt]
        # H0103
        areas = {
            "Tbedr": 14.5,
            "Tliv": 20.9,
            "Thall": 10.7,
            #"Tbath": 9.1
        }
        # H0102
        areas = {
            "Tbedr": 10,
            "Tliv": 24,
            "Thall": 7.9,
            #"Tbath": 9.1
        }
        apt_df = plot_apt(df, apt = apt)
        apt_df["Ta"] = df["Tout"]
        apt_df["phi_s"] = df["SolGlob"]
        
        if PLOT_APT:
            plt.show()
            _plot_apt(df, room_sps, apt = apt, include_bath=False)
        else:
            plt.close()
        
        # modularize the name map based on rooms :
        
        name_map = {
            f"""1273_563_{rooms[0]}_RT601""": 'Thall',
            f"""1273_563_{rooms[1]}_RT601""": 'Tliv',
            f"""1273_563_{rooms[2]}_RT601""": 'Tbedr',
            f"""1273_563_{rooms[3]}_RT601""": 'Tbath',
            f"""1273_563_{rooms[3]}_LZ001""": 'phi_h_bath',
            f"""1273_320_002_OE{apt[2:]}.Energy""": 'phi_h_int',
            'Ta': 'Ta',
            'phi_s': 'phi_s'
        }
        
        start = pd.Timestamp("2025-02-13 00:00").tz_localize("Europe/Oslo")
        stop = pd.Timestamp("2025-03-05 00:00").tz_localize("Europe/Oslo")
        
        data, A = finalize_apt_df(
            name_map, 
            areas,
            apt_df,
            hea,
            start_ts,
            stop_ts,
        )  
        energy_acc.loc[apt, "percent"] = ((data["phi_h_int"].sum() - data["phi_h"].sum())/data["phi_h_int"].sum())*100
        energy_acc.loc[apt, "en_tot"] = data["phi_h_int"].sum()
        energy_acc.loc[apt, "phi_h"] = data["phi_h"].sum()
        
        if i == 0:
            en_ts = data[["phi_h"]]
            en_ts.columns = ["phi_h_" + apt]
        else:
            col = "phi_h_" + apt
            en_ts[col] = data["phi_h"]
            
    # average:    
    #energy_avg = energy_acc["en_tot"].sum()/len(energy_acc)
    #energy_acc.loc[apts, "corr_factor"] = energy_acc["en_tot"]/energy_avg
    #energy_acc["phi_h_corr"] = energy_acc["phi_h"]*energy_acc["corr_factor"]
    #energy_acc["percent_corr"] = energy_acc["phi_h_corr"]/energy_acc["en_tot"]
    corr_factor = corr_factor.loc[[
        ndx for ndx in corr_factor.index \
            if
        ndx in energy_acc.index
    ]].squeeze()
    energy_acc["phi_h_corr"] = energy_acc["phi_h"]*corr_factor
    print(energy_acc)  
    
