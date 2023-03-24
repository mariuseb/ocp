from abc import ABC, abstractmethod, ABCMeta
import numpy as np
import casadi as ca
from pprint import pprint

"""
TODO: common transcription class 
"""

class Shooting(metaclass=ABCMeta):
    """
    Abstract class for
    shooting methods.
    """
    #def __init__(self, integrator, U, Y, Q, R, N, scale):
    # Q and R should also be variable entities
    # for eventual sensitivity calculation.
    #def __init__(self, integrator, Q, R, N, scale):
    def __init__(self, integrator, N, **kwargs):
        """
        Entities for NLP.
        """
        self.F = integrator
        #self.Q = Q
        #self.R = R
        #self.U = U
        #self.Y = Y
        self.N = N 
        #self.scale = scale
        self.x_nom = kwargs.pop("x_nom")
        self.u_nom = kwargs.pop("u_nom")
        self.r_nom = kwargs.pop("r_nom")
        self.y_nom = kwargs.pop("y_nom")
        self.p_nom = kwargs.pop("p_nom")
        self.w_nom = kwargs.pop("w_nom")
        self.v_nom = kwargs.pop("v_nom")
        #self.w_nom = kwargs.pop("w_nom", 1E-3)
        #self.w_nom = kwargs.pop("w_nom", 1/(self.x_nom*self.F.dt))
        #self.v_nom = kwargs.pop("v_nom", 1/self.x_nom)
        #self.v_nom = kwargs.pop("p_nom", 1E-5)
        
        # TODO: x_nom, r_nom, y_nom, u_nom
    
    @classmethod    
    def __subclasshook__(cls, subclass):
        return (
                hasattr(subclass, 'transcribe_nlp') 
                #and                 if not mhe.solver.stats()["return_status"] == "Solve_Succeeded":

                #hasattr(subclass, 'get_one_sample') 
                and 
                callable(subclass.transcribe_nlp)
                )
        
    @property
    def n_x(self):
        return self.F.dae.n_x

    @property
    def n_y(self): 
        return self.F.dae.n_y

    @property
    def n_u(self):
        return self.F.dae.n_u

    @property
    def n_z(self):
        return self.F.dae.n_z

    @property
    def n_w(self):
        return self.F.dae.n_w

    @property
    def n_v(self):
        return self.F.dae.n_v

    @property
    def n_r(self):
        return self.F.dae.n_r

    @property
    def n_p(self):
        return len(self.F.dae.dae.p)

# TODO: pass in order as from dae.
class NLPParser(object):
    """
    Purpose:
        - keep track of variable indices 
          (after returning symbolic NLP)
            -> can use same code for sysid, mhe and mpc.
        - result extraction
    """
    def __init__(self, var_tuple: tuple):
        """
        Parameters:
            var_tuple: 
                tuple - expect order "x", "z", "u", "p", "w", "v", "y"
        """
        
        d = {}
        varnames = ("x", "z", "u", "p", "w", "v", "y", "r")
        #varnames = ("x", "z", "p", "w", "v")
        
        prev = 0
        for name, var in zip(varnames, var_tuple):
            
            dim = var.shape[0]*var.shape[1]           
            d[name] = {
                        "range":
                        {
                            "a": prev,
                            "b": prev + dim
                        },
                        "dim": dim
                      }
            prev += dim
            
        self.vars = d
        
    def __getitem__(self, k):
        return self.vars[k]
    
    def set_g(self, g):
        self.g = g
        
    def set_x_orig(self, x):
        self.x_orig = x
        
    def set_p_orig(self, p):
        self.p_orig = p
    
    def set_x_gaps(self, x_gaps):
        self.x_gaps = x_gaps
        
    def set_h_gaps(self, h_gaps):
        self.h_gaps = h_gaps

