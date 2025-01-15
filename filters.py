#from lib.core.ocp import OCP
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import pdb
import casadi as ca
import os
import json
from ocp.dae import DAE
import ocp.integrators as integrators
from copy import deepcopy
from scipy.linalg import expm

'''
EKF implementations.
'''

class Filter(object):
    """
    General filtering class (cleanup needed)
    """
    def __init__(self, cfg, **kwds):
        if isinstance(cfg, str) or isinstance(cfg, os.PathLike):
            with open(cfg, "r") as f:
                cfg = json.load(f)
        
        
        self.dt = cfg["dt"]
        """
        TODO: modularize:
        """
        self.scale = kwds.pop("scale", {
                            "x_nom": 1,
                            "x_nom_b": 0,
                            "z_nom": 1,
                            "z_nom_b": 0,
                            "r_nom": 1,
                            "r_nom_b": 0,
                            "u_nom": 1,
                            "u_nom_b": 0,
                            "y_nom": 1,
                            "y_nom_b": 0,
                            "p_nom": 1
                            #"slack": False
                        })
        
        for k, v in self.scale.items():
            self.scale[k] = np.array(v)
        
        # algorithmic functions:
        functions = kwds.pop("functions", None) 
        cfg["model"]["functions"] = functions
        self.dae = dae = DAE(cfg["model"])
        
        #Q = cfg.pop("Q", ca.DM.eye(dae.n_x + dae.n_z))
        Q = cfg.pop("Q", ca.DM.eye(dae.n_x))
        R = cfg.pop("R", ca.DM.eye(dae.n_y))
        if isinstance([Q, R], list):
            self.Q = ca.diag(Q)
            self.R = ca.diag(R)
        else:
            self.Q = Q
            self.R = R
        # easy access for y:
        
        self.P_prev = kwds.pop("P0", None)
        #if P_prev is None:
        #    self.P_prev = ca.DM.eye(self.dae.n_x)

        integr_cfg = cfg.pop("integrator")
    
        integr_name = integr_cfg.pop("name")
        integr_klass = getattr(integrators, integr_name)
        # set dt as from data:
        integr_cfg["dt"] = self.dt
        # init integrator:
        self.integrator = integr_klass(dae, **integr_cfg) 
        self.init_order()
        self.init_f_expr()
        self.init_g_expr()
        self.init_h_expr()
        self.init_f()
        self.init_h()
        
        """
        Set all vars:
        """
        all_vars = []
        all_names = []
        for name in self.integrator.all_vars:
            var = getattr(self.integrator, name)
            if isinstance(var, (ca.MX, ca.SX)):
                all_vars.append(var)
            else:
                all_vars.append(ca.MX())
            all_names.append(name)
                         
        self.all_vars = all_vars
        self.all_names = all_names
        
        
        self.init_jac_f_x()
        self.init_jac_h_x()
        
        """
        Optional:
        """
        self.init_jac_f_z()
        self.init_jac_f_u()
        self.init_jac_g_x()
        self.init_jac_g_z()
    
        self.init_identity()
        
        #self.init_DMs()
        self.k = 0
        # dae.order:
        #self.y_names = [self.dae.y[key].name() for key in self.dae.y.keys()]
        # for states:
        self.df = pd.DataFrame(columns=self.dae.x)
        self.df_pred = pd.DataFrame(columns=self.dae.x)
        # for state covariance:
        self.P = {0: self.P_prev}
        self.P_aprioris = dict()
        self.set_log_det()
        #self.generate_symbolic_estimate()
        #self.generate_symbolic_estimate_for_loglik()
        self.p_cols = [
                        "p" + str(j) + str(i)
                        for j in range(1,self.n_x+1)
                        for i in range(1,self.n_x+1)
                        ]

    def init_identity(self):
        self.I = ca.DM.eye(self.x_symbolic.shape[0] + self.z_symbolic.shape[0])

    def init_covars(self, **kwargs):
        self.Q = kwargs.pop("Q", self.I)
        self.R = kwargs.pop("R", self.I)
        # initialize P_0 as Q
        #self.P_prev = self.Q
        self.P_prev = self.I

    def init_order(self):
        self.order = list(self.dae.order)
        
    def init_f(self):
        self.f = self.integrator.f 
        
    @property
    def n_y(self):
        return self.integrator.ny
    
    @property
    def n_x(self):
        return self.integrator.nx

    @property
    def n_u(self):
        return self.integrator.nu
    
    @property
    def n_r(self):
        return self.integrator.nr
    
    @property
    def n_d(self):
        return self.integrator.nd
    
    @property
    def n_z(self):
        return self.integrator.nz
    
    @property
    def n_p(self):
        return self.integrator.np
    
    def init_h(self):
        """
        self.h = ca.Function(
                            'h',
                            self.integrator.all_vars,
                            [self.h_expr],
                            self.order,
                            ['h']
                            ) 
        """
        self.h = ca.Function(
                            'h',
                            [self.x_symbolic, self.z_symbolic],
                            [self.h_expr],
                            ["x", "z"],
                            ['h']
                            ) 

    # for differentiation:
    def init_f_expr(self):
        self.f_expr = ca.vertcat(self.integrator.ode)

    def init_g_expr(self):
        self.g_expr = ca.vertcat(self.integrator.g_expr)
    
    def init_h_expr(self):
        #self.h_expr = ca.vertcat(self.integrator.h_expr)
        # CORRECTION:
        self.h_expr = ca.vertcat(*self.dae.dae.ydef())

    def set_params(self, p):
        self.p = p
        
    def set_Q(self, Q):
        self.Q = Q
        
    def set_R(self, R):
        self.R = R

    @property
    def y(self):
        #return list(map(lambda x: x.name(), self.dae.y.values()))
        return [y.name() for y in self.dae.y.values() if not isinstance(y, (float, int))]

    @property
    def x_symbolic(self):
        return self.integrator.x
    
    @property
    def z_symbolic(self):
        return self.integrator.z
    
    @property
    def u_symbolic(self):
        return self.integrator.u

    @property
    def jac_f_x_expr(self):
        return ca.jacobian(self.f_expr, self.x_symbolic)

    @property
    def jac_f_u_expr(self):
        return ca.jacobian(self.f_expr, self.u_symbolic)
    
    @property
    def jac_g_z_expr(self):
        try:
            return ca.jacobian(self.g_expr, self.z_symbolic)
        except RuntimeError:
            return ca.MX()
        
    @property
    def jac_f_z_expr(self):
        try:
            return ca.jacobian(self.f_expr, self.z_symbolic)
        except RuntimeError:
            return ca.MX()
    
    @property
    def jac_g_x_expr(self):
        try:
            return ca.jacobian(self.g_expr, self.x_symbolic)
        except RuntimeError:
            return ca.MX()

    @property
    def jac_h_x(self):
        #return ca.jacobian(self.h_expr, self.x_symbolic)      
        # CORRRECTION:
        #return ca.jacobian(self.h_expr, ca.vertcat(self.x_symbolic, self.z_symbolic))
        return ca.jacobian(self.h_expr, ca.vertcat(self.x_symbolic))
    
    def init_jac_f_x(self):
        self.jac_f_x = ca.Function('jac_f_x',
                                #self.integrator.all_vars,
                                self.all_vars,
                                #[self.x_symbolic],
                                [self.jac_f_x_expr],
                                #["x"],
                                #self.order,
                                self.all_names,
                                ['jac_f_x']) 
    
    def init_jac_f_u(self):
        self.jac_f_u = ca.Function('jac_f_u',
                                #self.integrator.all_vars,
                                self.all_vars,
                                #[self.x_symbolic],
                                [self.jac_f_u_expr],
                                #["x"],
                                #self.order,
                                self.all_names,
                                ['jac_f_u']) 
    
    def init_jac_f_z(self):
        self.jac_f_z = ca.Function('jac_f_z',
                                #[self.z_symbolic],
                                #self.integrator.all_vars,
                                self.all_vars,
                                [self.jac_f_z_expr],
                                self.all_names,
                                #["z"],
                                ['jac_f_z']) 
        
    def init_jac_g_x(self):
        self.jac_g_x = ca.Function('jac_g_x',
                                #self.integrator.all_vars,
                                self.all_vars,
                                #[self.x_symbolic],
                                [self.jac_g_x_expr],
                                self.all_names,
                                #["x"],
                                ['jac_g_x']) 
    
    def init_jac_g_z(self):
        self.jac_g_z = ca.Function('jac_g_z',
                                #[self.z_symbolic],
                                #self.integrator.all_vars,
                                self.all_vars,
                                [self.jac_g_z_expr],
                                #["z"],
                                self.all_names,
                                ['jac_g_z']) 
        

    def init_jac_h_x(self):
        self.jac_h = ca.Function('jac_h',
                                #self.integrator.all_vars,
                                self.all_vars,
                                [self.jac_h_x],
                                self.all_names,
                                ['jac_h'])
        
    def set_log_det(self):
        """
        For covariance estimation.
        
        (negative log-likelihood) 
        """ 
        
        self.Q_SX = ca.SX.sym("Q", self.n_x, self.n_x)
        self.R_SX = ca.SX.sym("R", self.n_y, self.n_y)
        #self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        #self.R = ca.MX.sym("R", self.n_y, self.n_y)
        #### set up log(det) - Functions:
        Q_SX = self.Q_SX
        R_SX = self.R_SX
        
        self.R_sqrt_inv = ca.Function("R_sqrt_inv",
                                     [self.R_SX],
                                     [ca.sqrt(ca.inv(self.R_SX))],
                                     ["R"],
                                     ["R_sqrt_inv"])
        
        self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
                                     [self.Q_SX],
                                     [ca.sqrt(ca.inv(self.Q_SX))],
                                     ["Q"],
                                     ["Q_sqrt_inv"])
            
        
        #self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        #self.R_square_root = ca.sqrt(ca.inv(self.R))
        
        self.R_square_root = self.R_sqrt_inv(self.R)
        self.Q_square_root = self.Q_sqrt_inv(self.Q)
        # for Q:
        self.log_det_Q = ca.Function(
                                     "log_det_Q",
                                     [Q_SX],
                                     [ca.trace(ca.log(ca.qr(Q_SX)[1]))],
                                     ["Q"],
                                     ["log(det(Q))"]                        
        )
        # for R:
        self.log_det_R = ca.Function(
                                     "log_det_R",
                                     [R_SX],
                                     [ca.trace(ca.log(ca.qr(R_SX)[1]))],
                                     ["Q"],
                                     ["log(det(R))"]                        
        )
    
    def chain_integrator(self):
        """
        Chain rootfinder for z (G) into integrator I.
        """
        _x0 = ca.MX.sym("x0", self.dae.n_x)
        _z0 = ca.MX.sym("z0", self.dae.n_z)
        #_z = ca.MX.sym("z", self.dae.n_z)
        _u = ca.MX.sym("u", self.dae.n_u)
        _p = ca.MX.sym("p", self.dae.n_p)
        _r = ca.MX.sym("r", self.dae.n_r)
        _d = ca.MX.sym("r", self.dae.n_d)
        # = ca.MX.sym("r", self.dae.n_r)
        z_expr = self.integrator.G(_z0, _x0, _u, _p, _r)
        I_chained_expr = self.integrator.one_sample(_x0, z_expr, _u, _p, _r, _d)
        return ca.Function("I_chained",
                            [_x0, _z0, _u, _p, _r, _d],
                            [I_chained_expr, z_expr],
                            ["x0","z0","u","p","r","d"],
                            ["xf", "z"])
        
