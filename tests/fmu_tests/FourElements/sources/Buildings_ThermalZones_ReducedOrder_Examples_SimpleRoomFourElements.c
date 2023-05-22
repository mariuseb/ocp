#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.c"
#endif
/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#include "simulation/solver/events.h"



/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 410
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.cloTim = time
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,410};
#line 9 "/home/marius/modelica-buildings/Buildings/Utilities/Time/ModelTime.mo"
  (data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */) = data->localData[0]->timeValue;
#line 119 OMC_FILE
  TRACE_POP
}
/*
equation index: 411
type: SIMPLE_ASSIGN
weaDat.add30Min.y = 1800.0 + HDifTil[1].weaBus.cloTim
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,411};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */) = 1800.0 + (data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */);
#line 133 OMC_FILE
  TRACE_POP
}
/*
equation index: 412
type: SIMPLE_ASSIGN
$whenCondition3 = weaDat.conTimMin.canRepeatWeatherFile and weaDat.add30Min.y > pre(weaDat.conTimMin.tNext)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_412(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,412};
  modelica_boolean tmp0;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  relationhysteresis(data, &tmp0, (data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */), (data->simulationInfo->realVarsPre[361] /* weaDat.conTimMin.tNext DISCRETE */), 1, Greater, GreaterZC);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */) = ((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) && tmp0);
#line 150 OMC_FILE
  TRACE_POP
}
/*
equation index: 413
type: WHEN

when {$whenCondition3} then
  weaDat.conTimMin.tNext = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.conTimMin.lenWea * (1.0 + (*Real*)(integer(weaDat.add30Min.y / weaDat.conTimMin.lenWea))) else time;
end when;
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,413};
  if(((data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */) /* edge */))
  {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    (data->localData[0]->realVars[361] /* weaDat.conTimMin.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[419] /* weaDat.conTimMin.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */),(data->simulationInfo->realParameter[419] /* weaDat.conTimMin.lenWea PARAM */),"weaDat.conTimMin.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 169 OMC_FILE
  }
  TRACE_POP
}
/*
equation index: 414
type: SIMPLE_ASSIGN
weaDat.conTimMin.calTim = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.add30Min.y - weaDat.conTimMin.tNext + weaDat.conTimMin.lenWea else weaDat.add30Min.y
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,414};
#line 38 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[320] /* weaDat.conTimMin.calTim variable */) = ((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?(data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */) - (data->localData[0]->realVars[361] /* weaDat.conTimMin.tNext DISCRETE */) + (data->simulationInfo->realParameter[419] /* weaDat.conTimMin.lenWea PARAM */):(data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */));
#line 184 OMC_FILE
  TRACE_POP
}
/*
equation index: 415
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[3] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 3, weaDat.conTimMin.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,415};
  (data->localData[0]->realVars[350] /* weaDat.datRea30Min.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 3), (data->localData[0]->realVars[320] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 416
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.HDifHor = max(0.0, weaDat.datRea30Min.y[3])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,416};
  (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */) = fmax(0.0,(data->localData[0]->realVars[350] /* weaDat.datRea30Min.y[3] variable */));
  TRACE_POP
}
/*
equation index: 417
type: SIMPLE_ASSIGN
HDifTil[1].skyCle.HDifHorBou = smooth(1, if noEvent(-5e-05 + HDifTil[1].weaBus.HDifHor > 2.5e-05) then HDifTil[1].weaBus.HDifHor else if noEvent(-5e-05 + HDifTil[1].weaBus.HDifHor < -2.5e-05) then 5e-05 else 0.25 * (-2.0 + 40000.0 * HDifTil[1].weaBus.HDifHor) * ((-2.0 + 40000.0 * HDifTil[1].weaBus.HDifHor) ^ 2.0 - 3.0) * (5e-05 - HDifTil[1].weaBus.HDifHor) + 0.5 * HDifTil[1].weaBus.HDifHor + 2.5e-05)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_417(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,417};
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  tmp1 = Greater(-5e-05 + (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */),2.5e-05);
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  tmp6 = (modelica_boolean)tmp1;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  if(tmp6)
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  {
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    tmp7 = (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */);
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  }
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  else
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  {
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    tmp2 = Less(-5e-05 + (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */),-2.5e-05);
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    tmp4 = (modelica_boolean)tmp2;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    if(tmp4)
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    {
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
      tmp5 = 5e-05;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    }
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    else
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    {
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
      tmp3 = -2.0 + (40000.0) * ((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */));
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
      tmp5 = (0.25) * (((-2.0 + (40000.0) * ((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */))) * ((tmp3 * tmp3) - 3.0)) * (5e-05 - (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */))) + (0.5) * ((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) + 2.5e-05;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    }
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    tmp7 = tmp5;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  }
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  (data->localData[0]->realVars[112] /* HDifTil[1].skyCle.HDifHorBou variable */) = tmp7;
#line 271 OMC_FILE
  TRACE_POP
}
/*
equation index: 418
type: SIMPLE_ASSIGN
HDifTil[2].skyCle.HDifHorBou = smooth(1, if noEvent(-5e-05 + HDifTil[1].weaBus.HDifHor > 2.5e-05) then HDifTil[1].weaBus.HDifHor else if noEvent(-5e-05 + HDifTil[1].weaBus.HDifHor < -2.5e-05) then 5e-05 else 0.25 * (-2.0 + 40000.0 * HDifTil[1].weaBus.HDifHor) * ((-2.0 + 40000.0 * HDifTil[1].weaBus.HDifHor) ^ 2.0 - 3.0) * (5e-05 - HDifTil[1].weaBus.HDifHor) + 0.5 * HDifTil[1].weaBus.HDifHor + 2.5e-05)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_418(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,418};
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_boolean tmp11;
  modelica_real tmp12;
  modelica_boolean tmp13;
  modelica_real tmp14;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  tmp8 = Greater(-5e-05 + (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */),2.5e-05);
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  tmp13 = (modelica_boolean)tmp8;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  if(tmp13)
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  {
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    tmp14 = (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */);
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  }
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  else
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  {
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    tmp9 = Less(-5e-05 + (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */),-2.5e-05);
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    tmp11 = (modelica_boolean)tmp9;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    if(tmp11)
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    {
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
      tmp12 = 5e-05;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    }
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    else
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    {
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
      tmp10 = -2.0 + (40000.0) * ((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */));
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
      tmp12 = (0.25) * (((-2.0 + (40000.0) * ((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */))) * ((tmp10 * tmp10) - 3.0)) * (5e-05 - (data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */))) + (0.5) * ((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) + 2.5e-05;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    }
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
    tmp14 = tmp12;
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  }
#line 33 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  (data->localData[0]->realVars[113] /* HDifTil[2].skyCle.HDifHorBou variable */) = tmp14;
#line 334 OMC_FILE
  TRACE_POP
}
/*
equation index: 419
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[2] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 2, weaDat.conTimMin.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,419};
  (data->localData[0]->realVars[349] /* weaDat.datRea30Min.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 2), (data->localData[0]->realVars[320] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 420
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.HDirNor = max(0.0, weaDat.datRea30Min.y[2])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_420(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,420};
  (data->localData[0]->realVars[119] /* HDifTil[1].weaBus.HDirNor variable */) = fmax(0.0,(data->localData[0]->realVars[349] /* weaDat.datRea30Min.y[2] variable */));
  TRACE_POP
}
/*
equation index: 421
type: SIMPLE_ASSIGN
weaDat.datRea30Min.y[1] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea30Min.tableID, 1, weaDat.conTimMin.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_421(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,421};
  (data->localData[0]->realVars[348] /* weaDat.datRea30Min.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 1), (data->localData[0]->realVars[320] /* weaDat.conTimMin.calTim variable */));
  TRACE_POP
}
/*
equation index: 422
type: SIMPLE_ASSIGN
HDirTil[2].weaBus.HGloHor = max(0.0, weaDat.datRea30Min.y[1])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,422};
  (data->localData[0]->realVars[153] /* HDirTil[2].weaBus.HGloHor variable */) = fmax(0.0,(data->localData[0]->realVars[348] /* weaDat.datRea30Min.y[1] variable */));
  TRACE_POP
}
/*
equation index: 423
type: SIMPLE_ASSIGN
HDifTil[1].HGroDifTil = 0.1000000000000004 * HDirTil[2].weaBus.HGloHor
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,423};
#line 54 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  (data->localData[0]->realVars[34] /* HDifTil[1].HGroDifTil variable */) = (0.1000000000000004) * ((data->localData[0]->realVars[153] /* HDirTil[2].weaBus.HGloHor variable */));
#line 396 OMC_FILE
  TRACE_POP
}
/*
equation index: 424
type: SIMPLE_ASSIGN
HDifTil[2].HGroDifTil = 0.1000000000000004 * HDirTil[2].weaBus.HGloHor
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,424};
#line 54 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  (data->localData[0]->realVars[35] /* HDifTil[2].HGroDifTil variable */) = (0.1000000000000004) * ((data->localData[0]->realVars[153] /* HDirTil[2].weaBus.HGloHor variable */));
#line 410 OMC_FILE
  TRACE_POP
}
/*
equation index: 425
type: SIMPLE_ASSIGN
eqAirTempVDI.delTEqSW[1] = 0.028 * HDirTil[2].weaBus.HGloHor
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,425};
#line 74 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[196] /* eqAirTempVDI.delTEqSW[1] variable */) = (0.028) * ((data->localData[0]->realVars[153] /* HDirTil[2].weaBus.HGloHor variable */));
#line 424 OMC_FILE
  TRACE_POP
}
/*
equation index: 426
type: SIMPLE_ASSIGN
weaDat.locTim.locTim = HDifTil[1].weaBus.cloTim + weaDat.locTim.diff
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,426};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->localData[0]->realVars[353] /* weaDat.locTim.locTim variable */) = (data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */) + (data->simulationInfo->realParameter[431] /* weaDat.locTim.diff PARAM */);
#line 438 OMC_FILE
  TRACE_POP
}
/*
equation index: 427
type: SIMPLE_ASSIGN
weaDat.eqnTim.Bt = 0.01726149809664721 * (-80.0 + 1.157407407407407e-05 * HDifTil[1].weaBus.cloTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,427};
#line 17 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[351] /* weaDat.eqnTim.Bt variable */) = (0.01726149809664721) * (-80.0 + (1.157407407407407e-05) * ((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */)));
#line 452 OMC_FILE
  TRACE_POP
}
/*
equation index: 428
type: SIMPLE_ASSIGN
$cse7 = sin(weaDat.eqnTim.Bt)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,428};
  (data->localData[0]->realVars[26] /* $cse7 variable */) = sin((data->localData[0]->realVars[351] /* weaDat.eqnTim.Bt variable */));
  TRACE_POP
}
/*
equation index: 429
type: SIMPLE_ASSIGN
$cse6 = cos(weaDat.eqnTim.Bt)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,429};
  (data->localData[0]->realVars[25] /* $cse6 variable */) = cos((data->localData[0]->realVars[351] /* weaDat.eqnTim.Bt variable */));
  TRACE_POP
}
/*
equation index: 430
type: SIMPLE_ASSIGN
$cse5 = sin(2.0 * weaDat.eqnTim.Bt)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,430};
  (data->localData[0]->realVars[24] /* $cse5 variable */) = sin((2.0) * ((data->localData[0]->realVars[351] /* weaDat.eqnTim.Bt variable */)));
  TRACE_POP
}
/*
equation index: 431
type: SIMPLE_ASSIGN
weaDat.eqnTim.eqnTim = 60.0 * (9.869999999999999 * $cse5 + (-7.53) * $cse6 + (-1.5) * $cse7)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,431};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[352] /* weaDat.eqnTim.eqnTim variable */) = (60.0) * ((9.869999999999999) * ((data->localData[0]->realVars[24] /* $cse5 variable */)) + (-7.53) * ((data->localData[0]->realVars[25] /* $cse6 variable */)) + (-1.5) * ((data->localData[0]->realVars[26] /* $cse7 variable */)));
#line 502 OMC_FILE
  TRACE_POP
}
/*
equation index: 432
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.solTim = weaDat.locTim.locTim + weaDat.eqnTim.eqnTim
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,432};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SolarTime.mo"
  (data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */) = (data->localData[0]->realVars[353] /* weaDat.locTim.locTim variable */) + (data->localData[0]->realVars[352] /* weaDat.eqnTim.eqnTim variable */);
#line 516 OMC_FILE
  TRACE_POP
}
/*
equation index: 433
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * HDifTil[1].weaBus.solTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,433};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[128] /* HDifTil[1].weaBus.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */)));
#line 530 OMC_FILE
  TRACE_POP
}
/*
equation index: 434
type: SIMPLE_ASSIGN
$cse10 = cos(HDifTil[1].weaBus.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,434};
  (data->localData[0]->realVars[13] /* $cse10 variable */) = cos((data->localData[0]->realVars[128] /* HDifTil[1].weaBus.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 435
type: SIMPLE_ASSIGN
HDifTil[1].incAng.solHouAng.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * HDifTil[1].weaBus.solTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,435};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[98] /* HDifTil[1].incAng.solHouAng.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */)));
#line 556 OMC_FILE
  TRACE_POP
}
/*
equation index: 436
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.sol_s = sin(HDifTil[1].incAng.solHouAng.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,436};
  (data->localData[0]->realVars[96] /* HDifTil[1].incAng.incAng.sol_s variable */) = sin((data->localData[0]->realVars[98] /* HDifTil[1].incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 437
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.sol_c = cos(HDifTil[1].incAng.solHouAng.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,437};
  (data->localData[0]->realVars[94] /* HDifTil[1].incAng.incAng.sol_c variable */) = cos((data->localData[0]->realVars[98] /* HDifTil[1].incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 438
type: SIMPLE_ASSIGN
HDifTil[2].incAng.solHouAng.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * HDifTil[1].weaBus.solTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,438};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[99] /* HDifTil[2].incAng.solHouAng.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */)));
#line 594 OMC_FILE
  TRACE_POP
}
/*
equation index: 439
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.sol_s = sin(HDifTil[2].incAng.solHouAng.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,439};
  (data->localData[0]->realVars[97] /* HDifTil[2].incAng.incAng.sol_s variable */) = sin((data->localData[0]->realVars[99] /* HDifTil[2].incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 440
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.sol_c = cos(HDifTil[2].incAng.solHouAng.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,440};
  (data->localData[0]->realVars[95] /* HDifTil[2].incAng.incAng.sol_c variable */) = cos((data->localData[0]->realVars[99] /* HDifTil[2].incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 441
type: SIMPLE_ASSIGN
HDirTil[1].incAng.solHouAng.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * HDifTil[1].weaBus.solTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,441};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[151] /* HDirTil[1].incAng.solHouAng.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */)));
#line 632 OMC_FILE
  TRACE_POP
}
/*
equation index: 442
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.sol_s = sin(HDirTil[1].incAng.solHouAng.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,442};
  (data->localData[0]->realVars[149] /* HDirTil[1].incAng.incAng.sol_s variable */) = sin((data->localData[0]->realVars[151] /* HDirTil[1].incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 443
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.sol_c = cos(HDirTil[1].incAng.solHouAng.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,443};
  (data->localData[0]->realVars[147] /* HDirTil[1].incAng.incAng.sol_c variable */) = cos((data->localData[0]->realVars[151] /* HDirTil[1].incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 444
type: SIMPLE_ASSIGN
HDirTil[2].incAng.solHouAng.solHouAng = 0.2617993877991494 * (-12.0 + 0.0002777777777777778 * HDifTil[1].weaBus.solTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,444};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/SolarHourAngle.mo"
  (data->localData[0]->realVars[152] /* HDirTil[2].incAng.solHouAng.solHouAng variable */) = (0.2617993877991494) * (-12.0 + (0.0002777777777777778) * ((data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */)));
#line 670 OMC_FILE
  TRACE_POP
}
/*
equation index: 445
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.sol_s = sin(HDirTil[2].incAng.solHouAng.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,445};
  (data->localData[0]->realVars[150] /* HDirTil[2].incAng.incAng.sol_s variable */) = sin((data->localData[0]->realVars[152] /* HDirTil[2].incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 446
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.sol_c = cos(HDirTil[2].incAng.solHouAng.solHouAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,446};
  (data->localData[0]->realVars[148] /* HDirTil[2].incAng.incAng.sol_c variable */) = cos((data->localData[0]->realVars[152] /* HDirTil[2].incAng.solHouAng.solHouAng variable */));
  TRACE_POP
}
/*
equation index: 447
type: SIMPLE_ASSIGN
$cse16 = cos(0.01721420632103996 * (HDifTil[1].weaBus.solTim / 86400.0 + 1.0))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,447};
  (data->localData[0]->realVars[17] /* $cse16 variable */) = cos((0.01721420632103996) * (DIVISION_SIM((data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */),86400.0,"86400.0",equationIndexes) + 1.0));
  TRACE_POP
}
/*
equation index: 448
type: SIMPLE_ASSIGN
HDifTil[1].skyBri.extRadCor = 1.0 + 0.033 * $cse16
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,448};
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  (data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */) = 1.0 + (0.033) * ((data->localData[0]->realVars[17] /* $cse16 variable */));
#line 720 OMC_FILE
  TRACE_POP
}
/*
equation index: 449
type: SIMPLE_ASSIGN
HDifTil[2].skyBri.extRadCor = 1.0 + 0.033 * $cse16
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,449};
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  (data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */) = 1.0 + (0.033) * ((data->localData[0]->realVars[17] /* $cse16 variable */));
#line 734 OMC_FILE
  TRACE_POP
}
/*
equation index: 450
type: SIMPLE_ASSIGN
$whenCondition2 = weaDat.conTim.canRepeatWeatherFile and HDifTil[1].weaBus.cloTim > pre(weaDat.conTim.tNext)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,450};
  modelica_boolean tmp15;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  relationhysteresis(data, &tmp15, (data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */), (data->simulationInfo->realVarsPre[360] /* weaDat.conTim.tNext DISCRETE */), 2, Greater, GreaterZC);
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) = ((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */) && tmp15);
#line 751 OMC_FILE
  TRACE_POP
}
/*
equation index: 451
type: WHEN

when {$whenCondition2} then
  weaDat.conTim.tNext = if weaDat.conTim.canRepeatWeatherFile then weaDat.conTim.lenWea * (1.0 + (*Real*)(integer(HDifTil[1].weaBus.cloTim / weaDat.conTim.lenWea))) else time;
end when;
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,451};
  if(((data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */) /* edge */))
  {
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    (data->localData[0]->realVars[360] /* weaDat.conTim.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[416] /* weaDat.conTim.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),(data->simulationInfo->realParameter[416] /* weaDat.conTim.lenWea PARAM */),"weaDat.conTim.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 770 OMC_FILE
  }
  TRACE_POP
}
/*
equation index: 452
type: SIMPLE_ASSIGN
weaDat.conTim.calTim = if weaDat.conTim.canRepeatWeatherFile then HDifTil[1].weaBus.cloTim - weaDat.conTim.tNext + weaDat.conTim.lenWea else HDifTil[1].weaBus.cloTim
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_452(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,452};
#line 38 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */) = ((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?(data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */) - (data->localData[0]->realVars[360] /* weaDat.conTim.tNext DISCRETE */) + (data->simulationInfo->realParameter[416] /* weaDat.conTim.lenWea PARAM */):(data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */));
#line 785 OMC_FILE
  TRACE_POP
}
/*
equation index: 453
type: SIMPLE_ASSIGN
weaDat.datRea.y[26] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 26, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_453(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,453};
  (data->localData[0]->realVars[347] /* weaDat.datRea.y[26] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 26), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 454
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.HHorIR = max(0.0, weaDat.datRea.y[26])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,454};
  (data->localData[0]->realVars[120] /* HDifTil[1].weaBus.HHorIR variable */) = fmax(0.0,(data->localData[0]->realVars[347] /* weaDat.datRea.y[26] variable */));
  TRACE_POP
}
/*
equation index: 455
type: SIMPLE_ASSIGN
weaBus.TBlaSky = (17635519.73952065 * HDifTil[1].weaBus.HHorIR) ^ 0.25
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,455};
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp16 = (17635519.73952065) * ((data->localData[0]->realVars[120] /* HDifTil[1].weaBus.HHorIR variable */));
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp17 = 0.25;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(tmp16 < 0.0 && tmp17 != 0.0)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp19 = modf(tmp17, &tmp20);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if(tmp19 > 0.5)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp19 -= 1.0;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp20 += 1.0;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    else if(tmp19 < -0.5)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp19 += 1.0;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp20 -= 1.0;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if(fabs(tmp19) < 1e-10)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp18 = pow(tmp16, tmp20);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    else
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      tmp22 = modf(1.0/tmp17, &tmp21);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      if(tmp22 > 0.5)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp22 -= 1.0;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp21 += 1.0;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      else if(tmp22 < -0.5)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp22 += 1.0;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp21 -= 1.0;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      if(fabs(tmp22) < 1e-10 && ((unsigned long)tmp21 & 1))
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        tmp18 = -pow(-tmp16, tmp19)*pow(tmp16, tmp20);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      else
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp16, tmp17);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  else
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    tmp18 = pow(tmp16, tmp17);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(isnan(tmp18) || isinf(tmp18))
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp16, tmp17);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[311] /* weaBus.TBlaSky variable */) = tmp18;
#line 930 OMC_FILE
  TRACE_POP
}
/*
equation index: 456
type: SIMPLE_ASSIGN
weaDat.datRea.y[25] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 25, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,456};
  (data->localData[0]->realVars[346] /* weaDat.datRea.y[25] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 25), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 457
type: SIMPLE_ASSIGN
weaDat.datRea.y[24] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 24, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,457};
  (data->localData[0]->realVars[345] /* weaDat.datRea.y[24] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 24), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 458
type: SIMPLE_ASSIGN
weaDat.datRea.y[23] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 23, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_458(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,458};
  (data->localData[0]->realVars[344] /* weaDat.datRea.y[23] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 23), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 459
type: SIMPLE_ASSIGN
weaDat.datRea.y[22] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 22, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_459(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,459};
  (data->localData[0]->realVars[343] /* weaDat.datRea.y[22] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 22), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 460
type: SIMPLE_ASSIGN
weaDat.datRea.y[21] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 21, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_460(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,460};
  (data->localData[0]->realVars[342] /* weaDat.datRea.y[21] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 21), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 461
type: SIMPLE_ASSIGN
weaDat.datRea.y[20] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 20, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_461(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,461};
  (data->localData[0]->realVars[341] /* weaDat.datRea.y[20] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 20), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 462
type: SIMPLE_ASSIGN
weaDat.datRea.y[19] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 19, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_462(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,462};
  (data->localData[0]->realVars[340] /* weaDat.datRea.y[19] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 19), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 463
type: SIMPLE_ASSIGN
weaDat.datRea.y[18] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 18, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_463(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,463};
  (data->localData[0]->realVars[339] /* weaDat.datRea.y[18] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 18), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 464
type: SIMPLE_ASSIGN
weaDat.datRea.y[17] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 17, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_464(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,464};
  (data->localData[0]->realVars[338] /* weaDat.datRea.y[17] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 17), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 465
type: SIMPLE_ASSIGN
weaDat.datRea.y[16] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 16, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_465(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,465};
  (data->localData[0]->realVars[337] /* weaDat.datRea.y[16] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 16), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 466
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.ceiHei = max(0.0, weaDat.datRea.y[16])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_466(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,466};
  (data->localData[0]->realVars[121] /* HDifTil[1].weaBus.ceiHei variable */) = fmax(0.0,(data->localData[0]->realVars[337] /* weaDat.datRea.y[16] variable */));
  TRACE_POP
}
/*
equation index: 467
type: SIMPLE_ASSIGN
weaDat.datRea.y[15] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 15, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_467(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,467};
  (data->localData[0]->realVars[336] /* weaDat.datRea.y[15] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 15), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 468
type: SIMPLE_ASSIGN
weaDat.datRea.y[14] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 14, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_468(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,468};
  (data->localData[0]->realVars[335] /* weaDat.datRea.y[14] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 14), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 469
type: SIMPLE_ASSIGN
weaDat.opaSkyCovSel.y = 0.1 * weaDat.datRea.y[14]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_469(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,469};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[354] /* weaDat.opaSkyCovSel.y variable */) = (0.1) * ((data->localData[0]->realVars[335] /* weaDat.datRea.y[14] variable */));
#line 1100 OMC_FILE
  TRACE_POP
}
/*
equation index: 470
type: SIMPLE_ASSIGN
$cse3 = max(0.0, weaDat.opaSkyCovSel.y)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_470(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,470};
  (data->localData[0]->realVars[22] /* $cse3 variable */) = fmax(0.0,(data->localData[0]->realVars[354] /* weaDat.opaSkyCovSel.y variable */));
  TRACE_POP
}
/*
equation index: 471
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.nOpa = min(1.0, $cse3)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_471(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,471};
  (data->localData[0]->realVars[123] /* HDifTil[1].weaBus.nOpa variable */) = fmin(1.0,(data->localData[0]->realVars[22] /* $cse3 variable */));
  TRACE_POP
}
/*
equation index: 472
type: SIMPLE_ASSIGN
weaDat.datRea.y[13] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 13, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_472(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,472};
  (data->localData[0]->realVars[334] /* weaDat.datRea.y[13] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 13), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 473
type: SIMPLE_ASSIGN
weaDat.totSkyCovSel.y = 0.1 * weaDat.datRea.y[13]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_473(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,473};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[357] /* weaDat.totSkyCovSel.y variable */) = (0.1) * ((data->localData[0]->realVars[334] /* weaDat.datRea.y[13] variable */));
#line 1150 OMC_FILE
  TRACE_POP
}
/*
equation index: 474
type: SIMPLE_ASSIGN
$cse2 = max(0.0, weaDat.totSkyCovSel.y)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_474(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,474};
  (data->localData[0]->realVars[21] /* $cse2 variable */) = fmax(0.0,(data->localData[0]->realVars[357] /* weaDat.totSkyCovSel.y variable */));
  TRACE_POP
}
/*
equation index: 475
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.nTot = min(1.0, $cse2)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_475(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,475};
  (data->localData[0]->realVars[124] /* HDifTil[1].weaBus.nTot variable */) = fmin(1.0,(data->localData[0]->realVars[21] /* $cse2 variable */));
  TRACE_POP
}
/*
equation index: 476
type: SIMPLE_ASSIGN
weaDat.datRea.y[12] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 12, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_476(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,476};
  (data->localData[0]->realVars[333] /* weaDat.datRea.y[12] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 12), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 477
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.winSpe = max(0.0, weaDat.datRea.y[12])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_477(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,477};
  (data->localData[0]->realVars[132] /* HDifTil[1].weaBus.winSpe variable */) = fmax(0.0,(data->localData[0]->realVars[333] /* weaDat.datRea.y[12] variable */));
  TRACE_POP
}
/*
equation index: 478
type: SIMPLE_ASSIGN
weaDat.datRea.y[11] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 11, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_478(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,478};
  (data->localData[0]->realVars[332] /* weaDat.datRea.y[11] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 11), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 479
type: SIMPLE_ASSIGN
weaDat.conWinDir.y = 0.0174532925199433 * weaDat.datRea.y[11]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_479(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,479};
#line 145 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[321] /* weaDat.conWinDir.y variable */) = (0.0174532925199433) * ((data->localData[0]->realVars[332] /* weaDat.datRea.y[11] variable */));
#line 1224 OMC_FILE
  TRACE_POP
}
/*
equation index: 480
type: SIMPLE_ASSIGN
$cse4 = max(0.0, weaDat.conWinDir.y)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_480(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,480};
  (data->localData[0]->realVars[23] /* $cse4 variable */) = fmax(0.0,(data->localData[0]->realVars[321] /* weaDat.conWinDir.y variable */));
  TRACE_POP
}
/*
equation index: 481
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.winDir = min(6.283185307179586, $cse4)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_481(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,481};
  (data->localData[0]->realVars[131] /* HDifTil[1].weaBus.winDir variable */) = fmin(6.283185307179586,(data->localData[0]->realVars[23] /* $cse4 variable */));
  TRACE_POP
}
/*
equation index: 482
type: SIMPLE_ASSIGN
weaDat.datRea.y[10] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 10, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_482(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,482};
  (data->localData[0]->realVars[331] /* weaDat.datRea.y[10] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 10), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 483
type: SIMPLE_ASSIGN
weaDat.datRea.y[9] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 9, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_483(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,483};
  (data->localData[0]->realVars[330] /* weaDat.datRea.y[9] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 9), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 484
type: SIMPLE_ASSIGN
weaDat.datRea.y[8] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 8, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_484(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,484};
  (data->localData[0]->realVars[329] /* weaDat.datRea.y[8] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 8), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 485
type: SIMPLE_ASSIGN
weaDat.datRea.y[7] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 7, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_485(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,485};
  (data->localData[0]->realVars[328] /* weaDat.datRea.y[7] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 7), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 486
type: SIMPLE_ASSIGN
weaDat.datRea.y[6] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 6, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_486(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,486};
  (data->localData[0]->realVars[327] /* weaDat.datRea.y[6] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 6), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 487
type: SIMPLE_ASSIGN
weaDat.datRea.y[5] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 5, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_487(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,487};
  (data->localData[0]->realVars[326] /* weaDat.datRea.y[5] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 5), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 488
type: SIMPLE_ASSIGN
weaDat.datRea.y[4] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 4, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_488(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,488};
  (data->localData[0]->realVars[325] /* weaDat.datRea.y[4] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 4), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 489
type: SIMPLE_ASSIGN
weaDat.datRea.y[3] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 3, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_489(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,489};
  (data->localData[0]->realVars[324] /* weaDat.datRea.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 3), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 490
type: SIMPLE_ASSIGN
weaDat.relHumSel.uFil = 0.01 * weaDat.datRea.y[3]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_490(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,490};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[356] /* weaDat.relHumSel.uFil variable */) = (0.01) * ((data->localData[0]->realVars[324] /* weaDat.datRea.y[3] variable */));
#line 1358 OMC_FILE
  TRACE_POP
}
/*
equation index: 491
type: SIMPLE_ASSIGN
$cse1 = max(0.0, weaDat.relHumSel.uFil)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_491(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,491};
  (data->localData[0]->realVars[12] /* $cse1 variable */) = fmax(0.0,(data->localData[0]->realVars[356] /* weaDat.relHumSel.uFil variable */));
  TRACE_POP
}
/*
equation index: 492
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.relHum = min(1.0, $cse1)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_492(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,492};
  (data->localData[0]->realVars[125] /* HDifTil[1].weaBus.relHum variable */) = fmin(1.0,(data->localData[0]->realVars[12] /* $cse1 variable */));
  TRACE_POP
}
/*
equation index: 493
type: SIMPLE_ASSIGN
weaDat.datRea.y[2] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 2, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_493(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,493};
  (data->localData[0]->realVars[323] /* weaDat.datRea.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 2), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 494
type: SIMPLE_ASSIGN
weaBus.TDewPoi = 273.15 + weaDat.datRea.y[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_494(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,494};
#line 37 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[312] /* weaBus.TDewPoi variable */) = 273.15 + (data->localData[0]->realVars[323] /* weaDat.datRea.y[2] variable */);
#line 1408 OMC_FILE
  TRACE_POP
}
/*
equation index: 495
type: SIMPLE_ASSIGN
weaDat.datRea.y[1] = Modelica.Blocks.Tables.Internal.getTable1DValue(weaDat.datRea.tableID, 1, weaDat.conTim.calTim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_495(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,495};
  (data->localData[0]->realVars[322] /* weaDat.datRea.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 1), (data->localData[0]->realVars[319] /* weaDat.conTim.calTim variable */));
  TRACE_POP
}
/*
equation index: 496
type: SIMPLE_ASSIGN
weaBus.TDryBul = 273.15 + weaDat.datRea.y[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_496(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,496};
#line 37 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */) = 273.15 + (data->localData[0]->realVars[322] /* weaDat.datRea.y[1] variable */);
#line 1434 OMC_FILE
  TRACE_POP
}
/*
equation index: 497
type: SIMPLE_ASSIGN
eqAirTemp.delTEqLW = 0.2 * (weaBus.TBlaSky - weaBus.TDryBul)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_497(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,497};
#line 23 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/VDI6007WithWindow.mo"
  (data->localData[0]->realVars[190] /* eqAirTemp.delTEqLW variable */) = (0.2) * ((data->localData[0]->realVars[311] /* weaBus.TBlaSky variable */) - (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */));
