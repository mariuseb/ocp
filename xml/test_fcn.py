from pylab import *
from casadi import *
from ocp.xml.XML_edit_own import patch_xml, get_functions_xml
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


model = DaeBuilder("foo")


model_path = "Buildings.Utilities.Math.Functions.Examples.RegNonZeroPower.xml"
processed_path = "RegNonZeroPower.xml"

patch_xml(model_path, processed_path)

#print("Check states and equations")

#inspect_xml(processed_path)
#inspect_xml(model_path)
#model.parse_fmi(processed_path)
model.parse_fmi(processed_path)
#f = model.fun('Buildings.Utilities.Math.Functions.regNonZeroPower')

#functions = get_functions_xml(model_path)

#print(functions)

#F = functions["Buildings_Utilities_Math_Functions_regNonZeroPower"]
# test output over 0, 1, .. , 10 with step ramp

xs = np.arange(0,1,step=0.01)
xs = np.append(xs, np.arange(1,10,step=1))
n = 0.5
delta = 0.01
y = np.array([])
for x in xs:
    y = np.append(y, F(x, n, delta))

plt.plot(xs, y)
plt.show()
    
