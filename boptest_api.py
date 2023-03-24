"""
Created on Sun Nov 14 22:01:17 2021

@author: mariusb
"""
import requests
#from opt.mpc.mpc import ConfigJson
#from opt.mpc.mpc import MPC
#from opt.mpc.ocp import OCP
import numpy as np
import pandas as pd
import pdb
import matplotlib.pyplot as plt
from pprint import pprint
import os
import json
#rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

class Forecaster(object):
    ''' 
    BOPTEST Forecaster object. A forecast is retrieved from BOPTEST,
    it should be set as reference in the MOSIOP MPC object.
    Only one operation is necessary in this case:
        - cast from dict to np.array, keeping 
          the order as defined in OCP-formulation.
          
    '''
    def __init__(self, cfg):

        self.ocp_names =  list(cfg["boptest_map"].values()) #self.get_names_from_MX(ocp.r.mx) # in order # TODO This is bad coding pracice as it is hardcoded for 'r' only. Should be generalized
        self.forecast_map = cfg['boptest_map'] # TODO Boptest map only refer to reference. Should be more generic to cater for other signals

    def to_np_array(self, forecast):
        ''' 
        Add the forecast to the MPC problem of interest. 
        There should be no dependance on the ordering of references,
        only (possibly) on a mapping between BOPTEST names and MOSIOP names.
        '''
        # cut out current timestep?
        sorted_forecast = {k: forecast[self.forecast_map[k]][1:] for k in self.ocp_names}
        return np.array(list(sorted_forecast.values())).transpose()

    @staticmethod
    def get_names_from_MX(mx):
        ''' Get names in order from concatenated MX objects. '''
        return str(mx).lstrip("MX(vertcat(").rstrip("))").replace(" ", "").split(",")  

        
# BOPTEST subclass of RESTApi

class RestApi(object):
    ''' Abstract class. '''
    def __init__(self):
        self.url = 'http://bacssaas_boptest:5000'
        self.name = self.get_name()['name']

    def initialize(self):
        return requests.put('{0}/initialize'.format(self.url), data={'start_time': self.start_time, 'warmup_period': self.warmup_period})
        
    def get_name(self) -> dict:
        return requests.get('{0}/name'.format(self.url)).json()
    
    def get_forecast(self) -> dict:
        return requests.get('{0}/forecast'.format(self.url)).json()
    
    def set_forecast_params(self, u={}):
        return requests.put('{0}/forecast_parameters'.format(self.url), data=u)
    
    def get_measurement_info(self):
        return requests.get('{0}/measurements'.format(self.url)).json()

    def get_forecast_info(self):
        return requests.get('{0}/forecast_info'.format(self.url)).json()
    
    def get_input_info(self):
        return requests.get('{0}/inputs'.format(self.url)).json()
         
    def set_step(self, step):
        return requests.put('{0}/step'.format(self.url), data={'step':step})
        
    def get_step(self, step):
        return requests.get('{0}/step'.format(self.url)).json()
    
    def get_kpis(self) -> dict:
        return requests.get('{0}/kpi'.format(self.url)).json()
   
    def advance(self, u={}) -> dict:
        return requests.post('{0}/advance'.format(self.url), data=u).json()
    

