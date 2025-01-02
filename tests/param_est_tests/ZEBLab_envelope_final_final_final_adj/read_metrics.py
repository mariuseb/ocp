import pandas as pd
import os

files = os.listdir("metrics")
tables = dict()

for file in files:
    tables[file.rstrip(".csv")] = pd.read_csv(os.path.join("metrics", file), index_col=0)

nrmse = pd.DataFrame()
for k, v in tables.items():
    if k.startswith("val"):
        nrmse.loc[k, "nrmse_avg"] = v.nrmse.mean()

    
print(tables)

print(nrmse.to_latex( float_format="%.3f"))