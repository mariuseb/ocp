from sysid.debug import Debug
from sysid.dae import DAE
import casadi as ca
import numpy as np


""" 
Abstract class.
TODO: 
Have the parameter estimation 
class inherit from this.
"""

class OCP(object):
    """
    Optimal control problem.

    Should function as ABC
    for MPC, MHE, FIE problems.

    (FIE-full information estimation/
     parameter estimation).
    """
    def __init__(self, dae, **kwargs):
        """
          .
        """ 
        #self.N = cfg['MPC']['temporal']['N']
        #self.Ts = cfg['MPC']['temporal']['h']
        #self.N = kwargs.pop("N")
        #self.dt = kwargs.pop("dt")

        # ocp variables

        #hk = np.exp(np.linspace(0,self.N-1,self.N)*self.non_uniform_gain)*self.dt
        #hk = self.dt
        # tf - finish time?
        # TODO: make a decision on tf:                    vertcat(*dae.dae.z), \
                # what 'bout r? separation between control input and external input
                # self.ocp.r.var(), \
        

        #tf = np.cumsum(hk)[-1]

        self.t = Mx('t')   # time
        self.t.add('t', 0, 1) # dummy end time .

        self.x = Mx('x')   # differential/state variables
        self.z = Mx('z')   # algebraic variables
        self.u = Mx('u')   # control piece-wise constrant
        # keep empty: 
        #self.r = Mx('r')   # reference piece-wise constrant
        self.p = Mx('p')   # parameters constants (another for time-varying tvp?)

        # Now iterate through DAE and add required information.

        """
        TODO: how to handle bounds here?

        TODO: keep 'old' MX from DAE or create new?
        """ 

        for x in dae.dae.x:
            self.x.add(x.name(), mx=x)
        for z in dae.dae.z:
            self.z.add(z.name(), mx=z)
        for u in dae.dae.u:
            self.u.add(u.name(), mx=u)
        for p in dae.dae.p:
            self.p.add(p.name(), mx=p)


        # incorporate user defined variables
        self.n_x_label = self.x.label()
        self.n_z_label = self.z.label()
        self.n_u_label = self.u.label()
        #self.n_y_label = self.y.label()
        self.n_p_label = self.p.label()

        #self.init()

        # cost functionals. but define them later.

        # lagrange:
        #self.l = self.l_fn()
        # mayer:
        #self.m = self.m_fn()

        # DAE equations

        #self.f = self.f_fn()    # ODE's
        #self.g = self.g_fn()    # equality constraints

        self.f = ca.vertcat(*dae.dae.ode)
        #self.g = ca.vertcat(*dae.dae.alg)
        self.g = ca.vertcat(*dae.g)

        # keep:
        self.dae = dae
        #self.h = self.h_fn()    # in-equality constraints
        #self.c = self.c_fn()    # periodical constraints

        # detect reference functionality

        #self.r_fn_active = True if self.r.dim() > 0 else False

    def g_fn(self):
        return ca.vertcat()

    def h_fn(self):
        return ca.vertcat()
        #if self.r_fn_active:
        #    if hasattr(self,'r_fn'):
        #        Debug.MOSIOP_NOTICE('Detected embedded internal reference function <{}> for class<{}>'.format('r_fn(self,k)', self.__class__.__name__))
        #    else:
        #        Debug.MOSIOP_WARNING('No internal reference function <{}> is supplied for class<{}>. Supply externally'.format('r_fn(self,k)', self.__class__.__name__))

    def l_fn(self):
        return 0

    def m_fn(self):
        return 0

    def f_fn(self):
        return ca.vertcat()

    def g_fn(self):
        return ca.vertcat()

    def h_fn(self):
        return ca.vertcat()

    def c_fn(self):
        return ca.vertcat()


# TODO: fix common ABC for stoch and det problems:
class FSE(OCP):
    pass


