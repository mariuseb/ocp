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
from hampel import hampel
# text:
    
def _solve_rosenbrock():
    # Declare variables
    x = ca.SX.sym("x")
    y = ca.SX.sym("y")
    z = ca.SX.sym("z")

    # Formulate the NLP
    f = x**2 + 100*z**2
    g = z + (1-x)**2 - y
    nlp = {'x': ca.vertcat(x,y,z), 'f':f, 'g':g}

    # Create an NLP solver
    solver = ca.nlpsol(
        "solver", 
        "ipopt",
        nlp,
        {"ipopt.print_level": 0}
    )
    # Solve the Rosenbrock problem
    res = solver(
        x0 =[2.5,3.0,0.75],
        ubg=0,
        lbg=0)
    
def prepare_data(data, room=219):
    """
    Prepare data for identification.
    """
    
    temps_219_cols = [col for col in data.columns if "T_" + str(room) in col]
    temps_219_cols = ["T_219_TR3"]
    temps_219 = data[temps_219_cols].mean(axis=1)
    y_data = data[["P_rad_" + str(room)]]*1000
    y_data.columns = ["phi_h"]
    #y_data["phi_int"] = data["phi_int_219"]
    y_data["phi_int_plugs"] = data["phi_int_" + str(room) + "_plugs"]
    y_data["phi_int_lig"] = data["phi_int_" + str(room) + "_lig"]
    y_data["phi_int"] = data["phi_int_" + str(room) + "_lig"] + data["phi_int_" + str(room) + "_plugs"]
    # ventilation:
    y_data["T_ext_air"] = data["T_ext_air_" + str(room)] # + 273.15
    y_data["T_sup_air"] = data["T_sup_air_" + str(room)] # + 273.15
    y_data["V_ext_air"] = data["V_ext_air_" + str(room)]
    y_data["V_sup_air"] = data["V_sup_air_" + str(room)]
    #y_data["ahu_reaFloSupAir"] =  data["V_sup_air_" + str(room)]*(1.292/3600)*1000
    #y_data["ahu_reaFloExtAir"] =  data["V_ext_air_" + str(room)]*(1.292/3600)*1000
    y_data["ahu_reaFloSupAir"] =  data["V_sup_air_" + str(room)]*(1.292/3600)
    y_data["ahu_reaFloExtAir"] =  data["V_ext_air_" + str(room)]*(1.292/3600)
    # indoor temp:
    y_data["Ti"] = temps_219
    y_data.Ti[y_data.Ti > 30] = 30
    
    y_data["phi_s"] = data["I_hor"]
    y_data["I_hor"] = data["I_hor"]
    y_data["Ta"] = data["T_amb"]
    y_data["Prad"] = data["P_rad_" + str(room)]*1000
    #y_data["CO2_in"] = data["CO2_219"]

    try:
        y_data["T_207"] = data["T_207"]
        y_data["T_211"] = data["T_211"]
        y_data["T_213"] = data["T_213"]
        y_data["T_217"] = data["T_217"]
        y_data["T_121"] = data["RSegm121"]
        y_data["T_321"] = data["RSegm321"]
        y_data["T_320"] = data["RSegm320"]
        y_data["Tset"] = data["T_set"]
        y_data["vent_on"] = (y_data["V_sup_air"] > 10).astype(int) 
        y_data["dt_index"] = y_data.index
        y_data[temps_219_cols] = data[temps_219_cols]
        y_data.dt_index.name = ""
        y_data["weekday"] = y_data["dt_index"].apply(lambda x: x.weekday())
        y_data["Tset_high"] = (y_data["Tset"] > 18).astype(int)
        y_data["hour"] = y_data["dt_index"].apply(lambda x: x.hour)
        y_data["weeknd"] = y_data["weekday"].apply(lambda x: 1 if x in (5,6) else 0)
        y_data["daytime"] = y_data["hour"].apply(lambda x: 1 if x in range(5,17) else 0)
    except:
        pass
    try:
        y_data["u_val"] = data["val_pos_219"]
        #y_data["u_val"] = data["val_cmd_219"]
        y_data["val_pos_219"] = data["val_pos_219"]
        y_data["Tsup"] = data["T_sup_219"]
        y_data["Tret"] = data["T_ret_219"]
        y_data["m_flow"] = data["V_flow_219"]*1.293
        y_data["V_flow_219"] = data["V_flow_219"]
        
        # remove obviously non-physical values, space heating:
        y_data.Tsup[y_data.Tsup > 48] = 48
        y_data.Tret[y_data.Tret > 38] = 38
        # remove obviously non-physical values, ventilation:
        #y_data.T_sup_air[y_data.T_sup_air > 28] = np.nan
        #y_data.T_ext_air[y_data.T_ext_air > 28] = np.nan
    
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
    
    #for col in y_data.columns:
    #    if col.startswith("T"):
    #        y_data[col] += 273.15
    
    # set measurements:
    y_data["y1"] = y_data["Ti"]
    #y_data["y2"] = y_data["Tret"]## ----setup, include=FALSE------------------------------------------------
