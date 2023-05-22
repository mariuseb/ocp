#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit.fmutmp/sources/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit.c"
#endif
/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  (data->localData[0]->realVars[21] /* TRadZon variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[22] /* Tsup variable */) = data->simulationInfo->inputVars[1];
  (data->localData[0]->realVars[64] /* fluPor[1].backward.T variable */) = data->simulationInfo->inputVars[2];
  (data->localData[0]->realVars[65] /* fluPor[2].backward.T variable */) = data->simulationInfo->inputVars[3];
  (data->localData[0]->realVars[91] /* ovePum variable */) = data->simulationInfo->inputVars[4];
  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[21].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[22].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->realVarsData[64].attribute.start;
  data->simulationInfo->inputVars[3] = data->modelData->realVarsData[65].attribute.start;
  data->simulationInfo->inputVars[4] = data->modelData->realVarsData[91].attribute.start;
  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[21].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[22].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->realVarsData[64].attribute.start = data->simulationInfo->inputVars[2];
  data->modelData->realVarsData[65].attribute.start = data->simulationInfo->inputVars[3];
  data->modelData->realVarsData[91].attribute.start = data->simulationInfo->inputVars[4];
  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[21].info.name;
  names[1] = (char *) data->modelData->realVarsData[22].info.name;
  names[2] = (char *) data->modelData->realVarsData[64].info.name;
  names[3] = (char *) data->modelData->realVarsData[65].info.name;
  names[4] = (char *) data->modelData->realVarsData[91].info.name;
  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = (data->localData[0]->realVars[18] /* QGaiLat_flow variable */);
  data->simulationInfo->outputVars[1] = (data->localData[0]->realVars[19] /* QGaiRad_flow variable */);
  data->simulationInfo->outputVars[2] = (data->localData[0]->realVars[20] /* QGaiSenCon_flow variable */);
  data->simulationInfo->outputVars[3] = (data->localData[0]->realVars[66] /* fluPor[1].forward.T variable */);
  data->simulationInfo->outputVars[4] = (data->localData[0]->realVars[67] /* fluPor[2].forward.T variable */);
  data->simulationInfo->outputVars[5] = (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */);
  data->simulationInfo->outputVars[6] = (data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */);
  data->simulationInfo->outputVars[7] = (data->localData[0]->realVars[94] /* y variable */);
  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 250
type: SIMPLE_ASSIGN
hvacAda.bou.X_in_internal[1] = hvacAda.bou.X[1]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
  (data->localData[0]->realVars[84] /* hvacAda.bou.X_in_internal[1] variable */) = (data->simulationInfo->realParameter[338] /* hvacAda.bou.X[1] PARAM */);
  TRACE_POP
}
/*
equation index: 251
type: SIMPLE_ASSIGN
bou.p_in_internal = bou.p
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  (data->localData[0]->realVars[24] /* bou.p_in_internal variable */) = (data->simulationInfo->realParameter[16] /* bou.p PARAM */);
  TRACE_POP
}
/*
equation index: 252
type: SIMPLE_ASSIGN
bou.X_in_internal[1] = bou.X[1]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  (data->localData[0]->realVars[23] /* bou.X_in_internal[1] variable */) = (data->simulationInfo->realParameter[15] /* bou.X[1] PARAM */);
  TRACE_POP
}
/*
equation index: 253
type: SIMPLE_ASSIGN
$DER.fan.filter.s[2] = fan.filter.u_nom * (fan.filter.s[1] - fan.filter.s[2]) * fan.filter.w_u
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
#line 52 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[3] /* der(fan.filter.s[2]) STATE_DER */) = ((data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */)) * (((data->localData[0]->realVars[0] /* fan.filter.s[1] STATE(1) */) - (data->localData[0]->realVars[1] /* fan.filter.s[2] STATE(1) */)) * ((data->simulationInfo->realParameter[197] /* fan.filter.w_u PARAM */)));
#line 183 OMC_FILE
  TRACE_POP
}
/*
equation index: 254
type: SIMPLE_ASSIGN
fluPor[2].m_flow = (-fan.filter.u_nom) * fan.filter.s[2]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */) = ((-(data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */))) * ((data->localData[0]->realVars[1] /* fan.filter.s[2] STATE(1) */));
#line 197 OMC_FILE
  TRACE_POP
}
/*
equation index: 255
type: SIMPLE_ASSIGN
hvacAda.con[2].X_w_internal = if fluPor[2].m_flow >= 0.0 then 0.0 else 1.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  modelica_boolean tmp0;
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */), 0.0, 0, GreaterEq, GreaterEqZC);
  (data->localData[0]->realVars[89] /* hvacAda.con[2].X_w_internal variable */) = (tmp0?0.0:1.0);
  TRACE_POP
}
/*
equation index: 256
type: SIMPLE_ASSIGN
fluPor[1].m_flow = -fluPor[2].m_flow
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
#line 13 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Fluid/Interfaces.mo"
  (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) = (-(data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */));
#line 225 OMC_FILE
  TRACE_POP
}
/*
equation index: 257
type: SIMPLE_ASSIGN
fan.vol.steBal.m_flowInv = if noEvent(fluPor[1].m_flow > 0.001 * fan.vol.steBal.m_flow_small) or noEvent(fluPor[1].m_flow < (-0.001) * fan.vol.steBal.m_flow_small) then 1.0 / fluPor[1].m_flow else if noEvent(fluPor[1].m_flow < 0.5 * fan.vol.steBal.deltaReg) and noEvent(fluPor[1].m_flow > (-0.5) * fan.vol.steBal.deltaReg) then fluPor[1].m_flow / fan.vol.steBal.deltaReg ^ 2.0 else Buildings.Utilities.Math.Functions.BaseClasses.smoothTransition(fluPor[1].m_flow, fan.vol.steBal.deltaReg, fan.vol.steBal.deltaInvReg, fan.vol.steBal.aReg, fan.vol.steBal.bReg, fan.vol.steBal.cReg, fan.vol.steBal.dReg, fan.vol.steBal.eReg, fan.vol.steBal.fReg)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_real tmp9;
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  tmp1 = Greater((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(0.001) * ((data->simulationInfo->realParameter[294] /* fan.vol.steBal.m_flow_small PARAM */)));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  tmp2 = Less((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(-0.001) * ((data->simulationInfo->realParameter[294] /* fan.vol.steBal.m_flow_small PARAM */)));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  tmp8 = (modelica_boolean)(tmp1 || tmp2);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  if(tmp8)
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  {
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp9 = DIVISION_SIM(1.0,(data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),"fluPor[1].m_flow",equationIndexes);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  }
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  else
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  {
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp3 = Less((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(0.5) * ((data->simulationInfo->realParameter[290] /* fan.vol.steBal.deltaReg PARAM */)));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp4 = Greater((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(-0.5) * ((data->simulationInfo->realParameter[290] /* fan.vol.steBal.deltaReg PARAM */)));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp6 = (modelica_boolean)(tmp3 && tmp4);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    if(tmp6)
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    {
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp5 = (data->simulationInfo->realParameter[290] /* fan.vol.steBal.deltaReg PARAM */);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp7 = DIVISION_SIM((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(tmp5 * tmp5),"fan.vol.steBal.deltaReg ^ 2.0",equationIndexes);
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    }
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    else
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    {
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp7 = omc_Buildings_Utilities_Math_Functions_BaseClasses_smoothTransition(threadData, (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), (data->simulationInfo->realParameter[290] /* fan.vol.steBal.deltaReg PARAM */), (data->simulationInfo->realParameter[289] /* fan.vol.steBal.deltaInvReg PARAM */), (data->simulationInfo->realParameter[284] /* fan.vol.steBal.aReg PARAM */), (data->simulationInfo->realParameter[285] /* fan.vol.steBal.bReg PARAM */), (data->simulationInfo->realParameter[286] /* fan.vol.steBal.cReg PARAM */), (data->simulationInfo->realParameter[288] /* fan.vol.steBal.dReg PARAM */), (data->simulationInfo->realParameter[291] /* fan.vol.steBal.eReg PARAM */), (data->simulationInfo->realParameter[292] /* fan.vol.steBal.fReg PARAM */));
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    }
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp9 = tmp7;
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  }
#line 136 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  (data->localData[0]->realVars[62] /* fan.vol.steBal.m_flowInv variable */) = tmp9;
#line 294 OMC_FILE
  TRACE_POP
}
/*
equation index: 258
type: SIMPLE_ASSIGN
hvacAda.con[1].X_w_internal = if fluPor[1].m_flow >= 0.0 then 0.0 else 1.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  modelica_boolean tmp10;
  relationhysteresis(data, &tmp10, (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), 0.0, 1, GreaterEq, GreaterEqZC);
  (data->localData[0]->realVars[88] /* hvacAda.con[1].X_w_internal variable */) = (tmp10?0.0:1.0);
  TRACE_POP
}
/*
equation index: 259
type: SIMPLE_ASSIGN
fan.VMachine_flow = 0.001004433569776996 * fluPor[1].m_flow
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
#line 451 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[28] /* fan.VMachine_flow variable */) = (0.001004433569776996) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */));
#line 322 OMC_FILE
  TRACE_POP
}
/*
equation index: 260
type: SIMPLE_ASSIGN
fan.eff.r_V = fan.VMachine_flow / fan.eff.V_flow_max
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
#line 454 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[36] /* fan.eff.r_V variable */) = DIVISION_SIM((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */),(data->simulationInfo->realParameter[33] /* fan.eff.V_flow_max PARAM */),"fan.eff.V_flow_max",equationIndexes);
#line 336 OMC_FILE
  TRACE_POP
}
/*
equation index: 261
type: SIMPLE_ASSIGN
resSup.dp = fluPor[1].m_flow * resSup.coeff
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
#line 38 "/home/marius/modelica-buildings/Buildings/Fluid/FixedResistances/PressureDrop.mo"
  (data->localData[0]->realVars[92] /* resSup.dp variable */) = ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */)) * ((data->simulationInfo->realParameter[357] /* resSup.coeff PARAM */));
