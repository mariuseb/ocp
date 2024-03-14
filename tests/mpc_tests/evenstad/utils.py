# -*- coding: utf-8 -*-
"""
Created on Wed Oct 19 07:42:07 2022

@author: hwaln

Module to recieve weather forecast from Met Norway Thredds Service
https://github.com/metno/NWPdocs/wiki/MET-Nordic-dataset
"""

import netCDF4
import pyproj
import numpy as np
import pandas as pd
import time
from collections import OrderedDict
#Create a format to change the data with a for loop
WEB_latest = u'https://thredds.met.no/thredds/dodsC/metpplatest/met_forecast_1_0km_nordic_latest.nc'
#WEB_latest_hist = u'https://thredds.met.no/thredds/dodsC/metpparchive/2021/08/01/met_analysis_1_0km_nordic_20210801T12Z.nc'

def get_forecast(index, location, forecast_map, forecasts=['Ta', 'phi_s'], test=False):

    index_=index.tz_convert('UTC') #convert to same timezone as NWP data

    try:
        if test: # historical
            year = index.year
            month = index.month
            day = index.day
            hour = index.hour
            if month < 10:
                month = "0" + str(month)
            else:
                month = str(month)
            #WEBfo = 'https://thredds.met.no/thredds/dodsC/metpparchive/%s/0%s/%s/met_forecast_1_0km_nordic_%s%s%sT00Z.nc' % (year, month, day)
            WEBfo = 'https://thredds.met.no/thredds/dodsC/metpparchive/%s/%s/%s/met_forecast_1_0km_nordic_%s%s%sT12Z.nc' % (year, month, day, year, month, day)
            data = netCDF4.Dataset(WEBfo, "r")
        else: # latest
            data = netCDF4.Dataset(WEB_latest, "r")

    except Exception as err:
        print(f'Warning: not able to recieve forecast with error: {err}')
        return None

    try:
        proj4='+proj=lcc +lat_0=63 +lon_0=15 +lat_1=63 +lat_2=63 +no_defs +R=6.371e+06'
        proj = pyproj.Proj(proj4)
        trans = pyproj.Transformer.from_pipeline(proj4)

        # Compute projected coordinates of lat/lon point
        X, Y = proj(location['lon'], location['lat'])

        # Find nearest neighbour
        x = data.variables["x"][:]
        y = data.variables["y"][:]
        Ix = np.argmin(np.abs(x - X))
        Iy = np.argmin(np.abs(y - Y))
        lat_act = np.abs(x - X)[Ix]
        lon_act = np.abs(y - Y)[Iy]

        _X, _Y = trans.transform(lon_act, lat_act)

        times = pd.DatetimeIndex(data.variables["time"][:].data.flatten().astype('datetime64[s]'), tz='UTC')
        variables={}
        for var in forecasts:
            variables[var] = data.variables[forecast_map[var]][:, Iy, Ix].data.flatten()
        df=pd.DataFrame(index=times, data=variables)
        if 'phi_s' in df.columns: #derivate solGlo
            df.phi_s=df.phi_s.diff().shift(-1)/3600
        df.index=df.index.tz_convert("Europe/Oslo")
        #forecastdf=df.resample(index.freqstr).asfreq().interpolate('linear').reindex(index)
        return df
    except Exception as err:
        print(f'Warning: not able to extract forecast with error: {err}')
        return None
    

def prepare_data(file1, file2):
    """
    Necessary operations on data to conform with model.
    """  
    names = [
    "Vtot",
    "Tsup_water_west_int",
    "Tret_water_west_int",
    "P_water_central",
    "Tsup_water_west",
    "Tret_water_west",
    "P_water",
    "V_flow",
    "E_tot",
    "valve",
    "V_flow_sup_air",
    "V_flow_exh_air",
    "Tsup_air",
    "Ti_113",
    "Tset_113",
    "Ti_117",
    "Tset_117",
    "Ti_119",
    "Tset_119",
    "Ti_123",
    "Tset_123",
    "Ti_124",
    "Tset_124",
    "Ti_125",
    "Tset_125",
    "Tret_air",
    "Ti_101",
    "Tset_101",
    "Ti_103",
    "Tset_103",
    "Ti_104",
    "Tset_104",
    "Ti_105",
    "Tset_105",
    "Ti_106",
    "Tset_106",
    "Ti_107",
    "Tset_107",
    "Ti_110",
    "Tset_110",
    "Ti_office_2nd_floor_n",
    "Ti_office_2nd_floor_s",
    "Trec_air",
    "E_in_xf53",
    "E_xf53",
    "phi_s",
    "Ta"
    ]
    
    sep = ","
    data1 = pd.read_csv(file1, sep=sep, skiprows=[1,2,3], header=0, index_col=0)
    data2 = pd.read_csv(file2, sep=sep, skiprows=[1,2,3], header=0, index_col=0)
    meas = pd.merge(data1, data2, left_index=True, right_index=True)

    #for name in meas.columns:
    #    print(name)
    
    # ordered:
    cols = list(meas.columns)
    name_pairs = []
    for i, col in enumerate(cols):
        name_pairs.append((col, names[i]))
    name_map = OrderedDict(name_pairs)
    meas = meas.rename(columns=name_map)

    """
    Convert str -> float:
    """
    for col in meas.columns:
        try:
            meas[col] = meas[col].astype(float)
        except ValueError:
            meas[col] = meas[col].apply(lambda x: str(x).replace(" ", "")).astype(float)       

    # Datetime-index
    meas.index = pd.to_datetime(meas.index, format="%d.%m.%Y %H:%M")

    """
    Take out only model-relevant quantities:
    """
    temp_cols = [col for col in meas.columns if "Ti_" in col 
                and "office" not in col
                and "113" not in col
                and "101" not in col]
    meas["Ti"] = meas["Ti_117"]
    
    rho_air = 1.204 # [kg/m^3]
    cp_air = 1000 # [J/kg*K]

    vent_in = (meas["Tsup_air"] - meas["Ti"])*(meas.V_flow_sup_air/3600)*rho_air*cp_air
    vent_out = (meas["Ti"] - meas["Tsup_air"])*(meas.V_flow_exh_air/3600)*rho_air*cp_air
    vent_net = vent_in + vent_out
    meas["P_vent"] = vent_net
    
    # resample to 1H:
    
    # set names:
    meas["P_water"] *= 1000
    meas["Ti"] += 273.15
    meas["Tsup_air"] += 273.15
    # 'filter' out circulation loss:
    #meas.P_water[meas.P_water < 5] = 0
    phi_h = meas["P_water"].resample(rule="1h").mean()
    meas = meas.resample(rule="1h").asfreq()
    meas["phi_h"] = phi_h # to Watts
    meas["Tsup"] = meas["Tsup_water_west"]
    meas["Tret"] = meas["Tret_water_west"]
    meas["m_flow_water"] = (meas["Tsup"] - meas["Tret"])*4200/(meas["phi_h"])
    meas["T_sup_air"] = meas["Tsup_air"]
    meas["y1"] = meas["Ti"]
    meas["y2"] = meas["phi_h"]
    
    meas = meas.bfill()

    return meas