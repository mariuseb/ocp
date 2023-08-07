import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#df = pd.read_csv("allData_15min.csv", index_col=0)
df = pd.read_csv("PRBSData_5min.csv", index_col=0)
df.index = pd.to_datetime(df.index)
#rad_temps = df[[col for col in df.columns if col.startswith("T") and "Rad" in col]]
#room_temps = df[[col for col in df.columns if col.startswith("6")]]
temp_cols = ["6S-611", "6S-617", "6S-615", "6S-614", "6S-620", "6S-613"]
east_cols = ["6S-611", "6S-614", "6S-613"]
west_cols = ["6S-617", "6S-615","6S-620"]
west = df[west_cols].mean(axis=1)
east = df[east_cols].mean(axis=1)
power_cols = ["P_radE", "P_radW"]
room_temps = df[temp_cols]
power = df[power_cols]
# take a subset of the data:
#rad_temps = rad_temps.loc["2020-02-01 12:00:00+01:00":"2020-05-14 12:00:00+01:00"]
#rad_temps.plot()
#room_temps = room_temps.loc["2020-03-01 12:00:00+01:00":"2020-03-30 12:00:00+01:00"]
fig, ax = plt.subplots(2,1, sharex=True)
ax[0].plot(df.index, room_temps.values)
#ax[0].plot(df.index, east.values, label="east")
#ax[0].plot(df.index, west.values, label="west")
ax[0].legend(temp_cols)
ax[1].plot(df.index, power.values)
ax1 = ax[1].twinx()
ax1.plot(df.index, df["SolGlob"].values, color="y")

#room_temps.plot()
plt.show()
#print(rad_temps)
#print(rad_temps)
print(room_temps)