class MultipleShooting(Shooting):
    
    def __init__(self, *args, **kwargs):
        self.name = "MultipleShooting"
        super(MultipleShooting, self).__init__(*args, **kwargs)
    
    def transcribe_nlp(self):
        """ 
        Transcribe the nlp.
        """ 
        
        #self.x_nom = 300
        #self.u_nom = 5000
        #self.r_nom = 300
        #self.p_nom = self.scale
        
        x = self.get_x()
        w = self.get_w()
        v = self.get_v()
        y = self.get_y()
        u = self.get_u()
        z = self.get_z()
        r = self.get_r()
        # TODO: init p here instead (for TVP etc.):
        #p = self.F.p
        p = self.get_p()
        
        self.F_map = self.map_F()
        self.h_map = self.map_h()
        self.g_map = self.map_g()
        
        
        
        # if 1-D U:
        
        # NOTE: below should be handled better.
        
        #if u.shape[1] == 1:
        #    u = u.T      
        #if y.shape[0] != self.n_y:
        #    y = y.T
        
        ############## setting up constraints #############
        
        # hardcode scaling here:
        
        xn = self.F_map(
                        x0=x*self.x_nom,
                        z=z,
                        u=u*self.u_nom,
                        p=self.p_nom*ca.repmat(p, 1, self.N),
                        #p=ca.repmat(p, 1, self.N),
                        # w same unit as dT/dt -> factor: 1/300/900
                        w=w*self.w_nom,
                        r=r*self.r_nom
                        )["xf"]
        
        x_gaps = xn[:,:-1]-self.x_nom*x[:,1:] 
        #x_gaps = xn - x[:,1:] 
        
        h_gaps = self.h_map(
                            y=y*self.y_nom,
                            x=x*self.x_nom,
                            z=z,
                            u=u*self.u_nom,
                            #p=ca.repmat(p, 1, self.N),
                            p=self.p_nom*ca.repmat(p, 1, self.N),
                            #p=self.scale*ca.repmat(p, 1, self.N),
                            v=v*self.v_nom,
                            r=r*self.r_nom
                            )["h"]
        
        g_gaps = self.g_map(
                            x=x*self.x_nom,
                            z=z,
                            u=u*self.u_nom,
                            #p=ca.repmat(p, 1, self.N),
                            p=self.p_nom*ca.repmat(p, 1, self.N),
                            #p=self.scale*ca.repmat(p, 1, self.N),
                            v=v*self.v_nom,
                            r=r*self.r_nom
                            )["g"]
        
        ###################################################
        
        # constraints:
        g = ca.vertcat(ca.vec(x_gaps), ca.vec(g_gaps), ca.vec(h_gaps))
        
        """
        vars in same order as the system def:
        
            dx/dt = f(x, z, u, p, w)  (1)
            0 = g(x, z, u, p, w)      (2)
            y = h(x, p, v)            (3)
        
        """
        V = ca.veccat(x, z, u, p, w, v, y, r)
        
        nlp_parser = NLPParser((x, z, u, p, w, v, y, r))
        # keep orig g:
        nlp_parser.set_g(g)  
        nlp_parser.set_x_orig(x)  
        nlp_parser.set_p_orig(p)  
        
        """
        Gaps without noise, scaling for covariance estimation:
        
        xn = self.F_map(
                        x0=x,
                        z=z,
                        u=u,
                        p=ca.repmat(p, 1, self.N),
                        w=0,
                        r=r
                        )["xf"]
        
        x_gaps = xn[:,:-1]-x[:,1:] 
        
        h_gaps = self.h_map(
                            y=y,
                            x=x,
                            z=z,
                            u=u,
                            #p=p,
                            p=ca.repmat(p, 1, self.N),
                            v=0,
                            r=r
                            )["h"]
        """
        
        nlp_parser.set_x_gaps(x_gaps)
        nlp_parser.set_h_gaps(h_gaps)
        
        nlp = {
               'x': V,
               #'f': obj,
               'g': g
               #'p': nlp_p
               }
        
        return nlp, nlp_parser
    
    """
    def get_nlp_obj(self, v, w):
        #R_rep = ca.repmat(ca.inv(self.R), self.N, self.N)
        #Q_rep = ca.repmat(ca.inv(self.Q), self.N, self.N)
        
        # define Q, R here:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        
        Q_square_root = ca.sqrt(ca.inv(self.Q))
        R_square_root = ca.sqrt(ca.inv(self.R))
        
        
        return 0.5*ca.dot(ca.mtimes(R_square_root, v),
                          ca.mtimes(v.T, R_square_root).T) \
                + \
                0.5*ca.dot(ca.mtimes(Q_square_root, w),
                           ca.mtimes(w.T, Q_square_root).T), \
                ca.veccat(self.Q, self.R)
    """
    
    def get_v(self):
        """ Measurement noise. """
        return ca.MX.sym("v", self.n_v, self.N)
    
    def get_w(self):
        """ Process noise. """
        return ca.MX.sym("w", self.n_w, self.N)

    def get_y(self):
        """ Process noise. """
        #return ca.MX.sym("y", self.n_y, self.N)*self.x_nom
        return ca.MX.sym("y", self.n_y, self.N)
    
    def get_u(self):
        """ Process noise. """
        #return ca.MX.sym("u", self.n_u, self.N)*self.u_nom
        return ca.MX.sym("u", self.n_u, self.N)

    def get_z(self):
        """ Process noise. """
        return ca.MX.sym("z", self.n_z, self.N)
    
    def get_x(self):
        """ Process noise. """
        #return ca.MX.sym("x", self.n_x, self.N)*self.x_nom
        return ca.MX.sym("x", self.n_x, self.N)

    def get_r(self):
        """ Process noise. """
        #return ca.MX.sym("r", self.n_r, self.N)*self.r_nom
        return ca.MX.sym("r", self.n_r, self.N)
    
    def get_p(self):
        """ Parameters. """
        #return ca.MX.sym("p", self.n_p)*self.p_nom
        return self.F.p #*self.p_nom
    
    def map_F(self):
        return self.F.one_sample.map(self.N, "openmp")
        #return self.F.one_sample.map(self.N)
    
    def map_h(self):
        """ Paralell map of measurement eqs """
        return self.F.h.map(self.N, "openmp")
        #return self.F.h.map(self.N)
    
    def map_g(self):
        """ Paralell map of algebraic eqs """
        return self.F.g.map(self.N, "openmp")
        #return self.F.g.map(self.N)
        
    
