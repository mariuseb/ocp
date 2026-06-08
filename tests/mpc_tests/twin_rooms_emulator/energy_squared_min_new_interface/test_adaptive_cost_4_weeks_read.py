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
from utils import quick_plot, plot_parameter_evolution
from pprint import pprint
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    start = pd.Timedelta('00 days 00:00:00')

    cfg = Config()("coordinator_boptest_2R2C_cost.json")
    traverse_dict(
        cfg
    )
    cfg["days"] = 28
    
    # limits:
    
    coord_cost = Coordinator.read_result(cfg, path="results/25596380.pkl")
    quick_plot(coord_cost)
    kpis_cost = coord_cost.get_custom_kpis(start=start)
    
    # adaptive:
    cfg = Config()("coordinator_boptest_2R2C_adaptive_cost.json")
    traverse_dict(
        cfg
    )
    cfg["days"] = 28
    
    coord_ad_cost = Coordinator.read_result(cfg)
    quick_plot(coord_ad_cost)
    kpis_ad_cost = coord_ad_cost.get_custom_kpis(start=start)
   
    plot_parameter_evolution(coord_ad_cost, "params_result/2R2C_params_jan.csv")
    
    
    cfg = Config()("coordinator_boptest_2R2C_MHE_cost.json")
    traverse_dict(
        cfg
    )
    cfg["days"] = 28
    
    coord_mhe_cost = Coordinator.read_result(cfg, path="results/26779476.pkl")
    quick_plot(coord_mhe_cost)
    kpis_mhe_cost = coord_mhe_cost.get_custom_kpis(start=start)
    
    plot_parameter_evolution(coord_mhe_cost, "params_result/2R2C_params_jan.csv")
    
    print("tail")