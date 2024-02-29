from abc import ABC, abstractmethod, ABCMeta
import numpy as np
import casadi as ca
from pprint import pprint
from ocp.integrators import idas, Cvodes

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
        self.map_eval = kwargs.pop("map_eval", True)
        #self.Q = Q
        #self.R = R
        #self.U = U
        #self.Y = Y
        self.N = N 
        #self.scale = scale
        self.x_nom = kwargs.pop("x_nom", 1)
        self.x_nom_b = kwargs.pop("x_nom_b", 0)
        self.z_nom = kwargs.pop("z_nom", 1)
        self.z_nom_b = kwargs.pop("z_nom_b", 0)
        self.u_nom = kwargs.pop("u_nom", 1)
        self.u_nom_b = kwargs.pop("u_nom_b", 0)
        self.r_nom = kwargs.pop("r_nom", 1)
        self.r_nom_b = kwargs.pop("r_nom_b", 0)
        self.y_nom = kwargs.pop("y_nom", 1)
        self.y_nom_b = kwargs.pop("y_nom_b", 0)
        self.p_nom = kwargs.pop("p_nom", 1)
        self.p_nom_b = kwargs.pop("p_nom_b", 0)
        #self.w_nom = kwargs.pop("w_nom", 1)
        self.s_nom = kwargs.pop("s_nom", 1)
        self.v_nom = kwargs.pop("v_nom", 1)
        self.v_nom_b = kwargs.pop("v_nom_b", 0)
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
        return self.F.dae.n_w # - self.F.dae.n_v - self.F.dae.n_s
    
    @property
    def n_s(self):
        return self.F.dae.n_s

    @property
    def n_v(self):
        return self.F.dae.n_v

    @property
    def n_r(self):
        return self.F.dae.n_r

    @property
    def n_p(self):
        return len(self.F.dae.dae.p())

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
                tuple - expect order "x", "z", "u", "p", "s", "v", "y", "r", "w"
        """
        
        d = {}
        varnames = ("x", "z", "u", "p", "v", "y", "r", "w")
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
        #g_shooting = []
        x = self.get_x()
        v = self.get_v()
        y = self.get_y()
        u = self.get_u()
        z = self.get_z()
        r = self.get_r()
        # TODO: init p here instead (for TVP etc.):
        #p = self.F.p
        p = self.get_p()
        w = self.get_w()
        
        # TODO: refactor
        #if isinstance(self.F, (idas, Cvodes)):
        if not self.map_eval:
            """
            res = self.F_map(
                            x0=x[:,:-1]*self.x_nom,
                            z0=z[:,:-1]*self.z_nom,
                            u=u*self.u_nom,
                            p=ca.vertcat(self.p_nom*ca.repmat(p, 1, self.N-1), r*self.r_nom),
                            )
            """
            #X = x[:,0]
            #Z = z[:,0]
            x_gaps = []
            g_gaps = ca.MX()
            
            if isinstance(self.F, (idas, Cvodes)):
                for n in range(self.N-1):
                    X = x[:,n+1]
                    Z = z[:,n+1]
                    # TODO: this must conform for all integrators
                    Fk = self.F.one_sample(x0=x[:,n]*self.x_nom + self.x_nom_b,
                                           z0=z[:,n]*self.z_nom + self.z_nom_b, 
                                           u=u[:,n]*self.u_nom + self.u_nom_b,
                                           p=ca.vertcat(self.p_nom*p, self.r_nom*r[:,n] + self.r_nom_b)
                                           )
                    Xk = Fk["xf"]
                    #Zk = Fk["zf"]/self.z_nom
                    x_gaps.append(Xk - (X*self.x_nom + self.x_nom_b))
            else:
                for n in range(self.N-1):
                    X = x[:,n+1]
                    Z = z[:,n+1]
                    Fk = self.F.one_sample(x0=x[:,n]*self.x_nom,
                                            z=z[:,n]*self.z_nom,
                                            u=u[:,n]*self.u_nom,
                                            p=self.p_nom*p,
                                            r=r[:,n]*self.r_nom)
                                            #s=s[:,n]*self.s_nom,
                    Xk = Fk["xf"]
                    #Xk = Fk["xf"]/self.x_nom
                    #Zk = Fk["zf"]
                    #x_gaps.append(Xk - X)
                    x_gaps.append(Xk - (X*self.x_nom + self.x_nom_b))
                
                    #g_gaps.append(Fk["zf"] - Z)
            #xn = res["xf"]
            #zn = res["zf"]
            x_gaps = ca.vertcat(*x_gaps)
        else:
            assert not isinstance(self.F, (idas, Cvodes))
            
            self.F_map = self.map_F()
            xn = self.F_map(
                            x0=x[:,:-1]*self.x_nom + self.x_nom_b,
                            z=z[:,:-1]*self.z_nom + self.z_nom_b,
                            u=u*self.u_nom + self.u_nom_b,
                            p=self.p_nom*ca.repmat(p, 1, self.N-1) + self.p_nom_b,
                            r=r[:,:-1]*self.r_nom + self.r_nom_b
                            #s=s[:,:-1]*self.s_nom,
                            #w=w[:,:-1]
                            )["xf"]
            xn_orig = self.F_map(
                                x0=x[:,:-1],
                                z=z[:,:-1],
                                u=u,
                                p=ca.repmat(p, 1, self.N-1),
                                r=r[:,:-1]
                                #s=s[:,:-1],
                                #w=w[:,:-1]
                                )["xf"]
            x_gaps = xn - (self.x_nom*x[:,1:] + self.x_nom_b)
            x_gaps_orig = xn_orig - x[:,1:]
            #x_gaps = xn - self.x_nom*x[:,1:]
        #x_gaps = xn[:,:-1]-self.x_nom*x[:,1:] 
        #x_gaps = xn[:,:-1] - (self.x_nom*x[:,1:]) # + self.x_nom_b)
        #x_gaps = xn - (self.x_nom*x[:,1:]) # + self.x_nom_b)
        # TODO: skip this for built-in integrators, e.g. IDAS 
        # h and g will hold if passed as algebraic equations
        
        # h must be present:
        self.h_map = self.map_h()
        # g is optional: 
        try:
            self.g_map = self.map_g()
            #self.w_map = self.map_wdef()
        except AttributeError:
            pass
        #self.G_map = self.map_G()
        
        
        
        # if 1-D U:
        
        # NOTE: below should be handled better.
        
        #if u.shape[1] == 1:
        #    u = u.T      
        #if y.shape[0] != self.n_y:
        #    y = y.T
        
        ############## setting up constraints #############
        
        # hardcode scaling here:
        
        try:
            h_gaps = self.h_map(
                                #y=y*self.y_nom + self.y_nom_b,
                                #x=x*self.x_nom + self.x_nom_b,
                                y=y*self.y_nom + self.y_nom_b,
                                x=x*self.x_nom + self.x_nom_b,
                                z=z*self.z_nom + self.z_nom_b,
                                u=u*self.u_nom + self.u_nom_b,
                                p=self.p_nom*ca.repmat(p, 1, self.N),
                                v=v*self.v_nom + self.v_nom_b,
                                r=r*self.r_nom + self.r_nom_b,
                                )["h"]
            h_gaps_orig = self.h_map(
                                    y=y,
                                    x=x,
                                    z=z,
                                    u=u,
                                    p=ca.repmat(p, 1, self.N),
                                    v=v,
                                    r=r
                                    )["h"]
        except (AttributeError, RuntimeError):
            h_gaps = ca.MX()
        try:
            """
            Discrete-time, difference equation defines w,
            i.e. w == wdef(w_prev,x,z,u,p,t).
            
            Propagate w forward, take difference with shifted
            variable.
            """
            
            wn = self.w_map(
                            #y=y*self.y_nom + self.y_nom_b,
                            #x=x*self.x_nom + self.x_nom_b,
                            y=y[:,:-1]*self.y_nom + self.y_nom_b,
                            x=x[:,:-1]*self.x_nom + self.x_nom_b,
                            z=z[:,:-1]*self.z_nom + self.z_nom_b,
                            u=u[:,:-1]*self.u_nom + self.u_nom_b,
                            p=self.p_nom*ca.repmat(p, 1, self.N-1),
                            v=v[:,:-1]*self.v_nom + self.v_nom_b,
                            r=r[:,:-1]*self.r_nom + self.r_nom_b,
                            w=w[:,:-1]
                            )["wdef"]
            w_gaps = wn - w[:,1:]
        except AttributeError:
            w_gaps = ca.MX()
            
        #G_p = ca.vertcat(x*self.x_nom, u*self.u_nom, p*self.p_nom, v*self.v_nom, r*self.r_nom)
        #G_p = ca.vertcat(x*self.x_nom, u*self.u_nom, p*self.p_nom, v*self.v_nom, r*self.r_nom)
    
        #p_for_G = self.p_nom*ca.repmat(p, 1, self.N)
        #G_p = ca.vertcat(x, u, p_for_G)
        
        """
        g_gaps = self.G_map(x0=z*self.z_nom, p=G_p)["x"]
        """
        try:
            g_gaps = self.g_map(
                                x=x*self.x_nom + self.x_nom_b,
                                z=z*self.z_nom + self.z_nom_b,
                                u=u*self.u_nom + self.u_nom_b,
                                p=self.p_nom*ca.repmat(p, 1, self.N),
                                r=r*self.r_nom + self.r_nom_b
                                #x=x[:,:-1]*self.x_nom,
                                #z=z[:,:-1]*self.z_nom,
                                #u=u[:,:-1]*self.u_nom,
                                #p=ca.repmat(p, 1, self.N),
                                #p=self.p_nom*ca.repmat(p, 1, self.N),
                                #v=v*self.v_nom,
                                #s=s*self.s_nom,
                                #r=r[:,:-1]*self.r_nom
                                #w=w
                                #r=0
                                )["g"]
        except (AttributeError, RuntimeError):
            #g_gaps = zn - z[:,1:]  
            g_gaps = ca.MX()
            #pass
        ###################################################
        
        # constraints:
        g = ca.vertcat(ca.vec(x_gaps), ca.vec(g_gaps), ca.vec(h_gaps), ca.vec(w_gaps))
        
        """
        vars in same order as the system def:
        
            dx/dt = f(x, z, u, p, s)  (1)
            0 = g(x, z, u, p, s)      (2)
            y = h(x, p, v)            (3)
        
        """
        #V = ca.veccat(x, z, u, p, w, v, y, r)
        V = ca.veccat(x, z, u, p, v, y, r, w)
        
        #nlp_parser = NLPParser((x, z, u, p, w, v, y, r))
        nlp_parser = NLPParser((x, z, u, p, v, y, r, w))
        # keep orig g:
        nlp_parser.set_g(g)  
        nlp_parser.set_x_orig(x)  
        nlp_parser.set_p_orig(p)  
        nlp_parser.vars["x"]["shooting_gaps"] = x_gaps.T
        
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
        
        #nlp_parser.set_x_gaps(x_gaps_orig)
        #nlp_parser.set_h_gaps(h_gaps_orig)
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
        """ Dep vars. """
        #return ca.MX.sym("w", self.n_w, self.N-1)
        return ca.MX.sym("w", self.n_w, self.N)

    def get_y(self):
        """ Measurements. """
        #return ca.MX.sym("y", self.n_y, self.N)*self.x_nom
        return ca.MX.sym("y", self.n_y, self.N)
    
    def get_u(self):
        """ Controllable inputs. """
        #return ca.MX.sym("u", self.n_u, self.N)*self.u_nom
        #return ca.MX.sym("u", self.n_u, self.N-1)
        return ca.MX.sym("u", self.n_u, self.N-1)

    def get_z(self):
        """ Alg vars. """
        return ca.MX.sym("z", self.n_z, self.N)
    
    def get_x(self):
        """ State vars. """
        #return ca.MX.sym("x", self.n_x, self.N)*self.x_nom
        return ca.MX.sym("x", self.n_x, self.N)

    def get_r(self):
        """ Uncontrollable inputs. """
        #return ca.MX.sym("r", self.n_r, self.N)*self.r_nom
        #return ca.MX.sym("r", self.n_r, self.N-1)
        return ca.MX.sym("r", self.n_r, self.N)
    
    def get_p(self):
        """ Parameters. """
        #return ca.MX.sym("p", self.n_p)*self.p_nom
        return self.F.p #*self.p_nom
    
    def map_F(self):
        return self.F.one_sample.map(self.N-1, "openmp")
        #return self.F.one_sample.map(self.N, "openmp")
    
    def map_h(self):
        """ Paralell map of measurement eqs """
        #return self.F.H.map(self.N, "openmp")
        return self.F.h.map(self.N, "openmp")

    """
    def map_g(self):
        return self.F.g.map(self.N-1, "openmp")
        #return self.F.g.map(self.N)
    """
    
    def map_g(self):
        """ Paralell map of algebraic eqs """
        #return self.F.g.map(self.N-1, "openmp")
        return self.F.g.map(self.N)

    def map_wdef(self):
        """ Paralell map of dependant variables """
        return self.F.wdef.map(self.N-1)
        
    
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
        # need to keep Da for calculation of z at finite elems:
        B, C, D, self.Da = self.get_coll_coeffs(d, self.method)
        
        x = []
        z = []
        u = []
        p = []
        w = []
        r = []
        v = []
        y = []
        xb = []
        #x_gaps = []
        g_shooting = []
        h_gaps = []
        
        x_nom = self.x_nom 
        x_nom_b = self.x_nom_b
        u_nom = self.u_nom 
        u_nom_b = self.u_nom_b
        p_nom = self.p_nom 
        p_nom_b = self.p_nom_b 
        r_nom = self.r_nom 
        r_nom_b = self.r_nom_b 
        z_nom = self.z_nom 
        z_nom_b = self.z_nom_b 
        y_nom = self.y_nom 
        y_nom_b = self.y_nom_b
        v_nom = self.v_nom
        
        n_x = self.n_x
        n_z = self.n_z
        n_u = self.n_u
        n_p = self.n_p
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

        # "Lift" initial conditions
        X0 = Xk = ca.MX.sym('X_0', n_x)
        #Z0 = Zk = ca.MX.sym('Z0', n_z)
        # X0 as parameter:
        x.append(Xk)
        xb.append(Xk)

        """
        TODO: new strategy for discretization,
        y defined identically as z.
        """

        # Formulate the NLP
        for k in range(self.N-1):

            # New NLP variable for the control
            Uk = ca.MX.sym('U_' + str(k), n_u)
            Rk = ca.MX.sym('R_' + str(k), n_r)
            #Wk = ca.MX.sym('W_' + str(k), n_w)
            Vk = ca.MX.sym('V_' + str(k), n_v)
            #Yk = ca.MX.sym('Y_' + str(k), n_y)
            #Zk = ca.MX.sym('Z_' + str(k), n_z)
            v.append(Vk)
            #y.append(Yk)
            u.append(Uk)
            r.append(Rk)
            #w.append(Wk)
            #z.append(Zk)

            # State at collocation points
            Xc = []
            for j in range(d):
                Xkj = ca.MX.sym('X_'+str(k)+'_'+str(j), n_x)
                Xc.append(Xkj)
                x.append(Xkj)

            # Loop over collocation points
            Xk_end = D[0]*Xk
            for j in range(1,d+1):
                # Expression for the state derivative at the collocation point
                xp = C[0,j]*Xk
                for i in range(d): xp = xp + C[i+1,j]*Xc[i]

                # Algebraic states from second collocation point onwards:
                Zkj = ca.MX.sym('Z_'+str(k)+'_'+str(j), n_z)
                z.append(Zkj)
                Ykj = ca.MX.sym('Y_'+str(k)+'_'+str(j), n_y)
                y.append(Ykj)
                
                # Append collocation equations
                #fj, qj = f(Xc[j-1]*x_nom, P*p_nom, Uk*u_nom)
                """
                TODO: fix n args.
                """
                fj = self.f(
                            Xc[j-1]*x_nom + x_nom_b, 
                            Zkj*z_nom + z_nom_b, 
                            Uk*u_nom + u_nom_b,
                            P*p_nom + p_nom_b,
                            #Wk*s_nom,
                            Rk*r_nom + r_nom_b
                            )
                            #Wk*s_nom)
                g.append(h*fj - xp*x_nom)
                #g.append(h*fj - (xp*x_nom + x_nom_b))

                # Add contribution to the end state
                Xk_end = Xk_end + D[j]*Xc[j-1];
                
                # append algebraic equation as constraint:
                g.append(self.F.g(
                        Zkj*z_nom + z_nom_b,
                        Xc[j-1]*x_nom + x_nom_b, 
                        Uk*u_nom + u_nom_b,
                        P*p_nom + p_nom_b,
                        Vk*v_nom,
                        #Wk*s_nom,
                        Rk*r_nom + r_nom_b)
                        #Wk*s_nom)
                )
                """
                TODO: enforce measurement only at k = 0,1,...,N-1,
                where N is number of measurements.
                """
                g.append(
                        self.F.h(
                        Ykj*y_nom + y_nom_b,
                        Xc[j-1]*x_nom + x_nom_b, 
                        Zkj*z_nom + z_nom_b,
                        Uk*u_nom + u_nom_b,
                        P*p_nom + p_nom_b,
                        Vk*v_nom,
                        Rk*r_nom + r_nom_b)
                        )
                        #Wk*s_nom)
                        
                """
                g.append(self.F.g(
                        Zkj,
                        Xc[j-1], 
                        Uk,
                        P*p_nom + p_nom_b,
                        Vk,
                        Rk)
                         )
                g.append(self.F.g(Zkj*z_nom + z_nom_b,
                    Xc[j-1]*x_nom + x_nom_b, 
                    Uk*u_nom + u_nom_b,
                    P*p_nom,
                    Vk*v_nom,
                    Rk*r_nom + r_nom_b))
                g.append(self.F.g(
                              Zkj,
                              Xkj, 
                              Uk,
                              P,
                              Vk,
                              Rk)
                     )
                """
                # Add contribution to quadrature function
                # TODO: modularize
                qj = ca.dot(Zkj, Zkj)
                J = J + B[j]*qj*h
                #J = J + B[j]*qj*h/(u_nom[0]**3)
                #J = J + B[j]*qj*h
            # can take simple quadrature?
            #J = J + Uk[0]**2
            
            # measurement equation, if exists
            
            # algebraic:
            """
            g.append(self.F.h(Yk*y_nom + y_nom_b, 
                              Xk*x_nom + x_nom_b, 
                              0,
                              0,
                              0,
                              Vk*v_nom,
                              0))
            g.append(self.F.g(Zk*z_nom + z_nom_b,
                              Xk*x_nom + x_nom_b, 
                              Uk*u_nom + u_nom_b,
                              P*p_nom,
                              Vk*v_nom,
                              Rk*r_nom + r_nom_b))
            g.append(self.F.g(
                              Zk,
                              Xk, 
                              Uk,
                              P,
                              Vk,
                              Rk)
                     )
            """
            #g.append(self.F.h(Yk*y_nom, Xk*x_nom, 0, 0, 0, Vk, 0))
            h_gaps.append(g[-1])
            


            # New NLP variable for state at end of interval
            Xk = ca.MX.sym('X_' + str(k+1), n_x)
            x.append(Xk)
            xb.append(Xk)
            # Add equality constraint
            g.append(Xk_end - Xk)
            g_shooting.append(Xk_end - Xk)
            #g.append(x_nom*Xk_end - x_nom*Xk)
            #x_gaps.append(g[-1])

        #Yk = ca.MX.sym('Y_' + str(k+1), n_y)
        
        """
        Vk = ca.MX.sym('V_' + str(k+1), n_v)
        Rk = ca.MX.sym('R_' + str(k+1), n_r)
        Uk = ca.MX.sym('U_' + str(k+1), n_u)
        #Zk = ca.MX.sym('Z_' + str(k+1), n_z)
        v.append(Vk)
        #y.append(Yk)
        r.append(Rk)
        u.append(Uk)
        """
        
        #z.append(Zk)
        # add last measurement equation
         
        """
        g.append(self.F.h(Yk*y_nom + y_nom_b, 
                          Xk*x_nom + x_nom_b, 
                          0,
                          0,
                          0,
                          Vk*v_nom,
                          0))
        g.append(self.F.g(Zk*z_nom + z_nom_b,
                        Xk*x_nom + x_nom_b, 
                        Uk*u_nom + u_nom_b,
                        P*p_nom,
                        Vk*v_nom,
                        Rk*r_nom + r_nom_b))
        g.append(self.F.g(
                        Zk,
                        Xk, 
                        Uk,
                        P,
                        Vk,
                        Rk)
                 )
        """
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
        nlp_parser = NLPParser((x, z, u, P, v, y, r, w))
        
        # set inds for boundary points:
        nlp_parser.vars["x"]["boundary_vars"] = ca.vertcat(*xb)
        nlp_parser.vars["x"]["shooting_gaps"] = ca.vertcat(*g_shooting)
        
        #nlp_parser.set_x_gaps(ca.vertcat(*x_gaps))
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
        return ca.MX.sym("u", self.n_u, self.N-1)

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
        # for algebraic vars:
        Da = np.zeros(d)
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
            
        # for algvars:
        tau = ca.SX.sym("tau")
        Da = np.zeros(d)
        for j in range(1,d+1):
            # Lagrange polynomials for the algebraic states: exclude the first point
            La = 1
            for j2 in range(1,d+1):
                if j2 != j:
                    La *= (tau-tau_root[j2])/(tau_root[j]-tau_root[j2])
            lafcn = ca.Function('lafcn', [tau], [La])
            Da[j-1] = lafcn(tau_root[0])
            
        return B, C, D, Da

           
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