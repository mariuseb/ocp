#import matplotlib
#matplotlib.use('QtAgg') # or 'TkAgg'
#import matplotlib.pyplot as plt
import pandas as pd
import matplotlib.pyplot as plt
import os
    
# transform data:
dirname = "30023_fall2024"
files = os.listdir(dirname)
frames = []
for file in files:
    frame = pd.read_csv(
        os.path.join(
            dirname,
            file
        ),
        index_col=0,
        header=1
    )
    colname = file[:-4]
    frame.rename(
        columns={
            "Value": colname
            }, inplace=True
    )
    frame = frame.iloc[23000:32928]
    frame.index = pd.to_datetime(frame.index, format="%d/%m/%Y %H:%M:%S CET")
    frame.index = frame.index.tz_localize("Europe/Oslo")
    frames.append(frame[colname])
    
df = pd.concat(frames, axis=1)

weather = pd.read_csv("weather_blindern_dec_2024.csv", index_col=0)
weather.index = pd.to_datetime(weather.index).tz_convert("Europe/Oslo") - pd.Timedelta(minutes=15)
weather = weather.resample(rule="5min").ffill()

df = pd.merge(
    df, weather, left_index=True, right_index=True
)
df.to_csv("30023_data.csv", index=True)
print(df)