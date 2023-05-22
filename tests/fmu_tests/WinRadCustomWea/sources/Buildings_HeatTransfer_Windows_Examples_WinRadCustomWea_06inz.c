#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustomWea/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_06inz.c"
#endif
/* Initialization */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_model.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_11mix.h"
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
winRad.staIntQAbsExtSha_flow.uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[125] /* winRad.staIntQAbsExtSha_flow.uSta_internal variable */) = 0.0;
#line 27 OMC_FILE
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
winRad.staIntQAbsGlaUns_flow[1].uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[128] /* winRad.staIntQAbsGlaUns_flow[1].uSta_internal variable */) = 0.0;
#line 42 OMC_FILE
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
winRad.staIntQAbsGlaUns_flow[2].uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[129] /* winRad.staIntQAbsGlaUns_flow[2].uSta_internal variable */) = 0.0;
#line 57 OMC_FILE
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
winRad.staIntQAbsGlaSha_flow[1].uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[126] /* winRad.staIntQAbsGlaSha_flow[1].uSta_internal variable */) = 0.0;
#line 72 OMC_FILE
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
winRad.staIntQAbsGlaSha_flow[2].uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[127] /* winRad.staIntQAbsGlaSha_flow[2].uSta_internal variable */) = 0.0;
#line 87 OMC_FILE
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
winRad.staIntQAbsIntSha_flow.uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[130] /* winRad.staIntQAbsIntSha_flow.uSta_internal variable */) = 0.0;
#line 102 OMC_FILE
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
winRad.staIntQTraDif_flow.uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[131] /* winRad.staIntQTraDif_flow.uSta_internal variable */) = 0.0;
#line 117 OMC_FILE
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
winRad.staIntQTraDir_flow.uSta_internal = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
#line 22 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  (data->localData[0]->realVars[132] /* winRad.staIntQTraDir_flow.uSta_internal variable */) = 0.0;
#line 132 OMC_FILE
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.TDryBul_degC = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
#line 35 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  (data->localData[0]->realVars[101] /* weaDat.tWetBul_TDryBulXi.TDryBul_degC variable */) = 0.0;
#line 147 OMC_FILE
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.rh_per = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
#line 37 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  (data->localData[0]->realVars[105] /* weaDat.tWetBul_TDryBulXi.rh_per variable */) = 0.0;
#line 162 OMC_FILE
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.lat_s = sin(weaDat.latitude.latitude)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
#line 30 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[27] /* HDirTil.incAng.incAng.lat_s variable */) = sin((data->simulationInfo->realParameter[106] /* weaDat.latitude.latitude PARAM */));
#line 177 OMC_FILE
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.lat_c = cos(weaDat.latitude.latitude)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
#line 29 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[26] /* HDirTil.incAng.incAng.lat_c variable */) = cos((data->simulationInfo->realParameter[106] /* weaDat.latitude.latitude PARAM */));
#line 192 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_230(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_239(DATA *data, threadData_t *threadData);


/*
equation index: 15
type: SIMPLE_ASSIGN
weaDat.conTimMin.tNext = if weaDat.conTimMin.canRepeatWeatherFile then weaDat.conTimMin.lenWea * (1.0 + (*Real*)(integer(weaDat.add30Min.y / weaDat.conTimMin.lenWea))) else time
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[140] /* weaDat.conTimMin.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[96] /* weaDat.conTimMin.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */),(data->simulationInfo->realParameter[96] /* weaDat.conTimMin.lenWea PARAM */),"weaDat.conTimMin.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 211 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_242(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_243(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_246(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_248(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_256(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_257(DATA *data, threadData_t *threadData);


/*
equation index: 22
type: SIMPLE_ASSIGN
weaDat.eqnTim.eqnTim = 60.0 * (9.869999999999999 * sin(2.0 * weaDat.eqnTim.Bt) + (-7.53) * cos(weaDat.eqnTim.Bt) + (-1.5) * sin(weaDat.eqnTim.Bt))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/EquationOfTime.mo"
  (data->localData[0]->realVars[96] /* weaDat.eqnTim.eqnTim variable */) = (60.0) * ((9.869999999999999) * (sin((2.0) * ((data->localData[0]->realVars[95] /* weaDat.eqnTim.Bt variable */)))) + (-7.53) * (cos((data->localData[0]->realVars[95] /* weaDat.eqnTim.Bt variable */))) + (-1.5) * (sin((data->localData[0]->realVars[95] /* weaDat.eqnTim.Bt variable */))));
#line 238 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_262(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_281(DATA *data, threadData_t *threadData);


/*
equation index: 25
type: SIMPLE_ASSIGN
weaBus.solDec = asin((-0.3979486313076103) * cos((weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  modelica_real tmp0;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp0 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[47] /* weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
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
  (data->localData[0]->realVars[52] /* weaBus.solDec variable */) = asin(tmp0);
#line 284 OMC_FILE
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
weaBus.solZen = acos(cos(weaDat.latitude.latitude) * cos(weaBus.solDec) * cos(weaBus.solHouAng) + sin(weaDat.latitude.latitude) * sin(weaBus.solDec))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  modelica_real tmp1;
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  tmp1 = ((cos((data->simulationInfo->realParameter[106] /* weaDat.latitude.latitude PARAM */))) * (cos((data->localData[0]->realVars[52] /* weaBus.solDec variable */)))) * (cos((data->localData[0]->realVars[53] /* weaBus.solHouAng variable */))) + (sin((data->simulationInfo->realParameter[106] /* weaDat.latitude.latitude PARAM */))) * (sin((data->localData[0]->realVars[52] /* weaBus.solDec variable */)));
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
  (data->localData[0]->realVars[55] /* weaBus.solZen variable */) = acos(tmp1);
#line 326 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_284(DATA *data, threadData_t *threadData);


/*
equation index: 28
type: SIMPLE_ASSIGN
weaDat.conTim.tNext = if weaDat.conTim.canRepeatWeatherFile then weaDat.conTim.lenWea * (1.0 + (*Real*)(integer(weaBus.cloTim / weaDat.conTim.lenWea))) else time
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->realVars[139] /* weaDat.conTim.tNext DISCRETE */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */)?((data->simulationInfo->realParameter[93] /* weaDat.conTim.lenWea PARAM */)) * (1.0 + ((modelica_real)((modelica_integer)floor(DIVISION_SIM((data->localData[0]->realVars[47] /* weaBus.cloTim variable */),(data->simulationInfo->realParameter[93] /* weaDat.conTim.lenWea PARAM */),"weaDat.conTim.lenWea",equationIndexes))))):data->localData[0]->timeValue);
#line 343 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_286(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_247(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_249(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_244(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_345(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_346(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_344(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_343(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_342(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_341(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_340(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_339(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_338(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_337(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_336(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_334(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_335(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_333(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_326(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_327(DATA *data, threadData_t *threadData);


/*
equation index: 49
type: SIMPLE_ASSIGN
weaBus.nOpa = min(1.0, max(0.0, weaDat.opaSkyCovSel.y))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterOpaqueSkyCover.mo"
  (data->localData[0]->realVars[48] /* weaBus.nOpa variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[98] /* weaDat.opaSkyCovSel.y variable */)));
#line 398 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_330(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_322(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_323(DATA *data, threadData_t *threadData);


/*
equation index: 53
type: SIMPLE_ASSIGN
weaBus.nTot = min(1.0, max(0.0, weaDat.totSkyCovSel.y))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterTotalSkyCover.mo"
  (data->localData[0]->realVars[49] /* weaBus.nTot variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[106] /* weaDat.totSkyCovSel.y variable */)));
#line 419 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_320(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_321(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_316(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_317(DATA *data, threadData_t *threadData);


/*
equation index: 58
type: SIMPLE_ASSIGN
weaBus.winDir = min(6.283185307179586, max(0.0, weaDat.conWinDir.y))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
#line 11 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterWindDirection.mo"
  (data->localData[0]->realVars[56] /* weaBus.winDir variable */) = fmin(6.283185307179586,fmax(0.0,(data->localData[0]->realVars[65] /* weaDat.conWinDir.y variable */)));
#line 442 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_315(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_314(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_313(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_312(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_311(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_310(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_309(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_294(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_295(DATA *data, threadData_t *threadData);


/*
equation index: 68
type: SIMPLE_ASSIGN
weaBus.relHum = min(1.0, max(0.0, weaDat.relHumSel.uFil))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
#line 10 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LimiterRelativeHumidity.mo"
  (data->localData[0]->realVars[50] /* weaBus.relHum variable */) = fmin(1.0,fmax(0.0,(data->localData[0]->realVars[100] /* weaDat.relHumSel.uFil variable */)));
#line 475 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_290(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_291(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_287(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_288(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_292(DATA *data, threadData_t *threadData);


