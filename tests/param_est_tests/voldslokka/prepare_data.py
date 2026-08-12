from utils import get_metno_data, get_stations, get_observations, read_data, sanitize_index
import matplotlib.pyplot as plt
import pandas as pd

client_id = "791c9c51-f86a-4367-b0ce-bc13717c0f70"
client_secret = "8769d748-d052-43cb-b3cf-c6ba1331c077"

#data = read_data("data_20036")
room = sanitize_index(
  pd.read_csv("room_20036.csv", index_col=0)
).drop(columns=["dt_index", "clean_date", "datetime_naive", "Excel Time"])
ahu = sanitize_index(
  pd.read_csv("AHU_20036.csv", index_col=0)
).drop(columns=["dt_index", "clean_date", "datetime_naive", "Excel Time"])
"""
Name map, model to MET API
"""

data = pd.concat([room, ahu], axis=1)

historical_map = {
                'Ta' : 'air_temperature',
                'phi_s' : 'mean(surface_downwelling_shortwave_flux_in_air PT1H)'
                  }

#start = "2024-03-01T00:00"
#stop = "2024-03-02T00:00"

start = data.index[0].strftime("%Y-%m-%dT%H:%M")
#stop = data.index[24].strftime("%Y-%m-%dT%H:%M")
stop = data.index[-1].strftime("%Y-%m-%dT%H:%M")
#stop = (data.index[0] + pd.Timedelta(days=120)).strftime("%Y-%m-%sdT%H:%M")

#names = ["OSLO", "BÆRUM"]
#stations = get_stations(client_id, start, stop, names)

"""
Closest to Voldsløkka w/ solar data 
is probably Blindern, SN18700

obs = get_observations(
                        client_id,
                        "SN18700",
                        start,
                        stop,
                        )
                        
"""

temp_hist = get_metno_data(
                            "SN18700",
                            historical_map["Ta"],
                            start,
                            stop,
                            client_id
                            )
temp_hist.index = pd.to_datetime(
  temp_hist["referenceTime"]
)
temp_hist = temp_hist[["value"]]
temp_hist.rename(columns={"value": "Ta"}, inplace=True)
solar_hist = get_metno_data(
                            "SN18700",
                            historical_map["phi_s"],
                            start,
                            stop,
                            client_id
                            )
solar_hist.index = pd.to_datetime(
  solar_hist["referenceTime"]
)
solar_hist = solar_hist[["value"]]
solar_hist.rename(columns={"value": "phi_s"}, inplace=True)

wea = pd.concat([temp_hist, solar_hist], axis=1)

wea = wea.resample(rule="5min").ffill().tz_convert(None)

df = pd.concat([data, wea], axis=1)
df.to_csv("20036.csv", index=True)

print("tail")

