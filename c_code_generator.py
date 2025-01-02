#from argparse import ArgumentError
import casadi as ca
#from casadi import *
from abc import ABC, abstractmethod, ABCMeta
import pandas as pd
#pd.set_option("display.precision", 8)
import numpy as np
#np.set_printoptions(precision=10)
import json
#import sys
#import pdb
#import pprint
from ocp.shooting import MultipleShooting, SingleShooting, Collocation
import copy
import re
#from tables import Col
#from integrators import RungeKutta4, Cvodes, IRK
import ocp.integrators as integrators
from ocp.dae import DAE
#from shooting import MultipleShooting
#from callback import ProcessIdCallback
import os
import subprocess
from collections import OrderedDict
#from shooting import Collocation
#from sysid.ocp import OCP
#import typing
import hashlib
import scipy
import typing
import copy
        
class NumpyEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, np.integer):
            return int(obj)
        if isinstance(obj, np.floating):
            return float(obj)
        if isinstance(obj, np.ndarray):
            return obj.tolist()
        if isinstance(obj, ca.DM):
            assert (obj.shape[0] in (1, None)) \
                    or \
                   (obj.shape[1] in (1, None))
            return list(np.array(obj).flatten())
        return super(NumpyEncoder, self).default(obj)

class CcodeGenerator():

    def __init__(self, solver, cfg):
        """
        Needs a solver-obj and config-file.
        """
        self.solver = solver
        self.cfg = cfg
        
    
    def get_c_code_name(self):
        """
        return "%s_solver_id_" % type(self).__name__ + \
                str(abs(hash(json.dumps(config, sort_keys=True)))) + \
                ".c"
        NOTE: built-in hash() only consistent internal to a process
        """
        config = self.cfg
        import hashlib
        if "N" not in config:
            config["N"] = self.N
        if "dt" not in config:
            config["dt"] = self.dt
        
        # not Json-serializable:
        #_  = self.kwargs.pop("functions", None)
        # but the rest of kwargs is:
        #config["kwargs"] = self.kwargs
        #config["scale_dict"] = self.scale_dict
        s = json.dumps(config, sort_keys=True, cls=NumpyEncoder)
        return "%s_solver_id_" % self.solver.name() + \
                str(
                    int(
                        hashlib.sha256(s.encode('utf-8')).hexdigest(),
                        16) %
                    10**8
                    ) \
                + ".c"
        
        
    def pregenerate_c_code(self, gen_code_filename):
        """
        Requires gcc. Make sure it is installed.
        
        NOTE: only tested on Linux.
        
        TODO: test on another platform.
        """
        #so_filename = gen_code_filename.replace(".c", ".so")
        # keep names for later:
        #self.c_files.append(gen_code_filename)
        #self.c_files.append(so_filename)
        #solver = kwargs.pop("solver")
        self.solver.generate_dependencies(gen_code_filename)
        return gen_code_filename.replace(".c", ".so")
        
    def compile_c_code(
                       self,
                       c_code_path,
                       so_path,
                       **kwargs
                       ):
        # Create a new NLP solver instance from the compiled code
        compiler = kwargs.pop("compiler", "clang")
        flags = kwargs.pop("flags", ["-O3"])
        #flags = kwargs.pop("flags", ["-Ofast"])
        if os.path.exists("_l4c_generated"):
            linkage = ["-L./", "_l4c_generated/libl4casadi_f.so"]
        else:
            linkage = []
            
        cmd_args = [compiler,"-fPIC","-shared"] + \
                    flags + \
                    linkage + \
                    [
                    c_code_path, 
                     "-o",
                     so_path
                     ]
        # compile:
        subprocess.run(cmd_args)
    
    def init_codegen_solver(self,
                            so_filename,
                            solver="ipopt",
                            **opts):
        """
        TODO: solver name
        """
        #self.opt.pop("verbose", False)
        #self.opt.pop("ipopt.hessian_approximation")
        solver_opts = copy.deepcopy(opts)
        opts[solver] = dict()
        for k, v in solver_opts.items():
            opts[solver][k.replace(solver + ".", "")] = v
        # re-init solver object:
        return ca.nlpsol("solver", 
                        solver,
                        so_filename,
                        opts)

    def prepare_solver(self, codegen=False, **kwargs):
        """
        Prepare solver.
        """
        if not hasattr(self, "solver"):      
            self._init_solver()
        opts = kwargs.pop("opts", dict())
        gen_code_filename = self.get_c_code_name()
        so_filename = gen_code_filename.replace(".c", ".so")

        if codegen:
            if not os.path.exists(gen_code_filename):
                self.pregenerate_c_code(gen_code_filename,
                                        **kwargs)
            #if not os.path.exists(self.so_filename):
            if not os.path.exists(so_filename):
                self.compile_c_code(
                    gen_code_filename,
                    so_filename
                )
            self.init_codegen_solver(so_filename, **opts)    
    

        



        

