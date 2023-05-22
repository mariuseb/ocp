#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustom/Buildings_HeatTransfer_Windows_Examples_WinRadCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustom_06inz.c"
#endif
/* Initialization */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_11mix.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
weaDat.souSelRad.HDifHor_in_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
  (data->localData[0]->realVars[109] /* weaDat.souSelRad.HDifHor_in_internal variable */) = 0.0;
#line 27 OMC_FILE
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
weaDat.pAtmSel.y = 101325.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[108] /* weaDat.pAtmSel.y variable */) = 101325.0;
#line 42 OMC_FILE
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.TDryBul_degC = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
#line 35 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  (data->localData[0]->realVars[110] /* weaDat.tWetBul_TDryBulXi.TDryBul_degC variable */) = 0.0;
#line 57 OMC_FILE
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.rh_per = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
#line 37 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  (data->localData[0]->realVars[114] /* weaDat.tWetBul_TDryBulXi.rh_per variable */) = 0.0;
#line 72 OMC_FILE
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
winRad.staIntQAbsExtSha_flow.uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[132] /* winRad.staIntQAbsExtSha_flow.uSta_internal variable */) = 0.0;
#line 87 OMC_FILE
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
winRad.staIntQAbsGlaUns_flow[1].uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[135] /* winRad.staIntQAbsGlaUns_flow[1].uSta_internal variable */) = 0.0;
#line 102 OMC_FILE
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
winRad.staIntQAbsGlaUns_flow[2].uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[136] /* winRad.staIntQAbsGlaUns_flow[2].uSta_internal variable */) = 0.0;
#line 117 OMC_FILE
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
winRad.staIntQAbsGlaSha_flow[1].uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[133] /* winRad.staIntQAbsGlaSha_flow[1].uSta_internal variable */) = 0.0;
#line 132 OMC_FILE
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
winRad.staIntQAbsGlaSha_flow[2].uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[134] /* winRad.staIntQAbsGlaSha_flow[2].uSta_internal variable */) = 0.0;
#line 147 OMC_FILE
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
winRad.staIntQAbsIntSha_flow.uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[137] /* winRad.staIntQAbsIntSha_flow.uSta_internal variable */) = 0.0;
#line 162 OMC_FILE
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
winRad.staIntQTraDif_flow.uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[138] /* winRad.staIntQTraDif_flow.uSta_internal variable */) = 0.0;
#line 177 OMC_FILE
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
winRad.staIntQTraDir_flow.uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[139] /* winRad.staIntQTraDir_flow.uSta_internal variable */) = 0.0;
#line 192 OMC_FILE
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.lat_s = sin(weaDat.latitude.latitude)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
#line 30 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[29] /* HDirTil.incAng.incAng.lat_s variable */) = sin((data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */));
#line 207 OMC_FILE
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.lat_c = cos(weaDat.latitude.latitude)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
#line 29 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[28] /* HDirTil.incAng.incAng.lat_c variable */) = cos((data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */));
#line 222 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_227(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_236(DATA *data, threadData_t *threadData);


/*
equation index: 17
type: SIMPLE_ASSIGN
weaDat.conTimMin.tNext = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.conTimMin.lenWea * (1.0 + (*Real*)(integer(weaDat.add30Min.y / weaDat.conTimMin.lenWea))) else time
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[148] /* weaDat.conTimMin.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[94] /* weaDat.conTimMin.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[69] /* weaDat.add30Min.y variable */),(data->simulationInfo->realParameter[94] /* weaDat.conTimMin.lenWea PARAM */),"weaDat.conTimMin.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 241 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_239(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_240(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_241(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_242(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_243(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_244(DATA *data, threadData_t *threadData);


/*
equation index: 24
type: SIMPLE_ASSIGN
weaDat.eqnTim.eqnTim = 60.0 * (9.869999999999999 * sin(2.0 * weaDat.eqnTim.Bt) + (-7.53) * cos(weaDat.eqnTim.Bt) + (-1.5) * sin(weaDat.eqnTim.Bt))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[106] /* weaDat.eqnTim.eqnTim variable */) = (60.0) * ((9.869999999999999) * (sin((2.0) * ((data->localData[0]->realVars[105] /* weaDat.eqnTim.Bt variable */)))) + (-7.53) * (cos((data->localData[0]->realVars[105] /* weaDat.eqnTim.Bt variable */))) + (-1.5) * (sin((data->localData[0]->realVars[105] /* weaDat.eqnTim.Bt variable */))));
#line 268 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_249(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_250(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_257(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_258(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_265(DATA *data, threadData_t *threadData);


/*
equation index: 30
type: SIMPLE_ASSIGN
weaBus.solDec = asin((-0.3979486313076103) * cos((weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  modelica_real tmp0;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp0 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[58] /* weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * cos((weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)) outside the domain -1.0 <= %g <= 1.0", tmp0);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  (data->localData[0]->realVars[63] /* weaBus.solDec variable */) = asin(tmp0);
#line 320 OMC_FILE
  TRACE_POP
}

/*
equation index: 31
type: SIMPLE_ASSIGN
weaBus.solZen = acos(cos(weaDat.latitude.latitude) * cos(weaBus.solDec) * cos(weaBus.solHouAng) + sin(weaDat.latitude.latitude) * sin(weaBus.solDec))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  modelica_real tmp1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  tmp1 = ((cos((data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */))) * (cos((data->localData[0]->realVars[63] /* weaBus.solDec variable */)))) * (cos((data->localData[0]->realVars[64] /* weaBus.solHouAng variable */))) + (sin((data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */))) * (sin((data->localData[0]->realVars[63] /* weaBus.solDec variable */)));
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of acos(cos(weaDat.latitude.latitude) * cos(weaBus.solDec) * cos(weaBus.solHouAng) + sin(weaDat.latitude.latitude) * sin(weaBus.solDec)) outside the domain -1.0 <= %g <= 1.0", tmp1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  (data->localData[0]->realVars[66] /* weaBus.solZen variable */) = acos(tmp1);
#line 362 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_253(DATA *data, threadData_t *threadData);


/*
equation index: 33
type: SIMPLE_ASSIGN
HDirTil.incAng.decAng.decAng = asin((-0.3979486313076103) * cos((weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  modelica_real tmp2;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp2 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[58] /* weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  if(!(tmp2 >= -1.0 && tmp2 <= 1.0))
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
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of asin((-0.3979486313076103) * cos((weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848)) outside the domain -1.0 <= %g <= 1.0", tmp2);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  (data->localData[0]->realVars[25] /* HDirTil.incAng.decAng.decAng variable */) = asin(tmp2);
#line 406 OMC_FILE
  TRACE_POP
}

/*
equation index: 34
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.dec_c = cos(HDirTil.incAng.decAng.decAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[26] /* HDirTil.incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[25] /* HDirTil.incAng.decAng.decAng variable */));
#line 421 OMC_FILE
  TRACE_POP
}

/*
equation index: 35
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.dec_s = sin(HDirTil.incAng.decAng.decAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[27] /* HDirTil.incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[25] /* HDirTil.incAng.decAng.decAng variable */));
#line 436 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_259(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_260(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_261(DATA *data, threadData_t *threadData);


/*
equation index: 39
type: SIMPLE_ASSIGN
weaDat.conTim.tNext = if weaDat.conTim.canRepeatWeatherFile then weaDat.conTim.lenWea * (1.0 + (*Real*)(integer(weaBus.cloTim / weaDat.conTim.lenWea))) else time
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[147] /* weaDat.conTim.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[91] /* weaDat.conTim.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[58] /* weaBus.cloTim variable */),(data->simulationInfo->realParameter[91] /* weaDat.conTim.lenWea PARAM */),"weaDat.conTim.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 457 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_267(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_303(DATA *data, threadData_t *threadData);


/*
equation index: 42
type: SIMPLE_ASSIGN
HDirTil.H = max(0.0, cos(HDirTil.inc) * weaBus.HDirNor)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DirectTiltedSurface.mo"
  (data->localData[0]->realVars[23] /* HDirTil.H variable */) = fmax(0.0,(cos((data->localData[0]->realVars[24] /* HDirTil.inc variable */))) * ((data->localData[0]->realVars[53] /* weaBus.HDirNor variable */)));
#line 476 OMC_FILE
  TRACE_POP
}

/*
equation index: 43
type: SIMPLE_ASSIGN
weaBus.HDifHor = max(0.0, HGloHor_in - HDirNor_in * cos(weaBus.solZen))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
#line 125 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
  (data->localData[0]->realVars[52] /* weaBus.HDifHor variable */) = fmax(0.0,(data->localData[0]->realVars[33] /* HGloHor_in variable */) - (((data->localData[0]->realVars[22] /* HDirNor_in variable */)) * (cos((data->localData[0]->realVars[66] /* weaBus.solZen variable */)))));
#line 491 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_297(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_296(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_295(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_294(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_293(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_292(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_291(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_290(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_289(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_288(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_287(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_286(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_285(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_284(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_283(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_282(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_280(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_281(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_279(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_278(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_277(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_276(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_275(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_274(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_273(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_272(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_270(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_271(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_268(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_269(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_298(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_256(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_299(DATA *data, threadData_t *threadData);


/*
equation index: 77
type: SIMPLE_ASSIGN
$PRE.weaDat.conTimMin.tNext = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  (data->simulationInfo->realVarsPre[148] /* weaDat.conTimMin.tNext DISCRETE */) = 0.0;
  TRACE_POP
}