## this is equivalent to \SweaveOpts{...}
    #y_data["y3"] = y_data["Tsup"]
    #y_data["y4"] = y_data["Prad"]
    #y_data["y5"] = y_data["m_flow"]
    #y_data["y6"] = y_data["CO2_in"]
    
    return y_data
    

class ZEBData(object):
    """
    Data from the ZEB Lab twin rooms.
    """
    def __init__(self, path, room=219):
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
        #data["P_rad_219"][data["P_rad_219"] > 2.0] = 2.0
        data["P_rad_219"][data["P_rad_219"] > 2.0] = 2.0
        data["P_rad_219"][data["P_rad_219"] < 0] = 0
        data["P_rad_220"][data["P_rad_220"] > 2.0] = 2.0
        data["P_rad_220"][data["P_rad_220"] < 0] = 0
        #data.P_rad_219[Data.data.P_rad_219 < 0] = 0
        # TODO: add more filters
        self.data = data
        self.room = room
        
    def check_if_any_all_nans(self, data):
        return (data.isna().sum() == len(data)).sum()
    
    def get_dataset(
                    self,
                    start = pd.Timestamp("2023-11-20 00:00"),
                    stop = pd.Timestamp("2023-11-27 00:00"),
                    sampling_rate = None
                    ):
        filter_stop = stop + pd.Timedelta(days=14)
        data = self.data.loc[start:(filter_stop + pd.Timedelta(value=sampling_rate))]
        data = data.interpolate()
        data = prepare_data(data, room=self.room)
        if (data.T_sup_air > 28).any():
            print("head")
        data.T_sup_air[data.T_sup_air > 28] = np.nan
        data.T_ext_air[data.T_ext_air > 28] = np.nan
        # interpolate:
        data[["T_sup_air", "T_ext_air"]] = data[["T_sup_air", "T_ext_air"]].interpolate()
        # then backfill:
        data = data.bfill()
        data = data.groupby(pd.Grouper(freq=sampling_rate)).mean().dropna()
        data["vent"] = (data["V_sup_air"] > 10).astype(int) 
        #data["vent"] = data["daytime"]
        data["Tset_high"] = (data["Tset"] > 18).astype(int)
        data["Tset"] = 22
        data["heat_on"] = (data["phi_h"] > 10).astype(int)
        #data["vent"] = data["Tset_high"]
        data["vent"] = (data["vent"] + data["Tset_high"] + data["heat_on"]).astype(bool).astype(int)
        
        """
        for name in ("T_sup_air", "T_ext_air"):
            if (data[name] > 30).any():
                print("head")
            # mean-transform:
            ts_mean = data[name].mean()
            ts = data[name] - ts_mean
            result = hampel(ts, window_size=24, n_sigma=1.5)
            # drop outliers:
            #ts_filtered = ts.drop(outlier_indices)
            data[name] = result.filtered_data.values + ts_mean
        """
        
        dt = (data.index[1] - data.index[0]).seconds
        # store datetime-index
        data = data.loc[start:(stop + pd.Timedelta(value=sampling_rate))]
        N = len(data)
        data["dt_index"] = data.index
        # set range index for identification:
        data.index = range(0,N*dt,dt)
        
        return data.iloc[0:N-1], dt, N-1
    
    def get_meta_for_parest(self,
                            start,
                            days,
                            sampling_rate
                            ):
        
        stop = start + pd.Timedelta(days=days) 
        data, dt, N = self.get_dataset(
                                  start=start, 
                                  stop=stop, 
                                  sampling_rate=sampling_rate
                                  )
        
        return dt, N
    
def quick_plot(ax, y_data):
    """
    A quick plot of the data required
    for envelope identification.
    """
    y_data.Ti.plot(ax=ax)
    y_data.Ta.plot(ax=ax)
    #for col in ["T_207", "T_211", "T_213", "T_217"]:
    #    y_data[col].plot(ax=ax, linewidth=0.5)
    ax.legend()
    ax1 = ax.twinx()
    y_data.phi_h.plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="k")
    y_data.phi_s.plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="y")
    y_data.I_hor.plot(ax=ax1, drawstyle="steps-post", linestyle="dashed", color="b")
    #P_vent = y_data.V_sup_air*(y_data.T_sup_air - y_data.Ti)
    #P_vent.plot(ax=ax1, color="g", linewidth=0.75)
    ax1.legend(["calculated from OE16 V_flow, delta T", ""])