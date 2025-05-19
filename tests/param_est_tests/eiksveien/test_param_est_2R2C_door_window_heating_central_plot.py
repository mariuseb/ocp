#from ast import Param

#import sys
import os
#import pathlib
#ocp_path = str(pathlib.Path(os.getcwd()).parent.parent.parent.parent)
#sys.path.append(ocp_path)
#from ocp.param_est import ParameterEstimation
from ocp.estimation import Estimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
#import json
import casadi as ca
from matplotlib.dates import MonthLocator, YearLocator, DayLocator, HourLocator
#import ocp.dae as dae
#import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
#from pprint import pprint
from matplotlib import rc
#from ocp.tests.utils import get_opt_config_path, get_data_path
#import os
#from pandas.plotting import autocorrelation_plot
#from ocp.filters import KalmanBucy
#from analyse import df, df_ene, df_dhw, plot_apt, search_tags, apt_rooms
from read_eiksveien import _plot_apt, get_room_setpoints, \
                                get_heating_central_data, \
                                    plot_heating_central_data, plot_shift, \
                                        append_to_apt_plot, finalize_apt_df, \
                                            finalize_df, generate_door_window_openings
from analyse import df, plot_apt, apt_rooms, \
                        plot_agg_apt, north_facade, \
                            south_facade
                    # df_ene, df_dhw, search_tags
# text:
#rc('mathtext', default='regular')
rc('text', usetex=True)
#import matplotlib
#matplotlib.rcParams.update({'font.size': 18})
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
#import matplotlib.dates as mdates



