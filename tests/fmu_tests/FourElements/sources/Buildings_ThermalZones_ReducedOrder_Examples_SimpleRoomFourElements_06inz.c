#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements.fmutmp/sources/Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_06inz.c"
#endif
/* Initialization */
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_model.h"
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_11mix.h"
#include "Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
weaDat.pAtmSel.y = 101325.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[355] /* weaDat.pAtmSel.y variable */) = 101325.0;
#line 27 OMC_FILE
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
weaDat.TBlaSkyCom.TDewPoiK = 273.15
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[314] /* weaDat.TBlaSkyCom.TDewPoiK variable */) = 273.15;
#line 42 OMC_FILE
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
weaDat.TBlaSkyCom.nOpa10 = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[316] /* weaDat.TBlaSkyCom.nOpa10 variable */) = 0.0;
#line 57 OMC_FILE
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
weaDat.TBlaSkyCom.epsSky = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
#line 35 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[315] /* weaDat.TBlaSkyCom.epsSky variable */) = 0.0;
#line 72 OMC_FILE
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.MM = 0.0289651159
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
#line 3988 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[299] /* thermalZoneFourElements.volAir.dynBal.medium.MM variable */) = 0.0289651159;
#line 87 OMC_FILE
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.mWat_flow_internal = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
#line 166 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[297] /* thermalZoneFourElements.volAir.dynBal.mWat_flow_internal variable */) = 0.0;
#line 102 OMC_FILE
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.lat_s = sin(weaDat.latitude.latitude)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
#line 30 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[146] /* HDirTil[2].incAng.incAng.lat_s variable */) = sin((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
#line 117 OMC_FILE
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.lat_c = cos(weaDat.latitude.latitude)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
#line 29 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[144] /* HDirTil[2].incAng.incAng.lat_c variable */) = cos((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
#line 132 OMC_FILE
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.lat_s = sin(weaDat.latitude.latitude)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
#line 30 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[145] /* HDirTil[1].incAng.incAng.lat_s variable */) = sin((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
#line 147 OMC_FILE
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.lat_c = cos(weaDat.latitude.latitude)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
#line 29 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[143] /* HDirTil[1].incAng.incAng.lat_c variable */) = cos((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
#line 162 OMC_FILE
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.lat_s = sin(weaDat.latitude.latitude)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
#line 30 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[93] /* HDifTil[2].incAng.incAng.lat_s variable */) = sin((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
#line 177 OMC_FILE
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.lat_c = cos(weaDat.latitude.latitude)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
#line 29 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[91] /* HDifTil[2].incAng.incAng.lat_c variable */) = cos((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
#line 192 OMC_FILE
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.lat_s = sin(weaDat.latitude.latitude)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
#line 30 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[92] /* HDifTil[1].incAng.incAng.lat_s variable */) = sin((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
#line 207 OMC_FILE
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.lat_c = cos(weaDat.latitude.latitude)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
#line 29 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[90] /* HDifTil[1].incAng.incAng.lat_c variable */) = cos((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */));
#line 222 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_410(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_411(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_426(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_427(DATA *data, threadData_t *threadData);


/*
equation index: 19
type: SIMPLE_ASSIGN
weaDat.eqnTim.eqnTim = 60.0 * (9.869999999999999 * sin(2.0 * weaDat.eqnTim.Bt) + (-7.53) * cos(weaDat.eqnTim.Bt) + (-1.5) * sin(weaDat.eqnTim.Bt))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[352] /* weaDat.eqnTim.eqnTim variable */) = (60.0) * ((9.869999999999999) * (sin((2.0) * ((data->localData[0]->realVars[351] /* weaDat.eqnTim.Bt variable */)))) + (-7.53) * (cos((data->localData[0]->realVars[351] /* weaDat.eqnTim.Bt variable */))) + (-1.5) * (sin((data->localData[0]->realVars[351] /* weaDat.eqnTim.Bt variable */))));
#line 245 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_432(DATA *data, threadData_t *threadData);


/*
equation index: 21
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.solDec = asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  modelica_real tmp0;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp0 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  if(!(tmp0 >= -1.0 && tmp0 <= 1.0))
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      data->simulationInfo->needToReThrow = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)) outside the domain -1.0 <= %g <= 1.0", tmp0);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  (data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */) = asin(tmp0);
#line 289 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_433(DATA *data, threadData_t *threadData);


/*
equation index: 23
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.solZen = acos(cos(weaDat.latitude.latitude) * cos(HDifTil[1].weaBus.solDec) * cos(HDifTil[1].weaBus.solHouAng) + sin(weaDat.latitude.latitude) * sin(HDifTil[1].weaBus.solDec))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  modelica_real tmp1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  tmp1 = ((cos((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */))) * (cos((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */)))) * (cos((data->localData[0]->realVars[128] /* HDifTil[1].weaBus.solHouAng variable */))) + (sin((data->simulationInfo->realParameter[429] /* weaDat.latitude.latitude PARAM */))) * (sin((data->localData[0]->realVars[127] /* HDifTil[1].weaBus.solDec variable */)));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  if(!(tmp1 >= -1.0 && tmp1 <= 1.0))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
      data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
    } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos(cos(weaDat.latitude.latitude) * cos(HDifTil[1].weaBus.solDec) * cos(HDifTil[1].weaBus.solHouAng) + sin(weaDat.latitude.latitude) * sin(HDifTil[1].weaBus.solDec)) outside the domain -1.0 <= %g <= 1.0", tmp1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  (data->localData[0]->realVars[130] /* HDifTil[1].weaBus.solZen variable */) = acos(tmp1);
#line 333 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_517(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_518(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_519(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_541(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_542(DATA *data, threadData_t *threadData);


