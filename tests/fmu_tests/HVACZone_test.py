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
import os
import zipfile

# Create a CasADi/DaeBuilder instance from the unzipped FMU
#dae = ca.DaeBuilder('HVACZone', '/home/marius/modelica/wdir/HVACZoneRad/HVACZoneRad.fmutmp')

# extract from archive:

fmu_path = os.path.join(
                    '/home/marius/modelica/wdir', \
                    'Buildings.Fluid.FMI.ExportContainers.Validation.FMUs.HVACThermalZoneWater', \
                    'Buildings.Fluid.FMI.ExportContainers.Validation.FMUs.HVACThermalZoneWater.fmu'
                        )
unzipped_path = os.path.join(
                    '/home/marius/modelica/wdir', \
                    'Buildings.Fluid.FMI.ExportContainers.Validation.FMUs.HVACThermalZoneWater', \
                    'HVACZone'
                        )
with zipfile.ZipFile(fmu_path) as fmu:
    fmu.extractall(unzipped_path)

dae = ca.DaeBuilder('HVACZone', 
                    unzipped_path
                    )
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

# create RK4 to simulate:

# This is a standard CasADi function that can be embedded into CasADi expressions
print(h)
print(f)

# We can evaluate it and calculate derivatives as with other CasADi functions
#ode0 = f(x0, u0)
#print('ode0: ', ode0)

# Analytic first derivatives with sparsities are also available
#jac = f.factory('jac_f', ['x', 'u'], ['jac:ode:x', 'jac:ode:u'])
#jac_ode_x0, jac_ode_u0 = jac(x0, u0)
#print('jac_ode_x0: ', jac_ode_x0)
#print('jac_ode_u0: ', jac_ode_u0)

# Code generation for the functions are currently work in progress
#f.generate('fmu_codegen')
