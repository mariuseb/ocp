#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustom/Buildings_HeatTransfer_Windows_Examples_WindowCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustom_12jac.c"
#endif
/* Jacobians 12 */
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustom_12jac.h"
#include "util/jacobian_util.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 73
type: SIMPLE_ASSIGN
intShaCon.conFra.dT.$pDERLSJac0.dummyVarLSJac0 = window.fra_b.T.SeedLSJac0 - heatFlowSensor1.port_a.T.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_73(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,73};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[28] /* intShaCon.conFra.dT.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[0] /* window.fra_b.T.SeedLSJac0 SEED_VAR */ - jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.SeedLSJac0 SEED_VAR */;
#line 26 OMC_FILE
  TRACE_POP
}

/*
equation index: 74
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT.$pDERLSJac0.dummyVarLSJac0 = window.glaUns_b.T.SeedLSJac0 - heatFlowSensor1.port_a.T.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_74(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,74};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[27] /* intShaCon.conWinUns.dT.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[2] /* window.glaUns_b.T.SeedLSJac0 SEED_VAR */ - jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.SeedLSJac0 SEED_VAR */;
#line 43 OMC_FILE
  TRACE_POP
}

/*
equation index: 75
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_b.$pDERLSJac0.dummyVarLSJac0 = 100769635.3235 * window.glaUns_b.T.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_75(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,75};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[26] /* window.glaUns.glass.1.T4_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[2] /* window.glaUns_b.T.SeedLSJac0 SEED_VAR */);
#line 60 OMC_FILE
  TRACE_POP
}

/*
equation index: 76
type: SIMPLE_ASSIGN
intShaRad.T4.$pDERLSJac0.dummyVarLSJac0 = 25192408.83087499 * intShaCon.TSha.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_76(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,76};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[25] /* intShaRad.T4.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (25192408.83087499) * (jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac0 SEED_VAR */);
#line 77 OMC_FILE
  TRACE_POP
}

/*
equation index: 77
type: SIMPLE_ASSIGN
intShaRad.JOut_air.$pDERLSJac0.dummyVarLSJac0 = indRad.JIn.SeedLSJac0 - window.JOutUns_b.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_77(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,77};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[16] /* intShaRad.JOut_air.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[8] /* indRad.JIn.SeedLSJac0 SEED_VAR */ - jacobian->seedVars[5] /* window.JOutUns_b.SeedLSJac0 SEED_VAR */;
#line 94 OMC_FILE
  TRACE_POP
}

/*
equation index: 78
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0 = extCon.conWinUns.Gc * window.glaUns_a.T.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_78(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,78};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->tmpVars[12] /* extCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[17] /* extCon.conWinUns.Gc variable */)) * (jacobian->seedVars[6] /* window.glaUns_a.T.SeedLSJac0 SEED_VAR */);
#line 111 OMC_FILE
  TRACE_POP
}

/*
equation index: 79
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_a.$pDERLSJac0.dummyVarLSJac0 = 100769635.3235 * window.glaUns_a.T.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_79(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,79};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[8] /* window.glaUns.glass.1.T4_a.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[6] /* window.glaUns_a.T.SeedLSJac0 SEED_VAR */);
#line 128 OMC_FILE
  TRACE_POP
}

/*
equation index: 80
type: SIMPLE_ASSIGN
extCon.JInUns.$pDERLSJac0.dummyVarLSJac0 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_a.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_80(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,80};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[10] /* extCon.JInUns.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->tmpVars[8] /* window.glaUns.glass.1.T4_a.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */));
#line 145 OMC_FILE
  TRACE_POP
}

/*
equation index: 81
type: SIMPLE_ASSIGN
$res_LSJac0_9.$pDERLSJac0.dummyVarLSJac0 = 0.00375 * (extCon.JInUns.$pDERLSJac0.dummyVarLSJac0 + extCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0) + window.glaUns.u * (window.glaUns_a.T.SeedLSJac0 - window.glaUns_b.T.SeedLSJac0)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_81(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,81};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[8] /* $res_LSJac0_9.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = (0.00375) * (jacobian->tmpVars[10] /* extCon.JInUns.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[12] /* extCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */) + ((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->seedVars[6] /* window.glaUns_a.T.SeedLSJac0 SEED_VAR */ - jacobian->seedVars[2] /* window.glaUns_b.T.SeedLSJac0 SEED_VAR */);
#line 162 OMC_FILE
  TRACE_POP
}

/*
equation index: 82
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_a.$pDERLSJac0.dummyVarLSJac0 = 100769635.3235 * window.glaSha_a.T.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_82(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,82};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[6] /* window.glaSha.glass.1.T4_a.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[7] /* window.glaSha_a.T.SeedLSJac0 SEED_VAR */);
#line 179 OMC_FILE
  TRACE_POP
}

/*
equation index: 83
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_a.$pDERLSJac0.dummyVarLSJac0 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_a.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_83(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,83};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[7] /* window.glaSha.glass.1.E_a.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->tmpVars[6] /* window.glaSha.glass.1.T4_a.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */));
#line 196 OMC_FILE
  TRACE_POP
}

/*
equation index: 84
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0 = extCon.shaCon.Gc * window.glaSha_a.T.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_84(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,84};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[24] /* extCon.shaCon.Gc variable */)) * (jacobian->seedVars[7] /* window.glaSha_a.T.SeedLSJac0 SEED_VAR */);
#line 213 OMC_FILE
  TRACE_POP
}

/*
equation index: 85
type: SIMPLE_ASSIGN
extCon.JInSha.$pDERLSJac0.dummyVarLSJac0 = (-extCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0) - window.glaSha.u * (intShaCon.glaSha.T.SeedLSJac0 - window.glaSha_a.T.SeedLSJac0) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_85(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,85};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[5] /* extCon.JInSha.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->seedVars[9] /* intShaCon.glaSha.T.SeedLSJac0 SEED_VAR */ - jacobian->seedVars[7] /* window.glaSha_a.T.SeedLSJac0 SEED_VAR */),-0.00375,"-0.00375"));
#line 230 OMC_FILE
  TRACE_POP
}

/*
equation index: 86
type: SIMPLE_ASSIGN
$res_LSJac0_1.$pDERLSJac0.dummyVarLSJac0 = window.glaSha.glass.1.E_a.$pDERLSJac0.dummyVarLSJac0 - extCon.JInSha.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_86(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,86};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[0] /* $res_LSJac0_1.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = jacobian->tmpVars[7] /* window.glaSha.glass.1.E_a.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[5] /* extCon.JInSha.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 247 OMC_FILE
  TRACE_POP
}

/*
equation index: 87
type: SIMPLE_ASSIGN
intShaRad.JIn_air.$pDERLSJac0.dummyVarLSJac0 = shaSig.y * indRad.JIn.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_87(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,87};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[3] /* intShaRad.JIn_air.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->seedVars[8] /* indRad.JIn.SeedLSJac0 SEED_VAR */);
#line 264 OMC_FILE
  TRACE_POP
}

/*
equation index: 88
type: SIMPLE_ASSIGN
intShaRad.E_glass.$pDERLSJac0.dummyVarLSJac0 = intShaRad.JOut_air.$pDERLSJac0.dummyVarLSJac0 - 0.75 * intShaRad.JIn_air.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_88(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,88};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[17] /* intShaRad.E_glass.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[16] /* intShaRad.JOut_air.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ - ((0.75) * (jacobian->tmpVars[3] /* intShaRad.JIn_air.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */));
#line 281 OMC_FILE
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
intShaRad.JOut_glass.$pDERLSJac0.dummyVarLSJac0 = intShaRad.E_glass.$pDERLSJac0.dummyVarLSJac0 + 0.75 * intShaRad.JIn_glass.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_89(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,89};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[19] /* intShaRad.JOut_glass.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[17] /* intShaRad.E_glass.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ + (0.75) * (jacobian->seedVars[4] /* intShaRad.JIn_glass.SeedLSJac0 SEED_VAR */);
#line 298 OMC_FILE
  TRACE_POP
}

/*
equation index: 90
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0 = intShaRad.JOut_glass.$pDERLSJac0.dummyVarLSJac0 - intShaRad.JIn_glass.SeedLSJac0 - extCon.JInSha.$pDERLSJac0.dummyVarLSJac0 - extCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_90(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,90};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[20] /* intShaCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[19] /* intShaRad.JOut_glass.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[4] /* intShaRad.JIn_glass.SeedLSJac0 SEED_VAR */ - jacobian->tmpVars[5] /* extCon.JInSha.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 315 OMC_FILE
  TRACE_POP
}

/*
equation index: 91
type: SIMPLE_ASSIGN
$res_LSJac0_4.$pDERLSJac0.dummyVarLSJac0 = intShaCon.conSha.Gc * (2.0 * intShaCon.glaSha.T.SeedLSJac0 + (-heatFlowSensor1.port_a.T.SeedLSJac0) - intShaCon.TSha.SeedLSJac0) - intShaCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_91(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,91};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->resultVars[3] /* $res_LSJac0_4.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[9] /* intShaCon.glaSha.T.SeedLSJac0 SEED_VAR */) + (-jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.SeedLSJac0 SEED_VAR */) - jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac0 SEED_VAR */) - jacobian->tmpVars[20] /* intShaCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 332 OMC_FILE
  TRACE_POP
}

/*
equation index: 92
type: SIMPLE_ASSIGN
$res_LSJac0_6.$pDERLSJac0.dummyVarLSJac0 = 1.134074883836886e-08 * shaSig.y * intShaRad.T4.$pDERLSJac0.dummyVarLSJac0 - intShaRad.E_glass.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_92(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,92};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->resultVars[5] /* $res_LSJac0_6.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = (1.134074883836886e-08) * (((data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->tmpVars[25] /* intShaRad.T4.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[17] /* intShaRad.E_glass.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 349 OMC_FILE
  TRACE_POP
}

/*
equation index: 93
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow.$pDERLSJac0.dummyVarLSJac0 = 0.25 * (intShaRad.JIn_air.$pDERLSJac0.dummyVarLSJac0 + intShaRad.JIn_glass.SeedLSJac0) - 2.0 * intShaRad.E_glass.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_93(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,93};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[18] /* intShaCon.QRadAbs_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (0.25) * (jacobian->tmpVars[3] /* intShaRad.JIn_air.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ + jacobian->seedVars[4] /* intShaRad.JIn_glass.SeedLSJac0 SEED_VAR */) - ((2.0) * (jacobian->tmpVars[17] /* intShaRad.E_glass.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */));
#line 366 OMC_FILE
  TRACE_POP
}

/*
equation index: 94
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow.$pDERLSJac0.dummyVarLSJac0 = (-intShaCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0) - intShaCon.QRadAbs_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_94(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,94};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[21] /* intShaCon.conSha.air.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[20] /* intShaCon.glaSha.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[18] /* intShaCon.QRadAbs_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 383 OMC_FILE
  TRACE_POP
}

/*
equation index: 95
type: SIMPLE_ASSIGN
$res_LSJac0_7.$pDERLSJac0.dummyVarLSJac0 = intShaCon.conSha.Gc * (2.0 * (heatFlowSensor1.port_a.T.SeedLSJac0 - intShaCon.TSha.SeedLSJac0) + heatFlowSensor1.port_a.T.SeedLSJac0 - intShaCon.glaSha.T.SeedLSJac0) - intShaCon.conSha.air.Q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_95(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,95};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->resultVars[6] /* $res_LSJac0_7.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.SeedLSJac0 SEED_VAR */ - jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac0 SEED_VAR */) + jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.SeedLSJac0 SEED_VAR */ - jacobian->seedVars[9] /* intShaCon.glaSha.T.SeedLSJac0 SEED_VAR */) - jacobian->tmpVars[21] /* intShaCon.conSha.air.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 400 OMC_FILE
  TRACE_POP
}

/*
equation index: 96
type: SIMPLE_ASSIGN
window.JInUns_b.$pDERLSJac0.dummyVarLSJac0 = (1.0 - shaSig.y) * indRad.JIn.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_96(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,96};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[2] /* window.JInUns_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->seedVars[8] /* indRad.JIn.SeedLSJac0 SEED_VAR */);
#line 417 OMC_FILE
  TRACE_POP
}

