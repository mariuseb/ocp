#from ast import Param
import sys
import os
import pathlib
ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
sys.path.append(ocp_path)
from ocp.param_est import ParameterEstimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from matplotlib import rc
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from scipy.stats import norm
# text:

"""
TODO: room-wise (i.e. 219, 220) preparation.
"""

def prepare_data(data):
    """
    Prepare data for identification.
    """
    cp_water = 4200
    data.V_flow_219 /= 3600
    data.V_flow_220 /= 3600
    data["phi_h_219"] = cp_water*data["V_flow_219"]*(data['T_sup_219'] - data['T_ret_219'])
    #data["phi_h_220"] = cp_water*data["V_flow_220"]*(data['T_sup_220'] - data['T_ret_220'])
    
    # do a plot of phi_h vs 219 temps
    temps_219_cols = [col for col in data.columns if "T_219" in col]
    #temps_219 = data[temps_219_cols]
    temps_219 = data[temps_219_cols].mean(axis=1)
    #temps_219 = data["T_219_TR3"]
    #y_data = data[["phi_h_219"]]
    y_data = data[["P_rad_219"]]*1000
    y_data.columns = ["phi_h"]
    
    # ventilation:
    y_data["T_ext_air"] = data["T_ext_air_219"]
    y_data["T_sup_air"] = data["T_sup_air_219"]
    y_data["V_ext_air"] = data["V_ext_air_219"]
    y_data["V_sup_air"] = data["V_sup_air_219"]
    y_data["T_207"] = data["T_207"]
    y_data["T_211"] = data["T_211"]
    y_data["T_213"] = data["T_213"]
    y_data["T_217"] = data["T_217"]
    y_data["T_121"] = data["RSegm121"]
    y_data["T_321"] = data["RSegm321"]
    y_data["T_320"] = data["RSegm320"]
    
    #data["phi_h"] = data["phi_h_219"]
    y_data["Ti"] = temps_219 # take avg (of different heights?)
    #data["Ti"] = data['T_219_TR4']
    y_data["phi_s"] = data["I_ver"]
    y_data["Ta"] = data["T_amb"]
    y_data["y1"] = y_data["Ti"]
    y_data["vent_on"] = (y_data["V_sup_air"] > 10).astype(int) 
    y_data["dt_index"] = y_data.index
    y_data.dt_index.name = ""
    y_data["weekday"] = y_data["dt_index"].apply(lambda x: x.weekday())
    y_data["weeknd"] = y_data["weekday"].apply(lambda x: 1 if x in (5,6) else 0)
    
    #dt = (y_data.index[1] - y_data.index[0]).seconds
    # set range index for identification/simulation:
    #y_data.index = range(0,len(y_data.index)*dt,dt)
    
    return y_data

def prepare_data(data):
    """
    Prepare data for identification.
    """
    cp_water = 4200
    data.V_flow_219 /= 3600
    data.V_flow_220 /= 3600
    data["phi_h_219"] = cp_water*data["V_flow_219"]*(data['T_sup_219'] - data['T_ret_219'])
    #data["phi_h_220"] = cp_water*data["V_flow_220"]*(data['T_sup_220'] - data['T_ret_220'])
    
    # do a plot of phi_h vs 219 temps
    temps_219_cols = [col for col in data.columns if "T_219" in col]
    #temps_219 = data[temps_219_cols]
    temps_219 = data[temps_219_cols].mean(axis=1)
    #temps_219 = data["T_219_TR3"]
    #y_data = data[["phi_h_219"]]
    y_data = data[["P_rad_219"]]*1000
    y_data.columns = ["phi_h"]
    
    # ventilation:
    y_data["T_ext_air"] = data["T_ext_air_219"]
    y_data["T_sup_air"] = data["T_sup_air_219"]
    y_data["V_ext_air"] = data["V_ext_air_219"]
    #y_data["V_sup_air"] = data["V_sup_air_219"]
    # recalculate V_sup_air to m_flow*cp_air:
    # "invert":
    #y_data["V_sup_air"] = (data["V_sup_air_219"].max() - data["V_sup_air_219"])
    #y_data["V_sup_air"] = (data["V_sup_air_219"]/3600)*1.204*1.006*1000 # [-> m3/s -> kg/s -> W/K]
    y_data["V_sup_air"] = data["V_sup_air_219"]
    y_data["T_207"] = data["T_207"]
    y_data["T_211"] = data["T_211"]
    y_data["T_213"] = data["T_213"]
    y_data["T_217"] = data["T_217"]
    y_data["T_121"] = data["RSegm121"]
    y_data["T_321"] = data["RSegm321"]
    y_data["T_320"] = data["RSegm320"]
    
    #data["phi_h"] = data["phi_h_219"]
    y_data["Ti"] = temps_219 # take avg (of different heights?)
    #data["Ti"] = data['T_219_TR4']
    y_data["phi_s"] = data["I_ver"]
    y_data["Ta"] = data["T_amb"]
    y_data["y1"] = y_data["Ti"]
    y_data["vent_on"] = (y_data["V_sup_air"] > 10).astype(int) 
    y_data["dt_index"] = y_data.index
    y_data.dt_index.name = ""
    y_data["weekday"] = y_data["dt_index"].apply(lambda x: x.weekday())
    y_data["weeknd"] = y_data["weekday"].apply(lambda x: 1 if x in (5,6) else 0)
    
    return y_data
    