#line 1448 OMC_FILE
  TRACE_POP
}
/*
equation index: 498
type: SIMPLE_ASSIGN
eqAirTempVDI.delTEqLWWin = eqAirTemp.delTEqLW
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_498(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,498};
  (data->localData[0]->realVars[195] /* eqAirTempVDI.delTEqLWWin variable */) = (data->localData[0]->realVars[190] /* eqAirTemp.delTEqLW variable */);
  TRACE_POP
}
/*
equation index: 499
type: SIMPLE_ASSIGN
eqAirTemp.TEqWin[2] = weaBus.TDryBul + eqAirTemp.delTEqLW
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_499(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,499};
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[189] /* eqAirTemp.TEqWin[2] variable */) = (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */) + (data->localData[0]->realVars[190] /* eqAirTemp.delTEqLW variable */);
#line 1474 OMC_FILE
  TRACE_POP
}
/*
equation index: 500
type: SIMPLE_ASSIGN
eqAirTemp.TEqWin[1] = eqAirTemp.TEqWin[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_500(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,500};
  (data->localData[0]->realVars[188] /* eqAirTemp.TEqWin[1] variable */) = (data->localData[0]->realVars[189] /* eqAirTemp.TEqWin[2] variable */);
  TRACE_POP
}
/*
equation index: 501
type: SIMPLE_ASSIGN
preTem1.T = eqAirTemp.TEqWin[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_501(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,501};
  (data->localData[0]->realVars[205] /* preTem1.T variable */) = (data->localData[0]->realVars[189] /* eqAirTemp.TEqWin[2] variable */);
  TRACE_POP
}
/*
equation index: 502
type: SIMPLE_ASSIGN
eqAirTempVDI.TEqWin[1] = weaBus.TDryBul + eqAirTemp.delTEqLW
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_502(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,502};
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[194] /* eqAirTempVDI.TEqWin[1] variable */) = (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */) + (data->localData[0]->realVars[190] /* eqAirTemp.delTEqLW variable */);
#line 1512 OMC_FILE
  TRACE_POP
}
/*
equation index: 503
type: SIMPLE_ASSIGN
eqAirTempVDI.TEqWall[1] = weaBus.TDryBul + eqAirTemp.delTEqLW + eqAirTempVDI.delTEqSW[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_503(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,503};
#line 77 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[193] /* eqAirTempVDI.TEqWall[1] variable */) = (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */) + (data->localData[0]->realVars[190] /* eqAirTemp.delTEqLW variable */) + (data->localData[0]->realVars[196] /* eqAirTempVDI.delTEqSW[1] variable */);
#line 1526 OMC_FILE
  TRACE_POP
}
/*
equation index: 511
type: LINEAR

<var>theConRoof.solid.T</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_511(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,511};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[210] /* theConRoof.solid.T variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 511 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 1, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,511};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 511 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[210] /* theConRoof.solid.T variable */) = aux_x[0];

  TRACE_POP
}
/*
equation index: 512
type: SIMPLE_ASSIGN
$cse13 = cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_512(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,512};
  (data->localData[0]->realVars[15] /* $cse13 variable */) = cos((DIVISION_SIM((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848));
  TRACE_POP
}
/*
equation index: 513
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.solDec = asin((-0.3979486313076103) * $cse13)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_513(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,513};
  modelica_real tmp23;
  tmp23 = (-0.3979486313076103) * ((data->localData[0]->realVars[15] /* $cse13 variable */));
  if(!(tmp23 >= -1.0 && tmp23 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * $cse13) outside the domain -1.0 <= %g <= 1.0", tmp23);
    }
  }
  (data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */) = asin(tmp23);
  TRACE_POP
}
/*
equation index: 514
type: SIMPLE_ASSIGN
$cse12 = sin(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_514(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,514};
  (data->localData[0]->realVars[14] /* $cse12 variable */) = sin((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 515
type: SIMPLE_ASSIGN
$cse9 = cos(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_515(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,515};
  (data->localData[0]->realVars[27] /* $cse9 variable */) = cos((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 516
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.solZen = acos($cse8 * $cse9 * $cse10 + $cse11 * $cse12)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_516(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,516};
  modelica_real tmp24;
  tmp24 = (((data->simulationInfo->realParameter[2] /* $cse8 PARAM */)) * ((data->localData[0]->realVars[27] /* $cse9 variable */))) * ((data->localData[0]->realVars[13] /* $cse10 variable */)) + ((data->simulationInfo->realParameter[0] /* $cse11 PARAM */)) * ((data->localData[0]->realVars[14] /* $cse12 variable */));
  if(!(tmp24 >= -1.0 && tmp24 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos($cse8 * $cse9 * $cse10 + $cse11 * $cse12) outside the domain -1.0 <= %g <= 1.0", tmp24);
    }
  }
  (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */) = acos(tmp24);
  TRACE_POP
}
/*
equation index: 517
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.solAlt = 1.570796326794897 - HDifTil[1].weaBus.solZen
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,517};
#line 13 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/AltitudeAngle.mo"
  (data->localData[0]->realVars[126] /* HDifTil[1].weaBus.solAlt variable */) = 1.570796326794897 - (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */);
#line 1665 OMC_FILE
  TRACE_POP
}
/*
equation index: 518
type: SIMPLE_ASSIGN
HDifTil[1].HDifTil.b = smooth(1, if noEvent(0.08715574274765814 - cos(HDifTil[1].weaBus.solZen) > 0.01) then 0.08715574274765814 else if noEvent(0.08715574274765814 - cos(HDifTil[1].weaBus.solZen) < -0.01) then cos(HDifTil[1].weaBus.solZen) else 0.25 * (8.715574274765814 - 100.0 * cos(HDifTil[1].weaBus.solZen)) * ((8.715574274765814 - 100.0 * cos(HDifTil[1].weaBus.solZen)) ^ 2.0 - 3.0) * (cos(HDifTil[1].weaBus.solZen) - 0.08715574274765814) + 0.04357787137382907 + 0.5 * cos(HDifTil[1].weaBus.solZen))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,518};
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  modelica_real tmp27;
  modelica_boolean tmp28;
  modelica_real tmp29;
  modelica_boolean tmp30;
  modelica_real tmp31;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  tmp25 = Greater(0.08715574274765814 - cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)),0.01);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  tmp30 = (modelica_boolean)tmp25;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  if(tmp30)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp31 = 0.08715574274765814;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  else
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp26 = Less(0.08715574274765814 - cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)),-0.01);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp28 = (modelica_boolean)tmp26;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    if(tmp28)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp29 = cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */));
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    else
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp27 = 8.715574274765814 - ((100.0) * (cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */))));
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp29 = (0.25) * (((8.715574274765814 - ((100.0) * (cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */))))) * ((tmp27 * tmp27) - 3.0)) * (cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - 0.08715574274765814)) + 0.04357787137382907 + (0.5) * (cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)));
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp31 = tmp29;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  (data->localData[0]->realVars[32] /* HDifTil[1].HDifTil.b variable */) = tmp31;
#line 1728 OMC_FILE
  TRACE_POP
}
/*
equation index: 519
type: SIMPLE_ASSIGN
HDifTil[1].skyCle.tmp1 = 1.040895310738997 * HDifTil[1].weaBus.solZen ^ 3.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,519};
  modelica_real tmp32;
#line 32 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  tmp32 = (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */);
#line 32 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  (data->localData[0]->realVars[116] /* HDifTil[1].skyCle.tmp1 variable */) = (1.040895310738997) * ((tmp32 * tmp32 * tmp32));
#line 1745 OMC_FILE
  TRACE_POP
}
/*
equation index: 520
type: SIMPLE_ASSIGN
HDifTil[1].skyCle.skyCle = Buildings.Utilities.Math.Functions.smoothLimit(((HDifTil[1].weaBus.HDirNor + HDifTil[1].skyCle.HDifHorBou) / HDifTil[1].skyCle.HDifHorBou + HDifTil[1].skyCle.tmp1) / (1.0 + HDifTil[1].skyCle.tmp1), 1.0, 8.0, 0.01)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_520(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,520};
  (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */) = omc_Buildings_Utilities_Math_Functions_smoothLimit(threadData, DIVISION_SIM(DIVISION_SIM((data->localData[0]->realVars[119] /* HDifTil[1].weaBus.HDirNor variable */) + (data->localData[0]->realVars[112] /* HDifTil[1].skyCle.HDifHorBou variable */),(data->localData[0]->realVars[112] /* HDifTil[1].skyCle.HDifHorBou variable */),"HDifTil[1].skyCle.HDifHorBou",equationIndexes) + (data->localData[0]->realVars[116] /* HDifTil[1].skyCle.tmp1 variable */),1.0 + (data->localData[0]->realVars[116] /* HDifTil[1].skyCle.tmp1 variable */),"1.0 + HDifTil[1].skyCle.tmp1",equationIndexes), 1.0, 8.0, 0.01);
  TRACE_POP
}
/*
equation index: 521
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.a1 = smooth(1, if noEvent(1.065 - HDifTil[1].skyCle.skyCle > 0.01) then 1.0 else if noEvent(1.065 - HDifTil[1].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((106.5 - 100.0 * HDifTil[1].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[1].skyCle.skyCle - 1.065) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_521(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,521};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  modelica_real tmp35;
  modelica_boolean tmp36;
  modelica_real tmp37;
  modelica_boolean tmp38;
  modelica_real tmp39;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp33 = Greater(1.065 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),0.01);
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp38 = (modelica_boolean)tmp33;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp38)
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp39 = 1.0;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp34 = Less(1.065 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),-0.01);
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp36 = (modelica_boolean)tmp34;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp36)
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp37 = 0.0;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp35 = 106.5 - ((100.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */)));
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp37 = (25.0) * (((tmp35 * tmp35) - 3.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */) - 1.065)) + 0.5;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp39 = tmp37;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[54] /* HDifTil[1].briCoe.a1 variable */) = tmp39;
#line 1820 OMC_FILE
  TRACE_POP
}
/*
equation index: 522
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.b2 = smooth(1, if noEvent(1.23 - HDifTil[1].skyCle.skyCle > 0.01) then 1.0 else if noEvent(1.23 - HDifTil[1].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((123.0 - 100.0 * HDifTil[1].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[1].skyCle.skyCle - 1.23) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,522};
  modelica_boolean tmp40;
  modelica_boolean tmp41;
  modelica_real tmp42;
  modelica_boolean tmp43;
  modelica_real tmp44;
  modelica_boolean tmp45;
  modelica_real tmp46;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp40 = Greater(1.23 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),0.01);
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp45 = (modelica_boolean)tmp40;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp45)
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp46 = 1.0;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp41 = Less(1.23 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),-0.01);
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp43 = (modelica_boolean)tmp41;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp43)
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp44 = 0.0;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp42 = 123.0 - ((100.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */)));
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp44 = (25.0) * (((tmp42 * tmp42) - 3.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */) - 1.23)) + 0.5;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp46 = tmp44;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[70] /* HDifTil[1].briCoe.b2 variable */) = tmp46;
#line 1883 OMC_FILE
  TRACE_POP
}
/*
equation index: 523
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.a2 = HDifTil[1].briCoe.b2 - HDifTil[1].briCoe.a1
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,523};
#line 88 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[56] /* HDifTil[1].briCoe.a2 variable */) = (data->localData[0]->realVars[70] /* HDifTil[1].briCoe.b2 variable */) - (data->localData[0]->realVars[54] /* HDifTil[1].briCoe.a1 variable */);
#line 1897 OMC_FILE
  TRACE_POP
}
/*
equation index: 524
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.b3 = smooth(1, if noEvent(1.5 - HDifTil[1].skyCle.skyCle > 0.01) then 1.0 else if noEvent(1.5 - HDifTil[1].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((150.0 - 100.0 * HDifTil[1].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[1].skyCle.skyCle - 1.5) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,524};
  modelica_boolean tmp47;
  modelica_boolean tmp48;
  modelica_real tmp49;
  modelica_boolean tmp50;
  modelica_real tmp51;
  modelica_boolean tmp52;
  modelica_real tmp53;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp47 = Greater(1.5 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),0.01);
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp52 = (modelica_boolean)tmp47;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp52)
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp53 = 1.0;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp48 = Less(1.5 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),-0.01);
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp50 = (modelica_boolean)tmp48;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp50)
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp51 = 0.0;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp49 = 150.0 - ((100.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */)));
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp51 = (25.0) * (((tmp49 * tmp49) - 3.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */) - 1.5)) + 0.5;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp53 = tmp51;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[72] /* HDifTil[1].briCoe.b3 variable */) = tmp53;
#line 1960 OMC_FILE
  TRACE_POP
}
/*
equation index: 525
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.a3 = HDifTil[1].briCoe.b3 - HDifTil[1].briCoe.b2
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,525};
#line 89 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[58] /* HDifTil[1].briCoe.a3 variable */) = (data->localData[0]->realVars[72] /* HDifTil[1].briCoe.b3 variable */) - (data->localData[0]->realVars[70] /* HDifTil[1].briCoe.b2 variable */);
#line 1974 OMC_FILE
  TRACE_POP
}
/*
equation index: 526
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.b4 = smooth(1, if noEvent(1.95 - HDifTil[1].skyCle.skyCle > 0.01) then 1.0 else if noEvent(1.95 - HDifTil[1].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((195.0 - 100.0 * HDifTil[1].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[1].skyCle.skyCle - 1.95) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_526(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,526};
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  modelica_real tmp56;
  modelica_boolean tmp57;
  modelica_real tmp58;
  modelica_boolean tmp59;
  modelica_real tmp60;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp54 = Greater(1.95 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),0.01);
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp59 = (modelica_boolean)tmp54;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp59)
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp60 = 1.0;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp55 = Less(1.95 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),-0.01);
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp57 = (modelica_boolean)tmp55;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp57)
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp58 = 0.0;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp56 = 195.0 - ((100.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */)));
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp58 = (25.0) * (((tmp56 * tmp56) - 3.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */) - 1.95)) + 0.5;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp60 = tmp58;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[74] /* HDifTil[1].briCoe.b4 variable */) = tmp60;
#line 2037 OMC_FILE
  TRACE_POP
}
/*
equation index: 527
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.a4 = HDifTil[1].briCoe.b4 - HDifTil[1].briCoe.b3
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_527(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,527};
#line 90 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[60] /* HDifTil[1].briCoe.a4 variable */) = (data->localData[0]->realVars[74] /* HDifTil[1].briCoe.b4 variable */) - (data->localData[0]->realVars[72] /* HDifTil[1].briCoe.b3 variable */);
#line 2051 OMC_FILE
  TRACE_POP
}
/*
equation index: 528
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.b5 = smooth(1, if noEvent(2.8 - HDifTil[1].skyCle.skyCle > 0.01) then 1.0 else if noEvent(2.8 - HDifTil[1].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((280.0 - 100.0 * HDifTil[1].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[1].skyCle.skyCle - 2.8) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_528(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,528};
  modelica_boolean tmp61;
  modelica_boolean tmp62;
  modelica_real tmp63;
  modelica_boolean tmp64;
  modelica_real tmp65;
  modelica_boolean tmp66;
  modelica_real tmp67;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp61 = Greater(2.8 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),0.01);
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp66 = (modelica_boolean)tmp61;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp66)
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp67 = 1.0;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp62 = Less(2.8 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),-0.01);
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp64 = (modelica_boolean)tmp62;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp64)
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp65 = 0.0;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp63 = 280.0 - ((100.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */)));
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp65 = (25.0) * (((tmp63 * tmp63) - 3.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */) - 2.8)) + 0.5;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp67 = tmp65;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[76] /* HDifTil[1].briCoe.b5 variable */) = tmp67;
#line 2114 OMC_FILE
  TRACE_POP
}
/*
equation index: 529
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.a5 = HDifTil[1].briCoe.b5 - HDifTil[1].briCoe.b4
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_529(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,529};
#line 91 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[62] /* HDifTil[1].briCoe.a5 variable */) = (data->localData[0]->realVars[76] /* HDifTil[1].briCoe.b5 variable */) - (data->localData[0]->realVars[74] /* HDifTil[1].briCoe.b4 variable */);
#line 2128 OMC_FILE
  TRACE_POP
}
/*
equation index: 530
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.b6 = smooth(1, if noEvent(4.5 - HDifTil[1].skyCle.skyCle > 0.01) then 1.0 else if noEvent(4.5 - HDifTil[1].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((450.0 - 100.0 * HDifTil[1].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[1].skyCle.skyCle - 4.5) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_530(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,530};
  modelica_boolean tmp68;
  modelica_boolean tmp69;
  modelica_real tmp70;
  modelica_boolean tmp71;
  modelica_real tmp72;
  modelica_boolean tmp73;
  modelica_real tmp74;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp68 = Greater(4.5 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),0.01);
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp73 = (modelica_boolean)tmp68;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp73)
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp74 = 1.0;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp69 = Less(4.5 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),-0.01);
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp71 = (modelica_boolean)tmp69;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp71)
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp72 = 0.0;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp70 = 450.0 - ((100.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */)));
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp72 = (25.0) * (((tmp70 * tmp70) - 3.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */) - 4.5)) + 0.5;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp74 = tmp72;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[78] /* HDifTil[1].briCoe.b6 variable */) = tmp74;
#line 2191 OMC_FILE
  TRACE_POP
}
/*
equation index: 531
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.a6 = HDifTil[1].briCoe.b6 - HDifTil[1].briCoe.b5
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_531(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,531};
#line 92 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[64] /* HDifTil[1].briCoe.a6 variable */) = (data->localData[0]->realVars[78] /* HDifTil[1].briCoe.b6 variable */) - (data->localData[0]->realVars[76] /* HDifTil[1].briCoe.b5 variable */);
#line 2205 OMC_FILE
  TRACE_POP
}
/*
equation index: 532
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.b7 = smooth(1, if noEvent(6.2 - HDifTil[1].skyCle.skyCle > 0.01) then 1.0 else if noEvent(6.2 - HDifTil[1].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((620.0 - 100.0 * HDifTil[1].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[1].skyCle.skyCle - 6.2) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,532};
  modelica_boolean tmp75;
  modelica_boolean tmp76;
  modelica_real tmp77;
  modelica_boolean tmp78;
  modelica_real tmp79;
  modelica_boolean tmp80;
  modelica_real tmp81;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp75 = Greater(6.2 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),0.01);
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp80 = (modelica_boolean)tmp75;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp80)
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp81 = 1.0;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp76 = Less(6.2 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),-0.01);
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp78 = (modelica_boolean)tmp76;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp78)
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp79 = 0.0;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp77 = 620.0 - ((100.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */)));
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp79 = (25.0) * (((tmp77 * tmp77) - 3.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */) - 6.2)) + 0.5;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp81 = tmp79;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[80] /* HDifTil[1].briCoe.b7 variable */) = tmp81;
#line 2268 OMC_FILE
  TRACE_POP
}
/*
equation index: 533
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.a7 = HDifTil[1].briCoe.b7 - HDifTil[1].briCoe.b6
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,533};
#line 93 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[66] /* HDifTil[1].briCoe.a7 variable */) = (data->localData[0]->realVars[80] /* HDifTil[1].briCoe.b7 variable */) - (data->localData[0]->realVars[78] /* HDifTil[1].briCoe.b6 variable */);
#line 2282 OMC_FILE
  TRACE_POP
}
/*
equation index: 534
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.a8 = smooth(1, if noEvent(-6.2 + HDifTil[1].skyCle.skyCle > 0.01) then 1.0 else if noEvent(-6.2 + HDifTil[1].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((-620.0 + 100.0 * HDifTil[1].skyCle.skyCle) ^ 2.0 - 3.0) * (6.2 - HDifTil[1].skyCle.skyCle) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,534};
  modelica_boolean tmp82;
  modelica_boolean tmp83;
  modelica_real tmp84;
  modelica_boolean tmp85;
  modelica_real tmp86;
  modelica_boolean tmp87;
  modelica_real tmp88;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp82 = Greater(-6.2 + (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),0.01);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp87 = (modelica_boolean)tmp82;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp87)
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp88 = 1.0;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp83 = Less(-6.2 + (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */),-0.01);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp85 = (modelica_boolean)tmp83;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp85)
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp86 = 0.0;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp84 = -620.0 + (100.0) * ((data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */));
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp86 = (25.0) * (((tmp84 * tmp84) - 3.0) * (6.2 - (data->localData[0]->realVars[114] /* HDifTil[1].skyCle.skyCle variable */))) + 0.5;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp88 = tmp86;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[68] /* HDifTil[1].briCoe.a8 variable */) = tmp88;
#line 2345 OMC_FILE
  TRACE_POP
}
/*
equation index: 535
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.F11 = 0.1299457 * HDifTil[1].briCoe.a2 + (-0.0083117) * HDifTil[1].briCoe.a1 + 0.3296958 * HDifTil[1].briCoe.a3 + 0.5682053 * HDifTil[1].briCoe.a4 + 0.873028 * HDifTil[1].briCoe.a5 + 1.1326077 * HDifTil[1].briCoe.a6 + 1.0601591 * HDifTil[1].briCoe.a7 + 0.677747 * HDifTil[1].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_535(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,535};
#line 96 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[40] /* HDifTil[1].briCoe.F11 variable */) = (0.1299457) * ((data->localData[0]->realVars[56] /* HDifTil[1].briCoe.a2 variable */)) + (-0.0083117) * ((data->localData[0]->realVars[54] /* HDifTil[1].briCoe.a1 variable */)) + (0.3296958) * ((data->localData[0]->realVars[58] /* HDifTil[1].briCoe.a3 variable */)) + (0.5682053) * ((data->localData[0]->realVars[60] /* HDifTil[1].briCoe.a4 variable */)) + (0.873028) * ((data->localData[0]->realVars[62] /* HDifTil[1].briCoe.a5 variable */)) + (1.1326077) * ((data->localData[0]->realVars[64] /* HDifTil[1].briCoe.a6 variable */)) + (1.0601591) * ((data->localData[0]->realVars[66] /* HDifTil[1].briCoe.a7 variable */)) + (0.677747) * ((data->localData[0]->realVars[68] /* HDifTil[1].briCoe.a8 variable */));
#line 2359 OMC_FILE
  TRACE_POP
}
/*
equation index: 536
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.F12 = 0.5877285 * HDifTil[1].briCoe.a1 + 0.6825954 * HDifTil[1].briCoe.a2 + 0.4868735 * HDifTil[1].briCoe.a3 + 0.1874525 * HDifTil[1].briCoe.a4 + (-0.3920403) * HDifTil[1].briCoe.a5 + (-1.2367284) * HDifTil[1].briCoe.a6 + (-1.5999137) * HDifTil[1].briCoe.a7 + (-0.3272588) * HDifTil[1].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_536(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,536};
#line 98 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[42] /* HDifTil[1].briCoe.F12 variable */) = (0.5877285) * ((data->localData[0]->realVars[54] /* HDifTil[1].briCoe.a1 variable */)) + (0.6825954) * ((data->localData[0]->realVars[56] /* HDifTil[1].briCoe.a2 variable */)) + (0.4868735) * ((data->localData[0]->realVars[58] /* HDifTil[1].briCoe.a3 variable */)) + (0.1874525) * ((data->localData[0]->realVars[60] /* HDifTil[1].briCoe.a4 variable */)) + (-0.3920403) * ((data->localData[0]->realVars[62] /* HDifTil[1].briCoe.a5 variable */)) + (-1.2367284) * ((data->localData[0]->realVars[64] /* HDifTil[1].briCoe.a6 variable */)) + (-1.5999137) * ((data->localData[0]->realVars[66] /* HDifTil[1].briCoe.a7 variable */)) + (-0.3272588) * ((data->localData[0]->realVars[68] /* HDifTil[1].briCoe.a8 variable */));
#line 2373 OMC_FILE
  TRACE_POP
}
/*
equation index: 537
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.F13 = (-0.0620636) * HDifTil[1].briCoe.a1 + (-0.1513725) * HDifTil[1].briCoe.a2 + (-0.2210958) * HDifTil[1].briCoe.a3 + (-0.295129) * HDifTil[1].briCoe.a4 + (-0.3616149) * HDifTil[1].briCoe.a5 + (-0.4118494) * HDifTil[1].briCoe.a6 + (-0.3589221) * HDifTil[1].briCoe.a7 + (-0.2504286) * HDifTil[1].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_537(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,537};
#line 100 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[44] /* HDifTil[1].briCoe.F13 variable */) = (-0.0620636) * ((data->localData[0]->realVars[54] /* HDifTil[1].briCoe.a1 variable */)) + (-0.1513725) * ((data->localData[0]->realVars[56] /* HDifTil[1].briCoe.a2 variable */)) + (-0.2210958) * ((data->localData[0]->realVars[58] /* HDifTil[1].briCoe.a3 variable */)) + (-0.295129) * ((data->localData[0]->realVars[60] /* HDifTil[1].briCoe.a4 variable */)) + (-0.3616149) * ((data->localData[0]->realVars[62] /* HDifTil[1].briCoe.a5 variable */)) + (-0.4118494) * ((data->localData[0]->realVars[64] /* HDifTil[1].briCoe.a6 variable */)) + (-0.3589221) * ((data->localData[0]->realVars[66] /* HDifTil[1].briCoe.a7 variable */)) + (-0.2504286) * ((data->localData[0]->realVars[68] /* HDifTil[1].briCoe.a8 variable */));
#line 2387 OMC_FILE
  TRACE_POP
}
/*
equation index: 538
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.F21 = (-0.0596012) * HDifTil[1].briCoe.a1 + (-0.0189325) * HDifTil[1].briCoe.a2 + 0.055414 * HDifTil[1].briCoe.a3 + 0.1088631 * HDifTil[1].briCoe.a4 + 0.2255647 * HDifTil[1].briCoe.a5 + 0.2877813 * HDifTil[1].briCoe.a6 + 0.2642124 * HDifTil[1].briCoe.a7 + 0.1561313 * HDifTil[1].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_538(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,538};
#line 102 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[48] /* HDifTil[1].briCoe.F21 variable */) = (-0.0596012) * ((data->localData[0]->realVars[54] /* HDifTil[1].briCoe.a1 variable */)) + (-0.0189325) * ((data->localData[0]->realVars[56] /* HDifTil[1].briCoe.a2 variable */)) + (0.055414) * ((data->localData[0]->realVars[58] /* HDifTil[1].briCoe.a3 variable */)) + (0.1088631) * ((data->localData[0]->realVars[60] /* HDifTil[1].briCoe.a4 variable */)) + (0.2255647) * ((data->localData[0]->realVars[62] /* HDifTil[1].briCoe.a5 variable */)) + (0.2877813) * ((data->localData[0]->realVars[64] /* HDifTil[1].briCoe.a6 variable */)) + (0.2642124) * ((data->localData[0]->realVars[66] /* HDifTil[1].briCoe.a7 variable */)) + (0.1561313) * ((data->localData[0]->realVars[68] /* HDifTil[1].briCoe.a8 variable */));
#line 2401 OMC_FILE
  TRACE_POP
}
/*
equation index: 539
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.F22 = 0.07212490000000001 * HDifTil[1].briCoe.a1 + 0.065965 * HDifTil[1].briCoe.a2 + (-0.0639588) * HDifTil[1].briCoe.a3 + (-0.1519229) * HDifTil[1].briCoe.a4 + (-0.4620442) * HDifTil[1].briCoe.a5 + (-0.8230357) * HDifTil[1].briCoe.a6 + (-1.127234) * HDifTil[1].briCoe.a7 + (-1.3765031) * HDifTil[1].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_539(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,539};
#line 104 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[50] /* HDifTil[1].briCoe.F22 variable */) = (0.07212490000000001) * ((data->localData[0]->realVars[54] /* HDifTil[1].briCoe.a1 variable */)) + (0.065965) * ((data->localData[0]->realVars[56] /* HDifTil[1].briCoe.a2 variable */)) + (-0.0639588) * ((data->localData[0]->realVars[58] /* HDifTil[1].briCoe.a3 variable */)) + (-0.1519229) * ((data->localData[0]->realVars[60] /* HDifTil[1].briCoe.a4 variable */)) + (-0.4620442) * ((data->localData[0]->realVars[62] /* HDifTil[1].briCoe.a5 variable */)) + (-0.8230357) * ((data->localData[0]->realVars[64] /* HDifTil[1].briCoe.a6 variable */)) + (-1.127234) * ((data->localData[0]->realVars[66] /* HDifTil[1].briCoe.a7 variable */)) + (-1.3765031) * ((data->localData[0]->realVars[68] /* HDifTil[1].briCoe.a8 variable */));
#line 2415 OMC_FILE
  TRACE_POP
}
/*
equation index: 540
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.F23 = (-0.0220216) * HDifTil[1].briCoe.a1 + (-0.0288748) * HDifTil[1].briCoe.a2 + (-0.0260542) * HDifTil[1].briCoe.a3 + (-0.0139754) * HDifTil[1].briCoe.a4 + 0.0012448 * HDifTil[1].briCoe.a5 + 0.0558651 * HDifTil[1].briCoe.a6 + 0.1310694 * HDifTil[1].briCoe.a7 + 0.2506212 * HDifTil[1].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_540(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,540};
#line 106 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[52] /* HDifTil[1].briCoe.F23 variable */) = (-0.0220216) * ((data->localData[0]->realVars[54] /* HDifTil[1].briCoe.a1 variable */)) + (-0.0288748) * ((data->localData[0]->realVars[56] /* HDifTil[1].briCoe.a2 variable */)) + (-0.0260542) * ((data->localData[0]->realVars[58] /* HDifTil[1].briCoe.a3 variable */)) + (-0.0139754) * ((data->localData[0]->realVars[60] /* HDifTil[1].briCoe.a4 variable */)) + (0.0012448) * ((data->localData[0]->realVars[62] /* HDifTil[1].briCoe.a5 variable */)) + (0.0558651) * ((data->localData[0]->realVars[64] /* HDifTil[1].briCoe.a6 variable */)) + (0.1310694) * ((data->localData[0]->realVars[66] /* HDifTil[1].briCoe.a7 variable */)) + (0.2506212) * ((data->localData[0]->realVars[68] /* HDifTil[1].briCoe.a8 variable */));
#line 2429 OMC_FILE
  TRACE_POP
}
/*
equation index: 541
type: SIMPLE_ASSIGN
HDifTil[1].relAirMas.zenLim = smooth(1, if noEvent(1.570796326794897 - HDifTil[1].weaBus.solZen > 0.01) then HDifTil[1].weaBus.solZen else if noEvent(1.570796326794897 - HDifTil[1].weaBus.solZen < -0.01) then 1.570796326794897 else 0.25 * (157.0796326794897 - 100.0 * HDifTil[1].weaBus.solZen) * ((157.0796326794897 - 100.0 * HDifTil[1].weaBus.solZen) ^ 2.0 - 3.0) * (1.570796326794897 - HDifTil[1].weaBus.solZen) + 0.5 * HDifTil[1].weaBus.solZen + 0.7853981633974483)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_541(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,541};
  modelica_boolean tmp89;
  modelica_boolean tmp90;
  modelica_real tmp91;
  modelica_boolean tmp92;
  modelica_real tmp93;
  modelica_boolean tmp94;
  modelica_real tmp95;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp89 = Greater(1.570796326794897 - (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */),0.01);
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp94 = (modelica_boolean)tmp89;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(tmp94)
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp95 = (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */);
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  else
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp90 = Less(1.570796326794897 - (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */),-0.01);
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp92 = (modelica_boolean)tmp90;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(tmp92)
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp93 = 1.570796326794897;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp91 = 157.0796326794897 - ((100.0) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)));
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp93 = (0.25) * (((157.0796326794897 - ((100.0) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)))) * ((tmp91 * tmp91) - 3.0)) * (1.570796326794897 - (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */))) + (0.5) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) + 0.7853981633974483;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp95 = tmp93;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->localData[0]->realVars[106] /* HDifTil[1].relAirMas.zenLim variable */) = tmp95;
#line 2492 OMC_FILE
  TRACE_POP
}
/*
equation index: 542
type: SIMPLE_ASSIGN
HDifTil[1].relAirMas.zenDeg = 57.29577951308232 * HDifTil[1].relAirMas.zenLim
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_542(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,542};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->localData[0]->realVars[104] /* HDifTil[1].relAirMas.zenDeg variable */) = (57.29577951308232) * ((data->localData[0]->realVars[106] /* HDifTil[1].relAirMas.zenLim variable */));
#line 2506 OMC_FILE
  TRACE_POP
}
/*
equation index: 543
type: SIMPLE_ASSIGN
$cse15 = cos(HDifTil[1].relAirMas.zenLim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_543(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,543};
  (data->localData[0]->realVars[16] /* $cse15 variable */) = cos((data->localData[0]->realVars[106] /* HDifTil[1].relAirMas.zenLim variable */));
  TRACE_POP
}
/*
equation index: 544
type: SIMPLE_ASSIGN
HDifTil[1].relAirMas.relAirMas = $cse14 / ($cse15 + 0.15 / (93.90000000000001 - HDifTil[1].relAirMas.zenDeg) ^ 1.253)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_544(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,544};
  modelica_real tmp96;
  modelica_real tmp97;
  modelica_real tmp98;
  modelica_real tmp99;
  modelica_real tmp100;
  modelica_real tmp101;
  modelica_real tmp102;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp96 = 93.90000000000001 - (data->localData[0]->realVars[104] /* HDifTil[1].relAirMas.zenDeg variable */);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp97 = 1.253;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(tmp96 < 0.0 && tmp97 != 0.0)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp99 = modf(tmp97, &tmp100);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(tmp99 > 0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp99 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp100 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else if(tmp99 < -0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp99 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp100 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(fabs(tmp99) < 1e-10)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp98 = pow(tmp96, tmp100);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp102 = modf(1.0/tmp97, &tmp101);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      if(tmp102 > 0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp102 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp101 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      else if(tmp102 < -0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp102 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp101 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      if(fabs(tmp102) < 1e-10 && ((unsigned long)tmp101 & 1))
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp98 = -pow(-tmp96, tmp99)*pow(tmp96, tmp100);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp96, tmp97);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp98 = pow(tmp96, tmp97);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(isnan(tmp98) || isinf(tmp98))
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp96, tmp97);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */) = DIVISION_SIM((data->simulationInfo->realParameter[1] /* $cse14 PARAM */),(data->localData[0]->realVars[16] /* $cse15 variable */) + DIVISION_SIM(0.15,tmp98,"(93.90000000000001 - HDifTil[1].relAirMas.zenDeg) ^ 1.253",equationIndexes),"$cse15 + 0.15 / (93.90000000000001 - HDifTil[1].relAirMas.zenDeg) ^ 1.253",equationIndexes);
#line 2639 OMC_FILE
  TRACE_POP
}
/*
equation index: 545
type: SIMPLE_ASSIGN
HDifTil[1].skyBri.skyBri = smooth(1, if noEvent(1.0 + (-0.0007320108337603397) * HDifTil[1].weaBus.HDifHor * HDifTil[1].relAirMas.relAirMas / HDifTil[1].skyBri.extRadCor > 0.025) then 0.0007320108337603397 * HDifTil[1].weaBus.HDifHor * HDifTil[1].relAirMas.relAirMas / HDifTil[1].skyBri.extRadCor else if noEvent(1.0 + (-0.0007320108337603397) * HDifTil[1].weaBus.HDifHor * HDifTil[1].relAirMas.relAirMas / HDifTil[1].skyBri.extRadCor < -0.025) then 1.0 else 0.25 * (40.0 + (-0.02928043335041359) * HDifTil[1].weaBus.HDifHor * HDifTil[1].relAirMas.relAirMas / HDifTil[1].skyBri.extRadCor) * ((40.0 + (-0.02928043335041359) * HDifTil[1].weaBus.HDifHor * HDifTil[1].relAirMas.relAirMas / HDifTil[1].skyBri.extRadCor) ^ 2.0 - 3.0) * (1.0 - 0.0007320108337603397 * HDifTil[1].weaBus.HDifHor * HDifTil[1].relAirMas.relAirMas / HDifTil[1].skyBri.extRadCor) + 0.0003660054168801698 * HDifTil[1].weaBus.HDifHor * HDifTil[1].relAirMas.relAirMas / HDifTil[1].skyBri.extRadCor + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_545(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,545};
  modelica_boolean tmp103;
  modelica_boolean tmp104;
  modelica_real tmp105;
  modelica_boolean tmp106;
  modelica_real tmp107;
  modelica_boolean tmp108;
  modelica_real tmp109;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  tmp103 = Greater(1.0 + (-0.0007320108337603397) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */),(data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */),"HDifTil[1].skyBri.extRadCor",equationIndexes))),0.025);
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  tmp108 = (modelica_boolean)tmp103;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  if(tmp108)
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    tmp109 = (0.0007320108337603397) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */),(data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */),"HDifTil[1].skyBri.extRadCor",equationIndexes)));
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  }
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  else
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    tmp104 = Less(1.0 + (-0.0007320108337603397) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */),(data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */),"HDifTil[1].skyBri.extRadCor",equationIndexes))),-0.025);
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    tmp106 = (modelica_boolean)tmp104;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    if(tmp106)
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
      tmp107 = 1.0;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    else
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
      tmp105 = 40.0 + (-0.02928043335041359) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */),(data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */),"HDifTil[1].skyBri.extRadCor",equationIndexes)));
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
      tmp107 = (0.25) * (((40.0 + (-0.02928043335041359) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */),(data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */),"HDifTil[1].skyBri.extRadCor",equationIndexes)))) * ((tmp105 * tmp105) - 3.0)) * (1.0 - ((0.0007320108337603397) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */),(data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */),"HDifTil[1].skyBri.extRadCor",equationIndexes)))))) + (0.0003660054168801698) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */),(data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */),"HDifTil[1].skyBri.extRadCor",equationIndexes))) + 0.5;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    tmp109 = tmp107;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  }
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  (data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */) = tmp109;
#line 2702 OMC_FILE
  TRACE_POP
}
/*
equation index: 546
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.F1 = smooth(1, if noEvent((-HDifTil[1].briCoe.F13) * HDifTil[1].weaBus.solZen - HDifTil[1].briCoe.F11 - HDifTil[1].briCoe.F12 * HDifTil[1].skyBri.skyBri > 0.01) then 0.0 else if noEvent((-HDifTil[1].briCoe.F13) * HDifTil[1].weaBus.solZen - HDifTil[1].briCoe.F11 - HDifTil[1].briCoe.F12 * HDifTil[1].skyBri.skyBri < -0.01) then HDifTil[1].briCoe.F11 + HDifTil[1].briCoe.F12 * HDifTil[1].skyBri.skyBri + HDifTil[1].briCoe.F13 * HDifTil[1].weaBus.solZen else 0.25 * 100.0 * ((-HDifTil[1].briCoe.F13) * HDifTil[1].weaBus.solZen - HDifTil[1].briCoe.F11 - HDifTil[1].briCoe.F12 * HDifTil[1].skyBri.skyBri) * ((100.0 * ((-HDifTil[1].briCoe.F13) * HDifTil[1].weaBus.solZen - HDifTil[1].briCoe.F11 - HDifTil[1].briCoe.F12 * HDifTil[1].skyBri.skyBri)) ^ 2.0 - 3.0) * (HDifTil[1].briCoe.F11 + HDifTil[1].briCoe.F12 * HDifTil[1].skyBri.skyBri + HDifTil[1].briCoe.F13 * HDifTil[1].weaBus.solZen) + 0.5 * (HDifTil[1].briCoe.F11 + HDifTil[1].briCoe.F12 * HDifTil[1].skyBri.skyBri + HDifTil[1].briCoe.F13 * HDifTil[1].weaBus.solZen))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_546(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,546};
  modelica_boolean tmp110;
  modelica_boolean tmp111;
  modelica_real tmp112;
  modelica_boolean tmp113;
  modelica_real tmp114;
  modelica_boolean tmp115;
  modelica_real tmp116;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp110 = Greater(((-(data->localData[0]->realVars[44] /* HDifTil[1].briCoe.F13 variable */))) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - (data->localData[0]->realVars[40] /* HDifTil[1].briCoe.F11 variable */) - (((data->localData[0]->realVars[42] /* HDifTil[1].briCoe.F12 variable */)) * ((data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */))),0.01);
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp115 = (modelica_boolean)tmp110;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp115)
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp116 = 0.0;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp111 = Less(((-(data->localData[0]->realVars[44] /* HDifTil[1].briCoe.F13 variable */))) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - (data->localData[0]->realVars[40] /* HDifTil[1].briCoe.F11 variable */) - (((data->localData[0]->realVars[42] /* HDifTil[1].briCoe.F12 variable */)) * ((data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */))),-0.01);
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp113 = (modelica_boolean)tmp111;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp113)
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp114 = (data->localData[0]->realVars[40] /* HDifTil[1].briCoe.F11 variable */) + ((data->localData[0]->realVars[42] /* HDifTil[1].briCoe.F12 variable */)) * ((data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */)) + ((data->localData[0]->realVars[44] /* HDifTil[1].briCoe.F13 variable */)) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */));
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp112 = (100.0) * (((-(data->localData[0]->realVars[44] /* HDifTil[1].briCoe.F13 variable */))) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - (data->localData[0]->realVars[40] /* HDifTil[1].briCoe.F11 variable */) - (((data->localData[0]->realVars[42] /* HDifTil[1].briCoe.F12 variable */)) * ((data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */))));
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp114 = (0.25) * ((((100.0) * (((-(data->localData[0]->realVars[44] /* HDifTil[1].briCoe.F13 variable */))) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - (data->localData[0]->realVars[40] /* HDifTil[1].briCoe.F11 variable */) - (((data->localData[0]->realVars[42] /* HDifTil[1].briCoe.F12 variable */)) * ((data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */))))) * ((tmp112 * tmp112) - 3.0)) * ((data->localData[0]->realVars[40] /* HDifTil[1].briCoe.F11 variable */) + ((data->localData[0]->realVars[42] /* HDifTil[1].briCoe.F12 variable */)) * ((data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */)) + ((data->localData[0]->realVars[44] /* HDifTil[1].briCoe.F13 variable */)) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)))) + (0.5) * ((data->localData[0]->realVars[40] /* HDifTil[1].briCoe.F11 variable */) + ((data->localData[0]->realVars[42] /* HDifTil[1].briCoe.F12 variable */)) * ((data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */)) + ((data->localData[0]->realVars[44] /* HDifTil[1].briCoe.F13 variable */)) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)));
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp116 = tmp114;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[38] /* HDifTil[1].briCoe.F1 variable */) = tmp116;
#line 2765 OMC_FILE
  TRACE_POP
}
/*
equation index: 547
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.F2 = HDifTil[1].briCoe.F21 + HDifTil[1].briCoe.F22 * HDifTil[1].skyBri.skyBri + HDifTil[1].briCoe.F23 * HDifTil[1].weaBus.solZen
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_547(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,547};
#line 112 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[46] /* HDifTil[1].briCoe.F2 variable */) = (data->localData[0]->realVars[48] /* HDifTil[1].briCoe.F21 variable */) + ((data->localData[0]->realVars[50] /* HDifTil[1].briCoe.F22 variable */)) * ((data->localData[0]->realVars[110] /* HDifTil[1].skyBri.skyBri variable */)) + ((data->localData[0]->realVars[52] /* HDifTil[1].briCoe.F23 variable */)) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */));
#line 2779 OMC_FILE
  TRACE_POP
}
/*
equation index: 548
type: SIMPLE_ASSIGN
HDifTil[2].HDifTil.b = smooth(1, if noEvent(0.08715574274765814 - cos(HDifTil[1].weaBus.solZen) > 0.01) then 0.08715574274765814 else if noEvent(0.08715574274765814 - cos(HDifTil[1].weaBus.solZen) < -0.01) then cos(HDifTil[1].weaBus.solZen) else 0.25 * (8.715574274765814 - 100.0 * cos(HDifTil[1].weaBus.solZen)) * ((8.715574274765814 - 100.0 * cos(HDifTil[1].weaBus.solZen)) ^ 2.0 - 3.0) * (cos(HDifTil[1].weaBus.solZen) - 0.08715574274765814) + 0.04357787137382907 + 0.5 * cos(HDifTil[1].weaBus.solZen))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_548(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,548};
  modelica_boolean tmp117;
  modelica_boolean tmp118;
  modelica_real tmp119;
  modelica_boolean tmp120;
  modelica_real tmp121;
  modelica_boolean tmp122;
  modelica_real tmp123;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  tmp117 = Greater(0.08715574274765814 - cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)),0.01);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  tmp122 = (modelica_boolean)tmp117;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  if(tmp122)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp123 = 0.08715574274765814;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  else
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp118 = Less(0.08715574274765814 - cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)),-0.01);
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp120 = (modelica_boolean)tmp118;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    if(tmp120)
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp121 = cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */));
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    else
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    {
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp119 = 8.715574274765814 - ((100.0) * (cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */))));
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp121 = (0.25) * (((8.715574274765814 - ((100.0) * (cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */))))) * ((tmp119 * tmp119) - 3.0)) * (cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - 0.08715574274765814)) + 0.04357787137382907 + (0.5) * (cos((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)));
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp123 = tmp121;
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  }
#line 48 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  (data->localData[0]->realVars[33] /* HDifTil[2].HDifTil.b variable */) = tmp123;
#line 2842 OMC_FILE
  TRACE_POP
}
/*
equation index: 549
type: SIMPLE_ASSIGN
HDifTil[2].skyCle.tmp1 = 1.040895310738997 * HDifTil[1].weaBus.solZen ^ 3.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_549(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,549};
  modelica_real tmp124;
#line 32 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  tmp124 = (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */);
#line 32 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyClearness.mo"
  (data->localData[0]->realVars[117] /* HDifTil[2].skyCle.tmp1 variable */) = (1.040895310738997) * ((tmp124 * tmp124 * tmp124));
