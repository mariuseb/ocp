from casadi import *
import numpy as np
import matplotlib.pyplot as plt

opti = Opti();

x = opti.variable();
y = opti.variable();
xy = vertcat(x,y)

a = 0.2;
p = opti.parameter();

opti.minimize((1-x)**2 + a*(y-x**2)**2);
opti.subject_to(x >= 0);
opti.subject_to((p/2)**2 <= (x + 0.5)**2 + y**2);
opti.subject_to((x + 0.5)**2 + y**2 <= p**2);

p_lins = [1.25,1.4,2];
c = ('r','g','b');
n_lin = len(p_lins);

# Use IPOPT to solve the nonlinear optimization
opts = dict()
opts["ipopt.print_level"] = 0;
opts["print_time"] = False;
opti.solver('ipopt', opts);

M = opti.to_function('M',[p], [xy])

"""
for i in range(3):
    p_lin = p_lins(i);
    subplot(1,n_lin,i)
    plot_nlp([a,p_lin],M(p_lin))
    title(['p = ' num2str(p_lin)])
print('nlp_1d','-dpng')

"""
#z = @(xy) xy(2,:)-xy(1,:);
z = lambda xy: xy[1, :] - xy[0, :]
#z = Function('z', [xy], [xy[1, :] - xy[0, :]]);
#z = Function('z', [xy], []);

## How does the optimal solution vary along p?
pvec = np.linspace(1,2,100);
S = []
zs = []
M_map = M.map(100)
#for _p in pvec:
#    s = M(_p)
#    S.append(s)
#    zs.append(float(z(s)))
S = M_map(pvec)
    


#figure
#plt.plot(pvec, z(S))
plt.plot(pvec, np.array(z(S)).flatten(), color="k", linestyle="dashed")
plt.ylabel('z')
plt.xlabel('p')
#plt.show()

print('nlp_sampled_1d','-dpng')

# Use SQPmethod + QRQP for accurate multipliers
opts = dict()
opts["qpsol"] = 'qrqp';
#opts["qpsol_options.print_iter"] = false;
#opts["print_status"] = false;
#opts["print_iteration"] = false;
#opts["print_time"] = false;
opti.solver('sqpmethod', opts);


Z = opti.to_function('Z', [p, xy], [z(xy)]);
#Z = Function('Z', [p, xy], [z(xy)]);
#Z = Function('Z', [p, xy], [z(M(xy))]);


zp = Z(p,xy);
j = jacobian(zp,p);
h, _ = hessian(zp,p);

Z_taylor = Function('Z_taylor',[p, xy], [zp, j, h]);

t = np.linspace(1,2,1000);

for i in range(n_lin):
    p0 = p_lins[i];
    [F, J, H] = Z_taylor(p0,M(p0));
    plt.plot(p0,F,linewidth=3, color=c[i])
    plt.plot(t, F+J*(t-p0)+1/2*H*(t-p0)**2,linewidth=2, color=c[i])
plt.show()
print(Z_taylor)