/*
equation index: 74
type: SIMPLE_ASSIGN
weaDat.TBlaSkyCom.epsSky = (0.787 + 0.764 * log((-weaDat.TBlaSkyCom.TDewPoiK) / (-273.15))) * (1.0 + 0.0224 * weaDat.TBlaSkyCom.nOpa10 + (-0.0035) * weaDat.TBlaSkyCom.nOpa10 ^ 2.0 + 0.00028 * weaDat.TBlaSkyCom.nOpa10 ^ 3.0)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_74(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp2 = DIVISION_SIM((-(data->localData[0]->realVars[58] /* weaDat.TBlaSkyCom.TDewPoiK variable */)),-273.15,"-273.15",equationIndexes);
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  if(!(tmp2 > 0.0))
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  {
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    if (data->simulationInfo->noThrowAsserts) {
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      data->simulationInfo->needToReThrow = 1;
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    } else {
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      FILE_INFO info = {"",0,0,0,0,0};
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of log((-weaDat.TBlaSkyCom.TDewPoiK) / (-273.15)) was %g should be > 0", tmp2);
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
    }
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  }tmp3 = (data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */);
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  tmp4 = (data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */);
#line 41 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SkyTemperature/BlackBody.mo"
  (data->localData[0]->realVars[59] /* weaDat.TBlaSkyCom.epsSky variable */) = (0.787 + (0.764) * (log(tmp2))) * (1.0 + (0.0224) * ((data->localData[0]->realVars[60] /* weaDat.TBlaSkyCom.nOpa10 variable */)) + (-0.0035) * ((tmp3 * tmp3)) + (0.00028) * ((tmp4 * tmp4 * tmp4)));
#line 531 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_332(DATA *data, threadData_t *threadData);


/*
equation index: 76
type: SIMPLE_ASSIGN
weaDat.tWetBul_TDryBulXi.XiDryBul = 0.621964713077499 * weaBus.relHum / ((-0.378035286922501) * weaBus.relHum + 165.6565689594004 * exp(4102.99 / (weaBus.TDryBul - 35.719) - 17.2799))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
#line 63 "/home/marius/modelica-buildings/Buildings/Utilities/Psychrometrics/TWetBul_TDryBulPhi.mo"
  (data->localData[0]->realVars[102] /* weaDat.tWetBul_TDryBulXi.XiDryBul variable */) = (0.621964713077499) * (DIVISION_SIM((data->localData[0]->realVars[50] /* weaBus.relHum variable */),(-0.378035286922501) * ((data->localData[0]->realVars[50] /* weaBus.relHum variable */)) + (165.6565689594004) * (exp(DIVISION_SIM(4102.99,(data->localData[0]->realVars[44] /* weaBus.TDryBul variable */) - 35.719,"weaBus.TDryBul - 35.719",equationIndexes) - 17.2799)),"(-0.378035286922501) * weaBus.relHum + 165.6565689594004 * exp(4102.99 / (weaBus.TDryBul - 35.719) - 17.2799)",equationIndexes));
#line 548 OMC_FILE
  TRACE_POP
}

void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_77(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_78(DATA*, threadData_t*);
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_79(DATA*, threadData_t*);
/*
equation index: 84
indexNonlinear: 0
type: NONLINEAR

vars: {weaBus.TWetBul}
eqns: {77, 78, 79}
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 84 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = (data->localData[0]->realVars[45] /* weaBus.TWetBul variable */);
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,84};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 84 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[45] /* weaBus.TWetBul variable */) = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_263(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_264(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_280(DATA *data, threadData_t *threadData);


/*
equation index: 88
type: SIMPLE_ASSIGN
HDirTil.incAng.decAng.decAng = asin((-0.3979486313076103) * cos((weaBus.cloTim / 86400.0 + 10.0) * 0.01720242383895848))
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  modelica_real tmp0;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/Declination.mo"
  tmp0 = (-0.3979486313076103) * (cos((DIVISION_SIM((data->localData[0]->realVars[47] /* weaBus.cloTim variable */),86400.0,"86400.0",equationIndexes) + 10.0) * (0.01720242383895848)));
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
  (data->localData[0]->realVars[23] /* HDirTil.incAng.decAng.decAng variable */) = asin(tmp0);
#line 630 OMC_FILE
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.dec_c = cos(HDirTil.incAng.decAng.decAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[24] /* HDirTil.incAng.incAng.dec_c variable */) = cos((data->localData[0]->realVars[23] /* HDirTil.incAng.decAng.decAng variable */));
#line 645 OMC_FILE
  TRACE_POP
}

/*
equation index: 90
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.dec_s = sin(HDirTil.incAng.decAng.decAng)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->localData[0]->realVars[25] /* HDirTil.incAng.incAng.dec_s variable */) = sin((data->localData[0]->realVars[23] /* HDirTil.incAng.decAng.decAng variable */));
#line 660 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_265(DATA *data, threadData_t *threadData);


/*
equation index: 92
type: SIMPLE_ASSIGN
HDirTil.H = max(0.0, cos(HDirTil.inc) * weaBus.HDirNor)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DirectTiltedSurface.mo"
  (data->localData[0]->realVars[21] /* HDirTil.H variable */) = fmax(0.0,(cos((data->localData[0]->realVars[22] /* HDirTil.inc variable */))) * ((data->localData[0]->realVars[39] /* weaBus.HDirNor variable */)));
#line 677 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_266(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_267(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_245(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_250(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_251(DATA *data, threadData_t *threadData);


/*
equation index: 98
type: SIMPLE_ASSIGN
$PRE.weaDat.conTimMin.tNext = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  (data->simulationInfo->realVarsPre[140] /* weaDat.conTimMin.tNext DISCRETE */) = 0.0;
  TRACE_POP
}

/*
equation index: 99
type: SIMPLE_ASSIGN
$whenCondition1 = weaDat.conTimMin.canRepeatWeatherFile and weaDat.add30Min.y > $PRE.weaDat.conTimMin.tNext
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  modelica_boolean tmp1;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp1 = Greater((data->localData[0]->realVars[61] /* weaDat.add30Min.y variable */),(data->simulationInfo->realVarsPre[140] /* weaDat.conTimMin.tNext DISCRETE */));
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) = ((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) && tmp1);
#line 718 OMC_FILE
  TRACE_POP
}

/*
equation index: 100
type: SIMPLE_ASSIGN
$PRE.weaDat.conTim.tNext = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  (data->simulationInfo->realVarsPre[139] /* weaDat.conTim.tNext DISCRETE */) = 0.0;
  TRACE_POP
}

/*
equation index: 101
type: SIMPLE_ASSIGN
$whenCondition2 = weaDat.conTim.canRepeatWeatherFile and weaBus.cloTim > $PRE.weaDat.conTim.tNext
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  modelica_boolean tmp2;
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp2 = Greater((data->localData[0]->realVars[47] /* weaBus.cloTim variable */),(data->simulationInfo->realVarsPre[139] /* weaDat.conTim.tNext DISCRETE */));
#line 36 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) = ((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) && tmp2);
#line 749 OMC_FILE
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[12,1] = 0.3052322754811356
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[147] /* winRad.abs.coeAbsDevExtIrrIntSha[12,1] PARAM */) = 0.3052322754811356;
#line 764 OMC_FILE
  TRACE_POP
}

/*
equation index: 103
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[13,1] = winRad.abs.coeAbsDevExtIrrIntSha[12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
#line 121 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[148] /* winRad.abs.coeAbsDevExtIrrIntSha[13,1] PARAM */) = (data->simulationInfo->realParameter[147] /* winRad.abs.coeAbsDevExtIrrIntSha[12,1] PARAM */);
#line 779 OMC_FILE
  TRACE_POP
}

/*
equation index: 104
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[146] /* winRad.abs.coeAbsDevExtIrrIntSha[11,1] PARAM */) = 0.0;
#line 794 OMC_FILE
  TRACE_POP
}

/*
equation index: 105
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[10,1] = 0.1062597676765009
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[145] /* winRad.abs.coeAbsDevExtIrrIntSha[10,1] PARAM */) = 0.1062597676765009;
#line 809 OMC_FILE
  TRACE_POP
}

/*
equation index: 106
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[9,1] = 0.2282840296108259
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[144] /* winRad.abs.coeAbsDevExtIrrIntSha[9,1] PARAM */) = 0.2282840296108259;
#line 824 OMC_FILE
  TRACE_POP
}

/*
equation index: 107
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[8,1] = 0.3020070366994245
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[143] /* winRad.abs.coeAbsDevExtIrrIntSha[8,1] PARAM */) = 0.3020070366994245;
#line 839 OMC_FILE
  TRACE_POP
}

/*
equation index: 108
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[7,1] = 0.3384699121977249
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[142] /* winRad.abs.coeAbsDevExtIrrIntSha[7,1] PARAM */) = 0.3384699121977249;
#line 854 OMC_FILE
  TRACE_POP
}

/*
equation index: 109
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[6,1] = 0.3555423033605714
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[141] /* winRad.abs.coeAbsDevExtIrrIntSha[6,1] PARAM */) = 0.3555423033605714;
#line 869 OMC_FILE
  TRACE_POP
}

/*
equation index: 110
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[5,1] = 0.3635548084822143
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[140] /* winRad.abs.coeAbsDevExtIrrIntSha[5,1] PARAM */) = 0.3635548084822143;
#line 884 OMC_FILE
  TRACE_POP
}

/*
equation index: 111
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[4,1] = 0.3673475997451543
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[139] /* winRad.abs.coeAbsDevExtIrrIntSha[4,1] PARAM */) = 0.3673475997451543;
#line 899 OMC_FILE
  TRACE_POP
}

/*
equation index: 112
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[3,1] = 0.3690498410990196
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[138] /* winRad.abs.coeAbsDevExtIrrIntSha[3,1] PARAM */) = 0.3690498410990196;
#line 914 OMC_FILE
  TRACE_POP
}

