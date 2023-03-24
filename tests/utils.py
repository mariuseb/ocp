import pandas as pd
import numpy as np
import pdb
import os
import ocp

#pd.set_option('display.max_rows', 500)
#pd.set_option('display.max_columns', 500)
#pd.set_option('display.width', 1000)

def get_opt_config_path():
    return os.path.join(ocp.__path__[0], "tests", "opt_configs") 

def get_boptest_config_path():
    return os.path.join(ocp.__path__[0], "tests", "boptest_configs") 

def get_data_path():
    return os.path.join(ocp.__path__[0], "tests", "data") 


class Bounds(object):
    def __init__(
                self, 
                dt: int,
                x: list = None,
                y: list = None,
                lb_night=None,
                ub_night=None,
                lb_day=None,
                ub_day=None,
                day_begin=7,
                day_end=22
                ):
        
        self.dt = dt
        self.t_h = int(3600/dt)
        self.x = x
        self.y = y
        self.day_begin = day_begin
        self.day_end = day_end
        self._init_df(
                    lb_night,
                    ub_night, 
                    lb_day,
                    ub_day
                     )
        
    def _init_df(
                 self,
                 lb_nig,
                 ub_nig,
                 lb_d,
                 ub_d
                ):
        
        self.df = pd.DataFrame(
                        index=range(self.t_h*24),
                        columns=pd.MultiIndex.from_product(
                            [
                            ["lb","ub"],
                            self.x
                            ]
                        )
                        )
        
        # ub, lb for non-material states:
        #diff = len(self.x) - len(self.y)
        #lb_night = np.append(np.array([lb_night]*len(self.y)), [10]*diff)
        #ub_night = np.append(np.array([ub_night]*len(self.y)), [500]*diff)
        #lb_day = np.append(np.array([lb_day]*len(self.y)), [10]*diff)
        #ub_day = np.append(np.array([ub_day]*len(self.y)), [500]*diff)
        #lb_night = np.array([lb_night, 10, lb_night, 10])
        #ub_night = np.array([ub_night, 500, ub_night, 500])
        #lb_day = np.array([lb_day, 10, lb_day, 10])
        #ub_day = np.array([ub_day, 500, ub_day, 500])
           
        # init arrays:
        lb_night = np.zeros(len(self.x))
        ub_night = np.zeros(len(self.x))
        lb_day = np.zeros(len(self.x))
        ub_day = np.zeros(len(self.x))
        
        # x is ordered:
        for i, name in enumerate(self.x):
            
            if name in lb_nig:
                lb_night[i] = lb_nig[name]
            else:
                lb_night[i] = 0
            
            if name in ub_nig:
                ub_night[i] = ub_nig[name]
            else:
                ub_night[i] = 500
            
            if name in lb_d:
                lb_day[i] = lb_d[name]
            else:
                lb_day[i] = 0
            
            if name in ub_d:
                ub_day[i] = ub_d[name]
            else:
                ub_day[i] = 500
        
        if lb_night.shape == (1,):
            lb_night = lb_night.reshape((1,1))
        if ub_night.shape == (1,):
            ub_night = ub_night.reshape((1,1))
        if ub_day.shape == (1,):
            ub_day = ub_day.reshape((1,1))
        if lb_day.shape == (1,):
            lb_day = lb_day.reshape((1,1))

        
        self.df.loc[0:self.t_h*7, "lb"] = lb_night
        self.df.loc[0:self.t_h*7, "ub"] = ub_night
        self.df.loc[self.t_h*7:(self.t_h*22 + 1), "lb"] = lb_day
        self.df.loc[self.t_h*7:(self.t_h*22 + 1), "ub"] = ub_day
        self.df.loc[(self.t_h*22 + 1):, "lb"] = lb_night
        self.df.loc[(self.t_h*22 + 1):, "ub"] = ub_night
    
    def get_bounds(self, k: int, N: int):
        """_summary_

        Args:
            k (int): discrete time step
            N (int): MPC horizon

        Returns:
            (np.array, np.array) : lower bound, upper bound
        """
        #if k == 90:
        #    print("head")
        
        inds = list(map(lambda x: x % (self.t_h*24),
                        (range(k+1, k+N))))
        
        # ref:
        
        
        return self.df.loc[inds, "lb"].values.flatten(), \
                self.df.loc[inds, "ub"].values.flatten(), \
                self.df.loc[inds, "lb"]["Ti"].values.flatten()
                
    def get_full(self, days):
        """
        Get full bounds frame. 
        """
        df = pd.concat([self.df]*days)
        df.index = range(self.dt, (len(df.index)+1)*self.dt, self.dt)
        return df