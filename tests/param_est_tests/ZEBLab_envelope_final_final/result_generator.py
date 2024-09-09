"""
This class takes in a trained grey-box model.

- produces results in the form of:
    - validate simulation fit on training data with one repeated simulation
    - generate the one-step ahead prediction using a vanilla discrete-time Kalman filter (time-varying : need switching point)
    - generate plots of trajectories, both
        - training
        - and validation datasets. 
    - produce table with:
        - R2 score
        - AIC
        - BIC (maybe)
        - (N)-RMSE
    - plot distribution of residuals
        - one-step
        - simulation
    for both validation and training sets.
    - plot acf, cp of one-step residuals
    
NOTE: 
    - grey-box model defined by:
        - structure (json file)
        - parameters

"""
import pandas as pd
import numpy as np
from utils import ZEBData
from ocp.param_est import ParameterEstimation
import matplotlib.pyplot as plt
from ocp.filters import KalmanDAE
#from utils import save_journal_plot, plot_residuals
from matplotlib import rc
from sklearn.metrics import r2_score
# text:
rc('text', usetex=True)
from scipy.stats import norm
import casadi as ca
from copy import deepcopy

class ResultGenerator(object):
    """
    Result generator.
    """
    def __init__(self,
                 config=None,
                 params=None,
                 dt=None,
                 slack=False,
                 z_guess=None):
        # for simplicity, to get the integrator:
        self.param_est = \
            param_est = ParameterEstimation(
                            config=config,
                            N=2, # no map in any case
                            dt=dt,
                            slack=slack,
                            param_guess=params
                            )
        self.config = config
        self.dt = dt
        self.slack = slack
        self.dae = param_est.dae
        self.I = param_est.integrator.one_sample
        self.G = param_est.integrator.G
        self.params = params
        self.z_guess = z_guess
        
    def half_day_validation_runner(
        self,
        ekf_config,
        start,
        N_days,
        param_guess,
        param_est,
        data,
        plot=True,
        prior_weight=1,
        sampling_rate="60min"
    ):
        p0 = param_est.p0
        cols = ["mse",
                "rmse",
                "nrmse",
                "cv-rmse",
                "r2",
                "r2_adj",
                "aic",
                "bic"]
        
        metrics = pd.DataFrame(
                            columns=cols
                            )
        training_metrics = pd.DataFrame(
                            columns=cols
                            )
        params_hist = pd.DataFrame(columns=list(param_guess.keys()))
        
        fig, axes = plt.subplots(7,2, sharex=False)
        # iterate:
        for delta_day in range(N_days):
            
            stop = start + pd.Timedelta(days=14)
            y_data = data.get_dataset(start=start, stop=stop)
            
            if not y_data.Ti.isna().any():
                """
                Skip if any holes in temperature
                """    
                y_data = y_data.bfill()
                y_data = y_data.groupby(pd.Grouper(freq=sampling_rate)).mean().dropna()
                y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
                
                N = len(y_data)
                dt = (y_data.index[1] - y_data.index[0]).seconds
                # set range index for identification:
                y_data.index = range(0,N*dt,dt)
            
        
                x_guess = np.array([
                                y_data.Ti.values.flatten(),
                                y_data.Ti.values.flatten() - 2
                                ])
                lbx = 0.7*x_guess
                ubx = 2*x_guess

                param_guess["alpha_vent_sup"]["ub"] = 1.1
                param_guess["alpha_vent_ext"]["ub"] = 1.1
                
                Q = ca.DM.eye(2)
                R = ca.DM.eye(1)
                P0 = ca.DM.eye(param_est.n_p + param_est.n_x)*prior_weight
                #for n in (1,3,5,7):
                #    P0[n,n] = 0
                for n in range(param_est.n_p, param_est.n_p + param_est.n_x):
                    P0[n,n] = 0
                #P0[9,9] = 1E3
                if delta_day < 100:
                    lbp = param_est.get_lbp(1e-2)
                    ubp = param_est.get_ubp(1e2)
                else:
                    lbp = p0
                    ubp = p0
                    
                sol, params = param_est.solve(
                            y_data,
                            #param_est.p0,
                            p0,
                            lbp=lbp,
                            ubp=ubp,
                            lbx=lbx,
                            ubx=ubx,
                            x_guess=x_guess,
                            x_N = np.array([293.15,293.15]), # not used
                            P0=P0,
                            covar=ca.veccat(Q, R),
                            codegen=True
                            )
                x0 = sol[self.x].iloc[0]   
                self.simple_sim_plot(
                                        y_data,
                                        x0,
                                        params,
                                        plot=False,
                                        map_eval=True,
                                        chained_eval=True,
                                        ax=axes[delta_day, 0]
                                        )            
                # obtain one-step ahead estimate:
                self.simple_one_step_plot(
                                                y_data,
                                                x0, 
                                                p_base=params,
                                                #p_mod=p_mod,
                                                p_tvp=params.values,
                                                tvp=False,
                                                ekf_config=ekf_config,
                                                cond_series=y_data.vent,
                                                plot=False,
                                                map_eval=True,
                                                switch=None,
                                                symbolic_estimate=True
                                                )   
                train_metrics = self.report_metrics("training")
                
                """
                Split validation in two:
                """
                
                y_data = data.get_dataset(
                                start = stop,
                                stop = stop + pd.Timedelta(days=0.5)
                                )  
                        
                if y_data.Ti.isna().any():
                    # check what happens
                    print(params)
                    
                y_data_raw = y_data.bfill()
                y_data_raw.index.name = "time"
                y_data = y_data_raw.groupby(pd.Grouper(freq=sampling_rate)).mean() #.dropna(axis=1)
                y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
                x0 = self.filtered[self.x].iloc[-1]
                #x0 = sol[self.x].iloc[-1]
                self.simple_sim_plot(
                                    y_data,
                                    x0,
                                    params,
                                    #plot=plot,
                                    plot=plot,
                                    map_eval=True,
                                    #symbolic_estimate=True
                                    ax=axes[delta_day, 0]
                                    )
                test_metrics = self.report_metrics("validation (bic, aic not valid)")
                metrics.loc[delta_day, :] = test_metrics.loc[metrics.columns].values.flatten()
                training_metrics.loc[delta_day, :] = train_metrics.loc[metrics.columns].values.flatten()
            
                self.simple_one_step_plot(
                                        y_data,
                                        x0, 
                                        p_base=params,
                                        #p_mod=p_mod,
                                        p_tvp=params.values,
                                        tvp=False,
                                        ekf_config=ekf_config,
                                        cond_series=y_data.vent,
                                        plot=False,
                                        map_eval=True,
                                        switch=None,
                                        symbolic_estimate=True
                                        )   
                #plt.show(block=True)
                #plt.close()
                train_metrics = self.report_metrics("training")
                y_data = data.get_dataset(
                                start = stop + pd.Timedelta(days=0.5),
                                stop = stop + pd.Timedelta(days=1)
                                )  
                        
                if y_data.Ti.isna().any():
                    # check what happens
                    print(params)
                    
                y_data_raw = y_data.bfill()
                y_data_raw.index.name = "time"
                y_data = y_data_raw.groupby(pd.Grouper(freq=sampling_rate)).mean() #.dropna(axis=1)
                y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
                x0 = self.filtered[self.x].iloc[-1]
                #x0 = sol[self.x].iloc[-1]
                self.simple_sim_plot(
                                    y_data,
                                    x0,
                                    params,
                                    #plot=plot,
                                    plot=plot,
                                    map_eval=True,
                                    #symbolic_estimate=True
                                    ax=axes[delta_day, 1]
                                    )
                test_metrics = self.report_metrics("validation (bic, aic not valid)")    
                metrics.loc[delta_day+0.5, :] = test_metrics.loc[metrics.columns].values.flatten()       
                param_guess = {
                    k: {
                        "init": params.loc[k],
                        "lb": 1e-2*params.loc[k],
                        "ub": 1e2*params.loc[k]
                        }
                    for k in params.index
                }
                params_hist.loc[delta_day] = params
                # advance 1 day:
                start = start + pd.Timedelta(days=1)
        
                if float(test_metrics.loc["nrmse"]) > 1:
                    # check what happens
                    print(params)
                p0 = params.values
                
        return fig, \
               axes, \
               training_metrics, \
               metrics, \
               params_hist
                
       
    def mse(self, y, y_pred):
        """
        Report the mse.
        """
        return ((y - y_pred) ** 2).mean()

    def rmse(self, y, y_pred):
        return np.sqrt(self.mse(y, y_pred))
    
    def nrmse(self, y, y_pred, by_std_dev=True):
        """
        Normalize by |y_max - y_min|
        """
        
        rmse = self.rmse(y, y_pred)
        if by_std_dev:
            return rmse/y.std()
        else:
            return rmse/(y.max() - y.min())
    
    def aic(self, y, y_pred, num_params):
        """
        Akaike's information criterion.
        """
        n = len(y)
        mse = self.mse(y, y_pred)
        #aic = 2*num_params - n*np.log(mse)
        aic = n*np.log(mse) + 2*num_params
        return aic
    
    def bic(self, y, y_pred, num_params):
        """
        Akaike's information criterion.
        """
        n = len(y)
        mse = self.mse(y, y_pred)
        #aic = n*log(mse) + 2*num_params
        #bic = num_params*np.log(n) - n*np.log(mse)
        bic =  n*np.log(mse) + num_params*np.log(n)
        return bic
    
    def report_metrics(self, name):
        """
        Require simulation first.
        """
        metrics = pd.DataFrame(
                               index=["mse",
                                      "rmse",
                                      "nrmse",
                                      "aic",
                                      "bic"],
                               columns=[name]
                               )
        
        y_pred, y = self.res["Ti"], self.y_data["y1"]
        try:
            y_one_step = self.one_step_res["Ti"]
            metrics.loc["one_step_mse", name] = self.mse(y, y_one_step)
        except: 
            pass
        metrics.loc["mse", name] = self.mse(y, y_pred)
        metrics.loc["rmse", name] = self.rmse(y, y_pred)
        metrics.loc["nrmse", name] = self.nrmse(y, y_pred)
        metrics.loc["cv-rmse", name] = metrics.loc["rmse", name]/y.mean()
        metrics.loc["r2", name] = r2_score(y, y_pred)
        # to calculate r^2 adjusted:
        r2 = metrics.loc["r2", name]
        np = self.dae.n_p
        n = len(y)
        #
        metrics.loc["r2_adj", name] = (1 - (1 - r2))*((n-1)/(n - np - 1))
        metrics.loc["aic", name] = self.aic(y, y_pred, self.num_params)
        metrics.loc["bic", name] = self.bic(y, y_pred, self.num_params)
        
        return metrics
        
    @property
    def num_params(self):
        return len(self.params)
        
        
    def simulate_full(
                      self,
                      x0,
                      y_data,
                      p,
                      map_eval=False,
                      chained_eval=True
                      ):
        """
        Simulate w/o feedback.
        
        Returns dataframe of state trajectory.
        """
        
        # empty arrays for keeping state:
        xs = np.array([])
        zs = np.array([])
        # p to array:
        #p = self.params.values.flatten()
        I = self.I
        G = self.G
        """
        Try initial z_guess as ones:
        """
        
        #z_guess = [1]*self.dae.n_z
        
        # get time-varying params:
        """
        TODO: generalize.
        
        But for now, assume all
        z to be tv parameters.
        """
        #tvp = self.dae.z
        tvp = list(map(lambda x: x.split("_")[0], [p for p in self.dae.z if p.endswith("_a")]))
        if self.z_guess is None:
            z_guess = self.params.loc[tvp].values
        else:
            z_guess = self.z_guess
            
        v = [0]*self.dae.n_v
        N = len(y_data)
        
        xs = np.append(xs, np.array(x0))
        
        if chained_eval: # default
            """
            Chain rootfinder for z (G) into integrator I.
            """
            _x0 = ca.MX.sym("x0", self.dae.n_x)
            _z0 = ca.MX.sym("z0", self.dae.n_z)
            _z = ca.MX.sym("z", self.dae.n_z)
            _u = ca.MX.sym("u", self.dae.n_u)
            _p = ca.MX.sym("p", self.dae.n_p)
            _r = ca.MX.sym("r", self.dae.n_r)
            # = ca.MX.sym("r", self.dae.n_r)
            z_expr = G(_z0, _x0, _u, _p, _r)
            I_chained_expr = I(_x0, z_expr, _u, _p, _r)
            I = ca.Function("I_chained",
                                    [_x0, _z0, _u, _p, _r],
                                    [I_chained_expr, z_expr],
                                    ["x0","z0","u","p","r"],
                                    ["xf", "z"])
        
        
        if not map_eval:
            for n in range(N-1):
                u = y_data[self.dae.u_names].iloc[n].values
                r = y_data[self.dae.r_names].iloc[n].values
                x0, z = I(x0, z_guess, u, p, r)
                xs = np.append(xs, np.array(x0))
                zs = np.append(zs, np.array(z))
                z_guess = z 
            xs = xs.reshape(N, self.dae.n_x)
        else: # map
            """
            No algebraic vars, time-varying parameters
            yet. 
            
            However, should be straightforward, can 
            chain rootfinder map into ODE-integrator.
            """
            F_map = I.mapaccum("simulator", N-1, [0,1],[0,1])
            _res = F_map(
                x0=x0,
                z0=z_guess,
                u=y_data[self.dae.u].values.T[:,:-1],
                p=ca.repmat(p, 1, N-1),
                r=y_data[self.dae.r_names].values.T[:,:-1],
            )
            xf = np.array(_res["xf"]).T
            zs = np.array(_res["z"]).T
            xs = np.append(xs, xf)
            
        res, y_data = self._post_process_sim(
                                      xs,
                                      zs,
                                      y_data
                                      )
        self.res = res
        self.y_data = y_data
        return res, y_data
    
    def simulate_one_step(
                          self, 
                          x0,
                          y_data,
                          ekf_config=None,
                          tvp=False,
                          cond_series=None,
                          p_base: pd.Series = None,
                          p_mod: pd.Series = None,
                          p_tvp: pd.Series = None,
                          switch=None,
                          map_eval=False,
                          symbolic_estimate=False,
                          R=None,
                          Q=None,
                          P0=None
                          ):
        """
        Simulate one-step ahead with Kalman feedback.
        """
        ekf = KalmanDAE(ekf_config)
        if R is not None:
            ekf.set_R(R)
        if Q is not None:
            ekf.set_Q(Q)
        if P0 is None:
            P_prev = np.diag([1]*ekf.n_x)
        #ekf.set_R(np.diag([1]))
        # set R, Q? P0?
        N = len(y_data)
        x_names = ekf.dae.x
        result = pd.DataFrame(
                              index=range(N),
                              columns=["res", "y_pred","y_meas"] + x_names
                              )
    
        xs = np.array([x0])
        zs = np.array([])
        #I = ekf.integrator.one_sample    
        I = self.I
        G = self.G
        v = [0]*self.dae.n_v
        #z_guess = self.z_guess
        tvp = list(map(lambda x: x.split("_")[0], [p for p in self.params.index if p.endswith("_w")]))
        if self.z_guess is None:
            z_guess = self.params.loc[tvp].values
        else:
            z_guess = self.z_guess
        
        if not tvp:
            p_base = p_tvp
            
        # get correct order for ekf:
        if isinstance(p_base, (pd.Series, pd.DataFrame)):
            p_base = p_base.loc[ekf.dae.p].values.flatten()

        if switch is None:
            def bypass(cond):
                return p_base
            switch = bypass
            
        if cond_series is None:
            cond_series = pd.Series([0]*N)
            
        result.loc[0, "y_meas"] = float(y_data[ekf.dae.y_names].iloc[0].values)
        result.loc[0, "y_pred"] = float(np.array(x0)[0])
        result.loc[0, ekf.dae.x] = x0
            
        if not map_eval:    
            if not symbolic_estimate:
                """
                Regular numerical evaluation.
                """
                # first y:
                for n in range(N-1):   
                    u = y_data[ekf.dae.u_names].iloc[n].values
                    r = y_data[ekf.dae.r_names].iloc[n].values
                        
                    #p = switch(y_data.index[0], p_base, p_mod)
                    #p = switch(cond_series.iloc[n], p_base, p_mod)
                    p = switch(cond_series.iloc[n])
                    """
                    TODO: figure out ordering of z,x.
                    For now, we assume ability estimate
                    X_k = (z_k-1, x_k), i.e. z lagging x
                    by one time-step.
                    """
                    # z_k-1|k-1:
                    z_pred = G(z_guess, x0, u, p_tvp, r)
                    # x_k|k-1:
                    x_pred = I(x0,z_pred,u,p_tvp,r)
                    result.loc[n+1, "y_pred"] = float(np.array(x_pred)[0])
                    #x_pred = I(x0,z_pred,u,p,r)
                    
                    xs = np.append(xs, np.array(x_pred))    
                    zs = np.append(zs, np.array(z_pred))
                    # guess for next iteration:
                    z_guess = z_pred
                    # filtering of prediction:s
                    residual_cols = list(map(lambda x: x + "_res", ekf.y))
                    try:
                        """
                        Return filtered x, z splitted
                        """
                        x0, z0, h0 = ekf.estimate(
                                                x_pred,
                                                #z=z_pred,
                                                z=np.array([]),
                                                p=p,
                                                y=y_data[ekf.dae.y_names].iloc[n+1].values,
                                                u=y_data[ekf.dae.u].iloc[n].values,
                                                r=y_data[ekf.dae.r_names].iloc[n].values
                                            )
                        result.loc[n+1, "y_meas"] = float(y_data[ekf.dae.y_names].iloc[n+1].values)
                        #result.loc[n, "res"] = np.array(x_pred[0,0])[0][0] - y_data[ekf.dae.y_names].iloc[n+1].values
                        """
                        vectorize:
                        """
                        #result.loc[n+1, ekf.y] = y_data[ekf.y].iloc[n+1].values
                        result.loc[n+1, ekf.dae.x] = x0
                        #result.loc[n, residual_cols] = result.loc[n, ekf.y].values - h0
                    except IndexError:
                        assert n == N-1
                        # then, estimate eq. to pred:
                        x0 = np.array(x_pred).flatten()
                        #result.loc[n, "y_meas"] = np.nan
                        #result.loc[n, "res"] = np.nan
                        """
                        vectorize:
                        """
                        result.loc[n, "y_meas"] = np.nan
                        #result.loc[n, ekf.dae.x] = x0
                        #result.loc[n, residual_cols] = np.nan
                        
                # last iteration, only prediction:
                result.loc[n, ekf.y] = h0
                #result.loc[n, "x_filt"] = float(x0[0])
                # set filtered values:
                result.loc[n, x_names] = x0
                
            else:
                xs = np.array([x0]) 
                
                for n in range(N-1):
                    res = ekf.one_sample_feedback(
                        x0=x0,
                        z0=z_guess,
                        u=y_data[ekf.dae.u_names].iloc[n].values,
                        r=y_data[ekf.dae.r_names].iloc[n].values,
                        p=p_base,
                        y=y_data[ekf.dae.y_names].iloc[n+1].values,
                        Q=ca.diag(ekf.Q),
                        R=ca.diag(ekf.R),
                        P_prev=P_prev,
                        dt=ekf.dt          
                    )
                    x0 = res["x_hat"]
                    z = res["z"]
                    x_pred = res["x_pred"]
                    P_prev = res["P_hat"]
                    h = res["h_x"]
                    
                    z_guess = z
                    
                    xs = np.append(xs, np.array(x_pred))  
                    zs = np.append(zs, np.array(z))  
                    
                    result.loc[n+1, "y_pred"] = float(np.array(h).flatten())
                    result.loc[n+1, "y_meas"] = float(y_data[ekf.dae.y_names].iloc[n+1].values)
                    result.loc[n+1, ekf.dae.x] = np.array(x0).T
                    
                xs = xs.flatten()
                
                
            
        else:
            """
            Accumulate x_hat and P_prev:
            """
            map_estimate = ekf.one_sample_feedback.mapaccum(
                                                            "simulator",
                                                            N-1,
                                                            ["x0", "z0", "P_prev"],
                                                            ["x_hat", "z", "P_hat"],
                                                            #[0,1,2],
                                                            #[0,1,2]
                                                            )
            res = map_estimate(
                x0=x0,
                z0=z_guess,
                P_prev=np.diag([1]*ekf.n_x),
                u=y_data[ekf.dae.u].values.T[:,:-1],
                r=y_data[ekf.dae.r_names].values.T,
                p=ca.repmat(p_base, 1, N-1),
                #y=y_data[ekf.dae.y_names].shift(-1).values.T[:,1:],
                y=y_data[ekf.dae.y_names].values.T[:,1:],
                Q=ca.repmat(ca.diag(ekf.Q), 1, N-1),
                R=ca.repmat(ca.diag(ekf.R), 1, N-1),
                dt=ca.repmat(ekf.dt, 1, N-1)
            )
            x_hat = res["x_hat"] #.reshape(((N-1), ekf.n_x))
            zs = np.array(res["z"]) #.reshape(((N-1), ekf.n_x))
            x_pred = res["x_pred"].reshape(((N-1)*ekf.n_x, 1))
            y_pred = res["h_x"]
            xs = np.append(xs, np.array(x_pred))  
            result.loc[1:, ekf.dae.x] = np.array(x_hat).T
            result.loc[1:, "y_pred"] = np.array(y_pred).flatten()
            result.loc[1:, "y_meas"] = y_data[ekf.dae.y_names].values[1:].flatten()
            #result.loc[1:, "res"] = result.loc[:, "y_meas"] - result.loc[:, "y_pred"]
            #xs = xs.reshape(ekf.n_x, N)
        
        # cannot filter last (no measurement)
        #xs = np.append(xs, np.array([np.nan, np.nan]))
                    
        one_step, y_data = self._post_process_sim(
                                      #xs[:-self.dae.n_x],
                                      xs,
                                      zs,
                                      y_data
                                      )
        self.one_step_res = one_step
        self.filtered = result
        return one_step, y_data, result
       
    def _post_process_sim(
                          self,
                          xs: np.array,
                          zs: np.array,
                          y_data: pd.DataFrame
                         ):
        """
        try:
            zsim = zs.reshape(
                            int(zs.shape[0]/self.dae.n_z),
                            self.dae.n_z
                            )
            sim_data = np.hstack([xsim, zsim])
        #except ZeroDivisionError:
        except:
        """
        xsim = xs.reshape(
                        #int(xs.shape[0]/self.dae.n_x),
                        len(y_data),
                        self.dae.n_x
                        )
        sim_data = xsim
        res = pd.DataFrame(
                        data=sim_data,
                        columns=self.dae.x #+ self.dae.z
                        )
        # set index to date-time
        try:
            res.index = y_data.dt_index
            y_data.index = y_data.dt_index
        except ValueError:
            dt_index = y_data.dt_index[:-1]
            res.index = dt_index
            #y_data.index = dt_index
            
        
        return res, y_data
    
    def simple_sim_plot(self,
                        y_data,
                        x0,
                        p,
                        HVAC=False,
                        plot=True,
                        map_eval=False,
                        chained_eval=True,
                        ax=None
                        ):
        """
        Create a simple plot.
        
        TODO: modularize
        """
        # update:
        self.params = p
        # new scaled integrator:
        """
        self.param_est = ParameterEstimation(
                                            config=self.config,
                                            N=2, # no map in any case
                                            dt=self.dt,
                                            slack=self.slack,
                                            param_guess=p
                                             )
        """
        res, y_data = self.simulate_full(
                                         x0,
                                         y_data,
                                         p,
                                         map_eval=map_eval,
                                         chained_eval=chained_eval
                                         )
        if plot:
            if not HVAC:
                """
                Plot envelope model.
                """
                if ax is None:
                    ax = res.Ti.plot(color="r", drawstyle="steps-post")
                else:
                    res.Ti.plot(color="r", drawstyle="steps-post", ax=ax)    
                    
                y_data.Ti.plot(color="k", linestyle="dashed", drawstyle="steps-post", linewidth=0.75, ax=ax)
                #y_data.Ta.plot(color="b", linestyle="dashed", linewidth=0.75, ax=ax, drawstyle="steps-post")
                ax1 = ax.twinx()
                #y_data.vent_on.plot(ax=ax1, color="y", linewidth=0.75, drawstyle="steps-post")
                (y_data.phi_h/y_data.phi_h.max()).plot(ax=ax1, color="g", linewidth=0.75, drawstyle="steps-post")
                ax.legend(["model", "measured"])
            else:
                y_map = self.param_est.dae.y
                fig, axes = plt.subplots(4,1, sharex=True)
                for i, (y, var) in enumerate(y_map.items()):
                    name = var.name()
                    ax = axes[i]
                    y_data[y].plot(color="k", linewidth=0.75, ax=ax)
                    res[name].plot(color="r", linestyle="dashed", linewidth=0.75, ax=ax)
                    ax.legend([y, name])
                
            #plt.show()
        
    def simple_one_step_plot(
                            self,
                            y_data,
                            x0,
                            p_base,
                            p_mod=None,
                            p_tvp=None,
                            ekf_config=None,
                            tvp=False,
                            cond_series=None,
                            switch=None,
                            plot=True,
                            map_eval=False,
                            symbolic_estimate=False,
                            R=None,
                            Q=None,
                            P0=None
                            ):
        """
        Create a plot of one-step predictions,
        along with filtered estimate.
        """
        res, y_data, filtered = self.simulate_one_step(
                                                    x0,
                                                    y_data,
                                                    ekf_config=ekf_config,
                                                    cond_series=cond_series,
                                                    tvp=tvp,
                                                    p_base=p_base,
                                                    p_mod=p_mod,
                                                    p_tvp=p_tvp,
                                                    switch=switch,
                                                    map_eval=map_eval,
                                                    symbolic_estimate=symbolic_estimate,
                                                    R=R,
                                                    Q=Q,
                                                    P0=P0
                                                    # pass switch as anonymous func
                                                    )
        # need to cut out estimate of first state:
        if plot:
            #res = res[1:]
            #y_data = y_data[1:]
            filtered.index = y_data.index
            # now, can plot:
            ax = res.Ti.plot(color="r")
            y_data.Ti.plot(color="k", linestyle="dashed", linewidth=0.75, ax=ax)
            filtered.Ti.plot(color="g", linestyle="dashed", linewidth=0.75, ax=ax)
            y_data.Ta.plot(color="b", linestyle="dashed", linewidth=0.75, ax=ax)
            ax1 = ax.twinx()
            #y_data.weeknd.plot(ax=ax1, color="y", linewidth=0.75)
            y_data.vent_on.plot(ax=ax1, color="y", linewidth=0.75)
            (y_data.phi_h/y_data.phi_h.max()).plot(ax=ax1, color="g", linewidth=0.75)
            ax.legend(["model", "measured", "filtered"])
            #plt.show()
        
    def make_journal_plot(
                          self,
                          y_data,
                          x0,
                          name,
                         ):
        
        # set various font sizes:
        #SMALL_SIZE = 12
        #MEDIUM_SIZE = 14
        #BIGGER_SIZE = 16
        SMALL_SIZE = 14
        MEDIUM_SIZE = 16
        BIGGER_SIZE = 18

        plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
        plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
        plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
        plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('legend', fontsize=BIGGER_SIZE)    # legend fontsize
        #plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
        plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title
    
        
        res, y_data = self.simulate_full(x0, y_data)
        y_data[res.columns] = res
        save_journal_plot(y_data, "plots/" + name + ".pdf")
          
    def plot_residual_dist(
                           self,
                           y_data,
                           name
                           ):
        """
        NB: Need to simulate first.
        """
        one_step = self.filtered
        sim_df = self.res
        sim_df["v1"] = sim_df["Ti"] - y_data["y1"]
        plot_residuals(one_step, sim_df, name)
        
        return one_step

    @property
    def x(self):
        return self.dae.x
        