/*
equation index: 29
type: SIMPLE_ASSIGN
HDifTil[1].relAirMas.relAirMas = exp((-0.0001184) * weaDat.altitude.Altitude) / (cos(HDifTil[1].relAirMas.zenLim) + 0.15 / (93.90000000000001 - HDifTil[1].relAirMas.zenDeg) ^ 1.253)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp2 = 93.90000000000001 - (data->localData[0]->realVars[104] /* HDifTil[1].relAirMas.zenDeg variable */);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp3 = 1.253;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(tmp2 < 0.0 && tmp3 != 0.0)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp5 = modf(tmp3, &tmp6);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(tmp5 > 0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp5 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp6 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else if(tmp5 < -0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp5 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp6 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(fabs(tmp5) < 1e-10)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp4 = pow(tmp2, tmp6);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp8 = modf(1.0/tmp3, &tmp7);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      if(tmp8 > 0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp8 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp7 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      else if(tmp8 < -0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp8 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp7 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      if(fabs(tmp8) < 1e-10 && ((unsigned long)tmp7 & 1))
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp4 = -pow(-tmp2, tmp5)*pow(tmp2, tmp6);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp2, tmp3);
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
    tmp4 = pow(tmp2, tmp3);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(isnan(tmp4) || isinf(tmp4))
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp2, tmp3);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->localData[0]->realVars[102] /* HDifTil[1].relAirMas.relAirMas variable */) = DIVISION_SIM(exp((-0.0001184) * ((data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */))),cos((data->localData[0]->realVars[106] /* HDifTil[1].relAirMas.zenLim variable */)) + DIVISION_SIM(0.15,tmp4,"(93.90000000000001 - HDifTil[1].relAirMas.zenDeg) ^ 1.253",equationIndexes),"cos(HDifTil[1].relAirMas.zenLim) + 0.15 / (93.90000000000001 - HDifTil[1].relAirMas.zenDeg) ^ 1.253",equationIndexes);
#line 465 OMC_FILE
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
HDifTil[1].skyBri.extRadCor = 1.0 + 0.033 * cos(0.01721420632103996 * (HDifTil[1].weaBus.solTim / 86400.0 + 1.0))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  (data->localData[0]->realVars[108] /* HDifTil[1].skyBri.extRadCor variable */) = 1.0 + (0.033) * (cos((0.01721420632103996) * (DIVISION_SIM((data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */),86400.0,"86400.0",equationIndexes) + 1.0)));
#line 480 OMC_FILE
  TRACE_POP
}

/*
equation index: 31
type: SIMPLE_ASSIGN
HDifTil[1].incAng.decAng.decAng = asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  modelica_real tmp9;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp9 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  if(!(tmp9 >= -1.0 && tmp9 <= 1.0))
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      data->simulationInfo->needToReThrow = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)) outside the domain -1.0 <= %g <= 1.0", tmp9);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  (data->localData[0]->realVars[84] /* HDifTil[1].incAng.decAng.decAng variable */) = asin(tmp9);
#line 522 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_435(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_548(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_549(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_571(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_572(DATA *data, threadData_t *threadData);


/*
equation index: 37
type: SIMPLE_ASSIGN
HDifTil[2].relAirMas.relAirMas = exp((-0.0001184) * weaDat.altitude.Altitude) / (cos(HDifTil[2].relAirMas.zenLim) + 0.15 / (93.90000000000001 - HDifTil[2].relAirMas.zenDeg) ^ 1.253)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp10 = 93.90000000000001 - (data->localData[0]->realVars[105] /* HDifTil[2].relAirMas.zenDeg variable */);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  tmp11 = 1.253;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(tmp10 < 0.0 && tmp11 != 0.0)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    tmp13 = modf(tmp11, &tmp14);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(tmp13 > 0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp13 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp14 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else if(tmp13 < -0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp13 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp14 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    if(fabs(tmp13) < 1e-10)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp12 = pow(tmp10, tmp14);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      tmp16 = modf(1.0/tmp11, &tmp15);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      if(tmp16 > 0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp16 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp15 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      else if(tmp16 < -0.5)
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp16 += 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp15 -= 1.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      if(fabs(tmp16) < 1e-10 && ((unsigned long)tmp15 & 1))
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        tmp12 = -pow(-tmp10, tmp13)*pow(tmp10, tmp14);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      else
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
      {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp10, tmp11);
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
    tmp12 = pow(tmp10, tmp11);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  if(isnan(tmp12) || isinf(tmp12))
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  {
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp10, tmp11);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  }
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/RelativeAirMass.mo"
  (data->localData[0]->realVars[103] /* HDifTil[2].relAirMas.relAirMas variable */) = DIVISION_SIM(exp((-0.0001184) * ((data->simulationInfo->realParameter[403] /* weaDat.altitude.Altitude PARAM */))),cos((data->localData[0]->realVars[107] /* HDifTil[2].relAirMas.zenLim variable */)) + DIVISION_SIM(0.15,tmp12,"(93.90000000000001 - HDifTil[2].relAirMas.zenDeg) ^ 1.253",equationIndexes),"cos(HDifTil[2].relAirMas.zenLim) + 0.15 / (93.90000000000001 - HDifTil[2].relAirMas.zenDeg) ^ 1.253",equationIndexes);
#line 654 OMC_FILE
  TRACE_POP
}

/*
equation index: 38
type: SIMPLE_ASSIGN
HDifTil[2].skyBri.extRadCor = 1.0 + 0.033 * cos(0.01721420632103996 * (HDifTil[1].weaBus.solTim / 86400.0 + 1.0))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
#line 21 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/SkyBrightness.mo"
  (data->localData[0]->realVars[109] /* HDifTil[2].skyBri.extRadCor variable */) = 1.0 + (0.033) * (cos((0.01721420632103996) * (DIVISION_SIM((data->localData[0]->realVars[129] /* HDifTil[1].weaBus.solTim variable */),86400.0,"86400.0",equationIndexes) + 1.0)));
#line 669 OMC_FILE
  TRACE_POP
}

/*
equation index: 39
type: SIMPLE_ASSIGN
HDifTil[2].incAng.decAng.decAng = asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  modelica_real tmp17;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp17 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  if(!(tmp17 >= -1.0 && tmp17 <= 1.0))
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      data->simulationInfo->needToReThrow = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)) outside the domain -1.0 <= %g <= 1.0", tmp17);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  (data->localData[0]->realVars[85] /* HDifTil[2].incAng.decAng.decAng variable */) = asin(tmp17);
#line 711 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_438(DATA *data, threadData_t *threadData);


/*
equation index: 41
type: SIMPLE_ASSIGN
HDirTil[1].incAng.decAng.decAng = asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  modelica_real tmp18;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp18 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  if(!(tmp18 >= -1.0 && tmp18 <= 1.0))
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      data->simulationInfo->needToReThrow = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)) outside the domain -1.0 <= %g <= 1.0", tmp18);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  (data->localData[0]->realVars[137] /* HDirTil[1].incAng.decAng.decAng variable */) = asin(tmp18);
#line 755 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_441(DATA *data, threadData_t *threadData);


/*
equation index: 43
type: SIMPLE_ASSIGN
HDirTil[2].incAng.decAng.decAng = asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  modelica_real tmp19;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp19 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  if(!(tmp19 >= -1.0 && tmp19 <= 1.0))
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      data->simulationInfo->needToReThrow = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * cos((HDifTil[1].weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)) outside the domain -1.0 <= %g <= 1.0", tmp19);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  (data->localData[0]->realVars[138] /* HDirTil[2].incAng.decAng.decAng variable */) = asin(tmp19);
#line 799 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_444(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_668(DATA *data, threadData_t *threadData);