/*
equation index: 113
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[2,1] = 0.3695381144818747
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
#line 114 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[137] /* winRad.abs.coeAbsDevExtIrrIntSha[2,1] PARAM */) = 0.3695381144818747;
#line 929 OMC_FILE
  TRACE_POP
}

/*
equation index: 114
type: SIMPLE_ASSIGN
winRad.abs.coeAbsDevExtIrrIntSha[1,1] = winRad.abs.coeAbsDevExtIrrIntSha[2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
#line 120 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */) = (data->simulationInfo->realParameter[137] /* winRad.abs.coeAbsDevExtIrrIntSha[2,1] PARAM */);
#line 944 OMC_FILE
  TRACE_POP
}

/*
equation index: 115
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,12,1] = 0.1039656205865592
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[201] /* winRad.abs.coeAbsEx[2,2,12,1] PARAM */) = 0.1039656205865592;
#line 959 OMC_FILE
  TRACE_POP
}

/*
equation index: 116
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,13,1] = winRad.abs.coeAbsEx[2,2,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
#line 103 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[202] /* winRad.abs.coeAbsEx[2,2,13,1] PARAM */) = (data->simulationInfo->realParameter[201] /* winRad.abs.coeAbsEx[2,2,12,1] PARAM */);
#line 974 OMC_FILE
  TRACE_POP
}

/*
equation index: 117
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,12,1] = 0.08526920479249403
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[175] /* winRad.abs.coeAbsEx[1,2,12,1] PARAM */) = 0.08526920479249403;
#line 989 OMC_FILE
  TRACE_POP
}

/*
equation index: 118
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,13,1] = winRad.abs.coeAbsEx[1,2,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
#line 103 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[176] /* winRad.abs.coeAbsEx[1,2,13,1] PARAM */) = (data->simulationInfo->realParameter[175] /* winRad.abs.coeAbsEx[1,2,12,1] PARAM */);
#line 1004 OMC_FILE
  TRACE_POP
}

/*
equation index: 119
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[200] /* winRad.abs.coeAbsEx[2,2,11,1] PARAM */) = 0.0;
#line 1019 OMC_FILE
  TRACE_POP
}

/*
equation index: 120
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[174] /* winRad.abs.coeAbsEx[1,2,11,1] PARAM */) = 0.0;
#line 1034 OMC_FILE
  TRACE_POP
}

/*
equation index: 121
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,10,1] = 0.06281787526849789
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[199] /* winRad.abs.coeAbsEx[2,2,10,1] PARAM */) = 0.06281787526849789;
#line 1049 OMC_FILE
  TRACE_POP
}

/*
equation index: 122
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,10,1] = 0.05645076246299933
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[173] /* winRad.abs.coeAbsEx[1,2,10,1] PARAM */) = 0.05645076246299933;
#line 1064 OMC_FILE
  TRACE_POP
}

/*
equation index: 123
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,9,1] = 0.08990517963983256
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[198] /* winRad.abs.coeAbsEx[2,2,9,1] PARAM */) = 0.08990517963983256;
#line 1079 OMC_FILE
  TRACE_POP
}

/*
equation index: 124
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,9,1] = 0.07585615681252504
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[172] /* winRad.abs.coeAbsEx[1,2,9,1] PARAM */) = 0.07585615681252504;
#line 1094 OMC_FILE
  TRACE_POP
}

/*
equation index: 125
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,8,1] = 0.1011252056324434
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[197] /* winRad.abs.coeAbsEx[2,2,8,1] PARAM */) = 0.1011252056324434;
#line 1109 OMC_FILE
  TRACE_POP
}

/*
equation index: 126
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,8,1] = 0.08303389367545573
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[171] /* winRad.abs.coeAbsEx[1,2,8,1] PARAM */) = 0.08303389367545573;
#line 1124 OMC_FILE
  TRACE_POP
}

/*
equation index: 127
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,7,1] = 0.1033001439761687
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[196] /* winRad.abs.coeAbsEx[2,2,7,1] PARAM */) = 0.1033001439761687;
#line 1139 OMC_FILE
  TRACE_POP
}

/*
equation index: 128
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,7,1] = 0.08385431211898785
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[170] /* winRad.abs.coeAbsEx[1,2,7,1] PARAM */) = 0.08385431211898785;
#line 1154 OMC_FILE
  TRACE_POP
}

/*
equation index: 129
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,6,1] = 0.1017176618131253
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[195] /* winRad.abs.coeAbsEx[2,2,6,1] PARAM */) = 0.1017176618131253;
#line 1169 OMC_FILE
  TRACE_POP
}

/*
equation index: 130
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,6,1] = 0.08216023482328237
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[169] /* winRad.abs.coeAbsEx[1,2,6,1] PARAM */) = 0.08216023482328237;
#line 1184 OMC_FILE
  TRACE_POP
}

/*
equation index: 131
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,5,1] = 0.09916070692199794
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[194] /* winRad.abs.coeAbsEx[2,2,5,1] PARAM */) = 0.09916070692199794;
#line 1199 OMC_FILE
  TRACE_POP
}

/*
equation index: 132
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,5,1] = 0.07991551880977556
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[168] /* winRad.abs.coeAbsEx[1,2,5,1] PARAM */) = 0.07991551880977556;
#line 1214 OMC_FILE
  TRACE_POP
}

/*
equation index: 133
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,4,1] = 0.09687385356797265
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[193] /* winRad.abs.coeAbsEx[2,2,4,1] PARAM */) = 0.09687385356797265;
#line 1229 OMC_FILE
  TRACE_POP
}

/*
equation index: 134
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,4,1] = 0.07799186166816173
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[167] /* winRad.abs.coeAbsEx[1,2,4,1] PARAM */) = 0.07799186166816173;
#line 1244 OMC_FILE
  TRACE_POP
}

/*
equation index: 135
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,3,1] = 0.09537350821079466
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[192] /* winRad.abs.coeAbsEx[2,2,3,1] PARAM */) = 0.09537350821079466;
#line 1259 OMC_FILE
  TRACE_POP
}

/*
equation index: 136
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,3,1] = 0.07674905803113916
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[166] /* winRad.abs.coeAbsEx[1,2,3,1] PARAM */) = 0.07674905803113916;
#line 1274 OMC_FILE
  TRACE_POP
}

/*
equation index: 137
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,2,1] = 0.0948566787482195
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[191] /* winRad.abs.coeAbsEx[2,2,2,1] PARAM */) = 0.0948566787482195;
#line 1289 OMC_FILE
  TRACE_POP
}

/*
equation index: 138
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,2,1,1] = winRad.abs.coeAbsEx[2,2,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
#line 102 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[190] /* winRad.abs.coeAbsEx[2,2,1,1] PARAM */) = (data->simulationInfo->realParameter[191] /* winRad.abs.coeAbsEx[2,2,2,1] PARAM */);
#line 1304 OMC_FILE
  TRACE_POP
}

/*
equation index: 139
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,2,1] = 0.07632331866750475
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[165] /* winRad.abs.coeAbsEx[1,2,2,1] PARAM */) = 0.07632331866750475;
#line 1319 OMC_FILE
  TRACE_POP
}

/*
equation index: 140
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,2,1,1] = winRad.abs.coeAbsEx[1,2,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
#line 102 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[164] /* winRad.abs.coeAbsEx[1,2,1,1] PARAM */) = (data->simulationInfo->realParameter[165] /* winRad.abs.coeAbsEx[1,2,2,1] PARAM */);
#line 1334 OMC_FILE
  TRACE_POP
}

/*
equation index: 141
type: SIMPLE_ASSIGN
winRad.abs.coeAbsIn[2,2,1] = 0.03241615014704199
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[206] /* winRad.abs.coeAbsIn[2,2,1] PARAM */) = 0.03241615014704199;
#line 1349 OMC_FILE
  TRACE_POP
}

/*
equation index: 142
type: SIMPLE_ASSIGN
winRad.abs.coeAbsIn[1,2,1] = 0.1227196468033888
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
#line 76 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[204] /* winRad.abs.coeAbsIn[1,2,1] PARAM */) = 0.1227196468033888;
#line 1364 OMC_FILE
  TRACE_POP
}

/*
equation index: 143
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,12,1] = 0.1354931525419724
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[188] /* winRad.abs.coeAbsEx[2,1,12,1] PARAM */) = 0.1354931525419724;
#line 1379 OMC_FILE
  TRACE_POP
}

/*
equation index: 144
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,13,1] = winRad.abs.coeAbsEx[2,1,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
#line 103 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[189] /* winRad.abs.coeAbsEx[2,1,13,1] PARAM */) = (data->simulationInfo->realParameter[188] /* winRad.abs.coeAbsEx[2,1,12,1] PARAM */);
#line 1394 OMC_FILE
  TRACE_POP
}

/*
equation index: 145
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,12,1] = 0.1227196468033888
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[162] /* winRad.abs.coeAbsEx[1,1,12,1] PARAM */) = 0.1227196468033888;
#line 1409 OMC_FILE
  TRACE_POP
}

/*
equation index: 146
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,13,1] = winRad.abs.coeAbsEx[1,1,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
#line 103 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[163] /* winRad.abs.coeAbsEx[1,1,13,1] PARAM */) = (data->simulationInfo->realParameter[162] /* winRad.abs.coeAbsEx[1,1,12,1] PARAM */);
#line 1424 OMC_FILE
  TRACE_POP
}

/*
equation index: 147
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[187] /* winRad.abs.coeAbsEx[2,1,11,1] PARAM */) = 0.0;
#line 1439 OMC_FILE
  TRACE_POP
}

