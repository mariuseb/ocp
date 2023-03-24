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
import casadi as ca
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from pprint import pprint

# Degree of interpolating polynomial
d = 3
# Get collocation points
tau_root = np.append(0, ca.collocation_points(d, 'legendre'))
# Coefficients of the collocation equation
C = np.zeros((d+1,d+1))
# Coefficients of the continuity equation
D = np.zeros(d+1)
# Coefficients of the quadrature function
B = np.zeros(d+1)
# Construct polynomial basis
for j in range(d+1):
    # Construct Lagrange polynomials to get the polynomial basis at the collocation point
    p = np.poly1d([1])
    for r in range(d+1):
        if r != j:
            p *= np.poly1d([1, -tau_root[r]]) / (tau_root[j]-tau_root[r])
    # Evaluate the polynomial at the final time to get the coefficients of the continuity equation
    D[j] = p(1.0)
    # Evaluate the time derivative of the polynomial at all collocation points to get the coefficients of the continuity equation
    pder = np.polyder(p)
    for r in range(d+1):
        C[j,r] = pder(tau_root[r])

    # Evaluate the integral of the polynomial to get the coefficients of the quadrature function
    pint = np.polyint(p)
    B[j] = pint(1.0)

data = pd.read_csv("MPC_1R1C.csv", index_col=0)

# Time horizon
T = data.index[-1]
lbx = data["lb_Ti"].values
ubx = data["ub_Ti"].values
u_vals = data[["Ta"]].values

# Declare model variables
Ti = ca.SX.sym('Ti')
#x2 = ca.SX.sym('x2')
x = ca.vertcat(Ti)
phi_h = ca.SX.sym('phi_h')
Ta = ca.SX.sym('Ta')
Ria = ca.SX.sym("Ria")
Ci = ca.SX.sym("Ci")

p = ca.vertcat(Ci, Ria)
u = ca.vertcat(phi_h, Ta)

# Model equations
xdot = ca.vertcat((Ta - Ti)/(Ria*Ci) + phi_h*(1/Ci))

# Objective term
L = phi_h**2

# Continuous time dynamics
f = ca.Function('f', [x, p, u], [xdot, L], ['x', 'p', 'u'], ['xdot', 'L'])

# Control discretization
N = len(data) - 1  # number of control intervals
h = T/N

# Start with an empty NLP
w=[]
w0 = []
lbw = []
ubw = []
J = 0
g=[]
lbg = []
ubg = []

# For plotting x and u given w
x_plot = []
u_plot = []

# "Lift" initial conditions
Xk = ca.MX.sym('X0', 1)
w.append(Xk)
#lbw.append([0, 1])
#ubw.append([0, 1])
#w0.append([0, 1])
lbw.append([lbx[0]])
ubw.append([ubx[0]])
w0.append([lbx[0]])
x_plot.append(Xk)

# Perturb with P, parameters
P = ca.MX.sym('P', 2)
#p = p + P

#p_val = 1

# Formulate the NLP
for k in range(N):

    # New NLP variable for the control
    Uk = ca.MX.sym('U_' + str(k), 2)
    w.append(Uk)
    #lbw.append([-1])
    #ubw.append([.85])
    #w0.append(s[0])
    lbw.append([0, float(u_vals[k])])
    ubw.append([5000, float(u_vals[k])])
    w0.append([0, float(u_vals[k])])
    u_plot.append(Uk)

    # State at collocation points
    Xc = []
    for j in range(d):
        Xkj = ca.MX.sym('X_'+str(k)+'_'+str(j), 1)
        Xc.append(Xkj)
        w.append(Xkj)
        #lbw.append([-0.25, -np.inf])
        #ubw.append([np.inf,  np.inf])
        #w0.append([0, 0])
        lbw.append([lbx[k+1]])
        ubw.append([ubx[k+1]])
        w0.append([lbx[k+1]])

    # Loop over collocation points
    Xk_end = D[0]*Xk
    for j in range(1,d+1):
       # Expression for the state derivative at the collocation point
       xp = C[0,j]*Xk
       for r in range(d): xp = xp + C[r+1,j]*Xc[r]

       # Append collocation equations
       fj, qj = f(Xc[j-1], P, Uk)
       g.append(h*fj - xp)
       #lbg.append([0, 0])
       #ubg.append([0, 0])
       lbg.append([0])
       ubg.append([0])

       # Add contribution to the end state
       Xk_end = Xk_end + D[j]*Xc[j-1];

       # Add contribution to quadrature function
       J = J + B[j]*qj*h

    # New NLP variable for state at end of interval
    Xk = ca.MX.sym('X_' + str(k+1), 1)
    w.append(Xk)
    lbw.append([lbx[k+1]])
    ubw.append([ubx[k+1]])
    w0.append([lbx[k+1]])
    x_plot.append(Xk)

    # Add equality constraint
    g.append(Xk_end-Xk)
    #lbg.append([0, 0])
    #ubg.append([0, 0])
    lbg.append([0])
    ubg.append([0])

