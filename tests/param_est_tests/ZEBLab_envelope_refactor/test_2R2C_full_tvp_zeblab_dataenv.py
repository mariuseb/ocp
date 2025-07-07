#from ast import Param
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import rc
from pprint import pprint
from ocp.coordinator import Coordinator
import pandas as pd
from ocp.config import Config
rc('mathtext', default='regular')



if __name__ == "__main__":
    
    cfg = Config()("coordinator_zeblab_dataenv_full_tvp.json")
    coord = Coordinator(
        cfg
    )
    Ti0 = coord.env.res.iloc[coord.env.i]["yTi"]
    x0 = np.array([
        Ti0, Ti0 - 2
    ])
    coord.controller.filter.set_x0(x0)
    coord.run(x0=x0)
    fig, axes, res = coord.plot_temperatures(
        heat_key="Prad"
    )
    plt.show()
    fig, axes = coord.plot_one_step_predictions(
        res
    )
    plt.show()
    print(coord)