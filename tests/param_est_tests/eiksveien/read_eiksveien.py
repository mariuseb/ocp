# -*- coding: utf-8 -*-
"""
Created on Thu Sep  5 08:36:25 2024

@author: hwaln
"""

#import os
import pandas as pd
#import numpy as np
#import pprint
import matplotlib.pyplot as plt
from analyse import apt_rooms
import math
import numpy as np 


def get_room_setpoints(df):
    """ Get room setpoints per apt. """
    prbs = pd.read_excel("PRBS.xlsx", sheet_name="PRBS_datetime")
    room_sps_base = pd.read_excel("settpunkter_eiksveien.xlsx")
    room_sps_base.index = room_sps_base.rom
    # only 7 days:
    prbs = prbs[0:3*168]
    # reindex w/ actual dates:
    index = pd.date_range(
        start="2025-02-09 00:00",
        end="2025-02-15 23:40",
        freq="20min"
        )
    prbs.index = index
    #prbs.loc[pd.Timestamp("2025-02-16 00:00:00")] = 0
    prbs = prbs["Signal"].sort_index()
    #prbs = prbs.resample(rule="5min").ffill()
    room_sps = pd.DataFrame(
        index=index,
        columns=room_sps_base.index
    )
    new_cols = {
      k: str(k) for k in room_sps.columns
    }
    room_sps.rename(columns=new_cols, inplace=True)
    for ndx in room_sps_base.index:
        room_sps.loc[:, str(ndx)] = room_sps_base.loc[ndx, "verdi"]
    num_weeks = math.ceil(
        (df.index[1] - df.index[0]
    ).seconds*len(df)/(86400*7))
    # triple length:
    room_sps = pd.concat([
      room_sps
    ]*num_weeks)
    #last_ndx = room_sps.index[-1] + pd.Timedelta(weeks=num_weeks-1)
    #start = df.index[0] - pd.Timedelta("1D")
    #end = df.index[-1] - pd.Timedelta("1D")
    start = df.index[0]
    end = df.index[-1]
    new_index = pd.date_range(
        #start=room_sps.index[0],
        start=start,
        end=end,
        freq="20min"
        )
    room_sps.index = new_index
    #room_sps = room_sps.resample(rule="5min").ffill()
    room_sps.index = room_sps.index.tz_convert('Etc/GMT-1')
     
    shift = get_shift(
        prbs,
        df,
        num_weeks=num_weeks+1,
        start=start-pd.Timedelta("1day"),
        stop=end-pd.Timedelta("1day")
    )
    shift = shift.loc[
        room_sps.index[0]:room_sps.index[-1]
    ]
    # add shift, but only on experiment duration:
    #shift = prbs.Signal*2
    for col in room_sps.columns:
        room_sps[col] += shift
    room_sps = room_sps.resample(rule="5min").ffill()
    """
    room_sps.loc[
        room_sps.index[-1] + pd.Timedelta(minutes=5)
    ] = room_sps.loc[room_sps.index[-1]]
    """
    return room_sps, shift


def get_shift(
    signal,
    df,
    num_weeks=1,
    start=None,
    stop=None,
    exp_start=pd.Timestamp(
        "02-13-2025 00:00"
    ).tz_localize('Etc/GMT-1'),
    exp_stop=pd.Timestamp(
        "03-05-2025 00:00"
    ).tz_localize('Etc/GMT-1')
):
    """ Setpoint shift. """
    #dt_index = signal.index
    signal = pd.concat([
      signal
    ]*num_weeks) 
    #dt_index = signal.index
    signal.index = range(len(signal.index))
    signal.index = pd.date_range(
        start=start,
        periods=len(signal), 
        freq="20min"
    )
    shift = signal*2
    shift.loc[:exp_start] = 0
    shift.loc[exp_stop:] = 0
    return shift
    
    
def plot_shift(shift):
    fig, ax = plt.subplots(1,1, figsize=(8,6))
    shift.plot(drawstyle="steps-post", ax=ax)
    ax.set_ylabel("$\Delta{T}_{set}$ [$^\circ$C]")
    plt.show()
    

def space_out_ylim(ax, factor=1.1):
    ylims = ax.get_ylim()
    ax.set_ylim([ylims[0], ylims[1]*factor])

def _plot_apt(apt_df, room_sps, apt=None, include_bath=True):
    """ Plot apartment w/ setpoints. """
    rooms = apt_rooms[apt]
    if not include_bath:
        rooms = rooms[:-1]
        nsubs = 3
    else:
        nsubs = 4
    fig, axes = plt.subplots(nsubs,1, sharex=True, figsize=(8,nsubs*2))
    
    apt_df[rooms] = room_sps.loc[apt_df.index, rooms]

    for i, room in enumerate(rooms):
        temp = f"""1273_563_{room}_RT601"""
        if room.endswith("4"):
            power = f"""1273_563_{room}_LZ001"""
        else:
            power = f"""1273_563_{room}_SC501"""
        apt_df[temp].plot(ax=axes[i], drawstyle="steps-post")
        apt_df[room].plot(ax=axes[i], drawstyle="steps-post")
        axes[i].legend([temp, room + "_SP"], ncol=2, loc="upper left")
        axes[i].set_ylabel("Temperature [$^\circ$C]")
        space_out_ylim(axes[i], factor=1.05)
        ax1 = axes[i].twinx()
        apt_df[power].plot(
            ax=ax1, 
            color="r",
            linestyle="dashed", 
            drawstyle="steps-post",
            linewidth=0.7
        )
        space_out_ylim(ax1, factor=1.3)
        ax1.legend(["valve on"], loc="upper right")
        ax1.set_yticks([0,1])
    fig.tight_layout()
    plt.show()


