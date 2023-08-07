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
import buildingdata.lib.metdata as met


def checkMemoryStatus():
    print(len(gc.get_objects()))
    print(sys.getsizeof(gc.get_objects()))


dataDir = '../../measurements/treatedData/'


def openFile(filename='energisentralFull.pkl'):
    file = open(dataDir+filename, 'rb')
    df = pickle.load(file)
    file.close()
    return df


def treatData(df):
    # downsample
    df = df.apply(pd.to_numeric, downcast='float')
    # Rename df columns
    df.rename(columns={'CH-1[V]':'FloVent',
                       'CH-2[V]':'FloRadE',
                       'CH-3[V]':'FloRadW',
                       'CH-5[C]':'TrVent',
                       'CH-6[C]':'TsVent',
                       'CH-7[C]':'TrRadE',
                       'CH-8[C]':'TsRadE',
                       'CH-9[C]':'TrRadW',
                       'CH-10[C]':'TsRadW'}, inplace=True)
    
    #rename
    df['FloVent'].name = 'V_vent[l/s]'
    df['FloRadE'].name ='V_radE[l/s]'
    df['FloRadW'].name ='V_radW[l/s]'
    df['TrVent'].name = 'Tr_vent[C]'
    df['TsVent'].name = 'Ts_vent[C]'
    df['TrRadE'].name = 'Tr_radE[C]'
    df['TsRadE'].name = 'Ts_radW[C]'
    df['TrRadW'].name = 'Tr_radE[C]'
    df['TsRadW'].name = 'Ts_radW[C]'
    
    #calculate power
    #P_vv = kv*f.d_water(t_kv)/1000*f.h_water(t_vv)-kvt*f.d_water(t_kv)/1000*f.h_water(t_kv)-vvct*f.d_water(t_vvc)/1000*f.h_water(t_vvc)
    df['P_radE'] = (df.FloRadE*f.d_water(df.TrRadE))/1000*(f.h_water(df.TsRadE)-f.h_water(df.TrRadE))
    df['P_radW'] = (df.FloRadW*f.d_water(df.TrRadW))/1000*(f.h_water(df.TsRadW)-f.h_water(df.TrRadW))
    df['P_radTot'] = df.P_radE+df.P_radW
    
    #set names
    df.P_radE.name = 'P_radE[W]'
    df.P_radW.name = 'P_radW[W]'
    df.P_radTot.name = 'P_radTot[W]'
    
    df=df.tz_localize('etc/gmt-1')
    return df

def addWeatherData(df):
    startDate=(df.index[0].date()+pd.DateOffset(days=-1)).strftime('%Y-%m-%d')
    endDate=(df.index[-1].date()+pd.Timedelta(1, unit='D')).strftime('%Y-%m-%d')
    df['Tout']=met.getMetDataTimeSeries('SN18700', 'air_temperature', startDate, endDate).tz_convert('etc/gmt-1')
    df['Tout']=df['Tout'].interpolate()
    df['SolGlob']=met.getMetDataTimeSeries('SN18700', 'mean(surface_downwelling_shortwave_flux_in_air PT1H)', startDate, endDate).tz_convert('etc/gmt-1')
    df['SolGlob']=df['SolGlob'].interpolate()
    df['WindDir']=met.getMetDataTimeSeries('SN18700', 'wind_from_direction', startDate, endDate).tz_convert('etc/gmt-1')
    df['WindDir']=df['WindDir'].interpolate()
    df['WindSpd']=met.getMetDataTimeSeries('SN18700', 'wind_speed', startDate, endDate).tz_convert('etc/gmt-1')
    df['WindSpd']=df['WindSpd'].interpolate()
    return df

# def appendData(df, newfile):
#     #read data
#     count = 0
#     with open(newfile) as file:
#         for line in file:
#             if '"Time";' in line: #header line
#                 break
#             else: # inside the 1st block
#                 count += 1
#     ndf=pd.read_csv(newfile,skiprows=count, sep=';', index_col='Time', decimal=',')
#     #set index to date/time format
#     ndf.index = pd.to_datetime(ndf.index, format="'%y-%m-%d %H:%M:%S")
#     #downsample
#     ndf = ndf.resample('2S').mean()
#     ndf=ndf.apply(pd.to_numeric,downcast='float')
#     #drop event and error
#     ndf = ndf.drop(['Event'], axis=1)
#     if 'CH-4[V]' in ndf.columns: ndf = ndf.drop(['CH-4[V]'], axis=1)
#     list_.append(ndf)
    