/*
equation index: 78
type: SIMPLE_ASSIGN
$whenCondition1 = weaDat.conTimMin.canRepeatWeatherFile and weaDat.add30Min.y > $PRE.weaDat.conTimMin.tNext
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  modelica_boolean tmp3;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp3 = Greater((data->localData[0]->realVars[69] /* weaDat.add30Min.y variable */),(data->simulationInfo->realVarsPre[148] /* weaDat.conTimMin.tNext DISCRETE */));
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) && tmp3);
#line 588 OMC_FILE
  TRACE_POP
}

/*
equation index: 79
type: SIMPLE_ASSIGN
$PRE.weaDat.conTim.tNext = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  (data->simulationInfo->realVarsPre[147] /* weaDat.conTim.tNext DISCRETE */) = 0.0;
  TRACE_POP
}

/*
equation index: 80
type: SIMPLE_ASSIGN
$whenCondition2 = weaDat.conTim.canRepeatWeatherFile and weaBus.cloTim > $PRE.weaDat.conTim.tNext
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  modelica_boolean tmp4;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp4 = Greater((data->localData[0]->realVars[58] /* weaBus.cloTim variable */),(data->simulationInfo->realVarsPre[147] /* weaDat.conTim.tNext DISCRETE */));
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) && tmp4);
#line 619 OMC_FILE
  TRACE_POP
}

/*
equation index: 81
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[12,1] = 0.3052322754811356
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[144] /* winRad.abs.coeAbsDevExtIrrIntSha[12,1] PARAM */) = 0.3052322754811356;
#line 634 OMC_FILE
  TRACE_POP
}

/*
equation index: 82
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[13,1] = winRad.abs.coeAbsDevExtIrrIntSha[12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[145] /* winRad.abs.coeAbsDevExtIrrIntSha[13,1] PARAM */) = (data->simulationInfo->realParameter[144] /* winRad.abs.coeAbsDevExtIrrIntSha[12,1] PARAM */);
#line 649 OMC_FILE
  TRACE_POP
}

/*
equation index: 83
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[143] /* winRad.abs.coeAbsDevExtIrrIntSha[11,1] PARAM */) = 0.0;
#line 664 OMC_FILE
  TRACE_POP
}

/*
equation index: 84
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[10,1] = 0.1062597676765009
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[142] /* winRad.abs.coeAbsDevExtIrrIntSha[10,1] PARAM */) = 0.1062597676765009;
#line 679 OMC_FILE
  TRACE_POP
}

/*
equation index: 85
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[9,1] = 0.2282840296108259
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[141] /* winRad.abs.coeAbsDevExtIrrIntSha[9,1] PARAM */) = 0.2282840296108259;
#line 694 OMC_FILE
  TRACE_POP
}

/*
equation index: 86
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[8,1] = 0.3020070366994245
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_86(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[140] /* winRad.abs.coeAbsDevExtIrrIntSha[8,1] PARAM */) = 0.3020070366994245;
#line 709 OMC_FILE
  TRACE_POP
}

/*
equation index: 87
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[7,1] = 0.3384699121977249
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[139] /* winRad.abs.coeAbsDevExtIrrIntSha[7,1] PARAM */) = 0.3384699121977249;
#line 724 OMC_FILE
  TRACE_POP
}

/*
equation index: 88
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[6,1] = 0.3555423033605714
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[138] /* winRad.abs.coeAbsDevExtIrrIntSha[6,1] PARAM */) = 0.3555423033605714;
#line 739 OMC_FILE
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[5,1] = 0.3635548084822143
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[137] /* winRad.abs.coeAbsDevExtIrrIntSha[5,1] PARAM */) = 0.3635548084822143;
#line 754 OMC_FILE
  TRACE_POP
}

/*
equation index: 90
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[4,1] = 0.3673475997451543
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[4,1] PARAM */) = 0.3673475997451543;
#line 769 OMC_FILE
  TRACE_POP
}

/*
equation index: 91
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[3,1] = 0.3690498410990196
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[135] /* winRad.abs.coeAbsDevExtIrrIntSha[3,1] PARAM */) = 0.3690498410990196;
#line 784 OMC_FILE
  TRACE_POP
}

/*
equation index: 92
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[2,1] = 0.3695381144818747
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[134] /* winRad.abs.coeAbsDevExtIrrIntSha[2,1] PARAM */) = 0.3695381144818747;
#line 799 OMC_FILE
  TRACE_POP
}

/*
equation index: 93
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[1,1] = winRad.abs.coeAbsDevExtIrrIntSha[2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
#line 120 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */) = (data->simulationInfo->realParameter[134] /* winRad.abs.coeAbsDevExtIrrIntSha[2,1] PARAM */);
#line 814 OMC_FILE
  TRACE_POP
}

/*
equation index: 94
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,12,1] = 0.1039656205865592
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[198] /* winRad.abs.coeAbsEx[2,2,12,1] PARAM */) = 0.1039656205865592;
#line 829 OMC_FILE
  TRACE_POP
}

/*
equation index: 95
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,13,1] = winRad.abs.coeAbsEx[2,2,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
#line 103 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[199] /* winRad.abs.coeAbsEx[2,2,13,1] PARAM */) = (data->simulationInfo->realParameter[198] /* winRad.abs.coeAbsEx[2,2,12,1] PARAM */);
#line 844 OMC_FILE
  TRACE_POP
}

/*
equation index: 96
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,12,1] = 0.08526920479249403
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[172] /* winRad.abs.coeAbsEx[1,2,12,1] PARAM */) = 0.08526920479249403;
#line 859 OMC_FILE
  TRACE_POP
}

/*
equation index: 97
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,13,1] = winRad.abs.coeAbsEx[1,2,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_97(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,97};
#line 103 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[173] /* winRad.abs.coeAbsEx[1,2,13,1] PARAM */) = (data->simulationInfo->realParameter[172] /* winRad.abs.coeAbsEx[1,2,12,1] PARAM */);
#line 874 OMC_FILE
  TRACE_POP
}

/*
equation index: 98
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[197] /* winRad.abs.coeAbsEx[2,2,11,1] PARAM */) = 0.0;
#line 889 OMC_FILE
  TRACE_POP
}

/*
equation index: 99
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[171] /* winRad.abs.coeAbsEx[1,2,11,1] PARAM */) = 0.0;
#line 904 OMC_FILE
  TRACE_POP
}

/*
equation index: 100
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,10,1] = 0.06281787526849789
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[196] /* winRad.abs.coeAbsEx[2,2,10,1] PARAM */) = 0.06281787526849789;
#line 919 OMC_FILE
  TRACE_POP
}

/*
equation index: 101
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,10,1] = 0.05645076246299933
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[170] /* winRad.abs.coeAbsEx[1,2,10,1] PARAM */) = 0.05645076246299933;
#line 934 OMC_FILE
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,9,1] = 0.08990517963983256
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[195] /* winRad.abs.coeAbsEx[2,2,9,1] PARAM */) = 0.08990517963983256;
#line 949 OMC_FILE
  TRACE_POP
}

/*
equation index: 103
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,9,1] = 0.07585615681252504
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[169] /* winRad.abs.coeAbsEx[1,2,9,1] PARAM */) = 0.07585615681252504;
#line 964 OMC_FILE
  TRACE_POP
}

/*
equation index: 104
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,8,1] = 0.1011252056324434
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[194] /* winRad.abs.coeAbsEx[2,2,8,1] PARAM */) = 0.1011252056324434;
#line 979 OMC_FILE
  TRACE_POP
}

/*
equation index: 105
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,8,1] = 0.08303389367545573
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[168] /* winRad.abs.coeAbsEx[1,2,8,1] PARAM */) = 0.08303389367545573;
#line 994 OMC_FILE
  TRACE_POP
}

/*
equation index: 106
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,7,1] = 0.1033001439761687
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[193] /* winRad.abs.coeAbsEx[2,2,7,1] PARAM */) = 0.1033001439761687;
#line 1009 OMC_FILE
  TRACE_POP
}

/*
equation index: 107
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,7,1] = 0.08385431211898785
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[167] /* winRad.abs.coeAbsEx[1,2,7,1] PARAM */) = 0.08385431211898785;
#line 1024 OMC_FILE
  TRACE_POP
}

/*
equation index: 108
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,6,1] = 0.1017176618131253
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[192] /* winRad.abs.coeAbsEx[2,2,6,1] PARAM */) = 0.1017176618131253;
#line 1039 OMC_FILE
  TRACE_POP
}

/*
equation index: 109
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,6,1] = 0.08216023482328237
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[166] /* winRad.abs.coeAbsEx[1,2,6,1] PARAM */) = 0.08216023482328237;
#line 1054 OMC_FILE
  TRACE_POP
}

/*
equation index: 110
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,5,1] = 0.09916070692199794
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[191] /* winRad.abs.coeAbsEx[2,2,5,1] PARAM */) = 0.09916070692199794;
#line 1069 OMC_FILE
  TRACE_POP
}

/*
equation index: 111
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,5,1] = 0.07991551880977556
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[165] /* winRad.abs.coeAbsEx[1,2,5,1] PARAM */) = 0.07991551880977556;
#line 1084 OMC_FILE
  TRACE_POP
}

/*
equation index: 112
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,4,1] = 0.09687385356797265
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[190] /* winRad.abs.coeAbsEx[2,2,4,1] PARAM */) = 0.09687385356797265;
#line 1099 OMC_FILE
  TRACE_POP
}

/*
equation index: 113
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,4,1] = 0.07799186166816173
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[164] /* winRad.abs.coeAbsEx[1,2,4,1] PARAM */) = 0.07799186166816173;
#line 1114 OMC_FILE
  TRACE_POP
}