/*
equation index: 97
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0 = window.JInUns_b.$pDERLSJac0.dummyVarLSJac0 - window.JOutUns_b.SeedLSJac0 - extCon.JInUns.$pDERLSJac0.dummyVarLSJac0 - extCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_97(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,97};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[13] /* intShaCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[2] /* window.JInUns_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[5] /* window.JOutUns_b.SeedLSJac0 SEED_VAR */ - jacobian->tmpVars[10] /* extCon.JInUns.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[12] /* extCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 434 OMC_FILE
  TRACE_POP
}

/*
equation index: 98
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow.$pDERLSJac0.dummyVarLSJac0 = 1.25 * intShaCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_98(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,98};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[15] /* intShaCon.conWinUns.q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (1.25) * (jacobian->tmpVars[13] /* intShaCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */);
#line 451 OMC_FILE
  TRACE_POP
}

/*
equation index: 99
type: SIMPLE_ASSIGN
$res_LSJac0_8.$pDERLSJac0.dummyVarLSJac0 = 4.0 * intShaCon.conFra.u * intShaCon.conWinUns.dT.$pDERLSJac0.dummyVarLSJac0 - intShaCon.conWinUns.q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_99(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,99};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[7] /* $res_LSJac0_8.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[27] /* intShaCon.conWinUns.dT.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[15] /* intShaCon.conWinUns.q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 468 OMC_FILE
  TRACE_POP
}

/*
equation index: 100
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow.$pDERLSJac0.dummyVarLSJac0 = intShaCon.conSha.air.Q_flow.$pDERLSJac0.dummyVarLSJac0 - intShaCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_100(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,100};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[21] /* intShaCon.conSha.air.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[13] /* intShaCon.conWinUns.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 485 OMC_FILE
  TRACE_POP
}

/*
equation index: 101
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow.$pDERLSJac0.dummyVarLSJac0 = 5.0 * intShaCon.conFra.Q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_101(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,101};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[23] /* intShaCon.conFra.q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (5.0) * (jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */);
#line 502 OMC_FILE
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
$res_LSJac0_3.$pDERLSJac0.dummyVarLSJac0 = 4.0 * intShaCon.conFra.u * intShaCon.conFra.dT.$pDERLSJac0.dummyVarLSJac0 - intShaCon.conFra.q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_102(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,102};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[2] /* $res_LSJac0_3.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[28] /* intShaCon.conFra.dT.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[23] /* intShaCon.conFra.q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 519 OMC_FILE
  TRACE_POP
}

/*
equation index: 103
type: SIMPLE_ASSIGN
window.frame.dT.$pDERLSJac0.dummyVarLSJac0 = (-intShaCon.conFra.Q_flow.$pDERLSJac0.dummyVarLSJac0) / (-0.6000000000000001)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_103(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,103};
  jacobian->tmpVars[24] /* window.frame.dT.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = DIVISION((-jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */),-0.6000000000000001,"-0.6000000000000001");
  TRACE_POP
}

/*
equation index: 104
type: SIMPLE_ASSIGN
extCon.conFra.dT.$pDERLSJac0.dummyVarLSJac0 = window.fra_b.T.SeedLSJac0 + window.frame.dT.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_104(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,104};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  jacobian->tmpVars[30] /* extCon.conFra.dT.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[0] /* window.fra_b.T.SeedLSJac0 SEED_VAR */ + jacobian->tmpVars[24] /* window.frame.dT.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 551 OMC_FILE
  TRACE_POP
}

/*
equation index: 105
type: SIMPLE_ASSIGN
$res_LSJac0_2.$pDERLSJac0.dummyVarLSJac0 = extCon.conCoeFra.GCon * extCon.conFra.dT.$pDERLSJac0.dummyVarLSJac0 + intShaCon.conFra.Q_flow.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_105(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,105};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->resultVars[1] /* $res_LSJac0_2.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = ((data->localData[0]->realVars[14] /* extCon.conCoeFra.GCon variable */)) * (jacobian->tmpVars[30] /* extCon.conFra.dT.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 568 OMC_FILE
  TRACE_POP
}

/*
equation index: 106
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_b.$pDERLSJac0.dummyVarLSJac0 = window.JOutUns_b.SeedLSJac0 - 0.16 * window.JInUns_b.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_106(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 33;
  const int equationIndexes[2] = {1,106};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[14] /* window.glaUns.glass.1.E_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[5] /* window.JOutUns_b.SeedLSJac0 SEED_VAR */ - ((0.16) * (jacobian->tmpVars[2] /* window.JInUns_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */));
#line 585 OMC_FILE
  TRACE_POP
}

/*
equation index: 107
type: SIMPLE_ASSIGN
$res_LSJac0_10.$pDERLSJac0.dummyVarLSJac0 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_b.$pDERLSJac0.dummyVarLSJac0 - window.glaUns.glass.1.E_b.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_107(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 34;
  const int equationIndexes[2] = {1,107};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[9] /* $res_LSJac0_10.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->tmpVars[26] /* window.glaUns.glass.1.T4_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[14] /* window.glaUns.glass.1.E_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */;
#line 602 OMC_FILE
  TRACE_POP
}

/*
equation index: 108
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_b.$pDERLSJac0.dummyVarLSJac0 = 100769635.3235 * intShaCon.glaSha.T.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_108(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 35;
  const int equationIndexes[2] = {1,108};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[0] /* window.glaSha.glass.1.T4_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[9] /* intShaCon.glaSha.T.SeedLSJac0 SEED_VAR */);
#line 619 OMC_FILE
  TRACE_POP
}

/*
equation index: 109
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_b.$pDERLSJac0.dummyVarLSJac0 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_b.$pDERLSJac0.dummyVarLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_109(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 36;
  const int equationIndexes[2] = {1,109};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[1] /* window.glaSha.glass.1.E_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->tmpVars[0] /* window.glaSha.glass.1.T4_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */));
#line 636 OMC_FILE
  TRACE_POP
}