# Concatenate vectors
w = ca.vertcat(*w)
g = ca.vertcat(*g)
x_plot = ca.horzcat(*x_plot)
u_plot = ca.horzcat(*u_plot)
w0 = np.concatenate(w0)
lbw = np.concatenate(lbw)
ubw = np.concatenate(ubw)
lbg = np.concatenate(lbg)
ubg = np.concatenate(ubg)

# Create an NLP solver
prob = {'f': J, 'x': w, 'g': g, 'p': P}

# Function to get x and u trajectories from w
trajectories = ca.Function('trajectories', [w], [x_plot, u_plot], ['w'], ['x', 'u'])

# Create an NLP solver, using SQP and active-set QP for accurate multipliers
opts = dict(qpsol='qrqp', qpsol_options=dict(print_iter=False,error_on_fail=False), print_time=False)
solver = ca.nlpsol('solver', 'sqpmethod', prob, opts)
"""
opts = {"ipopt.tol":1e-6,
        "expand": True, 
        "bound_consistency": True,
        "clip_inactive_lam": True,
        "calc_lam_x": False,
        "calc_lam_p": True}
solver = ca.nlpsol("solver", "ipopt", prob, opts)
"""

# Solve the NLP
p_val = [1e6, 0.01]
sol = solver(x0=w0, lbx=lbw, ubx=ubw, lbg=lbg, ubg=ubg, p=p_val)

# Extract trajectories
x_opt, u_opt = trajectories(sol['x'])
x_opt = x_opt.full() # to numpy array
u_opt = u_opt.full() # to numpy array

# Plot the result
tgrid = np.linspace(0, T, N+1)
#plt.figure(1)
#plt.clf()

fig, ax = plt.subplots(1,1)

ax.plot(tgrid, x_opt[0], '--')
#plt.plot(tgrid, x_opt[1], '-')
ax1 = ax.twinx()
ax1.step(tgrid, np.append(np.nan, u_opt[0]), '-.')
#ax.xlabel('t')
#plt.legend(['x1','u'])
plt.grid()
plt.show()

# High-level approach:
# Use factory to e.g. to calculate Hessian of optimal f w.r.t. p
#hsolver = solver.factory('h', solver.name_in(), ['hess:f:p:p'])
#print('hsolver generated')
#hsol = hsolver(x0=sol['x'], lam_x0=sol['lam_x'], lam_g0=sol['lam_g'],
#               lbx=lbw, ubx=ubw, lbg=lbg, ubg=ubg, p=p_val)
#print('Hessian of f w.r.t. p:')
#print(hsol['hess_f_p_p'])

# Low-level approach: Calculate directional derivatives.
# We will calculate two directions simultaneously
nfwd = 2

# Forward mode AD for the NLP solver object
fwd_solver = solver.forward(nfwd);
print('fwd_solver generated')

