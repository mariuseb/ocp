#from ast import Param
from ocp.param_est import ParameterEstimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from matplotlib import rc
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from ocp.frost_function import get_metno_data, get_stations, get_observations
# text:
rc('mathtext', default='regular')

# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

def read_couple(file1, file2, sep=","):    
    data1 = pd.read_csv(file1, sep=sep, skiprows=[1,2,3], header=0, index_col=0)
    data2 = pd.read_csv(file2, sep=sep, skiprows=[1,2,3], header=0, index_col=0)
    data = pd.merge(data1, data2, left_index=True, right_index=True)
    return data


client_id = "791c9c51-f86a-4367-b0ce-bc13717c0f70"
client_secret = "8769d748-d052-43cb-b3cf-c6ba1331c077"

# TODO: name map

    
def concat_vert(files, ending=None):
    """
    Concatenate evenstad data.
    """
    # merge vertically:
    dfs = []
    orig_kwargs = kwargs = {
        "sep": ";",
        #"skiprows": [1,2,3],
        "header": 0,
        "index_col": 0
    }
    datetime_format = "%d.%m.%Y %H:%M"
    # first change: "Evenstad-20230227T010515-%s.csv"
    # change back: "Evenstad-20230417T000800-%s.csv"
    for file in files:
        # assume alphabetical order:
        if file == "Evenstad-20230227T010515-%s.csv" %  (ending, ):
            kwargs  = {
                "sep": ",",
                "skiprows": [0,2,3],
                "header": 0,
                "index_col": 0
            }
            datetime_format = "mixed"
        if file == "Evenstad-20230417T000800-%s.csv" %  (ending, ):
            kwargs = orig_kwargs
            datetime_format = "%d.%m.%Y %H:%M"
            
        df = pd.read_csv(file, **kwargs)
        df.index = pd.to_datetime(df.index, format=datetime_format)
        # remove any cols with 'Unnamed' in name:
        df = df.drop(columns=[col for col in df.columns if "Unnamed" in col])       
        # backfill, first temperatures always missing:
        #df = df.fillna(method="bfill")
        assert not df.empty
        dfs.append(df.fillna(method="bfill"))
        
    data = pd.concat(dfs)
    
    # floatize:
    for col in data.columns:
        try:
            data[col] = data[col].astype(float)
        except ValueError:
            data[col] = data[col].apply(lambda x: str(x).replace(" ", "")).astype(float)       
    return data
        
        
def concatenate_data(sampling_time):
    """
    Concatenate raw data from Evenstad.
        
    Use global solar from Fåvang,
    ambient temperature from Evenstad. 
    """
    
    all_files = os.listdir()
    ones = sorted([file for file in all_files if file.endswith("-1.csv")])
    twos = sorted([file for file in all_files if file.endswith("-2.csv")])
    
    
    # first change: "Evenstad-20230227T010515-1.csv"
    # change back: "Evenstad-20230417T000800-1.csv"
    
    one = concat_vert(ones, ending="1")
    two = concat_vert(twos, ending="2")
    
    df = pd.merge(one, two, right_index=True, left_index=True)
    #df.index = pd.to_datetime(df.index, format="%d.%m.%Y %H:%M")
    return df
    


