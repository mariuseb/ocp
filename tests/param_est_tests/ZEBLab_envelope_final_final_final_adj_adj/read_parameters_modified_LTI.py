import pandas as pd
import os
from pprint import pprint
import matplotlib.pyplot as plt
import numpy as np


SMALL_SIZE = 14
MEDIUM_SIZE = 16
BIGGER_SIZE = 16

plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
plt.rc('legend', fontsize=12)    # legend fontsize
plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title

params_hist_jan = pd.read_csv("LTI_reiden_no_covar_opt_jan.csv")
params_hist_nov = pd.read_csv("LTI_reiden_no_covar_opt_nov.csv")


def set_first_and_scale(params_hist):
    params = params_hist.copy()
    A = 66
    params[["Ci", "Ce"]] /= 3.6E3*A
    params[["Rie", "Rea"]] *= A
    params[["Ai", "Ai_high"]] /= A

    priors = {
        "Rie": 0.250, # m²K / W 
        "Rie_w": 0.250, # m²K / W 
        "Rea": 2.250, # m²K / W 
        "Rea_w": 2.250, # m²K / W 
        "Ci": 9.50, # Wh / m²K
        "Ci_w": 9.50, # Wh / m²K
        "Ce": 112, # Wh / m²K
        "Ce_w": 112, # Wh / m²K
        "Ai": 10/A, # m²
        "Ai_high": 10/A, # m²
        "alpha_vent_sup": 0.5,
        "alpha_vent_ext": 0.5,
        "alpha_int": 0.5,
        "alpha_occ": 0.5 
    }

    extra = pd.DataFrame.from_dict(priors, orient="index").squeeze()
    params.loc[-1] = extra
    params = params.sort_index()
    params.index = range(len(params.index))
    
    return params

params_hist = (params_hist_nov, params_hist_jan)
mod_params = []
for params in params_hist:
        _params = set_first_and_scale(params)
        mod_params.append(_params)


from matplotlib.colors import ListedColormap
import seaborn as sns
# construct cmap
#colors = ["#9b59b6", "#3498db", "#95a5a6", "#e74c3c", "#34495e", "#2ecc71"]
#my_cmap = ListedColormap(sns.color_palette(flatui).as_hex())
#my_cmap = sns.color_palette("Spectral", as_cmap=True)
my_cmap = sns.color_palette("bright", as_cmap=True)
#colors = sns.color_palette("Set1") #, as_cmap=True)

def discrete_cmap(N, base_cmap=None):
    """Create an N-bin discrete colormap from the specified input map"""

    # Note that if base_cmap is a string or None, you can simply do
    #    return plt.cm.get_cmap(base_cmap, N)
    # The following works for string, None, or a colormap instance:

    base = plt.cm.get_cmap(base_cmap)
    color_list = base(np.linspace(0, 1, N))
    cmap_name = base.name + str(N)
    return base.from_list(cmap_name, color_list, N)

#colors = sns.color_palette("bright")
#colors = sns.color_palette("bright", as_cmap=True)
#colors = sns.color_palette("husl", 9)
#my_cmap = ListedColormap(sns.color_palette(colors).as_hex())
#color_cycler = plt.cycler(color=colors)
#plt.rcParams["axes.prop_cycle"] = plt.cycler("color", plt.cm.tab20c.colors)
#plt.rcParams["axes.prop_cycle"] = plt.cycler("color", sns.color_palette("bright"))
cmap=plt.cm.gist_rainbow
# build cycler with 5 equally spaced colors from that colormap
c = plt.cycler('color', cmap(np.linspace(0,1,5)) )
# supply cycler to the rcParam
plt.rcParams["axes.prop_cycle"] = c

fig, axes = plt.subplots(4,2, figsize=(12,8))
for i in range(2):
    #params = params_hist.loc[i*14:13+i*14]
    params = mod_params[i]
    params[["Ci"]].plot(ax=axes[0,i])
    params[["Ce"]].plot(ax=axes[0,i])
    #axes[0].legend(["$C_i$", "$C_{i}^{v}$","$C_e$", "$C_{e}^{v}$"], ncol=4,loc="upper left", bbox_to_anchor=(0.15, 1.3))
    axes[0,i].set_yscale('log')
    #axes[0,i].semilogy(x,y)
    axes[0,i].set_xticks([])
    if i == 1:
        axes[0,i].set_ylim(c_ylim)
        axes[1,i].set_ylim(r_ylim)
        axes[2,i].set_ylim(a_ylim)
        axes[3,i].set_ylim(i_ylim)
    ylims = axes[0,i].get_ylim()
    axes[0,i].set_ylim([10,ylims[1]])
    params[["Rie"]].plot(ax=axes[1,i])
    params[["Rea"]].plot(ax=axes[1,i])
    #axes[1].legend(["$R_{ie}$", "$R_{ie}^{v}$","$R_{ea}$", "$R_{ea}^{v}$"], ncol=4,loc="upper left", bbox_to_anchor=(0.125, 1.3))
    axes[1,i].set_yscale('log')
    axes[1,i].set_xticks([])
    params[["Ai"]].plot(ax=axes[2,i])
    params[["Ai_high"]].plot(ax=axes[2,i])
    #axes[2].legend(["$A_{i}$", "$A_{i}^{high}$"], ncol=2,loc="upper left", bbox_to_anchor=(0.20, 1.325))
    axes[2,i].set_xticks([])
    axes[2,i].set_yticks([0.10,0.20,0.30])
    params[["alpha_vent_sup", "alpha_int", "alpha_occ"]].plot(ax=axes[3,i])
    if i == 1:
        axes[0,i].legend(["$C_i$","$C_e$"], ncol=1,loc="upper left", bbox_to_anchor=(1.0, 0.9))
        axes[1,i].legend(["$R_{ie}$","$R_{ea}$"], ncol=1,loc="upper left", bbox_to_anchor=(1.0, 0.9))
        axes[2,i].legend(["$A_{i}$", "$A_{i}^{high}$"], ncol=1,loc="upper left", bbox_to_anchor=(1.0, 0.7))
        axes[3,i].legend(["$\\alpha_{v}^{sup}$", "$\\alpha_{int}$", "$\\alpha_{occ}$"], ncol=1,loc="upper left", bbox_to_anchor=(1.0, 0.8))
    elif i == 0:
        for j in range(4):
            axes[j,i].legend([])
        axes[0,i].set_ylabel("$\\frac{Wh}{m^{2}K}$")
        axes[1,i].set_ylabel("$\\frac{m^{2}K}{W}$")
        axes[2,i].set_ylabel("$\\frac{m^{2}}{m^{2}}$")
        axes[3,i].set_ylabel("$[-]$")
    if i == 0:
        c_ylim = axes[0,i].get_ylim()
        r_ylim = axes[1,i].get_ylim()
        a_ylim = axes[2,i].get_ylim()
        i_ylim = axes[3,i].get_ylim()
    axes[3,i].set_xticks(range(0,16,2))
    #fig.tight_layout()
plt.show()
print(params_hist)