/*
equation index: 110
type: SIMPLE_ASSIGN
$res_LSJac0_5.$pDERLSJac0.dummyVarLSJac0 = 0.16 * intShaRad.JOut_glass.$pDERLSJac0.dummyVarLSJac0 + window.glaSha.glass.1.E_b.$pDERLSJac0.dummyVarLSJac0 - intShaRad.JIn_glass.SeedLSJac0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_110(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 37;
  const int equationIndexes[2] = {1,110};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[4] /* $res_LSJac0_5.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_VAR */ = (0.16) * (jacobian->tmpVars[19] /* intShaRad.JOut_glass.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[1] /* window.glaSha.glass.1.E_b.$pDERLSJac0.dummyVarLSJac0 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[4] /* intShaRad.JIn_glass.SeedLSJac0 SEED_VAR */;
#line 653 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac0_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_LSJac0;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac0_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_LSJac0;
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_73(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_74(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_75(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_76(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_77(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_78(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_79(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_80(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_81(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_82(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_83(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_84(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_85(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_86(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_87(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_88(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_89(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_90(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_91(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_92(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_93(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_94(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_95(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_96(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_97(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_98(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_99(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_100(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_101(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_102(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_103(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_104(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_105(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_106(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_107(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_108(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_109(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_110(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 179
type: SIMPLE_ASSIGN
intShaCon.conFra.dT.$pDERLSJac1.dummyVarLSJac1 = window.fra_b.T.SeedLSJac1 - heatFlowSensor1.port_a.T.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_179(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,179};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[31] /* intShaCon.conFra.dT.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[0] /* window.fra_b.T.SeedLSJac1 SEED_VAR */ - jacobian->seedVars[2] /* heatFlowSensor1.port_a.T.SeedLSJac1 SEED_VAR */;
#line 731 OMC_FILE
  TRACE_POP
}

/*
equation index: 180
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT.$pDERLSJac1.dummyVarLSJac1 = window.glaUns_b.T.SeedLSJac1 - heatFlowSensor1.port_a.T.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_180(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,180};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[29] /* intShaCon.conWinUns.dT.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[1] /* window.glaUns_b.T.SeedLSJac1 SEED_VAR */ - jacobian->seedVars[2] /* heatFlowSensor1.port_a.T.SeedLSJac1 SEED_VAR */;
#line 748 OMC_FILE
  TRACE_POP
}

/*
equation index: 181
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_b.$pDERLSJac1.dummyVarLSJac1 = 100769635.3235 * window.glaUns_b.T.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_181(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,181};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[28] /* window.glaUns.glass.1.T4_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[1] /* window.glaUns_b.T.SeedLSJac1 SEED_VAR */);
#line 765 OMC_FILE
  TRACE_POP
}

/*
equation index: 182
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 = intShaCon.conSha.Gc * (2.0 * intShaCon.glaSha.T.SeedLSJac1 + (-heatFlowSensor1.port_a.T.SeedLSJac1) - intShaCon.TSha.SeedLSJac1)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_182(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,182};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[21] /* intShaCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[7] /* intShaCon.glaSha.T.SeedLSJac1 SEED_VAR */) + (-jacobian->seedVars[2] /* heatFlowSensor1.port_a.T.SeedLSJac1 SEED_VAR */) - jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac1 SEED_VAR */);
#line 782 OMC_FILE
  TRACE_POP
}

/*
equation index: 183
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow.$pDERLSJac1.dummyVarLSJac1 = intShaCon.conSha.Gc * (2.0 * (heatFlowSensor1.port_a.T.SeedLSJac1 - intShaCon.TSha.SeedLSJac1) + heatFlowSensor1.port_a.T.SeedLSJac1 - intShaCon.glaSha.T.SeedLSJac1)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_183(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,183};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[20] /* intShaCon.conSha.air.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[2] /* heatFlowSensor1.port_a.T.SeedLSJac1 SEED_VAR */ - jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac1 SEED_VAR */) + jacobian->seedVars[2] /* heatFlowSensor1.port_a.T.SeedLSJac1 SEED_VAR */ - jacobian->seedVars[7] /* intShaCon.glaSha.T.SeedLSJac1 SEED_VAR */);
#line 799 OMC_FILE
  TRACE_POP
}

/*
equation index: 184
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow.$pDERLSJac1.dummyVarLSJac1 = (-intShaCon.conSha.air.Q_flow.$pDERLSJac1.dummyVarLSJac1) - intShaCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_184(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,184};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[23] /* intShaCon.QRadAbs_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[20] /* intShaCon.conSha.air.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[21] /* intShaCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 816 OMC_FILE
  TRACE_POP
}

/*
equation index: 185
type: SIMPLE_ASSIGN
intShaRad.T4.$pDERLSJac1.dummyVarLSJac1 = 25192408.83087499 * intShaCon.TSha.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_185(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,185};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[13] /* intShaRad.T4.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (25192408.83087499) * (jacobian->seedVars[3] /* intShaCon.TSha.SeedLSJac1 SEED_VAR */);
#line 833 OMC_FILE
  TRACE_POP
}

/*
equation index: 186
type: SIMPLE_ASSIGN
intShaRad.E_glass.$pDERLSJac1.dummyVarLSJac1 = 1.134074883836886e-08 * shaSig.y * intShaRad.T4.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_186(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,186};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[14] /* intShaRad.E_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (1.134074883836886e-08) * (((data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->tmpVars[13] /* intShaRad.T4.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */));
#line 850 OMC_FILE
  TRACE_POP
}

/*
equation index: 187
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1 = extCon.conWinUns.Gc * window.glaUns_a.T.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_187(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,187};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->tmpVars[11] /* extCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[17] /* extCon.conWinUns.Gc variable */)) * (jacobian->seedVars[4] /* window.glaUns_a.T.SeedLSJac1 SEED_VAR */);
#line 867 OMC_FILE
  TRACE_POP
}

/*
equation index: 188
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_a.$pDERLSJac1.dummyVarLSJac1 = 100769635.3235 * window.glaUns_a.T.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_188(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,188};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[8] /* window.glaUns.glass.1.T4_a.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[4] /* window.glaUns_a.T.SeedLSJac1 SEED_VAR */);
#line 884 OMC_FILE
  TRACE_POP
}

/*
equation index: 189
type: SIMPLE_ASSIGN
extCon.JInUns.$pDERLSJac1.dummyVarLSJac1 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_a.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_189(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,189};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[12] /* extCon.JInUns.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->tmpVars[8] /* window.glaUns.glass.1.T4_a.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */));
#line 901 OMC_FILE
  TRACE_POP
}

/*
equation index: 190
type: SIMPLE_ASSIGN
$res_LSJac1_6.$pDERLSJac1.dummyVarLSJac1 = 0.00375 * (extCon.JInUns.$pDERLSJac1.dummyVarLSJac1 + extCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1) + window.glaUns.u * (window.glaUns_a.T.SeedLSJac1 - window.glaUns_b.T.SeedLSJac1)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_190(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,190};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[5] /* $res_LSJac1_6.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = (0.00375) * (jacobian->tmpVars[12] /* extCon.JInUns.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[11] /* extCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) + ((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->seedVars[4] /* window.glaUns_a.T.SeedLSJac1 SEED_VAR */ - jacobian->seedVars[1] /* window.glaUns_b.T.SeedLSJac1 SEED_VAR */);
#line 918 OMC_FILE
  TRACE_POP
}

/*
equation index: 191
type: SIMPLE_ASSIGN
intShaRad.JIn_air.$pDERLSJac1.dummyVarLSJac1 = shaSig.y * indRad.JIn.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_191(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,191};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[7] /* intShaRad.JIn_air.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->seedVars[5] /* indRad.JIn.SeedLSJac1 SEED_VAR */);
#line 935 OMC_FILE
  TRACE_POP
}

/*
equation index: 192
type: SIMPLE_ASSIGN
intShaRad.JOut_air.$pDERLSJac1.dummyVarLSJac1 = intShaRad.E_glass.$pDERLSJac1.dummyVarLSJac1 + 0.75 * intShaRad.JIn_air.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_192(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,192};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[15] /* intShaRad.JOut_air.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[14] /* intShaRad.E_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ + (0.75) * (jacobian->tmpVars[7] /* intShaRad.JIn_air.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */);
#line 952 OMC_FILE
  TRACE_POP
}

/*
equation index: 193
type: SIMPLE_ASSIGN
window.JOutUns_b.$pDERLSJac1.dummyVarLSJac1 = indRad.JIn.SeedLSJac1 - intShaRad.JOut_air.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_193(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,193};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[16] /* window.JOutUns_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[5] /* indRad.JIn.SeedLSJac1 SEED_VAR */ - jacobian->tmpVars[15] /* intShaRad.JOut_air.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 969 OMC_FILE
  TRACE_POP
}

/*
equation index: 194
type: SIMPLE_ASSIGN
intShaRad.JIn_glass.$pDERLSJac1.dummyVarLSJac1 = 8.0 * intShaRad.E_glass.$pDERLSJac1.dummyVarLSJac1 + 4.0 * intShaCon.QRadAbs_flow.$pDERLSJac1.dummyVarLSJac1 - intShaRad.JIn_air.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_194(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,194};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[24] /* intShaRad.JIn_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (8.0) * (jacobian->tmpVars[14] /* intShaRad.E_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) + (4.0) * (jacobian->tmpVars[23] /* intShaCon.QRadAbs_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[7] /* intShaRad.JIn_air.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 986 OMC_FILE
  TRACE_POP
}

/*
equation index: 195
type: SIMPLE_ASSIGN
window.JInUns_b.$pDERLSJac1.dummyVarLSJac1 = (1.0 - shaSig.y) * indRad.JIn.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_195(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,195};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[6] /* window.JInUns_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->seedVars[5] /* indRad.JIn.SeedLSJac1 SEED_VAR */);
#line 1003 OMC_FILE
  TRACE_POP
}

/*
equation index: 196
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1 = window.JInUns_b.$pDERLSJac1.dummyVarLSJac1 - window.JOutUns_b.$pDERLSJac1.dummyVarLSJac1 - extCon.JInUns.$pDERLSJac1.dummyVarLSJac1 - extCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_196(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,196};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[17] /* intShaCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[6] /* window.JInUns_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[16] /* window.JOutUns_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[12] /* extCon.JInUns.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[11] /* extCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1020 OMC_FILE
  TRACE_POP
}

/*
equation index: 197
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow.$pDERLSJac1.dummyVarLSJac1 = 1.25 * intShaCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_197(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,197};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[19] /* intShaCon.conWinUns.q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (1.25) * (jacobian->tmpVars[17] /* intShaCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */);
#line 1037 OMC_FILE
  TRACE_POP
}

/*
equation index: 198
type: SIMPLE_ASSIGN
$res_LSJac1_7.$pDERLSJac1.dummyVarLSJac1 = 4.0 * intShaCon.conFra.u * intShaCon.conWinUns.dT.$pDERLSJac1.dummyVarLSJac1 - intShaCon.conWinUns.q_flow.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_198(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,198};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[6] /* $res_LSJac1_7.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[29] /* intShaCon.conWinUns.dT.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[19] /* intShaCon.conWinUns.q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1054 OMC_FILE
  TRACE_POP
}

/*
equation index: 199
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow.$pDERLSJac1.dummyVarLSJac1 = intShaCon.conSha.air.Q_flow.$pDERLSJac1.dummyVarLSJac1 - intShaCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_199(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,199};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[20] /* intShaCon.conSha.air.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[17] /* intShaCon.conWinUns.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1071 OMC_FILE
  TRACE_POP
}

/*
equation index: 200
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow.$pDERLSJac1.dummyVarLSJac1 = 5.0 * intShaCon.conFra.Q_flow.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_200(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,200};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[26] /* intShaCon.conFra.q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (5.0) * (jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */);
#line 1088 OMC_FILE
  TRACE_POP
}

/*
equation index: 201
type: SIMPLE_ASSIGN
$res_LSJac1_2.$pDERLSJac1.dummyVarLSJac1 = 4.0 * intShaCon.conFra.u * intShaCon.conFra.dT.$pDERLSJac1.dummyVarLSJac1 - intShaCon.conFra.q_flow.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_201(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,201};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[1] /* $res_LSJac1_2.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[31] /* intShaCon.conFra.dT.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[26] /* intShaCon.conFra.q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1105 OMC_FILE
  TRACE_POP
}

/*
equation index: 202
type: SIMPLE_ASSIGN
window.frame.dT.$pDERLSJac1.dummyVarLSJac1 = (-intShaCon.conFra.Q_flow.$pDERLSJac1.dummyVarLSJac1) / (-0.6000000000000001)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_202(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,202};
  jacobian->tmpVars[27] /* window.frame.dT.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = DIVISION((-jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */),-0.6000000000000001,"-0.6000000000000001");
  TRACE_POP
}

/*
equation index: 203
type: SIMPLE_ASSIGN
extCon.conFra.dT.$pDERLSJac1.dummyVarLSJac1 = window.fra_b.T.SeedLSJac1 + window.frame.dT.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_203(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,203};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  jacobian->tmpVars[32] /* extCon.conFra.dT.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[0] /* window.fra_b.T.SeedLSJac1 SEED_VAR */ + jacobian->tmpVars[27] /* window.frame.dT.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1137 OMC_FILE
  TRACE_POP
}

/*
equation index: 204
type: SIMPLE_ASSIGN
$res_LSJac1_1.$pDERLSJac1.dummyVarLSJac1 = extCon.conCoeFra.GCon * extCon.conFra.dT.$pDERLSJac1.dummyVarLSJac1 + intShaCon.conFra.Q_flow.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_204(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,204};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->resultVars[0] /* $res_LSJac1_1.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = ((data->localData[0]->realVars[14] /* extCon.conCoeFra.GCon variable */)) * (jacobian->tmpVars[32] /* extCon.conFra.dT.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1154 OMC_FILE
  TRACE_POP
}

/*
equation index: 205
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_b.$pDERLSJac1.dummyVarLSJac1 = window.JOutUns_b.$pDERLSJac1.dummyVarLSJac1 - 0.16 * window.JInUns_b.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_205(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,205};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[18] /* window.glaUns.glass.1.E_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[16] /* window.JOutUns_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - ((0.16) * (jacobian->tmpVars[6] /* window.JInUns_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */));
#line 1171 OMC_FILE
  TRACE_POP
}

/*
equation index: 206
type: SIMPLE_ASSIGN
$res_LSJac1_8.$pDERLSJac1.dummyVarLSJac1 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_b.$pDERLSJac1.dummyVarLSJac1 - window.glaUns.glass.1.E_b.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_206(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,206};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[7] /* $res_LSJac1_8.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->tmpVars[28] /* window.glaUns.glass.1.T4_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[18] /* window.glaUns.glass.1.E_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1188 OMC_FILE
  TRACE_POP
}

/*
equation index: 207
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_a.$pDERLSJac1.dummyVarLSJac1 = 100769635.3235 * window.glaSha_a.T.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_207(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,207};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[4] /* window.glaSha.glass.1.T4_a.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[6] /* window.glaSha_a.T.SeedLSJac1 SEED_VAR */);
#line 1205 OMC_FILE
  TRACE_POP
}

/*
equation index: 208
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_a.$pDERLSJac1.dummyVarLSJac1 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_a.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_208(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,208};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[5] /* window.glaSha.glass.1.E_a.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->tmpVars[4] /* window.glaSha.glass.1.T4_a.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */));
#line 1222 OMC_FILE
  TRACE_POP
}

/*
equation index: 209
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 = extCon.shaCon.Gc * window.glaSha_a.T.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_209(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,209};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[2] /* extCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[24] /* extCon.shaCon.Gc variable */)) * (jacobian->seedVars[6] /* window.glaSha_a.T.SeedLSJac1 SEED_VAR */);
#line 1239 OMC_FILE
  TRACE_POP
}

/*
equation index: 210
type: SIMPLE_ASSIGN
extCon.JInSha.$pDERLSJac1.dummyVarLSJac1 = (-extCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1) - window.glaSha.u * (intShaCon.glaSha.T.SeedLSJac1 - window.glaSha_a.T.SeedLSJac1) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_210(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,210};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[3] /* extCon.JInSha.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[2] /* extCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->seedVars[7] /* intShaCon.glaSha.T.SeedLSJac1 SEED_VAR */ - jacobian->seedVars[6] /* window.glaSha_a.T.SeedLSJac1 SEED_VAR */),-0.00375,"-0.00375"));
#line 1256 OMC_FILE
  TRACE_POP
}

/*
equation index: 211
type: SIMPLE_ASSIGN
$res_LSJac1_5.$pDERLSJac1.dummyVarLSJac1 = window.glaSha.glass.1.E_a.$pDERLSJac1.dummyVarLSJac1 - extCon.JInSha.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_211(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,211};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[4] /* $res_LSJac1_5.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = jacobian->tmpVars[5] /* window.glaSha.glass.1.E_a.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[3] /* extCon.JInSha.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1273 OMC_FILE
  TRACE_POP
}

/*
equation index: 212
type: SIMPLE_ASSIGN
intShaRad.JOut_glass.$pDERLSJac1.dummyVarLSJac1 = intShaCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 - ((-intShaRad.JIn_glass.$pDERLSJac1.dummyVarLSJac1) - extCon.JInSha.$pDERLSJac1.dummyVarLSJac1 - extCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_212(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 33;
  const int equationIndexes[2] = {1,212};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[25] /* intShaRad.JOut_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[21] /* intShaCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - ((-jacobian->tmpVars[24] /* intShaRad.JIn_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[3] /* extCon.JInSha.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[2] /* extCon.glaSha.Q_flow.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */);
