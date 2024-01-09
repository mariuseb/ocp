# ocp
Parameter estimation, model predictive control, moving horizon estimation, reinforcement learning ++

**0. Requirements**

      For a minimal setup (i.e. no BOPTEST interaction and no fast linear solvers), use mamba, as the conda version of casadi on Windows seems to be broken (missing dll's etc.). Additinally, the speed of mamba is superior. Instructions to run a simple parameter estimation script are as follows:
      
      1.) Download Windows-installer and install miniforge3 (https://github.com/conda-forge/miniforge)
      
      2.) In 'Miniforge prompt' ('run as admin' if system-wide installation):
      
      - mamba init powershell
      
      3.) In powershell, from the root-folder of 'ocp', run:
      
      - mamba env create -f ocp_minimal.yml

      4.) Activate the environment with:

      - mamba activate ocp_minimal
      
      5.) See e.g. tests/param_est_tests/ZEBLL/test_param_est_2R2C.py on how to do parameter estimation on already existing data.

**1. Full setup (TODO)**

      For a full setup, README is TODO.
