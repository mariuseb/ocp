import numpy as np
import json
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from matplotlib import rc
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from ocp.frost_function import get_metno_data, get_stations, get_observations
from pprint import pprint
from collections import OrderedDict
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
    
def correct_data(files, columns, ending=None):
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
            # These are the correct columns:
            #correct_columns = pd.read_csv(file, **kwargs).columns
        if file == "Evenstad-20230417T000800-%s.csv" %  (ending, ):
            kwargs = orig_kwargs
            datetime_format = "%d.%m.%Y %H:%M"
            #wrong_columns = pd.read_csv(file, **kwargs).columns
            
        df = pd.read_csv(file, **kwargs)
        df.index = pd.to_datetime(df.index, format=datetime_format)
        # remove any cols with 'Unnamed' in name:
        df = df.drop(columns=[col for col in df.columns if "Unnamed" in col])       
        df = df.fillna(method="bfill")
        df.columns = columns
        
        if df.index.name is not None:
            df.index.name = None
        
        df.to_csv(file)
        
     

def concat_vert(files, ending=None):
    # merge vertically:
    dfs = []
    
    """
    orig_kwargs = kwargs = {
        "sep": ";",
        #"skiprows": [1,2,3],
        "header": 0,
        "index_col": 0
    }
    """
    
    #datetime_format = "%d.%m.%Y %H:%M"
    # first change: "Evenstad-20230227T010515-%s.csv"
    # change back: "Evenstad-20230417T000800-%s.csv"
    
    for file in files:
        #assume alphabetical order:
        #if file == "Evenstad-20230227T010515-%s.csv" %  (ending, ):
        kwargs  = {
            "sep": ",",
            "skiprows": [0,2,3],
            "header": 0,
            "index_col": 0
        }   
        df = pd.read_csv(file, **kwargs)
        df = df.drop(columns=[col for col in df.columns if "Unnamed" in col])   
        df.index.name = None
        dfs.append(df.fillna(method="bfill"))
        
    data = pd.concat(dfs)
    
    # floatize:
    for col in data.columns:
        try:
            data[col] = data[col].astype(float)
        except ValueError:
            data[col] = data[col].apply(lambda x: str(x).replace(" ", "")).astype(float)       
    return data
        
        
def clean_columns():
    """
    For most prevalent format,
    columns are jumbled. 
    
    Before doing anything with
    the data, fix this.
    
    NB! multi-columned data
    contain the correct order.
    Write this to all data-files.
    """
    
    all_files = os.listdir()
    ones = sorted([file for file in all_files if file.endswith("-1.csv")])
    twos = sorted([file for file in all_files if file.endswith("-2.csv")])
    
    # for all ones, set corrext multiindex header and index:
    kwargs  = {
        "sep": ",",
        #"skiprows": [0],
        "header": [0,1,2],
        "index_col": 0
    }
    # write in-place:
    correct = pd.read_csv("Evenstad-20230227T010515-1.csv", **kwargs)
    correct_data(ones, columns=correct.columns[:-1], ending="1")
    
    correct = pd.read_csv("Evenstad-20230227T010515-2.csv", **kwargs)
    correct_data(twos, columns=correct.columns[:-1], ending="2")
    
def concatenate_data():
    """
    """
    
    all_files = os.listdir()
    ones = sorted([file for file in all_files if file.endswith("-1.csv")])
    twos = sorted([file for file in all_files if file.endswith("-2.csv")])

    # write in-place:
    one = concat_vert(ones, ending="1")
    two = concat_vert(twos, ending="1")
    
    df = pd.merge(one, two, right_index=True, left_index=True)
    df.index = pd.to_datetime(df.index)
    
    return df


def get_historical_weather(start, stop):
    """
    Get weather data matching the index.
    """

        
    #start = weather.index[0]
    #stop = weather.index[-1]
    #start = str(start).split(" ")[0]
    #stop = str(stop).split(" ")[0]
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
                                            #"OSLO"

                                    ])
    # This is EVENSTAD:
    station_id = 'SN8140'
    # get temperature data from MET:  
    results = dict()
    for match in matches:
        avail = get_observations(client_id, match, start, stop)
        results[match] = avail
        #if match == "SN18700":
        #    print(avail)
        if avail.id.apply(lambda x: "flux" in x).sum() > 0:
            print(match)
            #avail.to_csv(match + ".csv")
            avail.loc[avail.id.apply(lambda x: "flux" in x) == True].to_csv(match + ".csv")


    #avail = get_observations(client_id, "SN18700", start, stop)

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


    weather = weather.resample(rule="5min").asfreq().fillna(method="bfill")
    weather["Ta"] = met_data.air_temperature   
    # again
    weather = weather.resample(rule="5min").asfreq().fillna(method="bfill")
    # check diff:
    #diff = pd.DataFrame(columns=["Ta", "Ta_faa"])
    #diff["Ta"] = met_data["air_temperature"]
    #diff["Ta_faa"] = weather["Ta"]
    #diff["Ta"] = 
    weather.to_csv("weather.csv")

    
# name map
names = [
    "Vtot",
    "Tsup_water_west_int",
    "Tret_water_west_int",
    "P_water_central",
    "Tsup_water_west",
    "Tret_water_west",
    "P_water",
    "V_flow",
    "E_tot",
    "valve",
    "V_flow_sup_air",
    "V_flow_exh_air",
    "Tsup_air",
    "Ti_113",
    "Tset_113",
    "Ti_117",
    "Tset_117",
    "Ti_119",
    "Tset_119",
    "Ti_123",
    "Tset_123",
    "Ti_124",
    "Tset_124",
    "Ti_125",
    "Tset_125",
    "Tret_air",
    "Ti_101",
    "Tset_101",
    "Ti_103",
    "Tset_103",
    "Ti_104",
    "Tset_104",
    "Ti_105",
    "Tset_105",
    "Ti_106",
    "Tset_106",
    "Ti_107",
    "Tset_107",
    "Ti_110",
    "Tset_110",
    "Ti_office_2nd_floor_n",
    "Ti_office_2nd_floor_s",
    "Trec_air",
    "E_in_xf53",
    "E_xf53",
    "phi_s",
    "Ta"
]

if __name__ == "__main__":

    """
    TODO: implement state check on data,
    i.e. investigate if the data file 
    pairs have identical headers.
    """
    clean_columns()
    df = concatenate_data()
    #wea = get_weather(regenerate=True)
    
    # add weather obs to df:
    #df[wea.columns] = wea.loc[df.index]
    
    # test plot of e.g. valve:
    #df['Pådrag ventil hovedstokk'].plot()
    for name in df.columns:
        print(name)
    
    # ordered:
    cols = list(df.columns)
    name_pairs = []
    for i, col in enumerate(cols):
        name_pairs.append((col, names[i]))
    name_map = OrderedDict(name_pairs)
    df = df.rename(columns=name_map)