#line 350 OMC_FILE
  TRACE_POP
}
/*
equation index: 262
type: SIMPLE_ASSIGN
fan.port_b.p = bou.p + resSup.dp
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,262};
#line 23 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortInterface.mo"
  (data->localData[0]->realVars[46] /* fan.port_b.p variable */) = (data->simulationInfo->realParameter[16] /* bou.p PARAM */) + (data->localData[0]->realVars[92] /* resSup.dp variable */);
#line 364 OMC_FILE
  TRACE_POP
}
/*
equation index: 263
type: SIMPLE_ASSIGN
hea.preDro.dp = if hea.preDro.dp_nominal_pos > 1e-15 then Buildings.Fluid.BaseClasses.FlowModels.basicFlowFunction_m_flow(fluPor[1].m_flow, hea.preDro.k, hea.preDro.m_flow_turbulent) else 0.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,263};
  modelica_boolean tmp11;
  tmp11 = Greater((data->simulationInfo->realParameter[326] /* hea.preDro.dp_nominal_pos PARAM */),1e-15);
  (data->localData[0]->realVars[83] /* hea.preDro.dp variable */) = (tmp11?omc_Buildings_Fluid_BaseClasses_FlowModels_basicFlowFunction__m__flow(threadData, (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), (data->simulationInfo->realParameter[328] /* hea.preDro.k PARAM */), (data->simulationInfo->realParameter[332] /* hea.preDro.m_flow_turbulent PARAM */)):0.0);
  TRACE_POP
}
/*
equation index: 264
type: SIMPLE_ASSIGN
fan.port_a.p = bou.p - hea.preDro.dp
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
#line 23 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortInterface.mo"
  (data->localData[0]->realVars[45] /* fan.port_a.p variable */) = (data->simulationInfo->realParameter[16] /* bou.p PARAM */) - (data->localData[0]->realVars[83] /* hea.preDro.dp variable */);
#line 392 OMC_FILE
  TRACE_POP
}
/*
equation index: 265
type: SIMPLE_ASSIGN
hea.dp = bou.p - fan.port_a.p
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,265};
#line 23 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortInterface.mo"
  (data->localData[0]->realVars[70] /* hea.dp variable */) = (data->simulationInfo->realParameter[16] /* bou.p PARAM */) - (data->localData[0]->realVars[45] /* fan.port_a.p variable */);
#line 406 OMC_FILE
  TRACE_POP
}
/*
equation index: 266
type: SIMPLE_ASSIGN
fan.senRelPre.p_rel = fan.port_b.p - fan.port_a.p
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,266};
#line 47 "/home/marius/modelica-buildings/Buildings/Fluid/Sensors/RelativePressure.mo"
  (data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */) = (data->localData[0]->realVars[46] /* fan.port_b.p variable */) - (data->localData[0]->realVars[45] /* fan.port_a.p variable */);
#line 420 OMC_FILE
  TRACE_POP
}
/*
equation index: 267
type: SIMPLE_ASSIGN
fan.eff.WFlo = smooth(1, if noEvent(fan.senRelPre.p_rel * fan.VMachine_flow > 0.5 * fan.eff.deltaP) then fan.senRelPre.p_rel * fan.VMachine_flow else if noEvent(fan.senRelPre.p_rel * fan.VMachine_flow < (-0.5) * fan.eff.deltaP) then 0.0 else if noEvent(0.5 * fan.eff.deltaP > 0.0) then (-fan.senRelPre.p_rel) * fan.VMachine_flow * (4.0 * (fan.senRelPre.p_rel * fan.VMachine_flow / fan.eff.deltaP) ^ 2.0 - 3.0) * 2.0 * fan.senRelPre.p_rel * fan.VMachine_flow / (fan.eff.deltaP * 4.0) + 0.5 * fan.senRelPre.p_rel * fan.VMachine_flow else 0.5 * fan.senRelPre.p_rel * fan.VMachine_flow)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_real tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  modelica_boolean tmp20;
  modelica_real tmp21;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp12 = Greater(((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(0.5) * ((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp20 = (modelica_boolean)tmp12;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  if(tmp20)
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp21 = ((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  else
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp13 = Less(((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(-0.5) * ((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp18 = (modelica_boolean)tmp13;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    if(tmp18)
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp19 = 0.0;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    else
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp14 = Greater((0.5) * ((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)),0.0);
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp16 = (modelica_boolean)tmp14;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      if(tmp16)
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp15 = ((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * (DIVISION_SIM((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */),(data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */),"fan.eff.deltaP",equationIndexes));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp17 = DIVISION_SIM((((-(data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */))) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */))) * (((4.0) * ((tmp15 * tmp15)) - 3.0) * ((2.0) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */))))),((data->simulationInfo->realParameter[36] /* fan.eff.deltaP PARAM */)) * (4.0),"fan.eff.deltaP * 4.0",equationIndexes) + (0.5) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      else
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      {
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
        tmp17 = (0.5) * (((data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */)) * ((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)));
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
      tmp19 = tmp17;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
    tmp21 = tmp19;
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  }
#line 590 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[32] /* fan.eff.WFlo variable */) = tmp21;
#line 506 OMC_FILE
  TRACE_POP
}
/*
equation index: 268
type: SIMPLE_ASSIGN
fan.eff.P_internal = 1.428571428571429 * fan.eff.WFlo
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
#line 654 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[31] /* fan.eff.P_internal variable */) = (1.428571428571429) * ((data->localData[0]->realVars[32] /* fan.eff.WFlo variable */));
#line 520 OMC_FILE
  TRACE_POP
}
/*
equation index: 269
type: SIMPLE_ASSIGN
fan.eff.yMot = if fan.eff.per.WMot_nominal > 1e-15 then fan.eff.P_internal / fan.eff.per.WMot_nominal else 1.0
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  modelica_boolean tmp22;
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  tmp22 = Greater((data->simulationInfo->realParameter[70] /* fan.eff.per.WMot_nominal PARAM */),1e-15);
#line 310 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[37] /* fan.eff.yMot variable */) = (tmp22?DIVISION_SIM((data->localData[0]->realVars[31] /* fan.eff.P_internal variable */),(data->simulationInfo->realParameter[70] /* fan.eff.per.WMot_nominal PARAM */),"fan.eff.per.WMot_nominal",equationIndexes):1.0);
#line 537 OMC_FILE
  TRACE_POP
}
/*
equation index: 270
type: SIMPLE_ASSIGN
fan.P = 2.040816326530613 * fan.eff.WFlo
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
#line 607 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/FlowMachineInterface.mo"
  (data->localData[0]->realVars[26] /* fan.P variable */) = (2.040816326530613) * ((data->localData[0]->realVars[32] /* fan.eff.WFlo variable */));