/*
equation index: 46
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.dec_c = cos(HDifTil[1].incAng.decAng.decAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[86] /* HDifTil[1].incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[84] /* HDifTil[1].incAng.decAng.decAng variable */));
#line 818 OMC_FILE
  TRACE_POP
}

/*
equation index: 47
type: SIMPLE_ASSIGN
HDifTil[1].incAng.incAng.dec_s = sin(HDifTil[1].incAng.decAng.decAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[88] /* HDifTil[1].incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[84] /* HDifTil[1].incAng.decAng.decAng variable */));
#line 833 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_437(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_436(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_580(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_581(DATA *data, threadData_t *threadData);


/*
equation index: 52
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.dec_c = cos(HDifTil[2].incAng.decAng.decAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[87] /* HDifTil[2].incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[85] /* HDifTil[2].incAng.decAng.decAng variable */));
#line 856 OMC_FILE
  TRACE_POP
}

/*
equation index: 53
type: SIMPLE_ASSIGN
HDifTil[2].incAng.incAng.dec_s = sin(HDifTil[2].incAng.decAng.decAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[89] /* HDifTil[2].incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[85] /* HDifTil[2].incAng.decAng.decAng variable */));
#line 871 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_440(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_439(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_586(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_587(DATA *data, threadData_t *threadData);


/*
equation index: 58
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.dec_c = cos(HDirTil[1].incAng.decAng.decAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[139] /* HDirTil[1].incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[137] /* HDirTil[1].incAng.decAng.decAng variable */));
#line 894 OMC_FILE
  TRACE_POP
}

/*
equation index: 59
type: SIMPLE_ASSIGN
HDirTil[1].incAng.incAng.dec_s = sin(HDirTil[1].incAng.decAng.decAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[141] /* HDirTil[1].incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[137] /* HDirTil[1].incAng.decAng.decAng variable */));
#line 909 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_443(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_442(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_592(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_596(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_593(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_594(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_595(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_598(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_600(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_597(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_602(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_599(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_601(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_603(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_604(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_605(DATA *data, threadData_t *threadData);


/*
equation index: 76
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.dec_c = cos(HDirTil[2].incAng.decAng.decAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[140] /* HDirTil[2].incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[138] /* HDirTil[2].incAng.decAng.decAng variable */));
#line 956 OMC_FILE
  TRACE_POP
}

/*
equation index: 77
type: SIMPLE_ASSIGN
HDirTil[2].incAng.incAng.dec_s = sin(HDirTil[2].incAng.decAng.decAng)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[142] /* HDirTil[2].incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[138] /* HDirTil[2].incAng.decAng.decAng variable */));
#line 971 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_446(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_445(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_616(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_620(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_617(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_618(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_619(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_622(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_624(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_621(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_626(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_623(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_625(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_627(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_628(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_629(DATA *data, threadData_t *threadData);


/*
equation index: 94
type: SIMPLE_ASSIGN
intGai.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(intGai.tableID, intGai.timeScaled)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
#line 1658 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */) = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, (data->simulationInfo->extObjs[0]), (data->localData[0]->realVars[200] /* intGai.timeScaled variable */));
#line 1018 OMC_FILE
  TRACE_POP
}

/*
equation index: 95
type: SIMPLE_ASSIGN
intGai.nextTimeEvent = if intGai.nextTimeEventScaled < 9.999999999999999e+59 then intGai.nextTimeEventScaled else 9.999999999999999e+59
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
  modelica_boolean tmp20;
#line 1659 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  tmp20 = Less((data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */),9.999999999999999e+59);
#line 1659 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[358] /* intGai.nextTimeEvent DISCRETE */) = (tmp20?(data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */):9.999999999999999e+59);
#line 1036 OMC_FILE
  TRACE_POP
}

/*
equation index: 96
type: SIMPLE_ASSIGN
weaDat.conTim.tNext = if weaDat.conTim.canRepeatWeatherFile then weaDat.conTim.lenWea * (1.0 + (*Real*)(integer(HDifTil[1].weaBus.cloTim / weaDat.conTim.lenWea))) else time
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[360] /* weaDat.conTim.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[416] /* weaDat.conTim.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),(data->simulationInfo->realParameter[416] /* weaDat.conTim.lenWea PARAM */),"weaDat.conTim.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 1051 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_452(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_453(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_454(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_455(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_456(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_457(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_458(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_459(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_460(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_461(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_462(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_463(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_464(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_465(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_466(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_467(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_468(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_469(DATA *data, threadData_t *threadData);


/*
equation index: 115
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.nOpa = min(1.0, max(0.0, weaDat.opaSkyCovSel.y))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterOpaqueSkyCover.mo"
  (data->localData[0]->realVars[123] /* HDifTil[1].weaBus.nOpa variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[354] /* weaDat.opaSkyCovSel.y variable */)));
#line 1102 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_472(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_473(DATA *data, threadData_t *threadData);


/*
equation index: 118
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.nTot = min(1.0, max(0.0, weaDat.totSkyCovSel.y))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterTotalSkyCover.mo"
  (data->localData[0]->realVars[124] /* HDifTil[1].weaBus.nTot variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[357] /* weaDat.totSkyCovSel.y variable */)));
#line 1121 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_476(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_477(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_478(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_479(DATA *data, threadData_t *threadData);


/*
equation index: 123
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.winDir = min(6.283185307179586, max(0.0, weaDat.conWinDir.y))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
#line 11 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterWindDirection.mo"
  (data->localData[0]->realVars[131] /* HDifTil[1].weaBus.winDir variable */) = fmin(6.283185307179586,fmax(0.0,(data->localData[0]->realVars[321] /* weaDat.conWinDir.y variable */)));
#line 1144 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_482(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_483(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_484(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_485(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_486(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_487(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_488(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_489(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_490(DATA *data, threadData_t *threadData);


/*
equation index: 133
type: SIMPLE_ASSIGN
HDifTil[1].weaBus.relHum = min(1.0, max(0.0, weaDat.relHumSel.uFil))
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterRelativeHumidity.mo"
  (data->localData[0]->realVars[125] /* HDifTil[1].weaBus.relHum variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[356] /* weaDat.relHumSel.uFil variable */)));
