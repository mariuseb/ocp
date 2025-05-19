# -*- coding: utf-8 -*-
"""
Created on Tue Feb 21 07:50:02 2023

@author: hwaln
"""

import pandas as pd
import os
import numpy as np
import matplotlib.pyplot as plt

parsed_data_dir = "./parsed/"

apt_rooms = {
    "H0101": ["1060", "1062", "1063", "1064"],
    "H0102": ["1070", "1072", "1073", "1074"],
    "H0103": ["1010", "1012", "1013", "1014"],
    "H0104": ["1020", "1022", "1023", "1024"],
    "H0105": ["1030", "1032", "1033", "1034"],
    "H0106": ["1050", "1052", "1053", "1054"],
    "H0201": ["1060", "1062", "1063", "1064"],
    "H0202": ["2070", "2072", "2073", "2074"],
    "H0203": ["2010", "2012", "2013", "2014"],
    "H0204": ["2020", "2022", "2023", "2024"],
    "H0205": ["2030", "2032", "2033", "2034"],
    "H0206": ["2050", "2052", "2053", "2054"],
}

# appartment agg lists
all_apts = [x for x in apt_rooms.keys()]
first_floor = [x for x in apt_rooms.keys() if "H01" in x]
second_floor = [x for x in apt_rooms.keys() if "H02" in x]

south_facade = ["H0102", "H0103", "H0104", "H0202", "H0203", "H0204"]
north_facade = ["H0101", "H0105", "H0106", "H0201", "H0205", "H0206"]


def concat_log(directory=parsed_data_dir):
    dfs = []
    for f in os.listdir(directory):
        if f.endswith(".csv"):
            dfs.append(
                pd.read_csv(directory + f, sep=";", index_col=0, parse_dates=True)
            )

    df = pd.concat(dfs)
    if len(df[df.index.duplicated(keep=False)]) > 0:
        print("Warning: duplicate indexes, removing:")
        print(df[df.index.duplicated(keep=False)])
        df = df[~df.index.duplicated()]
    df = df.tz_convert("Etc/GMT-1")
    return df


def search_tags(search_list, system=None, subsystem=None, component=None, drop=None):

    # search system
    if system is None:
        res_tags = search_list
    else:
        res_tags = [x for x in search_list if f"_{system}_" in x]

    # search subsystem
    if subsystem is None:
        res_tags = res_tags
    else:
        res_tags = [x for x in res_tags if f"_{subsystem}_" in x]

    # search component id
    if component is None:
        res_tags = res_tags
    else:
        res_tags = [x for x in res_tags if f"{component}" in x]

    # drop component id
    if drop is None:
        res_tags = res_tags
    else:
        res_tags = [x for x in res_tags if f"{drop}" not in x]

    return res_tags


def create_tag(system, subsystem, component):
    return "_".join(["1273", system, subsystem, component])


def zero_to_nan(df):

    tag_list = []

    for apt in all_apts:
        for room in apt_rooms[apt]:
            # room temperature
            tag_list.append(create_tag("563", room, "RT601"))
        # ventilation extract
        tag_list.append(create_tag("360", apt[2:], "RT501"))
        # heating
        tag_list += search_tags(
            df.columns, system="320", subsystem="002", component=f"OE{apt[2:]}"
        )
        # dhw
        tag_list += search_tags(
            df.columns, system="310", subsystem="001", component=f"RF{apt[2:]}"
        )

    # Common energy
    tag_list += search_tags(df.columns, component="total")
    tag_list += search_tags(df.columns, component="Energi_")

    tag_list += [
        "1273_320_002_OE401",
        "1273_320_001_OE501",
        #"1273_432_101_RE001_energi_tot",
        "1273_360_001_SFP",
    ]

    tag_list = list(set(tag_list))
    df[tag_list] = df[tag_list].mask(df[tag_list].eq(0))
    return df