def get_heating_central_data(df, room_sps, sampling_time):
    """ Get heating central data. """
    #rooms = np.array(list(apt_rooms.values())).flatten()
    pumps = [
            col for col in df.columns if "563" in col \
            and "SC501" in col \
            #and col.split("_")[2] in rooms \
            and "SP" not in col
            ]
    pump_sig = df[pumps].sum(axis=1)

    outdoor = [col for col in df.columns if "RT901" in col and "320" in col]
    #vent_dhw  = [col for col in df.columns if "320" in col and "OE" and ("003" in col or "004" in col)]
    hea_cent = df[[col for col in df.columns if "320" in col]]
    hea = (hea_cent[['1273_320_002_OE401', '1273_320_001_OE501', '1273_320_003_OE401_total']].diff(1)*12).fillna(0)
    #hea = hea.to_frame()
    hea.columns = ["Q_sh", "Q_hp", "Q_dhw"]
    hea["El_hp"] = df['1273_320_OE003_Mom.Effekt']
    hea["El_hp_acc"] = df['1273_320_OE003_Energi_Tot'].diff(1)
    hea["Tsup_sh"] = df['1273_320_002_RT401']
    hea["Tret_sh"] = df['1273_320_002_RT501']
    hea["Tsup_before_acc"] = df['1273_320_001_RT401']
    hea["Tret_before_acc"] = df['1273_320_001_RT501']
    hea["Tsup_boi"] = df['1273_320_001_RT503']
    hea["Tout"] = df[outdoor]
    hea["pump_sig"] = pump_sig
    #hea["Q_hp"] = df['1273_320_OE003_Mom.Effekt']
    hea["signal"] = (room_sps.loc[hea.index, "1060"] - 22)/2
    hea["Tsup_SPK_hp"] = 41 - (hea["Tout"] + 25)*(10/45)
    hea["Tsup_SPK"] = 33.5 - (hea["Tout"] + 20)*(5/45)
    hea = hea.resample(rule=sampling_time).mean()
    #return hea.iloc[1:]
    return hea

def gridify_axes(axes):
    for _ax in axes:
        #_ax.xaxis.set_major_locator(dloc)
        #_ax.xaxis.set_minor_locator(hloc)
        _ax.grid(which="both")
        _ax.grid(which='minor', alpha=0.2)
        _ax.grid(which='major', alpha=0.5)

def plot_heating_central_data(hea, start, stop):
    """ Plot heating central data. """
    hea = hea.loc[start:stop]
    fig, axes = plt.subplots(4,1, sharex=True)
    ax = axes[0]
    hea.Q_hp.plot(drawstyle="steps-post", ax=ax, linewidth=0.75)
    (hea.El_hp_acc*12).plot(drawstyle="steps-post", color="b", ax=ax, linewidth=0.75)
    #hea.Q_dhw.plot(drawstyle="steps-post", ax=ax)
    hea.Q_sh.plot(drawstyle="steps-post", ax=ax, linewidth=0.75)
    ax.legend(["$Q_{hp}$", "$P_{hp}$", "$Q_{sh}$"], loc="upper left", ncol=3, bbox_to_anchor=[0,1.4])
    ax.set_ylabel("Power [kW]")
    ax1 = ax.twinx()
    hea["signal"].plot(drawstyle="steps-post", ax=ax1, color="r", linewidth=0.75)
    ax1.set_ylabel("Setpoint shifted")
    ax = axes[1]
    hea["pump_sig"].plot(ax=ax, drawstyle="steps-post")
    ax.set_ylabel("\# of valves open")
    ax = axes[2]
    hea["Tsup_sh"].plot(drawstyle="steps-post", ax=ax, color="r", linewidth=0.75)
    #apt_df['1273_563_1072_RT601'].plot(drawstyle="steps-post", ax=ax, color="y", linewidth=0.5)
    #hea["Tsup_boi"].plot(drawstyle="steps-post", ax=ax, color="y", linewidth=0.5)
    hea["Tsup_SPK"].plot(drawstyle="steps-post", ax=ax, color="g", linewidth=0.75)
    #hea["Tsup_SPK_hp"].plot(drawstyle="steps-post", ax=ax, color="g", linewidth=0.5)
    hea["Tret_sh"].plot(drawstyle="steps-post", ax=ax, color="b", linewidth=0.75)
    #(hea["Tsup_sh"] - hea["Tret_sh"]).plot(drawstyle="steps-post", ax=ax, color="y", linewidth=0.5)
    #hea["Tsup_before_acc"].plot(drawstyle="steps-post", ax=ax, color="k", linewidth=0.5)
    #hea["Tsup_SPK"].plot(drawstyle="steps-post", ax=ax, color="g", linewidth=0.5)
    #hea["Tret_before_acc"].plot(drawstyle="steps-post", ax=ax, color="m", linewidth=0.5)
    ax.legend(["$T_{ret}^{sh}$", "$T_{sup}^{sh}$", "$T_{sup}^{spc}$"], loc="upper left", ncol=3, bbox_to_anchor=[0,1.4])
    ax = axes[3]
    hea["Tout"].plot(drawstyle="steps-post", ax=ax, color="b", linewidth=0.75)
    ax.legend(["$T_{amb}$"])
    ax.set_ylabel("Temperature [$^\circ$C]")
    #ax = axes[4]
    #hea["Tsup_before_acc"].plot(drawstyle="steps-post", ax=ax, color="r", linewidth=0.5)
    #hea["Tsup_SPK"].plot(drawstyle="steps-post", ax=ax, color="g", linewidth=0.5)
    #hea["Tret_before_acc"].plot(drawstyle="steps-post", ax=ax, color="b", linewidth=0.5)
    # show:
    gridify_axes(axes)
    return fig, axes
    
    