#line 1177 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_493(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_494(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_495(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_496(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_497(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_498(DATA *data, threadData_t *threadData);


/*
equation index: 140
type: SIMPLE_ASSIGN
eqAirTempVDI.TEqWin[1] = weaBus.TDryBul + eqAirTempVDI.delTEqLWWin
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
#line 76 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[194] /* eqAirTempVDI.TEqWin[1] variable */) = (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */) + (data->localData[0]->realVars[195] /* eqAirTempVDI.delTEqLWWin variable */);
#line 1204 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_499(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_500(DATA *data, threadData_t *threadData);


/*
equation index: 143
type: SIMPLE_ASSIGN
preTem1.T = 0.5 * (eqAirTemp.TEqWin[1] + eqAirTemp.TEqWin[2])
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
#line 25 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/VDI6007WithWindow.mo"
  (data->localData[0]->realVars[205] /* preTem1.T variable */) = (0.5) * ((data->localData[0]->realVars[188] /* eqAirTemp.TEqWin[1] variable */) + (data->localData[0]->realVars[189] /* eqAirTemp.TEqWin[2] variable */));
#line 1223 OMC_FILE
  TRACE_POP
}

/*
equation index: 144
type: SIMPLE_ASSIGN
weaDat.conTimMin.tNext = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.conTimMin.lenWea * (1.0 + (*Real*)(integer(weaDat.add30Min.y / weaDat.conTimMin.lenWea))) else time
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[361] /* weaDat.conTimMin.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[419] /* weaDat.conTimMin.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */),(data->simulationInfo->realParameter[419] /* weaDat.conTimMin.lenWea PARAM */),"weaDat.conTimMin.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 1238 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_414(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_415(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_416(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_575(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_418(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_545(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_417(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_419(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_420(DATA *data, threadData_t *threadData);


/*
equation index: 154
type: SIMPLE_ASSIGN
HDirTil[2].H = max(0.0, cos(HDirTil[2].inc) * HDifTil[1].weaBus.HDirNor)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DirectTiltedSurface.mo"
  (data->localData[0]->realVars[134] /* HDirTil[2].H variable */) = fmax(0.0,(cos((data->localData[0]->realVars[136] /* HDirTil[2].inc variable */))) * ((data->localData[0]->realVars[119] /* HDifTil[1].weaBus.HDirNor variable */)));
#line 1271 OMC_FILE
  TRACE_POP
}

/*
equation index: 155
type: SIMPLE_ASSIGN
HDirTil[1].H = max(0.0, cos(HDirTil[1].inc) * HDifTil[1].weaBus.HDirNor)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DirectTiltedSurface.mo"
  (data->localData[0]->realVars[133] /* HDirTil[1].H variable */) = fmax(0.0,(cos((data->localData[0]->realVars[135] /* HDirTil[1].inc variable */))) * ((data->localData[0]->realVars[119] /* HDifTil[1].weaBus.HDirNor variable */)));
#line 1286 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_550(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_564(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_562(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_560(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_563(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_558(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_561(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_556(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_559(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_554(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_557(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_552(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_555(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_551(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_553(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_570(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_569(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_568(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_577(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_567(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_566(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_565(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_576(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_588(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_520(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_534(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_532(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_530(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_533(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_528(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_531(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_526(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_529(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_524(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_527(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_522(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_525(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_521(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_523(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_540(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_539(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_538(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_547(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_537(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_536(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_535(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_546(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_582(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_421(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_422(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_425(DATA *data, threadData_t *threadData);


/*
equation index: 207
type: SIMPLE_ASSIGN
eqAirTempVDI.TEqWall[1] = weaBus.TDryBul + eqAirTempVDI.delTEqLWWin + eqAirTempVDI.delTEqSW[1]
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
#line 77 "/home/marius/modelica-buildings/Buildings/ThermalZones/ReducedOrder/EquivalentAirTemperature/BaseClasses/PartialVDI6007.mo"
  (data->localData[0]->realVars[193] /* eqAirTempVDI.TEqWall[1] variable */) = (data->localData[0]->realVars[313] /* weaBus.TDryBul variable */) + (data->localData[0]->realVars[195] /* eqAirTempVDI.delTEqLWWin variable */) + (data->localData[0]->realVars[196] /* eqAirTempVDI.delTEqSW[1] variable */);
#line 1403 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_424(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_632(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_638(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_633(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_589(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_640(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_641(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_642(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_423(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_608(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_610(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_639(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_609(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_637(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_636(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_635(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_634(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_583(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_611(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_612(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_613(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_643(DATA *data, threadData_t *threadData);


/*
equation index: 230
type: SIMPLE_ASSIGN
$PRE.weaDat.conTimMin.tNext = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  (data->simulationInfo->realVarsPre[361] /* weaDat.conTimMin.tNext DISCRETE */) = 0.0;
  TRACE_POP
}

/*
equation index: 231
type: SIMPLE_ASSIGN
$whenCondition3 = weaDat.conTimMin.canRepeatWeatherFile and weaDat.add30Min.y > $PRE.weaDat.conTimMin.tNext
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  modelica_boolean tmp21;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp21 = Greater((data->localData[0]->realVars[317] /* weaDat.add30Min.y variable */),(data->simulationInfo->realVarsPre[361] /* weaDat.conTimMin.tNext DISCRETE */));
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */) = ((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) && tmp21);
#line 1478 OMC_FILE
  TRACE_POP
}

/*
equation index: 232
type: SIMPLE_ASSIGN
$PRE.weaDat.conTim.tNext = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  (data->simulationInfo->realVarsPre[360] /* weaDat.conTim.tNext DISCRETE */) = 0.0;
  TRACE_POP
}

/*
equation index: 233
type: SIMPLE_ASSIGN
$whenCondition2 = weaDat.conTim.canRepeatWeatherFile and HDifTil[1].weaBus.cloTim > $PRE.weaDat.conTim.tNext
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  modelica_boolean tmp22;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp22 = Greater((data->localData[0]->realVars[122] /* HDifTil[1].weaBus.cloTim variable */),(data->simulationInfo->realVarsPre[360] /* weaDat.conTim.tNext DISCRETE */));
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) = ((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */) && tmp22);
#line 1509 OMC_FILE
  TRACE_POP
}

/*
equation index: 234
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermCapExt[1].der_T = $START.thermalZoneFourElements.extWallRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  (data->localData[0]->realVars[233] /* thermalZoneFourElements.extWallRC.thermCapExt[1].der_T variable */) = (data->modelData->realVarsData[233] /* thermalZoneFourElements.extWallRC.thermCapExt[1].der_T variable */).attribute .start;
  TRACE_POP
}