/*
equation index: 148
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[161] /* winRad.abs.coeAbsEx[1,1,11,1] PARAM */) = 0.0;
#line 1454 OMC_FILE
  TRACE_POP
}

/*
equation index: 149
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,10,1] = 0.1415178832813775
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[186] /* winRad.abs.coeAbsEx[2,1,10,1] PARAM */) = 0.1415178832813775;
#line 1469 OMC_FILE
  TRACE_POP
}

/*
equation index: 150
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,10,1] = 0.1371678328302604
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[160] /* winRad.abs.coeAbsEx[1,1,10,1] PARAM */) = 0.1371678328302604;
#line 1484 OMC_FILE
  TRACE_POP
}

/*
equation index: 151
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,9,1] = 0.1403970614972095
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[185] /* winRad.abs.coeAbsEx[2,1,9,1] PARAM */) = 0.1403970614972095;
#line 1499 OMC_FILE
  TRACE_POP
}

/*
equation index: 152
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,9,1] = 0.1307986830869973
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[159] /* winRad.abs.coeAbsEx[1,1,9,1] PARAM */) = 0.1307986830869973;
#line 1514 OMC_FILE
  TRACE_POP
}

/*
equation index: 153
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,8,1] = 0.1329258880977036
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[184] /* winRad.abs.coeAbsEx[2,1,8,1] PARAM */) = 0.1329258880977036;
#line 1529 OMC_FILE
  TRACE_POP
}

/*
equation index: 154
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,8,1] = 0.1205657930053361
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[158] /* winRad.abs.coeAbsEx[1,1,8,1] PARAM */) = 0.1205657930053361;
#line 1544 OMC_FILE
  TRACE_POP
}

/*
equation index: 155
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,7,1] = 0.1258553503945128
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[183] /* winRad.abs.coeAbsEx[2,1,7,1] PARAM */) = 0.1258553503945128;
#line 1559 OMC_FILE
  TRACE_POP
}

/*
equation index: 156
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,7,1] = 0.1125698390133378
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[157] /* winRad.abs.coeAbsEx[1,1,7,1] PARAM */) = 0.1125698390133378;
#line 1574 OMC_FILE
  TRACE_POP
}

/*
equation index: 157
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,6,1] = 0.1199592159293939
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,157};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[182] /* winRad.abs.coeAbsEx[2,1,6,1] PARAM */) = 0.1199592159293939;
#line 1589 OMC_FILE
  TRACE_POP
}

/*
equation index: 158
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,6,1] = 0.1065974620703473
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[156] /* winRad.abs.coeAbsEx[1,1,6,1] PARAM */) = 0.1065974620703473;
#line 1604 OMC_FILE
  TRACE_POP
}

/*
equation index: 159
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,5,1] = 0.1153398886779867
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,159};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[181] /* winRad.abs.coeAbsEx[2,1,5,1] PARAM */) = 0.1153398886779867;
#line 1619 OMC_FILE
  TRACE_POP
}

/*
equation index: 160
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,5,1] = 0.1021914583318008
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[155] /* winRad.abs.coeAbsEx[1,1,5,1] PARAM */) = 0.1021914583318008;
#line 1634 OMC_FILE
  TRACE_POP
}

/*
equation index: 161
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,4,1] = 0.1120318818175741
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,161};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[180] /* winRad.abs.coeAbsEx[2,1,4,1] PARAM */) = 0.1120318818175741;
#line 1649 OMC_FILE
  TRACE_POP
}

/*
equation index: 162
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,4,1] = 0.09913158934736244
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[154] /* winRad.abs.coeAbsEx[1,1,4,1] PARAM */) = 0.09913158934736244;
#line 1664 OMC_FILE
  TRACE_POP
}

/*
equation index: 163
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,3,1] = 0.1100473669610094
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,163};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[179] /* winRad.abs.coeAbsEx[2,1,3,1] PARAM */) = 0.1100473669610094;
#line 1679 OMC_FILE
  TRACE_POP
}

/*
equation index: 164
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,3,1] = 0.09732302857079711
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[153] /* winRad.abs.coeAbsEx[1,1,3,1] PARAM */) = 0.09732302857079711;
#line 1694 OMC_FILE
  TRACE_POP
}

/*
equation index: 165
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,2,1] = 0.1093863539769833
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
#line 92 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[178] /* winRad.abs.coeAbsEx[2,1,2,1] PARAM */) = 0.1093863539769833;
#line 1709 OMC_FILE
  TRACE_POP
}

/*
equation index: 166
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[2,1,1,1] = winRad.abs.coeAbsEx[2,1,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
#line 102 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[177] /* winRad.abs.coeAbsEx[2,1,1,1] PARAM */) = (data->simulationInfo->realParameter[178] /* winRad.abs.coeAbsEx[2,1,2,1] PARAM */);
#line 1724 OMC_FILE
  TRACE_POP
}

/*
equation index: 167
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,2,1] = 0.0967242489000629
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
#line 89 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[152] /* winRad.abs.coeAbsEx[1,1,2,1] PARAM */) = 0.0967242489000629;
#line 1739 OMC_FILE
  TRACE_POP
}

/*
equation index: 168
type: SIMPLE_ASSIGN
winRad.abs.coeAbsEx[1,1,1,1] = winRad.abs.coeAbsEx[1,1,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
#line 102 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */) = (data->simulationInfo->realParameter[152] /* winRad.abs.coeAbsEx[1,1,2,1] PARAM */);
#line 1754 OMC_FILE
  TRACE_POP
}

/*
equation index: 169
type: SIMPLE_ASSIGN
winRad.abs.coeAbsIn[2,1,1] = 0.02252369052121515
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
#line 79 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[205] /* winRad.abs.coeAbsIn[2,1,1] PARAM */) = 0.02252369052121515;
#line 1769 OMC_FILE
  TRACE_POP
}

/*
equation index: 170
type: SIMPLE_ASSIGN
winRad.abs.coeAbsIn[1,1,1] = 0.08526920479249403
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
#line 76 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[203] /* winRad.abs.coeAbsIn[1,1,1] PARAM */) = 0.08526920479249403;
#line 1784 OMC_FILE
  TRACE_POP
}

/*
equation index: 171
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,12,1] = 0.1526161377405678
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[959] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */) = 0.1526161377405678;
#line 1799 OMC_FILE
  TRACE_POP
}

/*
equation index: 172
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,13,1] = winRad.tra.coeTraWinExtIrr[2,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
#line 63 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[960] /* winRad.tra.coeTraWinExtIrr[2,13,1] PARAM */) = (data->simulationInfo->realParameter[959] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */);
#line 1814 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_252(DATA *data, threadData_t *threadData);


/*
equation index: 174
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,12,1] = 0.5777675151140318
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */) = 0.5777675151140318;
#line 1831 OMC_FILE
  TRACE_POP
}

/*
equation index: 175
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,13,1] = winRad.tra.coeTraWinExtIrr[1,12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,175};
#line 63 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[947] /* winRad.tra.coeTraWinExtIrr[1,13,1] PARAM */) = (data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */);
#line 1846 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_253(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_254(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_255(DATA *data, threadData_t *threadData);


