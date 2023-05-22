#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustomNoHeat/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_12jac.c"
#endif
/* Jacobians 12 */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_12jac.h"
#include "util/jacobian_util.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 36
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow.$pDERLSJac108.dummyVarLSJac108 = 4.0 * intShaCon.conFra.u * intShaCon.conFra.dT.SeedLSJac108
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_36(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,36};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->tmpVars[0] /* intShaCon.conFra.q_flow.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */ = (4.0) * (((data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */)) * (jacobian->seedVars[0] /* intShaCon.conFra.dT.SeedLSJac108 SEED_VAR */));
#line 26 OMC_FILE
  TRACE_POP
}

/*
equation index: 37
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow.$pDERLSJac108.dummyVarLSJac108 = 0.2 * intShaCon.conFra.q_flow.$pDERLSJac108.dummyVarLSJac108
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_37(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,37};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[2] /* intShaCon.conFra.Q_flow.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */ = (0.2) * (jacobian->tmpVars[0] /* intShaCon.conFra.q_flow.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */);
#line 43 OMC_FILE
  TRACE_POP
}

/*
equation index: 38
type: SIMPLE_ASSIGN
window.frame.dT.$pDERLSJac108.dummyVarLSJac108 = (-intShaCon.conFra.Q_flow.$pDERLSJac108.dummyVarLSJac108) / (-0.6000000000000001)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_38(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,38};
  jacobian->tmpVars[1] /* window.frame.dT.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */ = DIVISION((-jacobian->tmpVars[2] /* intShaCon.conFra.Q_flow.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */),-0.6000000000000001,"-0.6000000000000001");
  TRACE_POP
}

/*
equation index: 39
type: SIMPLE_ASSIGN
extCon.conFra.dT.$pDERLSJac108.dummyVarLSJac108 = intShaCon.conFra.dT.SeedLSJac108 + window.frame.dT.$pDERLSJac108.dummyVarLSJac108
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_39(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,39};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  jacobian->tmpVars[5] /* extCon.conFra.dT.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[0] /* intShaCon.conFra.dT.SeedLSJac108 SEED_VAR */ + jacobian->tmpVars[1] /* window.frame.dT.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */;
#line 75 OMC_FILE
  TRACE_POP
}

/*
equation index: 40
type: SIMPLE_ASSIGN
$res_LSJac108_1.$pDERLSJac108.dummyVarLSJac108 = extCon.conCoeFra.GCon * extCon.conFra.dT.$pDERLSJac108.dummyVarLSJac108 + intShaCon.conFra.Q_flow.$pDERLSJac108.dummyVarLSJac108
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_40(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,40};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->resultVars[0] /* $res_LSJac108_1.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_VAR */ = ((data->localData[0]->realVars[13] /* extCon.conCoeFra.GCon variable */)) * (jacobian->tmpVars[5] /* extCon.conFra.dT.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[2] /* intShaCon.conFra.Q_flow.$pDERLSJac108.dummyVarLSJac108 JACOBIAN_DIFF_VAR */;
#line 92 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac108_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_LSJac108;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac108_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_LSJac108;
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_36(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_37(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_38(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_39(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_40(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 75
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109 = extCon.conWinUns.Gc * window.glaUns_a.T.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_75(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,75};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->tmpVars[24] /* extCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[16] /* extCon.conWinUns.Gc variable */)) * (jacobian->seedVars[0] /* window.glaUns_a.T.SeedLSJac109 SEED_VAR */);
#line 137 OMC_FILE
  TRACE_POP
}

/*
equation index: 76
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_a.$pDERLSJac109.dummyVarLSJac109 = 100769635.3235 * window.glaUns_a.T.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_76(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,76};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[21] /* window.glaUns.glass.1.T4_a.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[0] /* window.glaUns_a.T.SeedLSJac109 SEED_VAR */);
#line 154 OMC_FILE
  TRACE_POP
}

/*
equation index: 77
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_a.$pDERLSJac109.dummyVarLSJac109 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_a.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_77(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,77};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[22] /* window.glaUns.glass.1.E_a.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * (jacobian->tmpVars[21] /* window.glaUns.glass.1.T4_a.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */));
#line 171 OMC_FILE
  TRACE_POP
}

/*
equation index: 78
type: SIMPLE_ASSIGN
window.JInUns_b.$pDERLSJac109.dummyVarLSJac109 = (1.0 - shaSig.y) * indRad.JIn.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_78(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,78};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[19] /* window.JInUns_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[58] /* shaSig.y variable */)) * (jacobian->seedVars[1] /* indRad.JIn.SeedLSJac109 SEED_VAR */);
#line 188 OMC_FILE
  TRACE_POP
}

/*
equation index: 79
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_a.$pDERLSJac109.dummyVarLSJac109 = 100769635.3235 * window.glaSha_a.T.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_79(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,79};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[14] /* window.glaSha.glass.1.T4_a.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[3] /* window.glaSha_a.T.SeedLSJac109 SEED_VAR */);
#line 205 OMC_FILE
  TRACE_POP
}

