# -*- coding: utf-8 -*-
"""
Created on Wed May  6 12:15:02 2020

@author: hwaln
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


def readAllKimoCSVs(dataDir='../../measurements/Inneklima/2020-05-05 ZEN logger fra høyblokk/'):
    logDict={'K1':['S4_N','S4_S'],
             'K2':['S2_A','S3_S'],
             'K3':['S6_N','S6_S'],
             'K4':['S2-7_A','SU-7_A']}
    l=[]
    for key in logDict:
        df=pd.read_csv(dataDir+key+'.csv', sep=';', encoding='mbcs', header=1, index_col=0, usecols=[1,2,3])
        df.index=pd.to_datetime(df.index, format='%d.%m.%Y %H.%M.%S')
        df=df.tz_localize('etc/gmt-1')
        oidx = df.index
        nidx = df.resample('5T').mean().index
        df=df.reindex(oidx.union(nidx)).interpolate('index').reindex(nidx)
        df.columns = logDict[key]
        l.append(df)
    dfKimo=pd.concat(l, axis=1)
    return dfKimo

def readAllTinyTagsData(dataDir='../../measurements/Inneklima/LoggedataTinyTag2020-05-14/'):
    logList=[135564,264150,266392,266470,267180,269989,269990,269991,271236,271241,365298,365301,365302,368203,369250,597882,603272,607531,607532]
    logNameLst=['5S_OA', '4N-SR', '3N-CR', '4S-RR', '2S-213',
       '2N-204', '6S-611', '2N-201', '4N-CA', 'US-LA',
       '6S-617', '6S-MR', '6S-615', '5N-501', '6S-Cr', '6S-614',
       '2S-210', '6S-620', '6S-613']
    l=[]
    for i, log in enumerate(logList):
        df=pd.read_csv(dataDir+str(log)+'.csv', encoding='mbcs', header=0, skiprows=[1], index_col=0, usecols=[0,1,2], na_values=['X','x'])
        df.index=pd.to_datetime(df.index, format='%m/%d/%Y %H:%M')
        df=df.tz_localize('Europe/Oslo')
        df=df.tz_convert('etc/gmt-1')
        oidx = df.index
        nidx = df.resample('5T').mean().index
        df=df.reindex(oidx.union(nidx)).interpolate('index').reindex(nidx)
        s = df['Temperature']
        s.rename(logNameLst[i], inplace=True)
        l.append(s)
    dfTiny=pd.concat(l, axis=1)
    return dfTiny['2020-02-07':]
    
    
def readPRBSTrendLogData(filename='../../measurements/prbsTrendlog.xlsx'):
    Tsup=pd.read_excel(filename, sheet_name='Ttil_Vent', usecols='A:B', index_col=0, skiprows=2)
    Text=pd.read_excel(filename, sheet_name='Tavtr_Vent', usecols='A:B', index_col=0, skiprows=2)
    df = pd.concat([Tsup,Text],axis=1)
    df.index=pd.to_datetime(df.index, format='%d.%m.%Y %H:%M:%S')
    df=df.tz_localize('etc/gmt-1')
    oidx = df.index
    nidx = df.resample('5T').mean().index
    df=df.reindex(oidx.union(nidx)).interpolate('index').reindex(nidx)
    df.columns=['Tv_sup', 'Tv_ext']
    return df

def readAllTempData():
    dfKimo=readAllKimoCSVs()
    dfVent=readPRBSTrendLogData()
    dfTiny=readAllTinyTagsData()
    dfTemp=pd.concat([dfKimo, dfVent, dfTiny], axis=1)
    return dfTemp