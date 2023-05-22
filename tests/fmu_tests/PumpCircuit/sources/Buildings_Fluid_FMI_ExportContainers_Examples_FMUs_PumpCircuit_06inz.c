#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit.fmutmp/sources/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_06inz.c"
#endif
/* Initialization */
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_model.h"
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_11mix.h"
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
fan.vol.steBal.mWat_flow_internal = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
#line 105 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  (data->localData[0]->realVars[61] /* fan.vol.steBal.mWat_flow_internal variable */) = 0.0;
#line 27 OMC_FILE
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
fan.vol.steBal.port_a.h_outflow = 83680.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  (data->localData[0]->realVars[63] /* fan.vol.steBal.port_a.h_outflow variable */) = 83680.0;
#line 42 OMC_FILE
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
fan.vol.U = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
#line 42 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  (data->localData[0]->realVars[57] /* fan.vol.U variable */) = 0.0;
#line 57 OMC_FILE
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
fan.vol.m = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  (data->localData[0]->realVars[58] /* fan.vol.m variable */) = 0.0;
#line 72 OMC_FILE
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
fan.preSou.dp_internal = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
#line 36 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/IdealSource.mo"
  (data->localData[0]->realVars[49] /* fan.preSou.dp_internal variable */) = 0.0;
#line 87 OMC_FILE
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
fan.preSou.port_a.h_outflow = 83680.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  (data->localData[0]->realVars[50] /* fan.preSou.port_a.h_outflow variable */) = 83680.0;
#line 102 OMC_FILE
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
fan.senRelPre.port_b.h_outflow = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  (data->localData[0]->realVars[55] /* fan.senRelPre.port_b.h_outflow variable */) = 0.0;
#line 117 OMC_FILE
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
fan.eff.r_N = 1.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
#line 123 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[35] /* fan.eff.r_N variable */) = 1.0;
#line 132 OMC_FILE
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
hea.outCon.X_wSet_internal = 0.01
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
#line 129 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[71] /* hea.outCon.X_wSet_internal variable */) = 0.01;
#line 147 OMC_FILE
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
hea.outCon.Xi_outflow = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
#line 112 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[72] /* hea.outCon.Xi_outflow variable */) = 0.0;
#line 162 OMC_FILE
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
hea.outCon.mWat_flow = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
#line 63 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[79] /* hea.outCon.mWat_flow variable */) = 0.0;
#line 177 OMC_FILE
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
hea.outCon.dXiAct = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
#line 118 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[73] /* hea.outCon.dXiAct variable */) = 0.0;
#line 192 OMC_FILE
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
hvacAda.con[1].X_wZon_internal2 = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Conversion/AirToOutlet.mo"
  (data->localData[0]->realVars[86] /* hvacAda.con[1].X_wZon_internal2 variable */) = 0.0;
#line 207 OMC_FILE
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
hvacAda.con[2].X_wZon_internal2 = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
#line 32 "/home/marius/modelica-buildings/Buildings/Fluid/FMI/Conversion/AirToOutlet.mo"
  (data->localData[0]->realVars[87] /* hvacAda.con[2].X_wZon_internal2 variable */) = 0.0;
#line 222 OMC_FILE
  TRACE_POP
}

/*
equation index: 15
type: SIMPLE_ASSIGN
fan.vol.steBal.dp = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
#line 23 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortInterface.mo"
  (data->localData[0]->realVars[60] /* fan.vol.steBal.dp variable */) = 0.0;
#line 237 OMC_FILE
  TRACE_POP
}

/*
equation index: 16
type: SIMPLE_ASSIGN
fan.eta = 0.4899999999999999
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
#line 100 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  (data->localData[0]->realVars[38] /* fan.eta variable */) = 0.4899999999999999;
#line 252 OMC_FILE
  TRACE_POP
}

/*
equation index: 17
type: SIMPLE_ASSIGN
fan.heatPort.Q_flow = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[43] /* fan.heatPort.Q_flow variable */) = 0.0;
#line 267 OMC_FILE
  TRACE_POP
}

/*
equation index: 18
type: SIMPLE_ASSIGN
hvacAda.bou.m_flow_in_internal = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/MassFlowSource_T.mo"
  (data->localData[0]->realVars[85] /* hvacAda.bou.m_flow_in_internal variable */) = 0.0;
#line 282 OMC_FILE
  TRACE_POP
}

/*
equation index: 19
type: SIMPLE_ASSIGN
fan.senRelPre.port_a.m_flow = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
#line 13 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  (data->localData[0]->realVars[54] /* fan.senRelPre.port_a.m_flow variable */) = 0.0;
#line 297 OMC_FILE
  TRACE_POP
}

/*
equation index: 20
type: SIMPLE_ASSIGN
fan.senRelPre.port_b.m_flow = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
#line 13 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  (data->localData[0]->realVars[56] /* fan.senRelPre.port_b.m_flow variable */) = 0.0;
#line 312 OMC_FILE
  TRACE_POP
}

/*
equation index: 21
type: SIMPLE_ASSIGN
fan.senRelPre.port_a.h_outflow = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  (data->localData[0]->realVars[53] /* fan.senRelPre.port_a.h_outflow variable */) = 0.0;
#line 327 OMC_FILE
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
hea.outCon.dp = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
#line 23 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortInterface.mo"
  (data->localData[0]->realVars[75] /* hea.outCon.dp variable */) = 0.0;
#line 342 OMC_FILE
  TRACE_POP
}

/*
equation index: 23
type: SIMPLE_ASSIGN
fan.eff.eta_internal = 0.7
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
#line 301 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[34] /* fan.eff.eta_internal variable */) = 0.7;
#line 357 OMC_FILE
  TRACE_POP
}

/*
equation index: 24
type: SIMPLE_ASSIGN
fan.eff.etaMot = 0.7
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
#line 116 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[33] /* fan.eff.etaMot variable */) = 0.7;
#line 372 OMC_FILE
  TRACE_POP
}

/*
equation index: 25
type: ALGORITHM

  fan.eff.powEu_internal := Buildings.Fluid.Movers.BaseClasses.Euler.power(Buildings.Fluid.Movers.BaseClasses.Euler.peak(0.0, 0.0, 0.7), Buildings.Fluid.Movers.BaseClasses.Characteristics.flowParametersInternal(2, {0.0, 0.0009999551372974348}, {20000.0, fan.eff.pCur1.dp[2]}));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  Buildings_Fluid_Movers_BaseClasses_Euler_peak tmp0;
  Buildings_Fluid_Movers_BaseClasses_Characteristics_flowParametersInternal tmp1;
  real_array tmp2;
  real_array tmp3;
  Buildings_Fluid_Movers_BaseClasses_Euler_powerWithDerivative tmp4;
  real_array tmp5;
  real_array tmp6;
  real_array tmp7;
  real_array tmp8;
  real_array tmp9;
  real_array tmp10;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp0._V_flow = 0.0;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp0._dp = 0.0;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp0._eta = 0.7;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  array_alloc_scalar_real_array(&tmp2, 2, (modelica_real)0.0, (modelica_real)0.0009999551372974348);
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  array_alloc_scalar_real_array(&tmp3, 2, (modelica_real)20000.0, (modelica_real)(data->simulationInfo->realParameter[54] /* fan.eff.pCur1.dp[2] PARAM */));
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp1._n = ((modelica_integer) 2);
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp1._V_flow = tmp2;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp1._dp = tmp3;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp4 = omc_Buildings_Fluid_Movers_BaseClasses_Euler_power(threadData, tmp0, tmp1);
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  array_alloc_scalar_real_array(&tmp5, 11, (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 3)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 4)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 5)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 6)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 7)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 8)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 9)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 10)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 11)));
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  real_array_create(&tmp6, ((modelica_real*)&((&(data->simulationInfo->realParameter[160] /* fan.eff.powEu_internal.V_flow[1] PARAM */))[((modelica_integer) 1) - 1])), 1, (_index_t)11);
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  real_array_copy_data(tmp5, tmp6);
#line 421 OMC_FILE
  array_alloc_scalar_real_array(&tmp7, 11, (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 3)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 4)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 5)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 6)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 7)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 8)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 9)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 10)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 11)));
  real_array_create(&tmp8, ((modelica_real*)&((&(data->simulationInfo->realParameter[149] /* fan.eff.powEu_internal.P[1] PARAM */))[((modelica_integer) 1) - 1])), 1, (_index_t)11);
  real_array_copy_data(tmp7, tmp8);
  array_alloc_scalar_real_array(&tmp9, 11, (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 3)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 4)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 5)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 6)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 7)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 8)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 9)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 10)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 11)));
  real_array_create(&tmp10, ((modelica_real*)&((&(data->simulationInfo->realParameter[171] /* fan.eff.powEu_internal.d[1] PARAM */))[((modelica_integer) 1) - 1])), 1, (_index_t)11);
  real_array_copy_data(tmp9, tmp10);
  ;
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
fan.eff.powEu.P[7] = fan.eff.powEu_internal.P[7]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[122] /* fan.eff.powEu.P[7] PARAM */) = (data->simulationInfo->realParameter[155] /* fan.eff.powEu_internal.P[7] PARAM */);
#line 443 OMC_FILE
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
fan.eff.powEuDer[3] = fan.eff.powEu_internal.d[3]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[140] /* fan.eff.powEuDer[3] PARAM */) = (data->simulationInfo->realParameter[173] /* fan.eff.powEu_internal.d[3] PARAM */);
#line 458 OMC_FILE
  TRACE_POP
}

