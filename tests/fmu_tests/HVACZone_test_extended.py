#!/usr/bin/env python
# coding: utf-8

import casadi
import os
import zipfile
from time import time


# ## Compiling the model into an FMU
# Different tools exist to compile Modelica models like these into FMUs.
# 
# Below is a code snippet for generating FMUs using two different Modelica compilers,
# the (closed-source) OCT compiler from Modelon and the open-source OpenModelica compiler:


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

dae = casadi.DaeBuilder(
                        'HVACZone', 
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

# ## FMU function objects
# 
# The evaluation of the FMU model equations takes place in a separate class, ``casadi::FmuFunction``, which is a standard differentiable CasADi function object. As such, it can embedded into optimization problems and have derivatives calculated automatically "under-the-hood".
# 
# FmuFunction instances are created from DaeBuilder instances, but does not depend on them after creation. Instead, they make a copy of the relevant subset of meta information in the DaeBuilder instance and stores them in the instance. If the DaeBuilder instance is later changed or deleted, it will not affect the FmuFunction. Included in the `FmuFunction` is a binary interface to the DLLs, adhering to the FMU standard (assuming version 2.0 as of this writing).
# 
# In the simplest case, let us create a function object that calculate the ODE right-hand-side as a function of the state vector $x$ and the controls $u$:


# Evaluate ODE right-hand-side
f = dae.create('f', ['x', 'u'], ['ode'])
h = dae.create('h', ['x', 'u'], ['ydef'])
print(f)
print(h)
# Evaluate the function numerically
u_test = u0
xdot_test = f(x0, u_test)
print('xdot_test: ', xdot_test)



# Alternative ODE right-hand-side function with u fixed
dae.set('Tsup', 330)
f_no_u = dae.create('f_no_u', ['x'], ['ode'])
print(f_no_u)
# Evaluate the function numerically
xdot_test_no_u = f_no_u(x0)
print('xdot_test_no_u: ', xdot_test_no_u)


# Similarly, only real-valued, differentiable variables should be included in the list of function outputs. Other variables can be included as "auxilliary variables" by specifying the "aux" option - the requested values will then be retrieved from the *stats*:


# Anything that is not real-valued (but for example string or integer valued) can also be passed this way.

# ### First order derivatives - Jacobians
# 
# First order derivative information can be obtained either numerically or analytically. In either case, the Jacobian sparsity information in the FMU will be exploited using CasADi's graph coloring techniques.
# 
# For efficiency, the evaluation can be done in parallel using either OpenMP or std::thread. The interface will distribute the evaluation over the available threads:

# A function that calculates the ODE and two Jacobian blocks:
J = dae.create('J', ['x', 'u'], ['ode', 'jac_ode_x', 'jac_ode_u'],
              dict(verbose = True, parallelization = 'openmp'))
print(J)

# Evaluate Jacobian
xdot_test, A_test, B_test = J(x0, u_test)
print('xdot_test: ', xdot_test)
print('A_test: ', A_test)
print('B_test: ', B_test)


# Notice that the output is sparse (00 denotes a stuctural zero in CasADi).
# 
# By default, analytic derivatives will be used if they are available in the FMU. Alternatively, derivatives can be calculated using finite differences using one of three schemes:
#  * Forward differences
#  * Central differences
#  * A smoothness seeking scheme using 5-point stencils: $f(x-2h), f(x-h), f(x), f(x+h), f(x+2h)$
#  
# All schemes will use perturbation sizes scaled by the nominal values in the FMU. If FMU variable bounds are present, they will be respected.
# This makes the perturbation step size predicable and the user can influence individual step sizes by modifying the corresponding nominal value.


# A function that calculates the ODE and two Jacobian blocks:
J_fd = dae.create('J_fd', ['x', 'u'], ['ode', 'jac_ode_x', 'jac_ode_u'],
              dict(verbose = True,
                   parallelization = 'openmp',
                   enable_ad = False))
print(J_fd)

# Evaluate Jacobian
xdot_fd, A_fd, B_fd = J_fd(x0, u_test)
print('xdot_fd: ', xdot_fd)
print('A_fd: ', A_fd)
print('B_fd: ', B_fd)


# Finally, the finite difference implementation can be run in "shadow mode" by setting the option "validate_ad" to True. The AD derivatives are then compared with the finite difference values and warnings are emitted if the difference exceeds a threshold. This feature is intended to help ensuring that the analytic derivatives are correct for complex physical models.

# ### Second order derivatives - Hessians
# The interface can also calculate second derivatives, i.e. Hessians. The Hessian can be calculated for any linear combination of the outputs (in gradient-based optimization, the weights are typically Lagrange multipliers).
# 
# Using the "dependenciesKind" field in the FMI XML, we can determine which input variables enter nonlinearly in any of the used outputs variables. This allows a "worst-case" sparsity pattern of the Hessian to be constructed.
# 
# The Hessian is then calculated by applying finite differencing to the first order analytic derivatives. The first order analytic derivatives are, in turn, by implicitly multiplying the Jacobian with a vector from the left, where the Jacobian is calculated using the graph coloring techniques described above. This is *not* the most efficient way to calculate second order derivatives -- a much more efficient alternative is to use adjoint derivatives to calculate the first order derivatives before using either finite differences or AD for the second derivatives. Since adjoint derivatives are not available in FMI 2.0, the workaround using the calculation of the sparse Jacobian was used. If/when the FMI interface is updated to support FMI 3.0, the first order derivatives can be calculated efficiently using `fmi3GetAdjointDerivative`, if supported by the generating tool. The current gradient calculation approach can then instead be used as a diagnostics feature, checking that `fmi3GetAdjointDerivative` for correctness for a specific model.
# 
# The Hessian calculation can be done in parallel, using OpenMP or std::thread. The nonlinearly entering variables are then split over the available threads:


# Create a function that calculate the Hessian of a linear
# combination of "ode" with respect to x and u: 
H = dae.create('H', ['x', 'u', 'adj_ode'],
               ['jac_adj_x_x', 'jac_adj_x_u', 'jac_adj_u_u'],
               dict(verbose = True, parallelization = 'openmp'))
print(H)
# Evaluate Hessian
# Evaluate Jacobian
H_xx, H_xu, H_uu = H(x0, u_test, 1)
print('H_xx: ', H_xx)
print('H_xu: ', H_xu)
print('H_uu: ', H_uu)


# In general, we have to perturb all nonlinearly entering variables, which will give us the full Hessian, not just the upper or lower triangular part. But since we also know that the Hessian has to be symmetric, we can use a symmetry check as an consistency check for the Hessian calculation. In addition, the diagonal entries of the Hessian can be calculated by using second order finite differences. Both these calculations can be done without any additional calls to the FMU, i.e. without significant computational overhead, and can thus be an important check that the entries are correctly calculated.
# 
# This diagnostics feature can be enabled by setting the option "check_hessian" to True. It is especially important since the correctness of the calculation will depend on suitably chosen nominal values, for scaling the perturbation step sizes. It is also important to be able to detect non-smoothnesses in the model equations or issues with the tool used to generate the FMU.

# ## Improved ODE/DAE integrator class suitable for FMI simulation
#  * CasADi's ODE/DAE integrators previously only efficient for forward/adjoint sensitivity calculations
#     when the ODEs/DAEs were available as *expressions*, not general *functions*
#  * With CasADi 3.6, the `integrator` class also works efficiently for DAEs given as functions, including `FmuFunction` instances
#  * In addition, ODE/DAE sensitivity analysis has been greatly refactored in CasADi 3.6:
#     - It now supports piecewise constant controls ("u")
#     - The differentiation now works when the solution is retrieved at a time grid, not just a single point
#     - The integrator plugin classes much better exploit the ODE/DAE sensitivity analysis structure




import numpy as np
# Create an integrator for simulating the ODE over 10 s using CVODES
N = 100
T = 3600*N
tgrid = np.linspace(0., T, N+1)
#tgrid = np.linspace(0., T, 100)
#dae.set_min(x[0], -np.inf) # relax lower bound on x1
daefun = dae.create('daefun')
sim = casadi.integrator('sim', 'cvodes', daefun, 0, tgrid)

u_test = [293.15, 330, 320, 310]

# Call integrator instance
r = sim(x0 = x0, u = u_test)
x_traj_sim = r['xf'].full()

import matplotlib.pyplot as plt
# Plot x1 vs. x2
plt.plot(x_traj_sim[0,:], x_traj_sim[1,:])
plt.xlabel(x[0])
plt.ylabel(x[1])
plt.grid(True)
plt.show()


# ## Forward sensitivity analysis with Sundials/CVODES
# In the following, we show how forward sensitivities can be calculated analytically for the FMU simulation.
# We will formulate these equations by providing the "nfwd" argument to the integrator instance.
# The `nfwd` argument will give additional columns in the input and output matrices corresponding to sensitivities
# that will be calculated along with the non-differentiated solution.
# 
# This is a new, lower level interface, to ODE/DAE sensitivity available in CasADi 3.6.
# You can also use the standard sensitivity syntax as demonstrated in the sensitivity_analysis.py example.
# We use the low-level syntax here since it is easier for debugging.

# Create a new Simulator with support for forward sensitivities
fwd_sim = casadi.integrator('fwd_sim', 'cvodes', daefun, 0, tgrid, dict(nfwd = 1, verbose = False, print_stats = True, second_order_correction = False))
print(fwd_sim)
# Let's calculate sensitivity w.r.t. x1, i.e. use a forward seed [1, 0] for x0:
seed_x0 = casadi.DM([1, 0])
fwd_test = fwd_sim(x0 = casadi.horzcat(x0, seed_x0),
                  u = casadi.horzcat(u_test, 0))
# The directional derivatives can be found in column 1, 3, 5, etc. of `xf` for the different grid points.
# (column 0, 2, 4, etc corresponds to nondifferentiated xf, for each grid point)
print('dxf/dx0 * seed_x0 [AD, forward] = ', fwd_test['xf'][:, 1::2])
# We can compare this result with a finite difference perturbation
pert = 1e-3
pert_sim = sim(x0=x0 + pert * seed_x0, u=u_test)
x_pert_sim = pert_sim['xf']
print('dxf/dx0 * seed_x0 [FD] = ', (x_pert_sim - x_traj_sim) / pert)


# ## Adjoint sensitivity analysis with Sundials/CVODES
# In the following, we show how adjoint sensitivities can be calculated analytically for the FMU simulation.
# We will formulate these equations by providing the "nadj" argument to the integrator instance.
# The `nadj` argument will give additional columns in the inputs and outputs of the integrator. Each seed has now
# the name of the nondifferentiated output, prefixed with "adj_" and each sensitivity has the name of the
# nondifferentiated input, also prefixed with "adj_".
# 
# As in the forward sensitivity case, you can also use the standard sensitivity syntax as demonstrated in the
# sensitivity_analysis.py example.




# Let us use a 4th order collocation discretization using Legendre roots, cf. 
# Nonlinear Programming: Concepts, Algorithms, and Applications to Chemical Processes
# by Lorenz Biegler (2010)
d = 3
# The roots can be queried from CasADi or looked up in the above textbook
tau_root = np.append(0, casadi.collocation_points(d, 'legendre'))
# Coefficients of the collocation equation
C = np.zeros((d+1,d+1))
# Coefficients of the continuity equation
D = np.zeros(d+1)
# Coefficients of the quadrature function
B = np.zeros(d+1)
# Construct polynomial basis
for j in range(d+1):
    # Construct Lagrange polynomials
    p = np.poly1d([1])
    for r in range(d+1):
        if r != j:
            p *= np.poly1d([1, -tau_root[r]]) / (tau_root[j]-tau_root[r])
    # Evaluate at the final time to get the coefficients of the continuity equation
    D[j] = p(1.0)
    # Evaluate the time derivative to get the coefficients of the continuity equation
    pder = np.polyder(p)
    for r in range(d+1): C[j,r] = pder(tau_root[r])
    # Evaluate the integral of the polynomial to get the coefficients of the quadrature function
    pint = np.polyint(p)
    B[j] = pint(1.0)
print('tau_root: ', tau_root)
print('C: ', C)
print('D: ', D)
print('B: ', B)




# Symbolic expression for the controls (piecewise constant)
U = casadi.MX.sym('U',len(u))
# Symbolic expressions for the states at each collocation point
X = [casadi.MX.sym('X_' + str(j), len(x)) for j in range(d+1)]
# Define the collocation equations
g = []
for j in range(1,d+1):
  # Expression for the state derivative at the collocation point
  xdot_j = 0
  for r in range (d+1): xdot_j += C[r,j]*X[r]
  # Append collocation equations
  g.append(h*f(X[j],U) - xdot_j)
# Concatenate constraints
g = casadi.vertcat(*g)
# Form a root-finding function, implicitly defining X[1:] as a function of U, X[0]
X_unknown = casadi.vertcat(*X[1:])
rfp = casadi.Function('rfp', [X_unknown, X[0], U], [g], ['V0', 'X0', 'U'], ['V'])


# * Rootfinding instances in CasADi solves problems of the form:
#  $$ g(x, p) = 0 $$
# * Nonlinear system of equation can be solved with KINSOL, other Newton solvers
# * Rootfinding instances are differentiable, derivatives to any order can be derived from implicit-function theorem



# We can solve this system of equations using Sundials/KINSOL
ifcn = casadi.rootfinder('ifcn', 'kinsol', rfp, dict(print_level = 1))
# Take a single step of the integrator
v0 = casadi.repmat(x0, d, 1)
v0 = ifcn(v0, x0, u_test)
# State at each collocation point
x_all = casadi.reshape(v0, len(x), d)
# Prepend initial state
x_all = casadi.horzcat(x0, x_all)
# Also calculate the state at the end
xf = casadi.mtimes(x_all, D)
# Print solution
print('x_all: ', x_all)
print('xf: ', xf)




# We can also use CasADi's native Newton solver
ifcn = casadi.rootfinder('ifcn', 'newton', rfp, dict(print_iteration = True))
# Take a single step of the integrator
v0 = casadi.repmat(x0, d, 1)
v0 = ifcn(v0, x0, u_test)
# State at each collocation point
x_all = casadi.reshape(v0, len(x), d)
# Prepend initial state
x_all = casadi.horzcat(x0, x_all)
# Also calculate the state at the end
xf = casadi.mtimes(x_all, D)
# Print solution
print('x_all: ', x_all)
print('xf: ', xf)


# ### Solvers for nonlinear systems of equations are differentiable to any order in CasADi:




# We can solve this system of equations using Sundials/KINSOL
ifcn = casadi.rootfinder('ifcn', 'kinsol', rfp, dict(print_level = 1))
# Differentiate Newton solver
jac_ifcn = ifcn.jacobian()
sol = jac_ifcn(V0 = v0, X0 = x0, U = u_test)
# Jacobian of state at collocation points w.r.t. U
print('jac_V_U = ', sol['jac_V_U'])
# Jacobian of state at collocation points w.r.t. X0
print('jac_V_X0 = ', sol['jac_V_X0'])




# Compare with finite differences
pert = 1e-3
# Perturn u
v0_pert = ifcn(casadi.repmat(x0, d, 1), x0, u_test + pert)
jac_V_U_fd = (v0_pert - v0) / pert
print('jac_V_U (FD) = ', jac_V_U_fd)
# Perturb x1
v0_pert = ifcn(casadi.repmat(x0, d, 1), x0 + casadi.DM([pert, 0]), u_test)
jac_V_X0_fd1 = (v0_pert - v0) / pert
# Perturb x2
v0_pert = ifcn(casadi.repmat(x0, d, 1), x0 + casadi.DM([0, pert]), u_test)
jac_V_X0_fd2 = (v0_pert - v0) / pert
print('jac_V_X0 (FD) = ', casadi.horzcat(jac_V_X0_fd1, jac_V_X0_fd2))





# Let's create a CasADi function for simulating the whole trajectory using Kinsol
ifcn = casadi.rootfinder('ifcn', 'kinsol', rfp)
x0_in = casadi.MX.sym('x0', len(x))
u_all = []
xk = x0_in
x_all = [x0_in]
for k in range(N):
    # Symbolic expression for the control for the interval
    uk = casadi.MX.sym('u' + str(k), len(u))
    u_all.append(uk)
    # Solve rootfinding problem, using previous step as guess
    vk = ifcn(casadi.repmat(xk,d,1), xk, uk)
    # Reshape and prepend initial state
    vk = casadi.reshape(vk, len(x), d)
    vk = casadi.horzcat(xk, vk)
    # Get the state at the end
    xk = casadi.mtimes(vk, D)
    # Save trajectory
    x_all.append(xk)
# Embed in a CasADi Function
irksim = casadi.Function('irksim', [x0_in, casadi.vcat(u_all)], [casadi.hcat(x_all)],
                         ['x0', 'u'], ['x'])
# Evaluate the function
x_traj = irksim(x0, u_test).full()





# Plot x1 vs. x2
plt.clf()
plt.plot(x_traj_sim[0,:], x_traj_sim[1,:], 'o', label = 'CVodes')
plt.plot(x_traj[0,:], x_traj[1,:], '-', label = 'Implicit Runge-Kutta with Kinsol')
plt.xlabel(x[0])
plt.ylabel(x[1])
plt.grid(True)
plt.legend()


# ## ODE/DAE sensitivity analysis of custom fixed step integrator




# A nonlinear equation solver is a differentiable object in CasADi.
# We can differentiate it analytically to get the Jacobian-times-vector product:
fwd_irksim = irksim.forward(1)
# Let's calculate sensitivity w.r.t. x1, i.e. use a forward seed [1, 0] for x0:
seed_x0 = casadi.DM([1, 0])
fwd_test = fwd_irksim(x0 = x0, u = u_test, fwd_x0 = seed_x0)
print('fwd_x (AD, forward) = ', fwd_test['fwd_x'])
# We can compare this result with a finite difference perturbation
pert = 1e-3
x_pert = irksim(x0 + pert * seed_x0, u_test).full()
print('fwd_x (FD) = ', (x_pert - x_traj) / pert)





# Now let's to a reverse mode AD, i.e. a transposed-Jacobian-times-vector product
adj_irksim = irksim.reverse(1)
# We seed the last entry in x2
seed_x = casadi.DM.zeros(2, N + 1)
seed_x[1, N] = 1
adj_test = adj_irksim(x0 = x0, u = u_test, adj_x = seed_x)
print('adj_x0 (AD, reverse) = ', adj_test['adj_x0'])
print('adj_u (AD, reverse) = ', adj_test['adj_u'])



# We can check that the result is consistent with forward mode AD:
print('Forward mode: derivative of x[1, N] w.r.t. x0[0] = ', fwd_test['fwd_x'][1, N])
print('Reverse mode: derivative of x[1, N] w.r.t. x0[0] = ', adj_test['adj_x0'][0])




# We can also calculate the full Jacobian of x w.r.t. x0 and u:
jac_irksim = irksim.jacobian()
jac_test = jac_irksim(x0 = x0, u = u_test)
print('jac_x_x0 = ', jac_test['jac_x_x0'])
print('jac_x_u = ', jac_test['jac_x_u'])




# Note the sparsity pattern of dx/du:
plt.spy(jac_test['jac_x_u'].sparse())
plt.show()


# ## Dynamic optimization
# Now let us find the control signals that minimize the cost function
# $$ J := \sum_{k = 0}^{N}{\|u_k\|^2 + \|x_{k+1}\|^2} $$
# We will embed the implicit Runge-Kutta discretization in a nonlinear program (NLP), which results in a simultaneous method for dynamic optimization. For details, cf. e.g. Biegler (2010)




# We will construct an NLP incrementally, starting with no decision variables, 
# and constraints, and zero objective
w = []
g = []
J = 0
# Loop over all control intervals, constructing the NLP and x, u trajectories
U_all = []
X_all = []
xk = casadi.MX(x0)
for k in range(N):
    # Symbolic expression for the control for the interval
    uk = casadi.MX.sym('u' + str(k), len(u))
    U_all.append(uk)
    w.append(uk)
    # States at each collocation point for the interval
    Xc = [xk]
    for j in range(1, d + 1):
        xkj = casadi.MX.sym('x' + str(k) + '_' + str(j), len(x))
        Xc.append(xkj)
        X_all.append(xkj)
        w.append(xkj)
    # Collect the collocation equations
    for j in range(1,d+1):
      # Expression for the state derivative at the collocation point
      xdot_j = 0
      for r in range (d+1): xdot_j += C[r,j]*Xc[r]
      # Append collocation equations
      g.append(h*f(Xc[j],uk) - xdot_j)
    # State at the end of the interval
    xk_end = 0
    for j in range(0,d+1): xk_end = xk_end + D[j] * Xc[j]
    # New variable for the state at the end of the interval
    xk = casadi.MX.sym('x' + str(k + 1), len(x))
    X_all.append(xk)
    w.append(xk)
    # Enforce continuity
    g.append(xk_end - xk)
    # Add contributions to the objective
    J = J + casadi.sumsqr(uk) + casadi.sumsqr(xk)
# Concatenate vectors
w = casadi.vcat(w)
g = casadi.vcat(g)
X_all = casadi.hcat(X_all)
U_all = casadi.hcat(U_all)
# Create mappings from (u, x) -> (w) and back
to_w = casadi.Function('to_w', [X_all, U_all], [w], ['x', 'u'], ['w'])
from_w = casadi.Function('from_w', [w], [X_all, U_all], ['w'], ['x', 'u'])
# Form the NLP
nlp = dict(x = w, f = J, g = g)



# Let's form the Jacobian of g w.r.t. w
t0 = time()
jac_g_w = casadi.jacobian(g, w)
print('Symbolic expression for Jacobian of g w.r.t w formed in %g s' % (time() - t0))
# Create a function for evaluation
t0 = time()
jfcn = casadi.Function('jfcn', [w], [jac_g_w], ['w'], ['jac_g_w'])
print('Jacobian function formed in %g s' % (time() - t0))
# Evaluate function
w_test = to_w(u = u_test, x = x0)['w']
t0 = time()
J_test = jfcn(w_test)
print('Jacobian evaluated in %g s' % (time() - t0))
# Let's look at the sparsity pattern
plt.spy(J_test.sparse())
plt.show()


# Formulate as a noninear program. In CasADi, they take the form:
#  $$ \begin{array}{cl}
#  \text{minimize} &  f(x, p) \\
#     \text{subject to} & \underline{x} \le x \le \overline{x} \\
#      & \underline{g} \le g(x, p) \le \overline{g} \\
#      & p = \underline{\overline{p}}
#     \end{array}
#      $$
#      
# CasADi will generate efficient derivative information and pass it to the specific solver
# 
# Multiple solver plugins, including IPOPT:



# Create an IPOPT instance, using L-BFGS
opts = dict(ipopt = dict(hessian_approximation = 'exact', linear_solver = 'mumps'))
solver = casadi.nlpsol('solver', 'ipopt', nlp, opts)




# Generate initial guess for w
w0 = to_w(u = 0, x = x0)['w']
# Lower bound for w
lbw = to_w(u = lbu, x = lbx)['w']
# Upper bound for w
ubw = to_w(u = ubu, x = ubx)['w']
# Solve NLP
sol = solver(x0 = w0, lbx = lbw, ubx = ubw, lbg = 0, ubg = 0)


# Extract solution
w_sorted = from_w(w = sol['x'])
x_opt = w_sorted['x']
u_opt = w_sorted['u']
# Add x0 to the beginning of x
x_opt = casadi.horzcat(x0, x_opt)
# Only keep the points at the interval boundaries
x_opt = x_opt[:, 0::d+1]
# Convert to numpy arrays
x_opt = x_opt.full()
u_opt = u_opt.full()
# Plot solution
plt.figure()
plt.plot(x_opt[0,:], x_opt[1,:])
plt.xlabel(x[0])
plt.ylabel(x[1])
plt.title("Optimal state trajectory")
plt.grid(True)
# Also plot as a function of time
grid = np.linspace(0, T, N+1)
# Plot the results
plt.figure()
plt.clf()
plt.plot(grid, x_opt[0,:],'--', label = x[0])
plt.plot(grid, x_opt[1,:],'-.', label = x[1])
plt.step(grid, np.concatenate(([np.nan], u_opt[0,:])),'-', label = u[0])
plt.title("Optimal solution")
plt.xlabel('time')
plt.legend()
plt.grid()
