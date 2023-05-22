#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustom/Buildings_HeatTransfer_Windows_Examples_WindowCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustom_03lsy.c"
#endif
/* Linear Systems */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* linear systems */

/*
equation index: 585
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER = 100769635.3235 * intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_585(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,585};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[54]) /* window.glaSha.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (100769635.3235) * ((parentJacobian->tmpVars[35]) /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 26 OMC_FILE
  TRACE_POP
}
/*
equation index: 586
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_586(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,586};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[52]) /* window.glaSha.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((parentJacobian->tmpVars[54]) /* window.glaSha.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */));
#line 40 OMC_FILE
  TRACE_POP
}
/*
equation index: 587
type: SIMPLE_ASSIGN
intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER = shaSig.y * indRad.JIn.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_587(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,587};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (parentJacobian->tmpVars[38]) /* intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((parentJacobian->tmpVars[21]) /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 54 OMC_FILE
  TRACE_POP
}
/*
equation index: 588
type: SIMPLE_ASSIGN
window.JInUns_b.$pDERFMIDER.dummyVarFMIDER = (1.0 - shaSig.y) * indRad.JIn.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_588(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,588};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (parentJacobian->tmpVars[46]) /* window.JInUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((parentJacobian->tmpVars[21]) /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 68 OMC_FILE
  TRACE_POP
}
/*
equation index: 589
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER = -(extCon.shaCon.Gc * (TOut.SeedFMIDER - window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER) + extCon.shaCon.Gc.$pDERFMIDER.dummyVarFMIDER * (TOut - window.glaSha_a.T))
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_589(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,589};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (parentJacobian->tmpVars[11]) /* extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (-(((data->localData[0]->realVars[24] /* extCon.shaCon.Gc variable */)) * ((parentJacobian->seedVars[5]) /* TOut.SeedFMIDER SEED_VAR */ - (parentJacobian->tmpVars[56]) /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + ((parentJacobian->tmpVars[15]) /* extCon.shaCon.Gc.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[7] /* TOut variable */) - (data->localData[0]->realVars[78] /* window.glaSha_a.T variable */))));
#line 82 OMC_FILE
  TRACE_POP
}
/*
equation index: 590
type: SIMPLE_ASSIGN
extCon.JInSha.$pDERFMIDER.dummyVarFMIDER = extCon.JOutSha.$pDERFMIDER.dummyVarFMIDER - ((-0.5) * QAbsSha_flow.SeedFMIDER + extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER) - window.glaSha.u * (intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER - window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_590(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,590};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[1]) /* extCon.JInSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[3]) /* extCon.JOutSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - ((-0.5) * ((parentJacobian->seedVars[0]) /* QAbsSha_flow.SeedFMIDER SEED_VAR */) + (parentJacobian->tmpVars[11]) /* extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((parentJacobian->tmpVars[35]) /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[56]) /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-0.00375,"-0.00375"));
#line 96 OMC_FILE
  TRACE_POP
}
/*
equation index: 591
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER = 100769635.3235 * window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_591(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,591};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[53]) /* window.glaSha.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (100769635.3235) * ((parentJacobian->tmpVars[56]) /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 110 OMC_FILE
  TRACE_POP
}
/*
equation index: 592
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_592(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,592};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[51]) /* window.glaSha.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((parentJacobian->tmpVars[53]) /* window.glaSha.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */));
#line 124 OMC_FILE
  TRACE_POP
}
/*
equation index: 593
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER = 100769635.3235 * window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_593(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,593};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[59]) /* window.glaUns.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (100769635.3235) * ((parentJacobian->tmpVars[62]) /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 138 OMC_FILE
  TRACE_POP
}
/*
equation index: 594
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_594(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,594};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[57]) /* window.glaUns.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((parentJacobian->tmpVars[59]) /* window.glaUns.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */));
#line 152 OMC_FILE
  TRACE_POP
}
/*
equation index: 595
type: SIMPLE_ASSIGN
extCon.JInUns.$pDERFMIDER.dummyVarFMIDER = window.glaUns.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER + 0.16 * extCon.JOutUns.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_595(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,595};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[2]) /* extCon.JInUns.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[57]) /* window.glaUns.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (0.16) * ((parentJacobian->tmpVars[4]) /* extCon.JOutUns.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 166 OMC_FILE
  TRACE_POP
}
/*
equation index: 596
type: SIMPLE_ASSIGN
extCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER = window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER - TOut.SeedFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_596(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,596};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[10]) /* extCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[62]) /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->seedVars[5]) /* TOut.SeedFMIDER SEED_VAR */;
#line 180 OMC_FILE
  TRACE_POP
}
/*
equation index: 597
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER = extCon.conWinUns.Gc * extCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER + extCon.conWinUns.Gc.$pDERFMIDER.dummyVarFMIDER * extCon.conWinUns.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_597(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,597};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[9]) /* extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[17] /* extCon.conWinUns.Gc variable */)) * ((parentJacobian->tmpVars[10]) /* extCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + ((parentJacobian->tmpVars[8]) /* extCon.conWinUns.Gc.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[19] /* extCon.conWinUns.dT variable */));
#line 194 OMC_FILE
  TRACE_POP
}
/*
equation index: 598
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER = QAbsUns_flow.SeedFMIDER + extCon.JOutUns.$pDERFMIDER.dummyVarFMIDER + window.JInUns_b.$pDERFMIDER.dummyVarFMIDER - window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER - extCon.JInUns.$pDERFMIDER.dummyVarFMIDER - extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_598(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,598};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[31]) /* intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->seedVars[1]) /* QAbsUns_flow.SeedFMIDER SEED_VAR */ + (parentJacobian->tmpVars[4]) /* extCon.JOutUns.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[46]) /* window.JInUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[47]) /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[2]) /* extCon.JInUns.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[9]) /* extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 208 OMC_FILE
  TRACE_POP
}
/*
equation index: 599
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER = window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER - 0.16 * window.JInUns_b.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_599(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,599};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[58]) /* window.glaUns.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[47]) /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - ((0.16) * ((parentJacobian->tmpVars[46]) /* window.JInUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */));
#line 222 OMC_FILE
  TRACE_POP
}
/*
equation index: 600
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow.$pDERFMIDER.dummyVarFMIDER = 1.25 * intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_600(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,600};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (parentJacobian->tmpVars[33]) /* intShaCon.conWinUns.q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (1.25) * ((parentJacobian->tmpVars[31]) /* intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 236 OMC_FILE
  TRACE_POP
}
/*
equation index: 601
type: SIMPLE_ASSIGN
intShaRad.JOut_air.$pDERFMIDER.dummyVarFMIDER = indRad.JIn.$pDERFMIDER.dummyVarFMIDER - window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_601(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,601};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (parentJacobian->tmpVars[40]) /* intShaRad.JOut_air.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[21]) /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[47]) /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 250 OMC_FILE
  TRACE_POP
}
/*
equation index: 602
type: SIMPLE_ASSIGN
intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER = intShaRad.JOut_air.$pDERFMIDER.dummyVarFMIDER - 0.75 * intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_602(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,602};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (parentJacobian->tmpVars[37]) /* intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[40]) /* intShaRad.JOut_air.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - ((0.75) * ((parentJacobian->tmpVars[38]) /* intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */));
#line 264 OMC_FILE
  TRACE_POP
}
/*
equation index: 603
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow.$pDERFMIDER.dummyVarFMIDER = QSolAbsInt_flow.SeedFMIDER + 0.25 * (intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER + intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER) - 2.0 * intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_603(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,603};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (parentJacobian->tmpVars[23]) /* intShaCon.QRadAbs_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->seedVars[3]) /* QSolAbsInt_flow.SeedFMIDER SEED_VAR */ + (0.25) * ((parentJacobian->tmpVars[38]) /* intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[39]) /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - ((2.0) * ((parentJacobian->tmpVars[37]) /* intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */));
#line 278 OMC_FILE
  TRACE_POP
}
/*
equation index: 604
type: SIMPLE_ASSIGN
intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER = intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER + 0.75 * intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_604(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,604};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (parentJacobian->tmpVars[41]) /* intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[37]) /* intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (0.75) * ((parentJacobian->tmpVars[39]) /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 292 OMC_FILE
  TRACE_POP
}
/*
equation index: 605
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER = QAbsSha_flow.SeedFMIDER + extCon.JOutSha.$pDERFMIDER.dummyVarFMIDER + intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER - intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER - extCon.JInSha.$pDERFMIDER.dummyVarFMIDER - extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_605(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,605};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[34]) /* intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->seedVars[0]) /* QAbsSha_flow.SeedFMIDER SEED_VAR */ + (parentJacobian->tmpVars[3]) /* extCon.JOutSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[41]) /* intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[39]) /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[1]) /* extCon.JInSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[11]) /* extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 306 OMC_FILE
  TRACE_POP
}
/*
equation index: 606
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER = (-intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER) - intShaCon.QRadAbs_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_606(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,606};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (parentJacobian->tmpVars[30]) /* intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (-(parentJacobian->tmpVars[34]) /* intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[23]) /* intShaCon.QRadAbs_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 320 OMC_FILE
  TRACE_POP
}
/*
equation index: 607
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER = intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER - intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_607(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,607};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (parentJacobian->tmpVars[25]) /* intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[30]) /* intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[31]) /* intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 334 OMC_FILE
  TRACE_POP
}
/*
equation index: 608
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow.$pDERFMIDER.dummyVarFMIDER = 5.0 * intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_608(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,608};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (parentJacobian->tmpVars[27]) /* intShaCon.conFra.q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (5.0) * ((parentJacobian->tmpVars[25]) /* intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 348 OMC_FILE
  TRACE_POP
}
/*
equation index: 609
type: SIMPLE_ASSIGN
window.frame.dT.$pDERFMIDER.dummyVarFMIDER = (-intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER) / (-0.6000000000000001)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_609(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,609};
  (parentJacobian->tmpVars[50]) /* window.frame.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = DIVISION((-(parentJacobian->tmpVars[25]) /* intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */),-0.6000000000000001,"-0.6000000000000001");
  TRACE_POP
}
/*
equation index: 610
type: SIMPLE_ASSIGN
intShaRad.T4.$pDERFMIDER.dummyVarFMIDER = 25192408.83087499 * intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_610(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,610};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (parentJacobian->tmpVars[42]) /* intShaRad.T4.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (25192408.83087499) * ((parentJacobian->tmpVars[24]) /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 374 OMC_FILE
  TRACE_POP
}
/*
equation index: 611
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER = 100769635.3235 * window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_611(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,611};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (parentJacobian->tmpVars[60]) /* window.glaUns.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (100769635.3235) * ((parentJacobian->tmpVars[63]) /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 388 OMC_FILE
  TRACE_POP
}
/*
equation index: 612
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER = window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER - heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_612(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,612};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (parentJacobian->tmpVars[32]) /* intShaCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[63]) /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[20]) /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 402 OMC_FILE
  TRACE_POP
}
/*
equation index: 613
type: SIMPLE_ASSIGN
window.fra_a.T.$pDERFMIDER.dummyVarFMIDER = TOut.SeedFMIDER + extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_613(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,613};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (parentJacobian->tmpVars[48]) /* window.fra_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->seedVars[5]) /* TOut.SeedFMIDER SEED_VAR */ + (parentJacobian->tmpVars[7]) /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 416 OMC_FILE
  TRACE_POP
}
/*
equation index: 614
type: SIMPLE_ASSIGN
window.fra_b.T.$pDERFMIDER.dummyVarFMIDER = window.fra_a.T.$pDERFMIDER.dummyVarFMIDER - window.frame.dT.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_614(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,614};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (parentJacobian->tmpVars[49]) /* window.fra_b.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[48]) /* window.fra_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[50]) /* window.frame.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 430 OMC_FILE
  TRACE_POP
}
/*
equation index: 615
type: SIMPLE_ASSIGN
intShaCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER = window.fra_b.T.$pDERFMIDER.dummyVarFMIDER - heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_615(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,615};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (parentJacobian->tmpVars[26]) /* intShaCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (parentJacobian->tmpVars[49]) /* window.fra_b.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[20]) /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
#line 444 OMC_FILE
  TRACE_POP
}

void residualFunc664(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,664};
  ANALYTIC_JACOBIAN* parentJacobian = data->simulationInfo->linearSystemData[2].parDynamicData[omc_get_thread_num()].parentJacobian;
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (parentJacobian->tmpVars[7]) /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[0];
  (parentJacobian->tmpVars[20]) /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[1];
  (parentJacobian->tmpVars[63]) /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[2];
  (parentJacobian->tmpVars[24]) /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[3];
  (parentJacobian->tmpVars[39]) /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[4];
  (parentJacobian->tmpVars[47]) /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[5];
  (parentJacobian->tmpVars[62]) /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[6];
  (parentJacobian->tmpVars[56]) /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[7];
  (parentJacobian->tmpVars[21]) /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[8];
  (parentJacobian->tmpVars[35]) /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = xloc[9];
  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_585(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_586(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_587(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_588(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_589(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_590(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_591(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_592(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_593(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_594(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_595(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_596(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_597(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_598(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_599(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_600(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_601(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_602(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_603(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_604(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_605(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_606(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_607(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_608(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_609(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_610(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_611(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_612(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_613(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_614(data, threadData, jacobian, parentJacobian);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_615(data, threadData, jacobian, parentJacobian);
  res[0] = (1.134074883836886e-08) * (((data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((parentJacobian->tmpVars[42]) /* intShaRad.T4.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */)) - (parentJacobian->tmpVars[37]) /* intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[1] = (0.16) * ((parentJacobian->tmpVars[3]) /* extCon.JOutSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (parentJacobian->tmpVars[51]) /* window.glaSha.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[1]) /* extCon.JInSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[2] = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * ((parentJacobian->tmpVars[26]) /* intShaCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */)) - (parentJacobian->tmpVars[27]) /* intShaCon.conFra.q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[3] = (0.00375) * ((-0.5) * ((parentJacobian->seedVars[1]) /* QAbsUns_flow.SeedFMIDER SEED_VAR */) + (parentJacobian->tmpVars[2]) /* extCon.JInUns.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ + (parentJacobian->tmpVars[9]) /* extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[4]) /* extCon.JOutUns.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + ((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((parentJacobian->tmpVars[62]) /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[63]) /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);

  res[4] = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((parentJacobian->tmpVars[60]) /* window.glaUns.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */)) - (parentJacobian->tmpVars[58]) /* window.glaUns.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[5] = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * ((parentJacobian->tmpVars[32]) /* intShaCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */)) - (parentJacobian->tmpVars[33]) /* intShaCon.conWinUns.q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[6] = ((parentJacobian->tmpVars[5]) /* extCon.conCoeFra.GCon.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[16] /* extCon.conFra.dT variable */)) + ((data->localData[0]->realVars[14] /* extCon.conCoeFra.GCon variable */)) * ((parentJacobian->tmpVars[7]) /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (parentJacobian->tmpVars[25]) /* intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[7] = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * ((parentJacobian->tmpVars[20]) /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[24]) /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (parentJacobian->tmpVars[20]) /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[35]) /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[30]) /* intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[8] = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * ((parentJacobian->tmpVars[35]) /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (-(parentJacobian->tmpVars[20]) /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[24]) /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) - (parentJacobian->tmpVars[34]) /* intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;

  res[9] = (0.16) * ((parentJacobian->tmpVars[41]) /* intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) + (parentJacobian->tmpVars[52]) /* window.glaSha.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ - (parentJacobian->tmpVars[39]) /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */;
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData664(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[7].attribute /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[7].attribute /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[7].attribute /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[20].attribute /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[20].attribute /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[20].attribute /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[63].attribute /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[63].attribute /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[63].attribute /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[24].attribute /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[24].attribute /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[24].attribute /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[39].attribute /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[39].attribute /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[39].attribute /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[47].attribute /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[47].attribute /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[47].attribute /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[62].attribute /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[62].attribute /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[62].attribute /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[56].attribute /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[56].attribute /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[56].attribute /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for indRad.JIn.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[21].attribute /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[21].attribute /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[21].attribute /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER */.max;
  /* static ls data for intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER */
  linearSystemData->nominal[i] = data->modelData->realVarsData[35].attribute /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[35].attribute /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[35].attribute /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER */.max;
}


/*
equation index: 138
type: SIMPLE_ASSIGN
window.glaSha.glass[1].T4_b = -22155463946.31301 + 100769635.3235 * intShaCon.glaSha.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[76] /* window.glaSha.glass[1].T4_b variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */));
#line 637 OMC_FILE
  TRACE_POP
}
/*
equation index: 139
type: SIMPLE_ASSIGN
window.glaSha.glass[1].E_b = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass[1].T4_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[74] /* window.glaSha.glass[1].E_b variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[76] /* window.glaSha.glass[1].T4_b variable */)));
#line 651 OMC_FILE
  TRACE_POP
}
/*
equation index: 140
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow = (-extCon.shaCon.Gc) * (TOut - window.glaSha_a.T)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[20] /* extCon.glaSha.Q_flow variable */) = ((-(data->localData[0]->realVars[24] /* extCon.shaCon.Gc variable */))) * ((data->localData[0]->realVars[7] /* TOut variable */) - (data->localData[0]->realVars[78] /* window.glaSha_a.T variable */));
#line 665 OMC_FILE
  TRACE_POP
}
/*
equation index: 141
type: SIMPLE_ASSIGN
extCon.JInSha = extCon.JOutSha - ((-0.5) * QAbsSha_flow + extCon.glaSha.Q_flow) - window.glaSha.u * (intShaCon.glaSha.T - window.glaSha_a.T) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[10] /* extCon.JInSha variable */) = (data->localData[0]->realVars[12] /* extCon.JOutSha variable */) - ((-0.5) * ((data->localData[0]->realVars[0] /* QAbsSha_flow variable */)) + (data->localData[0]->realVars[20] /* extCon.glaSha.Q_flow variable */)) - (DIVISION_SIM(((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */) - (data->localData[0]->realVars[78] /* window.glaSha_a.T variable */)),-0.00375,"-0.00375",equationIndexes));
#line 679 OMC_FILE
  TRACE_POP
}
/*
equation index: 142
type: SIMPLE_ASSIGN
window.glaSha.glass[1].T4_a = -22155463946.31301 + 100769635.3235 * window.glaSha_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[75] /* window.glaSha.glass[1].T4_a variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[78] /* window.glaSha_a.T variable */));
#line 693 OMC_FILE
  TRACE_POP
}
/*
equation index: 143
type: SIMPLE_ASSIGN
window.glaSha.glass[1].E_a = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass[1].T4_a
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[73] /* window.glaSha.glass[1].E_a variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[75] /* window.glaSha.glass[1].T4_a variable */)));
#line 707 OMC_FILE
  TRACE_POP
}
/*
equation index: 144
type: SIMPLE_ASSIGN
window.JInUns_b = (1.0 - shaSig.y) * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[68] /* window.JInUns_b variable */) = (1.0 - (data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((data->localData[0]->realVars[37] /* indRad.JIn variable */));
#line 721 OMC_FILE
  TRACE_POP
}
/*
equation index: 145
type: SIMPLE_ASSIGN
intShaRad.JIn_air = shaSig.y * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[57] /* intShaRad.JIn_air variable */) = ((data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((data->localData[0]->realVars[37] /* indRad.JIn variable */));
#line 735 OMC_FILE
  TRACE_POP
}
/*
equation index: 146
type: SIMPLE_ASSIGN
window.glaUns.glass[1].T4_a = -22155463946.31301 + 100769635.3235 * window.glaUns_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[81] /* window.glaUns.glass[1].T4_a variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[84] /* window.glaUns_a.T variable */));
#line 749 OMC_FILE
  TRACE_POP
}
/*
equation index: 147
type: SIMPLE_ASSIGN
window.glaUns.glass[1].E_a = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass[1].T4_a
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[79] /* window.glaUns.glass[1].E_a variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[81] /* window.glaUns.glass[1].T4_a variable */)));
#line 763 OMC_FILE
  TRACE_POP
}
/*
equation index: 148
type: SIMPLE_ASSIGN
extCon.conWinUns.dT = window.glaUns_a.T - TOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[19] /* extCon.conWinUns.dT variable */) = (data->localData[0]->realVars[84] /* window.glaUns_a.T variable */) - (data->localData[0]->realVars[7] /* TOut variable */);
#line 777 OMC_FILE
  TRACE_POP
}
/*
equation index: 149
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow = extCon.conWinUns.Gc * extCon.conWinUns.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[18] /* extCon.conWinUns.Q_flow variable */) = ((data->localData[0]->realVars[17] /* extCon.conWinUns.Gc variable */)) * ((data->localData[0]->realVars[19] /* extCon.conWinUns.dT variable */));
#line 791 OMC_FILE
  TRACE_POP
}
/*
equation index: 150
type: SIMPLE_ASSIGN
extCon.JInUns = window.glaUns.glass[1].E_a + 0.16 * extCon.JOutUns
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[11] /* extCon.JInUns variable */) = (data->localData[0]->realVars[79] /* window.glaUns.glass[1].E_a variable */) + (0.16) * ((data->localData[0]->realVars[13] /* extCon.JOutUns variable */));
#line 805 OMC_FILE
  TRACE_POP
}
/*
equation index: 151
type: SIMPLE_ASSIGN
intShaRad.T4 = 25192408.83087499 * intShaCon.TSha
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[61] /* intShaRad.T4 variable */) = (25192408.83087499) * ((data->localData[0]->realVars[41] /* intShaCon.TSha variable */));
#line 819 OMC_FILE
  TRACE_POP
}
/*
equation index: 152
type: SIMPLE_ASSIGN
intShaRad.E_glass = 1.134074883836886e-08 * shaSig.y * intShaRad.T4
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[56] /* intShaRad.E_glass variable */) = (1.134074883836886e-08) * (((data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((data->localData[0]->realVars[61] /* intShaRad.T4 variable */)));
#line 833 OMC_FILE
  TRACE_POP
}
/*
equation index: 153
type: SIMPLE_ASSIGN
intShaRad.JOut_air = intShaRad.E_glass + 0.75 * intShaRad.JIn_air
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[59] /* intShaRad.JOut_air variable */) = (data->localData[0]->realVars[56] /* intShaRad.E_glass variable */) + (0.75) * ((data->localData[0]->realVars[57] /* intShaRad.JIn_air variable */));
#line 847 OMC_FILE
  TRACE_POP
}
/*
equation index: 154
type: SIMPLE_ASSIGN
window.JOutUns_b = indRad.JIn - intShaRad.JOut_air
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[69] /* window.JOutUns_b variable */) = (data->localData[0]->realVars[37] /* indRad.JIn variable */) - (data->localData[0]->realVars[59] /* intShaRad.JOut_air variable */);
#line 861 OMC_FILE
  TRACE_POP
}
/*
equation index: 155
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow = QAbsUns_flow + extCon.JOutUns + window.JInUns_b - extCon.conWinUns.Q_flow - window.JOutUns_b - extCon.JInUns
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[50] /* intShaCon.conWinUns.Q_flow variable */) = (data->localData[0]->realVars[1] /* QAbsUns_flow variable */) + (data->localData[0]->realVars[13] /* extCon.JOutUns variable */) + (data->localData[0]->realVars[68] /* window.JInUns_b variable */) - (data->localData[0]->realVars[18] /* extCon.conWinUns.Q_flow variable */) - (data->localData[0]->realVars[69] /* window.JOutUns_b variable */) - (data->localData[0]->realVars[11] /* extCon.JInUns variable */);
#line 875 OMC_FILE
  TRACE_POP
}
/*
equation index: 156
type: SIMPLE_ASSIGN
window.glaUns.glass[1].E_b = window.JOutUns_b - 0.16 * window.JInUns_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[80] /* window.glaUns.glass[1].E_b variable */) = (data->localData[0]->realVars[69] /* window.JOutUns_b variable */) - ((0.16) * ((data->localData[0]->realVars[68] /* window.JInUns_b variable */)));
#line 889 OMC_FILE
  TRACE_POP
}
/*
equation index: 157
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow = 1.25 * intShaCon.conWinUns.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,157};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[52] /* intShaCon.conWinUns.q_flow variable */) = (1.25) * ((data->localData[0]->realVars[50] /* intShaCon.conWinUns.Q_flow variable */));
#line 903 OMC_FILE
  TRACE_POP
}
/*
equation index: 158
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow = intShaCon.conSha.Gc * (2.0 * (heatFlowSensor1.port_a.T - intShaCon.TSha) + heatFlowSensor1.port_a.T - intShaCon.glaSha.T)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[49] /* intShaCon.conSha.air.Q_flow variable */) = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * ((data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */) - (data->localData[0]->realVars[41] /* intShaCon.TSha variable */)) + (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */) - (data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */));
#line 917 OMC_FILE
  TRACE_POP
}
/*
equation index: 159
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow = intShaCon.conSha.Gc * (2.0 * intShaCon.glaSha.T + (-heatFlowSensor1.port_a.T) - intShaCon.TSha)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,159};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[53] /* intShaCon.glaSha.Q_flow variable */) = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * ((data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */)) + (-(data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */)) - (data->localData[0]->realVars[41] /* intShaCon.TSha variable */));
#line 931 OMC_FILE
  TRACE_POP
}
/*
equation index: 160
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow = intShaCon.conSha.air.Q_flow - intShaCon.conWinUns.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[44] /* intShaCon.conFra.Q_flow variable */) = (data->localData[0]->realVars[49] /* intShaCon.conSha.air.Q_flow variable */) - (data->localData[0]->realVars[50] /* intShaCon.conWinUns.Q_flow variable */);
#line 945 OMC_FILE
  TRACE_POP
}
/*
equation index: 161
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow = (-intShaCon.conSha.air.Q_flow) - intShaCon.glaSha.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,161};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[40] /* intShaCon.QRadAbs_flow variable */) = (-(data->localData[0]->realVars[49] /* intShaCon.conSha.air.Q_flow variable */)) - (data->localData[0]->realVars[53] /* intShaCon.glaSha.Q_flow variable */);
#line 959 OMC_FILE
  TRACE_POP
}
/*
equation index: 162
type: SIMPLE_ASSIGN
intShaRad.JIn_glass = 8.0 * intShaRad.E_glass + 4.0 * intShaCon.QRadAbs_flow - (4.0 * QSolAbsInt_flow + intShaRad.JIn_air)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */) = (8.0) * ((data->localData[0]->realVars[56] /* intShaRad.E_glass variable */)) + (4.0) * ((data->localData[0]->realVars[40] /* intShaCon.QRadAbs_flow variable */)) - ((4.0) * ((data->localData[0]->realVars[4] /* QSolAbsInt_flow variable */)) + (data->localData[0]->realVars[57] /* intShaRad.JIn_air variable */));
#line 973 OMC_FILE
  TRACE_POP
}
/*
equation index: 163
type: SIMPLE_ASSIGN
intShaRad.JOut_glass = extCon.JInSha - (QAbsSha_flow + extCon.JOutSha - intShaCon.glaSha.Q_flow - extCon.glaSha.Q_flow - intShaRad.JIn_glass)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,163};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[60] /* intShaRad.JOut_glass variable */) = (data->localData[0]->realVars[10] /* extCon.JInSha variable */) - ((data->localData[0]->realVars[0] /* QAbsSha_flow variable */) + (data->localData[0]->realVars[12] /* extCon.JOutSha variable */) - (data->localData[0]->realVars[53] /* intShaCon.glaSha.Q_flow variable */) - (data->localData[0]->realVars[20] /* extCon.glaSha.Q_flow variable */) - (data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */));
#line 987 OMC_FILE
  TRACE_POP
}
/*
equation index: 164
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow = 5.0 * intShaCon.conFra.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[46] /* intShaCon.conFra.q_flow variable */) = (5.0) * ((data->localData[0]->realVars[44] /* intShaCon.conFra.Q_flow variable */));
#line 1001 OMC_FILE
  TRACE_POP
}
/*
equation index: 165
type: SIMPLE_ASSIGN
window.frame.dT = 0.3333333333333333 * intShaCon.conFra.q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
  (data->localData[0]->realVars[72] /* window.frame.dT variable */) = (0.3333333333333333) * ((data->localData[0]->realVars[46] /* intShaCon.conFra.q_flow variable */));
  TRACE_POP
}
/*
equation index: 166
type: SIMPLE_ASSIGN
window.glaUns.glass[1].T4_b = -22155463946.31301 + 100769635.3235 * window.glaUns_b.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[82] /* window.glaUns.glass[1].T4_b variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[85] /* window.glaUns_b.T variable */));
#line 1027 OMC_FILE
  TRACE_POP
}
/*
equation index: 167
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT = window.glaUns_b.T - heatFlowSensor1.port_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[51] /* intShaCon.conWinUns.dT variable */) = (data->localData[0]->realVars[85] /* window.glaUns_b.T variable */) - (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */);
#line 1041 OMC_FILE
  TRACE_POP
}
/*
equation index: 168
type: SIMPLE_ASSIGN
window.fra_a.T = window.fra_b.T + window.frame.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[70] /* window.fra_a.T variable */) = (data->localData[0]->realVars[71] /* window.fra_b.T variable */) + (data->localData[0]->realVars[72] /* window.frame.dT variable */);
#line 1055 OMC_FILE
  TRACE_POP
}
/*
equation index: 169
type: SIMPLE_ASSIGN
intShaCon.conFra.dT = window.fra_b.T - heatFlowSensor1.port_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[45] /* intShaCon.conFra.dT variable */) = (data->localData[0]->realVars[71] /* window.fra_b.T variable */) - (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */);
#line 1069 OMC_FILE
  TRACE_POP
}
/*
equation index: 170
type: SIMPLE_ASSIGN
extCon.conFra.dT = window.fra_a.T - TOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[16] /* extCon.conFra.dT variable */) = (data->localData[0]->realVars[70] /* window.fra_a.T variable */) - (data->localData[0]->realVars[7] /* TOut variable */);
#line 1083 OMC_FILE
  TRACE_POP
}