#line 1290 OMC_FILE
  TRACE_POP
}

/*
equation index: 213
type: SIMPLE_ASSIGN
$res_LSJac1_3.$pDERLSJac1.dummyVarLSJac1 = 0.75 * intShaRad.JIn_glass.$pDERLSJac1.dummyVarLSJac1 + intShaRad.E_glass.$pDERLSJac1.dummyVarLSJac1 - intShaRad.JOut_glass.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_213(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 34;
  const int equationIndexes[2] = {1,213};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->resultVars[2] /* $res_LSJac1_3.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = (0.75) * (jacobian->tmpVars[24] /* intShaRad.JIn_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[14] /* intShaRad.E_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[25] /* intShaRad.JOut_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1307 OMC_FILE
  TRACE_POP
}

/*
equation index: 214
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_b.$pDERLSJac1.dummyVarLSJac1 = 100769635.3235 * intShaCon.glaSha.T.SeedLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_214(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 35;
  const int equationIndexes[2] = {1,214};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[0] /* window.glaSha.glass.1.T4_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[7] /* intShaCon.glaSha.T.SeedLSJac1 SEED_VAR */);
#line 1324 OMC_FILE
  TRACE_POP
}

/*
equation index: 215
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_b.$pDERLSJac1.dummyVarLSJac1 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_b.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_215(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 36;
  const int equationIndexes[2] = {1,215};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[1] /* window.glaSha.glass.1.E_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->tmpVars[0] /* window.glaSha.glass.1.T4_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */));
#line 1341 OMC_FILE
  TRACE_POP
}

/*
equation index: 216
type: SIMPLE_ASSIGN
$res_LSJac1_4.$pDERLSJac1.dummyVarLSJac1 = 0.16 * intShaRad.JOut_glass.$pDERLSJac1.dummyVarLSJac1 + window.glaSha.glass.1.E_b.$pDERLSJac1.dummyVarLSJac1 - intShaRad.JIn_glass.$pDERLSJac1.dummyVarLSJac1
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_216(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 37;
  const int equationIndexes[2] = {1,216};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[3] /* $res_LSJac1_4.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_VAR */ = (0.16) * (jacobian->tmpVars[25] /* intShaRad.JOut_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[1] /* window.glaSha.glass.1.E_b.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[24] /* intShaRad.JIn_glass.$pDERLSJac1.dummyVarLSJac1 JACOBIAN_DIFF_VAR */;
#line 1358 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac1_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_LSJac1;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac1_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_LSJac1;
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_179(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_180(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_181(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_182(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_183(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_184(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_185(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_186(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_187(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_188(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_189(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_190(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_191(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_192(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_193(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_194(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_195(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_196(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_197(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_198(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_199(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_200(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_201(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_202(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_203(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_204(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_205(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_206(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_207(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_208(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_209(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_210(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_211(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_212(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_213(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_214(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_215(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_216(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 626
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 - heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_626(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,626};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[27] /* intShaCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[2] /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */ - jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */;
#line 1436 OMC_FILE
  TRACE_POP
}

/*
equation index: 627
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 100769635.3235 * window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_627(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,627};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[26] /* window.glaUns.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[2] /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1453 OMC_FILE
  TRACE_POP
}

/*
equation index: 628
type: SIMPLE_ASSIGN
intShaRad.T4.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 25192408.83087499 * intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_628(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,628};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[25] /* intShaRad.T4.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (25192408.83087499) * (jacobian->seedVars[3] /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1470 OMC_FILE
  TRACE_POP
}

/*
equation index: 629
type: SIMPLE_ASSIGN
intShaRad.JOut_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = indRad.JIn.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 - window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_629(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,629};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[16] /* intShaRad.JOut_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[8] /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */ - jacobian->seedVars[5] /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */;
#line 1487 OMC_FILE
  TRACE_POP
}

/*
equation index: 630
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = extCon.conWinUns.Gc * window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_630(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,630};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->tmpVars[12] /* extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[17] /* extCon.conWinUns.Gc variable */)) * (jacobian->seedVars[6] /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1504 OMC_FILE
  TRACE_POP
}

/*
equation index: 631
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 100769635.3235 * window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_631(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,631};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[8] /* window.glaUns.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[6] /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1521 OMC_FILE
  TRACE_POP
}

/*
equation index: 632
type: SIMPLE_ASSIGN
extCon.JInUns.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_632(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,632};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[10] /* extCon.JInUns.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->tmpVars[8] /* window.glaUns.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */));
#line 1538 OMC_FILE
  TRACE_POP
}

/*
equation index: 633
type: SIMPLE_ASSIGN
$res_LSJac2_4.$pDERLSJac2.dummyVarLSJac2 = 0.00375 * (extCon.JInUns.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 + extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2) + window.glaUns.u * (window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 - window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_633(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,633};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[3] /* $res_LSJac2_4.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = (0.00375) * (jacobian->tmpVars[10] /* extCon.JInUns.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[12] /* extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */) + ((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->seedVars[6] /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */ - jacobian->seedVars[2] /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1555 OMC_FILE
  TRACE_POP
}

/*
equation index: 634
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 100769635.3235 * window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_634(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,634};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[6] /* window.glaSha.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[7] /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1572 OMC_FILE
  TRACE_POP
}

/*
equation index: 635
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_635(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,635};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[7] /* window.glaSha.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->tmpVars[6] /* window.glaSha.glass.1.T4_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */));
#line 1589 OMC_FILE
  TRACE_POP
}

/*
equation index: 636
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = extCon.shaCon.Gc * window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_636(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,636};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[24] /* extCon.shaCon.Gc variable */)) * (jacobian->seedVars[7] /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1606 OMC_FILE
  TRACE_POP
}

/*
equation index: 637
type: SIMPLE_ASSIGN
extCon.JInSha.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = (-extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2) - window.glaSha.u * (intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 - window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_637(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,637};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[5] /* extCon.JInSha.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->seedVars[9] /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */ - jacobian->seedVars[7] /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */),-0.00375,"-0.00375"));
#line 1623 OMC_FILE
  TRACE_POP
}

/*
equation index: 638
type: SIMPLE_ASSIGN
$res_LSJac2_2.$pDERLSJac2.dummyVarLSJac2 = window.glaSha.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - extCon.JInSha.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_638(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,638};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[1] /* $res_LSJac2_2.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = jacobian->tmpVars[7] /* window.glaSha.glass.1.E_a.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[5] /* extCon.JInSha.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1640 OMC_FILE
  TRACE_POP
}

/*
equation index: 639
type: SIMPLE_ASSIGN
window.JInUns_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = (1.0 - shaSig.y) * indRad.JIn.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_639(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,639};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[3] /* window.JInUns_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->seedVars[8] /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1657 OMC_FILE
  TRACE_POP
}

/*
equation index: 640
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = window.JInUns_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - extCon.JInUns.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_640(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,640};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[13] /* intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[3] /* window.JInUns_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[12] /* extCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[10] /* extCon.JInUns.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[5] /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */;
#line 1674 OMC_FILE
  TRACE_POP
}

/*
equation index: 641
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 1.25 * intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_641(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,641};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[15] /* intShaCon.conWinUns.q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (1.25) * (jacobian->tmpVars[13] /* intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */);
#line 1691 OMC_FILE
  TRACE_POP
}

/*
equation index: 642
type: SIMPLE_ASSIGN
$res_LSJac2_6.$pDERLSJac2.dummyVarLSJac2 = 4.0 * intShaCon.conFra.u * intShaCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - intShaCon.conWinUns.q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_642(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,642};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[5] /* $res_LSJac2_6.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[27] /* intShaCon.conWinUns.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[15] /* intShaCon.conWinUns.q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1708 OMC_FILE
  TRACE_POP
}

/*
equation index: 643
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 - 0.16 * window.JInUns_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_643(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,643};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[14] /* window.glaUns.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[5] /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */ - ((0.16) * (jacobian->tmpVars[3] /* window.JInUns_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */));
#line 1725 OMC_FILE
  TRACE_POP
}

/*
equation index: 644
type: SIMPLE_ASSIGN
$res_LSJac2_5.$pDERLSJac2.dummyVarLSJac2 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - window.glaUns.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_644(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,644};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[4] /* $res_LSJac2_5.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->tmpVars[26] /* window.glaUns.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[14] /* window.glaUns.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1742 OMC_FILE
  TRACE_POP
}

/*
equation index: 645
type: SIMPLE_ASSIGN
intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = shaSig.y * indRad.JIn.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_645(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,645};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[2] /* intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->seedVars[8] /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1759 OMC_FILE
  TRACE_POP
}

/*
equation index: 646
type: SIMPLE_ASSIGN
intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = intShaRad.JOut_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - 0.75 * intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_646(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,646};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[17] /* intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[16] /* intShaRad.JOut_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - ((0.75) * (jacobian->tmpVars[2] /* intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */));
#line 1776 OMC_FILE
  TRACE_POP
}

/*
equation index: 647
type: SIMPLE_ASSIGN
intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 + 0.75 * intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_647(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,647};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[19] /* intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[17] /* intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ + (0.75) * (jacobian->seedVars[4] /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 1793 OMC_FILE
  TRACE_POP
}

/*
equation index: 648
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - extCon.JInSha.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_648(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,648};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[20] /* intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[19] /* intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[5] /* extCon.JInSha.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[4] /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */;
#line 1810 OMC_FILE
  TRACE_POP
}

/*
equation index: 649
type: SIMPLE_ASSIGN
$res_LSJac2_9.$pDERLSJac2.dummyVarLSJac2 = intShaCon.conSha.Gc * (2.0 * intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 + (-heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2) - intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2) - intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_649(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,649};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->resultVars[8] /* $res_LSJac2_9.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[9] /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */) + (-jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */) - jacobian->seedVars[3] /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */) - jacobian->tmpVars[20] /* intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1827 OMC_FILE
  TRACE_POP
}

/*
equation index: 650
type: SIMPLE_ASSIGN
$res_LSJac2_1.$pDERLSJac2.dummyVarLSJac2 = 1.134074883836886e-08 * shaSig.y * intShaRad.T4.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_650(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,650};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->resultVars[0] /* $res_LSJac2_1.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = (1.134074883836886e-08) * (((data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->tmpVars[25] /* intShaRad.T4.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[17] /* intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1844 OMC_FILE
  TRACE_POP
}

/*
equation index: 651
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 0.25 * (intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 + intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2) - 2.0 * intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_651(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,651};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[18] /* intShaCon.QRadAbs_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (0.25) * (jacobian->tmpVars[2] /* intShaRad.JIn_air.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ + jacobian->seedVars[4] /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */) - ((2.0) * (jacobian->tmpVars[17] /* intShaRad.E_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */));
#line 1861 OMC_FILE
  TRACE_POP
}

/*
equation index: 652
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = (-intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2) - intShaCon.QRadAbs_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_652(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,652};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[21] /* intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[20] /* intShaCon.glaSha.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[18] /* intShaCon.QRadAbs_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1878 OMC_FILE
  TRACE_POP
}

/*
equation index: 653
type: SIMPLE_ASSIGN
intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_653(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,653};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[21] /* intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[13] /* intShaCon.conWinUns.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1895 OMC_FILE
  TRACE_POP
}

/*
equation index: 654
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 5.0 * intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_654(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,654};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[23] /* intShaCon.conFra.q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (5.0) * (jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */);
#line 1912 OMC_FILE
  TRACE_POP
}

/*
equation index: 655
type: SIMPLE_ASSIGN
window.frame.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = (-intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2) / (-0.6000000000000001)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_655(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,655};
  jacobian->tmpVars[24] /* window.frame.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = DIVISION((-jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */),-0.6000000000000001,"-0.6000000000000001");
  TRACE_POP
}

/*
equation index: 656
type: SIMPLE_ASSIGN
window.fra_b.T.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 - window.frame.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_656(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,656};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  jacobian->tmpVars[29] /* window.fra_b.T.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[0] /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */ - jacobian->tmpVars[24] /* window.frame.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1944 OMC_FILE
  TRACE_POP
}

/*
equation index: 657
type: SIMPLE_ASSIGN
intShaCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = window.fra_b.T.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_657(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,657};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[30] /* intShaCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[29] /* window.fra_b.T.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */;
#line 1961 OMC_FILE
  TRACE_POP
}

/*
equation index: 658
type: SIMPLE_ASSIGN
$res_LSJac2_3.$pDERLSJac2.dummyVarLSJac2 = 4.0 * intShaCon.conFra.u * intShaCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - intShaCon.conFra.q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_658(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,658};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[2] /* $res_LSJac2_3.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[30] /* intShaCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[23] /* intShaCon.conFra.q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1978 OMC_FILE
  TRACE_POP
}

/*
equation index: 659
type: SIMPLE_ASSIGN
$res_LSJac2_7.$pDERLSJac2.dummyVarLSJac2 = extCon.conCoeFra.GCon * extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 + intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_659(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 33;
  const int equationIndexes[2] = {1,659};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->resultVars[6] /* $res_LSJac2_7.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = ((data->localData[0]->realVars[14] /* extCon.conCoeFra.GCon variable */)) * (jacobian->seedVars[0] /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */) + jacobian->tmpVars[22] /* intShaCon.conFra.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 1995 OMC_FILE
  TRACE_POP
}

/*
equation index: 660
type: SIMPLE_ASSIGN
$res_LSJac2_8.$pDERLSJac2.dummyVarLSJac2 = intShaCon.conSha.Gc * (2.0 * (heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 - intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2) + heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 - intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2) - intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_660(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 34;
  const int equationIndexes[2] = {1,660};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->resultVars[7] /* $res_LSJac2_8.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */ - jacobian->seedVars[3] /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */) + jacobian->seedVars[1] /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */ - jacobian->seedVars[9] /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */) - jacobian->tmpVars[21] /* intShaCon.conSha.air.Q_flow.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */;
#line 2012 OMC_FILE
  TRACE_POP
}