#line 551 OMC_FILE
  TRACE_POP
}
/*
equation index: 271
type: SIMPLE_ASSIGN
fan.heaDis.QThe_flow = (if fan.per.motorCooledByFluid then fan.P else fan.eff.P_internal) - fan.eff.WFlo
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
#line 59 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  (data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */) = ((data->simulationInfo->booleanParameter[26] /* fan.per.motorCooledByFluid PARAM */)?(data->localData[0]->realVars[26] /* fan.P variable */):(data->localData[0]->realVars[31] /* fan.eff.P_internal variable */)) - (data->localData[0]->realVars[32] /* fan.eff.WFlo variable */);
#line 565 OMC_FILE
  TRACE_POP
}
/*
equation index: 272
type: SIMPLE_ASSIGN
fan.PToMed.u1 = smooth(1, if noEvent(abs(fan.VMachine_flow) + (-2.0) * fan.heaDis.delta_V_flow > fan.heaDis.delta_V_flow) then fan.heaDis.QThe_flow else if noEvent(abs(fan.VMachine_flow) + (-2.0) * fan.heaDis.delta_V_flow < (-fan.heaDis.delta_V_flow)) then 0.0 else if noEvent(fan.heaDis.delta_V_flow > 0.0) then 0.25 * (2.0 - abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow) * ((abs(fan.VMachine_flow) / fan.heaDis.delta_V_flow + -2.0) ^ 2.0 - 3.0) * fan.heaDis.QThe_flow + 0.5 * fan.heaDis.QThe_flow else 0.5 * fan.heaDis.QThe_flow)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  modelica_real tmp26;
  modelica_boolean tmp27;
  modelica_real tmp28;
  modelica_boolean tmp29;
  modelica_real tmp30;
  modelica_boolean tmp31;
  modelica_real tmp32;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  tmp23 = Greater(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)) + (-2.0) * ((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  tmp31 = (modelica_boolean)tmp23;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  if(tmp31)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp32 = (data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp24 = Less(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)) + (-2.0) * ((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)),(-(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */)));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp29 = (modelica_boolean)tmp24;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    if(tmp29)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp30 = 0.0;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp25 = Greater((data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),0.0);
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp27 = (modelica_boolean)tmp25;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      if(tmp27)
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp26 = DIVISION_SIM(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow",equationIndexes) + -2.0;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp28 = (0.25) * (((2.0 - (DIVISION_SIM(fabs((data->localData[0]->realVars[28] /* fan.VMachine_flow variable */)),(data->simulationInfo->realParameter[202] /* fan.heaDis.delta_V_flow PARAM */),"fan.heaDis.delta_V_flow",equationIndexes))) * ((tmp26 * tmp26) - 3.0)) * ((data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */))) + (0.5) * ((data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      else
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      {
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
        tmp28 = (0.5) * ((data->localData[0]->realVars[41] /* fan.heaDis.QThe_flow variable */));
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp30 = tmp28;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp32 = tmp30;
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 62 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  (data->localData[0]->realVars[27] /* fan.PToMed.u1 variable */) = tmp32;
#line 651 OMC_FILE
  TRACE_POP
}
/*
equation index: 273
type: SIMPLE_ASSIGN
fan.prePow.Q_flow = fan.PToMed.u1 + fan.eff.WFlo
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[47] /* fan.prePow.Q_flow variable */) = (data->localData[0]->realVars[27] /* fan.PToMed.u1 variable */) + (data->localData[0]->realVars[32] /* fan.eff.WFlo variable */);
#line 665 OMC_FILE
  TRACE_POP
}
/*
equation index: 274
type: SIMPLE_ASSIGN
fan.heaDis.etaHyd = fan.eff.WFlo / smooth(1, if noEvent(-1e-05 + fan.eff.P_internal > 1e-06) then fan.eff.P_internal else if noEvent(-1e-05 + fan.eff.P_internal < -1e-06) then 1e-05 else 0.25 * (-10.0 + 1000000.0 * fan.eff.P_internal) * ((-10.0 + 1000000.0 * fan.eff.P_internal) ^ 2.0 - 3.0) * (1e-05 - fan.eff.P_internal) + 0.5 * fan.eff.P_internal + 5e-06)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  modelica_real tmp35;
  modelica_boolean tmp36;
  modelica_real tmp37;
  modelica_boolean tmp38;
  modelica_real tmp39;
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  tmp33 = Greater(-1e-05 + (data->localData[0]->realVars[31] /* fan.eff.P_internal variable */),1e-06);
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  tmp38 = (modelica_boolean)tmp33;
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  if(tmp38)
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp39 = (data->localData[0]->realVars[31] /* fan.eff.P_internal variable */);
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  else
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  {
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp34 = Less(-1e-05 + (data->localData[0]->realVars[31] /* fan.eff.P_internal variable */),-1e-06);
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp36 = (modelica_boolean)tmp34;
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    if(tmp36)
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp37 = 1e-05;
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    else
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    {
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp35 = -10.0 + (1000000.0) * ((data->localData[0]->realVars[31] /* fan.eff.P_internal variable */));
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
      tmp37 = (0.25) * (((-10.0 + (1000000.0) * ((data->localData[0]->realVars[31] /* fan.eff.P_internal variable */))) * ((tmp35 * tmp35) - 3.0)) * (1e-05 - (data->localData[0]->realVars[31] /* fan.eff.P_internal variable */))) + (0.5) * ((data->localData[0]->realVars[31] /* fan.eff.P_internal variable */)) + 5e-06;
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    }
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
    tmp39 = tmp37;
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  }
#line 56 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PowerInterface.mo"
  (data->localData[0]->realVars[42] /* fan.heaDis.etaHyd variable */) = DIVISION_SIM((data->localData[0]->realVars[32] /* fan.eff.WFlo variable */),tmp39,"smooth(1, if noEvent(-1e-05 + fan.eff.P_internal > 1e-06) then fan.eff.P_internal else if noEvent(-1e-05 + fan.eff.P_internal < -1e-06) then 1e-05 else 0.25 * (-10.0 + 1000000.0 * fan.eff.P_internal) * ((-10.0 + 1000000.0 * fan.eff.P_internal) ^ 2.0 - 3.0) * (1e-05 - fan.eff.P_internal) + 0.5 * fan.eff.P_internal + 5e-06)",equationIndexes);