#line 2859 OMC_FILE
  TRACE_POP
}
/*
equation index: 550
type: SIMPLE_ASSIGN
HDifTil[2].skyCle.skyCle = Buildings.Utilities.Math.Functions.smoothLimit(((HDifTil[1].weaBus.HDirNor + HDifTil[2].skyCle.HDifHorBou) / HDifTil[2].skyCle.HDifHorBou + HDifTil[2].skyCle.tmp1) / (1.0 + HDifTil[2].skyCle.tmp1), 1.0, 8.0, 0.01)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_550(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,550};
  (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */) = omc_Buildings_Utilities_Math_Functions_smoothLimit(threadData, DIVISION_SIM(DIVISION_SIM((data->localData[0]->realVars[119] /* HDifTil[1].weaBus.HDirNor variable */) + (data->localData[0]->realVars[113] /* HDifTil[2].skyCle.HDifHorBou variable */),(data->localData[0]->realVars[113] /* HDifTil[2].skyCle.HDifHorBou variable */),"HDifTil[2].skyCle.HDifHorBou",equationIndexes) + (data->localData[0]->realVars[117] /* HDifTil[2].skyCle.tmp1 variable */),1.0 + (data->localData[0]->realVars[117] /* HDifTil[2].skyCle.tmp1 variable */),"1.0 + HDifTil[2].skyCle.tmp1",equationIndexes), 1.0, 8.0, 0.01);
  TRACE_POP
}
/*
equation index: 551
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.a1 = smooth(1, if noEvent(1.065 - HDifTil[2].skyCle.skyCle > 0.01) then 1.0 else if noEvent(1.065 - HDifTil[2].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((106.5 - 100.0 * HDifTil[2].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[2].skyCle.skyCle - 1.065) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_551(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,551};
  modelica_boolean tmp125;
  modelica_boolean tmp126;
  modelica_real tmp127;
  modelica_boolean tmp128;
  modelica_real tmp129;
  modelica_boolean tmp130;
  modelica_real tmp131;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp125 = Greater(1.065 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),0.01);
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp130 = (modelica_boolean)tmp125;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp130)
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp131 = 1.0;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp126 = Less(1.065 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),-0.01);
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp128 = (modelica_boolean)tmp126;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp128)
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp129 = 0.0;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp127 = 106.5 - ((100.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */)));
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp129 = (25.0) * (((tmp127 * tmp127) - 3.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */) - 1.065)) + 0.5;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp131 = tmp129;
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 45 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[55] /* HDifTil[2].briCoe.a1 variable */) = tmp131;
#line 2934 OMC_FILE
  TRACE_POP
}
/*
equation index: 552
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.b2 = smooth(1, if noEvent(1.23 - HDifTil[2].skyCle.skyCle > 0.01) then 1.0 else if noEvent(1.23 - HDifTil[2].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((123.0 - 100.0 * HDifTil[2].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[2].skyCle.skyCle - 1.23) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_552(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,552};
  modelica_boolean tmp132;
  modelica_boolean tmp133;
  modelica_real tmp134;
  modelica_boolean tmp135;
  modelica_real tmp136;
  modelica_boolean tmp137;
  modelica_real tmp138;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp132 = Greater(1.23 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),0.01);
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp137 = (modelica_boolean)tmp132;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp137)
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp138 = 1.0;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp133 = Less(1.23 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),-0.01);
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp135 = (modelica_boolean)tmp133;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp135)
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp136 = 0.0;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp134 = 123.0 - ((100.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */)));
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp136 = (25.0) * (((tmp134 * tmp134) - 3.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */) - 1.23)) + 0.5;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp138 = tmp136;
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 50 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[71] /* HDifTil[2].briCoe.b2 variable */) = tmp138;
#line 2997 OMC_FILE
  TRACE_POP
}
/*
equation index: 553
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.a2 = HDifTil[2].briCoe.b2 - HDifTil[2].briCoe.a1
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_553(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,553};
#line 88 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[57] /* HDifTil[2].briCoe.a2 variable */) = (data->localData[0]->realVars[71] /* HDifTil[2].briCoe.b2 variable */) - (data->localData[0]->realVars[55] /* HDifTil[2].briCoe.a1 variable */);
#line 3011 OMC_FILE
  TRACE_POP
}
/*
equation index: 554
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.b3 = smooth(1, if noEvent(1.5 - HDifTil[2].skyCle.skyCle > 0.01) then 1.0 else if noEvent(1.5 - HDifTil[2].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((150.0 - 100.0 * HDifTil[2].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[2].skyCle.skyCle - 1.5) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_554(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,554};
  modelica_boolean tmp139;
  modelica_boolean tmp140;
  modelica_real tmp141;
  modelica_boolean tmp142;
  modelica_real tmp143;
  modelica_boolean tmp144;
  modelica_real tmp145;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp139 = Greater(1.5 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),0.01);
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp144 = (modelica_boolean)tmp139;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp144)
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp145 = 1.0;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp140 = Less(1.5 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),-0.01);
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp142 = (modelica_boolean)tmp140;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp142)
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp143 = 0.0;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp141 = 150.0 - ((100.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */)));
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp143 = (25.0) * (((tmp141 * tmp141) - 3.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */) - 1.5)) + 0.5;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp145 = tmp143;
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 55 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[73] /* HDifTil[2].briCoe.b3 variable */) = tmp145;
#line 3074 OMC_FILE
  TRACE_POP
}
/*
equation index: 555
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.a3 = HDifTil[2].briCoe.b3 - HDifTil[2].briCoe.b2
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_555(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,555};
#line 89 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[59] /* HDifTil[2].briCoe.a3 variable */) = (data->localData[0]->realVars[73] /* HDifTil[2].briCoe.b3 variable */) - (data->localData[0]->realVars[71] /* HDifTil[2].briCoe.b2 variable */);
#line 3088 OMC_FILE
  TRACE_POP
}
/*
equation index: 556
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.b4 = smooth(1, if noEvent(1.95 - HDifTil[2].skyCle.skyCle > 0.01) then 1.0 else if noEvent(1.95 - HDifTil[2].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((195.0 - 100.0 * HDifTil[2].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[2].skyCle.skyCle - 1.95) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,556};
  modelica_boolean tmp146;
  modelica_boolean tmp147;
  modelica_real tmp148;
  modelica_boolean tmp149;
  modelica_real tmp150;
  modelica_boolean tmp151;
  modelica_real tmp152;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp146 = Greater(1.95 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),0.01);
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp151 = (modelica_boolean)tmp146;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp151)
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp152 = 1.0;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp147 = Less(1.95 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),-0.01);
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp149 = (modelica_boolean)tmp147;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp149)
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp150 = 0.0;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp148 = 195.0 - ((100.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */)));
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp150 = (25.0) * (((tmp148 * tmp148) - 3.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */) - 1.95)) + 0.5;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp152 = tmp150;
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 60 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[75] /* HDifTil[2].briCoe.b4 variable */) = tmp152;
#line 3151 OMC_FILE
  TRACE_POP
}
/*
equation index: 557
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.a4 = HDifTil[2].briCoe.b4 - HDifTil[2].briCoe.b3
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,557};
#line 90 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[61] /* HDifTil[2].briCoe.a4 variable */) = (data->localData[0]->realVars[75] /* HDifTil[2].briCoe.b4 variable */) - (data->localData[0]->realVars[73] /* HDifTil[2].briCoe.b3 variable */);
#line 3165 OMC_FILE
  TRACE_POP
}
/*
equation index: 558
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.b5 = smooth(1, if noEvent(2.8 - HDifTil[2].skyCle.skyCle > 0.01) then 1.0 else if noEvent(2.8 - HDifTil[2].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((280.0 - 100.0 * HDifTil[2].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[2].skyCle.skyCle - 2.8) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,558};
  modelica_boolean tmp153;
  modelica_boolean tmp154;
  modelica_real tmp155;
  modelica_boolean tmp156;
  modelica_real tmp157;
  modelica_boolean tmp158;
  modelica_real tmp159;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp153 = Greater(2.8 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),0.01);
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp158 = (modelica_boolean)tmp153;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp158)
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp159 = 1.0;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp154 = Less(2.8 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),-0.01);
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp156 = (modelica_boolean)tmp154;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp156)
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp157 = 0.0;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp155 = 280.0 - ((100.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */)));
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp157 = (25.0) * (((tmp155 * tmp155) - 3.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */) - 2.8)) + 0.5;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp159 = tmp157;
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 65 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[77] /* HDifTil[2].briCoe.b5 variable */) = tmp159;
#line 3228 OMC_FILE
  TRACE_POP
}
/*
equation index: 559
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.a5 = HDifTil[2].briCoe.b5 - HDifTil[2].briCoe.b4
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,559};
#line 91 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[63] /* HDifTil[2].briCoe.a5 variable */) = (data->localData[0]->realVars[77] /* HDifTil[2].briCoe.b5 variable */) - (data->localData[0]->realVars[75] /* HDifTil[2].briCoe.b4 variable */);
#line 3242 OMC_FILE
  TRACE_POP
}
/*
equation index: 560
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.b6 = smooth(1, if noEvent(4.5 - HDifTil[2].skyCle.skyCle > 0.01) then 1.0 else if noEvent(4.5 - HDifTil[2].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((450.0 - 100.0 * HDifTil[2].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[2].skyCle.skyCle - 4.5) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,560};
  modelica_boolean tmp160;
  modelica_boolean tmp161;
  modelica_real tmp162;
  modelica_boolean tmp163;
  modelica_real tmp164;
  modelica_boolean tmp165;
  modelica_real tmp166;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp160 = Greater(4.5 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),0.01);
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp165 = (modelica_boolean)tmp160;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp165)
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp166 = 1.0;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp161 = Less(4.5 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),-0.01);
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp163 = (modelica_boolean)tmp161;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp163)
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp164 = 0.0;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp162 = 450.0 - ((100.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */)));
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp164 = (25.0) * (((tmp162 * tmp162) - 3.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */) - 4.5)) + 0.5;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp166 = tmp164;
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 71 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[79] /* HDifTil[2].briCoe.b6 variable */) = tmp166;
#line 3305 OMC_FILE
  TRACE_POP
}
/*
equation index: 561
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.a6 = HDifTil[2].briCoe.b6 - HDifTil[2].briCoe.b5
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_561(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,561};
#line 92 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[65] /* HDifTil[2].briCoe.a6 variable */) = (data->localData[0]->realVars[79] /* HDifTil[2].briCoe.b6 variable */) - (data->localData[0]->realVars[77] /* HDifTil[2].briCoe.b5 variable */);
#line 3319 OMC_FILE
  TRACE_POP
}
/*
equation index: 562
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.b7 = smooth(1, if noEvent(6.2 - HDifTil[2].skyCle.skyCle > 0.01) then 1.0 else if noEvent(6.2 - HDifTil[2].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((620.0 - 100.0 * HDifTil[2].skyCle.skyCle) ^ 2.0 - 3.0) * (HDifTil[2].skyCle.skyCle - 6.2) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,562};
  modelica_boolean tmp167;
  modelica_boolean tmp168;
  modelica_real tmp169;
  modelica_boolean tmp170;
  modelica_real tmp171;
  modelica_boolean tmp172;
  modelica_real tmp173;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp167 = Greater(6.2 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),0.01);
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp172 = (modelica_boolean)tmp167;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp172)
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp173 = 1.0;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp168 = Less(6.2 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),-0.01);
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp170 = (modelica_boolean)tmp168;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp170)
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp171 = 0.0;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp169 = 620.0 - ((100.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */)));
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp171 = (25.0) * (((tmp169 * tmp169) - 3.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */) - 6.2)) + 0.5;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp173 = tmp171;
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 76 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[81] /* HDifTil[2].briCoe.b7 variable */) = tmp173;
#line 3382 OMC_FILE
  TRACE_POP
}
/*
equation index: 563
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.a7 = HDifTil[2].briCoe.b7 - HDifTil[2].briCoe.b6
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_563(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,563};
#line 93 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[67] /* HDifTil[2].briCoe.a7 variable */) = (data->localData[0]->realVars[81] /* HDifTil[2].briCoe.b7 variable */) - (data->localData[0]->realVars[79] /* HDifTil[2].briCoe.b6 variable */);
#line 3396 OMC_FILE
  TRACE_POP
}
/*
equation index: 564
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.a8 = smooth(1, if noEvent(-6.2 + HDifTil[2].skyCle.skyCle > 0.01) then 1.0 else if noEvent(-6.2 + HDifTil[2].skyCle.skyCle < -0.01) then 0.0 else 25.0 * ((-620.0 + 100.0 * HDifTil[2].skyCle.skyCle) ^ 2.0 - 3.0) * (6.2 - HDifTil[2].skyCle.skyCle) + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_564(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,564};
  modelica_boolean tmp174;
  modelica_boolean tmp175;
  modelica_real tmp176;
  modelica_boolean tmp177;
  modelica_real tmp178;
  modelica_boolean tmp179;
  modelica_real tmp180;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp174 = Greater(-6.2 + (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),0.01);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp179 = (modelica_boolean)tmp174;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp179)
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp180 = 1.0;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp175 = Less(-6.2 + (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */),-0.01);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp177 = (modelica_boolean)tmp175;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp177)
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp178 = 0.0;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp176 = -620.0 + (100.0) * ((data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */));
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp178 = (25.0) * (((tmp176 * tmp176) - 3.0) * (6.2 - (data->localData[0]->realVars[115] /* HDifTil[2].skyCle.skyCle variable */))) + 0.5;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp180 = tmp178;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[69] /* HDifTil[2].briCoe.a8 variable */) = tmp180;
#line 3459 OMC_FILE
  TRACE_POP
}
/*
equation index: 565
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.F11 = 0.1299457 * HDifTil[2].briCoe.a2 + (-0.0083117) * HDifTil[2].briCoe.a1 + 0.3296958 * HDifTil[2].briCoe.a3 + 0.5682053 * HDifTil[2].briCoe.a4 + 0.873028 * HDifTil[2].briCoe.a5 + 1.1326077 * HDifTil[2].briCoe.a6 + 1.0601591 * HDifTil[2].briCoe.a7 + 0.677747 * HDifTil[2].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_565(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,565};
#line 96 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[41] /* HDifTil[2].briCoe.F11 variable */) = (0.1299457) * ((data->localData[0]->realVars[57] /* HDifTil[2].briCoe.a2 variable */)) + (-0.0083117) * ((data->localData[0]->realVars[55] /* HDifTil[2].briCoe.a1 variable */)) + (0.3296958) * ((data->localData[0]->realVars[59] /* HDifTil[2].briCoe.a3 variable */)) + (0.5682053) * ((data->localData[0]->realVars[61] /* HDifTil[2].briCoe.a4 variable */)) + (0.873028) * ((data->localData[0]->realVars[63] /* HDifTil[2].briCoe.a5 variable */)) + (1.1326077) * ((data->localData[0]->realVars[65] /* HDifTil[2].briCoe.a6 variable */)) + (1.0601591) * ((data->localData[0]->realVars[67] /* HDifTil[2].briCoe.a7 variable */)) + (0.677747) * ((data->localData[0]->realVars[69] /* HDifTil[2].briCoe.a8 variable */));
#line 3473 OMC_FILE
  TRACE_POP
}
/*
equation index: 566
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.F12 = 0.5877285 * HDifTil[2].briCoe.a1 + 0.6825954 * HDifTil[2].briCoe.a2 + 0.4868735 * HDifTil[2].briCoe.a3 + 0.1874525 * HDifTil[2].briCoe.a4 + (-0.3920403) * HDifTil[2].briCoe.a5 + (-1.2367284) * HDifTil[2].briCoe.a6 + (-1.5999137) * HDifTil[2].briCoe.a7 + (-0.3272588) * HDifTil[2].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_566(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,566};
#line 98 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[43] /* HDifTil[2].briCoe.F12 variable */) = (0.5877285) * ((data->localData[0]->realVars[55] /* HDifTil[2].briCoe.a1 variable */)) + (0.6825954) * ((data->localData[0]->realVars[57] /* HDifTil[2].briCoe.a2 variable */)) + (0.4868735) * ((data->localData[0]->realVars[59] /* HDifTil[2].briCoe.a3 variable */)) + (0.1874525) * ((data->localData[0]->realVars[61] /* HDifTil[2].briCoe.a4 variable */)) + (-0.3920403) * ((data->localData[0]->realVars[63] /* HDifTil[2].briCoe.a5 variable */)) + (-1.2367284) * ((data->localData[0]->realVars[65] /* HDifTil[2].briCoe.a6 variable */)) + (-1.5999137) * ((data->localData[0]->realVars[67] /* HDifTil[2].briCoe.a7 variable */)) + (-0.3272588) * ((data->localData[0]->realVars[69] /* HDifTil[2].briCoe.a8 variable */));
#line 3487 OMC_FILE
  TRACE_POP
}
/*
equation index: 567
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.F13 = (-0.0620636) * HDifTil[2].briCoe.a1 + (-0.1513725) * HDifTil[2].briCoe.a2 + (-0.2210958) * HDifTil[2].briCoe.a3 + (-0.295129) * HDifTil[2].briCoe.a4 + (-0.3616149) * HDifTil[2].briCoe.a5 + (-0.4118494) * HDifTil[2].briCoe.a6 + (-0.3589221) * HDifTil[2].briCoe.a7 + (-0.2504286) * HDifTil[2].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_567(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,567};
#line 100 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[45] /* HDifTil[2].briCoe.F13 variable */) = (-0.0620636) * ((data->localData[0]->realVars[55] /* HDifTil[2].briCoe.a1 variable */)) + (-0.1513725) * ((data->localData[0]->realVars[57] /* HDifTil[2].briCoe.a2 variable */)) + (-0.2210958) * ((data->localData[0]->realVars[59] /* HDifTil[2].briCoe.a3 variable */)) + (-0.295129) * ((data->localData[0]->realVars[61] /* HDifTil[2].briCoe.a4 variable */)) + (-0.3616149) * ((data->localData[0]->realVars[63] /* HDifTil[2].briCoe.a5 variable */)) + (-0.4118494) * ((data->localData[0]->realVars[65] /* HDifTil[2].briCoe.a6 variable */)) + (-0.3589221) * ((data->localData[0]->realVars[67] /* HDifTil[2].briCoe.a7 variable */)) + (-0.2504286) * ((data->localData[0]->realVars[69] /* HDifTil[2].briCoe.a8 variable */));
#line 3501 OMC_FILE
  TRACE_POP
}
/*
equation index: 568
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.F21 = (-0.0596012) * HDifTil[2].briCoe.a1 + (-0.0189325) * HDifTil[2].briCoe.a2 + 0.055414 * HDifTil[2].briCoe.a3 + 0.1088631 * HDifTil[2].briCoe.a4 + 0.2255647 * HDifTil[2].briCoe.a5 + 0.2877813 * HDifTil[2].briCoe.a6 + 0.2642124 * HDifTil[2].briCoe.a7 + 0.1561313 * HDifTil[2].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_568(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,568};
#line 102 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[49] /* HDifTil[2].briCoe.F21 variable */) = (-0.0596012) * ((data->localData[0]->realVars[55] /* HDifTil[2].briCoe.a1 variable */)) + (-0.0189325) * ((data->localData[0]->realVars[57] /* HDifTil[2].briCoe.a2 variable */)) + (0.055414) * ((data->localData[0]->realVars[59] /* HDifTil[2].briCoe.a3 variable */)) + (0.1088631) * ((data->localData[0]->realVars[61] /* HDifTil[2].briCoe.a4 variable */)) + (0.2255647) * ((data->localData[0]->realVars[63] /* HDifTil[2].briCoe.a5 variable */)) + (0.2877813) * ((data->localData[0]->realVars[65] /* HDifTil[2].briCoe.a6 variable */)) + (0.2642124) * ((data->localData[0]->realVars[67] /* HDifTil[2].briCoe.a7 variable */)) + (0.1561313) * ((data->localData[0]->realVars[69] /* HDifTil[2].briCoe.a8 variable */));
#line 3515 OMC_FILE
  TRACE_POP
}
/*
equation index: 569
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.F22 = 0.07212490000000001 * HDifTil[2].briCoe.a1 + 0.065965 * HDifTil[2].briCoe.a2 + (-0.0639588) * HDifTil[2].briCoe.a3 + (-0.1519229) * HDifTil[2].briCoe.a4 + (-0.4620442) * HDifTil[2].briCoe.a5 + (-0.8230357) * HDifTil[2].briCoe.a6 + (-1.127234) * HDifTil[2].briCoe.a7 + (-1.3765031) * HDifTil[2].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_569(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,569};
#line 104 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[51] /* HDifTil[2].briCoe.F22 variable */) = (0.07212490000000001) * ((data->localData[0]->realVars[55] /* HDifTil[2].briCoe.a1 variable */)) + (0.065965) * ((data->localData[0]->realVars[57] /* HDifTil[2].briCoe.a2 variable */)) + (-0.0639588) * ((data->localData[0]->realVars[59] /* HDifTil[2].briCoe.a3 variable */)) + (-0.1519229) * ((data->localData[0]->realVars[61] /* HDifTil[2].briCoe.a4 variable */)) + (-0.4620442) * ((data->localData[0]->realVars[63] /* HDifTil[2].briCoe.a5 variable */)) + (-0.8230357) * ((data->localData[0]->realVars[65] /* HDifTil[2].briCoe.a6 variable */)) + (-1.127234) * ((data->localData[0]->realVars[67] /* HDifTil[2].briCoe.a7 variable */)) + (-1.3765031) * ((data->localData[0]->realVars[69] /* HDifTil[2].briCoe.a8 variable */));
#line 3529 OMC_FILE
  TRACE_POP
}
/*
equation index: 570
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.F23 = (-0.0220216) * HDifTil[2].briCoe.a1 + (-0.0288748) * HDifTil[2].briCoe.a2 + (-0.0260542) * HDifTil[2].briCoe.a3 + (-0.0139754) * HDifTil[2].briCoe.a4 + 0.0012448 * HDifTil[2].briCoe.a5 + 0.0558651 * HDifTil[2].briCoe.a6 + 0.1310694 * HDifTil[2].briCoe.a7 + 0.2506212 * HDifTil[2].briCoe.a8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_570(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,570};
#line 106 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[53] /* HDifTil[2].briCoe.F23 variable */) = (-0.0220216) * ((data->localData[0]->realVars[55] /* HDifTil[2].briCoe.a1 variable */)) + (-0.0288748) * ((data->localData[0]->realVars[57] /* HDifTil[2].briCoe.a2 variable */)) + (-0.0260542) * ((data->localData[0]->realVars[59] /* HDifTil[2].briCoe.a3 variable */)) + (-0.0139754) * ((data->localData[0]->realVars[61] /* HDifTil[2].briCoe.a4 variable */)) + (0.0012448) * ((data->localData[0]->realVars[63] /* HDifTil[2].briCoe.a5 variable */)) + (0.0558651) * ((data->localData[0]->realVars[65] /* HDifTil[2].briCoe.a6 variable */)) + (0.1310694) * ((data->localData[0]->realVars[67] /* HDifTil[2].briCoe.a7 variable */)) + (0.2506212) * ((data->localData[0]->realVars[69] /* HDifTil[2].briCoe.a8 variable */));
#line 3543 OMC_FILE
  TRACE_POP
}
/*
equation index: 571
type: SIMPLE_ASSIGN
HDifTil[2].relAirMas.zenLim = smooth(1, if noEvent(1.570796326794897 - HDifTil[1].weaBus.solZen > 0.01) then HDifTil[1].weaBus.solZen else if noEvent(1.570796326794897 - HDifTil[1].weaBus.solZen < -0.01) then 1.570796326794897 else 0.25 * (157.0796326794897 - 100.0 * HDifTil[1].weaBus.solZen) * ((157.0796326794897 - 100.0 * HDifTil[1].weaBus.solZen) ^ 2.0 - 3.0) * (1.570796326794897 - HDifTil[1].weaBus.solZen) + 0.5 * HDifTil[1].weaBus.solZen + 0.7853981633974483)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_571(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,571};
  modelica_boolean tmp181;
  modelica_boolean tmp182;
  modelica_real tmp183;
  modelica_boolean tmp184;
  modelica_real tmp185;
  modelica_boolean tmp186;
  modelica_real tmp187;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp181 = Greater(1.570796326794897 - (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */),0.01);
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp186 = (modelica_boolean)tmp181;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(tmp186)
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp187 = (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */);
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  else
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp182 = Less(1.570796326794897 - (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */),-0.01);
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp184 = (modelica_boolean)tmp182;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(tmp184)
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp185 = 1.570796326794897;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp183 = 157.0796326794897 - ((100.0) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)));
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp185 = (0.25) * (((157.0796326794897 - ((100.0) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)))) * ((tmp183 * tmp183) - 3.0)) * (1.570796326794897 - (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */))) + (0.5) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) + 0.7853981633974483;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp187 = tmp185;
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->localData[0]->realVars[107] /* HDifTil[2].relAirMas.zenLim variable */) = tmp187;
#line 3606 OMC_FILE
  TRACE_POP
}
/*
equation index: 572
type: SIMPLE_ASSIGN
HDifTil[2].relAirMas.zenDeg = 57.29577951308232 * HDifTil[2].relAirMas.zenLim
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_572(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,572};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->localData[0]->realVars[105] /* HDifTil[2].relAirMas.zenDeg variable */) = (57.29577951308232) * ((data->localData[0]->realVars[107] /* HDifTil[2].relAirMas.zenLim variable */));
#line 3620 OMC_FILE
  TRACE_POP
}
/*
equation index: 573
type: SIMPLE_ASSIGN
$cse17 = cos(HDifTil[2].relAirMas.zenLim)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_573(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,573};
  (data->localData[0]->realVars[18] /* $cse17 variable */) = cos((data->localData[0]->realVars[107] /* HDifTil[2].relAirMas.zenLim variable */));
  TRACE_POP
}
/*
equation index: 574
type: SIMPLE_ASSIGN
HDifTil[2].relAirMas.relAirMas = $cse14 / ($cse17 + 0.15 / (93.90000000000001 - HDifTil[2].relAirMas.zenDeg) ^ 1.253)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_574(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,574};
  modelica_real tmp188;
  modelica_real tmp189;
  modelica_real tmp190;
  modelica_real tmp191;
  modelica_real tmp192;
  modelica_real tmp193;
  modelica_real tmp194;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp188 = 93.90000000000001 - (data->localData[0]->realVars[105] /* HDifTil[2].relAirMas.zenDeg variable */);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp189 = 1.253;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(tmp188 < 0.0 && tmp189 != 0.0)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp191 = modf(tmp189, &tmp192);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(tmp191 > 0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp191 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp192 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else if(tmp191 < -0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp191 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp192 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(fabs(tmp191) < 1e-10)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp190 = pow(tmp188, tmp192);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp194 = modf(1.0/tmp189, &tmp193);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      if(tmp194 > 0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp194 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp193 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      else if(tmp194 < -0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp194 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp193 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      if(fabs(tmp194) < 1e-10 && ((unsigned long)tmp193 & 1))
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp190 = -pow(-tmp188, tmp191)*pow(tmp188, tmp192);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp188, tmp189);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp190 = pow(tmp188, tmp189);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(isnan(tmp190) || isinf(tmp190))
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp188, tmp189);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */) = DIVISION_SIM((data->simulationInfo->realParameter[1] /* $cse14 PARAM */),(data->localData[0]->realVars[18] /* $cse17 variable */) + DIVISION_SIM(0.15,tmp190,"(93.90000000000001 - HDifTil[2].relAirMas.zenDeg) ^ 1.253",equationIndexes),"$cse17 + 0.15 / (93.90000000000001 - HDifTil[2].relAirMas.zenDeg) ^ 1.253",equationIndexes);
#line 3753 OMC_FILE
  TRACE_POP
}
/*
equation index: 575
type: SIMPLE_ASSIGN
HDifTil[2].skyBri.skyBri = smooth(1, if noEvent(1.0 + (-0.0007320108337603397) * HDifTil[1].weaBus.HDifHor * HDifTil[2].relAirMas.relAirMas / HDifTil[2].skyBri.extRadCor > 0.025) then 0.0007320108337603397 * HDifTil[1].weaBus.HDifHor * HDifTil[2].relAirMas.relAirMas / HDifTil[2].skyBri.extRadCor else if noEvent(1.0 + (-0.0007320108337603397) * HDifTil[1].weaBus.HDifHor * HDifTil[2].relAirMas.relAirMas / HDifTil[2].skyBri.extRadCor < -0.025) then 1.0 else 0.25 * (40.0 + (-0.02928043335041359) * HDifTil[1].weaBus.HDifHor * HDifTil[2].relAirMas.relAirMas / HDifTil[2].skyBri.extRadCor) * ((40.0 + (-0.02928043335041359) * HDifTil[1].weaBus.HDifHor * HDifTil[2].relAirMas.relAirMas / HDifTil[2].skyBri.extRadCor) ^ 2.0 - 3.0) * (1.0 - 0.0007320108337603397 * HDifTil[1].weaBus.HDifHor * HDifTil[2].relAirMas.relAirMas / HDifTil[2].skyBri.extRadCor) + 0.0003660054168801698 * HDifTil[1].weaBus.HDifHor * HDifTil[2].relAirMas.relAirMas / HDifTil[2].skyBri.extRadCor + 0.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_575(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,575};
  modelica_boolean tmp195;
  modelica_boolean tmp196;
  modelica_real tmp197;
  modelica_boolean tmp198;
  modelica_real tmp199;
  modelica_boolean tmp200;
  modelica_real tmp201;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  tmp195 = Greater(1.0 + (-0.0007320108337603397) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */),(data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */),"HDifTil[2].skyBri.extRadCor",equationIndexes))),0.025);
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  tmp200 = (modelica_boolean)tmp195;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  if(tmp200)
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    tmp201 = (0.0007320108337603397) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */),(data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */),"HDifTil[2].skyBri.extRadCor",equationIndexes)));
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  }
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  else
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  {
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    tmp196 = Less(1.0 + (-0.0007320108337603397) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */),(data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */),"HDifTil[2].skyBri.extRadCor",equationIndexes))),-0.025);
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    tmp198 = (modelica_boolean)tmp196;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    if(tmp198)
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
      tmp199 = 1.0;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    else
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    {
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
      tmp197 = 40.0 + (-0.02928043335041359) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */),(data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */),"HDifTil[2].skyBri.extRadCor",equationIndexes)));
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
      tmp199 = (0.25) * (((40.0 + (-0.02928043335041359) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */),(data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */),"HDifTil[2].skyBri.extRadCor",equationIndexes)))) * ((tmp197 * tmp197) - 3.0)) * (1.0 - ((0.0007320108337603397) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */),(data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */),"HDifTil[2].skyBri.extRadCor",equationIndexes)))))) + (0.0003660054168801698) * (((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * (DIVISION_SIM((data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */),(data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */),"HDifTil[2].skyBri.extRadCor",equationIndexes))) + 0.5;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    }
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
    tmp201 = tmp199;
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  }
#line 22 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  (data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */) = tmp201;
#line 3816 OMC_FILE
  TRACE_POP
}
/*
equation index: 576
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.F1 = smooth(1, if noEvent((-HDifTil[2].briCoe.F13) * HDifTil[1].weaBus.solZen - HDifTil[2].briCoe.F11 - HDifTil[2].briCoe.F12 * HDifTil[2].skyBri.skyBri > 0.01) then 0.0 else if noEvent((-HDifTil[2].briCoe.F13) * HDifTil[1].weaBus.solZen - HDifTil[2].briCoe.F11 - HDifTil[2].briCoe.F12 * HDifTil[2].skyBri.skyBri < -0.01) then HDifTil[2].briCoe.F11 + HDifTil[2].briCoe.F12 * HDifTil[2].skyBri.skyBri + HDifTil[2].briCoe.F13 * HDifTil[1].weaBus.solZen else 0.25 * 100.0 * ((-HDifTil[2].briCoe.F13) * HDifTil[1].weaBus.solZen - HDifTil[2].briCoe.F11 - HDifTil[2].briCoe.F12 * HDifTil[2].skyBri.skyBri) * ((100.0 * ((-HDifTil[2].briCoe.F13) * HDifTil[1].weaBus.solZen - HDifTil[2].briCoe.F11 - HDifTil[2].briCoe.F12 * HDifTil[2].skyBri.skyBri)) ^ 2.0 - 3.0) * (HDifTil[2].briCoe.F11 + HDifTil[2].briCoe.F12 * HDifTil[2].skyBri.skyBri + HDifTil[2].briCoe.F13 * HDifTil[1].weaBus.solZen) + 0.5 * (HDifTil[2].briCoe.F11 + HDifTil[2].briCoe.F12 * HDifTil[2].skyBri.skyBri + HDifTil[2].briCoe.F13 * HDifTil[1].weaBus.solZen))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_576(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,576};
  modelica_boolean tmp202;
  modelica_boolean tmp203;
  modelica_real tmp204;
  modelica_boolean tmp205;
  modelica_real tmp206;
  modelica_boolean tmp207;
  modelica_real tmp208;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp202 = Greater(((-(data->localData[0]->realVars[45] /* HDifTil[2].briCoe.F13 variable */))) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - (data->localData[0]->realVars[41] /* HDifTil[2].briCoe.F11 variable */) - (((data->localData[0]->realVars[43] /* HDifTil[2].briCoe.F12 variable */)) * ((data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */))),0.01);
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  tmp207 = (modelica_boolean)tmp202;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  if(tmp207)
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp208 = 0.0;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  else
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  {
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp203 = Less(((-(data->localData[0]->realVars[45] /* HDifTil[2].briCoe.F13 variable */))) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - (data->localData[0]->realVars[41] /* HDifTil[2].briCoe.F11 variable */) - (((data->localData[0]->realVars[43] /* HDifTil[2].briCoe.F12 variable */)) * ((data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */))),-0.01);
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp205 = (modelica_boolean)tmp203;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    if(tmp205)
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp206 = (data->localData[0]->realVars[41] /* HDifTil[2].briCoe.F11 variable */) + ((data->localData[0]->realVars[43] /* HDifTil[2].briCoe.F12 variable */)) * ((data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */)) + ((data->localData[0]->realVars[45] /* HDifTil[2].briCoe.F13 variable */)) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */));
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    else
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    {
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp204 = (100.0) * (((-(data->localData[0]->realVars[45] /* HDifTil[2].briCoe.F13 variable */))) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - (data->localData[0]->realVars[41] /* HDifTil[2].briCoe.F11 variable */) - (((data->localData[0]->realVars[43] /* HDifTil[2].briCoe.F12 variable */)) * ((data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */))));
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
      tmp206 = (0.25) * ((((100.0) * (((-(data->localData[0]->realVars[45] /* HDifTil[2].briCoe.F13 variable */))) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)) - (data->localData[0]->realVars[41] /* HDifTil[2].briCoe.F11 variable */) - (((data->localData[0]->realVars[43] /* HDifTil[2].briCoe.F12 variable */)) * ((data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */))))) * ((tmp204 * tmp204) - 3.0)) * ((data->localData[0]->realVars[41] /* HDifTil[2].briCoe.F11 variable */) + ((data->localData[0]->realVars[43] /* HDifTil[2].briCoe.F12 variable */)) * ((data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */)) + ((data->localData[0]->realVars[45] /* HDifTil[2].briCoe.F13 variable */)) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)))) + (0.5) * ((data->localData[0]->realVars[41] /* HDifTil[2].briCoe.F11 variable */) + ((data->localData[0]->realVars[43] /* HDifTil[2].briCoe.F12 variable */)) * ((data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */)) + ((data->localData[0]->realVars[45] /* HDifTil[2].briCoe.F13 variable */)) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */)));
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    }
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
    tmp208 = tmp206;
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  }
#line 108 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[39] /* HDifTil[2].briCoe.F1 variable */) = tmp208;
#line 3879 OMC_FILE
  TRACE_POP
}
/*
equation index: 577
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.F2 = HDifTil[2].briCoe.F21 + HDifTil[2].briCoe.F22 * HDifTil[2].skyBri.skyBri + HDifTil[2].briCoe.F23 * HDifTil[1].weaBus.solZen
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_577(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,577};
#line 112 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[47] /* HDifTil[2].briCoe.F2 variable */) = (data->localData[0]->realVars[49] /* HDifTil[2].briCoe.F21 variable */) + ((data->localData[0]->realVars[51] /* HDifTil[2].briCoe.F22 variable */)) * ((data->localData[0]->realVars[111] /* HDifTil[2].skyBri.skyBri variable */)) + ((data->localData[0]->realVars[53] /* HDifTil[2].briCoe.F23 variable */)) * ((data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */));
#line 3893 OMC_FILE
  TRACE_POP
}
/*
equation index: 578
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.dec_s = sin(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_578(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,578};
  (data->localData[0]->realVars[88] /* HDifTil[1].incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 579
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.dec_c = cos(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_579(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,579};
  (data->localData[0]->realVars[86] /* HDifTil[1].incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 580
type: SIMPLE_ASSIGN
HDifTil[1].incAng.y = acos((-3.491481338843133e-15) * (HDifTil[1].incAng.incAng.dec_c * HDifTil[1].incAng.incAng.sol_c * HDifTil[1].incAng.incAng.lat_c + HDifTil[1].incAng.incAng.dec_s * HDifTil[1].incAng.incAng.lat_s) + (-6.982962677686267e-15) * HDifTil[1].incAng.incAng.dec_c * HDifTil[1].incAng.incAng.sol_s - (HDifTil[1].incAng.incAng.dec_c * HDifTil[1].incAng.incAng.sol_c * HDifTil[1].incAng.incAng.lat_s - HDifTil[1].incAng.incAng.dec_s * HDifTil[1].incAng.incAng.lat_c))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_580(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,580};
  modelica_real tmp209;
  tmp209 = (-3.491481338843133e-15) * ((((data->localData[0]->realVars[86] /* HDifTil[1].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[94] /* HDifTil[1].incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[90] /* HDifTil[1].incAng.incAng.lat_c variable */)) + ((data->localData[0]->realVars[88] /* HDifTil[1].incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[92] /* HDifTil[1].incAng.incAng.lat_s variable */))) + ((-6.982962677686267e-15) * ((data->localData[0]->realVars[86] /* HDifTil[1].incAng.incAng.dec_c variable */))) * ((data->localData[0]->realVars[96] /* HDifTil[1].incAng.incAng.sol_s variable */)) - ((((data->localData[0]->realVars[86] /* HDifTil[1].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[94] /* HDifTil[1].incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[92] /* HDifTil[1].incAng.incAng.lat_s variable */)) - (((data->localData[0]->realVars[88] /* HDifTil[1].incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[90] /* HDifTil[1].incAng.incAng.lat_c variable */))));
  if(!(tmp209 >= -1.0 && tmp209 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos((-3.491481338843133e-15) * (HDifTil[1].incAng.incAng.dec_c * HDifTil[1].incAng.incAng.sol_c * HDifTil[1].incAng.incAng.lat_c + HDifTil[1].incAng.incAng.dec_s * HDifTil[1].incAng.incAng.lat_s) + (-6.982962677686267e-15) * HDifTil[1].incAng.incAng.dec_c * HDifTil[1].incAng.incAng.sol_s - (HDifTil[1].incAng.incAng.dec_c * HDifTil[1].incAng.incAng.sol_c * HDifTil[1].incAng.incAng.lat_s - HDifTil[1].incAng.incAng.dec_s * HDifTil[1].incAng.incAng.lat_c)) outside the domain -1.0 <= %g <= 1.0", tmp209);
    }
  }
  (data->localData[0]->realVars[100] /* HDifTil[1].incAng.y variable */) = acos(tmp209);
  TRACE_POP
}
/*
equation index: 581
type: SIMPLE_ASSIGN
HDifTil[1].HDifTil.a = smooth(1, if noEvent((-cos(HDifTil[1].incAng.y)) > 0.01) then 0.0 else if noEvent((-cos(HDifTil[1].incAng.y)) < -0.01) then cos(HDifTil[1].incAng.y) else 0.25 * (-100.0) * cos(HDifTil[1].incAng.y) * (((-100.0) * cos(HDifTil[1].incAng.y)) ^ 2.0 - 3.0) * cos(HDifTil[1].incAng.y) + 0.5 * cos(HDifTil[1].incAng.y))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_581(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,581};
  modelica_boolean tmp210;
  modelica_boolean tmp211;
  modelica_real tmp212;
  modelica_boolean tmp213;
  modelica_real tmp214;
  modelica_boolean tmp215;
  modelica_real tmp216;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  tmp210 = Greater((-cos((data->localData[0]->realVars[100] /* HDifTil[1].incAng.y variable */))),0.01);
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  tmp215 = (modelica_boolean)tmp210;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  if(tmp215)
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  {
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp216 = 0.0;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  }
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  else
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  {
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp211 = Less((-cos((data->localData[0]->realVars[100] /* HDifTil[1].incAng.y variable */))),-0.01);
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp213 = (modelica_boolean)tmp211;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    if(tmp213)
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    {
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp214 = cos((data->localData[0]->realVars[100] /* HDifTil[1].incAng.y variable */));
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    }
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    else
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    {
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp212 = (-100.0) * (cos((data->localData[0]->realVars[100] /* HDifTil[1].incAng.y variable */)));
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp214 = (0.25) * ((((-100.0) * (cos((data->localData[0]->realVars[100] /* HDifTil[1].incAng.y variable */)))) * ((tmp212 * tmp212) - 3.0)) * (cos((data->localData[0]->realVars[100] /* HDifTil[1].incAng.y variable */)))) + (0.5) * (cos((data->localData[0]->realVars[100] /* HDifTil[1].incAng.y variable */)));
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    }
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp216 = tmp214;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  }
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  (data->localData[0]->realVars[30] /* HDifTil[1].HDifTil.a variable */) = tmp216;
#line 4006 OMC_FILE
  TRACE_POP
}
/*
equation index: 582
type: SIMPLE_ASSIGN
HDifTil[1].HSkyDifTil = HDifTil[1].weaBus.HDifHor * (0.4999999999999983 * (1.0 - HDifTil[1].briCoe.F1) + HDifTil[1].briCoe.F1 * HDifTil[1].HDifTil.a / HDifTil[1].HDifTil.b + HDifTil[1].briCoe.F2)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_582(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,582};
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  (data->localData[0]->realVars[36] /* HDifTil[1].HSkyDifTil variable */) = ((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * ((0.4999999999999983) * (1.0 - (data->localData[0]->realVars[38] /* HDifTil[1].briCoe.F1 variable */)) + ((data->localData[0]->realVars[38] /* HDifTil[1].briCoe.F1 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[30] /* HDifTil[1].HDifTil.a variable */),(data->localData[0]->realVars[32] /* HDifTil[1].HDifTil.b variable */),"HDifTil[1].HDifTil.b",equationIndexes)) + (data->localData[0]->realVars[46] /* HDifTil[1].briCoe.F2 variable */));
#line 4020 OMC_FILE
  TRACE_POP
}
/*
equation index: 583
type: SIMPLE_ASSIGN
HDifTil[1].H = HDifTil[1].HSkyDifTil + HDifTil[1].HGroDifTil
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_583(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,583};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[28] /* HDifTil[1].H variable */) = (data->localData[0]->realVars[36] /* HDifTil[1].HSkyDifTil variable */) + (data->localData[0]->realVars[34] /* HDifTil[1].HGroDifTil variable */);
#line 4034 OMC_FILE
  TRACE_POP
}
/*
equation index: 584
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.dec_s = sin(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_584(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,584};
  (data->localData[0]->realVars[89] /* HDifTil[2].incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 585
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.dec_c = cos(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_585(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,585};
  (data->localData[0]->realVars[87] /* HDifTil[2].incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 586
type: SIMPLE_ASSIGN
HDifTil[2].incAng.y = acos((-3.491481338843133e-15) * (HDifTil[2].incAng.incAng.dec_c * HDifTil[2].incAng.incAng.sol_c * HDifTil[2].incAng.incAng.lat_c + HDifTil[2].incAng.incAng.dec_s * HDifTil[2].incAng.incAng.lat_s) + 1.04744440165294e-14 * (HDifTil[2].incAng.incAng.dec_c * HDifTil[2].incAng.incAng.sol_c * HDifTil[2].incAng.incAng.lat_s - HDifTil[2].incAng.incAng.dec_s * HDifTil[2].incAng.incAng.lat_c) - HDifTil[2].incAng.incAng.dec_c * HDifTil[2].incAng.incAng.sol_s)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_586(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,586};
  modelica_real tmp217;
  tmp217 = (-3.491481338843133e-15) * ((((data->localData[0]->realVars[87] /* HDifTil[2].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[95] /* HDifTil[2].incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[91] /* HDifTil[2].incAng.incAng.lat_c variable */)) + ((data->localData[0]->realVars[89] /* HDifTil[2].incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[93] /* HDifTil[2].incAng.incAng.lat_s variable */))) + (1.04744440165294e-14) * ((((data->localData[0]->realVars[87] /* HDifTil[2].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[95] /* HDifTil[2].incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[93] /* HDifTil[2].incAng.incAng.lat_s variable */)) - (((data->localData[0]->realVars[89] /* HDifTil[2].incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[91] /* HDifTil[2].incAng.incAng.lat_c variable */)))) - (((data->localData[0]->realVars[87] /* HDifTil[2].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[97] /* HDifTil[2].incAng.incAng.sol_s variable */)));
  if(!(tmp217 >= -1.0 && tmp217 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos((-3.491481338843133e-15) * (HDifTil[2].incAng.incAng.dec_c * HDifTil[2].incAng.incAng.sol_c * HDifTil[2].incAng.incAng.lat_c + HDifTil[2].incAng.incAng.dec_s * HDifTil[2].incAng.incAng.lat_s) + 1.04744440165294e-14 * (HDifTil[2].incAng.incAng.dec_c * HDifTil[2].incAng.incAng.sol_c * HDifTil[2].incAng.incAng.lat_s - HDifTil[2].incAng.incAng.dec_s * HDifTil[2].incAng.incAng.lat_c) - HDifTil[2].incAng.incAng.dec_c * HDifTil[2].incAng.incAng.sol_s) outside the domain -1.0 <= %g <= 1.0", tmp217);
    }
  }
  (data->localData[0]->realVars[101] /* HDifTil[2].incAng.y variable */) = acos(tmp217);
  TRACE_POP
}
/*
equation index: 587
type: SIMPLE_ASSIGN
HDifTil[2].HDifTil.a = smooth(1, if noEvent((-cos(HDifTil[2].incAng.y)) > 0.01) then 0.0 else if noEvent((-cos(HDifTil[2].incAng.y)) < -0.01) then cos(HDifTil[2].incAng.y) else 0.25 * (-100.0) * cos(HDifTil[2].incAng.y) * (((-100.0) * cos(HDifTil[2].incAng.y)) ^ 2.0 - 3.0) * cos(HDifTil[2].incAng.y) + 0.5 * cos(HDifTil[2].incAng.y))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_587(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,587};
  modelica_boolean tmp218;
  modelica_boolean tmp219;
  modelica_real tmp220;
  modelica_boolean tmp221;
  modelica_real tmp222;
  modelica_boolean tmp223;
  modelica_real tmp224;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  tmp218 = Greater((-cos((data->localData[0]->realVars[101] /* HDifTil[2].incAng.y variable */))),0.01);
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  tmp223 = (modelica_boolean)tmp218;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  if(tmp223)
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  {
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp224 = 0.0;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  }
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  else
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  {
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp219 = Less((-cos((data->localData[0]->realVars[101] /* HDifTil[2].incAng.y variable */))),-0.01);
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp221 = (modelica_boolean)tmp219;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    if(tmp221)
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    {
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp222 = cos((data->localData[0]->realVars[101] /* HDifTil[2].incAng.y variable */));
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    }
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    else
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    {
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp220 = (-100.0) * (cos((data->localData[0]->realVars[101] /* HDifTil[2].incAng.y variable */)));
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
      tmp222 = (0.25) * ((((-100.0) * (cos((data->localData[0]->realVars[101] /* HDifTil[2].incAng.y variable */)))) * ((tmp220 * tmp220) - 3.0)) * (cos((data->localData[0]->realVars[101] /* HDifTil[2].incAng.y variable */)))) + (0.5) * (cos((data->localData[0]->realVars[101] /* HDifTil[2].incAng.y variable */)));
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    }
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
    tmp224 = tmp222;
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  }
#line 44 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  (data->localData[0]->realVars[31] /* HDifTil[2].HDifTil.a variable */) = tmp224;
#line 4147 OMC_FILE
  TRACE_POP
}
/*
equation index: 588
type: SIMPLE_ASSIGN
HDifTil[2].HSkyDifTil = HDifTil[1].weaBus.HDifHor * (0.4999999999999983 * (1.0 - HDifTil[2].briCoe.F1) + HDifTil[2].briCoe.F1 * HDifTil[2].HDifTil.a / HDifTil[2].HDifTil.b + HDifTil[2].briCoe.F2)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,588};
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffusePerez.mo"
  (data->localData[0]->realVars[37] /* HDifTil[2].HSkyDifTil variable */) = ((data->localData[0]->realVars[118] /* HDifTil[1].weaBus.HDifHor variable */)) * ((0.4999999999999983) * (1.0 - (data->localData[0]->realVars[39] /* HDifTil[2].briCoe.F1 variable */)) + ((data->localData[0]->realVars[39] /* HDifTil[2].briCoe.F1 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[31] /* HDifTil[2].HDifTil.a variable */),(data->localData[0]->realVars[33] /* HDifTil[2].HDifTil.b variable */),"HDifTil[2].HDifTil.b",equationIndexes)) + (data->localData[0]->realVars[47] /* HDifTil[2].briCoe.F2 variable */));