/*
equation index: 114
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,3,1] = 0.09537350821079466
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[189] /* winRad.abs.coeAbsEx[2,2,3,1] PARAM */) = 0.09537350821079466;
#line 1129 OMC_FILE
  TRACE_POP
}

/*
equation index: 115
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,3,1] = 0.07674905803113916
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[163] /* winRad.abs.coeAbsEx[1,2,3,1] PARAM */) = 0.07674905803113916;
#line 1144 OMC_FILE
  TRACE_POP
}

/*
equation index: 116
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,2,1] = 0.0948566787482195
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[188] /* winRad.abs.coeAbsEx[2,2,2,1] PARAM */) = 0.0948566787482195;
#line 1159 OMC_FILE
  TRACE_POP
}

/*
equation index: 117
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,1,1] = winRad.abs.coeAbsEx[2,2,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
#line 102 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[187] /* winRad.abs.coeAbsEx[2,2,1,1] PARAM */) = (data->simulationInfo->realParameter[188] /* winRad.abs.coeAbsEx[2,2,2,1] PARAM */);
#line 1174 OMC_FILE
  TRACE_POP
}

/*
equation index: 118
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,2,1] = 0.07632331866750475
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[162] /* winRad.abs.coeAbsEx[1,2,2,1] PARAM */) = 0.07632331866750475;
#line 1189 OMC_FILE
  TRACE_POP
}

/*
equation index: 119
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,1,1] = winRad.abs.coeAbsEx[1,2,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
#line 102 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[161] /* winRad.abs.coeAbsEx[1,2,1,1] PARAM */) = (data->simulationInfo->realParameter[162] /* winRad.abs.coeAbsEx[1,2,2,1] PARAM */);
#line 1204 OMC_FILE
  TRACE_POP
}

/*
equation index: 120
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,12,1] = 0.1354931525419724
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[185] /* winRad.abs.coeAbsEx[2,1,12,1] PARAM */) = 0.1354931525419724;
#line 1219 OMC_FILE
  TRACE_POP
}

/*
equation index: 121
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,13,1] = winRad.abs.coeAbsEx[2,1,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
#line 103 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[186] /* winRad.abs.coeAbsEx[2,1,13,1] PARAM */) = (data->simulationInfo->realParameter[185] /* winRad.abs.coeAbsEx[2,1,12,1] PARAM */);
#line 1234 OMC_FILE
  TRACE_POP
}

/*
equation index: 122
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,12,1] = 0.1227196468033888
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[159] /* winRad.abs.coeAbsEx[1,1,12,1] PARAM */) = 0.1227196468033888;
#line 1249 OMC_FILE
  TRACE_POP
}

/*
equation index: 123
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,13,1] = winRad.abs.coeAbsEx[1,1,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
#line 103 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[160] /* winRad.abs.coeAbsEx[1,1,13,1] PARAM */) = (data->simulationInfo->realParameter[159] /* winRad.abs.coeAbsEx[1,1,12,1] PARAM */);
#line 1264 OMC_FILE
  TRACE_POP
}

/*
equation index: 124
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[184] /* winRad.abs.coeAbsEx[2,1,11,1] PARAM */) = 0.0;
#line 1279 OMC_FILE
  TRACE_POP
}

/*
equation index: 125
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[158] /* winRad.abs.coeAbsEx[1,1,11,1] PARAM */) = 0.0;
#line 1294 OMC_FILE
  TRACE_POP
}

/*
equation index: 126
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,10,1] = 0.1415178832813775
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[183] /* winRad.abs.coeAbsEx[2,1,10,1] PARAM */) = 0.1415178832813775;
#line 1309 OMC_FILE
  TRACE_POP
}

/*
equation index: 127
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,10,1] = 0.1371678328302604
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[157] /* winRad.abs.coeAbsEx[1,1,10,1] PARAM */) = 0.1371678328302604;
#line 1324 OMC_FILE
  TRACE_POP
}

/*
equation index: 128
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,9,1] = 0.1403970614972095
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[182] /* winRad.abs.coeAbsEx[2,1,9,1] PARAM */) = 0.1403970614972095;
#line 1339 OMC_FILE
  TRACE_POP
}

/*
equation index: 129
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,9,1] = 0.1307986830869973
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[156] /* winRad.abs.coeAbsEx[1,1,9,1] PARAM */) = 0.1307986830869973;
#line 1354 OMC_FILE
  TRACE_POP
}

/*
equation index: 130
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,8,1] = 0.1329258880977036
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[181] /* winRad.abs.coeAbsEx[2,1,8,1] PARAM */) = 0.1329258880977036;
#line 1369 OMC_FILE
  TRACE_POP
}

/*
equation index: 131
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,8,1] = 0.1205657930053361
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[155] /* winRad.abs.coeAbsEx[1,1,8,1] PARAM */) = 0.1205657930053361;
#line 1384 OMC_FILE
  TRACE_POP
}

/*
equation index: 132
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,7,1] = 0.1258553503945128
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[180] /* winRad.abs.coeAbsEx[2,1,7,1] PARAM */) = 0.1258553503945128;
#line 1399 OMC_FILE
  TRACE_POP
}

/*
equation index: 133
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,7,1] = 0.1125698390133378
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[154] /* winRad.abs.coeAbsEx[1,1,7,1] PARAM */) = 0.1125698390133378;
#line 1414 OMC_FILE
  TRACE_POP
}

/*
equation index: 134
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,6,1] = 0.1199592159293939
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[179] /* winRad.abs.coeAbsEx[2,1,6,1] PARAM */) = 0.1199592159293939;
#line 1429 OMC_FILE
  TRACE_POP
}

/*
equation index: 135
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,6,1] = 0.1065974620703473
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[153] /* winRad.abs.coeAbsEx[1,1,6,1] PARAM */) = 0.1065974620703473;
#line 1444 OMC_FILE
  TRACE_POP
}

/*
equation index: 136
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,5,1] = 0.1153398886779867
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[178] /* winRad.abs.coeAbsEx[2,1,5,1] PARAM */) = 0.1153398886779867;
#line 1459 OMC_FILE
  TRACE_POP
}

/*
equation index: 137
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,5,1] = 0.1021914583318008
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[152] /* winRad.abs.coeAbsEx[1,1,5,1] PARAM */) = 0.1021914583318008;
#line 1474 OMC_FILE
  TRACE_POP
}

/*
equation index: 138
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,4,1] = 0.1120318818175741
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[177] /* winRad.abs.coeAbsEx[2,1,4,1] PARAM */) = 0.1120318818175741;
#line 1489 OMC_FILE
  TRACE_POP
}

/*
equation index: 139
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,4,1] = 0.09913158934736244
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,4,1] PARAM */) = 0.09913158934736244;
#line 1504 OMC_FILE
  TRACE_POP
}

/*
equation index: 140
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,3,1] = 0.1100473669610094
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[176] /* winRad.abs.coeAbsEx[2,1,3,1] PARAM */) = 0.1100473669610094;
#line 1519 OMC_FILE
  TRACE_POP
}

/*
equation index: 141
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,3,1] = 0.09732302857079711
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[150] /* winRad.abs.coeAbsEx[1,1,3,1] PARAM */) = 0.09732302857079711;
#line 1534 OMC_FILE
  TRACE_POP
}

/*
equation index: 142
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,2,1] = 0.1093863539769833
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[175] /* winRad.abs.coeAbsEx[2,1,2,1] PARAM */) = 0.1093863539769833;
#line 1549 OMC_FILE
  TRACE_POP
}

/*
equation index: 143
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,1,1] = winRad.abs.coeAbsEx[2,1,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
#line 102 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[174] /* winRad.abs.coeAbsEx[2,1,1,1] PARAM */) = (data->simulationInfo->realParameter[175] /* winRad.abs.coeAbsEx[2,1,2,1] PARAM */);
#line 1564 OMC_FILE
  TRACE_POP
}

/*
equation index: 144
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,2,1] = 0.0967242489000629
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[149] /* winRad.abs.coeAbsEx[1,1,2,1] PARAM */) = 0.0967242489000629;
#line 1579 OMC_FILE
  TRACE_POP
}

/*
equation index: 145
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,1,1] = winRad.abs.coeAbsEx[1,1,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
#line 102 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */) = (data->simulationInfo->realParameter[149] /* winRad.abs.coeAbsEx[1,1,2,1] PARAM */);
#line 1594 OMC_FILE
  TRACE_POP
}

