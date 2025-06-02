from collections import OrderedDict
import json
import copy
import os

class Config(object):
    def __call__(self, config):
        if isinstance(config, str) or isinstance(config, os.PathLike):
            with open(config, "r") as f:
                config = json.load(f, object_pairs_hook=OrderedDict)
        if "integrator" in config.keys():
            if "dt" not in config["integrator"]:
                config["integrator"]["dt"] = config["dt"]
        return copy.deepcopy(config)