#line 4161 OMC_FILE
  TRACE_POP
}
/*
equation index: 589
type: SIMPLE_ASSIGN
HDifTil[2].H = HDifTil[2].HSkyDifTil + HDifTil[2].HGroDifTil
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_589(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,589};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[29] /* HDifTil[2].H variable */) = (data->localData[0]->realVars[37] /* HDifTil[2].HSkyDifTil variable */) + (data->localData[0]->realVars[35] /* HDifTil[2].HGroDifTil variable */);
#line 4175 OMC_FILE
  TRACE_POP
}
/*
equation index: 590
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.dec_s = sin(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_590(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,590};
  (data->localData[0]->realVars[141] /* HDirTil[1].incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 591
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.dec_c = cos(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_591(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,591};
  (data->localData[0]->realVars[139] /* HDirTil[1].incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 592
type: SIMPLE_ASSIGN
HDirTil[1].inc = acos((-3.491481338843133e-15) * (HDirTil[1].incAng.incAng.dec_c * HDirTil[1].incAng.incAng.sol_c * HDirTil[1].incAng.incAng.lat_c + HDirTil[1].incAng.incAng.dec_s * HDirTil[1].incAng.incAng.lat_s) + (-6.982962677686267e-15) * HDirTil[1].incAng.incAng.dec_c * HDirTil[1].incAng.incAng.sol_s - (HDirTil[1].incAng.incAng.dec_c * HDirTil[1].incAng.incAng.sol_c * HDirTil[1].incAng.incAng.lat_s - HDirTil[1].incAng.incAng.dec_s * HDirTil[1].incAng.incAng.lat_c))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_592(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,592};
  modelica_real tmp225;
  tmp225 = (-3.491481338843133e-15) * ((((data->localData[0]->realVars[139] /* HDirTil[1].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[147] /* HDirTil[1].incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[143] /* HDirTil[1].incAng.incAng.lat_c variable */)) + ((data->localData[0]->realVars[141] /* HDirTil[1].incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[145] /* HDirTil[1].incAng.incAng.lat_s variable */))) + ((-6.982962677686267e-15) * ((data->localData[0]->realVars[139] /* HDirTil[1].incAng.incAng.dec_c variable */))) * ((data->localData[0]->realVars[149] /* HDirTil[1].incAng.incAng.sol_s variable */)) - ((((data->localData[0]->realVars[139] /* HDirTil[1].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[147] /* HDirTil[1].incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[145] /* HDirTil[1].incAng.incAng.lat_s variable */)) - (((data->localData[0]->realVars[141] /* HDirTil[1].incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[143] /* HDirTil[1].incAng.incAng.lat_c variable */))));
  if(!(tmp225 >= -1.0 && tmp225 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos((-3.491481338843133e-15) * (HDirTil[1].incAng.incAng.dec_c * HDirTil[1].incAng.incAng.sol_c * HDirTil[1].incAng.incAng.lat_c + HDirTil[1].incAng.incAng.dec_s * HDirTil[1].incAng.incAng.lat_s) + (-6.982962677686267e-15) * HDirTil[1].incAng.incAng.dec_c * HDirTil[1].incAng.incAng.sol_s - (HDirTil[1].incAng.incAng.dec_c * HDirTil[1].incAng.incAng.sol_c * HDirTil[1].incAng.incAng.lat_s - HDirTil[1].incAng.incAng.dec_s * HDirTil[1].incAng.incAng.lat_c)) outside the domain -1.0 <= %g <= 1.0", tmp225);
    }
  }
  (data->localData[0]->realVars[135] /* HDirTil[1].inc variable */) = acos(tmp225);
  TRACE_POP
}
/*
equation index: 593
type: SIMPLE_ASSIGN
corGDouPan.Ta_dir[1] = 0.918 + 57.29577951308232 * (0.000221 + 57.29577951308232 * (-2.75e-05 + 57.29577951308232 * (-3.82e-07 + 57.29577951308232 * (5.83e-08 + 57.29577951308232 * (-1.15e-09 + 2.715819948920102e-10 * HDirTil[1].inc) * HDirTil[1].inc) * HDirTil[1].inc) * HDirTil[1].inc) * HDirTil[1].inc) * HDirTil[1].inc
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_593(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,593};
#line 90 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[170] /* corGDouPan.Ta_dir[1] variable */) = 0.918 + (57.29577951308232) * ((0.000221 + (57.29577951308232) * ((-2.75e-05 + (57.29577951308232) * ((-3.82e-07 + (57.29577951308232) * ((5.83e-08 + (57.29577951308232) * ((-1.15e-09 + (2.715819948920102e-10) * ((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */))) * ((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */)))) * ((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */)))) * ((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */)))) * ((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */)))) * ((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */)));
#line 4239 OMC_FILE
  TRACE_POP
}
/*
equation index: 594
type: SIMPLE_ASSIGN
corGDouPan.rho_T1_dir[1] = 1.0 - corGDouPan.Ta_dir[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_594(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,594};
#line 94 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[182] /* corGDouPan.rho_T1_dir[1] variable */) = 1.0 - (data->localData[0]->realVars[170] /* corGDouPan.Ta_dir[1] variable */);
#line 4253 OMC_FILE
  TRACE_POP
}
/*
equation index: 595
type: SIMPLE_ASSIGN
corGDouPan.rho_11_dir[1] = corGDouPan.rho_T1_dir[1] / (2.0 - corGDouPan.rho_T1_dir[1])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_595(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,595};
#line 95 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[178] /* corGDouPan.rho_11_dir[1] variable */) = DIVISION_SIM((data->localData[0]->realVars[182] /* corGDouPan.rho_T1_dir[1] variable */),2.0 - (data->localData[0]->realVars[182] /* corGDouPan.rho_T1_dir[1] variable */),"2.0 - corGDouPan.rho_T1_dir[1]",equationIndexes);
#line 4267 OMC_FILE
  TRACE_POP
}
/*
equation index: 596
type: SIMPLE_ASSIGN
corGDouPan.Tai_dir[1] = 0.907 ^ (1.0 / sqrt(1.0 - (sin(HDirTil[1].inc) / 1.515) ^ 2.0))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_596(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,596};
  modelica_real tmp226;
  modelica_real tmp227;
  modelica_real tmp228;
  modelica_real tmp229;
  modelica_real tmp230;
  modelica_real tmp231;
  modelica_real tmp232;
  modelica_real tmp233;
  modelica_real tmp234;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp226 = DIVISION_SIM(sin((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */)),1.515,"1.515",equationIndexes);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp227 = 1.0 - ((tmp226 * tmp226));
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  if(!(tmp227 >= 0.0))
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      data->simulationInfo->needToReThrow = 1;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    } else {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(1.0 - (sin(HDirTil[1].inc) / 1.515) ^ 2.0) was %g should be >= 0", tmp227);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  }tmp228 = 0.907;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp229 = DIVISION_SIM(1.0,sqrt(tmp227),"sqrt(1.0 - (sin(HDirTil[1].inc) / 1.515) ^ 2.0)",equationIndexes);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  if(tmp228 < 0.0 && tmp229 != 0.0)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    tmp231 = modf(tmp229, &tmp232);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    if(tmp231 > 0.5)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp231 -= 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp232 += 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    else if(tmp231 < -0.5)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp231 += 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp232 -= 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    if(fabs(tmp231) < 1e-10)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp230 = pow(tmp228, tmp232);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    else
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp234 = modf(1.0/tmp229, &tmp233);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      if(tmp234 > 0.5)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp234 -= 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp233 += 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      else if(tmp234 < -0.5)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp234 += 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp233 -= 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      if(fabs(tmp234) < 1e-10 && ((unsigned long)tmp233 & 1))
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp230 = -pow(-tmp228, tmp231)*pow(tmp228, tmp232);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      else
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp228, tmp229);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  else
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    tmp230 = pow(tmp228, tmp229);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  if(isnan(tmp230) || isinf(tmp230))
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp228, tmp229);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[172] /* corGDouPan.Tai_dir[1] variable */) = tmp230;
#line 4416 OMC_FILE
  TRACE_POP
}
/*
equation index: 597
type: SIMPLE_ASSIGN
corGDouPan.Ta1_dir[1] = corGDouPan.Ta_dir[1] * corGDouPan.Tai_dir[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_597(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,597};
#line 93 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[166] /* corGDouPan.Ta1_dir[1] variable */) = ((data->localData[0]->realVars[170] /* corGDouPan.Ta_dir[1] variable */)) * ((data->localData[0]->realVars[172] /* corGDouPan.Tai_dir[1] variable */));
#line 4430 OMC_FILE
  TRACE_POP
}
/*
equation index: 598
type: SIMPLE_ASSIGN
corGDouPan.rho_1_dir[1] = corGDouPan.rho_11_dir[1] + ((1.0 - corGDouPan.rho_11_dir[1]) * corGDouPan.Tai_dir[1]) ^ 2.0 * corGDouPan.rho_11_dir[1] / (1.0 - (corGDouPan.rho_11_dir[1] * corGDouPan.Tai_dir[1]) ^ 2.0)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_598(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,598};
  modelica_real tmp235;
  modelica_real tmp236;
#line 96 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp235 = (1.0 - (data->localData[0]->realVars[178] /* corGDouPan.rho_11_dir[1] variable */)) * ((data->localData[0]->realVars[172] /* corGDouPan.Tai_dir[1] variable */));
#line 96 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp236 = ((data->localData[0]->realVars[178] /* corGDouPan.rho_11_dir[1] variable */)) * ((data->localData[0]->realVars[172] /* corGDouPan.Tai_dir[1] variable */));
#line 96 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[180] /* corGDouPan.rho_1_dir[1] variable */) = (data->localData[0]->realVars[178] /* corGDouPan.rho_11_dir[1] variable */) + ((tmp235 * tmp235)) * (DIVISION_SIM((data->localData[0]->realVars[178] /* corGDouPan.rho_11_dir[1] variable */),1.0 - ((tmp236 * tmp236)),"1.0 - (corGDouPan.rho_11_dir[1] * corGDouPan.Tai_dir[1]) ^ 2.0",equationIndexes));
#line 4450 OMC_FILE
  TRACE_POP
}
/*
equation index: 599
type: SIMPLE_ASSIGN
corGDouPan.a1_dir[1] = 1.0 - (corGDouPan.Ta1_dir[1] + corGDouPan.rho_1_dir[1])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_599(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,599};
#line 98 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[176] /* corGDouPan.a1_dir[1] variable */) = 1.0 - ((data->localData[0]->realVars[166] /* corGDouPan.Ta1_dir[1] variable */) + (data->localData[0]->realVars[180] /* corGDouPan.rho_1_dir[1] variable */));
#line 4464 OMC_FILE
  TRACE_POP
}
/*
equation index: 600
type: SIMPLE_ASSIGN
corGDouPan.XN2_dir[1] = 1.0 - corGDouPan.rho_1_dir[1] ^ 2.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_600(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,600};
  modelica_real tmp237;
#line 99 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp237 = (data->localData[0]->realVars[180] /* corGDouPan.rho_1_dir[1] variable */);
#line 99 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[174] /* corGDouPan.XN2_dir[1] variable */) = 1.0 - ((tmp237 * tmp237));
#line 4481 OMC_FILE
  TRACE_POP
}
/*
equation index: 601
type: SIMPLE_ASSIGN
corGDouPan.Q22_dir[1] = 0.7272727272727273 * corGDouPan.a1_dir[1] * corGDouPan.Ta1_dir[1] / corGDouPan.XN2_dir[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_601(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,601};
#line 101 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[162] /* corGDouPan.Q22_dir[1] variable */) = (0.7272727272727273) * (((data->localData[0]->realVars[176] /* corGDouPan.a1_dir[1] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[166] /* corGDouPan.Ta1_dir[1] variable */),(data->localData[0]->realVars[174] /* corGDouPan.XN2_dir[1] variable */),"corGDouPan.XN2_dir[1]",equationIndexes)));
#line 4495 OMC_FILE
  TRACE_POP
}
/*
equation index: 602
type: SIMPLE_ASSIGN
corGDouPan.Ta2_dir[1] = corGDouPan.Ta1_dir[1] ^ 2.0 / corGDouPan.XN2_dir[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_602(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,602};
  modelica_real tmp238;
#line 103 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp238 = (data->localData[0]->realVars[166] /* corGDouPan.Ta1_dir[1] variable */);
#line 103 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[168] /* corGDouPan.Ta2_dir[1] variable */) = DIVISION_SIM((tmp238 * tmp238),(data->localData[0]->realVars[174] /* corGDouPan.XN2_dir[1] variable */),"corGDouPan.XN2_dir[1]",equationIndexes);
#line 4512 OMC_FILE
  TRACE_POP
}
/*
equation index: 603
type: SIMPLE_ASSIGN
corGDouPan.Q21_dir[1] = 0.08400000000000001 * corGDouPan.a1_dir[1] * (1.0 + corGDouPan.Ta1_dir[1] * corGDouPan.rho_1_dir[1] / corGDouPan.XN2_dir[1])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_603(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,603};
#line 100 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[160] /* corGDouPan.Q21_dir[1] variable */) = (0.08400000000000001) * (((data->localData[0]->realVars[176] /* corGDouPan.a1_dir[1] variable */)) * (1.0 + ((data->localData[0]->realVars[166] /* corGDouPan.Ta1_dir[1] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[180] /* corGDouPan.rho_1_dir[1] variable */),(data->localData[0]->realVars[174] /* corGDouPan.XN2_dir[1] variable */),"corGDouPan.XN2_dir[1]",equationIndexes))));
#line 4526 OMC_FILE
  TRACE_POP
}
/*
equation index: 604
type: SIMPLE_ASSIGN
corGDouPan.Qsek2_dir[1] = corGDouPan.Q21_dir[1] + corGDouPan.Q22_dir[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_604(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,604};
#line 102 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[164] /* corGDouPan.Qsek2_dir[1] variable */) = (data->localData[0]->realVars[160] /* corGDouPan.Q21_dir[1] variable */) + (data->localData[0]->realVars[162] /* corGDouPan.Q22_dir[1] variable */);
#line 4540 OMC_FILE
  TRACE_POP
}
/*
equation index: 605
type: SIMPLE_ASSIGN
corGDouPan.CorG_dir[1] = 1.326787846623325 * (corGDouPan.Ta2_dir[1] + corGDouPan.Qsek2_dir[1])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_605(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,605};
#line 104 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[158] /* corGDouPan.CorG_dir[1] variable */) = (1.326787846623325) * ((data->localData[0]->realVars[168] /* corGDouPan.Ta2_dir[1] variable */) + (data->localData[0]->realVars[164] /* corGDouPan.Qsek2_dir[1] variable */));
#line 4554 OMC_FILE
  TRACE_POP
}
/*
equation index: 606
type: SIMPLE_ASSIGN
$cse18 = cos(HDirTil[1].inc)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_606(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,606};
  (data->localData[0]->realVars[19] /* $cse18 variable */) = cos((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */));
  TRACE_POP
}
/*
equation index: 607
type: SIMPLE_ASSIGN
HDirTil[1].H = max(0.0, $cse18 * HDifTil[1].weaBus.HDirNor)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_607(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,607};
  (data->localData[0]->realVars[133] /* HDirTil[1].H variable */) = fmax(0.0,((data->localData[0]->realVars[19] /* $cse18 variable */)) * ((data->localData[0]->realVars[119] /* HDifTil[1].weaBus.HDirNor variable */)));
  TRACE_POP
}
/*
equation index: 608
type: SIMPLE_ASSIGN
corGDouPan.solarRadWinTrans[1] = HDirTil[1].H * corGDouPan.CorG_dir[1] + 0.8629849850504174 * (HDifTil[1].HSkyDifTil + HDifTil[1].HGroDifTil)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_608(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,608};
#line 107 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[184] /* corGDouPan.solarRadWinTrans[1] variable */) = ((data->localData[0]->realVars[133] /* HDirTil[1].H variable */)) * ((data->localData[0]->realVars[158] /* corGDouPan.CorG_dir[1] variable */)) + (0.8629849850504174) * ((data->localData[0]->realVars[36] /* HDifTil[1].HSkyDifTil variable */) + (data->localData[0]->realVars[34] /* HDifTil[1].HGroDifTil variable */));
#line 4592 OMC_FILE
  TRACE_POP
}
/*
equation index: 609
type: SIMPLE_ASSIGN
thermalZoneFourElements.radHeatSol[1].Q_flow = 6.37 * corGDouPan.solarRadWinTrans[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_609(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,609};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[252] /* thermalZoneFourElements.radHeatSol[1].Q_flow variable */) = (6.37) * ((data->localData[0]->realVars[184] /* corGDouPan.solarRadWinTrans[1] variable */));
#line 4606 OMC_FILE
  TRACE_POP
}
/*
equation index: 610
type: SIMPLE_ASSIGN
thermalZoneFourElements.eConvSol[1].y = 0.63 * corGDouPan.solarRadWinTrans[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_610(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,610};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[229] /* thermalZoneFourElements.eConvSol[1].y variable */) = (0.63) * ((data->localData[0]->realVars[184] /* corGDouPan.solarRadWinTrans[1] variable */));
#line 4620 OMC_FILE
  TRACE_POP
}
/*
equation index: 611
type: SIMPLE_ASSIGN
solRad[1].y = HDirTil[1].H + HDifTil[1].H
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_611(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,611};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[206] /* solRad[1].y variable */) = (data->localData[0]->realVars[133] /* HDirTil[1].H variable */) + (data->localData[0]->realVars[28] /* HDifTil[1].H variable */);
#line 4634 OMC_FILE
  TRACE_POP
}
/*
equation index: 612
type: SIMPLE_ASSIGN
eqAirTemp.delTEqSW[1] = 0.028 * solRad[1].y
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_612(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,612};
#line 74 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[191] /* eqAirTemp.delTEqSW[1] variable */) = (0.028) * ((data->localData[0]->realVars[206] /* solRad[1].y variable */));
#line 4648 OMC_FILE
  TRACE_POP
}
/*
equation index: 613
type: SIMPLE_ASSIGN
eqAirTemp.TEqWall[1] = weaBus.TDryBul + eqAirTemp.delTEqLW + eqAirTemp.delTEqSW[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_613(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,613};
#line 77 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[186] /* eqAirTemp.TEqWall[1] variable */) = (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */) + (data->localData[0]->realVars[190] /* eqAirTemp.delTEqLW variable */) + (data->localData[0]->realVars[191] /* eqAirTemp.delTEqSW[1] variable */);
#line 4662 OMC_FILE
  TRACE_POP
}
/*
equation index: 614
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.dec_s = sin(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_614(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,614};
  (data->localData[0]->realVars[142] /* HDirTil[2].incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 615
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.dec_c = cos(HDifTil[1].weaBus.solDec)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_615(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,615};
  (data->localData[0]->realVars[140] /* HDirTil[2].incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */));
  TRACE_POP
}
/*
equation index: 616
type: SIMPLE_ASSIGN
HDirTil[2].inc = acos((-3.491481338843133e-15) * (HDirTil[2].incAng.incAng.dec_c * HDirTil[2].incAng.incAng.sol_c * HDirTil[2].incAng.incAng.lat_c + HDirTil[2].incAng.incAng.dec_s * HDirTil[2].incAng.incAng.lat_s) + 1.04744440165294e-14 * (HDirTil[2].incAng.incAng.dec_c * HDirTil[2].incAng.incAng.sol_c * HDirTil[2].incAng.incAng.lat_s - HDirTil[2].incAng.incAng.dec_s * HDirTil[2].incAng.incAng.lat_c) - HDirTil[2].incAng.incAng.dec_c * HDirTil[2].incAng.incAng.sol_s)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_616(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,616};
  modelica_real tmp239;
  tmp239 = (-3.491481338843133e-15) * ((((data->localData[0]->realVars[140] /* HDirTil[2].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[148] /* HDirTil[2].incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[144] /* HDirTil[2].incAng.incAng.lat_c variable */)) + ((data->localData[0]->realVars[142] /* HDirTil[2].incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[146] /* HDirTil[2].incAng.incAng.lat_s variable */))) + (1.04744440165294e-14) * ((((data->localData[0]->realVars[140] /* HDirTil[2].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[148] /* HDirTil[2].incAng.incAng.sol_c variable */))) * ((data->localData[0]->realVars[146] /* HDirTil[2].incAng.incAng.lat_s variable */)) - (((data->localData[0]->realVars[142] /* HDirTil[2].incAng.incAng.dec_s variable */)) * ((data->localData[0]->realVars[144] /* HDirTil[2].incAng.incAng.lat_c variable */)))) - (((data->localData[0]->realVars[140] /* HDirTil[2].incAng.incAng.dec_c variable */)) * ((data->localData[0]->realVars[150] /* HDirTil[2].incAng.incAng.sol_s variable */)));
  if(!(tmp239 >= -1.0 && tmp239 <= 1.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos((-3.491481338843133e-15) * (HDirTil[2].incAng.incAng.dec_c * HDirTil[2].incAng.incAng.sol_c * HDirTil[2].incAng.incAng.lat_c + HDirTil[2].incAng.incAng.dec_s * HDirTil[2].incAng.incAng.lat_s) + 1.04744440165294e-14 * (HDirTil[2].incAng.incAng.dec_c * HDirTil[2].incAng.incAng.sol_c * HDirTil[2].incAng.incAng.lat_s - HDirTil[2].incAng.incAng.dec_s * HDirTil[2].incAng.incAng.lat_c) - HDirTil[2].incAng.incAng.dec_c * HDirTil[2].incAng.incAng.sol_s) outside the domain -1.0 <= %g <= 1.0", tmp239);
    }
  }
  (data->localData[0]->realVars[136] /* HDirTil[2].inc variable */) = acos(tmp239);
  TRACE_POP
}
/*
equation index: 617
type: SIMPLE_ASSIGN
corGDouPan.Ta_dir[2] = 0.918 + 57.29577951308232 * (0.000221 + 57.29577951308232 * (-2.75e-05 + 57.29577951308232 * (-3.82e-07 + 57.29577951308232 * (5.83e-08 + 57.29577951308232 * (-1.15e-09 + 2.715819948920102e-10 * HDirTil[2].inc) * HDirTil[2].inc) * HDirTil[2].inc) * HDirTil[2].inc) * HDirTil[2].inc) * HDirTil[2].inc
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_617(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,617};
#line 90 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[171] /* corGDouPan.Ta_dir[2] variable */) = 0.918 + (57.29577951308232) * ((0.000221 + (57.29577951308232) * ((-2.75e-05 + (57.29577951308232) * ((-3.82e-07 + (57.29577951308232) * ((5.83e-08 + (57.29577951308232) * ((-1.15e-09 + (2.715819948920102e-10) * ((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */))) * ((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */)))) * ((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */)))) * ((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */)))) * ((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */)))) * ((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */)));
#line 4726 OMC_FILE
  TRACE_POP
}
/*
equation index: 618
type: SIMPLE_ASSIGN
corGDouPan.rho_T1_dir[2] = 1.0 - corGDouPan.Ta_dir[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_618(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,618};
#line 94 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[183] /* corGDouPan.rho_T1_dir[2] variable */) = 1.0 - (data->localData[0]->realVars[171] /* corGDouPan.Ta_dir[2] variable */);
#line 4740 OMC_FILE
  TRACE_POP
}
/*
equation index: 619
type: SIMPLE_ASSIGN
corGDouPan.rho_11_dir[2] = corGDouPan.rho_T1_dir[2] / (2.0 - corGDouPan.rho_T1_dir[2])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_619(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,619};
#line 95 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[179] /* corGDouPan.rho_11_dir[2] variable */) = DIVISION_SIM((data->localData[0]->realVars[183] /* corGDouPan.rho_T1_dir[2] variable */),2.0 - (data->localData[0]->realVars[183] /* corGDouPan.rho_T1_dir[2] variable */),"2.0 - corGDouPan.rho_T1_dir[2]",equationIndexes);
#line 4754 OMC_FILE
  TRACE_POP
}
/*
equation index: 620
type: SIMPLE_ASSIGN
corGDouPan.Tai_dir[2] = 0.907 ^ (1.0 / sqrt(1.0 - (sin(HDirTil[2].inc) / 1.515) ^ 2.0))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_620(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,620};
  modelica_real tmp240;
  modelica_real tmp241;
  modelica_real tmp242;
  modelica_real tmp243;
  modelica_real tmp244;
  modelica_real tmp245;
  modelica_real tmp246;
  modelica_real tmp247;
  modelica_real tmp248;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp240 = DIVISION_SIM(sin((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */)),1.515,"1.515",equationIndexes);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp241 = 1.0 - ((tmp240 * tmp240));
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  if(!(tmp241 >= 0.0))
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      data->simulationInfo->needToReThrow = 1;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    } else {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of sqrt(1.0 - (sin(HDirTil[2].inc) / 1.515) ^ 2.0) was %g should be >= 0", tmp241);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  }tmp242 = 0.907;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp243 = DIVISION_SIM(1.0,sqrt(tmp241),"sqrt(1.0 - (sin(HDirTil[2].inc) / 1.515) ^ 2.0)",equationIndexes);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  if(tmp242 < 0.0 && tmp243 != 0.0)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    tmp245 = modf(tmp243, &tmp246);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    if(tmp245 > 0.5)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp245 -= 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp246 += 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    else if(tmp245 < -0.5)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp245 += 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp246 -= 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    if(fabs(tmp245) < 1e-10)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp244 = pow(tmp242, tmp246);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    else
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      tmp248 = modf(1.0/tmp243, &tmp247);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      if(tmp248 > 0.5)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp248 -= 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp247 += 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      else if(tmp248 < -0.5)
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp248 += 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp247 -= 1.0;
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      if(fabs(tmp248) < 1e-10 && ((unsigned long)tmp247 & 1))
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        tmp244 = -pow(-tmp242, tmp245)*pow(tmp242, tmp246);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      else
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp242, tmp243);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
      }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  else
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    tmp244 = pow(tmp242, tmp243);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  if(isnan(tmp244) || isinf(tmp244))
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  {
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp242, tmp243);
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  }
#line 92 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[173] /* corGDouPan.Tai_dir[2] variable */) = tmp244;
#line 4903 OMC_FILE
  TRACE_POP
}
/*
equation index: 621
type: SIMPLE_ASSIGN
corGDouPan.Ta1_dir[2] = corGDouPan.Ta_dir[2] * corGDouPan.Tai_dir[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_621(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,621};
#line 93 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[167] /* corGDouPan.Ta1_dir[2] variable */) = ((data->localData[0]->realVars[171] /* corGDouPan.Ta_dir[2] variable */)) * ((data->localData[0]->realVars[173] /* corGDouPan.Tai_dir[2] variable */));
#line 4917 OMC_FILE
  TRACE_POP
}
/*
equation index: 622
type: SIMPLE_ASSIGN
corGDouPan.rho_1_dir[2] = corGDouPan.rho_11_dir[2] + ((1.0 - corGDouPan.rho_11_dir[2]) * corGDouPan.Tai_dir[2]) ^ 2.0 * corGDouPan.rho_11_dir[2] / (1.0 - (corGDouPan.rho_11_dir[2] * corGDouPan.Tai_dir[2]) ^ 2.0)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_622(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,622};
  modelica_real tmp249;
  modelica_real tmp250;
#line 96 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp249 = (1.0 - (data->localData[0]->realVars[179] /* corGDouPan.rho_11_dir[2] variable */)) * ((data->localData[0]->realVars[173] /* corGDouPan.Tai_dir[2] variable */));
#line 96 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp250 = ((data->localData[0]->realVars[179] /* corGDouPan.rho_11_dir[2] variable */)) * ((data->localData[0]->realVars[173] /* corGDouPan.Tai_dir[2] variable */));
#line 96 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[181] /* corGDouPan.rho_1_dir[2] variable */) = (data->localData[0]->realVars[179] /* corGDouPan.rho_11_dir[2] variable */) + ((tmp249 * tmp249)) * (DIVISION_SIM((data->localData[0]->realVars[179] /* corGDouPan.rho_11_dir[2] variable */),1.0 - ((tmp250 * tmp250)),"1.0 - (corGDouPan.rho_11_dir[2] * corGDouPan.Tai_dir[2]) ^ 2.0",equationIndexes));
#line 4937 OMC_FILE
  TRACE_POP
}
/*
equation index: 623
type: SIMPLE_ASSIGN
corGDouPan.a1_dir[2] = 1.0 - (corGDouPan.Ta1_dir[2] + corGDouPan.rho_1_dir[2])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_623(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,623};
#line 98 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[177] /* corGDouPan.a1_dir[2] variable */) = 1.0 - ((data->localData[0]->realVars[167] /* corGDouPan.Ta1_dir[2] variable */) + (data->localData[0]->realVars[181] /* corGDouPan.rho_1_dir[2] variable */));
#line 4951 OMC_FILE
  TRACE_POP
}
/*
equation index: 624
type: SIMPLE_ASSIGN
corGDouPan.XN2_dir[2] = 1.0 - corGDouPan.rho_1_dir[2] ^ 2.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_624(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,624};
  modelica_real tmp251;
#line 99 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp251 = (data->localData[0]->realVars[181] /* corGDouPan.rho_1_dir[2] variable */);
#line 99 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[175] /* corGDouPan.XN2_dir[2] variable */) = 1.0 - ((tmp251 * tmp251));
#line 4968 OMC_FILE
  TRACE_POP
}
/*
equation index: 625
type: SIMPLE_ASSIGN
corGDouPan.Q22_dir[2] = 0.7272727272727273 * corGDouPan.a1_dir[2] * corGDouPan.Ta1_dir[2] / corGDouPan.XN2_dir[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_625(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,625};
#line 101 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[163] /* corGDouPan.Q22_dir[2] variable */) = (0.7272727272727273) * (((data->localData[0]->realVars[177] /* corGDouPan.a1_dir[2] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[167] /* corGDouPan.Ta1_dir[2] variable */),(data->localData[0]->realVars[175] /* corGDouPan.XN2_dir[2] variable */),"corGDouPan.XN2_dir[2]",equationIndexes)));
#line 4982 OMC_FILE
  TRACE_POP
}
/*
equation index: 626
type: SIMPLE_ASSIGN
corGDouPan.Ta2_dir[2] = corGDouPan.Ta1_dir[2] ^ 2.0 / corGDouPan.XN2_dir[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_626(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,626};
  modelica_real tmp252;
#line 103 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  tmp252 = (data->localData[0]->realVars[167] /* corGDouPan.Ta1_dir[2] variable */);
#line 103 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[169] /* corGDouPan.Ta2_dir[2] variable */) = DIVISION_SIM((tmp252 * tmp252),(data->localData[0]->realVars[175] /* corGDouPan.XN2_dir[2] variable */),"corGDouPan.XN2_dir[2]",equationIndexes);
#line 4999 OMC_FILE
  TRACE_POP
}
/*
equation index: 627
type: SIMPLE_ASSIGN
corGDouPan.Q21_dir[2] = 0.08400000000000001 * corGDouPan.a1_dir[2] * (1.0 + corGDouPan.Ta1_dir[2] * corGDouPan.rho_1_dir[2] / corGDouPan.XN2_dir[2])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_627(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,627};
#line 100 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[161] /* corGDouPan.Q21_dir[2] variable */) = (0.08400000000000001) * (((data->localData[0]->realVars[177] /* corGDouPan.a1_dir[2] variable */)) * (1.0 + ((data->localData[0]->realVars[167] /* corGDouPan.Ta1_dir[2] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[181] /* corGDouPan.rho_1_dir[2] variable */),(data->localData[0]->realVars[175] /* corGDouPan.XN2_dir[2] variable */),"corGDouPan.XN2_dir[2]",equationIndexes))));
#line 5013 OMC_FILE
  TRACE_POP
}
/*
equation index: 628
type: SIMPLE_ASSIGN
corGDouPan.Qsek2_dir[2] = corGDouPan.Q21_dir[2] + corGDouPan.Q22_dir[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_628(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,628};
#line 102 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[165] /* corGDouPan.Qsek2_dir[2] variable */) = (data->localData[0]->realVars[161] /* corGDouPan.Q21_dir[2] variable */) + (data->localData[0]->realVars[163] /* corGDouPan.Q22_dir[2] variable */);
#line 5027 OMC_FILE
  TRACE_POP
}
/*
equation index: 629
type: SIMPLE_ASSIGN
corGDouPan.CorG_dir[2] = 1.326787846623325 * (corGDouPan.Ta2_dir[2] + corGDouPan.Qsek2_dir[2])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_629(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,629};
#line 104 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[159] /* corGDouPan.CorG_dir[2] variable */) = (1.326787846623325) * ((data->localData[0]->realVars[169] /* corGDouPan.Ta2_dir[2] variable */) + (data->localData[0]->realVars[165] /* corGDouPan.Qsek2_dir[2] variable */));
#line 5041 OMC_FILE
  TRACE_POP
}
/*
equation index: 630
type: SIMPLE_ASSIGN
$cse19 = cos(HDirTil[2].inc)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_630(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,630};
  (data->localData[0]->realVars[20] /* $cse19 variable */) = cos((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */));
  TRACE_POP
}
/*
equation index: 631
type: SIMPLE_ASSIGN
HDirTil[2].H = max(0.0, $cse19 * HDifTil[1].weaBus.HDirNor)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_631(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,631};
  (data->localData[0]->realVars[134] /* HDirTil[2].H variable */) = fmax(0.0,((data->localData[0]->realVars[20] /* $cse19 variable */)) * ((data->localData[0]->realVars[119] /* HDifTil[1].weaBus.HDirNor variable */)));
  TRACE_POP
}
/*
equation index: 632
type: SIMPLE_ASSIGN
corGDouPan.solarRadWinTrans[2] = HDirTil[2].H * corGDouPan.CorG_dir[2] + 0.8629849850504174 * (HDifTil[2].HSkyDifTil + HDifTil[2].HGroDifTil)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_632(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,632};
#line 107 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/SolarGain/CorrectionGDoublePane.mo"
  (data->localData[0]->realVars[185] /* corGDouPan.solarRadWinTrans[2] variable */) = ((data->localData[0]->realVars[134] /* HDirTil[2].H variable */)) * ((data->localData[0]->realVars[159] /* corGDouPan.CorG_dir[2] variable */)) + (0.8629849850504174) * ((data->localData[0]->realVars[37] /* HDifTil[2].HSkyDifTil variable */) + (data->localData[0]->realVars[35] /* HDifTil[2].HGroDifTil variable */));