# TODO: fix
class SingleShooting(Shooting):
    
    def __init__(self, *args, **kwargs):
        self.name = "SingleShooting"
        super(SingleShooting, self).__init__(*args, **kwargs)
    
    def transcribe_nlp(self):
        """ 
        Transcribe the nlp.
        """ 
        
        #self.x_nom = 300
        #self.u_nom = 5000
        #self.r_nom = 300
        #self.p_nom = self.scale
        
        x = self.get_x()
        w = self.get_w()
        v = self.get_v()
        y = self.get_y()
        u = self.get_u()
        z = self.get_z()
        r = self.get_r()
        # TODO: init p here instead (for TVP etc.):
        #p = self.F.p
        p = self.get_p()
        
        # unsure if single shooting is amenable to map:    
        #self.F_map = self.map_F()
        #self.h_map = self.map_h()
        #self.g_map = self.map_g()
        
        
        
        # if 1-D U:
        
        # NOTE: below should be handled better.
        
        #if u.shape[1] == 1:
        #    u = u.T      
        #if y.shape[0] != self.n_y:
        #    y = y.T
        
        ############## setting up constraints #############
        
        """
        propagate system one time-step with slice of u
        use result, "xf", for next time-step.
        
        NOTE: z needs to be handled separately,
        and outside of single-shooting integrator.
        """

        g = []
        Xk = x
        for n in range(self.N-1):
            Uk = u[:,n:(n+self.n_u)]
            Rk = r[:,n:(n+self.n_r)]
            # integrate
            Fk = self.F.one_sample(x0=Xk*self.x_nom,
                                    z=0, 
                                    u=Uk*self.u_nom,
                                    p=self.p_nom*p,
                                    w=w*self.w_nom,
                                    r=Rk*self.r_nom)
            Xk = Fk["xf"]/self.x_nom
            # add expression for state at integration end:
            g.append(Xk)
            
        for n in range(self.N-1):
            Uk = u[:,n:(n+self.n_u)]
            Rk = r[:,n:(n+self.n_r)]
            Hk = self.F.h(
                        y=y*self.y_nom,
                        x=x*self.x_nom,
                        z=z,
                        u=Uk*self.u_nom,
                        p=self.p_nom*p,
                        v=v*self.v_nom,
                        r=Rk*self.r_nom
                        )["h"]        
            g.append(Hk)
         
        #print(Xk)
                    
    
        
        
        """
        xn = self.F_map(
                        x0=x*self.x_nom,
                        z=z,
                        u=u*self.u_nom,
                        p=self.p_nom*ca.repmat(p, 1, self.N),
                        #p=ca.repmat(p, 1, self.N),
                        # w same unit as dT/dt -> factor: 1/300/900
                        w=w*self.w_nom,
                        r=r*self.r_nom
                        )["xf"]
        
        #x_gaps = xn[:,:-1]-self.x_nom*x[:,1:] 
        #x_gaps = xn - x[:,1:] 
        h_gaps = self.h_map(
                            y=y*self.y_nom,
                            x=x*self.x_nom,
                            z=z,
                            u=u*self.u_nom,
                            #p=ca.repmat(p, 1, self.N),
                            p=self.p_nom*ca.repmat(p, 1, self.N),
                            #p=self.scale*ca.repmat(p, 1, self.N),
                            v=v*self.v_nom,
                            r=r*self.r_nom
                            )["h"]
        
        g_gaps = self.g_map(
                            x=x*self.x_nom,
                            z=z,
                            u=u*self.u_nom,
                            #p=ca.repmat(p, 1, self.N),
                            p=self.p_nom*ca.repmat(p, 1, self.N),
                            #p=self.scale*ca.repmat(p, 1, self.N),
                            v=v*self.v_nom,
                            r=r*self.r_nom
                            )["g"]
        """    
        ###################################################
        
        # constraints:
        #g = ca.vertcat(*g)
        g = ca.veccat(*g)
        
        """
        vars in same order as the system def:
        
            dx/dt = f(x, z, u, p, w)  (1)
            0 = g(x, z, u, p, w)      (2)
            y = h(x, p, v)            (3)
        
        """
        V = ca.veccat(x, z, u, p, w, v, y, r)
        
        nlp_parser = NLPParser((x, z, u, p, w, v, y, r))
        # keep orig g:
        nlp_parser.set_g(g)  
        nlp_parser.set_x_orig(x)  
        nlp_parser.set_p_orig(p)  
        
        """
        Gaps without noise, scaling for covariance estimation:
        
        xn = self.F_map(
                        x0=x,
                        z=z,
                        u=u,
                        p=ca.repmat(p, 1, self.N),
                        w=0,
                        r=r
                        )["xf"]
        
        x_gaps = xn[:,:-1]-x[:,1:] 
        
        h_gaps = self.h_map(
                            y=y,
                            x=x,
                            z=z,
                            u=u,
                            #p=p,
                            p=ca.repmat(p, 1, self.N),
                            v=0,
                            r=r
                            )["h"]
        """
        
        #nlp_parser.set_x_gaps(x_gaps)
        #nlp_parser.set_h_gaps(h_gaps)
        
        nlp_parser.x_bounds_g = (0,self.N)
        
        nlp = {
               'x': V,
               #'f': obj,
               'g': g
               #'p': nlp_p
               }
        
        return nlp, nlp_parser
    
    """
    def get_nlp_obj(self, v, w):
        #R_rep = ca.repmat(ca.inv(self.R), self.N, self.N)
        #Q_rep = ca.repmat(ca.inv(self.Q), self.N, self.N)
        
        # define Q, R here:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        
        Q_square_root = ca.sqrt(ca.inv(self.Q))
        R_square_root = ca.sqrt(ca.inv(self.R))
        
        
        return 0.5*ca.dot(ca.mtimes(R_square_root, v),
                          ca.mtimes(v.T, R_square_root).T) \
                + \
                0.5*ca.dot(ca.mtimes(Q_square_root, w),
                           ca.mtimes(w.T, Q_square_root).T), \
                ca.veccat(self.Q, self.R)
    """
    
    def get_v(self):
        """ Measurement noise. """
        return ca.MX.sym("v", self.n_v, self.N)
    
    def get_w(self):
        """ Process noise. """
        return ca.MX.sym("w", self.n_w, self.N)

    def get_y(self):
        """ Process noise. """
        #return ca.MX.sym("y", self.n_y, self.N)*self.x_nom
        return ca.MX.sym("y", self.n_y, self.N)
    
    def get_u(self):
        """ Process noise. """
        #return ca.MX.sym("u", self.n_u, self.N)*self.u_nom
        return ca.MX.sym("u", self.n_u, self.N)

    def get_z(self):
        """ Process noise. """
        return ca.MX.sym("z", self.n_z, 1)
    
    def get_x(self):
        """ Process noise. """
        #return ca.MX.sym("x", self.n_x, self.N)*self.x_nom
        return ca.MX.sym("x", self.n_x, 1)

    def get_r(self):
        """ Process noise. """
        #return ca.MX.sym("r", self.n_r, self.N)*self.r_nom
        return ca.MX.sym("r", self.n_r, self.N)
    
    def get_p(self):
        """ Parameters. """
        #return ca.MX.sym("p", self.n_p)*self.p_nom
        return self.F.p #*self.p_nom
    
    def map_F(self):
        return self.F.one_sample.map(self.N, "openmp")
        #return self.F.one_sample.map(self.N)
    
    def map_h(self):
        """ Paralell map of measurement eqs """
        return self.F.h.map(self.N, "openmp")
        #return self.F.h.map(self.N)
    
    def map_g(self):
        """ Paralell map of algebraic eqs """
        return self.F.g.map(self.N, "openmp")
        #return self.F.g.map(self.N)
        
        