def plot_apt(df, apt="H0101", freq="5min", acc=False):
    fig, ax = plt.subplots(4, 1, sharex=True)

    # temperatures
    ax_ = ax[0]
    tag_list = []
    tag_list_tot = []
    # room temperature
    for room in apt_rooms[apt]:
        tag_list.append(create_tag("563", room, "RT601"))
    # ventilation extract
    tag_list.append(create_tag("360", apt[2:], "RT501"))
    # 
    tag_list_tot.extend(tag_list)
    # plot
    df[tag_list].resample(freq).nearest().plot(ax=ax_, lw=0.5)

    # mean room temp
    df[tag_list[:-2]].mean(axis=1).resample(freq).nearest().plot(ax=ax_)

    ax_.legend(apt_rooms[apt] + ["Vent_ext"] + ["mean"])

    # actuators
    ax_ = ax[1]
    tag_list = []
    for room in apt_rooms[apt]:
        tag_list += search_tags(
            df.columns, system="563", subsystem=room, component="SC", drop="_SP"
        )
        tag_list += search_tags(
            df.columns, system="563", subsystem=room, component="LZ", drop="_SP"
        )
    #
    tag_list_tot.extend(tag_list)
    # plot
    df[tag_list].resample(freq).mean().plot(ax=ax_, drawstyle="steps-post")
    ax_.legend(["_".join(x.split("_")[2:]) for x in tag_list])

    # heating
    ax_ = ax[2]
    tag_list = []
    tag_list += search_tags(
        df.columns, system="320", subsystem="002", component=f"OE{apt[2:]}"
    )
    #
    tag_list_tot.extend(tag_list)

    if acc:
        df[tag_list].resample(freq).nearest().plot(ax=ax_, drawstyle="steps-post")
    else:
        df[tag_list].diff().resample(freq).sum().plot(ax=ax_, drawstyle="steps-post")
    ax_.legend(["Space Heating"])

    # hot water
    ax_ = ax[3]
    tag_list = []
    tag_list += search_tags(
        df.columns, system="310", subsystem="001", component=f"RF{apt[2:]}"
    )
    #
    tag_list_tot.extend(tag_list)
    if acc:
        df[tag_list].resample(freq).nearest().plot(ax=ax_, drawstyle="steps-post")
    else:
        df[tag_list].diff().resample(freq).sum().plot(ax=ax_, drawstyle="steps-post")
    ax_.legend(["DHW"])
    
    return df[tag_list_tot]


def plot_agg_apt(df, apts, freq="5min", acc=False, plot_individual=True):
    fig, ax = plt.subplots(3, 1, sharex=True, figsize=(8,6))

    # temperatures
    ax_ = ax[0]
    tag_list = []
    # room temperature
    for apt in apts:
        tag_list_apt = []
        for room in apt_rooms[apt]:
            tag_list_apt.append(create_tag("563", room, "RT601"))
        tag_list_apt = tag_list_apt[:-1]  # Remove bathroom
        # plot
        if plot_individual:
            df[tag_list_apt].mean(axis=1).resample(freq).nearest().plot(ax=ax_, lw=0.5)
        tag_list += tag_list_apt
    # mean room temp
    df[tag_list].mean(axis=1).resample(freq).nearest().plot(ax=ax_)
    # plot setpoint shift:
    ax_.legend(apts + ["mean"])
    ax_.set_ylabel("Temperature [$^\circ$C]")

    # heating
    ax_ = ax[1]
    tag_list = []
    for apt in apts:
        tag_list += search_tags(
            df.columns, system="320", subsystem="002", component=f"OE{apt[2:]}"
        )
 
    ser = df[tag_list].diff().sum(axis=1).resample(freq).sum()
    factor = 3600/((ser.index[1] - ser.index[0]).seconds)
    ser *= factor
    df["Q_sh_acc_apt"] = df[tag_list].diff().sum(axis=1)
    
    if acc:
        df[tag_list].sub(df[tag_list].iloc[0]).sum(axis=1).resample(
            freq
        ).nearest().plot(ax=ax_, drawstyle="steps-post")
    else:
        ser.plot(
            ax=ax_, drawstyle="steps-post"
        )
    ax_.legend(["Space Heating"])
    ax_.set_ylabel("Space heating [kW]")

    # outdoor temp:
    ax_ = ax[2]
    df["Tout"].plot(
            ax=ax_, drawstyle="steps-post"
    )
    ax_.legend(["Tout"])
    ax_.set_ylabel("Temperature [$^\circ$C]")
    
    # hot water: 
    """
    tag_list = []
    for apt in apts:
        tag_list += search_tags(
            df.columns, system="310", subsystem="001", component=f"RF{apt[2:]}"
        )

    if acc:
        df[tag_list].sub(df[tag_list].iloc[0]).sum(axis=1).resample(
            freq
        ).nearest().plot(ax=ax_, drawstyle="steps-post")
    else:
        df[tag_list].diff().sum(axis=1).resample(freq).sum().plot(
            ax=ax_, drawstyle="steps-post"
        )
    ax_.legend(["DHW"])
    """
    return fig, ax, df