/*
equation index: 28
type: SIMPLE_ASSIGN
fan.eff.powEu.P[3] = fan.eff.powEu_internal.P[3]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[118] /* fan.eff.powEu.P[3] PARAM */) = (data->simulationInfo->realParameter[151] /* fan.eff.powEu_internal.P[3] PARAM */);
#line 473 OMC_FILE
  TRACE_POP
}

/*
equation index: 29
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[4] = fan.eff.powEu_internal.V_flow[4]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[130] /* fan.eff.powEu.V_flow[4] PARAM */) = (data->simulationInfo->realParameter[163] /* fan.eff.powEu_internal.V_flow[4] PARAM */);
#line 488 OMC_FILE
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[2] = fan.eff.powEu_internal.V_flow[2]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[128] /* fan.eff.powEu.V_flow[2] PARAM */) = (data->simulationInfo->realParameter[161] /* fan.eff.powEu_internal.V_flow[2] PARAM */);
#line 503 OMC_FILE
  TRACE_POP
}

/*
equation index: 31
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[3] = fan.eff.powEu_internal.V_flow[3]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[129] /* fan.eff.powEu.V_flow[3] PARAM */) = (data->simulationInfo->realParameter[162] /* fan.eff.powEu_internal.V_flow[3] PARAM */);
#line 518 OMC_FILE
  TRACE_POP
}

/*
equation index: 32
type: SIMPLE_ASSIGN
fan.eff.powEuDer[5] = fan.eff.powEu_internal.d[5]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[142] /* fan.eff.powEuDer[5] PARAM */) = (data->simulationInfo->realParameter[175] /* fan.eff.powEu_internal.d[5] PARAM */);
#line 533 OMC_FILE
  TRACE_POP
}

/*
equation index: 33
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[7] = fan.eff.powEu_internal.V_flow[7]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[133] /* fan.eff.powEu.V_flow[7] PARAM */) = (data->simulationInfo->realParameter[166] /* fan.eff.powEu_internal.V_flow[7] PARAM */);
#line 548 OMC_FILE
  TRACE_POP
}

/*
equation index: 34
type: SIMPLE_ASSIGN
fan.eff.powEuDer[9] = fan.eff.powEu_internal.d[9]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[146] /* fan.eff.powEuDer[9] PARAM */) = (data->simulationInfo->realParameter[179] /* fan.eff.powEu_internal.d[9] PARAM */);
#line 563 OMC_FILE
  TRACE_POP
}

/*
equation index: 35
type: SIMPLE_ASSIGN
fan.eff.powEuDer[2] = fan.eff.powEu_internal.d[2]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[139] /* fan.eff.powEuDer[2] PARAM */) = (data->simulationInfo->realParameter[172] /* fan.eff.powEu_internal.d[2] PARAM */);
#line 578 OMC_FILE
  TRACE_POP
}

/*
equation index: 36
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[10] = fan.eff.powEu_internal.V_flow[10]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[136] /* fan.eff.powEu.V_flow[10] PARAM */) = (data->simulationInfo->realParameter[169] /* fan.eff.powEu_internal.V_flow[10] PARAM */);
#line 593 OMC_FILE
  TRACE_POP
}

/*
equation index: 37
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[8] = fan.eff.powEu_internal.V_flow[8]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[134] /* fan.eff.powEu.V_flow[8] PARAM */) = (data->simulationInfo->realParameter[167] /* fan.eff.powEu_internal.V_flow[8] PARAM */);
#line 608 OMC_FILE
  TRACE_POP
}

/*
equation index: 38
type: SIMPLE_ASSIGN
fan.eff.powEuDer[11] = fan.eff.powEu_internal.d[11]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[148] /* fan.eff.powEuDer[11] PARAM */) = (data->simulationInfo->realParameter[181] /* fan.eff.powEu_internal.d[11] PARAM */);
#line 623 OMC_FILE
  TRACE_POP
}

/*
equation index: 39
type: SIMPLE_ASSIGN
fan.eff.powEu.P[6] = fan.eff.powEu_internal.P[6]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[121] /* fan.eff.powEu.P[6] PARAM */) = (data->simulationInfo->realParameter[154] /* fan.eff.powEu_internal.P[6] PARAM */);
#line 638 OMC_FILE
  TRACE_POP
}

/*
equation index: 40
type: SIMPLE_ASSIGN
fan.eff.powEuDer[7] = fan.eff.powEu_internal.d[7]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[144] /* fan.eff.powEuDer[7] PARAM */) = (data->simulationInfo->realParameter[177] /* fan.eff.powEu_internal.d[7] PARAM */);
#line 653 OMC_FILE
  TRACE_POP
}

/*
equation index: 41
type: SIMPLE_ASSIGN
fan.eff.powEu.P[2] = fan.eff.powEu_internal.P[2]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[117] /* fan.eff.powEu.P[2] PARAM */) = (data->simulationInfo->realParameter[150] /* fan.eff.powEu_internal.P[2] PARAM */);
#line 668 OMC_FILE
  TRACE_POP
}

/*
equation index: 42
type: SIMPLE_ASSIGN
fan.eff.powEuDer[1] = fan.eff.powEu_internal.d[1]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[138] /* fan.eff.powEuDer[1] PARAM */) = (data->simulationInfo->realParameter[171] /* fan.eff.powEu_internal.d[1] PARAM */);
#line 683 OMC_FILE
  TRACE_POP
}

/*
equation index: 43
type: SIMPLE_ASSIGN
fan.eff.powEuDer[8] = fan.eff.powEu_internal.d[8]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[145] /* fan.eff.powEuDer[8] PARAM */) = (data->simulationInfo->realParameter[178] /* fan.eff.powEu_internal.d[8] PARAM */);
#line 698 OMC_FILE
  TRACE_POP
}

/*
equation index: 44
type: SIMPLE_ASSIGN
fan.eff.powEu.P[1] = fan.eff.powEu_internal.P[1]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[116] /* fan.eff.powEu.P[1] PARAM */) = (data->simulationInfo->realParameter[149] /* fan.eff.powEu_internal.P[1] PARAM */);
#line 713 OMC_FILE
  TRACE_POP
}

/*
equation index: 45
type: SIMPLE_ASSIGN
fan.eff.powEu.P[9] = fan.eff.powEu_internal.P[9]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[124] /* fan.eff.powEu.P[9] PARAM */) = (data->simulationInfo->realParameter[157] /* fan.eff.powEu_internal.P[9] PARAM */);
#line 728 OMC_FILE
  TRACE_POP
}

/*
equation index: 46
type: SIMPLE_ASSIGN
fan.eff.powEuDer[4] = fan.eff.powEu_internal.d[4]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[141] /* fan.eff.powEuDer[4] PARAM */) = (data->simulationInfo->realParameter[174] /* fan.eff.powEu_internal.d[4] PARAM */);
#line 743 OMC_FILE
  TRACE_POP
}

/*
equation index: 47
type: SIMPLE_ASSIGN
fan.eff.powEu.P[11] = fan.eff.powEu_internal.P[11]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[126] /* fan.eff.powEu.P[11] PARAM */) = (data->simulationInfo->realParameter[159] /* fan.eff.powEu_internal.P[11] PARAM */);
#line 758 OMC_FILE
  TRACE_POP
}

