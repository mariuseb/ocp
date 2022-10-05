from argparse import ArgumentError
import casadi as ca
from casadi import *
from abc import ABC, abstractmethod, ABCMeta
import pandas as pd
import numpy as np
import json

from tables import Col
from sysid.integrators import RungeKutta4, Cvodes
from sysid.dae import DAE
from sysid.shooting import MultipleShooting
from sysid.callback import ProcessIdCallback
import os
from sysid.shooting import Collocation
from sysid.ocp import OCP
#import typing


class ParameterEstimation(object):
    """
    Class for parameter estimation.
    
    args:
        - config (for DAE)
        - integrator (RK4, idas, cvode etc.)
        - strategy (i.e. single-, multiple-shooting or collocation)
        - solver (gauss-newton, levenberg-marquandt, BFGS)

    """
    def __init__(self, 
                 config, \
                 # integrator="RK4", \
                 solver="gauss_newton",
                 codegen=True):
        """
        Starting point.
        """
        if isinstance(config, str) or isinstance(config, os.PathLike):
            with open(config, "r") as f:
                config = json.load(f)

        self.dae = dae = DAE(config["model"])

        """
        Here: use dae and config to create a OCP:
        """
        self.ocp = OCP(dae, config)

        self.dt = config["dt"]
        self.n_steps = config["n_steps"]
        self.method = config["method"]

        if self.method in ("MS", "SS"):
            # can we generalize the integrator class ?? 
            self.integrator = RungeKutta4(self.dt, self.n_steps, self.dae)
        else: # collocation method:
            pass
            # wait on integrator init.
            # it is actually questionable whether 
            # 'low-level' work such as creating
            # integrators should be done here.

        #self.integrator = Cvodes(self.dt, self.dae)
        # ipopt/casadi settings
        self.R = ca.DM(np.diag(config["R"]))
        self.Q = ca.DM(np.diag(config["Q"]))
        self.opt_config = config["opt"]
        self.codegen = codegen

        if codegen:
            if Importer.has_plugin('clang'):
                self.with_jit = True
                self.compiler = 'clang'
                print(f"Running with jit, compiler {self.compiler}.")
            elif Importer.has_plugin('shell'):
                self.with_jit = True
                self.compiler = 'shell'
                print(f"Running with jit, compiler {self.compiler}.")
            else:
                print("WARNING; running without jit. This may result in very slow evaluation times")
                self.with_jit = False
                self.compiler = ''
        else:
            self.with_jit = False
            self.compiler = ''
            print("WARNING; running without jit. This may result in very slow evaluation times")

    @property
    def p(self):
        return vertcat(*self.dae.dae.p)
    
    @property
    def x(self):
        return self.dae.dae.x
    
    @property
    def u(self):
        return self.dae.dae.u

    @property
    def u_names(self):
        return list(map(lambda x: x.name(), self.dae.dae.u))

    @property
    def h_names(self):
        """ 
        Only measurement eqs are algebraic for now. 
        """
        #return list(map(lambda h: h.name(), self.dae.dae.alg))
        h_names = []
        for eq in self.dae.dae.alg:
            try: 
                h_names.append(eq.name())
            except RuntimeError as e:
                # trivial equation, MX(0)
                check_msg = "'name' not defined for class N6casadi8ConstantINS_16CompiletimeConstILi0EEEEE"
                assert check_msg in str(e)
        return h_names
            
    

    def gauss_newton_solver(self, residual, ubg=None, lbg=None, with_cb=False):
        """
        Gauss-newton solver for fast (super-quadratic) convergence.
        """
        J = jacobian(residual,self.nlp_struct["x"])
        H = triu(mtimes(J.T, J))
        sigma = MX.sym("sigma")

        hessLag = Function('nlp_hess_l', \
                            {'x':self.nlp_struct["x"],'lam_f':sigma, 'hess_gamma_x_x':sigma*H},
                            ['x','p','lam_f','lam_g'], \
                             ['hess_gamma_x_x'],
                            dict(jit=self.with_jit, \
                            compiler=self.compiler))

        # set callback here:
        if with_cb:
            # there is no opt-problem w/o variables:
            n_x = self.nlp_struct["x"].shape[0]
            # but constraints and params are optional:
            try:
                n_g = self.nlp_struct["g"].shape[0]
            except KeyError:
                n_g = 0
            try:
                n_p = self.nlp_struct["p"]
            except KeyError:
                n_p = 0

            mycallback = ProcessIdCallback('mycallback', n_x, n_g, n_p)
            self.opt_config['iteration_callback'] = mycallback

        return nlpsol("solver", \
                      "ipopt", \
                       self.nlp_struct, \
                       dict(hess_lag=hessLag,
                            jit=self.with_jit, \
                            compiler=self.compiler, \
                            **self.opt_config))



    #def estimate(self, U, Y, param_guess=None, scale=None, strategy = "MS", keep_misc=True):
    def estimate(self, df, param_guess=None, scale=None, keep_misc=True, single=None, parallel=False):
        """
        Run the estimation procedure.

        Data should be labelled. Fix tomorrow (25/03-22)

        Return should be parsed.
        """
        
        ### get list of files in directory before jitting ###


        # TODO: clean up below:

        if single is None:

            self.N = len(df)

            U = DM(df[self.u_names].values)
            Y = DM(df[self.h_names].values)

            assert U.shape[0] == Y.shape[0]


            # TODO: refactor this:
            self.nlp_struct, residual, X, W = self.transcribe_nlp(U, Y, self.Q, self.R, scale, parallel=parallel)

            # add physicality constraints (lb and ub for params).
            # do it real simple, ub -> param_guess/5 and lb -> param_guess*5
            
            # state constraints:
            self.ms_constraints = self.nlp_struct.pop("g")

            self.lb_ms = self.ub_ms = [0]*self.ms_constraints.shape[0]

            #params = self.dae.dae.p

            self.g = veccat(self.ms_constraints, *self.dae.dae.p)

            p_lb = list(np.array(param_guess)/100)
            p_ub = list(np.array(param_guess)*100)

            lbg = self.lb_ms + p_lb
            ubg = self.ub_ms + p_ub

            # do another: add constraints for state trajectories: e.g. not more than 20 degrees above or below observed indoor temperature: 
            # assume one observation for now
            X_ub = repmat(Y+20, 1, 3).T
            X_lb = repmat(Y-20, 1, 3).T

            lbg = lbg + list(np.array(veccat(X_lb)).flatten())
            ubg = ubg + list(np.array(veccat(X_ub)).flatten())

            self.g = veccat(self.g, X)

        """
        else: # re-estimate?

            self.N = len(df)

            U = DM(df[self.u_names].values)
            Y = DM(df[self.h_names].values)

            assert U.shape[0] == Y.shape[0]

            self.nlp_struct, residual = self.transcribe_nlp(strategy, U, Y, scale)

            # add physicality constraints (lb and ub for params).
            # do it real simple, ub -> param_guess/5 and lb -> param_guess*5
            
            # state constraints:
            self.ms_constraints = self.nlp_struct.pop("g")

            self.lb_ms = self.ub_ms = [0]*self.ms_constraints.shape[0]

            #params = self.dae.dae.p

            self.g = veccat(self.ms_constraints, *self.dae.dae.p)
     
            p_lb = list(np.array(param_guess))
            p_ub = list(np.array(param_guess))

            for i, name in enumerate(self.dae.p):
                if name == single:
                    #p_lb[i] = param_guess[i]/100
                    #p_ub[i] = param_guess[i]*100
                    p_lb[i] = param_guess[i]/10
                    p_ub[i] = param_guess[i]*10
                    break
            else:
                raise ArgumentError("No matching parameter provided....")

            lbg = self.lb_ms + p_lb
            ubg = self.ub_ms + p_ub
            """

    
        self.nlp_struct["g"] = self.g

        self.solver = self.gauss_newton_solver(residual) 

        # should be some selection of strategy for guessing state trajectory

        ### solve block ###

        ### the GUESSING here is of vital importance ###
        yd = np.diff(Y,axis=0)*(1/self.dt)

        add_states = []

        #for n in range(self.dae.n_x - self.dae.n_h):
        for n in range(self.dae.n_x - len(self.h_names)):
            add_states.append(Y)

        # fix X_guess.shape, W_guess.shape            
        X_guess = horzcat(Y, horzcat(*add_states)).T
        W_guess = repmat(DM([0,0,0]), 1, X_guess.shape[1])

        x0 = veccat(param_guess,X_guess, W_guess)

        #mycallback = ProcessIdCallback("mycallback")
        #config["opt"]["iteration_callback"] = mycallback
        
        # nx, ng, np
        
        #mycallback = ProcessIdCallback('mycallback', 2, 1, 0)
        #opts = {}
        #opts['iteration_callback'] = mycallback

        # possible to set callback after nlpsol-call?
        #n_x = self.solver.size_in(0)[0]
        #n_g = self.solver.size_out(2)[1]
        #n_p = self.solver.size_in(1)[0]

        sol = self.solver(x0=x0,lbg=lbg,ubg=ubg)
        ##################
        self.clean_up_jit()
        ##################

        x = sol.pop("x")

        if keep_misc:
            self.sol = sol
        # parse the solution:
        params, states_df, noise_df = self.parse_nlp_res(x, scale)

        return params, states_df, noise_df


    def get_files_before(self):
        """
        Get files in $PWD before jitting.
        """
        if self.codegen:
            self.before_jit = self.get_files()

    def clean_up_jit(self):
        """
        Clean up after code-gen.
        """
        if self.codegen:
            after_jit = self.get_files()
            
            if self.before_jit != after_jit:
                # CaSADi has not done cleanup
                diff = set(after_jit).difference(set(self.before_jit))
                assert all(filename.split(".")[-1] in ("so", "o", "c") for filename in diff)
                for file in diff:
                    os.remove(file)
                else:
                    # Eventually, output such as this should go to logger.
                    print("Cleaned up JIT-files")
       

    @staticmethod
    def get_files():
        return os.listdir(os.getcwd())
        

    def parse_nlp_res(self, V: DM, scale: DM):
        """ 
        Parse the NLP-results to dataframe. 
        Know: V = veccat(params, X)

        MOVE to shooting sub-class? Right place to handle logic
        """
        param_arr = np.array(V[0:len(self.dae.p)]).T.flatten()

        params = {k: v for k, v in zip(self.dae.p, param_arr)}

        # states are wrongly scaled here. TODO: simulate with unscaled params.

        """
        Below:
        First exract w and x simult.
        Then take out x.
        Note: should have dim(x) == dim(w)
        """

        states_noise = V[len(self.dae.p):].reshape((self.dae.n_x, self.N*2)).T
        states = states_noise[0:self.N, :]
        noise = states_noise[self.N:2*self.N, :]

        index = np.arange(0, self.N*self.dt, self.dt, dtype=float)

        states_df = pd.DataFrame(data=np.array(states), \
                                 columns=self.dae.x, \
                                 index=index)

        noise_df = pd.DataFrame(data=np.array(noise), \
                                columns=self.dae.z, \
                                index=index)

        """
        Return noise as well.
        """

        return params, states_df, noise_df


    def transcribe_nlp(self, U, Y, Q, R, scale, parallel=False):
        """ 
        Transcribe the NLP.
        """
        if self.method == "MS":
            # TODO: refactor to instance, not class. re-think the interface. re-assign integrator creation to shooting instance?
            return MultipleShooting(self.integrator, scale, U, Y, Q, R, self.p, parallel=parallel)
        elif self.method == "collocation":
            """
            Conceptually, this (and the intended abstract class)
            should return the nlp_struct with the DAE discretized.

            TODO: how should collocation/inheritance work. 
            am thinking subclassing for each of FSE, MPC, MHE

            First, try to transcribe the NLP w/o any bounds
            symbolically from the DAE:
            """
            self.collocation = Collocation(self.dae, self.ocp)
        else:
            raise NotImplementedError("Only multiple shooting implemented at the moment...")
        #elif strategy == "SS":
        #    pass


    """
    Define as context manager.
    """

    def __enter__(self):
        self.get_files_before()
        return self
    
    def __exit__(self, *a):
        pass
        #self.clean_up_jit()
    