#     #drop columns with all nan values
#     ndf=ndf.dropna(axis=1, how='all')
    
#     #clean flow
#     ndf['CH-1[V]'].loc[ndf['CH-1[V]']<prm.V_min-eps]=np.nan
#     ndf['CH-2[V]'].loc[ndf['CH-2[V]']<prm.V_min-eps]=np.nan
#     ndf['CH-3[V]'].loc[ndf['CH-3[V]']<prm.V_min-eps]=np.nan
    
#     #convert flow
#     ndf['CH-1[V]']=((ndf['CH-1[V]']-prm.V_min)/(prm.V_max-prm.V_min))*(prm.flow_max-prm.flow_min)+prm.flow_min
#     ndf['CH-2[V]']=((ndf['CH-2[V]']-prm.V_min)/(prm.V_max-prm.V_min))*(prm.flow_max-prm.flow_min)+prm.flow_min
#     ndf['CH-3[V]']=((ndf['CH-3[V]']-prm.V_min)/(prm.V_max-prm.V_min))*(prm.flow_max-prm.flow_min)+prm.flow_min
    
#     ndf=treatData(ndf)
#     #merge
#     df = pd.concat(df,ndf)

#     #sort
#     df = df.sort_index()
    
#     return df

def createSepDayPlots(df, name, unit, start, end):
    linew=0.5
    ftype = '.png'
    #df=v1.to_frame(name)
    dateRange=pd.date_range(start,end, freq='1D')
    i=0
    for row in dateRange:
        date=str(dateRange[i]).split(' ')[0]
        ax=df[date].plot(lw=linew)
        #ax.set_xticks(np.arange(0,86400,7200))
        #ax.figure.autofmt_xdate()
        art = []
        lgd = ax.legend(loc=9,bbox_to_anchor=(0.5,-0.1), ncol=3)
        art.append(lgd)
        ax.set_ylabel(unit)
        plt.savefig('plots/'+name+date+ftype, dpi=300, additional_artist=art,  bbox_inches='tight')
        #ax.set_xlabel(date)
        #plt.savefig('plots/'+name+date+ftype, dpi=400, bbox_inches='tight')
        plt.close()
        i=i+1
    return


def plotCumDayLines (v1, name, ylab):
    linew=0.5
    ftype = '.png'
    colors=dict(zip([0,1,2,3,4,5,6], ['orange', 'yellow', 'green', 'blue', 'brown', 'black', 'red']))
    df=v1.to_frame(name)
    df.index = [df.index.time, df.index.date]
    df = df.unstack()
    dt = v1.index.freq.delta.seconds
    ax = (df[name].cumsum()*dt).plot(lw=linew, legend=0, color=df[name].columns.map(lambda x:colors[x.dayofweek]))
    ax.set_xticks(np.arange(0,86400,7200))
    ax.figure.autofmt_xdate()
    ax.set_ylabel(ylab)
    #create legend
    costum_lines = [Line2D([0],[0], color=colors[0], lw=1),
        Line2D([0],[0], color=colors[1], lw=1),
        Line2D([0],[0], color=colors[2], lw=1),
        Line2D([0],[0], color=colors[3], lw=1),
        Line2D([0],[0], color=colors[4], lw=1),
        Line2D([0],[0], color=colors[5], lw=1),
        Line2D([0],[0], color=colors[6], lw=1)]
    plt.legend(costum_lines, ['Mon', 'Tue', 'Wed', 'Thr', 'Fri', 'Sat', 'Sun'])
    plt.savefig(name+ftype, dpi=400, bbox_inches='tight')
    plt.clf()
    plt.close()
    return;
    
