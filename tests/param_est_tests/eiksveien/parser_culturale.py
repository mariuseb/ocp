# -*- coding: utf-8 -*-
"""
Created on Tue Feb  7 07:33:53 2023

@author: hwaln
"""

import pandas as pd
import os
import numpy as np
import buildings.lib.metNWP as met

new_data_dir = "./recieved/"
parsed_data_dir = "./parsed/"

digital_tags = ['LZ', 'SC']

location = {'Eiksveien':
            {'lat': 59.94,
            'lon': 10.60}}

def convert_to_datetime(index):
    # index = pd.to_datetime(index, format="%Y-%m-%dT%H:%M", utc=True)
    try:
        index = pd.to_datetime(index, format="ISO8601", utc=True)
    except Exception as err:
        print(err)
        index = pd.to_datetime(index, utc=True)

    return index

def concatTags(df, infer_setpoints=True):
    tags = sorted(set(df[1]))
    dfs = []
    d_tags = []
    for t in tags:
        if any(x in t.split('_')[4] for x in digital_tags):
            # Store at take digital tags after analog
            d_tags.append(t)
        else:
            d = df[df[1] == t].copy()
            d.index = convert_to_datetime(d[2])
            name = '_'.join(t.split('_')[1:])
            d=d.loc[~d.index.duplicated()]
            try:
                dfs.append(d[3].rename(f"{name}").resample('5min').nearest(limit=1))
            except Exception as e:
                print(f'Failed to resample {t}, {e}')
    for t in d_tags:
        d = df[df[1] == t].copy()
        d.index = convert_to_datetime(d[2])
        name = '_'.join(t.split('_')[1:])
        # add top and bottom row
        # get start and end of measurement period
        start = int(not bool(d[3].iloc[0]))  # time series start with oposite of first measured value
        end = d[3].iloc[-1]  # time series ends with same as last measured value
        boarders = pd.Series(index=dfs[0].index[[0, -1]], name=t, data=[start, end])
        d = pd.concat([boarders, d[3]], ignore_index=False).sort_index()
        d=d.loc[~d.index.duplicated()]
        try:
            dfs.append(d.rename(f"{name}").resample('1s').ffill().resample('5min').mean())
        except Exception as e:
            print(f'Failed to resample {t}, {e}')
        if infer_setpoints:
            dfs.append(infer_setpoints_(dfs, d, name).rename(f"{name}_SP"))

    dfTot = pd.concat(dfs, axis=1)
    dfTot.index = dfTot.index.tz_convert("Etc/Gmt-1")
    return dfTot


def infer_setpoints_(dfs, act_val, act_tag, hyst=0.2):
    try:
        Tin_tag = '_'.join(act_tag.split('_')[0:3]+['RT601'])
        Tin = [s for s in dfs if s.name==Tin_tag]
        if len(Tin)>1:
            raise Exception("Error in infering setpoint")
        else:
            Tin = Tin[0]
        Tin[Tin==0]=np.nan
        df_ = Tin.resample('1s').interpolate().to_frame()
    except:
        return np.nan
    df_[act_tag]=act_val.resample('1s').ffill()
    df_.columns=['Tin','act_val']
    df_['act_diff'] = df_['act_val'].diff()
    df_['Tset']=np.nan
    df_['Tset'][df_['act_diff'] > 0]=df_['Tin'][df_['act_diff'] > 0]+hyst
    df_['Tset'][df_['act_diff'] < 0]=df_['Tin'][df_['act_diff'] < 0]-hyst
    df_['Tset']=df_['Tset'].ffill().bfill()
    return df_['Tset'].round(0).resample('5min').first()



def get_weather_data(index):
    fromTime = index[0].strftime('%Y-%m-%d %H')
    toTime = index[-1].strftime('%Y-%m-%d %H')
    df, e=met.getLocationsWeatherData(location,
                                       fromTime=fromTime, toTime=toTime,
                                       tz='Etc/GMT-1', store=False, name='Name')
    return df['Eiksveien']

def parse_new_files(save=True, move=True):
    files = os.listdir(new_data_dir)
    dfs = []
    for f in files:
        if '.csv' in f:
            df=pd.read_csv(new_data_dir+f, sep=";", header=None)
            try:
                df[3]=pd.to_numeric(df[3])
            except:
                # some values not possbile to convert to nan
                df[3]=pd.to_numeric(df[3], errors='coerce')
                print('Warning: Following rows not numeric. set to nan')
                print(df[pd.to_numeric(df[3]).isna()])
            dfs.append(df)
    df = pd.concat(dfs, ignore_index=True)
    df = concatTags(df)
    dfWea = get_weather_data(df.index)
    dfWea = dfWea.resample(df.index.freq).ffill()
    dfTot = pd.concat([dfWea, df], axis=1)
    dfTot[dfWea.columns] = dfTot[dfWea.columns].ffill()  # fill last hour

    if save:
        name=f'{dfTot.index[0].strftime("%Y%m%d")}_{dfTot.index[-1].strftime("%Y%m%d")}'
        dfTot.to_csv(f'{parsed_data_dir}{name}.csv', sep=';')
    if move:
        # move imported file to imported folder
        for f in files:
            if '.csv' in f:
                os.rename(new_data_dir+f, f"{new_data_dir}treated/{f}")
