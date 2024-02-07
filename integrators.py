#from casadi import *
import casadi as ca
from abc import ABC, abstractmethod, ABCMeta
import numpy as np
from ocp.dae import DAE

class Integrator(metaclass=ABCMeta):
    @classmethod
    def __subclasshook__(cls, subclass):
        return (hasattr(subclass, 'dae')) #and 
                #hasattr(subclass, 'get_one_sample') and 
                #callable(subclass.get_one_sample))

#    @abstractmethod
#    def get_one_sample(self): 
#        raise NotImplementedError
    
    def _nvar(self, var):
        return var.shape[0]
    
    def _init_nvar_property(self, varname):
        def func(var):
            return var.shape[0]
        self.__setattr__("n" + varname, func(getattr(self, varname)))
    
    @property
    def x(self):
         return ca.vertcat(*self.dae.dae.x)
     
    def vars(self, names):
        mxs = []
        for name in names:
            #mxs.append(self.dae.dae.var(name))
            mxs.append(getattr(self.dae, name)) # get mx by name
        return ca.vertcat(*mxs)
    
    def var(self, var: str):
        if isinstance(self.dae, DAE):
            if var in ("r", "s", "w", "v"): 
                return self.vars(getattr(self.dae, var + "_names"))
            else:
                return self.vars(getattr(self.dae.dae, var)())
                
        elif isinstance(self.dae, dict):
            return self.dae[var]
    
    """
    another_stand_alone_function = my_shiny_new_decorator(another_stand_alone_function)
    ->
    @my_shiny_new_decorator
    def another_stand_alone_function():
        print("Leave me alone")
    """
    
    def set_ode_expr(self):
        if isinstance(self.dae, DAE):
            self.ode = ca.vertcat(*self.dae.dae.ode())
        elif isinstance(self.dae, dict):
            self.ode = self.dae["ode"]
        else: 
            raise TypeError("Unknown DAE-type")
        

    """
    TODO: fix for w-exprs:
    """        
    def set_h_expr(self):
        # collect meas noise:
        """
        TODO: fragile, dependant on self-defined naming.
        Make conformant with DaeBuilder.
        """
        if isinstance(self.dae, DAE):
            lhs_v = self.v
            lhs_w = self.w
            exprs = []
            w_exprs = []
            for w, expr in zip(self.dae.dae.w(), self.dae.dae.wdef()):
                if w.startswith("v"):
                    exprs.append(expr)
                else:
                    w_exprs.append(expr)
                    
            rhs_v = ca.vertcat(*exprs)
            #rhs_w = ca.vertcat(*w_exprs)
            #exprs_w = lhs_w - rhs_w
            #exprs_wdef = rhs_w
            #self.w_expr = exprs_w
            #self.w_expr_def = exprs_wdef
            # TODO: concatenate z and x for h
            # set:
            exprs_v = lhs_v - rhs_v      
        elif isinstance(self.dae, dict):
            exprs_v = self.dae["h"]
        else: 
            raise TypeError("Unknown DAE-type")
        
        self.h_expr = exprs_v
        
    
    def set_g_expr(self):
        """
        Set algebraic expressions.
        
        Rule:
            Any expression in config-file under
            keys "model", "alg" NOT starting with
            "h" is taken as algebraic expr.
        """
        if isinstance(self.dae, DAE):
            exprs = (v for k, v in self.dae.algs.items() if not k.startswith("h"))
            g_expr = ca.vertcat(*exprs)
        elif isinstance(self.dae, dict): 
            g_expr = self.dae["g"]
        else: 
            raise TypeError("Unknown DAE-type")
        
        self.g_expr = g_expr        
    
    
    """
    @property
    def x(self):
        return self.vars(self.dae.dae.x())
    """
    
    @property
    def x(self):
        return self.var("x")

    """
    @property
    def u(self):
         return self.vars(self.dae.dae.u())
    """

    @property
    def u(self):
        return self.var("u")

    """
    @property
    def p(self):
         return self.vars(self.dae.dae.p())
    """

    @property
    def p(self):
        return self.var("p")
     
    """
    @property
    def z(self):
         return self.vars(self.dae.dae.z())
    """
    
    @property
    def z(self):
        return self.var("z")
    
    """
    @property
    def y(self):
         return self.vars(self.dae.dae.y())
    """ 
    
    @property
    def y(self):
        return self.var("y")
    
    """
    @property
    def v(self):
        return self.vars(self.dae.v_names)
    """
    
    @property
    def v(self):
        return self.var("v")

    @property
    def w(self):
        return self.vars(self.dae.w_names)

    @property
    def w(self):
        return self.var("w")
    
    """
    @property
    def s(self):
        return self.vars(self.dae.s_names)
    """ 
    
    @property
    def s(self):
        return self.var("s")
    
    
    """
    TODO: clean up r:

    @property
    def r(self):
        return ca.vertcat(*[getattr(self.dae, name) for name in self.dae.r_names])
    """

    @property
    def r(self):
        return self.var("r")
    
    @property
    def all_vars(self):
        #return [getattr(self, name) for name in self.dae.order]
        return ("x","z","u","p","r","s","y","w","v")
    
    """
    @property
    def x(self):
         return vertcat(*self.dae.dae.x)

    @property
    def u(self):
         return vertcat(*self.dae.dae.u)

    @property
    def p(self):
         return vertcat(*self.dae.dae.p)
     
    @property
    def z(self):
         return vertcat(*self.dae.dae.z)
     
    @property
    def y(self):
         return vertcat(*self.dae.dae.y)
    
    @property
    def v(self):
        return vertcat(*[getattr(self.dae, name) for name in self.dae.v_names])
     
    @property
    def w(self):
        return vertcat(*[getattr(self.dae, name) for name in self.dae.w_names])

    @property
    def r(self):
        return vertcat(*[getattr(self.dae, name) for name in self.dae.r_names])
        
    """
    