def plotStackedDayLines (v1, name, unit, unitCum):
    linew=0.5
    ftype = '.png'
    des1 = '_cur'
    des2 = '_cum'
    df=v1.to_frame(name)
    df.index = [df.index.time, df.index.date]
    df = df.unstack()
    ax = df.plot(lw=linew,legend=0)
    ax.set_xticks(np.arange(0,86400,7200))
    ax.figure.autofmt_xdate()
    ax.set_ylabel(unit)
    plt.savefig(name+des1+ftype, dpi=400, bbox_inches='tight')
    plt.close()
    dt = v1.index.freq.delta.seconds
    ax = (df.cumsum()*dt).plot(lw=linew,legend=0)
    ax.set_xticks(np.arange(0,86400,7200))
    ax.figure.autofmt_xdate()
    ax.set_ylabel(unitCum)
    plt.savefig(name+des2+ftype, dpi=400, bbox_inches='tight')
    plt.close()
    return;

def plotStackedWeekdayLines (v1, freq, name, unit):
    linew=0.5
    ftype = '.png'
    #fname = v1.name.split('[')[0]+'StackedWeekdayLines'
    cats = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
    v1=v1.resample(freq).mean()
    df=v1.to_frame(name)
    df['Weekday'] = df.index.weekday_name
    df['Weekday']=pd.Categorical(df['Weekday'],categories = cats)
    df = df.groupby([df.index.time, 'Weekday'])[name].mean().unstack()
    ax = df.plot(lw=linew)
    ax.set_xticks(np.arange(0,86400,7200))
    ax.figure.autofmt_xdate()
    ax.set_ylabel(unit) 
    plt.savefig(name+ftype, dpi=300, bbox_inches='tight')
    plt.close()
    return;
    
def plotSepWeekdayLinesHour (v1, name, unit):
    linew=0.5
    ftype = '.png'
    #fname = v1.name.split('[')[0]+'SepWeekdayLines'
    cats = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
    df=v1.to_frame(v1.name)
    df['Weekday'] = df.index.weekday_name
    df['Weekday']=pd.Categorical(df['Weekday'],categories = cats)
    df = df.groupby([df.index.hour, 'Weekday'])[v1.name].mean().unstack()
    ax = df.plot(lw=linew,subplots=True, sharex=True, sharey=True)
    ax.set_xticks(np.arange(0,86400,7200))
    ax.figure.autofmt_xdate()
    ax.set_ylabel(unit)    #ax.layout(3,3)
    #ax.figure.autofmt_xdate()
    plt.savefig(name+ftype, dpi=300, bbox_inches='tight')
    plt.close()
    return;

    
def plotDailyMean (v1,freq, name, unit, ierr=False):
    linew=0.5
    ftype = '.png'
    #fname = v1.name.split('[')[0]+freq+'Mean'
    v1=v1.resample(freq).mean()
    v1.index = [v1.index.time, v1.index.date]
    if ierr:
        mean=v1.unstack(level=0).mean()
        err=v1.unstack(level=0).std()
        ax=mean.plot(lw=linew,xticks=np.arange(0,86401,14400), xlim=(0,86401),yerr=err, capsize=4)
    else:
        ax=v1.unstack(level=0).mean().plot(lw=linew,xticks=np.arange(0,86401,14400), xlim=(0,86401))
    ax.set_xticks(np.arange(0,86400,7200))
    ax.figure.autofmt_xdate()
    ax.set_ylabel(unit)    
    plt.savefig(name+ftype, dpi=300, bbox_inches='tight')
    plt.close()
    return;
    
def plotMinuteMean (v1):
    linew=0.5
    ftype = '.png'
    fname = v1.name.split('[')[0]+'HourMean'
    df=v1.to_frame(v1.name)
    df = df.groupby([df.index.hour])[v1.name].mean().unstack()
    ax = df.plot(lw=linew,subplots=True, sharex=True, sharey=True)
    #ax.layout(3,3)
    #ax.figure.autofmt_xdate()
    plt.savefig(fname+ftype, dpi=300, bbox_inches='tight')
    plt.close()
    return;    


def getEnergyDf (df):
#    Q_vent = df.P_vent.resample('1H').mean()/1000
#    Q_vent.name = 'Q_vent[kWh]'
    Q_radE = df.P_radE.resample('1H').mean()/1000
    Q_radE.name = 'Q_radE[kWh]'
    Q_radW = df.P_radW.resample('1H').mean()/1000
    Q_radW.name = 'Q_radW[kWh]'
    Q_radTot = df.P_radTot.resample('1H').mean()/1000
    Q_radTot.name = 'Q_radTot[kWh]'
    df_Q=pd.concat([Q_radE, Q_radW, Q_radTot], axis=1)
    return df_Q;
    
