from casadi import *
from abc import ABC, abstractmethod, ABCMeta
import numpy as np

class Integrator(metaclass=ABCMeta):
    @classmethod
    def __subclasshook__(cls, subclass):
        return (hasattr(subclass, 'dae')) #and 
                #hasattr(subclass, 'get_one_sample') and 
                #callable(subclass.get_one_sample))

#    @abstractmethod
#    def get_one_sample(self): 
#        raise NotImplementedError
    
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
        

    @property
    def all_vars(self):
        return [getattr(self, name) for name in self.dae.order]

class Cvodes(Integrator):
    """
    Wrapper for Cvodes functionality in Casadi.

    TODO: how to do n-step? i.e. sub-sampling.
    For now, only n_step = 1.

    TODO: handling of DAE's
    """ 
    
    def __init__(self, dt, dae):

        self.dae = dae
        opts = {
            "step0":    dt,
            #"min_step_size": dt,
            #"max_step_size": dt,
            "t0"      : 0.0,
            "tf"      : 1,
            "abstol"  : 1E-4
                }

        self.set_ode_func()
        # u->z in integrator call (algebraic var, constant on between phase boundaries (check term. in Betts ch. 4))
        self.I = integrator("I", "idas", {"x": self.x, "p": vertcat(self.p, self.u), "ode": self.ode}, opts)
        #elf.I.set_option("abstol", 1E-4)
        #I(x0=0)
        #stats = I.stats()
        #self.one_step = self.get_one_step()
        #self.one_sample = self.get_one_sample()


    def one_sample(self, x0=None, p=None):
        """
        x0, p
        """
        return self.I(x0=x0, p=p)
    
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
        self.ode = vertcat(*self.dae.dae.ode)


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
        self.set_g_expr()
        self.set_g()
        self.init_integrator()
        #self.one_sample = self.get_one_sample()
    
        
    def set_ode_expr(self):
        self.ode = vertcat(*self.dae.dae.ode)
    
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
        exprs = (v for k, v in self.dae.algs.items() if k.startswith("h"))
        self.h_expr = vertcat(*exprs)
        
    def set_h(self):
        self.h = Function('h',
                          [self.y, self.x, self.z, self.u, self.p, self.v, self.r],
                          [self.h_expr],
                          ["y", "x", "z", "u", "p", "v", "r"],
                          ["h"])
    
    def set_g_expr(self):
        """
        Set algebraic expressions.
        
        Rule:
            Any expression in config-file under
            keys "model", "alg" NOT starting with
            "h" is taken as algebraic expr.
        """
        exprs = (v for k, v in self.dae.algs.items() if not k.startswith("h"))
        self.g_expr = vertcat(*exprs)
        
    def set_g(self):
        self.g = Function('g',
                          [self.x, self.z, self.u, self.p, self.v, self.r],
                          [self.g_expr],
                          ["x", "z", "u", "p", "v", "r"],
                          ["g"])
        
    def set_ode_func(self):
        self.f = Function('f', [self.x, self.z, self.u, self.p, self.w, self.r], [self.ode], ["x", "z", "u", "p", "w", "r"], ["f"])
        
    def set_coll_coeffs(self):
        """
        Get collocation coefficients
        by degree of interpolating polynomial.s
        """
        
        # degree
        d = self.d
        
        tau_root = [0] + collocation_points(d, self.method)

        # Coefficients of the collocation equation
        C = np.zeros((d+1,d+1))

        # Coefficients of the continuity equation
        D = np.zeros(d+1)

        # Dimensionless time inside one control interval
        tau = SX.sym('tau')

        # For all collocation points
        for j in range(d+1):
        # Construct Lagrange polynomials to get the polynomial basis at the collocation point
            L = 1
            for r in range(d+1):
                if r != j:
                    L *= (tau-tau_root[r])/(tau_root[j]-tau_root[r])

            # Evaluate the polynomial at the final time to get the coefficients of the continuity equation
            lfcn = Function('lfcn', [tau], [L])
            D[j] = lfcn(1.0)

            # Evaluate the time derivative of the polynomial at all collocation points to get the coefficients of the continuity equation
            tfcn = Function('tfcn', [tau], [tangent(L,tau)])
            for r in range(d+1): C[j,r] = tfcn(tau_root[r])
            
        self.C = C
        self.D = D
        # and B for quadrature?

    def init_integrator(self):
        
        # improve handling:
        d, C, D, h, n, f = self.d, self.C, self.D, self.dt_n, self.n, self.f
        
        nx = len(self.dae.dae.x)
        nu = len(self.dae.dae.u)
        nz = len(self.dae.dae.z)        
        np = len(self.dae.dae.p)
        nw = len(self.dae.w_names)
        nr = len(self.dae.r_names)
        
        # x0, p, u, r, z, w, v:
        X0 = MX.sym('X0',nx)
        P = MX.sym('P',np)
        U = MX.sym('U',nu)
        R = MX.sym('U',nr)
        Z = MX.sym('Z',nz)
        W = MX.sym('W',nw)
        V = MX.sym('V', d*nx)
        
        # try to add meas noise:
        #v = MX.sym('v', nv)

        # Get the state at each collocation point
        X = [X0] + vertsplit(V, [r*nx for r in range(d+1)])

        # Get the collocation quations (that define V)
        V_eq = []
        for j in range(1,d+1):
            # Expression for the state derivative at the collocation point
            xp_j = 0
            for r in range (d+1):
                xp_j += C[r,j]*X[r]

            # Append collocation equations
            f_j = f(X[j], Z, U, P, W, R)
            V_eq.append(h*f_j - xp_j)

        # Concatenate constraints
        V_eq = vertcat(*V_eq)

        # Root-finding function, implicitly defines V as a function of X0 and P
        vfcn = Function(
                        'vfcn',
                        [V, X0, Z, U, P, W, R],
                        [V_eq]
                        )

        # Convert to SX to decrease overhead
        vfcn_sx = vfcn.expand()

        # Create a implicit function instance to solve the system of equations
        ifcn = rootfinder('ifcn', 'fast_newton', vfcn_sx)
        V = ifcn(MX(), X0, Z, U, P, W, R)
        X = [X0 if r==0 else V[(r-1)*nx:r*nx] for r in range(d+1)]

        # Get an expression for the state at the end of the finie element
        XF = 0
        for r in range(d+1):
            XF += D[r]*X[r]

        # Get the discrete time dynamics
        F = Function('F', [X0, Z, U, P, W, R], [XF])

        # Do this iteratively for all finite elements
        X = X0
        for i in range(n):
            X = F(X, Z, U, P, W, R)       
        
        self.one_sample = Function(
                                   'irk_integrator',
                                   [X0, Z, U, P, W, R],
                                   [X],
                                   ["x0", "z", "u", "p", "w", "r"],
                                   ["xf"]
                                   )
        
    def simulate(self, x0, U, params):
        """ 
        Simulate with given:
            - x0
            - U
            - params

        TODO: what about noise?
            - standard behaviour -> sim without noise.
        """
        if U.shape[1] == 1:
            N = U.shape[0]
        else:
            N = U.shape[1]

        #all_samples = self.get_one_sample().mapaccum("all_samples", N)
        all_samples = self.one_sample.mapaccum("all_samples", N)
        #u_coll = vertcat(U.T, repmat(params, 1, N), repmat(DM([0, 0]), 1, N))

        # TODO: fix case of more inputs
        #return all_samples(x0, u_coll, 0, 0, 0, 0)[0]
        w_vals = repmat(DM([0]*len(self.dae.dae.x)), 1, N)
        #v_vals = repmat(DM([0]*len(self.dae.dae.y)), 1, N)
        #return all_samples(x0, U.T, repmat(params, 1, N), w_vals)
        
        #### TODO: fix handling of 'z'
        
        x = all_samples(x0, 0, U.T, repmat(params, 1, N), w_vals, 0)
        return horzcat(x0, x)
        #return x
        


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
        self.set_h_expr()
        self.set_h()
        self.set_g_expr()
        self.set_g()
        self.one_step = self.get_one_step()
        self.one_sample = self.get_one_sample()

    def set_ode_expr(self):
        self.ode = vertcat(*self.dae.dae.ode)
    
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
        exprs = (v for k, v in self.dae.algs.items() if k.startswith("h"))
        self.h_expr = vertcat(*exprs)
        
    def set_h(self):
        self.h = Function('h',
                          [self.y, self.x, self.z, self.u, self.p, self.v, self.r],
                          [self.h_expr],
                          ["y", "x", "z", "u", "p", "v", "r"],
                          ["h"])
    
    def set_g_expr(self):
        """
        Set algebraic expressions.
        
        Rule:
            Any expression in config-file under
            keys "model", "alg" NOT starting with
            "h" is taken as algebraic expr.
        """
        exprs = (v for k, v in self.dae.algs.items() if not k.startswith("h"))
        self.g_expr = vertcat(*exprs)
        
    def set_g(self):
        self.g = Function('g',
                          [self.x, self.z, self.u, self.p, self.v, self.r],
                          [self.g_expr],
                          ["x", "z", "u", "p", "v", "r"],
                          ["g"])
        
    def set_ode_func(self):
        self.f = Function('f',
                          [self.x, self.z, self.u, self.p, self.w, self.r],
                          [self.ode],
                          ["x", "z", "u", "p", "w", "r"],
                          ["f"])
        
    @property
    def k1(self):
        return self.f(self.x, self.z, self.u, self.p, self.w, self.r)

    @property
    def k2(self):
        return self.f(self.x + self.dt/2.0*self.k1, self.z, self.u, self.p, self.w, self.r)

    @property
    def k3(self):
        return self.f(self.x + self.dt/2.0*self.k2, self.z, self.u, self.p, self.w, self.r)
    #X = self.x
    @property
    def k4(self):
        return self.f(self.x + self.dt*self.k3, self.z, self.u, self.p, self.w, self.r)
    
    @property
    def states_final(self):
        return self.x + self.dt/6.0*(self.k1 + 2*self.k2 + 2*self.k3 + self.k4)
    

    @property
    def final_expr(self):
        X = self.x
        for i in range(self.n_steps):
            X = self.one_step(X, self.z, self.u, self.p, self.w, self.r)
        return X

    def get_one_sample(self):
        return Function('one_sample',
                        [self.x, self.z, self.u, self.p, self.w, self.r],
                        [self.final_expr],
                        ["x0", "z", "u", "p", "w", "r"], ["xf"])  
    

    def get_one_step(self): # return Function-object
        return Function('one_step',[self.x, self.z, self.u, self.p, self.w, self.r], [self.states_final], ["x", "z", "u", "p", "w", "r"], ["x"]) 

    def simulate(self, x0, U, params):
        """ 
        Simulate with given:
            - x0
            - U
            - params

        TODO: what about z/noise states?
        """

        if U.shape[1] == 1:
            N = U.shape[0]
        else:
            N = U.shape[1]

        all_samples = self.get_one_sample().mapaccum("all_samples", N)

        return all_samples(x0, U, repmat(params,1,N)) # -> empty z 
        