# Seeds, initalized to zero
fwd_lbx = [ca.DM.zeros(sol['x'].sparsity()) for i in range(nfwd)]
fwd_ubx = [ca.DM.zeros(sol['x'].sparsity()) for i in range(nfwd)]
fwd_p = [ca.DM.zeros(P.sparsity()) for i in range(nfwd)]
fwd_lbg = [ca.DM.zeros(sol['g'].sparsity()) for i in range(nfwd)]
fwd_ubg = [ca.DM.zeros(sol['g'].sparsity()) for i in range(nfwd)]

# Let's preturb P
fwd_p[0][0] = 1  # first nonzero of P
fwd_p[1][1] = 1  # second nonzero of P

# Calculate sensitivities using AD
sol_fwd = fwd_solver(out_x=sol['x'], out_lam_g=sol['lam_g'], out_lam_x=sol['lam_x'],
            out_f=sol['f'], out_g=sol['g'], lbx=lbw, ubx=ubw, lbg=lbg, ubg=ubg,
            fwd_lbx=ca.horzcat(*fwd_lbx), fwd_ubx=ca.horzcat(*fwd_ubx),
            fwd_lbg=ca.horzcat(*fwd_lbg), fwd_ubg=ca.horzcat(*fwd_ubg),
            p=p_val, fwd_p=ca.horzcat(*fwd_p))

# Calculate the same thing using finite differences
h = 1e-4
pert = []
for d in range(nfwd):
    pert.append(solver(x0=sol['x'], lam_g0=sol['lam_g'], lam_x0=sol['lam_x'],
                lbx=lbw + h*(fwd_lbx[d]+fwd_ubx[d]),
                ubx=ubw + h*(fwd_lbx[d]+fwd_ubx[d]),
                lbg=lbg + h*(fwd_lbg[d]+fwd_ubg[d]),
                ubg=ubg + h*(fwd_lbg[d]+fwd_ubg[d]),
                p=p_val + h*fwd_p[d]))

# Print the result
for s in ['f']:
    print('==========')
    print('Checking ' + s)
    print('finite differences')
    for d in range(nfwd): print((pert[d][s]-sol[s])/h)
    print('AD fwd')
    M = sol_fwd['fwd_' + s].full()
    for d in range(nfwd): print(M[:, d].flatten())

# Perturb again, in the opposite direction for second order derivatives
pert2 = []
for d in range(nfwd):
    pert2.append(solver(x0=sol['x'], lam_g0=sol['lam_g'], lam_x0=sol['lam_x'],
                lbx=lbw - h*(fwd_lbx[d]+fwd_ubx[d]),
                ubx=ubw - h*(fwd_lbx[d]+fwd_ubx[d]),
                lbg=lbg - h*(fwd_lbg[d]+fwd_ubg[d]),
                ubg=ubg - h*(fwd_lbg[d]+fwd_ubg[d]),
                p=p_val - h*fwd_p[d]))

# Print the result
for s in ['f']:
    print('finite differences, second order: ' + s)
    for d in range(nfwd): print((pert[d][s] - 2*sol[s] + pert2[d][s])/(h*h))

# Reverse mode AD for the NLP solver object
nadj = 1
adj_solver = solver.reverse(nadj)
print('adj_solver generated')

# Seeds, initalized to zero
adj_f = [ca.DM.zeros(sol['f'].sparsity()) for i in range(nadj)]
adj_g = [ca.DM.zeros(sol['g'].sparsity()) for i in range(nadj)]
adj_x = [ca.DM.zeros(sol['x'].sparsity()) for i in range(nadj)]

# Study which inputs influence f
adj_f[0][0] = 1

# Calculate sensitivities using AD
sol_adj = adj_solver(out_x=sol['x'], out_lam_g=sol['lam_g'], out_lam_x=sol['lam_x'],
                out_f=sol['f'], out_g=sol['g'], lbx=lbw, ubx=ubw, lbg=lbg, ubg=ubg,
                adj_f=ca.horzcat(*adj_f), adj_g=ca.horzcat(*adj_g),
                p=p_val, adj_x=ca.horzcat(*adj_x))

# Print the result
for s in ['p']:
    print('==========')
    print('Checking ' + s)
    print('Reverse mode AD')
    print(sol_adj['adj_' + s])