"""
Kalman-Bucy filter (Hybrid EKF):
"""
    
class KalmanBucy(Filter):
    """
    Use symbolically to obtain
    covariance matrices for closed-loop
    control.
    """
    def __init__(self, cfg, **kwds):
        super(KalmanBucy, self).__init__(cfg, **kwds)
        """
        SDE-integrator: create, get Function:
        """
        
        self.SDEInt = SDEInt = integrators.SDEIntegrator(self.dae)
        self.Q_function = SDEInt.Q_symbolic
        
        self.initialize_P_integrator()
        self.generate_symbolic_estimate()
        self.generate_symbolic_estimate_for_loglik()
        self.initialize_wiener_integrator()
    
    def initialize_P_integrator(self):
        """
        Cannot feed P through 'regular' integrator,
        as it is matrix-valued. Hence, we initialize
        a tailored integrator for solving the
        continuous-time Lyapunov equation.
        """
        n_x = self.dae.n_x # + self.dae.n_z
        A = ca.MX.sym("A", n_x, n_x)
        sigma = ca.MX.sym("sigma", n_x, n_x)
        """
        Recreate symbolic theta:
        mxs = []
        for name in self.dae.theta_names:
            mxs.append(getattr(self.dae, name))
        """
        n_theta = self.dae.var("theta").shape[0]
        u = ca.MX.sym("u", self.n_u)
        #theta = ca.MX.sym("theta", n_theta)
        
        P0 = ca.MX.sym("P0", n_x, n_x)
        # c.t. Lyapunov equation:
        rhs_P = A@P0 + P0@A.T + sigma@sigma.T
        #rhs_P = A@P0 + P0@A.T + sigma
        #Q_call = self.Q_function(theta, u)
        #rhs_P = A@P0 + P0@A.T + Q_call@Q_call.T
        #rhs_P = A@P0 + P0@A.T + self.SDEInt.sde@self.SDEInt.sde.T
        #rhs_P = A@P0 + P0@A.T + theta.reshape((n_x, n_x))@theta.reshape((n_x, n_x)).T
        #rhs_P = A@P0 + P0@A.T + Q_call
        # function-obj for continuous-time ode:
        ode_P = ca.Function('ode_P', [P0, A, sigma], [rhs_P])
        # RK4 for this, analogous to state:
        N_steps_per_sample = 1
        dt = self.dt/N_steps_per_sample

        # Build an integrator for this system: Runge Kutta 4 integrator
        k1 = ode_P(P0, A, sigma)
        k2 = ode_P(P0 + dt/2.0*k1, A, sigma)
        k3 = ode_P(P0 + dt/2.0*k2, A,sigma)
        k4 = ode_P(P0 + dt*k3, A, sigma)
        # final expression:
        P_final = P0 + dt/6.0*(k1+2*k2+2*k3+k4)
        # integrator for state covariance:
        F = ca.Function('F_P',[P0, A, sigma],[P_final])
        P = P0
        # discretized dynamics:
        for _ in range(N_steps_per_sample):
            P = F(P, A, sigma)
        # function object for --"--
        self.one_sample_P = ca.Function('one_sample_P', [P0, A, sigma], [P])
        
    def initialize_wiener_integrator(self):
        """ 
        To obtain P0.
        """
        
        
        x0 = ca.MX.sym("x0", self.n_x)
        z0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)
        Ps = ca.MX.sym("Ps")
        dt = ca.MX.sym("dt")

        #A = ca.MX.sym("A", n_x, n_x)
        # obtain df/dx linearized at t=k-1:
        A = self.jac_f_x(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        #Ad = ca.expm(A*dt)
        
        n_x = self.dae.n_x # + self.dae.n_z
        sigma = ca.MX.sym("sigma", n_x, n_x)
        #P0 = ca.MX.sym("P0", n_x, n_x)
        # c.t. Lyapunov equation:
        #rhs_P = A@ca.expm(sigma)@ca.expm(sigma.T)@A.T
        rhs_P = ca.expm(A*dt)@sigma@sigma.T@ca.expm(A*dt).T
        #rhs_P = ca.expm(A)@sigma@sigma.T@ca.expm(A.T)
        # 'faux' P0:
        P0 = ca.MX.sym("P0", self.n_x, self.n_x)
        # function-obj for continuous-time ode:
        ode_P = ca.Function('ode_P', [P0,x0,z0,u,r,p,y,Ps,sigma,dt], [rhs_P])
        # RK4 for this, analogous to state:
        #N_steps_per_sample = 1
        #dt = self.dt/N_steps_per_sample

        # Build an integrator for this system: Runge Kutta 4 integrator
        k1 = ode_P(P0,x0,z0,u,r,p,y,Ps,sigma,dt)
        k2 = ode_P(P0 + dt/2.0*k1,x0,z0,u,r,p,y,Ps,sigma,dt)
        k3 = ode_P(P0 + dt/2.0*k2,x0,z0,u,r,p,y,Ps,sigma,dt)
        k4 = ode_P(P0 + dt*k3,x0,z0,u,r,p,y,Ps,sigma,dt)
        # final expression:
        P_final = P0 + dt/6.0*(k1+2*k2+2*k3+k4)
        # integrator for state covariance:
        F = ca.Function('F_P',[P0,x0,z0,u,r,p,y,Ps,sigma,dt],[P_final])
        P = P0
        # discretized dynamics:
        #for _ in range(N_steps_per_sample):
        for _ in range(1):
            P = F(P0,x0,z0,u,r,p,y,Ps,sigma,dt)
        # function object for --"--
        self.one_sample_wiener = ca.Function('one_sample_P',
                                             [P0,x0,z0,u,r,p,y,Ps,sigma,dt],
                                             [P],
                                             ["P0","x0","z0","u","r","p","y","Ps","sigma","dt"],
                                             ["P"])
        
        
    def reinit_symbolic_Q(self):
        mxs = []
        for name in self.dae.theta_names:
            mx = ca.MX.sym(name, self.n_x, self.n_x)
            mxs.append(mx)
        return mxs
        
    def generate_symbolic_estimate(self):
        """
        To be able to map evaluation of
        kalman feedback, create function:
        
        x0, u, r, p, y, Q, R, P_prev -> x_pred, x_hat, P_hat
        
        NOTE: remember to test equivalence with numeric version.
        
        NB! Only for ODE's.
        """
        x0 = ca.MX.sym("x0", self.n_x)
        z0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)   
        """
        Recreate symbolic theta:
        """
        #Q = ca.MX.sym("Q", self.n_x, self.n_x)
        Q = ca.veccat(*self.reinit_symbolic_Q())
        
        R = ca.MX.sym("R", self.n_y, self.n_y)
        #dt = ca.MX.sym("dt", 1)
        P_prev = ca.MX.sym("P_prev", self.n_x, self.n_x)
        
        """
        x_apriori = F(
                      x0=x0,
                      z=ca.MX(),
                      u=u,
                      p=p,
                      r=r
                      )["xf"]
        """
        F = self.chain_integrator()
        res = F(
                x0=x0,
                z0=z0,
                u=u,
                p=p,
                r=r,
                d=0
                )
        x_apriori = res["xf"]
        z = res["z"]

        # obtain df/dx linearized at t=k-1:
        A = self.jac_f_x(x0,z,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        # obtain linearization of h(x) (usually just [1, 0, ..., 0]):
        C = self.jac_h(x0,z,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        # take symbolic measurement:        
        #h_x = self.h(x_apriori, [])
        h_x = C@x_apriori
        # a priori covariance, continuous-time:
        #P_apriori = self.one_sample_P(P_prev, A, ca.expm(Q))
        P_apriori = self.one_sample_P(P_prev, A, self.Q_function(Q, u))
        # output prediction uncertainty:
        V_k = C@P_apriori@(C.T) + ca.expm(R)
        # kalman gain:
        K = P_apriori@(C.T)@ca.inv(V_k)
        # posterior state, covariance estimate (update equations):
        x_posteriori = x_apriori + K@(y - h_x)
        P_aposteriori = (ca.MX.eye(self.n_x) - K@C)@P_apriori
        # discretized dynamics of one-step ahead w/ feedback:
        self.one_sample_feedback = ca.Function(
            "F",
            [x0, z0, P_prev, u, r, p, y, Q, R],
            [x_posteriori, z, P_aposteriori, x_apriori, P_apriori, h_x],
            ["x0","z0","P_prev","u","r","p","y","Q","R"],
            ["x_hat","z","P_hat","x_pred", "P_apriori", "h_x"],
        )
    
    def generate_symbolic_estimate(self):
        """
        To be able to map evaluation of
        kalman feedback, create function:
        
        x0, u, r, p, y, Q, R, P_prev -> x_pred, x_hat, P_hat
        
        NOTE: remember to test equivalence with numeric version.
        
        NB! Only for ODE's.
        """
        
        #F = self.integrator.one_sample
        
        x0 = ca.MX.sym("x0", self.n_x)
        z0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)
        # here:
        # replace with:
        """
        Recreate symbolic theta:
        """
        #Q = ca.MX.sym("Q", self.n_x, self.n_x)
        Q = ca.veccat(*self.reinit_symbolic_Q())
        
        #Q_expr = self.dae.sde
        R = ca.MX.sym("R", self.n_y, self.n_y)
        #dt = ca.MX.sym("dt", 1)
        P_prev = ca.MX.sym("P_prev", self.n_x, self.n_x)
        
        """
        x_apriori = F(
                      x0=x0,
                      z=ca.MX(),
                      u=u,
                      p=p,
                      r=r
                      )["xf"]
        """
        self.F = self.chain_integrator()
        res = self.F(
                x0=x0,
                z0=z0,
                u=u,
                p=p,
                r=r,
                d=0
                )
        x_apriori = res["xf"]
        z = res["z"]

        # obtain df/dx linearized at t=k-1:
        A = self.jac_f_x(x0,z,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        # obtain linearization of h(x) (usually just [1, 0, ..., 0]):
        C = self.jac_h(x0,z,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        # take symbolic measurement:        
        #h_x = self.h(x_apriori, [])
        h_x = C@x_apriori
        # a priori covariance, continuous-time:
        #P_apriori = self.one_sample_P(P_prev, A, Q, u)
        P_apriori = self.one_sample_P(P_prev, A, self.Q_function(Q, u))
        #P_apriori = self.one_sample_P(P_prev, A, ca.expm(Q))
        # output prediction uncertainty:
        V_k = C@P_apriori@(C.T) + ca.expm(R)
        # kalman gain:
        K = P_apriori@(C.T)@ca.inv(V_k)
        e_k = y - h_x
        # posterior state, covariance estimate (update equations):
        x_posteriori = x_apriori + K@e_k
        P_aposteriori = (ca.MX.eye(self.n_x) - K@C)@P_apriori
        loglik = (1/2)*(self.log_det_R(V_k) + e_k.T@ca.inv(V_k)@e_k + self.n_y*ca.log(2*ca.pi))
        
        self.one_sample_feedback = ca.Function(
            "F",
            [x0, P_prev, z0, u, r, p, y, Q, R],
            [x_posteriori, P_aposteriori, z, x_apriori, h_x, e_k, V_k, P_apriori, loglik],
            ["x_0","P_0","z0","u","r","p","y","Q","R"],
            ["x_11","P_11","z","x_10","h_x", "e_k", "V_k", "P_10", "loglik"],
        )
        
    def generate_symbolic_estimate_for_loglik(self):
        """
        To be able to map evaluation of
        kalman feedback, create function:
        
        x0, u, r, p, y, Q, R, P_prev -> x_pred, x_hat, P_hat
        
        NOTE: remember to test equivalence with numeric version.
        
        NB! Only for ODE's.
        """
        
        #F = self.integrator.one_sample
        
        x_0 = ca.MX.sym("x0", self.n_x)
        z_0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        #u_shift = ca.MX.sym("u_1", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)
        # here:
        # replace with:
        """
        Recreate symbolic theta:
        """
        #Q = ca.MX.sym("Q", self.n_x, self.n_x)
        Q = ca.veccat(*self.reinit_symbolic_Q())
        #Q_expr = self.dae.sde
        R = ca.MX.sym("R", self.n_y, self.n_y)
        #dt = ca.MX.sym("dt", 1)
        P_0 = ca.MX.sym("P_0", self.n_x, self.n_x)
        """
        To produce log-likelihood expression:
        """
        # obtain linearization of h(x) (usually just [1, 0, ..., 0]):
        C = self.jac_h(x_0,z_0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        # let x0 denote x_0|-1, i.e a one-step pred:
        h_x = C@x_0
        e_k = y - h_x
        # similarly, let P0 denote P_0|-1,
        # yielding the output prediction uncertainty
        #V_k = C@P_0@(C.T) + ca.expm(R)
        V_k = C@P_0@(C.T) + R
        #V_k = C@P_0@(C.T) + R
        # the expression for the loglik becomes:
        loglik = (1/2)*(self.log_det_R(V_k) + \
                  e_k.T@ca.inv(V_k)@e_k + \
                  self.n_y*ca.log(2*ca.pi))
        # the Kalman gain:
        K = P_0@(C.T)@ca.inv(V_k)
        # posterior state, covariance estimate (update equations):
        x_00 = x_0 + K@e_k # x_0|0
        P_00 = (ca.MX.eye(self.n_x) - K@C)@P_0 # P_0|0
        # chain function calls to get DAE-integrator:
        F = self.chain_integrator()
        res = F(
                x0=x_00,
                z0=z_0,
                u=u,
                p=p,
                r=r,
                d=0
                )
        # symbolic simulation:
        x_10 = res["xf"]
        z_1 = res["z"]
     
        # obtain df/dx linearized at t=t_k:
        A = self.jac_f_x(x_0,z_1,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        P_10 = self.one_sample_P(P_00, A, self.Q_function(Q, u))
        
        self.one_sample_feedback_adj = ca.Function(
            "F",
            [x_0, P_0, z_0, u, r, p, y, Q, R],
            [x_00, P_00, z_1, x_10, h_x, e_k, V_k, P_10, loglik],
            ["x_0","P_0","z_0","u","r","p","y","Q","R"],
            ["x_00","P_00","z","x_10","h_x", "e_k", "V_k", "P_10", "loglik"],
        )
    
    # rethink this inteface
    def estimate(
                 self,
                 x00=ca.DM(),
                 z0=ca.DM(),
                 u=ca.DM(),
                 r=ca.DM(),
                 y=ca.DM(), 
                 p=ca.DM(), 
                 Q=ca.DM(),
                 R=ca.DM(),
                 ):
        ''' 
        Use symbolic function defined above.
         ["x0","z0","P_prev","u","r","p","y","Q","R"],
        '''
        P_prev = self.P_prev    
        self.k += 1
        x_11, z, P_11, x_10, P_10, h_x = self.one_sample_feedback(
                x00, z0, P_prev, u, r, p, y, Q, R
            )
        self.df.loc[self.k*self.dt, self.dae.x + self.dae.z] = np.concatenate([x_11, z]).flatten()
        self.df_pred.loc[self.k*self.dt, self.dae.x + self.dae.z] = np.concatenate([x_10, z]).flatten()
        # keep P a posteriori:
        self.P_prev = np.array(P_11)
        self.P[self.k] = self.P_prev
        return np.array(x_11)
         
    def estimate(
                self,
                x0=ca.DM(),
                z0=ca.DM(),
                u=ca.DM(),
                r=ca.DM(),
                y=ca.DM(), 
                p=ca.DM(), 
                Q=ca.DM(),
                R=ca.DM(),
                ):
        ''' 
        Use symbolic function defined above.
        
        [x_0, P_0, z_0, u, r, p, y, Q, R],
        [x_00, P_00, z_1, x_10, h_x, e_k, V_k, P_10, loglik],
        ["x_0","P_0","z_0","u","r","p","y","Q","R"],
        ["x_00","P_00","z","x_10","h_x", "e_k", "V_k", "P_10", "loglik"],
        '''
        P_prev = self.P_prev    
        self.k += 1
        x_00, P_00, z, x_10, h_x, e_k, V_k, P_10, loglik = self.one_sample_feedback_adj(
                x0, P_prev, z0, u, r, p, y, Q, R
            )
        self.df.loc[self.k*self.dt, self.dae.x + self.dae.z] = np.concatenate([x_00, z]).flatten()
        self.df_pred.loc[self.k*self.dt, self.dae.x + self.dae.z] = np.concatenate([x_10, z]).flatten()
        # keep P a priori:
        self.P_prev = np.array(P_10)
        self.P[self.k] = self.P_prev
        return np.array(x_00)
    
    
class KalmanDAE(Filter):
    ''' 
    A Kalman-filter for DAE's.
    
    C.f. https://www.sciencedirect.com/science/article/pii/S2405896318302829
    for algorithm.
    def __init__(self, cfg, **kwds):
        
        if isinstance(cfg, str) or isinstance(cfg, os.PathLike):
            with open(cfg, "r") as f:
                cfg = json.load(f)
        
        
        self.dt = cfg["dt"]
        
        # algorithmic functions:
        functions = kwds.pop("functions", None) 
        cfg["model"]["functions"] = functions
        self.dae = dae = DAE(cfg["model"])
        
        Q = cfg.pop("Q", ca.DM.eye(dae.n_x + dae.n_z))
        R = cfg.pop("R", ca.DM.eye(dae.n_y))
        if isinstance([Q, R], list):
            self.Q = ca.diag(Q)
            self.R = ca.diag(R)
        else:
            self.Q = Q
            self.R = R
        # easy access for y:
        
        P_prev = kwds.pop("P0", None)
        #if P_prev is None:
        #    self.P_prev = ca.DM.eye(self.dae.n_x)

        integr_cfg = cfg.pop("integrator")
    
        integr_name = integr_cfg.pop("name")
        integr_klass = getattr(integrators, integr_name)
        # set dt as from data:
        integr_cfg["dt"] = self.dt
        # init integrator:
        self.integrator = integr_klass(dae, **integr_cfg) 
        self.init_order()
        self.init_f_expr()
        self.init_g_expr()
        self.init_h_expr()
        self.init_f()
        self.init_h()
        
        """
        Set all vars:
        """
        all_vars = []
        all_names = []
        for name in self.integrator.all_vars:
            var = getattr(self.integrator, name)
            if isinstance(var, (ca.MX, ca.SX)):
                all_vars.append(var)
            else:
                all_vars.append(ca.MX())
            all_names.append(name)
                         
        self.all_vars = all_vars
        self.all_names = all_names
        
        
        self.init_jac_f_x()
        self.init_jac_h_x()
        
        """
        Optional:
        """
        self.init_jac_f_z()
        self.init_jac_f_u()
        self.init_jac_g_x()
        self.init_jac_g_z()
    
        self.init_identity()
        
        #self.init_DMs()
        self.k = 0
        # dae.order:
        #self.y_names = [self.dae.y[key].name() for key in self.dae.y.keys()]
        # for states:
        self.df = pd.DataFrame(columns=self.dae.x)
        # for state covariance:
        self.P = {0: P_prev}
        self.P_aprioris = dict()
        self.set_log_det()
        self.generate_symbolic_estimate()
        self.generate_symbolic_estimate_for_loglik()
    '''
    def __init__(self, cfg, **kwds):
        super(KalmanDAE, self).__init__(cfg, **kwds)
        """
        SDE-integrator: create, get Function:
        """
        #self.SDEInt = SDEInt = integrators.SDEIntegrator(self.dae)
        #self.Q_function = SDEInt.Q_symbolic
        
        #self.initialize_P_integrator()
        self.generate_symbolic_estimate()
        self.generate_symbolic_estimate_partial()
        self.generate_symbolic_estimate_for_loglik()
        self.generate_symbolic_smooting_estimate()
        self.initialize_wiener_integrator()
    

    def init_identity(self):
        self.I = ca.DM.eye(self.x_symbolic.shape[0] + self.z_symbolic.shape[0])

    def init_covars(self, **kwargs):
        self.Q = kwargs.pop("Q", self.I)
        self.R = kwargs.pop("R", self.I)
        # initialize P_0 as Q
        #self.P_prev = self.Q
        self.P_prev = self.I

    def init_order(self):
        self.order = list(self.dae.order)
        
    def init_f(self):
        self.f = self.integrator.f 
        
    @property
    def n_y(self):
        return self.integrator.ny
    
    @property
    def n_x(self):
        return self.integrator.nx

    @property
    def n_u(self):
        return self.integrator.nu
    
    @property
    def n_r(self):
        return self.integrator.nr
    
    @property
    def n_z(self):
        return self.integrator.nz
    
    @property
    def n_p(self):
        return self.integrator.np
    
    def init_h(self):
        """
        self.h = ca.Function(
                            'h',
                            self.integrator.all_vars,
                            [self.h_expr],
                            self.order,
                            ['h']
                            ) 
        """
        self.h = ca.Function(
                            'h',
                            [self.x_symbolic, self.z_symbolic],
                            [self.h_expr],
                            ["x", "z"],
                            ['h']
                            ) 

    # for differentiation:
    def init_f_expr(self):
        self.f_expr = ca.vertcat(self.integrator.ode)

    def init_g_expr(self):
        self.g_expr = ca.vertcat(self.integrator.g_expr)
    
    def init_h_expr(self):
        #self.h_expr = ca.vertcat(self.integrator.h_expr)
        # CORRECTION:
        self.h_expr = ca.vertcat(*self.dae.dae.ydef())

    def set_params(self, p):
        self.p = p
        
    def set_Q(self, Q):
        self.Q = Q
        
    def set_R(self, R):
        self.R = R

    @property
    def y(self):
        #return list(map(lambda x: x.name(), self.dae.y.values()))
        return [y.name() for y in self.dae.y.values() if not isinstance(y, (float, int))]

    @property
    def x_symbolic(self):
        return self.integrator.x
    
    @property
    def z_symbolic(self):
        return self.integrator.z
    
    @property
    def u_symbolic(self):
        return self.integrator.u

    @property
    def jac_f_x_expr(self):
        return ca.jacobian(self.f_expr, self.x_symbolic)

    @property
    def jac_f_u_expr(self):
        return ca.jacobian(self.f_expr, self.u_symbolic)
    
    @property
    def jac_g_z_expr(self):
        try:
            return ca.jacobian(self.g_expr, self.z_symbolic)
        except RuntimeError:
            return ca.MX()
        
    @property
    def jac_f_z_expr(self):
        try:
            return ca.jacobian(self.f_expr, self.z_symbolic)
        except RuntimeError:
            return ca.MX()
    
    @property
    def jac_g_x_expr(self):
        try:
            return ca.jacobian(self.g_expr, self.x_symbolic)
        except RuntimeError:
            return ca.MX()

    @property
    def jac_h_x(self):
        #return ca.jacobian(self.h_expr, self.x_symbolic)      
        # CORRRECTION:
        #return ca.jacobian(self.h_expr, ca.vertcat(self.x_symbolic, self.z_symbolic))
        return ca.jacobian(self.h_expr, ca.vertcat(self.x_symbolic))
    
    def init_jac_f_x(self):
        self.jac_f_x = ca.Function('jac_f_x',
                                #self.integrator.all_vars,
                                self.all_vars,
                                #[self.x_symbolic],
                                [self.jac_f_x_expr],
                                #["x"],
                                #self.order,
                                self.all_names,
                                ['jac_f_x']) 
    
    def init_jac_f_u(self):
        self.jac_f_u = ca.Function('jac_f_u',
                                #self.integrator.all_vars,
                                self.all_vars,
                                #[self.x_symbolic],
                                [self.jac_f_u_expr],
                                #["x"],
                                #self.order,
                                self.all_names,
                                ['jac_f_u']) 
    
    def init_jac_f_z(self):
        self.jac_f_z = ca.Function('jac_f_z',
                                #[self.z_symbolic],
                                #self.integrator.all_vars,
                                self.all_vars,
                                [self.jac_f_z_expr],
                                self.all_names,
                                #["z"],
                                ['jac_f_z']) 
        
    def init_jac_g_x(self):
        self.jac_g_x = ca.Function('jac_g_x',
                                #self.integrator.all_vars,
                                self.all_vars,
                                #[self.x_symbolic],
                                [self.jac_g_x_expr],
                                self.all_names,
                                #["x"],
                                ['jac_g_x']) 
    
    def init_jac_g_z(self):
        self.jac_g_z = ca.Function('jac_g_z',
                                #[self.z_symbolic],
                                #self.integrator.all_vars,
                                self.all_vars,
                                [self.jac_g_z_expr],
                                #["z"],
                                self.all_names,
                                ['jac_g_z']) 
        

    def init_jac_h_x(self):
        self.jac_h = ca.Function('jac_h',
                                #self.integrator.all_vars,
                                self.all_vars,
                                [self.jac_h_x],
                                self.all_names,
                                ['jac_h'])
        
    def set_log_det(self):
        """
        For covariance estimation.
        
        (negative log-likelihood) 
        """ 
        
        self.Q_SX = ca.SX.sym("Q", self.n_x, self.n_x)
        self.R_SX = ca.SX.sym("R", self.n_y, self.n_y)
        #self.Q = ca.MX.sym("Q", self.n_x, self.n_x)
        #self.R = ca.MX.sym("R", self.n_y, self.n_y)
        #### set up log(det) - Functions:
        Q_SX = self.Q_SX
        R_SX = self.R_SX
        
        self.R_sqrt_inv = ca.Function("R_sqrt_inv",
                                     [self.R_SX],
                                     [ca.sqrt(ca.inv(self.R_SX))],
                                     ["R"],
                                     ["R_sqrt_inv"])
        
        self.Q_sqrt_inv = ca.Function("Q_sqrt_inv",
                                     [self.Q_SX],
                                     [ca.sqrt(ca.inv(self.Q_SX))],
                                     ["Q"],
                                     ["Q_sqrt_inv"])
            
        
        #self.Q_square_root = ca.sqrt(ca.inv(self.Q))
        #self.R_square_root = ca.sqrt(ca.inv(self.R))
        
        self.R_square_root = self.R_sqrt_inv(self.R)
        self.Q_square_root = self.Q_sqrt_inv(self.Q)
        # for Q:
        self.log_det_Q = ca.Function(
                                     "log_det_Q",
                                     [Q_SX],
                                     [ca.trace(ca.log(ca.qr(Q_SX)[1]))],
                                     ["Q"],
                                     ["log(det(Q))"]                        
        )
        # for R:
        self.log_det_R = ca.Function(
                                     "log_det_R",
                                     [R_SX],
                                     [ca.trace(ca.log(ca.qr(R_SX)[1]))],
                                     ["Q"],
                                     ["log(det(R))"]                        
        )
         
        
        
    def estimate(
                 self,
                 x_pred,
                 u=ca.DM(),
                 r=ca.DM(),
                 y=ca.DM(), 
                 p=None,
                 z=ca.DM(),
                 v=ca.DM(),
                 s=ca.DM() #,
                 #w=ca.DM()
                 ):
        ''' 
        Assume general non-linear structure.
        Thus, A and C have to be looked up
        at each step.
        
        NOTE: x_pred from mpc.
        ##### pad 'y' with zeros #####
        y_pad = np.array([])
        i = 0
        
        # TODO: fix this to handle both ODE- and DAE-systems
        for k, var in self.dae.y.items():
            if hasattr(var, "name"):
                y_pad = np.append(y_pad, [y[i]])
                i += 1
            #else: # non-measured
            #    y_pad = np.append(y_pad, 0)
         '''
         
         
        #A11 = self.jac_f_x(x_pred,z,u,self.p,s,v,y,r,w)
        A11 = self.jac_f_x(x_pred,z,u,p,r,y,0,v,0)
        A12 = self.jac_f_z(x_pred,z,u,p,r,y,0,v,0)
        
        dGdx = self.jac_g_x(x_pred,z,u,p,r,y,0,v,0)
        dGdz = self.jac_g_z(x_pred,z,u,p,r,y,0,v,0)
        
        A21 = -np.linalg.inv(dGdz)@dGdx@A11
        A22 = -np.linalg.inv(dGdz)@dGdx@A12
        
        nx = self.dae.n_x
        nz = self.dae.n_z
        if nz > 0:
            dim = nx + nz
            A = ca.DM.zeros((dim, dim))
            A[0:nx, 0:nx] = A11
            A[0:nx, nx:dim] = A12
            A[nx:dim, 0:nx] = A21
            A[nx:dim, nx:dim] = A22
        else:
            A = A11
            dim = nx
            
        Ad = expm(A*self.dt)
        #C = self.jac_h(x_pred, z, u, self.p if p is None else p, s, v, y_pad, r, w)
        C = self.jac_h(x_pred,z,u,p,r,y,0,v,0)
        #h_x = self.h(y, x_pred, z, u, self.p if p is None else p, v, r)
        #h_x = self.h(x_pred, z)
        h_x = C@x_pred
        try:
            P_prev = self.P_prev
        except AttributeError:
            # first iteration, no history
            self.P_prev = np.diag([1]*dim)
            P_prev = self.P_prev
        
        """
        P_apriori = A*P_prev*A.T + Q
        """
        P_apriori = Ad@P_prev@Ad.T + self.Q
        self.P_aprioris[self.k-1] = P_apriori

        #K = ca.mtimes(ca.mtimes(P_apriori, ca.transpose(C)), ca.inv(ca.mtimes([C, P_apriori, ca.transpose(C)]) + self.R))
        V_k = C@P_apriori@(C.T) + self.R
        K = P_apriori@(C.T)@np.linalg.inv(V_k)
        #x_post = x_pred + ca.mtimes(K, (y - h_x))  
        #x_pred = np.append(x_pred, z)
        #x_post = x_pred + K@(y_pad - h_x)
        x_post = x_pred + K@(y - h_x)
        x_post = np.array(x_post).reshape(-1)
        # store estimation result. TODO: check ordering of states.
        #z_post = x_post[nx:]
        x_post = x_post[:nx]
        self.df.loc[(self.k+1)*self.dt, self.dae.x] = x_post
        #self.df.loc[self.k*self.dt, self.dae.z] = z_post
        self.P_prev = ca.mtimes((self.I - ca.mtimes(K, C)), P_apriori)
        self.k += 1
        # keep P a posteriori:
        #self.P[self.k] = deepcopy(self.P_prev)
        self.P[self.k] = ca.mtimes((self.I - ca.mtimes(K, C)), P_apriori)

        return x_post[0:nx], x_post[nx:dim], np.array(h_x).reshape(-1)
    
    def initialize_wiener_integrator(self):
        """ 
        To obtain P0.
        """
        
        
        x0 = ca.MX.sym("x0", self.n_x)
        z0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)
        Ps = ca.MX.sym("Ps")
        dt = ca.MX.sym("dt")

        #A = ca.MX.sym("A", n_x, n_x)
        # obtain df/dx linearized at t=k-1:
        A = self.jac_f_x(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        #Ad = ca.expm(A*dt)
        
        n_x = self.dae.n_x # + self.dae.n_z
        sigma = ca.MX.sym("sigma", n_x, n_x)
        #P0 = ca.MX.sym("P0", n_x, n_x)
        # c.t. Lyapunov equation:
        #rhs_P = A@ca.expm(sigma)@ca.expm(sigma.T)@A.T
        rhs_P = ca.expm(A*dt)@sigma@sigma.T@ca.expm(A*dt).T
        #rhs_P = ca.expm(A)@sigma@sigma.T@ca.expm(A.T)
        # 'faux' P0:
        P0 = ca.MX.sym("P0", self.n_x, self.n_x)
        # function-obj for continuous-time ode:
        ode_P = ca.Function('ode_P', [P0,x0,z0,u,r,p,y,Ps,sigma,dt], [rhs_P])
        # RK4 for this, analogous to state:
        #N_steps_per_sample = 1
        #dt = self.dt/N_steps_per_sample

        # Build an integrator for this system: Runge Kutta 4 integrator
        k1 = ode_P(P0,x0,z0,u,r,p,y,Ps,sigma,dt)
        k2 = ode_P(P0 + dt/2.0*k1,x0,z0,u,r,p,y,Ps,sigma,dt)
        k3 = ode_P(P0 + dt/2.0*k2,x0,z0,u,r,p,y,Ps,sigma,dt)
        k4 = ode_P(P0 + dt*k3,x0,z0,u,r,p,y,Ps,sigma,dt)
        # final expression:
        P_final = P0 + dt/6.0*(k1+2*k2+2*k3+k4)
        # integrator for state covariance:
        F = ca.Function('F_P',[P0,x0,z0,u,r,p,y,Ps,sigma,dt],[P_final])
        P = P0
        # discretized dynamics:
        #for _ in range(N_steps_per_sample):
        for _ in range(1):
            P = F(P0,x0,z0,u,r,p,y,Ps,sigma,dt)
        # function object for --"--
        self.one_sample_wiener = ca.Function('one_sample_P',
                                             [P0,x0,z0,u,r,p,y,Ps,sigma,dt],
                                             [P],
                                             ["P0","x0","z0","u","r","p","y","Ps","sigma","dt"],
                                             ["P"])
        
    
    
    def estimate_adj(
            self,
            x0=ca.DM(),
            x10=ca.DM(),
            z0=ca.DM(),
            u=ca.DM(),
            r=ca.DM(),
            y=ca.DM(), 
            p=ca.DM(), 
            Q=ca.DM(),
            R=ca.DM(),
            ):
        ''' 
        Use symbolic function defined above.
        
        [x0, z0, P_prev, u, r, p, y, Q, R, dt],
        [x_posteriori, z, P_aposteriori, x_apriori, h_x],
        ["x0","z0","P_prev","u","r","p","y","Q","R","dt"],
        ["x_hat","z","P_hat","x_pred","h_x"],
        '''
        
        # unpack scalings:
        x_nom = self.scale["x_nom"]
        x_nom_b = self.scale["x_nom_b"]
        z_nom = self.scale["z_nom"]
        z_nom_b = self.scale["z_nom_b"]
        u_nom = self.scale["u_nom"]
        u_nom_b = self.scale["u_nom_b"]
        r_nom = self.scale["r_nom"]
        r_nom_b = self.scale["r_nom_b"]
        y_nom = self.scale["y_nom"]
        y_nom_b = self.scale["y_nom_b"]
        p_nom = self.scale["p_nom"]
        
        P_prev = self.P_prev    
        self.k += 1
        x_00, \
        z, \
        P_11, \
        P_10, \
        x_10, \
        h_x = self.one_sample_feedback_partial(
                (x0 - x_nom_b)/x_nom,
                (x10 - x_nom_b)/x_nom,
                (z0 - z_nom_b)/z_nom,
                P_prev,
                (u - u_nom_b)/u_nom,
                (r - r_nom_b)/r_nom,
                #p/p_nom,
                p,
                (y - y_nom_b)/y_nom,
                Q,
                R, 
                self.dt
            )
        x_00 = x_00*x_nom + x_nom_b
        z = z*z_nom + z_nom_b
        self.df.loc[self.k*self.dt, self.dae.x + self.dae.z] = np.concatenate([x_00, z]).flatten()
        self.df_pred.loc[self.k*self.dt, self.dae.x + self.dae.z] = np.concatenate([x_10, z]).flatten()
        # keep P a priori:
        self.P_prev = np.array(P_11)
        self.P[self.k] = self.P_prev
        self.P_aprioris[self.k-1] = np.array(P_10)
        return np.array(x_00).flatten(), None, None

    def estimate_smoothing(
            self,
            x0=ca.DM(),
            x0_1=ca.DM(),
            z0=ca.DM(),
            u=ca.DM(),
            r=ca.DM(),
            y=ca.DM(), 
            d=ca.DM(), 
            p=ca.DM(), 
            P_prev=ca.DM(),
            Q=ca.DM(),
            R=ca.DM(),
            ):
        ''' 
        Use symbolic function defined above.
        
        [x0, x0_1, z0, P_0, u, r, p, y, Q, R, dt],
        [x_00, z, P_00, P_10, x_10],
        ["x0","x0_1", "z0","P_0","u","r","p","y","Q","R","dt"],
        ["x_00","z","P_00","P_10", "x_10"],
        '''
        
        # unpack scalings:
        x_nom = self.scale["x_nom"]
        x_nom_b = self.scale["x_nom_b"]
        z_nom = self.scale["z_nom"]
        z_nom_b = self.scale["z_nom_b"]
        u_nom = self.scale["u_nom"]
        u_nom_b = self.scale["u_nom_b"]
        r_nom = self.scale["r_nom"]
        r_nom_b = self.scale["r_nom_b"]
        y_nom = self.scale["y_nom"]
        y_nom_b = self.scale["y_nom_b"]
        p_nom = self.scale["p_nom"]
        
        #P_prev = self.P_prev    
        #self.k += 1
        #x0, x0_1, z0, P_0, u, r, p, y, Q, R, dt
        x_00, z, P_11, P_10, x_10, res_x, res_y, K, res, A = self.one_sample_smoothing_estimate(
                (x0 - x_nom_b)/x_nom,
                (x0_1 - x_nom_b)/x_nom,
                (z0 - z_nom_b)/z_nom,
                P_prev,
                (u - u_nom_b)/u_nom,
                (r - r_nom_b)/r_nom,
                p/p_nom,
                (y - y_nom_b)/y_nom,
                d,
                #p/p_nom,
                Q,
                R, 
                self.dt
            )
        x_00 = x_00*x_nom + x_nom_b
        z = z*z_nom + z_nom_b
        #self.df.loc[self.k*self.dt, self.dae.x] = np.concatenate([x_00]).flatten()
        #self.df_pred.loc[(self.k+1)*self.dt, self.dae.x] = np.concatenate([x_10]).flatten()
        # keep P a priori:
        #self.P_prev = np.array(P_10)
        P_next = np.array(P_10)
        #self.P[self.k] = np.array(P_11)
        #self.P_aprioris[self.k-1] = np.array(P_prev)
        return np.array(x_00).flatten(), np.array(x_10), P_next, res_x, res_y, res, K, A
    
    
    def generate_symbolic_estimate(self):
        """
        To be able to map evaluation of
        kalman feedback, create function:
        
        x0, u, r, p, y, Q, R, P_prev -> x_pred, x_hat, P_hat
        
        NOTE: remember to test equivalence with numeric version.
        
        NB! Only for ODE's.
        """
        
        #F = self.integrator.one_sample
        
        x0 = ca.MX.sym("x0", self.n_x)
        z0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)
        d = ca.MX.sym("d", self.n_d)
        Q = ca.MX.sym("Q", self.n_x, self.n_x)
        R = ca.MX.sym("R", self.n_y, self.n_y)
        dt = ca.MX.sym("dt", 1)
        P_prev = ca.MX.sym("P_prev", self.n_x, self.n_x)
        
        """
        x_apriori = F(
                      x0=x0,
                      z=ca.MX(),
                      u=u,
                      p=p,
                      r=r
                      )["xf"]
        """
        F = self.integrator.chain_integrator()
        res = F(
                x0=x0,
                z0=z0,
                u=u,
                p=p,
                r=r,
                #d=d
                )
        x_apriori = res["xf"]
        z = res["z"]

        # obtain discretized linearization of df/dx:
        A = self.jac_f_x(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        #B = self.jac_f_u(x0,[],u,p,r,y,0,[])
        Ad = ca.expm(A*dt)
        #Bd = A@(Ad - ca.DM.eye(self.n_x))@B
        #x_apriori = A@x0 + B@u

        # obtain discretized linearization of h(x):
        C = self.jac_h(x0,z0,u,p,r,y,ca.MX(),ca.MX(), ca.MX())
        # take symbolic measurement:        
        #h_x = self.h(x_apriori, [])
        h_x = C@x_apriori
        # a priori covariance:
        P_apriori = Ad@P_prev@Ad.T + Q
        # measurement uncertainty:
        V_k = C@P_apriori@(C.T) + R
        # kalman gain:
        K = P_apriori@(C.T)@ca.inv(V_k)
        # posterior state estimate:
        x_posteriori = x_apriori + K@(y - h_x)
        P_aposteriori = (ca.MX.eye(self.n_x) - K@C)@P_apriori
        
        self.one_sample_feedback = ca.Function(
            "F",
            [x0, z0, P_prev, u, r, p, y, Q, R, dt],
            [x_posteriori, z, P_aposteriori, x_apriori, h_x],
            ["x0","z0","P_prev","u","r","p","y","Q","R","dt"],
            ["x_hat","z","P_hat","x_pred","h_x"],
        )
        
    def generate_symbolic_estimate_for_loglik(self):
        """
        To be able to map evaluation of
        kalman feedback, create function:
        
        x0, u, r, p, y, Q, R, P_prev -> x_pred, x_hat, P_hat
        
        NOTE: remember to test equivalence with numeric version.
        
        NB! Only for ODE's.
        """
        
        #F = self.integrator.one_sample
        
        x_0 = ca.MX.sym("x0", self.n_x)
        z_0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        #u_shift = ca.MX.sym("u_1", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)
        dt = ca.MX.sym("dt", 1)
        # here:
        # replace with:
        """
        Recreate symbolic theta:
        """
        Q = ca.MX.sym("Q", self.n_x, self.n_x)
        #Q = ca.veccat(*self.reinit_symbolic_Q())
        #Q_expr = self.dae.sde
        R = ca.MX.sym("R", self.n_y, self.n_y)
        #dt = ca.MX.sym("dt", 1)
        P_0 = ca.MX.sym("P_0", self.n_x, self.n_x)
        """
        To produce log-likelihood expression:
        """
        # obtain linearization of h(x) (usually just [1, 0, ..., 0]):
        C = self.jac_h(x_0,z_0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        # let x0 denote x_0|-1, i.e a one-step pred:
        h_x = C@x_0
        e_k = y - h_x
        # similarly, let P0 denote P_0|-1,
        # yielding the output prediction uncertainty
        #V_k = C@P_0@(C.T) + ca.expm(R)
        V_k = C@P_0@(C.T) + R
        #V_k = C@P_0@(C.T) + R
        # the expression for the loglik becomes:
        loglik = (1/2)*(self.log_det_R(V_k) + \
                  e_k.T@ca.inv(V_k)@e_k + \
                  self.n_y*ca.log(2*ca.pi))
        # the Kalman gain:
        K = P_0@(C.T)@ca.inv(V_k)
        # posterior state, covariance estimate (update equations):
        x_00 = x_0 + K@e_k # x_0|0
        P_00 = (ca.MX.eye(self.n_x) - K@C)@P_0 # P_0|0
        # chain function calls to get DAE-integrator:
        """
        F = self.chain_integrator()
        res = F(
                x0=x_00,
                z0=z_0,
                u=u,
                p=p,
                r=r,
                d=0
                )
        # symbolic simulation:
        x_10 = res["xf"]
        z_1 = res["z"]
        """
     
        # obtain df/dx linearized at t=t_k:
        A = self.jac_f_x(x_0,z_0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        B = self.jac_f_u(x_0,z_0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        Ad = ca.expm(A*dt)
        Bd = ca.inv(Ad)@(Ad - ca.MX.eye(self.n_x))@B
        z_1 = ca.MX()
        x_10 = Ad@x_00 + Bd@u
        #P_10 = self.one_sample_P(P_00, A, self.Q_function(Q, u))
        P_10 = Ad@P_00@Ad.T + Q
        
        self.one_sample_feedback_adj = ca.Function(
            "F",
            [x_0, P_0, z_0, u, r, p, y, Q, R, dt],
            [x_00, P_00, z_1, x_10, h_x, e_k, V_k, P_10, loglik],
            ["x_0","P_0","z_0","u","r","p","y","Q","R","dt"],
            ["x_00","P_00","z","x_10","h_x", "e_k", "V_k", "P_10", "loglik"],
        )
    
    
    
    def generate_symbolic_estimate_partial(self):
        """
        To be able to map evaluation of
        kalman feedback, create function:
        
        x0, u, r, p, y, Q, R, P_prev -> x_pred, x_hat, P_hat
        
        NOTE: remember to test equivalence with numeric version.
        
        NB! Only for ODE's.
        """
        
        #F = self.integrator.one_sample
        
        x0 = ca.MX.sym("x0", self.n_x)
        x10 = ca.MX.sym("x10", self.n_x) # model pred from MPC
        z0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        d = ca.MX.sym("d", self.n_d)
        y = ca.MX.sym("y", self.n_y)
        Q = ca.MX.sym("Q", self.n_x, self.n_x)
        R = ca.MX.sym("R", self.n_y, self.n_y)
        dt = ca.MX.sym("dt", 1)
        P_prev = ca.MX.sym("P_prev", self.n_x, self.n_x)
        
        """
        x_apriori = F(
                      x0=x0,
                      z=ca.MX(),
                      u=u,
                      p=p,
                      r=r
                      )["xf"]
        """
        F = self.integrator.chain_integrator()
        res = F(
                x0=x0,
                z0=z0,
                u=u,
                p=p,
                r=r,
                #d=d
                )
        x_apriori = res["xf"]
        z = res["z"]

        # obtain discretized linearization of df/dx:
        A = self.jac_f_x(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        #B = self.jac_f_u(x0,[],u,p,r,y,0,[])
        Ad = ca.expm(A*dt)
        #Bd = A@(Ad - ca.DM.eye(self.n_x))@B
        #x_apriori = A@x0 + B@u

        # obtain discretized linearization of h(x):
        C = self.jac_h(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        # take symbolic measurement:        
        #h_x = self.h(x_apriori, [])
        #h_x = C@x_apriori
        h_x = C@x10
        # a priori covariance:
        P_apriori = Ad@P_prev@Ad.T + Q
        # measurement uncertainty:
        V_k = C@P_apriori@(C.T) + R
        # kalman gain:
        K = P_apriori@(C.T)@ca.inv(V_k)
        # posterior state estimate:
        #x_posteriori = x_apriori + K@(y - h_x)
        x_posteriori = x10 + K@(y - h_x)
        P_aposteriori = (ca.MX.eye(self.n_x) - K@C)@P_apriori
        
        self.one_sample_feedback_partial = ca.Function(
            "F",
            [x0, x10, z0, P_prev, u, r, p, y, Q, R, dt],
            [x_posteriori, z, P_aposteriori, P_apriori, x_apriori, h_x],
            ["x0","x10", "z0","P_prev","u","r","p","y","Q","R","dt"],
            ["x_hat","z","P_hat","P_pred", "x_pred","h_x"],
        )
        
    def generate_symbolic_smooting_estimate(self):
        """
        To be able to map evaluation of
        kalman feedback, create function:
        
        x_10, u, r, p, y, Q, R, P_10 -> x_11, x_21, P_11, P_21
        
        NOTE: remember to test equivalence with numeric version.
        
        NB! Only for ODE's.
        """
        
        #F = self.integrator.one_sample
        
        x0 = ca.MX.sym("x0", self.n_x)
        x0_1 = ca.MX.sym("x0_1", self.n_x) # x0_-1 --> prior 
        #x10 = ca.MX.sym("x10", self.n_x) # model pred from MPC
        z0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        d = ca.MX.sym("d", self.n_d)
        y = ca.MX.sym("y", self.n_y)
        Q = ca.MX.sym("Q", self.n_x, self.n_x)
        R = ca.MX.sym("R", self.n_y, self.n_y)
        dt = ca.MX.sym("dt", 1)
        P_0 = ca.MX.sym("P_0", self.n_x, self.n_x)
        
        """
        x_apriori = F(
                      x0=x0,
                      z=ca.MX(),
                      u=u,
                      p=p,
                      r=r
                      )["xf"]
        """
        C = self.jac_h(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        V_k = C@P_0@(C.T) + R
        K = P_0@(C.T)@ca.inv(V_k)
        P_00 = (ca.MX.eye(self.n_x) - K@C)@P_0
        #h0 = self.h(x0,z0)
        h0 = C@x0
        res_y = y - h0
        res_x = x0_1 - x0
        residual = (res_y - C@(res_x))
        x_00 = x0_1 + K@residual
        F = self.integrator.chain_integrator()
        res = F(
                x0=x_00,
                z0=z0,
                u=u,
                p=p,
                r=r,
                d=d
                )
        x_10 = res["xf"]
        # obtain discretized linearization of df/dx:
        A = self.jac_f_x(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        #B = self.jac_f_u(x0,[],u,p,r,y,0,[])
        Ad = ca.expm(A*dt)
        #P_10 = Ad@P_00@Ad.T + Q
        P_10 = Ad@P_00@Ad.T + Q
        z = res["z"]        
        
        """
        self.one_sample_smoothing_estimate = ca.Function(
            "F",
            [x0, x0_1, z0, P_0, u, r, p, y, Q, R, dt],
            [x_00, z, P_00, P_10, x_10, K, residual, res_y, res_x, h0, y],
            ["x0","x0_1", "z0","P_0","u","r","p","y","Q","R","dt"],
            ["x_00","z","P_00","P_10", "x_10", "K", "residual", "res_y", "res_x", "h0", "_y"],
        )
        """
        self.one_sample_smoothing_estimate = ca.Function(
            "F",
            [x0, x0_1, z0, P_0, u, r, p, y, d, Q, R, dt],
            [x_00, z, P_00, P_10, x_10, res_x, res_y, K, residual, Ad],
            ["x0","x0_1", "z0","P_0","u","r","p","y","d","Q","R","dt"],
            ["x_00","z","P_00","P_10", "x_10", "res_x", "res_y", "K", "residual", "A"],
        )
        
        
    
            
    def generate_symbolic_estimate_for_loglik_(self):
        """
        To be able to map evaluation of
        kalman feedback, create function:
        
        x0, u, r, p, y, Q, R, P_prev -> x_pred, x_hat, P_hat
        
        NOTE: remember to test equivalence with numeric version.
        
        NB! Only for ODE's.
        """
        
        #F = self.integrator.one_sample
        
        x0 = ca.MX.sym("x0", self.n_x)
        z0 = ca.MX.sym("z0", self.n_z)
        u = ca.MX.sym("u", self.n_u)
        r = ca.MX.sym("r", self.n_r)
        p = ca.MX.sym("p", self.n_p)
        y = ca.MX.sym("y", self.n_y)
        d = ca.MX.sym("d", self.n_d)
        Q = ca.MX.sym("Q", self.n_x, self.n_x)
        R = ca.MX.sym("R", self.n_y, self.n_y)
        dt = ca.MX.sym("dt", 1)
        P_prev = ca.MX.sym("P_prev", self.n_x, self.n_x)
        
        """
        x_apriori = F(
                      x0=x0,
                      z=ca.MX(),
                      u=u,
                      p=p,
                      r=r
                      )["xf"]
        """
        F = self.integrator.chain_integrator()
        res = F(
                x0=x0,
                z0=z0,
                u=u,
                p=p,
                r=r,
                #d=d
                )
        x_apriori = res["xf"]
        z = res["z"]

        # obtain discretized linearization of df/dx:
        A = self.jac_f_x(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        #B = self.jac_f_u(x0,[],u,p,r,y,0,[])
        Ad = ca.expm(A*dt)
        #Bd = A@(Ad - ca.DM.eye(self.n_x))@B
        #x_apriori = A@x0 + B@u

        # obtain discretized linearization of h(x):
        C = self.jac_h(x0,z0,u,p,r,y,ca.MX(),ca.MX(),ca.MX())
        # take symbolic measurement:        
        #h_x = self.h(x_apriori, [])
        h_x = C@x_apriori
        # a priori covariance:
        P_apriori = Ad@P_prev@Ad.T + Q.T@Q
        # measurement uncertainty:
        V_k = C@P_apriori@(C.T) + R.T@R
        # kalman gain:
        K = P_apriori@(C.T)@ca.inv(V_k)
        # posterior state estimate:
        e_k = y - h_x
        x_posteriori = x_apriori + K@e_k
        P_aposteriori = (ca.MX.eye(self.n_x) - K@C)@P_apriori
        loglik = self.log_det_R(V_k) + e_k.T@ca.inv(V_k)@e_k
        
        self.one_sample_feedback_adj = ca.Function(
            "F",
            [x0, P_prev, z0, u, r, p, y, Q, R, dt],
            [x_posteriori, P_aposteriori, z, x_apriori, h_x, e_k, V_k, loglik],
            ["x0","P_prev","z0","u","r","p","y","Q","R","dt"],
            ["x_hat","P_hat","z","x_pred","h_x", "e_k", "V_k", "loglik"],
        )
    
    def chain_integrator(self):
        """
        Chain rootfinder for z (G) into integrator I.
        """
        _x0 = ca.MX.sym("x0", self.dae.n_x)
        _z0 = ca.MX.sym("z0", self.dae.n_z)
        #_z = ca.MX.sym("z", self.dae.n_z)
        _u = ca.MX.sym("u", self.dae.n_u)
        _p = ca.MX.sym("p", self.dae.n_p)
        _r = ca.MX.sym("r", self.dae.n_r)
        _d = ca.MX.sym("d", self.dae.n_d)
        z_expr = self.integrator.G(_z0, _x0, _u, _p, _r)
        I_chained_expr = self.integrator.one_sample(_x0, z_expr, _u, _p, _r, _d)
        return ca.Function("I_chained",
                            [_x0, _z0, _u, _p, _r, _d],
                            [I_chained_expr, z_expr],
                            ["x0","z0","u","p","r","d"],
                            ["xf", "z"])
        

    def plot_results(self, boptest_df, \
                     boptest_map: dict, \
                     origin='2020-01-01'):
        ''' 
        Plot estimation results,
        compared with measurements.
         ''' 
        dt_index = pd.to_datetime(boptest_df.index, unit="s", origin=pd.Timestamp(origin))
        
        # temp fix
        keep = list(boptest_map.values())
        boptest_df = boptest_df[[col for col in keep]]
    
        boptest_df.index = dt_index
        df_ds = boptest_df.resample(rule=str(self.h) + "S").asfreq()

        # to align, leave out last
        df_ds = df_ds.iloc[:-1]
        self.df.index = df_ds.index

        fig, axes = plt.subplots(len(self.df.columns))
        
        for meas_col, est_col, ax in zip(df_ds.columns, self.df.columns, axes):
            labels = [self.latexize_est(est_col), self.latexize_meas(meas_col)]
            ax.plot(df_ds.index, self.df[est_col], color="r")
            ax.plot(df_ds.index, df_ds[meas_col], color="b")
            ax.legend(labels, loc='upper right', prop={'size': 10}, ncol=1)

        return fig, ax


    @staticmethod
    def latexize_meas(name):
        name, typ = name.split("_") # naming convention
        typ = "{" + typ + "}"
        return f"${name}_{typ}$"

    @staticmethod
    def latexize_est(name):
        name = "{" + name + "}"
        return f"$\hat{name}$"
