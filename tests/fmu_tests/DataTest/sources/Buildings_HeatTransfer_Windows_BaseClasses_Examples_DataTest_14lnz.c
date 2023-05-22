#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/Desktop/XML_dump/Buildings.HeatTransfer.Windows.BaseClasses.Examples.DataTest/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest.fmutmp/sources/Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_14lnz.c"
#endif
/* Linearization */
#include "Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_linear_model_frame()
{
  return "model linearized_model \"Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest\" \n  parameter Integer n = 0 \"number of states\";\n  parameter Integer m = 0 \"number of inputs\";\n  parameter Integer p = 22 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[m];\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'y_recordTest[1,1,1]' = y[1];\n""  Real 'y_recordTest[1,2,1]' = y[2];\n""  Real 'y_recordTest[1,3,1]' = y[3];\n""  Real 'y_recordTest[1,4,1]' = y[4];\n""  Real 'y_recordTest[1,5,1]' = y[5];\n""  Real 'y_recordTest[1,6,1]' = y[6];\n""  Real 'y_recordTest[1,7,1]' = y[7];\n""  Real 'y_recordTest[1,8,1]' = y[8];\n""  Real 'y_recordTest[1,9,1]' = y[9];\n""  Real 'y_recordTest[1,10,1]' = y[10];\n""  Real 'y_recordTest[1,11,1]' = y[11];\n""  Real 'y_y[1,1,1]' = y[12];\n""  Real 'y_y[1,2,1]' = y[13];\n""  Real 'y_y[1,3,1]' = y[14];\n""  Real 'y_y[1,4,1]' = y[15];\n""  Real 'y_y[1,5,1]' = y[16];\n""  Real 'y_y[1,6,1]' = y[17];\n""  Real 'y_y[1,7,1]' = y[18];\n""  Real 'y_y[1,8,1]' = y[19];\n""  Real 'y_y[1,9,1]' = y[20];\n""  Real 'y_y[1,10,1]' = y[21];\n""  Real 'y_y[1,11,1]' = y[22];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linearized_model;\n";
}
const char *Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest_linear_model_datarecovery_frame()
{
  return "model linearized_model \"Buildings_HeatTransfer_Windows_BaseClasses_Examples_DataTest\" \n parameter Integer n = 0 \"number of states\";\n  parameter Integer m = 0 \"number of inputs\";\n  parameter Integer p = 22 \"number of outputs\";\n  parameter Integer nz = 22 \"data recovery variables\";\n"
  "  parameter Real x0[0] = %s;\n"
  "  parameter Real u0[0] = %s;\n"
  "  parameter Real z0[22] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "  parameter Real Cz[nz, n] = zeros(nz, n);%s\n\n"
  "  parameter Real Dz[nz, m] = zeros(nz, m);%s\n\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[m];\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'y_recordTest[1,1,1]' = y[1];\n""  Real 'y_recordTest[1,2,1]' = y[2];\n""  Real 'y_recordTest[1,3,1]' = y[3];\n""  Real 'y_recordTest[1,4,1]' = y[4];\n""  Real 'y_recordTest[1,5,1]' = y[5];\n""  Real 'y_recordTest[1,6,1]' = y[6];\n""  Real 'y_recordTest[1,7,1]' = y[7];\n""  Real 'y_recordTest[1,8,1]' = y[8];\n""  Real 'y_recordTest[1,9,1]' = y[9];\n""  Real 'y_recordTest[1,10,1]' = y[10];\n""  Real 'y_recordTest[1,11,1]' = y[11];\n""  Real 'y_y[1,1,1]' = y[12];\n""  Real 'y_y[1,2,1]' = y[13];\n""  Real 'y_y[1,3,1]' = y[14];\n""  Real 'y_y[1,4,1]' = y[15];\n""  Real 'y_y[1,5,1]' = y[16];\n""  Real 'y_y[1,6,1]' = y[17];\n""  Real 'y_y[1,7,1]' = y[18];\n""  Real 'y_y[1,8,1]' = y[19];\n""  Real 'y_y[1,9,1]' = y[20];\n""  Real 'y_y[1,10,1]' = y[21];\n""  Real 'y_y[1,11,1]' = y[22];\n"
  "  Real 'z_recordTest[1,1,1]' = z[1];\n""  Real 'z_recordTest[1,2,1]' = z[2];\n""  Real 'z_recordTest[1,3,1]' = z[3];\n""  Real 'z_recordTest[1,4,1]' = z[4];\n""  Real 'z_recordTest[1,5,1]' = z[5];\n""  Real 'z_recordTest[1,6,1]' = z[6];\n""  Real 'z_recordTest[1,7,1]' = z[7];\n""  Real 'z_recordTest[1,8,1]' = z[8];\n""  Real 'z_recordTest[1,9,1]' = z[9];\n""  Real 'z_recordTest[1,10,1]' = z[10];\n""  Real 'z_recordTest[1,11,1]' = z[11];\n""  Real 'z_y[1,1,1]' = z[12];\n""  Real 'z_y[1,2,1]' = z[13];\n""  Real 'z_y[1,3,1]' = z[14];\n""  Real 'z_y[1,4,1]' = z[15];\n""  Real 'z_y[1,5,1]' = z[16];\n""  Real 'z_y[1,6,1]' = z[17];\n""  Real 'z_y[1,7,1]' = z[18];\n""  Real 'z_y[1,8,1]' = z[19];\n""  Real 'z_y[1,9,1]' = z[20];\n""  Real 'z_y[1,10,1]' = z[21];\n""  Real 'z_y[1,11,1]' = z[22];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