/*
equation index: 179
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
    winRad.abs.absRad[1,i + 1,:] := {(1.0 - uSha) * (HDifTilIso.H * winRad.abs.coeAbsEx[1,i,12,1] + HRoo.y * winRad.abs.coeAbsIn[1,i,1])};
    winRad.abs.absRad[2,i + 1,:] := {uSha * (HDifTilIso.H * winRad.abs.coeAbsEx[2,i,12,1] + HRoo.y * winRad.abs.coeAbsIn[2,i,1])};
  end for;
  for iSta in 1:1 loop
    winRad.abs.absRad[2,4,iSta] := uSha * (0.3052322754811356 * HDifTilIso.H + 0.5282960143941167 * HRoo.y);
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
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,179};
  real_array tmp3;
  index_spec_t tmp4;
  real_array tmp5;
  real_array tmp6;
  index_spec_t tmp7;
  real_array tmp8;
  real_array tmp9;
  index_spec_t tmp10;
  real_array tmp11;
  real_array tmp12;
  index_spec_t tmp13;
  real_array tmp14;
  real_array tmp15;
  index_spec_t tmp16;
  real_array tmp17;
  real_array tmp18;
  index_spec_t tmp19;
  real_array tmp20;
  modelica_integer tmp21;
  modelica_integer tmp22;
  modelica_integer tmp23;
  modelica_integer tmp24;
  modelica_integer tmp25;
  modelica_integer tmp26;
  real_array tmp27;
  real_array tmp28;
  modelica_integer tmp29;
  modelica_integer tmp30;
  modelica_integer tmp31;
  modelica_integer tmp32;
  modelica_integer tmp33;
  modelica_integer tmp34;
  real_array tmp35;
  modelica_integer tmp36;
  modelica_integer tmp37;
  modelica_integer tmp38;
  real_array tmp39;
  real_array tmp40;
  index_spec_t tmp41;
  index_spec_t tmp42;
  real_array tmp43;
  real_array tmp44;
  real_array tmp45;
  index_spec_t tmp46;
  index_spec_t tmp47;
  real_array tmp48;
  real_array tmp49;
  real_array tmp50;
  integer_array tmp51;
  modelica_integer tmp52;
  index_spec_t tmp53;
  index_spec_t tmp54;
  real_array tmp55;
  real_array tmp56;
  real_array tmp57;
  integer_array tmp58;
  modelica_integer tmp59;
  index_spec_t tmp60;
  index_spec_t tmp61;
  real_array tmp62;
  (data->localData[0]->realVars[111] /* winRad.abs.QAbsGlaSha_flow[2,1] variable */) = (data->modelData->realVarsData[111] /* winRad.abs.QAbsGlaSha_flow[2,1] variable */).attribute .start;

  (data->localData[0]->realVars[110] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */) = (data->modelData->realVarsData[110] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */).attribute .start;

  (data->localData[0]->realVars[113] /* winRad.abs.QAbsGlaUns_flow[2,1] variable */) = (data->modelData->realVarsData[113] /* winRad.abs.QAbsGlaUns_flow[2,1] variable */).attribute .start;

  (data->localData[0]->realVars[112] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */) = (data->modelData->realVarsData[112] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */).attribute .start;

  (data->localData[0]->realVars[114] /* winRad.abs.QAbsIntSha_flow[1] variable */) = (data->modelData->realVarsData[114] /* winRad.abs.QAbsIntSha_flow[1] variable */).attribute .start;

  (data->localData[0]->realVars[109] /* winRad.abs.QAbsExtSha_flow[1] variable */) = (data->modelData->realVarsData[109] /* winRad.abs.QAbsExtSha_flow[1] variable */).attribute .start;

  (data->localData[0]->realVars[124] /* winRad.abs.x variable */) = (data->modelData->realVarsData[124] /* winRad.abs.x variable */).attribute .start;

  (data->localData[0]->realVars[123] /* winRad.abs.incAng2 variable */) = (data->modelData->realVarsData[123] /* winRad.abs.incAng2 variable */).attribute .start;

  (data->localData[0]->realVars[122] /* winRad.abs.absRad[2,4,1] variable */) = (data->modelData->realVarsData[122] /* winRad.abs.absRad[2,4,1] variable */).attribute .start;

  (data->localData[0]->realVars[121] /* winRad.abs.absRad[2,3,1] variable */) = (data->modelData->realVarsData[121] /* winRad.abs.absRad[2,3,1] variable */).attribute .start;

  (data->localData[0]->realVars[120] /* winRad.abs.absRad[2,2,1] variable */) = (data->modelData->realVarsData[120] /* winRad.abs.absRad[2,2,1] variable */).attribute .start;

  (data->localData[0]->realVars[119] /* winRad.abs.absRad[2,1,1] variable */) = (data->modelData->realVarsData[119] /* winRad.abs.absRad[2,1,1] variable */).attribute .start;

  (data->localData[0]->realVars[118] /* winRad.abs.absRad[1,4,1] variable */) = (data->modelData->realVarsData[118] /* winRad.abs.absRad[1,4,1] variable */).attribute .start;

  (data->localData[0]->realVars[117] /* winRad.abs.absRad[1,3,1] variable */) = (data->modelData->realVarsData[117] /* winRad.abs.absRad[1,3,1] variable */).attribute .start;

  (data->localData[0]->realVars[116] /* winRad.abs.absRad[1,2,1] variable */) = (data->modelData->realVarsData[116] /* winRad.abs.absRad[1,2,1] variable */).attribute .start;

  (data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */) = (data->modelData->realVarsData[115] /* winRad.abs.absRad[1,1,1] variable */).attribute .start;

#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp3, 1, (modelica_real)0.0);
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp4, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp5, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 124 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp3, &tmp5, &tmp4);
#line 2007 OMC_FILE

#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp6, 1, (modelica_real)0.0);
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp7, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp8, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 125 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp6, &tmp8, &tmp7);
#line 2017 OMC_FILE

#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp9, 1, (modelica_real)0.0);
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp10, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp11, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 126 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp9, &tmp11, &tmp10);
#line 2027 OMC_FILE

#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  array_alloc_scalar_real_array(&tmp12, 1, (modelica_real)0.0);
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp13, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp14, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 127 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp12, &tmp14, &tmp13);
#line 2037 OMC_FILE

#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp21 = ((modelica_integer) 1); tmp22 = 1; tmp23 = ((modelica_integer) 2);
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp22 > 0) && (tmp21 > tmp23)) || ((tmp22 < 0) && (tmp21 < tmp23))))
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer i;
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(i = ((modelica_integer) 1); in_range_integer(i, tmp21, tmp23); i += tmp22)
#line 132 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp15, 1, (modelica_real)(1.0 - (data->localData[0]->realVars[36] /* uSha variable */)) * (((data->localData[0]->realVars[17] /* HDifTilIso.H variable */)) * ((&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (((modelica_integer) 1)-1)]) + ((data->localData[0]->realVars[31] /* HRoo.y variable */)) * ((&data->simulationInfo->realParameter[203] /* winRad.abs.coeAbsIn[1,1,1] PARAM */)[((((modelica_integer) 1) - 1) * 2 + (i-1)) * 1 + (((modelica_integer) 1)-1)])));
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      create_index_spec(&tmp16, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) i + ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      real_array_create(&tmp17, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 133 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      indexed_assign_real_array(tmp15, &tmp17, &tmp16);
#line 2059 OMC_FILE

#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp18, 1, (modelica_real)((data->localData[0]->realVars[36] /* uSha variable */)) * (((data->localData[0]->realVars[17] /* HDifTilIso.H variable */)) * ((&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (((modelica_integer) 1)-1)]) + ((data->localData[0]->realVars[31] /* HRoo.y variable */)) * ((&data->simulationInfo->realParameter[203] /* winRad.abs.coeAbsIn[1,1,1] PARAM */)[((((modelica_integer) 2) - 1) * 2 + (i-1)) * 1 + (((modelica_integer) 1)-1)])));
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      create_index_spec(&tmp19, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) i + ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      real_array_create(&tmp20, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 135 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      indexed_assign_real_array(tmp18, &tmp20, &tmp19);
#line 2069 OMC_FILE
    }
  }

#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp24 = ((modelica_integer) 1); tmp25 = 1; tmp26 = ((modelica_integer) 1);
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp25 > 0) && (tmp24 > tmp26)) || ((tmp25 < 0) && (tmp24 < tmp26))))
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer iSta;
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp24, tmp26); iSta += tmp25)
#line 145 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 151 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      (&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] = ((data->localData[0]->realVars[36] /* uSha variable */)) * ((0.3052322754811356) * ((data->localData[0]->realVars[17] /* HDifTilIso.H variable */)) + (0.5282960143941167) * ((data->localData[0]->realVars[31] /* HRoo.y variable */)));
#line 2087 OMC_FILE
    }
  }

#line 160 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->localData[0]->realVars[123] /* winRad.abs.incAng2 variable */) = fmin((data->localData[0]->realVars[22] /* HDirTil.inc variable */),1.570796326794897);
#line 2093 OMC_FILE

#line 162 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->localData[0]->realVars[124] /* winRad.abs.x variable */) = (5.729577951308232) * (fabs((data->localData[0]->realVars[123] /* winRad.abs.incAng2 variable */))) + 2.0;
#line 2097 OMC_FILE

#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp32 = ((modelica_integer) 1); tmp33 = 1; tmp34 = ((modelica_integer) 2);
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp33 > 0) && (tmp32 > tmp34)) || ((tmp33 < 0) && (tmp32 < tmp34))))
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer i;
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(i = ((modelica_integer) 1); in_range_integer(i, tmp32, tmp34); i += tmp33)
#line 165 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      tmp29 = ((modelica_integer) 1); tmp30 = 1; tmp31 = ((modelica_integer) 1);
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      if(!(((tmp30 > 0) && (tmp29 > tmp31)) || ((tmp30 < 0) && (tmp29 < tmp31))))
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      {
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        modelica_integer iSta;
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp29, tmp31); iSta += tmp30)
#line 167 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
        {
#line 168 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          array_alloc_scalar_real_array(&tmp27, 13, (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 1)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 2)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 3)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 5)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 6)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 7)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 8)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 9)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 10)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 11)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 1) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 13)-1)) * 1 + (iSta-1)]);
#line 168 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          (&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 1) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 1) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * ((1.0 - (data->localData[0]->realVars[36] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp27, (data->localData[0]->realVars[124] /* winRad.abs.x variable */))));
#line 2127 OMC_FILE

#line 174 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          array_alloc_scalar_real_array(&tmp28, 13, (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 1)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 2)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 3)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 5)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 6)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 7)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 8)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 9)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 10)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 11)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 12)-1)) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[151] /* winRad.abs.coeAbsEx[1,1,1,1] PARAM */)[(((((modelica_integer) 2) - 1) * 2 + (i-1)) * 13 + (((modelica_integer) 13)-1)) * 1 + (iSta-1)]);
#line 174 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
          (&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 2) - 1) * 4 + (i + ((modelica_integer) 1)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[36] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp28, (data->localData[0]->realVars[124] /* winRad.abs.x variable */))));
#line 2133 OMC_FILE
        }
      }
    }
  }

