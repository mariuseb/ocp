#from casadi import *
import casadi as ca
import re

class DAE(object):
    """
    class to be used as input for parameter estimation
    """
    def __init__(self, config):

        self.dae = ca.DaeBuilder()
        self.config = config
        self.add_params()
        self.add_states()
        self.add_alg_states()
        self.add_controls()
        self.add_meas()
        self.add_process_noise()
        self.add_meas_noise()
        self.add_refs()
        self.add_odes()
        self.add_algs()
        #self.add_meas()


    def add_params(self):
        """ Add param names..."""
        for name in self.config["p"]:
            param = self.dae.add_p(name)
            self.__setattr__(name, param)

        self.__setattr__("p", self.config["p"])
        
    def add_process_noise(self):
        """
        Add:
            - process noise/disturbance.
        """
        try:
            for name in self.config["w"]:
                # can't add to dae:
                # state = self.dae.add_x(name)
                noise = ca.MX.sym(name)
                self.__setattr__(name, noise)

            self.__setattr__("w_names", self.config["w"])
        except KeyError:
            self.__setattr__("w_names", [])
            
        
    def add_meas_noise(self):
        """
        Add:
            - measurement noise
        """
        try:
            for name in self.config["v"]:
                # can't add to dae:
                # state = self.dae.add_x(name)
                noise = ca.MX.sym(name)
                self.__setattr__(name, noise)

            self.__setattr__("v_names", self.config["v"])
        except KeyError:
            self.__setattr__("v_names", [])
            
    def add_refs(self):
        """
        Add:
            - externally supplied references
        """
        try:
            for name in self.config["r"]:
                # can't add to dae:
                # state = self.dae.add_x(name)
                noise = ca.MX.sym(name)
                self.__setattr__(name, noise)

            self.__setattr__("r_names", self.config["r"])
        except KeyError:
            self.__setattr__("r_names", [])


    def add_controls(self):
        self.u_names = []
        for name in self.config["u"]:
            control = self.dae.add_u(name)
            self.__setattr__(name, control)
            self.u_names.append(name)
        
        self.__setattr__("u", self.config["u"])
        

    def add_states(self):
        for name in self.config["x"]:
            state = self.dae.add_x(name)
            self.__setattr__(name, state)

        self.__setattr__("x", self.config["x"])

    def add_alg_states(self):
        """
        Add algebraic states.
        """
        try:
            for name in self.config["z"]:
                alg_state = self.dae.add_z(name)
                #noise = MX.sym(name)
                self.__setattr__(name, alg_state)

            self.__setattr__("z", self.config["z"])
        except KeyError:
            # to logger / warning 
            self.__setattr__("z", [])
            #pass

    def add_meas(self):
        """ 
        Add measurement. 
        """

        meas_exprs = {}

        repl_table = {k: "self." + k for k in self.__dict__.keys() if k not in ["dae", "config"]}
        pattern = re.compile(r'\b(' + '|'.join(repl_table.keys()) + r')\b')
        try:
            for name, eq_string in self.config["y"]:
                # expects name, definition:

                eq_string = pattern.sub(lambda x: repl_table[x.group()], eq_string)
                
                #exec(f'self.algs["{alg_name}"] =' + alg_string)

                exec("meas_exprs[name] = " + eq_string)

                meas_eq = self.dae.add_y(name, meas_exprs[name])
                #noise = MX.sym(name)
                self.__setattr__(name, meas_eq)

            # keep for later lookup:
            self.__setattr__("y", meas_exprs)
            self.__setattr__("y_names", list(meas_exprs.keys()))
        except KeyError:
            self.__setattr__("y", dict())
            
        
    
    # names:
    '''     
    @property
    def x_names(self):
        return self.x

    @property
    def z_names(self):
        return self.z

    @property
    def p_names(self):
        return self.x

    @property
    def u_names(self):
        return self.z
    
    @property
    def z_names(self):
        return self.z 
    '''
    
    @property
    def n_x(self):
        return len(self.dae.x)

    @property
    def n_z(self):
        return len(self.dae.z)

    @property
    def n_p(self):
        return len(self.dae.p)

    @property
    def n_w(self):
        return len(self.w_names)

    @property
    def n_v(self):
        return len(self.v_names)
    
    @property
    def n_r(self):
        return len(self.r_names)

    @property
    def n_u(self):
        return len(self.dae.u)

    @property
    def n_y(self):
        return len(self.dae.y)
    
    @property
    def order(self):
        return ("x", "z", "u", "p", "w", "v", "y", "r")
    
    @property
    def all_names(self):
        """
        Order:
            x, z, u, p, w, v, y, r
        """
        return self.x + \
               self.z + \
               self.u + \
               self.p + \
               self.w_names + \
               self.v_names + \
               list(self.y.keys()) + \
               self.r_names

    @property
    def g(self):
        """
        trivial equations must be filtered out.
        """
        #eqs = []
        #for eq in self.dae.alg:
        #    if is_symbolic(eq):
        #        eqs.appe

        return [eq for eq in self.dae.alg if not eq.is_zero()]
                

    """
    @property
    def p(self):
        return vertcat(*self.dae.p)

    @property
    def x(self):
        return vertcat(*self.dae.p)

    @property
    def u(self):
        return vertcat(*self.dae.u)
    """

    """
    Can generalize the below to add equation.
    """

    def _get_repl_table(self):
        """
        Get replacement table for
        expression initialization.
        """
        return {k: "self." + k for k in self.__dict__.keys() if k not in ["dae", "config"]}
    
    def _init_exprs(self, kind):
        """ Generic """
        
        repl_table = self._get_repl_table()
        
        if kind == "ode":
            
            self.odes = expr_dict = {}
            method = self.dae.add_ode
            
        elif kind == "alg":
            
            self.algs = expr_dict = {}
            method = self.dae.add_alg
            
        try:
            for expr_name, _string in self.config[kind].items():
                
                pattern = re.compile(r'\b(' + '|'.join(repl_table.keys()) + r')\b')
                expr_string = pattern.sub(lambda x: repl_table[x.group()], _string)

                #exec('ode =' + ode_string, globals())
                #exec(f'self.%s["{expr_name}"] =' + expr_string)
                exec(f'expr_dict["{expr_name}"] =' + expr_string)
                #self.dae.add_ode(expr_name, expr_dict[expr_name])
                method(expr_name, expr_dict[expr_name])
        except KeyError:
            pass
            
    def add_odes(self):
        self._init_exprs("ode")
        
    def add_algs(self):
        self._init_exprs("alg")
        