/*
equation index: 80
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_a.$pDERLSJac109.dummyVarLSJac109 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_a.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_80(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,80};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[15] /* window.glaSha.glass.1.E_a.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * (jacobian->tmpVars[14] /* window.glaSha.glass.1.T4_a.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */));
#line 222 OMC_FILE
  TRACE_POP
}

/*
equation index: 81
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 = extCon.shaCon.Gc * window.glaSha_a.T.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_81(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,81};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[12] /* extCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[23] /* extCon.shaCon.Gc variable */)) * (jacobian->seedVars[3] /* window.glaSha_a.T.SeedLSJac109 SEED_VAR */);
#line 239 OMC_FILE
  TRACE_POP
}

/*
equation index: 82
type: SIMPLE_ASSIGN
extCon.JInSha.$pDERLSJac109.dummyVarLSJac109 = (-extCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109) - window.glaSha.u * (intShaCon.glaSha.T.SeedLSJac109 - window.glaSha_a.T.SeedLSJac109) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_82(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,82};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[13] /* extCon.JInSha.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[12] /* extCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * (jacobian->seedVars[5] /* intShaCon.glaSha.T.SeedLSJac109 SEED_VAR */ - jacobian->seedVars[3] /* window.glaSha_a.T.SeedLSJac109 SEED_VAR */),-0.00375,"-0.00375"));
#line 256 OMC_FILE
  TRACE_POP
}

/*
equation index: 83
type: SIMPLE_ASSIGN
$res_LSJac109_2.$pDERLSJac109.dummyVarLSJac109 = window.glaSha.glass.1.E_a.$pDERLSJac109.dummyVarLSJac109 - extCon.JInSha.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_83(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,83};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[1] /* $res_LSJac109_2.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_VAR */ = jacobian->tmpVars[15] /* window.glaSha.glass.1.E_a.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[13] /* extCon.JInSha.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */;
#line 273 OMC_FILE
  TRACE_POP
}

/*
equation index: 84
type: SIMPLE_ASSIGN
intShaRad.T4.$pDERLSJac109.dummyVarLSJac109 = 25192408.83087499 * intShaCon.TSha.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_84(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,84};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[10] /* intShaRad.T4.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (25192408.83087499) * (jacobian->seedVars[4] /* intShaCon.TSha.SeedLSJac109 SEED_VAR */);
#line 290 OMC_FILE
  TRACE_POP
}

/*
equation index: 85
type: SIMPLE_ASSIGN
intShaRad.E_glass.$pDERLSJac109.dummyVarLSJac109 = 1.134074883836886e-08 * shaSig.y * intShaRad.T4.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_85(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,85};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[11] /* intShaRad.E_glass.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (1.134074883836886e-08) * (((data->localData[0]->realVars[58] /* shaSig.y variable */)) * (jacobian->tmpVars[10] /* intShaRad.T4.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */));
#line 307 OMC_FILE
  TRACE_POP
}

/*
equation index: 86
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 = intShaCon.conSha.Gc * (2.0 * intShaCon.glaSha.T.SeedLSJac109 - intShaCon.TSha.SeedLSJac109)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_86(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,86};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[8] /* intShaCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[5] /* intShaCon.glaSha.T.SeedLSJac109 SEED_VAR */) - jacobian->seedVars[4] /* intShaCon.TSha.SeedLSJac109 SEED_VAR */);
#line 324 OMC_FILE
  TRACE_POP
}

/*
equation index: 87
type: SIMPLE_ASSIGN
intShaRad.JOut_glass.$pDERLSJac109.dummyVarLSJac109 = intShaCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 - ((-intShaRad.JIn_glass.SeedLSJac109) - extCon.JInSha.$pDERLSJac109.dummyVarLSJac109 - extCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_87(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,87};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[8] /* intShaCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - ((-jacobian->seedVars[2] /* intShaRad.JIn_glass.SeedLSJac109 SEED_VAR */) - jacobian->tmpVars[13] /* extCon.JInSha.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[12] /* extCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */);
#line 341 OMC_FILE
  TRACE_POP
}

/*
equation index: 88
type: SIMPLE_ASSIGN
$res_LSJac109_4.$pDERLSJac109.dummyVarLSJac109 = 0.75 * intShaRad.JIn_glass.SeedLSJac109 + intShaRad.E_glass.$pDERLSJac109.dummyVarLSJac109 - intShaRad.JOut_glass.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_88(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,88};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->resultVars[3] /* $res_LSJac109_4.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_VAR */ = (0.75) * (jacobian->seedVars[2] /* intShaRad.JIn_glass.SeedLSJac109 SEED_VAR */) + jacobian->tmpVars[11] /* intShaRad.E_glass.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */;
#line 358 OMC_FILE
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow.$pDERLSJac109.dummyVarLSJac109 = (-intShaCon.conSha.Gc) * (2.0 * intShaCon.TSha.SeedLSJac109 + intShaCon.glaSha.T.SeedLSJac109)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_89(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,89};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[7] /* intShaCon.conSha.air.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = ((-(data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */))) * ((2.0) * (jacobian->seedVars[4] /* intShaCon.TSha.SeedLSJac109 SEED_VAR */) + jacobian->seedVars[5] /* intShaCon.glaSha.T.SeedLSJac109 SEED_VAR */);
#line 375 OMC_FILE
  TRACE_POP
}