/*
equation index: 48
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[6] = fan.eff.powEu_internal.V_flow[6]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[132] /* fan.eff.powEu.V_flow[6] PARAM */) = (data->simulationInfo->realParameter[165] /* fan.eff.powEu_internal.V_flow[6] PARAM */);
#line 773 OMC_FILE
  TRACE_POP
}

/*
equation index: 49
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[5] = fan.eff.powEu_internal.V_flow[5]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[131] /* fan.eff.powEu.V_flow[5] PARAM */) = (data->simulationInfo->realParameter[164] /* fan.eff.powEu_internal.V_flow[5] PARAM */);
#line 788 OMC_FILE
  TRACE_POP
}

/*
equation index: 50
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[11] = fan.eff.powEu_internal.V_flow[11]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[137] /* fan.eff.powEu.V_flow[11] PARAM */) = (data->simulationInfo->realParameter[170] /* fan.eff.powEu_internal.V_flow[11] PARAM */);
#line 803 OMC_FILE
  TRACE_POP
}

/*
equation index: 51
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[1] = fan.eff.powEu_internal.V_flow[1]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[127] /* fan.eff.powEu.V_flow[1] PARAM */) = (data->simulationInfo->realParameter[160] /* fan.eff.powEu_internal.V_flow[1] PARAM */);
#line 818 OMC_FILE
  TRACE_POP
}

/*
equation index: 52
type: SIMPLE_ASSIGN
fan.eff.powEu.V_flow[9] = fan.eff.powEu_internal.V_flow[9]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
#line 4 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[135] /* fan.eff.powEu.V_flow[9] PARAM */) = (data->simulationInfo->realParameter[168] /* fan.eff.powEu_internal.V_flow[9] PARAM */);
#line 833 OMC_FILE
  TRACE_POP
}

/*
equation index: 53
type: SIMPLE_ASSIGN
fan.eff.powEu.P[5] = fan.eff.powEu_internal.P[5]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[120] /* fan.eff.powEu.P[5] PARAM */) = (data->simulationInfo->realParameter[153] /* fan.eff.powEu_internal.P[5] PARAM */);
#line 848 OMC_FILE
  TRACE_POP
}

/*
equation index: 54
type: SIMPLE_ASSIGN
fan.eff.powEu.P[4] = fan.eff.powEu_internal.P[4]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[119] /* fan.eff.powEu.P[4] PARAM */) = (data->simulationInfo->realParameter[152] /* fan.eff.powEu_internal.P[4] PARAM */);
#line 863 OMC_FILE
  TRACE_POP
}

/*
equation index: 55
type: SIMPLE_ASSIGN
fan.eff.powEu.P[10] = fan.eff.powEu_internal.P[10]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[125] /* fan.eff.powEu.P[10] PARAM */) = (data->simulationInfo->realParameter[158] /* fan.eff.powEu_internal.P[10] PARAM */);
#line 878 OMC_FILE
  TRACE_POP
}

/*
equation index: 56
type: SIMPLE_ASSIGN
fan.eff.powEu.P[8] = fan.eff.powEu_internal.P[8]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
#line 6 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/Characteristics/powerParameters.mo"
  (data->simulationInfo->realParameter[123] /* fan.eff.powEu.P[8] PARAM */) = (data->simulationInfo->realParameter[156] /* fan.eff.powEu_internal.P[8] PARAM */);
#line 893 OMC_FILE
  TRACE_POP
}

/*
equation index: 57
type: SIMPLE_ASSIGN
fan.eff.powEuDer[10] = fan.eff.powEu_internal.d[10]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[147] /* fan.eff.powEuDer[10] PARAM */) = (data->simulationInfo->realParameter[180] /* fan.eff.powEu_internal.d[10] PARAM */);
#line 908 OMC_FILE
  TRACE_POP
}

/*
equation index: 58
type: SIMPLE_ASSIGN
fan.eff.powEuDer[6] = fan.eff.powEu_internal.d[6]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
#line 285 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[143] /* fan.eff.powEuDer[6] PARAM */) = (data->simulationInfo->realParameter[176] /* fan.eff.powEu_internal.d[6] PARAM */);
#line 923 OMC_FILE
  TRACE_POP
}

/*
equation index: 59
type: SIMPLE_ASSIGN
fan.rho_inlet.y = 995.586
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
#line 10 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[51] /* fan.rho_inlet.y variable */) = 995.586;
#line 938 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_305(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_306(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_307(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_251(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_252(DATA *data, threadData_t *threadData);


/*
equation index: 65
type: SIMPLE_ASSIGN
bou.ports[1].h_outflow = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.bou.Medium.specificEnthalpy(Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.bou.Medium.setState_pTX(bou.p_in_internal, bou.T, bou.X_in_internal))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  real_array tmp11;
#line 39 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
  real_array_create(&tmp11, ((modelica_real*)&((&data->localData[0]->realVars[23] /* bou.X_in_internal[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 39 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
  (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_bou_Medium_specificEnthalpy(threadData, omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_bou_Medium_setState__pTX(threadData, (data->localData[0]->realVars[24] /* bou.p_in_internal variable */), (data->simulationInfo->realParameter[13] /* bou.T PARAM */), tmp11));
#line 966 OMC_FILE
  TRACE_POP
}

/*
equation index: 66
type: SIMPLE_ASSIGN
$START.fan.vol.ports[2].h_outflow = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.vol.Medium.specificEnthalpy_pTX(fan.vol.p_start, fan.vol.T_start, fan.vol.X_start)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  real_array tmp12;
  real_array_create(&tmp12, ((modelica_real*)&((&data->simulationInfo->realParameter[271] /* fan.vol.X_start[1] PARAM */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
  (data->modelData->realVarsData[59] /* fan.vol.ports[2].h_outflow variable */).attribute .start = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_vol_Medium_specificEnthalpy__pTX(threadData, (data->simulationInfo->realParameter[275] /* fan.vol.p_start PARAM */), (data->simulationInfo->realParameter[268] /* fan.vol.T_start PARAM */), tmp12);
    (data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */) = (data->modelData->realVarsData[59] /* fan.vol.ports[2].h_outflow variable */).attribute .start;
    infoStreamPrint(LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[59].info /* fan.vol.ports[2].h_outflow */.name, (modelica_real) (data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */));
  TRACE_POP
}

/*
equation index: 67
type: SIMPLE_ASSIGN
$DER.fan.filter.s[1] = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[2] /* der(fan.filter.s[1]) STATE_DER */) = 0.0;
#line 998 OMC_FILE
  TRACE_POP
}

/*
equation index: 68
type: SIMPLE_ASSIGN
fan.filter.x[1] = ovePum - $DER.fan.filter.s[1] / fan.filter.w_u
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
#line 50 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[39] /* fan.filter.x[1] variable */) = (data->localData[0]->realVars[91] /* ovePum variable */) - (DIVISION_SIM((data->localData[0]->realVars[2] /* der(fan.filter.s[1]) STATE_DER */),(data->simulationInfo->realParameter[197] /* fan.filter.w_u PARAM */),"fan.filter.w_u",equationIndexes));
#line 1013 OMC_FILE
  TRACE_POP
}

/*
equation index: 69
type: SIMPLE_ASSIGN
fan.filter.s[1] = fan.filter.x[1] / fan.filter.u_nom
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[0] /* fan.filter.s[1] STATE(1) */) = DIVISION_SIM((data->localData[0]->realVars[39] /* fan.filter.x[1] variable */),(data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */),"fan.filter.u_nom",equationIndexes);
#line 1028 OMC_FILE
  TRACE_POP
}

/*
equation index: 70
type: SIMPLE_ASSIGN
fan.filter.y = fan.filter.y_start
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
#line 45 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[40] /* fan.filter.y variable */) = (data->simulationInfo->realParameter[200] /* fan.filter.y_start PARAM */);
#line 1043 OMC_FILE
  TRACE_POP
}

/*
equation index: 71
type: SIMPLE_ASSIGN
fluPor[1].m_flow = fan.filter.y
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
#line 13 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) = (data->localData[0]->realVars[40] /* fan.filter.y variable */);
#line 1058 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_258(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_257(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_259(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_260(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_261(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_262(DATA *data, threadData_t *threadData);