class Collocation(Shooting):
    
    def __init__(self, *args, **kwargs):
        self.name = "Collocation"
        super(Collocation, self).__init__(*args, **kwargs)
        self.method = self.F.method
    
    """
    def __init__(self, N, **kwargs):
        self.N = N 
        #self.scale = scale
        self.h = kwargs.pop("dt")
        self.d = kwargs.pop("degree")
        self.dae = kwargs.pop("dae")
        # expressions:
        self.ode = ca.vertcat(*self.dae.dae.ode)
        self.f = ca.Function('f',
                    [self.dae.x,
                     self.dae.z,
                     self.dae.u,
                     self.dae.p,
                     self.dae.w,
                     self.dae.r],
                    [self.ode],
                    ["x", "z", "u", "p", "w", "r"],
                    ["f"])
        # h, g (enforce at only at finite elements)
        self.x_nom = kwargs.pop("x_nom")
        self.u_nom = kwargs.pop("u_nom")
        self.r_nom = kwargs.pop("r_nom")
        self.y_nom = kwargs.pop("y_nom")
        self.p_nom = kwargs.pop("p_nom")
        self.w_nom = kwargs.pop("w_nom")
        self.v_nom = kwargs.pop("v_nom")
        #self.w_nom = kwargs.pop("w_nom", 1E-3)
        #self.w_nom = kwargs.pop("w_nom", 1/(self.x_nom*self.F.dt))
        #self.v_nom = kwargs.pop("v_nom", 1/self.x_nom)
        #self.v_nom = kwargs.pop("p_nom", 1E-5)
    """
     
    def transcribe_nlp(self):
        """ 
        Transcribe the nlp.
        """ 
        
        #self.x_nom = 300
        #self.u_nom = 5000
        #self.r_nom = 300
        #self.p_nom = self.scale
        d = self.d = self.F.d
        h = self.h = self.F.dt
        B, C, D = self.get_coll_coeffs(d, self.method)
        
        x = []
        z = []
        u = []
        p = []
        w = []
        r = []
        v = []
        y = []
        xb = []
        x_gaps = []
        h_gaps = []
        
        x_nom = self.x_nom 
        u_nom = self.u_nom 
        p_nom = self.p_nom 
        r_nom = self.r_nom 
        w_nom = self.w_nom 
        y_nom = self.y_nom 
        v_nom = self.v_nom 
        
        n_x = self.n_x
        n_z = self.n_z
        n_u = self.n_u
        n_p = self.n_p
        n_w = self.n_w
        n_r = self.n_r
        n_v = self.n_v
        n_y = self.n_y
        #x_nom = self.x_nom 
        
        #w0 = []
        #lbw = []
        #ubw = []
        g = []
        #lbg = []
        #ubg = []
        J = 0

        # For plotting x and u given w
        #x_plot = []
        #u_plot = []


        # Perturb with P, parameters
        #P = ca.MX.sym('P', n_p)
        P = self.F.p
        #p = p + P

        #p_val = 1

        #x_nom = np.array([300])
        #u_nom = np.array([5000, 300])
        #p_nom = np.array([1e6, 1e-2])
        #phi_h_nom = u_nom[1]


        #lb_phi_h = np.zeros((24,1))
        #ub_phi_h = np.ones((24,1))*5000


        #lbu = np.hstack((lb_phi_h, u_vals))/u_nom
        #ubu = np.hstack((ub_phi_h, u_vals))/u_nom
        #lbu = np.hstack((lb_phi_h, u_vals))
        #ubu = np.hstack((ub_phi_h, u_vals))

        #lbx = lbx/x_nom
        #ubx = ubx/x_nom
        #lbx = lbx
        #ubx = ubx

        # "Lift" initial conditions
        X0 = Xk = ca.MX.sym('X0', n_x)
        # X0 as parameter:
        x.append(Xk)
        #lbw.append([0, 1])
        #ubw.append([0, 1])
        #w0.append([0, 1])
        #lbw.append([lbx[0]])
        #ubw.append([ubx[0]])
        #w0.append([lbx[0]])
        #x_plot.append(Xk)

        # Formulate the NLP
        for k in range(self.N-1):

            # New NLP variable for the control
            Uk = ca.MX.sym('U_' + str(k), n_u)
            Rk = ca.MX.sym('R_' + str(k), n_r)
            Wk = ca.MX.sym('W_' + str(k), n_w)
            u.append(Uk)
            r.append(Rk)
            w.append(Wk)
            #lbw.append([-1])
            #ubw.append([.85])
            #w0.append(s[0])
            #lbw.append([0, float(u_vals[k])])
            #ubw.append([5000, float(u_vals[k])])
            #w0.append([0, float(u_vals[k])])
            #lbw.append(lbu[k])
            #ubw.append(ubu[k])
            #w0.append(lbu[k])
            #u_plot.append(Uk)

            # State at collocation points
            Xc = []
            for j in range(d):
                Xkj = ca.MX.sym('X_'+str(k)+'_'+str(j), n_x)
                Xc.append(Xkj)
                x.append(Xkj)
                #lbw.append([-0.25, -np.inf])
                #ubw.append([np.inf,  np.inf])
                #w0.append([0, 0])
                #lbw.append([lbx[k+1]])
                #ubw.append([ubx[k+1]])
                #w0.append([lbx[k+1]])

            # Loop over collocation points
            Xk_end = D[0]*Xk
            for j in range(1,d+1):
                # Expression for the state derivative at the collocation point
                xp = C[0,j]*Xk
                for i in range(d): xp = xp + C[i+1,j]*Xc[i]

                # Append collocation equations
                #fj, qj = f(Xc[j-1]*x_nom, P*p_nom, Uk*u_nom)
                fj = self.f(Xc[j-1]*x_nom, 0, Uk*u_nom, P*p_nom, Wk*w_nom, Rk*r_nom)
                #fj = self.f(Xc[j-1]*x_nom, 0, Uk*u_nom, P*p_nom, Wk, Rk*r_nom)
                g.append(h*fj - xp*x_nom)
                #lbg.append([0, 0])
                #ubg.append([0, 0])
                #lbg.append([0])
                #ubg.append([0])

                # Add contribution to the end state
                Xk_end = Xk_end + D[j]*Xc[j-1];

                # Add contribution to quadrature function
                # TODO: modularize
                #J = J + B[j]*qj*h/(u_nom[0]**3)
                #J = J + B[j]*qj*h
            # can take simple quadrature?
            #J = J + Uk[0]**2

            # measurement equation, if exists
            Vk = ca.MX.sym('V_' + str(k), n_v)
            Yk = ca.MX.sym('Y_' + str(k), n_y)
            v.append(Vk)
            y.append(Yk)
            
            g.append(self.F.h(Yk*y_nom, Xk*x_nom, 0, 0, 0, Vk*v_nom, 0))
            #g.append(self.F.h(Yk*y_nom, Xk*x_nom, 0, 0, 0, Vk, 0))
            h_gaps.append(g[-1])
            


            # New NLP variable for state at end of interval
            Xk = ca.MX.sym('X_' + str(k+1), n_x)
            x.append(Xk)
            xb.append(Xk)
            #lbw.append([lbx[k+1]])
            #ubw.append([ubx[k+1]])
            #w0.append([lbx[k+1]])
            #x_plot.append(Xk)

            # Add equality constraint
            #g.append(Xk_end - Xk)
            g.append(x_nom*Xk_end - x_nom*Xk)
            x_gaps.append(g[-1])
            #lbg.append([0, 0])
            #ubg.append([0, 0])
            #lbg.append([0])
            #ubg.append([0])

        Yk = ca.MX.sym('Y_' + str(k+1), n_y)
        Vk = ca.MX.sym('V_' + str(k+1), n_v)
        v.append(Vk)
        y.append(Yk)
        # add last measurement equation
        g.append(self.F.h(Yk*y_nom, Xk*x_nom, 0, 0, 0, Vk*v_nom, 0))
        #g.append(self.F.h(Yk*y_nom, Xk*x_nom, 0, 0, 0, Vk, 0))
        h_gaps.append(g[-1])

        # Concatenate vectors
        x = ca.vertcat(*x)
        z = ca.vertcat(*z)
        u = ca.vertcat(*u)
        # p?
        p = ca.vertcat(*p)
        w = ca.vertcat(*w)
        r = ca.vertcat(*r)
        v = ca.vertcat(*v)
        y = ca.vertcat(*y)
        
        #V = ca.veccat(x,z,u,p,w,r)
        
        #x_plot = ca.horzcat(*x_plot)
        #u_plot = ca.horzcat(*u_plot)
        #w0 = np.concatenate(w0)
        #lbw = np.concatenate(lbw)
        #ubw = np.concatenate(ubw)
        #lbg = np.concatenate(lbg)
        #ubg = np.concatenate(ubg)

        # Create an NLP solver
        #prob = {'f': J, 'x': V, 'g': g, 'p': P}

            
        #g = ca.veccat(*g)
        
        """
        vars in same order as the system def:
        
            dx/dt = f(x, z, u, p, w)  (1)
            0 = g(x, z, u, p, w)      (2)
            y = h(x, p, v)            (3)
        
        """
        g = ca.vertcat(*g)
        #V = ca.veccat(x, z, u, p, w, v, y, r)
        V = ca.veccat(x, z, u, P, w, v, y, r)
        
        #nlp_parser = NLPParser((x, z, u, p, w, v, y, r))
        nlp_parser = NLPParser((x, z, u, P, w, v, y, r))
        
        # set inds for boundary points:
        nlp_parser.vars["x"]["boundary_vars"] = ca.vertcat(*xb)
        
        nlp_parser.set_x_gaps(ca.vertcat(*x_gaps))
        nlp_parser.set_h_gaps(ca.vertcat(*h_gaps))
        
        # keep orig g:
        nlp_parser.set_g(g)  
        nlp_parser.set_x_orig(x)  
        nlp_parser.set_p_orig(p)  
        
        
        #nlp_parser.x_bounds_g = (0,self.N)
        
        nlp = {
               'x': V,
               #'f': J,
               'g': g
        #       'p': ca.vertcat(X0, P)
               #'p': nlp_p
               }
        
        return nlp, nlp_parser
    
    @property
    def f(self):
        return self.F.f 
    
    def get_v(self):
        """ Measurement noise. """
        return ca.MX.sym("v", self.n_v, self.N)
    
    def get_w(self):
        """ Process noise. """
        return ca.MX.sym("w", self.n_w, self.N)

    def get_y(self):
        """ Measurements. """
        #return ca.MX.sym("y", self.n_y, self.N)*self.x_nom
        return ca.MX.sym("y", self.n_y, self.N)
    
    def get_u(self):
        """ Process noise. """
        #return ca.MX.sym("u", self.n_u, self.N)*self.u_nom
        return ca.MX.sym("u", self.n_u, self.N)

    # TODO: fix algebraic equations?? See Biegler
    def get_z(self):
        """ Process noise. """
        return ca.MX.sym("z", self.n_z, 1)
    
    def get_x(self):
        """ Process noise. """
        #return ca.MX.sym("x", self.n_x, self.N)*self.x_nom
        return ca.MX.sym("x", self.n_x, (self.N-1)*(self.d+1)+1)
        # TODO: times n_steps as well

    def get_r(self):
        """ Process noise. """
        #return ca.MX.sym("r", self.n_r, self.N)*self.r_nom
        return ca.MX.sym("r", self.n_r, self.N)
    
    def get_p(self):
        """ Parameters. """
        #return ca.MX.sym("p", self.n_p)*self.p_nom
        return self.F.p #*self.p_nom
        #return self.dae.dae.p
    

