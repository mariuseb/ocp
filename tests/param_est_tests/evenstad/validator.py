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

from ocp.tests.param_est_tests.result_generator import ResultGenerator
import pandas as pd
import numpy as np

class Validator(object):
    """
    Convenience class for 
    validation of grey-box
    models.
    """
    def __init__(
                 self,
                 data,
                 cfg_path,
                 ekf_path,
                 dt=3600,
                 switches=["weeknd"] # could be more
                 ):
        self.data = data # assume cleaned
        self._generate_paths(cfg_path, ekf_path, switches)
        self.params = pd.DataFrame(pd.read_csv(
                                self.params_path,
                                index_col=0)
                                   )
        self.p_base = pd.DataFrame(pd.read_csv(
                                self.p_base_path,
                                index_col=0)).values.flatten()
                                   
        if len(switches) > 0:
            self.p_mod = pd.DataFrame(pd.read_csv(
                                    self.p_mod_paths[0],
                                    index_col=0)).values.flatten()
            self.tvp = True
        self.result_gen = ResultGenerator(
                    config=cfg_path,
                    params=self.params,
                    dt=dt
        )
        
        
    def _generate_paths(self,
                        cfg_path,
                        ekf_path,
                        switches
                        ):
        """
        Paths needed for plot generation.
        """
        self.base_path = base_path = \
            cfg_path.removeprefix("configs/").removesuffix(".json") + \
                    ".csv"
        self.params_path = "results/params_" + \
            base_path
        self.trajectory_path = "results/sol_" + \
            base_path
        self.p_base_path = "results/params_" + \
            base_path.removesuffix(".csv") + \
                "_base.csv"
        self.p_base_path = "results/params_" + \
            base_path.removesuffix(".csv") + \
                "_base.csv"
        self.p_mod_paths = []
        
        for switch in switches:
            p_mod_path = "results/params_" + \
                base_path.removesuffix(".csv") + \
                "_mod_" + \
                    switch + \
                        ".csv"    
            self.p_mod_paths.append(p_mod_path)
            
        self.ekf_config = ekf_path
        self.training_plot_path = "training_plot_" + \
            base_path.removesuffix(".csv")
        self.train_residual_plot_path = "training_residual_" + \
            base_path.removesuffix(".csv")
        self.validation_plot_path = "validation_plot_" + \
            base_path.removesuffix(".csv")
        self.validation_residual_plot_path = "validation_residual_" + \
            base_path.removesuffix(".csv")
            
    def generate_plots(
                        self,
                        x0: np.array,
                        data: pd.DataFrame,
                        plot_path: str,
                        residual_plot_path: str
                       ):
        self.result_gen.simple_sim_plot(
                                data,
                                x0
                                )
        self.result_gen.simple_one_step_plot(
                                data,
                                x0, 
                                p_base=self.p_base,
                                p_mod=self.p_mod,
                                p_tvp=self.params.values,
                                tvp=self.tvp,
                                ekf_config=self.ekf_config,
                                cond_series=data.vent_on,
                                switch=
                                    lambda x, p, p_mod: 
                                    p + p_mod
                                    if x > 0
                                    else
                                    p
                                )  
        self.result_gen.make_journal_plot(
                                    data,
                                    x0, 
                                    plot_path
                                    )
        res = self.result_gen.plot_residual_dist(
                                                data,
                                                residual_plot_path
                                                )
        if plot_path.startswith("train"):
            metrics_name = "training"
        else:
            metrics_name = "validation"
        metrics = self.result_gen.report_metrics(metrics_name)
        print(metrics)   
    
    def generate_training_plots(
                                self, 
                                start: pd.Timestamp, 
                                stop: pd.Timestamp
                                ):
        sol = pd.read_csv(self.trajectory_path, index_col=0)
        x0 = sol[self.result_gen.x].iloc[0]
        data = self.data.loc[start:stop]
        self.generate_plots(
                            x0,
                            data,
                            self.training_plot_path,
                            self.train_residual_plot_path
                            )
        
    def generate_validation_plots(
                                self, 
                                start: pd.Timestamp, 
                                stop: pd.Timestamp
                                ):
        """
        NB! must be called after filtering, 
        i.e. one-step ahead simulation.
        """
        x0 = self.result_gen.filtered[self.result_gen.x].iloc[-1]
        data = self.data.loc[start:stop]
        self.generate_plots(
                            x0,
                            data,
                            self.validation_plot_path,
                            self.validation_residual_plot_path
                            )
        
        
    def generate_all_plots(
                            self,
                            train_start: pd.Timestamp, 
                            train_stop: pd.Timestamp,
                            val_start: pd.Timestamp, 
                            val_stop: pd.Timestamp
                           ):
        self.generate_training_plots(
                                     train_start, 
                                     train_stop
                                     )
        self.generate_validation_plots(
                                     val_start, 
                                     val_stop
                                     )