#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp36 = ((modelica_integer) 1); tmp37 = 1; tmp38 = ((modelica_integer) 1);
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  if(!(((tmp37 > 0) && (tmp36 > tmp38)) || ((tmp37 < 0) && (tmp36 < tmp38))))
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  {
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    modelica_integer iSta;
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    for(iSta = ((modelica_integer) 1); in_range_integer(iSta, tmp36, tmp38); iSta += tmp37)
#line 183 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
    {
#line 184 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      array_alloc_scalar_real_array(&tmp35, 13, (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 1) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 2) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 3) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 4) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 5) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 6) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 7) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 8) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 9) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 10) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 11) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 12) - 1) * 1 + (iSta-1)], (modelica_real)(&data->simulationInfo->realParameter[136] /* winRad.abs.coeAbsDevExtIrrIntSha[1,1] PARAM */)[(((modelica_integer) 13) - 1) * 1 + (iSta-1)]);
#line 184 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
      (&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */))[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] = (&data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */)[((((modelica_integer) 2) - 1) * 4 + (((modelica_integer) 4)-1)) * 1 + (iSta-1)] + ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[36] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp35, (data->localData[0]->realVars[124] /* winRad.abs.x variable */))));
#line 2155 OMC_FILE
    }
  }

#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp39, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp41, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp39, &tmp41, &tmp40);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp42, 1, (modelica_integer)(1), (int*)0, 'W');
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp43, (modelica_real*)&(data->localData[0]->realVars[109] /* winRad.abs.QAbsExtSha_flow[1] variable */), 1, (_index_t)1);
#line 202 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp40, &tmp43, &tmp42);
#line 2171 OMC_FILE

#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp44, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp46, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 4)), 'S', (modelica_integer)(1), (int*)0, 'W');
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp44, &tmp46, &tmp45);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp47, 1, (modelica_integer)(1), (int*)0, 'W');
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp48, (modelica_real*)&(data->localData[0]->realVars[114] /* winRad.abs.QAbsIntSha_flow[1] variable */), 1, (_index_t)1);
#line 203 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp45, &tmp48, &tmp47);
#line 2185 OMC_FILE

#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp49, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_integer_array_from_range(&tmp51, ((modelica_integer) 2), 1, ((modelica_integer) 3));
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp52 = size_of_dimension_base_array(tmp51, 1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp53, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 1)), 'S', tmp52, integer_array_make_index_array(tmp51), 'A', (modelica_integer)(1), (int*)0, 'W');
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp49, &tmp53, &tmp50);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp54, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W');
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp55, (modelica_real*)&(data->localData[0]->realVars[112] /* winRad.abs.QAbsGlaUns_flow[1,1] variable */), 2, (_index_t)2, (_index_t)1);
#line 204 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp50, &tmp55, &tmp54);
#line 2203 OMC_FILE

#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp56, (modelica_real*)&(data->localData[0]->realVars[115] /* winRad.abs.absRad[1,1,1] variable */), 3, (_index_t)2, (_index_t)4, (_index_t)1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_integer_array_from_range(&tmp58, ((modelica_integer) 2), 1, ((modelica_integer) 3));
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  tmp59 = size_of_dimension_base_array(tmp58, 1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp60, 3, (modelica_integer)(0), make_index_array(1, (modelica_integer) ((modelica_integer) 2)), 'S', tmp59, integer_array_make_index_array(tmp58), 'A', (modelica_integer)(1), (int*)0, 'W');
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  index_alloc_real_array(&tmp56, &tmp60, &tmp57);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  create_index_spec(&tmp61, 2, (modelica_integer)(1), (int*)0, 'W', (modelica_integer)(1), (int*)0, 'W');
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  real_array_create(&tmp62, (modelica_real*)&(data->localData[0]->realVars[110] /* winRad.abs.QAbsGlaSha_flow[1,1] variable */), 2, (_index_t)2, (_index_t)1);
#line 205 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  indexed_assign_real_array(tmp57, &tmp62, &tmp61);
#line 2221 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_278(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_276(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_277(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_279(DATA *data, threadData_t *threadData);


/*
equation index: 184
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[958] /* winRad.tra.coeTraWinExtIrr[2,11,1] PARAM */) = 0.0;
#line 2244 OMC_FILE
  TRACE_POP
}

/*
equation index: 185
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,11,1] = 0.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,185};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[945] /* winRad.tra.coeTraWinExtIrr[1,11,1] PARAM */) = 0.0;
#line 2259 OMC_FILE
  TRACE_POP
}

/*
equation index: 186
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,10,1] = 0.05312988383825046
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[957] /* winRad.tra.coeTraWinExtIrr[2,10,1] PARAM */) = 0.05312988383825046;
#line 2274 OMC_FILE
  TRACE_POP
}

/*
equation index: 187
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,10,1] = 0.2011367960032149
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,187};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[944] /* winRad.tra.coeTraWinExtIrr[1,10,1] PARAM */) = 0.2011367960032149;
#line 2289 OMC_FILE
  TRACE_POP
}

/*
equation index: 188
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,9,1] = 0.1141420148054129
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,188};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[956] /* winRad.tra.coeTraWinExtIrr[2,9,1] PARAM */) = 0.1141420148054129;
#line 2304 OMC_FILE
  TRACE_POP
}

/*
equation index: 189
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,9,1] = 0.4321138592586893
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,189};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[943] /* winRad.tra.coeTraWinExtIrr[1,9,1] PARAM */) = 0.4321138592586893;
#line 2319 OMC_FILE
  TRACE_POP
}

/*
equation index: 190
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,8,1] = 0.1510035183497123
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,190};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[955] /* winRad.tra.coeTraWinExtIrr[2,8,1] PARAM */) = 0.1510035183497123;
#line 2334 OMC_FILE
  TRACE_POP
}

/*
equation index: 191
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,8,1] = 0.5716625309880206
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,191};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[942] /* winRad.tra.coeTraWinExtIrr[1,8,1] PARAM */) = 0.5716625309880206;
#line 2349 OMC_FILE
  TRACE_POP
}

/*
equation index: 192
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,7,1] = 0.1692349560988624
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[954] /* winRad.tra.coeTraWinExtIrr[2,7,1] PARAM */) = 0.1692349560988624;
#line 2364 OMC_FILE
  TRACE_POP
}

/*
equation index: 193
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,7,1] = 0.6406823125211414
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[941] /* winRad.tra.coeTraWinExtIrr[1,7,1] PARAM */) = 0.6406823125211414;
#line 2379 OMC_FILE
  TRACE_POP
}

/*
equation index: 194
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,6,1] = 0.1777711516802857
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[953] /* winRad.tra.coeTraWinExtIrr[2,6,1] PARAM */) = 0.1777711516802857;
#line 2394 OMC_FILE
  TRACE_POP
}

/*
equation index: 195
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,6,1] = 0.6729982692909955
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,195};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[940] /* winRad.tra.coeTraWinExtIrr[1,6,1] PARAM */) = 0.6729982692909955;
#line 2409 OMC_FILE
  TRACE_POP
}

/*
equation index: 196
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,5,1] = 0.1817774042411072
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,196};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[952] /* winRad.tra.coeTraWinExtIrr[2,5,1] PARAM */) = 0.1817774042411072;
#line 2424 OMC_FILE
  TRACE_POP
}

/*
equation index: 197
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,5,1] = 0.6881649654297732
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,197};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[939] /* winRad.tra.coeTraWinExtIrr[1,5,1] PARAM */) = 0.6881649654297732;
#line 2439 OMC_FILE
  TRACE_POP
}

/*
equation index: 198
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,4,1] = 0.1836737998725771
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[951] /* winRad.tra.coeTraWinExtIrr[2,4,1] PARAM */) = 0.1836737998725771;
#line 2454 OMC_FILE
  TRACE_POP
}

/*
equation index: 199
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,4,1] = 0.6953442572654116
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,199};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[938] /* winRad.tra.coeTraWinExtIrr[1,4,1] PARAM */) = 0.6953442572654116;
#line 2469 OMC_FILE
  TRACE_POP
}

/*
equation index: 200
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,3,1] = 0.1845249205495098
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[950] /* winRad.tra.coeTraWinExtIrr[2,3,1] PARAM */) = 0.1845249205495098;
#line 2484 OMC_FILE
  TRACE_POP
}

/*
equation index: 201
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,3,1] = 0.6985663927869478
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[937] /* winRad.tra.coeTraWinExtIrr[1,3,1] PARAM */) = 0.6985663927869478;
#line 2499 OMC_FILE
  TRACE_POP
}

/*
equation index: 202
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,2,1] = 0.1847690572409374
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
#line 52 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[949] /* winRad.tra.coeTraWinExtIrr[2,2,1] PARAM */) = 0.1847690572409374;
#line 2514 OMC_FILE
  TRACE_POP
}

/*
equation index: 203
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[2,1,1] = winRad.tra.coeTraWinExtIrr[2,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
#line 62 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[948] /* winRad.tra.coeTraWinExtIrr[2,1,1] PARAM */) = (data->simulationInfo->realParameter[949] /* winRad.tra.coeTraWinExtIrr[2,2,1] PARAM */);
#line 2529 OMC_FILE
  TRACE_POP
}

