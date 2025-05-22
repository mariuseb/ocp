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
from functools import reduce
from ocp.ocp import NumpyEncoder
    

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
        self.url = 'http://docker-web-1:80'
        #self.url = 'http://docker-boptest-1:5000'
        #self.name = self.get_name()['name']
        #self.forecast_points = list(requests.get('{0}/forecast_points'.format(self.url)).json()["payload"].keys())
    
    def initialize(self):
        return requests.put('{0}/initialize/{1}'.format(self.url, self.testid), data={
            'start_time': self.start_time, 
            'warmup_period': self.warmup_period
            }
        )

    def put_forecast(
            self, 
            N: int, 
            dt: int
        ):
        
        return requests.put('{0}/forecast/{1}'.format(self.url, self.testid), 
                            data={'point_names': self.forecast_points,
                                  'horizon': dt*(N-1),
                                  'interval': dt}
                            ).json()["payload"]
    
    def set_forecast_params(self, u={}):
        return requests.put('{0}/forecast_parameters/{1}'.format(self.url, self.testid), data=u)
    
    def get_measurement_info(self):
        return requests.get('{0}/measurements/{1}'.format(self.url, self.testid)).json()["payload"]

    def get_forecast_info(self):
        return requests.get('{0}/forecast_points/{1}'.format(self.url, self.testid)).json()["payload"]
    
    def get_input_info(self):
        return requests.get('{0}/inputs/{1}'.format(self.url, self.testid)).json()["payload"]
         
    def set_step(self, step):
        return requests.put('{0}/step/{1}'.format(self.url, self.testid), data={'step':step})
    
    def get_step(self, step):
        return requests.get('{0}/step/{1}'.format(self.url, self.testid)).json()["payload"]
    
    def put_results(self, ts, tf, points):
        return requests.put('{0}/results/{1}'.format(self.url, self.testid),
                            json={
                                'point_names': points,
                                'start_time': ts,
                                'final_time': tf
                            }).json()["payload"]
    
    def get_kpis(self):
        return requests.get('{0}/kpi/{1}'.format(self.url, self.testid)).json()["payload"]
   
    def advance(self, u={}):
        return requests.post('{0}/advance/{1}'.format(self.url, self.testid), json=u).json()["payload"]
    
    def get_testcases(self):
        return [case["testcaseid"] for case in requests.get('{0}/testcases'.format(self.url)).json()]
    
    def stop_testcase(self, testid):
        return requests.put('{0}/stop/{1}'.format(self.url, testid))
    
    def select_testcase(self, name):
        resp = requests.post('{0}/testcases/{1}/select'.format(self.url, name)).json()
        return resp["testid"]

    

