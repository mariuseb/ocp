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
    # from hourly to second values:
    data.V_flow_219 /= 3600
    data.V_flow_220 /= 3600
    data["phi_h_219"] = cp_water*data["V_flow_219"]*(data['T_sup_219'] - data['T_ret_219'])
    
    temps_219_cols = [col for col in data.columns if "T_219" in col]
    temps_219 = data[temps_219_cols].mean(axis=1)
    y_data = data[["P_rad_219"]]*1000
    y_data.columns = ["phi_h"]
    
    # ventilation:
    y_data["T_ext_air"] = data["T_ext_air_219"] + 273.15
    y_data["T_sup_air"] = data["T_sup_air_219"] + 273.15
    y_data["V_ext_air"] = data["V_ext_air_219"]
    #y_data["V_sup_air"] = data["V_sup_air_219"]
    # recalculate V_sup_air to m_flow*cp_air:
    # "invert":
    #y_data["V_sup_air"] = (data["V_sup_air_219"].max() - data["V_sup_air_219"])
    #y_data["V_sup_air"] = (data["V_sup_air_219"]/3600)*1.204*1.006*1000 # [-> m3/s -> kg/s -> W/K]
    y_data["V_sup_air"] = data["V_sup_air_219"]
    
    # indoor temp:
    y_data["Ti"] = temps_219
    y_data.Ti[y_data.Ti > 30] = 30
    y_data["Ti"] += 273.15
    
    y_data["phi_s"] = data["I_ver"]
    y_data["Ta"] = data["T_amb"] + 273.15
    y_data["y1"] = y_data["Ti"]
    y_data["Prad"] = data["P_rad_219"]*1000

    
    try:
        y_data["T_207"] = data["T_207"] + 273.15
        y_data["T_211"] = data["T_211"] + 273.15
        y_data["T_213"] = data["T_213"] + 273.15
        y_data["T_217"] = data["T_217"] + 273.15
        y_data["T_121"] = data["RSegm121"] + 273.15
        y_data["T_321"] = data["RSegm321"] + 273.15
        y_data["T_320"] = data["RSegm320"] + 273.15
        #data["phi_h"] = data["phi_h_219"]
        #data["Ti"] = data['T_219_TR4']
        y_data["vent_on"] = (y_data["V_sup_air"] > 10).astype(int) 
        y_data["dt_index"] = y_data.index
        y_data.dt_index.name = ""
        y_data["weekday"] = y_data["dt_index"].apply(lambda x: x.weekday())
        y_data["weeknd"] = y_data["weekday"].apply(lambda x: 1 if x in (5,6) else 0)
    except:
        pass
    
    # waterborne HVAC-system:
    try:
        y_data["u_val"] = data["val_pos_219"]
        #y_data["u_val"] = data["val_cmd_219"]
        y_data["val_pos_219"] = data["val_pos_219"]
        y_data["Tsup"] = data["T_sup_219"]
        y_data["Tret"] = data["T_ret_219"]
        y_data["Tset"] = data["T_set"]
        y_data["m_flow"] = data["V_flow_219"]*1.293
        y_data["V_flow_219"] = data["V_flow_219"]
        
        # remove obviously non-physical values:
        y_data.Tsup[y_data.Tsup > 48] = 48
        y_data.Tret[y_data.Tret > 38] = 38
        
        y_data["Tret_above"] = (y_data.Tret > 24).astype(int)
        
        y_data["m_flow"] = data.V_flow_219*1.293
        y_data["delta_m_flow"] = (y_data.m_flow - y_data.m_flow.shift(1))
        y_data["delta_m_flow"].fillna(method="bfill", inplace=True)
        # resample

        normed = (y_data.delta_m_flow.resample(rule="5min").mean()/y_data.delta_m_flow.max()).resample("5min").ffill()
        normed[normed < 0] = 0
        #normed[normed < 0] = normed[normed < 0].astype(bool).astype(int)*(-1)
        normed[normed > 0] = normed[normed > 0].astype(bool).astype(int)
        #y_data["normed"] = normed
        #y_data["rise"] = normed
        
        #data["u_val_set"] = data.val_pos_219
        y_data["u_val_set"] = data.val_cmd_219
        
        #m_flow_bool = (y_data.m_flow.resample(rule="5min").mean().astype(bool).astype(int)).resample("5min").ffill()
        m_flow_bool = (y_data.m_flow.astype(bool).astype(int)) #.resample("1min").ffill()
        y_data["m_flow_bool"] = m_flow_bool
        y_data["flow_weight"] = m_flow_bool + 1E-2
        y_data["u_val"] = data.val_pos_219
        y_data["valve_open"] = (data.val_pos_219 > 0).astype(int).round(0)
        y_data["valve_weight"] = y_data["valve_open"] + 1E-2
        # filter u_val
        y_data.u_val[y_data["u_val"] > 1] = 1
        y_data["Tsup"] = y_data["Tsup"] + 273.15
        y_data["Tret"] = y_data["Tret"] + 273.15
        
        y_data["Ta"] = data["Ta"] + 273.15
        y_data["y2"] = y_data["Tret"]
        y_data["y3"] = y_data["Tsup"]
        y_data["y4"] = y_data["Prad"]
        #y_data["y5"] = y_data.V_flow_219*1.293
        y_data["y5"] = y_data.m_flow
    except:
        pass
    
    return y_data
    