#line 728 OMC_FILE
  TRACE_POP
}
/*
equation index: 275
type: SIMPLE_ASSIGN
fan.dpMachine = fan.port_b.p - fan.port_a.p
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
#line 76 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
  (data->localData[0]->realVars[30] /* fan.dpMachine variable */) = (data->localData[0]->realVars[46] /* fan.port_b.p variable */) - (data->localData[0]->realVars[45] /* fan.port_a.p variable */);
#line 742 OMC_FILE
  TRACE_POP
}
/*
equation index: 276
type: SIMPLE_ASSIGN
fan.dp = fan.port_b.p - fan.dpMachine - fan.port_a.p - fan.senRelPre.p_rel
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,276};
  (data->localData[0]->realVars[29] /* fan.dp variable */) = (data->localData[0]->realVars[46] /* fan.port_b.p variable */) - (data->localData[0]->realVars[30] /* fan.dpMachine variable */) - (data->localData[0]->realVars[45] /* fan.port_a.p variable */) - (data->localData[0]->realVars[52] /* fan.senRelPre.p_rel variable */);
  TRACE_POP
}
/*
equation index: 277
type: ALGORITHM

  $cse8 := Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hea.outCon.Medium.setState_pTX(fan.port_a.p, Tsup, {});
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
  base_array_t tmp40;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hea_outCon_Medium_ThermodynamicState tmp41;
  simple_alloc_1d_base_array(&tmp40, 0, NULL);
  tmp41 = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hea_outCon_Medium_setState__pTX(threadData, (data->localData[0]->realVars[45] /* fan.port_a.p variable */), (data->localData[0]->realVars[22] /* Tsup variable */), tmp40);
  (data->localData[0]->realVars[16] /* $cse8.p variable */) = tmp41._p;
  (data->localData[0]->realVars[15] /* $cse8.T variable */) = tmp41._T;
  ;
  TRACE_POP
}
/*
equation index: 278
type: SIMPLE_ASSIGN
hea.outCon.hSet = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hea.outCon.Medium.specificEnthalpy($cse8)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hea_outCon_Medium_ThermodynamicState tmp42;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hea_outCon_Medium_ThermodynamicState_wrap_vars(threadData,tmp42, (data->localData[0]->realVars[16] /* $cse8.p variable */), (data->localData[0]->realVars[15] /* $cse8.T variable */));
  (data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hea_outCon_Medium_specificEnthalpy(threadData, tmp42);
  TRACE_POP
}
/*
equation index: 279
type: SIMPLE_ASSIGN
hea.outCon.mNor_flow = fluPor[1].m_flow / hea.outCon.m_flow_nominal
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
#line 173 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[78] /* hea.outCon.mNor_flow variable */) = DIVISION_SIM((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(data->simulationInfo->realParameter[317] /* hea.outCon.m_flow_nominal PARAM */),"hea.outCon.m_flow_nominal",equationIndexes);
#line 801 OMC_FILE
  TRACE_POP
}
/*
equation index: 280
type: SIMPLE_ASSIGN
hea.outCon.k = Modelica.Fluid.Utilities.regStep(fluPor[1].m_flow, hea.outCon.mNor_flow, -hea.outCon.mNor_flow, hea.outCon.m_flow_small)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  (data->localData[0]->realVars[77] /* hea.outCon.k variable */) = omc_Modelica_Fluid_Utilities_regStep(threadData, (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), (data->localData[0]->realVars[78] /* hea.outCon.mNor_flow variable */), (-(data->localData[0]->realVars[78] /* hea.outCon.mNor_flow variable */)), (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */));
  TRACE_POP
}
/*
equation index: 281
type: SIMPLE_ASSIGN
hea.outCon.m_flow_pos = smooth(1, if noEvent(fluPor[1].m_flow > hea.outCon.m_flow_small) then fluPor[1].m_flow else if noEvent(fluPor[1].m_flow < (-hea.outCon.m_flow_small)) then 0.0 else if noEvent(hea.outCon.m_flow_small > 0.0) then 0.25 * (3.0 - (fluPor[1].m_flow / hea.outCon.m_flow_small) ^ 2.0) * fluPor[1].m_flow ^ 2.0 / hea.outCon.m_flow_small + 0.5 * fluPor[1].m_flow else 0.5 * fluPor[1].m_flow)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
  modelica_boolean tmp43;
  modelica_boolean tmp44;
  modelica_boolean tmp45;
  modelica_real tmp46;
  modelica_real tmp47;
  modelica_boolean tmp48;
  modelica_real tmp49;
  modelica_boolean tmp50;
  modelica_real tmp51;
  modelica_boolean tmp52;
  modelica_real tmp53;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp43 = Greater((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */));
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp52 = (modelica_boolean)tmp43;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  if(tmp52)
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp53 = (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  else
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp44 = Less((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(-(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */)));
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp50 = (modelica_boolean)tmp44;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    if(tmp50)
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp51 = 0.0;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    else
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp45 = Greater((data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),0.0);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp48 = (modelica_boolean)tmp45;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      if(tmp48)
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp46 = DIVISION_SIM((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),"hea.outCon.m_flow_small",equationIndexes);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp47 = (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */);
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp49 = (0.25) * (DIVISION_SIM((3.0 - ((tmp46 * tmp46))) * ((tmp47 * tmp47)),(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),"hea.outCon.m_flow_small",equationIndexes)) + (0.5) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */));
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      else
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp49 = (0.5) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */));
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp51 = tmp49;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp53 = tmp51;
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 205 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[81] /* hea.outCon.m_flow_pos variable */) = tmp53;
#line 902 OMC_FILE
  TRACE_POP
}
/*
equation index: 282
type: SIMPLE_ASSIGN
hea.outCon.m_flow_non_zero = smooth(1, if noEvent(fluPor[1].m_flow - hea.outCon.m_flow_small > 0.5 * hea.outCon.m_flow_small) then fluPor[1].m_flow else if noEvent(fluPor[1].m_flow - hea.outCon.m_flow_small < (-0.5) * hea.outCon.m_flow_small) then hea.outCon.m_flow_small else if noEvent(0.5 * hea.outCon.m_flow_small > 0.0) then 0.25 * (4.0 * ((fluPor[1].m_flow - hea.outCon.m_flow_small) / hea.outCon.m_flow_small) ^ 2.0 - 3.0) * 2.0 * (fluPor[1].m_flow - hea.outCon.m_flow_small) / hea.outCon.m_flow_small * (hea.outCon.m_flow_small - fluPor[1].m_flow) + 0.5 * (fluPor[1].m_flow + hea.outCon.m_flow_small) else 0.5 * (fluPor[1].m_flow + hea.outCon.m_flow_small))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  modelica_boolean tmp56;
  modelica_real tmp57;
  modelica_boolean tmp58;
  modelica_real tmp59;
  modelica_boolean tmp60;
  modelica_real tmp61;
  modelica_boolean tmp62;
  modelica_real tmp63;
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp54 = Greater((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) - (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),(0.5) * ((data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */)));
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp62 = (modelica_boolean)tmp54;
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  if(tmp62)
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp63 = (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */);
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  else
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp55 = Less((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) - (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),(-0.5) * ((data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */)));
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp60 = (modelica_boolean)tmp55;
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    if(tmp60)
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp61 = (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */);
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    else
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp56 = Greater((0.5) * ((data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */)),0.0);
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp58 = (modelica_boolean)tmp56;
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      if(tmp58)
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp57 = DIVISION_SIM((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) - (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),"hea.outCon.m_flow_small",equationIndexes);
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp59 = (0.25) * ((DIVISION_SIM(((4.0) * ((tmp57 * tmp57)) - 3.0) * ((2.0) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) - (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */))),(data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */),"hea.outCon.m_flow_small",equationIndexes)) * ((data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */) - (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */))) + (0.5) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) + (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */));
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      else
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp59 = (0.5) * ((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */) + (data->simulationInfo->realParameter[318] /* hea.outCon.m_flow_small PARAM */));
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp61 = tmp59;
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp63 = tmp61;
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 214 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[80] /* hea.outCon.m_flow_non_zero variable */) = tmp63;
#line 988 OMC_FILE
  TRACE_POP
}
/*
equation index: 283
type: SIMPLE_ASSIGN
$cse9 = max(-fluPor[2].m_flow, 1e-07)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  (data->localData[0]->realVars[17] /* $cse9 variable */) = fmax((-(data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */)),1e-07);
  TRACE_POP
}
/*
equation index: 284
type: SIMPLE_ASSIGN
fan.filter.y = -fluPor[2].m_flow
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  (data->localData[0]->realVars[40] /* fan.filter.y variable */) = (-(data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */));
  TRACE_POP
}
/*
equation index: 285
type: SIMPLE_ASSIGN
fan.filter.x[1] = fan.filter.u_nom * fan.filter.s[1]
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
#line 25 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[39] /* fan.filter.x[1] variable */) = ((data->simulationInfo->realParameter[195] /* fan.filter.u_nom PARAM */)) * ((data->localData[0]->realVars[0] /* fan.filter.s[1] STATE(1) */));
#line 1026 OMC_FILE
  TRACE_POP
}
/*
equation index: 286
type: SIMPLE_ASSIGN
$DER.fan.filter.s[1] = (ovePum - fan.filter.x[1]) * fan.filter.w_u
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
#line 50 "/home/marius/modelica-buildings/Buildings/Fluid/BaseClasses/ActuatorFilter.mo"
  (data->localData[0]->realVars[2] /* der(fan.filter.s[1]) STATE_DER */) = ((data->localData[0]->realVars[91] /* ovePum variable */) - (data->localData[0]->realVars[39] /* fan.filter.x[1] variable */)) * ((data->simulationInfo->realParameter[197] /* fan.filter.w_u PARAM */));