class ZEBData(object):
    def __init__(self, path):
        #data_path = os.path.join("ZEBLab_year_60m.csv")
        data = pd.read_csv(path, index_col=0)[:-1]
        data.index = pd.to_datetime(data.index).tz_localize(None)
        # filter power:
        data["P_rad_219"][data["P_rad_219"] > 2.0] = 2.0
        # TODO: add more filters
        self.data = data
        
        
    def get_dataset(
                    self,
                    start = pd.Timestamp("2023-11-20 00:00"),
                    stop = pd.Timestamp("2023-11-27 00:00")
                    ):
        
        data = self.data.loc[start:stop]
        data = data.interpolate()
        return prepare_data(data)

def prepare_data_envelope(data):
    """
    Prepare data for envelope identification.
    """
    cp_water = 4200
    data.V_flow_219 /= 3600
    data.V_flow_220 /= 3600
    data["phi_h_219"] = cp_water*data["V_flow_219"]*(data['T_sup_219'] - data['T_ret_219'])
    #data["phi_h_220"] = cp_water*data["V_flow_220"]*(data['T_sup_220'] - data['T_ret_220'])
    
    temps_219_cols = [col for col in data.columns if "T_219" in col]
    #temps_219 = data[temps_219_cols]
    temps_219 = data[temps_219_cols].mean(axis=1)
    # do a plot of phi_h vs 219 temps
    """
    ax = temps_219.plot()
    ax1 = ax.twinx()
    data["phi_h_219"].plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="r")
    (data["P_rad_219"]*1000).plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    ax1.legend(["calculated from OE16 V_flow, delta T", ""])
    plt.show()
    """
    
    #y_data = data[["phi_h_219"]]
    y_data = data[["P_rad_219"]]*1000
    y_data.columns = ["phi_h"]
    
    # ventilation:
    y_data["T_ext_air"] = data["T_ext_air_219"]
    y_data["T_sup_air"] = data["T_sup_air_219"]
    y_data["V_ext_air"] = data["V_ext_air_219"]
    y_data["V_sup_air"] = data["V_sup_air_219"]
    y_data["u_val"] = data["val_219"]
    y_data["Tsup"] = data["T_sup_219"]
    y_data["Tret"] = data["T_ret_219"]
    y_data["Tset"] = data["T_set"]
    y_data["m_flow"] = data["V_flow_219"]*1.293
    y_data["Prad"] = data["P_rad_219"]*1000
    y_data["dt_index"] = data.index
    #data["phi_h"] = data["phi_h_219"]
    y_data["Ti"] = temps_219 # take avg (of different heights?)
    #data["Ti"] = data['T_219_TR4']
    y_data["phi_s"] = data["I_ver"]
    y_data["Ta"] = data["T_amb"]
    y_data["y1"] = y_data["Ti"]

    
    return y_data
   