/*
equation index: 78
type: SIMPLE_ASSIGN
hea.preDro.dp = if hea.preDro.dp_nominal_pos > 1e-15 then homotopy(Buildings.Fluid.BaseClasses.FlowModels.basicFlowFunction_m_flow(fluPor[1].m_flow, hea.preDro.k, hea.preDro.m_flow_turbulent), hea.preDro.dp_nominal_pos * fluPor[1].m_flow / hea.preDro.m_flow_nominal_pos) else 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  modelica_boolean tmp13;
  tmp13 = Greater((data->simulationInfo->realParameter[326] /* hea.preDro.dp_nominal_pos PARAM */),1e-15);
  (data->localData[0]->realVars[83] /* hea.preDro.dp variable */) = (tmp13?homotopy(omc_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow(threadData, (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), (data->simulationInfo->realParameter[328] /* hea.preDro.k PARAM */), (data->simulationInfo->realParameter[332] /* hea.preDro.m_flow_turbulent PARAM */)), DIVISION_SIM(((data->simulationInfo->realParameter[326] /* hea.preDro.dp_nominal_pos PARAM */)) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */)),(data->simulationInfo->realParameter[330] /* hea.preDro.m_flow_nominal_pos PARAM */),"hea.preDro.m_flow_nominal_pos",equationIndexes)):0.0);
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_264(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_275(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_266(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_267(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_270(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_268(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_274(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_271(DATA *data, threadData_t *threadData);


/*
equation index: 87
type: SIMPLE_ASSIGN
fan.PToMed.u1 = homotopy(smooth(1, if noEvent(abs(fan.VMachine_flow) + (-2.0) * fan.heaDis.delta_V_flow > fan.heaDis.delta_V_flow) then fan.heaDis.QThe_flow else if noEvent(abs(fan.VMachine_flow) + (-2.0) * fan.heaDis.delta_V_flow < (-fan.heaDis.delta_V_flow)) then 0.0 else if noEvent(fan.heaDis.delta_V_flow > 0.0) then 0.25 * (2.0 - abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow) * ((abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow + -2.0) ^ 2.0 - 3.0) * fan.heaDis.QThe_flow + 0.5 * fan.heaDis.QThe_flow else 0.5 * fan.heaDis.QThe_flow), 0.0)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_real tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  modelica_boolean tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  tmp14 = Greater(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)) + (-2.0) * ((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  tmp22 = (modelica_boolean)tmp14;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  if(tmp22)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp23 = (data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp15 = Less(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)) + (-2.0) * ((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)),(-(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp20 = (modelica_boolean)tmp15;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    if(tmp20)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp21 = 0.0;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp16 = Greater((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),0.0);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp18 = (modelica_boolean)tmp16;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      if(tmp18)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp17 = DIVISION_SIM(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow",equationIndexes) + -2.0;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp19 = (0.25) * (((2.0 - (DIVISION_SIM(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow",equationIndexes))) * ((tmp17 * tmp17) - 3.0)) * ((data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */))) + (0.5) * ((data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp19 = (0.5) * ((data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp21 = tmp19;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp23 = tmp21;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  (data->localData[0]->realVars[27] /* fan.PToMed.u1 variable */) = homotopy(tmp23, 0.0);
#line 1188 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_273(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_269(DATA *data, threadData_t *threadData);


/*
equation index: 90
type: SIMPLE_ASSIGN
hea.outCon.hSet = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hea.outCon.Medium.specificEnthalpy(Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hea.outCon.Medium.setState_pTX(fan.port_a.p, Tsup, {}))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
#line 198 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hea_outCon_Medium_specificEnthalpy(threadData, omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hea_outCon_Medium_setState__pTX(threadData, (data->localData[0]->realVars[45] /* fan.port_a.p variable */), (data->localData[0]->realVars[22] /* Tsup variable */), _OMC_LIT59));
#line 1207 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_292(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_294(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_295(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_276(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_300(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_265(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_279(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_280(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_281(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_293(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_282(DATA *data, threadData_t *threadData);


/*
equation index: 102
type: SIMPLE_ASSIGN
fluPor[2].m_flow = -fan.filter.y
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
#line 48 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/MassFlowSource_T.mo"
  (data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */) = (-(data->localData[0]->realVars[40] /* fan.filter.y variable */));
#line 1244 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_291(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_255(DATA *data, threadData_t *threadData);


/*
equation index: 105
type: SIMPLE_ASSIGN
resSup.port_b.h_outflow = max(fan.filter.y, 1e-07) * fan.vol.ports[2].h_outflow / (1e-07 + max(fan.filter.y, 1e-07))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
#line 428 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  (data->localData[0]->realVars[93] /* resSup.port_b.h_outflow variable */) = (fmax((data->localData[0]->realVars[40] /* fan.filter.y variable */),1e-07)) * (DIVISION_SIM((data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */),1e-07 + fmax((data->localData[0]->realVars[40] /* fan.filter.y variable */),1e-07),"1e-07 + max(fan.filter.y, 1e-07)",equationIndexes));
#line 1263 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_297(DATA *data, threadData_t *threadData);


/*
equation index: 107
type: SIMPLE_ASSIGN
fan.filter.s[2] = fan.filter.y / fan.filter.u_nom
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[1] /* fan.filter.s[2] STATE(1) */) = DIVISION_SIM((data->localData[0]->realVars[40] /* fan.filter.y variable */),(data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */),"fan.filter.u_nom",equationIndexes);
#line 1280 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(DATA *data, threadData_t *threadData);


/*
equation index: 109
type: SIMPLE_ASSIGN
fan.preSou.V_flow = fan.filter.y / Modelica.Fluid.Utilities.regStep(fan.filter.y, Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.density(Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.setState_phX(fan.port_a.p, fan.vol.ports[2].h_outflow, {})), Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.density(Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.setState_phX(fan.port_b.p, fan.vol.ports[2].h_outflow, {})), fan.preSou.m_flow_small)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
#line 40 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
  (data->localData[0]->realVars[48] /* fan.preSou.V_flow variable */) = DIVISION_SIM((data->localData[0]->realVars[40] /* fan.filter.y variable */),omc_Modelica_Fluid_Utilities_regStep(threadData, (data->localData[0]->realVars[40] /* fan.filter.y variable */), omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_density(threadData, omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_setState__phX(threadData, (data->localData[0]->realVars[45] /* fan.port_a.p variable */), (data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */), _OMC_LIT59)), omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_density(threadData, omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_setState__phX(threadData, (data->localData[0]->realVars[46] /* fan.port_b.p variable */), (data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */), _OMC_LIT59)), (data->simulationInfo->realParameter[258] /* fan.preSou.m_flow_small PARAM */)),"Modelica.Fluid.Utilities.regStep(fan.filter.y, Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.density(Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.setState_phX(fan.port_a.p, fan.vol.ports[2].h_outflow, {})), Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.density(Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.setState_phX(fan.port_b.p, fan.vol.ports[2].h_outflow, {})), fan.preSou.m_flow_small)",equationIndexes);
#line 1297 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_250(DATA *data, threadData_t *threadData);


/*
equation index: 111
type: SIMPLE_ASSIGN
hvacAda.ports[1].h_outflow = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hvacAda.bou.Medium.specificEnthalpy(Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hvacAda.bou.Medium.setState_pTX(bou.p, fluPor[1].backward.T, hvacAda.bou.X_in_internal))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  real_array tmp24;
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/MassFlowSource_T.mo"
  real_array_create(&tmp24, ((modelica_real*)&((&data->localData[0]->realVars[84] /* hvacAda.bou.X_in_internal[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 35 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/MassFlowSource_T.mo"
  (data->localData[0]->realVars[90] /* hvacAda.ports[1].h_outflow variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_bou_Medium_specificEnthalpy(threadData, omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_bou_Medium_setState__pTX(threadData, (data->simulationInfo->realParameter[16] /* bou.p PARAM */), (data->localData[0]->realVars[64] /* fluPor[1].backward.T variable */), tmp24));
#line 1317 OMC_FILE
  TRACE_POP
}

/*
equation index: 112
type: SIMPLE_ASSIGN
fan.eff.preDer3[4] = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[190] /* fan.eff.preDer3[4] PARAM */) = 0.0;
#line 1332 OMC_FILE
  TRACE_POP
}

/*
equation index: 113
type: SIMPLE_ASSIGN
fan.eff.preDer3[3] = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[189] /* fan.eff.preDer3[3] PARAM */) = 0.0;
#line 1347 OMC_FILE
  TRACE_POP
}