/*
equation index: 235
type: SIMPLE_ASSIGN
thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow = 5259932.23 * thermalZoneFourElements.extWallRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[234] /* thermalZoneFourElements.extWallRC.thermCapExt[1].port.Q_flow variable */) = (5259932.23) * ((data->localData[0]->realVars[233] /* thermalZoneFourElements.extWallRC.thermCapExt[1].der_T variable */));
#line 1537 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_772(DATA *data, threadData_t *threadData);


/*
equation index: 237
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermCapInt[1].der_T = $START.thermalZoneFourElements.intWallRC.thermCapInt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  (data->localData[0]->realVars[249] /* thermalZoneFourElements.intWallRC.thermCapInt[1].der_T variable */) = (data->modelData->realVarsData[249] /* thermalZoneFourElements.intWallRC.thermCapInt[1].der_T variable */).attribute .start;
  TRACE_POP
}

/*
equation index: 238
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow = 12391363.86 * thermalZoneFourElements.intWallRC.thermCapInt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[250] /* thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow variable */) = (12391363.86) * ((data->localData[0]->realVars[249] /* thermalZoneFourElements.intWallRC.thermCapInt[1].der_T variable */));
#line 1567 OMC_FILE
  TRACE_POP
}

/*
equation index: 239
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermResInt[1].dT = 0.000668895639141 * thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
#line 9 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/ThermalResistor.mo"
  (data->localData[0]->realVars[251] /* thermalZoneFourElements.intWallRC.thermResInt[1].dT variable */) = (0.000668895639141) * ((data->localData[0]->realVars[250] /* thermalZoneFourElements.intWallRC.thermCapInt[1].port.Q_flow variable */));
#line 1582 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_763(DATA *data, threadData_t *threadData);


/*
equation index: 241
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermCapExt[1].der_T = $START.thermalZoneFourElements.floorRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  (data->localData[0]->realVars[239] /* thermalZoneFourElements.floorRC.thermCapExt[1].der_T variable */) = (data->modelData->realVarsData[239] /* thermalZoneFourElements.floorRC.thermCapExt[1].der_T variable */).attribute .start;
  TRACE_POP
}

/*
equation index: 242
type: SIMPLE_ASSIGN
thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow = 5259932.23 * thermalZoneFourElements.floorRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[240] /* thermalZoneFourElements.floorRC.thermCapExt[1].port.Q_flow variable */) = (5259932.23) * ((data->localData[0]->realVars[239] /* thermalZoneFourElements.floorRC.thermCapExt[1].der_T variable */));
#line 1612 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_769(DATA *data, threadData_t *threadData);


/*
equation index: 244
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermCapExt[1].der_T = $START.thermalZoneFourElements.roofRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  (data->localData[0]->realVars[278] /* thermalZoneFourElements.roofRC.thermCapExt[1].der_T variable */) = (data->modelData->realVarsData[278] /* thermalZoneFourElements.roofRC.thermCapExt[1].der_T variable */).attribute .start;
  TRACE_POP
}

/*
equation index: 245
type: SIMPLE_ASSIGN
thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow = 5259932.23 * thermalZoneFourElements.roofRC.thermCapExt[1].der_T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
#line 16 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Components/HeatCapacitor.mo"
  (data->localData[0]->realVars[279] /* thermalZoneFourElements.roofRC.thermCapExt[1].port.Q_flow variable */) = (5259932.23) * ((data->localData[0]->realVars[278] /* thermalZoneFourElements.roofRC.thermCapExt[1].der_T variable */));
#line 1642 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_766(DATA *data, threadData_t *threadData);


/*
equation index: 247
type: SIMPLE_ASSIGN
$PRE.intGai.nextTimeEventScaled = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  (data->simulationInfo->realVarsPre[359] /* intGai.nextTimeEventScaled DISCRETE */) = 0.0;
  TRACE_POP
}

/*
equation index: 248
type: SIMPLE_ASSIGN
intGai.y[3] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer2(intGai.tableID, 3, intGai.timeScaled, intGai.nextTimeEventScaled, $PRE.intGai.nextTimeEventScaled)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
#line 1667 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[203] /* intGai.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer2(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 3), (data->localData[0]->realVars[200] /* intGai.timeScaled variable */), (data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[359] /* intGai.nextTimeEventScaled DISCRETE */));
#line 1672 OMC_FILE
  TRACE_POP
}

/*
equation index: 249
type: SIMPLE_ASSIGN
intGai.y[2] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer2(intGai.tableID, 2, intGai.timeScaled, intGai.nextTimeEventScaled, $PRE.intGai.nextTimeEventScaled)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
#line 1667 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[202] /* intGai.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer2(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 2), (data->localData[0]->realVars[200] /* intGai.timeScaled variable */), (data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[359] /* intGai.nextTimeEventScaled DISCRETE */));
#line 1687 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_778(DATA *data, threadData_t *threadData);


/*
equation index: 251
type: SIMPLE_ASSIGN
intGai.y[1] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer2(intGai.tableID, 1, intGai.timeScaled, intGai.nextTimeEventScaled, $PRE.intGai.nextTimeEventScaled)
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
#line 1667 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->realVars[201] /* intGai.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer2(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 1), (data->localData[0]->realVars[200] /* intGai.timeScaled variable */), (data->localData[0]->realVars[359] /* intGai.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[359] /* intGai.nextTimeEventScaled DISCRETE */));
#line 1704 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_672(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_673(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_674(DATA *data, threadData_t *threadData);


/*
equation index: 255
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.p = 101325.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
#line 203 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */) = 101325.0;
#line 1725 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_663(DATA *data, threadData_t *threadData);


/*
equation index: 257
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.T = 295.15
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
#line 194 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */) = 295.15;
#line 1742 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_664(DATA *data, threadData_t *threadData);


/*
equation index: 259
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.d = 0.003483702703378509 * thermalZoneFourElements.volAir.dynBal.medium.p / thermalZoneFourElements.volAir.dynBal.medium.T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
#line 6188 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[304] /* thermalZoneFourElements.volAir.dynBal.medium.d variable */) = (0.003483702703378509) * (DIVISION_SIM((data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */),(data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */),"thermalZoneFourElements.volAir.dynBal.medium.T",equationIndexes));
#line 1759 OMC_FILE
  TRACE_POP
}

