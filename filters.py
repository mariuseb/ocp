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
    pass

class EKF(Filter):
    ''' . '''
    def __init__(self, cfg):
        
        if isinstance(cfg, str) or isinstance(cfg, os.PathLike):
            with open(cfg, "r") as f:
                cfg = json.load(f)
        
        self.Q = ca.DM(np.diag(cfg["Q"]))
        self.R = ca.DM(np.diag(cfg["R"]))
        
        self.dt = cfg["dt"]
        self.dae = dae = DAE(cfg["model"])
        
        # easy access for y:
        
        P_prev = cfg.pop("P0", None)
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
        self.init_h_expr()
        self.init_f()
        self.init_h()
        self.init_jac_f_x()
        self.init_jac_h_x()
        self.init_identity()
        
        #self.init_DMs()
        self.k = 0
        # dae.order:
        #self.y_names = [self.dae.y[key].name() for key in self.dae.y.keys()]
        # for states:
        self.df = pd.DataFrame(columns=self.dae.x)
        # for state covariance:
        self.P = {0: P_prev}
        

    def init_identity(self):
        self.I = ca.DM.eye(self.x_symbolic.shape[0])

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
    
    def init_h(self):
        self.h = self.integrator.h

    # for differentiation:
    def init_f_expr(self):
        self.f_expr = ca.vertcat(self.integrator.ode)
    
    def init_h_expr(self):
        self.h_expr = ca.vertcat(self.integrator.h_expr)

    def set_params(self, p):
        self.p = p
        
    def set_Q(self, Q):
        self.Q = Q
        
    def set_R(self, R):
        self.R = R

    @property
    def y(self):
        return list(map(lambda x: x.name(), self.dae.y.values()))

    @property
    def x_symbolic(self):
        return self.integrator.x

    @property
    def jac_f_x(self):
        return ca.jacobian(self.f_expr, self.x_symbolic)

    @property
    def jac_h_x(self):
        return ca.jacobian(self.h_expr, self.x_symbolic)      
    
    def init_jac_f_x(self):
        self.jac_f = ca.Function('jac_f',
                                self.integrator.all_vars,
                                [self.jac_f_x],
                                self.order,
                                ['jac_f']) 
        

    def init_jac_h_x(self):
        self.jac_h = ca.Function('jac_h',
                                self.integrator.all_vars,
                                [self.jac_h_x],
                                self.order,
                                ['jac_h']) 

    # rethink this inteface
    def estimate(
                 self,
                 x_pred,
                 u=ca.DM(0),
                 r=ca.DM(0),
                 y=ca.DM(0), 
                 p=None,
                 z=ca.DM(0),
                 v=ca.DM(0),
                 w=ca.DM(0)
                 ):
        ''' 
        Assume general non-linear structure.
        Thus, A and C have to be looked up
        at each step.
        
        NOTE: x_pred from mpc.
         '''
         
        A = self.jac_f(x_pred, z, u, self.p if p is None else p, w, v, y, r)
        C = self.jac_h(x_pred, z, u, self.p if p is None else p, w, v, y, r)
        h_x = self.h(y, x_pred, z, u, self.p if p is None else p, v, r)
        try:
            
            P_apriori = ca.mtimes([A, self.P_prev, ca.transpose(A)]) + self.Q
            
        except AttributeError:
            """
            first iteration, do the calculation:
                P_0 = P_s int_t0^{t1} exp(A*dt)QQ^{T}exp(A*dt)^{T}dt
            """
            #from scipy import integrate
            #from numpy import vectorize
            from sympy import var, Matrix, MatMul, HadamardPower
            #from sympy import integrate, var, Matrix, MatrixSymbol, Transpose, transpose, MatMul, HadamardPower, hadamard_product  
            import scipy
            from sympy.utilities import lambdify
            from mpmath import quad
            P_s = 1 # scaling factor

            A = np.array(A)
            Q = np.array(self.Q)
            """
            Integrate P0 through 
            the Wiener process.
            
            Cf. https://ctsm.info/mathguide.pdf,
            page 19.
            """            
            _A = Matrix(A)
            _Q = Matrix(Q)
            dt = var("dt")
             
            exp_A = HadamardPower(np.e, _A*dt)
            quadr = MatMul(exp_A, MatMul(_Q, MatMul(_Q.T, exp_A.T)))
            P_0 = scipy.zeros(quadr.shape, dtype=float)
            for (i,j), expr in scipy.ndenumerate(quadr):
                tmp = lambdify((dt), expr, 'math')
                P_0[i,j] = quad(tmp, (0, self.dt))
            self.P_prev = ca.DM(P_0)    
            P_apriori = ca.mtimes([A, self.P_prev, ca.transpose(A)]) + self.Q
        
        # Kalman gain:
        K = ca.mtimes(ca.mtimes(P_apriori, ca.transpose(C)), ca.inv(ca.mtimes([C, P_apriori, ca.transpose(C)]) + self.R))
        # filtered prediction:
        x_post = x_pred + ca.mtimes(K, (y - h_x))
        # reshape for storing.
        x_post = np.array(x_post).reshape(-1)
        # store estimation result. TODO: check ordering of states.
        self.df.loc[self.k*self.dt, self.dae.x] = x_post
        # filtered covariance prediction:
        self.P_prev = ca.mtimes((self.I - ca.mtimes(K, C)), P_apriori)
        self.k += 1
        # store it:
        self.P[self.k] = ca.mtimes((self.I - ca.mtimes(K, C)), P_apriori)

        return x_post

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
    