class Boptest(RestApi):
    ''' Wrapper for Restful-API to BOPTEST. '''
    def __init__(self, cfg, name=None, bypass_forecast=False):
        RestApi.__init__(self)
        self.name = name
        try: # if file exists
            with open("testid.txt", "r") as f:
                old_testid = f.read()
            self.stop_testcase(old_testid)
        except FileNotFoundError:
            pass
        if isinstance(cfg, str) or isinstance(cfg, os.PathLike):
            with open(cfg, "r") as f:
                cfg = json.load(f)
        cfg = cfg[name]
        # spin up testcase worker:
        testcases = self.get_testcases()
        assert name in testcases
        self.testid = self.select_testcase(name)
        # write testid to file in current folder:
        with open("testid.txt", "w+") as f:
            f.write(self.testid)
        self.maps = cfg.pop("maps")
        #self.var = cfg['mosiop']['var_info']
        #self.h = h = cfg['mosiop']['MPC']['temporal']['h']
        #N = cfg['mosiop']['MPC']['temporal']['N']
        self.h = h = cfg["misc"].pop("h")
        self.N = N = cfg["misc"].pop("N")
        self.noise = cfg["misc"].pop("noise", False)
        self.bypass_forecast = bypass_forecast
        if bypass_forecast:
            # read resource folder:s
            self.get_forecast_df() # path?
        if self.noise:
            np.random.seed(seed=42)
        self.set_step(h)
        self.set_forecast_params({"horizon": h*(N-1), "interval": h})
        # start time
        self.start_time = self.time = cfg["misc"].pop("start_time")
        self.warmup_period = cfg["misc"].pop("warmup_period")
        # write info to text files in current dir        
        if not os.path.exists(self.name + "_meas_info.txt"):
            with open(self.name + "_meas_info.txt", "w+") as f:
                pprint(self.get_measurement_info(), stream=f)
            with open(self.name + "_forecast_info.txt", "w+") as f:
                pprint(self.get_forecast_info(), stream=f)
            with open(self.name + "_input_info.txt", "w+") as f:
                pprint(self.get_input_info(), stream=f)
        
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
        self.boptest_to_ocp = dict()
        for k, v in self.maps.items():
            setattr(self, k, v) # maps accessed by self.maps[<name_of_map>]
            self.var[k] = list(v.keys())
            if k in ("u", "y"):
                suffix = "_" + k
            else:
                suffix = ""
            _map = {_k: _v + suffix  for _k, _v in v.items()}
            self.boptest_to_ocp = {
                **self.boptest_to_ocp,
                **_map
            }  
        self.forecast_df = pd.DataFrame(columns=list(self.r.keys()))
        # get first forecast:
        data = self.get_forecast()
        # set it:
        self.forecast_df[0] = data.loc[0]
        #self.result_df = pd.DataFrame()
        self.initialize()
        # invert map for forecast:
        self.forecast_map = {v: k for k, v in self.maps["r"].items()}
        cfg = {'boptest_map': self.forecast_map}# 'mosiop_map':self.var} # TODO to make this more generic boptest_map should have similar variables maps for y,u,z,r,p (latter empty if not applicable)
        self.forecaster = Forecaster(cfg)

    def get_forecast_df(self):
        """
        Get forecast df.
        """
        files = os.listdir("Resources")
        dfs = []
        for file in files:
            path = os.path.join("Resources", file)
            # first read:
            df = pd.read_csv(path, 
                        header=[100],
                        #skiprows=[0,2,3,4,5,6], 
                        index_col=0)
            #header = len(df.columns) + 2
            n_cols = len(df.columns)
            #header = n_cols + 2
            header = 1
            skiprows = list(set(range(n_cols + 2)).difference(set([header])))
            df = pd.read_csv(path, 
                        header=[header],
                        #header=[n_cols],
                        skiprows=skiprows, 
                        index_col=0)
            if file.startswith("weather"):
                # resample to MPC sampling time:
                #df = df[0:-1:self.h]
                indices = [ndx for ndx in df.index if ndx % self.h == 0]
                df = df.loc[indices]
            df["time"] = df.index
            df.index.name = ""
            dfs.append(df)
        
        df = reduce(lambda left, right: 
            pd.merge(left, right, on=['time'],
                    how='outer'), dfs)
        df.index = df.time
        self.whole_forecast_df = df.ffill()

    @property
    def forecast_points(self):
        forecast_info = self.get_forecast_info()
        return list(forecast_info.keys())

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
        # advance:
        y = self.advance(u=self.get_control(u))
        # get forecast after advance:
        forecast = self.get_forecast()
        # internal time:
        self.time = y["time"]
        # set next column empty:
        #self.result_df.loc[y["time"], :] = np.nan
        self.forecast_df.loc[y["time"]] = forecast.iloc[0]
        #self.forecast_df.loc[int(y["time"] - self.h)] = forecast.iloc[0]
        #self.result_df.loc[y["time"] - self.h, self.u_names] = [y[k] for k in self.result_df.columns if k not in self.y_names]
        #self.result_df.loc[y["time"], self.y_names] = [y[k] for k in self.result_df if k in self.y_names]
        #self.result_df.loc[y["time"] - self.h, self.u_names] = [y[k] for k in self.u_names]
        #self.result_df.loc[y["time"], self.u_names] = [y[k] for k in self.u_names]
        #self.result_df.loc[y["time"], self.y_names] = [y[k] for k in self.y_names]
        
        if y_as_array:
            y_sorted = self.to_np_array(y, self.boptest_to_ocp, self.var["y"])
        else:
            # NOTE: changed this to return mapping of OCP-vars instead of BOPtest vars
            y_sorted = {k_ocp: y[k_bop + "_y"] for k_ocp, k_bop in self.y.items()}
        
        if self.noise: # add meas noise
            y_sorted += np.random.normal(scale=0.1, size=len(y_sorted))
        
        if u_as_array:
            u_sorted = self.to_np_array(y, self.boptest_to_ocp, self.var["u"])
        else:
            u_sorted = {k_bop: y[k_bop + "_u"] for k_ocp, k_bop in self.u.items()}

        # return actual u
        return forecast, y_sorted, u_sorted

    def get_forecast(self):
        #return self.to_np_array(self.get_forecast(), self.r, self.var["r"])
        index = np.arange(0, self.h*(self.N), self.h)
        
        if self.bypass_forecast:
            start = self.time
            stop = self.time + (self.N-1)*self.h
            _forecast = self.whole_forecast_df.loc[start:stop].rename(columns=self.forecast_map)
            forecast = _forecast[self.var["r"]]
            forecast.index = index
        else:
            _forecast = self.put_forecast(self.N, self.h)    
            vals = self.to_np_array(_forecast,
                                    self.r,
                                    self.var["r"])
            forecast = pd.DataFrame(index=index,
                            data=vals,
                            columns=self.var["r"])
        """
        Save first step, relying on internal time:
        """
        #offset = 2
        N = len(self.forecast_df)
        self.forecast_df.loc[self.time] = forecast.iloc[0]
        return forecast
    
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
        
        """
        u_values = {v + "_u": u_0.loc[k] \
                    for k, v in u_map.items()}           
        u_active = {v + "_activate": 1 \
                    for k, v in u_map.items()}     
        """
        u_values = {}
        u_active = {}
        for k, v in u_map.items():
            if k in u_0:
                u_values[v +  "_u"] = u_0.loc[k]
                u_values[v +  "_activate"] = 1
            #else:
            #    u_values[v +  "_u"] = 0
            #    u_values[v +  "_activate"] = 0
        
        u_dict = {**u_values, **u_active}
        return u_dict
    
    def construct_y0(self, y): 
        ''' 
        For this, a mapping between state and measurements.
        Assume we have the order of the differential states.
        
        This assumes we have measurements for all states,
        hence it needs to be generalized at some point
        for working with filters etc.
        '''
        return [y[meas] for state, meas in self.maps["state_map"].items()]
       
    def get_results(
            self,
            tf,
            ts=0,
            resample=True,
            include_forecast=True
        ) -> pd.DataFrame:
        
        measurements, inputs = \
            self.get_measurement_info(), self.get_input_info()
        points = list(measurements.keys()) + \
                 list(inputs.keys())
        
        if ts == 0 and self.start_time != 0:
            ts = self.start_time
            tf = self.start_time + tf
            
        res = self.put_results(ts, tf, points)
        df_res = pd.DataFrame().from_dict(res)
        rev_map = {v: k for k, v in self.boptest_to_ocp.items()}
        df_res.rename(columns=rev_map, inplace=True)
        df_res.index.name = 'time'
        df_res.index = pd.to_timedelta(df_res.index*30, unit="s")
        if resample:
            df_res = df_res.resample(rule=str(self.h/60) + "min").mean()
        if include_forecast:
            forecast_df = self.forecast_df.copy()
            forecast_df.index = df_res.index    
            df_res = pd.merge(
                df_res,
                forecast_df,
                left_index=True,
                right_index=True
            )
        return df_res

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
    
    
    def plot_temperatures(self, K, days, bounds, solar=False, heat_key="phi_h", cost_key="cost"):
        """
        Plot temperatures.
        """
        colors = iter(plt.cm.rainbow(np.linspace(0, 1, 5)))
        res = self.get_results(tf=(K+1)*self.h)
        #dt_index = pd.to_datetime(res.index, origin="2020-01-01 00:00")
        dt_index = pd.to_datetime(res.index.astype(np.int64))
        res.index = dt_index
        #res.index = dt_index
        y = ["Ti"]
        fig = plt.figure(figsize=(8,6))
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
            if y_name.startswith("T"):
                ser = (res[y_name]-273.15)
            else:
                ser = res[y_name]     
            index = np.array(res.index)
            l1 = ax.plot(index, ser.values, drawstyle="steps-post", color=next(colors), label="$%s_%s$" % (prefix, suffix))
            ax1 = ax.twinx()
            ax2 = ax.twinx()
            l2 = ax1.plot(index, res[[heat_key]].values, drawstyle="steps-post", color="k", linestyle="dashed", label="$\phi_h$")
            l3 = ax2.plot(index, res[[cost_key]].values, drawstyle="steps-post", color="b", linestyle="dashed", label="$c$")
            ax2.spines["right"].set_position(("axes", 1.1))
            ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d %H:%M'))
            post = bounds.get_full(days)
            pre = bounds.get_full(days)
            post -= 273.15
            pre -= 273.15
            #bounds_plt.loc[0] = [0]*len(bounds_plt.columns)
            pre.index = dt_index
            post.index = dt_index
            
            #post[post.index.hour >= 12] = np.nan
            #pre[(pre.index.hour <= 11) & (pre.index.hour > 0)] = np.nan
            cols_bds = ["k", "k"]
            # lines
            lns = l1 + l2 + l3
            #except:
            l_upper = ax.plot(index,
                            (post[("ub", y_name)].values), 
                            drawstyle="steps-" + "post",
                            color=cols_bds[0],
                            label="$%s_{%s}^{ub}$" % (prefix, "i"))
            
            l_lower = ax.plot(index, 
                            (post[("lb", y_name)].values),
                            drawstyle="steps-" + "post",
                            color=cols_bds[1],
                            label="$%s_{%s}^{lb}$" % (prefix, "i"))
            lns += l_upper
            lns += l_lower
            
            """
            #    lns = [l1]  
            for i, df in enumerate((post, pre)):
                if i == 0:
                    style = "post"
                else:
                    style = "pre"
                try: 
                    l_upper = ax.plot(index,
                                    (df[("ub", y_name)].values), 
                                    drawstyle="steps-" + style,
                                    color=cols_bds[0],
                                    label="$%s_{%s}^{ub}$" % (prefix, suffix))
                    
                    l_lower = ax.plot(index, 
                                    (df[("lb", y_name)].values),
                                    drawstyle="steps-" + style,
                                    color=cols_bds[1],
                                    label="$%s_{%s}^{lb}$" % (prefix, suffix))
                except:
                    pass 
                if i == 0:
                    lns += l_upper
                    lns += l_lower
            """
            labs = [l.get_label() for l in lns]
            ax.legend(lns, labs, loc='upper center', ncol=5)
            _min, _max = ax.get_ylim()
            ax.set_ylim([_min, _max+2])
            ax.set_ylabel(r"Temperature [$^\circ$C]")
            ax1.set_ylabel(r"Power [W]")
            ax2.set_ylabel(r"Cost [EUR/kWh]")
            axes.append(ax)
            axes.append(ax1)
        if solar:
            # plot solar rad
            ax2 = fig.add_subplot(212, sharex=ax)
            l1 = ax2.plot(index, res.phi_s.values, color=next(colors), label="$\phi_{s}$")
            ax2.set_ylabel(r"Global radiation [$\frac{kW}{m^{2}}$]")
            ax3 = ax2.twinx()
            ax3.set_ylabel(r"Shading control [-]")
            try:
                l2 = ax3.plot(dt_index, res.u_sha, drawstyle="steps", color=next(colors), label="$u_{sha}$")
                lns = l1 + l2
            except:
                pass
            _min, _max = ax3.get_ylim()
            ax3.set_ylim([_min, _max*1.2])
            labs = [l.get_label() for l in lns]
            ax.legend(lns, labs, loc='upper center', ncol=2)
            axes.append(ax2)
            axes.append(ax3)
        #fig.tight_layout()
        return fig, axes, dt_index