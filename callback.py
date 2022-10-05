#
#     This file is part of CasADi.
#
#     CasADi -- A symbolic framework for dynamic optimization.
#     Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
#                             K.U. Leuven. All rights reserved.
#     Copyright (C) 2011-2014 Greg Horn
#
#     CasADi is free software; you can redistribute it and/or
#     modify it under the terms of the GNU Lesser General Public
#     License as published by the Free Software Foundation; either
#     version 3 of the License, or (at your option) any later version.
#
#     CasADi is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#     Lesser General Public License for more details.
#
#     You should have received a copy of the GNU Lesser General Public
#     License along with CasADi; if not, write to the Free Software
#     Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#
#
#! Callback
#! =====================
from multiprocessing.dummy import Process
from casadi import *
from numpy import *
import os, psutil

#! In this example, we will demonstrate callback functionality for Ipopt.
#! Note that you need the fix https://github.com/casadi/casadi/wiki/enableIpoptCallback before this works
#!
#! We start with constructing the rosenbrock problem
"""
x=SX.sym("x")
y=SX.sym("y")

f = (1-x)**2+100*(y-x**2)**2
nlp={'x':vertcat(x,y), 'f':f,'g':x+y}
fcn = Function('f', [x, y], [f])

import matplotlib
if "Agg" not in matplotlib.get_backend():
  matplotlib.interactive(True)

from pylab import figure, subplot, contourf, colorbar, draw, show, plot, title

import time
"""

class ProcessIdCallback(Callback):
  def __init__(self, name, nx, ng, np, opts={}):
    Callback.__init__(self)

    self.nx = nx
    self.ng = ng
    self.np = np
    self.i = 0
    # Initialize internal objects
    self.construct(name, opts)

  def get_n_in(self): return nlpsol_n_out()
  def get_n_out(self): return 1
  def get_name_in(self, i): return nlpsol_out(i)
  def get_name_out(self, i): return "ret"

  def get_sparsity_in(self, i):
    n = nlpsol_out(i)
    if n=='f':
      return Sparsity. scalar()
    elif n in ('x', 'lam_x'):
      return Sparsity.dense(self.nx)
    elif n in ('g', 'lam_g'):
      return Sparsity.dense(self.ng)
    else:
      return Sparsity(0,0)

  def eval(self, arg):
    # Create dictionary
    self.i += 1
    print("#"*80)
    print("Iteration %s from process id %s:" % (str(self.i), str(os.getpid())))
    print("#"*80)
    return [0]


"""
mycallback = ProcessIdCallback('mycallback', 2, 1, 0)
opts = {}
opts['iteration_callback'] = mycallback
opts['ipopt.tol'] = 1e-8
opts['ipopt.max_iter'] = 50
solver = nlpsol('solver', 'ipopt', nlp, opts)
sol = solver(lbx=-10, ubx=10, lbg=-10, ubg=10)

#! By setting matplotlib interactivity off, we can inspect the figure at ease
#matplotlib.interactive(False)
#show()
""" 