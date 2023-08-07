import numpy as np
import pandas as pd
import param as prm
import glob
import pickle as pickle

eps=0.01
rawDir='../../measurements/rawData/energisentral/'
treDir='../../measurements/treatedData/'

allFiles = glob.glob(rawDir+'*.txt')
df = pd.DataFrame()
list_ = []
#read data
for file_ in allFiles:
    #count number of rows to skip
    count = 0
    with open(file_) as file:
        for line in file:
            if '"Time";' in line: #header line
                break
            else: # inside the 1st block
                count += 1
    rdf=pd.read_csv(file_,skiprows=count, sep=';', index_col='Time', decimal=',')
    #set index to date/time format
    rdf.index = pd.to_datetime(rdf.index, format="'%y-%m-%d %H:%M:%S")
    #downsample
    rdf = rdf.resample('2S').mean()
    rdf=rdf.apply(pd.to_numeric,downcast='float')
    #drop event and error
    rdf = rdf.drop(['Event'], axis=1)
    if 'CH-4[V]' in rdf.columns: rdf = rdf.drop(['CH-4[V]'], axis=1)
    list_.append(rdf)
df = pd.concat(list_)
del list_

#drop columns with all nan values
df=df.dropna(axis=1, how='all')

#clean flow
df['CH-1[V]'].loc[df['CH-1[V]']<prm.V_min-eps]=np.nan
df['CH-2[V]'].loc[df['CH-2[V]']<prm.V_min-eps]=np.nan
df['CH-3[V]'].loc[df['CH-3[V]']<prm.V_min-eps]=np.nan

#convert flow
df['CH-1[V]']=((df['CH-1[V]']-prm.V_min)/(prm.V_max-prm.V_min))*(prm.flow_max-prm.flow_min)+prm.flow_min
df['CH-2[V]']=((df['CH-2[V]']-prm.V_min)/(prm.V_max-prm.V_min))*(prm.flow_max-prm.flow_min)+prm.flow_min
df['CH-3[V]']=((df['CH-3[V]']-prm.V_min)/(prm.V_max-prm.V_min))*(prm.flow_max-prm.flow_min)+prm.flow_min

#sort
df = df.sort_index()

#resample
df = df.resample('2S').asfreq()

#downsample
df=df.apply(pd.to_numeric,downcast='float')

#store data
#df.to_csv('loggerData.dat')
#pickle
file = open(treDir+'energisentralFull.pkl','wb')
pickle.dump(df,file,protocol=pickle.HIGHEST_PROTOCOL)
file.close()
