from sysid.param_est import ParameterEstimation
import numpy as np
from dae import DAE
from sysid.integrators import RungeKutta4
import json
from casadi import *
import matplotlib.pyplot as plt
import pandas as pd
import pprint



if __name__ == "__main__":

    ############ create simulator block ###############
    with open("param_est_config_ms.json", "r") as file:
        config = json.load(file)
    
    model = config["model"]
    dt = config["dt"]
    N = config["N"]
    n_steps = config["n_steps"]

    # generate some data:
    numpy.random.seed(0)
    U = DM(0.1*numpy.random.random(N))
    x0 = DM([0,0])

    # create a dae
    dae = DAE(model)    
    # integrator:
    RK4 = RungeKutta4(dt, n_steps, dae)

    # true parameters:
    param_truth = DM([5.625e-6,2.3e-4,1,4.69])
    X = RK4.simulate(x0, U, param_truth)
    
    # measurement data
    Y = X[0,:].T
    ###################################################

    df = pd.DataFrame()
    #dt = np.arange(0, config["dt"]*len(df), config["dt"])
    df["u1"] = np.array(U).flatten()
    df["y1"] = np.array(Y).flatten()
    df.index = np.arange(0, config["dt"]*N, config["dt"])

    #df.index = range(len(df))
    #df = df.loc[[ndx for ndx in df.index if ndx % 5 == 0]]
    #df.index = np.arange(0, config["dt"]*len(df)*5, config["dt"]*5)

    #df["i"] = range(len(df))
    #df = df[[ndx for ndx in df.index if df.loc[]]]
    #df = df.iloc[0:2]

    param_guess = DM([5e-6,2e-4,1,5])
    #param_guess = DM([3e-6,0.5e-4,0.5,10])
    #param_guess = DM([5,2,1,5])
    #scale = vertcat(1e-6,1e-4,1,1)
    scale = vertcat(1,1,1,1)

    # estimate the parameters:
    param_est = ParameterEstimation(
                                    "param_est_config_coll.json",
                                    df,
                                    codegen=False,
                                    scale=scale
                                    )

    #pprint.pprint(param_est.nlp_struct)

    result = param_est.solve_ocp(
                                param_guess=param_guess, \
                                )

    #diff = DM(params.values()) - param_truth
    #threshold = DM([0.01]*len(params.values()))

    # check simulation of found parameters:
    # RK4 = RungeKutta4(dt, n_steps, dae)

    params = DM(result["params"].values())*scale
    ol = result["ol"]


    x0_est = DM(ol.iloc[0][["x1", "dx1"]].values)
    # with estimated parameters:
    X_test = RK4.simulate(x0_est, U, params)
    
    # check residual, take out 'x1' from result-dict

    # compare X simulated and Y
    
    #
    l_func = param_est.collocation.ca_l

    l_map = l_func.map(N)
    obj_test_l = l_map(0, X_test, U, 0, Y, repmat(params, 1, N))
    obj_test_lmap = sum(obj_test_l[n] for n in range(N))


    res = pd.DataFrame()
    res["sim"] = np.array(X_test[0, :]).flatten()
    res["true"] = np.array(Y).flatten()

    ax = res.sim.plot()
    res.true.plot(ax=ax)
    ax.legend()
    plt.show()

    #X_optim = ol[[]]s

    optim_coll = ol[["x1", "dx1", "y1", "time"]]
    optim = optim_coll.loc[[ndx for ndx in optim_coll.index if ndx % 28 == 0]]
    optim.index = range(len(optim.index))
    
    residual = (res["sim"] - res["true"])
    obj_test = sum(residual*residual)

    # try to map objective function from ocp over estimation horizon:
    #obj_all_samples = param_est.collocation.ca_l.map(N)

    #x = DM(res.values.T.shape)
    #y = Y
    #t = u = repmat([0], N)
    #z = 0
    #p = repmat([0], (4, N))

    #obj_test_map = sum(np.array(obj_all_samples(0, x, u, z, y, p)))

    # try to construct the residual from function param_est.collocation.ca_l:
    #obj_test_func = 0
    #residual_test_func = pd.Series()

    #for i in range(N):

    #    x = DM(optim.iloc[i][["x1", "dx1"]].values)
    #    y = Y[i]
    #    residual_test_func.loc[i] = float(l_func(0, x, 0, 0, y, 0))

    #obj_test_two = sum(residual_test_func*residual_test_func)

    #x = []
    #y = []

    #for n in range(N):
    #    x.append(param_est.collocation.get_x(n)[0])
    #    y.append(param_est.collocation.get_y(n))

    #J = Function(
    #     "J", \
    #     [vertcat(*param_est.x_c), vertcat(*param_est.y_b), vertcat(*param_est.u_b), param_est.nlp_struct["z"][-4:]], \
    #     [param_est.nlp_struct["J"]], \
    #     ["x", "y", "u", "p"], \
    #     ["J"])

    #J = Function(
    #     "J", \
    #     [vertcat(*param_est.x_b), vertcat(*param_est.y_b), vertcat(*param_est.u_b), param_est.nlp_struct["z"][-4:]], \
    #     [param_est.nlp_struct["J"]], \
    #     ["x", "y", "u", "p"], \
    #     ["J"])

    #x_coll = optim_coll[["x1", "dx1"]][:-1].values
    #x_bound = optim[["x1", "dx1"]][:-1].values

    #obj_test_three = J(X_test.reshape((X_test.shape[0]*X_test.shape[1], 1)), Y)
    #obj_test_three = J(DM(x_bound.flatten()), Y, U, params)
    #obj_test_three = J(X_test[0, :], Y)

    

    #residual = X_test[0, :].T - Y
    #residual = [ol[["x1"]].iloc[0].values - ol[["y1"]].iloc[0].values, ol[["x1"]].iloc[4].values - ol[["y1"]].iloc[4].values]
    #obj_test = dot(residual, residual)

    # find the value of 'J' using ocp-function objs:
    #obj = 0
    #skip = 4
    #K = 3
    #obj += param_est.collocation.ca_l(ol["time"].iloc[0], ol[["x1", "dx1"]].iloc[0], 0, 0, ol[["y1"]].iloc[0], param_guess)
    #obj += param_est.collocation.ca_l(ol["time"].iloc[4], ol[["x1", "dx1"]].iloc[4], 0, 0, ol[["y1"]].iloc[0], param_guess)


    #assert list(np.array(diff < threshold).squeeze()) and list(np.array(diff > -threshold).squeeze())

    #x_frame = pd.DataFrame(data=np.array(X).transpose(),
    #                       columns=states.columns, \
    #                       index=states.index)

    #ax = states["y"].plot(color="r")
    #x_frame["y"].plot(ax=ax, color="b")
    #ax.legend(["Estimated","True"])
    #plt.show()
    

    