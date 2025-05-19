# -*- coding: utf-8 -*-
"""
@author: mariusb
"""

import pandas as pd
import matplotlib.pyplot as plt
import os

names = ["batteri_lading.csv", "batteri_status.csv", "hovedtavle.csv", "PV_prod_15min.csv"]
df = pd.DataFrame()

for file in names:
    ser = pd.read_csv(
            os.path.join("el_data", file), 
            index_col=0
        )
    df[file.rstrip(".csv")] = ser

df.index = pd.to_datetime(df.index)

names = {
    "batteri_statu": "z_ba_perc",
    "batteri_lading": "y_ba",
    "hovedtavle": "y_imp",
    "PV_prod_15min": "y_pv",
}
df.rename(columns=names, inplace=True)
df["z_ba"] = ((df["z_ba_perc"]/100)*7.2)
df["y_ba_alt"] = df["z_ba"].shift(1) - df["z_ba"]

fig, axes = plt.subplots(4,1, sharex=True)
ax = axes[0]
df["z_ba"].plot(ax=ax, drawstyle="steps-post", color="m")
ax = axes[1]
df["y_ba_alt"].plot(ax=ax, drawstyle="steps-post", color="b")
ax = axes[2]
df["y_imp"].plot(ax=ax, drawstyle="steps-post", color="k")
#df["y_ba"].plot(ax=ax, drawstyle="steps-post", color="r")
plt.show()

print(df)