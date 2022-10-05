from casadi import *
import casadi as ca
from abc import ABC, abstractmethod, ABCMeta
from integrators import Integrator, RungeKutta4, Cvodes
import numpy as np
from debug import Debug
import pandas as pd
import matplotlib.pyplot as plt
import pprint


"""
TODO: make this parser abstract.
should be possible to pass a list
of strings with variable names
to parameterize the parser.
"""
class NLPParser:
    """
    NLP (Ipopt) - parser.
    """

    def __init__(self, var):
        self.var = var
        self.label = {
            'df': np.hstack(
                ('time',
                 var['x']['label'],
                    var['u']['label'],
                    var['z']['label'],
                    var['y']['label'])),
            't': 'time',
            'x': var['x']['label'],
            'u': var['u']['label'],
            'z': var['z']['label'],
            'y': var['y']['label']}

    def process(self, time, solution):
        """
        TODO:
        name conflict here:
            - 'x', differential state vars
            - 'x', solution variables of the NLP.
        """
        t = time                          # time vector for open loop simulation
        f = solution['f'].toarray()       # objective function

        g = solution['g'].toarray()       # general non-linear constraints
        lam_g = solution['lam_g'].toarray()

        x = solution['x'].toarray()       # optimization variables
        lam_x = solution['lam_x'].toarray()

        x_k = x[0:self.var['k']['range'] * self.var['nlp']['N']
               ].reshape(self.var['nlp']['N'], self.var['k']['range'])
        x_N = x[self.var['k']['range'] *
               self.var['nlp']['N']:-
               self.var['p']['dim']]

        df = pd.DataFrame(columns=self.label['df'])

        # total grid points per time step:
        coll_offset = (1 + self.var['nlp']['K'])*self.var['nlp']['M']

        for k in range(self.var['nlp']['N']):

            xk = x_k[k][self.var['x']['range']['a']:self.var['x']['range']['b']].reshape(
                (1 + self.var['nlp']['K'])*self.var['nlp']['M'], self.var['x']['dim'])

            uk = x_k[k][self.var['u']['range']['a']:self.var['u']
                       ['range']['b']].reshape(1, self.var['u']['dim'])

            zk = x_k[k][self.var['z']['range']['a']:self.var['z']['range']['b']].reshape(
                (1 + self.var['nlp']['K'])*self.var['nlp']['M'], self.var['z']['dim'])

            yk = x_k[k][self.var['y']['range']['a']:self.var['y']
                       ['range']['b']].reshape(1, self.var['y']['dim'])

            for j in range(coll_offset):

                df.loc[k*coll_offset + j] = \
                     np.hstack((t[k*coll_offset - 1 + j], xk[j], uk.flatten(), zk[j], yk.flatten()))

        # append terminal points (repeat for {u,r})

        xk = x_N[0:self.var['x']['dim']]
        zk = x_N[self.var['x']['dim']:self.var['z']['dim'], ]
        yk = x_N[self.var['z']['dim']:self.var['y']['dim'], ]

        df.loc[self.var['nlp']['N']*coll_offset] = \
                         np.hstack((t[self.var['nlp']['N']*coll_offset], \
                                                            xk.flatten(), \
                                                            uk.flatten(), \
                                                            zk.flatten(), \
                                                            yk.flatten()))

        ol = df
        var = {'x0': df.iloc[0, 1:1 + self.var['x']['dim']],
               'u0': df.iloc[0, 1 + \
                                self.var['x']['dim']:1 + \
                                self.var['x']['dim'] + \
                                self.var['u']['dim']],

               'z0': df.iloc[0, 1 + \
                                self.var['x']['dim'] + \
                                self.var['u']['dim']:1 + \
                                self.var['y']['dim'] + \
                                self.var['u']['dim'] + \
                                self.var['z']['dim']],

               'r0': df.iloc[0, 1 + \
                                self.var['x']['dim'] + \
                                self.var['u']['dim'] + \
                                self.var['z']['dim']:1 + \
                                self.var['y']['dim'] + \
                                self.var['u']['dim'] + \
                                self.var['z']['dim'] + \
                                self.var['y']['dim']],

               'x1': df.iloc[1 + self.var['nlp']['K'], 1:1 + self.var['y']['dim']]}

        warmstart = {'x0': x, 'lam_x0': lam_x, 'lam_g0': lam_g}

        p_start, p_stop = self.var["p"]["range"]["a"], self.var["p"]["range"]["b"]

        p = {name: float(val) for name, val \
             in \
             zip(self.var["p"]["label"], x[p_start:p_stop])}

        ret = {'ol': ol, 'params': p, 'obj': f, 'var': var, 'warmstart': warmstart}

        return ret

    def labels(self):
        return self.label


# abstract class for shooting-strategies

class Shooting(metaclass=ABCMeta):
    @classmethod
    def __subclasshook__(cls, subclass):
        return hasattr(subclass, 'get_expressions') and \
            callable(subclass.get_expressions)

    @abstractmethod
    def get_nlp_struct(self):
        raise NotImplementedError

    @abstractmethod
    def get_residual(self):
        raise NotImplementedError

    @classmethod
    def assert_horizon(cls, Y, U):
        """ Assert Y and U same length. """
        assert Y.shape[0] == U.shape[0]

    @classmethod
    def get_horizon(cls, Y):
        return Y.shape[0]

    @classmethod
    def get_residual(cls, Y, X):
        """
        Residual.

        Xn: propagated state
        Y: measurement data

        TODO:
            - handling of measured states (need h).
         """
        return (Y - X[0, :].T)
        # return (Y[1:] - X[0,:].T)


