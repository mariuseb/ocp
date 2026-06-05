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
from utils import quick_plot, plot_parameter_evolution, get_value_function_error
from pprint import pprint
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    cfg = Config()("coordinator_boptest_2R2C.json")
    traverse_dict(
        cfg
    )
    
    # limits:
    start = pd.Timedelta('14 days 00:00:00')
    
    cfg = Config()("coordinator_boptest_2R2C_adaptive_4_months.json")
    traverse_dict(
        cfg
    )
    coord_ad_mpc = Coordinator.read_result(cfg)
    quick_plot(coord_ad_mpc)
    kpis_ad_mpc = coord_ad_mpc.get_custom_kpis(start=start)

    plot_parameter_evolution(coord_ad_mpc, "params_result/2R2C_params_jan.csv")
    value = get_value_function_error(coord_ad_mpc, 12)
    
    print("tail")