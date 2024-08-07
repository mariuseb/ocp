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
try:
    from utils import ZEBData
except:
    pass
from ocp.param_est import ParameterEstimation
import matplotlib.pyplot as plt
from ocp.filters import KalmanDAE
#from utils import save_journal_plot, plot_residuals
from matplotlib import rc
from sklearn.metrics import r2_score
# text:
rc('text', usetex=True)
from scipy.stats import norm

class ResultGenerator(object):
    """
    Result generator.
    """
    def __init__(self,
                 config=None,
                 params=None,
                 dt=None,
                 z_guess=None):
        # for simplicity, to get the integrator:
        self.param_est = \
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
        self.z_guess = z_guess
       
       
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
        """
        TODO: fix 
        """
        tvp = list(map(lambda x: x.split("_")[0], [p for p in self.params.index if p.endswith("_a")]))
        if self.z_guess is None:
            z_guess = self.params.loc[tvp].values
        else:
            z_guess = self.z_guess
            
        v = [0]*self.dae.n_v
        N = len(y_data)
        
        for n in range(N):
            xs = np.append(xs, np.array(x0))
            u = y_data[self.dae.u_names].iloc[n].values
            r = y_data[self.dae.r_names].iloc[n].values
            
            #z = sol[I.dae.z].iloc[n].values
            # separate root-finding problem for values of z:
            z = G(z_guess, x0, u, p, r)
            zs = np.append(zs, np.array(z))
            x0 = I(x0,z,u,p,r)
            z_guess = z
        # last x:
        """
        xs = np.append(xs, np.array(x0))
        # last z?
        u = y_data[self.dae.u_names].iloc[n].values
        r = y_data[self.dae.r_names].iloc[n].values
        z = G(z_guess, x0, u, p, v, 0, 0, 0)
        zs = np.append(zs, np.array(z))
        """
        
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
                          switch=None
                          ):
        """
        Simulate one-step ahead with Kalman feedback.
        """
        ekf = KalmanDAE(ekf_config)
        #ekf.set_R(np.diag([1]))
        # set R, Q? P0?
        N = len(y_data)
        x_names = ekf.dae.x
        result = pd.DataFrame(
                              index=range(N-1),
                              columns=["res", "y_pred","y_meas"] + x_names
                              )
    
        xs = np.array([x0])
        zs = np.array([])
        #I = ekf.integrator.one_sample    
        I = self.I
        G = self.G
        v = [0]*self.dae.n_v
        z_guess = self.z_guess
        if z_guess is None:
            z_guess = np.array([])
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

        if not tvp:
            p_tvp = p_base
            
        
        for n in range(N-1):   
            u = y_data[ekf.dae.u_names].iloc[n].values
            r = y_data[ekf.dae.r_names].iloc[n].values
                
            #p = switch(y_data.index[0], p_base, p_mod)
            p = switch(cond_series.iloc[n], p_base, p_mod)
            
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
                #result.loc[n, "y_meas"] = float(y_data[ekf.dae.y_names].iloc[n+1].values)
                #result.loc[n, "res"] = np.array(x_pred[0,0])[0][0] - y_data[ekf.dae.y_names].iloc[n+1].values
                """
                vectorize:
                """
                result.loc[n, ekf.y] = y_data[ekf.y].iloc[n+1].values
                result.loc[n, residual_cols] = result.loc[n, ekf.y].values - h0
            except IndexError:
                assert n == N-1
                # then, estimate eq. to pred:
                x0 = x_pred
                #result.loc[n, "y_meas"] = np.nan
                #result.loc[n, "res"] = np.nan
                """
                vectorize:
                """
                result.loc[n, "y_meas"] = np.nan
                result.loc[n, residual_cols] = np.nan
                
            # last iteration, only prediction:
            result.loc[n, ekf.y] = h0
            #result.loc[n, "x_filt"] = float(x0[0])
            # set filtered values:
            result.loc[n, x_names] = x0
        
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
        xsim = xs.reshape(
                        int(xs.shape[0]/self.dae.n_x),
                        self.dae.n_x
                        )
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
            y_data.index = dt_index
            
        
        return res, y_data
    
    def simple_sim_plot(self, y_data, x0, HVAC=False):
        """
        Create a simple plot.
        
        TODO: modularize
        """
        res, y_data = self.simulate_full(x0, y_data)
        if not HVAC:
            """
            Plot envelope model.
            """
            ax = res.Ti.plot(color="r")
            y_data.Ti.plot(color="k", linestyle="dashed", linewidth=0.75, ax=ax)
            y_data.Ta.plot(color="b", linestyle="dashed", linewidth=0.75, ax=ax)
            ax1 = ax.twinx()
            y_data.vent_on.plot(ax=ax1, color="y", linewidth=0.75)
            (y_data.phi_h/y_data.phi_h.max()).plot(ax=ax1, color="g", linewidth=0.75)
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
            
        plt.show()
        
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
                                                    tvp=tvp,
                                                    p_base=p_base,
                                                    p_mod=p_mod,
                                                    p_tvp=p_tvp,
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
    ax.legend(["$T_i$", "$T_{i}^{meas}$"], loc="upper left", ncols=2)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.3])
    ax1 = ax.twinx()
    ax = ax1
    #data["weeknd"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
    data["vent_on"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
    ax.legend(["$\sigma_{vent}$"], loc="upper right", ncols=1)
    ax.set_yticks([0,1])
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.35])
    
    ax = axes[1]
    
    # power, other room temps / ventilation 
    (data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
    #(data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
    ax.legend(["$\phi_h$"], loc="upper left", ncols=1)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.2])
    ax.set_ylabel("Power $[kW]$")
    ax1 = ax.twinx()
    ax = ax1
    #(data["T_sup_air"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    #(data["T_321"] - 273.15).plot(color="b", ax=ax, linewidth=0.75)
    #(data["T_320"] - 273.15).plot(color="y", ax=ax, linewidth=0.75)
    (data["T_sup_air"]).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    #(data["T_321"]).plot(color="b", ax=ax, linewidth=0.75)
    #(data["T_320"]).plot(color="y", ax=ax, linewidth=0.75)
    ax.legend(["$T_{sup}^{v}$"], loc="upper right", ncols=3)
    #ax.legend(["$T_{sup}^{v}$", "$T_{321}$", "$T_{320}$"], loc="upper right", ncols=3)
    ax.set_xlabel("")
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.2])
    
    ax = axes[2]
    
    # dataar, outdoor temp
    #(data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
    (data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
    ax.legend(["$\phi_s$"], loc="upper left", ncols=1)
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
    ax.legend(["$T_{a}$"], loc="upper right", ncols=1)
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




