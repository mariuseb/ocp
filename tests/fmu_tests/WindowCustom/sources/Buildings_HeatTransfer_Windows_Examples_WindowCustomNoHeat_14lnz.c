#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustomNoHeat/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_14lnz.c"
#endif
/* Linearization */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_linear_model_frame()
{
  return "model linearized_model \"Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat\" \n  parameter Integer n = 0 \"number of states\";\n  parameter Integer m = 7 \"number of inputs\";\n  parameter Integer p = 0 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'u_QAbsSha_flow' = u[1];\n""  Real 'u_QAbsUns_flow' = u[2];\n""  Real 'u_QSolAbsExt_flow' = u[3];\n""  Real 'u_QSolAbsInt_flow' = u[4];\n""  Real 'u_TBlaSky' = u[5];\n""  Real 'u_TOut' = u[6];\n""  Real 'u_vWin' = u[7];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linearized_model;\n";
}
const char *Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_linear_model_datarecovery_frame()
{
  return "model linearized_model \"Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat\" \n parameter Integer n = 0 \"number of states\";\n  parameter Integer m = 7 \"number of inputs\";\n  parameter Integer p = 0 \"number of outputs\";\n  parameter Integer nz = 80 \"data recovery variables\";\n"
  "  parameter Real x0[0] = %s;\n"
  "  parameter Real u0[7] = %s;\n"
  "  parameter Real z0[80] = %s;\n"
  "\n"
  "  parameter Real A[n, n] = zeros(n, n);%s\n\n"
  "  parameter Real B[n, m] = zeros(n, m);%s\n\n"
  "  parameter Real C[p, n] = zeros(p, n);%s\n\n"
  "  parameter Real D[p, m] = zeros(p, m);%s\n\n"
  "  parameter Real Cz[nz, n] = zeros(nz, n);%s\n\n"
  "  parameter Real Dz[nz, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n];\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'u_QAbsSha_flow' = u[1];\n""  Real 'u_QAbsUns_flow' = u[2];\n""  Real 'u_QSolAbsExt_flow' = u[3];\n""  Real 'u_QSolAbsInt_flow' = u[4];\n""  Real 'u_TBlaSky' = u[5];\n""  Real 'u_TOut' = u[6];\n""  Real 'u_vWin' = u[7];\n"
  "  Real 'z_QAbsSha_flow' = z[1];\n""  Real 'z_QAbsUns_flow' = z[2];\n""  Real 'z_QSolAbsExt_flow' = z[3];\n""  Real 'z_QSolAbsInt_flow' = z[4];\n""  Real 'z_TBlaSky' = z[5];\n""  Real 'z_TOut' = z[6];\n""  Real 'z_TOuts.port.Q_flow' = z[7];\n""  Real 'z_TRAir.port.Q_flow' = z[8];\n""  Real 'z_TRAir.port.T' = z[9];\n""  Real 'z_extCon.JInSha' = z[10];\n""  Real 'z_extCon.JInUns' = z[11];\n""  Real 'z_extCon.JOutSha' = z[12];\n""  Real 'z_extCon.JOutUns' = z[13];\n""  Real 'z_extCon.conCoeFra.GCon' = z[14];\n""  Real 'z_extCon.conCoeGla.GCon' = z[15];\n""  Real 'z_extCon.conFra.dT' = z[16];\n""  Real 'z_extCon.conWinUns.Gc' = z[17];\n""  Real 'z_extCon.conWinUns.Q_flow' = z[18];\n""  Real 'z_extCon.conWinUns.dT' = z[19];\n""  Real 'z_extCon.glaSha.Q_flow' = z[20];\n""  Real 'z_extCon.radOut.JOut' = z[21];\n""  Real 'z_extCon.radOut.TRad' = z[22];\n""  Real 'z_extCon.radOut.TRad4' = z[23];\n""  Real 'z_extCon.shaCon.Gc' = z[24];\n""  Real 'z_extCon.shaCon.TSha' = z[25];\n""  Real 'z_extCon.shaRad.E_air' = z[26];\n""  Real 'z_extCon.shaRad.E_glass' = z[27];\n""  Real 'z_extCon.shaRad.QRadAbs_flow' = z[28];\n""  Real 'z_extCon.shaRad.T4' = z[29];\n""  Real 'z_extCon.shaRad.TSha_internal' = z[30];\n""  Real 'z_extCon.shaRad.u' = z[31];\n""  Real 'z_extCon.shaSig.yCom' = z[32];\n""  Real 'z_fixedHeatFlow.port.Q_flow' = z[33];\n""  Real 'z_fixedHeatFlow.port.T' = z[34];\n""  Real 'z_indRad.JIn' = z[35];\n""  Real 'z_indRad.T4' = z[36];\n""  Real 'z_indRad.heatPort.Q_flow' = z[37];\n""  Real 'z_intShaCon.QRadAbs_flow' = z[38];\n""  Real 'z_intShaCon.TSha' = z[39];\n""  Real 'z_intShaCon.conCoeGla.GCon' = z[40];\n""  Real 'z_intShaCon.conFra.Q_flow' = z[41];\n""  Real 'z_intShaCon.conFra.dT' = z[42];\n""  Real 'z_intShaCon.conFra.q_flow' = z[43];\n""  Real 'z_intShaCon.conFra.u' = z[44];\n""  Real 'z_intShaCon.conSha.Gc' = z[45];\n""  Real 'z_intShaCon.conSha.air.Q_flow' = z[46];\n""  Real 'z_intShaCon.conWinUns.Q_flow' = z[47];\n""  Real 'z_intShaCon.conWinUns.dT' = z[48];\n""  Real 'z_intShaCon.conWinUns.q_flow' = z[49];\n""  Real 'z_intShaCon.glaSha.Q_flow' = z[50];\n""  Real 'z_intShaCon.glaSha.T' = z[51];\n""  Real 'z_intShaCon.proSha.u2' = z[52];\n""  Real 'z_intShaRad.E_glass' = z[53];\n""  Real 'z_intShaRad.JIn_air' = z[54];\n""  Real 'z_intShaRad.JIn_glass' = z[55];\n""  Real 'z_intShaRad.JOut_air' = z[56];\n""  Real 'z_intShaRad.JOut_glass' = z[57];\n""  Real 'z_intShaRad.T4' = z[58];\n""  Real 'z_shaSig.y' = z[59];\n""  Real 'z_shaSig.yCom' = z[60];\n""  Real 'z_uSha.y' = z[61];\n""  Real 'z_vWin' = z[62];\n""  Real 'z_window.JInUns_b' = z[63];\n""  Real 'z_window.JOutUns_b' = z[64];\n""  Real 'z_window.fra_a.T' = z[65];\n""  Real 'z_window.fra_b.T' = z[66];\n""  Real 'z_window.frame.dT' = z[67];\n""  Real 'z_window.glaSha.glass[1].E_a' = z[68];\n""  Real 'z_window.glaSha.glass[1].E_b' = z[69];\n""  Real 'z_window.glaSha.glass[1].T4_a' = z[70];\n""  Real 'z_window.glaSha.glass[1].T4_b' = z[71];\n""  Real 'z_window.glaSha.u' = z[72];\n""  Real 'z_window.glaSha_a.T' = z[73];\n""  Real 'z_window.glaUns.glass[1].E_a' = z[74];\n""  Real 'z_window.glaUns.glass[1].E_b' = z[75];\n""  Real 'z_window.glaUns.glass[1].T4_a' = z[76];\n""  Real 'z_window.glaUns.glass[1].T4_b' = z[77];\n""  Real 'z_window.glaUns.u' = z[78];\n""  Real 'z_window.glaUns_a.T' = z[79];\n""  Real 'z_window.glaUns_b.T' = z[80];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