class Cvodes(Integrator):
    """
    Wrapper for Cvodes functionality in Casadi.

    TODO: how to do n-step? i.e. sub-sampling.
    For now, only n_step = 1.

    TODO: handling of DAE's
    """ 
    
    def __init__(self, dae, **kwds):

        self.dae = dae
        
        opts = {
            #"step0":    kwds["dt"],
            #"min_step_size": dt,
            #"max_step_size": dt,
            "abstol": 1E-6,
            "reltol"  : 1E-6,
            "max_order": 5,
            "linear_multistep_method": "bdf",
            "nonlinear_solver_iteration": "newton",
            "verbose": False
            
                }

        tgrid = kwds.pop("dt", [1])
        N = 1
        tgrid = [tgrid*1/N*(i+1) for i in range(N)]
        self.set_ode_func()
        #self.set_alg_func()
        # u->z in integrator call (algebraic var, constant on between phase boundaries (check term. in Betts ch. 4))
        self.one_sample = ca.integrator("I", \
            "cvodes", \
            {
             "x": self.x,
             "u": self.u,
             "p": ca.vertcat(self.p, self.r),
            "ode": self.ode,
            },
            0,
            tgrid,
            opts)
        
    def set_ode_func(self):
        """
        Deine as expr, not Function-obj.
        """
        self.ode = ca.vertcat(*self.dae.dae.ode())
        
    
