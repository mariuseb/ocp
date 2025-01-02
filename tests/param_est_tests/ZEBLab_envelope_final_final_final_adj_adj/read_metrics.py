import pandas as pd
import os

folder = "metrics_november"
files = os.listdir(folder)
tables = dict()

for file in files:
    if file.endswith("csv"):
        tables[file.rstrip(".csv")] = pd.read_csv(os.path.join(folder, file), index_col=0)

nrmse = pd.DataFrame()
for k, v in tables.items():
    #if k.startswith("val"):
    nrmse.loc[k, "nrmse_avg"] = v.nrmse.mean()
        
nrmse1 = pd.DataFrame()
for k, v in tables.items():
    #if k.startswith("val"):
    nrmse1.loc[k, "nrmse_avg"] = v.one_step_nrmse.mean()

print(tables)

print(nrmse.to_latex( float_format="%.3f"))