class MultipleShooting(Shooting):
    """Xn.reshape((X.shape[0], Xn.shape[1]))
    Multiple shooting.

    args:

    Returns:
        -
    """
    def __new__(cls,
                integrator: Integrator,
                scale: DM,
                U: DM,
                Y: DM,
                Q: DM,
                R: DM,
                p: MX,
                parallel=False):

        return cls.get_expressions(
            integrator, scale, U, Y, Q, R, p, parallel=parallel)

    @classmethod
    def get_expressions(cls,
                        integrator: Integrator,
                        scale: DM,
                        U: DM,
                        Y: DM,
                        Q: DM,
                        R: DM,
                        p: MX,
                        parallel=False):
        """
        Transcribe NLP.
        """
        N = cls.get_horizon(Y)

        X = MX.sym("X", integrator.dae.n_x, N)
        # noise:
        W = MX.sym("W", integrator.dae.n_z, N)
        # if parallel:
        #    Xn = integrator.one_sample.map(N, 'openmp')(X, U.T, scale*repmat(p,1,N))
        # else:
        #    Xn = integrator.one_sample.map(N)(X, U.T, repmat(p,1,N))
        Xn = cls.get_states_propagated(
            N, integrator, scale, X, U, p, W, parallel)
        residual = cls.get_residual(Y, Xn)

        """
        TODO: handling of constraints on sub-sampling intervals here.
        """

        gaps = cls.get_states_gap(Xn, X)
        # NLP-variables always in this order -> parsing results easy
        V = veccat(p, X, W)

        """
        Inlcude minimization of noise.
        """

        noise_term = 0

        for n_z in range(integrator.dae.n_z):
            # for n_z in range(1):
            noise_term += 0.5 * \
                dot(W[n_z, :].T, W[n_z, :].T) * (1 / Q[n_z, n_z])

        # build up measurement deviation similarly:

        if isinstance(gaps, list):
            return {'x': V, 'f': 0.5 *
                    dot(residual, residual), 'g': vec(*gaps)}, residual, X
        else:
            return {'x': V, 'f': 0.5 *
                    dot(residual, residual) +
                    noise_term, 'g': vec(gaps)}, residual, X, W

    @classmethod
    def get_states_propagated(cls, N, integrator, scale, X, U, p, W, parallel):
        """
        Propagate states one step forward in each time step.

        TODO: handle algebaric states / noise in all cases.
        """
        if parallel:
            if isinstance(integrator, RungeKutta4):
                return integrator.one_sample.map(N, 'openmp')(
                    X, U.T, scale * repmat(p, 1, N), W)
            elif isinstance(integrator, Cvodes):  # p and u merged
                #raise TypeError("Cvodes not mature..")
                # construct expression 'by hand'
                #Xn = MX.sym("Xn", X.shape[0], N-1)
                #Un = MX.sym("Un", U.shape[1], N)
                # Xn
                U = U.T
                Xn = []

                for n in range(0, N - 1):

                    #Xn[n+1, :] = integrator.one_sample(x0=Xn[n], p=veccat(U[n, :].reshape((U.shape[1], 1)), p))
                    Ik = integrator.one_sample(x0=X[:, n],
                                               p=veccat(p, U[:, n]))

                    #Xn[:, n] = Ik["xf"]
                    Xn.append(Ik["xf"])
                # return integrator.one_sample.map(N, 'openmp')(X,
                # vertcat(repmat(p,1,N), U.T), 0, 0, 0, 0)[0] # return 0th
                # elem, xf
                Xn = veccat(*Xn)
                return Xn.reshape((X.shape[0], X.shape[1] - 1))
        else:
            return integrator.one_sample.map(N)(
                X, U.T, scale * repmat(p, 1, N))

    @classmethod
    def get_states_gap(cls, Xn, X):
        """
        Create equality constraints.

        Xn: one-sample propagated state
        X: unpropagated state
        """
        if isinstance(Xn, list):
            gaps = []
            for n, xn in enumerate(Xn):
                gaps.append(xn - X[:, n + 1])
            return gaps
        else:
            return Xn[:, :-1] - X[:, 1:]
            # return Xn[:,:]-X[:,1:]

    @classmethod
    def get_states(cls, integrator, N):
        return MX.sym("X", integrator.dae.n_x, N)


"""
class SingleShooting(Shooting):

    def __new__(cls):
        pass

    @classmethod
    def get_states_propagated(cls, N, integrator, X, U, p):
        ''' Propagate dynamics through the estimation horizon. '''
        all_samples = integrator.get_one_sample.mapaccum("all_samples", N)
        return all_samples(x0, U, repmat(params*scale,1,N))
"""


"""
Should be an abstract class for this eventually,
with MHE, MPC and param est needing their
respective sub-classes.

TODO: first, make it fit with parameter estimation
problem.
Then, we can generalize.

TODO: Could this be a general 'Transcription' class??

TODO: what about finite elements with this
formulation? implicitly assumed to be 1?
"""


