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

"""
What is the name of the config-file?

All other names will be derived frsom it.
"""

cfg_path = "configs/2R2C_det_vent_single_tvp_weeknd.json"

base_path = cfg_path.removeprefix("configs/").removesuffix(".json") + \
            ".csv"
params_path = "results/params_" + \
            base_path
trajectory_path = "results/sol_" + \
            base_path
ekf_config = "configs/2R2C_det_vent_EKF.json"

training_plot_path = "training_plot_" + base_path.removesuffix(".csv")
train_residual_plot_path = "training_residual_" + base_path.removesuffix(".csv")
validation_plot_path = "validation_plot_" + base_path.removesuffix(".csv")
validation_residual_plot_path = "validation_residual_" + base_path.removesuffix(".csv")

params = pd.DataFrame(pd.read_csv(params_path, index_col=0))
# to get estimated x0, read trajectory:
sol = pd.read_csv(trajectory_path, index_col=0)
data = pd.read_csv("april_2024.csv", index_col=0)
data.index = pd.to_datetime(data.index)
data["dt_index"] = data.index

training_start = pd.Timestamp("2024-04-04 00:00")
training_stop = pd.Timestamp("2024-04-11 00:00")

y_data = data.loc[training_start:training_stop]

"""
GOAL: produce all needed results with following object:
"""

result_gen = ResultGenerator(
                             #config="configs/3R3C_det_vent_207_cond_weekend_full_tvp.json",
                             #config="configs/2R2C_det_vent.json",
                             config=cfg_path,
                             params=params,
                             dt=3600
                            )


x0 = sol[result_gen.x].iloc[0]
result_gen.simple_sim_plot(
                           y_data,
                           x0
                           )

#p_base = pd.read_csv("results/tvp_params_base.csv", index_col=0).values.flatten()
p_base = pd.read_csv("results/params_2R2C_det_vent_single_tvp_weeknd_base.csv", index_col=0).values.flatten()
p_mod = pd.read_csv("results/params_2R2C_det_vent_single_tvp_weeknd_mod_weeknd.csv", index_col=0).values.flatten()

result_gen.simple_one_step_plot(
                                y_data,
                                x0, 
                                p_base=p_base,
                                p_mod=p_mod,
                                p_tvp=params.values,
                                tvp=True,
                                ekf_config=ekf_config,
                                cond_series=y_data.weeknd,
                                switch=
                                    lambda x, p, p_mod: 
                                    p + p_mod
                                    if x > 0
                                    else
                                    p
                                )

x0 = sol[result_gen.x].iloc[0]
result_gen.make_journal_plot(
                             y_data,
                             x0, 
                             training_plot_path
                             )
res = result_gen.plot_residual_dist(
                                    y_data,
                                    train_residual_plot_path
                                    )
"""
ljung_test = acorr_ljungbox(res.Ti_res, lags=len(y_data)-2)
shapiro_test = shapiro(res.Ti_res)
normal_data = np.random.normal(size=500)
normal_data[54] += 10
shapiro_test_normal = shapiro(normal_data)
from pandas.plotting import autocorrelation_plot
autocorrelation_plot(res.Ti_res)
"""
train_metrics = result_gen.report_metrics("training")
print(train_metrics)

"""
Switch to validation dataset:
"""

val_start = pd.Timestamp("2024-04-11 00:00")
val_stop = pd.Timestamp("2024-04-15 23:00")
y_data = data.loc[val_start:val_stop]

#x0 = sol[result_gen.x].iloc[-1]
x0 = result_gen.filtered[result_gen.x].iloc[-1]
result_gen.simple_sim_plot(
                           y_data,
                           x0
                           )
result_gen.simple_one_step_plot(
                                y_data,
                                x0, 
                                p_base=p_base,
                                p_mod=p_mod,
                                p_tvp=params.values,
                                tvp=True,
                                ekf_config=ekf_config,
                                cond_series=y_data.weeknd,
                                switch=
                                    lambda x, p, p_mod: 
                                    p + p_mod
                                    if x > 0
                                    else
                                    p
                                )
result_gen.make_journal_plot(
                             y_data,
                             x0, 
                             validation_plot_path
                             )
result_gen.plot_residual_dist(
                              y_data,
                             validation_residual_plot_path
                             )
test_metrics = result_gen.report_metrics("validation (bic, aic not valid)")
print(test_metrics)
        
    