#line 5079 OMC_FILE
  TRACE_POP
}
/*
equation index: 633
type: SIMPLE_ASSIGN
thermalZoneFourElements.radHeatSol[2].Q_flow = 6.37 * corGDouPan.solarRadWinTrans[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_633(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,633};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[253] /* thermalZoneFourElements.radHeatSol[2].Q_flow variable */) = (6.37) * ((data->localData[0]->realVars[185] /* corGDouPan.solarRadWinTrans[2] variable */));
#line 5093 OMC_FILE
  TRACE_POP
}
/*
equation index: 634
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterSolRad.portOut[1].Q_flow = (-0.08121827411167512) * thermalZoneFourElements.radHeatSol[1].Q_flow + (-0.03723404255319149) * thermalZoneFourElements.radHeatSol[2].Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_634(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,634};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[290] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].Q_flow variable */) = (-0.08121827411167512) * ((data->localData[0]->realVars[252] /* thermalZoneFourElements.radHeatSol[1].Q_flow variable */)) + (-0.03723404255319149) * ((data->localData[0]->realVars[253] /* thermalZoneFourElements.radHeatSol[2].Q_flow variable */));
#line 5107 OMC_FILE
  TRACE_POP
}
/*
equation index: 635
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterSolRad.portOut[2].Q_flow = (-0.07106598984771574) * thermalZoneFourElements.radHeatSol[1].Q_flow + (-0.07446808510638298) * thermalZoneFourElements.radHeatSol[2].Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_635(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,635};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[291] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].Q_flow variable */) = (-0.07106598984771574) * ((data->localData[0]->realVars[252] /* thermalZoneFourElements.radHeatSol[1].Q_flow variable */)) + (-0.07446808510638298) * ((data->localData[0]->realVars[253] /* thermalZoneFourElements.radHeatSol[2].Q_flow variable */));
#line 5121 OMC_FILE
  TRACE_POP
}
/*
equation index: 636
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterSolRad.portOut[3].Q_flow = (-0.6142131979695431) * thermalZoneFourElements.radHeatSol[1].Q_flow + (-0.6436170212765957) * thermalZoneFourElements.radHeatSol[2].Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_636(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,636};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[292] /* thermalZoneFourElements.thermSplitterSolRad.portOut[3].Q_flow variable */) = (-0.6142131979695431) * ((data->localData[0]->realVars[252] /* thermalZoneFourElements.radHeatSol[1].Q_flow variable */)) + (-0.6436170212765957) * ((data->localData[0]->realVars[253] /* thermalZoneFourElements.radHeatSol[2].Q_flow variable */));
#line 5135 OMC_FILE
  TRACE_POP
}
/*
equation index: 637
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow = (-0.116751269035533) * thermalZoneFourElements.radHeatSol[1].Q_flow + (-0.1223404255319149) * thermalZoneFourElements.radHeatSol[2].Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_637(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,637};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[293] /* thermalZoneFourElements.thermSplitterSolRad.portOut[5].Q_flow variable */) = (-0.116751269035533) * ((data->localData[0]->realVars[252] /* thermalZoneFourElements.radHeatSol[1].Q_flow variable */)) + (-0.1223404255319149) * ((data->localData[0]->realVars[253] /* thermalZoneFourElements.radHeatSol[2].Q_flow variable */));
#line 5149 OMC_FILE
  TRACE_POP
}
/*
equation index: 638
type: SIMPLE_ASSIGN
thermalZoneFourElements.eConvSol[2].y = 0.63 * corGDouPan.solarRadWinTrans[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_638(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,638};
#line 552 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[230] /* thermalZoneFourElements.eConvSol[2].y variable */) = (0.63) * ((data->localData[0]->realVars[185] /* corGDouPan.solarRadWinTrans[2] variable */));
#line 5163 OMC_FILE
  TRACE_POP
}
/*
equation index: 639
type: SIMPLE_ASSIGN
thermalZoneFourElements.convHeatSol.Q_flow = thermalZoneFourElements.eConvSol[1].y + thermalZoneFourElements.eConvSol[2].y
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_639(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,639};
#line 791 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[222] /* thermalZoneFourElements.convHeatSol.Q_flow variable */) = (data->localData[0]->realVars[229] /* thermalZoneFourElements.eConvSol[1].y variable */) + (data->localData[0]->realVars[230] /* thermalZoneFourElements.eConvSol[2].y variable */);
#line 5177 OMC_FILE
  TRACE_POP
}
/*
equation index: 640
type: SIMPLE_ASSIGN
solRad[2].y = HDirTil[2].H + HDifTil[2].H
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_640(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,640};
#line 880 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[207] /* solRad[2].y variable */) = (data->localData[0]->realVars[134] /* HDirTil[2].H variable */) + (data->localData[0]->realVars[29] /* HDifTil[2].H variable */);
#line 5191 OMC_FILE
  TRACE_POP
}
/*
equation index: 641
type: SIMPLE_ASSIGN
eqAirTemp.delTEqSW[2] = 0.028 * solRad[2].y
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_641(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,641};
#line 74 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[192] /* eqAirTemp.delTEqSW[2] variable */) = (0.028) * ((data->localData[0]->realVars[207] /* solRad[2].y variable */));
#line 5205 OMC_FILE
  TRACE_POP
}
/*
equation index: 642
type: SIMPLE_ASSIGN
eqAirTemp.TEqWall[2] = weaBus.TDryBul + eqAirTemp.delTEqLW + eqAirTemp.delTEqSW[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_642(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,642};
#line 77 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[187] /* eqAirTemp.TEqWall[2] variable */) = (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */) + (data->localData[0]->realVars[190] /* eqAirTemp.delTEqLW variable */) + (data->localData[0]->realVars[192] /* eqAirTemp.delTEqSW[2] variable */);
#line 5219 OMC_FILE
  TRACE_POP
}
/*
equation index: 643
type: SIMPLE_ASSIGN
preTem.T = 0.3043478260869566 * eqAirTemp.TEqWall[1] + 0.6956521739130435 * eqAirTemp.TEqWall[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_643(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,643};
#line 24 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/VDI6007WithWindow.mo"
  (data->localData[0]->realVars[204] /* preTem.T variable */) = (0.3043478260869566) * ((data->localData[0]->realVars[186] /* eqAirTemp.TEqWall[1] variable */)) + (0.6956521739130435) * ((data->localData[0]->realVars[187] /* eqAirTemp.TEqWall[2] variable */));
