from boptest_api import Boptest
import casadi as ca
import matplotlib.pyplot as plt
import pandas as pd
import json
import numpy as np
import pprint

#from model import TestCase6, TestCase7, TestCase5, TestCase1

if __name__ == '__main__':

    with open("config.json", "r") as f:
        cfg = json.load(f)
    
    boptest_cfg = cfg["ZEBLL"]["boptest"]

    # initialize BOPTEST
    boptest = Boptest(boptest_cfg)

    for k in range(1):

        # evolve BOPTEST emulator
        r, y_meas = boptest.evolve()
        r.to_csv("data/MPC_open_loop_test.csv")
        #r, y_meas = boptest.evolve()



