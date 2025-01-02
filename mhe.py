#from argparse import ArgumentError
import casadi as ca
#from casadi import *
#from abc import ABC, abstractmethod, ABCMeta
import pandas as pd
#pd.set_option("display.precision", 8)
import numpy as np
#np.set_printoptions(precision=10)
#import json
#import sys
#import pdb
from pprint import pprint
import subprocess
import os
import re
#from sysid.shooting import MultipleShooting, SingleShooting
#import copy

#from tables import Col
#from integrators import RungeKutta4, Cvodes, IRK
#import sysid.integrators as integrators
#from sysid.dae import DAE
from ocp.shooting import MultipleShooting, Collocation
#from callback import ProcessIdCallback
#import os
#from shooting import Collocation
#from sysid.ocp import OCP
#import typing
from ocp.ocp import OCP


class MHE(OCP):
    def __init__(self, **kwargs):
        """
        Almost equal to regular sysid,
        though we drop statistics for now.
        
        Revised: now EXACTLY equal to 
        regular sysid problem under some
        conditions.
        """
        self.gamma = kwargs.pop("gamma", 1)
        self.arrival_cost = kwargs.pop("arrival_cost", False)
        self.algebraic_slack = kwargs.pop("algebraic_slack", False)
        super(MHE, self).__init__(**kwargs)
        self.df = pd.DataFrame(columns=self.dae.p + self.dae.x + self.dae.z)
        # covariance matrices:
        #self.R = ca.MX.sym("R", ca.Sparsity.diag(self.n_y))
        #self.Q = ca.MX.sym("Q", ca.Sparsity.diag(self.n_x))
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        #self.R = ca.MX.sym("R", 1, 1)
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        #self.set_hess_obj()
        
        """
        Possibly include slack variables
        in shooting gaps.
        """
        if self.slack:
            self.add_slack_to_shooting_gaps(algebraic_slack=self.algebraic_slack)
        
        if "f" not in self.nlp:
            self.set_nlp_obj(arrival_cost=self.arrival_cost)
            
        self.lbg = np.array([0]*self.nlp_parser.g.shape[0])
        self.ubg = np.array([0]*self.nlp_parser.g.shape[0])
        self.add_h() 
        #self.prepare_solver()
        
       
    def add_slack_to_shooting_gaps(self, algebraic_slack=False):
        """
        Write:  
            F(x, u) - x+ = s
        instead of:
            F(x, u) - x+ = 0
        
        TODO:
            - should also be accessible
            from ParameterEstimation.
           
        Only for multiple shooting for now.
        """
        if algebraic_slack:
            self.n_sl = self.n_x + self.n_z
            alg_gaps = self.nlp_parser.vars["z"]["alg_gaps"]
        else:
            self.n_sl = self.n_x
            alg_gaps = ca.MX(self.N-1)
        
        shooting_gaps = self.nlp_parser.vars["x"]["shooting_gaps"]
        #alg_gaps = self.nlp_parser.vars["z"]["alg_gaps"]
        sigma_shape = (self.N-1, self.n_sl)
        self.sigma = sigma = ca.MX.sym("sigma", sigma_shape)
        """
        Differential part:
        """
        diff_sigma = sigma[:,:self.n_x]
        new_x_gaps = shooting_gaps + diff_sigma
        #self.n_sl = self.n_x
        """
        Algebraic part:
        """
        alg_sigma = sigma[:,self.n_x:(self.n_sl)]
        new_z_gaps = alg_gaps + alg_sigma
        """
        Flatten, add new differential gaps back to NLP:
        """
        new_x_gaps = ca.veccat(new_x_gaps)
        self.nlp["g"][0:new_x_gaps.shape[0]] = new_x_gaps
        """
        Same for algebraic gaps:
        """
        new_z_gaps = ca.veccat(new_z_gaps)
        start = new_x_gaps.shape[0]
        stop = start + new_z_gaps.shape[0]
        self.nlp["g"][start:stop] = new_z_gaps
        
        """
        Add slack variable to problem definition:
        """
        self.nlp["x"] = ca.vertcat(self.nlp["x"], ca.veccat(self.sigma))
        dim = self.sigma.shape[0]*self.sigma.shape[1]
        self.nlp_parser.vars["sl"] = {
                            "range":
                                    {
                                        "a":
                                        self.nlp_parser["r"]["range"]["b"],
                                        "b": 
                                        self.nlp_parser["r"]["range"]["b"] + \
                                            dim
                                    },
                            "dim": dim
                            }
        #self.n_sl = self.n_x + self.n_z
        self.slack_names = list(map(lambda x: "s" + str(x+1), range(self.n_sl)))
        """
        MHE is now discrete-time stochastic.
        """    
    
    def set_nlp_obj(self, alg_in_Q=False, arrival_cost=False):
        """
        Parse MHE objective as passed in from config file.
        
        Modularize this method as we go. 
        """
        
        # initialize the parameters needed for the objective:
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        
        symbols = set(re.findall("|".join(self.dae.all_names), self.obj_string))
        vals = dict()
        for symbol in symbols:
            try:
                vals[symbol] = self.get(symbol)
            except KeyError:
                assert symbol.startswith("s")
            
        # here, multiply gamma in:
        #gamma = 0.99
        gamma_vec = ca.DM.ones((self.N, 1))
        for n in range(self.N):
            gamma_vec[self.N-1-n] *= (self.gamma**n)
        self.gamma_vec = gamma_vec
            
        obj_string = self.obj_string.replace("dot", "ca.dot")
        vals["ca"] = ca
        vals["R"] = self.R
        vals["Q"] = self.Q
        
        """
        s1, s2, ... , s_{nx} are aliases for sigma[:,0] , ... , sigma[:,nx-1]
        """
        if self.slack:
            sigma = self.sigma.reshape((self.N-1, self.n_sl))
            for n in range(self.n_sl):
                vals["s" + str(n+1)] = sigma[:,n]
        
        
        vals["gamma_v"] = np.sqrt(gamma_vec)
        if self.strategy.name == "Collocation":
            vals["gamma_s"] = np.sqrt(gamma_vec[0:(self.N-1)])
        else: # if any y part of z, we have not measured last z:
            #vals["gamma_s"] = vals["gamma_v"]
            vals["gamma_s"] = np.sqrt(gamma_vec[0:(self.N-1)])
            # TODO: modularize this!
            #vals["v2"] = vals["v2"][:-1] 
            #vals["v3"] = vals["v3"][:-1] 
            #vals["v4"] = vals["v4"][:-1] 
            # s's:
            #vals["s1"] = vals["s1"][:-1] 
            #vals["s2"] = vals["s2"][:-1] 
            #vals["s3"] = vals["s3"][:-1] 
            #vals["s4"] = vals["s4"][:-1] 
            #vals["s5"] = vals["s5"][:-1] 
            #vals["s6"] = vals["s6"][:-1] 
            #vals["s3"] = vals["s3"][:-1] 
            
        exec(f'obj_expr =' + obj_string, vals)
        
        self.nlp["f"] = self.f_orig = vals["obj_expr"]
        #self.nlp["p"] = ca.veccat(self.R, self.Q)
        #if self.arrival_cost:
        #    self.nlp["p"] = ca.veccat(self.nlp["p"], self.P0)
        
        # TODO: reshuffle ordering of MHE parameters ...
        if arrival_cost:
            """
            last_x = self.nlp_x[0:self.n_x]
            This might be the second last:
            last_z = self.nlp_z[0:self.n_z]
            p = self.strategy.F.p
            costate = ca.vertcat(p, last_x, last_z)
            arrival_cost = (costate - self.costate_prior).T@self.P0@(costate - self.costate_prior)
            self.nlp["f"] += arrival_cost
            self.nlp["p"] = ca.veccat(self.P0, self.Q, self.R, self.costate_prior)    
            """
            self.add_arrival_cost_to_objective()
        else:
            self.nlp["p"] = ca.veccat(self.Q, self.R)    
   
    """
    def __del__(self):
        for file in self.c_files:
            print("Deleting %s..." % file)
            os.remove(file)
    """      
    
    def add_arrival_cost_to_objective(self, p_aux=None):
        """
        Method for adding arrival cost to objective function
        """
        last_x = self.nlp_x[0:self.n_x]
        """
        This might be the second last:
        """
        
        #last_z = self.nlp_z[0:self.n_z]
        if p_aux is None:
            p = self.strategy.F.p
        else:
            p = p_aux
            
        self.P0 = ca.MX.sym("P0", ca.Sparsity.diag(self.n_x + p.shape[0]))
        self.costate_prior = ca.MX.sym("costate_prior", self.n_x + p.shape[0])
            
        costate = ca.vertcat(p, last_x)
        arrival_cost = (costate - self.costate_prior).T@self.P0@(costate - self.costate_prior)
        self.nlp["f"] = self.f_orig + arrival_cost
        self.nlp["p"] = ca.veccat(self.P0, self.Q, self.R, self.costate_prior)    
        
    #def store_param_and_state(self, params, state, z, k):
    #    self.df.loc[k*self.dt:(k+self.N*self.dt), :] = np.concatenate([params, state, z])
    
    def store_param_and_state(self, sol_df, k):
        names = self.dae.p + self.dae.x + self.dae.z
        #sol_df.index = np.arange(k*self.dt, int(k + self.N)*self.dt, self.dt)
        sol_df.index = np.linspace(k*self.dt, (k + self.N - 1)*self.dt, self.N)
        if k == 0:
            self.df = sol_df[names]
        else:
            self.df.loc[(k+self.N - 1)*self.dt] = np.nan
            self.df.loc[k*self.dt:(k+self.N)*self.dt] = sol_df[names]
        
    def solve(
              self,
              data,
              param_guess,
              covar=None,
              lbp=None,
              ubp=None,
              lbx=None,
              ubx=None,
              P0=None,
              x_N=None,
              #z_N=np.array([]),
              x_guess=None,
              p_aux=None,
              p_aux_prior=None,
              #arrival_cost=False,
              return_raw_sol=False,
              codegen=False
              ):
        """
        Set initials for v, w to 0
        """
        self.data = data   

        if x_guess is None:  
            x_guess = self.generate_x_guess()
            x_guess = x_guess.reshape((x_guess.shape[0]*x_guess.shape[1], 1))
        self.separate_data(
                          data,
                          lbp=lbp,
                          ubp=ubp,
                          #lbx=0.5*x_guess,
                          #ubx=1.5*x_guess,
                          lbx=lbx,
                          ubx=ubx,
                          x_guess=x_guess,
                          param_guess=param_guess
                          )
        
        self.set_bounds()
        #self._init_solver()
        if self.arrival_cost:        
            p0 = param_guess/self.p_nom
            x_N = (x_N - self.x_nom_b)/self.x_nom
            #z_N = (z_N - self.z_nom_b)/self.z_nom
            #p0 = param_guess
            #x_N = x_N
            if p_aux is not None:
                self.add_arrival_cost_to_objective(p_aux=p_aux)
                assert p_aux_prior is not None
                p_nom = self.get_scale(p_aux_prior)
                costate_prior = ca.vertcat(p_aux_prior/p_nom, x_N)
            else:
                costate_prior = ca.vertcat(p0, x_N)
                
            p = ca.veccat(P0, covar, costate_prior)       
        else:
            p = ca.veccat(covar)
        self.p_val = p # store
        
        self.prepare_solver(codegen=codegen)
        
        #if not hasattr(self, "solver"):      
        #    self._init_solver()
        # with p=covar
        
        # TODO: branching on arrival cost:
        """
        gen_code_filename = self.get_c_code_name()
        if codegen and not os.path.exists(gen_code_filename):
            self.pregenerate_c_code(gen_code_filename)
        """ 
        # possibility to overwrite lbx, ubx?
        # DEBUG:
        """
        from pprint import pprint
        for k, v in self.nlp_parser.vars.items():
            pprint(k + ": ")
            pprint(self.x0[v["range"]["a"]:v["range"]["b"]])
        # TODO:
        try:
            self.lbx = self.lbx.round(8)
            self.ubx = self.ubx.round(8)
        except:
            pass
        """
        if self.slack:
            start, stop = self.nlp_parser.vars["sl"]["range"]["a"], \
                self.nlp_parser.vars["sl"]["range"]["b"]
            
            self.lbx[start:stop] = [-np.inf]*(stop-start)
    
        solution = self.solver(
                            x0=self.x0,
                            lbg=self.lbg, # option for path-constraints?
                            ubg=self.ubg, # --"--
                            lbx=self.lbx,
                            ubx=self.ubx,
                            #p=ca.veccat(_P0, covar, ca.vertcat(param_guess, x_N))
                            p=p
                            #p=0
                            )
        
        self.sol_df, params = self.parse_solution(solution)
        
        # k given by history thus far:
        #k = len(self.df) + self.N - 2
        k = max(0, len(self.df) - self.N + 1)
        #self.df.loc[k*self.dt, :] = np.append(params.values, self.sol_df[self.x_names].iloc[-1])
        self.store_param_and_state(
                                   #params.values, 
                                   #self.sol_df[self.x_names].values,
                                   #self.sol_df[self.z_names].values,
                                   self.sol_df,
                                   k
                                   )
                
        #self.sol_df.index = np.arange((k-1)*self.dt, (k - 1 + self.N)*self.dt, self.dt)
        if not return_raw_sol:
            return self.sol_df, params
        else:
            return self.sol_df, params, solution
    
