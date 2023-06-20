import casadi as ca

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

functions = {"regNonZeroPower": regNonZeroPower}