/*
equation index: 661
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 100769635.3235 * intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_661(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 35;
  const int equationIndexes[2] = {1,661};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[0] /* window.glaSha.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[9] /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */);
#line 2029 OMC_FILE
  TRACE_POP
}

/*
equation index: 662
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_662(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 36;
  const int equationIndexes[2] = {1,662};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[1] /* window.glaSha.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->tmpVars[0] /* window.glaSha.glass.1.T4_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */));
#line 2046 OMC_FILE
  TRACE_POP
}

/*
equation index: 663
type: SIMPLE_ASSIGN
$res_LSJac2_10.$pDERLSJac2.dummyVarLSJac2 = 0.16 * intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 + window.glaSha.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 - intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_663(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 37;
  const int equationIndexes[2] = {1,663};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[9] /* $res_LSJac2_10.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_VAR */ = (0.16) * (jacobian->tmpVars[19] /* intShaRad.JOut_glass.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[1] /* window.glaSha.glass.1.E_b.$pDERFMIDER.dummyVarFMIDER.$pDERLSJac2.dummyVarLSJac2 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[4] /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER.SeedLSJac2 SEED_VAR */;
#line 2063 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac2_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_LSJac2;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac2_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_LSJac2;
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_626(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_627(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_628(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_629(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_630(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_631(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_632(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_633(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_634(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_635(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_636(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_637(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_638(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_639(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_640(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_641(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_642(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_643(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_644(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_645(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_646(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_647(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_648(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_649(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_650(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_651(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_652(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_653(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_654(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_655(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_656(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_657(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_658(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_659(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_660(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_661(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_662(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_663(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 717
type: SIMPLE_ASSIGN
window.fra_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 + intShaCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_717(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,717};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[29] /* window.fra_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[4] /* heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */ + jacobian->seedVars[0] /* intShaCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */;
#line 2141 OMC_FILE
  TRACE_POP
}

/*
equation index: 718
type: SIMPLE_ASSIGN
extCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = extCon.conWinUns.Gc * window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_718(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,718};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->tmpVars[27] /* extCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[17] /* extCon.conWinUns.Gc variable */)) * (jacobian->seedVars[1] /* window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2158 OMC_FILE
  TRACE_POP
}

/*
equation index: 719
type: SIMPLE_ASSIGN
extCon.JInUns.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = (-extCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3) - window.glaUns.u * (window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 - window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_719(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,719};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[28] /* extCon.JInUns.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[27] /* extCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->seedVars[2] /* window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */ - jacobian->seedVars[1] /* window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */),-0.00375,"-0.00375"));
#line 2175 OMC_FILE
  TRACE_POP
}

/*
equation index: 720
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 100769635.3235 * window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_720(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,720};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[24] /* window.glaUns.glass.1.T4_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[1] /* window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2192 OMC_FILE
  TRACE_POP
}

/*
equation index: 721
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_721(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,721};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[25] /* window.glaUns.glass.1.E_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->tmpVars[24] /* window.glaUns.glass.1.T4_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */));
#line 2209 OMC_FILE
  TRACE_POP
}

/*
equation index: 722
type: SIMPLE_ASSIGN
$res_LSJac3_1.$pDERLSJac3.dummyVarLSJac3 = window.glaUns.glass.1.E_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - extCon.JInUns.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_722(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,722};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[0] /* $res_LSJac3_1.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = jacobian->tmpVars[25] /* window.glaUns.glass.1.E_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[28] /* extCon.JInUns.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2226 OMC_FILE
  TRACE_POP
}

/*
equation index: 723
type: SIMPLE_ASSIGN
intShaCon.conWinUns.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 - heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_723(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,723};
#line 17 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[23] /* intShaCon.conWinUns.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[2] /* window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */ - jacobian->seedVars[4] /* heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */;
#line 2243 OMC_FILE
  TRACE_POP
}

/*
equation index: 724
type: SIMPLE_ASSIGN
window.glaUns.glass.1.T4_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 100769635.3235 * window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_724(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,724};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[22] /* window.glaUns.glass.1.T4_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[2] /* window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2260 OMC_FILE
  TRACE_POP
}

/*
equation index: 725
type: SIMPLE_ASSIGN
window.frame.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = (-intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3) / (-0.6000000000000001)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_725(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,725};
  jacobian->tmpVars[20] /* window.frame.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = DIVISION((-jacobian->seedVars[3] /* intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */),-0.6000000000000001,"-0.6000000000000001");
  TRACE_POP
}

/*
equation index: 726
type: SIMPLE_ASSIGN
extCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = window.fra_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 + window.frame.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_726(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,726};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  jacobian->tmpVars[31] /* extCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[29] /* window.fra_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[20] /* window.frame.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2292 OMC_FILE
  TRACE_POP
}

/*
equation index: 727
type: SIMPLE_ASSIGN
$res_LSJac3_7.$pDERLSJac3.dummyVarLSJac3 = extCon.conCoeFra.GCon * extCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 + intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_727(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,727};
#line 20 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/Convection.mo"
  jacobian->resultVars[6] /* $res_LSJac3_7.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = ((data->localData[0]->realVars[14] /* extCon.conCoeFra.GCon variable */)) * (jacobian->tmpVars[31] /* extCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) + jacobian->seedVars[3] /* intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */;
#line 2309 OMC_FILE
  TRACE_POP
}

/*
equation index: 728
type: SIMPLE_ASSIGN
intShaCon.conFra.q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 5.0 * intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_728(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,728};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[19] /* intShaCon.conFra.q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (5.0) * (jacobian->seedVars[3] /* intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2326 OMC_FILE
  TRACE_POP
}

/*
equation index: 729
type: SIMPLE_ASSIGN
$res_LSJac3_8.$pDERLSJac3.dummyVarLSJac3 = 4.0 * intShaCon.conFra.u * intShaCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 - intShaCon.conFra.q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_729(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,729};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[7] /* $res_LSJac3_8.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * (jacobian->seedVars[0] /* intShaCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */)) - jacobian->tmpVars[19] /* intShaCon.conFra.q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2343 OMC_FILE
  TRACE_POP
}

/*
equation index: 730
type: SIMPLE_ASSIGN
intShaCon.conSha.air.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = intShaCon.conSha.Gc * (2.0 * (heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 - intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3) + heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 - intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_730(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,730};
#line 50 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[14] /* intShaCon.conSha.air.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[4] /* heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */ - jacobian->seedVars[5] /* intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */) + jacobian->seedVars[4] /* heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */ - jacobian->seedVars[8] /* intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2360 OMC_FILE
  TRACE_POP
}

/*
equation index: 731
type: SIMPLE_ASSIGN
intShaCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = intShaCon.conSha.air.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_731(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,731};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  jacobian->tmpVars[18] /* intShaCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[14] /* intShaCon.conSha.air.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - jacobian->seedVars[3] /* intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */;
#line 2377 OMC_FILE
  TRACE_POP
}

/*
equation index: 732
type: SIMPLE_ASSIGN
intShaCon.conWinUns.q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 1.25 * intShaCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_732(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,732};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Convection/BaseClasses/PartialConvection.mo"
  jacobian->tmpVars[21] /* intShaCon.conWinUns.q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (1.25) * (jacobian->tmpVars[18] /* intShaCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */);
#line 2394 OMC_FILE
  TRACE_POP
}

/*
equation index: 733
type: SIMPLE_ASSIGN
$res_LSJac3_3.$pDERLSJac3.dummyVarLSJac3 = 4.0 * intShaCon.conFra.u * intShaCon.conWinUns.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - intShaCon.conWinUns.q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_733(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,733};
#line 44 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/InteriorConvection.mo"
  jacobian->resultVars[2] /* $res_LSJac3_3.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = (4.0) * (((data->localData[0]->realVars[47] /* intShaCon.conFra.u variable */)) * (jacobian->tmpVars[23] /* intShaCon.conWinUns.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[21] /* intShaCon.conWinUns.q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2411 OMC_FILE
  TRACE_POP
}

/*
equation index: 734
type: SIMPLE_ASSIGN
intShaCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = intShaCon.conSha.Gc * (2.0 * intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 + (-heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3) - intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_734(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,734};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[13] /* intShaCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[48] /* intShaCon.conSha.Gc variable */)) * ((2.0) * (jacobian->seedVars[8] /* intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */) + (-jacobian->seedVars[4] /* heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */) - jacobian->seedVars[5] /* intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2428 OMC_FILE
  TRACE_POP
}

/*
equation index: 735
type: SIMPLE_ASSIGN
intShaCon.QRadAbs_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = (-intShaCon.conSha.air.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3) - intShaCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_735(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,735};
#line 53 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[15] /* intShaCon.QRadAbs_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[14] /* intShaCon.conSha.air.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[13] /* intShaCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2445 OMC_FILE
  TRACE_POP
}

/*
equation index: 736
type: SIMPLE_ASSIGN
intShaRad.T4.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 25192408.83087499 * intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_736(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,736};
#line 106 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[8] /* intShaRad.T4.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (25192408.83087499) * (jacobian->seedVars[5] /* intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2462 OMC_FILE
  TRACE_POP
}

/*
equation index: 737
type: SIMPLE_ASSIGN
intShaRad.E_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 1.134074883836886e-08 * shaSig.y * intShaRad.T4.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_737(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,737};
#line 115 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[9] /* intShaRad.E_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (1.134074883836886e-08) * (((data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->tmpVars[8] /* intShaRad.T4.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */));
#line 2479 OMC_FILE
  TRACE_POP
}

/*
equation index: 738
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 100769635.3235 * window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_738(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,738};
#line 60 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[6] /* window.glaSha.glass.1.T4_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[6] /* window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2496 OMC_FILE
  TRACE_POP
}

/*
equation index: 739
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_739(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,739};
#line 72 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[7] /* window.glaSha.glass.1.E_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->tmpVars[6] /* window.glaSha.glass.1.T4_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */));
#line 2513 OMC_FILE
  TRACE_POP
}

/*
equation index: 740
type: SIMPLE_ASSIGN
extCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = extCon.shaCon.Gc * window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_740(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,740};
#line 55 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[24] /* extCon.shaCon.Gc variable */)) * (jacobian->seedVars[6] /* window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2530 OMC_FILE
  TRACE_POP
}

/*
equation index: 741
type: SIMPLE_ASSIGN
extCon.JInSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = (-extCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3) - window.glaSha.u * (intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 - window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3) / (-0.00375)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_741(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,741};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[5] /* extCon.JInSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (-jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) - (DIVISION(((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->seedVars[8] /* intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */ - jacobian->seedVars[6] /* window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */),-0.00375,"-0.00375"));
#line 2547 OMC_FILE
  TRACE_POP
}

/*
equation index: 742
type: SIMPLE_ASSIGN
$res_LSJac3_2.$pDERLSJac3.dummyVarLSJac3 = window.glaSha.glass.1.E_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - extCon.JInSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_742(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,742};
#line 78 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[1] /* $res_LSJac3_2.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = jacobian->tmpVars[7] /* window.glaSha.glass.1.E_a.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[5] /* extCon.JInSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2564 OMC_FILE
  TRACE_POP
}

/*
equation index: 743
type: SIMPLE_ASSIGN
window.JInUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = (1.0 - shaSig.y) * indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_743(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,743};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[3] /* window.JInUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->seedVars[7] /* indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2581 OMC_FILE
  TRACE_POP
}

/*
equation index: 744
type: SIMPLE_ASSIGN
intShaRad.JIn_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = shaSig.y * indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_744(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,744};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[2] /* intShaRad.JIn_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[62] /* shaSig.y variable */)) * (jacobian->seedVars[7] /* indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2598 OMC_FILE
  TRACE_POP
}

/*
equation index: 745
type: SIMPLE_ASSIGN
intShaRad.JOut_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = intShaRad.E_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 + 0.75 * intShaRad.JIn_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_745(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,745};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[10] /* intShaRad.JOut_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[9] /* intShaRad.E_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ + (0.75) * (jacobian->tmpVars[2] /* intShaRad.JIn_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */);
#line 2615 OMC_FILE
  TRACE_POP
}

/*
equation index: 746
type: SIMPLE_ASSIGN
window.JOutUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 - intShaRad.JOut_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_746(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,746};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[11] /* window.JOutUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = jacobian->seedVars[7] /* indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */ - jacobian->tmpVars[10] /* intShaRad.JOut_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2632 OMC_FILE
  TRACE_POP
}

/*
equation index: 747
type: SIMPLE_ASSIGN
window.glaUns.glass.1.E_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = window.JOutUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - 0.16 * window.JInUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_747(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 30;
  const int equationIndexes[2] = {1,747};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[12] /* window.glaUns.glass.1.E_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[11] /* window.JOutUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - ((0.16) * (jacobian->tmpVars[3] /* window.JInUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */));