#line 1040 OMC_FILE
  TRACE_POP
}
/*
equation index: 287
type: ALGORITHM

  $cse7 := Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hvacAda.bou.Medium.setState_pTX(bou.p, fluPor[1].backward.T, {hvacAda.bou.X[1]});
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  real_array tmp64;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_bou_Medium_ThermodynamicState tmp65;
  array_alloc_scalar_real_array(&tmp64, 1, (modelica_real)(data->simulationInfo->realParameter[338] /* hvacAda.bou.X[1] PARAM */));
  tmp65 = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_bou_Medium_setState__pTX(threadData, (data->simulationInfo->realParameter[16] /* bou.p PARAM */), (data->localData[0]->realVars[64] /* fluPor[1].backward.T variable */), tmp64);
  (data->localData[0]->realVars[14] /* $cse7.p variable */) = tmp65._p;
  (data->localData[0]->realVars[13] /* $cse7.T variable */) = tmp65._T;
  ;
  TRACE_POP
}
/*
equation index: 288
type: SIMPLE_ASSIGN
hvacAda.ports[1].h_outflow = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hvacAda.bou.Medium.specificEnthalpy($cse7)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_bou_Medium_ThermodynamicState tmp66;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_bou_Medium_ThermodynamicState_wrap_vars(threadData,tmp66, (data->localData[0]->realVars[14] /* $cse7.p variable */), (data->localData[0]->realVars[13] /* $cse7.T variable */));
  (data->localData[0]->realVars[90] /* hvacAda.ports[1].h_outflow variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_bou_Medium_specificEnthalpy(threadData, tmp66);
  TRACE_POP
}
/*
equation index: 289
type: ALGORITHM

  $cse1 := Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.bou.Medium.setState_pTX(bou.p, bou.T, {bou.X[1]});
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  real_array tmp67;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_bou_Medium_ThermodynamicState tmp68;
  array_alloc_scalar_real_array(&tmp67, 1, (modelica_real)(data->simulationInfo->realParameter[15] /* bou.X[1] PARAM */));
  tmp68 = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_bou_Medium_setState__pTX(threadData, (data->simulationInfo->realParameter[16] /* bou.p PARAM */), (data->simulationInfo->realParameter[13] /* bou.T PARAM */), tmp67);
  (data->localData[0]->realVars[5] /* $cse1.p variable */) = tmp68._p;
  (data->localData[0]->realVars[4] /* $cse1.T variable */) = tmp68._T;
  ;
  TRACE_POP
}
/*
equation index: 290
type: SIMPLE_ASSIGN
bou.ports[1].h_outflow = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.bou.Medium.specificEnthalpy($cse1)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_bou_Medium_ThermodynamicState tmp69;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_bou_Medium_ThermodynamicState_wrap_vars(threadData,tmp69, (data->localData[0]->realVars[5] /* $cse1.p variable */), (data->localData[0]->realVars[4] /* $cse1.T variable */));
  (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_bou_Medium_specificEnthalpy(threadData, tmp69);
  TRACE_POP
}
/*
equation index: 291
type: SIMPLE_ASSIGN
fluPor[2].forward.T = if fluPor[2].m_flow >= 0.0 then Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hvacAda.con.Medium.temperature_phX(300000.0, bou.ports[1].h_outflow, {1.0}) else 293.15
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
  modelica_boolean tmp70;
  relationhysteresis(data, &tmp70, (data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */), 0.0, 0, GreaterEq, GreaterEqZC);
  (data->localData[0]->realVars[67] /* fluPor[2].forward.T variable */) = (tmp70?omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_con_Medium_temperature__phX(threadData, 300000.0, (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */), _OMC_LIT9):293.15);
  TRACE_POP
}
/*
equation index: 292
type: SIMPLE_ASSIGN
hea.outCon.dhAct = smooth(1, if noEvent(hea.outCon.hSet - bou.ports[1].h_outflow > hea.outCon.deltaH) then hea.outCon.hSet - bou.ports[1].h_outflow else if noEvent(hea.outCon.hSet - bou.ports[1].h_outflow < (-hea.outCon.deltaH)) then 0.0 else if noEvent(hea.outCon.deltaH > 0.0) then 0.25 * (((hea.outCon.hSet - bou.ports[1].h_outflow) / hea.outCon.deltaH) ^ 2.0 - 3.0) * (bou.ports[1].h_outflow - hea.outCon.hSet) / hea.outCon.deltaH * (hea.outCon.hSet - bou.ports[1].h_outflow) + 0.5 * (hea.outCon.hSet - bou.ports[1].h_outflow) else 0.5 * (hea.outCon.hSet - bou.ports[1].h_outflow))
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  modelica_boolean tmp71;
  modelica_boolean tmp72;
  modelica_boolean tmp73;
  modelica_real tmp74;
  modelica_boolean tmp75;
  modelica_real tmp76;
  modelica_boolean tmp77;
  modelica_real tmp78;
  modelica_boolean tmp79;
  modelica_real tmp80;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp71 = Greater((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */));
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  tmp79 = (modelica_boolean)tmp71;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  if(tmp79)
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp80 = (data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */);
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  else
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp72 = Less((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),(-(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */)));
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp77 = (modelica_boolean)tmp72;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    if(tmp77)
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp78 = 0.0;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    else
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp73 = Greater((data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */),0.0);
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp75 = (modelica_boolean)tmp73;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      if(tmp75)
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp74 = DIVISION_SIM((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */),(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */),"hea.outCon.deltaH",equationIndexes);
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp76 = (0.25) * ((DIVISION_SIM(((tmp74 * tmp74) - 3.0) * ((data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */) - (data->localData[0]->realVars[76] /* hea.outCon.hSet variable */)),(data->simulationInfo->realParameter[313] /* hea.outCon.deltaH PARAM */),"hea.outCon.deltaH",equationIndexes)) * ((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */))) + (0.5) * ((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */));
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      else
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      {
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
        tmp76 = (0.5) * ((data->localData[0]->realVars[76] /* hea.outCon.hSet variable */) - (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */));
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
      tmp78 = tmp76;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
    tmp80 = tmp78;
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  }
#line 288 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[74] /* hea.outCon.dhAct variable */) = tmp80;
#line 1206 OMC_FILE
  TRACE_POP
}
/*
equation index: 293
type: SIMPLE_ASSIGN
y = hea.outCon.m_flow_pos * hea.outCon.dhAct
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
#line 294 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[94] /* y variable */) = ((data->localData[0]->realVars[81] /* hea.outCon.m_flow_pos variable */)) * ((data->localData[0]->realVars[74] /* hea.outCon.dhAct variable */));
#line 1220 OMC_FILE
  TRACE_POP
}
/*
equation index: 294
type: SIMPLE_ASSIGN
hea.port_a.h_outflow = bou.ports[1].h_outflow + hea.outCon.dhAct
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
#line 293 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PrescribedOutlet.mo"
  (data->localData[0]->realVars[82] /* hea.port_a.h_outflow variable */) = (data->localData[0]->realVars[25] /* bou.ports[1].h_outflow variable */) + (data->localData[0]->realVars[74] /* hea.outCon.dhAct variable */);
