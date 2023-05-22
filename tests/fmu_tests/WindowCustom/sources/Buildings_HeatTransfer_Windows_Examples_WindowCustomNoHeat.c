#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WindowCustomNoHeat/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat.c"
#endif
/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  (data->localData[0]->realVars[0] /* QAbsSha_flow variable */) = data->simulationInfo->inputVars[0];
  (data->localData[0]->realVars[1] /* QAbsUns_flow variable */) = data->simulationInfo->inputVars[1];
  (data->localData[0]->realVars[2] /* QSolAbsExt_flow variable */) = data->simulationInfo->inputVars[2];
  (data->localData[0]->realVars[3] /* QSolAbsInt_flow variable */) = data->simulationInfo->inputVars[3];
  (data->localData[0]->realVars[4] /* TBlaSky variable */) = data->simulationInfo->inputVars[4];
  (data->localData[0]->realVars[5] /* TOut variable */) = data->simulationInfo->inputVars[5];
  (data->localData[0]->realVars[61] /* vWin variable */) = data->simulationInfo->inputVars[6];
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[0].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[1].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->realVarsData[2].attribute.start;
  data->simulationInfo->inputVars[3] = data->modelData->realVarsData[3].attribute.start;
  data->simulationInfo->inputVars[4] = data->modelData->realVarsData[4].attribute.start;
  data->simulationInfo->inputVars[5] = data->modelData->realVarsData[5].attribute.start;
  data->simulationInfo->inputVars[6] = data->modelData->realVarsData[61].attribute.start;
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[0].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[1].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->realVarsData[2].attribute.start = data->simulationInfo->inputVars[2];
  data->modelData->realVarsData[3].attribute.start = data->simulationInfo->inputVars[3];
  data->modelData->realVarsData[4].attribute.start = data->simulationInfo->inputVars[4];
  data->modelData->realVarsData[5].attribute.start = data->simulationInfo->inputVars[5];
  data->modelData->realVarsData[61].attribute.start = data->simulationInfo->inputVars[6];
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[0].info.name;
  names[1] = (char *) data->modelData->realVarsData[1].info.name;
  names[2] = (char *) data->modelData->realVarsData[2].info.name;
  names[3] = (char *) data->modelData->realVarsData[3].info.name;
  names[4] = (char *) data->modelData->realVarsData[4].info.name;
  names[5] = (char *) data->modelData->realVarsData[5].info.name;
  names[6] = (char *) data->modelData->realVarsData[61].info.name;
  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 112
type: SIMPLE_ASSIGN
uSha.y = if time < 0.25 then 0.0 else if time < 0.75 then 2.0 * time - 0.5 else 1.0
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, 0.25, 0, Less, LessZC);
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  tmp2 = (modelica_boolean)tmp0;
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  if(tmp2)
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  {
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp3 = 0.0;
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  }
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  else
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  {
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    relationhysteresis(data, &tmp1, data->localData[0]->timeValue, 0.75, 1, Less, LessZC);
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp3 = (tmp1?(2.0) * (data->localData[0]->timeValue) - 0.5:1.0);
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  }
#line 252 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[60] /* uSha.y variable */) = tmp3;
#line 173 OMC_FILE
  TRACE_POP
}
/*
equation index: 113
type: SIMPLE_ASSIGN
shaSig.yCom = 1.0 - (1e-06 + 0.9999980000000001 * uSha.y)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  (data->localData[0]->realVars[59] /* shaSig.yCom variable */) = 1.0 - (1e-06 + (0.9999980000000001) * ((data->localData[0]->realVars[60] /* uSha.y variable */)));
  TRACE_POP
}
/*
equation index: 114
type: SIMPLE_ASSIGN
shaSig.y = 1.0 - shaSig.yCom
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
#line 24 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadingSignal.mo"
  (data->localData[0]->realVars[58] /* shaSig.y variable */) = 1.0 - (data->localData[0]->realVars[59] /* shaSig.yCom variable */);