/*
equation index: 114
type: SIMPLE_ASSIGN
fan.eff.preDer3[2] = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[188] /* fan.eff.preDer3[2] PARAM */) = 0.0;
#line 1362 OMC_FILE
  TRACE_POP
}

/*
equation index: 115
type: SIMPLE_ASSIGN
fan.eff.preDer3[1] = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[187] /* fan.eff.preDer3[1] PARAM */) = 0.0;
#line 1377 OMC_FILE
  TRACE_POP
}

/*
equation index: 116
type: SIMPLE_ASSIGN
fan.eff.preDer2[3] = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
#line 406 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[186] /* fan.eff.preDer2[3] PARAM */) = 0.0;
#line 1392 OMC_FILE
  TRACE_POP
}

/*
equation index: 117
type: SIMPLE_ASSIGN
fan.eff.preDer2[2] = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
#line 406 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[185] /* fan.eff.preDer2[2] PARAM */) = 0.0;
#line 1407 OMC_FILE
  TRACE_POP
}

/*
equation index: 118
type: SIMPLE_ASSIGN
fan.eff.preDer2[1] = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
#line 406 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->simulationInfo->realParameter[184] /* fan.eff.preDer2[1] PARAM */) = 0.0;
#line 1422 OMC_FILE
  TRACE_POP
}

/*
equation index: 119
type: ARRAY_CALL_ASSIGN

fan.eff.preDer1 = Buildings.Utilities.Math.Functions.splineDerivatives({0.0, 0.0009999551372974348}, {20000.0, fan.eff.pCur1.dp[2]}, Buildings.Utilities.Math.Functions.isMonotonic({20000.0, fan.eff.pCur1.dp[2]}, false))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  real_array tmp25;
  real_array tmp26;
  real_array tmp27;
#line 404 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  array_alloc_scalar_real_array(&tmp25, 2, (modelica_real)20000.0, (modelica_real)(data->simulationInfo->realParameter[54] /* fan.eff.pCur1.dp[2] PARAM */));
#line 404 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  array_alloc_scalar_real_array(&tmp26, 2, (modelica_real)20000.0, (modelica_real)(data->simulationInfo->realParameter[54] /* fan.eff.pCur1.dp[2] PARAM */));
#line 404 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  real_array_create(&tmp27, ((modelica_real*)&((&(data->simulationInfo->realParameter[182] /* fan.eff.preDer1[1] PARAM */))[((modelica_integer) 1) - 1])), 1, (_index_t)2);
#line 404 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  real_array_copy_data(omc_Buildings_Utilities_Math_Functions_splineDerivatives(threadData, _OMC_LIT60, tmp25, omc_Buildings_Utilities_Math_Functions_isMonotonic(threadData, tmp26, 0)), tmp27);
#line 1447 OMC_FILE
  TRACE_POP
}

/*
equation index: 130
type: ALGORITHM

  assert(if hea.preDro.dp_nominal_pos > 1e-15 then hea.preDro.m_flow_turbulent > 0.0 else true, "m_flow_turbulent must be bigger than zero.");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,42,"m_flow_turbulent must be bigger than zero.");
  static int tmp33 = 0;
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    tmp28 = Greater((data->simulationInfo->realParameter[326] /* hea.preDro.dp_nominal_pos PARAM */),1e-15);
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    tmp30 = (modelica_boolean)tmp28;
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    if(tmp30)
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      tmp29 = Greater((data->simulationInfo->realParameter[332] /* hea.preDro.m_flow_turbulent PARAM */),0.0);
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      tmp31 = tmp29;
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    }
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    else
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      tmp31 = 1;
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    }
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    if(!tmp31)
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        const char* assert_cond = "(if hea.preDro.dp_nominal_pos > 1e-15 then hea.preDro.m_flow_turbulent > 0.0 else true)";
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo",27,4,27,78,0};
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp32)));
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          data->simulationInfo->needToReThrow = 1;
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        } else {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo",27,4,27,78,0};
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp32)));
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        }
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      }
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    }
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  }
#line 1521 OMC_FILE
  TRACE_POP
}

/*
equation index: 129
type: ALGORITHM

  assert(fan.nominalValuesDefineDefaultPressureCurve, "*** Warning: You are using a flow or pressure controlled mover with the
             default pressure curve.
             This leads to approximate calculations of the electrical power
             consumption. Add the correct pressure curve in the record per
             to obtain an accurate computation.
             Setting nominalValuesDefineDefaultPressureCurve=true will suppress this warning.");
  assert(fan.nominalValuesDefineDefaultPressureCurve or fan.per.etaHydMet <> Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.Power_VolumeFlowRate, "*** Warning: You are using a flow or pressure controlled mover with the
             default pressure curve with per.etaHydMet set to
             Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.Power_VolumeFlowRate.
             Since this can cause wrong power consumption, the model will overwrite
             this setting and use instead
             Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.NotProvided.See the user guide to see what assumptions are made in this setting
             or provide other information to the model.
             Setting nominalValuesDefineDefaultPressureCurve=true will suppress this warning.");
  assert(not (fan.per.etaHydMet == Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.Power_VolumeFlowRate or fan.per.etaHydMet == Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.EulerNumber), "*** Warning in PumpCircuit.fan: per.etaHydMet is set to .Power_VolumeFlowRate or .EulerNumber.
             This requires that per.pressure be provided.
             Because it is not,
             the model will override this setting and use .NotProvided instead.");
  assert(fan.per.haveWMot_nominal or not (fan.per.etaMotMet == Buildings.Fluid.Movers.BaseClasses.Types.MotorEfficiencyMethod.Efficiency_MotorPartLoadRatio or fan.per.etaMotMet == Buildings.Fluid.Movers.BaseClasses.Types.MotorEfficiencyMethod.GenericCurve), "*** Warning in PumpCircuit.fan: per.etaMotMet is set to .Efficiency_MotorPartLoadRatio
             or .GenericCurve. This requires that per.WMot_nominal be provided
             or at least per.pressure be provided so that per.WMot_nominal can
             be estimated. Because neither is provided,
             the model will override this setting and use .NotProvided instead.");
  assert(fan.per.powerOrEfficiencyIsHydraulic or not (fan.per.etaMotMet == Buildings.Fluid.Movers.BaseClasses.Types.MotorEfficiencyMethod.Efficiency_MotorPartLoadRatio or fan.per.etaMotMet == Buildings.Fluid.Movers.BaseClasses.Types.MotorEfficiencyMethod.GenericCurve), "*** Warning in PumpCircuit.fan: per.etaMotMet is set to .Efficiency_MotorPartLoadRatio
             or .GenericCurve while information is provided for total electric
             power instead of hydraulic power. This forms an algebraic loop
             and may cause the simulation to not converge
             (see the \"Motor efficiency\" section in usersguide).");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
  static const MMC_DEFSTRINGLIT(tmp34,401,"*** Warning: You are using a flow or pressure controlled mover with the\n             default pressure curve.\n             This leads to approximate calculations of the electrical power\n             consumption. Add the correct pressure curve in the record per\n             to obtain an accurate computation.\n             Setting nominalValuesDefineDefaultPressureCurve=true will suppress this warning.");
  static int tmp35 = 0;
  static const MMC_DEFSTRINGLIT(tmp37,671,"*** Warning: You are using a flow or pressure controlled mover with the\n             default pressure curve with per.etaHydMet set to\n             Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.Power_VolumeFlowRate.\n             Since this can cause wrong power consumption, the model will overwrite\n             this setting and use instead\n             Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.NotProvided.See the user guide to see what assumptions are made in this setting\n             or provide other information to the model.\n             Setting nominalValuesDefineDefaultPressureCurve=true will suppress this warning.");
  static int tmp38 = 0;
  static const MMC_DEFSTRINGLIT(tmp41,264,"*** Warning in PumpCircuit.fan: per.etaHydMet is set to .Power_VolumeFlowRate or .EulerNumber.\n             This requires that per.pressure be provided.\n             Because it is not,\n             the model will override this setting and use .NotProvided instead.");
  static int tmp42 = 0;
  static const MMC_DEFSTRINGLIT(tmp45,380,"*** Warning in PumpCircuit.fan: per.etaMotMet is set to .Efficiency_MotorPartLoadRatio\n             or .GenericCurve. This requires that per.WMot_nominal be provided\n             or at least per.pressure be provided so that per.WMot_nominal can\n             be estimated. Because neither is provided,\n             the model will override this setting and use .NotProvided instead.");
  static int tmp46 = 0;
  static const MMC_DEFSTRINGLIT(tmp49,364,"*** Warning in PumpCircuit.fan: per.etaMotMet is set to .Efficiency_MotorPartLoadRatio\n             or .GenericCurve while information is provided for total electric\n             power instead of hydraulic power. This forms an algebraic loop\n             and may cause the simulation to not converge\n             (see the \"Motor efficiency\" section in usersguide).");
  static int tmp50 = 0;
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  if(!tmp35)
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  {
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    if(!(data->simulationInfo->booleanParameter[23] /* fan.nominalValuesDefineDefaultPressureCurve PARAM */))
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    {
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      {
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        const char* assert_cond = "(fan.nominalValuesDefineDefaultPressureCurve)";
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",348,3,357,39,0};
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp34)));
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        } else {
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",348,3,357,39,0};
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp34)));
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        }
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      }
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmp35 = 1;
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    }
#line 348 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  }
#line 1606 OMC_FILE

