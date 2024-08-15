import casadi as ca
import numpy as np
from ocp.dae import DAE
from ocp.integrators import RK4, IRK
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from ocp.param_est import ParameterEstimation
from utils import prepare_data
from os import system
import time

data = pd.read_csv("ZEBLab_2024_1m.csv")
data.index = pd.to_datetime(data._time)
data.index = data.index.tz_localize(None)

"""
Plot valve command vs. actual
"""
val_cmd = data["val_cmd_219"]
val_pos = data["val_pos_219"]/100
flow = data["V_flow_219"]

fig, axes = plt.subplots(3,1, sharex=True)
ax = axes[0]

val_cmd.plot(ax=ax, color="k", drawstyle="steps-post")
val_pos.plot(ax=ax, color="r", linestyle="dashed", drawstyle="steps-post")
ax.legend(loc="upper right")

ax1 = ax.twinx()
flow.plot(ax=ax1, color="b", drawstyle="steps-post")
ax1.legend(loc="upper left")

Tdev = data["T_set"] - data["T_219_TR3"]
Tdev[Tdev < 0] = 0
ax = axes[1]
Tdev.plot(ax=ax, color="r", drawstyle="steps-post")
ax.legend(["Tset - Ti"])

ax = axes[2]
data.P_rad_219.plot(ax=ax, drawstyle="steps-post")

plt.show()

data = prepare_data(data)
#data = data.resample(rule="5min").mean()
y_data = data.bfill() 
#y_data["u_val_set"] = y_data.val_cmd_219
#y_data["m_flow"] = (y_data.V_flow_219/y_data.V_flow_219.max())
#y_data["m_flow"] = y_data.V_flow_219
#y_data["y1"] = y_data["m_flow"]
# take only time point between 0400 and 1100
#start = pd.Timestamp("2022-12-13 00:00")
#stop = pd.Timestamp("2022-12-16 00:00")
start = pd.Timestamp("2023-12-03 00:00")
#stop = pd.Timestamp("2023-12-06 00:00")
stop = pd.Timestamp("2023-12-10 00:00")
y_data = y_data.loc[start:stop]

# TODO: 'algorithm' to find only non-zero power entries, rounding to limits
Prad = data.Prad.resample(rule="1H").mean()
gt_zero = Prad[Prad > 0]
cpy = gt_zero.copy()
cpy.index += pd.Timedelta(hours=1)
gt_zero_index = list(set(list(gt_zero.index) + list(cpy.index)))
#gt_zero = gt_zero.resample(rule="1min").asfreq()


#index_selection = [ndx for ndx in y_data.index if ndx.hour in range(7,12)]
index_selection = [ndx for ndx in y_data.index if 
                   ndx.floor("1H") in gt_zero_index]
#index_selection = list(gt_zero.index)
y_data = y_data.loc[index_selection]
#data = data.iloc[0:1000]

N = len(y_data)
dt = (y_data.index[1] - y_data.index[0]).seconds
# set range index for identification:
y_data["dt_index"] = y_data.index
y_data.index = range(0,N*dt,dt)

# only tau, delay
param_guess = np.array([500,
                        -15 + 273.15,
                        45 + 273.15,
                        0.7,
                        293,
                        5,
                        5,
                        5,
                        5,
                        5,
                        5,
                        1E-1,
                        1E2,
                        1E-1,
                        1E3,
                        1E-1,
                        1E3,
                        1E-1,
                        1E2,
                        2500
                        ])

lbp = 1E-2*param_guess
ubp = 1E2*param_guess
len_p = param_guess.shape[0]
lbp[0] = 500
ubp[0] = 500
lbp[0] = 300
ubp[0] = 10000
lbp[len_p-1] = 50
ubp[len_p-1] = 100000
lbp[1] = -20 + 273.15
ubp[1] = -10 + 273.15
lbp[2] = 35 + 273.15
ubp[2] = 50 + 273.15
lbp[3] = 1E-3
ubp[3] = 1.5
lbp[4] = 290
ubp[4] = 300
lbp[5] = 0
ubp[5] = 20
lbp[6] = 3
ubp[6] = 20
lbp[7] = 0
ubp[7] = 20
lbp[8] = 0
ubp[8] = 20
lbp[9] = 0
ubp[9] = 20
lbp[10] = 0
ubp[10] = 20
# constrain in particular Th to physically meaningful values:
x_guess = np.array([
                    y_data.Tsup,
                    (y_data.Tsup + y_data.Tret)/2,
                    y_data.Tret
                   ])
lbx = 0.7*x_guess
ubx = 1.3*x_guess

# limits on Tret:
#lbx[0:1] = 290
#lbx[1:2] = -1
#lbx[2:3] = 290
#ubx[2:3] = 310

#cfg_path = "configs/Tsup_Th_Tret_DDE_tvp_delay_simple.json"
cfg_path = "configs/Tsup_Th_Tret_DDE_tvp_delay_simpler.json"

param_est = ParameterEstimation(config=cfg_path,
                                N=N,
                                dt=dt,
                                param_guess=param_guess) 

"""
F = param_est.integrator.one_sample
F_map = F.map(N)
# vars:
x = ca.MX.sym("x", param_est.n_x, N)
z = ca.MX.sym("z", param_est.n_z, N)
u = ca.MX.sym("u", param_est.n_u, N)
p = ca.MX.sym("p", param_est.n_p, N)
# call:
F_map_call = F_map(x0=x, z=z, u=u, p=p, s=0, r=0, w=0)["xf"]

all_vars = ca.vertcat(x,z,u,p)

hess_F_map = ca.hessian(F_map_call, all_vars)
"""

f = param_est.nlp["f"]
g = param_est.nlp["g"]
x = param_est.nlp["x"]
R, Q = param_est.R, param_est.Q
hess_f = ca.hessian(f, x)[1]

"""
hessian of f:
"""

name = "hessF"
hess_F = ca.Function(name, [x, ca.veccat(R, Q)], [f], ["x", "p"], ["hess_f"])

#codegen = ca.CodeGenerator("ju")
#codegen.generate()
cname = hess_F.generate()

oname_no_opt = name + '_no_opt.so'
print('Compiling without optimization: ', oname_no_opt)
t1 = time.time()
system('gcc -fPIC -shared ' + cname + ' -o ' + oname_no_opt)
t2 = time.time()
print('time = ', (t2-t1)*1e3, ' ms')

"""
jacobian of g:
"""
name = "jacG"
jac_G = ca.Function(name, [x, ca.veccat(R, Q)], [g], ["x", "p"], ["jac_g"])

#codegen = ca.CodeGenerator("ju")
#codegen.generate()
cname = jac_G.generate()

oname_no_opt = name + '_no_opt.so'
print('Compiling without optimization: ', oname_no_opt)
t1 = time.time()
system('gcc -fPIC -shared ' + cname + ' -o ' + oname_no_opt)
t2 = time.time()
print('time = ', (t2-t1)*1e3, ' ms')