class DetFSE(OCP):

    def __init__(self, dae, **kwargs):

        # get Q, R:
        #Q = kwargs.pop("Q")
        R = kwargs.pop("R") 

        self.R = ca.DM(np.diag(R))
        #self.Q = ca.DM(np.diag(Q))

        super().__init__(dae, **kwargs)
        # extract measurement function, h (needs to be defined):
    
        """
        any algebraic equations starting with 'h' -> 
        belongs to state - output mapping.

        similarly for noise ->
        any starting with 'w':
        """
        #w_elems = []

        #for alg in self.dae.dae.z:
        #    if alg.name().startswith("w"):
        #        w_elems.append(alg)


        #h_elems = self.dae.y.values()
        # expression for measurement:
        self.h = ca.vertcat(*self.dae.y.values())
        # expression for noise:
        #self.w = ca.vertcat(*w_elems)
        # variable for measurement:
        self.y = Mx('y')
        # iterate through dae.y, add meas vars
        for y in self.dae.dae.y:
            self.y.add(y.name(), mx=y) # Now -> non-empty
    
        self.n_y_label = self.y.label()

        # stage cost:
        self.l = self.l_fn()
        # residual:
        self.r = self.r_fn()

    # abstract objective:
    # min (y_meas - y_model)_R + (w)_Q 

    def r_fn(self):
        """
        Residual.
        """
        return ca.mtimes(ca.inv(self.R), (self.y() - self.h))

    def l_fn(self):
        """
        Stage cost:
        r - residual 
        R - measurement covariance
        w - noise
        Q - noise covariance

        l(k) := r(k)^T*R^(-1)*r(k)
        """
        return ca.mtimes(ca.mtimes((self.y() - self.h).T, ca.inv(self.R)), (self.y() - self.h))
        

class StochFSE(OCP):

    def __init__(self, dae, **kwargs):

        # get Q, R:
        Q = kwargs.pop("Q")
        R = kwargs.pop("R") 

        self.R = ca.DM(np.diag(R))
        self.Q = ca.DM(np.diag(Q))

        super().__init__(dae, **kwargs)
        # extract measurement function, h (needs to be defined):
    
        """
        any algebraic equations starting with 'h' -> 
        belongs to state - output mapping.

        similarly for noise ->
        any starting with 'w':
        """
        w_elems = []

        for alg in self.dae.dae.z:
            if alg.name().startswith("w"):
                w_elems.append(alg)


        #h_elems = self.dae.y.values()
        # expression for measurement:
        self.h = ca.vertcat(*self.dae.y.values())
        # expression for noise:
        self.w = ca.vertcat(*w_elems)
        # variable for measurement:
        self.y = Mx('y')
        # iterate through dae.y, add meas vars
        for y in self.dae.dae.y:
            self.y.add(y.name(), mx=y) # Now -> non-empty
    
        self.n_y_label = self.y.label()

        # stage cost:
        self.l = self.l_fn()
        # residual:
        self.r = self.r_fn()

    # abstract objective:
    # min (y_meas - y_model)_R + (w)_Q 

    def r_fn(self):
        """
        Residual.
        """
        return ca.mtimes(ca.inv(self.R), (self.y() - self.h)) + \
             ca.mtimes(ca.inv(self.Q), self.w)


    def l_fn(self):
        """
        Stage cost:
        r - residual 
        R - measurement covariance
        w - noise
        Q - noise covariance

        l = r^T*R^-1*r + w^T*Q^-1*w
        """
        return ca.mtimes(ca.mtimes((self.y() - self.h).T, ca.inv(self.R)), (self.y() - self.h)) + \
               ca.mtimes(ca.mtimes(self.w.T, ca.inv(self.Q)), self.w)
        

class Mx(object):
    def __init__(self, name):
        """
        Consider making DAE rhs's
        SX, while keeping function-objs MX. 
        """
        self.mx = ca.MX()
        self._name = name
        self.disc = []
        self.mx0 = []
        self.min = []
        self.max = []


    def add(self, disc, *args, mx=None):

        if mx is None: # for t:
            self.mx = ca.vertcat(self.mx, ca.MX.sym(disc, 1, 1))
        else:
            self.mx = ca.vertcat(self.mx, mx)

        #self.mx = ca.vertcat(self.mx, ca.MX.sym(disc, 1, 1))
        self.disc.append(disc)

        if len(args) == 1:
            self.min.append(args[0])
            self.max.append(args[0])
            self.mx0.append(args[0])
        elif len(args) == 2:
            self.min.append(args[0])
            self.max.append(args[1])
            self.mx0.append((args[0]+args[1])/2)
        elif len(args) == 3:
            self.min.append(args[0])
            self.max.append(args[1])
            self.mx0.append(args[2])
        else:
            """
            Standard NLP shell should
            be unconstrained, hence
            set these to -inf and inf.
            """ 
            self.min.append(-np.inf)
            self.max.append(np.inf)

    def get(self, disc):
        return self.mx[self.disc.index(disc)]

    def var0(self):
        return self.mx0

    def var(self):
        return self.mx

    def name(self):
        return self._name

    def lb(self):
        return self.min

    def ub(self):
        return self.max

    def dim(self):
        return len(self.disc)

    def label(self):
        return self.disc

    # 'shortcut' for actual MX's:
    def __call__(self):
        return self.var()
