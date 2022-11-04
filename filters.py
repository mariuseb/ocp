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

'''
An EKF implementation.
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
        if P_prev is None:
            self.P_prev = ca.DM.eye(self.dae.n_x)

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
        P_apriori = ca.mtimes([A, self.P_prev, ca.transpose(A)]) + self.Q

        K = ca.mtimes(ca.mtimes(P_apriori, ca.transpose(C)), ca.inv(ca.mtimes([C, P_apriori, ca.transpose(C)]) + self.R))

        x_post = x_pred + ca.mtimes(K, (y - h_x))

        x_post = np.array(x_post).reshape(-1)
        # store estimation result. TODO: check ordering of states.
        self.df.loc[self.k*self.dt, self.dae.x] = x_post
        self.P_prev = ca.mtimes((self.I - ca.mtimes(K, C)), P_apriori)
        self.k += 1
        
        # keep P a posteriori:
        #self.P[self.k] = deepcopy(self.P_prev)
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
