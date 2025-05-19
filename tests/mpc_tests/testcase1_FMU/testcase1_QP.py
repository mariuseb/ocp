from ocp.mpc import MPC
import numpy as np
import json
import casadi as ca
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib
matplotlib.use('pdf')
from ocp.boptest_api_old import Boptest
from ocp.tests.utils import Bounds, get_boptest_config_path, get_opt_config_path
from matplotlib import rc
import os
from ocp.functions import functions
from copy import deepcopy
from project1_boptest_gym.examples.test_and_plot import plot_results
from project1_boptest_gym.boptestGymEnv import BoptestGymEnv

# text:
rc('mathtext', default='regular')
# datetime:
#plt.rcParams["date.autoformatter.minute"] = "%Y-%m-%d %H:%M"
import matplotlib.dates as mdates
    

if __name__ == "__main__":
    
    bop_config_base = get_boptest_config_path()
    opt_config_base = get_opt_config_path()
    
    mpc_cfg = os.path.join("configs", "1R1C_MPC.json")
    boptest_cfg = os.path.join(bop_config_base, "ZEBLL_config.json")
    #params = [1E-2,1E6]
    params = [1,1]
    kwargs = {"slack": False}

    mpc = MPC(config=mpc_cfg,
              param_guess=params, 
              functions=functions,
              **deepcopy(kwargs))  # to remove, replace with N
    
    # test solve:
    lb_night = {"Ti": 293.15}
    ub_night = {"Ti": 296.15}
    lb_day = {"Ti": 293.15}
    ub_day = {"Ti": 296.15}
    bounds = Bounds(mpc.dt,
                mpc.dae.x,
                ["Ti"],
                lb_night=lb_night,
                ub_night=ub_night,
                lb_day=lb_day,
                ub_day=ub_day)
    
    lbx, ubx, ref = bounds.get_bounds(0, mpc.N)   
    data = pd.DataFrame(data=[280.15]*13, columns=["Ta"])
    data["phi_s"] = [0]*13
    x0 = np.array([295.15])
    sol, u_0, x0 = mpc.solve(
                            data[0:mpc.N],
                            x0=x0,
                            lbx=lbx,
                            ubx=ubx,
                            params=params,
                            codegen=False
                            )
    
    # high-level interface:
    qp_struct = mpc.nlp
    qp_struct["g"] = qp_struct["g"][0]
    """
    opts = {"error_on_fail": False, 
            "qpsol_options": 
                {
                "sparse": False
                }
            }
    """
    opts = {"error_on_fail": False, 
            }
    qp = ca.qpsol("S", "qpoases", qp_struct, opts)
    qp = ca.nlpsol("S", "sqpmethod", qp_struct, opts)
    # try solving with high-level interface:
    ubx = mpc.ubx
    lbx = mpc.lbx
    ubx[1] = 296.15
    lbx[1] = 293.15
    #lbx[1] = 0
    #ubx[1] = 500
    x0 = mpc.x0
    #x0[1] = 293.15
    r = qp(
           x0=x0,
           lbg=mpc.lbg_current[0],
           ubg=mpc.ubg_current[0],
           lbx=lbx,
           ubx=ubx
           )
    
    ## construct QP 'manually':
    f = mpc.nlp["f"]
    x = mpc.nlp["x"]
    g = mpc.nlp["g"]
    #g = g_[0:mpc.N-1]
    #h = g_[mpc.N-1:]
    h = ca.MX()
    try:
        p = mpc.nlp["p"]
    except:
        p = ca.MX()
    
    gf = ca.gradient(f, x)
    c = ca.substitute(gf, x, ca.MX.zeros(x.sparsity()))
    H = ca.jacobian(gf, x, {"symmetric": True})
    
    r = ca.Function("constant_qp", [x, p], [ca.substitute(f, x, ca.MX.zeros(x.sparsity()))])
    
    b = ca.substitute(g, x, ca.MX.zeros(x.sparsity()))
    A = ca.jacobian(g, x)
    #P = ca.substitute(h, x, ca.MX.zeros(x.sparsity()))
    #Q = ca.jacobian(h, x[0:13])
    
    qp_d = {
        "h": H.sparsity(),
        "a": A.sparsity(), 
        #"p": P.sparsity(),
        #"q": Q.sparsity()
    }

    """
    prob = ca.Function(
                       "qp_prob", 
                       [x, p],
                       [H, c, A, b, Q, P],
                       ["x","p"],
                       ["H","c","A","b","Q","P"]
                       )
    """    
    prob = ca.Function(
                       "qp_prob", 
                       [x, p],
                       [H, c, A, b],
                       ["x","p"],
                       ["H","c","A","b"]
                       )
    
    p_range = mpc.nlp_parser["p"]["range"]
    start, stop = p_range["a"], p_range["b"]
    x0 = mpc.x0
    #x0[start:stop] = [0]*(stop-start)
    res = prob(x=mpc.x0, p=np.nan)
    A = res["A"]
    # set sensitivity dg/dp to zero manually:
    """
    TODO: fix for A multi-dim.
    """
    A[start:stop] = 0
    H = res["H"]
    b = res["b"]
    c = res["c"]
    #g = res["g"]
    lba = mpc.lbg_current
    uba = mpc.ubg_current
    
    qp_low = ca.conic("S", "qpoases", qp_d)
    lbx = mpc.lbx
    ubx = mpc.ubx
    # scale p:
    lbx[start:stop] *= mpc.p_nom
    ubx[start:stop] *= mpc.p_nom
    r = qp_low(
               h=H,
               #g=g,
               #b=b,
               a=A,
               lba=0, 
               uba=0,
               lbx=mpc.lbx,
               ubx=mpc.ubx,
               lam_x0=0,
               lam_a0=0
               )
    print(r)
    
    
    import torch
    import torch.nn as nn
    from torch.autograd import Function, Variable
    from torch.nn.parameter import Parameter
    import torch.nn.functional as F

    from qpth.qp import QPFunction
    
    """
    Try to solve QP using pytorch QPFunction:
    Q --> H
    G --> inequality constraint matrix.
    """
    x0 = torch.tensor(mpc.x0)
    Q = torch.tensor(np.array(H))
    A = torch.tensor(np.array(A))
    b = torch.tensor(np.array(b))
    p = torch.tensor(np.array(c))
    h = torch.tensor([-293.15,293.15,-293.15,296.15])
    G = torch.zeros((4,8))
    G[0,0] = -1
    G[1,0] = 1
    G[1,1] = -1
    G[2,1] = 1
    
    qpsol_torch = QPFunction(verbose=1)(Q, p, G, h, A, b)
    sol_ = qpsol_torch()
    