#    def map_F(self):
#        return self.F.one_sample.map(self.N, "openmp")
#        #return self.F.one_sample.map(self.N)
    
#    def map_h(self):
#        """ Paralell map of measurement eqs """
#        return self.F.h.map(self.N, "openmp")
#        #return self.F.h.map(self.N)
    
#    def map_g(self):
#        """ Paralell map of algebraic eqs """
#        return self.F.g.map(self.N, "openmp")
#        #return self.F.g.map(self.N)


    @staticmethod
    def get_coll_coeffs(d, method):
        tau_root = np.append(0, ca.collocation_points(d, method))
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
            
        return B, C, D

           
    """
    @property
    def n_x(self):
        return self.dae.n_x

    @property
    def n_y(self): 
        return self.dae.n_y

    @property
    def n_u(self):
        return self.dae.n_u

    @property
    def n_z(self):
        return self.dae.n_z

    @property
    def n_w(self):
        return self.dae.n_w

    @property
    def n_v(self):
        return self.dae.n_v

    @property
    def n_r(self):
        return self.dae.n_r
    
    def transcribe_nlp(self):
        
        #self.x_nom = 300
        #self.u_nom = 5000
        #self.r_nom = 300
        #self.p_nom = self.scale
        d = self.d = self.F.d
        h = self.h = self.F.dt
        B, C, D = self.get_coll_coeffs(d, self.method)
        
        
        x = self.get_x()
        w = self.get_w()
        v = self.get_v()
        y = self.get_y()
        u = self.get_u()
        z = self.get_z()
        r = self.get_r()
        # TODO: init p here instead (for TVP etc.):
        #p = self.F.p
        p = self.get_p()
        
        # unsure if single shooting is amenable to map:    
        #self.F_map = self.map_F()
        #self.h_map = self.map_h()
        #self.g_map = self.map_g()
        
        
        
        # if 1-D U:
        
        # NOTE: below should be handled better.
        
        #if u.shape[1] == 1:
        #    u = u.T      
        #if y.shape[0] != self.n_y:
        #    y = y.T
        
        ############## Transcribe NLP #############
        g = []
        Xk = x[:,0]
        for k in range(self.N-1):
            # New NLP variable for the control
            #Uk = ca.MX.sym('U_' + str(k))
            Uk = u[:,k:(k+self.n_u)]
            try:
                Zk = z[:,k:(k+self.n_z)]
            except:
                Zk = Zk
            
            Rk = r[:,k:(k+self.n_r)]
            try:
                Wk = w[:,k:(k+self.n_w)]
            except:
                Wk = Wk
            try:
                Yk = y[:,k:(k+self.n_y)]
            except:
                Yk = Yk
            try:
                Vk = v[:,k:(k+self.n_v)]
            except:
                Vk = Vk
            #w.append(Uk)
            #lbw.append([-1])
            #ubw.append([1])
            #w0.append([0])
            #u_plot.append(Uk)

            # State at collocation points
            Xc = []
            for j in range(1,d+1):
                #Xkj = ca.MX.sym('X_'+str(k)+'_'+str(j), 2)
                Xkj = x[:,k+j:(k+j+1)]
                Xc.append(Xkj)
                #w.append(Xkj)
                #lbw.append([-0.25, -np.inf])
                #ubw.append([np.inf,  np.inf])
                #w0.append([0, 0])

            # Loop over collocation points
            Xk_end = D[0]*Xk
            for j in range(1,d+1):
                # Expression for the state derivative at the collocation point
                xp = C[0,j]*Xk
                for i in range(d): xp = xp + C[i+1,j]*Xc[i]

                # Append collocation equations
                #fj, qj = self.f(Xc[j-1],Uk)
                fj = self.f(Xc[j-1],Zk,Uk,p,Wk,Rk)
                g.append(h*fj - xp)
                #lbg.append([0, 0])
                #ubg.append([0, 0])

                # Add contribution to the end state
                Xk_end = Xk_end + D[j]*Xc[j-1];

            # Add contribution to quadrature function
            # TODO: how to handle quadrature at later stage.
            #J = J + B[j]*qj*h

            # New NLP variable for state at end of interval
            #Xk = ca.MX.sym('X_' + str(k+1), 2)
            Xk = x[:,(k+1)*(d+1)]
            #w.append(Xk)
            #lbw.append([-0.25, -np.inf])
            #ubw.append([np.inf,  np.inf])
            #w0.append([0, 0])
            #x_plot.append(Xk)

            # Add equality constraint
            g.append(Xk_end-Xk)
            #lbg.append([0, 0])
            #ubg.append([0, 0])
            
        g = ca.veccat(*g)
        
        V = ca.veccat(x, z, u, p, w, v, y, r)
        
        nlp_parser = NLPParser((x, z, u, p, w, v, y, r))
        # keep orig g:
        nlp_parser.set_g(g)  
        nlp_parser.set_x_orig(x)  
        nlp_parser.set_p_orig(p)  
        
        
        #nlp_parser.x_bounds_g = (0,self.N)
        
        nlp = {
               'x': V,
               #'f': obj,
               'g': g
               #'p': nlp_p
               }
        
        return nlp, nlp_parser
    """