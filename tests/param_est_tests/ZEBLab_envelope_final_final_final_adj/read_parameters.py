import pandas as pd
import os
from pprint import pprint
import matplotlib.pyplot as plt
import numpy as np


folder = "to_CTSMR_no_covar_opt"
files = os.listdir(folder)
tables = dict()

for file in files:
    tables[file.rstrip(".csv")] = pd.read_csv(os.path.join(folder, file), index_col=0)

selection = [table for table in list(tables.keys()) if "parameters" in table]
params_hist = pd.DataFrame(columns=tables[selection[0]].index)

#for i, dataset in enumerate(("11_2023", "1_2023")):
dataset = "11_2023"
#dataset = "1_2023"
for day in range(14):
    tablename = os.path.join(folder, \
        'parameters_LTV_%s_daytime_15min%s.csv' % (
        dataset, str(day)
        )
    )
    table = pd.read_csv(tablename, index_col=0)
    params_hist.loc[day] = table.values.flatten()

#print(nrmse.to_latex( float_format="%.3f")
A = 66
params = params_hist.copy()
params[["Ci", "Ci_w", "Ce", "Ce_w"]] /= 3.6E3*A
params[["Rie", "Rie_w", "Rea", "Rea_w"]] *= A
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
    "alpha_int_plugs": 1,
    "alpha_int_lig": 1 
}

extra = pd.DataFrame.from_dict(priors, orient="index").squeeze()
params.loc[-1] = extra
params = params.sort_index()
params.index = range(len(params.index))


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

fig, axes = plt.subplots(4,1, figsize=(6,8))
params[["Ci", "Ci_w"]].plot(ax=axes[0])
params[["Ce", "Ce_w"]].plot(ax=axes[0])
#axes[0].legend(["$C_i$", "$C_{i}^{v}$","$C_e$", "$C_{e}^{v}$"], ncol=4,loc="upper left", bbox_to_anchor=(0.15, 1.3))
axes[0].legend(["$C_i$", "$C_{i}^{v}$","$C_e$", "$C_{e}^{v}$"], ncol=1,loc="upper left", bbox_to_anchor=(1.0, 0.9))
axes[0].set_yscale('log')
axes[0].set_xticks([])
ylims = axes[0].get_ylim()
axes[0].set_ylim([10,ylims[1]])
params[["Rie", "Rie_w"]].plot(ax=axes[1])
params[["Rea", "Rea_w"]].plot(ax=axes[1])
#axes[1].legend(["$R_{ie}$", "$R_{ie}^{v}$","$R_{ea}$", "$R_{ea}^{v}$"], ncol=4,loc="upper left", bbox_to_anchor=(0.125, 1.3))
axes[1].legend(["$R_{ie}$", "$R_{ie}^{v}$","$R_{ea}$", "$R_{ea}^{v}$"], ncol=1,loc="upper left", bbox_to_anchor=(1.0, 0.9))
axes[1].set_yscale('log')
axes[1].set_xticks([])
params[["Ai"]].plot(ax=axes[2])
params[["Ai_high"]].plot(ax=axes[2])
#axes[2].legend(["$A_{i}$", "$A_{i}^{high}$"], ncol=2,loc="upper left", bbox_to_anchor=(0.20, 1.325))
axes[2].legend(["$A_{i}$", "$A_{i}^{high}$"], ncol=1,loc="upper left", bbox_to_anchor=(1.0, 0.7))
axes[2].set_xticks([])
axes[2].set_yticks([0.05,0.10,0.15])
params[["alpha_vent_sup", "alpha_int_lig", "alpha_int_plugs"]].plot(ax=axes[3])
axes[3].legend(["$\\alpha_{v}^{sup}$", "$\\alpha_{int}^{lig}$", "$\\alpha_{int}^{plugs}$"], ncol=1,loc="upper left", bbox_to_anchor=(1.0, 0.8))
fig.tight_layout()
plt.show()
print(params_hist)