class idas(Integrator):
    """
    Wrapper for Cvodes functionality in Casadi.

    TODO: how to do n-step? i.e. sub-sampling.
    For now, only n_step = 1.

    TODO: handling of DAE's
    """ 
    
    def __init__(self, dae, **kwds):

        self.dae = dae
        
        dt = kwds.pop("dt", None)
        
        
        opts = {
            #"step0":    kwds["dt"],
            #"min_step_size": dt,
            #"max_step_size": dt,
            "abstol"  : 1E-1
            #"linear_solver": "csparse"
            }
        
        self.set_ode_func()
        self.set_alg_func()
        # u->z in integrator call (algebraic var, constant on between phase boundaries (check term. in Betts ch. 4))
        
        
        self.one_sample = ca.integrator("I", \
            "idas", \
            {
             "x": self.x,
             "u": self.u,
             "z": self.z,
             "p": ca.vertcat(self.p, self.r),
            "ode": self.ode,
            "alg": self.alg
            },
            0,
            [dt],
            opts)
        
        #self.one_sample.print_options()
        #self.one_sample.print_options()
       
        #self.one_sample = self.get_one_sample()
        
        #elf.I.set_option("abstol", 1E-4)
        #I(x0=0)
        #stats = self.I.stats()
        #self.one_step = self.get_one_step()
        #self.one_sample = self.get_one_sample()


    def get_one_sample(self):
        """
        x0, p
        """
        # symbolic call:
        #x0 = self.x
        #p = 
        
        nx = len(self.dae.dae.x())
        nu = len(self.dae.dae.u())
        nz = len(self.dae.dae.z())        
        np = len(self.dae.dae.p())
        ns = len(self.dae.s_names)
        nr = len(self.dae.r_names)
        
        # x0, p, u, r, z, w, v:
        X0 = ca.MX.sym('X0',nx)
        P = ca.MX.sym('P',np)
        U = ca.MX.sym('U',nu)
        R = ca.MX.sym('U',nr)
        Z = ca.MX.sym('Z',nz)
        S = ca.MX.sym('S',ns)
        #V = ca.MX.sym('V', d*nx)
        
        #return self.I(x0=self.x, p=self.p)
        
        # TODO: handle noise, S and V
        #return self.I(x0=X0, z0=Z, u=ca.vertcat(U, R), p=P)
        fcn_call = self.I(x0=X0, z0=Z, u=ca.vertcat(U, R), p=ca.vertcat(P,S))
    
        one_sample = ca.Function("F",
                                 [X0, Z, U, P, S, R],
                                 [fcn_call["xf"]],
                                 ["x", "z", "u", "p", "s", "r"],
                                 ["f"])
        
        return one_sample

    
    """
    @property
    def final_expr(self):
        pass

    def get_one_step(self): # return Function-object
        pass

    """
    def set_ode_func(self):
        """
        Deine as expr, not Function-obj.
        """
        self.ode = ca.vertcat(*self.dae.dae.ode())
    
    def set_alg_func(self):
        """
        Deine as expr, not Function-obj.
        """
        self.alg = ca.vertcat(*self.dae.dae.alg())


