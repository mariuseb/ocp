#from argparse import ArgumentError
import casadi as ca
from ocp.mpc import MPC
import numpy as np
from ocp.shooting import Collocation
from ocp.q_learning import Qlearning
import cvxpy as cvx
import os
import pandas as pd

class ParametricMPC(MPC):
    """
    Special MPC formulation tailored for
    RL learning.
    """
    def __init__(self, *args, **kwargs):
        self.model_params_in_policy = kwargs.pop("model_params_in_policy", False)
        self.objective_from_scratch = kwargs.pop("objective_from_scratch", True)
        super().__init__(**kwargs)
        self.obs_dim = self.n_x
        self.action_dim = self.n_u
        """
        Parameters of MPC policy:
        """
        #self.P = ca.MX.sym("P")
        if self.objective_from_scratch:
            self.build_objective()
        self.add_terminal_cost()
        self.add_initial_cost()
        self.add_V0()
        self.add_linear_objective_term()
        # empty:
        #self.f = ca.MX()
        self.add_dynamics_bias()
        # add model params as last part to P:
           
        """
        Own function:
        """
        
        self.sigma = ca.MX.sym("sigma", self.obs_dim, self.N-1)
        self.nlp["x"] = ca.vertcat(self.nlp["x"], self.sigma.T)
        dim = self.sigma.shape[0]*self.sigma.shape[1]
        self.nlp_parser.vars["sl"] = {
                            "range":
                                    {
                                        "a":
                                        self.nlp_parser["r"]["range"]["b"],
                                        "b": 
                                        self.nlp_parser["r"]["range"]["b"] + \
                                            dim
                                    },
                            "dim": dim
                            }
        self.n_sl = self.n_x
        self.slack_names = list(map(lambda x: "sigma_" + str(x+1), range(self.n_sl)))
        """
        """
        self.add_slack_to_objective()
        self.split_h_g()
        """
        TODO:
            - will encounter processes that are partially observable.
            
        Find a good way to handle this.
        """
        #self.nPf = self.obs_dim + 2 * self.action_dim
        self.nPf = self.obs_dim + 2*self.action_dim # one epsilon per action
        self.Pf = ca.MX.sym("Pf", self.nPf)  # [Initial state x0, action a, eps] ("fixed" params)
        # consider bounds on x, u  as fixed params?
        self.nPbounds = self.n_x*2*self.N + self.n_u*2*(self.N-1) # two-sided
        #self.Pbounds = ca.MX.sym("Pbounds", self.nPbounds) # -> instantiate later
        self.nP = self.P.shape[0]
        # slack var:
    
    def build_objective(self):
        J = 0
        for n in range(self.N-1):
            u_k = self.get_var_at_stage("u", n)
            J += (self.gamma**n)*u_k.T@u_k
        self.nlp["f"] = (1/2)*J
            
    
    def add_slack_to_objective(self):
        """
        Add slack terms to objective function.
        """
        #R = ca.MX.sym("R", self.n_x, self.n_x)
        
        w = 1e0 #*self.sl_nom # should be part of config file 
        for n in range(self.N-1):
            sl = self.get_var_at_stage("sl", n)
            self.nlp["f"] += sl@w@sl.T
           
    def get_p_equals_p_constraint(self):
        """
        Add model params to policy.
        """
        mxs = []
        p_names = self.dae.dae.p()
        for name in p_names:
            mx = self.dae.dae.var(name)
            mxs.append(mx)
        p_orig = ca.vertcat(*mxs) # original model params
        
        p = ca.MX.sym("p", self.n_p) # new parameter
        #self.P = ca.vertcat(self.P, p)
        #self.nlp.g.append(p_orig - p)
        return p, p_orig - p/self.p_nom
        #return p, p_orig - p
        
    def split_h_g(self):
        """
        Determine which constraints belong to
        h, g respectively.
        
        Important for calculating sensitivities
        """
        self.g = []
        self.hu0 = []
        self.hu = []
        self.hx = []
        self.hs = []
        
        for i, (lb, ub) in enumerate(zip(self.lbg, self.ubg)):
            """
            Does the below cover all cases??
            """
            ndx = ca.Slice(i,i+self.n_x)
            if lb != ub:
                self.h.append(self.nlp["g"][ndx])
            else:
                self.g.append(self.nlp["g"][ndx])
        """
        for i, (lb, ub) in enumerate(zip(self.lbx, self.ubx)):
            if lb != ub and lb != -np.inf and ub != np.inf:
                self.h.append(self.x[i])
        """
        # go through nlp-x for simple box constraints 
        # on x, u:
        """
        x_info = self.nlp_parser.vars["x"]
        start, stop = x_info["range"]["a"], x_info["range"]["b"]
        ndx = ca.Slice(start, stop)
        self.hx.append(self.nlp["x"][ndx])
        
        u_info = self.nlp_parser.vars["u"]
        start, stop = u_info["range"]["a"], u_info["range"]["a"] + self.n_u
        ndx = ca.Slice(start, stop)
        self.hu0.append(self.nlp["x"][ndx])
        
        start = stop
        stop = u_info["range"]["b"]
        ndx = ca.Slice(start, stop)
        self.hu.append(self.nlp["x"][ndx])
        """
        
        # define parameters as placeholders for 
        # numerical values on x,u bounds
        if isinstance(self.method, Collocation):
            n_x_skip = self.method.d + 1
        else:
            n_x_skip = 1
            
        x_info = self.nlp_parser.vars["x"]
        p_lbx = ca.MX.sym("p_lbx", self.n_x, self.N)
        p_ubx = ca.MX.sym("p_ubx", self.n_x, self.N)
        
        x_below = ca.MX.sym("x_below", self.n_x)
        x_above = ca.MX.sym("x_above", self.n_x)
        
        """
        First timestep,
        avoid bound modification.
        
        x_0 is given by estimation/observation only,
        i.e. no slack on first state.
        n = 0
        start = n*n_x_skip
        stop = n*n_x_skip + 1
        x = self.get_var_at_stage("x", 0)
        self.hx.append(p_lbx[:, start:stop] - x)
        self.hx.append(x - p_ubx[:, start:stop])
        """
        sl_nom = self.sl_nom
        
        for n in range(1, self.N):
            start = n*n_x_skip
            stop = n*n_x_skip + 1
            x = self.get_var_at_stage("x", n)
            self.hx.append(p_lbx[:, start:stop] + x_below - x - self.sigma[:, n-1]/sl_nom)
            self.hx.append(x - p_ubx[:, start:stop] + x_above - self.sigma[:, n-1]/sl_nom)
            self.hs.append(-self.sigma[:, n-1])
            
        u_info = self.nlp_parser.vars["u"]
        p_lbu = ca.MX.sym("p_lbu", self.n_u, self.N-1)
        p_ubu = ca.MX.sym("p_ubu", self.n_u, self.N-1)
        
        start, stop = 0, 1
        u0 = self.get_var_at_stage("u", 0)
        self.hu0.append(p_lbu[:, start:stop] - u0)
        self.hu0.append(u0 - p_ubu[:, start:stop])
        
        for n in range(1, self.N-1):
            start = n
            stop = n + 1
            u = self.get_var_at_stage("u", n)
            self.hu.append(p_lbu[:, start:stop] - u)
            self.hu.append(u - p_ubu[:, start:stop])
        
        # flat parameter vector:    
        self.Pbounds = ca.veccat(p_lbx, p_ubx, p_lbu, p_ubu)
        
        #self.P = ca.vertcat(self.P) #, x_below, x_above)
        self.P = ca.vertcat(self.P, x_below, x_above)
        
        if self.model_params_in_policy: 
            p, p_constr = self.get_p_equals_p_constraint()
            self.P = ca.vertcat(self.P, p)
            self.g.append(p_constr)

            
    def add_terminal_cost(self):
        """
        Add parametric terminal cost on state
        to nlp objective.
        """
        x_info = self.nlp_parser["x"]
        stop = x_info["range"]["b"]
        start = stop - self.n_x
        x_N = self.nlp["x"][start:stop]
        self.W = W = ca.MX.sym("W", self.n_x, self.n_x)
        self.P = W
        self.nlp["f"] += (1/2)*(self.gamma**self.N)*x_N@W@x_N.T

    def add_initial_cost(self):
        """
        Add parametric initial cost on state
        to nlp objective.
        """
        x_info = self.nlp_parser["x"]
        start = x_info["range"]["a"]
        stop = start + self.n_x
        x_0 = self.nlp["x"][start:stop]
        self.S = S = ca.MX.sym("S", self.n_x, self.n_x)
        self.P = ca.vertcat(self.P, S)
        self.nlp["f"] += (1/2)*(self.gamma**self.N)*x_0@S@x_0.T
        
    def add_linear_objective_term(self):
        """
        Add parametric terminal cost
        to nlp objective.
        """
        #J = self.nlp["f"]
        M = self.N-1
        n_xu = self.n_u + self.n_x
        self.f = f = ca.MX.sym("f", n_xu)
        for n in range(M):
            xn = self.get_var_at_stage("x", n)
            un = self.get_var_at_stage("u", n)
            self.nlp["f"] += (self.gamma**n)*f.T@ca.vertcat(xn, un)
        # extend parameter MX:
        self.P = ca.vertcat(self.P, f)
        
        
    def add_dynamics_bias(self):
        """
        Add linear bias term in
        the dynamic model constraints.
        """
        #x_info = self.nlp_parser["x"]
        g = self.nlp_parser.vars["x"]["shooting_gaps"]
        n_cols, n_rows = g.shape
        self.b = b = ca.MX.sym("b", n_rows) #, n_rows)
        # modify g by adding b:
        self.nlp_parser.vars["x"]["shooting_gaps"] = g + b
        new_shooting_gaps = g + b
        """
        TODO: fix below for algebraic, measurement equations:
        """
        if self.method == "collocation":
            self.nlp["g"][self.strategy.d::(self.strategy.d+1)] = new_shooting_gaps
        else:
            self.nlp["g"] = new_shooting_gaps
        # extend parameter MX:
        self.P = ca.vertcat(self.P, b)
        
    def add_V0(self):
        """
        Add V0, 'bias' to objective function.
        """
        self.V0 = V0 = ca.MX.sym("V0", 1)
        self.nlp["f"] += V0
        self.P = ca.vertcat(self.P, V0)
         
    def add_g_bias(self): 
        """
        Add dynamic bias (state-dependant?) to
        discretized model dynamics
        """
        pass
    
    def objective_cost(self):
        return self.nlp["f"]
    
    def equality_constraints(self):
        #return ca.vertcat(*self.g)
        return self.g
    
    def inequality_constraints(self):
        #return ca.vertcat(*self.hu0), ca.vertcat(*self.hu), ca.vertcat(*self.hx), ca.MX()
        #return self.hu0, self.hu, self.hx, []
        return self.hu0, self.hu, self.hx, self.hs


