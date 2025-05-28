import numpy as np
import pathlib
from pathlib import Path
import pandas as pd
from functools import reduce
import os
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

class BoptestMaps(object):
    def __init__(self, maps):
        self.set_maps(maps)
    
    def set_maps(self, maps):
        self.var = {}
        self.ocp_to_boptest = dict()
        for k, v in maps.items():
            setattr(self, k, v) # maps accessed by self.maps[<name_of_map>]
            self.var[k] = list(v.keys())
            if k in ("u", "y"):
                suffix = "_" + k
            else:
                suffix = ""
            _map = {_k: _v + suffix  for _k, _v in v.items()}
            self.ocp_to_boptest = {
                **self.ocp_to_boptest,
                **_map
            }  
        self.boptest_to_ocp = {v: k for k, v in self.ocp_to_boptest.items()}