void residualFunc217(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,217};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[71] /* window.fra_b.T variable */) = xloc[0];
  (data->localData[0]->realVars[85] /* window.glaUns_b.T variable */) = xloc[1];
  (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */) = xloc[2];
  (data->localData[0]->realVars[41] /* intShaCon.TSha variable */) = xloc[3];
  (data->localData[0]->realVars[84] /* window.glaUns_a.T variable */) = xloc[4];
  (data->localData[0]->realVars[37] /* indRad.JIn variable */) = xloc[5];
  (data->localData[0]->realVars[78] /* window.glaSha_a.T variable */) = xloc[6];
  (data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */) = xloc[7];
  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_138(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_139(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_140(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_141(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_142(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_143(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_144(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_145(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_146(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_147(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_148(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_149(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_150(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_151(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_152(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_153(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_154(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_155(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_156(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_157(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_158(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_159(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_160(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_161(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_162(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_163(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_164(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_165(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_166(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_167(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_168(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_169(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_170(data, threadData);
  res[0] = ((data->localData[0]->realVars[14] /* extCon.conCoeFra.GCon variable */)) * ((data->localData[0]->realVars[16] /* extCon.conFra.dT variable */)) + (data->localData[0]->realVars[44] /* intShaCon.conFra.Q_flow variable */);

  res[1] = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * ((data->localData[0]->realVars[45] /* intShaCon.conFra.dT variable */))) - (data->localData[0]->realVars[46] /* intShaCon.conFra.q_flow variable */);

  res[2] = (0.75) * ((data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */)) + (data->localData[0]->realVars[56] /* intShaRad.E_glass variable */) - (data->localData[0]->realVars[60] /* intShaRad.JOut_glass variable */);

  res[3] = (0.16) * ((data->localData[0]->realVars[60] /* intShaRad.JOut_glass variable */)) + (data->localData[0]->realVars[74] /* window.glaSha.glass[1].E_b variable */) - (data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */);

  res[4] = (0.16) * ((data->localData[0]->realVars[12] /* extCon.JOutSha variable */)) + (data->localData[0]->realVars[73] /* window.glaSha.glass[1].E_a variable */) - (data->localData[0]->realVars[10] /* extCon.JInSha variable */);

  res[5] = (0.00375) * ((-0.5) * ((data->localData[0]->realVars[1] /* QAbsUns_flow variable */)) + (data->localData[0]->realVars[11] /* extCon.JInUns variable */) + (data->localData[0]->realVars[18] /* extCon.conWinUns.Q_flow variable */) - (data->localData[0]->realVars[13] /* extCon.JOutUns variable */)) + ((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[84] /* window.glaUns_a.T variable */) - (data->localData[0]->realVars[85] /* window.glaUns_b.T variable */));

  res[6] = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * ((data->localData[0]->realVars[51] /* intShaCon.conWinUns.dT variable */))) - (data->localData[0]->realVars[52] /* intShaCon.conWinUns.q_flow variable */);

  res[7] = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[82] /* window.glaUns.glass[1].T4_b variable */))) - (data->localData[0]->realVars[80] /* window.glaUns.glass[1].E_b variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData217(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for window.fra_b.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[71].attribute /* window.fra_b.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[71].attribute /* window.fra_b.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[71].attribute /* window.fra_b.T */.max;
  /* static ls data for window.glaUns_b.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[85].attribute /* window.glaUns_b.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[85].attribute /* window.glaUns_b.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[85].attribute /* window.glaUns_b.T */.max;
  /* static ls data for heatFlowSensor1.port_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[35].attribute /* heatFlowSensor1.port_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[35].attribute /* heatFlowSensor1.port_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[35].attribute /* heatFlowSensor1.port_a.T */.max;
  /* static ls data for intShaCon.TSha */
  linearSystemData->nominal[i] = data->modelData->realVarsData[41].attribute /* intShaCon.TSha */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[41].attribute /* intShaCon.TSha */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[41].attribute /* intShaCon.TSha */.max;
  /* static ls data for window.glaUns_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[84].attribute /* window.glaUns_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[84].attribute /* window.glaUns_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[84].attribute /* window.glaUns_a.T */.max;
  /* static ls data for indRad.JIn */
  linearSystemData->nominal[i] = data->modelData->realVarsData[37].attribute /* indRad.JIn */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[37].attribute /* indRad.JIn */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[37].attribute /* indRad.JIn */.max;
  /* static ls data for window.glaSha_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[78].attribute /* window.glaSha_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[78].attribute /* window.glaSha_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[78].attribute /* window.glaSha_a.T */.max;
  /* static ls data for intShaCon.glaSha.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[54].attribute /* intShaCon.glaSha.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[54].attribute /* intShaCon.glaSha.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[54].attribute /* intShaCon.glaSha.T */.max;
}


/*
equation index: 32
type: SIMPLE_ASSIGN
window.glaSha.glass[1].T4_b = -22155463946.31301 + 100769635.3235 * intShaCon.glaSha.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[76] /* window.glaSha.glass[1].T4_b variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */));
#line 1267 OMC_FILE
  TRACE_POP
}
/*
equation index: 33
type: SIMPLE_ASSIGN
window.glaSha.glass[1].E_b = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass[1].T4_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[74] /* window.glaSha.glass[1].E_b variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[76] /* window.glaSha.glass[1].T4_b variable */)));
#line 1281 OMC_FILE
  TRACE_POP
}
/*
equation index: 34
type: SIMPLE_ASSIGN
window.JInUns_b = (1.0 - shaSig.y) * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[68] /* window.JInUns_b variable */) = (1.0 - (data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((data->localData[0]->realVars[37] /* indRad.JIn variable */));
#line 1295 OMC_FILE
  TRACE_POP
}
/*
equation index: 35
type: SIMPLE_ASSIGN
intShaRad.JIn_air = shaSig.y * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[57] /* intShaRad.JIn_air variable */) = ((data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((data->localData[0]->realVars[37] /* indRad.JIn variable */));
#line 1309 OMC_FILE
  TRACE_POP
}
/*
equation index: 36
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow = (-extCon.shaCon.Gc) * (TOut - window.glaSha_a.T)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[20] /* extCon.glaSha.Q_flow variable */) = ((-(data->localData[0]->realVars[24] /* extCon.shaCon.Gc variable */))) * ((data->localData[0]->realVars[7] /* TOut variable */) - (data->localData[0]->realVars[78] /* window.glaSha_a.T variable */));
#line 1323 OMC_FILE
  TRACE_POP
}
/*
equation index: 37
type: SIMPLE_ASSIGN
extCon.JInSha = extCon.JOutSha - ((-0.5) * QAbsSha_flow + extCon.glaSha.Q_flow) - window.glaSha.u * (intShaCon.glaSha.T - window.glaSha_a.T) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[10] /* extCon.JInSha variable */) = (data->localData[0]->realVars[12] /* extCon.JOutSha variable */) - ((-0.5) * ((data->localData[0]->realVars[0] /* QAbsSha_flow variable */)) + (data->localData[0]->realVars[20] /* extCon.glaSha.Q_flow variable */)) - (DIVISION_SIM(((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */) - (data->localData[0]->realVars[78] /* window.glaSha_a.T variable */)),-0.00375,"-0.00375",equationIndexes));
#line 1337 OMC_FILE
  TRACE_POP
}
/*
equation index: 38
type: SIMPLE_ASSIGN
window.glaSha.glass[1].T4_a = -22155463946.31301 + 100769635.3235 * window.glaSha_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[75] /* window.glaSha.glass[1].T4_a variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[78] /* window.glaSha_a.T variable */));
#line 1351 OMC_FILE
  TRACE_POP
}
/*
equation index: 39
type: SIMPLE_ASSIGN
window.glaSha.glass[1].E_a = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass[1].T4_a
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[73] /* window.glaSha.glass[1].E_a variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * ((data->localData[0]->realVars[75] /* window.glaSha.glass[1].T4_a variable */)));
#line 1365 OMC_FILE
  TRACE_POP
}
/*
equation index: 40
type: SIMPLE_ASSIGN
window.glaUns.glass[1].T4_a = -22155463946.31301 + 100769635.3235 * window.glaUns_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[81] /* window.glaUns.glass[1].T4_a variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[84] /* window.glaUns_a.T variable */));
#line 1379 OMC_FILE
  TRACE_POP
}
/*
equation index: 41
type: SIMPLE_ASSIGN
window.glaUns.glass[1].E_a = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass[1].T4_a
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[79] /* window.glaUns.glass[1].E_a variable */) = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[81] /* window.glaUns.glass[1].T4_a variable */)));
#line 1393 OMC_FILE
  TRACE_POP
}
/*
equation index: 42
type: SIMPLE_ASSIGN
extCon.JInUns = window.glaUns.glass[1].E_a + 0.16 * extCon.JOutUns
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[11] /* extCon.JInUns variable */) = (data->localData[0]->realVars[79] /* window.glaUns.glass[1].E_a variable */) + (0.16) * ((data->localData[0]->realVars[13] /* extCon.JOutUns variable */));
#line 1407 OMC_FILE
  TRACE_POP
}
/*
equation index: 43
type: SIMPLE_ASSIGN
extCon.conWinUns.dT = window.glaUns_a.T - TOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[19] /* extCon.conWinUns.dT variable */) = (data->localData[0]->realVars[84] /* window.glaUns_a.T variable */) - (data->localData[0]->realVars[7] /* TOut variable */);
#line 1421 OMC_FILE
  TRACE_POP
}
/*
equation index: 44
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow = extCon.conWinUns.Gc * extCon.conWinUns.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[18] /* extCon.conWinUns.Q_flow variable */) = ((data->localData[0]->realVars[17] /* extCon.conWinUns.Gc variable */)) * ((data->localData[0]->realVars[19] /* extCon.conWinUns.dT variable */));
#line 1435 OMC_FILE
  TRACE_POP
}
/*
equation index: 45
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow = QAbsUns_flow + extCon.JOutUns + window.JInUns_b - extCon.conWinUns.Q_flow - window.JOutUns_b - extCon.JInUns
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[50] /* intShaCon.conWinUns.Q_flow variable */) = (data->localData[0]->realVars[1] /* QAbsUns_flow variable */) + (data->localData[0]->realVars[13] /* extCon.JOutUns variable */) + (data->localData[0]->realVars[68] /* window.JInUns_b variable */) - (data->localData[0]->realVars[18] /* extCon.conWinUns.Q_flow variable */) - (data->localData[0]->realVars[69] /* window.JOutUns_b variable */) - (data->localData[0]->realVars[11] /* extCon.JInUns variable */);
#line 1449 OMC_FILE
  TRACE_POP
}
/*
equation index: 46
type: SIMPLE_ASSIGN
window.glaUns.glass[1].E_b = window.JOutUns_b - 0.16 * window.JInUns_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[80] /* window.glaUns.glass[1].E_b variable */) = (data->localData[0]->realVars[69] /* window.JOutUns_b variable */) - ((0.16) * ((data->localData[0]->realVars[68] /* window.JInUns_b variable */)));
#line 1463 OMC_FILE
  TRACE_POP
}
/*
equation index: 47
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow = 1.25 * intShaCon.conWinUns.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[52] /* intShaCon.conWinUns.q_flow variable */) = (1.25) * ((data->localData[0]->realVars[50] /* intShaCon.conWinUns.Q_flow variable */));
#line 1477 OMC_FILE
  TRACE_POP
}
/*
equation index: 48
type: SIMPLE_ASSIGN
intShaRad.JOut_air = indRad.JIn - window.JOutUns_b
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[59] /* intShaRad.JOut_air variable */) = (data->localData[0]->realVars[37] /* indRad.JIn variable */) - (data->localData[0]->realVars[69] /* window.JOutUns_b variable */);
#line 1491 OMC_FILE
  TRACE_POP
}
/*
equation index: 49
type: SIMPLE_ASSIGN
intShaRad.E_glass = intShaRad.JOut_air - 0.75 * intShaRad.JIn_air
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[56] /* intShaRad.E_glass variable */) = (data->localData[0]->realVars[59] /* intShaRad.JOut_air variable */) - ((0.75) * ((data->localData[0]->realVars[57] /* intShaRad.JIn_air variable */)));
#line 1505 OMC_FILE
  TRACE_POP
}
/*
equation index: 50
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow = QSolAbsInt_flow + 0.25 * (intShaRad.JIn_air + intShaRad.JIn_glass) - 2.0 * intShaRad.E_glass
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[40] /* intShaCon.QRadAbs_flow variable */) = (data->localData[0]->realVars[4] /* QSolAbsInt_flow variable */) + (0.25) * ((data->localData[0]->realVars[57] /* intShaRad.JIn_air variable */) + (data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */)) - ((2.0) * ((data->localData[0]->realVars[56] /* intShaRad.E_glass variable */)));
#line 1519 OMC_FILE
  TRACE_POP
}
/*
equation index: 51
type: SIMPLE_ASSIGN
intShaRad.JOut_glass = intShaRad.E_glass + 0.75 * intShaRad.JIn_glass
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[60] /* intShaRad.JOut_glass variable */) = (data->localData[0]->realVars[56] /* intShaRad.E_glass variable */) + (0.75) * ((data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */));
#line 1533 OMC_FILE
  TRACE_POP
}
/*
equation index: 52
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow = QAbsSha_flow + extCon.JOutSha + intShaRad.JOut_glass - extCon.glaSha.Q_flow - intShaRad.JIn_glass - extCon.JInSha
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[53] /* intShaCon.glaSha.Q_flow variable */) = (data->localData[0]->realVars[0] /* QAbsSha_flow variable */) + (data->localData[0]->realVars[12] /* extCon.JOutSha variable */) + (data->localData[0]->realVars[60] /* intShaRad.JOut_glass variable */) - (data->localData[0]->realVars[20] /* extCon.glaSha.Q_flow variable */) - (data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */) - (data->localData[0]->realVars[10] /* extCon.JInSha variable */);
#line 1547 OMC_FILE
  TRACE_POP
}
/*
equation index: 53
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow = (-intShaCon.glaSha.Q_flow) - intShaCon.QRadAbs_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[49] /* intShaCon.conSha.air.Q_flow variable */) = (-(data->localData[0]->realVars[53] /* intShaCon.glaSha.Q_flow variable */)) - (data->localData[0]->realVars[40] /* intShaCon.QRadAbs_flow variable */);
#line 1561 OMC_FILE
  TRACE_POP
}
/*
equation index: 54
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow = intShaCon.conSha.air.Q_flow - intShaCon.conWinUns.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[44] /* intShaCon.conFra.Q_flow variable */) = (data->localData[0]->realVars[49] /* intShaCon.conSha.air.Q_flow variable */) - (data->localData[0]->realVars[50] /* intShaCon.conWinUns.Q_flow variable */);
#line 1575 OMC_FILE
  TRACE_POP
}
/*
equation index: 55
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow = 5.0 * intShaCon.conFra.Q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[46] /* intShaCon.conFra.q_flow variable */) = (5.0) * ((data->localData[0]->realVars[44] /* intShaCon.conFra.Q_flow variable */));
#line 1589 OMC_FILE
  TRACE_POP
}
/*
equation index: 56
type: SIMPLE_ASSIGN
window.frame.dT = 0.3333333333333333 * intShaCon.conFra.q_flow
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
  (data->localData[0]->realVars[72] /* window.frame.dT variable */) = (0.3333333333333333) * ((data->localData[0]->realVars[46] /* intShaCon.conFra.q_flow variable */));
  TRACE_POP
}
/*
equation index: 57
type: SIMPLE_ASSIGN
intShaRad.T4 = 25192408.83087499 * intShaCon.TSha
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  (data->localData[0]->realVars[61] /* intShaRad.T4 variable */) = (25192408.83087499) * ((data->localData[0]->realVars[41] /* intShaCon.TSha variable */));
#line 1615 OMC_FILE
  TRACE_POP
}
/*
equation index: 58
type: SIMPLE_ASSIGN
window.glaUns.glass[1].T4_b = -22155463946.31301 + 100769635.3235 * window.glaUns_b.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  (data->localData[0]->realVars[82] /* window.glaUns.glass[1].T4_b variable */) = -22155463946.31301 + (100769635.3235) * ((data->localData[0]->realVars[85] /* window.glaUns_b.T variable */));
#line 1629 OMC_FILE
  TRACE_POP
}
/*
equation index: 59
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT = window.glaUns_b.T - heatFlowSensor1.port_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[51] /* intShaCon.conWinUns.dT variable */) = (data->localData[0]->realVars[85] /* window.glaUns_b.T variable */) - (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */);
#line 1643 OMC_FILE
  TRACE_POP
}
/*
equation index: 60
type: SIMPLE_ASSIGN
intShaCon.conFra.dT = window.fra_b.T - heatFlowSensor1.port_a.T
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  (data->localData[0]->realVars[45] /* intShaCon.conFra.dT variable */) = (data->localData[0]->realVars[71] /* window.fra_b.T variable */) - (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */);
#line 1657 OMC_FILE
  TRACE_POP
}
/*
equation index: 61
type: SIMPLE_ASSIGN
window.fra_a.T = window.fra_b.T + window.frame.dT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[70] /* window.fra_a.T variable */) = (data->localData[0]->realVars[71] /* window.fra_b.T variable */) + (data->localData[0]->realVars[72] /* window.frame.dT variable */);
#line 1671 OMC_FILE
  TRACE_POP
}
/*
equation index: 62
type: SIMPLE_ASSIGN
extCon.conFra.dT = window.fra_a.T - TOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  (data->localData[0]->realVars[16] /* extCon.conFra.dT variable */) = (data->localData[0]->realVars[70] /* window.fra_a.T variable */) - (data->localData[0]->realVars[7] /* TOut variable */);
#line 1685 OMC_FILE
  TRACE_POP
}