class MPCFormulation_ex(ParametricMPC):
    #def __init__(self, model, opt_params, gamma) -> None:
    def __init__(self, gamma, **kwargs) -> None:
        self.gamma = gamma
        self.etau = 1e-6
        # instantiate parents:
        super().__init__(**kwargs)
        # Define the NLP solver for the optimization problem
        self.define_nlp_solver()
        # Define optimization problem for Q function (u0 fixed)
        self.define_Q_nlp_solver()
        
    def define_nlp_solver(self):
        """
        Define the NLP solver for the optimization problem.
        NLP formulation:
        
        V(s) = min_{x,u,sigma} J(x,u,sigma)
            s.t. g(x,u,sigma) = 0
                 hu0(u0) <= 0
                 hu(u) <= 0
                 hx(x,sigma) <= 0
                 hs(sigma) <= 0
        """
        # Objective cost
        J = self.objective_cost()

        # Dynamics equality constraints
        g = self.equality_constraints()
        # Add fixed x0:
        x0 = self.get_var_at_stage("x", 0)
        state = self.Pf[:self.obs_dim]
        g.append(x0 - state)

        # Inequality constraints
        """
        For now, simple bounds.
        
        TODO: constraints on x back to 'g'
        """
        hu0, hu, hx, hs = self.inequality_constraints()

        # NLP Problem for value function and policy approximation
        G = ca.vertcat(*g)
        Hu = ca.vertcat(*hu0, *hu)
        Hx = ca.vertcat(*hx)
        Hs = ca.vertcat(*hs)
        G_vca = ca.vertcat(*g, *hu0, *hu, *hx, *hs)
        lbg = [0] * G.shape[0] + [-np.inf] * (Hu.shape[0] + Hx.shape[0] + Hs.shape[0])
        ubg = [0] * G.shape[0] + [0] * (Hu.shape[0] + Hx.shape[0] + Hs.shape[0])
        self.lbg_vcsd = ca.vertcat(*lbg)
        self.ubg_vcsd = ca.vertcat(*ubg)

        # NLP Problem for value function and policy approximation
        self.opts_setting = {
            "ipopt.max_iter": 5000,
            "ipopt.print_level": 5,
            #"ipopt.sb": True,
            "print_time": 0,
            "bound_consistency": True,
            "clip_inactive_lam": True,
            "ipopt.linear_solver": "ma57",
            "calc_lam_x": True,
            "calc_lam_p": False,
            #"ipopt.mu_target": self.etau,
            #"ipopt.mu_init": self.etau,
            #"ipopt.acceptable_tol": 1e-8,
            #"ipopt.acceptable_obj_change_tol": 1e-8,
        }
        
        self.vnlp_prob = vnlp_prob = {
            "f": J,
            "x": self.nlp["x"],
            "p": ca.vertcat(self.Pf, self.P, self.Pbounds),
            "g": G_vca
        }
        self.nlp_solver = ca.nlpsol(
                                    "vsolver",
                                    "ipopt",
                                    vnlp_prob,
                                    self.opts_setting
                                    )
        (
            self.Rfun,
            self.dPi,
            self.dLagV,
            self.dRdz,
            self.dRdp,
        ) = self.build_sensitivities(J, G, Hu, Hx, Hs)

    def define_Q_nlp_solver(self):
        """
        Define the NLP solver for the optimization problem.
        NLP formulation:
        
        Q(s,a) = min_{x,u,sigma} J(x,u,sigma)
            s.t. g(x,u,sigma) = 0
                 u0 = a
                 hu(u) <= 0
                 hx(x,sigma) <= 0
                 hs(sigma) <= 0
        """
        # Objective cost
        J = self.objective_cost()

        # Equality constraints
        g = self.equality_constraints()

        # Inequality constraints
        _, hu, hx, hs = self.inequality_constraints()

        # NLP problem for Q function approximation
        x0 = self.get_var_at_stage("x", 0)
        state = self.Pf[:self.obs_dim]
        g.append(x0 - state)
        # Implement initial action constraint
        u0 = self.get_var_at_stage("u", 0)
        action = self.Pf[self.obs_dim:(self.obs_dim + self.action_dim)]
        g.append(u0 - action)

        G = ca.vertcat(*g)
        Hu = ca.vertcat(*hu)  # No box constraint on u0
        Hx = ca.vertcat(*hx)
        Hs = ca.vertcat(*hs)
        G_qca = ca.vertcat(*g, *hu, *hx, *hs)
        lbg = [0] * G.shape[0] + [-np.inf] * (Hu.shape[0] + Hx.shape[0] + Hs.shape[0])
        ubg = [0] * G.shape[0] + [0] * (Hu.shape[0] + Hx.shape[0] + Hs.shape[0])
        self.lbg_qcsd = ca.vertcat(*lbg)
        self.ubg_qcsd = ca.vertcat(*ubg)        
        # define the Q-nlp problem and the corresponding solver
        """
        self.qsolver = ca.nlpsol(
                                 "q_solver",
                                 "sqpmethod", 
                                 qnlp_prob,
                                 self.q_opts
                                 )
        self.q_opts = dict(
            qpsol='qrqp',
            #qpsol='qrqp',
            qpsol_options=dict(print_iter=False,error_on_fail=False), 
            print_time=True,
            #regularize=True,
            min_step_size=1E-10
            )
        """
        
        self.q_opts = {
            "ipopt.max_iter": 100,
            "ipopt.print_level": 5,
            "print_time": 0,
            #"ipopt.sb": True,
            "bound_consistency": True,
            "clip_inactive_lam": True,
            "ipopt.linear_solver": "ma57",
            "calc_lam_x": True,
            "calc_lam_p": False,
            #"ipopt.mu_target": self.etau,
            #"ipopt.mu_init": self.etau,
            #"ipopt.acceptable_tol": 1e-8,
            #"ipopt.acceptable_obj_change_tol": 1e-8,
        }
          
        qnlp_prob = {
            "f": J,
            "x": self.nlp["x"],
            "p": ca.vertcat(self.Pf, self.P, self.Pbounds),
            "g": G_qca
        }
        
        self.qsolver = ca.nlpsol(
                                 "q_solver",
                                 "ipopt", 
                                 qnlp_prob,
                                 self.q_opts
                                 )
        _, _, self.dLagQ, _, _ = self.build_sensitivities(J, G, Hu, Hx, Hs)
       
    @property
    def Opt_Vars(self): 
        return self.nlp["x"]
        
    def build_sensitivities(self, J, G, Hu, Hx, Hs):
        """
        Computes the sensitivity functions for given cost and constraints in
        J, G, Hu, Hx, Hs

        Parameters
        ----------
        J : Cost function

        G : Equality constraints

        Hu : Input Constraints

        Hx : State Constraints

        Hs : Slack constraints


        Returns
        -------
        Rfun : Casadi function for KKT matrix
        dPi : Casadi function for nable_pi
        dLagfunc : Casadi function for nabla_lagrange
        f_dRdz : Casadi function for derivative of KKT matrix w.r.t. primal-dual variables
        f_dRdp : Casadi function for derivative of KKT matrix w.r.t. parameters

        """
        # Vector of Lagrange multipliers for dynamics equality constraints
        lamb = ca.MX.sym("lambda", G.shape[0])

        # Vector of Lagrange multipliers for input inequality constraints
        mu_u = ca.MX.sym("muu", Hu.shape[0])

        # Vector of Lagrange multipliers for state inequality constraints
        mu_x = ca.MX.sym("mux", Hx.shape[0])

        # Vector of Lagrange multipliers for slack inequality constraints
        mu_s = ca.MX.sym("mus", Hs.shape[0])

        # Vector of Lagrange multipliers
        mult = ca.vertcat(lamb, mu_u, mu_x, mu_s)

        # Lagrange function
        Lag = (
            J + ca.transpose(lamb) @ G + ca.transpose(mu_u) @ Hu + ca.transpose(mu_x) @ Hx + ca.transpose(mu_s) @ Hs
        )
        Lagfunc = ca.Function("Lag", [self.Opt_Vars, mult, self.Pf, self.P, self.Pbounds], [Lag])

        # Jacobian of the Lagrangian with respect to the primal decision variables and fixed + learnable parameters
        dLdw = ca.jacobian(Lag, self.Opt_Vars)
        dLdP = ca.jacobian(Lag, self.P)
        f_dLdP = ca.Function("dLdP", [self.Opt_Vars, mult, self.Pf, self.P, self.Pbounds], [dLdP])

        # Build KKT matrix expression
        R_kkt = ca.vertcat(
            ca.transpose(dLdw),
            G,
            mu_u * Hu + self.etau,
            mu_x * Hx + self.etau,
            mu_s * Hs + self.etau,
        )

        # z contains all variables of the lagrangian
        z = ca.vertcat(self.Opt_Vars, lamb, mu_u, mu_x, mu_s)

        # KKT matrix function
        Rfun = ca.Function("Rfun", [z, self.Pf, self.P, self.Pbounds], [R_kkt])

        # Sensitivity of the KKT matrix function with respect to the solution and learnable parameters
        dR_sensfunc = Rfun.factory("dR", ["i0", "i1", "i2"], ["jac:o0:i0", "jac:o0:i2"])

        # Sensitivity expression of the KKT matrix with respect to the solution
        [dRdz, dRdP] = dR_sensfunc(z, self.Pf, self.P)

        # Generate sensitivity of the optimal solution
        dzdP = -ca.inv(dRdz)[: self.action_dim, :] @ dRdP

        # Sensitivity function for the policy
        dPi = ca.Function("dPi", [z, self.Pf, self.P], [dzdP])

        # Sensitivity function of the KKT matrix with respect to the solution
        f_dRdz = ca.Function("dRdz", [z, self.Pf, self.P], [dRdz])

        # Sensitivity function of the KKT matrix with respect to the parameters
        f_dRdp = ca.Function("dRdP", [z, self.Pf, self.P], [dRdP])
        
        return Rfun, dPi, f_dLdP, f_dRdz, f_dRdp 
        
        
