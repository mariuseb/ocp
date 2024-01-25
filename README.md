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

**1. Devcontainer setup (Windows/Linux)**

      1.) Download Docker desktop from: https://www.docker.com/products/docker-desktop/.

      2.) Install WSL: https://learn.microsoft.com/en-us/windows/wsl/install (backend for Docker Desktop).
            - Make sure to enable wsl2
            - Enable integration with default WSL distro (settings -> Resources -> WSL Integration)

      3.) Download Vscode from: https://code.visualstudio.com/.

      4.) Open Vscode in root-folder of "ocp"-repo.

      5.) Install development container (pop-up window)

      6.) Copy-paste the following into "launch.json" (located under "workspaces/.vscode/launch.json"):

            {
            // Use IntelliSense to learn about possible attributes.
            // Hover to view descriptions of existing attributes.
            // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
            "version": "0.2.0",
            "configurations": [
                  {
                        "name": "Python: Current File",
                        "type": "python",
                        "request": "launch",
                        "program": "${file}",
                        "console": "integratedTerminal",
                        "cwd": "${workspaceFolder}/${relativeFileDirname}",
                        "justMyCode": true,
                        "env": {
                        "PYTHONPATH": "${workspaceFolder}${pathSeparator}${env:PYTHONPATH}"
                        }
                  }
            ]
            }

      7.) Run example scripts.

**2. Full setup (TODO)**

      For a full setup, README is TODO.