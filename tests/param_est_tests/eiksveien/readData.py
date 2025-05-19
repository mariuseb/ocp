# -*- coding: utf-8 -*-
"""
Created on Wed Sep 28 13:29:17 2022

@author: hwaln
"""

import pandas as pd

Area=973+211
Area_apt=60*12
Area_com=Area-Area_apt

fname_tot='Varme2.csv'
fname_apt1='Leiligheter1etg.txt'
fname_apt2='Leiligheter2etg.txt'

df_tot=pd.read_csv(fname_tot, sep=';', index_col=0)
df_tot.index=pd.to_datetime(df_tot.index)
df_tot.columns=['El_dhw', 'El_Boil', 'Ht_HP', 'Ht_floor', 'Ht_PreDhw', 'Ht_vent' ]
df_tot=df_tot.ffill().bfill()
df_tot=df_tot-df_tot.iloc[0]
df_tot['Ht_Tot']=df_tot[['El_dhw', 'El_Boil', 'Ht_HP']].sum(axis=1)
df_tot['Ht_Space']=df_tot[['Ht_floor', 'Ht_vent']].sum(axis=1)
df_tot['Ht_Dhw']=df_tot[['El_dhw', 'Ht_PreDhw']].sum(axis=1)

df_tot.plot()

df_apt1=pd.read_csv(fname_apt1, sep=';', index_col=0)
df_apt1.index=pd.to_datetime(df_apt1.index)
df_apt1=df_apt1.ffill().bfill()
df_apt1=df_apt1-df_apt1.iloc[0]
df_apt1['Ht_etg1']=df_apt1.sum(axis=1)
df_apt1=df_apt1.resample('1H').mean()
df_apt2=pd.read_csv(fname_apt2, sep=';', index_col=0)
df_apt2.index=pd.to_datetime(df_apt2.index)
df_apt2=df_apt2.ffill().bfill()
df_apt2=df_apt2-df_apt2.iloc[0]
df_apt2['Ht_etg2']=df_apt2.sum(axis=1)
df_apt2=df_apt2.resample('1H').mean()
df_apt=pd.concat([df_apt1, df_apt2], axis=1)
df_apt['Ht_apt']=df_apt.Ht_etg1+df_apt.Ht_etg2

df_tot['Ht_floor_apt']=df_apt['Ht_apt']
df_tot['Ht_floor_com']=df_tot.Ht_floor-df_tot.Ht_floor_apt
df_tot['Ht_space_com']=df_tot.Ht_floor_com+df_tot.Ht_vent