class MPCfunapprox(MPCFormulation_ex):
    def __init__(self, agent_params, seed=1, **kwargs):
        super().__init__(agent_params["gamma"], **kwargs)
        # Parameters
        self.learning_params = agent_params.pop("learning_params")
        self.lr = self.learning_params["lr"]
        self.tr = self.learning_params["tr"]
        self._parse_agent_params(**agent_params)
    
        self.dP_df = pd.DataFrame(columns=list(
                                map(
                                    lambda x: "theta" + str(x), 
                                    range(self.P.shape[0])
                                    )
                                    )
                                  )
        # Actor initilizaiton
        #super().__init__(self.model, self.opt_params, self.gamma)

        # Seeded random number generators
        self.rng1 = np.random.default_rng(seed)
        self.rng2 = np.random.default_rng(seed)

        # Parameter values
        #self.pf_val = 0.1 * self.rng1.random((self.nPf, 1))
        #self.p_val = 0.1 * self.rng1.random((self.nP, 1))

        """
        if "cost_wt" in self.opt_params:
            self.p_val[self.iP_cost[0] : self.iP_cost[1]] = self.cost_model.cost_param_init(self.opt_params["cost_wt"])
        self.pf_val[self.iP_cost[1] :], self.p_val[self.iP_cost[1] :] = self.model.model_param_init()
        """
        
         # initiate the learning module
        self.learning_module = Qlearning(self, self.learning_params, seed)
        
        # RL update formulation
        #self.constraint_param_opt(self.learning_module.lr, self.learning_module.tr) 
        
    def reset(self, obs):
        obs = self.model.get_obs(obs)
        action = np.array(self.action_dim)
        self.X0 = self.model.get_initial_guess(obs, action, self.N)

    """
    For warm-starting the NLP-solution:
    """
    def update_X0(self, opt_var):
        # "warm starting" for udpating the initial guess given to the solver
        # based on the last solution
        x0 = opt_var.copy()
        N, an, sn = self.N, self.action_dim, self.obs_dim
        at, st = an * N, sn * N

        x0[: an * (N - 1)] = opt_var[an:at]  # action init
        x0[at : at + sn * (N - 1)] = opt_var[at + sn : at + st]  # state/obs init
        x0[at + st : at + st + sn * (N - 1)] = opt_var[at + st + sn : at + 2 * st]  # sigma init
        return x0    

    def _parse_agent_params(self, eps, opt_params, gamma):
        self.eps = eps
        self.opt_params = opt_params
        self.gamma = gamma
        #self.learning_params = learning_params
        
    def codegen_solvers(self):
        """
        Code-generate nlp solver, Q-solver.
        """
        nlp_c_code_name = self.get_c_code_name(self.config)
        Q_c_code_name = nlp_c_code_name.replace("MPC", "Q")
        # generate c code for nlp solver:
        so_filename_nlp = self.pregenerate_c_code(
                                                nlp_c_code_name, 
                                                solver=self.nlp_solver
                                                )
        if not os.path.exists(so_filename_nlp):
            self.compile_c_code(
                                nlp_c_code_name, 
                                so_filename_nlp
                                )
        self.nlp_solver = self.init_codegen_solver(
                                                    so_filename_nlp, 
                                                    **self.opts_setting
                                                )
        so_filename_q = self.pregenerate_c_code(
                                                Q_c_code_name, 
                                                solver=self.qsolver
                                                )
        if not os.path.exists(so_filename_q):
            self.compile_c_code(
                                Q_c_code_name,                                
                                so_filename_q
                                )
        self.qsolver = self.init_codegen_solver(
                                                so_filename_q, 
                                                #solver="sqpmethod",
                                                **self.q_opts
                                                )
    
        
        
        
    def prepare_forward(self,
                data,
                prev_sol=None,
                x0=None,
                lbx=None,
                ubx=None,
                lbu=None,
                ubu=None,
                model_params=None, 
                policy_params=None
                ):
        self.data = data
        # sets disturbances:
        
        if self.model_params_in_policy:
            model_params = policy_params[-self.n_p:]
            #lbp = 1e-6*model_params
            #ubp = 1e6*model_params
            lbp = model_params
            ubp = model_params
        else:
            lbp = model_params
            ubp = model_params
            
        #if prev_sol is not None:
        #    self.x0 = prev_sol["x"]
        self.separate_data(
                          data,
                          #lbp=model_params,
                          #ubp=model_params,
                          lbp=lbp,
                          ubp=ubp,
                          p_guess=model_params
                          )
        
        """
        Scaling needs to be handled also
        for multiple states, inputs.
        
        Idea: set expanded scalings
        persistently in self.separate_data
        """
        self.set_bounds(skip_u=True, slack=True)
        
        """
        self.add_path_constraints(
                                x0=(x0 - self.x_nom_b)/self.x_nom,
                                lbx=(lbx - self.x_nom_b)/self.x_nom,
                                ubx=(ubx - self.x_nom_b)/self.x_nom,
                                )
        Parameter handling below:
        """
        
        lbx = (np.append(x0, lbx).flatten() - self.x_nom_b)/self.x_nom
        ubx = (np.append(x0, ubx).flatten() - self.x_nom_b)/self.x_nom
        
        if lbu is None:
            #lbu = self.bounds["u"]["lb"][:-1,:].flatten() 
            lbu = self.bounds["u"]["lb"].flatten() 
        if ubu is None:
            #ubu = self.bounds["u"]["ub"][:-1,:].flatten() 
            ubu = self.bounds["u"]["ub"].flatten() 
        
        
        self.p_bounds = p_bounds = np.concatenate([lbx, ubx, lbu, ubu])
        # x0 again:
        x0 = (x0 - self.x_nom_b)/self.x_nom
        # fixed parameters:
        self.pf_val = pf = np.concatenate([x0, np.array([0]), np.array([self.eps])])
        # policy parameters:
        self.pp_val = policy_params
        # concat:
        self.p_val = np.concatenate([pf, policy_params, p_bounds])
        # fix this, but usable for now to set bounds on r:
     
        #self.set_bounds()
        
    def prepare_warm_solve(
                        self,
                        data,
                        raw_sol,
                        model_params=None
                        ):
        self.data = data
        # sets disturbances:
        self.separate_data(
                          data,
                          lbp=model_params,
                          ubp=model_params,
                          p_guess=model_params
                          )
        #self.set_bounds(skip_u=True, slack=True)
        # need this for disturbances:
        self.set_bounds(skip_u=True, slack=True)
        self.x0 = self.get_warm_sol_x_u(raw_sol["x"])
        
    def get_warm_sol_x_u(self, x0):
        """
        Warm-up nlp x0 on x, u.
        """
        x_info = self.nlp_parser["x"]
        u_info = self.nlp_parser["u"]
        x_start, x_stop = x_info["range"]["a"], x_info["range"]["b"]
        u_start, u_stop = u_info["range"]["a"], u_info["range"]["b"]
        # fetch prev solution:
        x0_prev = self.x0_prev
        # warm start:
        x0[x_start:x_stop] = x0_prev[x_start:x_stop]
        x0[u_start:u_stop] = x0_prev[u_start:u_stop]
        return x0
        
    def act_forward(self, obs):
        """
            Evaluate the policy at the current state
        """
        # Forward policy function evaluation for argmin action
        # Setting Solver params
        #obs = self.model.get_obs(state)
        #pf_val = self.pf_val
        #pf_val[: self.obs_dim, :] = obs[:, None]
        #pf_val[: self.obs_dim] = obs
        #p_val = self.p_val
        #p = np.concatenate([pf_val, p_val])[:, 0]
        #X0 = self.X0

        # run the nlp solver
        
        """
        Warm-start only x, u 
        """
        x0 = self.x0
        try:
            x0 = self.get_warm_sol_x_u(x0)
        except AttributeError:
            # first iteration
            pass
                     
        soln = self.nlp_solver(
                               x0=x0,
                               lbg=self.lbg_vcsd, 
                               ubg=self.ubg_vcsd,
                               lbx=self.lbx,
                               ubx=self.ubx,
                               p=self.p_val
                               )
        fl = self.nlp_solver.stats()
        if not fl["success"]:
            print("OCP Solver Unsuccessful")

        # u0 as the MPC policy
        #opt_var = soln["x"].full()
        #act0 = opt_var[self.obs_dim : self.obs_dim + self.action_dim]
        
        # set action on p-fixed
        # (correct value to buffer):
        start = self.nlp_parser["u"]["range"]["a"]
        stop = start + self.n_u
        self.p_val[self.obs_dim:(self.obs_dim + self.action_dim)] = soln["x"][start:stop]
        
        sol_df, self.params = self.parse_solution(soln)
        
        act0 = sol_df.loc[0, self.u()]
        x0 = sol_df.loc[0, self.x()]
        # bookkeeping
        #self.X0 = self.update_X0(opt_var[:, 0])
        #self.X0 = self.update_X0(x0)
        """
        Update x0 of nlp for warmstart:
        """
        self.x0_prev = np.array(soln["x"]).flatten()
        
        info = {
            "optimal": fl["success"],
            "soln": soln.copy(),
            "pf": self.pf_val.copy(),
            "p": self.p_val.copy(),
        }
        return act0, info, sol_df, soln
    
    def V_value(self, state, p_val):
        """
            Evaluate the value function at the current state
        """
        # Forward policy function evaluation for argmin action
        # Solver params
        
        state = (state - self.x_nom_b)/self.x_nom
        
        """
        obs = state
        pf_val = self.pf_val
        pf_val[:self.obs_dim] = obs
        #p_val = self.p_val
        p_val = np.concatenate([pf_val, self.pp_val, self.p_bounds])
        """
        
        # run nlp solver
        soln = self.nlp_solver(
            x0=self.x0,
            #p=np.concatenate([pf_val,p_val])[:,0],
            lbx=self.lbx,
            ubx=self.ubx,
            p=p_val,
            lbg=self.lbg_vcsd,
            ubg=self.ubg_vcsd
        )
        fl = self.nlp_solver.stats()
        if not fl["success"]:
            print("OCP Solver Unsuccessful")
        
        v_mpc = soln["f"].full()[0,0]
        # for debugging purposes, inspect solution frame:
        sol_df, params = self.parse_solution(soln)        
        
        info = {
            "optimal": fl["success"],
            "soln": soln.copy(),
            #"pf": pf_val.copy(),
            "p": p_val.copy(),
        }
        return v_mpc, info, sol_df, soln

    def Q_value(self, state, action, p_val, sol):
        """
            Evaluate the Q function at the current state and action
        """
        # Action-value function evaluation
        
        """
        TODO: enable state estimation.
        """
        #obs = self.model.get_obs(state)
        
        state = (state - self.x_nom_b)/self.x_nom
        action = (action - self.u_nom_b)/self.u_nom
         
        """
        obs = state
        pf_val = self.pf_val
        #pf_val[: self.obs_dim, :] = obs[:, None]
        pf_val[:self.obs_dim] = obs
        pf_val[self.obs_dim:(self.obs_dim + self.action_dim)] = action
        # re-init p_vals:
        p_val = np.concatenate([pf_val, self.pp_val, self.p_bounds])
        
        """
        
        """
        fixed intial guess for u0 already set
        for original solve.
        X0 = self.x0
        u_info = self.nlp_parser.vars["u"]
        start = u_info["range"]["a"]
        stop = start + self.n_u
        X0[start:stop] = action
        """
        # set x0:
        x_info = self.nlp_parser.vars["x"]
        start = x_info["range"]["a"]
        stop = start + self.n_x
        self.x0[start:stop] = state
        # set u0:
        u_info = self.nlp_parser.vars["u"]
        start = u_info["range"]["a"]
        stop = start + self.n_u
        self.x0[start:stop] = action
        #self.lbx[start:stop] = action
        #self.ubx[start:stop] = action

        #x0 = self.get_warm_sol_x_u(sol["x"])

        # run Q nlp solver
        qsoln = self.qsolver(
            x0=self.x0,
            #p=np.concatenate([pf_val,p_val])[:,0],
            p=p_val,
            lbx=self.lbx,
            ubx=self.ubx,
            lbg=self.lbg_qcsd,
            ubg=self.ubg_qcsd
        )
        fl = self.qsolver.stats()
        if not fl["success"]:
            print("OCP Solver Unsuccessful")

        # Q value from nlp solution
        q_mpc = qsoln["f"].full()[0,0]
        
        info = {
            "optimal": fl["success"],
            "soln": qsoln.copy(),
            #"pf": pf_val.copy(),
            "p": p_val.copy(),
        }
        
        # for debugging purposes, inspect solution frame:
        sol_df, params = self.parse_solution(qsoln)
        
        return q_mpc, info, sol_df, qsoln
    
    def dVdP(self, soln, pf_val, p_val, p_bounds, optimal=True):
        """
            Evaluate the gradient of the value function at the current state
        """
        x = soln["x"].full()
        lam_g = soln["lam_g"].full()
        pf_val = pf_val.copy()
        p_val = p_val.copy()
        if optimal:
            dLdP = self.dLagV(x, lam_g, pf_val, p_val, p_bounds)
            dLdP = dLdP.full()
            """
            Temp fix for missing sensitivities on model params:
            Get sensitivities from 'lam_x' instead.
            """
            if self.model_params_in_policy:
                p_info = self.nlp_parser["p"]
                start, stop = p_info["range"]["a"], p_info["range"]["b"]
                lam_model_p = np.array(soln["lam_x"][start:stop]).flatten()
                dLdP[:,-self.n_p:] = lam_model_p #*self.p_nom
        else:
            dLdP = np.zeros((1, self.nP))
        return dLdP
    
    def dQdP(self, soln, pf_val, p_val, p_bounds, optimal=True):
        """
            Evaluate the gradient of the Q function at the current state and action
        """
        x = soln["x"].full()
        lam_g = soln["lam_g"].full()
        pf_val = pf_val.copy()
        p_val = p_val.copy()
        p_bounds = p_bounds.copy()
        if optimal:
            #dLdP = self.dLagQ(x, lam_g, pf_val[:, 0], p_val[:, 0])
            dLdP = self.dLagQ(x, lam_g, pf_val, p_val, p_bounds)
            dLdP = dLdP.full()
            # is dLdP equal to -lam_p obtained from Ipopt?
            #lam_p = -soln["lam_p"].full()[self.nPf:-self.nPbounds]
            #if not lam_p == dLdP.T:
            #    print("check sens.")
            """
            Temp fix for missing sensitivities on model params:
            Get sensitivities from 'lam_x' instead.
            """
            if self.model_params_in_policy:
                p_info = self.nlp_parser["p"]
                start, stop = p_info["range"]["a"], p_info["range"]["b"]
                lam_model_p = np.array(soln["lam_x"][start:stop]).flatten()
                dLdP[:,-self.n_p:] = lam_model_p #*self.p_nom
        else:
            dLdP = np.zeros((1, self.nP))
        return dLdP

    def dPidP(self, soln, pf_val, p_val, optimal=True):
        """
            Evaluate the gradient of the policy at the current state
        """
        x = soln["x"].full()
        lam_g = soln["lam_g"].full()
        z = np.concatenate((x, lam_g), axis=0)
        pf_val = pf_val.copy()
        p_val = p_val.copy()

        if optimal:
            jacob_act = self.dPi(z, pf_val[:, 0], p_val[:, 0]).full()[: self.action_dim, :]
        else:
            jacob_act = np.zeros((self.action_dim, self.nP))
        return jacob_act
    
    def train(self, replay_buffer):
        _ = self.learning_module.train(replay_buffer)
        #cost_p = self.p_val[self.iP_cost[0] : self.iP_cost[1]]
        #self.cost_model.print_params(cost_p)
        return self.pp_val
    
    def constraint_param_opt(self, lr, tr):
        # SDP for param update to ensure stable MPC formulation
        # l1, l2 = 0.000, 0.000
        self.dP_th = cvx.Variable((self.nP, 1))
        self.dJ_th = cvx.Parameter((self.nP, 1))
        self.P_th = cvx.Parameter((self.nP, 1))
        P_th_next = self.P_th + self.dP_th

        J_th = 0.5 * cvx.sum_squares(self.dP_th) + lr * self.dJ_th.T @ self.dP_th
        # J_up += l1 * cvx.norm(P_cost_next, 1) + l2 * cvx.norm(P_cost_next, 2)
        constraint = [self.dP_th <= tr, self.dP_th >= -tr]

        self.update_step = cvx.Problem(cvx.Minimize(J_th), constraint)

    def constraint_param_update(self, dJ, p_val):
        # Cost param update
        P_up = p_val.copy()
        self.dJ_th.value = dJ.copy()
        self.P_th.value = P_up.copy().reshape(self.P_th.shape)
        try:
            self.update_step.solve()
        except:
            print("SDP solver for cost param update failed")

        if self.update_step.status == "optimal":
            P_up += self.dP_th.value.copy()
        else:
            print(f"Problem status: {self.update_step.status}")
        return P_up
    
    def param_update(self, dJ, param_val=None, constrained_updates=True):
        # Param update scheme
        param_val = param_val if param_val is not None else self.pp_val
        self.constraint_param_opt(self.lr, self.learning_params["tr"])
        if constrained_updates:
            self.pp_val = self.constraint_param_update(dJ, param_val)
        else:
            # skip the cost for now:
            """
            dP = -self.lr[0] * dJ[self.iP_cost[0] : self.iP_cost[1], :]
            self.p_val[self.iP_cost[0] : self.iP_cost[1], :] += dP.clip(
                -self.tr[0], self.tr[0]
            )
            """
            # simple update:
            dP = (self.lr*dJ).flatten().clip(-self.tr, self.tr)
            self.dP_df.loc[len(self.dP_df), :] = dP
            # check if any steps create possibility of indefinite stage cost:
            self.lr = self.lr - 1e-4*self.lr                           
            """
            W, f, S, V0 = self.W, self.f, self.S, self.V0
            stage_cost_param_len = self.W.shape[0] + \
                                   self.f.shape[0] + \
                                   self.S.shape[0] + \
                                   self.V0.shape[0]
                                   
            for p in (W, f, S, V0): 
                p_len = p.shape[0]
                stop = start + p_len
                for i in range(start, stop):
                    if (self.pp_val[i] + dP[i]) < 0:
                        dP[i] = 0
                start += p_len
                
            for i in range(stage_cost_param_len):
                if (self.pp_val[i] + dP[i]) < 0:
                    dP[i] = 0
            """
                
            
            """
            Check if physical model paramaters become negative. 
            If so, reject step on them.
            """
            if self.model_params_in_policy:
                dP[-self.n_p:] *= self.p_nom
                # no negative model parameters:
                if any((self.pp_val + dP)[-self.n_p:] < 0):
                    dP[-self.n_p:] = 0
            self.pp_val = self.pp_val + dP