/*
equation index: 90
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow.$pDERLSJac109.dummyVarLSJac109 = (-intShaCon.conSha.air.Q_flow.$pDERLSJac109.dummyVarLSJac109) - intShaCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_90(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,90};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[9] /* intShaCon.QRadAbs_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[7] /* intShaCon.conSha.air.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[8] /* intShaCon.glaSha.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */;
#line 392 OMC_FILE
  TRACE_POP
}

/*
equation index: 91
type: SIMPLE_ASSIGN
intShaRad.JIn_air.$pDERLSJac109.dummyVarLSJac109 = 8.0 * intShaRad.E_glass.$pDERLSJac109.dummyVarLSJac109 + 4.0 * intShaCon.QRadAbs_flow.$pDERLSJac109.dummyVarLSJac109 - intShaRad.JIn_glass.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_91(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,91};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[16] /* intShaRad.JIn_air.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (8.0) * (jacobian->tmpVars[11] /* intShaRad.E_glass.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */) + (4.0) * (jacobian->tmpVars[9] /* intShaCon.QRadAbs_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */) - jacobian->seedVars[2] /* intShaRad.JIn_glass.SeedLSJac109 SEED_VAR */;
#line 409 OMC_FILE
  TRACE_POP
}

/*
equation index: 92
type: SIMPLE_ASSIGN
intShaRad.JOut_air.$pDERLSJac109.dummyVarLSJac109 = intShaRad.E_glass.$pDERLSJac109.dummyVarLSJac109 + 0.75 * intShaRad.JIn_air.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_92(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,92};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[18] /* intShaRad.JOut_air.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[11] /* intShaRad.E_glass.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ + (0.75) * (jacobian->tmpVars[16] /* intShaRad.JIn_air.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */);
#line 426 OMC_FILE
  TRACE_POP
}

/*
equation index: 93
type: SIMPLE_ASSIGN
$res_LSJac109_1.$pDERLSJac109.dummyVarLSJac109 = shaSig.y * indRad.JIn.SeedLSJac109 - intShaRad.JIn_air.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_93(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,93};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->resultVars[0] /* $res_LSJac109_1.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_VAR */ = ((data->localData[0]->realVars[58] /* shaSig.y variable */)) * (jacobian->seedVars[1] /* indRad.JIn.SeedLSJac109 SEED_VAR */) - jacobian->tmpVars[16] /* intShaRad.JIn_air.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */;
#line 443 OMC_FILE
  TRACE_POP
}

/*
equation index: 94
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_b.$pDERLSJac109.dummyVarLSJac109 = 100769635.3235 * intShaCon.glaSha.T.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_94(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,94};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[5] /* window.glaSha.glass.1.T4_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[5] /* intShaCon.glaSha.T.SeedLSJac109 SEED_VAR */);
#line 460 OMC_FILE
  TRACE_POP
}

/*
equation index: 95
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_b.$pDERLSJac109.dummyVarLSJac109 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_b.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_95(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,95};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[6] /* window.glaSha.glass.1.E_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * (jacobian->tmpVars[5] /* window.glaSha.glass.1.T4_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */));
#line 477 OMC_FILE
  TRACE_POP
}

/*
equation index: 96
type: SIMPLE_ASSIGN
$res_LSJac109_3.$pDERLSJac109.dummyVarLSJac109 = 0.16 * intShaRad.JOut_glass.$pDERLSJac109.dummyVarLSJac109 + window.glaSha.glass.1.E_b.$pDERLSJac109.dummyVarLSJac109 - intShaRad.JIn_glass.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_96(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,96};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[2] /* $res_LSJac109_3.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_VAR */ = (0.16) * (jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[6] /* window.glaSha.glass.1.E_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[2] /* intShaRad.JIn_glass.SeedLSJac109 SEED_VAR */;
#line 494 OMC_FILE
  TRACE_POP
}

/*
equation index: 97
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT.$pDERLSJac109.dummyVarLSJac109 = 9.923624282153129e-09 * window.glaUns.glass[1].T4_b.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_97(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,97};
  jacobian->tmpVars[1] /* intShaCon.conWinUns.dT.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (9.923624282153129e-09) * (jacobian->seedVars[6] /* window.glaUns.glass[1].T4_b.SeedLSJac109 SEED_VAR */);
  TRACE_POP
}

/*
equation index: 98
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow.$pDERLSJac109.dummyVarLSJac109 = 4.0 * intShaCon.conFra.u * intShaCon.conWinUns.dT.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_98(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,98};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->tmpVars[2] /* intShaCon.conWinUns.q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (4.0) * (((data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[1] /* intShaCon.conWinUns.dT.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */));
#line 526 OMC_FILE
  TRACE_POP
}