/*
equation index: 204
type: SIMPLE_ASSIGN
winRad.tra.QTraDirSha_flow[1] = HDirTil.H * uSha * Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.tra.coeTraWinExtIrr[2,1,1], winRad.tra.coeTraWinExtIrr[2,2,1], winRad.tra.coeTraWinExtIrr[2,3,1], winRad.tra.coeTraWinExtIrr[2,4,1], winRad.tra.coeTraWinExtIrr[2,5,1], winRad.tra.coeTraWinExtIrr[2,6,1], winRad.tra.coeTraWinExtIrr[2,7,1], winRad.tra.coeTraWinExtIrr[2,8,1], winRad.tra.coeTraWinExtIrr[2,9,1], winRad.tra.coeTraWinExtIrr[2,10,1], winRad.tra.coeTraWinExtIrr[2,11,1], winRad.tra.coeTraWinExtIrr[2,12,1], winRad.tra.coeTraWinExtIrr[2,13,1]}, winRad.tra.x)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  real_array tmp63;
#line 91 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  array_alloc_scalar_real_array(&tmp63, 13, (modelica_real)(data->simulationInfo->realParameter[948] /* winRad.tra.coeTraWinExtIrr[2,1,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[949] /* winRad.tra.coeTraWinExtIrr[2,2,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[950] /* winRad.tra.coeTraWinExtIrr[2,3,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[951] /* winRad.tra.coeTraWinExtIrr[2,4,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[952] /* winRad.tra.coeTraWinExtIrr[2,5,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[953] /* winRad.tra.coeTraWinExtIrr[2,6,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[954] /* winRad.tra.coeTraWinExtIrr[2,7,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[955] /* winRad.tra.coeTraWinExtIrr[2,8,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[956] /* winRad.tra.coeTraWinExtIrr[2,9,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[957] /* winRad.tra.coeTraWinExtIrr[2,10,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[958] /* winRad.tra.coeTraWinExtIrr[2,11,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[959] /* winRad.tra.coeTraWinExtIrr[2,12,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[960] /* winRad.tra.coeTraWinExtIrr[2,13,1] PARAM */));
#line 91 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[135] /* winRad.tra.QTraDirSha_flow[1] variable */) = ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * (((data->localData[0]->realVars[36] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp63, (data->localData[0]->realVars[138] /* winRad.tra.x variable */))));
#line 2547 OMC_FILE
  TRACE_POP
}

/*
equation index: 205
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,2,1] = 0.6994906348208673
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
#line 49 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[936] /* winRad.tra.coeTraWinExtIrr[1,2,1] PARAM */) = 0.6994906348208673;
#line 2562 OMC_FILE
  TRACE_POP
}

/*
equation index: 206
type: SIMPLE_ASSIGN
winRad.tra.coeTraWinExtIrr[1,1,1] = winRad.tra.coeTraWinExtIrr[1,2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
#line 62 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[935] /* winRad.tra.coeTraWinExtIrr[1,1,1] PARAM */) = (data->simulationInfo->realParameter[936] /* winRad.tra.coeTraWinExtIrr[1,2,1] PARAM */);
#line 2577 OMC_FILE
  TRACE_POP
}

/*
equation index: 207
type: SIMPLE_ASSIGN
winRad.tra.QTraDirUns_flow[1] = HDirTil.H * (1.0 - uSha) * Buildings.HeatTransfer.Windows.BaseClasses.smoothInterpolation({winRad.tra.coeTraWinExtIrr[1,1,1], winRad.tra.coeTraWinExtIrr[1,2,1], winRad.tra.coeTraWinExtIrr[1,3,1], winRad.tra.coeTraWinExtIrr[1,4,1], winRad.tra.coeTraWinExtIrr[1,5,1], winRad.tra.coeTraWinExtIrr[1,6,1], winRad.tra.coeTraWinExtIrr[1,7,1], winRad.tra.coeTraWinExtIrr[1,8,1], winRad.tra.coeTraWinExtIrr[1,9,1], winRad.tra.coeTraWinExtIrr[1,10,1], winRad.tra.coeTraWinExtIrr[1,11,1], winRad.tra.coeTraWinExtIrr[1,12,1], winRad.tra.coeTraWinExtIrr[1,13,1]}, winRad.tra.x)
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  real_array tmp64;
#line 83 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  array_alloc_scalar_real_array(&tmp64, 13, (modelica_real)(data->simulationInfo->realParameter[935] /* winRad.tra.coeTraWinExtIrr[1,1,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[936] /* winRad.tra.coeTraWinExtIrr[1,2,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[937] /* winRad.tra.coeTraWinExtIrr[1,3,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[938] /* winRad.tra.coeTraWinExtIrr[1,4,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[939] /* winRad.tra.coeTraWinExtIrr[1,5,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[940] /* winRad.tra.coeTraWinExtIrr[1,6,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[941] /* winRad.tra.coeTraWinExtIrr[1,7,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[942] /* winRad.tra.coeTraWinExtIrr[1,8,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[943] /* winRad.tra.coeTraWinExtIrr[1,9,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[944] /* winRad.tra.coeTraWinExtIrr[1,10,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[945] /* winRad.tra.coeTraWinExtIrr[1,11,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[946] /* winRad.tra.coeTraWinExtIrr[1,12,1] PARAM */), (modelica_real)(data->simulationInfo->realParameter[947] /* winRad.tra.coeTraWinExtIrr[1,13,1] PARAM */));
#line 83 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->localData[0]->realVars[136] /* winRad.tra.QTraDirUns_flow[1] variable */) = ((data->localData[0]->realVars[21] /* HDirTil.H variable */)) * ((1.0 - (data->localData[0]->realVars[36] /* uSha variable */)) * (omc_Buildings_HeatTransfer_Windows_BaseClasses_smoothInterpolation(threadData, tmp64, (data->localData[0]->realVars[138] /* winRad.tra.x variable */))));
#line 2595 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_274(DATA *data, threadData_t *threadData);


/*
equation index: 209
type: SIMPLE_ASSIGN
HDifTilIso.HDifTilIso.til_c = -3.491481338843133e-15
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
#line 25 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/BaseClasses/DiffuseIsotropic.mo"
  (data->localData[0]->realVars[18] /* HDifTilIso.HDifTilIso.til_c variable */) = -3.491481338843133e-15;
#line 2612 OMC_FILE
  TRACE_POP
}

/*
equation index: 210
type: SIMPLE_ASSIGN
weaDat.pAtmSel.y = 101325.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[99] /* weaDat.pAtmSel.y variable */) = 101325.0;
#line 2627 OMC_FILE
  TRACE_POP
}

/*
equation index: 211
type: SIMPLE_ASSIGN
weaDat.con30Min.y = 1800.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
#line 300 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Interfaces.mo"
  (data->localData[0]->realVars[62] /* weaDat.con30Min.y variable */) = 1800.0;
#line 2642 OMC_FILE
  TRACE_POP
}

/*
equation index: 212
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[12,1] = 0.2142436332900854
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[218] /* winRad.abs.coeRefExtPan1[12,1] PARAM */) = 0.2142436332900854;
#line 2657 OMC_FILE
  TRACE_POP
}

/*
equation index: 213
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[13,1] = winRad.abs.coeRefExtPan1[12,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
#line 119 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[219] /* winRad.abs.coeRefExtPan1[13,1] PARAM */) = (data->simulationInfo->realParameter[218] /* winRad.abs.coeRefExtPan1[12,1] PARAM */);
#line 2672 OMC_FILE
  TRACE_POP
}

/*
equation index: 214
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[2,1] = 0.127461797611565
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[208] /* winRad.abs.coeRefExtPan1[2,1] PARAM */) = 0.127461797611565;
#line 2687 OMC_FILE
  TRACE_POP
}

/*
equation index: 215
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[1,1] = winRad.abs.coeRefExtPan1[2,1]
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
#line 118 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[207] /* winRad.abs.coeRefExtPan1[1,1] PARAM */) = (data->simulationInfo->realParameter[208] /* winRad.abs.coeRefExtPan1[2,1] PARAM */);
#line 2702 OMC_FILE
  TRACE_POP
}

/*
equation index: 216
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[11,1] = 1.0
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[217] /* winRad.abs.coeRefExtPan1[11,1] PARAM */) = 1.0;
#line 2717 OMC_FILE
  TRACE_POP
}

/*
equation index: 217
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[10,1] = 0.6052446087035255
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[216] /* winRad.abs.coeRefExtPan1[10,1] PARAM */) = 0.6052446087035255;
#line 2732 OMC_FILE
  TRACE_POP
}

/*
equation index: 218
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[9,1] = 0.3612313008417883
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[215] /* winRad.abs.coeRefExtPan1[9,1] PARAM */) = 0.3612313008417883;
#line 2747 OMC_FILE
  TRACE_POP
}

/*
equation index: 219
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[8,1] = 0.2247377823311878
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[214] /* winRad.abs.coeRefExtPan1[8,1] PARAM */) = 0.2247377823311878;
#line 2762 OMC_FILE
  TRACE_POP
}

/*
equation index: 220
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[7,1] = 0.1628935363465329
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[213] /* winRad.abs.coeRefExtPan1[7,1] PARAM */) = 0.1628935363465329;
#line 2777 OMC_FILE
  TRACE_POP
}

/*
equation index: 221
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[6,1] = 0.1382440338153747
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[212] /* winRad.abs.coeRefExtPan1[6,1] PARAM */) = 0.1382440338153747;
#line 2792 OMC_FILE
  TRACE_POP
}

/*
equation index: 222
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[5,1] = 0.1297280574286503
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[211] /* winRad.abs.coeRefExtPan1[5,1] PARAM */) = 0.1297280574286503;
#line 2807 OMC_FILE
  TRACE_POP
}

/*
equation index: 223
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[4,1] = 0.1275322917190642
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[210] /* winRad.abs.coeRefExtPan1[4,1] PARAM */) = 0.1275322917190642;
#line 2822 OMC_FILE
  TRACE_POP
}