'''     
    def add_odes(self):
        # get params, states, to local scope
        
        #repl_table = {k: "self." + k for k in self.__dict__.keys() if k not in ["dae", "config"]}
        repl_table = self._get_repl_table()
        
        self.odes = {}

        for ode_name, ode_string in self.config["ode"].items():

            pattern = re.compile(r'\b(' + '|'.join(repl_table.keys()) + r')\b')
            ode_string = pattern.sub(lambda x: repl_table[x.group()], ode_string)

            #exec('ode =' + ode_string, globals())
            exec(f'self.odes["{ode_name}"] =' + ode_string)
            self.dae.add_ode(ode_name, self.odes[ode_name])
            #self.dae.add_aux(ode_name, self.odes[ode_name])

    def add_daes(self):
        # get params, states, to local scope
        
        #repl_table = {k: "self." + k for k in self.__dict__.keys() if k not in ["dae", "config"]}
        repl_table = self._get_repl_table()
        self.daes = {}

        for dae_name, dae_string in self.config["dae"].items():

            pattern = re.compile(r'\b(' + '|'.join(repl_table.keys()) + r')\b')
            dae_string = pattern.sub(lambda x: repl_table[x.group()], dae_string)

            #exec('ode =' + ode_string, globals())
            exec(f'self.daes["{dae_name}"] =' + dae_string)
            self.dae.add_dae(dae_name, self.daes[dae_name])
            #self.dae.add_aux(ode_name, self.odes[ode_name])

    def add_algs(self):
        
        #repl_table = {k: "self." + k for k in self.__dict__.keys() if k not in ["dae", "config"]}
        repl_table = self._get_repl_table()
        self.algs = {}

        for alg_name, alg_string in self.config["alg"].items():

            pattern = re.compile(r'\b(' + '|'.join(repl_table.keys()) + r')\b')
            alg_string = pattern.sub(lambda x: repl_table[x.group()], alg_string)
            
            exec(f'self.algs["{alg_name}"] =' + alg_string)
            self.dae.add_alg(alg_name, self.algs[alg_name]) '''