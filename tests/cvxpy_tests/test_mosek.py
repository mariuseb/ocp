##
#  Copyright : Copyright (c) MOSEK ApS, Denmark. All rights reserved.
#
#  File :      acc1.py
#
#  Purpose :   Tutorial example for affine conic constraints.
#              Models the problem:
#
#              maximize c^T x
#              subject to  sum(x) = 1
#                          gamma >= |Gx+h|_2
##
import sys, mosek

# Define a stream printer to grab output from MOSEK
def streamprinter(text):
    sys.stdout.write(text)
    sys.stdout.flush()

# Define problem data
n, k = 3, 2
# Only a symbolic constant
inf = 0.0

# Make a MOSEK environment
with mosek.Env() as env:
    # Attach a printer to the environment
    env.set_Stream(mosek.streamtype.log, streamprinter)

    # Create a task
    with env.Task(0, 0) as task:
        # Attach a printer to the task
        task.set_Stream(mosek.streamtype.log, streamprinter)

        # Create n free variables
        task.appendvars(n)
        task.putvarboundsliceconst(0, n, mosek.boundkey.fr, -inf, inf)

        # Set up the objective
        c = [2, 3, -1]
        task.putobjsense(mosek.objsense.maximize)
        task.putclist(range(n), c)

        # One linear constraint - sum(x) = 1
        task.appendcons(1)
        task.putarow(0, range(n), [1]*n)
        task.putconbound(0, mosek.boundkey.fx, 1.0, 1.0)

        # Append empty AFE rows for affine expression storage
        task.appendafes(k + 1)

        # G matrix in sparse form
        Gsubi = [0, 0, 1, 1]
        Gsubj = [0, 1, 0, 2]
        Gval  = [1.5, 0.1, 0.3, 2.1]
        # Other data
        h     = [0, 0.1]
        gamma = 0.03

        # Construct F matrix in sparse form
        Fsubi = [i + 1 for i in Gsubi]   # G will be placed from row number 1 in F
        Fsubj = Gsubj
        Fval  = Gval

        # Fill in F storage
        task.putafefentrylist(Fsubi, Fsubj, Fval)

        # Fill in g storage
        task.putafeg(0, gamma)
        task.putafegslice(1, k+1, h)

        # Define a conic quadratic domain
        quadDom = task.appendquadraticconedomain(k + 1)

        # Create the ACC
        task.appendacc(quadDom,    # Domain index
                       range(k+1), # Indices of AFE rows [0,...,k]
                       None)       # Ignored

        # Solve and retrieve solution
        task.optimize()
        xx = task.getxx(mosek.soltype.itr)
        if task.getsolsta(mosek.soltype.itr) == mosek.solsta.optimal:
            print("Solution: {xx}".format(xx=list(xx)))

        # Demonstrate retrieving activity of ACC
        activity = task.evaluateacc(mosek.soltype.itr, 
                                    0)     # ACC index          
        print("Activity of ACC:: {activity}".format(activity=list(activity)))

        # Demonstrate retrieving the dual of ACC
        doty = task.getaccdoty(mosek.soltype.itr, 
                               0)          # ACC index
        print("Dual of ACC:: {doty}".format(doty=list(doty)))