/*
equation index: 260
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.m = 52.5 * thermalZoneFourElements.volAir.dynBal.medium.d
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
#line 254 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[5] /* thermalZoneFourElements.volAir.dynBal.m STATE(1) */) = (52.5) * ((data->localData[0]->realVars[304] /* thermalZoneFourElements.volAir.dynBal.medium.d variable */));
#line 1774 OMC_FILE
  TRACE_POP
}

/*
equation index: 261
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.hOut_internal = Buildings.ThermalZones.ReducedOrder.Examples.SimpleRoomFourElements.thermalZoneFourElements.volAir.dynBal.Medium.specificEnthalpy_pTX(thermalZoneFourElements.volAir.dynBal.medium.p, thermalZoneFourElements.volAir.dynBal.medium.T, {1.0})
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
#line 6182 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[308] /* thermalZoneFourElements.volAir.hOut_internal variable */) = omc_Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_thermalZoneFourElements_volAir_dynBal_Medium_specificEnthalpy__pTX(threadData, (data->localData[0]->realVars[305] /* thermalZoneFourElements.volAir.dynBal.medium.p variable */), (data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */), _OMC_LIT42);
#line 1789 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_662(DATA *data, threadData_t *threadData);


/*
equation index: 372
type: LINEAR

<var>thermalZoneFourElements.thermSplitterIntGains.portOut[3].T</var>
<var>thermalZoneFourElements.thermSplitterIntGains.portOut[5].T</var>
<var>thermalZoneFourElements.thermSplitterIntGains.portOut[4].T</var>
<var>thermalZoneFourElements.thermSplitterSolRad.portOut[2].T</var>
<var>thermalZoneFourElements.convExtWall.dT</var>
<row>

</row>
<matrix>
</matrix>
*/
OMC_DISABLE_OPT
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_372(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,372};
  /* Linear equation system */
  int retValue;
  double aux_x[5] = { (data->localData[1]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */),(data->localData[1]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */),(data->localData[1]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */),(data->localData[1]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */),(data->localData[1]->realVars[219] /* thermalZoneFourElements.convExtWall.dT variable */) };
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 372 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  
  retValue = solve_linear_system(data, threadData, 0, &aux_x[0]);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,372};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving linear system 372 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) = aux_x[0];
  (data->localData[0]->realVars[289] /* thermalZoneFourElements.thermSplitterIntGains.portOut[5].T variable */) = aux_x[1];
  (data->localData[0]->realVars[288] /* thermalZoneFourElements.thermSplitterIntGains.portOut[4].T variable */) = aux_x[2];
  (data->localData[0]->realVars[295] /* thermalZoneFourElements.thermSplitterSolRad.portOut[2].T variable */) = aux_x[3];
  (data->localData[0]->realVars[219] /* thermalZoneFourElements.convExtWall.dT variable */) = aux_x[4];

  TRACE_POP
}

/*
equation index: 373
type: SIMPLE_ASSIGN
thermalZoneFourElements.intWallRC.thermCapInt[1].T = thermalZoneFourElements.thermSplitterIntGains.portOut[3].T - thermalZoneFourElements.intWallRC.thermResInt[1].dT
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_373(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,373};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/Element1D.mo"
  (data->localData[0]->realVars[2] /* thermalZoneFourElements.intWallRC.thermCapInt[1].T STATE(1,thermalZoneFourElements.intWallRC.thermCapInt[1].der_T) */) = (data->localData[0]->realVars[287] /* thermalZoneFourElements.thermSplitterIntGains.portOut[3].T variable */) - (data->localData[0]->realVars[251] /* thermalZoneFourElements.intWallRC.thermResInt[1].dT variable */);
#line 1852 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_775(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_774(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_773(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_779(DATA *data, threadData_t *threadData);

extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_780(DATA *data, threadData_t *threadData);


/*
equation index: 379
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.u = thermalZoneFourElements.volAir.hOut_internal + (-287.0509010514002) * thermalZoneFourElements.volAir.dynBal.medium.T
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,379};
#line 6186 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[307] /* thermalZoneFourElements.volAir.dynBal.medium.u variable */) = (data->localData[0]->realVars[308] /* thermalZoneFourElements.volAir.hOut_internal variable */) + (-287.0509010514002) * ((data->localData[0]->realVars[301] /* thermalZoneFourElements.volAir.dynBal.medium.T variable */));
#line 1877 OMC_FILE
  TRACE_POP
}

/*
equation index: 380
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.U = thermalZoneFourElements.volAir.dynBal.m * thermalZoneFourElements.volAir.dynBal.medium.u
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,380};
#line 261 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[4] /* thermalZoneFourElements.volAir.dynBal.U STATE(1) */) = ((data->localData[0]->realVars[5] /* thermalZoneFourElements.volAir.dynBal.m STATE(1) */)) * ((data->localData[0]->realVars[307] /* thermalZoneFourElements.volAir.dynBal.medium.u variable */));
#line 1892 OMC_FILE
  TRACE_POP
}

/*
equation index: 381
type: SIMPLE_ASSIGN
weaDat.con30Min.y = 1800.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,381};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[318] /* weaDat.con30Min.y variable */) = 1800.0;
#line 1907 OMC_FILE
  TRACE_POP
}

/*
equation index: 382
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.R_s = 287.0509010514002
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,382};
#line 3987 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[300] /* thermalZoneFourElements.volAir.dynBal.medium.R_s variable */) = 287.0509010514002;
#line 1922 OMC_FILE
  TRACE_POP
}

/*
equation index: 383
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.medium.X[1] = 1.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,383};
#line 3984 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Media/package.mo"
  (data->localData[0]->realVars[303] /* thermalZoneFourElements.volAir.dynBal.medium.X[1] variable */) = 1.0;
#line 1937 OMC_FILE
  TRACE_POP
}

/*
equation index: 384
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.mb_flow = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,384};
#line 111 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[298] /* thermalZoneFourElements.volAir.dynBal.mb_flow variable */) = 0.0;
#line 1952 OMC_FILE
  TRACE_POP
}

/*
equation index: 385
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.dynBal.Hb_flow = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,385};
#line 116 "/home/marius/modelica-buildings/Buildings/Fluid/Interfaces/ConservationEquation.mo"
  (data->localData[0]->realVars[296] /* thermalZoneFourElements.volAir.dynBal.Hb_flow variable */) = 0.0;
#line 1967 OMC_FILE
  TRACE_POP
}

/*
equation index: 386
type: SIMPLE_ASSIGN
thermalZoneFourElements.hConExtWall_const.y = 31.05
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,386};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[243] /* thermalZoneFourElements.hConExtWall_const.y variable */) = 31.05;
#line 1982 OMC_FILE
  TRACE_POP
}