#line 199 OMC_FILE
  TRACE_POP
}
/*
equation index: 115
type: SIMPLE_ASSIGN
intShaCon.proSha.u2 = 1e-06 + 0.9999980000000001 * uSha.y
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
#line 23 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadingSignal.mo"
  (data->localData[0]->realVars[51] /* intShaCon.proSha.u2 variable */) = 1e-06 + (0.9999980000000001) * ((data->localData[0]->realVars[60] /* uSha.y variable */));
#line 213 OMC_FILE
  TRACE_POP
}
/*
equation index: 116
type: SIMPLE_ASSIGN
intShaCon.conSha.Gc = 3.2 * intShaCon.proSha.u2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
#line 976 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[44] /* intShaCon.conSha.Gc variable */) = (3.2) * ((data->localData[0]->realVars[51] /* intShaCon.proSha.u2 variable */));
#line 227 OMC_FILE
  TRACE_POP
}
/*
equation index: 117
type: SIMPLE_ASSIGN
intShaCon.conFra.u = 1.0 - intShaCon.proSha.u2
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
#line 24 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadingSignal.mo"
  (data->localData[0]->realVars[43] /* intShaCon.conFra.u variable */) = 1.0 - (data->localData[0]->realVars[51] /* intShaCon.proSha.u2 variable */);
#line 241 OMC_FILE
  TRACE_POP
}
/*
equation index: 118
type: SIMPLE_ASSIGN
extCon.radOut.TRad4 = 0.5 * (TBlaSky ^ 4.0 + TOut ^ 4.0)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  modelica_real tmp4;
  modelica_real tmp5;
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  tmp4 = (data->localData[0]->realVars[4] /* TBlaSky variable */);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  tmp4 *= tmp4;tmp5 = (data->localData[0]->realVars[5] /* TOut variable */);
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  tmp5 *= tmp5;
#line 39 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  (data->localData[0]->realVars[22] /* extCon.radOut.TRad4 variable */) = (0.5) * ((tmp4 * tmp4) + (tmp5 * tmp5));
#line 263 OMC_FILE
  TRACE_POP
}
/*
equation index: 119
type: SIMPLE_ASSIGN
extCon.radOut.TRad = 219.8625 + 9.923624282153128e-09 * extCon.radOut.TRad4
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
#line 41 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/OutdoorRadiosity.mo"
  (data->localData[0]->realVars[21] /* extCon.radOut.TRad variable */) = 219.8625 + (9.923624282153128e-09) * ((data->localData[0]->realVars[22] /* extCon.radOut.TRad4 variable */));