class Boptest(RestApi):
    ''' Wrapper for Restful-API to BOPTEST. '''
    def __init__(self, cfg, name=None):
        RestApi.__init__(self)
        
        if isinstance(cfg, str) or isinstance(cfg, os.PathLike):
            with open(cfg, "r") as f:
                cfg = json.load(f)
        
        cfg = cfg[name]
        
        self.maps = cfg.pop("maps")
        #self.var = cfg['mosiop']['var_info']

        #self.h = h = cfg['mosiop']['MPC']['temporal']['h']
        #N = cfg['mosiop']['MPC']['temporal']['N']
        self.h = h = cfg["misc"].pop("h")
        self.N = N = cfg["misc"].pop("N")
        self.noise = cfg["misc"].pop("noise", False)
        
        if self.noise:
            np.random.seed(seed=42)    

        self.set_step(h)
        self.set_forecast_params({"horizon": h*(N-1), "interval": h})

        self.start_time = cfg["misc"].pop("start_time")
        self.warmup_period = cfg["misc"].pop("warmup_period")
        
        ''' 
        Takes config-file + desc. of ocp. 
        
        Description of maps from BOPTEST to Modelica-model.
        OCP-description should conform with Modelica naming:
            - <name_sof_mapping> = {<Modelica/OCP_name>:<BOPTEST_name>, ...}    
            
        Example for controls:
            - control_map = {"preHea": "oveAct"}
            
        which means that the overwrite-block the Modelica-model is named 
        "oveAct", while the actual variable that is overwritten by this 
        block is named "preHea".
        '''
        # ocp-names
        self.var = {}
        
        for k, v in self.maps.items():
            setattr(self, k, v) # maps accessed by self.maps[<name_of_map>]
            self.var[k] = list(v.keys())
            
        self.forecast_df = pd.DataFrame(columns=list(self.r.keys()))
        
        self.result_df = pd.DataFrame(columns = list(map(lambda x: x + "_u", list(self.u.values()))) + \
            list(self.boptest_to_ocp.values()))
        
        self.result_df.loc[0] = [0]*len(self.result_df.columns)
        
        self.initialize()
        # get initial temperature:
        res = self.get_results(tf=self.start_time+self.h, ts=self.start_time)
                       
        self.y_names = list(self.y.values())
        
        self.u_names = list(map(lambda x: x + "_u", \
                                list(self.u.values()))) + \
                                    [v for k, v in self.boptest_to_ocp.items() if v not in self.y_names]
        
        self.result_df.loc[int(res.index[0]), self.y_names] = res.loc[res.index[0], self.y_names]
        
            #list(self.boptest_to_ocp[k] for k, v in self.u.items()))
        #self.forecast = pd.DataFrame(columns=list(self.r.values()))
        
        self.initialize()

        # invert map for forecast:
        forecast_map = {v: k for k, v in self.maps["r"].items()}

        cfg = {'boptest_map': forecast_map}# 'mosiop_map':self.var} # TODO to make this more generic boptest_map should have similar variables maps for y,u,z,r,p (latter empty if not applicable)
        self.forecaster = Forecaster(cfg)

    def evolve(self,
               u={},
               y_as_array=True,
               u_as_array=True
               ):
        ''' 
        Advances simulation one step forward.
        Then forecast is retrieved.
            
        # get this to return df:
        '''
        # get forecast:
        forecast = self.forecast()
        
        y = self.advance(u=self.get_control(u))
        #self.forecast_df.loc[y["time"]] = forecast.iloc[0]
        self.forecast_df.loc[int(y["time"] - self.h)] = forecast.iloc[0]
        
        # set u:
        #self.result
        
        self.result_df.loc[y["time"] - self.h, self.u_names] = [y[k] for k in self.result_df.columns if k not in self.y_names]
        self.result_df.loc[y["time"], self.y_names] = [y[k] for k in self.result_df if k in self.y_names]
        
        #self


        if y_as_array:
            y_sorted = self.to_np_array(y, self.boptest_to_ocp, self.var["y"])
        else:
            y_sorted = {k_bop: y[k_bop] for k_ocp, k_bop in self.y.items()}
        
        if self.noise: # add meas noise
            y_sorted += np.random.normal(scale=0.1, size=len(y_sorted))
        
        if u_as_array:
            u_sorted = self.to_np_array(y, self.boptest_to_ocp, self.var["u"])
        else:
            u_sorted = {k_bop: y[k_bop + "_u"] for k_ocp, k_bop in self.u.items()}

        # return actual u
        return forecast, y_sorted, u_sorted

    def forecast(self):
        #return self.to_np_array(self.get_forecast(), self.r, self.var["r"])
        vals = self.to_np_array(self.get_forecast(), self.r, self.var["r"])
        
        return pd.DataFrame(index=np.arange(0, self.h*(self.N), self.h),
                            data=vals,
                            columns=self.var["r"])
    
    @staticmethod
    def to_np_array(y, mapping, var_labels):
        ''' 
        For retrieving, sorting algrebraic, differential variables (e.g. "y", "z")
        y: dict
            - results from advancing emulator one step.
        mapping: dict 
            - known mapping between emulator result and OCP-names 
              (should be one-to-one with Modelica names..)
        labels: list
            - ordering of variables in OCP.
        '''
        # y or z?
        
        vars_sorted = { k: y[mapping[k]] for k in var_labels if k in mapping.keys()}

        return np.array(list(vars_sorted.values())).transpose()

    def get_control(self, u_0) -> dict:
        '''
        Parse the control law from mpc for boptest-usage.
        '''
        if isinstance(u_0, dict):
            return u_0

        u_map = self.maps["u"]
        
        u_values = {v + "_u": u_0.loc[k] \
                    for k, v in u_map.items()}           
        u_active = {v + "_activate": 1 \
                    for k, v in u_map.items()}     
            
        return {**u_values, **u_active}
    
    def construct_y0(self, y): 
        ''' 
        For this, a mapping between state and measurements.
        Assume we have the order of the differential states.
        
        This assumes we have measurements for all states,
        hence it needs to be generalized at some point
        for working with filters etc.
        '''
        return [y[meas] for state, meas in self.maps["state_map"].items()]
       
    def get_results(self, tf, ts=0):
        ''' Get results. '''
        measurements, inputs = self.get_measurement_info(), self.get_input_info()

        #forecasts = self.maps["r"].values()

        points = list(measurements.keys()) + list(inputs.keys())
        df_res = pd.DataFrame()
        
        for point in points:
            res = requests.put('{0}/results'.format(self.url), data={'point_name':point,'start_time':ts, 'final_time':tf}).json()
            df_res = pd.concat((df_res,pd.DataFrame(data=res[point], index=res['time'],columns=[point])), axis=1)
     
        # pdb.set_trace()    
        df_res.index.name = 'time'
        # df_res.index = df_res.index.values/3600 # convert s --> hr
        
        return df_res

    def get_data(self, \
                ts=0, \
                tf=0, \
                mpc_names=True, \
                downsample=True,
                include_forecast=True
                ):
        ''' 
        Get data for parameter estimation,
        including forecasts.
        '''

        # ts adjusted? tf and ts are relative -> adjust
        """

        try:
            # first
            # include last forecast
            #df_res_orig = self.get_results(tf + self.start_time, ts=ts)
            forecast = self.forecast()
            self.forecast_df.loc[self.forecast_df.index[-1] + self.h] = forecast.iloc[0]
        except TypeError:
            pass
        
        df_res = self.get_results(tf + self.start_time, ts=ts)
        
        if include_forecast:
            forecast = self.forecast_df
            forecast.index = pd.TimedeltaIndex(forecast.index, unit="s")
            #df_res_orig.index = pd.TimedeltaIndex(df_res_orig.index, unit="s")
            df_res.index = pd.TimedeltaIndex(df_res.index, unit="s")
            #df_res_orig.index = pd.TimedeltaIndex(df_res_orig.index, unit="s")
            
            # shift (only heating):
            u_names_bop = list(map(lambda x: x + "_u", list(self.u.values()))) + \
                        list([v for k, v in self.boptest_to_ocp.items() if k in self.u])
                        
            rest = [col for col in df_res.columns if col not in u_names_bop]
            
            df_res_u = df_res[u_names_bop].iloc[1:]
            df_rest = df_res[rest].iloc[:-1]
            #df_res = df_res_orig[1:]
            #df_res.index = df_res_orig.index[:-1]
            
            df_res_u.index = df_res.index[:-1]
            df_rest.index = df_res.index[:-1]
            
            df_res = pd.merge(df_res_u, df_rest, left_index=True, right_index=True)
            #df_res = df_res_orig.iloc[:-1]
            
            forecast = forecast.resample('30s').ffill()
            #forecast = forecast.iloc[:-1]
            #df_res = df_res_orig.merge(forecast, left_index=True, right_index=True)
            df_res = df_res.merge(forecast, left_index=True, right_in                downsample=True,dex=True)
        """
        if ts < self.start_time:
            ts += self.start_time
            tf += self.start_time
        
        df_res = pd.merge(self.result_df, self.forecast_df, left_index=True, right_index=True)
        # append last y:
        df_res.loc[self.result_df.index[-1], self.y_names] = self.result_df.loc[self.result_df.index[-1], self.y_names]
            
        if mpc_names:
            """
            boptest_to_ocp = {}
            # get map of all ocp/mpc names
            for name, di in self.neuron.items():
                # measurement name is not the same as overwrite name
                boptest_to_ocp = {**boptest_to_ocp, **di}
            # take rest from mosiop maps
            for name, di in self.maps.items():
                if name not in boptest_to_ocp:
                    # reverse the dict added
                    boptest_to_ocp = {**boptest_to_ocp, **{v: k for k, v in di.items()}} 
            """
            boptest_to_ocp = {v: k for k, v in self.boptest_to_ocp.items()}
            df_res.rename(columns = boptest_to_ocp, inplace=True)
        # downsample
        """
        if downsample:
            #df_res = df_res.loc[[ndx for ndx in df_res.index if ndx % self.h == 0]]
            int_cols = self.sampling["integrate"]
            point_cols = self.sampling["point"]
            
            df_integrate = df_res[int_cols]
            df_point = df_res[point_cols]
            
            rule = str(self.h) + "s"
            df_integrate = df_integrate.resample(rule).mean()
            df_point = df_point.resample(rule).asfreq()
            
            df_res = pd.merge(df_integrate, df_point, left_index=True, right_index=True)
        """
        return df_res.loc[ts:tf]

    def plot_results(self, ts=0, tf=0, cols_to_plot=None, plot_ext=True):
        ''' Plot results of boptest-interaction. '''

        #res = self.get_results(tf, ts=ts)
        if plot_ext:
            res = self.get_data(tf, ts=ts, include_forecast=True)
        else:
            res = self.get_data(tf, ts=ts, include_forecast=False)

        if cols_to_plot is None:
            cols_to_plot = list(filter(lambda x: x != "time" \
                                       and not x.endswith("activate"), \
                                res.columns))
        if len(cols_to_plot) > 5:
            nrows, ncols = int(len(cols_to_plot)/2), 2
        else:
            nrows, ncols = len(cols_to_plot), 1

        fig, axes = plt.subplots(nrows, ncols)
        
        for col, ax in zip(cols_to_plot, axes.flatten()):
            latex_col = self.latexize(col)
            ax.plot(res.index, res[col], label=latex_col)
            ax.legend(loc='upper right', prop={'size': 10}, ncol=1)

        return fig, axes

    @staticmethod
    def latexize(name):
        try:
            name, typ = name.split("_") # naming convention
        except ValueError:
            if "_" not in name:
                # state variable?
                assert len(name) == 2
                return f"${name[0]}_{name[1]}$"
            else:
                name1, name2, typ = name.split("_") # naming convention
                name = "_".join([name1, name2])
        typ = "{" + typ + "}"
        return f"${name}_{typ}$"
    
    
    def plot_temperatures(self, K, days, bounds, solar=False):
        """
        Plot temperatures.
        """
        
        colors = iter(plt.cm.rainbow(np.linspace(0, 1, 5)))
    
        # get result
        res = self.get_data(tf=(K+1)*self.h)
        
        # leave out last: 
        res = res.iloc[:-1]
        dt_index = pd.to_datetime(res.index, origin="2020-01-01 00:00", unit="s").round("s")
        res.index = dt_index
        
        y = list(self.y.keys())
        
        #res.Ti.iloc[:-1] = res.Ti.iloc[1:] 
        #res = res.iloc[:-1]
        fig = plt.figure(figsize=(8,6))
        
        # Add plots vertically:
        
        #ax = fig.add_subplot(2, 1, 1)
        # plot for solar:
        #ax2 = fig.add_subplot(2, 1, 2)
        
        if solar:
            ax = fig.add_subplot(211)
        else:
            ax = fig.add_subplot(111)
        
        #dt_index = pd.Timestamp("2020-01-01 00:00") + res.index
        axes = []
        
        for y_name in y:
            
            prefix = y_name[0]
            
            if len(y_name) == 2:
                suffix = y_name[1]
            elif len(y_name) == 3:
                suffix = y_name[1:2]
            
            #l1 = res.Ti.plot(ax=ax, color="k")
            #l1 = ax.plot(res.index, res.Ti, color="k", label="$T_i$")
            l1 = ax.plot(dt_index, (res[y_name]-273.15), color=next(colors), label="$%s_%s$" % (prefix, suffix))
            ax1 = ax.twinx()
            #l2 = res.phi_h.plot(ax=ax1, color="k", linestyle="--")
            #l2 = ax1.plot(res.index, res.phi_h, color="k", linestyle="dashed", label="$\phi_h$")
            
            # TODO: map from temperature to heater:
            l2 = ax1.plot(dt_index, res.phi_h, color=next(colors), linestyle="dashed", label="$\phi_h$")
            
            #ax.legend([l1, l2], , loc=0)
            ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d %H:%M'))
            fig.autofmt_xdate()
            #ax.legend(["Ti"])
            #ax1.legend(["phi_h"])
            # plot bounds:
            #bounds_plt = pd.concat([bounds]*days)
            post = bounds.get_full(days)
            pre = bounds.get_full(days)
            post -= 273.15
            pre -= 273.15
            #bounds_plt.loc[0] = [0]*len(bounds_plt.columns)
            pre.index = dt_index
            post.index = dt_index
            
            post[post.index.hour >= 12] = np.nan
            pre[(pre.index.hour <= 11) & (pre.index.hour > 0)] = np.nan
            # split bounds in post and pre:
            #post = bounds_plt.loc[[ndx for ndx in bounds_plt.index if ndx.hour < 12]]
            #pre = bounds_plt.loc[[ndx for ndx in bounds_plt.index if ndx.hour >= 12]]
            
            #bounds_plt = bounds_plt.sort_index()
            #bounds_plt[("lb", "Ti")].plot(ax=ax, drawstyle="steps")
            #bounds_plt[("ub", "Ti")].plot(ax=ax, drawstyle="steps")
            #l3 = ax.plot(dt_index, (bounds_plt[("lb", "Ti")]-273.15), drawstyle="steps", label="$T_{i}^{lb}$")
            #l4 = ax.plot(dt_index, (bounds_plt[("ub", "Ti")]-273.15), drawstyle="steps", label="$T_{i}^{ub}$")
            #l3 = ax.plot(dt_index, (bounds_plt[("lb", "Ti")]), drawstyle="steps", label="$T_{i}^{lb}$")
            #l4 = ax.plot(dt_index, (bounds_plt[("ub", "Ti")]), drawstyle="steps", label="$T_{i}^{ub}$")
            cols_bds = ["k", "k"]
            #for i in range(2):
            #    cols_bds.append(next(colors))
            
            # lines
            lns = l1+l2
                
            for i, df in enumerate((post, pre)):
                
                if i == 0:
                    style = "post"
                else:
                    style = "pre"
                    
                l_upper = ax.plot(dt_index,
                                  (df[("ub", y_name)]), 
                                  drawstyle="steps-" + style,
                                  color=cols_bds[0],
                                  label="$%s_{%s}^{ub}$" % (prefix, suffix))
                
                l_lower = ax.plot(dt_index, 
                                  (df[("lb", y_name)]),
                                  drawstyle="steps-" + style,
                                  color=cols_bds[1],
                                  label="$%s_{%s}^{lb}$" % (prefix, suffix))
                
                if i == 0:
                    lns += l_upper
                    lns += l_lower
            
            labs = [l.get_label() for l in lns]
            ax.legend(lns, labs, loc='upper center', ncol=4)
            _min, _max = ax.get_ylim()
            ax.set_ylim([_min, _max+2])
            
            ax.set_ylabel(r"Temperature [$^\circ$C]")
            ax1.set_ylabel(r"Power [W]")
            
            axes.append(ax)
            axes.append(ax1)
        
        
        if solar:
            # plot solar rad
            ax2 = fig.add_subplot(212, sharex=ax)
            l1 = ax2.plot(dt_index, res.phi_s, color=next(colors), label="$\phi_{s}$")
            ax2.set_ylabel(r"Global radiation [$\frac{kW}{m^{2}}$]")
            ax3 = ax2.twinx()
            ax3.set_ylabel(r"Shading control [-]")
            l2 = ax3.plot(dt_index, res.u_sha, drawstyle="steps", color=next(colors), label="$u_{sha}$")
            
            
            _min, _max = ax3.get_ylim()
            ax3.set_ylim([_min, _max*1.2])
            
            lns = l1 + l2
            labs = [l.get_label() for l in lns]
            ax.legend(lns, labs, loc='upper center', ncol=2)
            
            axes.append(ax2)
            axes.append(ax3)
        
        fig.tight_layout()
        
        return fig, axes, dt_index