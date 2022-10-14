import pandas as pd
import numpy as np
import pdb

#pd.set_option('display.max_rows', 500)
#pd.set_option('display.max_columns', 500)
#pd.set_option('display.width', 1000)


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
                 lb_night,
                 ub_night,
                 lb_day,
                 ub_day
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
        diff = len(self.x) - len(self.y)
        lb_night = np.append(np.array(lb_night), [10]*diff)
        ub_night = np.append(np.array(ub_night), [500]*diff)
        lb_day = np.append(np.array(lb_day), [10]*diff)
        ub_day = np.append(np.array(ub_day), [500]*diff)
        
        self.df.loc[0:self.t_h*7, "lb"] = lb_night
        self.df.loc[0:self.t_h*7, "ub"] = ub_night
        self.df.loc[self.t_h*7:self.t_h*22, "lb"] = lb_day
        self.df.loc[self.t_h*7:self.t_h*22, "ub"] = ub_day
        self.df.loc[self.t_h*22:, "lb"] = lb_night
        self.df.loc[self.t_h*22:, "ub"] = ub_night
    
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
        
        return self.df.loc[inds, "lb"].values.flatten(), \
                self.df.loc[inds, "ub"].values.flatten()    
                
    def get_full(self, days):
        df = pd.concat([self.df]*days)
        df.index = range(self.dt, (len(df.index)+1)*self.dt, self.dt)
        return df