/*
equation index: 224
type: SIMPLE_ASSIGN
winRad.abs.coeRefExtPan1[3,1] = 0.1273615206111159
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
#line 109 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/AbsorbedRadiation.mo"
  (data->simulationInfo->realParameter[209] /* winRad.abs.coeRefExtPan1[3,1] PARAM */) = 0.1273615206111159;
#line 2837 OMC_FILE
  TRACE_POP
}

/*
equation index: 225
type: SIMPLE_ASSIGN
winRad.tra.traCoeRoo[1] = 0.5777675151140318
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
#line 69 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/TransmittedRadiation.mo"
  (data->simulationInfo->realParameter[1313] /* winRad.tra.traCoeRoo[1] PARAM */) = 0.5777675151140318;
#line 2852 OMC_FILE
  TRACE_POP
}

/*
equation index: 229
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0), "In WinRadCustomWea.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTimMin.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  modelica_boolean tmp65;
  static const MMC_DEFSTRINGLIT(tmp66,131,"In WinRadCustomWea.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp67;
  modelica_metatype tmpMeta68;
  static const MMC_DEFSTRINGLIT(tmp69,22," exceeds the end time ");
  modelica_metatype tmpMeta70;
  modelica_string tmp71;
  modelica_metatype tmpMeta72;
  static const MMC_DEFSTRINGLIT(tmp73,26," of the weather data file.");
  modelica_metatype tmpMeta74;
  static int tmp75 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp65 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[97] /* weaDat.conTimMin.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp65))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp67 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta68 = stringAppend(MMC_REFSTRINGLIT(tmp66),tmp67);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta70 = stringAppend(tmpMeta68,MMC_REFSTRINGLIT(tmp69));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp71 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[97] /* weaDat.conTimMin.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta72 = stringAppend(tmpMeta70,tmp71);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta74 = stringAppend(tmpMeta72,MMC_REFSTRINGLIT(tmp73));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time - weaDat.conTimMin.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta74));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta74));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2924 OMC_FILE
  TRACE_POP
}

/*
equation index: 228
type: ALGORITHM

  assert(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim), "In WinRadCustomWea.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTimMin.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  modelica_boolean tmp76;
  static const MMC_DEFSTRINGLIT(tmp77,131,"In WinRadCustomWea.weaDat.conTimMin: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp78;
  modelica_metatype tmpMeta79;
  static const MMC_DEFSTRINGLIT(tmp80,29," is less than the start time ");
  modelica_metatype tmpMeta81;
  modelica_string tmp82;
  modelica_metatype tmpMeta83;
  static const MMC_DEFSTRINGLIT(tmp84,26," of the weather data file.");
  modelica_metatype tmpMeta85;
  static int tmp86 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp76 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[98] /* weaDat.conTimMin.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) || tmp76))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp78 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta79 = stringAppend(MMC_REFSTRINGLIT(tmp77),tmp78);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta81 = stringAppend(tmpMeta79,MMC_REFSTRINGLIT(tmp80));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp82 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[98] /* weaDat.conTimMin.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta83 = stringAppend(tmpMeta81,tmp82);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta85 = stringAppend(tmpMeta83,MMC_REFSTRINGLIT(tmp84));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTimMin.canRepeatWeatherFile or noEvent(time >= weaDat.conTimMin.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta85));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta85));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 2996 OMC_FILE
  TRACE_POP
}

/*
equation index: 227
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0), "In WinRadCustomWea.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " exceeds the end time " + String(weaDat.conTim.weaDatEndTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  modelica_boolean tmp87;
  static const MMC_DEFSTRINGLIT(tmp88,128,"In WinRadCustomWea.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp89;
  modelica_metatype tmpMeta90;
  static const MMC_DEFSTRINGLIT(tmp91,22," exceeds the end time ");
  modelica_metatype tmpMeta92;
  modelica_string tmp93;
  modelica_metatype tmpMeta94;
  static const MMC_DEFSTRINGLIT(tmp95,26," of the weather data file.");
  modelica_metatype tmpMeta96;
  static int tmp97 = 0;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp87 = Less(data->localData[0]->timeValue - (data->simulationInfo->realParameter[94] /* weaDat.conTim.weaDatEndTim PARAM */),1800.0);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp87))
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp89 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta90 = stringAppend(MMC_REFSTRINGLIT(tmp88),tmp89);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta92 = stringAppend(tmpMeta90,MMC_REFSTRINGLIT(tmp91));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp93 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[94] /* weaDat.conTim.weaDatEndTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta94 = stringAppend(tmpMeta92,tmp93);
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta96 = stringAppend(tmpMeta94,MMC_REFSTRINGLIT(tmp95));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time - weaDat.conTim.weaDatEndTim < 1800.0))";
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta96));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",40,3,44,26,0};
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta96));
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 40 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 3068 OMC_FILE
  TRACE_POP
}

/*
equation index: 226
type: ALGORITHM

  assert(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim), "In WinRadCustomWea.weaDat.conTim: Insufficient weather data provided for the desired simulation period.
    The simulation time " + String(time, 6, 0, true) + " is less than the start time " + String(weaDat.conTim.weaDatStaTim, 6, 0, true) + " of the weather data file.");
*/
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  modelica_boolean tmp98;
  static const MMC_DEFSTRINGLIT(tmp99,128,"In WinRadCustomWea.weaDat.conTim: Insufficient weather data provided for the desired simulation period.\n    The simulation time ");
  modelica_string tmp100;
  modelica_metatype tmpMeta101;
  static const MMC_DEFSTRINGLIT(tmp102,29," is less than the start time ");
  modelica_metatype tmpMeta103;
  modelica_string tmp104;
  modelica_metatype tmpMeta105;
  static const MMC_DEFSTRINGLIT(tmp106,26," of the weather data file.");
  modelica_metatype tmpMeta107;
  static int tmp108 = 0;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    tmp98 = GreaterEq(data->localData[0]->timeValue,(data->simulationInfo->realParameter[95] /* weaDat.conTim.weaDatStaTim PARAM */));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    if(!((data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) || tmp98))
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp100 = modelica_real_to_modelica_string(data->localData[0]->timeValue, ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta101 = stringAppend(MMC_REFSTRINGLIT(tmp99),tmp100);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta103 = stringAppend(tmpMeta101,MMC_REFSTRINGLIT(tmp102));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmp104 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[95] /* weaDat.conTim.weaDatStaTim PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta105 = stringAppend(tmpMeta103,tmp104);
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      tmpMeta107 = stringAppend(tmpMeta105,MMC_REFSTRINGLIT(tmp106));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        const char* assert_cond = "(weaDat.conTim.canRepeatWeatherFile or noEvent(time >= weaDat.conTim.weaDatStaTim))";
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta107));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          data->simulationInfo->needToReThrow = 1;
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        } else {
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo",46,3,50,26,0};
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta107));
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
        }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
      }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
    }
#line 46 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  }
#line 3140 OMC_FILE
  TRACE_POP
}
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_1(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_2(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_3(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_4(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_5(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_6(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_7(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_8(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_9(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_10(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_11(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_12(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_230(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_239(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_15(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_242(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_243(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_246(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_248(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_256(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_257(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_22(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_262(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_281(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_25(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_26(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_284(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_28(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_286(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_247(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_249(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_244(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_345(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_346(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_344(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_343(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_342(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_341(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_340(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_339(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_338(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_337(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_336(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_334(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_335(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_333(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_326(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_327(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_49(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_330(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_322(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_323(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_53(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_320(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_321(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_316(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_317(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_58(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_315(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_314(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_313(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_312(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_311(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_310(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_309(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_294(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_295(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_68(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_290(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_291(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_287(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_288(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_292(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_74(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_332(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_76(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_84(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_263(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_264(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_280(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_88(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_89(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_90(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_265(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_92(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_266(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_267(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_245(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_250(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_251(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_98(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_99(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_100(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_101(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_102(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_103(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_104(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_105(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_106(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_107(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_108(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_109(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_110(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_111(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_112(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_113(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_114(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_115(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_116(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_117(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_118(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_119(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_120(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_121(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_122(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_123(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_124(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_125(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_126(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_127(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_128(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_129(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_130(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_131(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_132(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_133(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_134(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_135(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_136(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_137(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_138(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_139(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_140(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_141(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_142(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_143(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_144(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_145(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_146(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_147(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_148(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_149(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_150(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_151(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_152(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_153(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_154(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_155(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_156(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_157(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_158(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_159(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_160(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_161(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_162(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_163(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_164(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_165(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_166(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_167(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_168(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_169(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_170(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_171(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_172(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_252(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_174(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_175(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_253(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_254(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_255(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_179(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_278(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_276(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_277(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_279(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_184(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_185(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_186(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_187(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_188(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_189(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_190(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_191(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_192(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_193(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_194(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_195(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_196(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_197(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_198(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_199(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_200(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_201(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_202(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_203(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_204(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_205(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_206(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_207(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_274(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_209(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_210(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_211(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_212(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_213(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_214(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_215(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_216(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_217(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_218(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_219(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_220(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_221(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_222(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_223(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_224(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_225(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_229(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_228(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_227(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_eqFunction_226(data, threadData);
  TRACE_POP
}

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionInitialEquations_lambda0 function */

int Buildings_HeatTransfer_Windows_Examples_WinRadCustomWea_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