#line 2649 OMC_FILE
  TRACE_POP
}

/*
equation index: 748
type: SIMPLE_ASSIGN
$res_LSJac3_9.$pDERLSJac3.dummyVarLSJac3 = 3.810491609691938e-08 * window.glaUns.u * window.glaUns.glass.1.T4_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - window.glaUns.glass.1.E_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_748(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 31;
  const int equationIndexes[2] = {1,748};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[8] /* $res_LSJac3_9.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[83] /* window.glaUns.u variable */)) * (jacobian->tmpVars[22] /* window.glaUns.glass.1.T4_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */)) - jacobian->tmpVars[12] /* window.glaUns.glass.1.E_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2666 OMC_FILE
  TRACE_POP
}

/*
equation index: 749
type: SIMPLE_ASSIGN
$res_LSJac3_4.$pDERLSJac3.dummyVarLSJac3 = window.JInUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 + (-extCon.JInUns.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3) - window.JOutUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - intShaCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - extCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_749(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 32;
  const int equationIndexes[2] = {1,749};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[3] /* $res_LSJac3_4.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = jacobian->tmpVars[3] /* window.JInUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ + (-jacobian->tmpVars[28] /* extCon.JInUns.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[11] /* window.JOutUns_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[18] /* intShaCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[27] /* extCon.conWinUns.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2683 OMC_FILE
  TRACE_POP
}

/*
equation index: 750
type: SIMPLE_ASSIGN
intShaRad.JIn_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 8.0 * intShaRad.E_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 + 4.0 * intShaCon.QRadAbs_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - intShaRad.JIn_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_750(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 33;
  const int equationIndexes[2] = {1,750};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->tmpVars[16] /* intShaRad.JIn_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (8.0) * (jacobian->tmpVars[9] /* intShaRad.E_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) + (4.0) * (jacobian->tmpVars[15] /* intShaCon.QRadAbs_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[2] /* intShaRad.JIn_air.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2700 OMC_FILE
  TRACE_POP
}

/*
equation index: 751
type: SIMPLE_ASSIGN
intShaRad.JOut_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = intShaRad.JIn_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - ((-extCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3) - intShaCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - extCon.JInSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_751(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 34;
  const int equationIndexes[2] = {1,751};
#line 56 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[16] /* intShaRad.JIn_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - ((-jacobian->tmpVars[4] /* extCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[13] /* intShaCon.glaSha.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[5] /* extCon.JInSha.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */);
#line 2717 OMC_FILE
  TRACE_POP
}

/*
equation index: 752
type: SIMPLE_ASSIGN
$res_LSJac3_6.$pDERLSJac3.dummyVarLSJac3 = 0.75 * intShaRad.JIn_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 + intShaRad.E_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - intShaRad.JOut_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_752(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 35;
  const int equationIndexes[2] = {1,752};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeRadiation.mo"
  jacobian->resultVars[5] /* $res_LSJac3_6.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = (0.75) * (jacobian->tmpVars[16] /* intShaRad.JIn_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[9] /* intShaRad.E_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2734 OMC_FILE
  TRACE_POP
}

/*
equation index: 753
type: SIMPLE_ASSIGN
window.glaSha.glass.1.T4_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 100769635.3235 * intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_753(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 36;
  const int equationIndexes[2] = {1,753};
#line 61 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[0] /* window.glaSha.glass.1.T4_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (100769635.3235) * (jacobian->seedVars[8] /* intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT.SeedLSJac3 SEED_VAR */);
#line 2751 OMC_FILE
  TRACE_POP
}

/*
equation index: 754
type: SIMPLE_ASSIGN
window.glaSha.glass.1.E_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 = 3.810491609691938e-08 * window.glaSha.u * window.glaSha.glass.1.T4_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_754(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 37;
  const int equationIndexes[2] = {1,754};
#line 73 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->tmpVars[1] /* window.glaSha.glass.1.E_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ = (3.810491609691938e-08) * (((data->localData[0]->realVars[77] /* window.glaSha.u variable */)) * (jacobian->tmpVars[0] /* window.glaSha.glass.1.T4_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */));
#line 2768 OMC_FILE
  TRACE_POP
}

