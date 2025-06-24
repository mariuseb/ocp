from collections import OrderedDict
import json
import copy
import os

def traverse_dict(nested_dict):
    for key, value in nested_dict.items():
        if isinstance(value, dict):
            traverse_dict(value)
        elif isinstance(value, str) and value.endswith(".json"):
            nested_dict[key] = Config()(value)   
        else:
            pass # do nothing


class Config(object):
    def __call__(self, config):
        if isinstance(config, str) or isinstance(config, os.PathLike):
            with open(config, "r") as f:
                config = json.load(f, object_pairs_hook=OrderedDict)
        if "integrator" in config.keys():
            if "dt" not in config["integrator"]:
                try:
                    config["integrator"]["dt"] = config["dt"]
                except KeyError: # estimation config
                    pass
        return copy.deepcopy(
                config
        )