/*
equation index: 146
type: ALGORITHM

  winRad.abs.QAbsGlaSha_flow[2,1] := $START.winRad.abs.QAbsGlaSha_flow[2,1];
  winRad.abs.QAbsGlaSha_flow[1,1] := $START.winRad.abs.QAbsGlaSha_flow[1,1];
  winRad.abs.QAbsGlaUns_flow[2,1] := $START.winRad.abs.QAbsGlaUns_flow[2,1];
  winRad.abs.QAbsGlaUns_flow[1,1] := $START.winRad.abs.QAbsGlaUns_flow[1,1];
  winRad.abs.QAbsIntSha_flow[1] := $START.winRad.abs.QAbsIntSha_flow[1];
  winRad.abs.QAbsExtSha_flow[1] := $START.winRad.abs.QAbsExtSha_flow[1];
  winRad.abs.x := $START.winRad.abs.x;
  winRad.abs.incAng2 := $START.winRad.abs.incAng2;
  winRad.abs.absRad[2,4,1] := $START.winRad.abs.absRad[2,4,1];
  winRad.abs.absRad[2,3,1] := $START.winRad.abs.absRad[2,3,1];
  winRad.abs.absRad[2,2,1] := $START.winRad.abs.absRad[2,2,1];
  winRad.abs.absRad[2,1,1] := $START.winRad.abs.absRad[2,1,1];
  winRad.abs.absRad[1,4,1] := $START.winRad.abs.absRad[1,4,1];
  winRad.abs.absRad[1,3,1] := $START.winRad.abs.absRad[1,3,1];
  winRad.abs.absRad[1,2,1] := $START.winRad.abs.absRad[1,2,1];
  winRad.abs.absRad[1,1,1] := $START.winRad.abs.absRad[1,1,1];
  winRad.abs.absRad[1,1,:] := {0.0};
  winRad.abs.absRad[1,4,:] := {0.0};
  winRad.abs.absRad[2,1,:] := {0.0};
  winRad.abs.absRad[2,4,:] := {0.0};
  for i in 1:2 loop
    winRad.abs.absRad[1,i + 1,:] := {(1.0 - uSha) * HDifTilIso.H * winRad.abs.coeAbsEx[1,i,12,1]};
    winRad.abs.absRad[2,i + 1,:] := {uSha * HDifTilIso.H * winRad.abs.coeAbsEx[2,i,12,1]};
  end for;
  for iSta in 1:1 loop
    winRad.abs.absRad[2,4,iSta] := 0.3052322754811356 * uSha * HDifTilIso.H;
  end for;
  winRad.abs.incAng2 := min(HDirTil.inc, 1.570796326794897);
  winRad.abs.x := 5.729577951308232 * abs(winRad.abs.incAng2) + 2.0;
  for i in 1:2 loop
    for iSta in 1:1 loop
      winRad.abs.absRad[1,i + 1,iSta] := winRad.abs.absRad[1,i + 1,iSta] + HDirTil.H * (1.0 - uSha) * Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.abs.coeAbsEx[1,i,1,iSta], winRad.abs.coeAbsEx[1,i,2,iSta], winRad.abs.coeAbsEx[1,i,3,iSta], winRad.abs.coeAbsEx[1,i,4,iSta], winRad.abs.coeAbsEx[1,i,5,iSta], winRad.abs.coeAbsEx[1,i,6,iSta], winRad.abs.coeAbsEx[1,i,7,iSta], winRad.abs.coeAbsEx[1,i,8,iSta], winRad.abs.coeAbsEx[1,i,9,iSta], winRad.abs.coeAbsEx[1,i,10,iSta], winRad.abs.coeAbsEx[1,i,11,iSta], winRad.abs.coeAbsEx[1,i,12,iSta], winRad.abs.coeAbsEx[1,i,13,iSta]}, winRad.abs.x);
      winRad.abs.absRad[2,i + 1,iSta] := winRad.abs.absRad[2,i + 1,iSta] + HDirTil.H * uSha * Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.abs.coeAbsEx[2,i,1,iSta], winRad.abs.coeAbsEx[2,i,2,iSta], winRad.abs.coeAbsEx[2,i,3,iSta], winRad.abs.coeAbsEx[2,i,4,iSta], winRad.abs.coeAbsEx[2,i,5,iSta], winRad.abs.coeAbsEx[2,i,6,iSta], winRad.abs.coeAbsEx[2,i,7,iSta], winRad.abs.coeAbsEx[2,i,8,iSta], winRad.abs.coeAbsEx[2,i,9,iSta], winRad.abs.coeAbsEx[2,i,10,iSta], winRad.abs.coeAbsEx[2,i,11,iSta], winRad.abs.coeAbsEx[2,i,12,iSta], winRad.abs.coeAbsEx[2,i,13,iSta]}, winRad.abs.x);
    end for;
  end for;
  for iSta in 1:1 loop
    winRad.abs.absRad[2,4,iSta] := winRad.abs.absRad[2,4,iSta] + HDirTil.H * uSha * Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.abs.coeAbsDevExtIrrIntSha[1,iSta], winRad.abs.coeAbsDevExtIrrIntSha[2,iSta], winRad.abs.coeAbsDevExtIrrIntSha[3,iSta], winRad.abs.coeAbsDevExtIrrIntSha[4,iSta], winRad.abs.coeAbsDevExtIrrIntSha[5,iSta], winRad.abs.coeAbsDevExtIrrIntSha[6,iSta], winRad.abs.coeAbsDevExtIrrIntSha[7,iSta], winRad.abs.coeAbsDevExtIrrIntSha[8,iSta], winRad.abs.coeAbsDevExtIrrIntSha[9,iSta], winRad.abs.coeAbsDevExtIrrIntSha[10,iSta], winRad.abs.coeAbsDevExtIrrIntSha[11,iSta], winRad.abs.coeAbsDevExtIrrIntSha[12,iSta], winRad.abs.coeAbsDevExtIrrIntSha[13,iSta]}, winRad.abs.x);
  end for;
  winRad.abs.QAbsExtSha_flow[:] := winRad.abs.absRad[2,1,:];
  winRad.abs.QAbsIntSha_flow[:] := winRad.abs.absRad[2,4,:];
  winRad.abs.QAbsGlaUns_flow[:,:] := winRad.abs.absRad[1,2:3,:];
  winRad.abs.QAbsGlaSha_flow[:,:] := winRad.abs.absRad[2,2:3,:];
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
  real_array tmp5;
  index_spec_t tmp6;
  real_array tmp7;
  real_array tmp8;
  index_spec_t tmp9;
  real_array tmp10;
  real_array tmp11;
  index_spec_t tmp12;
  real_array tmp13;
  real_array tmp14;
  index_spec_t tmp15;
  real_array tmp16;
  real_array tmp17;
  index_spec_t tmp18;
  real_array tmp19;
  real_array tmp20;
  index_spec_t tmp21;
  real_array tmp22;
  modelica_integer tmp23;
  modelica_integer tmp24;
  modelica_integer tmp25;
  modelica_integer tmp26;
  modelica_integer tmp27;
  modelica_integer tmp28;
  real_array tmp29;
  real_array tmp30;
  modelica_integer tmp31;
  modelica_integer tmp32;
  modelica_integer tmp33;
  modelica_integer tmp34;
  modelica_integer tmp35;
  modelica_integer tmp36;
  real_array tmp37;
  modelica_integer tmp38;
  modelica_integer tmp39;
  modelica_integer tmp40;
  real_array tmp41;
  real_array tmp42;
  index_spec_t tmp43;
  index_spec_t tmp44;
  real_array tmp45;
  real_array tmp46;
  real_array tmp47;
  index_spec_t tmp48;
  index_spec_t tmp49;
  real_array tmp50;
  real_array tmp51;
  real_array tmp52;
  integer_array tmp53;
  modelica_integer tmp54;
  index_spec_t tmp55;
  index_spec_t tmp56;
  real_array tmp57;
  real_array tmp58;
  real_array tmp59;
  integer_array tmp60;
  modelica_integer tmp61;
  index_spec_t tmp62;
  index_spec_t tmp63;
  real_array tmp64;
  (data->localData[0]->realVars[118] /* winRad.abs.QAbsGlaSha_flow[2,1] variable */) = (data->modelData->realVarsData[118] /* winRad.abs.QAbsGlaSha_flow[2,1] variable */).attribute .start;

  (data->localData[0]->realVars[117] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */) = (data->modelData->realVarsData[117] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */).attribute .start;

  (data->localData[0]->realVars[120] /* winRad.abs.QAbsGlaUns_flow[2,1] variable */) = (data->modelData->realVarsData[120] /* winRad.abs.QAbsGlaUns_flow[2,1] variable */).attribute .start;

  (data->localData[0]->realVars[119] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */) = (data->modelData->realVarsData[119] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */).attribute .start;

  (data->localData[0]->realVars[121] /* winRad.abs.QAbsIntSha_flow[1] variable */) = (data->modelData->realVarsData[121] /* winRad.abs.QAbsIntSha_flow[1] variable */).attribute .start;

  (data->localData[0]->realVars[116] /* winRad.abs.QAbsExtSha_flow[1] variable */) = (data->modelData->realVarsData[116] /* winRad.abs.QAbsExtSha_flow[1] variable */).attribute .start;

  (data->localData[0]->realVars[131] /* winRad.abs.x variable */) = (data->modelData->realVarsData[131] /* winRad.abs.x variable */).attribute .start;

  (data->localData[0]->realVars[130] /* winRad.abs.incAng2 variable */) = (data->modelData->realVarsData[130] /* winRad.abs.incAng2 variable */).attribute .start;

  (data->localData[0]->realVars[129] /* winRad.abs.absRad[2,4,1] variable */) = (data->modelData->realVarsData[129] /* winRad.abs.absRad[2,4,1] variable */).attribute .start;

  (data->localData[0]->realVars[128] /* winRad.abs.absRad[2,3,1] variable */) = (data->modelData->realVarsData[128] /* winRad.abs.absRad[2,3,1] variable */).attribute .start;

  (data->localData[0]->realVars[127] /* winRad.abs.absRad[2,2,1] variable */) = (data->modelData->realVarsData[127] /* winRad.abs.absRad[2,2,1] variable */).attribute .start;

  (data->localData[0]->realVars[126] /* winRad.abs.absRad[2,1,1] variable */) = (data->modelData->realVarsData[126] /* winRad.abs.absRad[2,1,1] variable */).attribute .start;

  (data->localData[0]->realVars[125] /* winRad.abs.absRad[1,4,1] variable */) = (data->modelData->realVarsData[125] /* winRad.abs.absRad[1,4,1] variable */).attribute .start;

  (data->localData[0]->realVars[124] /* winRad.abs.absRad[1,3,1] variable */) = (data->modelData->realVarsData[124] /* winRad.abs.absRad[1,3,1] variable */).attribute .start;

  (data->localData[0]->realVars[123] /* winRad.abs.absRad[1,2,1] variable */) = (data->modelData->realVarsData[123] /* winRad.abs.absRad[1,2,1] variable */).attribute .start;

  (data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */) = (data->modelData->realVarsData[122] /* winRad.abs.absRad[1,1,1] variable */).attribute .start;