#line 5233 OMC_FILE
  TRACE_POP
}
/*
equation index: 651
type: LINEAR

<var>theConWall.dT</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_651(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,651};
  /* Linear equation system */
  int retValue;
  double aux_x[1] = { (data->localData[1]->realVars[212] /* theConWall.dT variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 651 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 2, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,651};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 651 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[212] /* theConWall.dT variable */) = aux_x[0];

  TRACE_POP
}
/*
equation index: 652
type: SIMPLE_ASSIGN
HDirTil[2].incAng.decAng.decAng = HDifTil[1].weaBus.solDec
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_652(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,652};
  (data->localData[0]->realVars[138] /* HDirTil[2].incAng.decAng.decAng variable */) = (data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */);
  TRACE_POP
}
/*
equation index: 653
type: SIMPLE_ASSIGN
HDifTil[1].incAng.decAng.decAng = HDifTil[1].weaBus.solDec
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_653(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,653};
  (data->localData[0]->realVars[84] /* HDifTil[1].incAng.decAng.decAng variable */) = (data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */);
  TRACE_POP
}
/*
equation index: 654
type: SIMPLE_ASSIGN
HDifTil[2].incAng.decAng.decAng = HDifTil[1].weaBus.solDec
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_654(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,654};
  (data->localData[0]->realVars[85] /* HDifTil[2].incAng.decAng.decAng variable */) = (data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */);
  TRACE_POP
}
/*
equation index: 655
type: SIMPLE_ASSIGN
HDirTil[1].incAng.decAng.decAng = HDifTil[1].weaBus.solDec
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_655(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,655};
  (data->localData[0]->realVars[137] /* HDirTil[1].incAng.decAng.decAng variable */) = (data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */);
  TRACE_POP
}
/*
equation index: 656
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.d = (-thermalZoneFourElements.volAir.dynBal.m) / (-52.5)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_656(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,656};
#line 254 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[304] /* thermalZoneFourElements.volAir.dynBal.medium.d variable */) = DIVISION_SIM((-(data->localData[0]->realVars[5] /* thermalZoneFourElements.volAir.dynBal.m STATE(1) */)),-52.5,"-52.5",equationIndexes);
#line 5332 OMC_FILE
  TRACE_POP
}
/*
equation index: 657
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.u = thermalZoneFourElements.volAir.dynBal.U / thermalZoneFourElements.volAir.dynBal.m
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_657(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,657};
#line 261 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[307] /* thermalZoneFourElements.volAir.dynBal.medium.u variable */) = DIVISION_SIM((data->localData[0]->realVars[4] /* thermalZoneFourElements.volAir.dynBal.U STATE(1) */),(data->localData[0]->realVars[5] /* thermalZoneFourElements.volAir.dynBal.m STATE(1) */),"thermalZoneFourElements.volAir.dynBal.m",equationIndexes);
#line 5346 OMC_FILE
  TRACE_POP
}
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_658(DATA*, threadData_t*);
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_659(DATA*, threadData_t*);
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_660(DATA*, threadData_t*);
/*
equation index: 661
indexNonlinear: 0
type: NONLINEAR

vars: {thermalZoneFourElements.volAir.dynBal.medium.T}
eqns: {658, 659, 660}
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_661(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,661};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 661 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = (data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */);
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,661};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 661 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}
/*
equation index: 662
type: SIMPLE_ASSIGN
thermalZoneFourElements.TAir = Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements.thermalZoneFourElements.volAir.Medium.temperature_phX(101325.0, thermalZoneFourElements.volAir.hOut_internal, {1.0})
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_662(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,662};
  (data->localData[0]->realVars[216] /* thermalZoneFourElements.TAir variable */) = omc_Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_thermalZoneFourElements_volAir_Medium_temperature__phX(threadData, 101325.0, (data->localData[0]->realVars[308] /* thermalZoneFourElements.volAir.hOut_internal variable */), _OMC_LIT42);
  TRACE_POP
}
/*
equation index: 663
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.p_bar = 1e-05 * thermalZoneFourElements.volAir.dynBal.medium.p
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_663(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,663};
#line 3999 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[306] /* thermalZoneFourElements.volAir.dynBal.medium.p_bar variable */) = (1e-05) * ((data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */));
#line 5405 OMC_FILE
  TRACE_POP
}
/*
equation index: 664
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.T_degC = -273.15 + thermalZoneFourElements.volAir.dynBal.medium.T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_664(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,664};
#line 3996 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[302] /* thermalZoneFourElements.volAir.dynBal.medium.T_degC variable */) = -273.15 + (data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */);
#line 5419 OMC_FILE
  TRACE_POP
}
/*
equation index: 665
type: SIMPLE_ASSIGN
$DER.thermalZoneFourElements.volAir.dynBal.m = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_665(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,665};
#line 306 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[11] /* der(thermalZoneFourElements.volAir.dynBal.m) STATE_DER */) = 0.0;
#line 5433 OMC_FILE
  TRACE_POP
}
/*
equation index: 666
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermResExtRem.dT = -283.15 + thermalZoneFourElements.floorRC.thermCapExt[1].T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_666(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,666};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[242] /* thermalZoneFourElements.floorRC.thermResExtRem.dT variable */) = -283.15 + (data->localData[0]->realVars[1] /* thermalZoneFourElements.floorRC.thermCapExt[1].T STATE(1,thermalZoneFourElements.floorRC.thermCapExt[1].der_T) */);
#line 5447 OMC_FILE
  TRACE_POP
}
/*
equation index: 667
type: SIMPLE_ASSIGN
thermalZoneFourElements.floor.Q_flow = (-thermalZoneFourElements.floorRC.thermResExtRem.dT) / 0.1265217391
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_667(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,667};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[237] /* thermalZoneFourElements.floor.Q_flow variable */) = DIVISION_SIM((-(data->localData[0]->realVars[242] /* thermalZoneFourElements.floorRC.thermResExtRem.dT variable */)),0.1265217391,"0.1265217391",equationIndexes);
#line 5461 OMC_FILE
  TRACE_POP
}
/*
equation index: 668
type: SIMPLE_ASSIGN
intGai.timeScaled = time
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_668(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,668};
#line 1656 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[200] /* intGai.timeScaled variable */) = data->localData[0]->timeValue;
#line 5475 OMC_FILE
  TRACE_POP
}
/*
equation index: 669
type: SIMPLE_ASSIGN
$whenCondition1 = time >= pre(intGai.nextTimeEvent)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_669(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,669};
  modelica_boolean tmp0;
#line 1658 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[358] /* intGai.nextTimeEvent DISCRETE */), 0, GreaterEq, GreaterEqZC);
#line 1658 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) = tmp0;
#line 5492 OMC_FILE
  TRACE_POP
}
/*
equation index: 670
type: WHEN

when {$whenCondition1} then
  intGai.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(intGai.tableID, intGai.timeScaled);
end when;
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_670(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,670};
  if(((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
#line 1658 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    (data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */) = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, (data->simulationInfo->extObjs[0]), (data->localData[0]->realVars[200] /* intGai.timeScaled variable */));
#line 5511 OMC_FILE
  }
  TRACE_POP
}
/*
equation index: 671
type: SIMPLE_ASSIGN
intGai.y[1] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer2(intGai.tableID, 1, intGai.timeScaled, intGai.nextTimeEventScaled, pre(intGai.nextTimeEventScaled))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_671(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,671};
#line 1667 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[201] /* intGai.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer2(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 1), (data->localData[0]->realVars[200] /* intGai.timeScaled variable */), (data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[359] /* intGai.nextTimeEventScaled DISCRETE */));
#line 5526 OMC_FILE
  TRACE_POP
}
/*
equation index: 672
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterIntGains.portOut[3].Q_flow = (-0.555045871559633) * intGai.y[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_672(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,672};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[285] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].Q_flow variable */) = (-0.555045871559633) * ((data->localData[0]->realVars[201] /* intGai.y[1] variable */));
#line 5540 OMC_FILE
  TRACE_POP
}
/*
equation index: 673
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterIntGains.portOut[2].Q_flow = (-0.1284403669724771) * intGai.y[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_673(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,673};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[284] /* thermalZoneFourElements.thermSplitterIntGains.portOut[2].Q_flow variable */) = (-0.1284403669724771) * ((data->localData[0]->realVars[201] /* intGai.y[1] variable */));
#line 5554 OMC_FILE
  TRACE_POP
}
/*
equation index: 674
type: SIMPLE_ASSIGN
thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow = (-0.1055045871559633) * intGai.y[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_674(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,674};
#line 17 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[286] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].Q_flow variable */) = (-0.1055045871559633) * ((data->localData[0]->realVars[201] /* intGai.y[1] variable */));
#line 5568 OMC_FILE
  TRACE_POP
}
/*
equation index: 761
type: LINEAR

<var>thermalZoneFourElements.thermSplitterIntGains.portOut[3].T</var>
<var>thermalZoneFourElements.thermSplitterIntGains.portOut[5].T</var>
<var>thermalZoneFourElements.thermSplitterIntGains.portOut[4].T</var>
<var>thermalZoneFourElements.thermSplitterSolRad.portOut[1].T</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_761(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,761};
  /* Linear equation system */
  int retValue;
  double aux_x[4] = { (data->localData[1]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */),(data->localData[1]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */),(data->localData[1]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */),(data->localData[1]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 761 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 3, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,761};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 761 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) = aux_x[0];
  (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) = aux_x[1];
  (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) = aux_x[2];
  (data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */) = aux_x[3];

  TRACE_POP
}
/*
equation index: 762
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermCapInt[1].der_T = thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow / 12391363.86
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_762(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,762};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[249] /* thermalZoneFourElements.intWallRC.thermCapInt[1].der_T variable */) = DIVISION_SIM((data->localData[0]->realVars[250] /* thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow variable */),12391363.86,"12391363.86",equationIndexes);
#line 5625 OMC_FILE
  TRACE_POP
}
/*
equation index: 763
type: SIMPLE_ASSIGN
$DER.thermalZoneFourElements.intWallRC.thermCapInt[1].T = thermalZoneFourElements.intWallRC.thermCapInt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_763(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,763};
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[8] /* der(thermalZoneFourElements.intWallRC.thermCapInt[1].T) STATE_DER */) = (data->localData[0]->realVars[249] /* thermalZoneFourElements.intWallRC.thermCapInt[1].der_T variable */);
#line 5639 OMC_FILE
  TRACE_POP
}
/*
equation index: 764
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow = thermalZoneFourElements.roofRC.port_a.Q_flow - theConRoof.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_764(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,764};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[279] /* thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow variable */) = (data->localData[0]->realVars[277] /* thermalZoneFourElements.roofRC.port_a.Q_flow variable */) - (data->localData[0]->realVars[208] /* theConRoof.Q_flow variable */);
#line 5653 OMC_FILE
  TRACE_POP
}
/*
equation index: 765
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermCapExt[1].der_T = thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow / 5259932.23
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_765(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,765};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[278] /* thermalZoneFourElements.roofRC.thermCapExt[1].der_T variable */) = DIVISION_SIM((data->localData[0]->realVars[279] /* thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow variable */),5259932.23,"5259932.23",equationIndexes);
#line 5667 OMC_FILE
  TRACE_POP
}
/*
equation index: 766
type: SIMPLE_ASSIGN
$DER.thermalZoneFourElements.roofRC.thermCapExt[1].T = thermalZoneFourElements.roofRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_766(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,766};
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[9] /* der(thermalZoneFourElements.roofRC.thermCapExt[1].T) STATE_DER */) = (data->localData[0]->realVars[278] /* thermalZoneFourElements.roofRC.thermCapExt[1].der_T variable */);
#line 5681 OMC_FILE
  TRACE_POP
}
/*
equation index: 767
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow = thermalZoneFourElements.floor.Q_flow + thermalZoneFourElements.floorRC.port_a.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_767(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,767};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[240] /* thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow variable */) = (data->localData[0]->realVars[237] /* thermalZoneFourElements.floor.Q_flow variable */) + (data->localData[0]->realVars[238] /* thermalZoneFourElements.floorRC.port_a.Q_flow variable */);
#line 5695 OMC_FILE
  TRACE_POP
}
/*
equation index: 768
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermCapExt[1].der_T = thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow / 5259932.23
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_768(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,768};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[239] /* thermalZoneFourElements.floorRC.thermCapExt[1].der_T variable */) = DIVISION_SIM((data->localData[0]->realVars[240] /* thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow variable */),5259932.23,"5259932.23",equationIndexes);
#line 5709 OMC_FILE
  TRACE_POP
}
/*
equation index: 769
type: SIMPLE_ASSIGN
$DER.thermalZoneFourElements.floorRC.thermCapExt[1].T = thermalZoneFourElements.floorRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_769(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,769};
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[7] /* der(thermalZoneFourElements.floorRC.thermCapExt[1].T) STATE_DER */) = (data->localData[0]->realVars[239] /* thermalZoneFourElements.floorRC.thermCapExt[1].der_T variable */);
#line 5723 OMC_FILE
  TRACE_POP
}
/*
equation index: 770
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow = thermalZoneFourElements.extWallRC.port_a.Q_flow - theConWall.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_770(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,770};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[234] /* thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow variable */) = (data->localData[0]->realVars[232] /* thermalZoneFourElements.extWallRC.port_a.Q_flow variable */) - (data->localData[0]->realVars[211] /* theConWall.Q_flow variable */);
#line 5737 OMC_FILE
  TRACE_POP
}
/*
equation index: 771
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermCapExt[1].der_T = thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow / 5259932.23
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_771(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,771};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[233] /* thermalZoneFourElements.extWallRC.thermCapExt[1].der_T variable */) = DIVISION_SIM((data->localData[0]->realVars[234] /* thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow variable */),5259932.23,"5259932.23",equationIndexes);
#line 5751 OMC_FILE
  TRACE_POP
}
/*
equation index: 772
type: SIMPLE_ASSIGN
$DER.thermalZoneFourElements.extWallRC.thermCapExt[1].T = thermalZoneFourElements.extWallRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_772(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,772};
#line 15 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[6] /* der(thermalZoneFourElements.extWallRC.thermCapExt[1].T) STATE_DER */) = (data->localData[0]->realVars[233] /* thermalZoneFourElements.extWallRC.thermCapExt[1].der_T variable */);
#line 5765 OMC_FILE
  TRACE_POP
}
/*
equation index: 773
type: SIMPLE_ASSIGN
thermalZoneFourElements.TRad = 0.1055045871559633 * thermalZoneFourElements.thermSplitterSolRad.portOut[1].T + 0.1284403669724771 * thermalZoneFourElements.thermSplitterSolRad.portOut[2].T + 0.555045871559633 * thermalZoneFourElements.thermSplitterIntGains.portOut[3].T + 0.1055045871559633 * (thermalZoneFourElements.thermSplitterIntGains.portOut[4].T + thermalZoneFourElements.thermSplitterIntGains.portOut[5].T)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_773(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,773};
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[217] /* thermalZoneFourElements.TRad variable */) = (0.1055045871559633) * ((data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */)) + (0.1284403669724771) * ((data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */)) + (0.555045871559633) * ((data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */)) + (0.1055045871559633) * ((data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) + (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */));
#line 5779 OMC_FILE
  TRACE_POP
}
/*
equation index: 774
type: SIMPLE_ASSIGN
thermalZoneFourElements.radHeatSol[1].port.T = 0.08121827411167512 * thermalZoneFourElements.thermSplitterSolRad.portOut[1].T + 0.07106598984771574 * thermalZoneFourElements.thermSplitterSolRad.portOut[2].T + 0.6142131979695431 * thermalZoneFourElements.thermSplitterIntGains.portOut[3].T + 0.116751269035533 * (thermalZoneFourElements.thermSplitterIntGains.portOut[4].T + thermalZoneFourElements.thermSplitterIntGains.portOut[5].T)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_774(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,774};
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[254] /* thermalZoneFourElements.radHeatSol[1].port.T variable */) = (0.08121827411167512) * ((data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */)) + (0.07106598984771574) * ((data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */)) + (0.6142131979695431) * ((data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */)) + (0.116751269035533) * ((data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) + (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */));
#line 5793 OMC_FILE
  TRACE_POP
}
/*
equation index: 775
type: SIMPLE_ASSIGN
thermalZoneFourElements.radHeatSol[2].port.T = 0.03723404255319149 * thermalZoneFourElements.thermSplitterSolRad.portOut[1].T + 0.07446808510638298 * thermalZoneFourElements.thermSplitterSolRad.portOut[2].T + 0.6436170212765957 * thermalZoneFourElements.thermSplitterIntGains.portOut[3].T + 0.1223404255319149 * (thermalZoneFourElements.thermSplitterIntGains.portOut[4].T + thermalZoneFourElements.thermSplitterIntGains.portOut[5].T)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_775(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,775};
#line 20 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/RC/BaseClasses/ThermSplitter.mo"
  (data->localData[0]->realVars[255] /* thermalZoneFourElements.radHeatSol[2].port.T variable */) = (0.03723404255319149) * ((data->localData[0]->realVars[294] /* thermalZoneFourElements.thermSplitterSolRad.portOut[1].T variable */)) + (0.07446808510638298) * ((data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */)) + (0.6436170212765957) * ((data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */)) + (0.1223404255319149) * ((data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) + (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */));
