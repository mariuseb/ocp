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
from ocp.utils import ZEBData
from ocp.param_est import ParameterEstimation
import matplotlib.pyplot as plt
from ocp.filters_old import KalmanDAE
#from utils import save_journal_plot, plot_residuals
from matplotlib import rc
from sklearn.metrics import r2_score
from copy import deepcopy
# text:
rc('text', usetex=True)
# try to standardize datetime-formatting:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d"
import matplotlib.dates as mdates
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M:%S"
from scipy.stats import norm
import casadi as ca
from copy import deepcopy
from matplotlib.colors import ListedColormap
import seaborn as sns
import os
from ocp.covar_solver_cont_old import CovarianceSolverContinuous
pd.set_option('future.no_silent_downcasting', True)
# construct cmap
#colors = ["#9b59b6", "#3498db", "#95a5a6", "#e74c3c", "#34495e", "#2ecc71"]
#my_cmap = ListedColormap(sns.color_palette(flatui).as_hex())
#my_cmap = sns.color_palette("Spectral", as_cmap=True)
#my_cmap = sns.color_palette("bright", as_cmap=True)
colors = sns.color_palette("Set1") #, as_cmap=True)

def discrete_cmap(N, base_cmap=None):
    """Create an N-bin discrete colormap from the specified input map"""

    # Note that if base_cmap is a string or None, you can simply do
    #    return plt.cm.get_cmap(base_cmap, N)
    # The following works for string, None, or a colormap instance:

    base = plt.cm.get_cmap(base_cmap)
    color_list = base(np.linspace(0, 1, N))
    cmap_name = base.name + str(N)
    return base.from_list(cmap_name, color_list, N)

#colors = sns.color_palette("bright")
#colors = sns.color_palette("bright", as_cmap=True)
#colors = sns.color_palette("husl", 9)
my_cmap = ListedColormap(sns.color_palette(colors).as_hex())
color_cycler = plt.cycler(color=colors)

color_map_custom = {
    "space_heat": colors[0],
    "vent_in": colors[4],
    "vent_out": colors[-2],
    "solar": colors[5],
    "one_step": colors[1],
    "sim": colors[2],
    "meas": "k",
    "int_gains": colors[-3],
    #"temp_amb": colors[-1],
    "temp_amb": "g",
    "binary": colors[3],
    "T_219_TR1": "dimgray", 
    "T_219_TR2": "gray", 
    "T_219_TR3": "darkgray", 
    "T_219_TR4": "silver", 
}

#my_cmap = discrete_cmap(10, my_cmap)

#N = 500
#data1 = np.random.randn(N)
#data2 = np.random.randn(N)
#colors = np.linspace(0,1,N)