#line 277 OMC_FILE
  TRACE_POP
}
/*
equation index: 120
type: SIMPLE_ASSIGN
extCon.radOut.JOut = 4.571212498951346 * extCon.radOut.TRad - 1005.03820805069
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  (data->localData[0]->realVars[20] /* extCon.radOut.JOut variable */) = (4.571212498951346) * ((data->localData[0]->realVars[21] /* extCon.radOut.TRad variable */)) - 1005.03820805069;
  TRACE_POP
}
/*
equation index: 121
type: SIMPLE_ASSIGN
extCon.conCoeFra.GCon = 0.2 * (4.0 + 4.0 * smooth(1, if noEvent(2.0 * vWin > 0.1) then vWin else if noEvent(2.0 * vWin < -0.1) then -vWin else 0.25 * (-20.0) * vWin * (400.0 * vWin ^ 2.0 - 3.0) * 2.0 * vWin))
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_boolean tmp11;
  modelica_real tmp12;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp6 = Greater((2.0) * ((data->localData[0]->realVars[61] /* vWin variable */)),0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp11 = (modelica_boolean)tmp6;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  if(tmp11)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp12 = (data->localData[0]->realVars[61] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp7 = Less((2.0) * ((data->localData[0]->realVars[61] /* vWin variable */)),-0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp9 = (modelica_boolean)tmp7;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    if(tmp9)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp10 = (-(data->localData[0]->realVars[61] /* vWin variable */));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp8 = (data->localData[0]->realVars[61] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp10 = (0.25) * ((((-20.0) * ((data->localData[0]->realVars[61] /* vWin variable */))) * ((400.0) * ((tmp8 * tmp8)) - 3.0)) * ((2.0) * ((data->localData[0]->realVars[61] /* vWin variable */))));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp12 = tmp10;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  (data->localData[0]->realVars[13] /* extCon.conCoeFra.GCon variable */) = (0.2) * (4.0 + (4.0) * (tmp12));
#line 352 OMC_FILE
  TRACE_POP
}
/*
equation index: 122
type: SIMPLE_ASSIGN
extCon.conCoeGla.GCon = 0.8 * (4.0 + 4.0 * smooth(1, if noEvent(2.0 * vWin > 0.1) then vWin else if noEvent(2.0 * vWin < -0.1) then -vWin else 0.25 * (-20.0) * vWin * (400.0 * vWin ^ 2.0 - 3.0) * 2.0 * vWin))
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_real tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp13 = Greater((2.0) * ((data->localData[0]->realVars[61] /* vWin variable */)),0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  tmp18 = (modelica_boolean)tmp13;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  if(tmp18)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp19 = (data->localData[0]->realVars[61] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp14 = Less((2.0) * ((data->localData[0]->realVars[61] /* vWin variable */)),-0.1);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp16 = (modelica_boolean)tmp14;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    if(tmp16)
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp17 = (-(data->localData[0]->realVars[61] /* vWin variable */));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    else
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    {
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp15 = (data->localData[0]->realVars[61] /* vWin variable */);
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
      tmp17 = (0.25) * ((((-20.0) * ((data->localData[0]->realVars[61] /* vWin variable */))) * ((400.0) * ((tmp15 * tmp15)) - 3.0)) * ((2.0) * ((data->localData[0]->realVars[61] /* vWin variable */))));
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
    tmp19 = tmp17;
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  }
#line 14 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ExteriorConvectionCoefficient.mo"
  (data->localData[0]->realVars[14] /* extCon.conCoeGla.GCon variable */) = (0.8) * (4.0 + (4.0) * (tmp19));
#line 415 OMC_FILE
  TRACE_POP
}
/*
equation index: 123
type: SIMPLE_ASSIGN
extCon.shaSig.yCom = 1.0 - (1e-06 + 0.9999980000000001 * uSha.y)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  (data->localData[0]->realVars[31] /* extCon.shaSig.yCom variable */) = 1.0 - (1e-06 + (0.9999980000000001) * ((data->localData[0]->realVars[60] /* uSha.y variable */)));
  TRACE_POP
}
/*
equation index: 124
type: SIMPLE_ASSIGN
extCon.shaRad.u = 1.0 - extCon.shaSig.yCom
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
#line 24 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadingSignal.mo"
  (data->localData[0]->realVars[30] /* extCon.shaRad.u variable */) = 1.0 - (data->localData[0]->realVars[31] /* extCon.shaSig.yCom variable */);
#line 441 OMC_FILE
  TRACE_POP
}
/*
equation index: 125
type: SIMPLE_ASSIGN
extCon.JOutSha = extCon.shaRad.u * extCon.radOut.JOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
#line 19 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[11] /* extCon.JOutSha variable */) = ((data->localData[0]->realVars[30] /* extCon.shaRad.u variable */)) * ((data->localData[0]->realVars[20] /* extCon.radOut.JOut variable */));
#line 455 OMC_FILE
  TRACE_POP
}
/*
equation index: 126
type: SIMPLE_ASSIGN
extCon.JOutUns = (1.0 - extCon.shaRad.u) * extCon.radOut.JOut
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
#line 20 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/RadiositySplitter.mo"
  (data->localData[0]->realVars[12] /* extCon.JOutUns variable */) = (1.0 - (data->localData[0]->realVars[30] /* extCon.shaRad.u variable */)) * ((data->localData[0]->realVars[20] /* extCon.radOut.JOut variable */));