#line 5807 OMC_FILE
  TRACE_POP
}
/*
equation index: 776
type: SIMPLE_ASSIGN
intGai.y[2] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer2(intGai.tableID, 2, intGai.timeScaled, intGai.nextTimeEventScaled, pre(intGai.nextTimeEventScaled))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_776(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,776};
#line 1667 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[202] /* intGai.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer2(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 2), (data->localData[0]->realVars[200] /* intGai.timeScaled variable */), (data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[359] /* intGai.nextTimeEventScaled DISCRETE */));
#line 5821 OMC_FILE
  TRACE_POP
}
/*
equation index: 777
type: SIMPLE_ASSIGN
intGai.y[3] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer2(intGai.tableID, 3, intGai.timeScaled, intGai.nextTimeEventScaled, pre(intGai.nextTimeEventScaled))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_777(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,777};
#line 1667 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[203] /* intGai.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer2(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 3), (data->localData[0]->realVars[200] /* intGai.timeScaled variable */), (data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[359] /* intGai.nextTimeEventScaled DISCRETE */));
#line 5835 OMC_FILE
  TRACE_POP
}
/*
equation index: 778
type: SIMPLE_ASSIGN
thermalZoneFourElements.intGainsConv.Q_flow = intGai.y[3] + intGai.y[2]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_778(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,778};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[248] /* thermalZoneFourElements.intGainsConv.Q_flow variable */) = (data->localData[0]->realVars[203] /* intGai.y[3] variable */) + (data->localData[0]->realVars[202] /* intGai.y[2] variable */);
#line 5849 OMC_FILE
  TRACE_POP
}
/*
equation index: 779
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.heatPort.Q_flow = thermalZoneFourElements.intGainsConv.Q_flow - ((-thermalZoneFourElements.convFloor.Q_flow) - thermalZoneFourElements.convRoof.Q_flow - thermalZoneFourElements.convIntWall.Q_flow - thermalZoneFourElements.convWin.Q_flow - thermalZoneFourElements.convExtWall.Q_flow - thermalZoneFourElements.convHeatSol.Q_flow)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_779(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,779};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[309] /* thermalZoneFourElements.volAir.heatPort.Q_flow variable */) = (data->localData[0]->realVars[248] /* thermalZoneFourElements.intGainsConv.Q_flow variable */) - ((-(data->localData[0]->realVars[220] /* thermalZoneFourElements.convFloor.Q_flow variable */)) - (data->localData[0]->realVars[225] /* thermalZoneFourElements.convRoof.Q_flow variable */) - (data->localData[0]->realVars[223] /* thermalZoneFourElements.convIntWall.Q_flow variable */) - (data->localData[0]->realVars[227] /* thermalZoneFourElements.convWin.Q_flow variable */) - (data->localData[0]->realVars[218] /* thermalZoneFourElements.convExtWall.Q_flow variable */) - (data->localData[0]->realVars[222] /* thermalZoneFourElements.convHeatSol.Q_flow variable */));
#line 5863 OMC_FILE
  TRACE_POP
}
/*
equation index: 780
type: SIMPLE_ASSIGN
$DER.thermalZoneFourElements.volAir.dynBal.U = thermalZoneFourElements.volAir.heatPort.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_780(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,780};
#line 300 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[10] /* der(thermalZoneFourElements.volAir.dynBal.U) STATE_DER */) = (data->localData[0]->realVars[309] /* thermalZoneFourElements.volAir.heatPort.Q_flow variable */);
#line 5877 OMC_FILE
  TRACE_POP
}
/*
equation index: 781
type: WHEN

when {$whenCondition1} then
  intGai.nextTimeEvent = if intGai.nextTimeEventScaled < 9.999999999999999e+59 then intGai.nextTimeEventScaled else 9.999999999999999e+59;
end when;
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_781(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,781};
  modelica_boolean tmp1;
  if(((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
#line 1659 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    tmp1 = Less((data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */),9.999999999999999e+59);
#line 1659 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
    (data->localData[0]->realVars[358] /* intGai.nextTimeEvent DISCRETE */) = (tmp1?(data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */):9.999999999999999e+59);
#line 5899 OMC_FILE
  }
  TRACE_POP
}
/*
equation index: 790
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim), "In SimpleRoomFourElements.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTim.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_790(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,790};
  modelica_boolean tmp2;
  static const MMC_DEFSTRINGLIT(tmp3,135,"In SimpleRoomFourElements.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp4;
  modelica_metatype tmpMeta5;
  static const MMC_DEFSTRINGLIT(tmp6,29," is less than the start time ");
  modelica_metatype tmpMeta7;
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static const MMC_DEFSTRINGLIT(tmp10,26," of the weather data file.");
  modelica_metatype tmpMeta11;
  static int tmp12 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp2 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[418] /* weaDat.conTim.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp2))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp4 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta5 = stringAppend(MMC_REFSTRINGLIT(tmp3),tmp4);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta7 = stringAppend(tmpMeta5,MMC_REFSTRINGLIT(tmp6));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp8 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[418] /* weaDat.conTim.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta9 = stringAppend(tmpMeta7,tmp8);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta11 = stringAppend(tmpMeta9,MMC_REFSTRINGLIT(tmp10));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta11));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta11));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 5971 OMC_FILE
  TRACE_POP
}
/*
equation index: 789
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0), "In SimpleRoomFourElements.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTim.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_789(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,789};
  modelica_boolean tmp13;
  static const MMC_DEFSTRINGLIT(tmp14,135,"In SimpleRoomFourElements.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp15;
  modelica_metatype tmpMeta16;
  static const MMC_DEFSTRINGLIT(tmp17,22," exceeds the end time ");
  modelica_metatype tmpMeta18;
  modelica_string tmp19;
  modelica_metatype tmpMeta20;
  static const MMC_DEFSTRINGLIT(tmp21,26," of the weather data file.");
  modelica_metatype tmpMeta22;
  static int tmp23 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp13 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[417] /* weaDat.conTim.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp13))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp15 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta16 = stringAppend(MMC_REFSTRINGLIT(tmp14),tmp15);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta18 = stringAppend(tmpMeta16,MMC_REFSTRINGLIT(tmp17));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp19 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[417] /* weaDat.conTim.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta20 = stringAppend(tmpMeta18,tmp19);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta22 = stringAppend(tmpMeta20,MMC_REFSTRINGLIT(tmp21));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta22));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta22));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 6042 OMC_FILE
  TRACE_POP
}
/*
equation index: 788
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim), "In SimpleRoomFourElements.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTimMin.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_788(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,788};
  modelica_boolean tmp24;
  static const MMC_DEFSTRINGLIT(tmp25,138,"In SimpleRoomFourElements.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp26;
  modelica_metatype tmpMeta27;
  static const MMC_DEFSTRINGLIT(tmp28,29," is less than the start time ");
  modelica_metatype tmpMeta29;
  modelica_string tmp30;
  modelica_metatype tmpMeta31;
  static const MMC_DEFSTRINGLIT(tmp32,26," of the weather data file.");
  modelica_metatype tmpMeta33;
  static int tmp34 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp24 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[421] /* weaDat.conTimMin.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp24))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp26 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta27 = stringAppend(MMC_REFSTRINGLIT(tmp25),tmp26);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta29 = stringAppend(tmpMeta27,MMC_REFSTRINGLIT(tmp28));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp30 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[421] /* weaDat.conTimMin.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta31 = stringAppend(tmpMeta29,tmp30);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta33 = stringAppend(tmpMeta31,MMC_REFSTRINGLIT(tmp32));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta33));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta33));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 6113 OMC_FILE
  TRACE_POP
}
/*
equation index: 787
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0), "In SimpleRoomFourElements.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTimMin.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_787(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,787};
  modelica_boolean tmp35;
  static const MMC_DEFSTRINGLIT(tmp36,138,"In SimpleRoomFourElements.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp37;
  modelica_metatype tmpMeta38;
  static const MMC_DEFSTRINGLIT(tmp39,22," exceeds the end time ");
  modelica_metatype tmpMeta40;
  modelica_string tmp41;
  modelica_metatype tmpMeta42;
  static const MMC_DEFSTRINGLIT(tmp43,26," of the weather data file.");
  modelica_metatype tmpMeta44;
  static int tmp45 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp35 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[420] /* weaDat.conTimMin.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp35))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp37 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta38 = stringAppend(MMC_REFSTRINGLIT(tmp36),tmp37);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta40 = stringAppend(tmpMeta38,MMC_REFSTRINGLIT(tmp39));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp41 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[420] /* weaDat.conTimMin.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta42 = stringAppend(tmpMeta40,tmp41);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta44 = stringAppend(tmpMeta42,MMC_REFSTRINGLIT(tmp43));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta44));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta44));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 6184 OMC_FILE
  TRACE_POP
}
/*
equation index: 786
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.medium.p >= 0.0, "Pressure (= " + String(thermalZoneFourElements.volAir.dynBal.medium.p, 6, 0, true) + " Pa) of medium \"" + "SimpleAir" + "\" is negative
(Temperature = " + String(thermalZoneFourElements.volAir.dynBal.medium.T, 6, 0, true) + " K)");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_786(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,786};
  modelica_boolean tmp46;
  static const MMC_DEFSTRINGLIT(tmp47,12,"Pressure (= ");
  modelica_string tmp48;
  modelica_metatype tmpMeta49;
  static const MMC_DEFSTRINGLIT(tmp50,16," Pa) of medium \"");
  modelica_metatype tmpMeta51;
  static const MMC_DEFSTRINGLIT(tmp52,9,"SimpleAir");
  modelica_metatype tmpMeta53;
  static const MMC_DEFSTRINGLIT(tmp54,29,"\" is negative\n(Temperature = ");
  modelica_metatype tmpMeta55;
  modelica_string tmp56;
  modelica_metatype tmpMeta57;
  static const MMC_DEFSTRINGLIT(tmp58,3," K)");
  modelica_metatype tmpMeta59;
  static int tmp60 = 0;
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp46 = GreaterEq((data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */),0.0);
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!tmp46)
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp48 = modelica_real_to_modelica_string((data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta49 = stringAppend(MMC_REFSTRINGLIT(tmp47),tmp48);
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta51 = stringAppend(tmpMeta49,MMC_REFSTRINGLIT(tmp50));
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta53 = stringAppend(tmpMeta51,MMC_REFSTRINGLIT(tmp52));
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta55 = stringAppend(tmpMeta53,MMC_REFSTRINGLIT(tmp54));
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp56 = modelica_real_to_modelica_string((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta57 = stringAppend(tmpMeta55,tmp56);
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta59 = stringAppend(tmpMeta57,MMC_REFSTRINGLIT(tmp58));
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.medium.p >= 0.0)";
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",4030,7,4031,76,0};
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta59));
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          data->simulationInfo->needToReThrow = 1;
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",4030,7,4031,76,0};
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta59));
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 4030 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 6263 OMC_FILE
  TRACE_POP
}
/*
equation index: 785
type: ALGORITHM

  assert(thermalZoneFourElements.volAir.dynBal.medium.T >= 273.15 and thermalZoneFourElements.volAir.dynBal.medium.T <= 373.15, "
Temperature T (= " + String(thermalZoneFourElements.volAir.dynBal.medium.T, 6, 0, true) + " K) is not
in the allowed range (" + String(273.15, 6, 0, true) + " K <= T <= " + String(373.15, 6, 0, true) + " K)
required from medium model \"" + "SimpleAir" + "\".
");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_785(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,785};
  modelica_boolean tmp61;
  modelica_boolean tmp62;
  static const MMC_DEFSTRINGLIT(tmp63,18,"\nTemperature T (= ");
  modelica_string tmp64;
  modelica_metatype tmpMeta65;
  static const MMC_DEFSTRINGLIT(tmp66,33," K) is not\nin the allowed range (");
  modelica_metatype tmpMeta67;
  modelica_string tmp68;
  modelica_metatype tmpMeta69;
  static const MMC_DEFSTRINGLIT(tmp70,11," K <= T <= ");
  modelica_metatype tmpMeta71;
  modelica_string tmp72;
  modelica_metatype tmpMeta73;
  static const MMC_DEFSTRINGLIT(tmp74,32," K)\nrequired from medium model \"");
  modelica_metatype tmpMeta75;
  static const MMC_DEFSTRINGLIT(tmp76,9,"SimpleAir");
  modelica_metatype tmpMeta77;
  static const MMC_DEFSTRINGLIT(tmp78,3,"\".\n");
  modelica_metatype tmpMeta79;
  static int tmp80 = 0;
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  {
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp61 = GreaterEq((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */),273.15);
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    tmp62 = LessEq((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */),373.15);
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    if(!(tmp61 && tmp62))
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    {
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp64 = modelica_real_to_modelica_string((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta65 = stringAppend(MMC_REFSTRINGLIT(tmp63),tmp64);
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta67 = stringAppend(tmpMeta65,MMC_REFSTRINGLIT(tmp66));
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp68 = modelica_real_to_modelica_string(273.15, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta69 = stringAppend(tmpMeta67,tmp68);
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta71 = stringAppend(tmpMeta69,MMC_REFSTRINGLIT(tmp70));
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmp72 = modelica_real_to_modelica_string(373.15, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta73 = stringAppend(tmpMeta71,tmp72);
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta75 = stringAppend(tmpMeta73,MMC_REFSTRINGLIT(tmp74));
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta77 = stringAppend(tmpMeta75,MMC_REFSTRINGLIT(tmp76));
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      tmpMeta79 = stringAppend(tmpMeta77,MMC_REFSTRINGLIT(tmp78));
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      {
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        const char* assert_cond = "(thermalZoneFourElements.volAir.dynBal.medium.T >= 273.15 and thermalZoneFourElements.volAir.dynBal.medium.T <= 373.15)";
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6177,7,6181,3,0};
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta79));
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          data->simulationInfo->needToReThrow = 1;
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        } else {
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo",6177,7,6181,3,0};
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta79));
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
        }
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
      }
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
    }
