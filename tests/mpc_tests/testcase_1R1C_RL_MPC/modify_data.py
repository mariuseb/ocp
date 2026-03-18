import pandas as pd
import matplotlib.pyplot as plt

weather = pd.read_csv("Resources/weather.csv", index_col=0)
setpoints = pd.read_csv("Resources/setpoints.csv", index_col=0)

#print(weather)

weather -= 20
setpoints["time"] = setpoints.index
setpoints["hour"] = setpoints.time.apply(lambda x: int(x/3600))
setpoints.index = setpoints["hour"]
setpoints["occ"] = setpoints.hour.apply(lambda x: True if (x % 24 > 7) and (x % 24 < 17) else False)
setpoints.loc[setpoints.occ != True, "LowerSetp[1]"] -= 4
setpoints.loc[setpoints.occ != True, "UpperSetp[1]"] += 5
setpoints.index = setpoints["time"]
setpoints.drop(columns=["hour", "time"], inplace=True)
# write edited files:
setpoints.to_csv("Resources/setpoints.csv", index=True)
#weather.to_csv("weather.csv", index=True)