def prepare_dataset(
                    data, 
                    plot=True,
                    columns=None, 
                    regenerate_weather=False
                    ):
    #weather = pd.read_csv("faavang_longer.csv", index_col=0)
    #weather = pd.read_csv("faavang.csv", index_col=0)
    
    if regenerate_weather:
        weather = pd.read_csv("faavang_longest.csv", index_col=0)
        weather.columns = ["Ta", "phi_s"]
        weather.index = pd.to_datetime(weather.index, utc=True).tz_localize(None)
        
        start = weather.index[0]
        stop = weather.index[-1]
        start = str(start).split(" ")[0]
        stop = str(stop).split(" ")[0]
        #start = str(start).split(" ")[0].replace("2023", "2016")
        #stop = str(stop).split(" ")[0].replace("2023", "2016")
        
        client_id = "791c9c51-f86a-4367-b0ce-bc13717c0f70"
        client_secret = "8769d748-d052-43cb-b3cf-c6ba1331c077"
        #station_id = 'SN25830'
        stations, matches = get_stations(client_id,
                                         start, 
                                         stop,
                                         names=[
                                                "RINGEBU",
                                                "GAUSDAL",
                                                "ÅMOT",
                                                "STOR-ELVDAL"
                                        ])
        # This is EVENSTAD:
        station_id = 'SN8140'
        # get temperature data from MET:  
        avail = get_observations(client_id, station_id, start, stop)
        
        # get temperature:
        voi = 'air_temperature'
        met_data = get_metno_data(station_id, voi, start, stop, client_id)
        met_data.index = pd.to_datetime(met_data.index)
        met_data.index = met_data.index.tz_localize(None)
        
        """
        stations_list = ['SN6840', 'SN13030', 'SN13150']
        avail = get_observations(client_id, stations_list[1], start, stop)
        print(avail)
        """
        
        #weather.index = pd.to_datetime(weather.index)
        #weather = weather.iloc[300:-1]
        #weather = weather.loc["2023-06-30 20:00:00+02:00":-1]
        try:
            data.index = pd.to_datetime(data.index)
        except ValueError:
            data.index = pd.to_datetime(data.index, format="%d.%m.%Y %H:%M")
        #data = data.resample(rule="1H").asfreq()

        weather = weather.resample(rule="5min").asfreq().fillna(method="bfill")
        weather.Ta = met_data.air_temperature   
        # again
        weather = weather.resample(rule="5min").asfreq().fillna(method="bfill")
        # check diff:
        #diff = pd.DataFrame(columns=["Ta", "Ta_faa"])
        #diff["Ta"] = met_data["air_temperature"]
        #diff["Ta_faa"] = weather["Ta"]
        #diff["Ta"] = 
        weather.to_csv("weather.csv")
    else:
        weather = pd.read_csv("weather.csv", index_col=0)
    
    if columns is not None:
        data.columns = columns
        
    #temps_west = data[["CE_36_01_RT43", "CE_36_01_RT41"]]
    temps_west = data[["CE_36_01_RT43"]].mean(axis=1)
    #temps_west = data[["CE_36_01_RT41"]]
    #temps_west = temps_west.mean(axis=1)
    #temps_east = data[["CE_36_01_RT42", "CE_36_01_RT47", "CE_36_01_RT46", "CE_36_01_RT48"]]
    temps_east = data[["CE_36_01_RT42"]].mean(axis=1)
    temps_small = data[["CE_36_01_RT47", "CE_36_01_RT46", "CE_36_01_RT48"]].mean(axis=1)
    #temps_east = data[["CE_36_01_RT42"]]
    exhaust = data[["CE_36_01_RT50"]]
    temps_old = pd.DataFrame(data=[temps_west, temps_small]).T
    #temps = pd.DataFrame(data=[temps_west, temps_east, temps_small]).T
    temps = pd.DataFrame(data=[temps_east, temps_small]).T
    #temps = exhaust
    #temps = pd.DataFrame(data=[temps_east]).T
    
    power = data["CE_32_01_OE50Kw"].apply(lambda x: str(x).replace(" ", "")).astype(float)
    #temps = data[["CE_36_01_RT42"]]
    #Ti = temps.mean(axis=1)
    #Ti = temps_west
    outside = weather.Ta
    #ax = temps.mean(axis=1).plot()
    #ax = data["CE_36_01_RT43"].plot(drawstyle="steps-post")
    
    if plot:
        ax = temps_east.plot(drawstyle="steps-post")
        temps_west.plot(ax=ax, drawstyle="steps-post")
        outside.plot(drawstyle="steps-post", ax=ax)
        data["CE_36_01_RT43XS"].plot(color="m", ax=ax, drawstyle="steps-post")
        ax1 = ax.twinx()
        power.plot(ax=ax1, color="k", linestyle="dashed", drawstyle="steps-post")
        plt.show()

    # plot ventilation:
    Tsup_air = data["CE_36_01_RT40"]
    Tret_air = data["CE_36_01_RT50"]
    V_in = data["CE_36_01_RP40L"].apply(lambda x: str(x).replace(" ", "")).astype(float)
    V_out = data["CE_36_01_RP50L"].apply(lambda x: str(x).replace(" ", "")).astype(float)
    # cut-off on 15k
    cut_off = 20000
    #V_in[V_in < cut_off] = 0
    #V_out[V_out < cut_off] = 0
    if plot:
        ax = V_in.plot(drawstyle="steps-post")
        V_out.plot(drawstyle="steps-post")
        ax.legend()
        ax1 = ax.twinx()
        Tsup_air.plot(drawstyle="steps-post", color="k", ax=ax1)
        Tret_air.plot(drawstyle="steps-post", color="r", ax=ax1)
        data["CE_36_01_RT43"].plot(drawstyle="steps-post", color="m", ax=ax1)
        ax1.legend()
        plt.show()
    


    # added power from ventilation:
    #Tdiff_in = data["CE_36_01_RT40"] - data["CE_36_01_RT43"]
    #Tdiff_out = data["CE_36_01_RT50"] - data["CE_36_01_RT43"]
    #Tdiff_in = data["CE_36_01_RT40"] - Ti
    #Tdiff_out = data["CE_36_01_RT50"] - Ti
    rho_air = 1.204 # [kg/m^3]
    #cp_air = 1000 # [J/kg*K]
    #power_in = rho_air*cp_air*(V_in/3600)*Tdiff_in
    #power_out = rho_air*cp_air*(V_out/3600)*Tdiff_out
    m_in = rho_air*(V_in/3600)
    m_out = rho_air*(V_out/3600)

    data = data.fillna(method="bfill")
    remove = data.columns
    y_data = data
    y_data["phi_s"] = weather.phi_s
    y_data["Ti"] = temps.mean(axis=1)
    y_data["Ti_old"] = temps_old.mean(axis=1)
    y_data["m_flow"] = data["3424_CE_ES_320_00_OE51m3"].apply(lambda x: str(x).replace(" ", "")).astype(float).diff()
    #y_data["Ti1"] = temps_west
    y_data["Ta"] = outside
    #y_data["Pvent"] = power_outtemps_east
    y_data["m_in"] = m_in
    y_data["m_out"] = m_out
    y_data["Tsup_air"] = Tsup_air
    y_data["Tret_air"] = Tret_air 
    y_data["Tset"] = y_data["CE_36_01_RT62XS"]
    y_data["valve"] = data["CE_32_01_SB00y"]
    y_data["Tret1"] = y_data["3424_CE_ES_320_00_OE51rt50"]
    y_data["Tsup1"] = y_data["3424_CE_ES_320_00_OE51rt40"]
    y_data["Tsup"] = y_data["CE_32_01_OE50_RT04"]
    y_data["Tret"] = y_data["CE_32_01_OE50_RT05"]
    y_data["phi_h"] = power*1000 # to W
    y_data["y1"] = y_data["Ti"]
    #y_data["y2"] = y_data["Ti1"]
    y_data.drop(columns=remove)
    y_data["dt_index"] = y_data.index
    
    
    return y_data
    

if __name__ == "__main__":

    one = concatenate_data("1H")