/*
equation index: 99
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109 = 0.8 * intShaCon.conWinUns.q_flow.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_99(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,99};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[3] /* intShaCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (0.8) * (jacobian->tmpVars[2] /* intShaCon.conWinUns.q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */);
#line 543 OMC_FILE
  TRACE_POP
}

/*
equation index: 100
type: SIMPLE_ASSIGN
extCon.JInUns.$pDERLSJac109.dummyVarLSJac109 = (-extCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109) - window.glaUns.u * (intShaCon.conWinUns.dT.$pDERLSJac109.dummyVarLSJac109 - window.glaUns_a.T.SeedLSJac109) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_100(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,100};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[25] /* extCon.JInUns.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[24] /* extCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * (jacobian->tmpVars[1] /* intShaCon.conWinUns.dT.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[0] /* window.glaUns_a.T.SeedLSJac109 SEED_VAR */),-0.00375,"-0.00375"));
#line 560 OMC_FILE
  TRACE_POP
}

/*
equation index: 101
type: SIMPLE_ASSIGN
$res_LSJac109_6.$pDERLSJac109.dummyVarLSJac109 = window.glaUns.glass.1.E_a.$pDERLSJac109.dummyVarLSJac109 - extCon.JInUns.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_101(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,101};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[5] /* $res_LSJac109_6.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_VAR */ = jacobian->tmpVars[22] /* window.glaUns.glass.1.E_a.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[25] /* extCon.JInUns.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */;
#line 577 OMC_FILE
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_b.$pDERLSJac109.dummyVarLSJac109 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass[1].T4_b.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_102(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,102};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[0] /* window.glaUns.glass.1.E_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * (jacobian->seedVars[6] /* window.glaUns.glass[1].T4_b.SeedLSJac109 SEED_VAR */));
#line 594 OMC_FILE
  TRACE_POP
}

/*
equation index: 103
type: SIMPLE_ASSIGN
window.JOutUns_b.$pDERLSJac109.dummyVarLSJac109 = window.glaUns.glass.1.E_b.$pDERLSJac109.dummyVarLSJac109 + 0.16 * window.JInUns_b.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_103(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,103};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[20] /* window.JOutUns_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[0] /* window.glaUns.glass.1.E_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ + (0.16) * (jacobian->tmpVars[19] /* window.JInUns_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */);
#line 611 OMC_FILE
  TRACE_POP
}

/*
equation index: 104
type: SIMPLE_ASSIGN
$res_LSJac109_5.$pDERLSJac109.dummyVarLSJac109 = intShaRad.JOut_air.$pDERLSJac109.dummyVarLSJac109 + window.JOutUns_b.$pDERLSJac109.dummyVarLSJac109 - indRad.JIn.SeedLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_104(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,104};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->resultVars[4] /* $res_LSJac109_5.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_VAR */ = jacobian->tmpVars[18] /* intShaRad.JOut_air.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[20] /* window.JOutUns_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[1] /* indRad.JIn.SeedLSJac109 SEED_VAR */;
#line 628 OMC_FILE
  TRACE_POP
}