def append_to_apt_plot(fig, ax, df, shift, hea):
    ax2 = ax[1].twinx()
    #ax1.plot(shift, drawstyle="steps-post", color="k")
    shift.plot(ax=ax2, drawstyle="steps-post", color="k", linewidth=0.7)
    hea.Q_sh.plot(ax=ax[1], drawstyle="steps-post", color="y")
    ax[0].legend(["Average temp. apts"])
    ax[1].legend(["Q_sh_apts", "Q_sh_tot"], ncol=2, loc="upper left")
    ax2.legend(["$\Delta{T}_{set}$ [$^\circ$C]"], loc="upper right")
    ax[1].set_ylim([0, 30])
    ax2.set_ylim([0, 2.5])
    fig.tight_layout()
    for _ax in ax:
        #_ax.xaxis.set_major_locator(dloc)
        #_ax.xaxis.set_minor_locator(hloc)
        _ax.grid(which="both")
        _ax.grid(which='minor', alpha=0.2)
        _ax.grid(which='major', alpha=0.5)
    plt.show()
    
def finalize_apt_df(
        name_map, 
        areas,
        apt_df,
        hea,
        start,
        stop,
        sampling_time="20min"
    ):
    data = apt_df.loc[:, list(name_map.keys())].rename(
        columns=name_map
    )
    area_tot = sum(
    list(areas.values())
    )
    data["Ti"] = (data["Tbedr"]*areas["Tbedr"] + \
                        data["Tliv"]*areas["Tliv"] + \
                            data["Thall"]*areas["Thall"]) \
                            / \
                      area_tot
                      
    #data = data.resample(rule=sampling_time).mean()
    
    apt_valves = [
                  col for col in
                  apt_df.columns if 
                  "SC" in col
                  ]
    
    valve_frac = apt_df[apt_valves].sum(axis=1)/(hea["pump_sig"])
    #valve_frac = apt_df[apt_valves].sum(axis=1)/33
    Q_sh_apt = valve_frac*hea["Q_sh"]
    data["phi_h"] = Q_sh_apt*1000
    data["phi_h_int"] = data["phi_h_int"].diff(1).fillna(0)*1000
        
    data = data.resample(rule=sampling_time).mean()
    
    # correction:
    #data["phi_h"] /= 3
    data["phi_h_int"] *= 12
        
    data["Ti"] += 273.15
    data["Tbedr"] += 273.15
    data["Tbath"] += 273.15
    data["Ta"] += 273.15
    # area of bathroom:
    A = 9.1
    # on/off to power:
    W_p_sqm = 150
    data["phi_h_bath"] *= W_p_sqm*A
    
    return data, area_tot

def finalize_df(
    df,
    sampling_time,
    start,
    stop
):
    df = df.sort_index()
    df.loc["2025-03-03 00:00"] = np.nan 
    df = df.interpolate()
        # experiment period:
    room_sps, shift = get_room_setpoints(df)
    # cut some data:
    room_sps = room_sps.loc[start:stop]
    df = df.loc[start:stop]
    # more extraction, plotting:
    hea = get_heating_central_data(df, room_sps, sampling_time)
    
    return df, hea, room_sps

def generate_door_window_openings(
    y_data,
    door_lim=0.35,
    window_lim=0.2
):
    y_data["delta_Ti"] = (y_data["y1"] - y_data["y1"].shift(1))
    door = (y_data["delta_Ti"] < -door_lim)
    window = ((y_data["delta_Ti"] > -door_lim) & (y_data["delta_Ti"] < -window_lim))
    y_data["door"] = door.shift(-1).fillna(False).astype(int)
    y_data["window"] = window.shift(-1).fillna(False).astype(int)
    return y_data
    
    
    