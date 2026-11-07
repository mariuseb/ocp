#import matplotlib
#matplotlib.use('QtAgg') # or 'TkAgg'
#import matplotlib.pyplot as plt
import pandas as pd
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
            "Value": colname, inplace=True
        },
        inplace=True
    )
    frames.append(frame)
    
df = pd.concat(frames, axis=1)
print(df)