"""
Kalman-Bucy filter:
"""
    
class KalmanBucy(Filter):
    ''' . '''
    def __init__(self, cfg, **kwds):
        
        if isinstance(cfg, str) or isinstance(cfg, os.PathLike):
            with open(cfg, "r") as f:
                cfg = json.load(f)
        
        self.Q = ca.DM(np.diag(cfg["Q"]))
        self.R = ca.DM(np.diag(cfg["R"]))
        
        self.dt = cfg["dt"]
        
        # algorithmic functions:
        functions = kwds.pop("functions", None) 
        cfg["model"]["functions"] = functions
        self.dae = dae = DAE(cfg["model"])
        
        # easy access for y:
        
        P_prev = cfg.pop("P0", None)
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
        self.init_h_expr()
        self.init_P()
        self.init_f()
        self.init_h()
        self.init_jac_f_x()
        self.init_jac_h_x()
        self.init_identity()
        
        #self.init_DMs()
        self.k = 0
        # dae.order:
        #self.y_names = [self.dae.y[key].name() for key in self.dae.y.keys()]
        # for states:
        self.df = pd.DataFrame(columns=self.dae.x)
        # for state covariance:
        self.P = {0: P_prev}
        

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
    def jac_f_x(self):
        return ca.jacobian(self.f_expr, self.x_symbolic)

    @property
    def jac_h_x(self):
        #return ca.jacobian(self.h_expr, self.x_symbolic)      
        # CORRRECTION:
        return ca.jacobian(self.h_expr, ca.vertcat(self.x_symbolic, self.z_symbolic))
    
    def init_jac_f_x(self):
        self.jac_f = ca.Function('jac_f',
                                self.integrator.all_vars,
                                [self.jac_f_x],
                                self.order,
                                ['jac_f']) 
        

    def init_jac_h_x(self):
        self.jac_h = ca.Function('jac_h',
                                self.integrator.all_vars,
                                [self.jac_h_x],
                                self.order,
                                ['jac_h']) 
        
        
    def init_P(self):
        
        # linearized dynamics at t = t_k:
        n_x = self.dae.n_x + self.dae.n_z
        #n_x = self.dae.n_x
        
        A = ca.SX.sym("A", n_x, n_x)
        # covariance scaling matrix, linearized at current timestep t = t_k:
        sigma = ca.SX.eye(n_x)
        
        for n in range(n_x):
            s = ca.SX.sym("s" + str(n))
            sigma[n,n] = s     
        """
        s1 = ca.SX.sym("s1")
        s2 = ca.SX.sym("s2")
        sigma[0,0] = s1
        sigma[1,1] = s2
        """
        #sigma = ca.diag(ca.SX([s1,s2]))
        #sigma = ca.SX(ca.Sparsity.diag([s1,s2])) # sparse by def
        #sigma = ca.SX(ca.Sparsity.diag([s1,s2])) # sparse by def
        # state covariance at t = t_k:
        P0 = ca.SX.sym("P0", n_x, n_x)

        # rhs of state covariance dynamics:
        rhs_P = ca.vertcat(ca.mtimes(A, P0) + ca.mtimes(P0, A.T) + ca.mtimes(sigma, sigma.T))

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

        P_final = P0 + dt/6.0*(k1+2*k2+2*k3+k4)

        # integrator for state covariance:
        F = ca.Function('F_P',[P0, A, sigma],[P_final])
        
        #noise_final = states+dt/6.0*(k1+2*k2+2*k3+k4)

        # simulator / integrator for process noise:
        #F_noise = ca.Function('F_noise',[noise, A_sym, sigma],[noise_final])

        #P = ca.SX.sym("P", 2, 2)
        # state covariance at t = t_k+1, evolve:
        P = P0

        for i in range(N_steps_per_sample):
            P = F(P, A, sigma)

        # Create one for process noise
        self.one_sample_P = ca.Function('one_sample_P', [P0, A, sigma], [P])

    # rethink this inteface
    def estimate(
                 self,
                 x_pred,
                 u=ca.DM(),
                 r=ca.DM(),
                 y=ca.DM(), 
                 p=None,
                 z=ca.DM(),
                 v=ca.DM(),
                 w=ca.DM()
                 ):
        ''' 
        Assume general non-linear structure.
        Thus, A and C have to be looked up
        at each step.
        
        NOTE: x_pred from mpc.
         '''
         
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
         
        A = self.jac_f(x_pred, z, u, self.p if p is None else p, w, v, y_pad, r)
        
        # pad A, if z
        dim = self.dae.n_z + self.dae.n_x
        if self.dae.n_z > 0:
            _A = A
            #dim = self.dae.n_z + self.dae.n_x
            A = ca.DM.zeros((dim, dim))
            A[0:self.dae.n_x, 0:self.dae.n_x] = _A
            
        
        Ad = expm(A*self.dt)
        C = self.jac_h(x_pred, z, u, self.p if p is None else p, w, v, y_pad, r)
        #h_x = self.h(y, x_pred, z, u, self.p if p is None else p, v, r)
        h_x = self.h(x_pred, z)
        try:
            # discrete-time:
            #P_apriori = ca.mtimes([A, self.P_prev, ca.transpose(A)]) + self.Q
            
            # continous-time, assume constant sigma/Q:
            P_apriori = self.one_sample_P(self.P_prev, A, self.Q)
            
        except AttributeError:
            """
            first iteration, do the calculation:
                P_0 = P_s int_t0^{t1} exp(A*dt)QQ^{T}exp(A*dt)^{T}dt
            """
            from scipy import integrate
            from numpy import vectorize
            P_s = 4 # scaling factor
            
            """
            A = np.array(A)
            Q = np.array(self.Q)
            # quadrature:
            #@staticmethod
            def f(A, Q):
                def g(dt):
                    #return np.exp(A*dt)@Q@Q.T@np.exp(A*dt).T
                    return np.matmul(np.exp(A*dt), np.matmul(Q, np.matmul(Q.T, np.exp(A*dt).T)))
                return g
            
            _A = np.array(A)
            _Q = np.array(self.Q)
            fv = np.vectorize(f)
            u = fv(_A, _Q)
            
            P0 = np.vectorize(integrate.quad)(u, 0, self.dt)
            
            from sympy import integrate, var, Matrix, MatrixSymbol, Transpose, transpose, MatMul, HadamardPower, hadamard_product  
            import scipy
            from sympy.utilities import lambdify
            from mpmath import quad
            
            _A = Matrix(A)
            _Q = Matrix(Q)
            dt = var("dt")
            #_A[0,0] *= dt 
            #_A[0,1] *= dt 
            #_A[1,0] *= dt 
            #_A[1,1] *= dt 
            
            exp_A = HadamardPower(np.e, _A*dt)
            
            quadr = MatMul(exp_A, MatMul(_Q, MatMul(_Q.T, exp_A.T)))
            
            P_0 = scipy.zeros(quadr.shape, dtype=float)
            
            #quadr.subs({_A: A, _Q: Q})
            for (i,j), expr in scipy.ndenumerate(quadr):
                tmp = lambdify((dt), expr, 'math')
                P_0[i,j] = quad(tmp, (0, self.dt))
            
            self.P_prev = P_s*ca.DM(P_0)
            #P00 = integrate(quadr[0,0], (dt, 0, self.dt))
            #P01 = integrate(quadr[0,1], (dt, 0, self.dt))
            #P10 = integrate(quadr[1,0], (dt, 0, self.dt))
            #P11 = integrate(quadr[1,1], (dt, 0, self.dt))
            
            #P0 = integrate(quadr, (dt, 0, self.dt))
            """
            
            self.P_prev = self.one_sample_P(ca.DM.eye(dim), A, self.Q)
            
            #P_apriori = ca.mtimes([Ad, self.P_prev, ca.transpose(Ad)]) + self.Q
            
            # continous-time, assume constant sigma/Q:
            P_apriori = self.one_sample_P(self.P_prev, A, self.Q)
            
            #self.P_prev = integrate.quadrature(f, 0, self.dt, args=(np.array(A), self.dt, np.array(self.Q)))
            #global _A
            #global _Q
            #_A = np.array(A)
            #_Q = np.array(self.Q)
            
            #dt = self.dt
            
            #tol = np.array([[1E-5, 1E-5], [1E-5, 1E-5]])
            #rtol = np.array([[1E-5, 1E-5], [1E-5, 1E-5]])
            #self.P_prev = vectorize(integrate.quadrature)(f, 0, dt)
            #self.P_prev = integrate.quadrature(f, 0, dt, tol=tol, rtol=rtol)
            #self.P_prev = integrate.quadrature(f, 0, self.dt, args=(_A, _Q))
            
            
            """
            Nm, Mm = np.meshgrid(range(3), range(2))

            def f(m,n):
                def g(x):
                    return m*x+n*x
                return g

            fv=np.vectorize(f)

            u=fv(Mm,Nm)

            np.vectorize(integrate.quad)(u,0,1)
            
            # casadi expr:
            A_sym = ca.SX.sym("A", 2,2)
            Q_sym = ca.SX.sym("Q", 2,2)
            x_sym = ca.SX.sym("x", 2,2)
            s = ca.SX.sym("s")
            
            # integrand:
            expr = ca.mtimes(
                             ca.exp(A_sym*s),
                             ca.mtimes(
                                    Q_sym,
                                        ca.mtimes(
                                                Q_sym.T,
                                                ca.exp(A_sym*s).T
                                                 )
                                        )
                             )
            P0 = ca.Function("P0",
                             [A_sym, Q_sym, s],
                             [expr],
                             ["A", "Q", "s"],
                             ["P0"])
            
            opts = {
                    "step0":    self.dt,
                    "t0"      : 0.0,
                    "tf"      : self.dt,
                    "abstol"  : 1E-4
                            }
            """
            # u->z in integrator call (algebraic var, constant on between phase boundaries (check term. in Betts ch. 4))
            #I = ca.integrator("I", "idas", {"x": x_sym, "p": ca.vertcat(A_sym, Q_sym), "ode": expr}, opts)
            #expr = ca.mtimes(ca.exp(A_sym*s), ca.mtimes(Q_sym, ca.mtimes())
             
            

        K = ca.mtimes(ca.mtimes(P_apriori, ca.transpose(C)), ca.inv(ca.mtimes([C, P_apriori, ca.transpose(C)]) + self.R))
        #x_post = x_pred + ca.mtimes(K, (y - h_x))  
        x_pred = np.append(x_pred, z)
        x_post = x_pred + ca.mtimes(K, (y_pad - h_x))
        x_post = np.array(x_post).reshape(-1)
        # store estimation result. TODO: check ordering of states.
        self.df.loc[self.k*self.dt, self.dae.x + self.dae.z] = x_post
        self.P_prev = ca.mtimes((self.I - ca.mtimes(K, C)), P_apriori)
        self.k += 1
        
        # keep P a posteriori:
        #self.P[self.k] = deepcopy(self.P_prev)
        self.P[self.k] = ca.mtimes((self.I - ca.mtimes(K, C)), P_apriori)

        return x_post[0:self.dae.n_x]

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
