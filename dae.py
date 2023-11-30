#from casadi import *
import casadi as ca
import re
import pdb

class DAE(object):
    """
    class to be used as input for parameter estimation
    """
    def __init__(self, config):

        self.dae = ca.DaeBuilder("foo")
        self.config = config
        
        # get functions:
        functions = config.pop("functions", None)
        if functions is not None:
            for k, v in functions.items():
                setattr(self, k, v)
        
        # set z empty
        #self.z = [
        self.v_names = []
        self.s_names = []
        self.w_names = []
        self.add_params()
        self.add_states()
        self.add_alg_states()
        self.add_controls()
        self.add_refs()
        self.add_meas()
        #self.add_process_noise()
        #self.add_meas_noise()
        self.add_w()
        #self.add_meas()
        self.add_odes()
        self.add_algs()


    def add_params(self):
        """ Add param names..."""
        for name in self.config["p"]:
            param = self.dae.add_p(name)
            self.__setattr__(name, param)

        self.__setattr__("p", self.config["p"])
    
    """
    def add_process_noise(self): # s

        try:
            for name in self.config["s"]:
                # can't add to dae:
                # state = self.dae.add_x(name)
                _noise = ca.MX.sym(name)
                noise = self.dae.add_w(name, _noise)
                self.__setattr__(name, noise)

            self.__setattr__("s_names", self.config["s"])
        except KeyError:
            self.__setattr__("s_names", [])
            
        
    def add_meas_noise(self):

        try:
            for name in self.config["v"]:
                # can't add to dae:
                # state = self.dae.add_x(name)
                #noise = ca.MX.sym(name)
                #alg = self.dae.add_z(name)
                #mx = self.dae.get(name)
                #self.__setattr__(name, alg)
                print("Do not add v yet..")
                

            self.__setattr__("v_names", self.config["v"])
            #self.z.extend(self.v_names)
        except KeyError:
            self.__setattr__("v_names", [])
    """   
         
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
        try:
            for name in self.config["u"]:
                control = self.dae.add_u(name)
                self.__setattr__(name, control)
                self.u_names.append(name)
            
            self.__setattr__("u", self.config["u"])
        except KeyError:
            self.__setattr__("u", [])
            
        

    def add_states(self):
        try:
            for name in self.config["x"]:
                state = self.dae.add_x(name)
                self.__setattr__(name, state)

            self.__setattr__("x", self.config["x"])
        except KeyError:
            self.__setattr__("x", [])

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
    '''
    
    @property
    def n_x(self):
        return self.dae.nx()

    @property
    def n_z(self):
        return self.dae.nz()

    @property
    def n_p(self):
        return self.dae.np()

    @property
    def n_w(self):
        return self.dae.nw() - self.n_v - self.n_s

    @property
    def n_v(self):
        return len(self.v_names)
    
    @property
    def n_s(self):
        return len(self.s_names)
    
    @property
    def n_r(self):
        return len(self.r_names)

    @property
    def n_u(self):
        return self.dae.nu()

    @property
    def n_y(self):
        return self.dae.ny()
    
    @property
    def order(self):
        return ("x", "z", "u", "p", "s", "v", "y", "r", "w")
    
    @property
    def all_names(self):
        """
        Order:
            x, z, u, p, s, v, y, r
        """
        return self.x + \
               self.z + \
               self.u + \
               self.p + \
               self.s_names + \
               self.v_names + \
               self.w_names + \
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
            #method = self.dae.add_ode
            method = self.dae.set_ode
            
        elif kind == "alg":
            
            self.algs = expr_dict = {}
            #method = self.dae.add_alg
            #method = self.dae.set_alg
            method = self.dae.set_alg
        
        elif kind == "w":
            
            self.algs = expr_dict = {}
            #method = self.dae.add_alg
            #method = self.dae.set_alg
            method = self.dae.add_w
            
        try:
            for expr_name, _string in self.config[kind].items():
                
                pattern = re.compile(r'\b(' + '|'.join(repl_table.keys()) + r')\b')
                expr_string = pattern.sub(lambda x: repl_table[x.group()], _string)

                #exec('ode =' + ode_string, globals())
                #exec(f'self.%s["{expr_name}"] =' + expr_string)
                try:
                    exec(f'expr_dict["{expr_name}"] =' + expr_string)
                except NameError:
                    # backward lag for difference equation:
                    _mx = ca.MX.sym(expr_name + "_prev")
                    self.__setattr__(expr_name + "_prev", _mx)
                    # regenerate the symbol table:
                    repl_table = self._get_repl_table()
                    pattern = re.compile(r'\b(' + '|'.join(repl_table.keys()) + r')\b')
                    expr_string = pattern.sub(lambda x: repl_table[x.group()], _string)
                    #expr_string = expr_string.replace(expr_name, "self." + expr_name + "_prev")
                    exec(f'expr_dict["{expr_name}"] =' + expr_string)
                    
                mx = method(expr_name, expr_dict[expr_name])
                
                if mx is not None:
                    self.__setattr__(expr_name, mx)
                    
                    """
                    Observe strict naming rules:
                    v : measurement noise
                    s : process noise
                    """
                    
                    if expr_name.startswith("v"):
                        self.v_names.append(expr_name)
                    elif expr_name.startswith("s"):
                        self.s_names.append(expr_name)
                    else: # other kinds of dependent variables, not handled yet
                        #raise ValueError("Check argument.")
                        self.w_names.append(expr_name)
                        print("Regular dependant variable %s" % (expr_name,) +
                              " added")
                        
                    
                elif hasattr(self, expr_name):
                    print("Already existing variable. Check.")
                    assert kind == "ode" or kind == "alg"
                    print("It is an equation, OK.")
                    
                    
        except KeyError:
            setattr(self, kind, [])
            #pass
            
    def add_odes(self):
        self._init_exprs("ode")
        
    def add_algs(self):
        self._init_exprs("alg")
    
    def add_w(self):
        self._init_exprs("w")
        
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