#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  if(!tmp38)
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  {
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    if(!((data->simulationInfo->booleanParameter[23] /* fan.nominalValuesDefineDefaultPressureCurve PARAM */) || ((data->simulationInfo->integerParameter[16] /* fan.per.etaHydMet PARAM */) != 3)))
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    {
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      {
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        const char* assert_cond = "(fan.nominalValuesDefineDefaultPressureCurve or fan.per.etaHydMet <> Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.Power_VolumeFlowRate)";
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",366,3,380,39,0};
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp37)));
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        } else {
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",366,3,380,39,0};
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp37)));
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        }
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      }
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmp38 = 1;
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    }
#line 366 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  }
#line 1642 OMC_FILE

#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  if(!tmp42)
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  {
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    if(!(!(((data->simulationInfo->integerParameter[16] /* fan.per.etaHydMet PARAM */) == 3) || ((data->simulationInfo->integerParameter[16] /* fan.per.etaHydMet PARAM */) == 4))))
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    {
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      {
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        const char* assert_cond = "(not (fan.per.etaHydMet == Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.Power_VolumeFlowRate or fan.per.etaHydMet == Buildings.Fluid.Movers.BaseClasses.Types.HydraulicEfficiencyMethod.EulerNumber))";
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",382,3,392,39,0};
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp41)));
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        } else {
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",382,3,392,39,0};
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp41)));
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        }
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      }
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmp42 = 1;
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    }
#line 382 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  }
#line 1678 OMC_FILE

#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  if(!tmp46)
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  {
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    if(!((data->simulationInfo->booleanParameter[25] /* fan.per.haveWMot_nominal PARAM */) || (!(((data->simulationInfo->integerParameter[17] /* fan.per.etaMotMet PARAM */) == 3) || ((data->simulationInfo->integerParameter[17] /* fan.per.etaMotMet PARAM */) == 4)))))
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    {
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      {
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        const char* assert_cond = "(fan.per.haveWMot_nominal or not (fan.per.etaMotMet == Buildings.Fluid.Movers.BaseClasses.Types.MotorEfficiencyMethod.Efficiency_MotorPartLoadRatio or fan.per.etaMotMet == Buildings.Fluid.Movers.BaseClasses.Types.MotorEfficiencyMethod.GenericCurve))";
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",394,3,405,39,0};
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp45)));
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        } else {
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",394,3,405,39,0};
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp45)));
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        }
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      }
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmp46 = 1;
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    }
#line 394 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  }
#line 1714 OMC_FILE

#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  if(!tmp50)
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  {
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    if(!((data->simulationInfo->booleanParameter[27] /* fan.per.powerOrEfficiencyIsHydraulic PARAM */) || (!(((data->simulationInfo->integerParameter[17] /* fan.per.etaMotMet PARAM */) == 3) || ((data->simulationInfo->integerParameter[17] /* fan.per.etaMotMet PARAM */) == 4)))))
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    {
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      {
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        const char* assert_cond = "(fan.per.powerOrEfficiencyIsHydraulic or not (fan.per.etaMotMet == Buildings.Fluid.Movers.BaseClasses.Types.MotorEfficiencyMethod.Efficiency_MotorPartLoadRatio or fan.per.etaMotMet == Buildings.Fluid.Movers.BaseClasses.Types.MotorEfficiencyMethod.GenericCurve))";
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",407,3,418,39,0};
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp49)));
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        } else {
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",407,3,418,39,0};
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp49)));
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        }
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      }
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmp50 = 1;
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    }
#line 407 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  }
#line 1750 OMC_FILE
  TRACE_POP
}

/*
equation index: 128
type: ALGORITHM

  assert(Buildings.Utilities.Math.Functions.isMonotonic({0.0, 0.0009999551372974348}, true), "The fan pressure rise must be a strictly decreasing sequence with respect to the volume flow rate,
  with the first element for the fan pressure raise being non-zero.
The following performance data have been entered:
" + Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.eff.getArrayAsString({0.0, 0.0009999551372974348}, "pressure.V_flow", 6, 6));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  real_array tmp51;
  static const MMC_DEFSTRINGLIT(tmp52,217,"The fan pressure rise must be a strictly decreasing sequence with respect to the volume flow rate,\n  with the first element for the fan pressure raise being non-zero.\nThe following performance data have been entered:\n");
  real_array tmp53;
  static const MMC_DEFSTRINGLIT(tmp54,15,"pressure.V_flow");
  modelica_metatype tmpMeta55;
  static int tmp56 = 0;
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  {
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    array_alloc_scalar_real_array(&tmp51, 2, (modelica_real)0.0, (modelica_real)0.0009999551372974348);
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    if(!omc_Buildings_Utilities_Math_Functions_isMonotonic(threadData, tmp51, 1))
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    {
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      array_alloc_scalar_real_array(&tmp53, 2, (modelica_real)0.0, (modelica_real)0.0009999551372974348);
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmpMeta55 = stringAppend(MMC_REFSTRINGLIT(tmp52),omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_eff_getArrayAsString(threadData, tmp53, MMC_REFSTRINGLIT(tmp54), ((modelica_integer) 6), ((modelica_integer) 6)));
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      {
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        const char* assert_cond = "(Buildings.Utilities.Math.Functions.isMonotonic({0.0, 0.0009999551372974348}, true))";
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo",360,3,365,62,0};
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta55));
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          data->simulationInfo->needToReThrow = 1;
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        } else {
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo",360,3,365,62,0};
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta55));
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        }
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      }
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    }
#line 360 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  }
#line 1811 OMC_FILE
  TRACE_POP
}

/*
equation index: 127
type: ALGORITHM

  assert(fan.eff.per.power.P[1] < 1e-06 or fan.eff.per.WMot_nominal > fan.eff.per.power.P[1] * 0.99, "In PumpCircuit.fan.eff: The rated motor power provided in
         per.WMot_nominal is smaller than the maximum power provided in per.power.
         Use a larger value for per.WMot_nominal or leave it blank to allow the
         model to assume a default value.");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
  modelica_boolean tmp57;
  modelica_boolean tmp58;
  static const MMC_DEFSTRINGLIT(tmp59,262,"In PumpCircuit.fan.eff: The rated motor power provided in\n         per.WMot_nominal is smaller than the maximum power provided in per.power.\n         Use a larger value for per.WMot_nominal or leave it blank to allow the\n         model to assume a default value.");
  static int tmp60 = 0;
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  {
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp57 = Less((data->simulationInfo->realParameter[105] /* fan.eff.per.power.P[1] PARAM */),1e-06);
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp58 = Greater((data->simulationInfo->realParameter[70] /* fan.eff.per.WMot_nominal PARAM */),((data->simulationInfo->realParameter[105] /* fan.eff.per.power.P[1] PARAM */)) * (0.99));
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    if(!(tmp57 || tmp58))
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    {
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      {
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        const char* assert_cond = "(fan.eff.per.power.P[1] < 1e-06 or fan.eff.per.WMot_nominal > fan.eff.per.power.P[1] * 0.99)";
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo",432,3,436,44,0};
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp59)));
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          data->simulationInfo->needToReThrow = 1;
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        } else {
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo",432,3,436,44,0};
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp59)));
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        }
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      }
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    }
#line 432 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  }
#line 1868 OMC_FILE
  TRACE_POP
}

