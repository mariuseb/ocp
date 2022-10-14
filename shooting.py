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
    def __init__(self, integrator, N, scale):
        """
        Entities for NLP.
        """
        self.F = integrator
        #self.Q = Q
        #self.R = R
        #self.U = U
        #self.Y = Y
        self.N = N 
        self.scale = scale
    
    @classmethod    
    def __subclasshook__(cls, subclass):
        return (
                hasattr(subclass, 'transcribe_nlp') 
                #and 
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
    
    def set_x_gaps(self, x_gaps):
        self.x_gaps = x_gaps
        
    def set_h_gaps(self, h_gaps):
        self.h_gaps = h_gaps

class MultipleShooting(Shooting):
    
    
    def transcribe_nlp(self):
        """ 
        Transcribe the nlp.
        """ 
        # some logic for stochasticity?
        x = self.get_x()
        w = self.get_w()
        v = self.get_v()
        y = self.get_y()
        u = self.get_u()
        z = self.get_z()
        r = self.get_r()
        # TODO: init p here instead (for TVP etc.):
        p = self.F.p
        
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
        
        xn = self.F_map(
                        x0=x,
                        z=z,
                        u=u,
                        p=self.scale*ca.repmat(p, 1, self.N),
                        w=w,
                        r=r
                        )["xf"]
        
        x_gaps = xn[:,:-1]-x[:,1:] 
        #x_gaps = xn - x[:,1:] 
        
        h_gaps = self.h_map(
                            y=y,
                            x=x,
                            z=z,
                            u=u,
                            #p=p,
                            p=self.scale*ca.repmat(p, 1, self.N),
                            v=v,
                            r=r
                            )["h"]
        
        g_gaps = self.g_map(
                            x=x,
                            z=z,
                            u=u,
                            #p=p,
                            p=self.scale*ca.repmat(p, 1, self.N),
                            v=v,
                            r=r
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
        return ca.MX.sym("y", self.n_y, self.N)
    
    def get_u(self):
        """ Process noise. """
        return ca.MX.sym("u", self.n_u, self.N)

    def get_z(self):
        """ Process noise. """
        return ca.MX.sym("z", self.n_z, self.N)
    
    def get_x(self):
        """ Process noise. """
        return ca.MX.sym("x", self.n_x, self.N)

    def get_r(self):
        """ Process noise. """
        return ca.MX.sym("r", self.n_r, self.N)
    
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