#line 1234 OMC_FILE
  TRACE_POP
}
/*
equation index: 295
type: SIMPLE_ASSIGN
fan.vol.ports[2].h_outflow = hea.port_a.h_outflow + fan.prePow.Q_flow * fan.vol.steBal.m_flowInv
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
#line 209 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  (data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */) = (data->localData[0]->realVars[82] /* hea.port_a.h_outflow variable */) + ((data->localData[0]->realVars[47] /* fan.prePow.Q_flow variable */)) * ((data->localData[0]->realVars[62] /* fan.vol.steBal.m_flowInv variable */));
#line 1248 OMC_FILE
  TRACE_POP
}
/*
equation index: 296
type: SIMPLE_ASSIGN
resSup.port_b.h_outflow = $cse9 * fan.vol.ports[2].h_outflow / (1e-07 + $cse9)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
#line 428 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/BaseClasses/PartialFlowMachine.mo"
  (data->localData[0]->realVars[93] /* resSup.port_b.h_outflow variable */) = ((data->localData[0]->realVars[17] /* $cse9 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */),1e-07 + (data->localData[0]->realVars[17] /* $cse9 variable */),"1e-07 + $cse9",equationIndexes));
#line 1262 OMC_FILE
  TRACE_POP
}
/*
equation index: 297
type: SIMPLE_ASSIGN
fluPor[1].forward.T = if fluPor[1].m_flow >= 0.0 then Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.hvacAda.con.Medium.temperature_phX(300000.0, resSup.port_b.h_outflow, {1.0}) else 293.15
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  modelica_boolean tmp81;
  relationhysteresis(data, &tmp81, (data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), 0.0, 1, GreaterEq, GreaterEqZC);
  (data->localData[0]->realVars[66] /* fluPor[1].forward.T variable */) = (tmp81?omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_hvacAda_con_Medium_temperature__phX(threadData, 300000.0, (data->localData[0]->realVars[93] /* resSup.port_b.h_outflow variable */), _OMC_LIT9):293.15);
  TRACE_POP
}
/*
equation index: 298
type: ALGORITHM

  $cse6 := Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.setState_phX(fan.port_b.p, fan.vol.ports[2].h_outflow, {});
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  base_array_t tmp82;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_ThermodynamicState tmp83;
  simple_alloc_1d_base_array(&tmp82, 0, NULL);
  tmp83 = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_setState__phX(threadData, (data->localData[0]->realVars[46] /* fan.port_b.p variable */), (data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */), tmp82);
  (data->localData[0]->realVars[12] /* $cse6.p variable */) = tmp83._p;
  (data->localData[0]->realVars[11] /* $cse6.T variable */) = tmp83._T;
  ;
  TRACE_POP
}
/*
equation index: 299
type: SIMPLE_ASSIGN
$cse5 = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.density($cse6)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_ThermodynamicState tmp84;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_ThermodynamicState_wrap_vars(threadData,tmp84, (data->localData[0]->realVars[12] /* $cse6.p variable */), (data->localData[0]->realVars[11] /* $cse6.T variable */));
  (data->localData[0]->realVars[10] /* $cse5 variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_density(threadData, tmp84);
  TRACE_POP
}
/*
equation index: 300
type: SIMPLE_ASSIGN
fan.heatPort.T = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.vol.Medium.temperature_phX(fan.port_a.p, fan.vol.ports[2].h_outflow, {1.0})
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  (data->localData[0]->realVars[44] /* fan.heatPort.T variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_vol_Medium_temperature__phX(threadData, (data->localData[0]->realVars[45] /* fan.port_a.p variable */), (data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */), _OMC_LIT9);
  TRACE_POP
}
/*
equation index: 301
type: ALGORITHM

  $cse4 := Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.setState_phX(fan.port_a.p, fan.vol.ports[2].h_outflow, {});
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  base_array_t tmp85;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_ThermodynamicState tmp86;
  simple_alloc_1d_base_array(&tmp85, 0, NULL);
  tmp86 = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_setState__phX(threadData, (data->localData[0]->realVars[45] /* fan.port_a.p variable */), (data->localData[0]->realVars[59] /* fan.vol.ports[2].h_outflow variable */), tmp85);
  (data->localData[0]->realVars[9] /* $cse4.p variable */) = tmp86._p;
  (data->localData[0]->realVars[8] /* $cse4.T variable */) = tmp86._T;
  ;
  TRACE_POP
}
/*
equation index: 302
type: SIMPLE_ASSIGN
$cse3 = Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit.fan.preSou.Medium.density($cse4)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_ThermodynamicState tmp87;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_ThermodynamicState_wrap_vars(threadData,tmp87, (data->localData[0]->realVars[9] /* $cse4.p variable */), (data->localData[0]->realVars[8] /* $cse4.T variable */));
  (data->localData[0]->realVars[7] /* $cse3 variable */) = omc_Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_fan_preSou_Medium_density(threadData, tmp87);
  TRACE_POP
}
/*
equation index: 303
type: SIMPLE_ASSIGN
$cse2 = Modelica.Fluid.Utilities.regStep(-fluPor[2].m_flow, $cse3, $cse5, fan.preSou.m_flow_small)
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  (data->localData[0]->realVars[6] /* $cse2 variable */) = omc_Modelica_Fluid_Utilities_regStep(threadData, (-(data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */)), (data->localData[0]->realVars[7] /* $cse3 variable */), (data->localData[0]->realVars[10] /* $cse5 variable */), (data->simulationInfo->realParameter[258] /* fan.preSou.m_flow_small PARAM */));
  TRACE_POP
}
/*
equation index: 304
type: SIMPLE_ASSIGN
fan.preSou.V_flow = (-fluPor[2].m_flow) / $cse2
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
#line 40 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
  (data->localData[0]->realVars[48] /* fan.preSou.V_flow variable */) = DIVISION_SIM((-(data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */)),(data->localData[0]->realVars[6] /* $cse2 variable */),"$cse2",equationIndexes);
