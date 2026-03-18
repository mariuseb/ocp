import numpy as np
import pathlib
from pathlib import Path
import pandas as pd
from functools import reduce
import os
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from abc import ABC, abstractmethod, ABCMeta
from typing import List

class BoptestGymABC(metaclass=ABCMeta):
    
    """
    @property
    @abstractmethod
    def boptest_to_ocp(self):
        pass
    """
    
    @abstractmethod
    def _get_results(
        self,
        tf: int,
        ts: int = 0,
        resample: bool = True
    ) -> pd.DataFrame:
        pass
    
    def get_results(
        self,
        tf,
        ts=0,
        resample=True,
        split_requests=True,
        data_path=Path("Resources")
    ) -> pd.DataFrame:
        internal_results = self._get_results(
            tf,
            ts=ts,
            resample=resample,
            split_requests=split_requests
        )
        if "time" not in internal_results.columns:
            internal_results["time"] = internal_results.index
        forecast_df = get_forecast_df(data_path)
        forecast_df = forecast_df.loc[internal_results.time]
        forecast_df.index = internal_results.index    
        df_res = pd.merge(
            internal_results ,
            forecast_df,
            left_index=True,
            right_index=True
        )
        return df_res.rename(
            columns=self.maps.boptest_to_ocp
        )

    @staticmethod
    def get_bound_cols(
        res
    ):
        return [col for col in res.columns if "_lb" in col or "_ub" in col]
    
    @staticmethod
    def multiindex_from_flat(
        y: List[str]
    ):
        return pd.MultiIndex.from_product(
            [["lb", "ub"], y],
            names=['bound', 'y']
        )
    

    def plot_temperatures(
        self,
        tf,
        ts=0,
        solar=False, 
        heat_key="phi_h", 
        cost_key="cost",
        y=["Ti"],
        res=None
    ):
        """
        Plot temperatures.
        """
        if res is None:
            res = self.get_results(
                tf, 
                ts=ts
            )
        bounds = res[self.get_bound_cols(res)]
        bounds.columns = self.multiindex_from_flat(y)
        # plot:
        colors = iter(plt.cm.rainbow(np.linspace(0, 1, 5)))
        dt_index = pd.to_datetime(res.index.astype(np.int64)*1E9)
        if not isinstance(res.index, pd.DatetimeIndex):
            res.index = dt_index
        #res.index = dt_index
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
            l1 = ax.plot(index, ser.values, linewidth=0.75, drawstyle="steps-post", color=next(colors), label="$%s_%s$" % (prefix, suffix))
            ax1 = ax.twinx()
            ax2 = ax.twinx()
            l2 = ax1.plot(index, res[[heat_key]].values, linewidth=0.75, drawstyle="steps-post", color="k", linestyle="dashed", label="$\phi_h$")
            l3 = ax2.plot(index, res[[cost_key]].values, linewidth=0.75, drawstyle="steps-post", color="y", linestyle="dashed", label="$c$")
            ax2.spines["right"].set_position(("axes", 1.1))
            ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d %H:%M'))
            
            """
            if bounds.shape[0] == 1: # then make periodic:
                bounds = pd.concat([bounds]*(K+1))
            """
            
            post = bounds.copy()
            pre = bounds.copy()
            post -= 273.15 # - 13
            pre -= 273.15 # - 13
                    
            pre.index = dt_index
            post.index = dt_index
            post[post.index.hour >= 12] = np.nan
            pre[(pre.index.hour <= 11) & (pre.index.hour > 0)] = np.nan
                
            cols_bds = ["k", "k"]
            # lines
            lns = l1 + l2 + l3
            #except:
            for i, df in enumerate((pre, post)):
                if i == 0:
                    style = "pre"
                else:
                    style = "post"
                try: 
                    l_upper = ax.plot(index,
                                    (df[("ub", y_name)].values), 
                                    #(df[y_name + "_ub"].values), 
                                    linewidth=0.75,
                                    drawstyle="steps-" + style,
                                    color=cols_bds[0],
                                    label="$%s_{%s}^{ub}$" % (prefix, suffix))
                    
                    l_lower = ax.plot(index, 
                                    #(df[y_name + "_lb"].values),
                                    (df[("lb", y_name)].values), 
                                    linewidth=0.75,
                                    drawstyle="steps-" + style,
                                    color=cols_bds[1],
                                    label="$%s_{%s}^{lb}$" % (prefix, suffix))
                except:
                    pass 
                if i == 0:
                    lns += l_upper
                    lns += l_lower
            labs = [l.get_label() for l in lns]
            ax.legend(lns, labs, loc='upper center', ncol=5)
            _min, _max = ax.get_ylim()
            ax.tick_params(axis='x', labelrotation=45)
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
        return fig, axes, res
    

def get_forecast_df(
    path: os.PathLike,
    dt: int = 900
):
    """
    Get forecast df.
    """
    files = os.listdir(path)
    #files = path.iterdir()
    dfs = []
    for file in files:
        """
        _path = os.path.join(
            path,
            file
        )
        # first read:
        df = pd.read_csv(
            _path, 
            #header=[100],
            header=[0],
            index_col=0
        )
        n_cols = len(df.columns)
        header = 1
        skiprows = list(
            set(range(n_cols + 2)
        ).difference(
            set([header])
            )
        )
        df = pd.read_csv(
            _path, 
            header=[header],
            #header=[n_cols],
            skiprows=skiprows, 
            index_col=0
        )
        if str(file).startswith("weather"):
            indices = [
                ndx for ndx in df.index
                if ndx % dt == 0
            ]
            df = df.loc[indices]
        """
        _path = os.path.join(
            path,
            file
        )
        df = pd.read_csv(
            _path, 
            header=[0],
            #header=[n_cols],
            #skiprows=skiprows, 
            index_col=0
        )
        indices = [
            ndx for ndx in df.index
            if ndx % dt == 0
        ]
        df = df.loc[indices]
        df["time"] = df.index
        df.index.name = ""
        dfs.append(df)
    df = reduce(lambda left, right: 
        pd.merge(
            left, 
            right, 
            on=['time'],
            how='outer'),
            dfs
        )
    df.index = df.time.astype(int)
    df["dt_index"] = pd.to_timedelta(df.index, unit="s")
    return df.ffill().drop_duplicates()
    #return df.interpolate().drop_duplicates()

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