class ResultGenerator(object):
    """
    Result generator.
    """
    def __init__(self,
                 config=None,
                 ekf_config=None,
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
        self.ekf_config = ekf_config
        self.dt = dt
        self.slack = slack
        self.dae = param_est.dae
        self.I = param_est.integrator.one_sample
        self.G = param_est.integrator.G
        self.params = params
        self.z_guess = z_guess
        
                
    def var_day_validation_runner(
        self,
        ekf_config,
        start,
        N_days,
        days,
        param_guess,
        param_est,
        data,
        plot=True,
        prior_weight=1,
        sampling_rate="60min",
        journal_plot=False,
        R=None,
        Q=None,
        P0=None,
        P0x=None,
        x0_opt=None,
        covar_solve=True,
        control_validation=False,
        num_segments=1,
        reidentification=False
    ):
        self.extra_inds = extra_inds = []
        p0 = param_est.p0
        cols = ["mse",
                "rmse",
                "nrmse",
                "cv-rmse",
                "one_step_mse",
                "one_step_rmse",
                "one_step_nrmse",
                "mbe",
                "r2",
                "r2_adj",
                "aic",
                "bic"]
        self.N_days = N_days
        self.num_segments = num_segments
        metrics = pd.DataFrame(
                            columns=cols
                            )
        training_metrics = pd.DataFrame(
                            columns=cols
                            )
        params_hist = pd.DataFrame(
                                   columns=list(param_guess.keys()) + ["phi_s_avg"]
                                   )
        # prepare result data frame:
        y_data, dt, N = data.get_dataset(
                                start=start, 
                                stop=start + pd.Timedelta(days=days), 
                                sampling_rate=sampling_rate
                                )
        val_start = start + pd.Timedelta(days=days)
        val_stop = val_start + pd.Timedelta(days=N_days)
        result = pd.DataFrame(index=
                              pd.date_range(
                                            start=val_start,
                                            end=val_stop,
                                            freq=sampling_rate
                                            ),
                              columns=list(y_data.columns) + ["Ti_sim", "Ti_onestep"] + self.dae.x
                              )
        #fig, axes = plt.subplots(2,N_days*2, sharex=False)
        # iterate:
        
        self.sols = dict()
        self.covar_sols = dict()
        self.train_res = dict()
        
        def set_new_results(y_data, result, new_results):
            #y_data_to_set = y_data[1:]
            #result.loc[y_data_to_set.index, y_data_to_set.columns] = y_data_to_set
            result.loc[y_data.index, y_data.columns] = y_data
            """
            New non-overlapping index:
            """
            #new_index = y_data.index[1:]
            new_first = y_data.index[0] + pd.Timedelta(seconds=1e-3)
            new_index = pd.DatetimeIndex.union(pd.DatetimeIndex([new_first]), y_data.index)
            res_to_set = new_results
            res_to_set = res_to_set.reindex(new_index)
            res_to_set = res_to_set.ffill()
            """
            Extend data cols with last element,
            new index should not be visible
            """
            result.loc[new_index[1], y_data.columns] = result.loc[y_data.index[0], y_data.columns]
            result.loc[new_index, ["Ti_sim"]] = res_to_set["Ti"]
            result = result.sort_index()
            return result, new_first
         
        """
        Set up covariance identification:
        """
        ##########################################################
        covar_kwargs = {
            #"x_nom": 12,
            #"x_nom_b": 289.15,
            #"z_nom": [1e-2,1e-2,1E6,1E6,1],
            #"z_nom_b": [0]*5,
            #"p_nom": OCP.get_scale(_params),
            "p_nom": self.param_est.p_nom,
            #"p_nom": [1e-2]*4 + [1e6]*4 + [1,1,1,1e-3,1,1],
            #"u_nom": [12]*7 + [1E3,1E3,1E3,1E3,10,10,1,1,1],
            #"u_nom_b ": [289.15]*7 + [0]*9,
            #"y_nom": [12],
            #"y_nom_b": [289.15],
            #"P_nom": [[1e-6,1e-6],[1e-6,1e-2]]  
            "P_nom": [[1e-3,1e-3],[1e-3,1e-3]]  
        }
        self.covar_solver = \
            covar_solver = \
                CovarianceSolverContinuous(
                                            self.ekf_config,
                                            self.config,
                                            y_data,
                                            param_guess,
                                            method="single_shooting",
                                            **covar_kwargs
                                          )
        P0 = np.ones(
                     (covar_solver.ekf.dae.n_x,
                      covar_solver.ekf.dae.n_x)
                     )*1e-3 # + 1e-2
        P0_guess = P0.flatten()
        Q_guess = np.array(
            ca.veccat(
                    ca.DM.eye(covar_solver.ekf.dae.n_x),
                    ca.DM.eye(covar_solver.ekf.dae.n_x)
                    )
            ).flatten()*-5
        #Q_guess[0] = -15
        #Q_guess[4] = -10
        R_guess = np.array(ca.DM.eye(covar_solver.ekf.dae.n_y)).flatten()*-5
        H = np.eye(covar_solver.n_theta + covar_solver.n_y)*1
        ##########################################################
            
        for delta_day in range(N_days):
            
            stop = start + pd.Timedelta(days=days)
            y_data, dt, N = data.get_dataset(
                                            start=start, 
                                            stop=stop, 
                                            sampling_rate=sampling_rate
                                            )
            y_data_train = y_data
            
            if not y_data.y1.isna().any():
                """
                Skip if any holes in temperature
                y_data = y_data.bfill()
                y_data = y_data.groupby(pd.Grouper(freq=sampling_rate)).mean().dropna()
                y_data["vent"] = (y_data["V_sup_air"] > 10).astype(int) 
                
                N = len(y_data)
                dt = (y_data.index[1] - y_data.index[0]).seconds
                # set range index for identification:
                y_data.index = range(0,N*dt,dt)
                """    
            
                if param_est.n_x == 2:
                    
                    x_guess = np.array([
                                    y_data.y1.values.flatten(),
                                    y_data.y1.values.flatten() - 2
                                    ])
                    
                elif param_est.n_x == 3:
                    
                    x_guess = np.array([
                                    y_data.y1.values.flatten(),
                                    y_data.y1.values.flatten() - 2,
                                    y_data.y1.values.flatten() + 2
                                    ])
                    
                else: 
                    
                    raise ValueError("error")
                    
                    
                lbx = 0.7*x_guess
                ubx = 2*x_guess

                param_guess["alpha_vent_sup"]["ub"] = 1.1
                param_guess["alpha_vent_ext"]["ub"] = 1.1
                
                if Q is None:
                    _Q = ca.DM.eye(param_est.n_x)
                if R is None:
                    _R = ca.DM.eye(param_est.n_y)
                if P0x is None:
                    P0x = ca.DM.eye(param_est.n_x)
                    
                #P0 = ca.DM.eye(param_est.n_p + param_est.n_x)*prior_weight*(1 + delta_day)
                P0 = ca.DM.eye(param_est.n_p + param_est.n_x)*prior_weight
                #P0[4,4] = 1E1
                # extra weight on int gains:
                #for n in range(param_est.n_p - 4, param_est.n_p):
                #    P0[n,n] = 1E3
                
                #if delta_day > 10: 
                #    P0 *= 1E-2
                
                #for n in (1,3,5,7):
                #    P0[n,n] = 0s
                for n in range(param_est.n_p, param_est.n_p + param_est.n_x):
                    P0[n,n] = 0
                #P0[9,9] = 1E3
                if not reidentification:
                    delta_day_lim = 1
                else:
                    delta_day_lim = 100
                
                if delta_day < delta_day_lim:
                    lbp = param_est.get_lbp(1e-2)
                    ubp = param_est.get_ubp(1e2)
                else:
                    lbp = p0
                    ubp = p0
                
                """
                ax = y_data["Ti"].plot(drawstyle="steps-post")
                ax1 = ax.twinx()
                y_data["phi_h"].plot(ax=ax1, color="r", drawstyle="steps-post")
                y_data["phi_int_plugs"].plot(ax=ax1, color="m", drawstyle="steps-post")
                y_data["phi_s"].plot(ax=ax1, color="y", drawstyle="steps-post")
                #y_data["DeltaPs"].plot(ax=ax1, color="y", drawstyle="steps-post")
                plt.show()
                """
  
                sol, params = param_est.solve(
                            y_data,
                            #param_est.p0,
                            p0,
                            lbp=lbp,
                            ubp=ubp,
                            lbx=lbx,
                            ubx=ubx,
                            x_guess=x_guess,
                            x_N = np.array([293.15]*param_est.n_x), # not used
                            P0=P0,
                            covar=ca.veccat(_Q, _R),
                            codegen=True
                            )
                self.sols[delta_day] = sol
        
                    
                x0 = sol[self.x].iloc[0]   
                self.simple_sim_plot(
                                    y_data,
                                    x0,
                                    params,
                                    plot=False,
                                    map_eval=True,
                                    chained_eval=True,
                                    #ax=axes[delta_day, 0]
                                    )  
                if journal_plot:
                    self.make_journal_plot(
                        y_data, 
                        x0,
                        str(start) + "_" + str(days),
                        res = self.res
                    )       
                # obtain one-step ahead estimate:
                if x0_opt is None:
                    x0_opt = x0
                    
                """
                Here, do covariance identification:
                """
                #########################################################
                
                if covar_solve:  # and delta_day == 0: # only first:         
                    """
                    Re-init covar solver each iter.
                    self.covar_solver = \
                    covar_solver = \
                        CovarianceSolverContinuous(
                                                    self.ekf_config,
                                                    self.config,
                                                    y_data,
                                                    param_guess,
                                                    method="single_shooting",
                                                    **covar_kwargs
                                                )
                    P0 = np.ones((covar_solver.ekf.dae.n_x,
                                  covar_solver.ekf.dae.n_x))*1e-5 # + 1e-2
                    P0[1,1] *= 1e3
                    P0_guess = P0.flatten()
                    Q_guess = np.array(
                        ca.veccat(
                                ca.DM.eye(covar_solver.ekf.dae.n_x),
                                ca.DM.eye(covar_solver.ekf.dae.n_x)
                                )
                        ).flatten()*-5
                    Q_guess[0] = -15
                    Q_guess[4] = -15
                    R_guess = np.array(ca.DM.eye(covar_solver.ekf.dae.n_y)).flatten()*-5
                    """
                    H = np.eye(covar_solver.n_theta + covar_solver.n_y)*1
                    
                    _params = params.loc[covar_solver.ekf.dae.p].values
                    sol = sol[:len(y_data)]
                    sol.index = y_data.index
                    y_data[covar_solver.ekf.dae.z] = sol[covar_solver.ekf.dae.z]
                    covar_sol, Q_df, R, raw_sol = covar_solver.solve(
                                    y_data, 
                                    _params,
                                    x0, # guess from smoothing
                                    P0_guess,
                                    Q_guess,
                                    R_guess, 
                                    H=H    
                                    )
                    self.covar_sols[delta_day] = raw_sol
                    M = int(86400/(int(sampling_rate.rstrip("min"))*60)) + 1
                    
                    def simulate_one_day_feedback(ekf, M, P_0):
                        F = ekf.one_sample_feedback_adj
                        F_map = F.mapaccum("simulator", M, [0,1], [3,7])
                        # simulate:
                        res = F_map(
                            x_0=x0,
                            #z0=Z,
                            P_0=P_0,
                            u=y_data[ekf.dae.u_names][0:M].values.T,
                            #u_shift=y_data[ekf.dae.u_names][1:M+1].values.T,
                            r=y_data[ekf.dae.r_names][0:M].values.T,
                            p=ca.repmat(_params,1,M),
                            y=y_data[ekf.dae.y_names][0:M].values.T,
                            Q=ca.repmat(Q_df.values.flatten(),1,M),
                            #Q=ca.repmat(Qval,1,M),
                            R=ca.repmat(R.flatten(),1,M)
                        ) 
                        P0 = res["P_10"][:,-ekf.n_x:]
                        return np.array(P0)
                    
                    def transform_Q_df(Q_df, covar_solver):
                        Q_cols_orig = list(Q_df.columns)
                        Q_cols = list(Q_df.columns)
                        for n in range(covar_solver.nQs - 1):
                            Q_cols_mod = list(map(
                                lambda x: x + "_" + str(n+1),
                                Q_cols_orig
                            ))
                            Q_cols += (Q_cols_mod)
                        _Q_vals = Q_df.values.flatten()
                        _Q_vals = _Q_vals.reshape((1,_Q_vals.shape[0]))
                        _Q_df = pd.DataFrame(
                                            index=np.array([delta_day]),
                                            columns=np.array(Q_cols),
                                            data=_Q_vals
                                            )
                        _Q_df["r"] = R
                        
                        return _Q_df
                        
                    
                    _Q_df = transform_Q_df(
                        Q_df,
                        covar_solver
                        )
                    P0x_first = covar_sol[
                        covar_solver.ekf.p_cols
                        ].values.reshape((
                            covar_solver.ekf.n_x,
                            covar_solver.ekf.n_x)
                        )
                
                    P0x_next = simulate_one_day_feedback(
                        covar_solver.ekf,
                        M, 
                        P0x_first
                        )
                    # DM to np.array:
                    #P0x = np.array(P0x)
                    # keep history:
                    if delta_day == 0:
                        # TODO: modularize:
                        theta_hist = covar_sol.copy()
                        theta_hist_orig_cols = covar_sol.columns
                        # swap P0 constraint:
                        covar_solver.exchange_P0_constraint(P0x_next.flatten())
                        #H = np.eye(covar_solver.n_theta + covar_solver.n_y)*1
                        #H = np.eye(covar_solver.n_theta + covar_solver.n_y)*0
                    else: 
                        theta_hist.loc[delta_day] = np.nan
                        theta_hist.loc[delta_day, list(theta_hist_orig_cols)] = covar_sol.values
                        # swap P0 value in constraint:
                        covar_solver.exchange_P0_value(P0x_next.flatten())
                    # for next iter:
                    Q_guess = Q_df.values.flatten()
                    R_guess = R.flatten()
                    P0_guess = P0x_next.flatten()
                    
                    theta_hist.loc[delta_day, _Q_df.columns] = _Q_df.values
                    #########################################################
                    
                    x0_filt = covar_sol[covar_solver.ekf.dae.x].iloc[0]
                    Q = Q_df.values.flatten()
                else:
                    theta_hist = pd.DataFrame()
                    x0_filt = sol[covar_solver.ekf.dae.x].iloc[0]
                    Q = Q_guess
                    R = R_guess
                    P0x = P0_guess.reshape((
                        self.covar_solver.ekf.n_x,
                        self.covar_solver.ekf.n_x
                                            ))
                                
                self.simple_one_step_plot(
                                            y_data,
                                            x0_filt,
                                            p_base=params,
                                            #p_mod=p_mod,
                                            p_tvp=params.values,
                                            tvp=False,
                                            ekf_config=ekf_config,
                                            cond_series=y_data.vent,
                                            plot=plot,
                                            map_eval=True,
                                            switch=None,
                                            symbolic_estimate=True,
                                            R=R,
                                            Q=Q,
                                            P0=P0,
                                            P0x=P0x
                                            )   
                sol["Ti_onestep"] = self.filtered["y_pred"].values
                sol["Ti_sim"] = sol["Ti"]
                
                residual_normalized = self.filtered["res"]/np.sqrt(self.one_step_res["V_k"])
                
                if delta_day == 0:
                    #sol["phi_int"] = sol["phi_int_plugs"] + sol["phi_int_lig"]
                    # keep residuals:
                    self.residuals = pd.DataFrame(
                                             index=range(len(sol)),
                                             data=residual_normalized.values,
                                             columns=["0"]
                                             )
                    #
                    
                    """
                    ax = y_data[["y1", "Tset"]].plot(drawstyle="steps-post")
                    ax1 = ax.twinx()
                    #y_data[["phi_h"]].plot(color="r", drawstyle="steps-post", ax=ax1)
                    y_data[["phi_s"]].plot(color="y", drawstyle="steps-post", ax=ax1)
                    #y_data[["T_sup_air"]].plot(color="k", drawstyle="steps-post", ax=ax)
                    #(y_data["vent"]*y_data["phi_h"].max()).plot(color="m", drawstyle="steps-post", ax=ax1)
                    plt.show(block=False)
                    """    
                else: 
                    # keep residuals:
                    self.residuals[str(delta_day)] = residual_normalized.values
                # keep training results:
                sol.index = y_data.dt_index
                self.train_res[delta_day] = sol.copy()
                self.train_res[delta_day][y_data.columns] = y_data
                self.train_res[delta_day]["Pvent"] = params["alpha_vent_sup"]* \
                                result["ahu_reaFloSupAir"]* \
                            (result["T_sup_air"] - result["Ti"]) + \
                        params["alpha_vent_ext"]* \
                    result["ahu_reaFloExtAir"]*(result["Ti"] - result["T_ext_air"])
                
                month = str(y_data.index[0].month)
                y_data.to_csv("to_CTSMR/ZEBLab_data_15min_%s_daytime_" % (month) + str(delta_day) +  ".csv")
                params.to_csv("to_CTSMR/parameters_LTV_%s_2023_daytime_15min" % (month) + str(delta_day) +  ".csv")
                sol.to_csv("to_CTSMR/solution_LTV_%s_2023_daytime_15min" % (month) + str(delta_day) + ".csv")
                
                train_metrics = self.report_metrics("training")
                
                """
                Split validation in two:p
                """
                
                delta_day_frac = 1/num_segments
                hrs = int(24/num_segments)
                training = y_data.copy()
                    
                for i in range(num_segments):
                    _start = stop + pd.Timedelta(days=i*delta_day_frac).round("s")
                    _stop = stop + pd.Timedelta(days=(i+1)*delta_day_frac).round("s")
                    y_data, dt, N = data.get_dataset(
                                                start = _start,
                                                stop = _stop,
                                                sampling_rate=sampling_rate
                                                )
                    
                    # take filtered now: (check model pred)
                    x0 = self.filtered[self.x].iloc[-1]
                    P0x = np.array(self.filtered.iloc[-1][
                        self.covar_solver.ekf.p_cols
                        ].astype(float).values).reshape(
                            (param_est.n_x, param_est.n_x)
                        )
                        
                    #x0 = sol[self.x].iloc[-1]
                    y_data.index.name = None
                    
                    """
                    if "Ai_high" in params.index and y_data.dt_index[0].month == 1:
                        if delta_day == 3:
                            params["Ai_high"] = params["Ai"]
                        # somewhere here, solar shading is implemented:
                        if delta_day > 4:
                            #params["Ai_high"] = 0
                            #if delta_day in (10,11,12,13):
                            params["Ai_high"] = 1E-1
                        #if delta_day == 13:
                        #    params["Ai_high"] = params["Ai"]
                    """
                    
                    if control_validation:
                        """
                        If control validation, then use last similar day for internal gains.
                        """ 
                        N = int(86400/self.dt)
                        """
                        if y_data.dt_index[0].dayofweek in (1,2,3,4,6): # weekday > tuesday
                            phi_int_pred = training["phi_int"].iloc[-(N+1):]
                        elif y_data.dt_index[0].dayofweek == 0: # monday, then take friday from training
                            phi_int_pred = training["phi_int"].iloc[-(3*N+1):-2*N]
                        elif y_data.dt_index[0].dayofweek == 5: # saturday, then take sunday from training
                            phi_int_pred = training["phi_int"].iloc[-(7*N+1):-6*N]
                        """
                        # last similar day:
                        phi_int_pred = training["phi_int"].iloc[-(7*N+1):-6*N]
                        y_data["phi_int"] = phi_int_pred.values
                            
                    
                    self.simple_sim_plot(
                                        y_data,
                                        x0,
                                        params,
                                        #plot=plot,
                                        plot=plot,
                                        suff="+%shrs" % (hrs*(i+1), ),
                                        map_eval=True,
                                        #symbolic_estimate=True
                                        #ax=axes[0, delta_day*2]
                                        )
                    #result.loc[y_data.index, y_data.columns] = y_data
                    #result.loc[y_data.index, "Ti_sim"] = self.res["Ti"]
                    if i == 0: # set y_pred == y_sim on result, first timestep
                        """ 
                        TODO: modularize:
                        """
                        result.loc[y_data.index[0], "Ti_onestep"] = x0["Ti"]
                        result.loc[y_data.index[0], "Ti_sim"] = x0["Ti"]
                        result.loc[y_data.index[0], self.dae.x] = x0
                        result.loc[y_data.index[0], y_data.columns] = \
                            y_data.loc[y_data.index[0]]
                        
                    
                    # this is only visual:    
                    #result, extra_ind = set_new_results(y_data[1:], result, self.res[1:])
                    #extra_inds.append(extra_ind)
                    
                    #if delta_day == 0:
                    #    result["Ti_sim"] = result["Ti_sim"].bfill()
                    
                    self.simple_one_step_plot(
                                            y_data,
                                            x0, 
                                            p_base=params,
                                            #p_mod=p_mod,
                                            p_tvp=params.values,
                                            tvp=False,
                                            ekf_config=ekf_config,
                                            cond_series=y_data.vent,
                                            plot=plot,
                                            map_eval=True,
                                            switch=None,
                                            symbolic_estimate=True,
                                            #ax=axes[1, delta_day*2]
                                            R=R,
                                            Q=Q,
                                            P0=P0,
                                            P0x=P0x,
                                            suff="+%shrs" % (hrs*(i+1), )
                                            )   
                    #print(x0)
                    
                    # save metrics:
                    test_metrics = self.report_metrics("validation (bic, aic not valid)")
                    metrics.loc[delta_day + i*delta_day_frac, :] = test_metrics.loc[metrics.columns].values.flatten()
                    training_metrics.loc[delta_day + i*delta_day_frac, :] = train_metrics.loc[metrics.columns].values.flatten()
                    
                    # one-step:
                    result.loc[y_data.index[1:], "Ti_onestep"] = \
                        self.filtered.loc[y_data.index[1:] ,"y_pred"]
                    # simulation:
                    result.loc[y_data.index[1:], "Ti_sim"] = \
                        self.res.loc[y_data.index[1:] ,"Ti"]
                    # filtering results:
                    result.loc[y_data.index[1:], self.dae.x] = \
                        self.filtered.loc[y_data.index[1:], self.dae.x]
                    # data:
                    result.loc[y_data.index[1:], y_data.columns] = \
                        y_data.loc[y_data.index[1:]]
                    # Pvent estimation:
                    result.loc[y_data.index, "Pvent"] = params["alpha_vent_sup"]*result["ahu_reaFloSupAir"]*(result["T_sup_air"] - result["Ti"]) + params["alpha_vent_ext"]*result["ahu_reaFloExtAir"]*(result["Ti"] - result["T_ext_air"])
                
                if reidentification:
                    factor = 1e2
                else:
                    factor = 1
                param_guess = {
                    k: {
                        "init": params.loc[k],
                        #"lb": 1e-2*params.loc[k],
                        #"ub": 1e2*params.loc[k]
                        "lb": (1/factor)*params.loc[k],
                        "ub": factor*params.loc[k]
                        }
                    for k in params.index
                }
                params_hist.loc[delta_day, list(param_guess.keys())] = params
                params_hist.loc[delta_day, "phi_s_avg"] = y_data_train["phi_s"].mean()
                # advance 1 day:
                start = start + pd.Timedelta(days=1)
        
                if float(test_metrics.loc["nrmse"].iloc[0]) > 1:
                    # check what happens
                    print(params)
                p0 = params.values
        self.val_res = result 
        return 0, \
               0, \
               training_metrics, \
               metrics, \
               params_hist, \
               theta_hist

 
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
    
    def mbe(self, y, y_pred):
        mbe_loss = np.mean(y - y_pred)
        return mbe_loss
    
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
            metrics.loc["one_step_rmse", name] = self.rmse(y, y_one_step)
            metrics.loc["one_step_nrmse", name] = self.nrmse(y, y_one_step)
        except: 
            pass
        metrics.loc["mse", name] = self.mse(y, y_pred)
        metrics.loc["rmse", name] = self.rmse(y, y_pred)
        metrics.loc["nrmse", name] = self.nrmse(y, y_pred)
        metrics.loc["cv-rmse", name] = metrics.loc["rmse", name]/y.mean()
        metrics.loc["r2", name] = r2_score(y, y_pred)
        metrics.loc["mbe", name] = self.mbe(y, y_pred)
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
        tvp = list(map(lambda x: x.split("_")[0], [p for p in self.dae.p if p.endswith("_w") or p.endswith("_low") or p.endswith("_high")]))
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
            _d = ca.MX.sym("d", self.dae.n_d)
            # = ca.MX.sym("r", self.dae.n_r)
            z_expr = G(_z0, _x0, _u, _p, _r)
            I_chained_expr = I(_x0, z_expr, _u, _p, _r, _d)
            I = ca.Function("I_chained",
                                    [_x0, _z0, _u, _p, _r, _d],
                                    [I_chained_expr, z_expr],
                                    ["x0","z0","u","p","r","d"],
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
            #_F_map = self.covar_solver.ekf.F.mapaccum("simulator", N-1, [0,1],[0,1])
            _res = F_map(
                x0=x0,
                z0=z_guess,
                u=y_data[self.dae.u].values.T[:,:-1],
                p=ca.repmat(p, 1, N-1),
                r=y_data[self.dae.r_names].values.T[:,:-1],
                d=0
            )
            """
            __res = _F_map(
                x0=x0,
                z0=z_guess,
                u=y_data[self.dae.u].values.T[:,:-1],
                p=ca.repmat(p, 1, N-1),
                r=y_data[self.dae.r_names].values.T[:,:-1],
                d=0
            )
            """
            
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
                          P0=None,
                          P0x=None
                          ):
        """
        Simulate one-step ahead with Kalman feedback.
        """
        #ekf = KalmanDAE(ekf_config)
        try:
            ekf = self.covar_solver.ekf
        except AttributeError:
            ekf = KalmanDAE(ekf_config)
        """
        if R is not None:
            ekf.set_R(R)
        if Q is not None:
            ekf.set_Q(Q)
        """
        if P0x is None:
            P_prev = np.diag([1]*ekf.n_x)
        else:
            P_prev = P0x
            
        #ekf.set_R(np.diag([1]))
        # set R, Q? P0?
        N = len(y_data)
        x_names = ekf.dae.x
        result = pd.DataFrame(
                              index=range(N),
                              columns=["res", "y_pred","y_meas"] + x_names + ekf.p_cols
                              )
    
        xs = np.array([x0])
        zs = np.array([])
        #I = ekf.integrator.one_sample    
        I = self.I
        G = self.G
        v = [0]*self.dae.n_v
        #z_guess = self.z_guess
        tvp = list(map(lambda x: x.split("_")[0], [p for p in self.dae.p if p.endswith("_w") or p.endswith("_low") or p.endswith("_high")]))
        if self.z_guess is None:
            z_guess = p_base.loc[tvp].values
        else:
            z_guess = self.z_guess
        
        #if not tvp:
        #    p_base = p_tvp
            
        # get correct order for ekf:
        if isinstance(p_base, (pd.Series, pd.DataFrame)):
            p_base = p_base.loc[ekf.dae.p].values.flatten()

        if switch is None:
            def bypass(cond):
                return p_base
            switch = bypass
            
        if cond_series is None:
            cond_series = pd.Series([0]*N)
            
        #result.loc[0, "y_meas"] = float(y_data[ekf.dae.y_names].iloc[0].values)
        #result.loc[0, "y_pred"] = float(np.array(x0)[0])
        #result.loc[0, ekf.dae.x] = x0
            
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
            map_estimate = ekf.one_sample_feedback.mapaccum(
                                                            "simulator",
                                                            N-1,
                                                            ["x_0", "P_0"],
                                                            ["x_11", "P_11"],
                                                            #[0,1,2],
                                                            #[0,1,2]
                                                            )
            """
            map_estimate = ekf.one_sample_feedback_adj.mapaccum(
                                                            "simulator",
                                                            N,
                                                            [0,1],
                                                            [3,7]
                                                            )
            
            # before filtering, we know x0:
            result.loc[0, ekf.dae.x] = x0.values
            #y_to_x = [mx.name() for mx in list(ekf.dae.y.values())] 
            #x0_df = pd.DataFrame(columns=ekf.dae.x, data=x0)
            # TODO: generalize:
            result.loc[0, "y_pred"] = x0["Ti"].values
            result.loc[0, ekf.p_cols] = np.array(P0x).flatten()
            
            res = map_estimate(
                x_0=x0.values,
                z_0=ca.repmat(z_guess, 1, N),
                #P_0=np.diag([1]*ekf.n_x),
                P_0=P0x,
                u=y_data[ekf.dae.u].values[0:N].T,
                r=y_data[ekf.dae.r_names].values[0:N].T,
                p=ca.repmat(p_base, 1, N),
                #y=y_data[ekf.dae.y_names].shift(-1).values.T[:,1:],
                #y=y_data[ekf.dae.y_names].values[1:].T,
                y=y_data[ekf.dae.y_names].values[:].T,
                Q=ca.repmat(Q, 1, N), # Q, flat, must be passed
                R=ca.repmat(R, 1, N), # R must be passed
                dt=self.dt
            )
                 
            # use filtering form:
            """
            x_hat = res["x_11"] #.reshape(((N-1), ekf.n_x))
            x_pred = res["x_10"] #.reshape(((N-1), ekf.n_x))
            P_hat = res["P_11"] #.reshape(((N-1), ekf.n_x))
            P_pred = res["P_10"] #.reshape(((N-1), ekf.n_x))
            zs = np.array(res["z"]) #.reshape(((N-1), ekf.n_x))
            #x_pred = res["x_10"].reshape(((N)*ekf.n_x, 1))
            y_pred = res["h_x"]
            # NOTE: x_hat, x_pred shifted
            xs = np.append(xs, np.array(x_pred))  
            result.loc[1:N-1, ekf.dae.x] = np.array(x_hat).T
            result.loc[1:N-1, "y_pred"] = np.array(y_pred).flatten()
            result.loc[:, "y_meas"] = y_data[ekf.dae.y_names].values.flatten()
            result.loc[1:N-1, ekf.p_cols] = np.array(P_hat).T.reshape((N-1,ekf.dae.n_x**2))
            """
            x_hat = res["x_00"] #.reshape(((N-1), ekf.n_x))
            x_pred = res["x_10"] #.reshape(((N-1), ekf.n_x))
            P_hat = res["P_00"] #.reshape(((N-1), ekf.n_x))
            P_pred = res["P_10"] #.reshape(((N-1), ekf.n_x))
            zs = np.array(res["z"]) #.reshape(((N-1), ekf.n_x))
            #x_pred = res["x_10"].reshape(((N)*ekf.n_x, 1))
            y_pred = res["h_x"]
            # NOTE: x_hat, x_pred shifted
            xs = np.append(xs, np.array(x_pred))  
            result.loc[0:N-1, ekf.dae.x] = np.array(x_hat).T
            result.loc[0:N-1, "y_pred"] = np.array(y_pred).flatten()
            result.loc[:, "y_meas"] = y_data[ekf.dae.y_names].values.flatten()
            result.loc[0:N, ekf.p_cols] = np.array(P_hat).T.reshape((N,ekf.dae.n_x**2))
            #result.loc[1:, "res"] = result.loc[:, "y_meas"] - result.loc[:, "y_pred"]
            #xs = xs.reshape(ekf.n_x, N)
        
        # cannot filter last (no measurement)
        #xs = np.append(xs, np.array([np.nan, np.nan]))
        #result.index = y_data.dt_index
        """
        one_step, y_data = self._post_process_sim(
                                      #xs[:-self.dae.n_x],
                                      xs,
                                      zs,
                                      y_data[:-1]
                                      )
        """
        result["res"] = result["y_meas"] - result["y_pred"]  
        self.one_step_res = pd.DataFrame(result["res"])
        self.one_step_res.columns = map(lambda x: x + "_res", ekf.y)
        self.one_step_res[ekf.p_cols] = np.nan
        self.one_step_res[ekf.dae.x] = np.nan
        self.one_step_res["V_k"] = np.nan
        ####################### save model preds: #######################################
        self.one_step_res.loc[0, ekf.p_cols] = np.array(P0x).flatten()
        self.one_step_res.loc[0, ekf.dae.x] = x0.values
        self.one_step_res.loc[0:,ekf.p_cols] = np.array(P_pred).T.reshape((N, ekf.n_x**2))
        self.one_step_res.loc[0:, ekf.dae.x] = np.array(x_pred).T.reshape(((N), ekf.n_x))
        self.one_step_res.loc[0:, "V_k"] = np.array(res["V_k"]).T
        #################################################################################
        # save output prediction covariance:
        result.index = y_data.dt_index
        self.one_step_res.index = y_data.dt_index
        ####################################
        self.filtered = result
        return self.one_step_res, y_data, result
       
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
                        savefig=True,
                        suff="",
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
        self.res, y_data = self.simulate_full(
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
                    fig, ax = plt.subplots(1,1)
                    #res.Ti.plot(color="r", drawstyle="steps-post")
                #else:
                self.res.Ti.plot(color="r", linewidth=0.5, drawstyle="steps-post", ax=ax)    
                    
                y_data.y1.plot(color="k", linestyle="dashed", drawstyle="steps-post", linewidth=0.75, ax=ax)
                #y_data.Tset.plot(color="y", linestyle="dashed", drawstyle="steps-post", linewidth=0.75, ax=ax)
                #y_data.Ta.plot(color="b", linestyle="dashed", linewidth=0.75, ax=ax, drawstyle="steps-post")
                ax1 = ax.twinx()
                #y_data.vent_on.plot(ax=ax1, color="y", linewidth=0.75, drawstyle="steps-post")
                (y_data.phi_h/1000).plot(ax=ax1, color="g", linewidth=0.75, drawstyle="steps-post")
                (y_data.phi_s/1000).plot(ax=ax1, color="y", linewidth=0.75, drawstyle="steps-post")
                (y_data.phi_int_plugs/1000).plot(ax=ax1, color="m", linewidth=0.75, drawstyle="steps-post")
                (y_data.phi_int_lig/1000).plot(ax=ax1, color="b", linewidth=0.75, drawstyle="steps-post")
                y_data.vent.plot(ax=ax1, color="g", linewidth=0.75, drawstyle="steps-post")
                ax1.set_ylim([0,2.5])
                ax.set_ylim([18,25])
                if ax is None:
                    ax.legend(["model", "measured"])
                #else:
                #    #ax.legend(["$\\hat{x}_{N} \\vert M", "y_{N}"])
                fig.savefig("plots/" + str(y_data.index[-2]).split(" ")[0] + suff + ".pdf") 
            else:
                y_map = self.param_est.dae.y
                fig, axes = plt.subplots(4,1, sharex=True)
                for i, (y, var) in enumerate(y_map.items()):
                    name = var.name()
                    ax = axes[i]
                    y_data[y].plot(color="k", linewidth=0.75, ax=ax)
                    self.res[name].plot(color="r", linestyle="dashed", linewidth=0.75, ax=ax)
                    ax.legend([y, name])
                
            plt.close()
        
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
                            P0=None,
                            P0x=None,
                            ax=None,
                            suff=""
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
                                                    P0=P0,
                                                    P0x=P0x
                                                    # pass switch as anonymous func
                                                    )
        # need to cut out estimate of first state:
        
        SMALL_SIZE = 10
        MEDIUM_SIZE = 10
        BIGGER_SIZE = 10
        self.MARKERSIZE = 2
        self.LINEWIDTH=0.75

        plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
        plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
        plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
        plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
        plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title
        
        if plot:
            #res = res[1:]
            #y_data = y_data[1:]
            filtered.index = y_data.index
            # now, can plot:
            fig, ax = plt.subplots(1,1,sharex=True)
            #if ax is None:
            self.filtered = self.filtered.astype(float)
            self.filtered.y_pred.plot(
                                    color="r",
                                    drawstyle="steps-post",
                                    linewidth=0.5
                                    )
            #else:
            #    res.Ti.plot(ax=ax, color="r", drawstyle="steps-post")
            self.filtered.y_meas.plot(
                           color="k",
                           linestyle="dashed", 
                           drawstyle="steps-post",
                           linewidth=0.5, 
                           ax=ax
                           )
            #filtered.Ti.plot(color="g", linestyle="dashed", linewidth=0.75, ax=ax)
            #y_data.Ta.plot(color="b", linestyle="dashed", linewidth=0.75, ax=ax)
            ax1 = ax.twinx()
            #y_data.weeknd.plot(ax=ax1, color="y", linewidth=0.75)
            #y_data.vent_on.plot(ax=ax1, color="y", linewidth=0.75)
            #(y_data.phi_h/y_data.phi_h.max()).plot(ax=ax1, color="g", linewidth=0.75)
            (y_data.phi_h/1000).plot(ax=ax1, color="g", linewidth=0.75, drawstyle="steps-post")
            try:
                y_data.vent.plot(ax=ax1, color="m", linewidth=0.75, drawstyle="steps-post")
            except AttributeError:
                pass
            ax1.set_ylim([0,2.5])
            ax.set_ylim([290,300])
            fig.savefig("plots/" + "one_step_" + str(y_data.index[0]).split(" ")[0] + suff + ".pdf")
            #ax.legend(["model", "measured", "filtered"])
            plt.show()
            
            #plt.close()
        
    def make_journal_plot(
                          self,
                          y_data,
                          x0,
                          name,
                          res=None
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
        plt.rc('axes', labelsize=SMALL_SIZE)    # fontsize of the x and y labels
        plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
        #plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
        plt.rc('figure', titlesize=SMALL_SIZE)  # fontsize of the figure title
    
        if res is None:
            res, y_data = self.simulate_full(x0, y_data)
        y_data[res.columns] = res
        
        save_journal_plot(y_data, "plots/" + name + ".pdf")
          
    def make_journal_plot_alt(
                          self,
                          name,
                          training=True,
                          day=0
                         ):
        
        SMALL_SIZE = 14
        MEDIUM_SIZE = 16
        BIGGER_SIZE = 16
        self.MARKERSIZE = 2
        self.LINEWIDTH=0.75

        plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
        plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
        plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
        plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
        plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title
        
        self.save_journal_plot_alt_alt(
                                "plots/" + name + ".pdf",
                                   training=training,
                                   day=day
                                   )
    def make_data_plot_alt(
                          self,
                          name,
                          training=True,
                          day=0
                         ):
        
        SMALL_SIZE = 14
        MEDIUM_SIZE = 16
        BIGGER_SIZE = 16
        self.MARKERSIZE = 2
        self.LINEWIDTH=0.75

        plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
        plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
        plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
        plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
        plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
        plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title
        
        self.save_data_plot_alt(
                                "plots/data_" + name + ".pdf",
                                   training=training,
                                   day=day
                                   )
          
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
        
    def save_journal_plot_alt(self, name, training=True):
        """
        Make a nicely formatted plot of
        simulation result, boundary conditions.
        
        TODO: handling unit C or K
        
        """
        if training:
            data = self.train_res
            markevery = 1E6
        else:
            data = self.val_res
            markevery = 13
        
        fig, axes = plt.subplots(3,1, sharex=True, figsize=(14,7 ))
        # plot training fit:
        ax = axes[0]
        
        index = data.index
        #plt.set_prop_cycle(color_cycler)
        #plt.rc('axes', prop_cycle=color_cycler)
        ax.plot(index.to_numpy(),
            data["Ti_onestep"].to_numpy(),
                                  linewidth=self.LINEWIDTH,
                                  drawstyle="steps-post",
                                  c=color_map_custom["one_step"],
                                  #cmap=my_cmap
                                  ) #, marker="v", markersize=MARKERSIZE)
        ax.plot(index.to_numpy(),
            data["y1"].to_numpy(),
                linewidth=self.LINEWIDTH,
                          drawstyle="steps-post",
                          #color="k",
                          linestyle="dashed",
                          c=color_map_custom["meas"],
                          #cmap=my_cmap,
                          ) #, marker="<", markersize=MARKERSIZE)
        ax.plot(index.to_numpy(),
                data["Ti_sim"].to_numpy(),
                linewidth=self.LINEWIDTH,
                              drawstyle="steps-post", 
                              #linestyle="dashed",
                              #color="r",
                              c=color_map_custom["sim"],
                              #cmap=my_cmap,
                              markevery=markevery,
                              #ax=ax,
                              marker="*", 
                              markersize=self.MARKERSIZE)
        ax.plot(index.to_numpy(),
                data["T_sup_air"].to_numpy(),
                                 c=color_map_custom["vent_in"],
                                 #cmap=my_cmap,
                                 linestyle="dashed",
                                 #ax=ax, 
                                 linewidth=self.LINEWIDTH)
        ax.plot(index.to_numpy(),
                data["T_ext_air"].to_numpy(),
                                 c=color_map_custom["vent_out"],
                                 #cmap=my_cmap,
                                 linestyle="dashed",
                                 #ax=ax,
                                 linewidth=self.LINEWIDTH)
        ax.set_ylabel("Temperature $[^\circ C]$")
        #ax.legend(["$T_i$", "$T_{i}^{meas}$", "$T_{sup}^{v}$", "$T_{ext}^{v}$"], loc="upper left", ncol=4)
        ylim = ax.get_ylim()
        #ax.set_ylim([ylim[0], ylim[1]*1.05])
        ax.set_ylim([ylim[0], ylim[1]*1.05])
        ax.legend(
                  [
                   "$\\hat{x}_{k|k-1}$", 
                   "$y_{N}$",
                   "$x_{K|K-M}$",
                   "$T_{sup}^{v}$",
                   "$T_{ext}^{v}$"
                   ],
                  loc="upper left",
                  bbox_to_anchor=(0.0, 1.28),
                  ncol=5
                  )
        # dim. less vent on/off:
        ax1 = ax.twinx()
        ax = ax1
        #data["weeknd"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
        #ax.set_prop_cycle(color_cycler)
        ax.plot(index.to_numpy(),
            (data["vent"]).to_numpy(),
                          drawstyle="steps-post", 
                          c=color_map_custom["binary"],
                          linewidth=0.75
                          )
        ax.set_yticks([0,1])
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.1])
        ax.legend(["$\sigma_{vent}$"],
                  loc="upper right",
                  bbox_to_anchor=(1.00, 1.26),
                  ncol=1
                  )
        
        # vertlines:
        if not training:
            for ind in self.extra_inds:
                plt.axvline(x=ind, color='k', linewidth=0.5, label='axvline - full height')
        
        ax = axes[1]
        #ax.set_prop_cycle(color_cycler)
        # power, other room temps / ventilation 
        ax.plot(index.to_numpy(),
                (data["phi_h"]/1000).to_numpy(), 
                                  drawstyle="steps-post",
                                  #ax=ax,
                                  c=color_map_custom["space_heat"],
                                  linewidth=0.75
                                  )
        ax.plot(index.to_numpy(),
                (data["phi_int"]/1000).to_numpy(),
                                    #color="m",
                                    drawstyle="steps-post", 
                                    #ax=ax,
                                    c=color_map_custom["int_gains"],
                                    linewidth=0.75
                                    )
        #(data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
        ax.legend(["$\phi_h$", "$\phi_{int}$"], loc="upper left", ncol=1)
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.2])
        ax.set_ylabel("Power $[kW]$")
        ax1 = ax.twinx()
        ax = ax1
        #(data["T_sup_air"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
        #(data["T_321"] - 273.15).plot(color="b", ax=ax, linewidth=0.75)
        #(data["T_320"] - 273.15).plot(color="y", ax=ax, linewidth=0.75)
        ax.plot(index.to_numpy(),
                (data["ahu_reaFloSupAir"]).to_numpy(),
                                 #color="k",
                                 linestyle="dashed",
                                 #ax=ax,
                                 c=color_map_custom["vent_in"],
                                 linewidth=0.75
                                 )
        ax.plot(index.to_numpy(),
                (data["ahu_reaFloExtAir"]).to_numpy(),
                                 #color="g",
                                 linestyle="dashed",
                                 c=color_map_custom["vent_out"],
                                 #ax=ax,
                                 linewidth=0.75
                                 )
        #(data["T_321"]).plot(color="b", ax=ax, linewidth=0.75)
        #(data["T_320"]).plot(color="y", ax=ax, linewidth=0.75)
        #ax.legend(["$T_{sup}^{v}$", "$T_{321}$", "$T_{320}$"], loc="upper right", ncol=3)
        ax.legend(["$V_{sup}^{v}$", "$V_{ext}^{v}$"], loc="upper right", ncol=1)
        ax.set_ylabel("Airflow [$\\frac{kg}{s}$]")
        ax.set_xlabel("")
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.2])
        
        ax = axes[2]
        
        # dataar, outdoor temp
        #(data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
        ax.plot(index.to_numpy(),
                (data["phi_s"]/1000).to_numpy(),
                                  #color="y",
                                  c=color_map_custom["solar"], 
                                  drawstyle="steps-post", 
                                  #ax=ax, 
                                  linewidth=0.75
                                  )
        ax.legend(["$\phi_s$"], loc="upper left", ncol=1)
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.1])
        ax.set_ylabel("Solar global [$\\frac{kW}{m^2}$]")
        ax.set_yticks([0,0.5])
        ax.set_xlabel("")
        
        ax1 = ax.twinx()
        ax = ax1
        #(data["Ta"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
        ax.plot(index.to_numpy(),
                (data["Ta"]).to_numpy(),
                          c=color_map_custom["temp_amb"],
                          linestyle="dashed",
                          #ax=ax, 
                          linewidth=0.75
                          )
        #data["T_321"].plot(color="b", ax=ax, linewidth=0.75)
        #sol["T_320"].plot(color="y", ax=ax, linewidth=0.75)
        ax.legend(["$T_{a}$"], loc="upper right", ncol=1)
        ax.set_ylabel("Temperature $[^\circ C]$")
        ax.set_xlabel("")
        ylim = ax.get_ylim()

        # set formatter
        #plt.show()
        #ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
        #ax.xaxis.set_minor_formatter(mdates.DateFormatter('%b-%d'))
        ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
        ax.minorticks_off()
        #ax.xaxis.set_minor_formatter(mdates.DateFormatter('%b-%d'))
        # Rotates and right-aligns the x labels so they don't crowd each other.
        for label in ax.get_xticklabels(which='major'):
            label.set(rotation=30, horizontalalignment='right')
        #ax.set_ylim([ylim[0], ylim[1]*1.25])
        fig.tight_layout()
        plt.savefig(name)
        plt.savefig(name.replace(".pdf", ".png"))
        plt.close()
        
    def save_journal_plot_alt_alt(self, name, training=True, day=0):
        """
        Make a nicely formatted plot of
        simulation result, boundary conditions.
        
        TODO: handling unit C or K
        
        """
        extras = []
        if training:
            data = self.train_res[day]
            markevery = 1E6
            index = data.index
        else:
            skip = int(96/self.num_segments)
            data = self.val_res.copy()
            markevery = skip + 1
            index = data.index
            # go through index, add 'fake' to mark starting
            # point for simulation
            for i in range(1, self.num_segments*self.N_days):
                extra = index[skip*i] + pd.Timedelta(seconds=1e-3)
                extras.append(extra)
            # how to interpolate?
            index = pd.DatetimeIndex.union(index, extras)
            data = data.reindex(index)     
            """
            Forward-fill every column except sim pred:
            """
            rest = data.columns.drop(["Ti_sim"])
            data[rest] = data[rest].ffill()
            data["Ti_sim"] = data["Ti_sim"].ffill()
            #data[rest] = data[rest].ffill()
            #data["Ti_sim"] = data["Ti_sim"].ffill
        
        fig, axes = plt.subplots(2,1, sharex=True, figsize=(14,5 ))
        # plot training fit:
        ax = axes[0]
        
        
        #plt.set_prop_cycle(color_cycler)
        #plt.rc('axes', prop_cycle=color_cycler)
        ax.plot(index.to_numpy(),
            data["Ti_onestep"].to_numpy(),
                                  linewidth=self.LINEWIDTH,
                                  drawstyle="steps-post",
                                  c=color_map_custom["one_step"],
                                  #cmap=my_cmap
                                  ) #, marker="v", markersize=MARKERSIZE)
        ax.plot(index.to_numpy(),
            data["y1"].to_numpy(),
                linewidth=self.LINEWIDTH,
                          drawstyle="steps-post",
                          #color="k",
                          linestyle="dashed",
                          c=color_map_custom["meas"],
                          #cmap=my_cmap,
                          ) #, marker="<", markersize=MARKERSIZE)
        ax.plot(index.to_numpy(),
                data["Ti_sim"].to_numpy(),
                linewidth=self.LINEWIDTH,
                              drawstyle="steps-post", 
                              #linestyle="dashed",
                              #color="r",
                              c=color_map_custom["sim"],
                              #cmap=my_cmap,
                              markevery=markevery,
                              #ax=ax,
                              marker="*", 
                              markersize=self.MARKERSIZE)
        ax.set_ylabel("Temperature $[^\circ C]$")
        #ax.legend(["$T_i$", "$T_{i}^{meas}$", "$T_{sup}^{v}$", "$T_{ext}^{v}$"], loc="upper left", ncol=4)
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.05])
        ax.legend(
                  [
                   "$\\hat{x}_{k|k-1}$", 
                   "$y_{N}$",
                   "$x_{K|K-M}$"
                   ],
                  loc="upper left",
                  bbox_to_anchor=(0.0, 1.28),
                  ncol=3
                  )
        # dim. less vent on/off:
        ax1 = ax.twinx()
        ax = ax1
        #data["weeknd"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
        #ax.set_prop_cycle(color_cycler)
        ax.plot(index.to_numpy(),
            (data["vent"]).to_numpy(),
                          drawstyle="steps-post", 
                          c=color_map_custom["binary"],
                          linewidth=0.75
                          )
        ax.set_yticks([0,1])
        ylim = ax.get_ylim()
        #ax.set_ylim([ylim[0], ylim[1]*1.1])
        ax.legend(["$\sigma_{vent}$"],
                  loc="upper right",
                  bbox_to_anchor=(1.00, 1.26),
                  ncol=1
                  )
        
        # vertlines:
        if not training:
            #for ind in self.extra_inds:
            for ind in extras:
                plt.axvline(x=ind, color='k', linewidth=0.5, label='axvline - full height')
        
        ax = axes[1]
        #ax.set_prop_cycle(color_cycler)
        # power, other room temps / ventilation 
        ax.plot(index.to_numpy(),
                (data["phi_h"]/1000).to_numpy(), 
                                  drawstyle="steps-post",
                                  #ax=ax,
                                  c=color_map_custom["space_heat"],
                                  linewidth=0.75
                                  )
        ax.plot(index.to_numpy(),
                (data["phi_int"]/1000).to_numpy(),
                                    #color="m",
                                    drawstyle="steps-post", 
                                    #ax=ax,
                                    c=color_map_custom["int_gains"],
                                    linewidth=0.75
                                    )
        #(data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
        ax.plot(index.to_numpy(),
                (data["Pvent"]/1000).to_numpy(),
                                    #color="m",
                                    drawstyle="steps-post", 
                                    #ax=ax,
                                    c=color_map_custom["vent_in"],
                                    linewidth=0.75
                                    )
        ax.plot(index.to_numpy(),
                (data["phi_s"]/1000).to_numpy(),
                                    #color="m",
                                    drawstyle="steps-post", 
                                    #ax=ax,
                                    c=color_map_custom["solar"],
                                    linewidth=0.75
                                    )
        #(data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
        #ax.legend(["$\phi_h$", "$\phi_{int}$", "$\phi_{v}$", "$\phi_s$"], loc="upper left", ncol=1)
        
        # rotate ticks:
        #for label in ax.get_xticklabels(which='major'):
        #    label.set(rotation=30, horizontalalignment='right')
            
        ax.legend(["$\phi_h$", "$\phi_{int}$", "$\phi_{v}$", "$\phi_s$"], loc="upper left", ncol=4)
        ylim = ax.get_ylim()
        #ax.set_ylim([ylim[0], ylim[1]*1.2])
        ax.set_ylabel("Power $[kW]$")
        #(data["T_321"]).plot(color="b", ax=ax, linewidth=0.75)
        #(data["T_320"]).plot(color="y", ax=ax, linewidth=0.75)
        #ax.legend(["$T_{sup}^{v}$", "$T_{321}$", "$T_{320}$"], loc="upper right", ncol=3)
        #ax.legend(["$V_{sup}^{v}$", "$V_{ext}^{v}$"], loc="upper right", ncol=1)
        #ax.set_ylabel("Airflow [$\\frac{kg}{s}$]")
        ax.set_xlabel("")
        ylim = ax.get_ylim()
        #ax.set_ylim([ylim[0], ylim[1]*1.2])
        #ax.set_ylim([18,25])
        
        
        ax1 = ax.twinx()
        ax = ax1
        #(data["Ta"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
        ax.plot(index.to_numpy(),
                (data["Ta"]).to_numpy(),
                          c=color_map_custom["temp_amb"],
                          linestyle="dashed",
                          #ax=ax, 
                          linewidth=0.75
                          )
        #data["T_321"].plot(color="b", ax=ax, linewidth=0.75)
        #sol["T_320"].plot(color="y", ax=ax, linewidth=0.75)
        ax.legend(["$T_{a}$"], loc="upper right", ncol=1)
        ax.set_ylabel("Temperature $[^\circ C]$")
        ax.set_xlabel("")
        ylim = ax.get_ylim()

        """
        ax = axes[2]
        ax.plot(index.to_numpy(),
        (data["ahu_reaFloSupAir"]).to_numpy(),
                            #color="k",
                            linestyle="dashed",
                            #ax=ax,
                            c=color_map_custom["vent_in"],
                            linewidth=0.75
                            )
        ax.plot(index.to_numpy(),
                (data["ahu_reaFloExtAir"]).to_numpy(),
                                 #color="g",
                                 linestyle="dashed",
                                 c=color_map_custom["vent_out"],
                                 #ax=ax,
                                 linewidth=0.75
                                 )
        #(data["T_321"]).plot(color="b", ax=ax, linewidth=0.75)
        #(data["T_320"]).plot(color="y", ax=ax, linewidth=0.75)
        #ax.legend(["$T_{sup}^{v}$", "$T_{321}$", "$T_{320}$"], loc="upper right", ncol=3)
        ax.legend(["$V_{sup}^{v}$", "$V_{ext}^{v}$"], loc="upper right", ncol=1)
        ax.set_ylabel("Airflow [$\\frac{kg}{s}$]")
        ax.set_xlabel("")
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.2])
        """
        # set formatter
        #plt.show()
        #ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
        #ax.xaxis.set_minor_formatter(mdates.DateFormatter('%b-%d'))
        ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
        ax.minorticks_off()
        #ax.xaxis.set_minor_formatter(mdates.DateFormatter('%b-%d'))
        # Rotates and right-aligns the x labels so they don't crowd each other.
        #ax.set_ylim([ylim[0], ylim[1]*1.25])
        fig.tight_layout()
        plt.savefig(name)
        plt.savefig(name.replace(".pdf", ".png"))
        plt.close()
        
    def save_data_plot_alt(self, name, training=True,day=0):
        """
        Make a nicely formatted plot of
        simulation result, boundary conditions.
        
        TODO: handling unit C or K
        
        """
        if training:
            data = self.train_res[day]
            markevery = 1E6
        else:
            data = self.val_res
            markevery = 13
        
        fig, axes = plt.subplots(4,1, sharex=True, figsize=(14,10))
        # plot training fit:
        ax = axes[0]
        
        index = data.index
        #plt.set_prop_cycle(color_cycler)
        #plt.rc('axes', prop_cycle=color_cycler)
        ax.plot(index.to_numpy(),
            data["y1"].to_numpy(),
                linewidth=1.0,
                          drawstyle="steps-post",
                          #color="k",
                          c=color_map_custom["meas"],
                          #cmap=my_cmap,
                          ) #, marker="<", markersize=MARKERSIZE)
        for col in ["T_219_TR1", "T_219_TR2", "T_219_TR3", "T_219_TR4"]:
            ax.plot(index.to_numpy(),
                data[col].to_numpy(),
                    linewidth=self.LINEWIDTH,
                            drawstyle="steps-post",
                            #color="k",
                            linestyle="dashed",
                            c=color_map_custom[col],
                            #cmap=my_cmap,
                            ) #, marker="<", markersize=MARKERSIZE)
            
        #ax.legend(["$T_i$", "$T_{i}^{meas}$", "$T_{sup}^{v}$", "$T_{ext}^{v}$"], loc="upper left", ncol=4)
        ylim = ax.get_ylim()
        #ax.set_ylim([ylim[0], ylim[1]*1.05])
        #ax.set_ylim([ylim[0], ylim[1]*0.9])
        ax.legend(
                  [
                   "$y_{N}$",
                   "$y_{1,N}$",
                   "$y_{2,N}$",
                   "$y_{3,N}$",
                   "$y_{4,N}$"
                   ],
                  loc="upper left",
                  bbox_to_anchor=(0.0, 1.28),
                  ncol=5
                  )
        ax.set_ylabel("Temperature $[^\circ C]$")
        
        ax = axes[1]
        
        ax.plot(index.to_numpy(),
                data["T_sup_air"].to_numpy(),
                                 c=color_map_custom["vent_in"],
                                 #cmap=my_cmap,
                                 linestyle="dashed",
                                 #ax=ax, 
                                 linewidth=self.LINEWIDTH)
        ax.plot(index.to_numpy(),
                data["T_ext_air"].to_numpy(),
                                 c=color_map_custom["vent_out"],
                                 #cmap=my_cmap,
                                 linestyle="dashed",
                                 #ax=ax,
                                 linewidth=self.LINEWIDTH)
        ax.set_ylabel("Temperature $[^\circ C]$")
        ylim = ax.get_ylim()
        #ax.set_ylim([ylim[0], ylim[1]*1.05])
        #ax.set_ylim([ylim[0], ylim[1]*0.9])
        ax.legend(
                  [
                   "$T_{sup}^{v}$",
                   "$T_{ext}^{v}$"
                   ],
                  loc="upper left",
                  bbox_to_anchor=(0.0, 1.26),
                  ncol=2
                  )
        # dim. less vent on/off:
        ax1 = ax.twinx()
        ax = ax1
        #data["weeknd"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
        #ax.set_prop_cycle(color_cycler)
        ax.plot(index.to_numpy(),
            (data["vent"]).to_numpy(),
                          drawstyle="steps-post", 
                          c=color_map_custom["binary"],
                          linewidth=0.75
                          )
        ax.set_yticks([0,1])
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.1])
        ax.legend(["$\sigma_{vent}$"],
                  loc="upper right",
                  bbox_to_anchor=(1.00, 1.26),
                  ncol=1
                  )
        
        # vertlines:
        if not training:
            for ind in self.extra_inds:
                plt.axvline(x=ind, color='k', linewidth=0.5, label='axvline - full height')
        
        ax = axes[2]
        #ax.set_prop_cycle(color_cycler)
        # power, other room temps / ventilation 
        ax.plot(index.to_numpy(),
                (data["phi_h"]/1000).to_numpy(), 
                                  drawstyle="steps-post",
                                  #ax=ax,
                                  c=color_map_custom["space_heat"],
                                  linewidth=0.75
                                  )
        ax.plot(index.to_numpy(),
                (data["phi_int"]/1000).to_numpy(),
                                    #color="m",
                                    drawstyle="steps-post", 
                                    #ax=ax,
                                    c=color_map_custom["int_gains"],
                                    linewidth=0.75
                                    )
        #(data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
        ax.legend(["$\phi_h$", "$\phi_{int}$"], loc="upper left", ncol=1)
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.2])
        ax.set_ylabel("Power $[kW]$")
        ax1 = ax.twinx()
        ax = ax1
        #(data["T_sup_air"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
        #(data["T_321"] - 273.15).plot(color="b", ax=ax, linewidth=0.75)
        #(data["T_320"] - 273.15).plot(color="y", ax=ax, linewidth=0.75)
        ax.plot(index.to_numpy(),
                (data["ahu_reaFloSupAir"]).to_numpy(),
                                 #color="k",
                                 linestyle="dashed",
                                 #ax=ax,
                                 c=color_map_custom["vent_in"],
                                 linewidth=0.75
                                 )
        ax.plot(index.to_numpy(),
                (data["ahu_reaFloExtAir"]).to_numpy(),
                                 #color="g",
                                 linestyle="dashed",
                                 c=color_map_custom["vent_out"],
                                 #ax=ax,
                                 linewidth=0.75
                                 )
        #(data["T_321"]).plot(color="b", ax=ax, linewidth=0.75)
        #(data["T_320"]).plot(color="y", ax=ax, linewidth=0.75)
        #ax.legend(["$T_{sup}^{v}$", "$T_{321}$", "$T_{320}$"], loc="upper right", ncol=3)
        ax.legend(["$V_{sup}^{v}$", "$V_{ext}^{v}$"], loc="upper right", ncol=1)
        ax.set_ylabel("Airflow [$\\frac{kg}{s}$]")
        ax.set_xlabel("")
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.2])
        
        ax = axes[3]
        
        # dataar, outdoor temp
        #(data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
        ax.plot(index.to_numpy(),
                (data["phi_s"]/1000).to_numpy(),
                                  #color="y",
                                  c=color_map_custom["solar"], 
                                  drawstyle="steps-post", 
                                  #ax=ax, 
                                  linewidth=0.75
                                  )
        ax.legend(["$\phi_s$"], loc="upper left", ncol=1)
        ylim = ax.get_ylim()
        ax.set_ylim([ylim[0], ylim[1]*1.1])
        ax.set_ylabel("Solar global [$\\frac{kW}{m^2}$]")
        ax.set_yticks([0,0.5])
        ax.set_xlabel("")
        
        ax1 = ax.twinx()
        ax = ax1
        #(data["Ta"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
        ax.plot(index.to_numpy(),
                (data["Ta"]).to_numpy(),
                          c=color_map_custom["temp_amb"],
                          linestyle="dashed",
                          #ax=ax, 
                          linewidth=0.75
                          )
        #data["T_321"].plot(color="b", ax=ax, linewidth=0.75)
        #sol["T_320"].plot(color="y", ax=ax, linewidth=0.75)
        ax.legend(["$T_{a}$"], loc="upper right", ncol=1)
        ax.set_ylabel("Temperature $[^\circ C]$")
        ax.set_xlabel("")
        ylim = ax.get_ylim()

        # set formatter
        #plt.show()
        #ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
        #ax.xaxis.set_minor_formatter(mdates.DateFormatter('%b-%d'))
        ax.xaxis.set_major_formatter(mdates.DateFormatter('%b-%d'))
        ax.minorticks_off()
        #ax.xaxis.set_minor_formatter(mdates.DateFormatter('%b-%d'))
        # Rotates and right-aligns the x labels so they don't crowd each other.
        for label in ax.get_xticklabels(which='major'):
            label.set(rotation=30, horizontalalignment='right')
        #ax.set_ylim([ylim[0], ylim[1]*1.25])
        fig.tight_layout()
        plt.savefig(name)
        plt.savefig(name.replace(".pdf", ".png"))
        plt.close()
        

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
    (data["Ti"]).plot(color="r", linestyle="dashed", drawstyle="steps-post", ax=ax, linewidth=0.75)
    (data["y1"]).plot(color="k", ax=ax, linewidth=0.75,  drawstyle="steps-post")
    (data["T_sup_air"]).plot(color="k", linestyle="dashed", ax=ax, linewidth=0.75)
    (data["T_ext_air"]).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    ax.set_ylabel("Temperature $[^\circ C]$")
    ax.legend(["$T_i$", "$T_{i}^{meas}$", "$T_{sup}^{v}$", "$T_{ext}^{v}$"], loc="upper left", ncol=4)
    ylim = ax.get_ylim()
    #ax.set_ylim([ylim[0], ylim[1]*1.3])
    ax.set_ylim([18,25])
    ax1 = ax.twinx()
    ax = ax1
    #data["weeknd"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
    data["vent"].plot(color="m", ax=ax, drawstyle="steps-post", linewidth=0.75)
    ax.legend(["$\sigma_{vent}$"], loc="upper right", ncol=1)
    ax.set_yticks([0,1])
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.35])
    #ax.set_ylim([18,25])
    
    ax = axes[1]
    
    # power, other room temps / ventilation 
    (data["phi_h"]/1000).plot(color="r", drawstyle="steps-post", ax=ax, linewidth=0.75)
    (data["phi_int"]/1000).plot(color="m", drawstyle="steps-post", ax=ax, linewidth=0.75)
    #(data["phi_s"]/1000).plot(color="y", drawstyle="steps-post", ax=ax, linewidth=0.75)
    ax.legend(["$\phi_h$", "$\phi_{int}$"], loc="upper left", ncol=1)
    ylim = ax.get_ylim()
    ax.set_ylim([ylim[0], ylim[1]*1.2])
    ax.set_ylabel("Power $[kW]$")
    ax1 = ax.twinx()
    ax = ax1
    #(data["T_sup_air"] - 273.15).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    #(data["T_321"] - 273.15).plot(color="b", ax=ax, linewidth=0.75)
    #(data["T_320"] - 273.15).plot(color="y", ax=ax, linewidth=0.75)
    (data["V_sup_air"]).plot(color="k", linestyle="dashed", ax=ax, linewidth=0.75)
    (data["V_ext_air"]).plot(color="g", linestyle="dashed", ax=ax, linewidth=0.75)
    #(data["T_321"]).plot(color="b", ax=ax, linewidth=0.75)
    #(data["T_320"]).plot(color="y", ax=ax, linewidth=0.75)
    #ax.legend(["$T_{sup}^{v}$", "$T_{321}$", "$T_{320}$"], loc="upper right", ncol=3)
    ax.legend(["$V_{sup}^{v}$", "$V_{ext}^{v}$"], loc="upper right", ncol=1)
    ax.set_ylabel("Airflow [boldsymbol{$\\frac{m^3}{h}$}]")
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
    plt.close()
    
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
            ax_i.set_ylim(0, 500)
            ax_twin = ax_i.twinx()
            ymax = ax_i.get_ylim()[1]
            ax_twin.set_ylim(0, ymax / norm_factor)
            #ax_twin.set_ylim(0, 450)
        #plt.suptitle(title, fontsize=18)
        fig.tight_layout()
        plt.savefig("plots/" + title.replace(", ", "_") + ".pdf")
        plt.savefig("plots/" + title.replace(", ", "_") + ".png")
        #plt.show()

    #df1, df2 = [pd.DataFrame({"gap": np.random.normal(0, 0.2, n)}) for n in [6000, 4000]]
    #df1 = one_step_df[["res"]].copy()
    df1 = one_step_df[["Ti_res"]].copy()
    df1.columns = ["gap"]
    df2 = sim_df[["v1"]].copy()
    df2.index = df1.index
    df2.columns = ["gap"]

    # filter out abs(res) > 0.4
    #df1[abs(df1) > 0.4] = 0
    #df2[abs(df2) > 0.4] = 0
    
    drawSubplots(df1, df2, name)




