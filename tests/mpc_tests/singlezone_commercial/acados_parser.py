# -*- coding: future_fstrings -*-
#
# Copyright (c) The acados authors.
#
# This file is part of acados.
#
# The 2-Clause BSD License
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.;
#

# authors: Katrin Baumgaertner, Jonathan Frey

import numpy as np
from dataclasses import dataclass
from acados_template import AcadosModel, AcadosSim, AcadosSimSolver
import casadi as ca
import pandas as pd
from ocp.dae import DAE
import json
from collections import OrderedDict
import os
from ocp.functions import functions
from pprint import pprint
import matplotlib.pyplot as plt


def setup_acados_model_from_DAE(
        config: str,
        functions
    ):
    """
    Setup Acados-model from DAE object:
    """
    if isinstance(config, str) or isinstance(config, os.PathLike):
        with open(config, "r") as f:
            config = json.load(f, object_pairs_hook=OrderedDict)
    config["model"]["functions"] = functions
    dae = DAE(config["model"])

    x = dae.var("x")
    z = dae.var("z")
    p = dae.var("p")

    _u = dae.var("u")
    r = dae.var("r")
    u = ca.vertcat(_u, r)
    
    ode = ca.vertcat(*dae.dae.ode())
    xdot = ca.MX.sym("xdot", dae.n_x + dae.n_z)
    g = ca.vertcat(*dae.g)
    #g_impl = z - g
    f_expl = ca.vertcat(ode, g)

    #f_expl = 0
    f_impl = xdot - f_expl

    model = AcadosModel()
    #model.dae = dae
    model.u_names = dae.u + dae.r_names
    model.p_names = dae.p
    model.z_names = dae.z
    model.x_names = dae.x

    """
    f_expl = vertcat(xvel, u, f)
    f_impl = xdot - f_expl

    model = AcadosModel()

    model.f_impl_expr = f_impl
    model.f_expl_expr = f_expl
    """
    
    model.f_impl_expr = f_impl
    model.f_expl_expr = f_expl
    model.x = x
    model.xdot = xdot
    model.u = u
    model.z = z
    model.p = p
    model.name = "test"
    
    return model

params = pd.read_csv("full_model_latest.csv", index_col=0)
params_CO2 = pd.read_csv("CO2_model.csv", index_col=0)
params_CO2.rename(index={"c":"c1"}, inplace=True)
params = pd.concat([params, params_CO2])
#model = setup_acados_model_from_DAE("mpc_configs/3R2C_MPC_CO2_ext.json", functions)
model = setup_acados_model_from_DAE("mpc_configs/3R2C_MPC_simple.json", functions)

"""
First step:
    - simulation.

Next step:
    - optimization.
"""

def setup_acados_integrator(
    model,
    dt,
    params: pd.DataFrame,
    sensitivity_propagation=False,
    num_stages=1,
    num_steps=96,
    integrator_type="IRK",
    ):
    
    sim = AcadosSim()
    # set model
    sim.model = model
    # set simulation time
    sim.solver_options.T = dt
    ## set options
    sim.solver_options.integrator_type = integrator_type
    sim.solver_options.num_stages = num_stages
    sim.solver_options.num_steps = num_steps
    # for implicit integrator
    #sim.solver_options.newton_iter = 3
    sim.solver_options.newton_tol = 1e-6
    sim.solver_options.collocation_type = "GAUSS_LEGENDRE"
    # sensitivity_propagation
    sim.solver_options.sens_adj = sensitivity_propagation
    sim.solver_options.sens_forw = sensitivity_propagation
    sim.solver_options.sens_hess = sensitivity_propagation
    # nominal parameter values
    sim.parameter_values = params.values.flatten()
    # create
    acados_integrator = AcadosSimSolver(sim)
    
    return acados_integrator

N = 1
intg = setup_acados_integrator(
                               model,
                               900, 
                               params.loc[model.p_names],
                               num_steps=N
                               )
data = pd.read_csv("test_data.csv", index_col=0) 
sol = pd.DataFrame(columns=model.x_names)
N = 95
x0 = np.array([293.15, 293.15, 420])
for n in range(N):
    u_data = data[model.u_names].iloc[n].values
    z_data = data[model.z_names].iloc[n].values
    intg.set("u", u_data)
    intg.set("z", z_data)
    intg.set("x", x0)
    x0 = intg.simulate()
    sol.loc[n, model.x_names] = x0
    
ax = sol.Ti.plot()
plt.show()
print(intg)