/*
equation index: 105
type: SIMPLE_ASSIGN
$res_LSJac109_7.$pDERLSJac109.dummyVarLSJac109 = window.JInUns_b.$pDERLSJac109.dummyVarLSJac109 + (-extCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109) - intShaCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109 - extCon.JInUns.$pDERLSJac109.dummyVarLSJac109 - window.JOutUns_b.$pDERLSJac109.dummyVarLSJac109
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_105(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,105};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[6] /* $res_LSJac109_7.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_VAR */ = jacobian->tmpVars[19] /* window.JInUns_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ + (-jacobian->tmpVars[24] /* extCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[3] /* intShaCon.conWinUns.Q_flow.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[25] /* extCon.JInUns.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[20] /* window.JOutUns_b.$pDERLSJac109.dummyVarLSJac109 JACOBIAN_DIFF_VAR */;
#line 645 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac109_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_LSJac109;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac109_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_LSJac109;
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_75(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_76(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_77(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_78(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_79(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_80(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_81(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_82(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_83(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_84(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_85(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_86(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_87(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_88(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_89(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_90(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_91(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_92(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_93(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_94(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_95(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_96(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_97(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_98(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_99(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_100(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_101(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_102(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_103(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_104(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_105(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 138
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow.$pDERLSJac110.dummyVarLSJac110 = (-extCon.conCoeFra.GCon) * extCon.conFra.dT.SeedLSJac110
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_138(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,138};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->tmpVars[0] /* intShaCon.conFra.Q_flow.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */ = ((-(data->localData[0]->realVars[13] /* extCon.conCoeFra.GCon variable */))) * (jacobian->seedVars[0] /* extCon.conFra.dT.SeedLSJac110 SEED_VAR */);
#line 716 OMC_FILE
  TRACE_POP
}

/*
equation index: 139
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow.$pDERLSJac110.dummyVarLSJac110 = 5.0 * intShaCon.conFra.Q_flow.$pDERLSJac110.dummyVarLSJac110
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_139(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,139};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[1] /* intShaCon.conFra.q_flow.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */ = (5.0) * (jacobian->tmpVars[0] /* intShaCon.conFra.Q_flow.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */);
#line 733 OMC_FILE
  TRACE_POP
}

/*
equation index: 140
type: SIMPLE_ASSIGN
window.frame.dT.$pDERLSJac110.dummyVarLSJac110 = (-intShaCon.conFra.Q_flow.$pDERLSJac110.dummyVarLSJac110) / (-0.6000000000000001)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_140(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,140};
  jacobian->tmpVars[2] /* window.frame.dT.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */ = DIVISION((-jacobian->tmpVars[0] /* intShaCon.conFra.Q_flow.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */),-0.6000000000000001,"-0.6000000000000001");
  TRACE_POP
}

/*
equation index: 141
type: SIMPLE_ASSIGN
intShaCon.conFra.dT.$pDERLSJac110.dummyVarLSJac110 = extCon.conFra.dT.SeedLSJac110 - window.frame.dT.$pDERLSJac110.dummyVarLSJac110
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_141(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,141};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  jacobian->tmpVars[5] /* intShaCon.conFra.dT.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[0] /* extCon.conFra.dT.SeedLSJac110 SEED_VAR */ - jacobian->tmpVars[2] /* window.frame.dT.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */;
#line 765 OMC_FILE
  TRACE_POP
}

/*
equation index: 142
type: SIMPLE_ASSIGN
$res_LSJac110_1.$pDERLSJac110.dummyVarLSJac110 = 4.0 * intShaCon.conFra.u * intShaCon.conFra.dT.$pDERLSJac110.dummyVarLSJac110 - intShaCon.conFra.q_flow.$pDERLSJac110.dummyVarLSJac110
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_142(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,142};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[0] /* $res_LSJac110_1.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[5] /* intShaCon.conFra.dT.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[1] /* intShaCon.conFra.q_flow.$pDERLSJac110.dummyVarLSJac110 JACOBIAN_DIFF_VAR */;
#line 782 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac110_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_LSJac110;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac110_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_LSJac110;
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_138(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_139(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_140(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_141(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_142(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 177
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_a.$pDERLSJac111.dummyVarLSJac111 = 100769635.3235 * window.glaUns_a.T.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_177(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,177};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[22] /* window.glaUns.glass.1.T4_a.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[0] /* window.glaUns_a.T.SeedLSJac111 SEED_VAR */);
#line 827 OMC_FILE
  TRACE_POP
}

/*
equation index: 178
type: SIMPLE_ASSIGN
extCon.JInUns.$pDERLSJac111.dummyVarLSJac111 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_a.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_178(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,178};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[24] /* extCon.JInUns.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * (jacobian->tmpVars[22] /* window.glaUns.glass.1.T4_a.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */));
#line 844 OMC_FILE
  TRACE_POP
}

/*
equation index: 179
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_a.$pDERLSJac111.dummyVarLSJac111 = 100769635.3235 * window.glaSha_a.T.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_179(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,179};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[20] /* window.glaSha.glass.1.T4_a.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[1] /* window.glaSha_a.T.SeedLSJac111 SEED_VAR */);
#line 861 OMC_FILE
  TRACE_POP
}

/*
equation index: 180
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_a.$pDERLSJac111.dummyVarLSJac111 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_a.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_180(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,180};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[21] /* window.glaSha.glass.1.E_a.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * (jacobian->tmpVars[20] /* window.glaSha.glass.1.T4_a.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */));
#line 878 OMC_FILE
  TRACE_POP
}

/*
equation index: 181
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 = extCon.shaCon.Gc * window.glaSha_a.T.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_181(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,181};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[18] /* extCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[23] /* extCon.shaCon.Gc variable */)) * (jacobian->seedVars[1] /* window.glaSha_a.T.SeedLSJac111 SEED_VAR */);
#line 895 OMC_FILE
  TRACE_POP
}

/*
equation index: 182
type: SIMPLE_ASSIGN
extCon.JInSha.$pDERLSJac111.dummyVarLSJac111 = (-extCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111) - window.glaSha.u * (intShaCon.glaSha.T.SeedLSJac111 - window.glaSha_a.T.SeedLSJac111) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_182(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,182};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[19] /* extCon.JInSha.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[18] /* extCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * (jacobian->seedVars[4] /* intShaCon.glaSha.T.SeedLSJac111 SEED_VAR */ - jacobian->seedVars[1] /* window.glaSha_a.T.SeedLSJac111 SEED_VAR */),-0.00375,"-0.00375"));
#line 912 OMC_FILE
  TRACE_POP
}

/*
equation index: 183
type: SIMPLE_ASSIGN
$res_LSJac111_2.$pDERLSJac111.dummyVarLSJac111 = window.glaSha.glass.1.E_a.$pDERLSJac111.dummyVarLSJac111 - extCon.JInSha.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_183(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,183};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[1] /* $res_LSJac111_2.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_VAR */ = jacobian->tmpVars[21] /* window.glaSha.glass.1.E_a.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[19] /* extCon.JInSha.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */;
#line 929 OMC_FILE
  TRACE_POP
}

/*
equation index: 184
type: SIMPLE_ASSIGN
window.JInUns_b.$pDERLSJac111.dummyVarLSJac111 = (1.0 - shaSig.y) * indRad.JIn.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_184(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,184};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[13] /* window.JInUns_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[58] /* shaSig.y variable */)) * (jacobian->seedVars[2] /* indRad.JIn.SeedLSJac111 SEED_VAR */);
#line 946 OMC_FILE
  TRACE_POP
}

/*
equation index: 185
type: SIMPLE_ASSIGN
intShaRad.JIn_air.$pDERLSJac111.dummyVarLSJac111 = shaSig.y * indRad.JIn.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_185(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,185};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[12] /* intShaRad.JIn_air.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[58] /* shaSig.y variable */)) * (jacobian->seedVars[2] /* indRad.JIn.SeedLSJac111 SEED_VAR */);
#line 963 OMC_FILE
  TRACE_POP
}

/*
equation index: 186
type: SIMPLE_ASSIGN
intShaRad.T4.$pDERLSJac111.dummyVarLSJac111 = 25192408.83087499 * intShaCon.TSha.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_186(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,186};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[10] /* intShaRad.T4.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (25192408.83087499) * (jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac111 SEED_VAR */);
#line 980 OMC_FILE
  TRACE_POP
}

/*
equation index: 187
type: SIMPLE_ASSIGN
intShaRad.E_glass.$pDERLSJac111.dummyVarLSJac111 = 1.134074883836886e-08 * shaSig.y * intShaRad.T4.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_187(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,187};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[11] /* intShaRad.E_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (1.134074883836886e-08) * (((data->localData[0]->realVars[58] /* shaSig.y variable */)) * (jacobian->tmpVars[10] /* intShaRad.T4.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */));
#line 997 OMC_FILE
  TRACE_POP
}

/*
equation index: 188
type: SIMPLE_ASSIGN
intShaRad.JOut_air.$pDERLSJac111.dummyVarLSJac111 = intShaRad.E_glass.$pDERLSJac111.dummyVarLSJac111 + 0.75 * intShaRad.JIn_air.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_188(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,188};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[16] /* intShaRad.JOut_air.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[11] /* intShaRad.E_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ + (0.75) * (jacobian->tmpVars[12] /* intShaRad.JIn_air.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */);
#line 1014 OMC_FILE
  TRACE_POP
}

