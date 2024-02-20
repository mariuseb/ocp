#from argparse import ArgumentError
import casadi as ca
from ocp.mpc import MPC
import numpy as np

class ParametricMPC(MPC):
    """
    Special MPC formulation tailored for
    RL learning.
    """
    def __init__(self, *args, **kwargs):
        super().__init__(**kwargs)
        self.split_h_g()
        """
        Parameters of MPC policy:
        """
        self.P = ca.MX.sym("P")
        self.add_terminal_cost()
        
    def split_h_g(self):
        """
        Determine which constraints belong to
        h, g respectively.
        
        Important for calculating sensitivities
        """
        self.g = []
        self.h = []
        
        for i, (lb, ub) in enumerate(zip(self.lbg, self.ubg)):
            """
            Does the below cover all cases??
            """
            ndx = ca.Slice(i,i+self.n_x)
            if lb != ub:
                self.h.append(self.nlp["g"][ndx])
            else:
                self.g.append(self.nlp["g"][ndx])
        """
        for i, (lb, ub) in enumerate(zip(self.lbx, self.ubx)):
            if lb != ub and lb != -np.inf and ub != np.inf:
                self.h.append(self.x[i])
        """
        # go through nlp-x for simple box constraints 
        # on x, u:
        x_info = self.nlp_parser.vars["x"]
        start, stop = x_info["range"]["a"], x_info["range"]["b"]
        ndx = ca.Slice(start, stop)
        self.h.append(self.nlp["x"][ndx])
        
        u_info = self.nlp_parser.vars["u"]
        start, stop = u_info["range"]["a"], u_info["range"]["b"]
        ndx = ca.Slice(start, stop)
        self.h.append(self.nlp["x"][ndx])
            
                
                
    def add_terminal_cost(self):
        """
        Add parametric terminal cost
        to nlp objective.
        """
        x_info = self.nlp_parser["x"]
        stop = x_info["range"]["b"]
        start = stop - self.n_x
        x_N = self.nlp["x"][start:stop]
        W = ca.MX.sym("W", self.n_x, self.n_x)
        self.P = ca.vertcat(self.P, W)
        self.nlp["f"] += x_N@W@x_N.T
        
    def add_g_bias(self): 
        """
        Add dynamic bias (state-dependant?) to
        discretized model dynamics
        """
        pass
    
    def objective_cost(self):
        return self.nlp["f"]
    
    def equality_constraints(self):
        return ca.vertcat(*self.g)
    
    def inequality_constraints(self):
        return ca.vertcat(*self.h)


        
        
        
