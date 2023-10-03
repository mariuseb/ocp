#from ast import Param
from ocp.param_est import ParameterEstimation
#from ocp.covar_solve import CovarianceSolver
import numpy as np
import json
import casadi as ca
import ocp.dae as dae
import ocp.integrators as integrators
import pandas as pd
import matplotlib.pyplot as plt
from pprint import pprint
from matplotlib import rc
from ocp.tests.utils import get_opt_config_path, get_data_path
import os
from ocp.frost_function import get_metno_data, get_stations, get_observations
# text:
rc('mathtext', default='regular')

# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates

def read_couple(file1, file2, sep=","):    
    data1 = pd.read_csv(file1, sep=sep, skiprows=[1,2,3], header=0, index_col=0)
    data2 = pd.read_csv(file2, sep=sep, skiprows=[1,2,3], header=0, index_col=0)
    data = pd.merge(data1, data2, left_index=True, right_index=True)
    return data

def prepare_dataset(
                    data, 
                    plot=True,
                    columns=None, 
                    regenerate_weather=False
                    ):
    #weather = pd.read_csv("faavang_longer.csv", index_col=0)
    #weather = pd.read_csv("faavang.csv", index_col=0)
    
    if regenerate_weather:
        weather = pd.read_csv("faavang_longest.csv", index_col=0)
        weather.columns = ["Ta", "phi_s"]
        weather.index = pd.to_datetime(weather.index, utc=True).tz_localize(None)
        
        start = weather.index[0]
        stop = weather.index[-1]
        start = str(start).split(" ")[0]
        stop = str(stop).split(" ")[0]
        #start = str(start).split(" ")[0].replace("2023", "2016")
        #stop = str(stop).split(" ")[0].replace("2023", "2016")
        
        client_id = "791c9c51-f86a-4367-b0ce-bc13717c0f70"
        client_secret = "8769d748-d052-43cb-b3cf-c6ba1331c077"
        #station_id = 'SN25830'
        stations, matches = get_stations(client_id,
                                         start, 
                                         stop,
                                         names=[
                                                "RINGEBU",
                                                "GAUSDAL",
                                                "ÅMOT",
                                                "STOR-ELVDAL"
                                        ])
        # This is EVENSTAD:
        station_id = 'SN8140'
        # get temperature data from MET:  
        avail = get_observations(client_id, station_id, start, stop)
        
        # get temperature:
        voi = 'air_temperature'
        met_data = get_metno_data(station_id, voi, start, stop, client_id)
        met_data.index = pd.to_datetime(met_data.index)
        met_data.index = met_data.index.tz_localize(None)
        
        """
        stations_list = ['SN6840', 'SN13030', 'SN13150']
        avail = get_observations(client_id, stations_list[1], start, stop)
        print(avail)
        """
        
        #weather.index = pd.to_datetime(weather.index)
        #weather = weather.iloc[300:-1]
        #weather = weather.loc["2023-06-30 20:00:00+02:00":-1]
        try:
            data.index = pd.to_datetime(data.index)
        except ValueError:
            data.index = pd.to_datetime(data.index, format="%d.%m.%Y %H:%M")
        #data = data.resample(rule="1H").asfreq()

        weather = weather.resample(rule="5min").asfreq().fillna(method="bfill")
        weather.Ta = met_data.air_temperature   
        # again
        weather = weather.resample(rule="5min").asfreq().fillna(method="bfill")
        # check diff:
        #diff = pd.DataFrame(columns=["Ta", "Ta_faa"])
        #diff["Ta"] = met_data["air_temperature"]
        #diff["Ta_faa"] = weather["Ta"]
        #diff["Ta"] = 
        weather.to_csv("weather.csv")
    else:
        weather = pd.read_csv("weather.csv", index_col=0)
    
    if columns is not None:
        data.columns = columns
        
    #temps_west = data[["CE_36_01_RT43", "CE_36_01_RT41"]]
    temps_west = data[["CE_36_01_RT43"]].mean(axis=1)
    #temps_west = data[["CE_36_01_RT41"]]
    #temps_west = temps_west.mean(axis=1)
    #temps_east = data[["CE_36_01_RT42", "CE_36_01_RT47", "CE_36_01_RT46", "CE_36_01_RT48"]]
    temps_east = data[["CE_36_01_RT42"]].mean(axis=1)
    temps_small = data[["CE_36_01_RT47", "CE_36_01_RT46", "CE_36_01_RT48"]].mean(axis=1)
    #temps_east = data[["CE_36_01_RT42"]]
    
    temps_old = pd.DataFrame(data=[temps_west, temps_east]).T
    temps = pd.DataFrame(data=[temps_west, temps_east, temps_small]).T
    #temps = pd.DataFrame(data=[temps_east]).T
    
    power = data["CE_32_01_OE50Kw"].apply(lambda x: str(x).replace(" ", "")).astype(float)
    #temps = data[["CE_36_01_RT42"]]
    #Ti = temps.mean(axis=1)
    #Ti = temps_west
    outside = weather.Ta
    #ax = temps.mean(axis=1).plot()
    #ax = data["CE_36_01_RT43"].plot(drawstyle="steps-post")
    
    if plot:
        ax = temps_east.plot(drawstyle="steps-post")
        temps_west.plot(ax=ax, drawstyle="steps-post")
        outside.plot(drawstyle="steps-post", ax=ax)
        data["CE_36_01_RT43XS"].plot(color="m", ax=ax, drawstyle="steps-post")
        ax1 = ax.twinx()
        power.plot(ax=ax1, color="k", linestyle="dashed", drawstyle="steps-post")
        plt.show()

    # plot ventilation:
    Tsup_air = data["CE_36_01_RT40"]
    Tret_air = data["CE_36_01_RT50"]
    V_in = data["CE_36_01_RP40L"].apply(lambda x: str(x).replace(" ", "")).astype(float)
    V_out = data["CE_36_01_RP50L"].apply(lambda x: str(x).replace(" ", "")).astype(float)
    # cut-off on 15k
    cut_off = 20000
    #V_in[V_in < cut_off] = 0
    #V_out[V_out < cut_off] = 0
    if plot:
        ax = V_in.plot(drawstyle="steps-post")
        V_out.plot(drawstyle="steps-post")
        ax.legend()
        ax1 = ax.twinx()
        Tsup_air.plot(drawstyle="steps-post", color="k", ax=ax1)
        Tret_air.plot(drawstyle="steps-post", color="r", ax=ax1)
        data["CE_36_01_RT43"].plot(drawstyle="steps-post", color="m", ax=ax1)
        ax1.legend()
        plt.show()
    


    # added power from ventilation:
    #Tdiff_in = data["CE_36_01_RT40"] - data["CE_36_01_RT43"]
    #Tdiff_out = data["CE_36_01_RT50"] - data["CE_36_01_RT43"]
    #Tdiff_in = data["CE_36_01_RT40"] - Ti
    #Tdiff_out = data["CE_36_01_RT50"] - Ti
    rho_air = 1.204 # [kg/m^3]
    #cp_air = 1000 # [J/kg*K]
    #power_in = rho_air*cp_air*(V_in/3600)*Tdiff_in
    #power_out = rho_air*cp_air*(V_out/3600)*Tdiff_out
    m_in = rho_air*(V_in/3600)
    m_out = rho_air*(V_out/3600)

    data = data.fillna(method="bfill")
    remove = data.columns
    y_data = data
    y_data["phi_s"] = weather.phi_s
    y_data["Ti"] = temps.mean(axis=1)
    y_data["Ti_old"] = temps_old.mean(axis=1)
    y_data["m_flow"] = data["3424_CE_ES_320_00_OE51m3"].apply(lambda x: str(x).replace(" ", "")).astype(float).diff()
    #y_data["Ti1"] = temps_west
    y_data["Ta"] = outside
    #y_data["Pvent"] = power_outtemps_east
    y_data["m_in"] = m_in
    y_data["m_out"] = m_out
    y_data["Tsup_air"] = Tsup_air
    y_data["Tret_air"] = Tret_air 
    y_data["Tset"] = y_data["CE_36_01_RT62XS"]
    y_data["valve"] = data["CE_32_01_SB00y"]
    y_data["Tret1"] = y_data["3424_CE_ES_320_00_OE51rt50"]
    y_data["Tsup1"] = y_data["3424_CE_ES_320_00_OE51rt40"]
    y_data["Tsup"] = y_data["CE_32_01_OE50_RT04"]
    y_data["Tret"] = y_data["CE_32_01_OE50_RT05"]
    y_data["phi_h"] = power*1000 # to W
    y_data["y1"] = y_data["Ti"]
    #y_data["y2"] = y_data["Ti1"]
    y_data.drop(columns=remove)
    y_data["dt_index"] = y_data.index
    
    
    return y_data
    