/*
equation index: 189
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 = intShaCon.conSha.Gc * (2.0 * intShaCon.glaSha.T.SeedLSJac111 - intShaCon.TSha.SeedLSJac111)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_189(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,189};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[8] /* intShaCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[4] /* intShaCon.glaSha.T.SeedLSJac111 SEED_VAR */) - jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac111 SEED_VAR */);
#line 1031 OMC_FILE
  TRACE_POP
}

/*
equation index: 190
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow.$pDERLSJac111.dummyVarLSJac111 = (-intShaCon.conSha.Gc) * (2.0 * intShaCon.TSha.SeedLSJac111 + intShaCon.glaSha.T.SeedLSJac111)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_190(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,190};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[7] /* intShaCon.conSha.air.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = ((-(data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */))) * ((2.0) * (jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac111 SEED_VAR */) + jacobian->seedVars[4] /* intShaCon.glaSha.T.SeedLSJac111 SEED_VAR */);
#line 1048 OMC_FILE
  TRACE_POP
}

/*
equation index: 191
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow.$pDERLSJac111.dummyVarLSJac111 = (-intShaCon.conSha.air.Q_flow.$pDERLSJac111.dummyVarLSJac111) - intShaCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_191(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,191};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[9] /* intShaCon.QRadAbs_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[7] /* intShaCon.conSha.air.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[8] /* intShaCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */;
#line 1065 OMC_FILE
  TRACE_POP
}

/*
equation index: 192
type: SIMPLE_ASSIGN
intShaRad.JIn_glass.$pDERLSJac111.dummyVarLSJac111 = 8.0 * intShaRad.E_glass.$pDERLSJac111.dummyVarLSJac111 + 4.0 * intShaCon.QRadAbs_flow.$pDERLSJac111.dummyVarLSJac111 - intShaRad.JIn_air.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_192(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,192};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[14] /* intShaRad.JIn_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (8.0) * (jacobian->tmpVars[11] /* intShaRad.E_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */) + (4.0) * (jacobian->tmpVars[9] /* intShaCon.QRadAbs_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[12] /* intShaRad.JIn_air.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */;
#line 1082 OMC_FILE
  TRACE_POP
}

/*
equation index: 193
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_b.$pDERLSJac111.dummyVarLSJac111 = 100769635.3235 * intShaCon.glaSha.T.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_193(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,193};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[5] /* window.glaSha.glass.1.T4_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[4] /* intShaCon.glaSha.T.SeedLSJac111 SEED_VAR */);
#line 1099 OMC_FILE
  TRACE_POP
}