#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp5, 1, (modelica_real)0.0);
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp6, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp7, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp5, &tmp7, &tmp6);
#line 1749 OMC_FILE

#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp8, 1, (modelica_real)0.0);
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp9, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp10, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp8, &tmp10, &tmp9);
#line 1759 OMC_FILE

#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp11, 1, (modelica_real)0.0);
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp12, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp13, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp11, &tmp13, &tmp12);
#line 1769 OMC_FILE

#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp14, 1, (modelica_real)0.0);
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp15, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp16, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp14, &tmp16, &tmp15);
#line 1779 OMC_FILE

#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp23 = ((modelica_integer) 1); tmp24 = 1; tmp25 = ((modelica_integer) 2);
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp24 > 0) && (tmp23 > tmp25)) || ((tmp24 < 0) && (tmp23 < tmp25))))
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer i;
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(i = ((modelica_integer) 1); in_range_integer(i, tmp23, tmp25); i += tmp24)
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp17, 1, (modelica_real)(1.0 - (data->localData[0]->realVars[50] /* uSha variable */)) * (((data->localData[0]->realVars[18] /* HDifTilIso.H variable */)) * ((&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (((modelica_integer) 1)-1)])));
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      create_index_spec(&tmp18, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) i + ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      real_array_create(&tmp19, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      indexed_assign_real_array(tmp17, &tmp19, &tmp18);
#line 1801 OMC_FILE

#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp20, 1, (modelica_real)((data->localData[0]->realVars[50] /* uSha variable */)) * (((data->localData[0]->realVars[18] /* HDifTilIso.H variable */)) * ((&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (((modelica_integer) 1)-1)])));
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      create_index_spec(&tmp21, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) i + ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      real_array_create(&tmp22, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      indexed_assign_real_array(tmp20, &tmp22, &tmp21);
#line 1811 OMC_FILE
    }
  }

#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp26 = ((modelica_integer) 1); tmp27 = 1; tmp28 = ((modelica_integer) 1);
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp27 > 0) && (tmp26 > tmp28)) || ((tmp27 < 0) && (tmp26 < tmp28))))
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer iSta;
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp26, tmp28); iSta += tmp27)
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 151 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      (&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] = (0.3052322754811356) * (((data->localData[0]->realVars[50] /* uSha variable */)) * ((data->localData[0]->realVars[18] /* HDifTilIso.H variable */)));
#line 1829 OMC_FILE
    }
  }

#line 160 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->localData[0]->realVars[130] /* winRad.abs.incAng2 variable */) = fmin((data->localData[0]->realVars[24] /* HDirTil.inc variable */),1.570796326794897);
#line 1835 OMC_FILE

#line 162 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->localData[0]->realVars[131] /* winRad.abs.x variable */) = (5.729577951308232) * (fabs((data->localData[0]->realVars[130] /* winRad.abs.incAng2 variable */))) + 2.0;
#line 1839 OMC_FILE

#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp34 = ((modelica_integer) 1); tmp35 = 1; tmp36 = ((modelica_integer) 2);
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp35 > 0) && (tmp34 > tmp36)) || ((tmp35 < 0) && (tmp34 < tmp36))))
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer i;
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(i = ((modelica_integer) 1); in_range_integer(i, tmp34, tmp36); i += tmp35)
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      tmp31 = ((modelica_integer) 1); tmp32 = 1; tmp33 = ((modelica_integer) 1);
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      if(!(((tmp32 > 0) && (tmp31 > tmp33)) || ((tmp32 < 0) && (tmp31 < tmp33))))
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      {
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        modelica_integer iSta;
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp31, tmp33); iSta += tmp32)
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        {
#line 168 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          array_alloc_scalar_real_array(&tmp29, 13, (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 1)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 2)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 3)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 5)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 6)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 7)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 8)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 9)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 10)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 11)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 13)-1)) * 1 + (iSta-1)]);
#line 168 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          (&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 1) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 1) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * ((1.0 - (data->localData[0]->realVars[50] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp29, (data->localData[0]->realVars[131] /* winRad.abs.x variable */))));
#line 1869 OMC_FILE

#line 174 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          array_alloc_scalar_real_array(&tmp30, 13, (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 1)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 2)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 3)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 5)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 6)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 7)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 8)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 9)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 10)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 11)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 13)-1)) * 1 + (iSta-1)]);
#line 174 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          (&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 2) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[50] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp30, (data->localData[0]->realVars[131] /* winRad.abs.x variable */))));
#line 1875 OMC_FILE
        }
      }
    }
  }

#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp38 = ((modelica_integer) 1); tmp39 = 1; tmp40 = ((modelica_integer) 1);
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp39 > 0) && (tmp38 > tmp40)) || ((tmp39 < 0) && (tmp38 < tmp40))))
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer iSta;
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp38, tmp40); iSta += tmp39)
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 184 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp37, 13, (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 2) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 3) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 4) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 5) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 6) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 7) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 8) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 9) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 10) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 11) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 12) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[133] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 13) - 1) * 1 + (iSta-1)]);
#line 184 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      (&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[50] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp37, (data->localData[0]->realVars[131] /* winRad.abs.x variable */))));
#line 1897 OMC_FILE
    }
  }

#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp41, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp43, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp41, &tmp43, &tmp42);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp44, 1, (modelica_integer)(1), (int*)0, 'W');
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp45, (modelica_real*)&(data->localData[0]->realVars[116] /* winRad.abs.QAbsExtSha_flow[1] variable */), 1, (_index_t)1);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp42, &tmp45, &tmp44);
#line 1913 OMC_FILE

#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp46, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp48, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp46, &tmp48, &tmp47);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp49, 1, (modelica_integer)(1), (int*)0, 'W');
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp50, (modelica_real*)&(data->localData[0]->realVars[121] /* winRad.abs.QAbsIntSha_flow[1] variable */), 1, (_index_t)1);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp47, &tmp50, &tmp49);
#line 1927 OMC_FILE

#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp51, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_integer_array_from_range(&tmp53, ((modelica_integer) 2), 1, ((modelica_integer) 3));
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp54 = size_of_dimension_base_array(tmp53, 1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp55, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', tmp54, integer_array_make_index_array(tmp53), 'A', (modelica_integer)(1), (int*)0, 'W');
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp51, &tmp55, &tmp52);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp56, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W');
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp57, (modelica_real*)&(data->localData[0]->realVars[119] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */), 2, (_index_t)2, (_index_t)1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp52, &tmp57, &tmp56);
#line 1945 OMC_FILE

#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp58, (modelica_real*)&(data->localData[0]->realVars[122] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_integer_array_from_range(&tmp60, ((modelica_integer) 2), 1, ((modelica_integer) 3));
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp61 = size_of_dimension_base_array(tmp60, 1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp62, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', tmp61, integer_array_make_index_array(tmp60), 'A', (modelica_integer)(1), (int*)0, 'W');
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp58, &tmp62, &tmp59);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp63, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W');
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp64, (modelica_real*)&(data->localData[0]->realVars[117] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */), 2, (_index_t)2, (_index_t)1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp59, &tmp64, &tmp63);
#line 1963 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_310(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_309(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_311(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_312(DATA *data, threadData_t *threadData);


/*
equation index: 151
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,12,1] = 0.1526161377405678
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[956] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */) = 0.1526161377405678;
#line 1986 OMC_FILE
  TRACE_POP
}

/*
equation index: 152
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,13,1] = winRad.tra.coeTraWinExtIrr[2,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
#line 63 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[957] /* winRad.tra.coeTraWinExtIrr[2,13,1] PARAM */) = (data->simulationInfo->realParameter[956] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */);
#line 2001 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_301(DATA *data, threadData_t *threadData);


/*
equation index: 154
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,12,1] = 0.5777675151140318
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[943] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */) = 0.5777675151140318;
#line 2018 OMC_FILE
  TRACE_POP
}

/*
equation index: 155
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,13,1] = winRad.tra.coeTraWinExtIrr[1,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
#line 63 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[944] /* winRad.tra.coeTraWinExtIrr[1,13,1] PARAM */) = (data->simulationInfo->realParameter[943] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */);
#line 2033 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_300(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_302(DATA *data, threadData_t *threadData);


/*
equation index: 158
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[955] /* winRad.tra.coeTraWinExtIrr[2,11,1] PARAM */) = 0.0;
#line 2052 OMC_FILE
  TRACE_POP
}

/*
equation index: 159
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,159};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[942] /* winRad.tra.coeTraWinExtIrr[1,11,1] PARAM */) = 0.0;
#line 2067 OMC_FILE
  TRACE_POP
}

/*
equation index: 160
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,10,1] = 0.05312988383825046
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[954] /* winRad.tra.coeTraWinExtIrr[2,10,1] PARAM */) = 0.05312988383825046;
#line 2082 OMC_FILE
  TRACE_POP
}

/*
equation index: 161
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,10,1] = 0.2011367960032149
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,161};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[941] /* winRad.tra.coeTraWinExtIrr[1,10,1] PARAM */) = 0.2011367960032149;
#line 2097 OMC_FILE
  TRACE_POP
}

