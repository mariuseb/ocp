import casadi as ca
import pandas as pd
import numpy as np
from pprint import pprint
import re
from ocp.shooting import SingleShooting, MultipleShooting, Collocation
from ocp.covar_est import CovarianceEstimation
from ocp.ocp import OCP, get_scale, is_single_shooting

class Estimation(OCP, CovarianceEstimation):
    
    __name__ = "Estimation"
    
    def __init__(self, **kwargs):
        """
        Almost equal to regular sysid,
        though we drop statistics for now.
        
        Revised: now EXACTLY equal to 
        regular sysid problem under some
        conditions.
        """
        self.gamma = kwargs.pop("gamma", 1)
        need_sensitivities = kwargs.pop("need_sensitivities", False)
        #self.codegen = kwargs.pop("codegen", False)
        self.arrival_cost = kwargs.pop("arrival_cost", False)
        self.algebraic_slack = kwargs.pop("algebraic_slack", False)
        super(Estimation, self).__init__(**kwargs)
        self.df = pd.DataFrame(columns=self.dae.p + self.dae.x + self.dae.z)
        # covariance matrices:
        self.R = ca.MX.sym("R", self.n_y, self.n_y)
        self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
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

        self.prepare_solver(codegen=self.codegen)

        if need_sensitivities:   
            self.set_up_grad_f_x_solver()
            self.set_up_jac_x_p_solver()
        #self.prepare_solver()
    
    def set_up_grad_f_x_solver(self):
        """
        Assume multiple shooting. 

        TODO: check / add other options
        """
        f = self.nlp["f"]
        rho = ca.MX.sym("rho")
        x_gaps = self.nlp_parser["x"]["shooting_gaps"]
        y_gaps = self.nlp_parser["y"]["shooting_gaps"]
        shooting_expr = 0
        for n in range(self.N-1):
            shooting_expr += ca.sqrt(
                x_gaps[n,:]@x_gaps[n,:].T
            )
        # TODO: include R:
        for n in range(self.N):
            #shooting_expr += y_gaps[n,:]**2
            shooting_expr += ca.sqrt(
                y_gaps[n,:]@y_gaps[n,:].T
            )
        shooting_expr = rho/2*(shooting_expr)
        f = f + shooting_expr
        x, p = self.nlp["x"], self.nlp["p"]
        grad_f_x_expr = ca.gradient(
            f, x
        )
        self.grad_f_x = ca.Function(
            "grad_f_x", [x, p, rho], [grad_f_x_expr], ["x", "p", "rho"], ["grad_f_x"]
        )

    def set_up_jac_x_p_solver(self):
        """
        Use factory of sqp-solver to form this.
        Hence, will have same signature as that
        one.
        """
        self.jac_x_p = self.sqp_solver.factory(
            'h', self.solver.name_in(), ['jac:x:p']
        )

       
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
        
    def get_MX(self, symbol):
        if symbol.startswith("v") and is_single_shooting(self.strategy):
            # TODO: slicing:
            return self.v
        else:
            return self.get(symbol)
    
    def _transform_v(self):
        self.v = ca.vertcat(
            *self.strategy.v
        )
        
    
    def set_nlp_obj(self, alg_in_Q=False, arrival_cost=False):
        """
        Parse MHE objective as passed in from config file.
        
        Modularize this method as we go. 
        """
        if is_single_shooting(self.strategy):
            self._transform_v()
             
        # initialize the parameters needed for the objective:
        self.Q0 = ca.MX.sym("Q0", self.n_x, self.n_x)
        self.R0 = ca.MX.sym("R0", self.n_y, self.n_y)
        # TODO: expand to multiple_dims:
        #self.xi_q = ca.MX.sym("xi_q", self.n_x, self.n_x)
        self.Q = ca.expm(self.Q0)
        self.R = ca.expm(self.R0)
        #symbols = set(re.findall("|".join(self.dae.all_names), self.obj_string))
        #symbols = re.findall("|".join(self.dae.all_names), self.obj_string)
        symbols = []
        for symbol in self.dae.all_names:
            if re.search(symbol, self.obj_string) is not None:
                symbols.append(symbol)
        
        vals = dict()
        for symbol in symbols:
            try:
                #vals[symbol] = self.get(symbol)
                vals[symbol] = self.get_MX(symbol)
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
        #vals["p_nom_map"] = self.p_nom_map
        
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
            vals["gamma_s"] = np.sqrt(gamma_vec[0:(self.N-1)])
            
        exec(f'obj_expr =' + obj_string, vals)
        self.nlp["f"] = self.f_orig = vals["obj_expr"]
        # TODO: reshuffle ordering of MHE parameters ...
        if arrival_cost:
            self.add_arrival_cost_to_objective()
        else:
            #self.nlp["p"] = ca.veccat(self.Q, self.R)    
            # TODO: check:
            self.nlp["p"] = ca.veccat(self.Q0, self.R0)    
   
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
        self.P = ca.expm(self.P0)
        self.costate_prior = ca.MX.sym("costate_prior", self.n_x + p.shape[0])
            
        costate = ca.vertcat(p, last_x)
        #arrival_cost = (costate - self.costate_prior).T@ca.inv(self.P0)@(costate - self.costate_prior)
        #arrival_cost = (costate - self.costate_prior).T@self.P0@(costate - self.costate_prior)
        arrival_cost = (costate - self.costate_prior).T@self.P@(costate - self.costate_prior)
        self.nlp["f"] = self.f_orig + arrival_cost
        #self.nlp["p"] = ca.veccat(self.P0, self.Q, self.R, self.costate_prior)    
        self.nlp["p"] = ca.veccat(self.P0, self.Q0, self.R0, self.costate_prior)    
        
    
    def store_param_and_state(self, params, state, z, k):
        self.df.loc[k*self.dt, :] = np.concatenate([params, state, z])
        
    def presolve(
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
        x_guess=None,
        p_aux=None,
        p_aux_prior=None,
        codegen=False
    ):
        """
        Set initials for v, w to 0
        """
        self.data = data   
        if x_guess is None:  
            x_guess = self.generate_x_guess()
            x_guess = x_guess.reshape((x_guess.shape[0]*x_guess.shape[1], 1))

        # store values of NLP-parameters:
        self.P0_val = P0
        #self.Q_val = Q 
        #self.R_val = R
        
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
            self.x_N_val = x_N
            #z_N = (z_N - self.z_nom_b)/self.z_nom
            #p0 = param_guess
            #x_N = x_N
            if p_aux is not None:
                self.add_arrival_cost_to_objective(p_aux=p_aux)
                assert p_aux_prior is not None
                p_nom = get_scale(p_aux_prior)
                costate_prior = ca.vertcat(p_aux_prior/p_nom, x_N)
            else:
                costate_prior = ca.vertcat(p0, x_N)
                
            p = ca.veccat(P0, covar, costate_prior)       
        else:
            p = ca.veccat(covar)
        self.p_val = p # store
        #self.nlp["p"] = self.integrator.p
        #self.p_val = param_guess/self.p_nom
        
        #self.prepare_solver(codegen=codegen)
        
        
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
              x_guess=None,
              p_aux=None,
              p_aux_prior=None,
              return_raw_sol=False,
              codegen=False
    ):      
        self.presolve(
            data,
            param_guess,
            covar=covar,
            lbp=lbp,
            ubp=ubp,
            lbx=lbx,
            ubx=ubx,
            P0=P0,
            x_N=x_N,
            x_guess=x_guess,
            p_aux=p_aux,
            p_aux_prior=p_aux_prior,
            codegen=codegen
        )
        
        solution = self.solver(
                            x0=self.x0,
                            lbg=self.lbg, # option for path-constraints?
                            ubg=self.ubg, # --"--
                            lbx=self.lbx,
                            ubx=self.ubx,
                            #p=ca.veccat(_P0, covar, ca.vertcat(param_guess, x_N))
                            p=self.p_val
                            #p=0
                            )
        ### The below is 'MHE-specific':
        self.sol_df, params = self.parse_solution(solution)
        # k given by history thus far:
        k = len(self.df) + self.N - 1
        self.store_param_and_state(
                                   params.values, 
                                   self.sol_df[self.x_names].iloc[-1].values,
                                   self.sol_df[self.z_names].iloc[-2].values,
                                   k + 1
                                   )
        self.sol_df.index = np.arange(k*self.dt, (k + self.N)*self.dt, self.dt)
        ####
        if not return_raw_sol:
            return self.sol_df, params
        else:
            return self.sol_df, params, solution
    