def prepare_data(data):
    """
    Prepare data for identification.
    """
    
    temps_219_cols = [col for col in data.columns if "T_219" in col]
    temps_219 = data[temps_219_cols].mean(axis=1)
    y_data = data[["P_rad_219"]]*1000
    y_data.columns = ["phi_h"]
    y_data["phi_int"] = data["phi_int"]
    # ventilation:
    y_data["T_ext_air"] = data["T_ext_air_219"] # + 273.15
    y_data["T_sup_air"] = data["T_sup_air_219"] # + 273.15
    y_data["V_ext_air"] = data["V_ext_air_219"]
    y_data["V_sup_air"] = data["V_sup_air_219"]
    y_data["ahu_reaFloSupAir"] =  data["V_sup_air_219"]*1.292/3600
    y_data["ahu_reaFloExtAir"] =  data["V_ext_air_219"]*1.292/3600
    # indoor temp:
    y_data["Ti"] = temps_219
    y_data.Ti[y_data.Ti > 30] = 30
    
    y_data["phi_s"] = data["I_ver"]
    y_data["Ta"] = data["T_amb"]
    y_data["Prad"] = data["P_rad_219"]*1000
    y_data["CO2_in"] = data["CO2_219"]

    try:
        y_data["T_207"] = data["T_207"]
        y_data["T_211"] = data["T_211"]
        y_data["T_213"] = data["T_213"]
        y_data["T_217"] = data["T_217"]
        y_data["T_121"] = data["RSegm121"]
        y_data["T_321"] = data["RSegm321"]
        y_data["T_320"] = data["RSegm320"]
        y_data["vent_on"] = (y_data["V_sup_air"] > 10).astype(int) 
        y_data["dt_index"] = y_data.index
        y_data.dt_index.name = ""
        y_data["weekday"] = y_data["dt_index"].apply(lambda x: x.weekday())
        y_data["weeknd"] = y_data["weekday"].apply(lambda x: 1 if x in (5,6) else 0)
    except:
        pass
    try:
        y_data["u_val"] = data["val_pos_219"]
        #y_data["u_val"] = data["val_cmd_219"]
        y_data["val_pos_219"] = data["val_pos_219"]
        y_data["Tsup"] = data["T_sup_219"]
        y_data["Tret"] = data["T_ret_219"]
        y_data["Tset"] = data["T_set"]
        y_data["m_flow"] = data["V_flow_219"]*1.293
        y_data["V_flow_219"] = data["V_flow_219"]
        
        # remove obviously non-physical values:
        y_data.Tsup[y_data.Tsup > 48] = 48
        y_data.Tret[y_data.Tret > 38] = 38
        
        y_data["Tret_above"] = (y_data.Tret > 24).astype(int)
        
        y_data["m_flow"] = data.V_flow_219*1.293
        y_data["delta_m_flow"] = (y_data.m_flow - y_data.m_flow.shift(1))
        y_data["delta_m_flow"].fillna(method="bfill", inplace=True)
        
        y_data["u_val_set"] = data.val_cmd_219
        
        m_flow_bool = (y_data.m_flow.astype(bool).astype(int))
        y_data["m_flow_bool"] = m_flow_bool
        y_data["flow_weight"] = m_flow_bool + 1E-2
        y_data["u_val"] = data.val_pos_219
        y_data["valve_open"] = (data.val_pos_219 > 0).astype(int).round(0)
        y_data["valve_weight"] = y_data["valve_open"] + 1E-2
        # filter u_val
        y_data.u_val[y_data["u_val"] > 1] = 1
        y_data["Tsup"] = y_data["Tsup"]
        y_data["Tret"] = y_data["Tret"]
    except:
        pass
    
    for col in y_data.columns:
        if col.startswith("T"):
            y_data[col] += 273.15
    
    # set measurements:
    y_data["y1"] = y_data["Ti"]
    y_data["y2"] = y_data["Tret"]
    y_data["y3"] = y_data["Tsup"]
    y_data["y4"] = y_data["Prad"]
    y_data["y5"] = y_data["m_flow"]
    y_data["y6"] = y_data["CO2_in"]
    
    return y_data
    

class ZEBData(object):
    """
    Data from the ZEB Lab twin rooms.
    """
    def __init__(self, path):
        # cut out last timestep:
        data = pd.read_csv(path, index_col=0)[:-1]
        try:
            assert self.check_if_any_all_nans(data) == 0
        except AssertionError:
            print("#"*75)
            print("Some data are all nan's, check closer.")
            print("#"*75)
            sys.exit(1)
        data.index = pd.to_datetime(data.index).tz_localize(None)
        # filter power outliers:
        data["P_rad_219"][data["P_rad_219"] > 2.0] = 2.0
        # TODO: add more filters
        self.data = data
        
    def check_if_any_all_nans(self, data):
        return (data.isna().sum() == len(data)).sum()
    
    def get_dataset(
                    self,
                    start = pd.Timestamp("2023-11-20 00:00"),
                    stop = pd.Timestamp("2023-11-27 00:00")
                    ):
        
        data = self.data.loc[start:stop]
        data = data.interpolate()
        return prepare_data(data)
    
def quick_plot(ax, y_data):
    """
    A quick plot of the data required
    for envelope identification.
    """
    y_data.Ti.plot(ax=ax)
    for col in ["T_207", "T_211", "T_213", "T_217"]:
        y_data[col].plot(ax=ax, linewidth=0.5)
    ax.legend()
    ax1 = ax.twinx()
    y_data.phi_h.plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    P_vent = y_data.V_sup_air*(y_data.T_sup_air - y_data.Ti)
    P_vent.plot(ax=ax1, color="g", linewidth=0.75)
    ax1.legend(["calculated from OE16 V_flow, delta T", ""])