def plotEnergyTotal(df_Q):
    fig, ax = plt.subplots()
    df = df_Q.copy(deep=True)
    df.index = [df.index.hour, df.index.date]
    ax=df['Q_vv[kWh]'].unstack(level=0).mean().plot()
    ax=df['Q_vvc[kWh]'].unstack(level=0).mean().plot()
    ax=df['Q_tot[kWh]'].unstack(level=0).mean().plot()
    ax=(df['Q_prodTot[kWh]'].unstack(level=0).mean()).plot()
    ax.legend(['Q_vv', 'Q_vvc', 'Q_tot', 'Q_prod'])
    ax.set_ylabel('kWh/h')
    ax.set_xlabel('Time')
    return 

def plotEnergySource(df_Q):
    df = df_Q.copy(deep=True)
    df.index = [df.index.hour, df.index.date]
    ax=df['Q_VPPre[kWh]'].unstack(level=0).mean().plot()
    ax=df['Q_ElPre[kWh]'].unstack(level=0).mean().plot()
    ax=df['Q_VPPeak[kWh]'].unstack(level=0).mean().plot()
    ax=df['Q_ElPeak[kWh]'].unstack(level=0).mean().plot()
    ax=df['Q_prodTot[kWh]'].unstack(level=0).mean().plot()
    ax.legend(['VP_preheat', 'El_preheat', 'VP_peakheat','El_peakheat', 'Total'])
    ax.set_ylabel('kWh/h')
    ax.set_xlabel('Time')
    return

def plotEnergySourcePie(df_Q):
    df_Q[['Q_VPPre[kWh]', 'Q_ElPre[kWh]', 'Q_VPPeak[kWh]','Q_ElPeak[kWh]']].mean().plot.pie(
            autopct='%.1f%%', figsize=(6,6), 
            labels=['VP forvarming','El forvarming','VP ettervarming', 'El ettervarming'])
    plt.ylabel('')
    return

def plotEnergyLossPie(df_Q):
    df_Q[['Q_vv[kWh]', 'Q_vvc[kWh]', 'Q_ProdLoss[kWh]']].mean().plot.pie(
            autopct='%.1f%%', figsize=(6,6), 
            labels=['Varmtvann','Varmetap sirkulasjon','Varmetap produksjon'])
    plt.ylabel('')
    return
    
def compareNS3031(df_Q):
    fig, ax = plt.subplots()
    df_NS=pd.read_csv('NS3031_2016.csv', skiprows=[1], sep=';', decimal=',', index_col='Time', encoding='ISO-8859-1')
    df_NS.index = pd.date_range('1/1/2018 00:00:00', freq='H', periods=24)
    df_NS.index = [df_NS.index.hour, df_NS.index.date]
    Q_NS = df_NS['Boligblokker'].unstack(level=0).mean().sum()
    df_Meas = df_Q.copy(deep=True)
    df_Meas.index = [df_Meas.index.hour, df_Meas.index.date]
    Q_Meas =(df_Meas['Q_vv[kWh]'].unstack(level=0).mean()/prm.bra*1000).sum()
    ax=df_NS['Boligblokker'].unstack(level=0).mean().plot(drawstyle="steps-post")
    ax=(df_Meas['Q_vv[kWh]'].unstack(level=0).mean()/prm.bra*1000).plot(drawstyle="steps-post")
    ax.legend(['NS3031:2016', 'Q_vv'])
    ax.set_ylabel('Wh/m2')
    return Q_NS, Q_Meas   