class IRK(Integrator):
    
    def __init__(
                self,
                dae,
                **kwds
                ):
        """
        n-step implicit RK, aka Collocation.
        
        n: int - finite elements
        """
        self.dae = dae    
        
        '''         
        if len(kwds) == 0:
        self.d = degree
        self.dt = dt
        self.n = n_steps
        self.h = dt/n_steps
        self.method = method   
        else: # assume all params to come from kwds 
        '''
        self.d = kwds.pop("degree")
        self.dt = kwds.pop("dt")
        self.n = kwds.pop("n_steps") # finite elements
        self.dt_n = self.dt/self.n # dt on finite elements -> for use in collocation equations
        self.method = kwds.pop("method")
        

        self.set_ode_expr()
        self.set_ode_func()     
        self.set_coll_coeffs()
        #self.set_meas_expr()
        #self.set_meas_func()
        self.set_h_expr()
        self.set_h()
        
        for name in self.all_vars:
            self._init_nvar_property(name)
        
        self.set_g_expr()
        if not self.g_expr.is_empty():
            self.set_g() # the function-obj
            self.set_G() # rootfinder
        # TODO: fix w, dependant parameters
        #self.set_w()
        #self.set_wdef()
        
        self.init_integrator()
        #self.one_sample = self.get_one_sample()
    
        
    
    ''' def set_meas_expr(self):
        self._h = vertcat(*self.dae.algs.values())
        
    def set_meas_func(self):
        self.g = Function('g', [self.x, self.y, self.v], [self._h], ["x", "y", "v"], ["g"]) '''
      
    """
    def set_ode_expr(self):
        self.ode = ca.vertcat(*self.dae.dae.ode())
        
    def set_h_expr(self):
        #exprs = (v for k, v in self.dae.algs.items() if k.startswith("h"))
        #self.h_expr = ca.vertcat(*exprs)
        exprs = (self.dae.y[name] for name in self.dae.dae.y())
        self.h_expr = ca.vertcat(*exprs)
        
    # rename: rearrange_w
    def set_h_expr(self):
        exprs = []
        w_exprs = []
        for w, expr in zip(self.dae.dae.w(), self.dae.dae.wdef()):
            if w.startswith("v"):
                exprs.append(expr)
            else:
                w_exprs.append(expr)
                
        rhs_v = ca.vertcat(*exprs)
        #rhs_w = ca.vertcat(*w_exprs)
        # set:
        exprs_v = lhs_v - rhs_v
        #exprs_w = lhs_w - rhs_w
        #exprs_wdef = rhs_w
        self.h_expr = exprs_v
        #self.w_expr = exprs_w
        #self.w_expr_def = exprs_wdef
        
        # TODO: concatenate z and x for h
    """  
    
    def set_h(self):
        self.h = ca.Function('h',
                          [self.y, self.x, self.z, self.u, self.p, self.v, self.r, self.w],
                          [self.h_expr],
                          ["y", "x", "z", "u", "p", "v", "r", "w"],
                          ["h"])
    
    def set_w(self):
        self.wdef = ca.Function('wdef',
                          [self.y, self.x, self.z, self.u, self.p, self.v, self.r, self.w],
                          [self.w_expr],
                          ["y", "x", "z", "u", "p", "v", "r", "w"],
                          ["wdef"])
                          #**{"allow_duplicate_io_names" : True})
                          
    """
    def set_wdef(self):
        self.wdef = ca.Function('wdef',
                          [self.y, self.x, self.z, self.u, self.p, self.v, self.r, self.w],
                          [self.w_expr_def],
                          ["y", "x", "z", "u", "p", "v", "r", "w"],
                          ["wdef"])
                          #**{"allow_duplicate_io_names" : True})
        
    
    def set_g_expr(self):
        exprs = (v for k, v in self.dae.algs.items() if not k.startswith("h"))
        self.g_expr = ca.vertcat(*exprs)
    """
        
    def set_g(self):
        self.g = ca.Function('g',
                          [self.z, self.x, self.u, self.p, self.v, self.s, self.r, self.w],
                          [self.g_expr],
                          ["z", "x", "u", "p", "v", "s", "r", "w"],
                          ["g"])
        
    def set_G(self):
        """ g non-explicit."""
        
        """
        nx = len(self.dae.dae.x())
        nu = len(self.dae.dae.u())
        nz = len(self.dae.dae.z())        
        np = len(self.dae.dae.p())
        ns = len(self.dae.s_names)
        nr = len(self.dae.r_names)
        nw = len(self.dae.w_names)
        """
        
        nx = self.nx
        nu = self.nu
        nz = self.nz
        np = self.np
        ns = self.ns
        nr = self.nr
        nw = self.nw
        
        # x0, p, u, r, z, w, v:
        X = ca.MX.sym('X',nx)
        P = ca.MX.sym('P',np)
        U = ca.MX.sym('U',nu)
        R = ca.MX.sym('U',nr)
        Z = ca.MX.sym('Z',nz)
        S = ca.MX.sym('S',ns)
        W = ca.MX.sym('W',nw)
        #V = MX.sym('V', d*nx)
        
        """        
        vfcn = Function(
                        'vfcn',
                        [X0, Z, U, P, W, R],
                        [self.g_expr]
                        )
        # Convert to SX to decrease overhead
        #vfcn_sx = self.g.expand()
        # Create a implicit function instance to solve the system of equations
        #rootfinder('myarctan', 'newton', dict(x=x, p=p, g=tan(x)-p))
        
        # TODO: fix for all vars:
        
        ifcn = ca.rootfinder('ifcn_g', 'fast_newton', dict(x=self.z, \
                                                        p=ca.vertcat(
                                                                  self.x,
                                                                  self.u,
                                                                  self.p
                                                                  ),
                                                        g=self.g_expr))
        
        self.G = ifcn
        """
        
        """
        vfcn = ca.Function(
                'vfcn',
                [Z, X, U, P, S, R],
                [self.g_expr]
                )
                #[V, X0, _Z, U, P, S, R],
                #[ca.vertcat(V, _Z), X0, U, P, S, R],
        zfcn = ca.Function(
                        'zfcn',
                        #[V, X0, _Z, U, P, S, R],
                        [_Z, X0, V, U, P, S, R],
                        [Z_eq]
                        )
        """
        # Convert to SX to decrease overhead
        #vfcn_sx = vfcn.expand()
        #zfcn_sx = zfcn.expand()

        # Create a implicit function instance to solve the system of equations
        #v_ifcn = ca.rootfinder('ifcn', 'fast_newton', vfcn_sx)
        #z_ifcn = ca.rootfinder('ifcn', 'fast_newton', zfcn_sx)
        #ifcn = ca.rootfinder('ifcn', 'fast_newton', vfcn_sx)
        #ifcn = ca.rootfinder('g_rootfinder', 'fast_newton', self.g)
        ifcn = ca.rootfinder('g_rf', 'newton', self.g)
        self.G = ifcn
        
        
    def set_ode_func(self):
        self.f = ca.Function('f',
                          [self.x, self.z, self.u, self.p, self.s, self.r, self.w],
                          [self.ode],
                          ["x", "z", "u", "p", "s", "r", "w"],
                          ["f"])
        
    def set_coll_coeffs(self):
        """
        Get collocation coefficients
        by degree of interpolating polynomial.s
        """
        
        # degree
        d = self.d
        
        tau_root = [0] + ca.collocation_points(d, self.method)

        # Coefficients of the collocation equation
        C = np.zeros((d+1,d+1))

        # Coefficients of the continuity equation
        D = np.zeros(d+1)

        # Dimensionless time inside one control interval
        tau = ca.SX.sym('tau')

        # For all collocation points
        for j in range(d+1):
        # Construct Lagrange polynomials to get the polynomial basis at the collocation point
            L = 1
            for r in range(d+1):
                if r != j:
                    L *= (tau-tau_root[r])/(tau_root[j]-tau_root[r])

            # Evaluate the polynomial at the final time to get the coefficients of the continuity equation
            lfcn = ca.Function('lfcn', [tau], [L])
            D[j] = lfcn(1.0)

            # Evaluate the time derivative of the polynomial at all collocation points to get the coefficients of the continuity equation
            tfcn = ca.Function('tfcn', [tau], [ca.tangent(L,tau)])
            for r in range(d+1): C[j,r] = tfcn(tau_root[r])
            
        self.C = C
        self.D = D
        # and B for quadrature?

    def init_integrator(self):
        
        # improve handling:
        d, C, D, h, n, f = self.d, self.C, self.D, self.dt_n, self.n, self.f
        
        """
        nx = len(self.dae.dae.x())
        nu = len(self.dae.dae.u())
        nz = len(self.dae.dae.z())        
        np = len(self.dae.dae.p())
        ns = len(self.dae.s_names)
        nr = len(self.dae.r_names)
        nw = len(self.dae.w_names)
        """
        nx = self.nx
        nu = self.nu
        nz = self.nz
        np = self.np
        ns = self.ns
        nr = self.nr
        nw = self.nw
        
        # x0, p, u, r, z, w, v:
        X0 = ca.MX.sym('X0',nx)
        P = ca.MX.sym('P',np)
        U = ca.MX.sym('U',nu)
        R = ca.MX.sym('U',nr)
        #_Z = ca.MX.sym('Z',d*nz)
        Z = ca.MX.sym('Z',nz)
        S = ca.MX.sym('S',ns)
        W = ca.MX.sym('W',nw)
        V = ca.MX.sym('V', d*nx)
        
        # try to add meas noise:
        #v = MX.sym('v', nv)

        # Get the state at each collocation point
        X = [X0] + ca.vertsplit(V, [r*nx for r in range(d+1)])
        #Z = ca.vertsplit(_Z, [r*nz for r in range(d+1)])

        # Get the collocation quations (that define V)
        V_eq = []
        #Z_eq = []
        for j in range(1,d+1):
            # Expression for the state derivative at the collocation point
            xp_j = 0
            for r in range (d+1):
                xp_j += C[r,j]*X[r]


            # TODO: needs re-formulation, algebraic variables only defined on collocation points
            f_j = f(X[j], Z, U, P, S, R, W)
            #g_j = g(X[j], Z, U, P, S, R)
            #f_j = f(X[j], Z[j-1], U, P, S, R)
            #g_j = g(X[j], Z[j-1], U, P, S, R)
            # Append collocation equations
            V_eq.append(h*f_j - xp_j)
            # Append algebraic equations 
            #Z_eq.append(g_j)
            #V_eq.append(g_j)

        # Concatenate constraints
        V_eq = ca.vertcat(*V_eq)
        #Z_eq = ca.vertcat(*Z_eq)

        # Root-finding function, implicitly defines V as a function of X0 and P
        vfcn = ca.Function(
                        'vfcn',
                        [V, X0, Z, U, P, S, R, W],
                        #[V, X0, _Z, U, P, S, R],
                        #[ca.vertcat(V, _Z), X0, U, P, S, R],
                        [V_eq]
                        )
        """
        zfcn = ca.Function(
                        'zfcn',
                        #[V, X0, _Z, U, P, S, R],
                        [_Z, X0, V, U, P, S, R],
                        [Z_eq]
                        )
        """
        # Convert to SX to decrease overhead
        vfcn_sx = vfcn.expand()
        #zfcn_sx = zfcn.expand()

        # Create a implicit function instance to solve the system of equations
        #v_ifcn = ca.rootfinder('ifcn', 'fast_newton', vfcn_sx)
        #z_ifcn = ca.rootfinder('ifcn', 'fast_newton', zfcn_sx)
        #ifcn = ca.rootfinder('ifcn', 'fast_newton', vfcn_sx)
        #ifcn = ca.rootfinder('ifcn', 'fast_newton', vfcn)
        #ifcn = ca.rootfinder('ifcn', 'fast_newton', vfcn)
        ifcn = ca.rootfinder('ifcn', 'fast_newton', vfcn_sx)

        
        V = ifcn(ca.MX(), X0, Z, U, P, S, R, W)
        
        #V = ifcn(ca.MX(), X0, U, P, S, R)
        X = [X0 if r==0 else V[(r-1)*nx:r*nx] for r in range(d+1)]
        #offset = d*nx
        #Z = [V[(offset + r*nz):(offset + (r+1)*nz)] for r in range(d)]

        # Get an expression for the state at the end of the finite element
        XF = 0
        #ZF = 0
        for r in range(d+1):
            XF += D[r]*X[r]
            #if r != d:
            #    ZF += D[r]*Z[r]
                
                

        # Get the discrete time dynamics
        F = ca.Function('F', [X0, Z, U, P, S, R, W], [XF])
        #F = ca.Function('F', [X0, _Z, U, P, S, R], [XF])
        #F = ca.Function('F', [X0, U, P, S, R], [XF])
        #F_Z = ca.Function('F_Z', [X0, U, P, S, R], [ZF])

        # Do this iteratively for all finite elements
        X = X0
        for i in range(n):
            X = F(X, Z, U, P, S, R, W)       
            #X = F(X, U, P, S, R)       
            #Z = F_Z(X, U, P, S, R)       
        
        self.one_sample = ca.Function(
                                   'irk_integrator',
                                   [X0, Z, U, P, S, R, W],
                                   #[X0, _Z, U, P, S, R],
                                   #[X0, U, P, S, R],
                                   #[X, Z],
                                   [X],
                                   ["x0", "z", "u", "p", "s", "r", "w"],
                                   #["x", "u", "p", "s", "r"],
                                   ["xf"]
                                   )

    def simulate(self, 
                 N=None,
                 x0=None,
                 u=ca.DM([]),
                 p=ca.DM([]),
                 r=ca.DM([])
                 ):
        """ 
        Simulate ODE-dynamics over N time-steps with given:
            - x0
            - u
            - p
            - r
        """
        if N is None:
            if u.shape[1] == 1:
                N = u.shape[0]
            else:
                N = u.shape[1]

        all_samples = self.one_sample.mapaccum("all_samples", int(N))
        #return all_samples(x0, 0, U, ca.repmat(params,1,N), 0, 0) # -> empty z 
        return all_samples(x0,0,u,p,0,r,0)
    
    