/*
equation index: 387
type: SIMPLE_ASSIGN
thermalZoneFourElements.hConWin_const.y = 37.8
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,387};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[247] /* thermalZoneFourElements.hConWin_const.y variable */) = 37.8;
#line 1997 OMC_FILE
  TRACE_POP
}

/*
equation index: 388
type: SIMPLE_ASSIGN
thermalZoneFourElements.senTAir.port.Q_flow = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,388};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[282] /* thermalZoneFourElements.senTAir.port.Q_flow variable */) = 0.0;
#line 2012 OMC_FILE
  TRACE_POP
}

/*
equation index: 389
type: SIMPLE_ASSIGN
thermalZoneFourElements.senTRad.port.Q_flow = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,389};
#line 4 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Thermal/HeatTransfer/Interfaces/HeatPort.mo"
  (data->localData[0]->realVars[283] /* thermalZoneFourElements.senTRad.port.Q_flow variable */) = 0.0;
#line 2027 OMC_FILE
  TRACE_POP
}

/*
equation index: 390
type: SIMPLE_ASSIGN
thermalZoneFourElements.hConIntWall.y = 128.26
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,390};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[245] /* thermalZoneFourElements.hConIntWall.y variable */) = 128.26;
#line 2042 OMC_FILE
  TRACE_POP
}

/*
equation index: 391
type: SIMPLE_ASSIGN
thermalZoneFourElements.hConFloor_const.y = 31.05
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,391};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[244] /* thermalZoneFourElements.hConFloor_const.y variable */) = 31.05;
#line 2057 OMC_FILE
  TRACE_POP
}

/*
equation index: 392
type: SIMPLE_ASSIGN
thermalZoneFourElements.hConRoof_const.y = 31.05
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,392};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[246] /* thermalZoneFourElements.hConRoof_const.y variable */) = 31.05;
#line 2072 OMC_FILE
  TRACE_POP
}

/*
equation index: 393
type: SIMPLE_ASSIGN
const[1].y = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,393};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[155] /* const[1].y variable */) = 0.0;
#line 2087 OMC_FILE
  TRACE_POP
}

/*
equation index: 394
type: SIMPLE_ASSIGN
const[2].y = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[156] /* const[2].y variable */) = 0.0;
#line 2102 OMC_FILE
  TRACE_POP
}

/*
equation index: 395
type: SIMPLE_ASSIGN
hConWall.y = 287.5
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[198] /* hConWall.y variable */) = 287.5;
#line 2117 OMC_FILE
  TRACE_POP
}

/*
equation index: 396
type: SIMPLE_ASSIGN
hConWin.y = 280.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,396};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[199] /* hConWin.y variable */) = 280.0;
#line 2132 OMC_FILE
  TRACE_POP
}

/*
equation index: 397
type: SIMPLE_ASSIGN
TSoil.y = 283.15
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,397};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[154] /* TSoil.y variable */) = 283.15;
#line 2147 OMC_FILE
  TRACE_POP
}

/*
equation index: 398
type: SIMPLE_ASSIGN
hConRoof.y = 287.5
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,398};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[197] /* hConRoof.y variable */) = 287.5;
#line 2162 OMC_FILE
  TRACE_POP
}

/*
equation index: 399
type: SIMPLE_ASSIGN
const1.y = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,399};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[157] /* const1.y variable */) = 0.0;
#line 2177 OMC_FILE
  TRACE_POP
}

/*
equation index: 400
type: SIMPLE_ASSIGN
HDifTil[1].briCoe.d = 0.01
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,400};
#line 27 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[82] /* HDifTil[1].briCoe.d variable */) = 0.01;
#line 2192 OMC_FILE
  TRACE_POP
}

/*
equation index: 401
type: SIMPLE_ASSIGN
HDifTil[2].briCoe.d = 0.01
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,401};
#line 27 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/BrighteningCoefficient.mo"
  (data->localData[0]->realVars[83] /* HDifTil[2].briCoe.d variable */) = 0.01;
#line 2207 OMC_FILE
  TRACE_POP
}

/*
equation index: 402
type: SIMPLE_ASSIGN
thermalZoneFourElements.volAir.p = 101325.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,402};
#line 44 "/home/marius/modelica-buildings/Buildings/Fluid/MixingVolumes/BaseClasses/PartialMixingVolume.mo"
  (data->localData[0]->realVars[310] /* thermalZoneFourElements.volAir.p variable */) = 101325.0;
#line 2222 OMC_FILE
  TRACE_POP
}
extern void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_665(DATA *data, threadData_t *threadData);


/*
equation index: 404
type: SIMPLE_ASSIGN
$PRE.intGai.nextTimeEvent = 0.0
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,404};
  (data->simulationInfo->realVarsPre[358] /* intGai.nextTimeEvent DISCRETE */) = 0.0;
  TRACE_POP
}

/*
equation index: 405
type: SIMPLE_ASSIGN
$whenCondition1 = time >= $PRE.intGai.nextTimeEvent
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,405};
  modelica_boolean tmp23;
#line 1658 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  tmp23 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realVarsPre[358] /* intGai.nextTimeEvent DISCRETE */));
#line 1658 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo"
  (data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) = tmp23;
#line 2255 OMC_FILE
  TRACE_POP
}

