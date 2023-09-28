#!/usr/bin/env python
# coding: utf-8

"""
Want to test non-linearity of output-limited, anti-windup PID controller,
compared to regular, linear PID-control.

"""


# Use FMU to create a CasADi/DaeBuilder instance
import casadi
import numpy as np
import matplotlib.pyplot as plt

def test_pid_fmu(fmu_path, N, dt):

    #dae = casadi.DaeBuilder('PI', "FMUs/PI/PI.fmutmp")
    #dae = casadi.DaeBuilder('PI', "FMUs/LimPID/LimPID.fmutmp")
    dae = casadi.DaeBuilder('PI', fmu_path )
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


    # Get free control, bounds
    u = dae.u()
    lbu = dae.min(u)
    ubu = dae.max(u)
    nu = dae.nu()
    print('u: ', u)
    print('lbu: ', lbu)
    print('ubu: ', ubu)

    # Evaluate ODE right-hand-side
    f = dae.create('f', ['x', 'u'], ['ode'])
    print(f)
    # Evaluate the function numerically
    #u_test = 0.4
    np.random.seed(42)
    u_test = np.random.rand(dae.nu(), N)
    xdot_test = f(x0, u_test)
    #print('xdot_test: ', xdot_test)



    # Evaluate ODE right-hand-side with auxilliary field
    """
    f_with_aux = dae.create('f_with_aux', ['x', 'u'], ['ode'],
                dict(aux = ['pi.x', 'u']))
    print(f_with_aux)
    # After evaluation, the aux variables are in the stats field:
    #u_test = 0.4
    np.random.seed(42)
    #u_test = np.random.rand(1,202)
    u_test = np.random.rand(dae.nu(), N)
    xdot_test_with_aux = f_with_aux(x0, u_test)
    print('xdot_test_with_aux: ', xdot_test_with_aux)
    print(f_with_aux.stats())
    """

    # Anything that is not real-valued (but for example string or integer valued) can also be passed this way.

    # ### First order derivatives - Jacobians
    # 
    # First order derivative information can be obtained either numerically or analytically. In either case, the Jacobian sparsity information in the FMU will be exploited using CasADi's graph coloring techniques.
    # 
    # For efficiency, the evaluation can be done in parallel using either OpenMP or std::thread. The interface will distribute the evaluation over the available threads:


    # A function that calculates the ODE and two Jacobian blocks:
    J = dae.create('J', ['x', 'u'], ['ode', 'jac_ode_x', 'jac_ode_u'],
                dict(verbose = False, parallelization = 'openmp'))
    print(J)

    # Evaluate Jacobian
    xdot_test, A_test, B_test = J(x0, u_test)
    #print('xdot_test: ', xdot_test)
    #print('A_test: ', A_test)
    #print('B_test: ', B_test)


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
                dict(verbose = False,
                    parallelization = 'openmp',
                    enable_ad = False))
    #print(J_fd)

    # Evaluate Jacobian
    xdot_fd, A_fd, B_fd = J_fd(x0, u_test)
    #print('xdot_fd: ', xdot_fd)
    #print('A_fd: ', A_fd)
    #print('B_fd: ', B_fd)


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
                dict(verbose = False, parallelization = 'openmp'))
    print(H)
    # Evaluate Hessian
    # Evaluate Jacobian
    H_xx, H_xu, H_uu = H(x0, u_test, 1)
    #print('H_xx: ', H_xx)
    #print('H_xu: ', H_xu)
    #print('H_uu: ', H_uu)


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

    # Create an integrator for simulating the ODE over 10 s using CVODES
    T = N*dt - dt
    tgrid = np.linspace(0., T, N)
    dae.set_min(x[0], -np.inf) # relax lower bound on x1
    daefun = dae.create('daefun')
    sim = casadi.integrator('sim', 'cvodes', daefun, 0, tgrid)



    # Call integrator instance
    r = sim(x0 = x0, u = u_test)
    x_traj_sim = r['xf'].full()

    # Plot x1 vs. x2#
    #plt.plot(x_traj_sim[0,:], x_traj_sim[1,:])
    plt.plot(tgrid, x_traj_sim[0,:])
    plt.grid(True)
    plt.xlabel("time")
    plt.ylabel("pi.x")


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
    #seed_x0 = casadi.DM([1, 0])
    seed_x0 = casadi.DM([1])
    fwd_test = fwd_sim(x0 = casadi.horzcat(x0, seed_x0),
                    #u = casadi.horzcat(u_test, 0))
                    u = u_test)
    # The directional derivatives can be found in column 1, 3, 5, etc. of `xf` for the different grid points.
    # (column 0, 2, 4, etc corresponds to nondifferentiated xf, for each grid point)
    print('dxf/dx0 * seed_x0 [AD, forward] = ', fwd_test['xf'][:, 1::2])

    # plot it:
    plt.plot(tgrid, fwd_test['xf'][:, 1::2].reshape((N,1)), color="m", linestyle="dashed") # TODO: reshape to (N, n_x)
    #plt.xlabel(["trajectory"], ["fwd_sens"])

    # We can compare this result with a finite difference perturbation
    pert = 1e-3
    pert_sim = sim(x0=x0 + pert * seed_x0, u=u_test)
    x_pert_sim = pert_sim['xf']
    #print('dxf/dx0 * seed_x0 [FD] = ', (x_pert_sim - x_traj_sim) / pert)


    # ## Adjoint sensitivity analysis with Sundials/CVODES
    # In the following, we show how adjoint sensitivities can be calculated analytically for the FMU simulation.
    # We will formulate these equations by providing the "nadj" argument to the integrator instance.
    # The `nadj` argument will give additional columns in the inputs and outputs of the integrator. Each seed has now
    # the name of the nondifferentiated output, prefixed with "adj_" and each sensitivity has the name of the
    # nondifferentiated input, also prefixed with "adj_".
    # 
    # As in the forward sensitivity case, you can also use the standard sensitivity syntax as demonstrated in the
    # sensitivity_analysis.py example.


    # Create a new Simulator with support for adjoint sensitivities
    adj_sim = casadi.integrator('adj_sim', 'cvodes', daefun, 0, tgrid, dict(nadj = 1, verbose = False, print_stats = True, second_order_correction = True, print_time = True))
    print(adj_sim)
    # Let's calculate sensitivity of xf[0] w.r.t. u at all the grid points, i.e. use an adjoint seed [1, 0] for xf:
    seed_xf = casadi.DM.zeros(1, N)
    seed_xf[:, -1] =  casadi.DM([1])  # We seed the state at the last grid point only
    adj_test = adj_sim(x0 = x0, adj_xf = seed_xf, u = u_test)
    print('trans(dxf/du) * seed_xf (AD, adjoint) = ', adj_test['adj_u'])

    adj_u = adj_test['adj_u'].reshape((1,nu*N))
    plt.plot(tgrid, adj_u[:,0::2].reshape((N,1)))
    plt.plot(tgrid, adj_u[:,1::2].reshape((N,1)))
    plt.title(fmu_path)
    plt.legend(["trajectory", "dxf/dx0 * seed_x0 (AD, forward)", "trans(dxf/du0) * seed_xf (AD, adjoint)", "trans(dxf/du1) * seed_xf (AD, adjoint)"])
    plt.show()


    # ## Forward-over-adjoint sensitivity analysis with Sundials/CVODES
    # We can also calculate second order sensitivities, i.e. Hessian-times-vector products, analytically. Again, we use the new low-level interface


    fwd_adj_sim = casadi.integrator('fwd_adj_sim', 'cvodes', daefun, 0, tgrid, dict(nfwd = 1, nadj = 1, verbose = False, print_stats = True, second_order_correction = False))
    print(fwd_adj_sim)
    # Let's calculate sensitivity of d(xf[0])/dx1 w.r.t. u at all the grid points, i.e. combining the seeds for forward and adjoint sensitivitiy analysis above
    #fwd_adj_test = fwd_adj_sim(x0 = casadi.horzcat(x0, seed_x0), adj_xf = casadi.horzcat(seed_xf, casadi.DM.zeros(seed_xf.shape)), u = casadi.horzcat(u_test, 0))
    fwd_adj_test = fwd_adj_sim(x0 = casadi.horzcat(x0, seed_x0), adj_xf = casadi.horzcat(seed_xf, casadi.DM.zeros(seed_xf.shape)), u = u_test)
    #print('d(trans(dxf/du) * seed_xf)/dx0 * seed_x0 (AD, forward-over-adjoint) = ', fwd_adj_test['adj_u'][:,1::2])

fmu_paths = ["FMUs/LimPID/LimPID.fmutmp", "FMUs/PI/PI.fmutmp"]
N = 100
dt = 900
for path in fmu_paths:
    test_pid_fmu(path,N,dt)