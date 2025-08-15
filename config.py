import json
import copy
import os
import hashlib
import inspect
import numpy as np
import casadi as ca
import pandas as pd
from pathlib import Path
from pprint import pprint
from collections import OrderedDict

class NativeTypeEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, np.integer):
            return int(obj)
        if isinstance(obj, np.floating):
            return float(obj)
        if isinstance(obj, np.ndarray):
            return obj.tolist()
        if isinstance(obj, pd.DataFrame):
            if not isinstance(obj.index, pd.RangeIndex):
                obj.index = range(len(obj.index))
            if "dt_index" in obj.columns:
                obj.drop(columns=["dt_index"], inplace=True)
            return obj.to_dict()
        #if isinstance(obj, pd.Timestamp):
        #    return obj.to_pydatetime()
        if isinstance(obj, Path):
            return str(obj)
        if isinstance(obj, ca.DM):
            return list(np.array(obj).flatten())
        return super(NativeTypeEncoder, self).default(obj)

def traverse_dict(nested_dict):
    for key, value in nested_dict.items():
        if isinstance(value, dict):
            traverse_dict(value)
        elif isinstance(value, str) and value.endswith(".json"):
            nested_dict[key] = Config()(value)   
        else:
            pass # do nothing

def convert_json_to_native_types(d: OrderedDict):
    return json.dumps(d, sort_keys=True, cls=NativeTypeEncoder)

def get_json_hash(config: OrderedDict):
    s = convert_json_to_native_types(
        config
    )
    return str(
                int(
                    hashlib.sha256(s.encode('utf-8')).hexdigest(),
                    16) %
            10**8
        ) 


def get_abspath_of_caller(path):
    current_file_path_obj = Path(__file__)
    current_directory_obj = current_file_path_obj.parent
    return Path(current_directory_obj, path)

class Config(object):
    def __call__(self, config):
        if isinstance(config, str) or isinstance(config, os.PathLike):
            #config = get_abspath_of_caller(config)
            with open(config, "r") as f:
                config = json.load(f, object_pairs_hook=OrderedDict)
        if "integrator" in config.keys():
            if "dt" not in config["integrator"]:
                try:
                    config["integrator"]["dt"] = config["dt"]
                except KeyError: # estimation config
                    pass
        traverse_dict(config)
        return copy.deepcopy(
                config
        )
    
    