/*
equation index: 409
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0), "In SimpleRoomFourElements.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTimMin.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,409};
  modelica_boolean tmp24;
  static const MMC_DEFSTRINGLIT(tmp25,138,"In SimpleRoomFourElements.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp26;
  modelica_metatype tmpMeta27;
  static const MMC_DEFSTRINGLIT(tmp28,22," exceeds the end time ");
  modelica_metatype tmpMeta29;
  modelica_string tmp30;
  modelica_metatype tmpMeta31;
  static const MMC_DEFSTRINGLIT(tmp32,26," of the weather data file.");
  modelica_metatype tmpMeta33;
  static int tmp34 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp24 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[420] /* weaDat.conTimMin.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp24))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp26 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta27 = stringAppend(MMC_REFSTRINGLIT(tmp25),tmp26);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta29 = stringAppend(tmpMeta27,MMC_REFSTRINGLIT(tmp28));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp30 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[420] /* weaDat.conTimMin.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta31 = stringAppend(tmpMeta29,tmp30);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta33 = stringAppend(tmpMeta31,MMC_REFSTRINGLIT(tmp32));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta33));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta33));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2327 OMC_FILE
  TRACE_POP
}

/*
equation index: 408
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim), "In SimpleRoomFourElements.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTimMin.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,408};
  modelica_boolean tmp35;
  static const MMC_DEFSTRINGLIT(tmp36,138,"In SimpleRoomFourElements.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp37;
  modelica_metatype tmpMeta38;
  static const MMC_DEFSTRINGLIT(tmp39,29," is less than the start time ");
  modelica_metatype tmpMeta40;
  modelica_string tmp41;
  modelica_metatype tmpMeta42;
  static const MMC_DEFSTRINGLIT(tmp43,26," of the weather data file.");
  modelica_metatype tmpMeta44;
  static int tmp45 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp35 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[421] /* weaDat.conTimMin.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[31] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp35))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp37 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta38 = stringAppend(MMC_REFSTRINGLIT(tmp36),tmp37);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta40 = stringAppend(tmpMeta38,MMC_REFSTRINGLIT(tmp39));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp41 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[421] /* weaDat.conTimMin.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta42 = stringAppend(tmpMeta40,tmp41);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta44 = stringAppend(tmpMeta42,MMC_REFSTRINGLIT(tmp43));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta44));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta44));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2399 OMC_FILE
  TRACE_POP
}

/*
equation index: 407
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0), "In SimpleRoomFourElements.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTim.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,407};
  modelica_boolean tmp46;
  static const MMC_DEFSTRINGLIT(tmp47,135,"In SimpleRoomFourElements.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp48;
  modelica_metatype tmpMeta49;
  static const MMC_DEFSTRINGLIT(tmp50,22," exceeds the end time ");
  modelica_metatype tmpMeta51;
  modelica_string tmp52;
  modelica_metatype tmpMeta53;
  static const MMC_DEFSTRINGLIT(tmp54,26," of the weather data file.");
  modelica_metatype tmpMeta55;
  static int tmp56 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp46 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[417] /* weaDat.conTim.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp46))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp48 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta49 = stringAppend(MMC_REFSTRINGLIT(tmp47),tmp48);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta51 = stringAppend(tmpMeta49,MMC_REFSTRINGLIT(tmp50));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp52 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[417] /* weaDat.conTim.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta53 = stringAppend(tmpMeta51,tmp52);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta55 = stringAppend(tmpMeta53,MMC_REFSTRINGLIT(tmp54));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta55));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta55));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2471 OMC_FILE
  TRACE_POP
}

/*
equation index: 406
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim), "In SimpleRoomFourElements.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTim.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,406};
  modelica_boolean tmp57;
  static const MMC_DEFSTRINGLIT(tmp58,135,"In SimpleRoomFourElements.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp59;
  modelica_metatype tmpMeta60;
  static const MMC_DEFSTRINGLIT(tmp61,29," is less than the start time ");
  modelica_metatype tmpMeta62;
  modelica_string tmp63;
  modelica_metatype tmpMeta64;
  static const MMC_DEFSTRINGLIT(tmp65,26," of the weather data file.");
  modelica_metatype tmpMeta66;
  static int tmp67 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp57 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[418] /* weaDat.conTim.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[30] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp57))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp59 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta60 = stringAppend(MMC_REFSTRINGLIT(tmp58),tmp59);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta62 = stringAppend(tmpMeta60,MMC_REFSTRINGLIT(tmp61));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp63 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[418] /* weaDat.conTim.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta64 = stringAppend(tmpMeta62,tmp63);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta66 = stringAppend(tmpMeta64,MMC_REFSTRINGLIT(tmp65));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta66));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta66));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2543 OMC_FILE
  TRACE_POP
}
OMC_DISABLE_OPT
void Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_1(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_2(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_3(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_4(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_5(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_6(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_7(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_8(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_9(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_10(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_11(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_12(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_13(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_14(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_410(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_411(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_426(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_427(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_19(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_432(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_21(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_433(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_23(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_517(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_518(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_519(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_541(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_542(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_29(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_30(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_31(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_435(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_548(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_549(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_571(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_572(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_37(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_38(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_39(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_438(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_41(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_441(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_43(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_444(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_668(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_46(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_47(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_437(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_436(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_580(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_581(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_52(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_53(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_440(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_439(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_586(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_587(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_58(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_59(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_443(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_442(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_592(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_596(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_593(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_594(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_595(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_598(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_600(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_597(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_602(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_599(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_601(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_603(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_604(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_605(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_76(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_77(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_446(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_445(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_616(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_620(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_617(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_618(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_619(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_622(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_624(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_621(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_626(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_623(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_625(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_627(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_628(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_629(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_94(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_95(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_96(data, threadData);
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
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_115(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_472(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_473(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_118(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_476(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_477(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_478(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_479(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_123(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_482(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_483(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_484(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_485(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_486(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_487(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_488(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_489(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_490(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_133(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_493(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_494(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_495(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_496(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_497(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_498(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_140(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_499(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_500(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_143(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_144(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_414(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_415(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_416(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_575(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_418(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_545(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_417(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_419(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_420(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_154(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_155(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_550(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_564(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_562(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_560(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_563(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_558(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_561(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_556(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_559(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_554(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_557(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_552(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_555(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_551(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_553(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_570(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_569(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_568(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_577(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_567(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_566(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_565(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_576(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_588(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_520(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_534(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_532(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_530(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_533(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_528(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_531(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_526(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_529(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_524(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_527(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_522(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_525(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_521(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_523(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_540(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_539(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_538(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_547(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_537(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_536(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_535(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_546(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_582(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_421(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_422(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_425(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_207(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_424(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_632(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_638(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_633(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_589(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_640(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_641(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_642(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_423(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_608(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_610(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_639(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_609(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_637(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_636(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_635(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_634(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_583(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_611(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_612(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_613(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_643(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_230(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_231(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_232(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_233(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_234(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_235(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_772(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_237(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_238(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_239(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_763(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_241(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_242(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_769(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_244(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_245(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_766(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_247(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_248(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_249(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_778(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_251(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_672(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_673(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_674(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_255(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_663(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_257(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_664(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_259(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_260(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_261(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_662(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_372(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_373(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_775(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_774(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_773(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_779(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_780(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_379(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_380(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_381(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_382(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_383(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_384(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_385(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_386(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_387(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_388(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_389(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_390(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_391(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_392(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_393(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_394(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_395(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_396(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_397(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_398(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_399(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_400(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_401(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_402(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_665(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_404(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_405(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_409(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_408(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_407(data, threadData);
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_eqFunction_406(data, threadData);
  TRACE_POP
}

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionInitialEquations_lambda0 function */

int Buildings_ThermalZones_ReducedOrder_Examples_SimpleRoomFourElements_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