/*
equation index: 126
type: ALGORITHM

  assert(fan.m_flow_nominal >= 1e-60, "In PumpCircuit.fan: The value of parameter m_flow_nominal should be greater or equal than " + String(1e-60, 6, 0, true) + " but it equals " + String(fan.m_flow_nominal, 6, 0, true));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
  modelica_boolean tmp61;
  static const MMC_DEFSTRINGLIT(tmp62,90,"In PumpCircuit.fan: The value of parameter m_flow_nominal should be greater or equal than ");
  modelica_string tmp63;
  modelica_metatype tmpMeta64;
  static const MMC_DEFSTRINGLIT(tmp65,15," but it equals ");
  modelica_metatype tmpMeta66;
  modelica_string tmp67;
  modelica_metatype tmpMeta68;
  static int tmp69 = 0;
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  {
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    tmp61 = GreaterEq((data->simulationInfo->realParameter[204] /* fan.m_flow_nominal PARAM */),1e-60);
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    if(!tmp61)
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    {
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmp63 = modelica_real_to_modelica_string(1e-60, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmpMeta64 = stringAppend(MMC_REFSTRINGLIT(tmp62),tmp63);
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmpMeta66 = stringAppend(tmpMeta64,MMC_REFSTRINGLIT(tmp65));
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmp67 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[204] /* fan.m_flow_nominal PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      tmpMeta68 = stringAppend(tmpMeta66,tmp67);
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      {
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        const char* assert_cond = "(fan.m_flow_nominal >= 1e-60)";
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",340,3,342,81,0};
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          data->simulationInfo->needToReThrow = 1;
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        } else {
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo",340,3,342,81,0};
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
        }
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
      }
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
    }
#line 340 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  }
#line 1935 OMC_FILE
  TRACE_POP
}

/*
equation index: 125
type: ALGORITHM

  assert(resSup.m_flow_turbulent > 0.0, "m_flow_turbulent must be bigger than zero.");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  modelica_boolean tmp70;
  static const MMC_DEFSTRINGLIT(tmp71,42,"m_flow_turbulent must be bigger than zero.");
  static int tmp72 = 0;
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    tmp70 = Greater((data->simulationInfo->realParameter[366] /* resSup.m_flow_turbulent PARAM */),0.0);
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    if(!tmp70)
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        const char* assert_cond = "(resSup.m_flow_turbulent > 0.0)";
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo",27,4,27,78,0};
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp71)));
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          data->simulationInfo->needToReThrow = 1;
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        } else {
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo",27,4,27,78,0};
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp71)));
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        }
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      }
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    }
#line 27 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  }
#line 1986 OMC_FILE
  TRACE_POP
}

/*
equation index: 124
type: ALGORITHM

  assert(resSup.m_flow_nominal_pos > 0.0, "m_flow_nominal_pos must be non-zero. Check parameters.");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  modelica_boolean tmp73;
  static const MMC_DEFSTRINGLIT(tmp74,54,"m_flow_nominal_pos must be non-zero. Check parameters.");
  static int tmp75 = 0;
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    tmp73 = Greater((data->simulationInfo->realParameter[364] /* resSup.m_flow_nominal_pos PARAM */),0.0);
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    if(!tmp73)
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        const char* assert_cond = "(resSup.m_flow_nominal_pos > 0.0)";
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo",30,2,30,90,0};
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp74)));
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          data->simulationInfo->needToReThrow = 1;
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        } else {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo",30,2,30,90,0};
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp74)));
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        }
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      }
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    }
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  }
#line 2037 OMC_FILE
  TRACE_POP
}

/*
equation index: 123
type: ALGORITHM

  assert(hea.preDro.m_flow_nominal_pos > 0.0, "m_flow_nominal_pos must be non-zero. Check parameters.");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  modelica_boolean tmp76;
  static const MMC_DEFSTRINGLIT(tmp77,54,"m_flow_nominal_pos must be non-zero. Check parameters.");
  static int tmp78 = 0;
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    tmp76 = Greater((data->simulationInfo->realParameter[330] /* hea.preDro.m_flow_nominal_pos PARAM */),0.0);
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    if(!tmp76)
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        const char* assert_cond = "(hea.preDro.m_flow_nominal_pos > 0.0)";
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo",30,2,30,90,0};
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp77)));
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          data->simulationInfo->needToReThrow = 1;
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        } else {
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo",30,2,30,90,0};
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp77)));
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
        }
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
      }
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
    }
#line 30 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  }
#line 2088 OMC_FILE
  TRACE_POP
}

/*
equation index: 122
type: ALGORITHM

  Modelica.Fluid.Utilities.checkBoundary("SimpleLiquidWater", {"SimpleLiquidWater"}, true, true, bou.X_in_internal, "Boundary_pT");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  static const MMC_DEFSTRINGLIT(tmp79,17,"SimpleLiquidWater");
  string_array tmp80;
  static const MMC_DEFSTRINGLIT(tmp81,17,"SimpleLiquidWater");
  real_array tmp82;
  static const MMC_DEFSTRINGLIT(tmp83,11,"Boundary_pT");
#line 43 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/BaseClasses/PartialSource_Xi_C.mo"
  array_alloc_scalar_string_array(&tmp80, 1, (modelica_string)MMC_REFSTRINGLIT(tmp81));
#line 43 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/BaseClasses/PartialSource_Xi_C.mo"
  real_array_create(&tmp82, ((modelica_real*)&((&data->localData[0]->realVars[23] /* bou.X_in_internal[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 43 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/BaseClasses/PartialSource_Xi_C.mo"
  omc_Modelica_Fluid_Utilities_checkBoundary(threadData, MMC_REFSTRINGLIT(tmp79), tmp80, 1, 1, tmp82, MMC_REFSTRINGLIT(tmp83));
#line 2113 OMC_FILE
  TRACE_POP
}

/*
equation index: 121
type: ALGORITHM

  assert(bou.p_in_internal > 10000.0, "In PumpCircuit.bou: The parameter value p=" + String(bou.p_in_internal, 6, 0, true) + " is low for water. This is likely an error.");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  modelica_boolean tmp84;
  static const MMC_DEFSTRINGLIT(tmp85,42,"In PumpCircuit.bou: The parameter value p=");
  modelica_string tmp86;
  modelica_metatype tmpMeta87;
  static const MMC_DEFSTRINGLIT(tmp88,43," is low for water. This is likely an error.");
  modelica_metatype tmpMeta89;
  static int tmp90 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
    tmp84 = Greater((data->localData[0]->realVars[24] /* bou.p_in_internal variable */),10000.0);
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
    if(!tmp84)
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
      tmp86 = modelica_real_to_modelica_string((data->localData[0]->realVars[24] /* bou.p_in_internal variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
      tmpMeta87 = stringAppend(MMC_REFSTRINGLIT(tmp85),tmp86);
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
      tmpMeta89 = stringAppend(tmpMeta87,MMC_REFSTRINGLIT(tmp88));
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
        const char* assert_cond = "(bou.p_in_internal > 10000.0)";
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo",46,7,47,104,0};
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta89));
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo",46,7,47,104,0};
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta89));
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/Boundary_pT.mo"
  }
#line 2174 OMC_FILE
  TRACE_POP
}

/*
equation index: 120
type: ALGORITHM

  Modelica.Fluid.Utilities.checkBoundary("SimpleLiquidWater", {"SimpleLiquidWater"}, true, true, hvacAda.bou.X_in_internal, "Boundary_pT");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  static const MMC_DEFSTRINGLIT(tmp91,17,"SimpleLiquidWater");
  string_array tmp92;
  static const MMC_DEFSTRINGLIT(tmp93,17,"SimpleLiquidWater");
  real_array tmp94;
  static const MMC_DEFSTRINGLIT(tmp95,11,"Boundary_pT");
#line 43 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/BaseClasses/PartialSource_Xi_C.mo"
  array_alloc_scalar_string_array(&tmp92, 1, (modelica_string)MMC_REFSTRINGLIT(tmp93));
#line 43 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/BaseClasses/PartialSource_Xi_C.mo"
  real_array_create(&tmp94, ((modelica_real*)&((&data->localData[0]->realVars[84] /* hvacAda.bou.X_in_internal[1] variable */)[((modelica_integer) 1) - 1])), 1, (_index_t)1);
#line 43 "/home/marius/modelica-buildings/Buildings/Fluid/Sources/BaseClasses/PartialSource_Xi_C.mo"
  omc_Modelica_Fluid_Utilities_checkBoundary(threadData, MMC_REFSTRINGLIT(tmp91), tmp92, 1, 1, tmp94, MMC_REFSTRINGLIT(tmp95));