/*
equation index: 162
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,9,1] = 0.1141420148054129
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[953] /* winRad.tra.coeTraWinExtIrr[2,9,1] PARAM */) = 0.1141420148054129;
#line 2112 OMC_FILE
  TRACE_POP
}

/*
equation index: 163
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,9,1] = 0.4321138592586893
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,163};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[940] /* winRad.tra.coeTraWinExtIrr[1,9,1] PARAM */) = 0.4321138592586893;
#line 2127 OMC_FILE
  TRACE_POP
}

/*
equation index: 164
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,8,1] = 0.1510035183497123
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[952] /* winRad.tra.coeTraWinExtIrr[2,8,1] PARAM */) = 0.1510035183497123;
#line 2142 OMC_FILE
  TRACE_POP
}

/*
equation index: 165
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,8,1] = 0.5716625309880206
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[939] /* winRad.tra.coeTraWinExtIrr[1,8,1] PARAM */) = 0.5716625309880206;
#line 2157 OMC_FILE
  TRACE_POP
}

/*
equation index: 166
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,7,1] = 0.1692349560988624
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[951] /* winRad.tra.coeTraWinExtIrr[2,7,1] PARAM */) = 0.1692349560988624;
#line 2172 OMC_FILE
  TRACE_POP
}

/*
equation index: 167
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,7,1] = 0.6406823125211414
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[938] /* winRad.tra.coeTraWinExtIrr[1,7,1] PARAM */) = 0.6406823125211414;
#line 2187 OMC_FILE
  TRACE_POP
}

/*
equation index: 168
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,6,1] = 0.1777711516802857
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[950] /* winRad.tra.coeTraWinExtIrr[2,6,1] PARAM */) = 0.1777711516802857;
#line 2202 OMC_FILE
  TRACE_POP
}

/*
equation index: 169
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,6,1] = 0.6729982692909955
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[937] /* winRad.tra.coeTraWinExtIrr[1,6,1] PARAM */) = 0.6729982692909955;
#line 2217 OMC_FILE
  TRACE_POP
}

/*
equation index: 170
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,5,1] = 0.1817774042411072
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[949] /* winRad.tra.coeTraWinExtIrr[2,5,1] PARAM */) = 0.1817774042411072;
#line 2232 OMC_FILE
  TRACE_POP
}

/*
equation index: 171
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,5,1] = 0.6881649654297732
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[936] /* winRad.tra.coeTraWinExtIrr[1,5,1] PARAM */) = 0.6881649654297732;
#line 2247 OMC_FILE
  TRACE_POP
}

/*
equation index: 172
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,4,1] = 0.1836737998725771
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[948] /* winRad.tra.coeTraWinExtIrr[2,4,1] PARAM */) = 0.1836737998725771;
#line 2262 OMC_FILE
  TRACE_POP
}

/*
equation index: 173
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,4,1] = 0.6953442572654116
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_173(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,173};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[935] /* winRad.tra.coeTraWinExtIrr[1,4,1] PARAM */) = 0.6953442572654116;
#line 2277 OMC_FILE
  TRACE_POP
}

/*
equation index: 174
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,3,1] = 0.1845249205495098
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[947] /* winRad.tra.coeTraWinExtIrr[2,3,1] PARAM */) = 0.1845249205495098;
#line 2292 OMC_FILE
  TRACE_POP
}

/*
equation index: 175
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,3,1] = 0.6985663927869478
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,175};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[934] /* winRad.tra.coeTraWinExtIrr[1,3,1] PARAM */) = 0.6985663927869478;
#line 2307 OMC_FILE
  TRACE_POP
}

/*
equation index: 176
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,2,1] = 0.1847690572409374
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_176(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,176};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[2,2,1] PARAM */) = 0.1847690572409374;
#line 2322 OMC_FILE
  TRACE_POP
}

/*
equation index: 177
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,1,1] = winRad.tra.coeTraWinExtIrr[2,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_177(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,177};
#line 62 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[945] /* winRad.tra.coeTraWinExtIrr[2,1,1] PARAM */) = (data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[2,2,1] PARAM */);
#line 2337 OMC_FILE
  TRACE_POP
}

/*
equation index: 178
type: SIMPLE_ASSIGN
winRad.tra.QTraDirSha_flow[1] = HDirTil.H * uSha * Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.tra.coeTraWinExtIrr[2,1,1], winRad.tra.coeTraWinExtIrr[2,2,1], winRad.tra.coeTraWinExtIrr[2,3,1], winRad.tra.coeTraWinExtIrr[2,4,1], winRad.tra.coeTraWinExtIrr[2,5,1], winRad.tra.coeTraWinExtIrr[2,6,1], winRad.tra.coeTraWinExtIrr[2,7,1], winRad.tra.coeTraWinExtIrr[2,8,1], winRad.tra.coeTraWinExtIrr[2,9,1], winRad.tra.coeTraWinExtIrr[2,10,1], winRad.tra.coeTraWinExtIrr[2,11,1], winRad.tra.coeTraWinExtIrr[2,12,1], winRad.tra.coeTraWinExtIrr[2,13,1]}, winRad.tra.x)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,178};
  real_array tmp65;
#line 91 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  array_alloc_scalar_real_array(&tmp65, 13, (modelica_real)(data->simulationInfo->realParameter[945] /* winRad.tra.coeTraWinExtIrr[2,1,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[2,2,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[947] /* winRad.tra.coeTraWinExtIrr[2,3,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[948] /* winRad.tra.coeTraWinExtIrr[2,4,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[949] /* winRad.tra.coeTraWinExtIrr[2,5,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[950] /* winRad.tra.coeTraWinExtIrr[2,6,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[951] /* winRad.tra.coeTraWinExtIrr[2,7,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[952] /* winRad.tra.coeTraWinExtIrr[2,8,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[953] /* winRad.tra.coeTraWinExtIrr[2,9,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[954] /* winRad.tra.coeTraWinExtIrr[2,10,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[955] /* winRad.tra.coeTraWinExtIrr[2,11,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[956] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[957] /* winRad.tra.coeTraWinExtIrr[2,13,1] PARAM */));
#line 91 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[142] /* winRad.tra.QTraDirSha_flow[1] variable */) = ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[50] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp65, (data->localData[0]->realVars[145] /* winRad.tra.x variable */))));
#line 2355 OMC_FILE
  TRACE_POP
}

/*
equation index: 179
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,2,1] = 0.6994906348208673
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,179};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[933] /* winRad.tra.coeTraWinExtIrr[1,2,1] PARAM */) = 0.6994906348208673;
#line 2370 OMC_FILE
  TRACE_POP
}

/*
equation index: 180
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,1,1] = winRad.tra.coeTraWinExtIrr[1,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,180};
#line 62 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[932] /* winRad.tra.coeTraWinExtIrr[1,1,1] PARAM */) = (data->simulationInfo->realParameter[933] /* winRad.tra.coeTraWinExtIrr[1,2,1] PARAM */);
#line 2385 OMC_FILE
  TRACE_POP
}

/*
equation index: 181
type: SIMPLE_ASSIGN
winRad.tra.QTraDirUns_flow[1] = HDirTil.H * (1.0 - uSha) * Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.tra.coeTraWinExtIrr[1,1,1], winRad.tra.coeTraWinExtIrr[1,2,1], winRad.tra.coeTraWinExtIrr[1,3,1], winRad.tra.coeTraWinExtIrr[1,4,1], winRad.tra.coeTraWinExtIrr[1,5,1], winRad.tra.coeTraWinExtIrr[1,6,1], winRad.tra.coeTraWinExtIrr[1,7,1], winRad.tra.coeTraWinExtIrr[1,8,1], winRad.tra.coeTraWinExtIrr[1,9,1], winRad.tra.coeTraWinExtIrr[1,10,1], winRad.tra.coeTraWinExtIrr[1,11,1], winRad.tra.coeTraWinExtIrr[1,12,1], winRad.tra.coeTraWinExtIrr[1,13,1]}, winRad.tra.x)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  real_array tmp66;
#line 83 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  array_alloc_scalar_real_array(&tmp66, 13, (modelica_real)(data->simulationInfo->realParameter[932] /* winRad.tra.coeTraWinExtIrr[1,1,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[933] /* winRad.tra.coeTraWinExtIrr[1,2,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[934] /* winRad.tra.coeTraWinExtIrr[1,3,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[935] /* winRad.tra.coeTraWinExtIrr[1,4,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[936] /* winRad.tra.coeTraWinExtIrr[1,5,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[937] /* winRad.tra.coeTraWinExtIrr[1,6,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[938] /* winRad.tra.coeTraWinExtIrr[1,7,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[939] /* winRad.tra.coeTraWinExtIrr[1,8,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[940] /* winRad.tra.coeTraWinExtIrr[1,9,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[941] /* winRad.tra.coeTraWinExtIrr[1,10,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[942] /* winRad.tra.coeTraWinExtIrr[1,11,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[943] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[944] /* winRad.tra.coeTraWinExtIrr[1,13,1] PARAM */));
#line 83 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[143] /* winRad.tra.QTraDirUns_flow[1] variable */) = ((data->localData[0]->realVars[23] /* HDirTil.H variable */)) * ((1.0 - (data->localData[0]->realVars[50] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp66, (data->localData[0]->realVars[145] /* winRad.tra.x variable */))));
#line 2403 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_307(DATA *data, threadData_t *threadData);


/*
equation index: 183
type: SIMPLE_ASSIGN
HDifTilIso.HDifTilIso.til_c = -3.491481338843133e-15
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffuseIsotropic.mo"
  (data->localData[0]->realVars[19] /* HDifTilIso.HDifTilIso.til_c variable */) = -3.491481338843133e-15;