# DHW consumption
def create_dhw_data(df, freq="1h"):
    tag_list = []
    for apt in all_apts:
        tag_list += search_tags(
            df.columns, system="310", subsystem="001", component=f"RF{apt[2:]}"
        )

    df_dhw = df[tag_list].diff().resample(freq).sum().mul(1000)
    df_dhw.columns = all_apts
    df_dhw["total_apt"] = df_dhw.sum(axis=1)
    df_dhw["Q_vvb"] = df["1273_320_OE001_Energi_Tot"].diff().resample(freq).sum()
    df_dhw["Q_hp"] = df["1273_320_003_OE401_total"].diff().resample(freq).sum()
    df_dhw["Q_tot"] = df_dhw.Q_vvb + df_dhw.Q_hp
    return df_dhw


def create_energy_data(df, freq="1h"):
    #cur_freq = df.index.freq.nanos / 1e9
    cur_freq = (df.index[1] - df.index[0]).seconds
    df_ene = pd.DataFrame(index=df.resample(freq).mean().index)

    # produced heat
    df_ene["Q_HP"] = (
        df["1273_320_001_OE501"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Q_EB"] = (
        df["1273_320_OE002_Energi_Tot"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Q_HS_prod"] = df_ene[["Q_HP", "Q_EB"]].sum(axis=1)
    df_ene["Q_HWH"] = (
        df["1273_320_OE001_Energi_Tot"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Q_HtTot_prod"] = df_ene[["Q_HS_prod", "Q_HWH"]].sum(axis=1)

    # consumed heat
    df_ene["Q_DHW_HS"] = (
        df["1273_320_003_OE401_total"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Q_DHW"] = df_ene[["Q_DHW_HS", "Q_HWH"]].sum(axis=1)
    df_ene["Q_FH"] = (
        df["1273_320_002_OE401"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    # get apt floor heating
    tag_list = []
    for apt in all_apts:
        tag_list += search_tags(
            df.columns, system="320", subsystem="002", component=f"OE{apt[2:]}"
        )
    df_ene["Q_FH_apt"] = df[tag_list].diff().sum(axis=1).resample(freq).sum()
    df_ene["Q_FH_com"] = df_ene["Q_FH"] - df_ene["Q_FH_apt"]
    df_ene["Q_VH"] = (
        df["1273_320_004_OE501_total"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Q_SH"] = df_ene[["Q_FH", "Q_VH"]].sum(axis=1)
    df_ene["Q_HS_cons"] = df_ene[["Q_SH", "Q_DHW_HS"]].sum(axis=1)
    df_ene["Q_HtTot_cons"] = df_ene[["Q_SH", "Q_DHW"]].sum(axis=1)

    # Electricity
    df_ene["Y_HP"] = (
        df["1273_320_OE003_Energi_Tot"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Y_EB"] = (
        df["1273_320_OE002_Energi_Tot"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Y_HS"] = df_ene[["Y_HP", "Y_EB"]].sum(axis=1)
    df_ene["Y_HS_SH"] = df_ene["Y_HS"].mul(df_ene["Q_SH"].div(df_ene["Q_HS_cons"]))
    df_ene["Y_HS_DHW"] = df_ene["Y_HS"].mul(df_ene["Q_DHW_HS"].div(df_ene["Q_HS_cons"]))
    df_ene["Y_HWH"] = (
        df["1273_320_OE001_Energi_Tot"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Y_DHW_tot"] = df_ene[["Y_HS_DHW", "Y_HWH"]].sum(axis=1)
    df_ene["Y_SH_tot"] = df_ene["Y_HS_SH"]
    df_ene["Y_Ht_tot"] = df_ene[["Y_HS", "Y_HWH"]].sum(axis=1)
    # df_ene["Y_fan_pump_aux"] = (
    #     df["1273_432_101_OE108_energi_tot"]
    #     .mul(10)
    #     .diff()
    #     .resample(freq)
    #     .sum()
    #     .sub(df_ene["Y_Ht_tot"])
    # )
    df_ene["Y_fan_calc"] = (
        df[["1273_360_001_RF401", "1273_360_001_RF501"]]
        .max(axis=1)
        .mul(df["1273_360_001_SFP"])
        .div(1000)
        .resample(freq)
        .mean()
    )
    df_ene["Y_HtSnow"] = (
        df["1273_432_101_OE303_307_energi_tot"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Y_Elevator"] = (
        df["1273_432_101_OE506_energi_tot"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )
    df_ene["Y_EV"] = (
        df["1273_432_101_OE109_energi_tot"]
        .diff()
        .mul(3600 / cur_freq)
        .resample(freq)
        .agg(pd.Series.mean, skipna=False)
    )

    # COPs
    df_ene["COP_HP"] = df_ene["Q_HP"] / df_ene["Y_HP"]
    df_ene["COP_HS_prod"] = df_ene["Q_HS_prod"] / df_ene["Y_HS"]
    df_ene["COP_HS_cons"] = df_ene["Q_HS_cons"] / df_ene["Y_HS"]
    df_ene["COP_DHW"] = df_ene["Q_DHW"] / df_ene["Y_DHW_tot"]
    df_ene["COP_SH"] = df_ene["Q_SH"] / df_ene["Y_SH_tot"]
    df_ene["COP_tot"] = df_ene["Q_HtTot_prod"] / df_ene["Y_Ht_tot"]

    return df_ene

df = concat_log()
df.index.freq = df.index.inferred_freq
df = zero_to_nan(df)
df_dhw = create_dhw_data(df)
df_ene = create_energy_data(df)


def plotCommonDailyBoxPlot(
    df=df_dhw[all_apts].mean(axis=1).to_frame(),
    freq="1h",
    name="mean_hourly_boxplot",
    unit="liter/apt",
    dlist=[0, 1, 2, 3, 4, 5, 6],
):
    linew = 0.5
    ftype = ".png"
    s = []
    for i, v in enumerate(df.columns):
        v1 = df[v][df.index.dayofweek.isin(dlist)]
        v1 = v1.resample(freq).mean()
        # v1.index = [v1.index.time, v1.index.date, [i]*len(v1.index)]
        s.append(v1)
    s = pd.concat(s)
    s.index = [s.index.hour, s.index.date, list(range(len(s.index)))]
    # s.index = [s.index.time, s.index.date, list(range(len(s.index)))]
    ax = s.unstack(level=0).plot.box()

    ax.set_ylabel(unit)
    plt.savefig(name + ftype, dpi=400, bbox_inches="tight")
    # plt.close()
    return


def getDailyRoomFlowBoxPlot(df=df_dhw[all_apts]):
    df_rand = df[np.random.RandomState(10).permutation(df.columns)]
    df_rand.columns = range(1, len(all_apts) + 1)
    df_rand.resample("1D").sum().boxplot()
    plt.ylabel("liter/day")
    plt.xlabel("Apartment")
    plt.ylim(0)
    plt.savefig("DailyBoxPlot_perApt.png", dpi=400, bbox_inches="tight")
    # plt.clf()
    # plt.close()
    return