/*
equation index: 194
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_b.$pDERLSJac111.dummyVarLSJac111 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_b.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_194(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,194};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[6] /* window.glaSha.glass.1.E_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[71] /* window.glaSha.u variable */)) * (jacobian->tmpVars[5] /* window.glaSha.glass.1.T4_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */));
#line 1116 OMC_FILE
  TRACE_POP
}

/*
equation index: 195
type: SIMPLE_ASSIGN
intShaRad.JOut_glass.$pDERLSJac111.dummyVarLSJac111 = (window.glaSha.glass.1.E_b.$pDERLSJac111.dummyVarLSJac111 - intShaRad.JIn_glass.$pDERLSJac111.dummyVarLSJac111) / (-0.16)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_195(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,195};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = DIVISION(jacobian->tmpVars[6] /* window.glaSha.glass.1.E_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[14] /* intShaRad.JIn_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */,-0.16,"-0.16");
#line 1133 OMC_FILE
  TRACE_POP
}

/*
equation index: 196
type: SIMPLE_ASSIGN
$res_LSJac111_1.$pDERLSJac111.dummyVarLSJac111 = 0.75 * intShaRad.JIn_glass.$pDERLSJac111.dummyVarLSJac111 + intShaRad.E_glass.$pDERLSJac111.dummyVarLSJac111 - intShaRad.JOut_glass.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_196(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,196};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->resultVars[0] /* $res_LSJac111_1.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_VAR */ = (0.75) * (jacobian->tmpVars[14] /* intShaRad.JIn_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[11] /* intShaRad.E_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */;
#line 1150 OMC_FILE
  TRACE_POP
}

/*
equation index: 197
type: SIMPLE_ASSIGN
$res_LSJac111_3.$pDERLSJac111.dummyVarLSJac111 = intShaRad.JOut_glass.$pDERLSJac111.dummyVarLSJac111 + (-extCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111) - intShaCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 - extCon.JInSha.$pDERLSJac111.dummyVarLSJac111 - intShaRad.JIn_glass.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_197(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,197};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[2] /* $res_LSJac111_3.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_VAR */ = jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ + (-jacobian->tmpVars[18] /* extCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[8] /* intShaCon.glaSha.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[19] /* extCon.JInSha.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[14] /* intShaRad.JIn_glass.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */;
#line 1167 OMC_FILE
  TRACE_POP
}

/*
equation index: 198
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT.$pDERLSJac111.dummyVarLSJac111 = 9.923624282153129e-09 * window.glaUns.glass[1].T4_b.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_198(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,198};
  jacobian->tmpVars[1] /* intShaCon.conWinUns.dT.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (9.923624282153129e-09) * (jacobian->seedVars[5] /* window.glaUns.glass[1].T4_b.SeedLSJac111 SEED_VAR */);
  TRACE_POP
}

/*
equation index: 199
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow.$pDERLSJac111.dummyVarLSJac111 = 4.0 * intShaCon.conFra.u * intShaCon.conWinUns.dT.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_199(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,199};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->tmpVars[2] /* intShaCon.conWinUns.q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (4.0) * (((data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[1] /* intShaCon.conWinUns.dT.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */));
#line 1199 OMC_FILE
  TRACE_POP
}

/*
equation index: 200
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111 = 0.8 * intShaCon.conWinUns.q_flow.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_200(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,200};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[3] /* intShaCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (0.8) * (jacobian->tmpVars[2] /* intShaCon.conWinUns.q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */);
#line 1216 OMC_FILE
  TRACE_POP
}

/*
equation index: 201
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111 = (-extCon.JInUns.$pDERLSJac111.dummyVarLSJac111) - window.glaUns.u * (intShaCon.conWinUns.dT.$pDERLSJac111.dummyVarLSJac111 - window.glaUns_a.T.SeedLSJac111) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_201(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,201};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[25] /* extCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[24] /* extCon.JInUns.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * (jacobian->tmpVars[1] /* intShaCon.conWinUns.dT.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[0] /* window.glaUns_a.T.SeedLSJac111 SEED_VAR */),-0.00375,"-0.00375"));
#line 1233 OMC_FILE
  TRACE_POP
}

/*
equation index: 202
type: SIMPLE_ASSIGN
$res_LSJac111_5.$pDERLSJac111.dummyVarLSJac111 = extCon.conWinUns.Gc * window.glaUns_a.T.SeedLSJac111 - extCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_202(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,202};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->resultVars[4] /* $res_LSJac111_5.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_VAR */ = ((data->localData[0]->realVars[16] /* extCon.conWinUns.Gc variable */)) * (jacobian->seedVars[0] /* window.glaUns_a.T.SeedLSJac111 SEED_VAR */) - jacobian->tmpVars[25] /* extCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */;
#line 1250 OMC_FILE
  TRACE_POP
}

/*
equation index: 203
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_b.$pDERLSJac111.dummyVarLSJac111 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass[1].T4_b.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_203(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,203};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[0] /* window.glaUns.glass.1.E_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaUns.u variable */)) * (jacobian->seedVars[5] /* window.glaUns.glass[1].T4_b.SeedLSJac111 SEED_VAR */));
#line 1267 OMC_FILE
  TRACE_POP
}