if __name__ == "__main__":

    cfg_path = os.path.join("configs", "3R2C_door_window_input_air.json")
    sampling_time = "20min"
    dt = int(sampling_time.rstrip("min"))*60
    PLOT_APT = True
    INCLUDE_DOOR_WINDOW = False
    
    start = "2025-02-13 00:00"
    stop = "2025-03-05 00:00"
    
    #start = "2024-12-05 00:00"
    #stop = "2024-12-12 00:00"
    #start = "2024-10-21 06:00"
    #stop = "2024-10-27 18:00"
    
    start_ts = pd.Timestamp(start).tz_localize("Europe/Oslo")
    stop_ts = pd.Timestamp(stop).tz_localize("Europe/Oslo")

    df, hea, room_sps = finalize_df(
        df,
        sampling_time,
        start,
        stop
    )
    
    # this period is relatively predictable:
    _start = pd.Timestamp(start).tz_localize("Europe/Oslo")
    _stop = _start + pd.Timedelta(days=21)
    #_stop = _start + pd.Timedelta(hours=6)
    fig, axes = plot_heating_central_data(
        hea,
        _start,
        _stop
    )
    fig.savefig("heating_central_data_whole.png")
    #fig.tight_layout()
    plt.show()
    
    # this period is relatively predictable:
    __start = "2025-02-14 12:00"
    _start = pd.Timestamp(__start).tz_localize("Europe/Oslo")
    #_stop = _start + pd.Timedelta(days=7)
    _stop = _start + pd.Timedelta(hours=12)
    fig, axes = plot_heating_central_data(
        hea,
        _start,
        _stop
    )
    fig.savefig("heating_central_data_nice.png")
    #fig.tight_layout()
    plt.show()
    
    apt = "H0102"
    #apt = "H0102"
    rooms = apt_rooms[apt]
    # H0103
    areas = {
        "Tbedr": 14.5,
        "Tliv": 20.9,
        "Thall": 10.7,
        #"Tbath": 9.1
    }
    # H0102
    areas = {
        "Tbedr": 10,
        "Tliv": 24,
        "Thall": 7.9,
        #"Tbath": 9.1
    }
    apt_df = plot_apt(df, apt = apt)
    apt_df["Ta"] = df["Tout"]
    apt_df["phi_s"] = df["SolGlob"]
    
    if PLOT_APT:
        plt.show()
        _plot_apt(df, room_sps, apt = apt, include_bath=False)
    else:
        plt.close()
    
    # modularize the name map based on rooms :
    
    name_map = {
        f"""1273_563_{rooms[0]}_RT601""": 'Thall',
        f"""1273_563_{rooms[1]}_RT601""": 'Tliv',
        f"""1273_563_{rooms[2]}_RT601""": 'Tbedr',
        f"""1273_563_{rooms[3]}_RT601""": 'Tbath',
        f"""1273_563_{rooms[3]}_LZ001""": 'phi_h_bath',
        f"""1273_320_002_OE{apt[2:]}.Energy""": 'phi_h_int',
        'Ta': 'Ta',
        'phi_s': 'phi_s'
    }
    
    start = pd.Timestamp("2025-02-13 00:00").tz_localize("Europe/Oslo")
    stop = pd.Timestamp("2025-02-15 00:00").tz_localize("Europe/Oslo")
    
    data, A = finalize_apt_df(
        name_map, 
        areas,
        apt_df,
        hea,
        start_ts,
        stop_ts,
    )    
    
    start = "2025-02-13 00:00"
    stop = "2025-02-15 00:00"

    start_ts = pd.Timestamp(start).tz_localize("Europe/Oslo")
    stop_ts = pd.Timestamp(stop).tz_localize("Europe/Oslo")
    
    y_data = data.loc[
        start_ts:stop_ts
    ]
    N = len(y_data)
    
    # interpolate away nan's, see if good enough:
    y_data = y_data.interpolate()
    y_data["dt_index"] = y_data.index
    y_data["y1"] = y_data["Ti"]
    
    y_data = generate_door_window_openings(
        y_data,
        door_lim=0.35,
        window_lim=0.15
    )
    if INCLUDE_DOOR_WINDOW:
        door_df = pd.read_csv(
            "vinduslufting/H0103_vdoor.csv",
            index_col=0
        )
        door_df.index = pd.to_datetime(
            door_df.index
        ).tz_convert("Europe/Oslo")
        door_df = door_df.loc[
            start_ts:stop_ts
        ]  
        door_df["num_ope"] = door_df["value"].diff(1).fillna(0)
        door_df = door_df.resample(rule="20min").ffill()
        door_df["num_ope"] = door_df["num_ope"].astype(int)
        door_df.iloc[-1] = 0
        y_data["num_ope"] = door_df["num_ope"]
    else:
        y_data["num_ope"] = 0
        
    # check door against temp:
    ax = y_data.Ti.plot(drawstyle="steps-post", color="b")
    ax1 = ax.twinx()
    y_data.door.plot(drawstyle="steps-post", color="k", ax=ax1)
    #y_data.window.plot(drawstyle="steps-post", color="m", ax=ax1)
    #y_data.delta_Ti.plot(drawstyle="steps-post", color="y", ax=ax1)
    y_data.num_ope.plot(drawstyle="steps-post", color="m", ax=ax1)
    plt.show()
    
    y_data.index = range(len(y_data.index))
    y_data.index *= dt
    
    param_guess = {
                    "Rbi": 
                    {
                        "init": 1e-2
                    },
                    "Ci":
                    {
                        "init": 1e6
                    }
    }

    kwargs = {
        "x_nom": 12,
        "x_nom_b": 289.15,
        "u_nom": [12, 12, 1000,1000, 1, 1],
        "u_nom_b ": [289.15, 289.15, 0, 0, 0, 0],
        "y_nom": [12],
        "y_nom_b": [289.15],
        #"slack": True
        "slack": False
    }
    
    priors = {
        "Rie": 0.250/A, # m²K / W 
        "Rfi": 0.250/A, # m²K / W 
        "Rbi": 10*0.250/A, # m²K / W 
        "Rea": 2.250/A, # m²K / W 
        "Ria": 2.250/A, # m²K / W 
        "Ria_d": 2.250/A, # m²K / W 
        "Ria_w": 2.250/A, # m²K / W 
        "Ci": 9.50*3600*A, # Wh / m²K
        "Cfloor": 100*3600*A, # Wh / m²K
        "Ce": 112*3600*A, # Wh / m²K
        "Ai": 0.15*A, # m²
        "Ai_high": 10, # m²
        "alpha_vent_sup": 0.5,
        "alpha_vent_ext": 1e-4,
        "alpha_int": 1,
        "alpha_occ": 1
    }
    
    for name, value in priors.items():
        if param_guess.get(name) is None:
            param_guess[name] = dict()
        param_guess[name]["init"] = value 
        param_guess[name]["lb"] = value*1E-3
        param_guess[name]["ub"] = value*1E3
    
    param_guess["alpha_vent_sup"]["ub"] = 1.0
    param_guess["alpha_vent_ext"]["ub"] = 1.0
    param_guess["alpha_int"]["ub"] = 1.0
    # constrain in particular Th to physically meaningful values:
    x_guess = np.array([
                    y_data.Ti.values.flatten(),
                    y_data.Ti.values.flatten()
                    ])
    lbx = 0.95*x_guess
    ubx = 1.05*x_guess
    
    with Estimation(
                    config=cfg_path,
                    N=N,
                    dt=dt,
                    param_guess=param_guess,
                    truncate_scaling=True,
                    arrival_cost=True,
                    **kwargs
                    ) as param_est:

        Q = ca.DM.eye(2)
        R = ca.DM.eye(1)
        
        lbp = param_est.get_lbp(1e-3)
        ubp = param_est.get_ubp(1e3)
        p0 = param_est.p0
        P0 = np.eye(param_est.n_p + param_est.n_x)*1
        P0[
           param_est.n_p:(param_est.n_p + param_est.n_x),
           param_est.n_p:(param_est.n_p + param_est.n_x)
           ] = 0
        #P0[2,2] = 0
        #P0[5,5] = 0
        
        #lbp = param_est.get_lbp(1e-1)
        #ubp = param_est.get_ubp(1e1)
        p0 = param_est.p0
        sol, params = param_est.solve(
                                      y_data,
                                      p0,
                                      lbp=lbp,
                                      ubp=ubp,
                                      lbx=lbx,
                                      ubx=ubx,
                                      x_guess=x_guess,
                                      covar=ca.veccat(Q, R),
                                      codegen=False,
                                      P0=P0,
                                      x_N=x_guess[-1,-param_est.n_x:]
                                      )

        sol.index = y_data.dt_index
        y_data.index = y_data.dt_index
        fig, axes = plt.subplots(2,1, sharex=True, figsize=(6,4))
        fig.suptitle("Grey-box identification, two days")
        ax = axes[0]
        (sol["Ti"] - 273.15).plot(color="r", linewidth=0.75, drawstyle="steps-post", ax=ax )
        (sol["y1"] - 273.15).plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        #(sol["Tbath"] - 273.15).plot(color="b", ax=ax, linewidth=0.75, drawstyle="steps-post")
        #sol["Ti"].plot(color="k", ax=ax, linewidth=0.75, drawstyle="steps-post")
        ax.legend(["model", "measured"], loc="upper left")
        ax.set_ylabel("Temperature [$^\circ$C]")
        ax = axes[1]
        sol["phi_h"].plot(ax=ax, drawstyle="steps-post", color="r")
        ax.legend(["phi_h"], loc="upper left")
        ax.set_ylabel("Power [W]")
        ax.set_ylim([0,2500])
        ax1 = ax.twinx()
        #sol["phi_h"].plot(ax=ax1, drawstyle="steps-post")
        sol["door"].plot(ax=ax1, drawstyle="steps-post", color="b")
        sol["window"].plot(ax=ax1, color="m", drawstyle="steps-post")
        y_data["num_ope"].plot(ax=ax1, drawstyle="steps-post", color="b")
        ax1.set_ylim([0,1.3])
        ax1.legend(["door", "window"], loc="upper right")
        fig.tight_layout()
        fig.savefig("grey_box_iden_two_days.png")
        plt.close()
    # dump for plots:
    print(params)