#line 2420 OMC_FILE
  TRACE_POP
}

/*
equation index: 184
type: SIMPLE_ASSIGN
weaDat.con30Min.y = 1800.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[70] /* weaDat.con30Min.y variable */) = 1800.0;
#line 2435 OMC_FILE
  TRACE_POP
}

/*
equation index: 185
type: SIMPLE_ASSIGN
HRoo.y = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,185};
#line 548 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Math.mo"
  (data->localData[0]->realVars[35] /* HRoo.y variable */) = 0.0;
#line 2450 OMC_FILE
  TRACE_POP
}

/*
equation index: 186
type: SIMPLE_ASSIGN
weaBus.nTot = min(1.0, max(0.0, totSkyCov_in))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterTotalSkyCover.mo"
  (data->localData[0]->realVars[60] /* weaBus.nTot variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[49] /* totSkyCov_in variable */)));
#line 2465 OMC_FILE
  TRACE_POP
}

/*
equation index: 187
type: SIMPLE_ASSIGN
weaBus.nOpa = min(1.0, max(0.0, opaSkyCov_in))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,187};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterOpaqueSkyCover.mo"
  (data->localData[0]->realVars[59] /* weaBus.nOpa variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[47] /* opaSkyCov_in variable */)));
#line 2480 OMC_FILE
  TRACE_POP
}

/*
equation index: 188
type: SIMPLE_ASSIGN
weaBus.winDir = min(6.283185307179586, max(0.0, winDir_in))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,188};
#line 11 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterWindDirection.mo"
  (data->localData[0]->realVars[67] /* weaBus.winDir variable */) = fmin(6.283185307179586,fmax(0.0,(data->localData[0]->realVars[115] /* winDir_in variable */)));
#line 2495 OMC_FILE
  TRACE_POP
}

/*
equation index: 189
type: SIMPLE_ASSIGN
weaBus.relHum = min(1.0, max(0.0, relHum_in))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,189};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterRelativeHumidity.mo"
  (data->localData[0]->realVars[61] /* weaBus.relHum variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[48] /* relHum_in variable */)));
#line 2510 OMC_FILE
  TRACE_POP
}

/*
equation index: 190
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiDryBul = 0.621964713077499 * weaBus.relHum / ((-0.378035286922501) * weaBus.relHum + 165.6565689594004 * exp(4102.99 / (TDryBul_in - 35.719) - 17.2799))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,190};
#line 63 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  (data->localData[0]->realVars[111] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */) = (0.621964713077499) * (DIVISION_SIM((data->localData[0]->realVars[61] /* weaBus.relHum variable */),(-0.378035286922501) * ((data->localData[0]->realVars[61] /* weaBus.relHum variable */)) + (165.6565689594004) * (exp(DIVISION_SIM(4102.99,(data->localData[0]->realVars[45] /* TDryBul_in variable */) - 35.719,"TDryBul_in - 35.719",equationIndexes) - 17.2799)),"(-0.378035286922501) * weaBus.relHum + 165.6565689594004 * exp(4102.99 / (TDryBul_in - 35.719) - 17.2799)",equationIndexes));
#line 2525 OMC_FILE
  TRACE_POP
}

void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_191(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_192(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_193(DATA*, threadData_t*);
/*
equation index: 198
indexNonlinear: 0
type: NONLINEAR

vars: {weaBus.TWetBul}
eqns: {191, 192, 193}
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 198 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = (data->localData[0]->realVars[56] /* weaBus.TWetBul variable */);
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,198};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 198 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[56] /* weaBus.TWetBul variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_315(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_314(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_313(DATA *data, threadData_t *threadData);


/*
equation index: 202
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[12,1] = 0.2142436332900854
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[215] /* winRad.abs.coeRefExtPan1[12,1] PARAM */) = 0.2142436332900854;
#line 2580 OMC_FILE
  TRACE_POP
}

/*
equation index: 203
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[13,1] = winRad.abs.coeRefExtPan1[12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[216] /* winRad.abs.coeRefExtPan1[13,1] PARAM */) = (data->simulationInfo->realParameter[215] /* winRad.abs.coeRefExtPan1[12,1] PARAM */);
#line 2595 OMC_FILE
  TRACE_POP
}

/*
equation index: 204
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[2,1] = 0.127461797611565
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[205] /* winRad.abs.coeRefExtPan1[2,1] PARAM */) = 0.127461797611565;
#line 2610 OMC_FILE
  TRACE_POP
}

/*
equation index: 205
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[1,1] = winRad.abs.coeRefExtPan1[2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[204] /* winRad.abs.coeRefExtPan1[1,1] PARAM */) = (data->simulationInfo->realParameter[205] /* winRad.abs.coeRefExtPan1[2,1] PARAM */);
#line 2625 OMC_FILE
  TRACE_POP
}

/*
equation index: 206
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[11,1] = 1.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[214] /* winRad.abs.coeRefExtPan1[11,1] PARAM */) = 1.0;
#line 2640 OMC_FILE
  TRACE_POP
}

/*
equation index: 207
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[10,1] = 0.6052446087035255
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[213] /* winRad.abs.coeRefExtPan1[10,1] PARAM */) = 0.6052446087035255;
#line 2655 OMC_FILE
  TRACE_POP
}

/*
equation index: 208
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[9,1] = 0.3612313008417883
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[212] /* winRad.abs.coeRefExtPan1[9,1] PARAM */) = 0.3612313008417883;
#line 2670 OMC_FILE
  TRACE_POP
}

/*
equation index: 209
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[8,1] = 0.2247377823311878
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[211] /* winRad.abs.coeRefExtPan1[8,1] PARAM */) = 0.2247377823311878;
#line 2685 OMC_FILE
  TRACE_POP
}

/*
equation index: 210
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[7,1] = 0.1628935363465329
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[210] /* winRad.abs.coeRefExtPan1[7,1] PARAM */) = 0.1628935363465329;
#line 2700 OMC_FILE
  TRACE_POP
}

/*
equation index: 211
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[6,1] = 0.1382440338153747
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[209] /* winRad.abs.coeRefExtPan1[6,1] PARAM */) = 0.1382440338153747;
#line 2715 OMC_FILE
  TRACE_POP
}

/*
equation index: 212
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[5,1] = 0.1297280574286503
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[208] /* winRad.abs.coeRefExtPan1[5,1] PARAM */) = 0.1297280574286503;
#line 2730 OMC_FILE
  TRACE_POP
}

/*
equation index: 213
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[4,1] = 0.1275322917190642
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[207] /* winRad.abs.coeRefExtPan1[4,1] PARAM */) = 0.1275322917190642;
#line 2745 OMC_FILE
  TRACE_POP
}

/*
equation index: 214
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[3,1] = 0.1273615206111159
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[206] /* winRad.abs.coeRefExtPan1[3,1] PARAM */) = 0.1273615206111159;
#line 2760 OMC_FILE
  TRACE_POP
}

/*
equation index: 215
type: SIMPLE_ASSIGN
winRad.abs.coeAbsIn[2,2,1] = 0.03241615014704199
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[203] /* winRad.abs.coeAbsIn[2,2,1] PARAM */) = 0.03241615014704199;
#line 2775 OMC_FILE
  TRACE_POP
}

/*
equation index: 216
type: SIMPLE_ASSIGN
winRad.abs.coeAbsIn[1,2,1] = 0.1227196468033888
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
#line 76 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[201] /* winRad.abs.coeAbsIn[1,2,1] PARAM */) = 0.1227196468033888;
#line 2790 OMC_FILE
  TRACE_POP
}

/*
equation index: 217
type: SIMPLE_ASSIGN
winRad.abs.coeAbsIn[2,1,1] = 0.02252369052121515
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[202] /* winRad.abs.coeAbsIn[2,1,1] PARAM */) = 0.02252369052121515;
#line 2805 OMC_FILE
  TRACE_POP
}

/*
equation index: 218
type: SIMPLE_ASSIGN
winRad.abs.coeAbsIn[1,1,1] = 0.08526920479249403
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
#line 76 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[200] /* winRad.abs.coeAbsIn[1,1,1] PARAM */) = 0.08526920479249403;
#line 2820 OMC_FILE
  TRACE_POP
}

/*
equation index: 219
type: SIMPLE_ASSIGN
winRad.tra.traCoeRoo[1] = 0.5777675151140318
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
#line 69 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[1310] /* winRad.tra.traCoeRoo[1] PARAM */) = 0.5777675151140318;
#line 2835 OMC_FILE
  TRACE_POP
}

