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
from validator import Validator
import pandas as pd

"""
What is the name of the config-file?

All other names will be derived frsom it.
"""

cfg_path = "configs/2R2C_det_vent_single_tvp_vent.json"
ekf_path = "configs/2R2C_det_vent_EKF.json"

data = pd.read_csv("first_half_2023.csv", index_col=0)
data.index = pd.to_datetime(data.index)
data["dt_index"] = data.index

train_start = pd.Timestamp("2023-04-01 00:00")
train_stop = pd.Timestamp("2023-04-15 00:00")
val_start = pd.Timestamp("2023-04-15 00:00")
val_stop = pd.Timestamp("2023-04-22 00:00")

validate = Validator(
                     data,
                     cfg_path,
                     ekf_path
                     )

validate.generate_all_plots(
                            train_start,
                            train_stop,
                            val_start,
                            val_stop
                            )
 
 

    







