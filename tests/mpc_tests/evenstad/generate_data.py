#%%
import numpy as np
import json
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib
from pprint import pprint
from matplotlib import rc
from ocp.frost_function import get_metno_data, get_stations, get_observations
from ocp.functions import functions
# text:
rc('mathtext', default='regular')
from ocp.tests.mpc_tests.evenstad.utils import get_forecast, prepare_data
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
from collections import OrderedDict
#matplotlib.rcParams["backend"] = "tkagg"

TEST_MODE = True
location = {
            "lat": 61.424779678595705, 
            "lon": 11.082286053879768
            }

"""
These are needed to get the historical data:
"""
client_id = "791c9c51-f86a-4367-b0ce-bc13717c0f70"
client_secret = "8769d748-d052-43cb-b3cf-c6ba1331c077"
"""
Name map, model to MET API
"""
historical_map = {
                'Ta' : 'air_temperature',
                'phi_s' : 'mean(surface_downwelling_shortwave_flux_in_air PT1H)'
                  }

forecast_map = {
                'Ta' : 'air_temperature_2m',
                'phi_s' : 'integral_of_surface_downwelling_shortwave_flux_in_air_wrt_time'
                }
"""
Stations solar radiation:
    - SN7420, RENA-ØRHAUGEN

Temperature:
    - SN8140, Evenstad
"""


if __name__ == "__main__":

    if TEST_MODE:
        now = pd.Timestamp("01-26-2024 14:30:00").tz_localize("Europe/Oslo")
        #now = pd.Timestamp.now().tz_localize("Europe/Oslo")
        #now = now.tz_convert('Europe/Oslo')
    else:
        now = pd.Timestamp.now().tz_localize("Europe/Oslo")
        #now = now.tz_convert('Europe/Oslo')
        #now = now.tz_localize(None)

    five_today = pd.Timestamp(str(now.date()) + " 17:00").tz_localize("Europe/Oslo")

    # NOTE: you have to modify this to current date
    # to fetch 'real-time' compliant data. 
    # (i.e., if you want to generate optimal set-points
    #  for today)
    #stop = pd.Timestamp("01-26-2024 14:00:00").tz_localize("Europe/Oslo")
    stop = now

    try:
        assert (now <= stop <= five_today)
        print("Script is running in real-time mode.")
    except AssertionError:
        print(
            "Script must be run between 14:00 and 17:00 " + 
            "on a given day to generate weather data " +
            "that is real-time compliant. Furthermore, " + 
            "it is the responsibility of the user to set"
            "the correct stop point for data retrieval." +
            " Currently it is set to %s, " % (str(stop), ) +
            "which means that the script is generating test data."
            )
        

    """
    Read historical measurement data from SAUTER.
    Use length of it to determine how far back to 
    retrieve weather data.

    NOTE: user/runner of script have
    to edit the below variables to 
    the correct filenames:
    """

    file1 = "Evenstad-20230130T002331-1.csv"
    file2 = "Evenstad-20230130T002331-2.csv"

    meas = prepare_data(file1, file2)

    if TEST_MODE: # convert index 2023 -> 2024:
        meas["dt_index"] = meas.index
        meas.dt_index = meas.dt_index.apply(lambda x: pd.Timestamp(str(x).replace("2023", "2024")))
        meas.index = meas["dt_index"]
        meas.index = meas.index.tz_localize("Europe/Oslo")

    #start = stop - pd.Timedelta(days=14) # - pd.Timedelta(hours=1)
    start = meas.index[0]

    start_str = str(start).replace(" ", "T")
    #stop_str = str(stop + pd.Timedelta(hours=1)).replace(" ", "T")
    stop_str = str(stop).replace(" ", "T")

    """
    The below code snippet fetches
    the needed historical weather data:
    """
    # Get historical temperature:
    weather = get_metno_data(
                            "SN8140", # Evenstad
                            historical_map["Ta"],
                            start_str,
                            stop_str,
                            client_id
                            )
    weather.columns = ["Ta"] 
    # convert to Kelvin:
    weather["Ta"] += 273.15
    # Get historical solar radiation:
    solar_hist = get_metno_data(
                                "SN7420", # Rena
                                historical_map["phi_s"],
                                start_str,
                                stop_str,
                                client_id
                                )
    weather["phi_s"] = solar_hist.values
    weather.index = pd.to_datetime(weather.index)
    # Timestamps are UTC+0, convert 1 hours ahead.
    #weather.index += pd.Timedelta(hours=1)
    # Now localize to get rid of UTC specifier.
    weather.index = weather.index.tz_convert("Europe/Oslo")
    # Keep weather file:
    weather.to_csv(
                "historical_weather_data/%s-%s.csv" 
                %
                (start_str, stop_str)
                )
    
    """
    The below code snippet fetches
    the needed weather predictions:
    """
    forecast = get_forecast(
                            now,
                            location,
                            forecast_map,
                            test=TEST_MODE
                            )
    #forecast.index = forecast.index.tz_convert("Europe/Oslo")
    #forecast.index = forecast.index.tz_localize(None)
    forecast.to_csv(
                "weather_forecasts/%s.csv" 
                %
                (str(now),)
                )
    
    """
    The below code snippet transforms 
    a direct copy-paste from NordPool
    to correct format:
    """
    spot = pd.read_excel(
                        "spot.xlsx",
                        header=None, 
                        names=["time", "price"]
                        )
    start = pd.Timestamp(str(now.date()) + " 00:00").tz_localize("Europe/Oslo")
    end = pd.Timestamp(str((start + pd.Timedelta(days=2)  - pd.Timedelta(hours=1)))).tz_convert("Europe/Oslo")
    spot.index = pd.date_range(
                            start=start, 
                            end=end,
                            freq="1H"
                            )
    spot.price = spot.price.apply(lambda x: x.replace(",", ".")).astype(float)

    #%matplotlib ipympl
    #plt.figure()
    #ax = spot.price.plot()
    #plt.pause(1)
    #plt.show()
    #print(spot)

    now = now.tz_localize(None)
    date_string = str(now).replace(":", "-")
    """
    Write data for MPC problem:
    """
    forecast["P_spot"] = spot.price
    mpc_data = forecast.loc[~forecast.isna().sum(axis=1).astype(bool)]
    mpc_data.to_csv(
            "mpc_data/%s.csv" 
            %
            (date_string,)
            )
    
    """
    Write data for state
    estimation problem:
    """
    meas[["Ta", "phi_s"]] = weather    
    kalman_data = meas.loc[~meas.isna().sum(axis=1).astype(bool)]
    kalman_data.to_csv(
            "kalman_data/%s.csv" 
            %
            (date_string,)
            )
    
    

