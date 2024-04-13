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

params = pd.DataFrame(pd.read_csv("results_HVAC/params_HVAC_model_tvp.csv", index_col=0))
# to get estimated x0, read trajectory:
sol = pd.read_csv("results_HVAC/sol_HVAC_model_tvp.csv", index_col=0)
Data = ZEBData("ZEBLab_dec_2022_1m.csv")
y_data = Data.get_dataset(
                          start = pd.Timestamp("2022-12-14 00:00"),
                          stop = pd.Timestamp("2022-12-17 00:00")
                          )
y_data = y_data.bfill()

"""
GOAL: produce all needed results with following object:
"""

result_gen = ResultGenerator(
                             config="configs/Tret_Tsup_Th_Prad_flow_TVP.json",
                             params=params,
                             dt=300,
                             z_guess=[280,0,0]
                            )


x0 = sol[result_gen.x].iloc[0]
result_gen.simple_sim_plot(
                           y_data,
                           x0,
                           HVAC=True
                           )

#p_base = pd.read_csv("results/tvp_params_base_2R2C_vent_no_conns.csv", index_col=0).values.flatten()
#p_mod = pd.read_csv("results/tvp_params_mod_2R2C_vent_no_conns.csv", index_col=0).values.flatten()
ekf_config = "configs/ekf_configs/6R3C_hvac_EKF.json"

result_gen.simple_one_step_plot(
                                y_data,
                                x0, 
                                p_base=params,
                                #p_mod=p_mod, 
                                ekf_config=ekf_config
                                )

x0 = sol[result_gen.x].iloc[0]
result_gen.make_journal_plot(
                             y_data,
                             x0, 
                             "tvp_journal_plot_training_2R2C_vent_no_conns"
                             )
result_gen.plot_residual_dist(
                              y_data,
                             "tvp_residual_plot_training_2R2C_vent_no_conns"
                             )
train_metrics = result_gen.report_metrics("training")
print(train_metrics)

"""
Switch to validation dataset:
"""

y_data = Data.get_dataset(
                          start = pd.Timestamp("2022-12-17 00:00"),
                          stop = pd.Timestamp("2022-12-20 00:00")
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
                                p_base=params,
                                #p_mod=p_mod,
                                ekf_config=ekf_config
                                )

result_gen.make_journal_plot(
                             y_data,
                             x0, 
                             "tvp_journal_plot_validation_2R2C_vent_no_conns"
                             )
result_gen.plot_residual_dist(
                              y_data,
                             "tvp_residual_plot_validation_2R2C_vent_no_conns"
                             )
test_metrics = result_gen.report_metrics("validation (bic, aic not valid)")
print(test_metrics)
print(sol)
        
    







