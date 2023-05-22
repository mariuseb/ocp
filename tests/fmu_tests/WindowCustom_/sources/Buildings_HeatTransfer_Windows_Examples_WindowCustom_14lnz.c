#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustom/Buildings_HeatTransfer_Windows_Examples_WindowCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustom_14lnz.c"
#endif
/* Linearization */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *Buildings_HeatTransfer_Windows_Examples_WindowCustom_linear_model_frame()
{
  return "model linearized_model \"Buildings_HeatTransfer_Windows_Examples_WindowCustom\" \n  parameter Integer n = 0 \"number of states\";\n  parameter Integer m = 7 \"number of inputs\";\n  parameter Integer p = 3 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'u_QAbsSha_flow' = u[1];\n""  Real 'u_QAbsUns_flow' = u[2];\n""  Real 'u_QSolAbsExt_flow' = u[3];\n""  Real 'u_QSolAbsInt_flow' = u[4];\n""  Real 'u_TBlaSky' = u[5];\n""  Real 'u_TOut' = u[6];\n""  Real 'u_vWin' = u[7];\n"
  "  Real 'y_QInt_flow' = y[1];\n""  Real 'y_TCon' = y[2];\n""  Real 'y_TRad' = y[3];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linearized_model;\n";
}
const char *Buildings_HeatTransfer_Windows_Examples_WindowCustom_linear_model_datarecovery_frame()
{
  return "model linearized_model \"Buildings_HeatTransfer_Windows_Examples_WindowCustom\" \n parameter Integer n = 0 \"number of states\";\n  parameter Integer m = 7 \"number of inputs\";\n  parameter Integer p = 3 \"number of outputs\";\n  parameter Integer nz = 86 \"data recovery variables\";\n"
  "  parameter Real x0[0] = %s;\n"
  "  parameter Real u0[7] = %s;\n"
  "  parameter Real z0[86] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "  parameter Real Cz[nz, n] = zeros(nz, n);%s\n\n"
  "  parameter Real Dz[nz, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'u_QAbsSha_flow' = u[1];\n""  Real 'u_QAbsUns_flow' = u[2];\n""  Real 'u_QSolAbsExt_flow' = u[3];\n""  Real 'u_QSolAbsInt_flow' = u[4];\n""  Real 'u_TBlaSky' = u[5];\n""  Real 'u_TOut' = u[6];\n""  Real 'u_vWin' = u[7];\n"
  "  Real 'y_QInt_flow' = y[1];\n""  Real 'y_TCon' = y[2];\n""  Real 'y_TRad' = y[3];\n"
  "  Real 'z_QAbsSha_flow' = z[1];\n""  Real 'z_QAbsUns_flow' = z[2];\n""  Real 'z_QInt_flow' = z[3];\n""  Real 'z_QSolAbsExt_flow' = z[4];\n""  Real 'z_QSolAbsInt_flow' = z[5];\n""  Real 'z_TBlaSky' = z[6];\n""  Real 'z_TCon' = z[7];\n""  Real 'z_TOut' = z[8];\n""  Real 'z_TOuts.port.Q_flow' = z[9];\n""  Real 'z_TRad' = z[10];\n""  Real 'z_extCon.JInSha' = z[11];\n""  Real 'z_extCon.JInUns' = z[12];\n""  Real 'z_extCon.JOutSha' = z[13];\n""  Real 'z_extCon.JOutUns' = z[14];\n""  Real 'z_extCon.conCoeFra.GCon' = z[15];\n""  Real 'z_extCon.conCoeGla.GCon' = z[16];\n""  Real 'z_extCon.conFra.dT' = z[17];\n""  Real 'z_extCon.conWinUns.Gc' = z[18];\n""  Real 'z_extCon.conWinUns.Q_flow' = z[19];\n""  Real 'z_extCon.conWinUns.dT' = z[20];\n""  Real 'z_extCon.glaSha.Q_flow' = z[21];\n""  Real 'z_extCon.radOut.JOut' = z[22];\n""  Real 'z_extCon.radOut.TRad' = z[23];\n""  Real 'z_extCon.radOut.TRad4' = z[24];\n""  Real 'z_extCon.shaCon.Gc' = z[25];\n""  Real 'z_extCon.shaCon.TSha' = z[26];\n""  Real 'z_extCon.shaRad.E_air' = z[27];\n""  Real 'z_extCon.shaRad.E_glass' = z[28];\n""  Real 'z_extCon.shaRad.QRadAbs_flow' = z[29];\n""  Real 'z_extCon.shaRad.T4' = z[30];\n""  Real 'z_extCon.shaRad.TSha_internal' = z[31];\n""  Real 'z_extCon.shaRad.u' = z[32];\n""  Real 'z_extCon.shaSig.yCom' = z[33];\n""  Real 'z_heatFlowSensor.port_a.T' = z[34];\n""  Real 'z_heatFlowSensor.port_b.Q_flow' = z[35];\n""  Real 'z_heatFlowSensor1.port_a.T' = z[36];\n""  Real 'z_heatFlowSensor1.port_b.Q_flow' = z[37];\n""  Real 'z_indRad.JIn' = z[38];\n""  Real 'z_indRad.T4' = z[39];\n""  Real 'z_indRad.heatPort.Q_flow' = z[40];\n""  Real 'z_intShaCon.QRadAbs_flow' = z[41];\n""  Real 'z_intShaCon.TSha' = z[42];\n""  Real 'z_intShaCon.air.Q_flow' = z[43];\n""  Real 'z_intShaCon.conCoeGla.GCon' = z[44];\n""  Real 'z_intShaCon.conFra.Q_flow' = z[45];\n""  Real 'z_intShaCon.conFra.dT' = z[46];\n""  Real 'z_intShaCon.conFra.q_flow' = z[47];\n""  Real 'z_intShaCon.conFra.u' = z[48];\n""  Real 'z_intShaCon.conSha.Gc' = z[49];\n""  Real 'z_intShaCon.conSha.air.Q_flow' = z[50];\n""  Real 'z_intShaCon.conWinUns.Q_flow' = z[51];\n""  Real 'z_intShaCon.conWinUns.dT' = z[52];\n""  Real 'z_intShaCon.conWinUns.q_flow' = z[53];\n""  Real 'z_intShaCon.glaSha.Q_flow' = z[54];\n""  Real 'z_intShaCon.glaSha.T' = z[55];\n""  Real 'z_intShaCon.proSha.u2' = z[56];\n""  Real 'z_intShaRad.E_glass' = z[57];\n""  Real 'z_intShaRad.JIn_air' = z[58];\n""  Real 'z_intShaRad.JIn_glass' = z[59];\n""  Real 'z_intShaRad.JOut_air' = z[60];\n""  Real 'z_intShaRad.JOut_glass' = z[61];\n""  Real 'z_intShaRad.T4' = z[62];\n""  Real 'z_shaSig.y' = z[63];\n""  Real 'z_shaSig.yCom' = z[64];\n""  Real 'z_temperatureSensor.port.Q_flow' = z[65];\n""  Real 'z_temperatureSensor1.port.Q_flow' = z[66];\n""  Real 'z_uSha.y' = z[67];\n""  Real 'z_vWin' = z[68];\n""  Real 'z_window.JInUns_b' = z[69];\n""  Real 'z_window.JOutUns_b' = z[70];\n""  Real 'z_window.fra_a.T' = z[71];\n""  Real 'z_window.fra_b.T' = z[72];\n""  Real 'z_window.frame.dT' = z[73];\n""  Real 'z_window.glaSha.glass[1].E_a' = z[74];\n""  Real 'z_window.glaSha.glass[1].E_b' = z[75];\n""  Real 'z_window.glaSha.glass[1].T4_a' = z[76];\n""  Real 'z_window.glaSha.glass[1].T4_b' = z[77];\n""  Real 'z_window.glaSha.u' = z[78];\n""  Real 'z_window.glaSha_a.T' = z[79];\n""  Real 'z_window.glaUns.glass[1].E_a' = z[80];\n""  Real 'z_window.glaUns.glass[1].E_b' = z[81];\n""  Real 'z_window.glaUns.glass[1].T4_a' = z[82];\n""  Real 'z_window.glaUns.glass[1].T4_b' = z[83];\n""  Real 'z_window.glaUns.u' = z[84];\n""  Real 'z_window.glaUns_a.T' = z[85];\n""  Real 'z_window.glaUns_b.T' = z[86];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