def prepare_data_HVAC(
                      data,
                      start=pd.Timestamp("2022-12-14 00:00"), 
                      stop=pd.Timestamp("2023-03-20 00:00")
                      ):
    """
    Prepare data for HVAC-identification.
    """
    data.index = pd.to_datetime(data._time)
    data.index = data.index.tz_localize(None)
    data = data.loc[start:stop]
    
    # get simpler temprature names:
    temp_data = prepare_data_envelope(data)
    data = pd.merge(
                    data,
                    temp_data, 
                    left_index=True,
                    right_index=True
                    )
    data.drop(columns=["y1"], inplace=True) # different measurements 
    
    data.V_flow_219[data.V_flow_219 > 0.027780] = 0.027780
    data.Tsup[data.Tsup > 48] = 48
    data.Tret[data.Tret > 38] = 38
    #data["Ti"] = 
    data.Ti[data.Ti > 30] = 30
    
    # bfill:
    
    data.drop(columns=["_time"], inplace=True)
    data = data.resample(rule="5min").mean()
    
    data["m_flow"] = data.V_flow_219*1.293
    data["delta_m_flow"] = (data.m_flow - data.m_flow.shift(1))
    data["delta_m_flow"].fillna(method="bfill", inplace=True)
    # resample

    normed = (data.delta_m_flow.resample(rule="5min").mean()/data.delta_m_flow.max()).resample("5min").ffill()
    normed[normed < 0] = 0
    #normed[normed < 0] = normed[normed < 0].astype(bool).astype(int)*(-1)
    normed[normed > 0] = normed[normed > 0].astype(bool).astype(int)
    data["normed"] = normed
    
    #data["u_val_set"] = data.val_pos_219
    data["u_val_set"] = data.val_219
    
    m_flow_bool = (data.m_flow.resample(rule="5min").mean().astype(bool).astype(int)).resample("5min").ffill()
    data["m_flow_bool"] = m_flow_bool
    data["m_flow_weight"] = m_flow_bool + 0.01
    #data["y1"] = data["m_flow"]
    data["u_val"] = data.val_219
    # filter u_val
    data.u_val[data["u_val"] > 1] = 1
    data["Ti"] = data["Ti"] + 273.15
    data["Tsup"] = data["Tsup"] + 273.15
    data["Tret"] = data["Tret"] + 273.15
    data["Ta"] = data["Ta"] + 273.15
    data["y1"] = data["Tret"]
    data["y2"] = data["Tsup"]
    data["y3"] = data["Prad"]
    data["y4"] = data.V_flow_219*1.293
    
    return data


def save_journal_plot(data, name):
    """
    Make a nicely formatted plot of
    simulation result, boundary conditions.
    """
    fig, axes = plt.subplots(3,1, sharex=True, figsize=(12,5))
    # plot training fit:
    ax = axes[0]
    data["Ti"].plot(color="r", linestyle="dashed", ax=ax, linewidth=0.75)
    data["y1"].plot(color="k", ax=ax, linewidth=0.75)
    ax.set_ylabel("Temperature $[^\circ C]$")
    ax.legend(["$T_i$", "$T_{i}^{meas}$"], loc="upper left", ncols=2)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.3])
    ax1 = ax.twinx()
    ax = ax1
    #data["weeknd"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
    data["vent_on"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
    ax.legend(["$\sigma_{vent}$"], loc="upper right", ncols=1)
    ax.set_yticks([0,1])
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.35])
    
    ax = axes[1]
    
    # power, other room temps / ventilation 
    (data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
    #(data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
    ax.legend(["$\phi_h$"], loc="upper left", ncols=1)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.2])
    ax.set_ylabel("Power $[kW]$")
    ax1 = ax.twinx()
    ax = ax1
    data["T_sup_air"].plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    data["T_321"].plot(color="b", ax=ax, linewidth=0.75)
    data["T_320"].plot(color="y", ax=ax, linewidth=0.75)
    ax.legend(["$T_{sup}^{v}$", "$T_{321}$", "$T_{320}$"], loc="upper right", ncols=3)
    ax.set_xlabel("")
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.2])
    
    ax = axes[2]
    
    # dataar, outdoor temp
    #(data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
    (data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
    ax.legend(["$\phi_s$"], loc="upper left", ncols=1)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.1])
    ax.set_ylabel("Power [$\\frac{kW}{m^2}$]")
    ax.set_yticks([0,0.5])
    ax.set_xlabel("")
    ax1 = ax.twinx()
    ax = ax1
    data["Ta"].plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    #data["T_321"].plot(color="b", ax=ax, linewidth=0.75)
    #sol["T_320"].plot(color="y", ax=ax, linewidth=0.75)
    ax.legend(["$T_{a}$"], loc="upper right", ncols=1)
    ax.set_xlabel("")
    ylim = ax.get_ylim()
    #ax.set_ylim([ylim[0], ylim[1]*1.25])
    fig.tight_layout()
    #plt.show()
    plt.savefig(name)
    
