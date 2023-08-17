import casadi as ca

dt = 900
dae = ca.DaeBuilder('Simple2R2C', 'Simple2R2C_PI')
dae.disp(True)
#ode = dae.create('f', ['x','u','p'], ['ode'], {"verbose": True})
ode = dae.create('f', ['t', 'x', 'z', 'p', 'u'], ['ode','alg','ydef'], {"verbose": True})
tgrid = [0,dt]
#_N = 1
#tgrid = [dt*1/N*(i+1) for i in range(_N)]
opts = {
        "abstol": 3e-6,
        "reltol"  : 1E-6,
        "max_order": 5,
        "linear_multistep_method": "bdf",
        "nonlinear_solver_iteration": "newton",
        "verbose": True
        }
F = ca.integrator('F', 'cvodes', ode, tgrid[0], tgrid[1:], opts)