#line 1380 OMC_FILE
  TRACE_POP
}
/*
equation index: 305
type: SIMPLE_ASSIGN
QGaiLat_flow = zero.k
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  (data->localData[0]->realVars[18] /* QGaiLat_flow variable */) = (data->simulationInfo->realParameter[372] /* zero.k PARAM */);
  TRACE_POP
}
/*
equation index: 306
type: SIMPLE_ASSIGN
QGaiSenCon_flow = zero.k
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  (data->localData[0]->realVars[20] /* QGaiSenCon_flow variable */) = (data->simulationInfo->realParameter[372] /* zero.k PARAM */);
  TRACE_POP
}
/*
equation index: 307
type: SIMPLE_ASSIGN
QGaiRad_flow = zero.k
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
  (data->localData[0]->realVars[19] /* QGaiRad_flow variable */) = (data->simulationInfo->realParameter[372] /* zero.k PARAM */);
  TRACE_POP
}
/*
equation index: 311
type: ALGORITHM

  assert(noEvent(abs(fan.prePow.Q_flow) < 836800.0 * max(0.001 * fan.vol.steBal.m_flow_small, abs(fluPor[1].m_flow))), "In PumpCircuit.fan.vol.steBal:
   The heat flow rate equals " + String(fan.prePow.Q_flow, 6, 0, true) + " W and the mass flow rate equals " + String(fluPor[1].m_flow, 6, 0, true) + " kg/s,
   which results in a temperature difference " + String(abs(fan.prePow.Q_flow) / (4184.0 * max(0.001 * fan.vol.steBal.m_flow_small, abs(fluPor[1].m_flow))), 6, 0, true) + " K > dTMax=" + String(200.0, 6, 0, true) + " K.
   This may indicate that energy is not conserved for small mass flow rates.
   The implementation may require prescribedHeatFlowRate = false.");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  modelica_boolean tmp88;
  static const MMC_DEFSTRINGLIT(tmp89,60,"In PumpCircuit.fan.vol.steBal:\n   The heat flow rate equals ");
  modelica_string tmp90;
  modelica_metatype tmpMeta91;
  static const MMC_DEFSTRINGLIT(tmp92,33," W and the mass flow rate equals ");
  modelica_metatype tmpMeta93;
  modelica_string tmp94;
  modelica_metatype tmpMeta95;
  static const MMC_DEFSTRINGLIT(tmp96,52," kg/s,\n   which results in a temperature difference ");
  modelica_metatype tmpMeta97;
  modelica_string tmp98;
  modelica_metatype tmpMeta99;
  static const MMC_DEFSTRINGLIT(tmp100,11," K > dTMax=");
  modelica_metatype tmpMeta101;
  modelica_string tmp102;
  modelica_metatype tmpMeta103;
  static const MMC_DEFSTRINGLIT(tmp104,146," K.\n   This may indicate that energy is not conserved for small mass flow rates.\n   The implementation may require prescribedHeatFlowRate = false.");
  modelica_metatype tmpMeta105;
  static int tmp106 = 0;
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  {
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    tmp88 = Less(fabs((data->localData[0]->realVars[47] /* fan.prePow.Q_flow variable */)),(836800.0) * (fmax((0.001) * ((data->simulationInfo->realParameter[294] /* fan.vol.steBal.m_flow_small PARAM */)),fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */)))));
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    if(!tmp88)
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    {
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp90 = modelica_real_to_modelica_string((data->localData[0]->realVars[47] /* fan.prePow.Q_flow variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmpMeta91 = stringAppend(MMC_REFSTRINGLIT(tmp89),tmp90);
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmpMeta93 = stringAppend(tmpMeta91,MMC_REFSTRINGLIT(tmp92));
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp94 = modelica_real_to_modelica_string((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmpMeta95 = stringAppend(tmpMeta93,tmp94);
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmpMeta97 = stringAppend(tmpMeta95,MMC_REFSTRINGLIT(tmp96));
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp98 = modelica_real_to_modelica_string(DIVISION_SIM(fabs((data->localData[0]->realVars[47] /* fan.prePow.Q_flow variable */)),(4184.0) * (fmax((0.001) * ((data->simulationInfo->realParameter[294] /* fan.vol.steBal.m_flow_small PARAM */)),fabs((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */)))),"4184.0 * max(0.001 * fan.vol.steBal.m_flow_small, abs(fluPor[1].m_flow))",equationIndexes), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmpMeta99 = stringAppend(tmpMeta97,tmp98);
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmpMeta101 = stringAppend(tmpMeta99,MMC_REFSTRINGLIT(tmp100));
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmp102 = modelica_real_to_modelica_string(200.0, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmpMeta103 = stringAppend(tmpMeta101,tmp102);
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      tmpMeta105 = stringAppend(tmpMeta103,MMC_REFSTRINGLIT(tmp104));
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      {
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
        const char* assert_cond = "(noEvent(abs(fan.prePow.Q_flow) < 836800.0 * max(0.001 * fan.vol.steBal.m_flow_small, abs(fluPor[1].m_flow))))";
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo",146,5,154,68,0};
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta105));
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
          data->simulationInfo->needToReThrow = 1;
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
        } else {
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo",146,5,154,68,0};
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta105));
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
        }
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
      }
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
    }
#line 146 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/StaticTwoPortConservationEquation.mo"
  }
#line 1510 OMC_FILE
  TRACE_POP
}
/*
equation index: 310
type: ALGORITHM

  assert(fluPor[1].m_flow > (-fan.vol.m_flow_small), "In PumpCircuit.fan.vol: Model has flow reversal,
  but the parameter allowFlowReversal is set to false.
  m_flow_small    = " + String(fan.vol.m_flow_small, 6, 0, true) + "
  ports[1].m_flow = " + String(fluPor[1].m_flow, 6, 0, true) + "
");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
  modelica_boolean tmp107;
  static const MMC_DEFSTRINGLIT(tmp108,124,"In PumpCircuit.fan.vol: Model has flow reversal,\n  but the parameter allowFlowReversal is set to false.\n  m_flow_small    = ");
  modelica_string tmp109;
  modelica_metatype tmpMeta110;
  static const MMC_DEFSTRINGLIT(tmp111,21,"\n  ports[1].m_flow = ");
  modelica_metatype tmpMeta112;
  modelica_string tmp113;
  modelica_metatype tmpMeta114;
  modelica_metatype tmpMeta115;
  static int tmp116 = 0;
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  {
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    tmp107 = Greater((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */),(-(data->simulationInfo->realParameter[274] /* fan.vol.m_flow_small PARAM */)));
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    if(!tmp107)
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    {
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp109 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[274] /* fan.vol.m_flow_small PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmpMeta110 = stringAppend(MMC_REFSTRINGLIT(tmp108),tmp109);
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmpMeta112 = stringAppend(tmpMeta110,MMC_REFSTRINGLIT(tmp111));
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmp113 = modelica_real_to_modelica_string((data->localData[0]->realVars[68] /* fluPor[1].m_flow variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmpMeta114 = stringAppend(tmpMeta112,tmp113);
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      tmpMeta115 = stringAppend(tmpMeta114,(modelica_string) mmc_strings_len1[10]);
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      {
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        const char* assert_cond = "(fluPor[1].m_flow > (-fan.vol.m_flow_small))";
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",134,5,139,3,0};
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta115));
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          data->simulationInfo->needToReThrow = 1;
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        } else {
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo",134,5,139,3,0};
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta115));
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
        }
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
      }
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
    }
#line 134 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  }
#line 1583 OMC_FILE
  TRACE_POP
}
/*
equation index: 309
type: ALGORITHM

  assert((-fluPor[2].m_flow) > (-fan.preSou.m_flow_small), "Reverting flow occurs even though allowFlowReversal is false");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  modelica_boolean tmp117;
  static const MMC_DEFSTRINGLIT(tmp118,60,"Reverting flow occurs even though allowFlowReversal is false");
  static int tmp119 = 0;
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
  {
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
    tmp117 = Greater((-(data->localData[0]->realVars[69] /* fluPor[2].m_flow variable */)),(-(data->simulationInfo->realParameter[258] /* fan.preSou.m_flow_small PARAM */)));
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
    if(!tmp117)
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
    {
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
      {
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
        const char* assert_cond = "((-fluPor[2].m_flow) > (-fan.preSou.m_flow_small))";
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo",80,3,81,70,0};
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp118)));
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
          data->simulationInfo->needToReThrow = 1;
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
        } else {
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo",80,3,81,70,0};
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp118)));
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
        }
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
      }
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
    }