/*
equation index: 226
type: ALGORITHM

  assert(noEvent(TDryBul_in > 203.15) and noEvent(TDryBul_in < 343.15), "In WinRadCustom.weaDat.cheTemDryBul: Weather data dry bulb temperature out of bounds.
   TIn = " + String(TDryBul_in, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,95,"In WinRadCustom.weaDat.cheTemDryBul: Weather data dry bulb temperature out of bounds.\n   TIn = ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp0 = Greater((data->localData[0]->realVars[45] /* TDryBul_in variable */),203.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp1 = Less((data->localData[0]->realVars[45] /* TDryBul_in variable */),343.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    if(!(tmp0 && tmp1))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp3 = modelica_real_to_modelica_string((data->localData[0]->realVars[45] /* TDryBul_in variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        const char* assert_cond = "(noEvent(TDryBul_in > 203.15) and noEvent(TDryBul_in < 343.15))";
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  }
#line 2896 OMC_FILE
  TRACE_POP
}

/*
equation index: 225
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0), "In WinRadCustom.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTimMin.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,128,"In WinRadCustom.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static const MMC_DEFSTRINGLIT(tmp10,22," exceeds the end time ");
  modelica_metatype tmpMeta11;
  modelica_string tmp12;
  modelica_metatype tmpMeta13;
  static const MMC_DEFSTRINGLIT(tmp14,26," of the weather data file.");
  modelica_metatype tmpMeta15;
  static int tmp16 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp6 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[95] /* weaDat.conTimMin.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp6))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp8 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta11 = stringAppend(tmpMeta9,MMC_REFSTRINGLIT(tmp10));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp12 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[95] /* weaDat.conTimMin.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta13 = stringAppend(tmpMeta11,tmp12);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta15 = stringAppend(tmpMeta13,MMC_REFSTRINGLIT(tmp14));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta15));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2968 OMC_FILE
  TRACE_POP
}

/*
equation index: 224
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim), "In WinRadCustom.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTimMin.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  modelica_boolean tmp17;
  static const MMC_DEFSTRINGLIT(tmp18,128,"In WinRadCustom.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp19;
  modelica_metatype tmpMeta20;
  static const MMC_DEFSTRINGLIT(tmp21,29," is less than the start time ");
  modelica_metatype tmpMeta22;
  modelica_string tmp23;
  modelica_metatype tmpMeta24;
  static const MMC_DEFSTRINGLIT(tmp25,26," of the weather data file.");
  modelica_metatype tmpMeta26;
  static int tmp27 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp17 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[96] /* weaDat.conTimMin.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp17))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp19 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta20 = stringAppend(MMC_REFSTRINGLIT(tmp18),tmp19);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta22 = stringAppend(tmpMeta20,MMC_REFSTRINGLIT(tmp21));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp23 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[96] /* weaDat.conTimMin.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta24 = stringAppend(tmpMeta22,tmp23);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta26 = stringAppend(tmpMeta24,MMC_REFSTRINGLIT(tmp25));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta26));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta26));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 3040 OMC_FILE
  TRACE_POP
}

/*
equation index: 223
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0), "In WinRadCustom.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTim.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
  modelica_boolean tmp28;
  static const MMC_DEFSTRINGLIT(tmp29,125,"In WinRadCustom.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp30;
  modelica_metatype tmpMeta31;
  static const MMC_DEFSTRINGLIT(tmp32,22," exceeds the end time ");
  modelica_metatype tmpMeta33;
  modelica_string tmp34;
  modelica_metatype tmpMeta35;
  static const MMC_DEFSTRINGLIT(tmp36,26," of the weather data file.");
  modelica_metatype tmpMeta37;
  static int tmp38 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp28 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[92] /* weaDat.conTim.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp28))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp30 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta31 = stringAppend(MMC_REFSTRINGLIT(tmp29),tmp30);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta33 = stringAppend(tmpMeta31,MMC_REFSTRINGLIT(tmp32));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp34 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[92] /* weaDat.conTim.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta35 = stringAppend(tmpMeta33,tmp34);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta37 = stringAppend(tmpMeta35,MMC_REFSTRINGLIT(tmp36));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta37));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta37));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 3112 OMC_FILE
  TRACE_POP
}

/*
equation index: 222
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim), "In WinRadCustom.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTim.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  modelica_boolean tmp39;
  static const MMC_DEFSTRINGLIT(tmp40,125,"In WinRadCustom.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp41;
  modelica_metatype tmpMeta42;
  static const MMC_DEFSTRINGLIT(tmp43,29," is less than the start time ");
  modelica_metatype tmpMeta44;
  modelica_string tmp45;
  modelica_metatype tmpMeta46;
  static const MMC_DEFSTRINGLIT(tmp47,26," of the weather data file.");
  modelica_metatype tmpMeta48;
  static int tmp49 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp39 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[93] /* weaDat.conTim.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp39))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp41 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta42 = stringAppend(MMC_REFSTRINGLIT(tmp40),tmp41);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta44 = stringAppend(tmpMeta42,MMC_REFSTRINGLIT(tmp43));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp45 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[93] /* weaDat.conTim.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta46 = stringAppend(tmpMeta44,tmp45);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta48 = stringAppend(tmpMeta46,MMC_REFSTRINGLIT(tmp47));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta48));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta48));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 3184 OMC_FILE
  TRACE_POP
}

/*
equation index: 221
type: ALGORITHM

  assert(noEvent(TDewPoi_in > 203.15) and noEvent(TDewPoi_in < 343.15), "In WinRadCustom.weaDat.cheTemDewPoi: Weather data dew point temperature out of bounds.
   TIn = " + String(TDewPoi_in, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  modelica_boolean tmp50;
  modelica_boolean tmp51;
  static const MMC_DEFSTRINGLIT(tmp52,96,"In WinRadCustom.weaDat.cheTemDewPoi: Weather data dew point temperature out of bounds.\n   TIn = ");
  modelica_string tmp53;
  modelica_metatype tmpMeta54;
  static int tmp55 = 0;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp50 = Greater((data->localData[0]->realVars[44] /* TDewPoi_in variable */),203.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp51 = Less((data->localData[0]->realVars[44] /* TDewPoi_in variable */),343.15);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    if(!(tmp50 && tmp51))
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp53 = modelica_real_to_modelica_string((data->localData[0]->realVars[44] /* TDewPoi_in variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmpMeta54 = stringAppend(MMC_REFSTRINGLIT(tmp52),tmp53);
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        const char* assert_cond = "(noEvent(TDewPoi_in > 203.15) and noEvent(TDewPoi_in < 343.15))";
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta54));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        } else {
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",23,3,25,10,0};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta54));
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    }
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  }
#line 3245 OMC_FILE
  TRACE_POP
}

/*
equation index: 220
type: ALGORITHM

  assert(noEvent(TBlaSky_in > 0.0) and noEvent(TBlaSky_in < 343.15), "In WinRadCustom.weaDat.cheTemBlaSky: Weather data black-body sky temperature out of bounds.
   TIn = " + String(TBlaSky_in, 6, 0, true));
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  modelica_boolean tmp56;
  modelica_boolean tmp57;
  static const MMC_DEFSTRINGLIT(tmp58,101,"In WinRadCustom.weaDat.cheTemBlaSky: Weather data black-body sky temperature out of bounds.\n   TIn = ");
  modelica_string tmp59;
  modelica_metatype tmpMeta60;
  static int tmp61 = 0;
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp56 = Greater((data->localData[0]->realVars[43] /* TBlaSky_in variable */),0.0);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp57 = Less((data->localData[0]->realVars[43] /* TBlaSky_in variable */),343.15);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    if(!(tmp56 && tmp57))
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp59 = modelica_real_to_modelica_string((data->localData[0]->realVars[43] /* TBlaSky_in variable */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmpMeta60 = stringAppend(MMC_REFSTRINGLIT(tmp58),tmp59);
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        const char* assert_cond = "(noEvent(TBlaSky_in > 0.0) and noEvent(TBlaSky_in < 343.15))";
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",25,3,27,18,0};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta60));
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          data->simulationInfo->needToReThrow = 1;
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        } else {
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",25,3,27,18,0};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta60));
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    }
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  }
#line 3306 OMC_FILE
  TRACE_POP
}
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_2(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_3(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_4(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_5(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_6(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_7(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_8(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_9(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_10(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_11(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_12(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_13(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_14(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_227(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_236(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_17(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_239(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_240(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_241(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_242(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_243(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_244(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_24(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_249(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_250(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_257(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_258(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_265(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_30(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_31(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_253(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_33(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_34(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_35(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_259(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_260(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_261(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_39(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_267(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_303(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_42(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_43(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_297(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_296(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_295(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_294(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_293(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_292(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_291(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_290(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_289(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_288(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_287(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_286(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_285(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_284(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_283(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_282(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_280(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_281(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_279(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_278(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_277(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_276(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_275(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_274(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_273(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_272(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_270(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_271(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_268(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_269(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_298(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_256(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_299(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_77(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_78(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_79(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_80(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_81(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_82(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_83(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_84(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_85(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_86(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_87(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_88(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_89(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_90(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_91(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_92(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_93(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_94(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_95(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_96(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_97(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_98(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_99(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_100(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_101(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_102(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_103(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_104(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_105(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_106(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_107(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_108(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_109(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_110(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_111(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_112(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_113(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_114(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_115(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_116(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_117(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_118(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_119(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_120(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_121(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_122(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_123(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_124(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_125(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_126(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_127(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_128(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_129(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_130(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_131(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_132(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_133(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_134(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_135(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_136(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_137(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_138(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_139(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_140(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_141(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_142(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_143(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_144(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_145(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_146(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_310(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_309(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_311(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_312(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_151(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_152(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_301(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_154(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_155(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_300(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_302(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_158(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_159(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_160(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_161(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_162(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_163(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_164(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_165(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_166(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_167(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_168(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_169(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_170(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_171(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_172(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_173(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_174(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_175(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_176(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_177(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_178(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_179(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_180(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_181(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_307(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_183(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_184(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_185(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_186(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_187(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_188(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_189(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_190(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_198(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_315(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_314(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_313(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_202(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_203(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_204(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_205(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_206(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_207(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_208(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_209(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_210(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_211(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_212(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_213(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_214(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_215(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_216(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_217(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_218(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_219(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_226(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_225(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_224(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_223(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_222(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_221(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_220(data, threadData);
  TRACE_POP
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionInitialEquations_lambda0 function */

int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