#line 2199 OMC_FILE
  TRACE_POP
}
OMC_DISABLE_OPT
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_1(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_2(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_3(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_4(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_5(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_6(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_7(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_8(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_9(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_10(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_11(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_12(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_13(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_14(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_15(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_16(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_17(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_18(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_19(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_20(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_21(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_22(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_23(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_24(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_25(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_26(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_27(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_28(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_29(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_30(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_31(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_32(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_33(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_34(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_35(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_36(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_37(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_38(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_39(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_40(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_41(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_42(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_43(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_44(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_45(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_46(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_47(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_48(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_49(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_50(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_51(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_52(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_53(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_54(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_55(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_56(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_57(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_58(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_59(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_305(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_306(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_307(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_251(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_252(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_65(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_66(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_67(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_68(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_69(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_70(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_71(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_258(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_257(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_259(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_260(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_261(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_262(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_78(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_264(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_275(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_266(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_267(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_270(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_268(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_274(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_271(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_87(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_273(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_269(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_90(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_292(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_294(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_295(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_276(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_300(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_265(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_279(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_280(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_281(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_293(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_282(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_102(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_291(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_255(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_105(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_297(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_107(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_109(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_250(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_111(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_112(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_113(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_114(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_115(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_116(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_117(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_118(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_119(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_130(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_129(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_128(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_127(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_126(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_125(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_124(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_123(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_122(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_121(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_120(data, threadData);
  TRACE_POP
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_1(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_2(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_3(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_4(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_5(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_6(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_7(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_8(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_9(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_10(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_11(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_12(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_13(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_14(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_15(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_16(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_17(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_18(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_19(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_20(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_21(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_22(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_23(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_24(DATA *data, threadData_t *threadData);


/*
equation index: 155
type: ALGORITHM

  fan.eff.powEu_internal := Buildings.Fluid.Movers.BaseClasses.Euler.power(Buildings.Fluid.Movers.BaseClasses.Euler.peak(0.0, 0.0, 0.7), Buildings.Fluid.Movers.BaseClasses.Characteristics.flowParametersInternal(2, {0.0, 0.0009999551372974348}, {20000.0, fan.eff.pCur1.dp[2]}));
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  Buildings_Fluid_Movers_BaseClasses_Euler_peak tmp0;
  Buildings_Fluid_Movers_BaseClasses_Characteristics_flowParametersInternal tmp1;
  real_array tmp2;
  real_array tmp3;
  Buildings_Fluid_Movers_BaseClasses_Euler_powerWithDerivative tmp4;
  real_array tmp5;
  real_array tmp6;
  real_array tmp7;
  real_array tmp8;
  real_array tmp9;
  real_array tmp10;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp0._V_flow = 0.0;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp0._dp = 0.0;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp0._eta = 0.7;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  array_alloc_scalar_real_array(&tmp2, 2, (modelica_real)0.0, (modelica_real)0.0009999551372974348);
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  array_alloc_scalar_real_array(&tmp3, 2, (modelica_real)20000.0, (modelica_real)(data->simulationInfo->realParameter[54] /* fan.eff.pCur1.dp[2] PARAM */));
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp1._n = ((modelica_integer) 2);
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp1._V_flow = tmp2;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp1._dp = tmp3;
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp4 = omc_Buildings_Fluid_Movers_BaseClasses_Euler_power(threadData, tmp0, tmp1);
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  array_alloc_scalar_real_array(&tmp5, 11, (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 3)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 4)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 5)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 6)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 7)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 8)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 9)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 10)), (modelica_real)real_array_get(tmp4._V_flow, 1, ((modelica_integer) 11)));
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  real_array_create(&tmp6, ((modelica_real*)&((&(data->simulationInfo->realParameter[160] /* fan.eff.powEu_internal.V_flow[1] PARAM */))[((modelica_integer) 1) - 1])), 1, (_index_t)11);
#line 273 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  real_array_copy_data(tmp5, tmp6);
#line 2444 OMC_FILE
  array_alloc_scalar_real_array(&tmp7, 11, (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 3)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 4)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 5)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 6)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 7)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 8)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 9)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 10)), (modelica_real)real_array_get(tmp4._P, 1, ((modelica_integer) 11)));
  real_array_create(&tmp8, ((modelica_real*)&((&(data->simulationInfo->realParameter[149] /* fan.eff.powEu_internal.P[1] PARAM */))[((modelica_integer) 1) - 1])), 1, (_index_t)11);
  real_array_copy_data(tmp7, tmp8);
  array_alloc_scalar_real_array(&tmp9, 11, (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 1)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 2)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 3)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 4)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 5)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 6)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 7)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 8)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 9)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 10)), (modelica_real)real_array_get(tmp4._d, 1, ((modelica_integer) 11)));
  real_array_create(&tmp10, ((modelica_real*)&((&(data->simulationInfo->realParameter[171] /* fan.eff.powEu_internal.d[1] PARAM */))[((modelica_integer) 1) - 1])), 1, (_index_t)11);
  real_array_copy_data(tmp9, tmp10);
  ;
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_26(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_27(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_28(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_29(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_30(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_31(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_32(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_33(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_34(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_35(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_36(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_37(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_38(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_39(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_40(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_41(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_42(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_43(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_44(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_45(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_46(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_47(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_48(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_49(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_50(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_51(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_52(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_53(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_54(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_55(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_56(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_57(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_58(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_59(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_305(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_306(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_307(DATA *data, threadData_t *threadData);


/*
equation index: 193
type: SIMPLE_ASSIGN
fan.PToMed.u1 = 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  (data->localData[0]->realVars[27] /* fan.PToMed.u1 variable */) = 0.0;
#line 2540 OMC_FILE
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_251(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_252(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_65(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_66(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_67(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_68(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_69(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_70(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_71(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_258(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_257(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_259(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_260(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_261(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_262(DATA *data, threadData_t *threadData);


/*
equation index: 209
type: SIMPLE_ASSIGN
hea.preDro.dp = if hea.preDro.dp_nominal_pos > 1e-15 then hea.preDro.dp_nominal_pos * fluPor[1].m_flow / hea.preDro.m_flow_nominal_pos else 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  modelica_boolean tmp11;
  tmp11 = Greater((data->simulationInfo->realParameter[326] /* hea.preDro.dp_nominal_pos PARAM */),1e-15);
  (data->localData[0]->realVars[83] /* hea.preDro.dp variable */) = (tmp11?DIVISION_SIM(((data->simulationInfo->realParameter[326] /* hea.preDro.dp_nominal_pos PARAM */)) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */)),(data->simulationInfo->realParameter[330] /* hea.preDro.m_flow_nominal_pos PARAM */),"hea.preDro.m_flow_nominal_pos",equationIndexes):0.0);
  TRACE_POP
}
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_264(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_275(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_266(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_267(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_273(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_270(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_268(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_274(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_271(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_269(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_90(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_292(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_294(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_295(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_276(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_300(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_265(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_279(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_280(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_281(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_293(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_282(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_102(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_291(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_255(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_105(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_297(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_107(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_109(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_250(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_111(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_112(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_113(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_114(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_115(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_116(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_117(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_118(DATA *data, threadData_t *threadData);

extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_119(DATA *data, threadData_t *threadData);

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_1(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_2(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_3(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_4(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_5(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_6(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_7(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_8(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_9(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_10(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_11(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_12(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_13(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_14(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_15(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_16(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_17(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_18(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_19(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_20(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_21(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_22(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_23(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_24(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_155(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_26(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_27(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_28(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_29(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_30(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_31(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_32(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_33(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_34(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_35(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_36(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_37(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_38(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_39(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_40(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_41(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_42(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_43(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_44(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_45(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_46(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_47(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_48(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_49(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_50(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_51(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_52(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_53(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_54(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_55(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_56(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_57(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_58(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_59(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_305(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_306(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_307(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_193(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_251(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_252(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_65(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_66(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_67(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_68(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_69(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_70(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_71(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_258(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_257(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_259(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_260(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_261(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_262(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_209(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_264(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_275(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_266(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_267(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_273(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_270(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_268(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_274(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_271(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_269(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_90(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_292(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_294(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_295(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_276(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_300(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_265(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_279(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_280(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_281(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_293(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_282(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_102(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_291(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_255(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_105(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_297(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_107(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_109(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_250(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_111(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_112(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_113(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_114(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_115(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_116(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_117(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_118(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_119(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