#line 469 OMC_FILE
  TRACE_POP
}
/*
equation index: 127
type: SIMPLE_ASSIGN
extCon.conWinUns.Gc = extCon.shaSig.yCom * extCon.conCoeGla.GCon
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
#line 976 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[16] /* extCon.conWinUns.Gc variable */) = ((data->localData[0]->realVars[31] /* extCon.shaSig.yCom variable */)) * ((data->localData[0]->realVars[14] /* extCon.conCoeGla.GCon variable */));
#line 483 OMC_FILE
  TRACE_POP
}
/*
equation index: 128
type: SIMPLE_ASSIGN
extCon.shaCon.Gc = extCon.conCoeGla.GCon * extCon.shaRad.u
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
#line 976 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[23] /* extCon.shaCon.Gc variable */) = ((data->localData[0]->realVars[14] /* extCon.conCoeGla.GCon variable */)) * ((data->localData[0]->realVars[30] /* extCon.shaRad.u variable */));
#line 497 OMC_FILE
  TRACE_POP
}
/*
equation index: 129
type: SIMPLE_ASSIGN
window.glaUns.u = 1.0 - (1e-06 + 0.9999980000000001 * uSha.y)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
  (data->localData[0]->realVars[77] /* window.glaUns.u variable */) = 1.0 - (1e-06 + (0.9999980000000001) * ((data->localData[0]->realVars[60] /* uSha.y variable */)));
  TRACE_POP
}
/*
equation index: 130
type: SIMPLE_ASSIGN
window.glaSha.u = 1.0 - window.glaUns.u
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
#line 24 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadingSignal.mo"
  (data->localData[0]->realVars[71] /* window.glaSha.u variable */) = 1.0 - (data->localData[0]->realVars[77] /* window.glaUns.u variable */);
#line 523 OMC_FILE
  TRACE_POP
}
/*
equation index: 143
type: LINEAR

<var>extCon.conFra.dT</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[15] /* extCon.conFra.dT variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 143 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 2, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,143};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 143 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[15] /* extCon.conFra.dT variable */) = aux_x[0];

  TRACE_POP
}
/*
equation index: 207
type: LINEAR

<var>window.glaUns_a.T</var>
<var>window.glaSha_a.T</var>
<var>indRad.JIn</var>
<var>intShaCon.TSha</var>
<var>intShaCon.glaSha.T</var>
<var>window.glaUns.glass[1].T4_b</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  /* Linear equation system */
  int retValue;
  double aux_x[6] = { (data->localData[1]->realVars[78] /* window.glaUns_a.T variable */),(data->localData[1]->realVars[72] /* window.glaSha_a.T variable */),(data->localData[1]->realVars[34] /* indRad.JIn variable */),(data->localData[1]->realVars[38] /* intShaCon.TSha variable */),(data->localData[1]->realVars[50] /* intShaCon.glaSha.T variable */),(data->localData[1]->realVars[76] /* window.glaUns.glass[1].T4_b variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 207 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 3, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,207};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 207 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[78] /* window.glaUns_a.T variable */) = aux_x[0];
  (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */) = aux_x[1];
  (data->localData[0]->realVars[34] /* indRad.JIn variable */) = aux_x[2];
  (data->localData[0]->realVars[38] /* intShaCon.TSha variable */) = aux_x[3];
  (data->localData[0]->realVars[50] /* intShaCon.glaSha.T variable */) = aux_x[4];
  (data->localData[0]->realVars[76] /* window.glaUns.glass[1].T4_b variable */) = aux_x[5];

  TRACE_POP
}
/*
equation index: 208
type: SIMPLE_ASSIGN
extCon.shaCon.TSha = 0.5 * (TOut + window.glaSha_a.T)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
#line 57 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/ShadeConvection.mo"
  (data->localData[0]->realVars[24] /* extCon.shaCon.TSha variable */) = (0.5) * ((data->localData[0]->realVars[5] /* TOut variable */) + (data->localData[0]->realVars[72] /* window.glaSha_a.T variable */));
