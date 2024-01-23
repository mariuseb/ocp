import casadi as ca
import numpy as np
import matplotlib.pyplot as plt

# TODO: make singleton module for these .. 

# inputs
x = ca.MX.sym("x")
n = ca.MX.sym("n")
delta = ca.MX.sym("delta")
# protected:
delta2 = delta*delta
x2 = x*x
y_d = delta**n
yP_d = n*delta**(n-1)
yPP_d = n*(n-1)*delta**(n-2)
a1 = -(yP_d/delta - yPP_d)/delta2/8
a3 = (yPP_d - 12 * a1 * delta2)/2
a5 = (y_d - delta2 * (a3 + delta2 * a1))
# output
#y = ca.MX.sym("y")

# expressions:
y_if = ca.fabs(x)**n
#y_if = x**n
y_else = a5 + x2*(a3 + x2*a1)

# output
y = ca.if_else(ca.fabs(x) > delta, y_if, y_else)
regNonZeroPower = ca.Function(
                              "regNonZeroPower", 
                              [x, n, delta],
                              [y],
                              ["x", "n", "delta"],
                              ["y"]
                              )

q = ca.MX.sym("q")
y = ca.if_else(x > 0, q, 0)
oneWayHeating = ca.Function(
                            "oneWayHeating", 
                            [x, q],
                            [y],
                            ["x", "q"],
                            ["y"]
                            )

"""
Function equalPercentage
"""
y = ca.MX.sym("y")
R = ca.MX.sym("R")
l = ca.MX.sym("l")
delta = ca.MX.sym("delta")
# protected:
logR = ca.log(R)
z = (3*delta/2)
q = delta*(R**z)*logR
p = R**z
a = (q - 2*p + 2*(R**delta))/((delta**3)*R)
b = (-5*q + 12*p - 13*(R**delta) + l*R)/(2*(delta**2)*R)
c = (7*q - 18*p + 24*(R**delta) - 6*l*R)/(4*delta*R)
d = (-3*q + 8*p - 9*(R**delta) + 9*l*R)/(8*R)
# expressions:
phi_if = l + y*(R**(delta-1) - l)/delta
phi_else_else = d + y*(c+y*(b+y*a))
phi_else_if = R**(y-1)

# output
else_expr = ca.if_else(y > (3/2)*delta, phi_else_if, phi_else_else)
expr =  ca.if_else(y < delta/2, phi_if, else_expr)
equalPercentage = ca.Function(
                                "equalPercentage", 
                                [y,R,l,delta],
                                [expr]
                                #["x", "n", "delta"],
                                #["y"]
                                )
    

"""
Function basicFlowFunction_dp
"""
dp = ca.MX.sym("dp")
k = ca.MX.sym("k")
m_flow_turbulent = ca.MX.sym("m_flow_turbulent")
#delta = ca.MX.sym("delta")

dp_turbulent = (m_flow_turbulent/k)**2
dpNorm = dp/dp_turbulent
dpNormSq = dpNorm**2

m_flow = ca.if_else(ca.fabs(dp) > dp_turbulent, \
                    ca.sign(dp)*k*ca.sqrt(ca.fabs(dp)), \
                    (1.40625  + (0.15625*dpNormSq - 0.5625)*dpNormSq)*m_flow_turbulent*dpNorm)

basicFlowFunction_dp = ca.Function(
                                "basicFlowFunction", 
                                [dp,k,m_flow_turbulent],
                                [m_flow],
                                ["dp", "k", "m_flow_turbulent"],
                                ["m_flow"]
                                )


#test = regNonZeroPower(1, 1.24, 10)
#print(test)

"""
 m_flow = Buildings.Fluid.BaseClasses.FlowModels.basicFlowFunction_dp(valLin.res1.dp, valLin.res1.k, 0.04) - Buildings.Fluid.BaseClasses.FlowModels.basicFlowFunction_dp(valLin.res3.dp, valLin.res3.k, 0.04)
 e.g.
 
   valLin.res1.kVal = valLin.res1.phi * valLin.res1.Kv_SI;
   valLin.res1.k = valLin.res1.kVal;
   valLin.res1.phi = max(0.005000000000000001, 0.05 + valLin.res1.y_actual * 0.95)
   valLin.res1.Kv_SI = 2.0 / sqrt(valLin.res1.dpValve_nominal)

"""

# test over x \in [0, ..., 10]
"""
xs = np.arange(0,1,step=0.01)
#xs = np.append(xs, np.arange(1,10,step=1))
dp = 6000
m_flow_turbulent = 2

y = np.array([])
for x in xs:
    dp = 6000*x
    k = max(0.005, 0.05 + x*0.95)*(2/np.sqrt(6000))
    ys = basicFlowFunction_dp(dp, k, m_flow_turbulent)
    y = np.append(y, ys)

plt.plot(xs, y)
plt.show()
"""

"""
# test it with one input:
test = regNonZeroPower(1, 1.24, 10)
print(test)

# test over x \in [0, ..., 10]
xs = np.arange(0,1,step=0.01)
#xs = np.append(xs, np.arange(1,10,step=1))
n = 0.5
delta = 0.01
y = np.array([])
for x in xs:
    y = np.append(y, regNonZeroPower(x, n, delta))

plt.plot(xs, y)
plt.show()
"""

# TODO: enable calling this function in model defintion
"""
First: construct the function outside initialization,
pass it as a separate object, which must be part of 
namespace when init'ing DAE object.
"""

functions = {
             "regNonZeroPower": regNonZeroPower,
             "oneWayHeating": oneWayHeating,
             "equalPercentage": equalPercentage,
             "basicFlowFunction_dp": basicFlowFunction_dp
             }