#line 6177 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  }
#line 6358 OMC_FILE
  TRACE_POP
}
/*
equation index: 784
type: ALGORITHM

  assert(noEvent(weaBus.TBlaSky > 0.0) and noEvent(weaBus.TBlaSky < 343.15), "In SimpleRoomFourElements.weaDat.cheTemBlaSky: Weather data black-body sky temperature out of bounds.
   TIn = " + String(weaBus.TBlaSky, 6, 0, true));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_784(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,784};
  modelica_boolean tmp81;
  modelica_boolean tmp82;
  static const MMC_DEFSTRINGLIT(tmp83,111,"In SimpleRoomFourElements.weaDat.cheTemBlaSky: Weather data black-body sky temperature out of bounds.\n   TIn = ");
  modelica_string tmp84;
  modelica_metatype tmpMeta85;
  static int tmp86 = 0;
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp81 = Greater((data->localData[0]->realVars[311] /* weaBus.TBlaSky variable */),0.0);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp82 = Less((data->localData[0]->realVars[311] /* weaBus.TBlaSky variable */),343.15);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    if(!(tmp81 && tmp82))
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp84 = modelica_real_to_modelica_string((data->localData[0]->realVars[311] /* weaBus.TBlaSky variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmpMeta85 = stringAppend(MMC_REFSTRINGLIT(tmp83),tmp84);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        const char* assert_cond = "(noEvent(weaBus.TBlaSky > 0.0) and noEvent(weaBus.TBlaSky < 343.15))";
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",25,3,27,18,0};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta85));
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        } else {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",25,3,27,18,0};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta85));
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  }
#line 6418 OMC_FILE
  TRACE_POP
}
/*
equation index: 783
type: ALGORITHM

  assert(noEvent(weaBus.TDewPoi > 203.15) and noEvent(weaBus.TDewPoi < 343.15), "In SimpleRoomFourElements.weaDat.cheTemDewPoi: Weather data dew point temperature out of bounds.
   TIn = " + String(weaBus.TDewPoi, 6, 0, true));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_783(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,783};
  modelica_boolean tmp87;
  modelica_boolean tmp88;
  static const MMC_DEFSTRINGLIT(tmp89,106,"In SimpleRoomFourElements.weaDat.cheTemDewPoi: Weather data dew point temperature out of bounds.\n   TIn = ");
  modelica_string tmp90;
  modelica_metatype tmpMeta91;
  static int tmp92 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp87 = Greater((data->localData[0]->realVars[312] /* weaBus.TDewPoi variable */),203.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp88 = Less((data->localData[0]->realVars[312] /* weaBus.TDewPoi variable */),343.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    if(!(tmp87 && tmp88))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp90 = modelica_real_to_modelica_string((data->localData[0]->realVars[312] /* weaBus.TDewPoi variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmpMeta91 = stringAppend(MMC_REFSTRINGLIT(tmp89),tmp90);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        const char* assert_cond = "(noEvent(weaBus.TDewPoi > 203.15) and noEvent(weaBus.TDewPoi < 343.15))";
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta91));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta91));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  }
#line 6478 OMC_FILE
  TRACE_POP
}
/*
equation index: 782
type: ALGORITHM

  assert(noEvent(weaBus.TDryBul > 203.15) and noEvent(weaBus.TDryBul < 343.15), "In SimpleRoomFourElements.weaDat.cheTemDryBul: Weather data dry bulb temperature out of bounds.
   TIn = " + String(weaBus.TDryBul, 6, 0, true));
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_782(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,782};
  modelica_boolean tmp93;
  modelica_boolean tmp94;
  static const MMC_DEFSTRINGLIT(tmp95,105,"In SimpleRoomFourElements.weaDat.cheTemDryBul: Weather data dry bulb temperature out of bounds.\n   TIn = ");
  modelica_string tmp96;
  modelica_metatype tmpMeta97;
  static int tmp98 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp93 = Greater((data->localData[0]->realVars[313] /* weaBus.TDryBul variable */),203.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp94 = Less((data->localData[0]->realVars[313] /* weaBus.TDryBul variable */),343.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    if(!(tmp93 && tmp94))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp96 = modelica_real_to_modelica_string((data->localData[0]->realVars[313] /* weaBus.TDryBul variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmpMeta97 = stringAppend(MMC_REFSTRINGLIT(tmp95),tmp96);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        const char* assert_cond = "(noEvent(weaBus.TDryBul > 203.15) and noEvent(weaBus.TDryBul < 343.15))";
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta97));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta97));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  }
#line 6538 OMC_FILE
  TRACE_POP
}

OMC_DISABLE_OPT
int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionLocalKnownVars(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_410(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_411(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_412(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_413(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_414(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_415(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_416(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_417(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_418(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_419(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_420(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_421(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_422(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_423(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_424(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_425(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_426(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_427(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_428(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_429(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_430(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_431(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_432(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_433(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_434(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_435(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_436(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_437(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_438(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_439(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_440(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_441(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_442(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_443(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_444(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_445(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_446(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_447(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_448(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_449(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_450(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_451(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_452(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_453(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_454(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_455(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_456(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_457(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_458(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_459(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_460(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_461(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_462(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_463(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_464(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_465(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_466(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_467(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_468(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_469(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_470(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_471(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_472(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_473(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_474(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_475(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_476(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_477(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_478(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_479(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_480(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_481(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_482(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_483(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_484(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_485(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_486(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_487(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_488(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_489(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_490(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_491(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_492(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_493(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_494(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_495(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_496(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_497(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_498(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_499(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_500(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_501(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_502(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_503(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_511(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_512(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_513(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_514(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_515(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_516(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_517(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_518(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_519(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_520(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_521(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_522(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_523(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_524(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_525(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_526(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_527(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_528(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_529(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_530(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_531(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_532(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_533(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_534(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_535(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_536(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_537(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_538(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_539(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_540(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_541(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_542(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_543(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_544(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_545(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_546(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_547(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_548(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_549(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_550(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_551(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_552(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_553(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_554(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_555(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_556(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_557(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_558(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_559(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_560(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_561(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_562(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_563(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_564(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_565(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_566(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_567(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_568(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_569(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_570(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_571(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_572(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_573(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_574(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_575(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_576(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_577(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_578(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_579(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_580(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_581(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_582(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_583(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_584(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_585(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_586(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_587(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_588(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_589(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_590(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_591(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_592(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_593(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_594(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_595(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_596(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_597(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_598(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_599(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_600(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_601(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_602(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_603(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_604(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_605(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_606(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_607(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_608(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_609(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_610(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_611(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_612(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_613(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_614(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_615(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_616(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_617(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_618(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_619(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_620(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_621(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_622(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_623(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_624(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_625(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_626(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_627(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_628(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_629(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_630(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_631(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_632(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_633(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_634(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_635(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_636(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_637(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_638(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_639(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_640(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_641(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_642(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_643(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_651(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_652(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_653(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_654(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_655(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_656(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_657(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_661(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_662(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_663(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_664(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_665(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_666(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_667(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_668(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_669(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_670(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_671(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_672(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_673(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_674(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_761(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_762(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_763(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_764(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_765(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_766(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_767(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_768(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_769(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_770(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_771(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_772(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_773(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_774(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_775(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_776(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_777(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_778(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_779(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_780(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_781(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_790(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_789(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_788(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_787(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_786(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_785(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_784(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_783(data, threadData);

  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_782(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_410(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_411(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_412(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_414(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_415(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_416(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_417(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_418(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_419(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_420(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_421(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_422(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_423(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_424(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_425(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_426(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_427(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_428(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_429(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_430(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_431(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_432(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_433(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_434(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_435(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_436(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_437(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_438(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_439(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_440(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_441(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_442(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_443(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_444(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_445(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_446(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_447(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_448(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_449(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_450(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_452(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_453(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_454(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_455(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_495(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_496(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_497(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_499(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_503(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_511(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_512(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_513(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_514(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_515(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_516(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_518(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_519(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_520(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_521(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_522(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_523(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_524(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_525(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_526(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_527(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_528(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_529(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_530(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_531(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_532(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_533(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_534(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_535(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_536(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_537(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_538(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_539(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_540(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_541(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_542(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_543(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_544(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_545(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_546(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_547(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_548(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_549(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_550(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_551(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_552(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_553(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_554(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_555(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_556(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_557(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_558(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_559(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_560(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_561(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_562(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_563(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_564(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_565(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_566(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_567(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_568(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_569(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_570(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_571(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_572(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_573(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_574(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_575(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_576(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_577(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_578(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_579(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_580(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_581(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_582(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_583(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_584(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_585(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_586(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_587(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_588(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_589(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_590(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_591(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_592(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_593(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_594(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_595(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_596(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_597(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_598(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_599(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_600(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_601(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_602(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_603(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_604(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_605(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_606(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_607(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_608(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_609(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_610(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_611(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_612(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_613(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_614(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_615(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_616(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_617(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_618(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_619(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_620(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_621(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_622(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_623(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_624(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_625(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_626(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_627(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_628(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_629(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_630(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_631(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_632(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_633(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_634(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_635(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_636(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_637(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_638(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_639(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_640(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_641(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_642(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_643(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_651(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_656(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_657(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_661(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_662(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_665(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_666(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_667(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_668(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_669(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_671(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_672(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_673(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_674(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_761(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_762(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_763(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_764(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_765(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_766(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_767(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_768(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_769(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_770(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_771(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_772(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_776(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_777(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_778(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_779(DATA* data, threadData_t *threadData);
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_780(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_410(data, threadData);
    threadData->lastEquationSolved = 410;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_411(data, threadData);
    threadData->lastEquationSolved = 411;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_412(data, threadData);
    threadData->lastEquationSolved = 412;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_414(data, threadData);
    threadData->lastEquationSolved = 414;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_415(data, threadData);
    threadData->lastEquationSolved = 415;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_416(data, threadData);
    threadData->lastEquationSolved = 416;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_417(data, threadData);
    threadData->lastEquationSolved = 417;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_418(data, threadData);
    threadData->lastEquationSolved = 418;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_419(data, threadData);
    threadData->lastEquationSolved = 419;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_420(data, threadData);
    threadData->lastEquationSolved = 420;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_421(data, threadData);
    threadData->lastEquationSolved = 421;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_422(data, threadData);
    threadData->lastEquationSolved = 422;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_423(data, threadData);
    threadData->lastEquationSolved = 423;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_424(data, threadData);
    threadData->lastEquationSolved = 424;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_425(data, threadData);
    threadData->lastEquationSolved = 425;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_426(data, threadData);
    threadData->lastEquationSolved = 426;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_427(data, threadData);
    threadData->lastEquationSolved = 427;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_428(data, threadData);
    threadData->lastEquationSolved = 428;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_429(data, threadData);
    threadData->lastEquationSolved = 429;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_430(data, threadData);
    threadData->lastEquationSolved = 430;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_431(data, threadData);
    threadData->lastEquationSolved = 431;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_432(data, threadData);
    threadData->lastEquationSolved = 432;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_433(data, threadData);
    threadData->lastEquationSolved = 433;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_434(data, threadData);
    threadData->lastEquationSolved = 434;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_435(data, threadData);
    threadData->lastEquationSolved = 435;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_436(data, threadData);
    threadData->lastEquationSolved = 436;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_437(data, threadData);
    threadData->lastEquationSolved = 437;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_438(data, threadData);
    threadData->lastEquationSolved = 438;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_439(data, threadData);
    threadData->lastEquationSolved = 439;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_440(data, threadData);
    threadData->lastEquationSolved = 440;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_441(data, threadData);
    threadData->lastEquationSolved = 441;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_442(data, threadData);
    threadData->lastEquationSolved = 442;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_443(data, threadData);
    threadData->lastEquationSolved = 443;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_444(data, threadData);
    threadData->lastEquationSolved = 444;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_445(data, threadData);
    threadData->lastEquationSolved = 445;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_446(data, threadData);
    threadData->lastEquationSolved = 446;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_447(data, threadData);
    threadData->lastEquationSolved = 447;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_448(data, threadData);
    threadData->lastEquationSolved = 448;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_449(data, threadData);
    threadData->lastEquationSolved = 449;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_450(data, threadData);
    threadData->lastEquationSolved = 450;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_452(data, threadData);
    threadData->lastEquationSolved = 452;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_453(data, threadData);
    threadData->lastEquationSolved = 453;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_454(data, threadData);
    threadData->lastEquationSolved = 454;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_455(data, threadData);
    threadData->lastEquationSolved = 455;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_495(data, threadData);
    threadData->lastEquationSolved = 495;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_496(data, threadData);
    threadData->lastEquationSolved = 496;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_497(data, threadData);
    threadData->lastEquationSolved = 497;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_499(data, threadData);
    threadData->lastEquationSolved = 499;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_503(data, threadData);
    threadData->lastEquationSolved = 503;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_511(data, threadData);
    threadData->lastEquationSolved = 511;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_512(data, threadData);
    threadData->lastEquationSolved = 512;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_513(data, threadData);
    threadData->lastEquationSolved = 513;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_514(data, threadData);
    threadData->lastEquationSolved = 514;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_515(data, threadData);
    threadData->lastEquationSolved = 515;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_516(data, threadData);
    threadData->lastEquationSolved = 516;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_518(data, threadData);
    threadData->lastEquationSolved = 518;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_519(data, threadData);
    threadData->lastEquationSolved = 519;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_520(data, threadData);
    threadData->lastEquationSolved = 520;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_521(data, threadData);
    threadData->lastEquationSolved = 521;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_522(data, threadData);
    threadData->lastEquationSolved = 522;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_523(data, threadData);
    threadData->lastEquationSolved = 523;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_524(data, threadData);
    threadData->lastEquationSolved = 524;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_525(data, threadData);
    threadData->lastEquationSolved = 525;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_526(data, threadData);
    threadData->lastEquationSolved = 526;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_527(data, threadData);
    threadData->lastEquationSolved = 527;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_528(data, threadData);
    threadData->lastEquationSolved = 528;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_529(data, threadData);
    threadData->lastEquationSolved = 529;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_530(data, threadData);
    threadData->lastEquationSolved = 530;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_531(data, threadData);
    threadData->lastEquationSolved = 531;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_532(data, threadData);
    threadData->lastEquationSolved = 532;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_533(data, threadData);
    threadData->lastEquationSolved = 533;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_534(data, threadData);
    threadData->lastEquationSolved = 534;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_535(data, threadData);
    threadData->lastEquationSolved = 535;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_536(data, threadData);
    threadData->lastEquationSolved = 536;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_537(data, threadData);
    threadData->lastEquationSolved = 537;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_538(data, threadData);
    threadData->lastEquationSolved = 538;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_539(data, threadData);
    threadData->lastEquationSolved = 539;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_540(data, threadData);
    threadData->lastEquationSolved = 540;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_541(data, threadData);
    threadData->lastEquationSolved = 541;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_542(data, threadData);
    threadData->lastEquationSolved = 542;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_543(data, threadData);
    threadData->lastEquationSolved = 543;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_544(data, threadData);
    threadData->lastEquationSolved = 544;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_545(data, threadData);
    threadData->lastEquationSolved = 545;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_546(data, threadData);
    threadData->lastEquationSolved = 546;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_547(data, threadData);
    threadData->lastEquationSolved = 547;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_548(data, threadData);
    threadData->lastEquationSolved = 548;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_549(data, threadData);
    threadData->lastEquationSolved = 549;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_550(data, threadData);
    threadData->lastEquationSolved = 550;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_551(data, threadData);
    threadData->lastEquationSolved = 551;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_552(data, threadData);
    threadData->lastEquationSolved = 552;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_553(data, threadData);
    threadData->lastEquationSolved = 553;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_554(data, threadData);
    threadData->lastEquationSolved = 554;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_555(data, threadData);
    threadData->lastEquationSolved = 555;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_556(data, threadData);
    threadData->lastEquationSolved = 556;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_557(data, threadData);
    threadData->lastEquationSolved = 557;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_558(data, threadData);
    threadData->lastEquationSolved = 558;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_559(data, threadData);
    threadData->lastEquationSolved = 559;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_560(data, threadData);
    threadData->lastEquationSolved = 560;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_561(data, threadData);
    threadData->lastEquationSolved = 561;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_562(data, threadData);
    threadData->lastEquationSolved = 562;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_563(data, threadData);
    threadData->lastEquationSolved = 563;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_564(data, threadData);
    threadData->lastEquationSolved = 564;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_565(data, threadData);
    threadData->lastEquationSolved = 565;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_566(data, threadData);
    threadData->lastEquationSolved = 566;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_567(data, threadData);
    threadData->lastEquationSolved = 567;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_568(data, threadData);
    threadData->lastEquationSolved = 568;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_569(data, threadData);
    threadData->lastEquationSolved = 569;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_570(data, threadData);
    threadData->lastEquationSolved = 570;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_571(data, threadData);
    threadData->lastEquationSolved = 571;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_572(data, threadData);
    threadData->lastEquationSolved = 572;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_573(data, threadData);
    threadData->lastEquationSolved = 573;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_574(data, threadData);
    threadData->lastEquationSolved = 574;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_575(data, threadData);
    threadData->lastEquationSolved = 575;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_576(data, threadData);
    threadData->lastEquationSolved = 576;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_577(data, threadData);
    threadData->lastEquationSolved = 577;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_578(data, threadData);
    threadData->lastEquationSolved = 578;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_579(data, threadData);
    threadData->lastEquationSolved = 579;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_580(data, threadData);
    threadData->lastEquationSolved = 580;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_581(data, threadData);
    threadData->lastEquationSolved = 581;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_582(data, threadData);
    threadData->lastEquationSolved = 582;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_583(data, threadData);
    threadData->lastEquationSolved = 583;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_584(data, threadData);
    threadData->lastEquationSolved = 584;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_585(data, threadData);
    threadData->lastEquationSolved = 585;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_586(data, threadData);
    threadData->lastEquationSolved = 586;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_587(data, threadData);
    threadData->lastEquationSolved = 587;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_588(data, threadData);
    threadData->lastEquationSolved = 588;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_589(data, threadData);
    threadData->lastEquationSolved = 589;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_590(data, threadData);
    threadData->lastEquationSolved = 590;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_591(data, threadData);
    threadData->lastEquationSolved = 591;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_592(data, threadData);
    threadData->lastEquationSolved = 592;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_593(data, threadData);
    threadData->lastEquationSolved = 593;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_594(data, threadData);
    threadData->lastEquationSolved = 594;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_595(data, threadData);
    threadData->lastEquationSolved = 595;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_596(data, threadData);
    threadData->lastEquationSolved = 596;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_597(data, threadData);
    threadData->lastEquationSolved = 597;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_598(data, threadData);
    threadData->lastEquationSolved = 598;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_599(data, threadData);
    threadData->lastEquationSolved = 599;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_600(data, threadData);
    threadData->lastEquationSolved = 600;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_601(data, threadData);
    threadData->lastEquationSolved = 601;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_602(data, threadData);
    threadData->lastEquationSolved = 602;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_603(data, threadData);
    threadData->lastEquationSolved = 603;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_604(data, threadData);
    threadData->lastEquationSolved = 604;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_605(data, threadData);
    threadData->lastEquationSolved = 605;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_606(data, threadData);
    threadData->lastEquationSolved = 606;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_607(data, threadData);
    threadData->lastEquationSolved = 607;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_608(data, threadData);
    threadData->lastEquationSolved = 608;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_609(data, threadData);
    threadData->lastEquationSolved = 609;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_610(data, threadData);
    threadData->lastEquationSolved = 610;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_611(data, threadData);
    threadData->lastEquationSolved = 611;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_612(data, threadData);
    threadData->lastEquationSolved = 612;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_613(data, threadData);
    threadData->lastEquationSolved = 613;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_614(data, threadData);
    threadData->lastEquationSolved = 614;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_615(data, threadData);
    threadData->lastEquationSolved = 615;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_616(data, threadData);
    threadData->lastEquationSolved = 616;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_617(data, threadData);
    threadData->lastEquationSolved = 617;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_618(data, threadData);
    threadData->lastEquationSolved = 618;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_619(data, threadData);
    threadData->lastEquationSolved = 619;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_620(data, threadData);
    threadData->lastEquationSolved = 620;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_621(data, threadData);
    threadData->lastEquationSolved = 621;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_622(data, threadData);
    threadData->lastEquationSolved = 622;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_623(data, threadData);
    threadData->lastEquationSolved = 623;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_624(data, threadData);
    threadData->lastEquationSolved = 624;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_625(data, threadData);
    threadData->lastEquationSolved = 625;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_626(data, threadData);
    threadData->lastEquationSolved = 626;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_627(data, threadData);
    threadData->lastEquationSolved = 627;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_628(data, threadData);
    threadData->lastEquationSolved = 628;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_629(data, threadData);
    threadData->lastEquationSolved = 629;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_630(data, threadData);
    threadData->lastEquationSolved = 630;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_631(data, threadData);
    threadData->lastEquationSolved = 631;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_632(data, threadData);
    threadData->lastEquationSolved = 632;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_633(data, threadData);
    threadData->lastEquationSolved = 633;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_634(data, threadData);
    threadData->lastEquationSolved = 634;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_635(data, threadData);
    threadData->lastEquationSolved = 635;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_636(data, threadData);
    threadData->lastEquationSolved = 636;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_637(data, threadData);
    threadData->lastEquationSolved = 637;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_638(data, threadData);
    threadData->lastEquationSolved = 638;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_639(data, threadData);
    threadData->lastEquationSolved = 639;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_640(data, threadData);
    threadData->lastEquationSolved = 640;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_641(data, threadData);
    threadData->lastEquationSolved = 641;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_642(data, threadData);
    threadData->lastEquationSolved = 642;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_643(data, threadData);
    threadData->lastEquationSolved = 643;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_651(data, threadData);
    threadData->lastEquationSolved = 651;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_656(data, threadData);
    threadData->lastEquationSolved = 656;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_657(data, threadData);
    threadData->lastEquationSolved = 657;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_661(data, threadData);
    threadData->lastEquationSolved = 661;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_662(data, threadData);
    threadData->lastEquationSolved = 662;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_665(data, threadData);
    threadData->lastEquationSolved = 665;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_666(data, threadData);
    threadData->lastEquationSolved = 666;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_667(data, threadData);
    threadData->lastEquationSolved = 667;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_668(data, threadData);
    threadData->lastEquationSolved = 668;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_669(data, threadData);
    threadData->lastEquationSolved = 669;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_671(data, threadData);
    threadData->lastEquationSolved = 671;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_672(data, threadData);
    threadData->lastEquationSolved = 672;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_673(data, threadData);
    threadData->lastEquationSolved = 673;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_674(data, threadData);
    threadData->lastEquationSolved = 674;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_761(data, threadData);
    threadData->lastEquationSolved = 761;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_762(data, threadData);
    threadData->lastEquationSolved = 762;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_763(data, threadData);
    threadData->lastEquationSolved = 763;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_764(data, threadData);
    threadData->lastEquationSolved = 764;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_765(data, threadData);
    threadData->lastEquationSolved = 765;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_766(data, threadData);
    threadData->lastEquationSolved = 766;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_767(data, threadData);
    threadData->lastEquationSolved = 767;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_768(data, threadData);
    threadData->lastEquationSolved = 768;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_769(data, threadData);
    threadData->lastEquationSolved = 769;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_770(data, threadData);
    threadData->lastEquationSolved = 770;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_771(data, threadData);
    threadData->lastEquationSolved = 771;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_772(data, threadData);
    threadData->lastEquationSolved = 772;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_776(data, threadData);
    threadData->lastEquationSolved = 776;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_777(data, threadData);
    threadData->lastEquationSolved = 777;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_778(data, threadData);
    threadData->lastEquationSolved = 778;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_779(data, threadData);
    threadData->lastEquationSolved = 779;
  }
  {
    Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_780(data, threadData);
    threadData->lastEquationSolved = 780;
  }
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_12jac.h"
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_callback = {
   NULL,    /* performSimulation */
   NULL,    /* performQSSSimulation */
   NULL,    /* updateContinuousSystem */
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialNonLinearSystem,    /* initialNonLinearSystem */
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialLinearSystem,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initializeDAEmodeData,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionODE,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionAlgebraics,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionDAE,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionLocalKnownVars,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_input_function,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_input_function_init,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_input_function_updateStartValues,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_data_function,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_output_function,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_setc_function,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_setb_function,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_storeDelayed,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_storeSpatialDistribution,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_initSpatialDistribution,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_updateBoundVariableAttributes,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionRemovedInitialEquations,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_updateBoundParameters,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_checkForAsserts,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_ZeroCrossingsEquations,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_ZeroCrossings,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_updateRelations,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_zeroCrossingDescription,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_relationDescription,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_initSample,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_INDEX_JAC_A,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_INDEX_JAC_B,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_INDEX_JAC_C,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_INDEX_JAC_D,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_INDEX_JAC_F,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_INDEX_JAC_H,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianA,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianB,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianC,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianD,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianF,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianH,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacA_column,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacB_column,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacC_column,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacD_column,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacF_column,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacH_column,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_linear_model_frame,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_linear_model_datarecovery_frame,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_mayer,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_lagrange,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_pickUpBoundsForInputsInOptimization,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_setInputData,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_getTimeGrid,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_symbolicInlineSystem,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_initSynchronous,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_updateSynchronous,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_function_equationsSynchronous,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_inputNames,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_dataReconciliationInputNames,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_dataReconciliationUnmeasuredVariables,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_read_input_fmu,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianFMIDER,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacFMIDER_column,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_INDEX_JAC_FMIDER,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_initialAnalyticJacobianFMIDERINIT,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionJacFMIDERINIT_column,
   Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_INDEX_JAC_FMIDERINIT

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
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements";
  data->modelData->modelFilePrefix = "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/Examples";
  data->modelData->modelGUID = "{c9dc621b-3714-403c-b713-dcbcb3b3cbc6}";
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 6;
  data->modelData->nVariablesReal = 362;
  data->modelData->nDiscreteReal = 4;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 3;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 456;
  data->modelData->nParametersInteger = 101;
  data->modelData->nParametersBoolean = 38;
  data->modelData->nParametersString = 7;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 582;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 3;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 3;
  
  GC_asprintf(&data->modelData->modelDataXml.fileName, "%s/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_info.json", data->modelData->resourcesDir);
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 36;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 2457;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 12;
  data->modelData->nNonLinearSystems = 1;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 19;
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

