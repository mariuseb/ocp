from pylab import *
from casadi import *
from ocp.xml.XML_edit import patch_xml, inspect_xml
import pandas as pd

try: # CasADi develop
    model = DaeBuilder("foo")
except: # CasADi 3.5.5
    model = DaeBuilder()

model_path = "Simple2R2C.xml"
processed_path = 'Simple2R2C_processed.xml'

patch_xml(model_path, processed_path)

print("Check states and equations")

inspect_xml(processed_path)
#inspect_xml(model_path)
model.parse_fmi(processed_path)

#model.disp(True)

sdot = model.sdot

model.make_explicit()
model.sort_d()
model.split_d()

print(model.x)
print(model.d)
print(model.ddef)
print(model.u)
