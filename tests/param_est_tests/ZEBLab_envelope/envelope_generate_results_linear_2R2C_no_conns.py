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

params = pd.DataFrame(pd.read_csv("results/params_envelope_2R2C_linear_no_conns.csv", index_col=0))
# to get estimated x0, read trajectory:
sol = pd.read_csv("results/linear_in_training_traj_2R2C_no_conns.csv", index_col=0)
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
                             #config="configs/3R3C_det_vent_207_cond_weekend_full_tvp.json",
                             config="configs/2R2C_det_vent_no_conns.json",
                             params=params,
                             dt=3600
                            )


x0 = sol[result_gen.x].iloc[0]
result_gen.simple_sim_plot(
                           y_data,
                           x0
                           )

#p_base = pd.read_csv("results/tvp_params_base.csv", index_col=0).values.flatten()
p_base = params
#p_mod = pd.read_csv("results/tvp_params_mod.csv", index_col=0).values.flatten()
ekf_config = "configs/ekf_configs/2R2C_envelope_EKF_no_conns.json"

x0 = sol[result_gen.x].iloc[0]
result_gen.simple_one_step_plot(
                                y_data,
                                x0, 
                                p_base=p_base,
                                ekf_config=ekf_config
                                )

result_gen.make_journal_plot(
                             y_data,
                             x0, 
                             "linear_2R2C_journal_plot_training_no_conns"
                             )
result_gen.plot_residual_dist(
                              y_data,
                             "linear_2R2C_residual_plot_training_no_conns"
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
                                ekf_config=ekf_config
                                )


result_gen.make_journal_plot(
                             y_data,
                             x0, 
                             "linear_2R2C_journal_plot_validation_no_conns"
                             )
result_gen.plot_residual_dist(
                              y_data,
                             "linear_2R2C_residual_plot_validation_no_conns"
                             )
test_metrics = result_gen.report_metrics("validation")
print(test_metrics)



"""
res, y_data, filtered = result_gen.simulate_one_step(
                                                    x0,
                                                    y_data,
                                                    ekf_config=ekf_config,
                                                    tvp=True,
                                                    switch=
                                                        lambda x, p, p_mod: 
                                                        p
                                                        if x.dayofweek not in (5,6) 
                                                        else
                                                        p + p_mod,
                                                    p_base=p_base,
                                                    p_mod=p_mod
                                                    # pass switch as anonymous func
                                                    )
"""



print(sol)
        
    







