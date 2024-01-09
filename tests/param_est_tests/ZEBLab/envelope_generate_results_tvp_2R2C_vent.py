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
from result_generator import ResultGenerator
import pandas as pd
from utils import ZEBData
import matplotlib.pyplot as plt

params = pd.DataFrame(pd.read_csv("results/params_envelope_tvp_2R2C_vent.csv", index_col=0))
# to get estimated x0, read trajectory:
sol = pd.read_csv("results/tvp_in_training_traj_2R2C_vent.csv", index_col=0)
Data = ZEBData("ZEBLab_2years_60m.csv")
y_data = Data.get_dataset(
                          start = pd.Timestamp("2023-11-14 00:00"),
                          stop = pd.Timestamp("2023-11-28 00:00")
                          )
y_data = y_data.bfill()

"""
GOAL: produce all needed results with following object:
"""

result_gen = ResultGenerator(
                             config="configs/2R2C_det_vent_tvp_vent_cond_no_constr.json",
                             params=params,
                             dt=3600
                            )


x0 = sol[result_gen.x].iloc[0]
result_gen.simple_sim_plot(
                           y_data,
                           x0
                           )

p_base = pd.read_csv("results/tvp_params_base_2R2C_vent.csv", index_col=0).values.flatten()
p_mod = pd.read_csv("results/tvp_params_mod_2R2C_vent.csv", index_col=0).values.flatten()
ekf_config = "configs/ekf_configs/2R2C_envelope_EKF.json"

result_gen.simple_one_step_plot(
                                y_data,
                                x0, 
                                p_base=p_base,
                                p_mod=p_mod,
                                ekf_config=ekf_config,
                                cond_series=y_data.V_sup_air,
                                switch=
                                    lambda x, p, p_mod: 
                                    p + p_mod
                                    if x > 10
                                    else
                                    p
                                )

x0 = sol[result_gen.x].iloc[0]
result_gen.make_journal_plot(
                             y_data,
                             x0, 
                             "tvp_journal_plot_training_2R2C_vent"
                             )
result_gen.plot_residual_dist(
                              y_data,
                             "tvp_residual_plot_training_2R2C_vent"
                             )
train_metrics = result_gen.report_metrics("training")
print(train_metrics)

"""
Switch to validation dataset:
"""

y_data = Data.get_dataset(
                          start = pd.Timestamp("2023-11-28 00:00"),
                          stop = pd.Timestamp("2023-12-05 00:00")
                          )

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
                                ekf_config=ekf_config,
                                cond_series=y_data.V_sup_air,
                                switch=
                                    lambda x, p, p_mod: 
                                    p + p_mod
                                    if x > 10
                                    else
                                    p
                                )
result_gen.make_journal_plot(
                             y_data,
                             x0, 
                             "tvp_journal_plot_validation_2R2C_vent"
                             )
result_gen.plot_residual_dist(
                              y_data,
                             "tvp_residual_plot_validation_2R2C_vent"
                             )
test_metrics = result_gen.report_metrics("validation (bic, aic not valid)")
print(test_metrics)
print(sol)
        
    