def genYearlyDataTable(vv, Q_con, Q_vv):
    ytab = pd.DataFrame(columns=('Name','Total', 'Per m2', 'Per Room'))
    ytab.Name =(['DHW Consumption [Liter]', 'Energy for DHW [kWh]', 'Heat Loss [kWh]'])
    dt = vv.index.freq.delta.seconds
    vv.index = [vv.index.time, vv.index.date]
    ytab.loc[0,'Total']=vv.unstack(level=0).mean().sum()*dt*365
    ytab.loc[0,'Per m2']=vv.unstack(level=0).mean().sum()*dt*365/prm.bra
    ytab.loc[0,'Per Room']=vv.unstack(level=0).mean().sum()*dt*365/prm.nRoom
    
    Q_con.index = [Q_con.index.hour, Q_con.index.date]
    ytab.loc[1,'Total']=Q_con.unstack(level=0).mean().sum()*365
    ytab.loc[1,'Per m2']=Q_con.unstack(level=0).mean().sum()*365/prm.bra
    ytab.loc[1,'Per Room']=Q_con.unstack(level=0).mean().sum()*365/prm.nRoom
    
    Q_vv.index = [Q_vv.index.hour, Q_vv.index.date]
    ytab.loc[2,'Total']=ytab.loc[1,'Total']-Q_vv.unstack(level=0).mean().sum()*365
    ytab.loc[2,'Per m2']=ytab.loc[1,'Per m2']-Q_vv.unstack(level=0).mean().sum()*365/prm.bra
    ytab.loc[2,'Per Room']=ytab.loc[1,'Per Room']-Q_vv.unstack(level=0).mean().sum()*365/prm.nRoom
    ytab.set_index('Name')
    return ytab    

def genMaximumCurves(kvt,vv,vvc,start,end,freq): #start, end and freq in seconds
    dfmax = pd.DataFrame(columns=('kvt', 'vv', 'vvc'))
    for i in range(int(end/freq)):
        j=i*freq+start
        f = str(j)+'S'
        dfmax.loc[j]=[kvt.resample(f).mean().max(), 
                 vv.resample(f).mean().max(),
                 vvc.resample(f).mean().max()]
    dfmax['Time [s]']=pd.timedelta_range(str(start)+' Seconds',str(end-freq)+' Seconds',freq=str(freq)+'S').seconds
    dfmax.set_index('Time [s]', inplace=True)
    return dfmax

def genMaximumCurve(s,name,start,end,freq): #start, end and freq in seconds):
    dfmax = pd.DataFrame()
    dfmax[name]=0
    for i in range(int(end/freq)):
        j=i*freq+start
        f = str(j)+'S'
        dfmax.loc[j]=[s.resample(f).mean().max()]
    dfmax['Time [s]']=pd.timedelta_range(str(start)+' Seconds',str(end-freq)+' Seconds',freq=str(freq)+'S').seconds
    dfmax.set_index('Time [s]', inplace=True)
    return dfmax

def genRollingMaximumCurve(s,name,start,end): #start, end and freq in seconds):
    dfmax = pd.DataFrame(columns=['Time [s]', name])
    for i in range(int(np.sqrt(end))):
        freq = str(start+i*i)+'S'
        dfmax.loc[i]=[(start+i*i), s.rolling(freq).mean().max()]
    ie=int(np.sqrt(end))
    freq = str(ie*ie)+'S'
    dfmax.loc[ie]=[(ie*ie), s.rolling(freq).mean().max()]
    dfmax.set_index('Time [s]', inplace=True)
    return dfmax

def plotmaxPerDay(s, ylab):
    df=pd.DataFrame()
    df['S']=s.resample('1D').max()
    df['dow']=df.index.dayofweek
    df.index=df.index.date
    colors = dict(zip([0,1,2,3,4,5,6], ['orange', 'yellow', 'green', 'blue', 'brown', 'black', 'red']))
    ax=df.S.plot.bar(rot=0, color=df.dow.map(lambda x: colors[x]))
    #set x-ticks
    n=7
    ticks = ax.xaxis.get_ticklocs()
    ticklabels = [l.get_text() for l in ax.xaxis.get_ticklabels()]
    ax.xaxis.set_ticks(ticks[::n])
    ax.xaxis.set_ticklabels(ticklabels[::n])
    ax.set_ylabel(ylab)
    costum_lines = [Line2D([0],[0], color=colors[0], lw=5),
        Line2D([0],[0], color=colors[1], lw=5),
        Line2D([0],[0], color=colors[2], lw=5),
        Line2D([0],[0], color=colors[3], lw=5),
        Line2D([0],[0], color=colors[4], lw=5),
        Line2D([0],[0], color=colors[5], lw=5),
        Line2D([0],[0], color=colors[6], lw=5)]
    plt.legend(costum_lines, ['Mon', 'Tue', 'Wed', 'Thr', 'Fri', 'Sat', 'Sun'])
    return ax




