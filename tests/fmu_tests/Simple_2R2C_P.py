#
#     MIT No Attribution
#
#     Copyright (C) 2010-2023 Joel Andersson, Joris Gillis, Moritz Diehl, KU Leuven.
#
#     Permission is hereby granted, free of charge, to any person obtaining a copy of this
#     software and associated documentation files (the "Software"), to deal in the Software
#     without restriction, including without limitation the rights to use, copy, modify,
#     merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
#     permit persons to whom the Software is furnished to do so.
#
#     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
#     INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
#     PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
#     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#     OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
#     SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# -*- coding: utf-8 -*-
#from casadi import *
import casadi as ca
from epw import epw
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# read in e+ weatherfile
o = epw()
o.read("USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.epw")
print(o)
o.dataframe.index = range(len(o.dataframe))
wea = o.dataframe
wea['Dry Bulb Temperature'] += 273.15
wea['Dew Point Temperature'] += 273.15

name_map = {
 'Dry Bulb Temperature': 'TDryBul',
 'Dew Point Temperature': 'TDewPoi',
 'Relative Humidity': 'relHum',
 'Opaque Sky Cover (used if Horizontal IR Intensity missing)': 'opaSkyCov',
 'Ceiling Height': 'ceiHei',
 'Total Sky Cover': 'totSkyCov',
 'Wind Speed': 'winSpe',
 'Wind Direction': 'winDir',
 'Global Horizontal Radiation': 'HGloHor',
 'Direct Normal Radiation': 'HDirNor',
 'Diffuse Horizontal Radiation': 'HDifHor',
 'Horizontal Infrared Radiation Intensity': 'HInfHor'
}


# Create a CasADi/DaeBuilder instance from the unzipped FMU
dae = ca.DaeBuilder('Simple2R2C', 'Simple2R2C')
dae.disp(True)

# Get state vector, initial conditions, bounds
x = dae.x()
lbx = dae.min(x)
ubx = dae.max(x)
x0 = dae.start(x)
print('x: ', x)
print('lbx: ', lbx)
print('ubx: ', ubx)
print('x0: ', x0)

# Get5 control vector, initial conditions, bounds
u = dae.u()
lbu = dae.min(u)
ubu = dae.max(u)
u0 = dae.start(u)
print('u: ', u)
print('lbu: ', lbu)
print('ubu: ', ubu)
print('u0: ', u0)


# Let's create a CasADi function for evaluating the ODE right-hand-side.
# We only need to specify the expressions that are varying:
f = dae.create('f', ['x', 'u'], ['ode'])
h = dae.create('h', ['x', 'u'], ['ydef'])

# integrate FMU??

time_grid = [0, 3600]
#I = ca.integrator("test", dae, 'idas', time_grid)
#I = ca.integrator("test", 'cvodes', f, 0, time_grid)
I = ca.integrator("test", 'idas', f, 0, time_grid)

#s = ca.rootfinder('s', 'newton', h)

# create RK4 to simulate?
# only algebraic eqs.?
_name_map = {v: k for k, v in name_map.items()}

wea = wea.rename(columns=name_map)

# get u names:
def get_u(i, udef, wea, name_map):
    u0 = []
    for n, name in enumerate(dae.u()):
        _name = name.replace("_in", "")
        if _name in name_map:
            val = wea[_name].iloc[i]
        else:
            val = udef[n]
        #if _name.startswith("T"):
        #    val += 273.15
        u0.append(val)
    return u0

_u0 = get_u(0, u0, wea, _name_map)
    
print(_u0)

# try compute at 0 
y = h(0, _u0)

_u0 = get_u(5100, u0, wea, _name_map)
# try compute at 5100
y = h(0, _u0)

# try compute for the whole year ?? 
res = pd.DataFrame(columns = dae.y())
#N = len(wea)
N = 24
for i in range(N):
    _u0 = get_u(i, u0, wea, _name_map)
    y = h(0, _u0)
    if i > 0:
        _u0[4] = y[4] # feedback diffusive rad
    res.loc[i] = np.array(y).flatten()
    
# This is a standard CasADi function that can be embedded into CasADi expressions
print(h)
print(f)

# We can evaluate it and calculate derivatives as with other CasADi functions
ode0 = f(x0, u0)
print('ode0: ', ode0)

# Analytic first derivatives with sparsities are also available
jac = f.factory('jac_f', ['x', 'u'], ['jac:ode:x', 'jac:ode:u'])
jac_ode_x0, jac_ode_u0 = jac(x0, u0)
print('jac_ode_x0: ', jac_ode_x0)
print('jac_ode_u0: ', jac_ode_u0)

# Code generation for the functions are currently work in progress
#f.generate('fmu_codegen')