if __name__ == "__main__":
    
    cfg_path = os.path.join("configs", "3R2C_det.json")
    #cfg_path = os.path.join("configs", "3R3C_det.json")
    #cfg_path = os.path.join("configs", "3R2C_det.json")
    #cfg_path = os.path.join("configs", "5R4C_det_vent.json")
    #cfg_path = os.path.join("configs", "5R4C_vent.json")
    data_path = "data"
    #ekf_config = os.path.join(get_opt_config_path(), "2R2C_EKF.json")
    
    """
    data1 = pd.read_csv("evenstad1_jan.csv", skiprows=[1,2,3], header=0, index_col=0)
    data2 = pd.read_csv("evenstad2_jan.csv",  skiprows=[1,2,3], header=0, index_col=0)
    data = pd.merge(data1, data2, left_index=True, right_index=True)
    """
    data1 = read_couple("evenstad1_jan.csv", "evenstad2_jan.csv")
    data2 = read_couple("evenstad1_feb1.csv", "evenstad2_feb1.csv")
    data3 = read_couple("evenstad1_feb2.csv", "evenstad2_feb2.csv")
    data4 = read_couple("evenstad1_apr1.csv", "evenstad2_apr1.csv")
    data5 = read_couple("evenstad1_apr2.csv", "evenstad2_apr2.csv", sep=";")
    
    columns = [col for col in data1.columns if "Unnamed" not in col]
    #data = pd.concat([data1, data2, data3, data4, data5])
    data = pd.concat([data1, data2, data3])
    #data = pd.concat([data2, data3])
    #data = data2
    # do a simple bfill:y_data.phi_h.resample(rule="1H").mean() 
    #data = data.fillna(method="bfill")
    
    temp_cols = [col for col in data.columns if "RT" in col \
        and "OE" not in col \
        and "40" not in col \
        and "50" not in col \
        #and "90" not in col \
        and "XS" not in col
            ]
    
    y_data = prepare_dataset(data1, plot=False, regenerate_weather=False) 
    y_data.index = pd.to_datetime(y_data.index)
    
    # plot simple phi_h vs. Ti:
    phi_h = y_data.phi_h.resample(rule="1H").mean() #.shift(2)
    Ti = y_data.Ti.resample(rule="1H").asfreq()
    ax = Ti.plot(drawstyle="steps-post", color="k")
    ax1 = ax.twinx()
    phi_h.plot(drawstyle="steps-post", ax=ax1, color="r")
    plt.show()
    
    Ta = y_data.Ta.resample(rule="1H").asfreq()
    Tset = y_data.Tset.resample(rule="1H").asfreq()
    valve = y_data.valve.resample(rule="1H").asfreq()
    ax = valve.plot(drawstyle="steps-post", color="k")
    Ta.plot(drawstyle="steps-post", ax=ax, color="g")
    Tset.plot(drawstyle="steps-post", ax=ax, color="m")
    
    ax1 = ax.twinx()
    phi_h.plot(drawstyle="steps-post", ax=ax1, color="r")
    plt.show()
    
    y_data = y_data.resample(rule="1H").asfreq()
    y_data["phi_h"] = phi_h
    
    
    
    #y_data = y_data.loc["2023-01-24 00:10:00":"2023-01-27 00:10:00"]
    
    work_inds = [
                 ndx for ndx in y_data.index \
                 if \
                 ndx.hour in range(7,18) \
                 and \
                 ndx.dayofweek in range(6)
                ]
    #y_data = y_data.loc[work_inds]
      
    ########### Many plots, rearrange to plt.subplots ##############
              
    extra = prepare_dataset(data5, plot=False, columns=columns, regenerate_weather=False)
    
    y_data = y_data[1:]
    #y_data = y_data[24:]
    #y_data = pd.concat([y_data, extra])
    #y_data = y_data.fillna(method="bfill")
    N = len(y_data)
    dt = (y_data.index[1] - y_data.index[0]).seconds
    y_data.index = np.arange(0,N*dt, dt)
    param_guess = ca.DM([#
                2.288896e-04,
                2.933085e-03,
                2.933085e-03,
                1.353292e+07,
                1.613305e+08,
                #1.613305e+07,
                3.137043e+02
                         ])
    #param_guess = ca.DM([1.532625e-03,1.160423e-02,1.328633e+06,6.644898e+06,5.578587e+00])
    #lbp = ca.DM([0.001,0.01,1E5,1E6,1])
    #ubp = ca.DM([0.1,1,1E7,1E8,50])
    len_p = param_guess.shape[0]
    lbp = 0.001*param_guess
    ubp = 1000*param_guess
    
    """
    lbp[len_p-1] = 4200
    ubp[len_p-1] = 4200
    for i in range(2,8):
        lbp[len_p-i] = 0
        ubp[len_p-i] = 1
    lbp[len_p-6] = 0.1
    ubp[len_p-6] = 0.9
    lbp[len_p-7] = 0.1
    ubp[len_p-7] = 0.9
    """
    #param_guess = ca.DM([0.001,0.009,1,1E6,1E7,1])
    #param_est = ParameterEstimation(cfg_path, y_data, param_guess)
    
    #    with ParameterEstimation(config=cfg_path,
    #                             data=y_data,
    #                             param_guess=param_guess) as param_est:
    x_guess = np.array([
                        y_data.Ti.values.flatten(),
                        y_data.Ti.values.flatten() #,
                        #y_data.Ti.values.flatten()
                        #y_data.Ti1.values.flatten(),
                        #y_data.Ti1.values.flatten()
                        ])
    lbx = 0.7*x_guess
    ubx = 1.3*x_guess
    
    with ParameterEstimation(config=cfg_path,
                             N=N,
                             dt=dt,
                             param_guess=param_guess) as param_est:
        
        Q = ca.DM.eye(2)
        #Q[0,0] = 6.55919266e-01
        #Q[1,1] = 4.52496393e-01
        #Q[1,0] = 0.01
        #Q[0,1] = 0.01
        R = ca.DM.eye(1)
        # provide Q, R in solve here:
        # provide lb, ub for p here:
        #grad_f = ca.gradient(param_est.nlp["f"], param_est.nlp["x"])
        #grad_f_f = ca.Function("grad_f", [param_est.nlp["x"]], [grad_f])
        
        """
        from cvxpy with first solution:
        [[6.55919266e-01 5.26466051e-12]
        [5.26466051e-12 4.52496393e-01]]
        
        params after first solve:
        Rie    1.532625e-03
        Rea    1.160423e-02
        Ci     1.328633e+06
        Ce     6.644898e+06
        Ai     5.578587e+00
        
        params after second solve:
        Rie    1.567088e-03
        Rea    1.160390e-02
        Ci     1.337609e+06
        Ce     6.747752e+06
        Ai     5.132032e+00
                        
        Does it change the physical parameters any???    
            
        """
        sol, params, raw_sol = param_est.solve(
                                        y_data,
                                        param_guess,
                                        lbp=lbp,
                                        ubp=ubp,
                                        lbx=lbx,
                                        ubx=ubx,
                                        covar=ca.veccat(Q, R),
                                        return_raw_sol=True
                                        )
        fig, axes = plt.subplots(1,1,sharex=True)
        ax = axes
        sol.index = y_data.dt_index
        sol["Ti"].plot(color="r", ax=ax, drawstyle="steps-post")
        sol["y1"].plot(color="k", ax=ax, drawstyle="steps-post")
        ax.legend()
        plt.show()
        print(params)
        
        # validate with unseen data:
        test = prepare_dataset(data5, columns=columns)
        test = test[1:]
        test.index = y_data.index
        F = param_est.integrator.one_sample.mapaccum(len(test))
        x0 = sol[["Ti", "Te", "Ti1", "Te1"]].iloc[0].values
        #x0 = ca.DM([test.Ti[0], test.Ti[0], test.Ti1[0], test.Ti1[0]])
        #x0 = ca.DM([test.Ti[0], test.Ti[0] - 15, test.Ti1[0], test.Ti1[0] - 15])
        u_data = test[param_est.dae.u].values.T
        p_data = ca.repmat(params.values, 1, len(test))
        #p_data = ca.repmat(param_guess, 1, len(test))
        z_data = ca.repmat(1, 1, len(test))
        res = F(x0=x0, z=z_data, u=u_data, p=p_data, s=0, r=0)
        Ti_res = res["xf"][0, :]
        Ti1_res = res["xf"][2, :]
        test_res = pd.DataFrame(columns=["y1", "y2", "Ti_res", "Ti1_res"])
        test_res["y1"] = test.y1
        #test_r#es["y2"] = test.y2
        test_res["Ti_res"] = np.array(Ti_res).flatten()
        #test_res["Ti1_res"] = np.array(Ti1_res).flatten()
        test_res.plot()
        plt.show()
        print(test_res)
        