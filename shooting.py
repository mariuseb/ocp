from abc import ABC, abstractmethod, ABCMeta
import numpy as np
import casadi as ca
from pprint import pprint

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
        #self.w_nom = kwargs.pop("w_nom", 1E-3)
        self.w_nom = kwargs.pop("w_nom", 1/(self.x_nom*self.F.dt))
        self.v_nom = kwargs.pop("v_nom", 1/self.x_nom)
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
        """
        
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
        
    
class SingleShooting(object):
    pass