def plot_residuals(one_step_df, sim_df, name):
    """
    Nice plot of residuals.
    """
    def drawSingle(myax, mydf, title, variable=None):
        num_bins = 30
        xs = mydf["gap"]
        x = np.linspace(-1, 1, 1000)

        mu = np.mean(x)
        sigma = np.std(xs)
        n, bins, patches = myax.hist(xs, num_bins, alpha=0.65, ec='black', facecolor='blue', density=False)

        myax.set_ylabel('frequency', color="black", fontsize=12, weight="bold")
        myax.set_xlabel("Temperature residual $[^\circ C]$", fontsize=12, weight="bold", horizontalalignment='center')
        myax.set_title(title)

        """
        Calculate the normal dist.:
        """
        X = mydf.gap
        W = np.array([1]*len(X))
        mu = sum (X * W) / sum(W)
        sigma = np.sqrt (sum (W * (X- mu)**2) / sum(W))
        
        #sigma = 0.075
        normalization_factor = len(xs) * (bins[1] - bins[0])
        y_normcurve = norm.pdf(x, mu, sigma) * normalization_factor
        #y_normcurve = norm.pdf(x, mu, sigma) # * normalization_factor
        myax.plot(x, y_normcurve, 'r--', linewidth=0.8)
        myax.vlines(mu, 0, y_normcurve.max(), 'y', '--', color='lime', label='example', linewidth=0.75)
        # set legend:
        myax.legend([
                    "$\sigma$ = {:.3f}".format(sigma),
                    "$\mu$ = {:.3f}".format(mu),
                    variable
                    #"$\mu = %s$" % (str(mu), )
                    ])
        #return normalization_factor
        return 1

    def drawSubplots(mydf1, mydf2, title):
        plt.rcParams['figure.figsize'] = (12, 5)

        fig, ax = plt.subplots(nrows=1, ncols=2, sharex=True, sharey=True)

        dfs = [mydf1, mydf2]
        norm_factors = [drawSingle(ax_i, df, title, var)
                        for ax_i, df, title, var in zip(ax.ravel(),
                                                dfs,
                                                ["One-step ahead", "Simulation"], 
                                                ['$\hat{T}_{t|t-1}^{i} - Y_t$', '$\hat{T}_{t|0}^{i} - Y_t$'])]
        for ax_i, norm_factor in zip(ax.ravel(), norm_factors):
            ax_twin = ax_i.twinx()
            ymax = ax_i.get_ylim()[1]
            ax_twin.set_ylim(0, ymax / norm_factor)
        #plt.suptitle(title, fontsize=18)
        fig.tight_layout()
        plt.savefig("plots/" + title.replace(", ", "_") + ".pdf")
        #plt.show()

    #df1, df2 = [pd.DataFrame({"gap": np.random.normal(0, 0.2, n)}) for n in [6000, 4000]]
    df1 = one_step_df[["res"]].copy()
    df1.columns = ["gap"]
    df2 = sim_df[["v1"]][1:].copy()
    df2.index = df1.index
    df2.columns = ["gap"]

    # filter out abs(res) > 0.4
    #df1[abs(df1) > 0.4] = 0
    #df2[abs(df2) > 0.4] = 0
    
    drawSubplots(df1, df2, name)