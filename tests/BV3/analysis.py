# -*- coding: utf-8 -*-
"""
Created on Wed May  6 14:14:03 2020

@author: hwaln
"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
import pandas as pd
import param as prm
import vvfunc as f
import pickle
import sys
import gc
import glob
import buildings.lib.metdata as met
import matplotlib.colors as mcolors
from cycler import cycler
import pvlib.solarposition as sp
import seaborn as sns

plt.rc('axes', prop_cycle=(cycler('linestyle', ['-', '--', ':', '-.'])*cycler('color',mcolors.TABLEAU_COLORS)))

dataDir='../../Measurements/'
plotDir=dataDir+'plots/'
#kimoLst=['S2_A', 'S3_S', 'S4_N', 'S4_S', 'S6_N', 'S6_S', 'S2-7_A', 'SU-7_A']
kimoLst=['S2_A', 'S3_S', 'S4_N', 'S4_S', 'S6_N', 'S6_S', 'SU-7_A']

tinyLst=['US-LA', '2N-201','2N-204','2S-210', '2S-213', '3N-CR',
       '4N-SR', '4N-CA', '4S-RR', '5N-501','5S_OA',
        '6S-611', '6S-613', '6S-614', '6S-615','6S-617', '6S-620','6S-MR', '6S-Cr']

def openFile(filename='treatedData/energisentralFull.pkl'):
    file = open(dataDir+filename,'rb')
    df = pickle.load(file)
    file.close()
    return df

def resampleAllData(df, freq):
    #resamples data frame according to specification
    #df = dataframe
    #freq = resampling frequency

    #function to only include days with full dataset
    def nansumwrapper(a, **kwargs):
        if np.isnan(a).any():
            return np.nan
        else:
            return np.nansum(a, **kwargs)
    #create dictionary of resampling methods
    d={}
    meanLst=['qh', 'qv', 'qint','Te', 'Isol', 'Ws','Wd']
    sumLst=[]
    firstLst=kimoLst+tinyLst+['WorkingDay', 'WorkingHours', 'Tv_ext_mean', '6S_mean', 'Tv_sup', 'Tv_ext']
    for col in df.columns:
        if col in meanLst:
            d[col]='mean'
        elif col in sumLst:
#            d[col]=nansumwrapper
            d[col]='sum'
        elif col in firstLst:
            d[col] = 'first'
        else:
            d[col]='mean'
            print('Warning: resampleBuildingData: '+ col +' not in resample method list. Method set to mean')

    return df.resample(freq).agg(d)

def resampleCTSMData(df, freq):
    #resamples data frame according to specification
    #df = dataframe
    #freq = resampling frequency

    #function to only include days with full dataset
    def nansumwrapper(a, **kwargs):
        if np.isnan(a).any():
            return np.nan
        else:
            return np.nansum(a, **kwargs)
    #create dictionary of resampling methods
    d={}
    meanLst=['qh', 'qv', 'qint','Te', 'Isol', 'Ws','Wd']
    sumLst=[]
    firstLst=['yTi']
    for col in df.columns:
        if col in meanLst:
            d[col]='mean'
        elif col in sumLst:
#            d[col]=nansumwrapper
            d[col]='sum'
        elif col in firstLst:
            d[col] = 'first'
        else:
            print('Warning: resampleBuildingData: ' + col
                  + ' not in resample method list. Variaable not included')

    df=df.resample(freq).agg(d)
    return df

def addfanSpd(df):
    PRBS_start='2020-04-06'
    PRBS_end='2020-04-13'

    df['fanSpd']=1

    #normal operation
    dWd={}
    #dWd['00:00:00']=0.0
    dWd['06:00:00']=0.0
    dWd['06:30:00']=0.67
    dWd['18:00:00']=1.0
    dWd['18:30:00']=0.67
    dWd['23:59:59']=0.0

    dWe={}
    #dWd['00:00:00']=0.0
    dWe['10:00:00']=0.0
    dWe['15:00:00']=0.67
    dWe['23:59:59']=0.0

    start_day_time='00:00:00'
    for end_day_time in dWd:
        day_time_index = df.between_time(start_day_time, end_day_time, include_end=False)[df['WorkingDay']==1].index
        df.loc[df.index.isin(day_time_index),'fanSpd'] = dWd[end_day_time]
        start_day_time=end_day_time

    start_day_time='00:00:00'
    for end_day_time in dWe:
        day_time_index = df.between_time(start_day_time, end_day_time, include_end=False)[df['WorkingDay']==0].index
        df.loc[df.index.isin(day_time_index),'fanSpd'] = dWe[end_day_time]
        start_day_time=end_day_time

    # prbs
    df.loc[PRBS_start:PRBS_end,'fanSpd']=0.67


def openFilesAndConcat():
    dfEn=openFile(filename='treatedData/energisentral_inklWea.pkl')
    dfTemp=openFile(filename='Inneklima/tempData.pkl')
    dfEn=dfEn.resample('5T').mean()
    df=pd.concat([dfEn, dfTemp],axis=1)
    df['WorkingDay']=(df.index.dayofweek<5).astype(int)
    df['WorkingHours']=((df['WorkingDay']==1) & (df.index.hour>=7) & (df.index.hour<=17)).astype(int)
    addfanSpd(df)
    df['Tv_ext_mean']=calcMeanVentTemp(df)
    df['6S_mean']=calcMean6S(df)
    return df

def calcMeanVentTemp(df):
    dMea={'S4_N':3,
          'S4_S':2,
          'S2_A':1,
          'S3_S':2,
          'S6_N':2,
          'S6_S':2}
    Tem=pd.Series(data=0, index=df.index)
    c=0
    for key in dMea:
        Tem+=df[key]*dMea[key]
        c+=dMea[key]
    return Tem/c

def calcMean6S(df):
    dMea={'6S-611':3,
          '6S-613':2,
          '6S-614':1,
          '6S-615':1,
          '6S-617':3,
          '6S-620':2,
          '6S-MR':2,
          '6S-Cr':1}
    Tem=pd.Series(data=0, index=df.index)
    c=0
    for key in dMea:
        Tem+=df[key]*dMea[key]
        c+=dMea[key]
    return Tem/c



def calcQvent(Tavt, FanSpd, VfloNom, Tsup):
    cp=1000 #J/kgK
    rho= 1.205 #kg/m3
    return VfloNom*FanSpd*cp*rho*(Tsup-Tavt)

def generateCTSMRInput(df, fname='../CTSMR/Data/bv3_15T_SU-7_A.csv', fromDate='2020-04-06', toDate='2020-04-13 16', freq='15T', yTi='SU-7_A', calcVent=False):
    dfC=df[fromDate:toDate][[yTi, 'P_radTot','Tout', 'SolGlob','WindSpd', 'WindDir']]
    dfC.columns=['yTi', 'qh', 'Te', 'Isol', 'Ws', 'Wd']
    dfC['qint']=0
    dfC['qv']=calcQvent(df['SU-7_A'], 1, 3.6,20) if calcVent else 0
    dfC=resampleCTSMData(dfC, freq)
    dfC['t']=(dfC.index.to_series()-dfC.index[0]).dt.total_seconds().astype(int)
    dfC['Azimuth'] = sp.get_solarposition(dfC.index, latitude=59.944760, longitude=10.711493).azimuth/180*np.pi
    dfC.to_csv(fname, sep=';')
    return dfC

def plotCTSMRInput(df):
    fig,ax = plt.subplots(3,1, sharex=True)
    tax=[a.twinx() for a in ax]
    #indoor temperature
    df.yTi.plot(ax=ax[0])

    #weather
    df.Te.plot(ax=ax[1])
    df.Isol.plot(ax=tax[1])

    #power
    df.qh.plot(ax=ax[2])

def generatePRBSSimFile(df, fname='bv3_15T_SU-7_A_sim.csv', fromDate='2020-04-06', toDate='2020-04-13 16', freq='15T', yTi='SU-7_A', calcVent=False):
    dfC=df[fromDate:toDate][['Tout', 'SolGlob', 'P_radTot', yTi]]
    dfC.columns=['Te', 'Isol', 'qh', 'yTi']
    dfC['qint']=0
    dfC['qv']=calcQvent(df['SU-7_A'], 1, 3.6, 20) if calcVent else 0
    dfC=resampleCTSMData(dfC, freq)
    dfC['s']=(dfC.index.to_series()-dfC.index[0]).dt.total_seconds().astype(int)
    dfC['h']=dfC['s']/3600
    dfSim=dfC[['s','h','Te', 'Isol','qint','qv','qh', 'yTi']]
    dfSim[['Te', 'yTi']]+=273.15
    dfSim.reset_index(drop=True, inplace=True)
    return dfSim

def generateNormSimFile(df, fname='bv3_15T_SU-7_A_simNorm.csv', fromDate='2020-03-23', toDate='2020-03-29', freq='15T', yTi='SU-7_A', calcVent=False):
    dfC=df[fromDate:toDate][['Tout', 'SolGlob', 'P_radTot', yTi]]
    dfC.columns=['Te', 'Isol', 'qh', 'yTi']
    dfC['qint']=0
    dfC['qv']=calcQvent(df['SU-7_A'], df['fanSpd'], 3.6/0.67, 21) if calcVent else 0
    dfC=resampleCTSMData(dfC, freq)
    dfC['s']=(dfC.index.to_series()-dfC.index[0]).dt.total_seconds().astype(int)
    dfC['h']=dfC['s']/3600
    dfSim=dfC[['s','h','Te', 'Isol','qint','qv','qh', 'yTi']]
    dfSim[['Te', 'yTi']]+=273.15
    dfSim.reset_index(drop=True, inplace=True)
    return dfSim

######## Plots #######
## Energy central ##


def plotMainPropRes(df, tempLst=['SU-7_A'], fromDate='2020-04-06', toDate='2020-04-13'):
    fig,ax = plt.subplots(3,1, sharex=True)
    tax=[a.twinx() for a in ax]
    #indoor temperature
    df[fromDate:toDate][tempLst].plot(ax=ax[0])
    ax[0].legend('')
    ax[0].set_ylabel('Tin [C]', color='tab:blue')

    #weather
    df[fromDate:toDate]['Tout'].plot(ax=ax[1])
    ax[1].set_ylabel('Tout [C]', color='tab:blue')
    df[fromDate:toDate]['SolGlob'].plot(ax=tax[1], color='tab:orange')
    tax[1].set_ylabel('Solar radiaton [W/m2]', color='tab:orange')

    #power
    (df[fromDate:toDate]['P_radTot']/1000).plot(ax=ax[2])
    ax[2].set_ylabel('Power [kW]', color='tab:blue')


def plotSupplyTempScatter(df, fromDate='2020-02-01', toDate='2020-03-30'):
    fig,ax = plt.subplots(1,1)

    ax.scatter(df[fromDate:toDate]['Tout'], df[fromDate:toDate]['TsRadE'])
    ax.scatter(df[fromDate:toDate]['Tout'], df[fromDate:toDate]['TsRadW'])

    ax.legend(['East','West'])
    ax.set_ylabel('Supply temperature [C]')
    ax.set_xlabel('Ambient temperature [C]')
    return fig,ax

def plotETScatter_hourly(df, fromDate='2020-02-01', toDate='2020-03-30'):
    freq='1H'
    fig,ax = plt.subplots(1,1)
    df_=df.resample(freq).mean()

    ax.scatter(df_[fromDate:toDate]['Tout'], df_[fromDate:toDate]['P_radE'].resample(freq).mean()/1000)
    ax.scatter(df_[fromDate:toDate]['Tout'], df_[fromDate:toDate]['P_radW'].resample(freq).mean()/1000)

    ax.legend(['East','West'])
    ax.set_ylabel('Energy [kWh/h]')
    ax.set_xlabel('Ambient temperature [C]')
    return fig,ax

def plotETScatter_daily(df, fromDate='2020-02-01', toDate='2020-03-30'):
    freq='1D'
    fig,ax = plt.subplots(1,1)
    df_=df.resample(freq).mean()
    colors = ['tab:blue', 'tab:orange']
    markers = ['o','x']
    ax.scatter(df_[fromDate:toDate][df_['WorkingDay']==1]['Tout'], df_[fromDate:toDate][df['WorkingDay']==1]['P_radE']*24/1000, color=colors[0], marker=markers[0])
    ax.scatter(df_[fromDate:toDate][df_['WorkingDay']==1]['Tout'], df_[fromDate:toDate][df['WorkingDay']==1]['P_radW']*24/1000, color=colors[1], marker=markers[0])
    ax.scatter(df_[fromDate:toDate][df_['WorkingDay']==0]['Tout'], df_[fromDate:toDate][df['WorkingDay']==0]['P_radE']*24/1000, color=colors[0], marker=markers[1])
    ax.scatter(df_[fromDate:toDate][df_['WorkingDay']==0]['Tout'], df_[fromDate:toDate][df['WorkingDay']==0]['P_radW']*24/1000, color=colors[1], marker=markers[1])
    ax.legend(['East','West'])
    ax.set_ylabel('Energy [kWh/day]')
    ax.set_xlabel('Ambient temperature [C]')
    return fig,ax

def plotEnTsupScatter(df, fromDate='2020-02-01', toDate='2020-03-30'):
    freq='1H'
    fig,ax = plt.subplots(1,1)

    ax.scatter(df[fromDate:toDate]['TsRadE'].resample(freq).mean(), df[fromDate:toDate]['P_radE'].resample(freq).mean()/1000)
    ax.scatter(df[fromDate:toDate]['TsRadW'].resample(freq).mean(), df[fromDate:toDate]['P_radW'].resample(freq).mean()/1000)

    ax.legend(['East','West'])
    ax.set_ylabel('Energy [kWh]')
    ax.set_xlabel('Supply temperature [C]')
    return fig, ax

def plotEn_dTScatter(df, fromDate='2020-02-01', toDate='2020-03-30'):
    freq='1H'
    fig,ax = plt.subplots(1,1)

    ax.scatter((df[fromDate:toDate]['TsRadE'].resample(freq).mean()-df[fromDate:toDate]['SU-7_A'].resample(freq).mean()), df[fromDate:toDate]['P_radE'].resample(freq).mean()/1000)
    ax.scatter(df[fromDate:toDate]['TsRadW'].resample(freq).mean()-df[fromDate:toDate]['SU-7_A'].resample(freq).mean(), df[fromDate:toDate]['P_radW'].resample(freq).mean()/1000)

    ax.legend(['East','West'])
    ax.set_ylabel('Energy [kWh]')
    ax.set_xlabel('Supply temperature [C]')
    return fig, ax

## Air temperatures ##
def plotKimoLoggers(df, lst=kimoLst, fromDate='2020-02-01', toDate='2020-03-30', WorkingHoursOnly=False, freq='5min'):
    fig,ax = plt.subplots(1,1)

    if WorkingHoursOnly:
        df[lst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax)
    else:
        df[lst][fromDate:toDate].plot(ax=ax)

    ax.set_ylabel('Temperature [C]')
    ax.legend(loc='center left', bbox_to_anchor=(1, 0.5))
    return fig, ax

def plotSingleVsMean(df, singLst=tinyLst, meanLst=[], fromDate='2020-02-01', toDate='2020-03-30', WorkingHoursOnly=False, freq='5min'):
    fig,ax = plt.subplots(1,1)

    if WorkingHoursOnly:
        df[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax, ls='--')
        df[meanLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax, lw=2)
    else:
        df[singLst][fromDate:toDate].resample(freq).first().plot(ax=ax, ls='--')
        df[meanLst][fromDate:toDate].resample(freq).first().plot(ax=ax, lw=2)

    ax.set_ylabel('Temperature [C]')
    ax.legend(loc='center left', bbox_to_anchor=(1, 0.5))
    return fig, ax

def plotAllSingleVsExt(df, fromDate='2020-02-01', toDate='2020-03-30', WorkingHoursOnly=False, freq='5min'):
    fig,ax = plt.subplots(3,1, sharex=True)
    #6th floor
    singLst=['6S-611', '6S-613', '6S-614', '6S-615','6S-617', '6S-620','6S-MR', '6S-Cr']
    meanLst=['6S_mean', 'S6_S']
    if WorkingHoursOnly:
        df[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[0], ls='--')
        df[meanLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[0], lw=2)
    else:
        df[singLst][fromDate:toDate].plot(ax=ax[0], ls='--')
        df[meanLst][fromDate:toDate].plot(ax=ax[0], lw=2)
    #4th floor
    singLst=['4N-SR', '4N-CR', '4S-RR']
    meanLst=['S4_N', 'S4_S']
    if WorkingHoursOnly:
        df[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[1], ls='--')
        df[meanLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[1], lw=2)
    else:
        df[singLst][fromDate:toDate].plot(ax=ax[1], ls='--')
        df[meanLst][fromDate:toDate].plot(ax=ax[1], lw=2)
    #2nd floor
    singLst=['2N-201','2N-204','2S-210', '2S-213']
    meanLst=['S2_A']
    if WorkingHoursOnly:
        df[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[2], ls='--')
        df[meanLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[2], lw=2)
    else:
        df[singLst][fromDate:toDate].plot(ax=ax[2], ls='--')
        df[meanLst][fromDate:toDate].plot(ax=ax[2], lw=2)
    for a in ax:
        a.set_ylabel('Temperature [C]')
        a.legend(loc='center left', bbox_to_anchor=(1, 0.5))
    return fig, ax

def plotSingleDiffMean(df, freq='5T', singLst=kimoLst, mean='Tv_ext_mean', fromDate='2020-04-06', toDate='2020-04-13', WorkingHoursOnly=False, inclPow=False):
    fig,ax = plt.subplots(1+int(inclPow),1, sharex=True)
    ax0=ax[0] if inclPow else ax
    dfDiff=pd.DataFrame(index=df.index)
    for s in singLst:
        dfDiff[s]=df[s]-df[mean]

    if WorkingHoursOnly:
        dfDiff[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax0)
    else:
        dfDiff[singLst][fromDate:toDate].resample(freq).first().plot(ax=ax0)

    ax0.set_ylabel('Temperature [C]')
    ax0.legend(loc='center left', bbox_to_anchor=(1, 0.5))

    if inclPow:
        (df[fromDate:toDate]['P_radTot']/1000).resample(freq).mean().plot(ax=ax[1])
        ax[1].set_ylabel('Power [kW]', color='tab:blue')

        tax1=ax[1].twinx()
        df[fromDate:toDate]['SolGlob'].resample(freq).mean().plot(ax=tax1, color='tab:orange')
        tax1.set_ylabel('Solar radiaton [W/m2]', color='tab:orange')

    return fig, ax

def creatDiffDepScatterPlot(df, singLst=kimoLst, mean='Tv_ext_mean', fromDate='2020-04-06', toDate='2020-04-13', WorkingHoursOnly=False):# Visualising data dependencies with seaborn, might take a couple of minutes to run
    # Create the pairgrid object
    data=pd.DataFrame(index=df.index)
    for s in singLst:
        data[s]=df[s]-df[mean]
    data['Heat']=df['P_radTot']/1000
    data['SolGlob']=df['SolGlob']
    data=data[fromDate:toDate]

    grid = sns.PairGrid(data=data, vars=list(data.columns), diag_sharey=False)

    # Upper is a scatter plot
    grid.map_lower(plt.scatter, alpha=0.8, s=20)

    # Diagonal is a histogram
    grid.map_diag(sns.kdeplot)
    # Bottom is density plot
    #grid.map_upper(sns.kdeplot)
    #plt.savefig('/gridmap.pdf')
    plt.show()
    return

def createDiffCorrMatrixPlot(df, singLst=kimoLst, mean='Tv_ext_mean', fromDate='2020-04-06', toDate='2020-04-13', WorkingHoursOnly=False):
    # Create correlation matrix
    data=pd.DataFrame(index=df.index)
    for s in singLst:
        data[s]=df[s]-df[mean]
    data['Heat']=df['P_radTot']/1000
    data['SolGlob']=df['SolGlob']
    if WorkingHoursOnly:
        data=data[df['WorkingHours']==1][fromDate:toDate]
    else:
        data=data[fromDate:toDate]

    corr_matrix = data.corr(method='spearman')
    # Plot
    fig, axs = plt.subplots(1, 1, figsize=(10, 10))
    sns.heatmap(abs(corr_matrix), annot=True, cmap = plt.cm.autumn_r, fmt='.2f', ax=axs)
    return

def plotAllSingleVsExtDiff(df, fromDate='2020-02-01', toDate='2020-03-30', WorkingHoursOnly=False, freq='5min'):
    fig,ax = plt.subplots(3,1, sharex=True)
    #6th floor
    singLst=['6S-611', '6S-613', '6S-614', '6S-615','6S-617', '6S-620','6S-MR', '6S-Cr', '6S_mean']
    mean = 'S6_S'
    dfDiff=pd.DataFrame(index=df.index)
    for s in singLst:
        dfDiff[s]=df[s]-df[mean]

    if WorkingHoursOnly:
        df[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[0])
    else:
        df[singLst][fromDate:toDate].plot(ax=ax[0])
    #4th floor
    singLst=['4N-SR', '4N-CR', '4S-RR']
    meanLst=['S4_N', 'S4_S']

    if WorkingHoursOnly:
        df[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[1], ls='--')
        df[meanLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[1], lw=2)
    else:
        df[singLst][fromDate:toDate].plot(ax=ax[1], ls='--')
        df[meanLst][fromDate:toDate].plot(ax=ax[1], lw=2)
    #2nd floor
    singLst=['2N-201','2N-204','2S-210', '2S-213']
    meanLst=['S2_A']
    if WorkingHoursOnly:
        df[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[2], ls='--')
        df[meanLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax[2], lw=2)
    else:
        df[singLst][fromDate:toDate].plot(ax=ax[2], ls='--')
        df[meanLst][fromDate:toDate].plot(ax=ax[2], lw=2)
    for a in ax:
        a.set_ylabel('Temperature [C]')
        a.legend(loc='center left', bbox_to_anchor=(1, 0.5))
    return fig, ax

def plotSingleVsExt(df,singLst, meanLst, fromDate='2020-02-01', toDate='2020-03-30', WorkingHoursOnly=False, freq='5min', legend=None):
    fig,ax = plt.subplots(1,1, sharex=True)
    #singLst=['6S-611', '6S-613', '6S-614', '6S-615','6S-617', '6S-620','6S-MR', '6S-Cr', '6S_mean']
    #mean = 'S6_S'

    if WorkingHoursOnly:
        df[singLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax, ls='--')
        df[meanLst][df['WorkingHours']==1][fromDate:toDate].resample(freq).first().plot(ax=ax, lw=2, color='black')
    else:
        df[singLst][fromDate:toDate].plot(ax=ax, ls='--')
        df[meanLst][fromDate:toDate].plot(ax=ax, lw=2, color='black')
    ax.set_ylabel('Temperature [C]')
    if legend is None:
        legend=list(singLst)+list(meanLst)
    ax.legend(legend, loc='center left', bbox_to_anchor=(1, 0.5))
    return fig,ax


# BS2023 plots
def plot_vent_comp(df):
    singLst=['S2_A', 'S3_S', 'S4_N', 'S4_S', 'S6_N', 'S6_S']
    meanLst=['SU-7_A']
    legend=singLst+['S_A']
    fig, ax = plotSingleVsExt(df, singLst=singLst, meanLst=meanLst,
                              fromDate='2020-04-06', toDate='2020-04-13 16',
                              freq='1H', legend=legend)
    plt.savefig('vent_PRBS.png', dpi=600, bbox_inches='tight')

def plot_6th_comp(df):
    singLst=['6S-611', '6S-613', '6S-614', '6S-615','6S-617', '6S-620','6S-MR', '6S-Cr']
    meanLst=['S6_S']
    legend=[f'6S_{i}' for i in range(1,9)]+meanLst
    fig, ax = plotSingleVsExt(df, singLst=singLst, meanLst=meanLst,
                              fromDate='2020-04-06', toDate='2020-04-13 16',
                              freq='1H', legend=legend)
    plt.savefig('6th_PRBS.png', dpi=600, bbox_inches='tight')
