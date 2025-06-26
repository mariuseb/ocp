#from ast import Param
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
#import os
#from pathlib import Path
#from ocp.mpc_agent import MPCAgent
#from ocp.boptestGymEnv import BoptestGymEnv
#from ocp.customGymEnv import CustomGymEnv
from ocp.coordinator import Coordinator
import pandas as pd
from ocp.config import Config, traverse_dict
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_2R3C_adaptive.json")
    traverse_dict(
        cfg
    )
    coord = Coordinator(
        # "coordinator_boptest.json"
        cfg
    )
    x0 = np.array([
        293.15, 293.15, 16
    ])
    coord.run(x0=x0)
    res = coord.env.get_results(86400*2)
    res_nosplit = coord.env.get_results(86400*2, split_requests=False)
    assert (res_nosplit == res).all().all()
    print(res)
    