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
from ocp.filters import KalmanBucy
from utils import save_journal_plot, plot_residuals
from matplotlib import rc
from ocp.filters import KalmanBucy
from sklearn.metrics import r2_score
# text:
rc('text', usetex=True)

class ResultGenerator(object):
    """
    Result generator.
    """
    def __init__(self,
                 config=None,
                 params=None,
                 dt=None):
        # for simplicity, to get the integrator:
        param_est = ParameterEstimation(
                                        config=config,
                                        N=2, # no map in any case
                                        dt=dt,
                                        param_guess=params.values.flatten()
                                        )
        self.dae = param_est.dae
        self.I = param_est.integrator.one_sample
        self.G = param_est.integrator.G
        self.params = params
       
       
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
        metrics.loc["mse", name] = self.mse(y, y_pred)
        metrics.loc["rmse", name] = self.rmse(y, y_pred)
        metrics.loc["nrmse", name] = self.nrmse(y, y_pred)
        metrics.loc["r2", name] = r2_score(y, y_pred)
        metrics.loc["aic", name] = self.aic(y, y_pred, self.num_params)
        metrics.loc["bic", name] = self.bic(y, y_pred, self.num_params)
        
        return metrics
        
    @property
    def num_params(self):
        return len(self.params)
        
        
    def simulate_full(self, x0, y_data):
        """
        Simulate w/o feedback.
        
        Returns dataframe of state trajectory.
        """
        
        # empty arrays for keeping state:
        xs = np.array([])
        zs = np.array([])
        # p to array:
        p = self.params.values.flatten()
        I = self.I
        G = self.G
        """
        Try initial z_guess as ones:
        """
        
        #z_guess = [1]*self.dae.n_z
        
        # get time-varying params:
        tvp = list(map(lambda x: x.split("_")[0], [p for p in self.params.index if p.endswith("_a")]))
        z_guess = self.params.loc[tvp].values
        v = [0]*self.dae.n_v
        N = len(y_data)
        
        for n in range(N):
            xs = np.append(xs, np.array(x0))
            u = y_data[self.dae.u_names].iloc[n].values
            r = y_data[self.dae.r_names].iloc[n].values
            
            #z = sol[I.dae.z].iloc[n].values
            # separate root-finding problem for values of z:
            z = G(z_guess, x0, u, p, v, 0, 0, 0)
            zs = np.append(zs, np.array(z))
            x0 = I(x0,z,u,p,0,r,0)
            z_guess = z
        
        res, y_data = self._post_process_sim(
                                      xs,
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
                          switch=None
                          ):
        """
        Simulate one-step ahead with Kalman feedback.
        """
        ekf = KalmanBucy(ekf_config)
        ekf.set_R(np.diag([1]))
        # set R, Q? P0?
        N = len(y_data)
        x_names = ekf.dae.x
        result = pd.DataFrame(
                              index=range(N-1),
                              columns=["res", "y_pred","y_meas"] + x_names
                              )
    
        xs = np.array([x0])
        I = ekf.integrator.one_sample    
        #p = p_base
        
        # get correct order for ekf:
        if isinstance(p_base, (pd.Series, pd.DataFrame)):
            p_base = p_base.loc[ekf.dae.p].values.flatten()

        if switch is None:
            def bypass(cond, p_base, p_mod):
                return p_base
            switch = bypass
            
        if cond_series is None:
            cond_series = pd.Series([0]*N)
        
        
        
        
        for n in range(N-1):   
            u = y_data[ekf.dae.u_names].iloc[n].values
            r = y_data[ekf.dae.r_names].iloc[n].values
                
            #p = switch(y_data.index[0], p_base, p_mod)
            p = switch(cond_series.iloc[n], p_base, p_mod)
            # noiseless model prediction:
            x_pred = I(x0,0,u,p,0,r,0)
            xs = np.append(xs, np.array(x_pred))    
            
            # filtering of prediction:s
            try:
                x0 = ekf.estimate(
                                x_pred,
                                p=p,
                                y=y_data[ekf.dae.y_names].iloc[n+1].values,
                                u=y_data[ekf.dae.u].iloc[n].values,
                                r=y_data[ekf.dae.r_names].iloc[n].values
                                )
                result.loc[n, "y_meas"] = float(y_data[ekf.dae.y_names].iloc[n+1].values)
                result.loc[n, "res"] = np.array(x_pred[0,0])[0][0] - y_data[ekf.dae.y_names].iloc[n+1].values
            except IndexError:
                assert n == N -1
                # then, estimate eq. to pred:
                x0 = x_pred
                result.loc[n, "y_meas"] = np.nan
                result.loc[n, "res"] = np.nan
                
            result.loc[n, "y_pred"] = float(x_pred[0])
            #result.loc[n, "x_filt"] = float(x0[0])
            # set filtered values:
            result.loc[n, x_names] = x0
        
        one_step, y_data = self._post_process_sim(
                                      xs,
                                      y_data
                                      )
        self.one_step_res = one_step
        self.filtered = result
        return one_step, y_data, result
        
        """
        ax = result["y_meas"].plot(color="k", linewidth=0.5)
        result["y_pred"].plot(color="r", linestyle="dashed", linewidth=0.5, ax=ax)
        plt.show()
        """    
       
    def _post_process_sim(
                          self,
                          xs: np.array,
                          y_data: pd.DataFrame
                         ):
        res = pd.DataFrame(
                        data=xs.reshape(
                                        int(xs.shape[0]/self.dae.n_x),
                                        self.dae.n_x
                                        ),
                        columns=self.dae.x
                        )
        # set index to date-time
        res.index = y_data.dt_index
        #res.index = y_data.dt_index[1:]
        y_data.index = y_data.dt_index
        
        return res, y_data
    
    def simple_sim_plot(self, y_data, x0):
        """
        Create a simple plot.
        """
        res, y_data = self.simulate_full(x0, y_data)
        ax = res.Ti.plot(color="r")
        y_data.Ti.plot(color="k", linestyle="dashed", linewidth=0.75, ax=ax)
        y_data.Ta.plot(color="b", linestyle="dashed", linewidth=0.75, ax=ax)
        ax1 = ax.twinx()
        y_data.vent_on.plot(ax=ax1, color="y", linewidth=0.75)
        (y_data.phi_h/y_data.phi_h.max()).plot(ax=ax1, color="g", linewidth=0.75)
        ax.legend(["model", "measured"])
        plt.show()
        
    def simple_one_step_plot(
                            self,
                            y_data,
                            x0,
                            p_base,
                            p_mod=None,
                            ekf_config=None,
                            cond_series=None,
                            switch=None
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
                                                    tvp=True,
                                                    p_base=p_base,
                                                    p_mod=p_mod,
                                                    switch=switch
                                                    # pass switch as anonymous func
                                                    )
        # need to cut out estimate of first state:
        res = res[1:]
        y_data = y_data[1:]
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
        plt.show()
        
    def make_journal_plot(
                          self,
                          y_data,
                          x0,
                          name,
                         ):
        
        # set various font sizes:
        SMALL_SIZE = 12
        MEDIUM_SIZE = 14
        BIGGER_SIZE = 16

        plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
        plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
        plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
        plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        #plt.rc('legend', fontsize=MEDIUM_SIZE)    # legend fontsize
        plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
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

    @property
    def x(self):
        return self.dae.x
        