#line 80 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/PartialTwoPortTransport.mo"
  }
#line 1633 OMC_FILE
  TRACE_POP
}
/*
equation index: 308
type: ALGORITHM

  assert((-fan.dp) <= 40000.0, "In PumpCircuit.fan: Model operates with head -dp = " + String(-fan.dp, 6, 0, true) + " Pa,
    exceeding the pressure allowed by the parameter " + "PumpCircuit.fan" + ".dpMax.
    This can happen if the model forces a high mass flow rate through a closed actuator,
    or if the performance record is unreasonable. Please verify your model, and
    consider using one of the other pump or fan models.");
*/
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
  modelica_boolean tmp120;
  static const MMC_DEFSTRINGLIT(tmp121,51,"In PumpCircuit.fan: Model operates with head -dp = ");
  modelica_string tmp122;
  modelica_metatype tmpMeta123;
  static const MMC_DEFSTRINGLIT(tmp124,57," Pa,\n    exceeding the pressure allowed by the parameter ");
  modelica_metatype tmpMeta125;
  static const MMC_DEFSTRINGLIT(tmp126,15,"PumpCircuit.fan");
  modelica_metatype tmpMeta127;
  static const MMC_DEFSTRINGLIT(tmp128,232,".dpMax.\n    This can happen if the model forces a high mass flow rate through a closed actuator,\n    or if the performance record is unreasonable. Please verify your model, and\n    consider using one of the other pump or fan models.");
  modelica_metatype tmpMeta129;
  static int tmp130 = 0;
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
  {
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
    tmp120 = LessEq((-(data->localData[0]->realVars[29] /* fan.dp variable */)),40000.0);
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
    if(!tmp120)
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
    {
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
      tmp122 = modelica_real_to_modelica_string((-(data->localData[0]->realVars[29] /* fan.dp variable */)), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
      tmpMeta123 = stringAppend(MMC_REFSTRINGLIT(tmp121),tmp122);
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
      tmpMeta125 = stringAppend(tmpMeta123,MMC_REFSTRINGLIT(tmp124));
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
      tmpMeta127 = stringAppend(tmpMeta125,MMC_REFSTRINGLIT(tmp126));
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
      tmpMeta129 = stringAppend(tmpMeta127,MMC_REFSTRINGLIT(tmp128));
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
      {
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
        const char* assert_cond = "((-fan.dp) <= 40000.0)";
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo",88,3,93,58,0};
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta129));
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
          data->simulationInfo->needToReThrow = 1;
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
        } else {
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo",88,3,93,58,0};
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta129));
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
        }
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
      }
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
    }
#line 88 "/home/marius/modelica-buildings/Buildings/Fluid/Movers/FlowControlled_m_flow.mo"
  }
#line 1705 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionLocalKnownVars(data, threadData);
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_250(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_251(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_252(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_254(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_255(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_256(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_257(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_258(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_259(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_260(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_261(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_262(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_263(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_264(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_265(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_266(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_267(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_268(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_269(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_270(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_271(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_272(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_273(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_274(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_275(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_276(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_277(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_278(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_279(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_280(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_281(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_282(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_283(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_284(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_285(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_286(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_287(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_288(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_289(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_290(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_291(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_292(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_293(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_294(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_295(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_296(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_297(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_298(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_299(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_300(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_301(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_302(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_303(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_304(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_305(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_306(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_307(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_311(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_310(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_309(data, threadData);

  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_308(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(DATA* data, threadData_t *threadData);
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_285(DATA* data, threadData_t *threadData);
extern void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_286(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  {
    Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_253(data, threadData);
    threadData->lastEquationSolved = 253;
  }
  {
    Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_285(data, threadData);
    threadData->lastEquationSolved = 285;
  }
  {
    Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_eqFunction_286(data, threadData);
    threadData->lastEquationSolved = 286;
  }
}

int Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_12jac.h"
#include "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initializeDAEmodeData,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionODE,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionAlgebraics,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionDAE,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionLocalKnownVars,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_input_function,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_input_function_init,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_input_function_updateStartValues,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_data_function,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_output_function,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_setc_function,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_setb_function,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_storeDelayed,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_storeSpatialDistribution,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_initSpatialDistribution,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_updateBoundVariableAttributes,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionInitialEquations_lambda0,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionRemovedInitialEquations,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_updateBoundParameters,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_checkForAsserts,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_ZeroCrossingsEquations,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_ZeroCrossings,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_updateRelations,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_zeroCrossingDescription,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_relationDescription,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_initSample,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_A,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_B,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_C,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_D,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_F,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_H,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianA,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianB,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianC,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianD,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianF,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianH,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacA_column,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacB_column,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacC_column,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacD_column,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacF_column,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacH_column,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_linear_model_frame,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_linear_model_datarecovery_frame,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_mayer,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_lagrange,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_pickUpBoundsForInputsInOptimization,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_setInputData,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_getTimeGrid,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_symbolicInlineSystem,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_initSynchronous,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_updateSynchronous,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_function_equationsSynchronous,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_inputNames,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_dataReconciliationInputNames,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_dataReconciliationUnmeasuredVariables,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_read_input_fmu,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_initialAnalyticJacobianFMIDER,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_functionJacFMIDER_column,
   Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_INDEX_JAC_FMIDER,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Buildings"
#define _OMC_LIT_RESOURCE_0_dir_data "/home/marius/modelica-buildings/Buildings"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,9,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,41,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Complex"
#define _OMC_LIT_RESOURCE_1_dir_data "/home/marius/.openmodelica/libraries/Complex 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,7,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,59,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,60,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_3_dir_data "/home/marius/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,16,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,68,_OMC_LIT_RESOURCE_3_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,8,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir)}};
void Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Buildings.Fluid.FMI.ExportContainers.Examples.FMUs.PumpCircuit";
  data->modelData->modelFilePrefix = "Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/marius/modelica-buildings/Buildings/Fluid/FMI/ExportContainers/Examples/FMUs";
  data->modelData->modelGUID = "{c7b75550-fe16-48a2-84ba-a9672a40f82e}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 2;
  data->modelData->nVariablesReal = 95;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 374;
  data->modelData->nParametersInteger = 31;
  data->modelData->nParametersBoolean = 93;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 5;
  data->modelData->nOutputVars = 8;
  
  data->modelData->nAliasReal = 165;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 2;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/Buildings_Fluid_FMI_ExportContainers_Examples_FMUs_PumpCircuit_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 42;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 981;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 7;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nBaseClocks = 0;
  
  data->modelData->nSpatialDistributions = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage =
  OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

