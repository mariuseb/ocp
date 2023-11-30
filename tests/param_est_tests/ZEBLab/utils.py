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
# text:

"""
TODO: room-wise (i.e. 219, 220) preparation.
"""

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