from argparse import ArgumentError
from tabnanny import check
import casadi as ca
from casadi import *
from abc import ABC, abstractmethod, ABCMeta
import pandas as pd
import numpy as np
import json

#from tables import Col
from sysid.integrators import RungeKutta4, Cvodes
from sysid.dae import DAE
from sysid.shooting import MultipleShooting
from sysid.callback import ProcessIdCallback
import os
from sysid.shooting import Collocation, NLPParser
from sysid.ocp import OCP, DetFSE, StochFSE
#import typing
import pprint


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
                 data,
                 solver="gauss_newton",
                 codegen=True,
                 scale=None
                 ):
        """
        Starting point.
        """
        if isinstance(config, str) or isinstance(config, os.PathLike):
            with open(config, "r") as f:
                config = json.load(f)

        self.dae = dae = DAE(config["model"])
        self.scale = scale
        """
        Here: use dae and config to create a OCP:
        """

        ######### abstract: #############
        #self.dt = config["dt"]
        #self.n_steps = config["n_steps"]
        #self.method = config["method"]
        self.opt_config = config["opt"]
        self.stochastic = bool(config.pop("stochastic", False))
        ##################################

        ### problem-specific:
        self.R = ca.DM(np.diag(config["R"]))
        self.Q = ca.DM(np.diag(config["Q"]))

        # problem specific:
        if self.stochastic:
            self.ocp = StochFSE(dae, **config)
        else:
            self.ocp = DetFSE(dae, **config)
        ############ abstract ############:
        #if self.method in ("MS", "SS"):
            # can we generalize the integrator class ?? 
        #    self.integrator = RungeKutta4(self.dt, self.n_steps, self.dae)
        #else: # collocation method:
        #    pass
            # wait on integrator init.
            # it is actually questionable whether 
            # 'low-level' work such as creating
            # integrators should be done here.

        #self.integrator = Cvodes(self.dt, self.dae)
        # ipopt/casadi settings

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
        #######################################

        trans_config = config.pop("transcription")

        self.transcribe_nlp(data, **trans_config)
        

    @property
    def p(self):
        return vertcat(*self.dae.dae.p)
    
    @property
    def x(self):
        return self.dae.dae.x
    
    @property
    def u(self):
        return self.dae.dae.u

    """
    def x_boundary(self, i):

        offset = self.var["k"]["range"]

        base = self.var["x"]["range"]["a"]

        # see https://numpy.org/doc/stable/reference/generated/numpy.r_.html
        bounds = np.r_[[ \
                        range(offset*i + base, offset*i + base + self.var["x"]["dim"]) \
                        for i in range(0, self.N) \
                      ]]

        return self.nlp_struct["z"][bounds[i]]
    

    @property
    def y_boundary(self):
        return self.nlp_struct["z"][
                                    np.arange
                                             (
                                                self.var["y"]["off"], \
                                                self.var["y"]["off"] + self.var["k"]["range"]*self.N, \
                                                self.var["k"]["range"]
                                             )
                                    ]
    """

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
        for eq in self.dae.dae.y: # y - measurement equations:
            try: 
                h_names.append(eq.name())
            except RuntimeError as e:
                # trivial equation, MX(0)
                check_msg1 = "'name' not defined for class N6casadi8ConstantINS_16CompiletimeConstILi0EEEEE"
                check_msg2 = "'name' not defined for class N6casadi8BinaryMXILb1ELb0EEE" 
                assert check_msg1 in str(e) or check_msg2 in str(e)
        return h_names
            
    
    # TODO: handle SQP etc. 
    def init_solver(self, \
                residual, \
                ubg=None, \
                lbg=None, \
                with_cb=False,
                algorithm=None):
        """
        Gauss-newton solver for faster (super-quadratic) convergence.

        NOTE: sensitive to initial guess z0.
        TODO: implement LM-algorithm.
        """

        #J = jacobian(residual,self.collocation.nlp_struct["z"])
        #H = triu(mtimes(J.T, J))
        #sigma = MX.sym("sigma")

        opts = dict(
                    jit=self.with_jit, \
                    compiler=self.compiler, \
                    **self.opt_config
                    )


        if algorithm == "gauss-newton":
            
            J = jacobian(residual,self.collocation.nlp_struct["z"])
            H = triu(mtimes(J.T, J))
            sigma = MX.sym("sigma")

            opts["hess_lag"] = Function(
                                        'nlp_hess_l', \
                                        {'z':self.collocation.nlp_struct["z"], \
                                        'lam_f':sigma, \
                                        'hess_gamma_z_z':sigma*H},
                                        ['z','p','lam_f','lam_g'], \
                                        ['hess_gamma_z_z'],
                                        dict(jit=self.with_jit, \
                                        compiler=self.compiler)
                                        )
        #else:
        #    hess_lag = None

        #opts = dict(hess_lag=hess_lag,
        #            jit=self.with_jit, \
        #            compiler=self.compiler, \
        #            **self.opt_config)

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
            opts['iteration_callback'] = mycallback

        #return nlpsol("solver", \
        #              "ipopt", \
        #               self.collocation.nlp_struct, \
        #               opts)

        ####### manually construct J ##############:
        
        x = self.collocation.get_x
        y = self.collocation.get_y
        u = self.collocation.get_u
        xc = self.collocation.get_xc

        residual = 0

        self.x_b = []
        self.y_b = []
        self.x_c = []
        self.u_b = []
        self.p_var = self.collocation.get_p()

        for i in range(self.N):

            residual += x(i)[0] - y(i)
            self.x_b.append(x(i))
            self.y_b.append(y(i))
            self.u_b.append(u(i))

            for m in range(self.collocation.M):
                for k in range(self.collocation.K + 1):
                    self.x_c.append(xc(i, m, k))

        self.nlp_struct["f"] = dot(residual, residual)

        #l_func = self.collocation.ca_l

        #l_map = l_func.map(N)
        #obj_test_l = l_map(0, X_test, U, 0, Y, repmat(params, 1, N))
        #obj_test_lmap = sum(obj_test_l[n] for n in range(N))
        
        """
        obj = 0
        for n in range(self.N):
            x = self.x_b[n]
            y = self.y_b[n]
            obj += self.collocation.ca_l(0, x, 0, 0, y, self.collocation.get_p())
            


        #self.nlp_struct["f"] = self.nlp_struct["J"]
        #self.nlp_struct["J"] = dot(residual, residual)
        self.nlp_struct["J"] = obj
        """
        
        ###########################################
        self.nlp_struct['z'] = ca.vertcat(*self.nlp_struct['z'])
        """
        self.nlp_struct['g'] = ca.vertcat(*self.nlp_struct['g'])
        self.nlp_struct['z0'] = np.concatenate(self.nlp_struct['z0'])
        self.nlp_struct['lbz'] = np.concatenate(self.nlp_struct['lbz'])
        self.nlp_struct['ubz'] = np.concatenate(self.nlp_struct['ubz'])
        self.nlp_struct['lbg'] = np.concatenate(self.nlp_struct['lbg'])
        self.nlp_struct['ubg'] = np.concatenate(self.nlp_struct['ubg'])
        """


        prob = {
                'f': self.nlp_struct['J'],
                'x': self.nlp_struct['z'],
                'g': self.nlp_struct['g']
               }

        # TODO: solver selection:
        self.nlp_struct["solver"] = nlpsol("solver", "ipopt", prob, opts)


    def set_bounds_p(self, lbp, ubp):
        
        # use self.collocation.var and
        # self.collocation.nlp_struct
        # to set proper bounds for
        # the parameter estimation problem.

        var = self.collocation.var
        nlp_struct = self.collocation.nlp_struct

        nlp_struct["lbz"][var["p"]["range"]["a"]:var["p"]["range"]["b"]] = lbp
        nlp_struct["ubz"][var["p"]["range"]["a"]:var["p"]["range"]["b"]] = ubp


    # NOTE: this is collocation specific?
    # NOTE: param est specific?
    # NOTE: abstract method
    def set_bounds_var(self, lb, ub, _varname=None):
        """
        Constrains collocated 
        trajectory
        from below and above.

        For bounds passed in:
            dim(lbx) = dim(ubx) = N

        Hence, the arrays have to
        be expanded appropriately.
        We want dim(lbx) = (K+1)*(N-1) + 1 

        Args:
            lbx (np.array): lower bound for state trajectory
            ubx (np.array): upper ----------"---------------

        TODO: fix for end state x_end
        """

        # use self.collocation.var and
        # self.collocation.nlp_struct
        # to set proper bounds for
        # the parameter estimation problem.

        var = self.collocation.var
        nlp_struct = self.collocation.nlp_struct
        K = self.collocation.K
        M = self.collocation.M
        
        # find indices for state constraints
        # (NOTE: they are not sequential in
        #  'nlp_struct')

        # to next x:  
        # 
        # TODO: consider adding this info to 'var':      
        #################################################################
        
        """
        if _varname == "x":

            n_skip = var["u"]["dim"] + \
                    (K+1)*var["z"]["dim"] + \
                    var["y"]["dim"]

        elif _varname == "z":

            n_skip = var["u"]["dim"] + \
                        (K+1)*var["x"]["dim"] + \
                        var["y"]["dim"]

        elif _varname == "y":

            n_skip = var["u"]["dim"] + \
                        (K+1)*var["x"]["dim"] + \
                        (K+1)*var["z"]["dim"]

        elif _varname == "u":

            n_skip = var["y"]["dim"] + \
                        (K+1)*var["x"]["dim"] + \
                        (K+1)*var["z"]["dim"]
        """
        ####################################################################

        coll_dim = var[_varname]["range"]["b"] - var[_varname]["range"]["a"]

        """
        One finite element
        (all ocp-vars except p):
        """
        #offset = var["y"]["dim"] + \
        #        (K+1)*var["x"]["dim"] + \
        #        (K+1)*var["z"]["dim"] + \
        #        var["u"]["dim"]
        offset = var["k"]["range"]

        base = var[_varname]["range"]["a"]

        # see https://numpy.org/doc/stable/reference/generated/numpy.r_.html
        bounds = np.r_[[ \
                        range(offset*i + base, offset*i + base + coll_dim) \
                        for i in range(0, self.N) \
                      ]]
    
        # expand bounds to fit collocation:

        #if _varname == "x":
        #    pass

        if not len(lb) == len(bounds): # for x, z
            lb = np.repeat(lb, (K+1)*M, axis=0).T
            ub = np.repeat(ub, (K+1)*M, axis=0).T
        

        if bounds.shape == lb.shape:
            nlp_struct["lbz"][bounds] = lb
            nlp_struct["ubz"][bounds] = ub
        else:
            # reshape indices or bounds?
            bounds = np.reshape(bounds, lb.shape)

            nlp_struct["lbz"][bounds] = lb
            nlp_struct["ubz"][bounds] = ub

        # TODO: fix for end state...
        if _varname in ("x", "z"):

            # different handling of y, as u has no variable at t = N
            # subtract collocation points:
            if _varname == "z":
                base = base - K*M*var["x"]["dim"] - K*M*var["z"]["dim"] - var["u"]["dim"]

            start, vardim = offset*self.N + base, var[_varname]["dim"]
            b_start = K*vardim
            b_end = (K+1)*M*vardim

            _slice = np.r_[start:start+vardim]

            if bounds.ndim > 1:
            
                nlp_struct["lbz"][_slice] = lb[-1, b_start:b_end]
                nlp_struct["ubz"][_slice] = ub[-1, b_start:b_end]

            else:
                # TODO: find root cause of this difference and eliminate...
                nlp_struct["lbz"][_slice] = lb[-1*vardim:]
                nlp_struct["ubz"][_slice] = ub[-1*vardim:]

            #nlp_struct["lbz"][_slice] = lb[b_start:b_end]
            #nlp_struct["ubz"][_slice] = ub[b_start:b_end]

            #nlp_struct["lbz"][_slice] = lb[-1*vardim:]
            #nlp_struct["ubz"][_slice] = ub[-1*vardim:]

            # keep bounds for x:
            # for setting z0 (x0)
            if _varname == "x":
                self.x_bounds = np.append(bounds, _slice)

        elif _varname in ("y", "u"):

            nlp_struct["z0"][bounds] = lb

            if _varname == "y":

                #base = base - (((K+1)*M) - 1)*var["x"]["dim"] - K*M*var["z"]["dim"] - var["u"]["dim"]
                #start, vardim = offset*self.N + base, var[_varname]["dim"]
                y_dim = var["y"]["dim"]

                #_slice = np.r_[start:start+vardim]
                start = var["k"]["range"]*(var["nlp"]["N"] - 1) + \
                        var["z"]["dim"] + \
                        var["x"]["dim"] + \
                        var["u"]["dim"] + \
                        var["y"]["range"]["a"]
                #self.nlp_struct["z"][offset]
                _slice = np.r_[start:(start + y_dim)]


                nlp_struct["lbz"][_slice] = lb[-1*y_dim:]
                nlp_struct["ubz"][_slice] = ub[-1*y_dim:]
                nlp_struct["z0"][_slice] = ub[-1*y_dim:]


    #def get_bound_inds_x(self):


    def set_bounds_z(self, lbz, ubz):
        """_summary_

        Args:
            lbz (_type_): _description_
            ubz (_type_): _description_
        """
        self.set_bounds_var(lbz, ubz, _varname="z")

    def set_bounds_x(self, lbx, ubx):
        """_summary_

        Args:
            lbx (_type_): _description_
            ubx (_type_): _description_
        """
        self.set_bounds_var(lbx, ubx, _varname="x")


    # for parameter estimation problem:
    def set_bounds_y(self, Y):
        """
        Y contains the measurements.

        Args:
            lbx (_type_): _description_
            ubx (_type_): _description_
        """
        self.set_bounds_var(Y, Y, _varname="y")

    def set_bounds_u(self, U):
        """
        U contains the controls.

        Args:
            lbx (_type_): _description_
            ubx (_type_): _description_
        """
        self.set_bounds_var(U, U, _varname="u")


    #def estimate(self, U, Y, param_guess=None, scale=None, strategy = "MS", keep_misc=True):
    #def estimate(self, df, param_guess=None, scale=None, keep_misc=True, single=None, parallel=False):
    def set_bounds(self, \
                    lbp=None,
                    ubp=None,
                    lbx=None,
                    ubx=None
                    #scale=None
                    ):
        """
        Transcribe problem symbolically.

        Set bounds for:
            - p
            - x
            - y (fixed)
            - u (fixed)
        
        w/z enters directly in the objective,
        hence no need to constrain it. 

        """

        if lbp is not None and ubp is not None:
            # only if both are non-None:
            self.set_bounds_p(lbp, ubp)
        else:
            # assert that both are None
            assert lbp is None and ubp is None

        if lbx is not None and ubx is not None:
            # only if both are non-None:
            self.set_bounds_x(lbx, ubx)
        else:
            # assert that both are None
            # TODO: fix
            #pass
            # inf is default:

            if lbx is None:
                lbx = np.repeat([-np.inf]*self.ocp.x.dim(), self.collocation.N)
            if ubx is None:
                ubx = np.repeat([np.inf]*self.ocp.x.dim(), self.collocation.N)

            self.set_bounds_x(lbx, ubx)
        ################ param estimation specific ################

        # refer to self:
        self.set_bounds_u(self.U)
        self.set_bounds_y(self.Y)

        ############################################################

    def remove_inf_z0(self):
        self.nlp_struct["z0"][self.nlp_struct["z0"] == -np.inf] = 0
        
    def solve_ocp(self, \
                  param_guess=None, 
                  x0=None, 
                  lbp=None, 
                  ubp=None, 
                  lbx=None,
                  ubx=None,
                  algorithm=None,
                  solver="ipopt"):
        """
        TODO: implement more meta-solvers:
            - Levenberg-Marquandt
            - BFGBS?

        TODO: pass whole z0 or just param guess?
            
        TODO: solver opts via config.

        x0 - initial guess for state trajectory.
        """
        
        # TODO: need symbolic residual for inst. of GN-solver.

        self.set_bounds(lbp=lbp,
                        ubp=ubp,
                        lbx=lbx,
                        ubx=ubx)

        self.set_z0(param_guess, x0)

        # rewrite:
        if -np.inf in self.nlp_struct["z0"]: 
            self.remove_inf_z0()

        if not hasattr(self, "solver"):
            # grab residual.
            residual = self.collocation.residual
            self.init_solver(residual, algorithm=algorithm) 

        # shortcut:
        self.solver = self.nlp_struct["solver"]

        #sol = self.solver(x0=x0,lbg=lbg,ubg=ubg)

        solution = self.solver(x0=self.collocation.nlp_struct["z0"], 
                                lbg=self.collocation.nlp_struct["lbg"], 
                                ubg=self.collocation.nlp_struct["ubg"], 
                                lbx=self.collocation.nlp_struct["lbz"], 
                                ubx=self.collocation.nlp_struct["ubz"])

        # parse
        self.parser = NLPParser(self.collocation.var)

        nlp_stats = self.nlp_struct['solver'].stats()
        
        if (nlp_stats['success'] != True) or (
                nlp_stats['return_status'] != 'Solve_Succeeded'):
            print(
                'Success: {}; Iter. cnt: {}; Return Status: {}'.format(
                    nlp_stats['success'],
                    nlp_stats['iter_count'],
                    nlp_stats['return_status']))

        parsed = self.parser.process(self.nlp_struct['t'], solution)

        return parsed

        ##################
        #self.clean_up_jit()
        ##################

        #if keep_misc:
        #    self.sol = sol
        # parse the solution:
        #params, states_df, noise_df = self.parse_nlp_res(x, scale)

        #return params, states_df, noise_df
    
    def set_z0(self, p0, x0):
        """
        p0 - initial guess for parameters
        x0 - initial guess for parameters
        """
        K = self.collocation.K
        M = self.collocation.M
        var = self.collocation.var

        if x0 is None:
            # take values from Y
            x0 = self.Y
            # fill in for collocation:
            x0 = np.repeat(x0, (K+1)*M, axis=0).T
            # append for end state
            x0 = np.append(x0, x0[:,-1])
            """
            Expand if needed, i.e.:
                dim(x) > dim(y)
            E.g. if dim(x) = 3, dim(y) = 1
                x0 = np.repeat(x0, dim(x), axis=1)

            TODO: fix for dim(y) > 1
            """
            x0 = np.repeat(x0, var["x"]["dim"])

        if p0 is None: # recover by using lb
            raise ValueError("Must provide an initial guess for the parameter est.")

        z0 = np.append(x0, p0)


        # TODO: get these bounds as rest of problem is
        # set up.
        p0_bounds = np.r_[var["p"]["range"]["a"]:var["p"]["range"]["b"]]
        # bounds for NLP 'z0':
        z0_bounds = np.append(self.x_bounds, \
                              p0_bounds)

        self.collocation.nlp_struct["z0"][z0_bounds] = z0


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


    #def transcribe_nlp(self, U, Y, Q, R, scale, parallel=False):
    def transcribe_nlp(self,
                       df: pd.DataFrame, 
                       **kwds
                       ):
        """ 
        Transcribe the NLP.

        TODO: is 'ocp' needed or can we use self?

        TODO: implement auto-scaling for the NLP:
        from math import log10, floor
        def find_exp(number) -> int:
            base10 = log10(abs(number))
            return floor(base10)
        

        """

        ############### INFER from DATA #####################

        self.N = len(df)

        # we expect an exact match for the names.
        self.U = df[self.u_names].values
        self.Y = df[self.h_names].values

        # for consistency:
        assert self.U.shape[0] == self.Y.shape[0]

        # default?
        self.method = kwds.pop("method")

        # add arguments from data:
        if "N" not in kwds:
            kwds["N"] = self.N

        if "scale" not in kwds:
            kwds["scale"] = self.scale

        if "dt" not in kwds: # assume seconds TODO: handle datetime etc.

            dt = df.index[1] - df.index[0]
            
            if isinstance(df.index, pd.DatetimeIndex) \
                 or \
                isinstance(df.index, pd.TimedeltaIndex):

                kwds["dt"] =  dt.seconds

            else:
                # warning: assume SI-units -> seconds. 
                kwds["dt"] =  dt
            

        ######################################################

        if self.method == "MS":

            # FIXME


            # TODO: refactor to instance, not class. re-think the interface. re-assign integrator creation to shooting instance?

            # NOTE: want to have this similar to collocation: 
            # should not return anything via class-methods,
            # but keep the object.

            # TODO: refactor multiple shooting code to be similar to collocation.
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

            # TODO: this object contains 'nlp_struct'
            # and 'var'. These objs are only things
            # needed to complete the NLP-formulation.

            self.collocation = Collocation(self.ocp, **kwds)
            self.nlp_struct = self.collocation.nlp_struct
            self.var = self.collocation.var
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
    

    ######################################## OLD CODE #################################################
        #def estimate(self, U, Y, param_guess=None, scale=None, strategy = "MS", keep_misc=True):
    #def estimate(self, df, param_guess=None, scale=None, keep_misc=True, single=None, parallel=False):

    """
    def transcribe(self, \
                    df: pd.DataFrame, \
                    param_guess=None, \
                    lbp=None, \
                    ubp=None, \
                    lbx=None, \
                    ubx=None, \
                    scale=None):

        Transcribe problem symbolically.

        Set bounds for:
            - p
            - x
            - y (fixed)
            - u (fixed)
        
        w/z enters directly in the objective,
        hence no need to constrain it. 

        
        ### get list of files in directory before jitting ###

        # TODO: clean up below:

        #if single is None:p

        self.N = len(df)

        # we expect an exact match for the names.
        U = df[self.u_names].values
        self.Y = Y = df[self.h_names].values

        # for consistency:
        assert U.shape[0] == Y.shape[0]

        # TODO: refactor this:
        #self.nlp_struct, residual, X, W = self.transcribe_nlp(U, Y, self.Q, self.R, scale, parallel=parallel)

        # This sets 'nlp_struct':
        # TODO: this transcription should
        # be purely symbolical.
        self.transcribe_nlp(self.ocp)

        if lbp is not None and ubp is not None:
            # only if both are non-None:
            self.set_bounds_p(lbp, ubp)
        else:
            # assert that both are None
            assert lbp is None and ubp is None

        if lbx is not None and ubx is not None:
            # only if both are non-None:
            self.set_bounds_x(lbx, ubx)
        else:
            # assert that both are None
            assert lbx is None and ubx is None

        self.set_bounds_u(U)
        self.set_bounds_y(Y)

    
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
    
        #self.nlp_struct["g"] = self.g

        # TODO: need symbolic residual for inst. of GN-solver.
        
        #self.solver = self.gauss_newton_solver(residual) 

        # should be some selection of strategy for guessing state trajectory

        ### solve block ###

        ### the GUESSING here is of vital importance ###
        #yd = np.diff(Y,axis=0)*(1/self.dt)

        #add_states = []

        #for n in range(self.dae.n_x - self.dae.n_h):
        #for n in range(self.dae.n_x - len(self.h_names)):
        #    add_states.append(Y)

        # fix X_guess.shape, W_guess.shape            
        #X_guess = horzcat(Y, horzcat(*add_states)).T
        #W_guess = repmat(DM([0,0,0]), 1, X_guess.shape[1])

        #x0 = veccat(param_guess,X_guess, W_guess)

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

        #sol = self.solver(x0=x0,lbg=lbg,ubg=ubg)
        ##################
        #self.clean_up_jit()
        ##################

        #x = sol.pop("x")

        #if keep_misc:
        #    self.sol = sol
        # parse the solution:
        #params, states_df, noise_df = self.parse_nlp_res(x, scale)

        #return params, states_df, noise_df