/*
equation index: 204
type: SIMPLE_ASSIGN
window.JOutUns_b.$pDERLSJac111.dummyVarLSJac111 = window.glaUns.glass.1.E_b.$pDERLSJac111.dummyVarLSJac111 + 0.16 * window.JInUns_b.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_204(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,204};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[15] /* window.JOutUns_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[0] /* window.glaUns.glass.1.E_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ + (0.16) * (jacobian->tmpVars[13] /* window.JInUns_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */);
#line 1284 OMC_FILE
  TRACE_POP
}

/*
equation index: 205
type: SIMPLE_ASSIGN
$res_LSJac111_4.$pDERLSJac111.dummyVarLSJac111 = intShaRad.JOut_air.$pDERLSJac111.dummyVarLSJac111 + window.JOutUns_b.$pDERLSJac111.dummyVarLSJac111 - indRad.JIn.SeedLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_205(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,205};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->resultVars[3] /* $res_LSJac111_4.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_VAR */ = jacobian->tmpVars[16] /* intShaRad.JOut_air.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[15] /* window.JOutUns_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[2] /* indRad.JIn.SeedLSJac111 SEED_VAR */;
#line 1301 OMC_FILE
  TRACE_POP
}

/*
equation index: 206
type: SIMPLE_ASSIGN
$res_LSJac111_6.$pDERLSJac111.dummyVarLSJac111 = window.JInUns_b.$pDERLSJac111.dummyVarLSJac111 + (-extCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111) - intShaCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111 - extCon.JInUns.$pDERLSJac111.dummyVarLSJac111 - window.JOutUns_b.$pDERLSJac111.dummyVarLSJac111
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_206(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,206};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[5] /* $res_LSJac111_6.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_VAR */ = jacobian->tmpVars[13] /* window.JInUns_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ + (-jacobian->tmpVars[25] /* extCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[3] /* intShaCon.conWinUns.Q_flow.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[24] /* extCon.JInUns.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[15] /* window.JOutUns_b.$pDERLSJac111.dummyVarLSJac111 JACOBIAN_DIFF_VAR */;
#line 1318 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac111_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_LSJac111;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacLSJac111_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_LSJac111;
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_177(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_178(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_179(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_180(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_181(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_182(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_183(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_184(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_185(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_186(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_187(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_188(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_189(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_190(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_191(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_192(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_193(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_194(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_195(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_196(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_197(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_198(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_199(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_200(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_201(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_202(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_203(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_204(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_205(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_206(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacFMIDERINIT_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_FMIDERINIT;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacFMIDERINIT_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_FMIDERINIT;
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacFMIDER_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianLSJac108(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 1, 1, 7, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianLSJac109(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+7] = {0,2,3,4,3,4,5,3};
  const int rowIndex[24] = {5,6,0,4,6,0,2,3,4,1,2,3,0,2,3,4,0,1,2,3,4,4,5,6};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 7, 7, 33, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(7, 24, 5);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (7+1)*sizeof(unsigned int));
  
  for(i=2;i<7+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 24*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {6};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {5};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {4};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 2 columns */
  const int indices_4[2] = {1, 3};
  for(i=0; i<2; i++)
    jacobian->sparsePattern->colorCols[indices_4[i]] = 4;
  
  /* color 5 with 2 columns */
  const int indices_5[2] = {0, 2};
  for(i=0; i<2; i++)
    jacobian->sparsePattern->colorCols[indices_5[i]] = 5;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianLSJac110(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 1, 1, 7, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianLSJac111(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+6] = {0,2,2,4,3,3,3};
  const int rowIndex[17] = {4,5,1,2,0,2,3,5,0,2,3,0,1,2,3,4,5};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 6, 6, 33, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(6, 17, 4);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (6+1)*sizeof(unsigned int));
  
  for(i=2;i<6+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 17*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 2 columns */
  const int indices_1[2] = {4, 5};
  for(i=0; i<2; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {3};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {2};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 2 columns */
  const int indices_4[2] = {0, 1};
  for(i=0; i<2; i++)
    jacobian->sparsePattern->colorCols[indices_4[i]] = 4;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianFMIDERINIT(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+63] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  const int rowIndex[0] = {};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 63, 155, 73, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(63, 0, 1);
  jacobian->availability = JACOBIAN_ONLY_SPARSITY;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (63+1)*sizeof(unsigned int));
  
  for(i=2;i<63+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 0*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 63 columns */
  const int indices_1[63] = {5, 0, 1, 3, 15, 4, 2, 50, 54, 51, 52, 53, 48, 49, 47, 42, 45, 43, 46, 41, 44, 39, 40, 61, 62, 57, 58, 55, 56, 59, 60, 37, 38, 32, 27, 31, 28, 29, 30, 25, 26, 24, 19, 22, 20, 23, 18, 21, 16, 17, 35, 36, 33, 34, 9, 10, 7, 8, 11, 14, 12, 6, 13};
  for(i=0; i<63; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianFMIDER(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}