class Collocation(object):

    def __init__(self, ocp, **kwds):
        """
        For interface example, see 3R3C.json.
        """

        super(Collocation, self).__init__()
        #OBS.__init__(self, cfg)
        # order, make option later.

        """
        Options below:
        can pass as kwargs. 
        (own collocation/transcription dict in config.json)
        """
        self.non_uniform_gain = kwds.pop("non_uniform_gain")
        self.method = kwds.pop("roots")
        self.K = kwds.pop("degree")
        self.dt = kwds.pop("dt")
        self.M = kwds.pop("finite_elements")
        self.N = kwds.pop("N")
        self.scale = kwds.pop("scale")
        #self.ipopt_warmstart = False
        #self.linear_solver = "ma27"
        #self.ipopt_verbose = 5
        # Is 'dae' needed now?
        self.ocp = ocp
        #self.max_iter = 10000

        # collocation and sampling horizon setup
        # TODO: is it necessary to have possibility for non-uniform sampling
        # times?
        self.hk = np.exp(np.linspace(0, self.N - 1, self.N)
                         * self.non_uniform_gain) * self.dt
        #self.hk = self.h
        self.tk = np.concatenate([np.array([0]), np.cumsum(self.hk)])

        self.B, self.C, self.D, self.tau, self.debug = CollocationCoeffs(
            {'K': self.K, 'method': self.method}).coef()

        # nlp spesific equation dim
        self.l_n = 1                             # lagrange term dimension
        self.m_n = 1                             # mayer term dimension

        self.f_n = self.ocp.f.shape[0]           # ODE term dimension
        self.g_n = self.ocp.g.shape[0]           # equality term dimension
        self.h_n = self.ocp.h.shape[0]           # inequality term dimension
        # self.c_n = self.ocp.c.shape[0]           # periodical constraiself.P
        # = ca.DM(np.diag(np.ones(cfg['ocp'].y.dim())))t

        # dae contains the needed symbolics:
        self.f = self.ocp.f
        self.g = self.ocp.g
        self.h = self.ocp.h

        # self.f_n = self.f.shape[0]           # ODE term dimension
        # self.g_n = self.g.shape[0]           # equality term dimension

        """
        TODO: what to do with this?
        for parameter estimation,
        this could be e.g. constraints
        on state trajectories?

        """
        #self.h_n = self.ocp.h.shape[0]
        #self.c_n = self.ocp.c.shape[0]

        # nlp specific variables dim
        """
        TODO: fix this:
        """
        self.var = self.extract()

        # construct casadi function handlers

        """
        Instead of OCP, read in model specified via json-format.

        Init var-list here:
        """

        # create MX for time:
        #self.t = t = MX.sym("t")

        """
        List can be conditional on end-use.
        For example, consider the splitting
        of u into tuple (u,r) for MPC
        (distinction between controllable
        and non-controllable inputs).

        For e.g. parameter estimation,
        this is not necessary.
        """

        var_list = [
            self.ocp.t(),
            self.ocp.x(),
            self.ocp.u(),
            self.ocp.z(),
            self.ocp.y(),
            self.ocp.p()
        ]

        """
        var_list = [t, \
                    vertcat(*dae.dae.x), \
                    vertcat(*dae.dae.u), \
                    vertcat(*dae.dae.z), \
                # what 'bout r? separation between control input and external input
                # self.ocp.r.var(), \
                    vertcat(*dae.dae.p)]
        """

        #var_names = map(var_list, lambda x: x.name())
        var_names = ['t', 'x', 'u', 'z', 'y', 'p']

        self.ca_f = ca.Function('f',
                                var_list,
                                [self.f],
                                var_names,
                                ['f']
                                )
        self.ca_g = ca.Function('g',
                                var_list,
                                [self.g],
                                var_names,
                                ['g']
                                )
        #self.ca_g = ca.Function('g', [self.ocp.t.var(), self.ocp.y.var(), self.ocp.u.var(), self.ocp.z.var(), self.ocp.r.var(), self.ocp.p.var()], [self.ocp.g], ['t', 'y', 'u', 'z', 'r', 'p'], ['g'])
        self.ca_h = ca.Function('h',
                                 var_list, \
                                 [self.h], \
                                 var_names, \
                                 ['h'])
        #self.ca_c = ca.Function('c', [self.ocp.y.var()], [self.ocp.c], ['y'], ['c'])

        """
        TODO:
        How to construct objective?
        """
        self.ca_l = ca.Function('l',
                                var_list, \
                                [self.ocp.l],
                                var_names,
                                ['l'])

        """
        residual for gauss-newton:
        """
        self.ca_r = ca.Function('r',
                        var_list, \
                        [self.ocp.r],
                        var_names,
                        ['r'])
        # forget about mayer-term for now:
        #self.ca_m = ca.Function('m', [self.ocp.t.var(), self.ocp.y.var(), self.ocp.u.var(), self.ocp.z.var(), self.ocp.r.var(), self.ocp.p.var()], [self.ocp.m], ['t', 'y', 'u', 'z', 'r', 'p'], ['m'])

        # integration handler for simulations
        self.grid = self.dt * self.tau
        # below is nebensache, fix later.
        self.ca_i = ca.integrator('F','collocation',
                                  {'x':ca.vertcat(self.ocp.x.var(), self.ocp.z.var()),
                                   #'p':ca.vertcat(self.ocp.u.var(),self.ocp.r.var(),self.ocp.p.var()) if self.ocp.r_fn_active else ca.vertcat(self.ocp.u.var(),self.ocp.p.var()),
                                   'p':ca.vertcat(self.ocp.u.var(),self.ocp.p.var()),
                                   'ode':self.ocp.f },
                                  {'tf':self.dt,
                                   'grid':self.grid})
        #
        # NLP problem formulation
        #

        # create nlp variable

        self.create_nlp_framework()

        # instantiate nlp problem

        self.init_nlp()

        # object to extract NLP optimal solution

        self.parse = NLPParser(self.var)

        # update config with NLP var info
        #cfg['var_info'] = self.var_info()

    #
    # helper function to add to nlp structure
    #

    def add_time(self, t_i_j):
        self.nlp_struct['t'].append(t_i_j)

    def add_nlp_var(self, var, lb, ub, var0):
        """
        z - decision variable in the NLP-formulation.
        """

        self.nlp_struct['z'].append(var)
        self.nlp_struct['lbz'].append(lb)
        self.nlp_struct['ubz'].append(ub)
        self.nlp_struct['z0'].append(var0)

    def add_nlp_res(self, res, lbg, ubg):
        """
        g - constraint in the NLP-formulation.
        """
        self.nlp_struct['g'].append(res)
        self.nlp_struct['lbg'].append(lbg)
        self.nlp_struct['ubg'].append(ubg)

    def add_cost(self, cost):
        self.nlp_struct['J'] += cost

    def add_residual(self, cost):
        self.residual += cost

    #
    # setup solver structure
    #

    def init_solver(self):
        """
        Let this stand for now...
        """
        #self.nlp_struct['z'] = ca.vertcat(*self.nlp_struct['z'])
        self.nlp_struct['g'] = ca.vertcat(*self.nlp_struct['g'])
        self.nlp_struct['z0'] = np.concatenate(self.nlp_struct['z0'])
        self.nlp_struct['lbz'] = np.concatenate(self.nlp_struct['lbz'])
        self.nlp_struct['ubz'] = np.concatenate(self.nlp_struct['ubz'])
        self.nlp_struct['lbg'] = np.concatenate(self.nlp_struct['lbg'])
        self.nlp_struct['ubg'] = np.concatenate(self.nlp_struct['ubg'])

        #prob = {
        #    'f': self.nlp_struct['J'],
        #    'x': self.nlp_struct['z'],
        #    'g': self.nlp_struct['g']}
        #if self.ipopt_warmstart:
        #    opts = {'print_time': 0,
        #            'ipopt': {'linear_solver': self.linear_solver,
        #                      'print_level': self.ipopt_verbose,
        #                      'sb': 'yes',
        #                      'warm_start_init_point': 'yes',
        #                      'max_iter': self.max_iter}}
            # 'print_timing_statistics':'yes'}}
        #else:
        #    opts = {'print_time': 0,
        #            'ipopt': {'linear_solver': self.linear_solver,
        #                      'print_level': self.ipopt_verbose,
        #                      'sb': 'yes',
        #                      'max_iter': self.max_iter,
        #                      'constr_viol_tol': 0.1
        #                      }}
            # 'print_level': 8}}

        # TODO: option for solver here: should be able to select sqp directly.

        # TODO: defer solver-obj construction until after bounds have been set.

        #self.nlp_struct['solver'] = ca.nlpsol('solver', 'ipopt', prob, opts)
        #self.nlp_struct["solver"] = ca.nlpsol('solver', 'sqpmethod', prob)

    #
    # initialize nlp skeleton
    #

    # @abstractmethod
    def create_nlp_framework(self):
        """
        This method initializes all the needed variables.

        TODO: this is collocation specific.
        Thinking in terms of ABC, a
        transcription method should define
        this method on its own. But for now
        leave it as is. Instead define methods
        to overwrite lbs and ubs for different
        problem classes.

        TODO: think in terms of modularizing
        this, i.e. splitting up into
        sensible parts (per variable).

        NOTE: This should enable a smooth 
        transition towards creating
        a robust inheritance hierarchy
        for the different problem classes.

        """

        # nlp structure

        self.nlp_struct = {
            't': [],
            'J': 0,
            'z': [],
            'z0': [],
            'lbz': [],
            'ubz': [],
            'g': [],
            'lbg': [],
            'ubg': [],
            'solver': lambda z0, lbz, ubz, lbg, ubg: ()
        }

        self.residual = 0

        # TODO: add option for multiple shooting here
        # also single shooting

        # construct empty NLP variable structure
        for i in range(self.N):

            # add time on phase boundary

            self.add_time(self.tk[i])

            # iterate through finite elements
            for m in range(1, self.M + 1):

                self.add_time(self.tk[i] + self.tau[0]*(self.hk[i]/self.M)*m)

                for j in range(1, self.K + 1):

                    self.add_time(self.tk[i] + self.tau[j]*(self.hk[i]/self.M)*m)

            if self.var['x']['dim']:

                # add differential variable on phase boundary
                """
                self.add_nlp_var(ca.MX.sym(
                    self.ocp.x.name() + '_' + str(i),
                    self.var['x']['dim']),
                    self.ocp.x.lb(),
                    self.ocp.x.ub(),
                    self.ocp.x.lb()
                )
                """

                # add differential collocation variables
                # NOTE: have added finite elements:
                for m in range(self.M):
                    
                    # NOTE: add differential variable on finite element boundary
                    #self.add_nlp_var(
                    #        ca.MX.sym(
                    #            self.ocp.x.name() +
                    #            '_' +
                    #            str(i) +
                    #            '_' +
                    #            str(m) +
                    #            '_0',
                    #            self.var['x']['dim']),
                    #        self.ocp.x.lb(),
                    #        self.ocp.x.ub(),
                    #        self.ocp.x.lb())

                    for j in range(self.K + 1):
                
                        self.add_nlp_var(
                            ca.MX.sym(
                                self.ocp.x.name() +
                                '_' +
                                str(i) +
                                '_' +
                                str(m) +
                                '_' +
                                str(j),
                                self.var['x']['dim']),
                            self.ocp.x.lb(),
                            self.ocp.x.ub(),
                            self.ocp.x.lb())

            if self.var['u']['dim']:

                # add control variable

                self.add_nlp_var(
                    ca.MX.sym(
                        self.ocp.u.name() +
                        '_' +
                        str(i),
                        self.var['u']['dim']),
                    self.ocp.u.lb(),
                    self.ocp.u.ub(),
                    self.ocp.u.lb())

            if self.var['z']['dim']:

                # add algebraic variable on phase boundary

                self.add_nlp_var(
                    ca.MX.sym(
                        self.ocp.z.name() +
                        '_' +
                        str(i),
                        self.var['z']['dim']),
                    self.ocp.z.lb(),
                    self.ocp.z.ub(),
                    self.ocp.z.lb())

                # add algebraic collocation variables
                for m in range(0, self.M):
                    for j in range(1, self.K + 1):

                        self.add_nlp_var(
                            ca.MX.sym(
                                self.ocp.z.name() +
                                '_' +
                                str(i) +
                                '_' +
                                str(m) +
                                '_' +
                                str(j),
                                self.var['z']['dim']),
                            self.ocp.z.lb(),
                            self.ocp.z.ub(),
                            self.ocp.z.lb())

            
            # TODO: before we do this, must
            # add 'y' to self.var
            if self.var['y']['dim']:

                # add measurement variable on phase boundary
                # shift right
                self.add_nlp_var(
                    ca.MX.sym(
                        self.ocp.y.name() +
                        '_' +
                        str(i),
                        self.var['y']['dim']),
                    self.ocp.y.lb(),
                    self.ocp.y.ub(),
                    self.ocp.y.lb())

            # if self.var['r']['dim']:

                # add reference variable

            #    self.add_nlp_var(ca.MX.sym( self.ocp.r.name() + '_' + str(i), self.var['r']['dim'] ), self.ocp.r.lb(), self.ocp.r.ub(), self.ocp.r.lb())

        #
        # add terminal variables
        #

        # terminal time

        self.add_time(self.tk[self.N])

        if self.var['x']['dim']:

            # terminal differential variable

            self.add_nlp_var(
                ca.MX.sym(
                    self.ocp.x.name() + '_' + str(
                        self.N),
                    self.var['x']['dim']),
                self.ocp.x.lb(),
                self.ocp.x.ub(),
                self.ocp.x.lb())

        if self.var['z']['dim']:

            # terminal algebraic variable

            self.add_nlp_var(
                ca.MX.sym(
                    self.ocp.z.name() + '_' + str(
                        self.N),
                    self.var['z']['dim']),
                self.ocp.z.lb(),
                self.ocp.z.ub(),
                self.ocp.z.lb())


        if self.var['y']['dim']:

            # terminal measurement variable

            self.add_nlp_var(
                ca.MX.sym(
                    self.ocp.y.name() + '_' + str(
                        self.N),
                    self.var['y']['dim']),
                self.ocp.y.lb(),
                self.ocp.y.ub(),
                self.ocp.y.lb())

        if self.var['p']['dim']:

            # add constant parameters

            self.add_nlp_var(
                ca.MX.sym(
                    self.ocp.p.name(),
                    self.var['p']['dim']),
                self.ocp.p.lb(),
                self.ocp.p.ub(),
                self.ocp.p.lb())

    # @abstractmethod
    def init_nlp(self):
        """
        This method initializes all constraints lb_g < g(z) < ub_g.
        In addition the objective (sum_i (sum_j l_i,j))

        Collocation-specific.

        TODO: refactor this to one method per action :
        e.g. setting up: 
            - boundary/phase constraints
            - residual constraints
        
        also, per variable. This way it will
        be easier to create a proper
        class hierarchy and robust code.
        """

        t = self.get_t

        #t_0_1_0 = t(0,0,0)

        x = self.get_x
        xc = self.get_xc
        # NOTE: x at finite element:
        xm = self.get_xm
        u = self.get_u
        z = self.get_z
        zc = self.get_zc
        y = self.get_y
        p = self.get_p

        #x_0_1_0 = xc(0,1,0)

        for i in range(self.N):

            #
            # differential equations
            #

            if self.f_n:

                # NOTE: continuity boundary constraints for differential variables
                # NOTE: continuity at the end of each finite element:

                for m in range(self.M):

                    x_i_end = self.D[0] * xm(i, m)

                    for tau_j in range(1, self.K + 1):
                        x_i_end += self.D[tau_j] * xc(i, m, tau_j)
                    
                    # see in page 16-17 in https://lirias.kuleuven.be/retrieve/243411

                    # NOTE: fix x-getter at finite elem.
                    #self.add_nlp_res(x_i_end - xc(i + 1, m + 1, 0),
                    #                np.zeros(self.var['x']['dim']),
                    #                np.zeros(self.var['x']['dim']))
                    self.add_nlp_res(x_i_end - xm(i, m + 1),
                                    np.zeros(self.var['x']['dim']),
                                    np.zeros(self.var['x']['dim']))

                # NOTE: residual constraints on collocation points for differential - 'collocation equations'
                # NOTE: collocation 


                # NOTE: outer loop: finite elems
                for m in range(self.M):

                    for tau_k in range(1, self.K + 1):
                        
                        # x at start of finite element
                        x_i_p = self.C[0, tau_k] * xc(i, m, 0)

                        for tau_j in range(1, self.K + 1):

                            x_i_p += self.C[tau_j, tau_k] * xc(i, m, tau_j)

                        f_tau_k = self.ca_f(t(i, m, tau_k), xc(i, m, tau_k), u(i), zc(i, tau_k), y(i), p())

                        self.add_nlp_res(
                            (self.hk[i]/self.M) * f_tau_k - x_i_p,
                            np.zeros(
                                self.f_n),
                            np.zeros(
                                self.f_n))

            #
            # algebraic equations
            #

            """
            if self.g_n:
                # residual constraints on for algebraic variables
                #g_tau_k = self.ca_g(t(i), y(i), u(i), z(i), r(i), p())
                g_tau_k = self.ca_g(t(i), x(i), u(i), z(i), y(i), p())
                self.add_nlp_res(
                    g_tau_k, np.zeros(
                        self.g_n), np.zeros(
                        self.g_n))
            """
            # TODO: what to do about this? denotes ineqaulity in MPC case,
            # measurement function in case of parameter estimation..
            # simple -> we define them in different subclasses.
            
            """
            if self.h_n:
            #    # residual constraints for in-equality constraints
            #    # NOTE: h_n now measurement function!
                h_tau_k = self.ca_h(t(i), x(i), u(i), z(i), y(i), p())
                self.add_nlp_res(h_tau_k, -np.Inf *
                                 np.ones(self.h_n), np.zeros(self.h_n))
            """
            #
            # cost
            #

            # add lagrange cost
            for m in range(self.M):
                for tau_k in range(self.K + 1):
                    l_tau_k = self.ca_l(t(i, m, tau_k), xc(i, m, tau_k), u(i), zc(i, tau_k), y(i), p())
                    #self.add_cost(self.B[tau_k]*l_tau_k*self.hk[i]) (self.hk[i]/self.M)*(m + 1)
                    #self.add_cost(self.B[tau_k] * l_tau_k * (self.hk[i]/self.M)*(m + 1))
                    self.add_cost(self.B[tau_k] * l_tau_k * (self.hk[i]/self.M))
            
            #for tau_k in range(self.K + 1):
            #l_i = self.ca_l(t(i), x(i), u(i), z(i), y(i), p())
            #self.add_cost(self.B[tau_k] * l_tau_k * self.hk[i])
            #self.add_cost(l_i)

            #l_tau_k = self.ca_l(t(i), x(i), u(i), z(i), y(i), p())
            #self.add_cost(self.B[0] * l_tau_k * self.hk[i])


            # discretize residual as well (in case of G-N)
            for m in range(self.M):
                for tau_k in range(self.K + 1):
                    r_tau_k = self.ca_r(t(i, m, tau_k), xc(i, m, tau_k), u(i), zc(i, tau_k), y(i), p())
                    self.add_residual(self.B[tau_k] * r_tau_k * (self.hk[i]/self.M))
            

        # terminal cost on differential variable (mayer)

        #m_tau_N = self.ca_m(t(self.N), x(self.N), u(
        #    self.N - 1), z(self.N), p())
        #self.add_cost(m_tau_N)

        # terminal constraint
        #self.add_nlp_res(u(self.N-1) - u(self.N-2), np.zeros(self.var['u']['dim']), np.zeros(self.var['u']['dim']))

        # periodical constraints y(0) = y(N)
        # if self.c_n:
        #    self.add_nlp_res(self.ca_c(y(self.N)) - self.ca_c(y(0)), np.zeros(self.c_n), np.zeros(self.c_n))

        #
        # pipe NLP arguments and construct solver

        self.init_solver()

        # print user statistics on creation
        self.nlp_info()

    def solve_ocp(self, y_0, r_0, t_k):

        # initilize using observer, if active
        self.set_y0(self.observer.sample() if self.use_observer else y_0)

        # enforce reference value
        if isinstance(r_0, np.ndarray) is False:
            Debug.MOSIOP_WARNING(
                'Supplied reference not of type:{}. Will be casted'.format(
                    np.array))
            r_0 = np.array(r_0)

        self.set_reference(r_0)

        # call defined solver
        if self.ipopt_warmstart['enabled'] and (
                'init' in self.ipopt_warmstart.keys()):
            solution = self.nlp_struct['solver'](
                x0=self.ipopt_warmstart['init']['x0'],
                lam_x0=self.ipopt_warmstart['init']['lam_x0'],
                lam_g0=self.ipopt_warmstart['init']['lam_g0'],
                lbx=self.nlp_struct['lbz'],
                ubx=self.nlp_struct['ubz'],
                lbg=self.nlp_struct['lbg'],
                ubg=self.nlp_struct['ubg'])
        else:

            # try to filter out -inf in 'lbg':
            #self.nlp_struct['lbg'] = list(map(lambda x: 0 if x is -np.inf else x, self.nlp_struct['lbg']))
            #self.nlp_struct['lbg'] = self.nlp_struct['ubg']

            solution = self.nlp_struct['solver'](x0=self.nlp_struct['z0'],  # + np.random.rand(len(self.nlp_struct['z0']),1),
                                                 lbx=self.nlp_struct['lbz'],
                                                 ubx=self.nlp_struct['ubz'],
                                                 lbg=self.nlp_struct['lbg'],
                                                 ubg=self.nlp_struct['ubg'])

        nlp_stats = self.nlp_struct['solver'].stats()

        if (nlp_stats['success'] != True) or (
                nlp_stats['return_status'] != 'Solve_Succeeded'):
            print(
                'Success: {}; Iter. cnt: {}; Return Status: {}'.format(
                    nlp_stats['success'],
                    nlp_stats['iter_count'],
                    nlp_stats['return_status']))

        if self.debug['debug']:

            df = self.parse.process(self.nlp_struct['t'], solution)

            time = df[0]['time']
            x = df[0].iloc[:, self.debug['state']]
            plt.plot(time[0::self.K + 1],
                     x[0::self.K + 1],
                     linestyle='-',
                     linewidth=0.5,
                     marker='o',
                     markersize=5,
                     color='green',
                     label='$t_i$')
            plt.plot(
                time,
                x,
                linestyle='-',
                linewidth=0.5,
                marker='x',
                markersize=5,
                color='blue',
                label=r'$\tau _i$')

            for k in range(self.N):

                tk = np.array(time[k * (self.K + 1)])
                zk = np.array(x[k * (self.K + 1):(k + 1) * (self.K + 1)])

                t = tk + self.hk[k] * self.debug['tau_i']
                y = np.zeros(t.shape)

                for i in range(len(y)):
                    for j in range(self.K + 1):
                        y[i] += self.debug['D_i'][j, i] * zk[j]

                plt.plot(
                    t,
                    y,
                    linestyle='-',
                    linewidth=0.3,
                    markersize=5,
                    color='red',
                    label=r'$z^{K}(t)$' if k == 0 else "")

            plt.legend(
                loc='upper right',
                prop={
                    'size': 10},
                ncol=1,
                frameon=False)
            plt.title(
                'Collocation debugging for {}'.format(
                    self.debug['disc']))
            plt.xlabel('time')
            plt.ylabel('x')
            plt.savefig('../lib/debug/collocation_debug_' +
                        self.debug['disc'] + '.png', dpi=600)
            plt.show()

            warnings.warn('Disable collocation debugging to continue')

        # extract data from optimal solution
        parsed = self.parse.process(self.nlp_struct['t'], solution)

        # update state estimator
        if self.use_observer:
            self.observer.update(
                {'y_meas': y_0, 'var': parsed['var'], 'p': self.get_parameter()})

        return parsed['ol'], parsed['var']['u0'], parsed['var']['x1']

    def solve_sim(self, y0, u):

        # solve only from one time-step ahead

        if u.ndim == 1:
            return np.array(self.ocp.sim(y0, u)).flatten()

        # solve for multiple time-steps ahead

        y = y0
        for k in range(len(u)):
            print('u=[{}]'.format(u[k]))
            y0 = self.grid, np.append(y0, self.F(x0=y0, p=u[k])['xf'])
            y = np.append(y, y0)

        return y

    #
    # extract OCP related variables
    #

    def extract(self):
        """
        TODO: fix this:
        """

        # this takes into account
        # both finite elements and
        # collocation points:
        coll_offset = self.M*(self.K+1) - 1

        # NOTE: c_off for x and z

        var = {self.ocp.x.name(): {'dim': self.ocp.x.dim(),
                                 'col': self.K,
                                 'N': (self.N + 1) * self.ocp.x.dim(),
                                 'c_N': self.N * self.K * self.M * self.ocp.x.dim(),
                                 'off': 0,
                                 'c_off': 1 if self.ocp.x.dim() else 0,
                                 'range': {'a': 0, 'b': self.ocp.x.dim() * (1 + self.K) * self.M},
                                 'label': self.ocp.n_x_label}}

        var[self.ocp.u.name()] = {'dim': self.ocp.u.dim(),
                                'col': 0,
                                'N': self.N * self.ocp.u.dim(),
                                'c_N': 0,
                                'off': var['x']['c_off'] + (coll_offset if self.ocp.x.dim() else 0),
                                'c_off': var['x']['c_off'] + (coll_offset if self.ocp.x.dim() else 0) + (1 if self.ocp.u.dim() else 0),
                                'range': {'a': var['x']['range']['b'], 'b': var['x']['range']['b'] + self.ocp.u.dim()},
                                'label': self.ocp.n_u_label}

        var[self.ocp.z.name()] = {'dim': self.ocp.z.dim(),
                                'col': self.K,
                                'N': (self.N + 1) * self.ocp.z.dim(),
                                'c_N': self.N*self.K*self.M*self.ocp.z.dim(),
                                'off': var['u']['c_off'],
                                'c_off': var['u']['c_off'] + (1 if self.ocp.z.dim() else 0),
                                'range': {'a': var['u']['range']['b'],
                                          'b': var['u']['range']['b'] + self.ocp.z.dim() * (1 + self.K) * self.M},
                                'label': self.ocp.n_z_label}

        # NOTE: collocate y or not? remember that measurements are only given at t=k...
        # so there is really no need for collocation..
        """
        var[self.ocp.y.name()] = {'dim': self.ocp.y.dim(),
                                'col': self.K,
                                'N': (self.N + 1) * self.ocp.y.dim(),
                                'c_N': self.N * self.K * self.ocp.y.dim(),
                                'off': var['u']['c_off'],
                                'c_off': var['u']['c_off'] + (1 if self.ocp.y.dim() else 0),
                                'range': {'a': var['z']['range']['b'],
                                          'b': var['z']['range']['b'] + self.ocp.y.dim() * (1 + self.K)},
                                'label': self.ocp.n_z_label}s
        
        """
        var[self.ocp.y.name()] = {'dim':self.ocp.y.dim(),
                                  'col':0,
                                  'N':self.N*self.ocp.y.dim(),
                                  'c_N':0,
                                  'off':  var['z']['c_off'] + (coll_offset if self.ocp.z.dim() else 0),
                                  'c_off':var['z']['c_off'] + (coll_offset if self.ocp.z.dim() else 0) + (1 if self.ocp.y.dim() else 0),
                                  'range':{  'a':var['z']['range']['b'], 'b':var['z']['range']['b'] + self.ocp.y.dim() },
                                  'label':self.ocp.n_y_label }


        var[self.ocp.p.name()] = {'dim':self.ocp.p.dim(),
                                  'col':0,
                                  'N':self.ocp.p.dim(),
                                  'c_N':0,
                                  'off':  self.N*var['y']['c_off'] + (1 if self.ocp.y.dim() else 0) + (1 if self.ocp.z.dim() else 0),
                                  'c_off':self.N*var['y']['c_off'] + (1 if self.ocp.y.dim() else 0) + (1 if self.ocp.z.dim() else 0) + (1 if self.ocp.p.dim() else 0) ,
                                  'range':{ 'a':self.N*var['y']['range']['b'] + self.ocp.x.dim() + self.ocp.y.dim() + self.ocp.z.dim(), 'b':self.N*var['y']['range']['b'] + self.ocp.x.dim()+ self.ocp.z.dim() + self.ocp.y.dim() + self.ocp.p.dim() },
                                  'label':self.ocp.n_p_label}
        """

        var[self.ocp.p.name()] = {'dim': self.ocp.p.dim(), 'col': 0, 'N': self.ocp.p.dim(), 'c_N': 0, 
                                'off': \
                                self.N *
                                (var['z']['c_off'] + (self.K if self.ocp.z.dim() else 0)) +
                                (1 if self.ocp.x.dim() else 0) +
                                (1 if self.ocp.z.dim() else 0),
                                'c_off': 
                                self.N *
                                (var['z']['c_off'] + (self.K if self.ocp.z.dim() else 0)) +
                                (1 if self.ocp.x.dim() else 0) +
                                (1 if self.ocp.z.dim() else 0) +
                                (1 if self.ocp.p.dim() else 0), 'range': {'a': self.N *
                                                                          var['z']['range']['b'] +
                                                                          self.ocp.x.dim() +
                                                                          self.ocp.z.dim(), 'b': self.N *
                                                                          var['z']['range']['b'] +
                                                                          self.ocp.x.dim() +
                                                                          self.ocp.z.dim() +
                                                                          self.ocp.p.dim()}, 'label': self.ocp.n_p_label}
        """
        #var['k']               = {'off':var['r']['c_off'],'range':self.ocp.x.dim()*(1+self.K)+self.ocp.u.dim()+self.ocp.z.dim()*(1+self.K)+self.ocp.r.dim() }
        var['k'] = {'off': var['y']['c_off'], \
                    # all:
                   'range': self.ocp.x.dim()*(1 + self.K)*self.M + \
                            self.ocp.u.dim() + \
                            self.ocp.z.dim()*(1 + self.K)*self.M + \
                            self.ocp.y.dim()}
        var['nlp'] = {'K': self.K, 'M': self.M, 'N': self.N}

        return var

    #
    # retrieve variables from created NLP framework
    #

    def get_t(self, k, m=0, j=0):

        if k < 0 or k > self.N:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N))

        if m < 0 or m > self.M - 1 :
            #warnings.warn(
            #    'chosen finite element m={} outside of bounds [0,{}]'.format(
            #        m, self.M - 1))
            raise ValueError("chosen finite element" +
                             " m={} outside of bounds [0,{}]" 
                             % ((m, self.M - 1)))

        # m*(self.K + 1) + j - 1
        return self.nlp_struct['t'][k*((1 + self.K)*self.M) + (1 + self.K)*m + j]


    def get_x(self, k):

        """
        if k < 0 or k > self.N:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N))
        """
        if self.var['x']['dim']:
            #return self.nlp_struct['z'][k * self.var['k']['off']]
            return self.get_xc(k, 0, 0)
        #return self.ocp.x.var()
    
        return self.ocp.x()


    def get_xm(self, k, m):

        """
        get x at finite element.

        if k < 0 or k > self.N:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N))
        """
        if self.var['x']['dim']:
            #return self.nlp_struct['z'][k * self.var['k']['off']]

            if m > self.M - 1: # next
                return self.get_xc(k + 1, 0, 0)    
            else:
                return self.get_xc(k, m, 0)
    
        return self.ocp.x()

    def get_xc(self, k, m, j):

        if k < 0 or k > self.N - 1:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N - 1))

        if m < 0 or m > (self.M - 1):
            warnings.warn(
                'chosen finite element m={} for x outside of bounds [0,{}]'.format(
                    m, self.M))

        if j < 0 or j > self.K:
            warnings.warn(
                'chosen collocation point j={} for x outside of bounds [0,{}]'.format(
                    j, self.K))

        if self.var['x']['dim']:
            return self.nlp_struct['z'][k*self.var['k']['off'] + self.var['x']['c_off'] + m*(self.K + 1) + j - 1]
        return self.ocp.x()

    def get_u(self, k):

        if k < 0 or k > self.N - 1:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N - 1))

        if self.var['u']['dim']:
            return self.nlp_struct['z'][k*self.var['k']['off'] + self.var['u']['off']]
        return self.ocp.u()


    def get_y(self, k):

        if k < 0 or k > self.N - 1:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N - 1))


        # FIXME: handle end point (y_N)
        if self.var['y']['dim']:
            return self.nlp_struct['z'][k*self.var['k']['off'] + self.var['y']['off']]
        return self.ocp.y()

    def get_z(self, k):

        if k < 0 or k > self.N:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N))

        if self.var['z']['dim']:
            if k < self.N:
                return self.nlp_struct['z'][k *
                                            self.var['k']['off'] +
                                            self.var['z']['off']]
            return self.nlp_struct['z'][k * self.var['k']['off'] + 1]
        return self.ocp.z.var()

    def get_zc(self, k, j):

        if k < 0 or k > self.N - 1:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N - 1))

        if j < 0 or j > self.K:
            warnings.warn(
                'chosen collocation point j={} for z outside of bounds [0,{}]'.format(
                    j, self.K))

        if self.var['z']['dim']:
            return self.nlp_struct['z'][k * self.var['k']
                                        ['off'] + self.var['z']['c_off'] + j - 1]
        return self.ocp.z.var()

    def get_r(self, k):

        if k < 0 or k > self.N - 1:
            warnings.warn(
                'chosen stage k={} outside of bounds [0,{}]'.format(
                    k, self.N - 1))

        if self.var['r']['dim']:
            return self.nlp_struct['z'][k * self.var['k']
                                        ['off'] + self.var['r']['off']]
        return self.ocp.r.var()

    def get_p(self):

        if self.var['p']['dim']:
            # with scale:
            return self.nlp_struct['z'][self.var['p']['c_off']]*self.scale
        return self.ocp.p.var()

    def set_y0(self, y0):

        # enforce reference value
        if isinstance(y0, np.ndarray) is False:
            Debug.MOSIOP_WARNING(
                'Supplied reference not of type:{}. Will be casted'.format(
                    np.array))
            y0 = np.array(y0)

        try:

            assert(np.array(y0).size == self.var['y']['dim'])

            if self.y0['fixed']:

                self.nlp_struct['z0'][0:self.var['y']['dim']] = y0
                self.nlp_struct['lbz'][0:self.var['y']['dim']] = y0
                self.nlp_struct['ubz'][0:self.var['y']['dim']] = y0

            else:

                Debug.MOSIOP_NOTICE(
                    'Ignore initial conditions for fixed config')

        except BaseException:

            Debug.MOSIOP_WARNING(
                'Cannot evaluate intial conditions {}. Set to default initial conditions {}'.format(
                    y0, self.ocp.y0))

            self.nlp_struct['z0'][0:self.var['y']['dim']] = self.ocp.y0
            self.nlp_struct['lbz'][0:self.var['y']['dim']] = self.ocp.y0
            self.nlp_struct['ubz'][0:self.var['y']['dim']] = self.ocp.y0

            return

    def get_y0(self):
        return self.nlp_struct['z0'][0:self.var['y']['dim']]

    def set_reference(self, r):

        if r.shape[0] == 0:
            return

        for k in range(0, self.N):
            self.nlp_struct['z0'][k *
                                  self.var['k']['range'] +
                                  self.var['r']['range']['a']:k *
                                  self.var['k']['range'] +
                                  self.var['r']['range']['b']] = r[k]
            self.nlp_struct['lbz'][k *
                                   self.var['k']['range'] +
                                   self.var['r']['range']['a']:k *
                                   self.var['k']['range'] +
                                   self.var['r']['range']['b']] = r[k]
            self.nlp_struct['ubz'][k *
                                   self.var['k']['range'] +
                                   self.var['r']['range']['a']:k *
                                   self.var['k']['range'] +
                                   self.var['r']['range']['b']] = r[k]

    def set_parameter(self, p):

        assert(
            p.shape[0] == (
                self.var['p']['range']['b'] -
                self.var['p']['range']['a']))

        self.nlp_struct['z0'][self.var['p']['range']
                              ['a']:self.var['p']['range']['b']] = p
        self.nlp_struct['lbz'][self.var['p']['range']
                               ['a']:self.var['p']['range']['b']] = p
        self.nlp_struct['ubz'][self.var['p']['range']
                               ['a']:self.var['p']['range']['b']] = p

    def get_parameter(self):
        return self.nlp_struct['z0'][self.var['p'][
            'range']['a']:self.var['p']['range']['b']]

    def get_labels(self):
        return self.parse.labels()

    def nlp_info(self):

        columns = [
            'Dimension:',
            'Boundary variables:',
            'Collocation points:',
            'Total variables:',
            'Variable range:']
        index = ['x', 'u', 'z', 'y', 'p']
        data = []
        for i in index:
            data.append(
                (self.var[i]['dim'],
                 self.var[i]['N'],
                    self.var[i]['c_N'],
                    self.var[i]['N'] + self.var[i]['c_N'],
                    '[' + str(
                    self.var[i]['range']['a']) + ', ' + str(
                    self.var[i]['range']['b']) + ')'))
        df = pd.DataFrame(data, columns=columns, index=index).transpose()
        df.style.set_caption(
            'NLP variable structure for N={} and K={}'.format(
                self.N, self.K))
        print(df)

    def var_info(self):

        index = ['y', 'u', 'z', 'r', 'p']
        data = {}
        for i in index:
            data[i] = {
                'dim': self.var[i]['dim'],
                'labels': self.var[i]['label']}
        return data