def save_journal_plot(data, name):
    """
    Make a nicely formatted plot of
    simulation result, boundary conditions.
    
    TODO: handling unit C or K
    
    """
    fig, axes = plt.subplots(3,1, sharex=True, figsize=(14,10 ))
    # plot training fit:
    ax = axes[0]
    #(data["Ti"]- 273.15).plot(color="r", linestyle="dashed", ax=ax, linewidth=0.75)
    #(data["y1"] - 273.15).plot(color="k", ax=ax, linewidth=0.75)
    (data["Ti"]).plot(color="r", linestyle="dashed", ax=ax, linewidth=0.75)
    (data["y1"]).plot(color="k", ax=ax, linewidth=0.75)
    ax.set_ylabel("Temperature $[^\circ C]$")
    ax.legend(["$T_i$", "$T_{i}^{meas}$"], loc="upper left", ncol=2)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.3])
    ax1 = ax.twinx()
    ax = ax1
    #data["weeknd"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
    data["vent_on"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
    ax.legend(["$\sigma_{vent}$"], loc="upper right", ncol=1)
    ax.set_yticks([0,1])
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.35])
    
    ax = axes[1]
    
    # power, other room temps / ventilation 
    (data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
    #(data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
    ax.legend(["$\phi_h$"], loc="upper left", ncol=1)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.2])
    ax.set_ylabel("Power $[kW]$")
    ax1 = ax.twinx()
    ax = ax1
    #(data["T_sup_air"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    #(data["T_321"] - 273.15).plot(color="b", ax=ax, linewidth=0.75)
    #(data["T_320"] - 273.15).plot(color="y", ax=ax, linewidth=0.75)
    (data["T_sup_air"]).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    (data["T_321"]).plot(color="b", ax=ax, linewidth=0.75)
    (data["T_320"]).plot(color="y", ax=ax, linewidth=0.75)
    ax.legend(["$T_{sup}^{v}$", "$T_{321}$", "$T_{320}$"], loc="upper right", ncol=3)
    ax.set_xlabel("")
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.2])
    
    ax = axes[2]
    
    # dataar, outdoor temp
    #(data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
    (data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
    ax.legend(["$\phi_s$"], loc="upper left", ncol=1)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.1])
    ax.set_ylabel("Power [$\\frac{kW}{m^2}$]")
    ax.set_yticks([0,0.5])
    ax.set_xlabel("")
    ax1 = ax.twinx()
    ax = ax1
    #(data["Ta"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    (data["Ta"]).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    #data["T_321"].plot(color="b", ax=ax, linewidth=0.75)
    #sol["T_320"].plot(color="y", ax=ax, linewidth=0.75)
    ax.legend(["$T_{a}$"], loc="upper right", ncol=1)
    ax.set_xlabel("")
    ylim = ax.get_ylim()
    #ax.set_ylim([ylim[0], ylim[1]*1.25])
    fig.tight_layout()
    #plt.show()
    plt.savefig(name)
    plt.savefig(name.replace(".pdf", ".png"))
    