void residualFunc111(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,111};
  ANALYTIC_JACOBIAN* jacobian = NULL;
  (data->localData[0]->realVars[71] /* window.fra_b.T variable */) = xloc[0];
  (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */) = xloc[1];
  (data->localData[0]->realVars[85] /* window.glaUns_b.T variable */) = xloc[2];
  (data->localData[0]->realVars[41] /* intShaCon.TSha variable */) = xloc[3];
  (data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */) = xloc[4];
  (data->localData[0]->realVars[69] /* window.JOutUns_b variable */) = xloc[5];
  (data->localData[0]->realVars[84] /* window.glaUns_a.T variable */) = xloc[6];
  (data->localData[0]->realVars[78] /* window.glaSha_a.T variable */) = xloc[7];
  (data->localData[0]->realVars[37] /* indRad.JIn variable */) = xloc[8];
  (data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */) = xloc[9];
  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_32(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_33(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_34(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_35(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_36(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_37(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_38(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_39(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_40(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_41(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_42(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_43(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_44(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_45(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_46(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_47(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_48(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_49(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_50(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_51(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_52(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_53(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_54(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_55(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_56(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_57(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_58(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_59(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_60(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_61(data, threadData);

  /* local constraints */
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_62(data, threadData);
  res[0] = (0.16) * ((data->localData[0]->realVars[12] /* extCon.JOutSha variable */)) + (data->localData[0]->realVars[73] /* window.glaSha.glass[1].E_a variable */) - (data->localData[0]->realVars[10] /* extCon.JInSha variable */);

  res[1] = ((data->localData[0]->realVars[14] /* extCon.conCoeFra.GCon variable */)) * ((data->localData[0]->realVars[16] /* extCon.conFra.dT variable */)) + (data->localData[0]->realVars[44] /* intShaCon.conFra.Q_flow variable */);

  res[2] = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * ((data->localData[0]->realVars[45] /* intShaCon.conFra.dT variable */))) - (data->localData[0]->realVars[46] /* intShaCon.conFra.q_flow variable */);

  res[3] = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * ((data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */)) + (-(data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */)) - (data->localData[0]->realVars[41] /* intShaCon.TSha variable */)) - (data->localData[0]->realVars[53] /* intShaCon.glaSha.Q_flow variable */);

  res[4] = (0.16) * ((data->localData[0]->realVars[60] /* intShaRad.JOut_glass variable */)) + (data->localData[0]->realVars[74] /* window.glaSha.glass[1].E_b variable */) - (data->localData[0]->realVars[58] /* intShaRad.JIn_glass variable */);

  res[5] = (1.134074883836886e-08) * (((data->localData[0]->realVars[62] /* shaSig.y variable */)) * ((data->localData[0]->realVars[61] /* intShaRad.T4 variable */))) - (data->localData[0]->realVars[56] /* intShaRad.E_glass variable */);

  res[6] = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * ((data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */) - (data->localData[0]->realVars[41] /* intShaCon.TSha variable */)) + (data->localData[0]->realVars[35] /* heatFlowSensor1.port_a.T variable */) - (data->localData[0]->realVars[54] /* intShaCon.glaSha.T variable */)) - (data->localData[0]->realVars[49] /* intShaCon.conSha.air.Q_flow variable */);

  res[7] = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * ((data->localData[0]->realVars[51] /* intShaCon.conWinUns.dT variable */))) - (data->localData[0]->realVars[52] /* intShaCon.conWinUns.q_flow variable */);

  res[8] = (0.00375) * ((-0.5) * ((data->localData[0]->realVars[1] /* QAbsUns_flow variable */)) + (data->localData[0]->realVars[11] /* extCon.JInUns variable */) + (data->localData[0]->realVars[18] /* extCon.conWinUns.Q_flow variable */) - (data->localData[0]->realVars[13] /* extCon.JOutUns variable */)) + ((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[84] /* window.glaUns_a.T variable */) - (data->localData[0]->realVars[85] /* window.glaUns_b.T variable */));

  res[9] = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * ((data->localData[0]->realVars[82] /* window.glaUns.glass[1].T4_b variable */))) - (data->localData[0]->realVars[80] /* window.glaUns.glass[1].E_b variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
void initializeStaticLSData111(DATA* data, threadData_t* threadData, LINEAR_SYSTEM_DATA* linearSystemData, modelica_boolean initSparsePattern)
{
  int i=0;
  /* static ls data for window.fra_b.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[71].attribute /* window.fra_b.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[71].attribute /* window.fra_b.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[71].attribute /* window.fra_b.T */.max;
  /* static ls data for heatFlowSensor1.port_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[35].attribute /* heatFlowSensor1.port_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[35].attribute /* heatFlowSensor1.port_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[35].attribute /* heatFlowSensor1.port_a.T */.max;
  /* static ls data for window.glaUns_b.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[85].attribute /* window.glaUns_b.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[85].attribute /* window.glaUns_b.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[85].attribute /* window.glaUns_b.T */.max;
  /* static ls data for intShaCon.TSha */
  linearSystemData->nominal[i] = data->modelData->realVarsData[41].attribute /* intShaCon.TSha */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[41].attribute /* intShaCon.TSha */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[41].attribute /* intShaCon.TSha */.max;
  /* static ls data for intShaRad.JIn_glass */
  linearSystemData->nominal[i] = data->modelData->realVarsData[58].attribute /* intShaRad.JIn_glass */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[58].attribute /* intShaRad.JIn_glass */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[58].attribute /* intShaRad.JIn_glass */.max;
  /* static ls data for window.JOutUns_b */
  linearSystemData->nominal[i] = data->modelData->realVarsData[69].attribute /* window.JOutUns_b */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[69].attribute /* window.JOutUns_b */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[69].attribute /* window.JOutUns_b */.max;
  /* static ls data for window.glaUns_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[84].attribute /* window.glaUns_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[84].attribute /* window.glaUns_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[84].attribute /* window.glaUns_a.T */.max;
  /* static ls data for window.glaSha_a.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[78].attribute /* window.glaSha_a.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[78].attribute /* window.glaSha_a.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[78].attribute /* window.glaSha_a.T */.max;
  /* static ls data for indRad.JIn */
  linearSystemData->nominal[i] = data->modelData->realVarsData[37].attribute /* indRad.JIn */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[37].attribute /* indRad.JIn */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[37].attribute /* indRad.JIn */.max;
  /* static ls data for intShaCon.glaSha.T */
  linearSystemData->nominal[i] = data->modelData->realVarsData[54].attribute /* intShaCon.glaSha.T */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[54].attribute /* intShaCon.glaSha.T */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[54].attribute /* intShaCon.glaSha.T */.max;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize linear systems */
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA* linearSystemData)
{
  /* linear systems */
  assertStreamPrint(NULL, nLinearSystems > 2, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[2].equationIndex = 664;
  linearSystemData[2].size = 10;
  linearSystemData[2].nnz = 0;
  linearSystemData[2].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[2].residualFunc = residualFunc664;
  linearSystemData[2].strictTearingFunctionCall = NULL;
  linearSystemData[2].analyticalJacobianColumn = Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac2_column;
  linearSystemData[2].initialAnalyticalJacobian = Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianLSJac2;
  linearSystemData[2].jacobianIndex = 3 /*jacInx*/;
  linearSystemData[2].setA = NULL;  //setLinearMatrixA664;
  linearSystemData[2].setb = NULL;  //setLinearVectorb664;
  linearSystemData[2].initializeStaticLSData = initializeStaticLSData664;
  
  assertStreamPrint(NULL, nLinearSystems > 1, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[1].equationIndex = 217;
  linearSystemData[1].size = 8;
  linearSystemData[1].nnz = 0;
  linearSystemData[1].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[1].residualFunc = residualFunc217;
  linearSystemData[1].strictTearingFunctionCall = NULL;
  linearSystemData[1].analyticalJacobianColumn = Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac1_column;
  linearSystemData[1].initialAnalyticalJacobian = Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianLSJac1;
  linearSystemData[1].jacobianIndex = 1 /*jacInx*/;
  linearSystemData[1].setA = NULL;  //setLinearMatrixA217;
  linearSystemData[1].setb = NULL;  //setLinearVectorb217;
  linearSystemData[1].initializeStaticLSData = initializeStaticLSData217;
  
  assertStreamPrint(NULL, nLinearSystems > 0, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[0].equationIndex = 111;
  linearSystemData[0].size = 10;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;   /* Symbolic Jacobian available */
  linearSystemData[0].residualFunc = residualFunc111;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac0_column;
  linearSystemData[0].initialAnalyticalJacobian = Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianLSJac0;
  linearSystemData[0].jacobianIndex = 0 /*jacInx*/;
  linearSystemData[0].setA = NULL;  //setLinearMatrixA111;
  linearSystemData[0].setb = NULL;  //setLinearVectorb111;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData111;
}

#if defined(__cplusplus)
}
#endif