/*
equation index: 755
type: SIMPLE_ASSIGN
$res_LSJac3_5.$pDERLSJac3.dummyVarLSJac3 = 0.16 * intShaRad.JOut_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 + window.glaSha.glass.1.E_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 - intShaRad.JIn_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_755(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 38;
  const int equationIndexes[2] = {1,755};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/GlassLayer.mo"
  jacobian->resultVars[4] /* $res_LSJac3_5.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_VAR */ = (0.16) * (jacobian->tmpVars[17] /* intShaRad.JOut_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[1] /* window.glaSha.glass.1.E_b.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[16] /* intShaRad.JIn_glass.$pDERFMIDERINIT.dummyVarFMIDERINIT.$pDERLSJac3.dummyVarLSJac3 JACOBIAN_DIFF_VAR */;
#line 2785 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac3_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_LSJac3;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacLSJac3_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_LSJac3;
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_717(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_718(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_719(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_720(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_721(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_722(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_723(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_724(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_725(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_726(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_727(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_728(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_729(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_730(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_731(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_732(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_733(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_734(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_735(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_736(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_737(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_738(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_739(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_740(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_741(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_742(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_743(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_744(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_745(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_746(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_747(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_748(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_749(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_750(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_751(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_752(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_753(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_754(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_755(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 667
type: SIMPLE_ASSIGN
extCon.radOut.TRad4.$pDERFMIDERINIT.dummyVarFMIDERINIT = 2.0 * (TBlaSky ^ 3.0 * TBlaSky.SeedFMIDERINIT + TOut ^ 3.0 * TOut.SeedFMIDERINIT)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_667(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,667};
  modelica_real tmp0;
  modelica_real tmp1;
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  tmp0 = (data->localData[0]->realVars[5] /* TBlaSky variable */);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  tmp1 = (data->localData[0]->realVars[7] /* TOut variable */);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  jacobian->tmpVars[14] /* extCon.radOut.TRad4.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = (2.0) * (((tmp0 * tmp0 * tmp0)) * (jacobian->seedVars[4] /* TBlaSky.SeedFMIDERINIT SEED_VAR */) + ((tmp1 * tmp1 * tmp1)) * (jacobian->seedVars[5] /* TOut.SeedFMIDERINIT SEED_VAR */));
#line 2870 OMC_FILE
  TRACE_POP
}

/*
equation index: 668
type: SIMPLE_ASSIGN
extCon.radOut.TRad.$pDERFMIDERINIT.dummyVarFMIDERINIT = 9.923624282153128e-09 * extCon.radOut.TRad4.$pDERFMIDERINIT.dummyVarFMIDERINIT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_668(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,668};
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  jacobian->tmpVars[13] /* extCon.radOut.TRad.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = (9.923624282153128e-09) * (jacobian->tmpVars[14] /* extCon.radOut.TRad4.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */);
#line 2887 OMC_FILE
  TRACE_POP
}

/*
equation index: 669
type: SIMPLE_ASSIGN
extCon.radOut.JOut.$pDERFMIDERINIT.dummyVarFMIDERINIT = 4.571212498951346 * extCon.radOut.TRad.$pDERFMIDERINIT.dummyVarFMIDERINIT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_669(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,669};
  jacobian->tmpVars[12] /* extCon.radOut.JOut.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = (4.571212498951346) * (jacobian->tmpVars[13] /* extCon.radOut.TRad.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */);
  TRACE_POP
}

/*
equation index: 670
type: SIMPLE_ASSIGN
extCon.JOutSha.$pDERFMIDERINIT.dummyVarFMIDERINIT = extCon.shaRad.u * extCon.radOut.JOut.$pDERFMIDERINIT.dummyVarFMIDERINIT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_670(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,670};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[3] /* extCon.JOutSha.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[31] /* extCon.shaRad.u variable */)) * (jacobian->tmpVars[12] /* extCon.radOut.JOut.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */);
#line 2919 OMC_FILE
  TRACE_POP
}

/*
equation index: 671
type: SIMPLE_ASSIGN
extCon.JOutUns.$pDERFMIDERINIT.dummyVarFMIDERINIT = (1.0 - extCon.shaRad.u) * extCon.radOut.JOut.$pDERFMIDERINIT.dummyVarFMIDERINIT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_671(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,671};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[4] /* extCon.JOutUns.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[31] /* extCon.shaRad.u variable */)) * (jacobian->tmpVars[12] /* extCon.radOut.JOut.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */);
#line 2936 OMC_FILE
  TRACE_POP
}

/*
equation index: 672
type: SIMPLE_ASSIGN
extCon.conCoeFra.GCon.$pDERFMIDERINIT.dummyVarFMIDERINIT = 0.8 * smooth(0, if noEvent(2.0 * vWin > 0.1) then vWin.SeedFMIDERINIT else if noEvent(2.0 * vWin < -0.1) then -vWin.SeedFMIDERINIT else 0.5 * ((-20.0) * vWin * (400.0 * vWin ^ 2.0 - 3.0) * vWin.SeedFMIDERINIT + ((-20.0) * vWin * 400.0 * 2.0 * vWin * vWin.SeedFMIDERINIT + (-20.0) * vWin.SeedFMIDERINIT * (400.0 * vWin ^ 2.0 - 3.0)) * vWin))
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_672(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,672};
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_real tmp9;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp2 = Greater((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */)),0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp8 = (modelica_boolean)tmp2;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  if(tmp8)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp9 = jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp3 = Less((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */)),-0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp6 = (modelica_boolean)tmp3;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    if(tmp6)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp7 = (-jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp4 = (data->localData[0]->realVars[67] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp5 = (data->localData[0]->realVars[67] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp7 = (0.5) * ((((-20.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * ((400.0) * ((tmp4 * tmp4)) - 3.0)) * (jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */) + (((-20.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * ((400.0) * (((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * (jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */))) + ((-20.0) * (jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */)) * ((400.0) * ((tmp5 * tmp5)) - 3.0)) * ((data->localData[0]->realVars[67] /* vWin variable */)));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp9 = tmp7;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  jacobian->tmpVars[5] /* extCon.conCoeFra.GCon.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = (0.8) * (tmp9);
#line 3005 OMC_FILE
  TRACE_POP
}

/*
equation index: 673
type: SIMPLE_ASSIGN
extCon.conCoeGla.GCon.$pDERFMIDERINIT.dummyVarFMIDERINIT = 3.2 * smooth(0, if noEvent(2.0 * vWin > 0.1) then vWin.SeedFMIDERINIT else if noEvent(2.0 * vWin < -0.1) then -vWin.SeedFMIDERINIT else 0.5 * ((-20.0) * vWin * (400.0 * vWin ^ 2.0 - 3.0) * vWin.SeedFMIDERINIT + ((-20.0) * vWin * 400.0 * 2.0 * vWin * vWin.SeedFMIDERINIT + (-20.0) * vWin.SeedFMIDERINIT * (400.0 * vWin ^ 2.0 - 3.0)) * vWin))
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_673(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,673};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_real tmp17;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp10 = Greater((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */)),0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp16 = (modelica_boolean)tmp10;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  if(tmp16)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp17 = jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp11 = Less((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */)),-0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp14 = (modelica_boolean)tmp11;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    if(tmp14)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp15 = (-jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp12 = (data->localData[0]->realVars[67] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp13 = (data->localData[0]->realVars[67] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp15 = (0.5) * ((((-20.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * ((400.0) * ((tmp12 * tmp12)) - 3.0)) * (jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */) + (((-20.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * ((400.0) * (((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * (jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */))) + ((-20.0) * (jacobian->seedVars[18] /* vWin.SeedFMIDERINIT SEED_VAR */)) * ((400.0) * ((tmp13 * tmp13)) - 3.0)) * ((data->localData[0]->realVars[67] /* vWin variable */)));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp17 = tmp15;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  jacobian->tmpVars[6] /* extCon.conCoeGla.GCon.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = (3.2) * (tmp17);
#line 3074 OMC_FILE
  TRACE_POP
}

/*
equation index: 674
type: SIMPLE_ASSIGN
extCon.conWinUns.Gc.$pDERFMIDERINIT.dummyVarFMIDERINIT = extCon.shaSig.yCom * extCon.conCoeGla.GCon.$pDERFMIDERINIT.dummyVarFMIDERINIT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_674(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,674};
#line 976 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[8] /* extCon.conWinUns.Gc.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[32] /* extCon.shaSig.yCom variable */)) * (jacobian->tmpVars[6] /* extCon.conCoeGla.GCon.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */);
#line 3091 OMC_FILE
  TRACE_POP
}

/*
equation index: 675
type: SIMPLE_ASSIGN
extCon.shaCon.Gc.$pDERFMIDERINIT.dummyVarFMIDERINIT = extCon.conCoeGla.GCon.$pDERFMIDERINIT.dummyVarFMIDERINIT * extCon.shaRad.u
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_675(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,675};
#line 976 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[15] /* extCon.shaCon.Gc.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = (jacobian->tmpVars[6] /* extCon.conCoeGla.GCon.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[31] /* extCon.shaRad.u variable */));
#line 3108 OMC_FILE
  TRACE_POP
}

/*
equation index: 756
type: LINEAR

<var>intShaCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<var>window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<var>window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<var>intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<var>heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<var>intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<var>window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<var>indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<var>intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_756(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,756};
  /* Linear equation system */
  int retValue;
  double aux_x[9] = { jacobian->tmpVars[36] /* intShaCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */,jacobian->tmpVars[74] /* window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */,jacobian->tmpVars[75] /* window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */,jacobian->tmpVars[35] /* intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */,jacobian->tmpVars[26] /* heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */,jacobian->tmpVars[32] /* intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */,jacobian->tmpVars[68] /* window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */,jacobian->tmpVars[28] /* indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */,jacobian->tmpVars[45] /* intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 756 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[2].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 2, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,756};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 756 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[36] /* intShaCon.conFra.dT.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[0];
  jacobian->tmpVars[74] /* window.glaUns_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[1];
  jacobian->tmpVars[75] /* window.glaUns_b.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[2];
  jacobian->tmpVars[35] /* intShaCon.conFra.Q_flow.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[3];
  jacobian->tmpVars[26] /* heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[4];
  jacobian->tmpVars[32] /* intShaCon.TSha.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[5];
  jacobian->tmpVars[68] /* window.glaSha_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[6];
  jacobian->tmpVars[28] /* indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[7];
  jacobian->tmpVars[45] /* intShaCon.glaSha.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */ = aux_x[8];

  TRACE_POP
}

/*
equation index: 757
type: SIMPLE_ASSIGN
TRad.$pDERFMIDERINIT.dummyVarFMIDERINIT = 0.3150148894478964 * indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_757(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,757};
  jacobian->resultVars[2] /* TRad.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_VAR */ = (0.3150148894478964) * (jacobian->tmpVars[28] /* indRad.JIn.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */);
  TRACE_POP
}

/*
equation index: 758
type: SIMPLE_ASSIGN
TCon.$pDERFMIDERINIT.dummyVarFMIDERINIT = 1.8 * heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_758(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,758};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Fahrenheit/TemperatureSensor.mo"
  jacobian->resultVars[1] /* TCon.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_VAR */ = (1.8) * (jacobian->tmpVars[26] /* heatFlowSensor1.port_a.T.$pDERFMIDERINIT.dummyVarFMIDERINIT JACOBIAN_DIFF_VAR */);
#line 3197 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacFMIDERINIT_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_FMIDERINIT;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacFMIDERINIT_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_FMIDERINIT;
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_667(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_668(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_669(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_670(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_671(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_672(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_673(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_674(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_675(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_756(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_757(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_758(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 576
type: SIMPLE_ASSIGN
extCon.radOut.TRad4.$pDERFMIDER.dummyVarFMIDER = 2.0 * (TBlaSky ^ 3.0 * TBlaSky.SeedFMIDER + TOut ^ 3.0 * TOut.SeedFMIDER)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_576(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,576};
  modelica_real tmp18;
  modelica_real tmp19;
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  tmp18 = (data->localData[0]->realVars[5] /* TBlaSky variable */);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  tmp19 = (data->localData[0]->realVars[7] /* TOut variable */);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  jacobian->tmpVars[14] /* extCon.radOut.TRad4.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (2.0) * (((tmp18 * tmp18 * tmp18)) * (jacobian->seedVars[4] /* TBlaSky.SeedFMIDER SEED_VAR */) + ((tmp19 * tmp19 * tmp19)) * (jacobian->seedVars[5] /* TOut.SeedFMIDER SEED_VAR */));
#line 3255 OMC_FILE
  TRACE_POP
}

/*
equation index: 577
type: SIMPLE_ASSIGN
extCon.radOut.TRad.$pDERFMIDER.dummyVarFMIDER = 9.923624282153128e-09 * extCon.radOut.TRad4.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_577(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,577};
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  jacobian->tmpVars[13] /* extCon.radOut.TRad.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (9.923624282153128e-09) * (jacobian->tmpVars[14] /* extCon.radOut.TRad4.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 3272 OMC_FILE
  TRACE_POP
}

/*
equation index: 578
type: SIMPLE_ASSIGN
extCon.radOut.JOut.$pDERFMIDER.dummyVarFMIDER = 4.571212498951346 * extCon.radOut.TRad.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_578(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,578};
  jacobian->tmpVars[12] /* extCon.radOut.JOut.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (4.571212498951346) * (jacobian->tmpVars[13] /* extCon.radOut.TRad.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
  TRACE_POP
}

/*
equation index: 579
type: SIMPLE_ASSIGN
extCon.conCoeFra.GCon.$pDERFMIDER.dummyVarFMIDER = 0.8 * smooth(0, if noEvent(2.0 * vWin > 0.1) then vWin.SeedFMIDER else if noEvent(2.0 * vWin < -0.1) then -vWin.SeedFMIDER else 0.5 * ((-20.0) * vWin * (400.0 * vWin ^ 2.0 - 3.0) * vWin.SeedFMIDER + ((-20.0) * vWin * 400.0 * 2.0 * vWin * vWin.SeedFMIDER + (-20.0) * vWin.SeedFMIDER * (400.0 * vWin ^ 2.0 - 3.0)) * vWin))
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_579(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,579};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  modelica_boolean tmp26;
  modelica_real tmp27;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp20 = Greater((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */)),0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp26 = (modelica_boolean)tmp20;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  if(tmp26)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp27 = jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp21 = Less((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */)),-0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp24 = (modelica_boolean)tmp21;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    if(tmp24)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp25 = (-jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp22 = (data->localData[0]->realVars[67] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp23 = (data->localData[0]->realVars[67] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp25 = (0.5) * ((((-20.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * ((400.0) * ((tmp22 * tmp22)) - 3.0)) * (jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */) + (((-20.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * ((400.0) * (((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * (jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */))) + ((-20.0) * (jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */)) * ((400.0) * ((tmp23 * tmp23)) - 3.0)) * ((data->localData[0]->realVars[67] /* vWin variable */)));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp27 = tmp25;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  jacobian->tmpVars[5] /* extCon.conCoeFra.GCon.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (0.8) * (tmp27);
#line 3356 OMC_FILE
  TRACE_POP
}

/*
equation index: 580
type: SIMPLE_ASSIGN
extCon.conCoeGla.GCon.$pDERFMIDER.dummyVarFMIDER = 3.2 * smooth(0, if noEvent(2.0 * vWin > 0.1) then vWin.SeedFMIDER else if noEvent(2.0 * vWin < -0.1) then -vWin.SeedFMIDER else 0.5 * ((-20.0) * vWin * (400.0 * vWin ^ 2.0 - 3.0) * vWin.SeedFMIDER + ((-20.0) * vWin * 400.0 * 2.0 * vWin * vWin.SeedFMIDER + (-20.0) * vWin.SeedFMIDER * (400.0 * vWin ^ 2.0 - 3.0)) * vWin))
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_580(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,580};
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_boolean tmp32;
  modelica_real tmp33;
  modelica_boolean tmp34;
  modelica_real tmp35;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp28 = Greater((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */)),0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp34 = (modelica_boolean)tmp28;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  if(tmp34)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp35 = jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp29 = Less((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */)),-0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp32 = (modelica_boolean)tmp29;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    if(tmp32)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp33 = (-jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp30 = (data->localData[0]->realVars[67] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp31 = (data->localData[0]->realVars[67] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp33 = (0.5) * ((((-20.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * ((400.0) * ((tmp30 * tmp30)) - 3.0)) * (jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */) + (((-20.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * ((400.0) * (((2.0) * ((data->localData[0]->realVars[67] /* vWin variable */))) * (jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */))) + ((-20.0) * (jacobian->seedVars[6] /* vWin.SeedFMIDER SEED_VAR */)) * ((400.0) * ((tmp31 * tmp31)) - 3.0)) * ((data->localData[0]->realVars[67] /* vWin variable */)));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp35 = tmp33;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  jacobian->tmpVars[6] /* extCon.conCoeGla.GCon.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (3.2) * (tmp35);
#line 3425 OMC_FILE
  TRACE_POP
}

/*
equation index: 581
type: SIMPLE_ASSIGN
extCon.JOutSha.$pDERFMIDER.dummyVarFMIDER = extCon.shaRad.u * extCon.radOut.JOut.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_581(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,581};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[3] /* extCon.JOutSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[31] /* extCon.shaRad.u variable */)) * (jacobian->tmpVars[12] /* extCon.radOut.JOut.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 3442 OMC_FILE
  TRACE_POP
}

/*
equation index: 582
type: SIMPLE_ASSIGN
extCon.JOutUns.$pDERFMIDER.dummyVarFMIDER = (1.0 - extCon.shaRad.u) * extCon.radOut.JOut.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_582(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,582};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  jacobian->tmpVars[4] /* extCon.JOutUns.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (1.0 - (data->localData[0]->realVars[31] /* extCon.shaRad.u variable */)) * (jacobian->tmpVars[12] /* extCon.radOut.JOut.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 3459 OMC_FILE
  TRACE_POP
}

/*
equation index: 583
type: SIMPLE_ASSIGN
extCon.conWinUns.Gc.$pDERFMIDER.dummyVarFMIDER = extCon.shaSig.yCom * extCon.conCoeGla.GCon.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_583(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,583};
#line 976 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[8] /* extCon.conWinUns.Gc.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[32] /* extCon.shaSig.yCom variable */)) * (jacobian->tmpVars[6] /* extCon.conCoeGla.GCon.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 3476 OMC_FILE
  TRACE_POP
}

/*
equation index: 584
type: SIMPLE_ASSIGN
extCon.shaCon.Gc.$pDERFMIDER.dummyVarFMIDER = extCon.conCoeGla.GCon.$pDERFMIDER.dummyVarFMIDER * extCon.shaRad.u
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_584(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,584};
#line 976 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  jacobian->tmpVars[15] /* extCon.shaCon.Gc.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = (jacobian->tmpVars[6] /* extCon.conCoeGla.GCon.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[31] /* extCon.shaRad.u variable */));
#line 3493 OMC_FILE
  TRACE_POP
}

/*
equation index: 664
type: LINEAR

<var>extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER</var>
<var>heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER</var>
<var>window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER</var>
<var>intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER</var>
<var>intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER</var>
<var>window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER</var>
<var>window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER</var>
<var>window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER</var>
<var>indRad.JIn.$pDERFMIDER.dummyVarFMIDER</var>
<var>intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_664(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,664};
  /* Linear equation system */
  int retValue;
  double aux_x[10] = { jacobian->tmpVars[7] /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[20] /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[63] /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[24] /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[39] /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[47] /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[62] /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[56] /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[21] /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */,jacobian->tmpVars[35] /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 664 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[2].parDynamicData[omc_get_thread_num()].parentJacobian = jacobian;
  
  retValue = solve_linear_system(data, threadData, 2, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,664};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 664 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  jacobian->tmpVars[7] /* extCon.conFra.dT.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[0];
  jacobian->tmpVars[20] /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[1];
  jacobian->tmpVars[63] /* window.glaUns_b.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[2];
  jacobian->tmpVars[24] /* intShaCon.TSha.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[3];
  jacobian->tmpVars[39] /* intShaRad.JIn_glass.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[4];
  jacobian->tmpVars[47] /* window.JOutUns_b.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[5];
  jacobian->tmpVars[62] /* window.glaUns_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[6];
  jacobian->tmpVars[56] /* window.glaSha_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[7];
  jacobian->tmpVars[21] /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[8];
  jacobian->tmpVars[35] /* intShaCon.glaSha.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */ = aux_x[9];

  TRACE_POP
}

/*
equation index: 665
type: SIMPLE_ASSIGN
TRad.$pDERFMIDER.dummyVarFMIDER = 0.3150148894478964 * indRad.JIn.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_665(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,665};
  jacobian->resultVars[2] /* TRad.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */ = (0.3150148894478964) * (jacobian->tmpVars[21] /* indRad.JIn.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
  TRACE_POP
}

/*
equation index: 666
type: SIMPLE_ASSIGN
TCon.$pDERFMIDER.dummyVarFMIDER = 1.8 * heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_666(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,666};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Fahrenheit/TemperatureSensor.mo"
  jacobian->resultVars[1] /* TCon.$pDERFMIDER.dummyVarFMIDER JACOBIAN_VAR */ = (1.8) * (jacobian->tmpVars[20] /* heatFlowSensor1.port_a.T.$pDERFMIDER.dummyVarFMIDER JACOBIAN_DIFF_VAR */);
#line 3584 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacFMIDER_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_FMIDER;
  
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacFMIDER_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = Buildings_HeatTransfer_Windows_Examples_WindowCustom_INDEX_JAC_FMIDER;
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_576(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_577(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_578(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_579(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_580(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_581(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_582(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_583(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_584(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_664(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_665(data, threadData, jacobian, parentJacobian);
  Buildings_HeatTransfer_Windows_Examples_WindowCustom_eqFunction_666(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianLSJac0(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+10] = {0,2,4,3,3,5,8,4,5,8,6};
  const int rowIndex[48] = {1,2,2,3,6,7,7,8,9,3,5,6,1,2,3,4,6,1,2,3,4,5,6,7,9,1,2,7,8,0,1,2,3,6,1,2,3,4,5,6,7,9,0,1,2,3,4,6};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 10, 10, 41, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(10, 48, 8);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (10+1)*sizeof(unsigned int));
  
  for(i=2;i<10+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 48*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {9};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {8};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {7};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 1 columns */
  const int indices_4[1] = {6};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_4[i]] = 4;
  
  /* color 5 with 1 columns */
  const int indices_5[1] = {5};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_5[i]] = 5;
  
  /* color 6 with 1 columns */
  const int indices_6[1] = {4};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_6[i]] = 6;
  
  /* color 7 with 1 columns */
  const int indices_7[1] = {1};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_7[i]] = 7;
  
  /* color 8 with 3 columns */
  const int indices_8[3] = {0, 2, 3};
  for(i=0; i<3; i++)
    jacobian->sparsePattern->colorCols[indices_8[i]] = 8;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianLSJac1(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+8] = {0,2,3,5,6,4,6,3,5};
  const int rowIndex[34] = {0,1,5,6,7,0,1,2,3,6,0,1,2,3,6,7,0,1,5,6,0,1,2,3,6,7,2,3,4,0,1,2,3,4};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 8, 8, 41, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(8, 34, 6);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (8+1)*sizeof(unsigned int));
  
  for(i=2;i<8+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 34*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {7};
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
  
  /* color 4 with 1 columns */
  const int indices_4[1] = {3};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_4[i]] = 4;
  
  /* color 5 with 1 columns */
  const int indices_5[1] = {2};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_5[i]] = 5;
  
  /* color 6 with 3 columns */
  const int indices_6[3] = {0, 1, 6};
  for(i=0; i<3; i++)
    jacobian->sparsePattern->colorCols[indices_6[i]] = 6;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianLSJac2(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+10] = {0,2,4,3,3,5,8,4,5,8,6};
  const int rowIndex[48] = {2,6,2,5,7,8,3,4,5,0,7,8,2,6,7,8,9,0,2,4,5,6,7,8,9,2,3,5,6,1,2,6,7,8,0,2,4,5,6,7,8,9,1,2,6,7,8,9};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 10, 10, 41, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(10, 48, 8);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (10+1)*sizeof(unsigned int));
  
  for(i=2;i<10+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 48*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {9};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {8};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {7};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 1 columns */
  const int indices_4[1] = {6};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_4[i]] = 4;
  
  /* color 5 with 1 columns */
  const int indices_5[1] = {5};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_5[i]] = 5;
  
  /* color 6 with 1 columns */
  const int indices_6[1] = {4};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_6[i]] = 6;
  
  /* color 7 with 1 columns */
  const int indices_7[1] = {1};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_7[i]] = 7;
  
  /* color 8 with 3 columns */
  const int indices_8[3] = {0, 2, 3};
  for(i=0; i<3; i++)
    jacobian->sparsePattern->colorCols[indices_8[i]] = 8;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianLSJac3(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+9] = {0,2,2,4,4,5,5,3,4,5};
  const int rowIndex[34] = {6,7,0,3,0,2,3,8,2,3,6,7,2,3,4,5,6,2,3,4,5,8,1,4,5,3,4,5,8,1,2,3,4,5};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 9, 9, 41, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(9, 34, 7);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (9+1)*sizeof(unsigned int));
  
  for(i=2;i<9+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 34*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {8};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {7};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {5};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 1 columns */
  const int indices_4[1] = {4};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_4[i]] = 4;
  
  /* color 5 with 1 columns */
  const int indices_5[1] = {3};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_5[i]] = 5;
  
  /* color 6 with 1 columns */
  const int indices_6[1] = {2};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_6[i]] = 6;
  
  /* color 7 with 3 columns */
  const int indices_7[3] = {0, 1, 6};
  for(i=0; i<3; i++)
    jacobian->sparsePattern->colorCols[indices_7[i]] = 7;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianFMIDERINIT(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+66] = {0,2,2,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  const int rowIndex[12] = {1,2,1,2,1,2,1,2,1,2,1,2};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 66, 158, 79, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(66, 12, 6);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (66+1)*sizeof(unsigned int));
  
  for(i=2;i<66+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 12*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {4};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {18};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {3};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 1 columns */
  const int indices_4[1] = {1};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_4[i]] = 4;
  
  /* color 5 with 1 columns */
  const int indices_5[1] = {0};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_5[i]] = 5;
  
  /* color 6 with 61 columns */
  const int indices_6[61] = {5, 2, 53, 57, 54, 55, 56, 51, 52, 50, 45, 48, 46, 49, 44, 47, 42, 43, 64, 65, 60, 61, 58, 59, 62, 63, 40, 41, 35, 30, 34, 31, 32, 33, 28, 29, 27, 22, 25, 23, 26, 21, 24, 19, 20, 38, 39, 36, 37, 8, 9, 6, 7, 10, 15, 16, 17, 12, 14, 11, 13};
  for(i=0; i<61; i++)
    jacobian->sparsePattern->colorCols[indices_6[i]] = 6;
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianFMIDER(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  const int colPtrIndex[1+7] = {0,2,2,0,2,2,2,2};
  const int rowIndex[12] = {1,2,1,2,1,2,1,2,1,2,1,2};
  int i = 0;
  
  initAnalyticJacobian(jacobian, 7, 3, 67, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(7, 12, 6);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (7+1)*sizeof(unsigned int));
  
  for(i=2;i<7+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 12*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {5};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {0};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_2[i]] = 2;
  
  /* color 3 with 1 columns */
  const int indices_3[1] = {1};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_3[i]] = 3;
  
  /* color 4 with 1 columns */
  const int indices_4[1] = {3};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_4[i]] = 4;
  
  /* color 5 with 1 columns */
  const int indices_5[1] = {6};
  for(i=0; i<1; i++)
    jacobian->sparsePattern->colorCols[indices_5[i]] = 5;
  
  /* color 6 with 2 columns */
  const int indices_6[2] = {2, 4};
  for(i=0; i<2; i++)
    jacobian->sparsePattern->colorCols[indices_6[i]] = 6;
  TRACE_POP
  return 0;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int Buildings_HeatTransfer_Windows_Examples_WindowCustom_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}