#line 621 OMC_FILE
  TRACE_POP
}
/*
equation index: 209
type: SIMPLE_ASSIGN
fixedHeatFlow.port.T = 219.8625 - (-0.175008271915498) * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  (data->localData[0]->realVars[33] /* fixedHeatFlow.port.T variable */) = 219.8625 - ((-0.175008271915498) * ((data->localData[0]->realVars[34] /* indRad.JIn variable */)));
  TRACE_POP
}
/*
equation index: 210
type: SIMPLE_ASSIGN
indRad.T4 = 17635519.73952065 * indRad.JIn
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Radiosity/IndoorRadiosity.mo"
  (data->localData[0]->realVars[35] /* indRad.T4 variable */) = (17635519.73952065) * ((data->localData[0]->realVars[34] /* indRad.JIn variable */));
#line 647 OMC_FILE
  TRACE_POP
}
/*
equation index: 211
type: SIMPLE_ASSIGN
TRAir.port.Q_flow = intShaCon.conWinUns.Q_flow - (intShaCon.conSha.air.Q_flow - intShaCon.conFra.Q_flow)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[7] /* TRAir.port.Q_flow variable */) = (data->localData[0]->realVars[46] /* intShaCon.conWinUns.Q_flow variable */) - ((data->localData[0]->realVars[45] /* intShaCon.conSha.air.Q_flow variable */) - (data->localData[0]->realVars[40] /* intShaCon.conFra.Q_flow variable */));
#line 661 OMC_FILE
  TRACE_POP
}
/*
equation index: 212
type: SIMPLE_ASSIGN
TOuts.port.Q_flow = extCon.conWinUns.Q_flow - (intShaCon.conFra.Q_flow - extCon.glaSha.Q_flow)
*/
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[6] /* TOuts.port.Q_flow variable */) = (data->localData[0]->realVars[17] /* extCon.conWinUns.Q_flow variable */) - ((data->localData[0]->realVars[40] /* intShaCon.conFra.Q_flow variable */) - (data->localData[0]->realVars[19] /* extCon.glaSha.Q_flow variable */));
#line 675 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionLocalKnownVars(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_112(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_113(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_114(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_115(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_116(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_117(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_118(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_119(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_120(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_121(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_122(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_123(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_124(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_125(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_126(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_127(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_128(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_129(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_130(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_143(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_207(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_208(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_209(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_210(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_211(data, threadData);

  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_eqFunction_212(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_12jac.h"
#include "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialLinearSystem,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initializeDAEmodeData,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionODE,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionAlgebraics,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionDAE,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionLocalKnownVars,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_input_function,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_input_function_init,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_input_function_updateStartValues,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_data_function,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_output_function,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_setc_function,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_setb_function,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_storeDelayed,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_storeSpatialDistribution,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_initSpatialDistribution,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_updateBoundVariableAttributes,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionRemovedInitialEquations,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_updateBoundParameters,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_checkForAsserts,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_ZeroCrossingsEquations,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_ZeroCrossings,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_updateRelations,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_zeroCrossingDescription,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_relationDescription,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_initSample,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_A,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_B,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_C,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_D,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_F,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_H,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianA,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianB,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianC,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianD,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianF,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianH,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacA_column,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacB_column,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacC_column,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacD_column,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacF_column,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacH_column,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_linear_model_frame,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_linear_model_datarecovery_frame,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_mayer,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_lagrange,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_pickUpBoundsForInputsInOptimization,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_setInputData,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_getTimeGrid,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_symbolicInlineSystem,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_initSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_updateSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_function_equationsSynchronous,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_inputNames,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_dataReconciliationInputNames,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_dataReconciliationUnmeasuredVariables,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_read_input_fmu,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianFMIDER,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacFMIDER_column,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_FMIDER,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_initialAnalyticJacobianFMIDERINIT,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_functionJacFMIDERINIT_column,
   Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_INDEX_JAC_FMIDERINIT

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
void Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Buildings.HeatTransfer.Windows.Examples.WindowCustomNoHeat";
  data->modelData->modelFilePrefix = "Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/Examples";
  data->modelData->modelGUID = "{e56e7a70-0d14-432d-b989-74257136a85e}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 80;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 244;
  data->modelData->nParametersInteger = 10;
  data->modelData->nParametersBoolean = 53;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 7;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 158;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 2;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/Buildings_HeatTransfer_Windows_Examples_WindowCustomNoHeat_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 561;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 4;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 11;
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