def plot_residuals(one_step_df, sim_df, name):
    """
    Nice plot of residuals.
    """
    def drawSingle(myax, mydf, title, variable=None):
        num_bins = 30
        xs = mydf["gap"]
        x = np.linspace(-1, 1, 1000)

        mu = np.mean(x)
        sigma = np.std(xs)
        n, bins, patches = myax.hist(xs, num_bins, alpha=0.65, ec='black', facecolor='blue', density=False)

        myax.set_ylabel('frequency', color="black", fontsize=12, weight="bold")
        myax.set_xlabel("Temperature residual $[^\circ C]$", fontsize=12, weight="bold", horizontalalignment='center')
        myax.set_title(title)

        """
        Calculate the normal dist.:
        """
        X = mydf.gap
        W = np.array([1]*len(X))
        mu = sum (X * W) / sum(W)
        sigma = np.sqrt (sum (W * (X- mu)**2) / sum(W))
        
        #sigma = 0.075
        normalization_factor = len(xs) * (bins[1] - bins[0])
        y_normcurve = norm.pdf(x, mu, sigma) * normalization_factor
        #y_normcurve = norm.pdf(x, mu, sigma) # * normalization_factor
        myax.plot(x, y_normcurve, 'r--', linewidth=0.8)
        myax.vlines(mu, 0, y_normcurve.max(), 'y', '--', color='lime', label='example', linewidth=0.75)
        # set legend:
        myax.legend([
                    "$\sigma$ = {:.3f}".format(sigma),
                    "$\mu$ = {:.3f}".format(mu),
                    variable
                    #"$\mu = %s$" % (str(mu), )
                    ])
        #return normalization_factor
        return 1

    def drawSubplots(mydf1, mydf2, title):
        plt.rcParams['figure.figsize'] = (12, 5)

        fig, ax = plt.subplots(nrows=1, ncols=2, sharex=True, sharey=True)

        dfs = [mydf1, mydf2]
        norm_factors = [drawSingle(ax_i, df, title, var)
                        for ax_i, df, title, var in zip(ax.ravel(),
                                                dfs,
                                                ["One-step ahead", "Simulation"], 
                                                ['$\hat{T}_{t|t-1}^{i} - Y_t$', '$\hat{T}_{t|0}^{i} - Y_t$'])]
        for ax_i, norm_factor in zip(ax.ravel(), norm_factors):
            ax_twin = ax_i.twinx()
            ymax = ax_i.get_ylim()[1]
            ax_twin.set_ylim(0, ymax / norm_factor)
        #plt.suptitle(title, fontsize=18)
        fig.tight_layout()
        plt.savefig("plots/" + title.replace(", ", "_") + ".pdf")
        plt.savefig("plots/" + title.replace(", ", "_") + ".png")
        #plt.show()

    #df1, df2 = [pd.DataFrame({"gap": np.random.normal(0, 0.2, n)}) for n in [6000, 4000]]
    #df1 = one_step_df[["res"]].copy()
    df1 = one_step_df[["Ti_res"]].copy()
    df1.columns = ["gap"]
    df2 = sim_df[["v1"]][1:].copy()
    df2.index = df1.index
    df2.columns = ["gap"]

    # filter out abs(res) > 0.4
    #df1[abs(df1) > 0.4] = 0
    #df2[abs(df2) > 0.4] = 0
    
    drawSubplots(df1, df2, name)