"""
TODO: recfactor RK4. __init__ should take either:
    - DAE wrapper 
    or
    - MXDict/SXDict 
    describing the DAE-dynamics.
"""

class RK4(Integrator):
    ''' 
    Simple RK4 implementation. 

    TODO: Fix for simple algebraic (i.e. noise)
    states. Do as if n_step == 1, i.e. no
    need to enforce equality of w_n[t, i] = w_n[t, i+1]
    (on sub-intervals).
    
    TODO: can we generalize this to n-step RK-methods?
    '''
    def __init__(self, dae, **kwds):
        self.dae = dae
        dt = kwds.pop("dt")
        n_steps = kwds.pop("n_steps")

        assert n_steps >= 1

        self.n_steps = n_steps
        self.dt = dt/n_steps
        self.set_ode_expr()
        self.set_ode_func()  
        try:   
            self.set_h_expr()
            self.set_h()
        except:
            print("Not able to set measurement expressions...")
        #self.set_H()
        """
        NOTE: algebraic expressions should not be 
        part of explicit integrator.
        
        TODO: fix
        """
        try:   
            self.set_g_expr()
            self.set_g()
        except:
            print("Not able to set algebraic expressions...")
            
        self.one_step = self.get_one_step()
        self.one_sample = self.get_one_sample()
    
    ''' def set_meas_expr(self):
        self._h = vertcat(*self.dae.algs.values())
        
    def set_meas_func(self):
        self.g = Function('g', [self.x, self.y, self.v], [self._h], ["x", "y", "v"], ["g"]) '''
        
    def set_h_expr(self):
        """
        Set measurement expressions.
        
        Rule:
            Any expression in config-file under
            keys "model", "alg" starting with
            "h" is taken as measurement expr.
        """
        #exprs = (v for k, v in self.dae.algs.items() if k.startswith("h"))
        
        """
        Expression needs to start with y for wdef 
        """
        
        # collect meas noise:
        lhs = self.v
        rhs = ca.vertcat(*self.dae.dae.wdef())
        #exprs =  -rhs - lhs
        exprs = lhs - rhs
        #exprs = (v for k, v in self.dae.algs.items() if k.startswith("v"))
        #exprs
        
        #self.h_expr = vertcat(*exprs)
        self.h_expr = exprs
        
    def set_h(self):
        self.h = ca.Function('h',
                          [self.v, self.y, self.x, self.z, self.u, self.p, self.r, self.w],
                          [self.h_expr],
                          ["v", "y", "x", "z", "u", "p", "r", "w"],
                          ["h"])
        
    def set_H(self):
        ifcn = ca.rootfinder('g_rf', 'newton', self.h)
        self.H = ifcn
    
    def set_g_expr(self):
        """
        Set algebraic expressions.
        
        Rule:
            Any expression in config-file under
            keys "model", "alg" NOT starting with
            "h" is taken as algebraic expr.
        """
        exprs = (v for k, v in self.dae.algs.items() if not k.startswith("h"))
        self.g_expr = ca.vertcat(*exprs)
        
    def set_g(self):
        self.g = ca.Function('g',
                          [self.z, self.x, self.u, self.p, self.v, self.s, self.r, self.w],
                          [self.g_expr],
                          ["z", "x", "u", "p", "v", "s", "r", "w"],
                          ["g"])
        
    def set_ode_func(self):
        self.f = ca.Function('f',
                          [self.x, self.z, self.u, self.p, self.s, self.r, self.w],
                          [self.ode],
                          ["x", "z", "u", "p", "s", "r", "w"],
                          ["f"])
        
    @property
    def k1(self):
        return self.f(self.x, self.z, self.u, self.p, self.s, self.r, self.w)

    @property
    def k2(self):
        return self.f(self.x + self.dt/2.0*self.k1, self.z, self.u, self.p, self.s, self.r, self.w)

    @property
    def k3(self):
        return self.f(self.x + self.dt/2.0*self.k2, self.z, self.u, self.p, self.s, self.r, self.w)
    #X = self.x
    @property
    def k4(self):
        return self.f(self.x + self.dt*self.k3, self.z, self.u, self.p, self.s, self.r, self.w)
    
    @property
    def states_final(self):
        return self.x + self.dt/6.0*(self.k1 + 2*self.k2 + 2*self.k3 + self.k4)
    
    @property
    def final_expr(self):
        X = self.x
        for i in range(self.n_steps):
            X = self.one_step(X, self.z, self.u, self.p, self.s, self.r, self.w)
        return X

    def get_one_sample(self):
        return ca.Function('one_sample',
                        [self.x, self.z, self.u, self.p, self.s, self.r, self.w],
                        [self.final_expr],
                        ["x0", "z", "u", "p", "s", "r", "w"],
                        ["xf"])  
    

    def get_one_step(self): # return Function-object
        return ca.Function('one_step',
                        [self.x, self.z, self.u, self.p, self.s, self.r, self.w],
                        [self.states_final],
                        ["x", "z", "u", "p", "s", "r", "w"],
                        ["xf"]) 

    def simulate(self, 
                 N=None,
                 x0=None,
                 u=ca.DM([]),
                 p=ca.DM([]),
                 r=ca.DM([]),
                 z=ca.DM([]),
                 s=ca.DM([]),
                 y=ca.DM([]),
                 w=ca.DM([]),
                 v=ca.DM([])
                 ):
        """ 
        Simulate ODE-dynamics over N time-steps with given:
            - x0
            - u
            - p
            - r
        """
        if N is None:
            if u.shape[1] == 1:
                N = u.shape[0]
            else:
                N = u.shape[1]

        all_samples = self.get_one_sample().mapaccum("all_samples", int(N))
        #return all_samples(x0, 0, U, ca.repmat(params,1,N), 0, 0) # -> empty z 
        return all_samples(x0, z, u, p, s, r, w)
        