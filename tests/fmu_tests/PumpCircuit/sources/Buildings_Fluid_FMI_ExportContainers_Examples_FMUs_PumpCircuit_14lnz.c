#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit.fmutmp/sources/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_14lnz.c"
#endif
/* Linearization */
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_model.h"
#if defined(__cplusplus)
extern "C" {
#endif
const char *Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_linear_model_frame()
{
  return "model linearized_model \"Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit\" \n  parameter Integer n = 2 \"number of states\";\n  parameter Integer m = 5 \"number of inputs\";\n  parameter Integer p = 8 \"number of outputs\";\n"
  "  parameter Real x0[n] = %s;\n"
  "  parameter Real u0[m] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] =\n\t[%s];\n\n"
  "  parameter Real C[p, n] =\n\t[%s];\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "\n"
  "  Real 'x_fan.filter.s[1]' = x[1];\n""  Real 'x_fan.filter.s[2]' = x[2];\n"
  "  Real 'u_TRadZon' = u[1];\n""  Real 'u_Tsup' = u[2];\n""  Real 'u_fluPor[1].backward.T' = u[3];\n""  Real 'u_fluPor[2].backward.T' = u[4];\n""  Real 'u_ovePum' = u[5];\n"
  "  Real 'y_QGaiLat_flow' = y[1];\n""  Real 'y_QGaiRad_flow' = y[2];\n""  Real 'y_QGaiSenCon_flow' = y[3];\n""  Real 'y_fluPor[1].forward.T' = y[4];\n""  Real 'y_fluPor[2].forward.T' = y[5];\n""  Real 'y_fluPor[1].m_flow' = y[6];\n""  Real 'y_fluPor[2].m_flow' = y[7];\n""  Real 'y_y' = y[8];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linearized_model;\n";
}
const char *Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_linear_model_datarecovery_frame()
{
  return "model linearized_model \"Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit\" \n parameter Integer n = 2 \"number of states\";\n  parameter Integer m = 5 \"number of inputs\";\n  parameter Integer p = 8 \"number of outputs\";\n  parameter Integer nz = 91 \"data recovery variables\";\n"
  "  parameter Real x0[2] = %s;\n"
  "  parameter Real u0[5] = %s;\n"
  "  parameter Real z0[91] = %s;\n"
  "\n"
  "  parameter Real A[n, n] =\n\t[%s];\n\n"
  "  parameter Real B[n, m] =\n\t[%s];\n\n"
  "  parameter Real C[p, n] =\n\t[%s];\n\n"
  "  parameter Real D[p, m] =\n\t[%s];\n\n"
  "  parameter Real Cz[nz, n] =\n\t[%s];\n\n"
  "  parameter Real Dz[nz, m] =\n\t[%s];\n\n"
  "\n"
  "  Real x[n](start=x0);\n"
  "  input Real u[m](start=u0);\n"
  "  output Real y[p];\n"
  "  output Real z[nz];\n"
  "\n"
  "  Real 'x_fan.filter.s[1]' = x[1];\n""  Real 'x_fan.filter.s[2]' = x[2];\n"
  "  Real 'u_TRadZon' = u[1];\n""  Real 'u_Tsup' = u[2];\n""  Real 'u_fluPor[1].backward.T' = u[3];\n""  Real 'u_fluPor[2].backward.T' = u[4];\n""  Real 'u_ovePum' = u[5];\n"
  "  Real 'y_QGaiLat_flow' = y[1];\n""  Real 'y_QGaiRad_flow' = y[2];\n""  Real 'y_QGaiSenCon_flow' = y[3];\n""  Real 'y_fluPor[1].forward.T' = y[4];\n""  Real 'y_fluPor[2].forward.T' = y[5];\n""  Real 'y_fluPor[1].m_flow' = y[6];\n""  Real 'y_fluPor[2].m_flow' = y[7];\n""  Real 'y_y' = y[8];\n"
  "  Real 'z_$cse1.T' = z[1];\n""  Real 'z_$cse1.p' = z[2];\n""  Real 'z_$cse2' = z[3];\n""  Real 'z_$cse3' = z[4];\n""  Real 'z_$cse4.T' = z[5];\n""  Real 'z_$cse4.p' = z[6];\n""  Real 'z_$cse5' = z[7];\n""  Real 'z_$cse6.T' = z[8];\n""  Real 'z_$cse6.p' = z[9];\n""  Real 'z_$cse7.T' = z[10];\n""  Real 'z_$cse7.p' = z[11];\n""  Real 'z_$cse8.T' = z[12];\n""  Real 'z_$cse8.p' = z[13];\n""  Real 'z_$cse9' = z[14];\n""  Real 'z_QGaiLat_flow' = z[15];\n""  Real 'z_QGaiRad_flow' = z[16];\n""  Real 'z_QGaiSenCon_flow' = z[17];\n""  Real 'z_TRadZon' = z[18];\n""  Real 'z_Tsup' = z[19];\n""  Real 'z_bou.X_in_internal[1]' = z[20];\n""  Real 'z_bou.p_in_internal' = z[21];\n""  Real 'z_bou.ports[1].h_outflow' = z[22];\n""  Real 'z_fan.P' = z[23];\n""  Real 'z_fan.PToMed.u1' = z[24];\n""  Real 'z_fan.VMachine_flow' = z[25];\n""  Real 'z_fan.dp' = z[26];\n""  Real 'z_fan.dpMachine' = z[27];\n""  Real 'z_fan.eff.P_internal' = z[28];\n""  Real 'z_fan.eff.WFlo' = z[29];\n""  Real 'z_fan.eff.etaMot' = z[30];\n""  Real 'z_fan.eff.eta_internal' = z[31];\n""  Real 'z_fan.eff.r_N' = z[32];\n""  Real 'z_fan.eff.r_V' = z[33];\n""  Real 'z_fan.eff.yMot' = z[34];\n""  Real 'z_fan.eta' = z[35];\n""  Real 'z_fan.filter.x[1]' = z[36];\n""  Real 'z_fan.filter.y' = z[37];\n""  Real 'z_fan.heaDis.QThe_flow' = z[38];\n""  Real 'z_fan.heaDis.etaHyd' = z[39];\n""  Real 'z_fan.heatPort.Q_flow' = z[40];\n""  Real 'z_fan.heatPort.T' = z[41];\n""  Real 'z_fan.port_a.p' = z[42];\n""  Real 'z_fan.port_b.p' = z[43];\n""  Real 'z_fan.prePow.Q_flow' = z[44];\n""  Real 'z_fan.preSou.V_flow' = z[45];\n""  Real 'z_fan.preSou.dp_internal' = z[46];\n""  Real 'z_fan.preSou.port_a.h_outflow' = z[47];\n""  Real 'z_fan.rho_inlet.y' = z[48];\n""  Real 'z_fan.senRelPre.p_rel' = z[49];\n""  Real 'z_fan.senRelPre.port_a.h_outflow' = z[50];\n""  Real 'z_fan.senRelPre.port_a.m_flow' = z[51];\n""  Real 'z_fan.senRelPre.port_b.h_outflow' = z[52];\n""  Real 'z_fan.senRelPre.port_b.m_flow' = z[53];\n""  Real 'z_fan.vol.U' = z[54];\n""  Real 'z_fan.vol.m' = z[55];\n""  Real 'z_fan.vol.ports[2].h_outflow' = z[56];\n""  Real 'z_fan.vol.steBal.dp' = z[57];\n""  Real 'z_fan.vol.steBal.mWat_flow_internal' = z[58];\n""  Real 'z_fan.vol.steBal.m_flowInv' = z[59];\n""  Real 'z_fan.vol.steBal.port_a.h_outflow' = z[60];\n""  Real 'z_fluPor[1].backward.T' = z[61];\n""  Real 'z_fluPor[2].backward.T' = z[62];\n""  Real 'z_fluPor[1].forward.T' = z[63];\n""  Real 'z_fluPor[2].forward.T' = z[64];\n""  Real 'z_fluPor[1].m_flow' = z[65];\n""  Real 'z_fluPor[2].m_flow' = z[66];\n""  Real 'z_hea.dp' = z[67];\n""  Real 'z_hea.outCon.X_wSet_internal' = z[68];\n""  Real 'z_hea.outCon.Xi_outflow' = z[69];\n""  Real 'z_hea.outCon.dXiAct' = z[70];\n""  Real 'z_hea.outCon.dhAct' = z[71];\n""  Real 'z_hea.outCon.dp' = z[72];\n""  Real 'z_hea.outCon.hSet' = z[73];\n""  Real 'z_hea.outCon.k' = z[74];\n""  Real 'z_hea.outCon.mNor_flow' = z[75];\n""  Real 'z_hea.outCon.mWat_flow' = z[76];\n""  Real 'z_hea.outCon.m_flow_non_zero' = z[77];\n""  Real 'z_hea.outCon.m_flow_pos' = z[78];\n""  Real 'z_hea.port_a.h_outflow' = z[79];\n""  Real 'z_hea.preDro.dp' = z[80];\n""  Real 'z_hvacAda.bou.X_in_internal[1]' = z[81];\n""  Real 'z_hvacAda.bou.m_flow_in_internal' = z[82];\n""  Real 'z_hvacAda.con[1].X_wZon_internal2' = z[83];\n""  Real 'z_hvacAda.con[2].X_wZon_internal2' = z[84];\n""  Real 'z_hvacAda.con[1].X_w_internal' = z[85];\n""  Real 'z_hvacAda.con[2].X_w_internal' = z[86];\n""  Real 'z_hvacAda.ports[1].h_outflow' = z[87];\n""  Real 'z_ovePum' = z[88];\n""  Real 'z_resSup.dp' = z[89];\n""  Real 'z_resSup.port_b.h_outflow' = z[90];\n""  Real 'z_y' = z[91];\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linearized_model;\n";
}
#if defined(__cplusplus)
}
#endif