class CollocationCoeffs(object):
    """
    Singleton?
    """

    def __init__(self, cfg):
        self.cfg = cfg

    def coef(self, debug=False):

        K = self.cfg['K']
        B = np.zeros(K + 1)
        C = np.zeros((K + 1, K + 1))
        D = np.zeros(K + 1)

        tau_root = np.append(0, ca.collocation_points(K, self.cfg['method']))

        # For debugging, plot a over sampled polynomial approximation

        if debug:

            N = 100
            tau_i = np.linspace(0, 1, N)
            D_i = np.zeros((K + 1, N))

        for j in range(K + 1):

            # construct polynomial for j-th collocation point
            lj = np.poly1d([1])
            for k in range(K + 1):
                if k != j:
                    lj *= np.poly1d([1, -tau_root[k]]) / \
                        (tau_root[j] - tau_root[k])

            # coefficients continuity equations
            D[j] = lj(1.0)

            if debug:
                for k in range(N):
                    # see 10.4 in Bieglers book to subsample
                    D_i[j, k] = lj(tau_i[k])

            # coefficients for collocation equations

            dlj = np.polyder(lj)
            for k in range(K + 1):
                C[j, k] = dlj(tau_root[k])

            # coefficients for
            ilj = np.polyint(lj)
            B[j] = ilj(1.0)

        return B, C, D, tau_root, {'debug': debug, 'N': N, 'tau_i': tau_i, 'D_i': D_i,
                                   'state': 2, 'disc': self.cfg['method'] + ' K=' + str(K)} if debug else {'debug': debug}
