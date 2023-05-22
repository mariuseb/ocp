#ifdef OMC_BASE_FILE
  #define OMC_FILE OMC_BASE_FILE
#else
  #define OMC_FILE "/home/marius/fmu_test/buildopt/test/Buildings.HeatTransfer.Windows.Examples.WinRadCustom/Buildings_HeatTransfer_Windows_Examples_WinRadCustom.fmutmp/sources/Buildings_HeatTransfer_Windows_Examples_WinRadCustom_08bnd.c"
#endif
/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "Buildings_HeatTransfer_Windows_Examples_WinRadCustom_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}

void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 343
type: SIMPLE_ASSIGN
weaDat.lat = Buildings.BoundaryConditions.WeatherData.BaseClasses.getLatitudeTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos"))
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_343(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,343};
#line 228 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[102] /* weaDat.lat PARAM */) = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLatitudeTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT32));
#line 53 OMC_FILE
  TRACE_POP
}

/*
equation index: 344
type: SIMPLE_ASSIGN
weaDat.latitude.latitude = weaDat.lat
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,344};
#line 436 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */) = (data->simulationInfo->realParameter[102] /* weaDat.lat PARAM */);
#line 69 OMC_FILE
  TRACE_POP
}

/*
equation index: 345
type: SIMPLE_ASSIGN
$cse6 = cos(weaDat.latitude.latitude)
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,345};
  (data->simulationInfo->realParameter[0] /* $cse6 PARAM */) = cos((data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */));
  TRACE_POP
}

/*
equation index: 346
type: SIMPLE_ASSIGN
$cse9 = sin(weaDat.latitude.latitude)
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,346};
  (data->simulationInfo->realParameter[1] /* $cse9 PARAM */) = sin((data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */));
  TRACE_POP
}

/*
equation index: 347
type: SIMPLE_ASSIGN
weaDat.datRea.tableID = Modelica.Blocks.Types.ExternalCombiTable1D.constructor("tab1", if OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos") <> "NoName" and not Modelica.Utilities.Strings.isEmpty(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos")) then OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos") else "NoName", {}, {2, 3, 4, 5, 6, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 8}, Modelica.Blocks.Types.Smoothness.ContinuousDerivative, Modelica.Blocks.Types.Extrapolation.LastTwoPoints, false)
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,347};
#line 43 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->extObjs[0]) = omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData, _OMC_LIT33, (((!stringEqual(OpenModelica__fmuLoadResource(_OMC_LIT32), _OMC_LIT34)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, OpenModelica__fmuLoadResource(_OMC_LIT32))))?OpenModelica__fmuLoadResource(_OMC_LIT32):_OMC_LIT34), _OMC_LIT35, _OMC_LIT36, 2, 2, 0);
#line 113 OMC_FILE
  TRACE_POP
}

/*
equation index: 348
type: SIMPLE_ASSIGN
weaDat.datRea30Min.tableID = Modelica.Blocks.Types.ExternalCombiTable1D.constructor("tab1", if OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos") <> "NoName" and not Modelica.Utilities.Strings.isEmpty(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos")) then OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos") else "NoName", {}, {9, 10, 11}, Modelica.Blocks.Types.Smoothness.ContinuousDerivative, Modelica.Blocks.Types.Extrapolation.LastTwoPoints, false)
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,348};
#line 43 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->extObjs[1]) = omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData, _OMC_LIT33, (((!stringEqual(OpenModelica__fmuLoadResource(_OMC_LIT32), _OMC_LIT34)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, OpenModelica__fmuLoadResource(_OMC_LIT32))))?OpenModelica__fmuLoadResource(_OMC_LIT32):_OMC_LIT34), _OMC_LIT35, _OMC_LIT37, 2, 2, 0);
#line 129 OMC_FILE
  TRACE_POP
}

/*
equation index: 349
type: SIMPLE_ASSIGN
weaDat.lon = Buildings.BoundaryConditions.WeatherData.BaseClasses.getLongitudeTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos"))
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,349};
#line 225 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[108] /* weaDat.lon PARAM */) = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getLongitudeTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT32));
#line 145 OMC_FILE
  TRACE_POP
}

/*
equation index: 350
type: SIMPLE_ASSIGN
weaDat.longitude.longitude = weaDat.lon
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,350};
#line 480 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[109] /* weaDat.longitude.longitude PARAM */) = (data->simulationInfo->realParameter[108] /* weaDat.lon PARAM */);
#line 161 OMC_FILE
  TRACE_POP
}

/*
equation index: 351
type: SIMPLE_ASSIGN
HDirTil.incAng.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[22] /* HDirTil.incAng.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[109] /* weaDat.longitude.longitude PARAM */);
#line 177 OMC_FILE
  TRACE_POP
}

/*
equation index: 352
type: SIMPLE_ASSIGN
HDirTil.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[26] /* HDirTil.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[109] /* weaDat.longitude.longitude PARAM */);
#line 193 OMC_FILE
  TRACE_POP
}

/*
equation index: 353
type: SIMPLE_ASSIGN
HDifTilIso.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[13] /* HDifTilIso.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[109] /* weaDat.longitude.longitude PARAM */);
#line 209 OMC_FILE
  TRACE_POP
}

/*
equation index: 354
type: SIMPLE_ASSIGN
weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[69] /* weaBus.lon PARAM */) = (data->simulationInfo->realParameter[109] /* weaDat.longitude.longitude PARAM */);
#line 225 OMC_FILE
  TRACE_POP
}

/*
equation index: 355
type: SIMPLE_ASSIGN
weaDat.weaBus.lon = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,355};
#line 854 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[124] /* weaDat.weaBus.lon PARAM */) = (data->simulationInfo->realParameter[109] /* weaDat.longitude.longitude PARAM */);
#line 241 OMC_FILE
  TRACE_POP
}

/*
equation index: 356
type: SIMPLE_ASSIGN
weaDat.longitude.y = weaDat.longitude.longitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_356(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,356};
#line 482 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[110] /* weaDat.longitude.y PARAM */) = (data->simulationInfo->realParameter[109] /* weaDat.longitude.longitude PARAM */);
#line 257 OMC_FILE
  TRACE_POP
}

/*
equation index: 357
type: SIMPLE_ASSIGN
weaDat.alt = Buildings.BoundaryConditions.WeatherData.BaseClasses.getAltitudeLocationTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos"))
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_357(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,357};
#line 234 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[79] /* weaDat.alt PARAM */) = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getAltitudeLocationTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT32));
#line 273 OMC_FILE
  TRACE_POP
}

/*
equation index: 358
type: SIMPLE_ASSIGN
weaDat.altitude.Altitude = weaDat.alt
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_358(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,358};
#line 524 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[80] /* weaDat.altitude.Altitude PARAM */) = (data->simulationInfo->realParameter[79] /* weaDat.alt PARAM */);
#line 289 OMC_FILE
  TRACE_POP
}

/*
equation index: 359
type: SIMPLE_ASSIGN
HDirTil.incAng.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_359(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,359};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[20] /* HDirTil.incAng.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[80] /* weaDat.altitude.Altitude PARAM */);
#line 305 OMC_FILE
  TRACE_POP
}

/*
equation index: 360
type: SIMPLE_ASSIGN
HDirTil.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_360(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,360};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[24] /* HDirTil.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[80] /* weaDat.altitude.Altitude PARAM */);
#line 321 OMC_FILE
  TRACE_POP
}

/*
equation index: 361
type: SIMPLE_ASSIGN
HDifTilIso.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_361(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,361};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[11] /* HDifTilIso.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[80] /* weaDat.altitude.Altitude PARAM */);
#line 337 OMC_FILE
  TRACE_POP
}

/*
equation index: 362
type: SIMPLE_ASSIGN
weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_362(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,362};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[67] /* weaBus.alt PARAM */) = (data->simulationInfo->realParameter[80] /* weaDat.altitude.Altitude PARAM */);
#line 353 OMC_FILE
  TRACE_POP
}

/*
equation index: 363
type: SIMPLE_ASSIGN
weaDat.weaBus.alt = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_363(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,363};
#line 860 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[122] /* weaDat.weaBus.alt PARAM */) = (data->simulationInfo->realParameter[80] /* weaDat.altitude.Altitude PARAM */);
#line 369 OMC_FILE
  TRACE_POP
}

/*
equation index: 364
type: SIMPLE_ASSIGN
weaDat.altitude.y = weaDat.altitude.Altitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_364(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,364};
#line 527 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[81] /* weaDat.altitude.y PARAM */) = (data->simulationInfo->realParameter[80] /* weaDat.altitude.Altitude PARAM */);
#line 385 OMC_FILE
  TRACE_POP
}

/*
equation index: 365
type: SIMPLE_ASSIGN
HDirTil.incAng.incAng.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_365(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,365};
#line 19 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/IncidenceAngle.mo"
  (data->simulationInfo->realParameter[17] /* HDirTil.incAng.incAng.lat PARAM */) = (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */);
#line 401 OMC_FILE
  TRACE_POP
}

/*
equation index: 366
type: SIMPLE_ASSIGN
HDirTil.incAng.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_366(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,366};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[21] /* HDirTil.incAng.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */);
#line 417 OMC_FILE
  TRACE_POP
}

/*
equation index: 367
type: SIMPLE_ASSIGN
HDirTil.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,367};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[25] /* HDirTil.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */);
#line 433 OMC_FILE
  TRACE_POP
}

/*
equation index: 368
type: SIMPLE_ASSIGN
HDifTilIso.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_368(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,368};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[12] /* HDifTilIso.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */);
#line 449 OMC_FILE
  TRACE_POP
}

/*
equation index: 369
type: SIMPLE_ASSIGN
weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_369(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,369};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[68] /* weaBus.lat PARAM */) = (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */);
#line 465 OMC_FILE
  TRACE_POP
}

/*
equation index: 370
type: SIMPLE_ASSIGN
weaDat.weaBus.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_370(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,370};
#line 857 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[123] /* weaDat.weaBus.lat PARAM */) = (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */);
#line 481 OMC_FILE
  TRACE_POP
}

/*
equation index: 371
type: SIMPLE_ASSIGN
weaDat.zenAng.lat = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_371(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,371};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarGeometry/BaseClasses/ZenithAngle.mo"
  (data->simulationInfo->realParameter[129] /* weaDat.zenAng.lat PARAM */) = (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */);
#line 497 OMC_FILE
  TRACE_POP
}

/*
equation index: 372
type: SIMPLE_ASSIGN
weaDat.latitude.y = weaDat.latitude.latitude
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_372(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,372};
#line 438 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[104] /* weaDat.latitude.y PARAM */) = (data->simulationInfo->realParameter[103] /* weaDat.latitude.latitude PARAM */);
#line 513 OMC_FILE
  TRACE_POP
}

/*
equation index: 1499
type: SIMPLE_ASSIGN
weaDat.timeSpan[1] = Buildings.BoundaryConditions.WeatherData.BaseClasses.getTimeSpanTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos"), "tab1")[1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1499(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1499};
#line 239 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[118] /* weaDat.timeSpan[1] PARAM */) = real_get(omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT32), _OMC_LIT33), 0);
#line 529 OMC_FILE
  TRACE_POP
}

/*
equation index: 1500
type: SIMPLE_ASSIGN
weaDat.conTim.weaDatStaTim = weaDat.timeSpan[1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1500(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1500};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[93] /* weaDat.conTim.weaDatStaTim PARAM */) = (data->simulationInfo->realParameter[118] /* weaDat.timeSpan[1] PARAM */);
#line 545 OMC_FILE
  TRACE_POP
}

/*
equation index: 1501
type: SIMPLE_ASSIGN
weaDat.timeSpan[2] = Buildings.BoundaryConditions.WeatherData.BaseClasses.getTimeSpanTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos"), "tab1")[2]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1501(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1501};
#line 239 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[119] /* weaDat.timeSpan[2] PARAM */) = real_get(omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeSpanTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT32), _OMC_LIT33), 1);
#line 561 OMC_FILE
  TRACE_POP
}

/*
equation index: 1502
type: SIMPLE_ASSIGN
weaDat.conTim.weaDatEndTim = weaDat.timeSpan[2]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1502(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1502};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[92] /* weaDat.conTim.weaDatEndTim PARAM */) = (data->simulationInfo->realParameter[119] /* weaDat.timeSpan[2] PARAM */);
#line 577 OMC_FILE
  TRACE_POP
}

/*
equation index: 1503
type: SIMPLE_ASSIGN
weaDat.conTim.lenWea = weaDat.conTim.weaDatEndTim - weaDat.conTim.weaDatStaTim
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1503(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1503};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[91] /* weaDat.conTim.lenWea PARAM */) = (data->simulationInfo->realParameter[92] /* weaDat.conTim.weaDatEndTim PARAM */) - (data->simulationInfo->realParameter[93] /* weaDat.conTim.weaDatStaTim PARAM */);
#line 593 OMC_FILE
  TRACE_POP
}

/*
equation index: 1504
type: SIMPLE_ASSIGN
weaDat.conTim.canRepeatWeatherFile = abs(mod(weaDat.conTim.lenWea, 31536000.0)) < 0.01
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1504(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1504};
  modelica_real tmp2;
  modelica_boolean tmp3;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp2 = 31536000.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(weaDat.conTim.lenWea, 31536000.0)");}
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp3 = Less(fabs(modelica_real_mod((data->simulationInfo->realParameter[91] /* weaDat.conTim.lenWea PARAM */), tmp2)),0.01);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->booleanParameter[8] /* weaDat.conTim.canRepeatWeatherFile PARAM */) = tmp3;
#line 617 OMC_FILE
  TRACE_POP
}

/*
equation index: 1505
type: SIMPLE_ASSIGN
weaDat.conTimMin.weaDatStaTim = weaDat.timeSpan[1]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1505};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[96] /* weaDat.conTimMin.weaDatStaTim PARAM */) = (data->simulationInfo->realParameter[118] /* weaDat.timeSpan[1] PARAM */);
#line 633 OMC_FILE
  TRACE_POP
}

/*
equation index: 1506
type: SIMPLE_ASSIGN
weaDat.conTimMin.weaDatEndTim = weaDat.timeSpan[2]
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1506};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[95] /* weaDat.conTimMin.weaDatEndTim PARAM */) = (data->simulationInfo->realParameter[119] /* weaDat.timeSpan[2] PARAM */);
#line 649 OMC_FILE
  TRACE_POP
}

/*
equation index: 1507
type: SIMPLE_ASSIGN
weaDat.conTimMin.lenWea = weaDat.conTimMin.weaDatEndTim - weaDat.conTimMin.weaDatStaTim
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1507};
#line 23 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->realParameter[94] /* weaDat.conTimMin.lenWea PARAM */) = (data->simulationInfo->realParameter[95] /* weaDat.conTimMin.weaDatEndTim PARAM */) - (data->simulationInfo->realParameter[96] /* weaDat.conTimMin.weaDatStaTim PARAM */);
#line 665 OMC_FILE
  TRACE_POP
}

/*
equation index: 1508
type: SIMPLE_ASSIGN
weaDat.conTimMin.canRepeatWeatherFile = abs(mod(weaDat.conTimMin.lenWea, 31536000.0)) < 0.01
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1508};
  modelica_real tmp4;
  modelica_boolean tmp5;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp4 = 31536000.0;
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(weaDat.conTimMin.lenWea, 31536000.0)");}
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  tmp5 = Less(fabs(modelica_real_mod((data->simulationInfo->realParameter[94] /* weaDat.conTimMin.lenWea PARAM */), tmp4)),0.01);
#line 26 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/ConvertTime.mo"
  (data->simulationInfo->booleanParameter[9] /* weaDat.conTimMin.canRepeatWeatherFile PARAM */) = tmp5;
#line 689 OMC_FILE
  TRACE_POP
}

/*
equation index: 1509
type: SIMPLE_ASSIGN
weaDat.datRea30Min.u_max = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmax(weaDat.datRea30Min.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1509};
#line 40 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->realParameter[99] /* weaDat.datRea30Min.u_max PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData, (data->simulationInfo->extObjs[1]));
#line 705 OMC_FILE
  TRACE_POP
}

/*
equation index: 1510
type: SIMPLE_ASSIGN
weaDat.datRea30Min.u_min = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmin(weaDat.datRea30Min.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1510(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1510};
#line 38 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->realParameter[100] /* weaDat.datRea30Min.u_min PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData, (data->simulationInfo->extObjs[1]));
#line 721 OMC_FILE
  TRACE_POP
}

/*
equation index: 1518
type: SIMPLE_ASSIGN
weaDat.datRea30Min.fileName = OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos")
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1518};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->stringParameter[2] /* weaDat.datRea30Min.fileName PARAM */) = OpenModelica__fmuLoadResource(_OMC_LIT32);
#line 737 OMC_FILE
  TRACE_POP
}

/*
equation index: 1519
type: SIMPLE_ASSIGN
weaDat.datRea30Min.tableName = "tab1"
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1519};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->stringParameter[3] /* weaDat.datRea30Min.tableName PARAM */) = _OMC_LIT33;
#line 753 OMC_FILE
  TRACE_POP
}

/*
equation index: 1522
type: SIMPLE_ASSIGN
weaDat.timZon = Buildings.BoundaryConditions.WeatherData.BaseClasses.getTimeZoneTMY3(OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos"))
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1522};
#line 231 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->realParameter[117] /* weaDat.timZon PARAM */) = omc_Buildings_BoundaryConditions_WeatherData_BaseClasses_getTimeZoneTMY3(threadData, OpenModelica__fmuLoadResource(_OMC_LIT32));
#line 769 OMC_FILE
  TRACE_POP
}

/*
equation index: 1523
type: SIMPLE_ASSIGN
weaDat.locTim.timZon = weaDat.timZon
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1523};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->simulationInfo->realParameter[107] /* weaDat.locTim.timZon PARAM */) = (data->simulationInfo->realParameter[117] /* weaDat.timZon PARAM */);
#line 785 OMC_FILE
  TRACE_POP
}

/*
equation index: 1524
type: SIMPLE_ASSIGN
weaDat.locTim.lon = weaDat.lon
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1524};
#line 9 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->simulationInfo->realParameter[106] /* weaDat.locTim.lon PARAM */) = (data->simulationInfo->realParameter[108] /* weaDat.lon PARAM */);
#line 801 OMC_FILE
  TRACE_POP
}

/*
equation index: 1525
type: SIMPLE_ASSIGN
weaDat.locTim.diff = 13750.98708313976 * weaDat.locTim.lon - weaDat.locTim.timZon
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1525};
#line 15 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/LocalCivilTime.mo"
  (data->simulationInfo->realParameter[105] /* weaDat.locTim.diff PARAM */) = (13750.98708313976) * ((data->simulationInfo->realParameter[106] /* weaDat.locTim.lon PARAM */)) - (data->simulationInfo->realParameter[107] /* weaDat.locTim.timZon PARAM */);
#line 817 OMC_FILE
  TRACE_POP
}

/*
equation index: 1556
type: SIMPLE_ASSIGN
weaDat.datRea.u_max = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmax(weaDat.datRea.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1556};
#line 40 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->realParameter[97] /* weaDat.datRea.u_max PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData, (data->simulationInfo->extObjs[0]));
#line 833 OMC_FILE
  TRACE_POP
}

/*
equation index: 1557
type: SIMPLE_ASSIGN
weaDat.datRea.u_min = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmin(weaDat.datRea.tableID)
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1557};
#line 38 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->realParameter[98] /* weaDat.datRea.u_min PARAM */) = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData, (data->simulationInfo->extObjs[0]));
#line 849 OMC_FILE
  TRACE_POP
}

/*
equation index: 1588
type: SIMPLE_ASSIGN
weaDat.datRea.fileName = OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos")
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1588};
#line 17 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->stringParameter[0] /* weaDat.datRea.fileName PARAM */) = OpenModelica__fmuLoadResource(_OMC_LIT32);
#line 865 OMC_FILE
  TRACE_POP
}

/*
equation index: 1589
type: SIMPLE_ASSIGN
weaDat.datRea.tableName = "tab1"
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1589(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1589};
#line 14 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  (data->simulationInfo->stringParameter[1] /* weaDat.datRea.tableName PARAM */) = _OMC_LIT33;
#line 881 OMC_FILE
  TRACE_POP
}

/*
equation index: 1617
type: SIMPLE_ASSIGN
weaDat.filNam = OpenModelica_fmuLoadResource("/home/marius/modelica-buildings/Buildings/Resources/weatherdata/USA_IL_Chicago-OHare.Intl.AP.725300_TMY3.mos")
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1617(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1617};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  (data->simulationInfo->stringParameter[4] /* weaDat.filNam PARAM */) = OpenModelica__fmuLoadResource(_OMC_LIT32);
#line 897 OMC_FILE
  TRACE_POP
}
extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_185(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_184(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_183(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_14(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_13(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_12(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_11(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_10(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_9(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_8(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_7(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_6(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_5(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_4(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_3(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_2(DATA *data, threadData_t *threadData);

extern void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1(DATA *data, threadData_t *threadData);


/*
equation index: 1686
type: ALGORITHM

  assert(winRad.staIntQTraDir_flow.NSta >= 1, "Variable violating min constraint: 1 <= winRad.staIntQTraDir_flow.NSta, has value: " + String(winRad.staIntQTraDir_flow.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1686(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1686};
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,83,"Variable violating min constraint: 1 <= winRad.staIntQTraDir_flow.NSta, has value: ");
  modelica_string tmp8;
  modelica_metatype tmpMeta9;
  static int tmp10 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  if(!tmp10)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    tmp6 = GreaterEq((data->simulationInfo->integerParameter[81] /* winRad.staIntQTraDir_flow.NSta PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    if(!tmp6)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp8 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[81] /* winRad.staIntQTraDir_flow.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmpMeta9 = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        const char* assert_cond = "(winRad.staIntQTraDir_flow.NSta >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta9));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp10 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  }
#line 991 OMC_FILE
  TRACE_POP
}

/*
equation index: 1687
type: ALGORITHM

  assert(winRad.staIntQTraDif_flow.NSta >= 1, "Variable violating min constraint: 1 <= winRad.staIntQTraDif_flow.NSta, has value: " + String(winRad.staIntQTraDif_flow.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1687(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1687};
  modelica_boolean tmp11;
  static const MMC_DEFSTRINGLIT(tmp12,83,"Variable violating min constraint: 1 <= winRad.staIntQTraDif_flow.NSta, has value: ");
  modelica_string tmp13;
  modelica_metatype tmpMeta14;
  static int tmp15 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  if(!tmp15)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    tmp11 = GreaterEq((data->simulationInfo->integerParameter[80] /* winRad.staIntQTraDif_flow.NSta PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    if(!tmp11)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp13 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[80] /* winRad.staIntQTraDif_flow.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmpMeta14 = stringAppend(MMC_REFSTRINGLIT(tmp12),tmp13);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        const char* assert_cond = "(winRad.staIntQTraDif_flow.NSta >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta14));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp15 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  }
#line 1051 OMC_FILE
  TRACE_POP
}

/*
equation index: 1688
type: ALGORITHM

  assert(winRad.staIntQAbsIntSha_flow.NSta >= 1, "Variable violating min constraint: 1 <= winRad.staIntQAbsIntSha_flow.NSta, has value: " + String(winRad.staIntQAbsIntSha_flow.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1688(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1688};
  modelica_boolean tmp16;
  static const MMC_DEFSTRINGLIT(tmp17,86,"Variable violating min constraint: 1 <= winRad.staIntQAbsIntSha_flow.NSta, has value: ");
  modelica_string tmp18;
  modelica_metatype tmpMeta19;
  static int tmp20 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  if(!tmp20)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    tmp16 = GreaterEq((data->simulationInfo->integerParameter[79] /* winRad.staIntQAbsIntSha_flow.NSta PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    if(!tmp16)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp18 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[79] /* winRad.staIntQAbsIntSha_flow.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmpMeta19 = stringAppend(MMC_REFSTRINGLIT(tmp17),tmp18);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        const char* assert_cond = "(winRad.staIntQAbsIntSha_flow.NSta >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta19));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta19));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp20 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  }
#line 1111 OMC_FILE
  TRACE_POP
}

/*
equation index: 1689
type: ALGORITHM

  assert(winRad.staIntQAbsGlaSha_flow[2].NSta >= 1, "Variable violating min constraint: 1 <= winRad.staIntQAbsGlaSha_flow[2].NSta, has value: " + String(winRad.staIntQAbsGlaSha_flow[2].NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1689(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1689};
  modelica_boolean tmp21;
  static const MMC_DEFSTRINGLIT(tmp22,89,"Variable violating min constraint: 1 <= winRad.staIntQAbsGlaSha_flow[2].NSta, has value: ");
  modelica_string tmp23;
  modelica_metatype tmpMeta24;
  static int tmp25 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  if(!tmp25)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    tmp21 = GreaterEq((data->simulationInfo->integerParameter[76] /* winRad.staIntQAbsGlaSha_flow[2].NSta PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    if(!tmp21)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp23 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[76] /* winRad.staIntQAbsGlaSha_flow[2].NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmpMeta24 = stringAppend(MMC_REFSTRINGLIT(tmp22),tmp23);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        const char* assert_cond = "(winRad.staIntQAbsGlaSha_flow[2].NSta >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta24));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta24));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp25 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  }
#line 1171 OMC_FILE
  TRACE_POP
}

/*
equation index: 1690
type: ALGORITHM

  assert(winRad.staIntQAbsGlaSha_flow[1].NSta >= 1, "Variable violating min constraint: 1 <= winRad.staIntQAbsGlaSha_flow[1].NSta, has value: " + String(winRad.staIntQAbsGlaSha_flow[1].NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1690(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1690};
  modelica_boolean tmp26;
  static const MMC_DEFSTRINGLIT(tmp27,89,"Variable violating min constraint: 1 <= winRad.staIntQAbsGlaSha_flow[1].NSta, has value: ");
  modelica_string tmp28;
  modelica_metatype tmpMeta29;
  static int tmp30 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  if(!tmp30)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    tmp26 = GreaterEq((data->simulationInfo->integerParameter[75] /* winRad.staIntQAbsGlaSha_flow[1].NSta PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    if(!tmp26)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp28 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[75] /* winRad.staIntQAbsGlaSha_flow[1].NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmpMeta29 = stringAppend(MMC_REFSTRINGLIT(tmp27),tmp28);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        const char* assert_cond = "(winRad.staIntQAbsGlaSha_flow[1].NSta >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta29));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta29));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp30 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  }
#line 1231 OMC_FILE
  TRACE_POP
}

/*
equation index: 1691
type: ALGORITHM

  assert(winRad.staIntQAbsGlaUns_flow[2].NSta >= 1, "Variable violating min constraint: 1 <= winRad.staIntQAbsGlaUns_flow[2].NSta, has value: " + String(winRad.staIntQAbsGlaUns_flow[2].NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1691(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1691};
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,89,"Variable violating min constraint: 1 <= winRad.staIntQAbsGlaUns_flow[2].NSta, has value: ");
  modelica_string tmp33;
  modelica_metatype tmpMeta34;
  static int tmp35 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  if(!tmp35)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    tmp31 = GreaterEq((data->simulationInfo->integerParameter[78] /* winRad.staIntQAbsGlaUns_flow[2].NSta PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    if(!tmp31)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp33 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[78] /* winRad.staIntQAbsGlaUns_flow[2].NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmpMeta34 = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        const char* assert_cond = "(winRad.staIntQAbsGlaUns_flow[2].NSta >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta34));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta34));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp35 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  }
#line 1291 OMC_FILE
  TRACE_POP
}

/*
equation index: 1692
type: ALGORITHM

  assert(winRad.staIntQAbsGlaUns_flow[1].NSta >= 1, "Variable violating min constraint: 1 <= winRad.staIntQAbsGlaUns_flow[1].NSta, has value: " + String(winRad.staIntQAbsGlaUns_flow[1].NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1692(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1692};
  modelica_boolean tmp36;
  static const MMC_DEFSTRINGLIT(tmp37,89,"Variable violating min constraint: 1 <= winRad.staIntQAbsGlaUns_flow[1].NSta, has value: ");
  modelica_string tmp38;
  modelica_metatype tmpMeta39;
  static int tmp40 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  if(!tmp40)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    tmp36 = GreaterEq((data->simulationInfo->integerParameter[77] /* winRad.staIntQAbsGlaUns_flow[1].NSta PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    if(!tmp36)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp38 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[77] /* winRad.staIntQAbsGlaUns_flow[1].NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmpMeta39 = stringAppend(MMC_REFSTRINGLIT(tmp37),tmp38);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        const char* assert_cond = "(winRad.staIntQAbsGlaUns_flow[1].NSta >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta39));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta39));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp40 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  }
#line 1351 OMC_FILE
  TRACE_POP
}

/*
equation index: 1693
type: ALGORITHM

  assert(winRad.staIntQAbsExtSha_flow.NSta >= 1, "Variable violating min constraint: 1 <= winRad.staIntQAbsExtSha_flow.NSta, has value: " + String(winRad.staIntQAbsExtSha_flow.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1693(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1693};
  modelica_boolean tmp41;
  static const MMC_DEFSTRINGLIT(tmp42,86,"Variable violating min constraint: 1 <= winRad.staIntQAbsExtSha_flow.NSta, has value: ");
  modelica_string tmp43;
  modelica_metatype tmpMeta44;
  static int tmp45 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  if(!tmp45)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    tmp41 = GreaterEq((data->simulationInfo->integerParameter[74] /* winRad.staIntQAbsExtSha_flow.NSta PARAM */),((modelica_integer) 1));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    if(!tmp41)
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp43 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[74] /* winRad.staIntQAbsExtSha_flow.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmpMeta44 = stringAppend(MMC_REFSTRINGLIT(tmp42),tmp43);
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        const char* assert_cond = "(winRad.staIntQAbsExtSha_flow.NSta >= 1)";
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta44));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo",5,3,7,31,0};
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta44));
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
      tmp45 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/StateInterpolator.mo"
  }
#line 1411 OMC_FILE
  TRACE_POP
}

/*
equation index: 1694
type: ALGORITHM

  assert(winRad.abs.radDat.NSta >= 1, "Variable violating min constraint: 1 <= winRad.abs.radDat.NSta, has value: " + String(winRad.abs.radDat.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1694(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1694};
  modelica_boolean tmp46;
  static const MMC_DEFSTRINGLIT(tmp47,75,"Variable violating min constraint: 1 <= winRad.abs.radDat.NSta, has value: ");
  modelica_string tmp48;
  modelica_metatype tmpMeta49;
  static int tmp50 = 0;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp50)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp46 = GreaterEq((data->simulationInfo->integerParameter[69] /* winRad.abs.radDat.NSta PARAM */),((modelica_integer) 1));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp46)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp48 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[69] /* winRad.abs.radDat.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta49 = stringAppend(MMC_REFSTRINGLIT(tmp47),tmp48);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.abs.radDat.NSta >= 1)";
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta49));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta49));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp50 = 1;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1471 OMC_FILE
  TRACE_POP
}

/*
equation index: 1695
type: ALGORITHM

  assert(winRad.abs.radDat.N >= 1, "Variable violating min constraint: 1 <= winRad.abs.radDat.N, has value: " + String(winRad.abs.radDat.N, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1695(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1695};
  modelica_boolean tmp51;
  static const MMC_DEFSTRINGLIT(tmp52,72,"Variable violating min constraint: 1 <= winRad.abs.radDat.N, has value: ");
  modelica_string tmp53;
  modelica_metatype tmpMeta54;
  static int tmp55 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp55)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp51 = GreaterEq((data->simulationInfo->integerParameter[67] /* winRad.abs.radDat.N PARAM */),((modelica_integer) 1));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp51)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp53 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[67] /* winRad.abs.radDat.N PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta54 = stringAppend(MMC_REFSTRINGLIT(tmp52),tmp53);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.abs.radDat.N >= 1)";
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta54));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta54));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp55 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1531 OMC_FILE
  TRACE_POP
}

/*
equation index: 1696
type: ALGORITHM

  assert(winRad.abs.NSta >= 1, "Variable violating min constraint: 1 <= winRad.abs.NSta, has value: " + String(winRad.abs.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1696(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1696};
  modelica_boolean tmp56;
  static const MMC_DEFSTRINGLIT(tmp57,68,"Variable violating min constraint: 1 <= winRad.abs.NSta, has value: ");
  modelica_string tmp58;
  modelica_metatype tmpMeta59;
  static int tmp60 = 0;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp60)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp56 = GreaterEq((data->simulationInfo->integerParameter[65] /* winRad.abs.NSta PARAM */),((modelica_integer) 1));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp56)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp58 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[65] /* winRad.abs.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta59 = stringAppend(MMC_REFSTRINGLIT(tmp57),tmp58);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.abs.NSta >= 1)";
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta59));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta59));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp60 = 1;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1591 OMC_FILE
  TRACE_POP
}

/*
equation index: 1697
type: ALGORITHM

  assert(winRad.abs.N >= 1, "Variable violating min constraint: 1 <= winRad.abs.N, has value: " + String(winRad.abs.N, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1697(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1697};
  modelica_boolean tmp61;
  static const MMC_DEFSTRINGLIT(tmp62,65,"Variable violating min constraint: 1 <= winRad.abs.N, has value: ");
  modelica_string tmp63;
  modelica_metatype tmpMeta64;
  static int tmp65 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp65)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp61 = GreaterEq((data->simulationInfo->integerParameter[63] /* winRad.abs.N PARAM */),((modelica_integer) 1));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp61)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp63 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[63] /* winRad.abs.N PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta64 = stringAppend(MMC_REFSTRINGLIT(tmp62),tmp63);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.abs.N >= 1)";
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta64));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta64));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp65 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1651 OMC_FILE
  TRACE_POP
}

/*
equation index: 1698
type: ALGORITHM

  assert(winRad.tra.radDat.NSta >= 1, "Variable violating min constraint: 1 <= winRad.tra.radDat.NSta, has value: " + String(winRad.tra.radDat.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1698(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1698};
  modelica_boolean tmp66;
  static const MMC_DEFSTRINGLIT(tmp67,75,"Variable violating min constraint: 1 <= winRad.tra.radDat.NSta, has value: ");
  modelica_string tmp68;
  modelica_metatype tmpMeta69;
  static int tmp70 = 0;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp70)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp66 = GreaterEq((data->simulationInfo->integerParameter[89] /* winRad.tra.radDat.NSta PARAM */),((modelica_integer) 1));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp66)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp68 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[89] /* winRad.tra.radDat.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta69 = stringAppend(MMC_REFSTRINGLIT(tmp67),tmp68);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.tra.radDat.NSta >= 1)";
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta69));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta69));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp70 = 1;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1711 OMC_FILE
  TRACE_POP
}

/*
equation index: 1699
type: ALGORITHM

  assert(winRad.tra.radDat.N >= 1, "Variable violating min constraint: 1 <= winRad.tra.radDat.N, has value: " + String(winRad.tra.radDat.N, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1699(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1699};
  modelica_boolean tmp71;
  static const MMC_DEFSTRINGLIT(tmp72,72,"Variable violating min constraint: 1 <= winRad.tra.radDat.N, has value: ");
  modelica_string tmp73;
  modelica_metatype tmpMeta74;
  static int tmp75 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp75)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp71 = GreaterEq((data->simulationInfo->integerParameter[87] /* winRad.tra.radDat.N PARAM */),((modelica_integer) 1));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp71)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp73 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[87] /* winRad.tra.radDat.N PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta74 = stringAppend(MMC_REFSTRINGLIT(tmp72),tmp73);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.tra.radDat.N >= 1)";
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta74));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta74));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp75 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1771 OMC_FILE
  TRACE_POP
}

/*
equation index: 1700
type: ALGORITHM

  assert(winRad.tra.NSta >= 1, "Variable violating min constraint: 1 <= winRad.tra.NSta, has value: " + String(winRad.tra.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1700(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1700};
  modelica_boolean tmp76;
  static const MMC_DEFSTRINGLIT(tmp77,68,"Variable violating min constraint: 1 <= winRad.tra.NSta, has value: ");
  modelica_string tmp78;
  modelica_metatype tmpMeta79;
  static int tmp80 = 0;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp80)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp76 = GreaterEq((data->simulationInfo->integerParameter[85] /* winRad.tra.NSta PARAM */),((modelica_integer) 1));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp76)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp78 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[85] /* winRad.tra.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta79 = stringAppend(MMC_REFSTRINGLIT(tmp77),tmp78);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.tra.NSta >= 1)";
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta79));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta79));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp80 = 1;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1831 OMC_FILE
  TRACE_POP
}

/*
equation index: 1701
type: ALGORITHM

  assert(winRad.tra.N >= 1, "Variable violating min constraint: 1 <= winRad.tra.N, has value: " + String(winRad.tra.N, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1701(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1701};
  modelica_boolean tmp81;
  static const MMC_DEFSTRINGLIT(tmp82,65,"Variable violating min constraint: 1 <= winRad.tra.N, has value: ");
  modelica_string tmp83;
  modelica_metatype tmpMeta84;
  static int tmp85 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp85)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp81 = GreaterEq((data->simulationInfo->integerParameter[83] /* winRad.tra.N PARAM */),((modelica_integer) 1));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp81)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp83 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[83] /* winRad.tra.N PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta84 = stringAppend(MMC_REFSTRINGLIT(tmp82),tmp83);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.tra.N >= 1)";
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta84));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta84));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp85 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1891 OMC_FILE
  TRACE_POP
}

/*
equation index: 1702
type: ALGORITHM

  assert(winRad.radDat.NSta >= 1, "Variable violating min constraint: 1 <= winRad.radDat.NSta, has value: " + String(winRad.radDat.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1702(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1702};
  modelica_boolean tmp86;
  static const MMC_DEFSTRINGLIT(tmp87,71,"Variable violating min constraint: 1 <= winRad.radDat.NSta, has value: ");
  modelica_string tmp88;
  modelica_metatype tmpMeta89;
  static int tmp90 = 0;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp90)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp86 = GreaterEq((data->simulationInfo->integerParameter[73] /* winRad.radDat.NSta PARAM */),((modelica_integer) 1));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp86)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp88 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[73] /* winRad.radDat.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta89 = stringAppend(MMC_REFSTRINGLIT(tmp87),tmp88);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.radDat.NSta >= 1)";
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta89));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta89));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp90 = 1;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 1951 OMC_FILE
  TRACE_POP
}

/*
equation index: 1703
type: ALGORITHM

  assert(winRad.radDat.N >= 1, "Variable violating min constraint: 1 <= winRad.radDat.N, has value: " + String(winRad.radDat.N, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1703(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1703};
  modelica_boolean tmp91;
  static const MMC_DEFSTRINGLIT(tmp92,68,"Variable violating min constraint: 1 <= winRad.radDat.N, has value: ");
  modelica_string tmp93;
  modelica_metatype tmpMeta94;
  static int tmp95 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp95)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp91 = GreaterEq((data->simulationInfo->integerParameter[71] /* winRad.radDat.N PARAM */),((modelica_integer) 1));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp91)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp93 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[71] /* winRad.radDat.N PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta94 = stringAppend(MMC_REFSTRINGLIT(tmp92),tmp93);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.radDat.N >= 1)";
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta94));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta94));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp95 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 2011 OMC_FILE
  TRACE_POP
}

/*
equation index: 1704
type: ALGORITHM

  assert(winRad.NSta >= 1, "Variable violating min constraint: 1 <= winRad.NSta, has value: " + String(winRad.NSta, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1704(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1704};
  modelica_boolean tmp96;
  static const MMC_DEFSTRINGLIT(tmp97,64,"Variable violating min constraint: 1 <= winRad.NSta, has value: ");
  modelica_string tmp98;
  modelica_metatype tmpMeta99;
  static int tmp100 = 0;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp100)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp96 = GreaterEq((data->simulationInfo->integerParameter[61] /* winRad.NSta PARAM */),((modelica_integer) 1));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp96)
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp98 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[61] /* winRad.NSta PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta99 = stringAppend(MMC_REFSTRINGLIT(tmp97),tmp98);
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.NSta >= 1)";
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta99));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",10,3,12,31,0};
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta99));
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp100 = 1;
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 10 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 2071 OMC_FILE
  TRACE_POP
}

/*
equation index: 1705
type: ALGORITHM

  assert(winRad.N >= 1, "Variable violating min constraint: 1 <= winRad.N, has value: " + String(winRad.N, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1705(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1705};
  modelica_boolean tmp101;
  static const MMC_DEFSTRINGLIT(tmp102,61,"Variable violating min constraint: 1 <= winRad.N, has value: ");
  modelica_string tmp103;
  modelica_metatype tmpMeta104;
  static int tmp105 = 0;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  if(!tmp105)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    tmp101 = GreaterEq((data->simulationInfo->integerParameter[60] /* winRad.N PARAM */),((modelica_integer) 1));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    if(!tmp101)
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp103 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[60] /* winRad.N PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmpMeta104 = stringAppend(MMC_REFSTRINGLIT(tmp102),tmp103);
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        const char* assert_cond = "(winRad.N >= 1)";
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta104));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        } else {
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo",7,3,8,39,0};
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta104));
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
        }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
      tmp105 = 1;
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
    }
#line 7 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Windows/BaseClasses/RadiationBaseData.mo"
  }
#line 2131 OMC_FILE
  TRACE_POP
}

/*
equation index: 1706
type: ALGORITHM

  assert(weaDat.cheTemBlaSky.TMax >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemBlaSky.TMax, has value: " + String(weaDat.cheTemBlaSky.TMax, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1706(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1706};
  modelica_boolean tmp106;
  static const MMC_DEFSTRINGLIT(tmp107,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemBlaSky.TMax, has value: ");
  modelica_string tmp108;
  modelica_metatype tmpMeta109;
  static int tmp110 = 0;
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  if(!tmp110)
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp106 = GreaterEq((data->simulationInfo->realParameter[84] /* weaDat.cheTemBlaSky.TMax PARAM */),0.0);
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    if(!tmp106)
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp108 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[84] /* weaDat.cheTemBlaSky.TMax PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmpMeta109 = stringAppend(MMC_REFSTRINGLIT(tmp107),tmp108);
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemBlaSky.TMax >= 0.0)";
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",8,3,9,34,0};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta109));
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        } else {
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",8,3,9,34,0};
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta109));
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        }
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      }
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp110 = 1;
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    }
#line 8 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  }
#line 2191 OMC_FILE
  TRACE_POP
}

/*
equation index: 1707
type: ALGORITHM

  assert(weaDat.cheTemBlaSky.TMin >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemBlaSky.TMin, has value: " + String(weaDat.cheTemBlaSky.TMin, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1707(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1707};
  modelica_boolean tmp111;
  static const MMC_DEFSTRINGLIT(tmp112,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemBlaSky.TMin, has value: ");
  modelica_string tmp113;
  modelica_metatype tmpMeta114;
  static int tmp115 = 0;
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  if(!tmp115)
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    tmp111 = GreaterEq((data->simulationInfo->realParameter[85] /* weaDat.cheTemBlaSky.TMin PARAM */),0.0);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    if(!tmp111)
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp113 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[85] /* weaDat.cheTemBlaSky.TMin PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmpMeta114 = stringAppend(MMC_REFSTRINGLIT(tmp112),tmp113);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemBlaSky.TMin >= 0.0)";
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",6,3,7,34,0};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta114));
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        } else {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo",6,3,7,34,0};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta114));
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
        }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
      tmp115 = 1;
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
    }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckBlackBodySkyTemperature.mo"
  }
#line 2251 OMC_FILE
  TRACE_POP
}

/*
equation index: 1708
type: ALGORITHM

  assert(weaDat.datRea30Min.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and weaDat.datRea30Min.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= weaDat.datRea30Min.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(weaDat.datRea30Min.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1708(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1708};
  modelica_boolean tmp116;
  modelica_boolean tmp117;
  static const MMC_DEFSTRINGLIT(tmp118,192,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= weaDat.datRea30Min.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp119;
  modelica_metatype tmpMeta120;
  static int tmp121 = 0;
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  if(!tmp121)
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp116 = GreaterEq((data->simulationInfo->integerParameter[43] /* weaDat.datRea30Min.extrapolation PARAM */),1);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp117 = LessEq((data->simulationInfo->integerParameter[43] /* weaDat.datRea30Min.extrapolation PARAM */),4);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    if(!(tmp116 && tmp117))
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp119 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[43] /* weaDat.datRea30Min.extrapolation PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmpMeta120 = stringAppend(MMC_REFSTRINGLIT(tmp118),tmp119);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        const char* assert_cond = "(weaDat.datRea30Min.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and weaDat.datRea30Min.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation)";
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",32,5,34,61,0};
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta120));
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        } else {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",32,5,34,61,0};
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta120));
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp121 = 1;
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  }
#line 2314 OMC_FILE
  TRACE_POP
}

/*
equation index: 1709
type: ALGORITHM

  assert(weaDat.datRea30Min.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and weaDat.datRea30Min.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= weaDat.datRea30Min.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: " + String(weaDat.datRea30Min.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1709(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1709};
  modelica_boolean tmp122;
  modelica_boolean tmp123;
  static const MMC_DEFSTRINGLIT(tmp124,197,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= weaDat.datRea30Min.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: ");
  modelica_string tmp125;
  modelica_metatype tmpMeta126;
  static int tmp127 = 0;
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  if(!tmp127)
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp122 = GreaterEq((data->simulationInfo->integerParameter[45] /* weaDat.datRea30Min.smoothness PARAM */),1);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp123 = LessEq((data->simulationInfo->integerParameter[45] /* weaDat.datRea30Min.smoothness PARAM */),6);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    if(!(tmp122 && tmp123))
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp125 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[45] /* weaDat.datRea30Min.smoothness PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmpMeta126 = stringAppend(MMC_REFSTRINGLIT(tmp124),tmp125);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        const char* assert_cond = "(weaDat.datRea30Min.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and weaDat.datRea30Min.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative)";
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",29,5,31,61,0};
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta126));
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        } else {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",29,5,31,61,0};
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta126));
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp127 = 1;
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  }
#line 2377 OMC_FILE
  TRACE_POP
}

/*
equation index: 1710
type: ALGORITHM

  assert(weaDat.cheTemDewPoi.TMax >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemDewPoi.TMax, has value: " + String(weaDat.cheTemDewPoi.TMax, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1710(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1710};
  modelica_boolean tmp128;
  static const MMC_DEFSTRINGLIT(tmp129,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemDewPoi.TMax, has value: ");
  modelica_string tmp130;
  modelica_metatype tmpMeta131;
  static int tmp132 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  if(!tmp132)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp128 = GreaterEq((data->simulationInfo->realParameter[86] /* weaDat.cheTemDewPoi.TMax PARAM */),0.0);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    if(!tmp128)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp130 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[86] /* weaDat.cheTemDewPoi.TMax PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmpMeta131 = stringAppend(MMC_REFSTRINGLIT(tmp129),tmp130);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemDewPoi.TMax >= 0.0)";
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",18,3,19,34,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta131));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",18,3,19,34,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta131));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp132 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  }
#line 2437 OMC_FILE
  TRACE_POP
}

/*
equation index: 1711
type: ALGORITHM

  assert(weaDat.cheTemDewPoi.TMin >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemDewPoi.TMin, has value: " + String(weaDat.cheTemDewPoi.TMin, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1711(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1711};
  modelica_boolean tmp133;
  static const MMC_DEFSTRINGLIT(tmp134,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemDewPoi.TMin, has value: ");
  modelica_string tmp135;
  modelica_metatype tmpMeta136;
  static int tmp137 = 0;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  if(!tmp137)
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    tmp133 = GreaterEq((data->simulationInfo->realParameter[87] /* weaDat.cheTemDewPoi.TMin PARAM */),0.0);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    if(!tmp133)
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp135 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[87] /* weaDat.cheTemDewPoi.TMin PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmpMeta136 = stringAppend(MMC_REFSTRINGLIT(tmp134),tmp135);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemDewPoi.TMin >= 0.0)";
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",16,3,17,34,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta136));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo",16,3,17,34,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta136));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
        }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
      tmp137 = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDewPointTemperature.mo"
  }
#line 2497 OMC_FILE
  TRACE_POP
}

/*
equation index: 1712
type: ALGORITHM

  assert(weaDat.cheTemDryBul.TMax >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemDryBul.TMax, has value: " + String(weaDat.cheTemDryBul.TMax, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1712(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1712};
  modelica_boolean tmp138;
  static const MMC_DEFSTRINGLIT(tmp139,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemDryBul.TMax, has value: ");
  modelica_string tmp140;
  modelica_metatype tmpMeta141;
  static int tmp142 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  if(!tmp142)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp138 = GreaterEq((data->simulationInfo->realParameter[88] /* weaDat.cheTemDryBul.TMax PARAM */),0.0);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    if(!tmp138)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp140 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[88] /* weaDat.cheTemDryBul.TMax PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmpMeta141 = stringAppend(MMC_REFSTRINGLIT(tmp139),tmp140);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemDryBul.TMax >= 0.0)";
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",18,3,19,34,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta141));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",18,3,19,34,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta141));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp142 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  }
#line 2557 OMC_FILE
  TRACE_POP
}

/*
equation index: 1713
type: ALGORITHM

  assert(weaDat.cheTemDryBul.TMin >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.cheTemDryBul.TMin, has value: " + String(weaDat.cheTemDryBul.TMin, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1713(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1713};
  modelica_boolean tmp143;
  static const MMC_DEFSTRINGLIT(tmp144,79,"Variable violating min constraint: 0.0 <= weaDat.cheTemDryBul.TMin, has value: ");
  modelica_string tmp145;
  modelica_metatype tmpMeta146;
  static int tmp147 = 0;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  if(!tmp147)
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    tmp143 = GreaterEq((data->simulationInfo->realParameter[89] /* weaDat.cheTemDryBul.TMin PARAM */),0.0);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    if(!tmp143)
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp145 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[89] /* weaDat.cheTemDryBul.TMin PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmpMeta146 = stringAppend(MMC_REFSTRINGLIT(tmp144),tmp145);
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        const char* assert_cond = "(weaDat.cheTemDryBul.TMin >= 0.0)";
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",16,3,17,34,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta146));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        } else {
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo",16,3,17,34,0};
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta146));
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
        }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
      tmp147 = 1;
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
    }
#line 16 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/CheckDryBulbTemperature.mo"
  }
#line 2617 OMC_FILE
  TRACE_POP
}

/*
equation index: 1714
type: ALGORITHM

  assert(weaDat.souSelRad.datSou >= Buildings.BoundaryConditions.Types.RadiationDataSource.File and weaDat.souSelRad.datSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.RadiationDataSource.File <= weaDat.souSelRad.datSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, has value: " + String(weaDat.souSelRad.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1714(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1714};
  modelica_boolean tmp148;
  modelica_boolean tmp149;
  static const MMC_DEFSTRINGLIT(tmp150,218,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.RadiationDataSource.File <= weaDat.souSelRad.datSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, has value: ");
  modelica_string tmp151;
  modelica_metatype tmpMeta152;
  static int tmp153 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
  if(!tmp153)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    tmp148 = GreaterEq((data->simulationInfo->integerParameter[53] /* weaDat.souSelRad.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    tmp149 = LessEq((data->simulationInfo->integerParameter[53] /* weaDat.souSelRad.datSou PARAM */),4);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    if(!(tmp148 && tmp149))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      tmp151 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[53] /* weaDat.souSelRad.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      tmpMeta152 = stringAppend(MMC_REFSTRINGLIT(tmp150),tmp151);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
        const char* assert_cond = "(weaDat.souSelRad.datSou >= Buildings.BoundaryConditions.Types.RadiationDataSource.File and weaDat.souSelRad.datSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta152));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta152));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
      tmp153 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelectorRadiation.mo"
  }
#line 2680 OMC_FILE
  TRACE_POP
}

/*
equation index: 1715
type: ALGORITHM

  assert(weaDat.horInfRadSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.horInfRadSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.horInfRadSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.horInfRadSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1715(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1715};
  modelica_boolean tmp154;
  modelica_boolean tmp155;
  static const MMC_DEFSTRINGLIT(tmp156,187,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.horInfRadSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp157;
  modelica_metatype tmpMeta158;
  static int tmp159 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp159)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp154 = GreaterEq((data->simulationInfo->integerParameter[46] /* weaDat.horInfRadSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp155 = LessEq((data->simulationInfo->integerParameter[46] /* weaDat.horInfRadSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp154 && tmp155))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp157 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[46] /* weaDat.horInfRadSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta158 = stringAppend(MMC_REFSTRINGLIT(tmp156),tmp157);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.horInfRadSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.horInfRadSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta158));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta158));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp159 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 2743 OMC_FILE
  TRACE_POP
}

/*
equation index: 1716
type: ALGORITHM

  assert(weaDat.winDirSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winDirSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winDirSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.winDirSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1716(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1716};
  modelica_boolean tmp160;
  modelica_boolean tmp161;
  static const MMC_DEFSTRINGLIT(tmp162,184,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winDirSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp163;
  modelica_metatype tmpMeta164;
  static int tmp165 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp165)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp160 = GreaterEq((data->simulationInfo->integerParameter[56] /* weaDat.winDirSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp161 = LessEq((data->simulationInfo->integerParameter[56] /* weaDat.winDirSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp160 && tmp161))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp163 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[56] /* weaDat.winDirSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta164 = stringAppend(MMC_REFSTRINGLIT(tmp162),tmp163);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.winDirSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winDirSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta164));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta164));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp165 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 2806 OMC_FILE
  TRACE_POP
}

/*
equation index: 1717
type: ALGORITHM

  assert(weaDat.winSpeSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winSpeSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winSpeSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.winSpeSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1717(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1717};
  modelica_boolean tmp166;
  modelica_boolean tmp167;
  static const MMC_DEFSTRINGLIT(tmp168,184,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winSpeSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp169;
  modelica_metatype tmpMeta170;
  static int tmp171 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp171)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp166 = GreaterEq((data->simulationInfo->integerParameter[58] /* weaDat.winSpeSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp167 = LessEq((data->simulationInfo->integerParameter[58] /* weaDat.winSpeSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp166 && tmp167))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp169 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[58] /* weaDat.winSpeSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta170 = stringAppend(MMC_REFSTRINGLIT(tmp168),tmp169);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.winSpeSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winSpeSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta170));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta170));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp171 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 2869 OMC_FILE
  TRACE_POP
}

/*
equation index: 1718
type: ALGORITHM

  assert(weaDat.totSkyCovSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.totSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.totSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.totSkyCovSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1718(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1718};
  modelica_boolean tmp172;
  modelica_boolean tmp173;
  static const MMC_DEFSTRINGLIT(tmp174,187,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.totSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp175;
  modelica_metatype tmpMeta176;
  static int tmp177 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp177)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp172 = GreaterEq((data->simulationInfo->integerParameter[54] /* weaDat.totSkyCovSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp173 = LessEq((data->simulationInfo->integerParameter[54] /* weaDat.totSkyCovSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp172 && tmp173))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp175 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[54] /* weaDat.totSkyCovSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta176 = stringAppend(MMC_REFSTRINGLIT(tmp174),tmp175);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.totSkyCovSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.totSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta176));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta176));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp177 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 2932 OMC_FILE
  TRACE_POP
}

/*
equation index: 1719
type: ALGORITHM

  assert(weaDat.ceiHeiSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.ceiHeiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.ceiHeiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.ceiHeiSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1719(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1719};
  modelica_boolean tmp178;
  modelica_boolean tmp179;
  static const MMC_DEFSTRINGLIT(tmp180,184,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.ceiHeiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp181;
  modelica_metatype tmpMeta182;
  static int tmp183 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp183)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp178 = GreaterEq((data->simulationInfo->integerParameter[9] /* weaDat.ceiHeiSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp179 = LessEq((data->simulationInfo->integerParameter[9] /* weaDat.ceiHeiSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp178 && tmp179))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp181 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[9] /* weaDat.ceiHeiSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta182 = stringAppend(MMC_REFSTRINGLIT(tmp180),tmp181);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.ceiHeiSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.ceiHeiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta182));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta182));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp183 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 2995 OMC_FILE
  TRACE_POP
}

/*
equation index: 1720
type: ALGORITHM

  assert(weaDat.opaSkyCovSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.opaSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.opaSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.opaSkyCovSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1720(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1720};
  modelica_boolean tmp184;
  modelica_boolean tmp185;
  static const MMC_DEFSTRINGLIT(tmp186,187,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.opaSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp187;
  modelica_metatype tmpMeta188;
  static int tmp189 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp189)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp184 = GreaterEq((data->simulationInfo->integerParameter[47] /* weaDat.opaSkyCovSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp185 = LessEq((data->simulationInfo->integerParameter[47] /* weaDat.opaSkyCovSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp184 && tmp185))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp187 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[47] /* weaDat.opaSkyCovSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta188 = stringAppend(MMC_REFSTRINGLIT(tmp186),tmp187);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.opaSkyCovSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.opaSkyCovSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta188));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta188));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp189 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 3058 OMC_FILE
  TRACE_POP
}

/*
equation index: 1721
type: ALGORITHM

  assert(weaDat.relHumSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.relHumSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.relHumSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.relHumSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1721(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1721};
  modelica_boolean tmp190;
  modelica_boolean tmp191;
  static const MMC_DEFSTRINGLIT(tmp192,184,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.relHumSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp193;
  modelica_metatype tmpMeta194;
  static int tmp195 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp195)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp190 = GreaterEq((data->simulationInfo->integerParameter[51] /* weaDat.relHumSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp191 = LessEq((data->simulationInfo->integerParameter[51] /* weaDat.relHumSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp190 && tmp191))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp193 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[51] /* weaDat.relHumSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta194 = stringAppend(MMC_REFSTRINGLIT(tmp192),tmp193);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.relHumSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.relHumSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta194));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta194));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp195 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 3121 OMC_FILE
  TRACE_POP
}

/*
equation index: 1722
type: ALGORITHM

  assert(weaDat.TBlaSkySel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TBlaSkySel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TBlaSkySel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TBlaSkySel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1722(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1722};
  modelica_boolean tmp196;
  modelica_boolean tmp197;
  static const MMC_DEFSTRINGLIT(tmp198,185,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TBlaSkySel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp199;
  modelica_metatype tmpMeta200;
  static int tmp201 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp201)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp196 = GreaterEq((data->simulationInfo->integerParameter[2] /* weaDat.TBlaSkySel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp197 = LessEq((data->simulationInfo->integerParameter[2] /* weaDat.TBlaSkySel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp196 && tmp197))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp199 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[2] /* weaDat.TBlaSkySel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta200 = stringAppend(MMC_REFSTRINGLIT(tmp198),tmp199);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.TBlaSkySel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TBlaSkySel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta200));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta200));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp201 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 3184 OMC_FILE
  TRACE_POP
}

/*
equation index: 1723
type: ALGORITHM

  assert(weaDat.TDryBulSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDryBulSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDryBulSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TDryBulSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1723(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1723};
  modelica_boolean tmp202;
  modelica_boolean tmp203;
  static const MMC_DEFSTRINGLIT(tmp204,185,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDryBulSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp205;
  modelica_metatype tmpMeta206;
  static int tmp207 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp207)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp202 = GreaterEq((data->simulationInfo->integerParameter[6] /* weaDat.TDryBulSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp203 = LessEq((data->simulationInfo->integerParameter[6] /* weaDat.TDryBulSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp202 && tmp203))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp205 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[6] /* weaDat.TDryBulSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta206 = stringAppend(MMC_REFSTRINGLIT(tmp204),tmp205);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.TDryBulSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDryBulSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta206));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta206));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp207 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 3247 OMC_FILE
  TRACE_POP
}

/*
equation index: 1724
type: ALGORITHM

  assert(weaDat.TDewPoiSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDewPoiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDewPoiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TDewPoiSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1724(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1724};
  modelica_boolean tmp208;
  modelica_boolean tmp209;
  static const MMC_DEFSTRINGLIT(tmp210,185,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDewPoiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp211;
  modelica_metatype tmpMeta212;
  static int tmp213 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp213)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp208 = GreaterEq((data->simulationInfo->integerParameter[4] /* weaDat.TDewPoiSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp209 = LessEq((data->simulationInfo->integerParameter[4] /* weaDat.TDewPoiSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp208 && tmp209))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp211 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[4] /* weaDat.TDewPoiSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta212 = stringAppend(MMC_REFSTRINGLIT(tmp210),tmp211);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.TDewPoiSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDewPoiSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta212));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta212));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp213 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 3310 OMC_FILE
  TRACE_POP
}

/*
equation index: 1725
type: ALGORITHM

  assert(weaDat.pAtmSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.pAtmSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.pAtmSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.pAtmSel.datSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1725(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1725};
  modelica_boolean tmp214;
  modelica_boolean tmp215;
  static const MMC_DEFSTRINGLIT(tmp216,182,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.pAtmSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp217;
  modelica_metatype tmpMeta218;
  static int tmp219 = 0;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  if(!tmp219)
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp214 = GreaterEq((data->simulationInfo->integerParameter[49] /* weaDat.pAtmSel.datSou PARAM */),1);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    tmp215 = LessEq((data->simulationInfo->integerParameter[49] /* weaDat.pAtmSel.datSou PARAM */),3);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    if(!(tmp214 && tmp215))
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp217 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[49] /* weaDat.pAtmSel.datSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmpMeta218 = stringAppend(MMC_REFSTRINGLIT(tmp216),tmp217);
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        const char* assert_cond = "(weaDat.pAtmSel.datSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.pAtmSel.datSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta218));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        } else {
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo",5,3,6,30,0};
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta218));
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
        }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
      tmp219 = 1;
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
    }
#line 5 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/BaseClasses/SourceSelector.mo"
  }
#line 3373 OMC_FILE
  TRACE_POP
}

/*
equation index: 1726
type: ALGORITHM

  assert(weaDat.datRea.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and weaDat.datRea.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= weaDat.datRea.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(weaDat.datRea.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1726(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1726};
  modelica_boolean tmp220;
  modelica_boolean tmp221;
  static const MMC_DEFSTRINGLIT(tmp222,187,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= weaDat.datRea.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp223;
  modelica_metatype tmpMeta224;
  static int tmp225 = 0;
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  if(!tmp225)
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp220 = GreaterEq((data->simulationInfo->integerParameter[37] /* weaDat.datRea.extrapolation PARAM */),1);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp221 = LessEq((data->simulationInfo->integerParameter[37] /* weaDat.datRea.extrapolation PARAM */),4);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    if(!(tmp220 && tmp221))
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp223 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[37] /* weaDat.datRea.extrapolation PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmpMeta224 = stringAppend(MMC_REFSTRINGLIT(tmp222),tmp223);
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        const char* assert_cond = "(weaDat.datRea.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and weaDat.datRea.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation)";
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",32,5,34,61,0};
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta224));
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        } else {
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",32,5,34,61,0};
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta224));
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp225 = 1;
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    }
#line 32 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  }
#line 3436 OMC_FILE
  TRACE_POP
}

/*
equation index: 1727
type: ALGORITHM

  assert(weaDat.datRea.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and weaDat.datRea.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= weaDat.datRea.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: " + String(weaDat.datRea.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1727(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1727};
  modelica_boolean tmp226;
  modelica_boolean tmp227;
  static const MMC_DEFSTRINGLIT(tmp228,192,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= weaDat.datRea.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative, has value: ");
  modelica_string tmp229;
  modelica_metatype tmpMeta230;
  static int tmp231 = 0;
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  if(!tmp231)
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp226 = GreaterEq((data->simulationInfo->integerParameter[39] /* weaDat.datRea.smoothness PARAM */),1);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    tmp227 = LessEq((data->simulationInfo->integerParameter[39] /* weaDat.datRea.smoothness PARAM */),6);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    if(!(tmp226 && tmp227))
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp229 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[39] /* weaDat.datRea.smoothness PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmpMeta230 = stringAppend(MMC_REFSTRINGLIT(tmp228),tmp229);
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        const char* assert_cond = "(weaDat.datRea.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and weaDat.datRea.smoothness <= Modelica.Blocks.Types.Smoothness.ModifiedContinuousDerivative)";
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",29,5,31,61,0};
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta230));
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        } else {
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          FILE_INFO info = {"/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo",29,5,31,61,0};
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta230));
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
        }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
      tmp231 = 1;
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
    }
#line 29 "/home/marius/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Tables.mo"
  }
#line 3499 OMC_FILE
  TRACE_POP
}

/*
equation index: 1728
type: ALGORITHM

  assert(weaDat.calTSky >= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation and weaDat.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation <= weaDat.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, has value: " + String(weaDat.calTSky, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1728(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1728};
  modelica_boolean tmp232;
  modelica_boolean tmp233;
  static const MMC_DEFSTRINGLIT(tmp234,238,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation <= weaDat.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover, has value: ");
  modelica_string tmp235;
  modelica_metatype tmpMeta236;
  static int tmp237 = 0;
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp237)
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp232 = GreaterEq((data->simulationInfo->integerParameter[8] /* weaDat.calTSky PARAM */),1);
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp233 = LessEq((data->simulationInfo->integerParameter[8] /* weaDat.calTSky PARAM */),2);
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp232 && tmp233))
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp235 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[8] /* weaDat.calTSky PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta236 = stringAppend(MMC_REFSTRINGLIT(tmp234),tmp235);
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.calTSky >= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.HorizontalRadiation and weaDat.calTSky <= Buildings.BoundaryConditions.Types.SkyTemperatureCalculation.TemperaturesAndSkyCover)";
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",218,3,223,53,0};
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta236));
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",218,3,223,53,0};
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta236));
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp237 = 1;
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 218 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 3562 OMC_FILE
  TRACE_POP
}

/*
equation index: 1729
type: ALGORITHM

  assert(weaDat.opaSkyCov >= 0.0 and weaDat.opaSkyCov <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.opaSkyCov <= 1.0, has value: " + String(weaDat.opaSkyCov, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1729(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1729};
  modelica_boolean tmp238;
  modelica_boolean tmp239;
  static const MMC_DEFSTRINGLIT(tmp240,82,"Variable violating min/max constraint: 0.0 <= weaDat.opaSkyCov <= 1.0, has value: ");
  modelica_string tmp241;
  modelica_metatype tmpMeta242;
  static int tmp243 = 0;
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp243)
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp238 = GreaterEq((data->simulationInfo->realParameter[111] /* weaDat.opaSkyCov PARAM */),0.0);
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp239 = LessEq((data->simulationInfo->realParameter[111] /* weaDat.opaSkyCov PARAM */),1.0);
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp238 && tmp239))
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp241 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[111] /* weaDat.opaSkyCov PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta242 = stringAppend(MMC_REFSTRINGLIT(tmp240),tmp241);
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.opaSkyCov >= 0.0 and weaDat.opaSkyCov <= 1.0)";
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",204,3,209,43,0};
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta242));
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",204,3,209,43,0};
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta242));
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp243 = 1;
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 204 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 3625 OMC_FILE
  TRACE_POP
}

/*
equation index: 1730
type: ALGORITHM

  assert(weaDat.opaSkyCovSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.opaSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.opaSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.opaSkyCovSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1730(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1730};
  modelica_boolean tmp244;
  modelica_boolean tmp245;
  static const MMC_DEFSTRINGLIT(tmp246,180,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.opaSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp247;
  modelica_metatype tmpMeta248;
  static int tmp249 = 0;
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp249)
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp244 = GreaterEq((data->simulationInfo->integerParameter[48] /* weaDat.opaSkyCovSou PARAM */),1);
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp245 = LessEq((data->simulationInfo->integerParameter[48] /* weaDat.opaSkyCovSou PARAM */),3);
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp244 && tmp245))
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp247 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[48] /* weaDat.opaSkyCovSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta248 = stringAppend(MMC_REFSTRINGLIT(tmp246),tmp247);
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.opaSkyCovSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.opaSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",202,3,203,94,0};
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta248));
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",202,3,203,94,0};
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta248));
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp249 = 1;
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 202 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 3688 OMC_FILE
  TRACE_POP
}

/*
equation index: 1731
type: ALGORITHM

  assert(weaDat.totSkyCov >= 0.0 and weaDat.totSkyCov <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.totSkyCov <= 1.0, has value: " + String(weaDat.totSkyCov, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1731(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1731};
  modelica_boolean tmp250;
  modelica_boolean tmp251;
  static const MMC_DEFSTRINGLIT(tmp252,82,"Variable violating min/max constraint: 0.0 <= weaDat.totSkyCov <= 1.0, has value: ");
  modelica_string tmp253;
  modelica_metatype tmpMeta254;
  static int tmp255 = 0;
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp255)
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp250 = GreaterEq((data->simulationInfo->realParameter[120] /* weaDat.totSkyCov PARAM */),0.0);
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp251 = LessEq((data->simulationInfo->realParameter[120] /* weaDat.totSkyCov PARAM */),1.0);
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp250 && tmp251))
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp253 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[120] /* weaDat.totSkyCov PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta254 = stringAppend(MMC_REFSTRINGLIT(tmp252),tmp253);
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.totSkyCov >= 0.0 and weaDat.totSkyCov <= 1.0)";
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",188,3,193,43,0};
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta254));
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",188,3,193,43,0};
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta254));
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp255 = 1;
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 188 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 3751 OMC_FILE
  TRACE_POP
}

/*
equation index: 1732
type: ALGORITHM

  assert(weaDat.totSkyCovSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.totSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.totSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.totSkyCovSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1732(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1732};
  modelica_boolean tmp256;
  modelica_boolean tmp257;
  static const MMC_DEFSTRINGLIT(tmp258,180,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.totSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp259;
  modelica_metatype tmpMeta260;
  static int tmp261 = 0;
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp261)
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp256 = GreaterEq((data->simulationInfo->integerParameter[55] /* weaDat.totSkyCovSou PARAM */),1);
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp257 = LessEq((data->simulationInfo->integerParameter[55] /* weaDat.totSkyCovSou PARAM */),3);
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp256 && tmp257))
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp259 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[55] /* weaDat.totSkyCovSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta260 = stringAppend(MMC_REFSTRINGLIT(tmp258),tmp259);
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.totSkyCovSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.totSkyCovSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",186,3,187,93,0};
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta260));
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",186,3,187,93,0};
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta260));
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp261 = 1;
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 186 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 3814 OMC_FILE
  TRACE_POP
}

/*
equation index: 1733
type: ALGORITHM

  assert(weaDat.ceiHeiSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.ceiHeiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.ceiHeiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.ceiHeiSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1733(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1733};
  modelica_boolean tmp262;
  modelica_boolean tmp263;
  static const MMC_DEFSTRINGLIT(tmp264,177,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.ceiHeiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp265;
  modelica_metatype tmpMeta266;
  static int tmp267 = 0;
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp267)
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp262 = GreaterEq((data->simulationInfo->integerParameter[10] /* weaDat.ceiHeiSou PARAM */),1);
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp263 = LessEq((data->simulationInfo->integerParameter[10] /* weaDat.ceiHeiSou PARAM */),3);
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp262 && tmp263))
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp265 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[10] /* weaDat.ceiHeiSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta266 = stringAppend(MMC_REFSTRINGLIT(tmp264),tmp265);
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.ceiHeiSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.ceiHeiSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",170,3,171,92,0};
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta266));
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",170,3,171,92,0};
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta266));
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp267 = 1;
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 170 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 3877 OMC_FILE
  TRACE_POP
}

/*
equation index: 1734
type: ALGORITHM

  assert(weaDat.HSou >= Buildings.BoundaryConditions.Types.RadiationDataSource.File and weaDat.HSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.RadiationDataSource.File <= weaDat.HSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, has value: " + String(weaDat.HSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1734(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1734};
  modelica_boolean tmp268;
  modelica_boolean tmp269;
  static const MMC_DEFSTRINGLIT(tmp270,206,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.RadiationDataSource.File <= weaDat.HSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor, has value: ");
  modelica_string tmp271;
  modelica_metatype tmpMeta272;
  static int tmp273 = 0;
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp273)
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp268 = GreaterEq((data->simulationInfo->integerParameter[1] /* weaDat.HSou PARAM */),1);
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp269 = LessEq((data->simulationInfo->integerParameter[1] /* weaDat.HSou PARAM */),4);
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp268 && tmp269))
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp271 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[1] /* weaDat.HSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta272 = stringAppend(MMC_REFSTRINGLIT(tmp270),tmp271);
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.HSou >= Buildings.BoundaryConditions.Types.RadiationDataSource.File and weaDat.HSou <= Buildings.BoundaryConditions.Types.RadiationDataSource.Input_HDirNor_HGloHor)";
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",135,4,137,76,0};
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta272));
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",135,4,137,76,0};
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta272));
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp273 = 1;
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 135 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 3940 OMC_FILE
  TRACE_POP
}

/*
equation index: 1735
type: ALGORITHM

  assert(weaDat.HInfHorSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.HInfHorSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.HInfHorSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.HInfHorSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1735(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1735};
  modelica_boolean tmp274;
  modelica_boolean tmp275;
  static const MMC_DEFSTRINGLIT(tmp276,178,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.HInfHorSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp277;
  modelica_metatype tmpMeta278;
  static int tmp279 = 0;
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp279)
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp274 = GreaterEq((data->simulationInfo->integerParameter[0] /* weaDat.HInfHorSou PARAM */),1);
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp275 = LessEq((data->simulationInfo->integerParameter[0] /* weaDat.HInfHorSou PARAM */),3);
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp274 && tmp275))
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp277 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* weaDat.HInfHorSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta278 = stringAppend(MMC_REFSTRINGLIT(tmp276),tmp277);
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.HInfHorSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.HInfHorSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",123,3,124,107,0};
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta278));
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",123,3,124,107,0};
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta278));
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp279 = 1;
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 123 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4003 OMC_FILE
  TRACE_POP
}

/*
equation index: 1736
type: ALGORITHM

  assert(weaDat.winDirSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winDirSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winDirSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.winDirSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1736(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1736};
  modelica_boolean tmp280;
  modelica_boolean tmp281;
  static const MMC_DEFSTRINGLIT(tmp282,177,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winDirSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp283;
  modelica_metatype tmpMeta284;
  static int tmp285 = 0;
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp285)
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp280 = GreaterEq((data->simulationInfo->integerParameter[57] /* weaDat.winDirSou PARAM */),1);
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp281 = LessEq((data->simulationInfo->integerParameter[57] /* weaDat.winDirSou PARAM */),3);
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp280 && tmp281))
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp283 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[57] /* weaDat.winDirSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta284 = stringAppend(MMC_REFSTRINGLIT(tmp282),tmp283);
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.winDirSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winDirSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",109,3,110,92,0};
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta284));
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",109,3,110,92,0};
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta284));
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp285 = 1;
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 109 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4066 OMC_FILE
  TRACE_POP
}

/*
equation index: 1737
type: ALGORITHM

  assert(weaDat.winSpe >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.winSpe, has value: " + String(weaDat.winSpe, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1737(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1737};
  modelica_boolean tmp286;
  static const MMC_DEFSTRINGLIT(tmp287,68,"Variable violating min constraint: 0.0 <= weaDat.winSpe, has value: ");
  modelica_string tmp288;
  modelica_metatype tmpMeta289;
  static int tmp290 = 0;
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp290)
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp286 = GreaterEq((data->simulationInfo->realParameter[127] /* weaDat.winSpe PARAM */),0.0);
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp286)
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp288 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[127] /* weaDat.winSpe PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta289 = stringAppend(MMC_REFSTRINGLIT(tmp287),tmp288);
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.winSpe >= 0.0)";
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",97,3,99,43,0};
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta289));
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",97,3,99,43,0};
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta289));
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp290 = 1;
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 97 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4126 OMC_FILE
  TRACE_POP
}

/*
equation index: 1738
type: ALGORITHM

  assert(weaDat.winSpeSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winSpeSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winSpeSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.winSpeSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1738(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1738};
  modelica_boolean tmp291;
  modelica_boolean tmp292;
  static const MMC_DEFSTRINGLIT(tmp293,177,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.winSpeSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp294;
  modelica_metatype tmpMeta295;
  static int tmp296 = 0;
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp296)
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp291 = GreaterEq((data->simulationInfo->integerParameter[59] /* weaDat.winSpeSou PARAM */),1);
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp292 = LessEq((data->simulationInfo->integerParameter[59] /* weaDat.winSpeSou PARAM */),3);
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp291 && tmp292))
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp294 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[59] /* weaDat.winSpeSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta295 = stringAppend(MMC_REFSTRINGLIT(tmp293),tmp294);
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.winSpeSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.winSpeSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",95,3,96,88,0};
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta295));
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",95,3,96,88,0};
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta295));
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp296 = 1;
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 95 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4189 OMC_FILE
  TRACE_POP
}

/*
equation index: 1739
type: ALGORITHM

  assert(weaDat.relHum >= 0.0 and weaDat.relHum <= 1.0, "Variable violating min/max constraint: 0.0 <= weaDat.relHum <= 1.0, has value: " + String(weaDat.relHum, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1739(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1739};
  modelica_boolean tmp297;
  modelica_boolean tmp298;
  static const MMC_DEFSTRINGLIT(tmp299,79,"Variable violating min/max constraint: 0.0 <= weaDat.relHum <= 1.0, has value: ");
  modelica_string tmp300;
  modelica_metatype tmpMeta301;
  static int tmp302 = 0;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp302)
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp297 = GreaterEq((data->simulationInfo->realParameter[115] /* weaDat.relHum PARAM */),0.0);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp298 = LessEq((data->simulationInfo->realParameter[115] /* weaDat.relHum PARAM */),1.0);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp297 && tmp298))
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp300 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[115] /* weaDat.relHum PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta301 = stringAppend(MMC_REFSTRINGLIT(tmp299),tmp300);
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.relHum >= 0.0 and weaDat.relHum <= 1.0)";
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",81,3,85,43,0};
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta301));
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",81,3,85,43,0};
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta301));
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp302 = 1;
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 81 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4252 OMC_FILE
  TRACE_POP
}

/*
equation index: 1740
type: ALGORITHM

  assert(weaDat.relHumSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.relHumSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.relHumSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.relHumSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1740(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1740};
  modelica_boolean tmp303;
  modelica_boolean tmp304;
  static const MMC_DEFSTRINGLIT(tmp305,177,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.relHumSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp306;
  modelica_metatype tmpMeta307;
  static int tmp308 = 0;
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp308)
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp303 = GreaterEq((data->simulationInfo->integerParameter[52] /* weaDat.relHumSou PARAM */),1);
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp304 = LessEq((data->simulationInfo->integerParameter[52] /* weaDat.relHumSou PARAM */),3);
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp303 && tmp304))
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp306 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[52] /* weaDat.relHumSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta307 = stringAppend(MMC_REFSTRINGLIT(tmp305),tmp306);
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.relHumSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.relHumSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",79,3,80,95,0};
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta307));
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",79,3,80,95,0};
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta307));
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp308 = 1;
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 79 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4315 OMC_FILE
  TRACE_POP
}

/*
equation index: 1741
type: ALGORITHM

  assert(weaDat.TBlaSky >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.TBlaSky, has value: " + String(weaDat.TBlaSky, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1741(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1741};
  modelica_boolean tmp309;
  static const MMC_DEFSTRINGLIT(tmp310,69,"Variable violating min constraint: 0.0 <= weaDat.TBlaSky, has value: ");
  modelica_string tmp311;
  modelica_metatype tmpMeta312;
  static int tmp313 = 0;
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp313)
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp309 = GreaterEq((data->simulationInfo->realParameter[71] /* weaDat.TBlaSky PARAM */),0.0);
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp309)
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp311 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[71] /* weaDat.TBlaSky PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta312 = stringAppend(MMC_REFSTRINGLIT(tmp310),tmp311);
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TBlaSky >= 0.0)";
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",66,3,68,43,0};
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta312));
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",66,3,68,43,0};
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta312));
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp313 = 1;
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 66 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4375 OMC_FILE
  TRACE_POP
}

/*
equation index: 1742
type: ALGORITHM

  assert(weaDat.TBlaSkySou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TBlaSkySou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TBlaSkySou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TBlaSkySou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1742(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1742};
  modelica_boolean tmp314;
  modelica_boolean tmp315;
  static const MMC_DEFSTRINGLIT(tmp316,178,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TBlaSkySou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp317;
  modelica_metatype tmpMeta318;
  static int tmp319 = 0;
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp319)
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp314 = GreaterEq((data->simulationInfo->integerParameter[3] /* weaDat.TBlaSkySou PARAM */),1);
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp315 = LessEq((data->simulationInfo->integerParameter[3] /* weaDat.TBlaSkySou PARAM */),3);
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp314 && tmp315))
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp317 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[3] /* weaDat.TBlaSkySou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta318 = stringAppend(MMC_REFSTRINGLIT(tmp316),tmp317);
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TBlaSkySou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TBlaSkySou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",64,3,65,104,0};
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta318));
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",64,3,65,104,0};
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta318));
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp319 = 1;
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 64 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4438 OMC_FILE
  TRACE_POP
}

/*
equation index: 1743
type: ALGORITHM

  assert(weaDat.TDewPoi >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.TDewPoi, has value: " + String(weaDat.TDewPoi, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1743(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1743};
  modelica_boolean tmp320;
  static const MMC_DEFSTRINGLIT(tmp321,69,"Variable violating min constraint: 0.0 <= weaDat.TDewPoi, has value: ");
  modelica_string tmp322;
  modelica_metatype tmpMeta323;
  static int tmp324 = 0;
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp324)
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp320 = GreaterEq((data->simulationInfo->realParameter[73] /* weaDat.TDewPoi PARAM */),0.0);
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp320)
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp322 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[73] /* weaDat.TDewPoi PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta323 = stringAppend(MMC_REFSTRINGLIT(tmp321),tmp322);
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TDewPoi >= 0.0)";
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",52,3,54,43,0};
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta323));
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",52,3,54,43,0};
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta323));
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp324 = 1;
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 52 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4498 OMC_FILE
  TRACE_POP
}

/*
equation index: 1744
type: ALGORITHM

  assert(weaDat.TDewPoiSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDewPoiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDewPoiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TDewPoiSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1744(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1744};
  modelica_boolean tmp325;
  modelica_boolean tmp326;
  static const MMC_DEFSTRINGLIT(tmp327,178,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDewPoiSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp328;
  modelica_metatype tmpMeta329;
  static int tmp330 = 0;
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp330)
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp325 = GreaterEq((data->simulationInfo->integerParameter[5] /* weaDat.TDewPoiSou PARAM */),1);
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp326 = LessEq((data->simulationInfo->integerParameter[5] /* weaDat.TDewPoiSou PARAM */),3);
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp325 && tmp326))
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp328 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[5] /* weaDat.TDewPoiSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta329 = stringAppend(MMC_REFSTRINGLIT(tmp327),tmp328);
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TDewPoiSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDewPoiSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",49,3,51,75,0};
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta329));
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",49,3,51,75,0};
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta329));
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp330 = 1;
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 49 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4561 OMC_FILE
  TRACE_POP
}

/*
equation index: 1745
type: ALGORITHM

  assert(weaDat.TDryBul >= 0.0, "Variable violating min constraint: 0.0 <= weaDat.TDryBul, has value: " + String(weaDat.TDryBul, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1745(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1745};
  modelica_boolean tmp331;
  static const MMC_DEFSTRINGLIT(tmp332,69,"Variable violating min constraint: 0.0 <= weaDat.TDryBul, has value: ");
  modelica_string tmp333;
  modelica_metatype tmpMeta334;
  static int tmp335 = 0;
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp335)
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp331 = GreaterEq((data->simulationInfo->realParameter[75] /* weaDat.TDryBul PARAM */),0.0);
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!tmp331)
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp333 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[75] /* weaDat.TDryBul PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta334 = stringAppend(MMC_REFSTRINGLIT(tmp332),tmp333);
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TDryBul >= 0.0)";
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",37,3,39,43,0};
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta334));
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",37,3,39,43,0};
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta334));
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp335 = 1;
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 37 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4621 OMC_FILE
  TRACE_POP
}

/*
equation index: 1746
type: ALGORITHM

  assert(weaDat.TDryBulSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDryBulSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDryBulSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.TDryBulSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1746(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1746};
  modelica_boolean tmp336;
  modelica_boolean tmp337;
  static const MMC_DEFSTRINGLIT(tmp338,178,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.TDryBulSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp339;
  modelica_metatype tmpMeta340;
  static int tmp341 = 0;
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp341)
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp336 = GreaterEq((data->simulationInfo->integerParameter[7] /* weaDat.TDryBulSou PARAM */),1);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp337 = LessEq((data->simulationInfo->integerParameter[7] /* weaDat.TDryBulSou PARAM */),3);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp336 && tmp337))
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp339 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[7] /* weaDat.TDryBulSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta340 = stringAppend(MMC_REFSTRINGLIT(tmp338),tmp339);
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.TDryBulSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.TDryBulSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",34,3,36,75,0};
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta340));
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",34,3,36,75,0};
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta340));
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp341 = 1;
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 34 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4684 OMC_FILE
  TRACE_POP
}

/*
equation index: 1747
type: ALGORITHM

  assert(weaDat.pAtmSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.pAtmSou <= Buildings.BoundaryConditions.Types.DataSource.Input, "Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.pAtmSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: " + String(weaDat.pAtmSou, "d"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1747(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1747};
  modelica_boolean tmp342;
  modelica_boolean tmp343;
  static const MMC_DEFSTRINGLIT(tmp344,175,"Variable violating min/max constraint: Buildings.BoundaryConditions.Types.DataSource.File <= weaDat.pAtmSou <= Buildings.BoundaryConditions.Types.DataSource.Input, has value: ");
  modelica_string tmp345;
  modelica_metatype tmpMeta346;
  static int tmp347 = 0;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  if(!tmp347)
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp342 = GreaterEq((data->simulationInfo->integerParameter[50] /* weaDat.pAtmSou PARAM */),1);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    tmp343 = LessEq((data->simulationInfo->integerParameter[50] /* weaDat.pAtmSou PARAM */),3);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    if(!(tmp342 && tmp343))
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp345 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[50] /* weaDat.pAtmSou PARAM */), (modelica_string) mmc_strings_len1[100]);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmpMeta346 = stringAppend(MMC_REFSTRINGLIT(tmp344),tmp345);
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        const char* assert_cond = "(weaDat.pAtmSou >= Buildings.BoundaryConditions.Types.DataSource.File and weaDat.pAtmSou <= Buildings.BoundaryConditions.Types.DataSource.Input)";
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",18,3,20,75,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta346));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        } else {
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo",18,3,20,75,0};
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta346));
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
        }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
      tmp347 = 1;
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
    }
#line 18 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/WeatherData/ReaderTMY3.mo"
  }
#line 4747 OMC_FILE
  TRACE_POP
}

/*
equation index: 1748
type: ALGORITHM

  assert(HDifTilIso.rho >= 0.0 and HDifTilIso.rho <= 1.0, "Variable violating min/max constraint: 0.0 <= HDifTilIso.rho <= 1.0, has value: " + String(HDifTilIso.rho, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1748(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1748};
  modelica_boolean tmp348;
  modelica_boolean tmp349;
  static const MMC_DEFSTRINGLIT(tmp350,80,"Variable violating min/max constraint: 0.0 <= HDifTilIso.rho <= 1.0, has value: ");
  modelica_string tmp351;
  modelica_metatype tmpMeta352;
  static int tmp353 = 0;
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
  if(!tmp353)
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
  {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
    tmp348 = GreaterEq((data->simulationInfo->realParameter[9] /* HDifTilIso.rho PARAM */),0.0);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
    tmp349 = LessEq((data->simulationInfo->realParameter[9] /* HDifTilIso.rho PARAM */),1.0);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
    if(!(tmp348 && tmp349))
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
    {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
      tmp351 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[9] /* HDifTilIso.rho PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
      tmpMeta352 = stringAppend(MMC_REFSTRINGLIT(tmp350),tmp351);
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
      {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
        const char* assert_cond = "(HDifTilIso.rho >= 0.0 and HDifTilIso.rho <= 1.0)";
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo",6,3,6,76,0};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta352));
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
        } else {
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo",6,3,6,76,0};
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta352));
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
        }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
      }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
      tmp353 = 1;
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
    }
#line 6 "/home/marius/modelica-buildings/Buildings/BoundaryConditions/SolarIrradiation/DiffuseIsotropic.mo"
  }
#line 4810 OMC_FILE
  TRACE_POP
}

/*
equation index: 1749
type: ALGORITHM

  assert(glaSys.gas[1].MM >= 0.0, "Variable violating min constraint: 0.0 <= glaSys.gas[1].MM, has value: " + String(glaSys.gas[1].MM, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1749(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1749};
  modelica_boolean tmp354;
  static const MMC_DEFSTRINGLIT(tmp355,71,"Variable violating min constraint: 0.0 <= glaSys.gas[1].MM, has value: ");
  modelica_string tmp356;
  modelica_metatype tmpMeta357;
  static int tmp358 = 0;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp358)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp354 = GreaterEq((data->simulationInfo->realParameter[33] /* glaSys.gas[1].MM PARAM */),0.0);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp354)
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp356 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[33] /* glaSys.gas[1].MM PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta357 = stringAppend(MMC_REFSTRINGLIT(tmp355),tmp356);
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(glaSys.gas[1].MM >= 0.0)";
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta357));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",21,5,22,48,0};
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta357));
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp358 = 1;
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 21 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 4870 OMC_FILE
  TRACE_POP
}

/*
equation index: 1750
type: ALGORITHM

  assert(glaSys.gas[1].a_mu >= 0.0, "Variable violating min constraint: 0.0 <= glaSys.gas[1].a_mu, has value: " + String(glaSys.gas[1].a_mu, "g"));
*/
OMC_DISABLE_OPT
static void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1750(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1750};
  modelica_boolean tmp359;
  static const MMC_DEFSTRINGLIT(tmp360,73,"Variable violating min constraint: 0.0 <= glaSys.gas[1].a_mu, has value: ");
  modelica_string tmp361;
  modelica_metatype tmpMeta362;
  static int tmp363 = 0;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  if(!tmp363)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    tmp359 = GreaterEq((data->simulationInfo->realParameter[37] /* glaSys.gas[1].a_mu PARAM */),0.0);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    if(!tmp359)
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp361 = modelica_real_to_modelica_string_format((data->simulationInfo->realParameter[37] /* glaSys.gas[1].a_mu PARAM */), (modelica_string) mmc_strings_len1[103]);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmpMeta362 = stringAppend(MMC_REFSTRINGLIT(tmp360),tmp361);
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        const char* assert_cond = "(glaSys.gas[1].a_mu >= 0.0)";
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        if (data->simulationInfo->noThrowAsserts) {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta362));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        } else {
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          FILE_INFO info = {"/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo",12,5,13,51,0};
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta362));
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
        }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
      tmp363 = 1;
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
    }
#line 12 "/home/marius/modelica-buildings/Buildings/HeatTransfer/Data/Gases.mo"
  }
#line 4930 OMC_FILE
  TRACE_POP
}
OMC_DISABLE_OPT
void Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_343(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_344(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_345(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_346(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_347(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_348(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_349(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_350(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_351(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_352(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_353(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_354(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_355(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_356(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_357(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_358(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_359(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_360(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_361(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_362(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_363(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_364(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_365(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_366(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_367(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_368(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_369(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_370(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_371(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_372(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1499(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1500(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1501(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1502(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1503(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1504(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1505(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1506(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1507(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1508(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1509(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1510(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1518(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1519(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1522(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1523(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1524(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1525(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1556(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1557(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1588(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1589(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1617(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_185(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_184(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_183(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_14(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_13(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_12(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_11(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_10(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_9(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_8(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_7(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_6(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_5(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_4(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_3(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_2(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1686(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1687(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1688(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1689(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1690(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1691(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1692(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1693(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1694(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1695(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1696(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1697(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1698(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1699(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1700(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1701(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1702(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1703(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1704(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1705(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1706(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1707(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1708(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1709(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1710(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1711(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1712(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1713(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1714(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1715(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1716(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1717(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1718(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1719(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1720(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1721(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1722(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1723(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1724(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1725(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1726(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1727(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1728(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1729(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1730(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1731(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1732(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1733(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1734(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1735(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1736(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1737(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1738(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1739(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1740(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1741(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1742(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1743(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1744(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1745(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1746(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1747(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1748(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1749(data, threadData);
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_eqFunction_1750(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[11] /* weaDat.datRea.columns[1] PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[11].time_unvarying = 1;
  (data->simulationInfo->integerParameter[12] /* weaDat.datRea.columns[2] PARAM */) = ((modelica_integer) 3);
  data->modelData->integerParameterData[12].time_unvarying = 1;
  (data->simulationInfo->integerParameter[13] /* weaDat.datRea.columns[3] PARAM */) = ((modelica_integer) 4);
  data->modelData->integerParameterData[13].time_unvarying = 1;
  (data->simulationInfo->integerParameter[14] /* weaDat.datRea.columns[4] PARAM */) = ((modelica_integer) 5);
  data->modelData->integerParameterData[14].time_unvarying = 1;
  (data->simulationInfo->integerParameter[15] /* weaDat.datRea.columns[5] PARAM */) = ((modelica_integer) 6);
  data->modelData->integerParameterData[15].time_unvarying = 1;
  (data->simulationInfo->integerParameter[16] /* weaDat.datRea.columns[6] PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[16].time_unvarying = 1;
  (data->simulationInfo->integerParameter[17] /* weaDat.datRea.columns[7] PARAM */) = ((modelica_integer) 12);
  data->modelData->integerParameterData[17].time_unvarying = 1;
  (data->simulationInfo->integerParameter[18] /* weaDat.datRea.columns[8] PARAM */) = ((modelica_integer) 13);
  data->modelData->integerParameterData[18].time_unvarying = 1;
  (data->simulationInfo->integerParameter[19] /* weaDat.datRea.columns[9] PARAM */) = ((modelica_integer) 14);
  data->modelData->integerParameterData[19].time_unvarying = 1;
  (data->simulationInfo->integerParameter[20] /* weaDat.datRea.columns[10] PARAM */) = ((modelica_integer) 15);
  data->modelData->integerParameterData[20].time_unvarying = 1;
  (data->simulationInfo->integerParameter[21] /* weaDat.datRea.columns[11] PARAM */) = ((modelica_integer) 16);
  data->modelData->integerParameterData[21].time_unvarying = 1;
  (data->simulationInfo->integerParameter[22] /* weaDat.datRea.columns[12] PARAM */) = ((modelica_integer) 17);
  data->modelData->integerParameterData[22].time_unvarying = 1;
  (data->simulationInfo->integerParameter[23] /* weaDat.datRea.columns[13] PARAM */) = ((modelica_integer) 18);
  data->modelData->integerParameterData[23].time_unvarying = 1;
  (data->simulationInfo->integerParameter[24] /* weaDat.datRea.columns[14] PARAM */) = ((modelica_integer) 19);
  data->modelData->integerParameterData[24].time_unvarying = 1;
  (data->simulationInfo->integerParameter[25] /* weaDat.datRea.columns[15] PARAM */) = ((modelica_integer) 20);
  data->modelData->integerParameterData[25].time_unvarying = 1;
  (data->simulationInfo->integerParameter[26] /* weaDat.datRea.columns[16] PARAM */) = ((modelica_integer) 21);
  data->modelData->integerParameterData[26].time_unvarying = 1;
  (data->simulationInfo->integerParameter[27] /* weaDat.datRea.columns[17] PARAM */) = ((modelica_integer) 22);
  data->modelData->integerParameterData[27].time_unvarying = 1;
  (data->simulationInfo->integerParameter[28] /* weaDat.datRea.columns[18] PARAM */) = ((modelica_integer) 23);
  data->modelData->integerParameterData[28].time_unvarying = 1;
  (data->simulationInfo->integerParameter[29] /* weaDat.datRea.columns[19] PARAM */) = ((modelica_integer) 24);
  data->modelData->integerParameterData[29].time_unvarying = 1;
  (data->simulationInfo->integerParameter[30] /* weaDat.datRea.columns[20] PARAM */) = ((modelica_integer) 25);
  data->modelData->integerParameterData[30].time_unvarying = 1;
  (data->simulationInfo->integerParameter[31] /* weaDat.datRea.columns[21] PARAM */) = ((modelica_integer) 26);
  data->modelData->integerParameterData[31].time_unvarying = 1;
  (data->simulationInfo->integerParameter[32] /* weaDat.datRea.columns[22] PARAM */) = ((modelica_integer) 27);
  data->modelData->integerParameterData[32].time_unvarying = 1;
  (data->simulationInfo->integerParameter[33] /* weaDat.datRea.columns[23] PARAM */) = ((modelica_integer) 28);
  data->modelData->integerParameterData[33].time_unvarying = 1;
  (data->simulationInfo->integerParameter[34] /* weaDat.datRea.columns[24] PARAM */) = ((modelica_integer) 29);
  data->modelData->integerParameterData[34].time_unvarying = 1;
  (data->simulationInfo->integerParameter[35] /* weaDat.datRea.columns[25] PARAM */) = ((modelica_integer) 30);
  data->modelData->integerParameterData[35].time_unvarying = 1;
  (data->simulationInfo->integerParameter[36] /* weaDat.datRea.columns[26] PARAM */) = ((modelica_integer) 8);
  data->modelData->integerParameterData[36].time_unvarying = 1;
  (data->simulationInfo->integerParameter[38] /* weaDat.datRea.nout PARAM */) = ((modelica_integer) 26);
  data->modelData->integerParameterData[38].time_unvarying = 1;
  (data->simulationInfo->integerParameter[40] /* weaDat.datRea30Min.columns[1] PARAM */) = ((modelica_integer) 9);
  data->modelData->integerParameterData[40].time_unvarying = 1;
  (data->simulationInfo->integerParameter[41] /* weaDat.datRea30Min.columns[2] PARAM */) = ((modelica_integer) 10);
  data->modelData->integerParameterData[41].time_unvarying = 1;
  (data->simulationInfo->integerParameter[42] /* weaDat.datRea30Min.columns[3] PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[42].time_unvarying = 1;
  (data->simulationInfo->integerParameter[44] /* weaDat.datRea30Min.nout PARAM */) = ((modelica_integer) 3);
  data->modelData->integerParameterData[44].time_unvarying = 1;
  (data->simulationInfo->integerParameter[60] /* winRad.N PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[60].time_unvarying = 1;
  (data->simulationInfo->integerParameter[61] /* winRad.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[61].time_unvarying = 1;
  (data->simulationInfo->integerParameter[62] /* winRad.abs.HEM PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[62].time_unvarying = 1;
  (data->simulationInfo->integerParameter[63] /* winRad.abs.N PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[63].time_unvarying = 1;
  (data->simulationInfo->integerParameter[64] /* winRad.abs.NDIR PARAM */) = ((modelica_integer) 10);
  data->modelData->integerParameterData[64].time_unvarying = 1;
  (data->simulationInfo->integerParameter[65] /* winRad.abs.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[65].time_unvarying = 1;
  (data->simulationInfo->integerParameter[66] /* winRad.abs.radDat.HEM PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[66].time_unvarying = 1;
  (data->simulationInfo->integerParameter[67] /* winRad.abs.radDat.N PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[67].time_unvarying = 1;
  (data->simulationInfo->integerParameter[68] /* winRad.abs.radDat.NDIR PARAM */) = ((modelica_integer) 10);
  data->modelData->integerParameterData[68].time_unvarying = 1;
  (data->simulationInfo->integerParameter[69] /* winRad.abs.radDat.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[69].time_unvarying = 1;
  (data->simulationInfo->integerParameter[70] /* winRad.radDat.HEM PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[70].time_unvarying = 1;
  (data->simulationInfo->integerParameter[71] /* winRad.radDat.N PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[71].time_unvarying = 1;
  (data->simulationInfo->integerParameter[72] /* winRad.radDat.NDIR PARAM */) = ((modelica_integer) 10);
  data->modelData->integerParameterData[72].time_unvarying = 1;
  (data->simulationInfo->integerParameter[73] /* winRad.radDat.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[73].time_unvarying = 1;
  (data->simulationInfo->integerParameter[74] /* winRad.staIntQAbsExtSha_flow.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[74].time_unvarying = 1;
  (data->simulationInfo->integerParameter[75] /* winRad.staIntQAbsGlaSha_flow[1].NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[75].time_unvarying = 1;
  (data->simulationInfo->integerParameter[76] /* winRad.staIntQAbsGlaSha_flow[2].NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[76].time_unvarying = 1;
  (data->simulationInfo->integerParameter[77] /* winRad.staIntQAbsGlaUns_flow[1].NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[77].time_unvarying = 1;
  (data->simulationInfo->integerParameter[78] /* winRad.staIntQAbsGlaUns_flow[2].NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[78].time_unvarying = 1;
  (data->simulationInfo->integerParameter[79] /* winRad.staIntQAbsIntSha_flow.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[79].time_unvarying = 1;
  (data->simulationInfo->integerParameter[80] /* winRad.staIntQTraDif_flow.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[80].time_unvarying = 1;
  (data->simulationInfo->integerParameter[81] /* winRad.staIntQTraDir_flow.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[81].time_unvarying = 1;
  (data->simulationInfo->integerParameter[82] /* winRad.tra.HEM PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[82].time_unvarying = 1;
  (data->simulationInfo->integerParameter[83] /* winRad.tra.N PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[83].time_unvarying = 1;
  (data->simulationInfo->integerParameter[84] /* winRad.tra.NDIR PARAM */) = ((modelica_integer) 10);
  data->modelData->integerParameterData[84].time_unvarying = 1;
  (data->simulationInfo->integerParameter[85] /* winRad.tra.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[85].time_unvarying = 1;
  (data->simulationInfo->integerParameter[86] /* winRad.tra.radDat.HEM PARAM */) = ((modelica_integer) 11);
  data->modelData->integerParameterData[86].time_unvarying = 1;
  (data->simulationInfo->integerParameter[87] /* winRad.tra.radDat.N PARAM */) = ((modelica_integer) 2);
  data->modelData->integerParameterData[87].time_unvarying = 1;
  (data->simulationInfo->integerParameter[88] /* winRad.tra.radDat.NDIR PARAM */) = ((modelica_integer) 10);
  data->modelData->integerParameterData[88].time_unvarying = 1;
  (data->simulationInfo->integerParameter[89] /* winRad.tra.radDat.NSta PARAM */) = ((modelica_integer) 1);
  data->modelData->integerParameterData[89].time_unvarying = 1;
  (data->simulationInfo->realParameter[2] /* A PARAM */) = 1.0;
  data->modelData->realParameterData[2].time_unvarying = 1;
  (data->simulationInfo->realParameter[3] /* AFra PARAM */) = 0.2;
  data->modelData->realParameterData[3].time_unvarying = 1;
  (data->simulationInfo->realParameter[4] /* AGla PARAM */) = 0.8;
  data->modelData->realParameterData[4].time_unvarying = 1;
  (data->simulationInfo->realParameter[5] /* HDifTilIso.HDifTilIso.rho PARAM */) = 0.2;
  data->modelData->realParameterData[5].time_unvarying = 1;
  (data->simulationInfo->realParameter[6] /* HDifTilIso.HDifTilIso.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[6].time_unvarying = 1;
  (data->simulationInfo->realParameter[7] /* HDifTilIso.add.k1 PARAM */) = 1.0;
  data->modelData->realParameterData[7].time_unvarying = 1;
  (data->simulationInfo->realParameter[8] /* HDifTilIso.add.k2 PARAM */) = 1.0;
  data->modelData->realParameterData[8].time_unvarying = 1;
  (data->simulationInfo->realParameter[9] /* HDifTilIso.rho PARAM */) = 0.2;
  data->modelData->realParameterData[9].time_unvarying = 1;
  (data->simulationInfo->realParameter[10] /* HDifTilIso.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[10].time_unvarying = 1;
  (data->simulationInfo->realParameter[14] /* HDirTil.azi PARAM */) = 0.0;
  data->modelData->realParameterData[14].time_unvarying = 1;
  (data->simulationInfo->realParameter[15] /* HDirTil.incAng.azi PARAM */) = 0.0;
  data->modelData->realParameterData[15].time_unvarying = 1;
  (data->simulationInfo->realParameter[16] /* HDirTil.incAng.incAng.azi PARAM */) = 0.0;
  data->modelData->realParameterData[16].time_unvarying = 1;
  (data->simulationInfo->realParameter[18] /* HDirTil.incAng.incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[18].time_unvarying = 1;
  (data->simulationInfo->realParameter[19] /* HDirTil.incAng.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[19].time_unvarying = 1;
  (data->simulationInfo->realParameter[23] /* HDirTil.til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[23].time_unvarying = 1;
  (data->simulationInfo->realParameter[27] /* HRoo.k PARAM */) = 0.0;
  data->modelData->realParameterData[27].time_unvarying = 1;
  (data->simulationInfo->realParameter[28] /* azi PARAM */) = 0.0;
  data->modelData->realParameterData[28].time_unvarying = 1;
  (data->simulationInfo->realParameter[29] /* fFra PARAM */) = 0.2;
  data->modelData->realParameterData[29].time_unvarying = 1;
  (data->simulationInfo->realParameter[30] /* glaSys.UFra PARAM */) = 1.4;
  data->modelData->realParameterData[30].time_unvarying = 1;
  (data->simulationInfo->realParameter[31] /* glaSys.absIRFra PARAM */) = 0.8;
  data->modelData->realParameterData[31].time_unvarying = 1;
  (data->simulationInfo->realParameter[32] /* glaSys.absSolFra PARAM */) = 0.5;
  data->modelData->realParameterData[32].time_unvarying = 1;
  (data->simulationInfo->realParameter[33] /* glaSys.gas[1].MM PARAM */) = 0.02897;
  data->modelData->realParameterData[33].time_unvarying = 1;
  (data->simulationInfo->realParameter[34] /* glaSys.gas[1].P0 PARAM */) = 101325.0;
  data->modelData->realParameterData[34].time_unvarying = 1;
  (data->simulationInfo->realParameter[35] /* glaSys.gas[1].a_c PARAM */) = 1002.737;
  data->modelData->realParameterData[35].time_unvarying = 1;
  (data->simulationInfo->realParameter[36] /* glaSys.gas[1].a_k PARAM */) = 0.002873;
  data->modelData->realParameterData[36].time_unvarying = 1;
  (data->simulationInfo->realParameter[37] /* glaSys.gas[1].a_mu PARAM */) = 3.723e-06;
  data->modelData->realParameterData[37].time_unvarying = 1;
  (data->simulationInfo->realParameter[38] /* glaSys.gas[1].b_c PARAM */) = 0.012324;
  data->modelData->realParameterData[38].time_unvarying = 1;
  (data->simulationInfo->realParameter[39] /* glaSys.gas[1].b_k PARAM */) = 7.76e-05;
  data->modelData->realParameterData[39].time_unvarying = 1;
  (data->simulationInfo->realParameter[40] /* glaSys.gas[1].b_mu PARAM */) = 4.94e-08;
  data->modelData->realParameterData[40].time_unvarying = 1;
  (data->simulationInfo->realParameter[41] /* glaSys.gas[1].x PARAM */) = 0.0127;
  data->modelData->realParameterData[41].time_unvarying = 1;
  (data->simulationInfo->realParameter[42] /* glaSys.glass[1].absIR_a PARAM */) = 0.84;
  data->modelData->realParameterData[42].time_unvarying = 1;
  (data->simulationInfo->realParameter[43] /* glaSys.glass[2].absIR_a PARAM */) = 0.84;
  data->modelData->realParameterData[43].time_unvarying = 1;
  (data->simulationInfo->realParameter[44] /* glaSys.glass[1].absIR_b PARAM */) = 0.84;
  data->modelData->realParameterData[44].time_unvarying = 1;
  (data->simulationInfo->realParameter[45] /* glaSys.glass[2].absIR_b PARAM */) = 0.84;
  data->modelData->realParameterData[45].time_unvarying = 1;
  (data->simulationInfo->realParameter[46] /* glaSys.glass[1].k PARAM */) = 1.0;
  data->modelData->realParameterData[46].time_unvarying = 1;
  (data->simulationInfo->realParameter[47] /* glaSys.glass[2].k PARAM */) = 1.0;
  data->modelData->realParameterData[47].time_unvarying = 1;
  (data->simulationInfo->realParameter[48] /* glaSys.glass[1].rhoSol_a[1] PARAM */) = 0.075;
  data->modelData->realParameterData[48].time_unvarying = 1;
  (data->simulationInfo->realParameter[49] /* glaSys.glass[2].rhoSol_a[1] PARAM */) = 0.075;
  data->modelData->realParameterData[49].time_unvarying = 1;
  (data->simulationInfo->realParameter[50] /* glaSys.glass[1].rhoSol_b[1] PARAM */) = 0.075;
  data->modelData->realParameterData[50].time_unvarying = 1;
  (data->simulationInfo->realParameter[51] /* glaSys.glass[2].rhoSol_b[1] PARAM */) = 0.075;
  data->modelData->realParameterData[51].time_unvarying = 1;
  (data->simulationInfo->realParameter[52] /* glaSys.glass[1].tauIR PARAM */) = 0.0;
  data->modelData->realParameterData[52].time_unvarying = 1;
  (data->simulationInfo->realParameter[53] /* glaSys.glass[2].tauIR PARAM */) = 0.0;
  data->modelData->realParameterData[53].time_unvarying = 1;
  (data->simulationInfo->realParameter[54] /* glaSys.glass[1].tauSol[1] PARAM */) = 0.834;
  data->modelData->realParameterData[54].time_unvarying = 1;
  (data->simulationInfo->realParameter[55] /* glaSys.glass[2].tauSol[1] PARAM */) = 0.834;
  data->modelData->realParameterData[55].time_unvarying = 1;
  (data->simulationInfo->realParameter[56] /* glaSys.glass[1].x PARAM */) = 0.003;
  data->modelData->realParameterData[56].time_unvarying = 1;
  (data->simulationInfo->realParameter[57] /* glaSys.glass[2].x PARAM */) = 0.003;
  data->modelData->realParameterData[57].time_unvarying = 1;
  (data->simulationInfo->realParameter[60] /* glaSys.shade.rhoSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[60].time_unvarying = 1;
  (data->simulationInfo->realParameter[61] /* glaSys.shade.rhoSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[61].time_unvarying = 1;
  (data->simulationInfo->realParameter[64] /* glaSys.shade.tauSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[64].time_unvarying = 1;
  (data->simulationInfo->realParameter[65] /* glaSys.shade.tauSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[65].time_unvarying = 1;
  (data->simulationInfo->realParameter[66] /* til PARAM */) = 1.5707963267949;
  data->modelData->realParameterData[66].time_unvarying = 1;
  (data->simulationInfo->realParameter[70] /* weaDat.HInfHor PARAM */) = 0.0;
  data->modelData->realParameterData[70].time_unvarying = 1;
  (data->simulationInfo->realParameter[71] /* weaDat.TBlaSky PARAM */) = 273.15;
  data->modelData->realParameterData[71].time_unvarying = 1;
  (data->simulationInfo->realParameter[72] /* weaDat.TBlaSkySel.p PARAM */) = 273.15;
  data->modelData->realParameterData[72].time_unvarying = 1;
  (data->simulationInfo->realParameter[73] /* weaDat.TDewPoi PARAM */) = 283.15;
  data->modelData->realParameterData[73].time_unvarying = 1;
  (data->simulationInfo->realParameter[74] /* weaDat.TDewPoiSel.p PARAM */) = 283.15;
  data->modelData->realParameterData[74].time_unvarying = 1;
  (data->simulationInfo->realParameter[75] /* weaDat.TDryBul PARAM */) = 293.15;
  data->modelData->realParameterData[75].time_unvarying = 1;
  (data->simulationInfo->realParameter[76] /* weaDat.TDryBulSel.p PARAM */) = 293.15;
  data->modelData->realParameterData[76].time_unvarying = 1;
  (data->simulationInfo->realParameter[77] /* weaDat.add30Min.k1 PARAM */) = 1.0;
  data->modelData->realParameterData[77].time_unvarying = 1;
  (data->simulationInfo->realParameter[78] /* weaDat.add30Min.k2 PARAM */) = 1.0;
  data->modelData->realParameterData[78].time_unvarying = 1;
  (data->simulationInfo->realParameter[82] /* weaDat.ceiHei PARAM */) = 20000.0;
  data->modelData->realParameterData[82].time_unvarying = 1;
  (data->simulationInfo->realParameter[83] /* weaDat.ceiHeiSel.p PARAM */) = 20000.0;
  data->modelData->realParameterData[83].time_unvarying = 1;
  (data->simulationInfo->realParameter[84] /* weaDat.cheTemBlaSky.TMax PARAM */) = 343.15;
  data->modelData->realParameterData[84].time_unvarying = 1;
  (data->simulationInfo->realParameter[85] /* weaDat.cheTemBlaSky.TMin PARAM */) = 0.0;
  data->modelData->realParameterData[85].time_unvarying = 1;
  (data->simulationInfo->realParameter[86] /* weaDat.cheTemDewPoi.TMax PARAM */) = 343.15;
  data->modelData->realParameterData[86].time_unvarying = 1;
  (data->simulationInfo->realParameter[87] /* weaDat.cheTemDewPoi.TMin PARAM */) = 203.15;
  data->modelData->realParameterData[87].time_unvarying = 1;
  (data->simulationInfo->realParameter[88] /* weaDat.cheTemDryBul.TMax PARAM */) = 343.15;
  data->modelData->realParameterData[88].time_unvarying = 1;
  (data->simulationInfo->realParameter[89] /* weaDat.cheTemDryBul.TMin PARAM */) = 203.15;
  data->modelData->realParameterData[89].time_unvarying = 1;
  (data->simulationInfo->realParameter[90] /* weaDat.con30Min.k PARAM */) = 1800.0;
  data->modelData->realParameterData[90].time_unvarying = 1;
  (data->simulationInfo->realParameter[101] /* weaDat.horInfRadSel.p PARAM */) = 0.0;
  data->modelData->realParameterData[101].time_unvarying = 1;
  (data->simulationInfo->realParameter[111] /* weaDat.opaSkyCov PARAM */) = 0.5;
  data->modelData->realParameterData[111].time_unvarying = 1;
  (data->simulationInfo->realParameter[112] /* weaDat.opaSkyCovSel.p PARAM */) = 0.5;
  data->modelData->realParameterData[112].time_unvarying = 1;
  (data->simulationInfo->realParameter[113] /* weaDat.pAtm PARAM */) = 101325.0;
  data->modelData->realParameterData[113].time_unvarying = 1;
  (data->simulationInfo->realParameter[114] /* weaDat.pAtmSel.p PARAM */) = 101325.0;
  data->modelData->realParameterData[114].time_unvarying = 1;
  (data->simulationInfo->realParameter[115] /* weaDat.relHum PARAM */) = 0.5;
  data->modelData->realParameterData[115].time_unvarying = 1;
  (data->simulationInfo->realParameter[116] /* weaDat.relHumSel.p PARAM */) = 0.5;
  data->modelData->realParameterData[116].time_unvarying = 1;
  (data->simulationInfo->realParameter[120] /* weaDat.totSkyCov PARAM */) = 0.5;
  data->modelData->realParameterData[120].time_unvarying = 1;
  (data->simulationInfo->realParameter[121] /* weaDat.totSkyCovSel.p PARAM */) = 0.5;
  data->modelData->realParameterData[121].time_unvarying = 1;
  (data->simulationInfo->realParameter[125] /* weaDat.winDir PARAM */) = 1.0;
  data->modelData->realParameterData[125].time_unvarying = 1;
  (data->simulationInfo->realParameter[126] /* weaDat.winDirSel.p PARAM */) = 1.0;
  data->modelData->realParameterData[126].time_unvarying = 1;
  (data->simulationInfo->realParameter[127] /* weaDat.winSpe PARAM */) = 1.0;
  data->modelData->realParameterData[127].time_unvarying = 1;
  (data->simulationInfo->realParameter[128] /* weaDat.winSpeSel.p PARAM */) = 1.0;
  data->modelData->realParameterData[128].time_unvarying = 1;
  (data->simulationInfo->realParameter[130] /* winRad.AWin PARAM */) = 1.0;
  data->modelData->realParameterData[130].time_unvarying = 1;
  (data->simulationInfo->realParameter[131] /* winRad.abs.AWin PARAM */) = 1.0;
  data->modelData->realParameterData[131].time_unvarying = 1;
  (data->simulationInfo->realParameter[132] /* winRad.abs.coeAbsDevExtIrrExtSha PARAM */) = 0.5;
  data->modelData->realParameterData[132].time_unvarying = 1;
  (data->simulationInfo->realParameter[146] /* winRad.abs.coeAbsDevIntIrrExtSha[1] PARAM */) = 0.8473838622594322;
  data->modelData->realParameterData[146].time_unvarying = 1;
  (data->simulationInfo->realParameter[147] /* winRad.abs.coeAbsDevIntIrrIntSha[1] PARAM */) = 0.5282960143941167;
  data->modelData->realParameterData[147].time_unvarying = 1;
  (data->simulationInfo->realParameter[217] /* winRad.abs.radDat.absExtIrrExtSha[1,1,1] PARAM */) = 0.02499520908519422;
  data->modelData->realParameterData[217].time_unvarying = 1;
  (data->simulationInfo->realParameter[218] /* winRad.abs.radDat.absExtIrrExtSha[1,2,1] PARAM */) = 0.02514929957574206;
  data->modelData->realParameterData[218].time_unvarying = 1;
  (data->simulationInfo->realParameter[219] /* winRad.abs.radDat.absExtIrrExtSha[1,3,1] PARAM */) = 0.02561776873020298;
  data->modelData->realParameterData[219].time_unvarying = 1;
  (data->simulationInfo->realParameter[220] /* winRad.abs.radDat.absExtIrrExtSha[1,4,1] PARAM */) = 0.02642332367824236;
  data->modelData->realParameterData[220].time_unvarying = 1;
  (data->simulationInfo->realParameter[221] /* winRad.abs.radDat.absExtIrrExtSha[1,5,1] PARAM */) = 0.0276225173612099;
  data->modelData->realParameterData[221].time_unvarying = 1;
  (data->simulationInfo->realParameter[222] /* winRad.abs.radDat.absExtIrrExtSha[1,6,1] PARAM */) = 0.02935337359634402;
  data->modelData->realParameterData[222].time_unvarying = 1;
  (data->simulationInfo->realParameter[223] /* winRad.abs.radDat.absExtIrrExtSha[1,7,1] PARAM */) = 0.03193076631094863;
  data->modelData->realParameterData[223].time_unvarying = 1;
  (data->simulationInfo->realParameter[224] /* winRad.abs.radDat.absExtIrrExtSha[1,8,1] PARAM */) = 0.03581982523119827;
  data->modelData->realParameterData[224].time_unvarying = 1;
  (data->simulationInfo->realParameter[225] /* winRad.abs.radDat.absExtIrrExtSha[1,9,1] PARAM */) = 0.03977435612665067;
  data->modelData->realParameterData[225].time_unvarying = 1;
  (data->simulationInfo->realParameter[226] /* winRad.abs.radDat.absExtIrrExtSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[226].time_unvarying = 1;
  (data->simulationInfo->realParameter[227] /* winRad.abs.radDat.absExtIrrExtSha[1,11,1] PARAM */) = 0.03241615014704199;
  data->modelData->realParameterData[227].time_unvarying = 1;
  (data->simulationInfo->realParameter[228] /* winRad.abs.radDat.absExtIrrExtSha[2,1,1] PARAM */) = 0.01972325791995835;
  data->modelData->realParameterData[228].time_unvarying = 1;
  (data->simulationInfo->realParameter[229] /* winRad.abs.radDat.absExtIrrExtSha[2,2,1] PARAM */) = 0.01983276806040852;
  data->modelData->realParameterData[229].time_unvarying = 1;
  (data->simulationInfo->realParameter[230] /* winRad.abs.radDat.absExtIrrExtSha[2,3,1] PARAM */) = 0.02015480119109085;
  data->modelData->realParameterData[230].time_unvarying = 1;
  (data->simulationInfo->realParameter[231] /* winRad.abs.radDat.absExtIrrExtSha[2,4,1] PARAM */) = 0.02066350412154015;
  data->modelData->realParameterData[231].time_unvarying = 1;
  (data->simulationInfo->realParameter[232] /* winRad.abs.radDat.absExtIrrExtSha[2,5,1] PARAM */) = 0.02129011768881981;
  data->modelData->realParameterData[232].time_unvarying = 1;
  (data->simulationInfo->realParameter[233] /* winRad.abs.radDat.absExtIrrExtSha[2,6,1] PARAM */) = 0.02186559892833682;
  data->modelData->realParameterData[233].time_unvarying = 1;
  (data->simulationInfo->realParameter[234] /* winRad.abs.radDat.absExtIrrExtSha[2,7,1] PARAM */) = 0.0219907802101197;
  data->modelData->realParameterData[234].time_unvarying = 1;
  (data->simulationInfo->realParameter[235] /* winRad.abs.radDat.absExtIrrExtSha[2,8,1] PARAM */) = 0.02077355991365581;
  data->modelData->realParameterData[235].time_unvarying = 1;
  (data->simulationInfo->realParameter[236] /* winRad.abs.radDat.absExtIrrExtSha[2,9,1] PARAM */) = 0.01636894513455467;
  data->modelData->realParameterData[236].time_unvarying = 1;
  (data->simulationInfo->realParameter[237] /* winRad.abs.radDat.absExtIrrExtSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[237].time_unvarying = 1;
  (data->simulationInfo->realParameter[238] /* winRad.abs.radDat.absExtIrrExtSha[2,11,1] PARAM */) = 0.02252369052121515;
  data->modelData->realParameterData[238].time_unvarying = 1;
  (data->simulationInfo->realParameter[239] /* winRad.abs.radDat.absExtIrrIntSha[1,1,1] PARAM */) = 0.1093863539769833;
  data->modelData->realParameterData[239].time_unvarying = 1;
  (data->simulationInfo->realParameter[240] /* winRad.abs.radDat.absExtIrrIntSha[1,2,1] PARAM */) = 0.1100473669610094;
  data->modelData->realParameterData[240].time_unvarying = 1;
  (data->simulationInfo->realParameter[241] /* winRad.abs.radDat.absExtIrrIntSha[1,3,1] PARAM */) = 0.1120318818175741;
  data->modelData->realParameterData[241].time_unvarying = 1;
  (data->simulationInfo->realParameter[242] /* winRad.abs.radDat.absExtIrrIntSha[1,4,1] PARAM */) = 0.1153398886779867;
  data->modelData->realParameterData[242].time_unvarying = 1;
  (data->simulationInfo->realParameter[243] /* winRad.abs.radDat.absExtIrrIntSha[1,5,1] PARAM */) = 0.1199592159293939;
  data->modelData->realParameterData[243].time_unvarying = 1;
  (data->simulationInfo->realParameter[244] /* winRad.abs.radDat.absExtIrrIntSha[1,6,1] PARAM */) = 0.1258553503945128;
  data->modelData->realParameterData[244].time_unvarying = 1;
  (data->simulationInfo->realParameter[245] /* winRad.abs.radDat.absExtIrrIntSha[1,7,1] PARAM */) = 0.1329258880977036;
  data->modelData->realParameterData[245].time_unvarying = 1;
  (data->simulationInfo->realParameter[246] /* winRad.abs.radDat.absExtIrrIntSha[1,8,1] PARAM */) = 0.1403970614972095;
  data->modelData->realParameterData[246].time_unvarying = 1;
  (data->simulationInfo->realParameter[247] /* winRad.abs.radDat.absExtIrrIntSha[1,9,1] PARAM */) = 0.1415178832813775;
  data->modelData->realParameterData[247].time_unvarying = 1;
  (data->simulationInfo->realParameter[248] /* winRad.abs.radDat.absExtIrrIntSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[248].time_unvarying = 1;
  (data->simulationInfo->realParameter[249] /* winRad.abs.radDat.absExtIrrIntSha[1,11,1] PARAM */) = 0.1354931525419724;
  data->modelData->realParameterData[249].time_unvarying = 1;
  (data->simulationInfo->realParameter[250] /* winRad.abs.radDat.absExtIrrIntSha[2,1,1] PARAM */) = 0.0948566787482195;
  data->modelData->realParameterData[250].time_unvarying = 1;
  (data->simulationInfo->realParameter[251] /* winRad.abs.radDat.absExtIrrIntSha[2,2,1] PARAM */) = 0.09537350821079466;
  data->modelData->realParameterData[251].time_unvarying = 1;
  (data->simulationInfo->realParameter[252] /* winRad.abs.radDat.absExtIrrIntSha[2,3,1] PARAM */) = 0.09687385356797265;
  data->modelData->realParameterData[252].time_unvarying = 1;
  (data->simulationInfo->realParameter[253] /* winRad.abs.radDat.absExtIrrIntSha[2,4,1] PARAM */) = 0.09916070692199794;
  data->modelData->realParameterData[253].time_unvarying = 1;
  (data->simulationInfo->realParameter[254] /* winRad.abs.radDat.absExtIrrIntSha[2,5,1] PARAM */) = 0.1017176618131253;
  data->modelData->realParameterData[254].time_unvarying = 1;
  (data->simulationInfo->realParameter[255] /* winRad.abs.radDat.absExtIrrIntSha[2,6,1] PARAM */) = 0.1033001439761687;
  data->modelData->realParameterData[255].time_unvarying = 1;
  (data->simulationInfo->realParameter[256] /* winRad.abs.radDat.absExtIrrIntSha[2,7,1] PARAM */) = 0.1011252056324434;
  data->modelData->realParameterData[256].time_unvarying = 1;
  (data->simulationInfo->realParameter[257] /* winRad.abs.radDat.absExtIrrIntSha[2,8,1] PARAM */) = 0.08990517963983256;
  data->modelData->realParameterData[257].time_unvarying = 1;
  (data->simulationInfo->realParameter[258] /* winRad.abs.radDat.absExtIrrIntSha[2,9,1] PARAM */) = 0.06281787526849789;
  data->modelData->realParameterData[258].time_unvarying = 1;
  (data->simulationInfo->realParameter[259] /* winRad.abs.radDat.absExtIrrIntSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[259].time_unvarying = 1;
  (data->simulationInfo->realParameter[260] /* winRad.abs.radDat.absExtIrrIntSha[2,11,1] PARAM */) = 0.1039656205865592;
  data->modelData->realParameterData[260].time_unvarying = 1;
  (data->simulationInfo->realParameter[261] /* winRad.abs.radDat.absExtIrrNoSha[1,1,1] PARAM */) = 0.0967242489000629;
  data->modelData->realParameterData[261].time_unvarying = 1;
  (data->simulationInfo->realParameter[262] /* winRad.abs.radDat.absExtIrrNoSha[1,2,1] PARAM */) = 0.09732302857079711;
  data->modelData->realParameterData[262].time_unvarying = 1;
  (data->simulationInfo->realParameter[263] /* winRad.abs.radDat.absExtIrrNoSha[1,3,1] PARAM */) = 0.09913158934736244;
  data->modelData->realParameterData[263].time_unvarying = 1;
  (data->simulationInfo->realParameter[264] /* winRad.abs.radDat.absExtIrrNoSha[1,4,1] PARAM */) = 0.1021914583318008;
  data->modelData->realParameterData[264].time_unvarying = 1;
  (data->simulationInfo->realParameter[265] /* winRad.abs.radDat.absExtIrrNoSha[1,5,1] PARAM */) = 0.1065974620703473;
  data->modelData->realParameterData[265].time_unvarying = 1;
  (data->simulationInfo->realParameter[266] /* winRad.abs.radDat.absExtIrrNoSha[1,6,1] PARAM */) = 0.1125698390133378;
  data->modelData->realParameterData[266].time_unvarying = 1;
  (data->simulationInfo->realParameter[267] /* winRad.abs.radDat.absExtIrrNoSha[1,7,1] PARAM */) = 0.1205657930053361;
  data->modelData->realParameterData[267].time_unvarying = 1;
  (data->simulationInfo->realParameter[268] /* winRad.abs.radDat.absExtIrrNoSha[1,8,1] PARAM */) = 0.1307986830869973;
  data->modelData->realParameterData[268].time_unvarying = 1;
  (data->simulationInfo->realParameter[269] /* winRad.abs.radDat.absExtIrrNoSha[1,9,1] PARAM */) = 0.1371678328302604;
  data->modelData->realParameterData[269].time_unvarying = 1;
  (data->simulationInfo->realParameter[270] /* winRad.abs.radDat.absExtIrrNoSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[270].time_unvarying = 1;
  (data->simulationInfo->realParameter[271] /* winRad.abs.radDat.absExtIrrNoSha[1,11,1] PARAM */) = 0.1227196468033888;
  data->modelData->realParameterData[271].time_unvarying = 1;
  (data->simulationInfo->realParameter[272] /* winRad.abs.radDat.absExtIrrNoSha[2,1,1] PARAM */) = 0.07632331866750475;
  data->modelData->realParameterData[272].time_unvarying = 1;
  (data->simulationInfo->realParameter[273] /* winRad.abs.radDat.absExtIrrNoSha[2,2,1] PARAM */) = 0.07674905803113916;
  data->modelData->realParameterData[273].time_unvarying = 1;
  (data->simulationInfo->realParameter[274] /* winRad.abs.radDat.absExtIrrNoSha[2,3,1] PARAM */) = 0.07799186166816173;
  data->modelData->realParameterData[274].time_unvarying = 1;
  (data->simulationInfo->realParameter[275] /* winRad.abs.radDat.absExtIrrNoSha[2,4,1] PARAM */) = 0.07991551880977556;
  data->modelData->realParameterData[275].time_unvarying = 1;
  (data->simulationInfo->realParameter[276] /* winRad.abs.radDat.absExtIrrNoSha[2,5,1] PARAM */) = 0.08216023482328237;
  data->modelData->realParameterData[276].time_unvarying = 1;
  (data->simulationInfo->realParameter[277] /* winRad.abs.radDat.absExtIrrNoSha[2,6,1] PARAM */) = 0.08385431211898785;
  data->modelData->realParameterData[277].time_unvarying = 1;
  (data->simulationInfo->realParameter[278] /* winRad.abs.radDat.absExtIrrNoSha[2,7,1] PARAM */) = 0.08303389367545573;
  data->modelData->realParameterData[278].time_unvarying = 1;
  (data->simulationInfo->realParameter[279] /* winRad.abs.radDat.absExtIrrNoSha[2,8,1] PARAM */) = 0.07585615681252504;
  data->modelData->realParameterData[279].time_unvarying = 1;
  (data->simulationInfo->realParameter[280] /* winRad.abs.radDat.absExtIrrNoSha[2,9,1] PARAM */) = 0.05645076246299933;
  data->modelData->realParameterData[280].time_unvarying = 1;
  (data->simulationInfo->realParameter[281] /* winRad.abs.radDat.absExtIrrNoSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[281].time_unvarying = 1;
  (data->simulationInfo->realParameter[282] /* winRad.abs.radDat.absExtIrrNoSha[2,11,1] PARAM */) = 0.08526920479249403;
  data->modelData->realParameterData[282].time_unvarying = 1;
  (data->simulationInfo->realParameter[283] /* winRad.abs.radDat.absIntIrrExtSha[1,1] PARAM */) = 0.1039656205865592;
  data->modelData->realParameterData[283].time_unvarying = 1;
  (data->simulationInfo->realParameter[284] /* winRad.abs.radDat.absIntIrrExtSha[2,1] PARAM */) = 0.1354931525419724;
  data->modelData->realParameterData[284].time_unvarying = 1;
  (data->simulationInfo->realParameter[285] /* winRad.abs.radDat.absIntIrrIntSha[1,1] PARAM */) = 0.02252369052121515;
  data->modelData->realParameterData[285].time_unvarying = 1;
  (data->simulationInfo->realParameter[286] /* winRad.abs.radDat.absIntIrrIntSha[2,1] PARAM */) = 0.03241615014704199;
  data->modelData->realParameterData[286].time_unvarying = 1;
  (data->simulationInfo->realParameter[287] /* winRad.abs.radDat.absIntIrrNoSha[1,1] PARAM */) = 0.08526920479249403;
  data->modelData->realParameterData[287].time_unvarying = 1;
  (data->simulationInfo->realParameter[288] /* winRad.abs.radDat.absIntIrrNoSha[2,1] PARAM */) = 0.1227196468033888;
  data->modelData->realParameterData[288].time_unvarying = 1;
  (data->simulationInfo->realParameter[289] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[1,1] PARAM */) = 0.3695381144818747;
  data->modelData->realParameterData[289].time_unvarying = 1;
  (data->simulationInfo->realParameter[290] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[2,1] PARAM */) = 0.3690498410990196;
  data->modelData->realParameterData[290].time_unvarying = 1;
  (data->simulationInfo->realParameter[291] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[3,1] PARAM */) = 0.3673475997451543;
  data->modelData->realParameterData[291].time_unvarying = 1;
  (data->simulationInfo->realParameter[292] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[4,1] PARAM */) = 0.3635548084822143;
  data->modelData->realParameterData[292].time_unvarying = 1;
  (data->simulationInfo->realParameter[293] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[5,1] PARAM */) = 0.3555423033605714;
  data->modelData->realParameterData[293].time_unvarying = 1;
  (data->simulationInfo->realParameter[294] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[6,1] PARAM */) = 0.3384699121977249;
  data->modelData->realParameterData[294].time_unvarying = 1;
  (data->simulationInfo->realParameter[295] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[7,1] PARAM */) = 0.3020070366994245;
  data->modelData->realParameterData[295].time_unvarying = 1;
  (data->simulationInfo->realParameter[296] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[8,1] PARAM */) = 0.2282840296108259;
  data->modelData->realParameterData[296].time_unvarying = 1;
  (data->simulationInfo->realParameter[297] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[9,1] PARAM */) = 0.1062597676765009;
  data->modelData->realParameterData[297].time_unvarying = 1;
  (data->simulationInfo->realParameter[298] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[298].time_unvarying = 1;
  (data->simulationInfo->realParameter[299] /* winRad.abs.radDat.devAbsExtIrrIntShaDev[11,1] PARAM */) = 0.3052322754811356;
  data->modelData->realParameterData[299].time_unvarying = 1;
  (data->simulationInfo->realParameter[300] /* winRad.abs.radDat.devAbsIntIrrIntSha[1] PARAM */) = 0.5282960143941167;
  data->modelData->realParameterData[300].time_unvarying = 1;
  (data->simulationInfo->realParameter[301] /* winRad.abs.radDat.glass[1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[301].time_unvarying = 1;
  (data->simulationInfo->realParameter[302] /* winRad.abs.radDat.glass[1,2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[302].time_unvarying = 1;
  (data->simulationInfo->realParameter[303] /* winRad.abs.radDat.glass[2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[303].time_unvarying = 1;
  (data->simulationInfo->realParameter[304] /* winRad.abs.radDat.glass[2,2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[304].time_unvarying = 1;
  (data->simulationInfo->realParameter[305] /* winRad.abs.radDat.glass[3,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[305].time_unvarying = 1;
  (data->simulationInfo->realParameter[306] /* winRad.abs.radDat.glass[3,2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[306].time_unvarying = 1;
  (data->simulationInfo->realParameter[307] /* winRad.abs.radDat.layer[1,1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[307].time_unvarying = 1;
  (data->simulationInfo->realParameter[308] /* winRad.abs.radDat.layer[1,1,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[308].time_unvarying = 1;
  (data->simulationInfo->realParameter[309] /* winRad.abs.radDat.layer[1,1,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[309].time_unvarying = 1;
  (data->simulationInfo->realParameter[310] /* winRad.abs.radDat.layer[1,1,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[310].time_unvarying = 1;
  (data->simulationInfo->realParameter[311] /* winRad.abs.radDat.layer[1,1,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[311].time_unvarying = 1;
  (data->simulationInfo->realParameter[312] /* winRad.abs.radDat.layer[1,1,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[312].time_unvarying = 1;
  (data->simulationInfo->realParameter[313] /* winRad.abs.radDat.layer[1,1,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[313].time_unvarying = 1;
  (data->simulationInfo->realParameter[314] /* winRad.abs.radDat.layer[1,1,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[314].time_unvarying = 1;
  (data->simulationInfo->realParameter[315] /* winRad.abs.radDat.layer[1,1,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[315].time_unvarying = 1;
  (data->simulationInfo->realParameter[316] /* winRad.abs.radDat.layer[1,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[316].time_unvarying = 1;
  (data->simulationInfo->realParameter[317] /* winRad.abs.radDat.layer[1,1,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[317].time_unvarying = 1;
  (data->simulationInfo->realParameter[318] /* winRad.abs.radDat.layer[1,2,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[318].time_unvarying = 1;
  (data->simulationInfo->realParameter[319] /* winRad.abs.radDat.layer[1,2,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[319].time_unvarying = 1;
  (data->simulationInfo->realParameter[320] /* winRad.abs.radDat.layer[1,2,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[320].time_unvarying = 1;
  (data->simulationInfo->realParameter[321] /* winRad.abs.radDat.layer[1,2,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[321].time_unvarying = 1;
  (data->simulationInfo->realParameter[322] /* winRad.abs.radDat.layer[1,2,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[322].time_unvarying = 1;
  (data->simulationInfo->realParameter[323] /* winRad.abs.radDat.layer[1,2,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[323].time_unvarying = 1;
  (data->simulationInfo->realParameter[324] /* winRad.abs.radDat.layer[1,2,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[324].time_unvarying = 1;
  (data->simulationInfo->realParameter[325] /* winRad.abs.radDat.layer[1,2,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[325].time_unvarying = 1;
  (data->simulationInfo->realParameter[326] /* winRad.abs.radDat.layer[1,2,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[326].time_unvarying = 1;
  (data->simulationInfo->realParameter[327] /* winRad.abs.radDat.layer[1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[327].time_unvarying = 1;
  (data->simulationInfo->realParameter[328] /* winRad.abs.radDat.layer[1,2,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[328].time_unvarying = 1;
  (data->simulationInfo->realParameter[329] /* winRad.abs.radDat.layer[2,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[329].time_unvarying = 1;
  (data->simulationInfo->realParameter[330] /* winRad.abs.radDat.layer[2,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[330].time_unvarying = 1;
  (data->simulationInfo->realParameter[331] /* winRad.abs.radDat.layer[2,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[331].time_unvarying = 1;
  (data->simulationInfo->realParameter[332] /* winRad.abs.radDat.layer[2,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[332].time_unvarying = 1;
  (data->simulationInfo->realParameter[333] /* winRad.abs.radDat.layer[2,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[333].time_unvarying = 1;
  (data->simulationInfo->realParameter[334] /* winRad.abs.radDat.layer[2,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[334].time_unvarying = 1;
  (data->simulationInfo->realParameter[335] /* winRad.abs.radDat.layer[2,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[335].time_unvarying = 1;
  (data->simulationInfo->realParameter[336] /* winRad.abs.radDat.layer[2,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[336].time_unvarying = 1;
  (data->simulationInfo->realParameter[337] /* winRad.abs.radDat.layer[2,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[337].time_unvarying = 1;
  (data->simulationInfo->realParameter[338] /* winRad.abs.radDat.layer[2,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[338].time_unvarying = 1;
  (data->simulationInfo->realParameter[339] /* winRad.abs.radDat.layer[2,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[339].time_unvarying = 1;
  (data->simulationInfo->realParameter[340] /* winRad.abs.radDat.layer[2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[340].time_unvarying = 1;
  (data->simulationInfo->realParameter[341] /* winRad.abs.radDat.layer[2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[341].time_unvarying = 1;
  (data->simulationInfo->realParameter[342] /* winRad.abs.radDat.layer[2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[342].time_unvarying = 1;
  (data->simulationInfo->realParameter[343] /* winRad.abs.radDat.layer[2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[343].time_unvarying = 1;
  (data->simulationInfo->realParameter[344] /* winRad.abs.radDat.layer[2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[344].time_unvarying = 1;
  (data->simulationInfo->realParameter[345] /* winRad.abs.radDat.layer[2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[345].time_unvarying = 1;
  (data->simulationInfo->realParameter[346] /* winRad.abs.radDat.layer[2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[346].time_unvarying = 1;
  (data->simulationInfo->realParameter[347] /* winRad.abs.radDat.layer[2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[347].time_unvarying = 1;
  (data->simulationInfo->realParameter[348] /* winRad.abs.radDat.layer[2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[348].time_unvarying = 1;
  (data->simulationInfo->realParameter[349] /* winRad.abs.radDat.layer[2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[349].time_unvarying = 1;
  (data->simulationInfo->realParameter[350] /* winRad.abs.radDat.layer[2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[350].time_unvarying = 1;
  (data->simulationInfo->realParameter[351] /* winRad.abs.radDat.layer[3,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[351].time_unvarying = 1;
  (data->simulationInfo->realParameter[352] /* winRad.abs.radDat.layer[3,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[352].time_unvarying = 1;
  (data->simulationInfo->realParameter[353] /* winRad.abs.radDat.layer[3,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[353].time_unvarying = 1;
  (data->simulationInfo->realParameter[354] /* winRad.abs.radDat.layer[3,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[354].time_unvarying = 1;
  (data->simulationInfo->realParameter[355] /* winRad.abs.radDat.layer[3,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[355].time_unvarying = 1;
  (data->simulationInfo->realParameter[356] /* winRad.abs.radDat.layer[3,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[356].time_unvarying = 1;
  (data->simulationInfo->realParameter[357] /* winRad.abs.radDat.layer[3,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[357].time_unvarying = 1;
  (data->simulationInfo->realParameter[358] /* winRad.abs.radDat.layer[3,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[358].time_unvarying = 1;
  (data->simulationInfo->realParameter[359] /* winRad.abs.radDat.layer[3,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[359].time_unvarying = 1;
  (data->simulationInfo->realParameter[360] /* winRad.abs.radDat.layer[3,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[360].time_unvarying = 1;
  (data->simulationInfo->realParameter[361] /* winRad.abs.radDat.layer[3,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[361].time_unvarying = 1;
  (data->simulationInfo->realParameter[362] /* winRad.abs.radDat.layer[3,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[362].time_unvarying = 1;
  (data->simulationInfo->realParameter[363] /* winRad.abs.radDat.layer[3,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[363].time_unvarying = 1;
  (data->simulationInfo->realParameter[364] /* winRad.abs.radDat.layer[3,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[364].time_unvarying = 1;
  (data->simulationInfo->realParameter[365] /* winRad.abs.radDat.layer[3,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[365].time_unvarying = 1;
  (data->simulationInfo->realParameter[366] /* winRad.abs.radDat.layer[3,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[366].time_unvarying = 1;
  (data->simulationInfo->realParameter[367] /* winRad.abs.radDat.layer[3,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[367].time_unvarying = 1;
  (data->simulationInfo->realParameter[368] /* winRad.abs.radDat.layer[3,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[368].time_unvarying = 1;
  (data->simulationInfo->realParameter[369] /* winRad.abs.radDat.layer[3,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[369].time_unvarying = 1;
  (data->simulationInfo->realParameter[370] /* winRad.abs.radDat.layer[3,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[370].time_unvarying = 1;
  (data->simulationInfo->realParameter[371] /* winRad.abs.radDat.layer[3,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[371].time_unvarying = 1;
  (data->simulationInfo->realParameter[372] /* winRad.abs.radDat.layer[3,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[372].time_unvarying = 1;
  (data->simulationInfo->realParameter[373] /* winRad.abs.radDat.psi[1] PARAM */) = 0.0;
  data->modelData->realParameterData[373].time_unvarying = 1;
  (data->simulationInfo->realParameter[374] /* winRad.abs.radDat.psi[2] PARAM */) = 0.1745329251994329;
  data->modelData->realParameterData[374].time_unvarying = 1;
  (data->simulationInfo->realParameter[375] /* winRad.abs.radDat.psi[3] PARAM */) = 0.3490658503988659;
  data->modelData->realParameterData[375].time_unvarying = 1;
  (data->simulationInfo->realParameter[376] /* winRad.abs.radDat.psi[4] PARAM */) = 0.5235987755982988;
  data->modelData->realParameterData[376].time_unvarying = 1;
  (data->simulationInfo->realParameter[377] /* winRad.abs.radDat.psi[5] PARAM */) = 0.6981317007977318;
  data->modelData->realParameterData[377].time_unvarying = 1;
  (data->simulationInfo->realParameter[378] /* winRad.abs.radDat.psi[6] PARAM */) = 0.8726646259971648;
  data->modelData->realParameterData[378].time_unvarying = 1;
  (data->simulationInfo->realParameter[379] /* winRad.abs.radDat.psi[7] PARAM */) = 1.047197551196598;
  data->modelData->realParameterData[379].time_unvarying = 1;
  (data->simulationInfo->realParameter[380] /* winRad.abs.radDat.psi[8] PARAM */) = 1.221730476396031;
  data->modelData->realParameterData[380].time_unvarying = 1;
  (data->simulationInfo->realParameter[381] /* winRad.abs.radDat.psi[9] PARAM */) = 1.396263401595464;
  data->modelData->realParameterData[381].time_unvarying = 1;
  (data->simulationInfo->realParameter[382] /* winRad.abs.radDat.psi[10] PARAM */) = 1.570796326794897;
  data->modelData->realParameterData[382].time_unvarying = 1;
  (data->simulationInfo->realParameter[383] /* winRad.abs.radDat.rhoGlaSol_a[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[383].time_unvarying = 1;
  (data->simulationInfo->realParameter[384] /* winRad.abs.radDat.rhoGlaSol_a[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[384].time_unvarying = 1;
  (data->simulationInfo->realParameter[385] /* winRad.abs.radDat.rhoGlaSol_b[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[385].time_unvarying = 1;
  (data->simulationInfo->realParameter[386] /* winRad.abs.radDat.rhoGlaSol_b[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[386].time_unvarying = 1;
  (data->simulationInfo->realParameter[387] /* winRad.abs.radDat.rhoShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[387].time_unvarying = 1;
  (data->simulationInfo->realParameter[388] /* winRad.abs.radDat.rhoShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[388].time_unvarying = 1;
  (data->simulationInfo->realParameter[389] /* winRad.abs.radDat.tauGlaSol[1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[389].time_unvarying = 1;
  (data->simulationInfo->realParameter[390] /* winRad.abs.radDat.tauGlaSol[2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[390].time_unvarying = 1;
  (data->simulationInfo->realParameter[391] /* winRad.abs.radDat.tauShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[391].time_unvarying = 1;
  (data->simulationInfo->realParameter[392] /* winRad.abs.radDat.tauShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[392].time_unvarying = 1;
  (data->simulationInfo->realParameter[393] /* winRad.abs.radDat.traRef[1,1,1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[393].time_unvarying = 1;
  (data->simulationInfo->realParameter[394] /* winRad.abs.radDat.traRef[1,1,1,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[394].time_unvarying = 1;
  (data->simulationInfo->realParameter[395] /* winRad.abs.radDat.traRef[1,1,1,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[395].time_unvarying = 1;
  (data->simulationInfo->realParameter[396] /* winRad.abs.radDat.traRef[1,1,1,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[396].time_unvarying = 1;
  (data->simulationInfo->realParameter[397] /* winRad.abs.radDat.traRef[1,1,1,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[397].time_unvarying = 1;
  (data->simulationInfo->realParameter[398] /* winRad.abs.radDat.traRef[1,1,1,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[398].time_unvarying = 1;
  (data->simulationInfo->realParameter[399] /* winRad.abs.radDat.traRef[1,1,1,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[399].time_unvarying = 1;
  (data->simulationInfo->realParameter[400] /* winRad.abs.radDat.traRef[1,1,1,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[400].time_unvarying = 1;
  (data->simulationInfo->realParameter[401] /* winRad.abs.radDat.traRef[1,1,1,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[401].time_unvarying = 1;
  (data->simulationInfo->realParameter[402] /* winRad.abs.radDat.traRef[1,1,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[402].time_unvarying = 1;
  (data->simulationInfo->realParameter[403] /* winRad.abs.radDat.traRef[1,1,1,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[403].time_unvarying = 1;
  (data->simulationInfo->realParameter[404] /* winRad.abs.radDat.traRef[1,1,2,1,1] PARAM */) = 0.6994906348208673;
  data->modelData->realParameterData[404].time_unvarying = 1;
  (data->simulationInfo->realParameter[405] /* winRad.abs.radDat.traRef[1,1,2,2,1] PARAM */) = 0.6985663927869478;
  data->modelData->realParameterData[405].time_unvarying = 1;
  (data->simulationInfo->realParameter[406] /* winRad.abs.radDat.traRef[1,1,2,3,1] PARAM */) = 0.6953442572654116;
  data->modelData->realParameterData[406].time_unvarying = 1;
  (data->simulationInfo->realParameter[407] /* winRad.abs.radDat.traRef[1,1,2,4,1] PARAM */) = 0.6881649654297732;
  data->modelData->realParameterData[407].time_unvarying = 1;
  (data->simulationInfo->realParameter[408] /* winRad.abs.radDat.traRef[1,1,2,5,1] PARAM */) = 0.6729982692909955;
  data->modelData->realParameterData[408].time_unvarying = 1;
  (data->simulationInfo->realParameter[409] /* winRad.abs.radDat.traRef[1,1,2,6,1] PARAM */) = 0.6406823125211414;
  data->modelData->realParameterData[409].time_unvarying = 1;
  (data->simulationInfo->realParameter[410] /* winRad.abs.radDat.traRef[1,1,2,7,1] PARAM */) = 0.5716625309880206;
  data->modelData->realParameterData[410].time_unvarying = 1;
  (data->simulationInfo->realParameter[411] /* winRad.abs.radDat.traRef[1,1,2,8,1] PARAM */) = 0.4321138592586893;
  data->modelData->realParameterData[411].time_unvarying = 1;
  (data->simulationInfo->realParameter[412] /* winRad.abs.radDat.traRef[1,1,2,9,1] PARAM */) = 0.2011367960032149;
  data->modelData->realParameterData[412].time_unvarying = 1;
  (data->simulationInfo->realParameter[413] /* winRad.abs.radDat.traRef[1,1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[413].time_unvarying = 1;
  (data->simulationInfo->realParameter[414] /* winRad.abs.radDat.traRef[1,1,2,11,1] PARAM */) = 0.5777675151140318;
  data->modelData->realParameterData[414].time_unvarying = 1;
  (data->simulationInfo->realParameter[415] /* winRad.abs.radDat.traRef[1,2,1,1,1] PARAM */) = 0.6994906348208673;
  data->modelData->realParameterData[415].time_unvarying = 1;
  (data->simulationInfo->realParameter[416] /* winRad.abs.radDat.traRef[1,2,1,2,1] PARAM */) = 0.6985663927869478;
  data->modelData->realParameterData[416].time_unvarying = 1;
  (data->simulationInfo->realParameter[417] /* winRad.abs.radDat.traRef[1,2,1,3,1] PARAM */) = 0.6953442572654116;
  data->modelData->realParameterData[417].time_unvarying = 1;
  (data->simulationInfo->realParameter[418] /* winRad.abs.radDat.traRef[1,2,1,4,1] PARAM */) = 0.6881649654297732;
  data->modelData->realParameterData[418].time_unvarying = 1;
  (data->simulationInfo->realParameter[419] /* winRad.abs.radDat.traRef[1,2,1,5,1] PARAM */) = 0.6729982692909955;
  data->modelData->realParameterData[419].time_unvarying = 1;
  (data->simulationInfo->realParameter[420] /* winRad.abs.radDat.traRef[1,2,1,6,1] PARAM */) = 0.6406823125211414;
  data->modelData->realParameterData[420].time_unvarying = 1;
  (data->simulationInfo->realParameter[421] /* winRad.abs.radDat.traRef[1,2,1,7,1] PARAM */) = 0.5716625309880206;
  data->modelData->realParameterData[421].time_unvarying = 1;
  (data->simulationInfo->realParameter[422] /* winRad.abs.radDat.traRef[1,2,1,8,1] PARAM */) = 0.4321138592586893;
  data->modelData->realParameterData[422].time_unvarying = 1;
  (data->simulationInfo->realParameter[423] /* winRad.abs.radDat.traRef[1,2,1,9,1] PARAM */) = 0.2011367960032149;
  data->modelData->realParameterData[423].time_unvarying = 1;
  (data->simulationInfo->realParameter[424] /* winRad.abs.radDat.traRef[1,2,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[424].time_unvarying = 1;
  (data->simulationInfo->realParameter[425] /* winRad.abs.radDat.traRef[1,2,1,11,1] PARAM */) = 0.5777675151140318;
  data->modelData->realParameterData[425].time_unvarying = 1;
  (data->simulationInfo->realParameter[426] /* winRad.abs.radDat.traRef[1,2,2,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[426].time_unvarying = 1;
  (data->simulationInfo->realParameter[427] /* winRad.abs.radDat.traRef[1,2,2,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[427].time_unvarying = 1;
  (data->simulationInfo->realParameter[428] /* winRad.abs.radDat.traRef[1,2,2,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[428].time_unvarying = 1;
  (data->simulationInfo->realParameter[429] /* winRad.abs.radDat.traRef[1,2,2,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[429].time_unvarying = 1;
  (data->simulationInfo->realParameter[430] /* winRad.abs.radDat.traRef[1,2,2,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[430].time_unvarying = 1;
  (data->simulationInfo->realParameter[431] /* winRad.abs.radDat.traRef[1,2,2,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[431].time_unvarying = 1;
  (data->simulationInfo->realParameter[432] /* winRad.abs.radDat.traRef[1,2,2,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[432].time_unvarying = 1;
  (data->simulationInfo->realParameter[433] /* winRad.abs.radDat.traRef[1,2,2,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[433].time_unvarying = 1;
  (data->simulationInfo->realParameter[434] /* winRad.abs.radDat.traRef[1,2,2,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[434].time_unvarying = 1;
  (data->simulationInfo->realParameter[435] /* winRad.abs.radDat.traRef[1,2,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[435].time_unvarying = 1;
  (data->simulationInfo->realParameter[436] /* winRad.abs.radDat.traRef[1,2,2,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[436].time_unvarying = 1;
  (data->simulationInfo->realParameter[437] /* winRad.abs.radDat.traRef[2,1,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[437].time_unvarying = 1;
  (data->simulationInfo->realParameter[438] /* winRad.abs.radDat.traRef[2,1,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[438].time_unvarying = 1;
  (data->simulationInfo->realParameter[439] /* winRad.abs.radDat.traRef[2,1,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[439].time_unvarying = 1;
  (data->simulationInfo->realParameter[440] /* winRad.abs.radDat.traRef[2,1,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[440].time_unvarying = 1;
  (data->simulationInfo->realParameter[441] /* winRad.abs.radDat.traRef[2,1,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[441].time_unvarying = 1;
  (data->simulationInfo->realParameter[442] /* winRad.abs.radDat.traRef[2,1,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[442].time_unvarying = 1;
  (data->simulationInfo->realParameter[443] /* winRad.abs.radDat.traRef[2,1,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[443].time_unvarying = 1;
  (data->simulationInfo->realParameter[444] /* winRad.abs.radDat.traRef[2,1,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[444].time_unvarying = 1;
  (data->simulationInfo->realParameter[445] /* winRad.abs.radDat.traRef[2,1,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[445].time_unvarying = 1;
  (data->simulationInfo->realParameter[446] /* winRad.abs.radDat.traRef[2,1,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[446].time_unvarying = 1;
  (data->simulationInfo->realParameter[447] /* winRad.abs.radDat.traRef[2,1,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[447].time_unvarying = 1;
  (data->simulationInfo->realParameter[448] /* winRad.abs.radDat.traRef[2,1,2,1,1] PARAM */) = 0.127461797611565;
  data->modelData->realParameterData[448].time_unvarying = 1;
  (data->simulationInfo->realParameter[449] /* winRad.abs.radDat.traRef[2,1,2,2,1] PARAM */) = 0.1273615206111159;
  data->modelData->realParameterData[449].time_unvarying = 1;
  (data->simulationInfo->realParameter[450] /* winRad.abs.radDat.traRef[2,1,2,3,1] PARAM */) = 0.1275322917190642;
  data->modelData->realParameterData[450].time_unvarying = 1;
  (data->simulationInfo->realParameter[451] /* winRad.abs.radDat.traRef[2,1,2,4,1] PARAM */) = 0.1297280574286503;
  data->modelData->realParameterData[451].time_unvarying = 1;
  (data->simulationInfo->realParameter[452] /* winRad.abs.radDat.traRef[2,1,2,5,1] PARAM */) = 0.1382440338153747;
  data->modelData->realParameterData[452].time_unvarying = 1;
  (data->simulationInfo->realParameter[453] /* winRad.abs.radDat.traRef[2,1,2,6,1] PARAM */) = 0.1628935363465329;
  data->modelData->realParameterData[453].time_unvarying = 1;
  (data->simulationInfo->realParameter[454] /* winRad.abs.radDat.traRef[2,1,2,7,1] PARAM */) = 0.2247377823311878;
  data->modelData->realParameterData[454].time_unvarying = 1;
  (data->simulationInfo->realParameter[455] /* winRad.abs.radDat.traRef[2,1,2,8,1] PARAM */) = 0.3612313008417883;
  data->modelData->realParameterData[455].time_unvarying = 1;
  (data->simulationInfo->realParameter[456] /* winRad.abs.radDat.traRef[2,1,2,9,1] PARAM */) = 0.6052446087035255;
  data->modelData->realParameterData[456].time_unvarying = 1;
  (data->simulationInfo->realParameter[457] /* winRad.abs.radDat.traRef[2,1,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[457].time_unvarying = 1;
  (data->simulationInfo->realParameter[458] /* winRad.abs.radDat.traRef[2,1,2,11,1] PARAM */) = 0.2142436332900854;
  data->modelData->realParameterData[458].time_unvarying = 1;
  (data->simulationInfo->realParameter[459] /* winRad.abs.radDat.traRef[2,2,1,1,1] PARAM */) = 0.0;
  data->modelData->realParameterData[459].time_unvarying = 1;
  (data->simulationInfo->realParameter[460] /* winRad.abs.radDat.traRef[2,2,1,2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[460].time_unvarying = 1;
  (data->simulationInfo->realParameter[461] /* winRad.abs.radDat.traRef[2,2,1,3,1] PARAM */) = 0.0;
  data->modelData->realParameterData[461].time_unvarying = 1;
  (data->simulationInfo->realParameter[462] /* winRad.abs.radDat.traRef[2,2,1,4,1] PARAM */) = 0.0;
  data->modelData->realParameterData[462].time_unvarying = 1;
  (data->simulationInfo->realParameter[463] /* winRad.abs.radDat.traRef[2,2,1,5,1] PARAM */) = 0.0;
  data->modelData->realParameterData[463].time_unvarying = 1;
  (data->simulationInfo->realParameter[464] /* winRad.abs.radDat.traRef[2,2,1,6,1] PARAM */) = 0.0;
  data->modelData->realParameterData[464].time_unvarying = 1;
  (data->simulationInfo->realParameter[465] /* winRad.abs.radDat.traRef[2,2,1,7,1] PARAM */) = 0.0;
  data->modelData->realParameterData[465].time_unvarying = 1;
  (data->simulationInfo->realParameter[466] /* winRad.abs.radDat.traRef[2,2,1,8,1] PARAM */) = 0.0;
  data->modelData->realParameterData[466].time_unvarying = 1;
  (data->simulationInfo->realParameter[467] /* winRad.abs.radDat.traRef[2,2,1,9,1] PARAM */) = 0.0;
  data->modelData->realParameterData[467].time_unvarying = 1;
  (data->simulationInfo->realParameter[468] /* winRad.abs.radDat.traRef[2,2,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[468].time_unvarying = 1;
  (data->simulationInfo->realParameter[469] /* winRad.abs.radDat.traRef[2,2,1,11,1] PARAM */) = 0.0;
  data->modelData->realParameterData[469].time_unvarying = 1;
  (data->simulationInfo->realParameter[470] /* winRad.abs.radDat.traRef[2,2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[470].time_unvarying = 1;
  (data->simulationInfo->realParameter[471] /* winRad.abs.radDat.traRef[2,2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[471].time_unvarying = 1;
  (data->simulationInfo->realParameter[472] /* winRad.abs.radDat.traRef[2,2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[472].time_unvarying = 1;
  (data->simulationInfo->realParameter[473] /* winRad.abs.radDat.traRef[2,2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[473].time_unvarying = 1;
  (data->simulationInfo->realParameter[474] /* winRad.abs.radDat.traRef[2,2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[474].time_unvarying = 1;
  (data->simulationInfo->realParameter[475] /* winRad.abs.radDat.traRef[2,2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[475].time_unvarying = 1;
  (data->simulationInfo->realParameter[476] /* winRad.abs.radDat.traRef[2,2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[476].time_unvarying = 1;
  (data->simulationInfo->realParameter[477] /* winRad.abs.radDat.traRef[2,2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[477].time_unvarying = 1;
  (data->simulationInfo->realParameter[478] /* winRad.abs.radDat.traRef[2,2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[478].time_unvarying = 1;
  (data->simulationInfo->realParameter[479] /* winRad.abs.radDat.traRef[2,2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[479].time_unvarying = 1;
  (data->simulationInfo->realParameter[480] /* winRad.abs.radDat.traRef[2,2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[480].time_unvarying = 1;
  (data->simulationInfo->realParameter[481] /* winRad.abs.radDat.traRef[3,1,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[481].time_unvarying = 1;
  (data->simulationInfo->realParameter[482] /* winRad.abs.radDat.traRef[3,1,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[482].time_unvarying = 1;
  (data->simulationInfo->realParameter[483] /* winRad.abs.radDat.traRef[3,1,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[483].time_unvarying = 1;
  (data->simulationInfo->realParameter[484] /* winRad.abs.radDat.traRef[3,1,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[484].time_unvarying = 1;
  (data->simulationInfo->realParameter[485] /* winRad.abs.radDat.traRef[3,1,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[485].time_unvarying = 1;
  (data->simulationInfo->realParameter[486] /* winRad.abs.radDat.traRef[3,1,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[486].time_unvarying = 1;
  (data->simulationInfo->realParameter[487] /* winRad.abs.radDat.traRef[3,1,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[487].time_unvarying = 1;
  (data->simulationInfo->realParameter[488] /* winRad.abs.radDat.traRef[3,1,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[488].time_unvarying = 1;
  (data->simulationInfo->realParameter[489] /* winRad.abs.radDat.traRef[3,1,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[489].time_unvarying = 1;
  (data->simulationInfo->realParameter[490] /* winRad.abs.radDat.traRef[3,1,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[490].time_unvarying = 1;
  (data->simulationInfo->realParameter[491] /* winRad.abs.radDat.traRef[3,1,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[491].time_unvarying = 1;
  (data->simulationInfo->realParameter[492] /* winRad.abs.radDat.traRef[3,1,2,1,1] PARAM */) = 0.0;
  data->modelData->realParameterData[492].time_unvarying = 1;
  (data->simulationInfo->realParameter[493] /* winRad.abs.radDat.traRef[3,1,2,2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[493].time_unvarying = 1;
  (data->simulationInfo->realParameter[494] /* winRad.abs.radDat.traRef[3,1,2,3,1] PARAM */) = 0.0;
  data->modelData->realParameterData[494].time_unvarying = 1;
  (data->simulationInfo->realParameter[495] /* winRad.abs.radDat.traRef[3,1,2,4,1] PARAM */) = 0.0;
  data->modelData->realParameterData[495].time_unvarying = 1;
  (data->simulationInfo->realParameter[496] /* winRad.abs.radDat.traRef[3,1,2,5,1] PARAM */) = 0.0;
  data->modelData->realParameterData[496].time_unvarying = 1;
  (data->simulationInfo->realParameter[497] /* winRad.abs.radDat.traRef[3,1,2,6,1] PARAM */) = 0.0;
  data->modelData->realParameterData[497].time_unvarying = 1;
  (data->simulationInfo->realParameter[498] /* winRad.abs.radDat.traRef[3,1,2,7,1] PARAM */) = 0.0;
  data->modelData->realParameterData[498].time_unvarying = 1;
  (data->simulationInfo->realParameter[499] /* winRad.abs.radDat.traRef[3,1,2,8,1] PARAM */) = 0.0;
  data->modelData->realParameterData[499].time_unvarying = 1;
  (data->simulationInfo->realParameter[500] /* winRad.abs.radDat.traRef[3,1,2,9,1] PARAM */) = 0.0;
  data->modelData->realParameterData[500].time_unvarying = 1;
  (data->simulationInfo->realParameter[501] /* winRad.abs.radDat.traRef[3,1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[501].time_unvarying = 1;
  (data->simulationInfo->realParameter[502] /* winRad.abs.radDat.traRef[3,1,2,11,1] PARAM */) = 0.0;
  data->modelData->realParameterData[502].time_unvarying = 1;
  (data->simulationInfo->realParameter[503] /* winRad.abs.radDat.traRef[3,2,1,1,1] PARAM */) = 0.127461797611565;
  data->modelData->realParameterData[503].time_unvarying = 1;
  (data->simulationInfo->realParameter[504] /* winRad.abs.radDat.traRef[3,2,1,2,1] PARAM */) = 0.1273615206111159;
  data->modelData->realParameterData[504].time_unvarying = 1;
  (data->simulationInfo->realParameter[505] /* winRad.abs.radDat.traRef[3,2,1,3,1] PARAM */) = 0.1275322917190642;
  data->modelData->realParameterData[505].time_unvarying = 1;
  (data->simulationInfo->realParameter[506] /* winRad.abs.radDat.traRef[3,2,1,4,1] PARAM */) = 0.1297280574286503;
  data->modelData->realParameterData[506].time_unvarying = 1;
  (data->simulationInfo->realParameter[507] /* winRad.abs.radDat.traRef[3,2,1,5,1] PARAM */) = 0.1382440338153747;
  data->modelData->realParameterData[507].time_unvarying = 1;
  (data->simulationInfo->realParameter[508] /* winRad.abs.radDat.traRef[3,2,1,6,1] PARAM */) = 0.1628935363465329;
  data->modelData->realParameterData[508].time_unvarying = 1;
  (data->simulationInfo->realParameter[509] /* winRad.abs.radDat.traRef[3,2,1,7,1] PARAM */) = 0.2247377823311878;
  data->modelData->realParameterData[509].time_unvarying = 1;
  (data->simulationInfo->realParameter[510] /* winRad.abs.radDat.traRef[3,2,1,8,1] PARAM */) = 0.3612313008417883;
  data->modelData->realParameterData[510].time_unvarying = 1;
  (data->simulationInfo->realParameter[511] /* winRad.abs.radDat.traRef[3,2,1,9,1] PARAM */) = 0.6052446087035255;
  data->modelData->realParameterData[511].time_unvarying = 1;
  (data->simulationInfo->realParameter[512] /* winRad.abs.radDat.traRef[3,2,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[512].time_unvarying = 1;
  (data->simulationInfo->realParameter[513] /* winRad.abs.radDat.traRef[3,2,1,11,1] PARAM */) = 0.2142436332900854;
  data->modelData->realParameterData[513].time_unvarying = 1;
  (data->simulationInfo->realParameter[514] /* winRad.abs.radDat.traRef[3,2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[514].time_unvarying = 1;
  (data->simulationInfo->realParameter[515] /* winRad.abs.radDat.traRef[3,2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[515].time_unvarying = 1;
  (data->simulationInfo->realParameter[516] /* winRad.abs.radDat.traRef[3,2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[516].time_unvarying = 1;
  (data->simulationInfo->realParameter[517] /* winRad.abs.radDat.traRef[3,2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[517].time_unvarying = 1;
  (data->simulationInfo->realParameter[518] /* winRad.abs.radDat.traRef[3,2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[518].time_unvarying = 1;
  (data->simulationInfo->realParameter[519] /* winRad.abs.radDat.traRef[3,2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[519].time_unvarying = 1;
  (data->simulationInfo->realParameter[520] /* winRad.abs.radDat.traRef[3,2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[520].time_unvarying = 1;
  (data->simulationInfo->realParameter[521] /* winRad.abs.radDat.traRef[3,2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[521].time_unvarying = 1;
  (data->simulationInfo->realParameter[522] /* winRad.abs.radDat.traRef[3,2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[522].time_unvarying = 1;
  (data->simulationInfo->realParameter[523] /* winRad.abs.radDat.traRef[3,2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[523].time_unvarying = 1;
  (data->simulationInfo->realParameter[524] /* winRad.abs.radDat.traRef[3,2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[524].time_unvarying = 1;
  (data->simulationInfo->realParameter[525] /* winRad.abs.radDat.traRefShaDev[1,1] PARAM */) = 0.25;
  data->modelData->realParameterData[525].time_unvarying = 1;
  (data->simulationInfo->realParameter[526] /* winRad.abs.radDat.traRefShaDev[1,2] PARAM */) = 0.25;
  data->modelData->realParameterData[526].time_unvarying = 1;
  (data->simulationInfo->realParameter[527] /* winRad.abs.radDat.traRefShaDev[2,1] PARAM */) = 0.25;
  data->modelData->realParameterData[527].time_unvarying = 1;
  (data->simulationInfo->realParameter[528] /* winRad.abs.radDat.traRefShaDev[2,2] PARAM */) = 0.25;
  data->modelData->realParameterData[528].time_unvarying = 1;
  (data->simulationInfo->realParameter[529] /* winRad.abs.radDat.winTraExtIrrExtSha[1,1] PARAM */) = 0.1807604077499478;
  data->modelData->realParameterData[529].time_unvarying = 1;
  (data->simulationInfo->realParameter[530] /* winRad.abs.radDat.winTraExtIrrExtSha[2,1] PARAM */) = 0.1805169418146947;
  data->modelData->realParameterData[530].time_unvarying = 1;
  (data->simulationInfo->realParameter[531] /* winRad.abs.radDat.winTraExtIrrExtSha[3,1] PARAM */) = 0.1796921494729775;
  data->modelData->realParameterData[531].time_unvarying = 1;
  (data->simulationInfo->realParameter[532] /* winRad.abs.radDat.winTraExtIrrExtSha[4,1] PARAM */) = 0.1779366487415986;
  data->modelData->realParameterData[532].time_unvarying = 1;
  (data->simulationInfo->realParameter[533] /* winRad.abs.radDat.winTraExtIrrExtSha[5,1] PARAM */) = 0.1743935175988208;
  data->modelData->realParameterData[533].time_unvarying = 1;
  (data->simulationInfo->realParameter[534] /* winRad.abs.radDat.winTraExtIrrExtSha[6,1] PARAM */) = 0.1670623982483838;
  data->modelData->realParameterData[534].time_unvarying = 1;
  (data->simulationInfo->realParameter[535] /* winRad.abs.radDat.winTraExtIrrExtSha[7,1] PARAM */) = 0.1513996817065354;
  data->modelData->realParameterData[535].time_unvarying = 1;
  (data->simulationInfo->realParameter[536] /* winRad.abs.radDat.winTraExtIrrExtSha[8,1] PARAM */) = 0.1183363819368878;
  data->modelData->realParameterData[536].time_unvarying = 1;
  (data->simulationInfo->realParameter[537] /* winRad.abs.radDat.winTraExtIrrExtSha[9,1] PARAM */) = 0.05832334293934013;
  data->modelData->realParameterData[537].time_unvarying = 1;
  (data->simulationInfo->realParameter[538] /* winRad.abs.radDat.winTraExtIrrExtSha[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[538].time_unvarying = 1;
  (data->simulationInfo->realParameter[539] /* winRad.abs.radDat.winTraExtIrrExtSha[11,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[539].time_unvarying = 1;
  (data->simulationInfo->realParameter[540] /* winRad.abs.radDat.winTraExtIrrIntSha[1,1] PARAM */) = 0.1847690572409374;
  data->modelData->realParameterData[540].time_unvarying = 1;
  (data->simulationInfo->realParameter[541] /* winRad.abs.radDat.winTraExtIrrIntSha[2,1] PARAM */) = 0.1845249205495098;
  data->modelData->realParameterData[541].time_unvarying = 1;
  (data->simulationInfo->realParameter[542] /* winRad.abs.radDat.winTraExtIrrIntSha[3,1] PARAM */) = 0.1836737998725771;
  data->modelData->realParameterData[542].time_unvarying = 1;
  (data->simulationInfo->realParameter[543] /* winRad.abs.radDat.winTraExtIrrIntSha[4,1] PARAM */) = 0.1817774042411072;
  data->modelData->realParameterData[543].time_unvarying = 1;
  (data->simulationInfo->realParameter[544] /* winRad.abs.radDat.winTraExtIrrIntSha[5,1] PARAM */) = 0.1777711516802857;
  data->modelData->realParameterData[544].time_unvarying = 1;
  (data->simulationInfo->realParameter[545] /* winRad.abs.radDat.winTraExtIrrIntSha[6,1] PARAM */) = 0.1692349560988624;
  data->modelData->realParameterData[545].time_unvarying = 1;
  (data->simulationInfo->realParameter[546] /* winRad.abs.radDat.winTraExtIrrIntSha[7,1] PARAM */) = 0.1510035183497123;
  data->modelData->realParameterData[546].time_unvarying = 1;
  (data->simulationInfo->realParameter[547] /* winRad.abs.radDat.winTraExtIrrIntSha[8,1] PARAM */) = 0.1141420148054129;
  data->modelData->realParameterData[547].time_unvarying = 1;
  (data->simulationInfo->realParameter[548] /* winRad.abs.radDat.winTraExtIrrIntSha[9,1] PARAM */) = 0.05312988383825046;
  data->modelData->realParameterData[548].time_unvarying = 1;
  (data->simulationInfo->realParameter[549] /* winRad.abs.radDat.winTraExtIrrIntSha[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[549].time_unvarying = 1;
  (data->simulationInfo->realParameter[550] /* winRad.abs.radDat.winTraExtIrrIntSha[11,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[550].time_unvarying = 1;
  (data->simulationInfo->realParameter[551] /* winRad.abs.radDat.winTraRefIntIrrExtSha[1,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[551].time_unvarying = 1;
  (data->simulationInfo->realParameter[552] /* winRad.abs.radDat.winTraRefIntIrrExtSha[2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[552].time_unvarying = 1;
  (data->simulationInfo->realParameter[553] /* winRad.abs.radDat.winTraRefIntIrrExtSha[3,1] PARAM */) = 0.302420279958754;
  data->modelData->realParameterData[553].time_unvarying = 1;
  (data->simulationInfo->realParameter[554] /* winRad.abs.radDat.winTraRefIntIrrIntSha[1,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[554].time_unvarying = 1;
  (data->simulationInfo->realParameter[555] /* winRad.abs.radDat.winTraRefIntIrrIntSha[2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[555].time_unvarying = 1;
  (data->simulationInfo->realParameter[556] /* winRad.abs.radDat.winTraRefIntIrrIntSha[3,1] PARAM */) = 0.2641480071970583;
  data->modelData->realParameterData[556].time_unvarying = 1;
  (data->simulationInfo->realParameter[557] /* winRad.abs.radDat.xGla[1] PARAM */) = 0.003;
  data->modelData->realParameterData[557].time_unvarying = 1;
  (data->simulationInfo->realParameter[558] /* winRad.abs.radDat.xGla[2] PARAM */) = 0.003;
  data->modelData->realParameterData[558].time_unvarying = 1;
  (data->simulationInfo->realParameter[559] /* winRad.abs.rhoGlaSol_a[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[559].time_unvarying = 1;
  (data->simulationInfo->realParameter[560] /* winRad.abs.rhoGlaSol_a[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[560].time_unvarying = 1;
  (data->simulationInfo->realParameter[561] /* winRad.abs.rhoGlaSol_b[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[561].time_unvarying = 1;
  (data->simulationInfo->realParameter[562] /* winRad.abs.rhoGlaSol_b[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[562].time_unvarying = 1;
  (data->simulationInfo->realParameter[563] /* winRad.abs.rhoShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[563].time_unvarying = 1;
  (data->simulationInfo->realParameter[564] /* winRad.abs.rhoShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[564].time_unvarying = 1;
  (data->simulationInfo->realParameter[565] /* winRad.abs.tauGlaSol[1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[565].time_unvarying = 1;
  (data->simulationInfo->realParameter[566] /* winRad.abs.tauGlaSol[2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[566].time_unvarying = 1;
  (data->simulationInfo->realParameter[567] /* winRad.abs.tauShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[567].time_unvarying = 1;
  (data->simulationInfo->realParameter[568] /* winRad.abs.tauShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[568].time_unvarying = 1;
  (data->simulationInfo->realParameter[569] /* winRad.abs.xGla[1] PARAM */) = 0.003;
  data->modelData->realParameterData[569].time_unvarying = 1;
  (data->simulationInfo->realParameter[570] /* winRad.abs.xGla[2] PARAM */) = 0.003;
  data->modelData->realParameterData[570].time_unvarying = 1;
  (data->simulationInfo->realParameter[571] /* winRad.radDat.absExtIrrExtSha[1,1,1] PARAM */) = 0.02499520908519422;
  data->modelData->realParameterData[571].time_unvarying = 1;
  (data->simulationInfo->realParameter[572] /* winRad.radDat.absExtIrrExtSha[1,2,1] PARAM */) = 0.02514929957574206;
  data->modelData->realParameterData[572].time_unvarying = 1;
  (data->simulationInfo->realParameter[573] /* winRad.radDat.absExtIrrExtSha[1,3,1] PARAM */) = 0.02561776873020298;
  data->modelData->realParameterData[573].time_unvarying = 1;
  (data->simulationInfo->realParameter[574] /* winRad.radDat.absExtIrrExtSha[1,4,1] PARAM */) = 0.02642332367824236;
  data->modelData->realParameterData[574].time_unvarying = 1;
  (data->simulationInfo->realParameter[575] /* winRad.radDat.absExtIrrExtSha[1,5,1] PARAM */) = 0.0276225173612099;
  data->modelData->realParameterData[575].time_unvarying = 1;
  (data->simulationInfo->realParameter[576] /* winRad.radDat.absExtIrrExtSha[1,6,1] PARAM */) = 0.02935337359634402;
  data->modelData->realParameterData[576].time_unvarying = 1;
  (data->simulationInfo->realParameter[577] /* winRad.radDat.absExtIrrExtSha[1,7,1] PARAM */) = 0.03193076631094863;
  data->modelData->realParameterData[577].time_unvarying = 1;
  (data->simulationInfo->realParameter[578] /* winRad.radDat.absExtIrrExtSha[1,8,1] PARAM */) = 0.03581982523119827;
  data->modelData->realParameterData[578].time_unvarying = 1;
  (data->simulationInfo->realParameter[579] /* winRad.radDat.absExtIrrExtSha[1,9,1] PARAM */) = 0.03977435612665067;
  data->modelData->realParameterData[579].time_unvarying = 1;
  (data->simulationInfo->realParameter[580] /* winRad.radDat.absExtIrrExtSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[580].time_unvarying = 1;
  (data->simulationInfo->realParameter[581] /* winRad.radDat.absExtIrrExtSha[1,11,1] PARAM */) = 0.03241615014704199;
  data->modelData->realParameterData[581].time_unvarying = 1;
  (data->simulationInfo->realParameter[582] /* winRad.radDat.absExtIrrExtSha[2,1,1] PARAM */) = 0.01972325791995835;
  data->modelData->realParameterData[582].time_unvarying = 1;
  (data->simulationInfo->realParameter[583] /* winRad.radDat.absExtIrrExtSha[2,2,1] PARAM */) = 0.01983276806040852;
  data->modelData->realParameterData[583].time_unvarying = 1;
  (data->simulationInfo->realParameter[584] /* winRad.radDat.absExtIrrExtSha[2,3,1] PARAM */) = 0.02015480119109085;
  data->modelData->realParameterData[584].time_unvarying = 1;
  (data->simulationInfo->realParameter[585] /* winRad.radDat.absExtIrrExtSha[2,4,1] PARAM */) = 0.02066350412154015;
  data->modelData->realParameterData[585].time_unvarying = 1;
  (data->simulationInfo->realParameter[586] /* winRad.radDat.absExtIrrExtSha[2,5,1] PARAM */) = 0.02129011768881981;
  data->modelData->realParameterData[586].time_unvarying = 1;
  (data->simulationInfo->realParameter[587] /* winRad.radDat.absExtIrrExtSha[2,6,1] PARAM */) = 0.02186559892833682;
  data->modelData->realParameterData[587].time_unvarying = 1;
  (data->simulationInfo->realParameter[588] /* winRad.radDat.absExtIrrExtSha[2,7,1] PARAM */) = 0.0219907802101197;
  data->modelData->realParameterData[588].time_unvarying = 1;
  (data->simulationInfo->realParameter[589] /* winRad.radDat.absExtIrrExtSha[2,8,1] PARAM */) = 0.02077355991365581;
  data->modelData->realParameterData[589].time_unvarying = 1;
  (data->simulationInfo->realParameter[590] /* winRad.radDat.absExtIrrExtSha[2,9,1] PARAM */) = 0.01636894513455467;
  data->modelData->realParameterData[590].time_unvarying = 1;
  (data->simulationInfo->realParameter[591] /* winRad.radDat.absExtIrrExtSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[591].time_unvarying = 1;
  (data->simulationInfo->realParameter[592] /* winRad.radDat.absExtIrrExtSha[2,11,1] PARAM */) = 0.02252369052121515;
  data->modelData->realParameterData[592].time_unvarying = 1;
  (data->simulationInfo->realParameter[593] /* winRad.radDat.absExtIrrIntSha[1,1,1] PARAM */) = 0.1093863539769833;
  data->modelData->realParameterData[593].time_unvarying = 1;
  (data->simulationInfo->realParameter[594] /* winRad.radDat.absExtIrrIntSha[1,2,1] PARAM */) = 0.1100473669610094;
  data->modelData->realParameterData[594].time_unvarying = 1;
  (data->simulationInfo->realParameter[595] /* winRad.radDat.absExtIrrIntSha[1,3,1] PARAM */) = 0.1120318818175741;
  data->modelData->realParameterData[595].time_unvarying = 1;
  (data->simulationInfo->realParameter[596] /* winRad.radDat.absExtIrrIntSha[1,4,1] PARAM */) = 0.1153398886779867;
  data->modelData->realParameterData[596].time_unvarying = 1;
  (data->simulationInfo->realParameter[597] /* winRad.radDat.absExtIrrIntSha[1,5,1] PARAM */) = 0.1199592159293939;
  data->modelData->realParameterData[597].time_unvarying = 1;
  (data->simulationInfo->realParameter[598] /* winRad.radDat.absExtIrrIntSha[1,6,1] PARAM */) = 0.1258553503945128;
  data->modelData->realParameterData[598].time_unvarying = 1;
  (data->simulationInfo->realParameter[599] /* winRad.radDat.absExtIrrIntSha[1,7,1] PARAM */) = 0.1329258880977036;
  data->modelData->realParameterData[599].time_unvarying = 1;
  (data->simulationInfo->realParameter[600] /* winRad.radDat.absExtIrrIntSha[1,8,1] PARAM */) = 0.1403970614972095;
  data->modelData->realParameterData[600].time_unvarying = 1;
  (data->simulationInfo->realParameter[601] /* winRad.radDat.absExtIrrIntSha[1,9,1] PARAM */) = 0.1415178832813775;
  data->modelData->realParameterData[601].time_unvarying = 1;
  (data->simulationInfo->realParameter[602] /* winRad.radDat.absExtIrrIntSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[602].time_unvarying = 1;
  (data->simulationInfo->realParameter[603] /* winRad.radDat.absExtIrrIntSha[1,11,1] PARAM */) = 0.1354931525419724;
  data->modelData->realParameterData[603].time_unvarying = 1;
  (data->simulationInfo->realParameter[604] /* winRad.radDat.absExtIrrIntSha[2,1,1] PARAM */) = 0.0948566787482195;
  data->modelData->realParameterData[604].time_unvarying = 1;
  (data->simulationInfo->realParameter[605] /* winRad.radDat.absExtIrrIntSha[2,2,1] PARAM */) = 0.09537350821079466;
  data->modelData->realParameterData[605].time_unvarying = 1;
  (data->simulationInfo->realParameter[606] /* winRad.radDat.absExtIrrIntSha[2,3,1] PARAM */) = 0.09687385356797265;
  data->modelData->realParameterData[606].time_unvarying = 1;
  (data->simulationInfo->realParameter[607] /* winRad.radDat.absExtIrrIntSha[2,4,1] PARAM */) = 0.09916070692199794;
  data->modelData->realParameterData[607].time_unvarying = 1;
  (data->simulationInfo->realParameter[608] /* winRad.radDat.absExtIrrIntSha[2,5,1] PARAM */) = 0.1017176618131253;
  data->modelData->realParameterData[608].time_unvarying = 1;
  (data->simulationInfo->realParameter[609] /* winRad.radDat.absExtIrrIntSha[2,6,1] PARAM */) = 0.1033001439761687;
  data->modelData->realParameterData[609].time_unvarying = 1;
  (data->simulationInfo->realParameter[610] /* winRad.radDat.absExtIrrIntSha[2,7,1] PARAM */) = 0.1011252056324434;
  data->modelData->realParameterData[610].time_unvarying = 1;
  (data->simulationInfo->realParameter[611] /* winRad.radDat.absExtIrrIntSha[2,8,1] PARAM */) = 0.08990517963983256;
  data->modelData->realParameterData[611].time_unvarying = 1;
  (data->simulationInfo->realParameter[612] /* winRad.radDat.absExtIrrIntSha[2,9,1] PARAM */) = 0.06281787526849789;
  data->modelData->realParameterData[612].time_unvarying = 1;
  (data->simulationInfo->realParameter[613] /* winRad.radDat.absExtIrrIntSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[613].time_unvarying = 1;
  (data->simulationInfo->realParameter[614] /* winRad.radDat.absExtIrrIntSha[2,11,1] PARAM */) = 0.1039656205865592;
  data->modelData->realParameterData[614].time_unvarying = 1;
  (data->simulationInfo->realParameter[615] /* winRad.radDat.absExtIrrNoSha[1,1,1] PARAM */) = 0.0967242489000629;
  data->modelData->realParameterData[615].time_unvarying = 1;
  (data->simulationInfo->realParameter[616] /* winRad.radDat.absExtIrrNoSha[1,2,1] PARAM */) = 0.09732302857079711;
  data->modelData->realParameterData[616].time_unvarying = 1;
  (data->simulationInfo->realParameter[617] /* winRad.radDat.absExtIrrNoSha[1,3,1] PARAM */) = 0.09913158934736244;
  data->modelData->realParameterData[617].time_unvarying = 1;
  (data->simulationInfo->realParameter[618] /* winRad.radDat.absExtIrrNoSha[1,4,1] PARAM */) = 0.1021914583318008;
  data->modelData->realParameterData[618].time_unvarying = 1;
  (data->simulationInfo->realParameter[619] /* winRad.radDat.absExtIrrNoSha[1,5,1] PARAM */) = 0.1065974620703473;
  data->modelData->realParameterData[619].time_unvarying = 1;
  (data->simulationInfo->realParameter[620] /* winRad.radDat.absExtIrrNoSha[1,6,1] PARAM */) = 0.1125698390133378;
  data->modelData->realParameterData[620].time_unvarying = 1;
  (data->simulationInfo->realParameter[621] /* winRad.radDat.absExtIrrNoSha[1,7,1] PARAM */) = 0.1205657930053361;
  data->modelData->realParameterData[621].time_unvarying = 1;
  (data->simulationInfo->realParameter[622] /* winRad.radDat.absExtIrrNoSha[1,8,1] PARAM */) = 0.1307986830869973;
  data->modelData->realParameterData[622].time_unvarying = 1;
  (data->simulationInfo->realParameter[623] /* winRad.radDat.absExtIrrNoSha[1,9,1] PARAM */) = 0.1371678328302604;
  data->modelData->realParameterData[623].time_unvarying = 1;
  (data->simulationInfo->realParameter[624] /* winRad.radDat.absExtIrrNoSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[624].time_unvarying = 1;
  (data->simulationInfo->realParameter[625] /* winRad.radDat.absExtIrrNoSha[1,11,1] PARAM */) = 0.1227196468033888;
  data->modelData->realParameterData[625].time_unvarying = 1;
  (data->simulationInfo->realParameter[626] /* winRad.radDat.absExtIrrNoSha[2,1,1] PARAM */) = 0.07632331866750475;
  data->modelData->realParameterData[626].time_unvarying = 1;
  (data->simulationInfo->realParameter[627] /* winRad.radDat.absExtIrrNoSha[2,2,1] PARAM */) = 0.07674905803113916;
  data->modelData->realParameterData[627].time_unvarying = 1;
  (data->simulationInfo->realParameter[628] /* winRad.radDat.absExtIrrNoSha[2,3,1] PARAM */) = 0.07799186166816173;
  data->modelData->realParameterData[628].time_unvarying = 1;
  (data->simulationInfo->realParameter[629] /* winRad.radDat.absExtIrrNoSha[2,4,1] PARAM */) = 0.07991551880977556;
  data->modelData->realParameterData[629].time_unvarying = 1;
  (data->simulationInfo->realParameter[630] /* winRad.radDat.absExtIrrNoSha[2,5,1] PARAM */) = 0.08216023482328237;
  data->modelData->realParameterData[630].time_unvarying = 1;
  (data->simulationInfo->realParameter[631] /* winRad.radDat.absExtIrrNoSha[2,6,1] PARAM */) = 0.08385431211898785;
  data->modelData->realParameterData[631].time_unvarying = 1;
  (data->simulationInfo->realParameter[632] /* winRad.radDat.absExtIrrNoSha[2,7,1] PARAM */) = 0.08303389367545573;
  data->modelData->realParameterData[632].time_unvarying = 1;
  (data->simulationInfo->realParameter[633] /* winRad.radDat.absExtIrrNoSha[2,8,1] PARAM */) = 0.07585615681252504;
  data->modelData->realParameterData[633].time_unvarying = 1;
  (data->simulationInfo->realParameter[634] /* winRad.radDat.absExtIrrNoSha[2,9,1] PARAM */) = 0.05645076246299933;
  data->modelData->realParameterData[634].time_unvarying = 1;
  (data->simulationInfo->realParameter[635] /* winRad.radDat.absExtIrrNoSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[635].time_unvarying = 1;
  (data->simulationInfo->realParameter[636] /* winRad.radDat.absExtIrrNoSha[2,11,1] PARAM */) = 0.08526920479249403;
  data->modelData->realParameterData[636].time_unvarying = 1;
  (data->simulationInfo->realParameter[637] /* winRad.radDat.absIntIrrExtSha[1,1] PARAM */) = 0.1039656205865592;
  data->modelData->realParameterData[637].time_unvarying = 1;
  (data->simulationInfo->realParameter[638] /* winRad.radDat.absIntIrrExtSha[2,1] PARAM */) = 0.1354931525419724;
  data->modelData->realParameterData[638].time_unvarying = 1;
  (data->simulationInfo->realParameter[639] /* winRad.radDat.absIntIrrIntSha[1,1] PARAM */) = 0.02252369052121515;
  data->modelData->realParameterData[639].time_unvarying = 1;
  (data->simulationInfo->realParameter[640] /* winRad.radDat.absIntIrrIntSha[2,1] PARAM */) = 0.03241615014704199;
  data->modelData->realParameterData[640].time_unvarying = 1;
  (data->simulationInfo->realParameter[641] /* winRad.radDat.absIntIrrNoSha[1,1] PARAM */) = 0.08526920479249403;
  data->modelData->realParameterData[641].time_unvarying = 1;
  (data->simulationInfo->realParameter[642] /* winRad.radDat.absIntIrrNoSha[2,1] PARAM */) = 0.1227196468033888;
  data->modelData->realParameterData[642].time_unvarying = 1;
  (data->simulationInfo->realParameter[643] /* winRad.radDat.devAbsExtIrrIntShaDev[1,1] PARAM */) = 0.3695381144818747;
  data->modelData->realParameterData[643].time_unvarying = 1;
  (data->simulationInfo->realParameter[644] /* winRad.radDat.devAbsExtIrrIntShaDev[2,1] PARAM */) = 0.3690498410990196;
  data->modelData->realParameterData[644].time_unvarying = 1;
  (data->simulationInfo->realParameter[645] /* winRad.radDat.devAbsExtIrrIntShaDev[3,1] PARAM */) = 0.3673475997451543;
  data->modelData->realParameterData[645].time_unvarying = 1;
  (data->simulationInfo->realParameter[646] /* winRad.radDat.devAbsExtIrrIntShaDev[4,1] PARAM */) = 0.3635548084822143;
  data->modelData->realParameterData[646].time_unvarying = 1;
  (data->simulationInfo->realParameter[647] /* winRad.radDat.devAbsExtIrrIntShaDev[5,1] PARAM */) = 0.3555423033605714;
  data->modelData->realParameterData[647].time_unvarying = 1;
  (data->simulationInfo->realParameter[648] /* winRad.radDat.devAbsExtIrrIntShaDev[6,1] PARAM */) = 0.3384699121977249;
  data->modelData->realParameterData[648].time_unvarying = 1;
  (data->simulationInfo->realParameter[649] /* winRad.radDat.devAbsExtIrrIntShaDev[7,1] PARAM */) = 0.3020070366994245;
  data->modelData->realParameterData[649].time_unvarying = 1;
  (data->simulationInfo->realParameter[650] /* winRad.radDat.devAbsExtIrrIntShaDev[8,1] PARAM */) = 0.2282840296108259;
  data->modelData->realParameterData[650].time_unvarying = 1;
  (data->simulationInfo->realParameter[651] /* winRad.radDat.devAbsExtIrrIntShaDev[9,1] PARAM */) = 0.1062597676765009;
  data->modelData->realParameterData[651].time_unvarying = 1;
  (data->simulationInfo->realParameter[652] /* winRad.radDat.devAbsExtIrrIntShaDev[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[652].time_unvarying = 1;
  (data->simulationInfo->realParameter[653] /* winRad.radDat.devAbsExtIrrIntShaDev[11,1] PARAM */) = 0.3052322754811356;
  data->modelData->realParameterData[653].time_unvarying = 1;
  (data->simulationInfo->realParameter[654] /* winRad.radDat.devAbsIntIrrIntSha[1] PARAM */) = 0.5282960143941167;
  data->modelData->realParameterData[654].time_unvarying = 1;
  (data->simulationInfo->realParameter[655] /* winRad.radDat.glass[1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[655].time_unvarying = 1;
  (data->simulationInfo->realParameter[656] /* winRad.radDat.glass[1,2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[656].time_unvarying = 1;
  (data->simulationInfo->realParameter[657] /* winRad.radDat.glass[2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[657].time_unvarying = 1;
  (data->simulationInfo->realParameter[658] /* winRad.radDat.glass[2,2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[658].time_unvarying = 1;
  (data->simulationInfo->realParameter[659] /* winRad.radDat.glass[3,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[659].time_unvarying = 1;
  (data->simulationInfo->realParameter[660] /* winRad.radDat.glass[3,2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[660].time_unvarying = 1;
  (data->simulationInfo->realParameter[661] /* winRad.radDat.layer[1,1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[661].time_unvarying = 1;
  (data->simulationInfo->realParameter[662] /* winRad.radDat.layer[1,1,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[662].time_unvarying = 1;
  (data->simulationInfo->realParameter[663] /* winRad.radDat.layer[1,1,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[663].time_unvarying = 1;
  (data->simulationInfo->realParameter[664] /* winRad.radDat.layer[1,1,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[664].time_unvarying = 1;
  (data->simulationInfo->realParameter[665] /* winRad.radDat.layer[1,1,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[665].time_unvarying = 1;
  (data->simulationInfo->realParameter[666] /* winRad.radDat.layer[1,1,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[666].time_unvarying = 1;
  (data->simulationInfo->realParameter[667] /* winRad.radDat.layer[1,1,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[667].time_unvarying = 1;
  (data->simulationInfo->realParameter[668] /* winRad.radDat.layer[1,1,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[668].time_unvarying = 1;
  (data->simulationInfo->realParameter[669] /* winRad.radDat.layer[1,1,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[669].time_unvarying = 1;
  (data->simulationInfo->realParameter[670] /* winRad.radDat.layer[1,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[670].time_unvarying = 1;
  (data->simulationInfo->realParameter[671] /* winRad.radDat.layer[1,1,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[671].time_unvarying = 1;
  (data->simulationInfo->realParameter[672] /* winRad.radDat.layer[1,2,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[672].time_unvarying = 1;
  (data->simulationInfo->realParameter[673] /* winRad.radDat.layer[1,2,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[673].time_unvarying = 1;
  (data->simulationInfo->realParameter[674] /* winRad.radDat.layer[1,2,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[674].time_unvarying = 1;
  (data->simulationInfo->realParameter[675] /* winRad.radDat.layer[1,2,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[675].time_unvarying = 1;
  (data->simulationInfo->realParameter[676] /* winRad.radDat.layer[1,2,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[676].time_unvarying = 1;
  (data->simulationInfo->realParameter[677] /* winRad.radDat.layer[1,2,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[677].time_unvarying = 1;
  (data->simulationInfo->realParameter[678] /* winRad.radDat.layer[1,2,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[678].time_unvarying = 1;
  (data->simulationInfo->realParameter[679] /* winRad.radDat.layer[1,2,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[679].time_unvarying = 1;
  (data->simulationInfo->realParameter[680] /* winRad.radDat.layer[1,2,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[680].time_unvarying = 1;
  (data->simulationInfo->realParameter[681] /* winRad.radDat.layer[1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[681].time_unvarying = 1;
  (data->simulationInfo->realParameter[682] /* winRad.radDat.layer[1,2,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[682].time_unvarying = 1;
  (data->simulationInfo->realParameter[683] /* winRad.radDat.layer[2,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[683].time_unvarying = 1;
  (data->simulationInfo->realParameter[684] /* winRad.radDat.layer[2,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[684].time_unvarying = 1;
  (data->simulationInfo->realParameter[685] /* winRad.radDat.layer[2,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[685].time_unvarying = 1;
  (data->simulationInfo->realParameter[686] /* winRad.radDat.layer[2,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[686].time_unvarying = 1;
  (data->simulationInfo->realParameter[687] /* winRad.radDat.layer[2,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[687].time_unvarying = 1;
  (data->simulationInfo->realParameter[688] /* winRad.radDat.layer[2,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[688].time_unvarying = 1;
  (data->simulationInfo->realParameter[689] /* winRad.radDat.layer[2,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[689].time_unvarying = 1;
  (data->simulationInfo->realParameter[690] /* winRad.radDat.layer[2,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[690].time_unvarying = 1;
  (data->simulationInfo->realParameter[691] /* winRad.radDat.layer[2,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[691].time_unvarying = 1;
  (data->simulationInfo->realParameter[692] /* winRad.radDat.layer[2,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[692].time_unvarying = 1;
  (data->simulationInfo->realParameter[693] /* winRad.radDat.layer[2,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[693].time_unvarying = 1;
  (data->simulationInfo->realParameter[694] /* winRad.radDat.layer[2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[694].time_unvarying = 1;
  (data->simulationInfo->realParameter[695] /* winRad.radDat.layer[2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[695].time_unvarying = 1;
  (data->simulationInfo->realParameter[696] /* winRad.radDat.layer[2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[696].time_unvarying = 1;
  (data->simulationInfo->realParameter[697] /* winRad.radDat.layer[2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[697].time_unvarying = 1;
  (data->simulationInfo->realParameter[698] /* winRad.radDat.layer[2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[698].time_unvarying = 1;
  (data->simulationInfo->realParameter[699] /* winRad.radDat.layer[2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[699].time_unvarying = 1;
  (data->simulationInfo->realParameter[700] /* winRad.radDat.layer[2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[700].time_unvarying = 1;
  (data->simulationInfo->realParameter[701] /* winRad.radDat.layer[2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[701].time_unvarying = 1;
  (data->simulationInfo->realParameter[702] /* winRad.radDat.layer[2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[702].time_unvarying = 1;
  (data->simulationInfo->realParameter[703] /* winRad.radDat.layer[2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[703].time_unvarying = 1;
  (data->simulationInfo->realParameter[704] /* winRad.radDat.layer[2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[704].time_unvarying = 1;
  (data->simulationInfo->realParameter[705] /* winRad.radDat.layer[3,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[705].time_unvarying = 1;
  (data->simulationInfo->realParameter[706] /* winRad.radDat.layer[3,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[706].time_unvarying = 1;
  (data->simulationInfo->realParameter[707] /* winRad.radDat.layer[3,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[707].time_unvarying = 1;
  (data->simulationInfo->realParameter[708] /* winRad.radDat.layer[3,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[708].time_unvarying = 1;
  (data->simulationInfo->realParameter[709] /* winRad.radDat.layer[3,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[709].time_unvarying = 1;
  (data->simulationInfo->realParameter[710] /* winRad.radDat.layer[3,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[710].time_unvarying = 1;
  (data->simulationInfo->realParameter[711] /* winRad.radDat.layer[3,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[711].time_unvarying = 1;
  (data->simulationInfo->realParameter[712] /* winRad.radDat.layer[3,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[712].time_unvarying = 1;
  (data->simulationInfo->realParameter[713] /* winRad.radDat.layer[3,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[713].time_unvarying = 1;
  (data->simulationInfo->realParameter[714] /* winRad.radDat.layer[3,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[714].time_unvarying = 1;
  (data->simulationInfo->realParameter[715] /* winRad.radDat.layer[3,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[715].time_unvarying = 1;
  (data->simulationInfo->realParameter[716] /* winRad.radDat.layer[3,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[716].time_unvarying = 1;
  (data->simulationInfo->realParameter[717] /* winRad.radDat.layer[3,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[717].time_unvarying = 1;
  (data->simulationInfo->realParameter[718] /* winRad.radDat.layer[3,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[718].time_unvarying = 1;
  (data->simulationInfo->realParameter[719] /* winRad.radDat.layer[3,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[719].time_unvarying = 1;
  (data->simulationInfo->realParameter[720] /* winRad.radDat.layer[3,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[720].time_unvarying = 1;
  (data->simulationInfo->realParameter[721] /* winRad.radDat.layer[3,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[721].time_unvarying = 1;
  (data->simulationInfo->realParameter[722] /* winRad.radDat.layer[3,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[722].time_unvarying = 1;
  (data->simulationInfo->realParameter[723] /* winRad.radDat.layer[3,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[723].time_unvarying = 1;
  (data->simulationInfo->realParameter[724] /* winRad.radDat.layer[3,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[724].time_unvarying = 1;
  (data->simulationInfo->realParameter[725] /* winRad.radDat.layer[3,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[725].time_unvarying = 1;
  (data->simulationInfo->realParameter[726] /* winRad.radDat.layer[3,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[726].time_unvarying = 1;
  (data->simulationInfo->realParameter[727] /* winRad.radDat.psi[1] PARAM */) = 0.0;
  data->modelData->realParameterData[727].time_unvarying = 1;
  (data->simulationInfo->realParameter[728] /* winRad.radDat.psi[2] PARAM */) = 0.1745329251994329;
  data->modelData->realParameterData[728].time_unvarying = 1;
  (data->simulationInfo->realParameter[729] /* winRad.radDat.psi[3] PARAM */) = 0.3490658503988659;
  data->modelData->realParameterData[729].time_unvarying = 1;
  (data->simulationInfo->realParameter[730] /* winRad.radDat.psi[4] PARAM */) = 0.5235987755982988;
  data->modelData->realParameterData[730].time_unvarying = 1;
  (data->simulationInfo->realParameter[731] /* winRad.radDat.psi[5] PARAM */) = 0.6981317007977318;
  data->modelData->realParameterData[731].time_unvarying = 1;
  (data->simulationInfo->realParameter[732] /* winRad.radDat.psi[6] PARAM */) = 0.8726646259971648;
  data->modelData->realParameterData[732].time_unvarying = 1;
  (data->simulationInfo->realParameter[733] /* winRad.radDat.psi[7] PARAM */) = 1.047197551196598;
  data->modelData->realParameterData[733].time_unvarying = 1;
  (data->simulationInfo->realParameter[734] /* winRad.radDat.psi[8] PARAM */) = 1.221730476396031;
  data->modelData->realParameterData[734].time_unvarying = 1;
  (data->simulationInfo->realParameter[735] /* winRad.radDat.psi[9] PARAM */) = 1.396263401595464;
  data->modelData->realParameterData[735].time_unvarying = 1;
  (data->simulationInfo->realParameter[736] /* winRad.radDat.psi[10] PARAM */) = 1.570796326794897;
  data->modelData->realParameterData[736].time_unvarying = 1;
  (data->simulationInfo->realParameter[737] /* winRad.radDat.rhoGlaSol_a[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[737].time_unvarying = 1;
  (data->simulationInfo->realParameter[738] /* winRad.radDat.rhoGlaSol_a[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[738].time_unvarying = 1;
  (data->simulationInfo->realParameter[739] /* winRad.radDat.rhoGlaSol_b[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[739].time_unvarying = 1;
  (data->simulationInfo->realParameter[740] /* winRad.radDat.rhoGlaSol_b[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[740].time_unvarying = 1;
  (data->simulationInfo->realParameter[741] /* winRad.radDat.rhoShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[741].time_unvarying = 1;
  (data->simulationInfo->realParameter[742] /* winRad.radDat.rhoShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[742].time_unvarying = 1;
  (data->simulationInfo->realParameter[743] /* winRad.radDat.tauGlaSol[1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[743].time_unvarying = 1;
  (data->simulationInfo->realParameter[744] /* winRad.radDat.tauGlaSol[2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[744].time_unvarying = 1;
  (data->simulationInfo->realParameter[745] /* winRad.radDat.tauShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[745].time_unvarying = 1;
  (data->simulationInfo->realParameter[746] /* winRad.radDat.tauShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[746].time_unvarying = 1;
  (data->simulationInfo->realParameter[747] /* winRad.radDat.traRef[1,1,1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[747].time_unvarying = 1;
  (data->simulationInfo->realParameter[748] /* winRad.radDat.traRef[1,1,1,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[748].time_unvarying = 1;
  (data->simulationInfo->realParameter[749] /* winRad.radDat.traRef[1,1,1,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[749].time_unvarying = 1;
  (data->simulationInfo->realParameter[750] /* winRad.radDat.traRef[1,1,1,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[750].time_unvarying = 1;
  (data->simulationInfo->realParameter[751] /* winRad.radDat.traRef[1,1,1,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[751].time_unvarying = 1;
  (data->simulationInfo->realParameter[752] /* winRad.radDat.traRef[1,1,1,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[752].time_unvarying = 1;
  (data->simulationInfo->realParameter[753] /* winRad.radDat.traRef[1,1,1,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[753].time_unvarying = 1;
  (data->simulationInfo->realParameter[754] /* winRad.radDat.traRef[1,1,1,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[754].time_unvarying = 1;
  (data->simulationInfo->realParameter[755] /* winRad.radDat.traRef[1,1,1,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[755].time_unvarying = 1;
  (data->simulationInfo->realParameter[756] /* winRad.radDat.traRef[1,1,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[756].time_unvarying = 1;
  (data->simulationInfo->realParameter[757] /* winRad.radDat.traRef[1,1,1,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[757].time_unvarying = 1;
  (data->simulationInfo->realParameter[758] /* winRad.radDat.traRef[1,1,2,1,1] PARAM */) = 0.6994906348208673;
  data->modelData->realParameterData[758].time_unvarying = 1;
  (data->simulationInfo->realParameter[759] /* winRad.radDat.traRef[1,1,2,2,1] PARAM */) = 0.6985663927869478;
  data->modelData->realParameterData[759].time_unvarying = 1;
  (data->simulationInfo->realParameter[760] /* winRad.radDat.traRef[1,1,2,3,1] PARAM */) = 0.6953442572654116;
  data->modelData->realParameterData[760].time_unvarying = 1;
  (data->simulationInfo->realParameter[761] /* winRad.radDat.traRef[1,1,2,4,1] PARAM */) = 0.6881649654297732;
  data->modelData->realParameterData[761].time_unvarying = 1;
  (data->simulationInfo->realParameter[762] /* winRad.radDat.traRef[1,1,2,5,1] PARAM */) = 0.6729982692909955;
  data->modelData->realParameterData[762].time_unvarying = 1;
  (data->simulationInfo->realParameter[763] /* winRad.radDat.traRef[1,1,2,6,1] PARAM */) = 0.6406823125211414;
  data->modelData->realParameterData[763].time_unvarying = 1;
  (data->simulationInfo->realParameter[764] /* winRad.radDat.traRef[1,1,2,7,1] PARAM */) = 0.5716625309880206;
  data->modelData->realParameterData[764].time_unvarying = 1;
  (data->simulationInfo->realParameter[765] /* winRad.radDat.traRef[1,1,2,8,1] PARAM */) = 0.4321138592586893;
  data->modelData->realParameterData[765].time_unvarying = 1;
  (data->simulationInfo->realParameter[766] /* winRad.radDat.traRef[1,1,2,9,1] PARAM */) = 0.2011367960032149;
  data->modelData->realParameterData[766].time_unvarying = 1;
  (data->simulationInfo->realParameter[767] /* winRad.radDat.traRef[1,1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[767].time_unvarying = 1;
  (data->simulationInfo->realParameter[768] /* winRad.radDat.traRef[1,1,2,11,1] PARAM */) = 0.5777675151140318;
  data->modelData->realParameterData[768].time_unvarying = 1;
  (data->simulationInfo->realParameter[769] /* winRad.radDat.traRef[1,2,1,1,1] PARAM */) = 0.6994906348208673;
  data->modelData->realParameterData[769].time_unvarying = 1;
  (data->simulationInfo->realParameter[770] /* winRad.radDat.traRef[1,2,1,2,1] PARAM */) = 0.6985663927869478;
  data->modelData->realParameterData[770].time_unvarying = 1;
  (data->simulationInfo->realParameter[771] /* winRad.radDat.traRef[1,2,1,3,1] PARAM */) = 0.6953442572654116;
  data->modelData->realParameterData[771].time_unvarying = 1;
  (data->simulationInfo->realParameter[772] /* winRad.radDat.traRef[1,2,1,4,1] PARAM */) = 0.6881649654297732;
  data->modelData->realParameterData[772].time_unvarying = 1;
  (data->simulationInfo->realParameter[773] /* winRad.radDat.traRef[1,2,1,5,1] PARAM */) = 0.6729982692909955;
  data->modelData->realParameterData[773].time_unvarying = 1;
  (data->simulationInfo->realParameter[774] /* winRad.radDat.traRef[1,2,1,6,1] PARAM */) = 0.6406823125211414;
  data->modelData->realParameterData[774].time_unvarying = 1;
  (data->simulationInfo->realParameter[775] /* winRad.radDat.traRef[1,2,1,7,1] PARAM */) = 0.5716625309880206;
  data->modelData->realParameterData[775].time_unvarying = 1;
  (data->simulationInfo->realParameter[776] /* winRad.radDat.traRef[1,2,1,8,1] PARAM */) = 0.4321138592586893;
  data->modelData->realParameterData[776].time_unvarying = 1;
  (data->simulationInfo->realParameter[777] /* winRad.radDat.traRef[1,2,1,9,1] PARAM */) = 0.2011367960032149;
  data->modelData->realParameterData[777].time_unvarying = 1;
  (data->simulationInfo->realParameter[778] /* winRad.radDat.traRef[1,2,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[778].time_unvarying = 1;
  (data->simulationInfo->realParameter[779] /* winRad.radDat.traRef[1,2,1,11,1] PARAM */) = 0.5777675151140318;
  data->modelData->realParameterData[779].time_unvarying = 1;
  (data->simulationInfo->realParameter[780] /* winRad.radDat.traRef[1,2,2,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[780].time_unvarying = 1;
  (data->simulationInfo->realParameter[781] /* winRad.radDat.traRef[1,2,2,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[781].time_unvarying = 1;
  (data->simulationInfo->realParameter[782] /* winRad.radDat.traRef[1,2,2,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[782].time_unvarying = 1;
  (data->simulationInfo->realParameter[783] /* winRad.radDat.traRef[1,2,2,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[783].time_unvarying = 1;
  (data->simulationInfo->realParameter[784] /* winRad.radDat.traRef[1,2,2,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[784].time_unvarying = 1;
  (data->simulationInfo->realParameter[785] /* winRad.radDat.traRef[1,2,2,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[785].time_unvarying = 1;
  (data->simulationInfo->realParameter[786] /* winRad.radDat.traRef[1,2,2,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[786].time_unvarying = 1;
  (data->simulationInfo->realParameter[787] /* winRad.radDat.traRef[1,2,2,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[787].time_unvarying = 1;
  (data->simulationInfo->realParameter[788] /* winRad.radDat.traRef[1,2,2,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[788].time_unvarying = 1;
  (data->simulationInfo->realParameter[789] /* winRad.radDat.traRef[1,2,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[789].time_unvarying = 1;
  (data->simulationInfo->realParameter[790] /* winRad.radDat.traRef[1,2,2,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[790].time_unvarying = 1;
  (data->simulationInfo->realParameter[791] /* winRad.radDat.traRef[2,1,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[791].time_unvarying = 1;
  (data->simulationInfo->realParameter[792] /* winRad.radDat.traRef[2,1,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[792].time_unvarying = 1;
  (data->simulationInfo->realParameter[793] /* winRad.radDat.traRef[2,1,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[793].time_unvarying = 1;
  (data->simulationInfo->realParameter[794] /* winRad.radDat.traRef[2,1,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[794].time_unvarying = 1;
  (data->simulationInfo->realParameter[795] /* winRad.radDat.traRef[2,1,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[795].time_unvarying = 1;
  (data->simulationInfo->realParameter[796] /* winRad.radDat.traRef[2,1,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[796].time_unvarying = 1;
  (data->simulationInfo->realParameter[797] /* winRad.radDat.traRef[2,1,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[797].time_unvarying = 1;
  (data->simulationInfo->realParameter[798] /* winRad.radDat.traRef[2,1,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[798].time_unvarying = 1;
  (data->simulationInfo->realParameter[799] /* winRad.radDat.traRef[2,1,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[799].time_unvarying = 1;
  (data->simulationInfo->realParameter[800] /* winRad.radDat.traRef[2,1,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[800].time_unvarying = 1;
  (data->simulationInfo->realParameter[801] /* winRad.radDat.traRef[2,1,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[801].time_unvarying = 1;
  (data->simulationInfo->realParameter[802] /* winRad.radDat.traRef[2,1,2,1,1] PARAM */) = 0.127461797611565;
  data->modelData->realParameterData[802].time_unvarying = 1;
  (data->simulationInfo->realParameter[803] /* winRad.radDat.traRef[2,1,2,2,1] PARAM */) = 0.1273615206111159;
  data->modelData->realParameterData[803].time_unvarying = 1;
  (data->simulationInfo->realParameter[804] /* winRad.radDat.traRef[2,1,2,3,1] PARAM */) = 0.1275322917190642;
  data->modelData->realParameterData[804].time_unvarying = 1;
  (data->simulationInfo->realParameter[805] /* winRad.radDat.traRef[2,1,2,4,1] PARAM */) = 0.1297280574286503;
  data->modelData->realParameterData[805].time_unvarying = 1;
  (data->simulationInfo->realParameter[806] /* winRad.radDat.traRef[2,1,2,5,1] PARAM */) = 0.1382440338153747;
  data->modelData->realParameterData[806].time_unvarying = 1;
  (data->simulationInfo->realParameter[807] /* winRad.radDat.traRef[2,1,2,6,1] PARAM */) = 0.1628935363465329;
  data->modelData->realParameterData[807].time_unvarying = 1;
  (data->simulationInfo->realParameter[808] /* winRad.radDat.traRef[2,1,2,7,1] PARAM */) = 0.2247377823311878;
  data->modelData->realParameterData[808].time_unvarying = 1;
  (data->simulationInfo->realParameter[809] /* winRad.radDat.traRef[2,1,2,8,1] PARAM */) = 0.3612313008417883;
  data->modelData->realParameterData[809].time_unvarying = 1;
  (data->simulationInfo->realParameter[810] /* winRad.radDat.traRef[2,1,2,9,1] PARAM */) = 0.6052446087035255;
  data->modelData->realParameterData[810].time_unvarying = 1;
  (data->simulationInfo->realParameter[811] /* winRad.radDat.traRef[2,1,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[811].time_unvarying = 1;
  (data->simulationInfo->realParameter[812] /* winRad.radDat.traRef[2,1,2,11,1] PARAM */) = 0.2142436332900854;
  data->modelData->realParameterData[812].time_unvarying = 1;
  (data->simulationInfo->realParameter[813] /* winRad.radDat.traRef[2,2,1,1,1] PARAM */) = 0.0;
  data->modelData->realParameterData[813].time_unvarying = 1;
  (data->simulationInfo->realParameter[814] /* winRad.radDat.traRef[2,2,1,2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[814].time_unvarying = 1;
  (data->simulationInfo->realParameter[815] /* winRad.radDat.traRef[2,2,1,3,1] PARAM */) = 0.0;
  data->modelData->realParameterData[815].time_unvarying = 1;
  (data->simulationInfo->realParameter[816] /* winRad.radDat.traRef[2,2,1,4,1] PARAM */) = 0.0;
  data->modelData->realParameterData[816].time_unvarying = 1;
  (data->simulationInfo->realParameter[817] /* winRad.radDat.traRef[2,2,1,5,1] PARAM */) = 0.0;
  data->modelData->realParameterData[817].time_unvarying = 1;
  (data->simulationInfo->realParameter[818] /* winRad.radDat.traRef[2,2,1,6,1] PARAM */) = 0.0;
  data->modelData->realParameterData[818].time_unvarying = 1;
  (data->simulationInfo->realParameter[819] /* winRad.radDat.traRef[2,2,1,7,1] PARAM */) = 0.0;
  data->modelData->realParameterData[819].time_unvarying = 1;
  (data->simulationInfo->realParameter[820] /* winRad.radDat.traRef[2,2,1,8,1] PARAM */) = 0.0;
  data->modelData->realParameterData[820].time_unvarying = 1;
  (data->simulationInfo->realParameter[821] /* winRad.radDat.traRef[2,2,1,9,1] PARAM */) = 0.0;
  data->modelData->realParameterData[821].time_unvarying = 1;
  (data->simulationInfo->realParameter[822] /* winRad.radDat.traRef[2,2,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[822].time_unvarying = 1;
  (data->simulationInfo->realParameter[823] /* winRad.radDat.traRef[2,2,1,11,1] PARAM */) = 0.0;
  data->modelData->realParameterData[823].time_unvarying = 1;
  (data->simulationInfo->realParameter[824] /* winRad.radDat.traRef[2,2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[824].time_unvarying = 1;
  (data->simulationInfo->realParameter[825] /* winRad.radDat.traRef[2,2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[825].time_unvarying = 1;
  (data->simulationInfo->realParameter[826] /* winRad.radDat.traRef[2,2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[826].time_unvarying = 1;
  (data->simulationInfo->realParameter[827] /* winRad.radDat.traRef[2,2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[827].time_unvarying = 1;
  (data->simulationInfo->realParameter[828] /* winRad.radDat.traRef[2,2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[828].time_unvarying = 1;
  (data->simulationInfo->realParameter[829] /* winRad.radDat.traRef[2,2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[829].time_unvarying = 1;
  (data->simulationInfo->realParameter[830] /* winRad.radDat.traRef[2,2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[830].time_unvarying = 1;
  (data->simulationInfo->realParameter[831] /* winRad.radDat.traRef[2,2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[831].time_unvarying = 1;
  (data->simulationInfo->realParameter[832] /* winRad.radDat.traRef[2,2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[832].time_unvarying = 1;
  (data->simulationInfo->realParameter[833] /* winRad.radDat.traRef[2,2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[833].time_unvarying = 1;
  (data->simulationInfo->realParameter[834] /* winRad.radDat.traRef[2,2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[834].time_unvarying = 1;
  (data->simulationInfo->realParameter[835] /* winRad.radDat.traRef[3,1,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[835].time_unvarying = 1;
  (data->simulationInfo->realParameter[836] /* winRad.radDat.traRef[3,1,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[836].time_unvarying = 1;
  (data->simulationInfo->realParameter[837] /* winRad.radDat.traRef[3,1,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[837].time_unvarying = 1;
  (data->simulationInfo->realParameter[838] /* winRad.radDat.traRef[3,1,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[838].time_unvarying = 1;
  (data->simulationInfo->realParameter[839] /* winRad.radDat.traRef[3,1,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[839].time_unvarying = 1;
  (data->simulationInfo->realParameter[840] /* winRad.radDat.traRef[3,1,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[840].time_unvarying = 1;
  (data->simulationInfo->realParameter[841] /* winRad.radDat.traRef[3,1,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[841].time_unvarying = 1;
  (data->simulationInfo->realParameter[842] /* winRad.radDat.traRef[3,1,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[842].time_unvarying = 1;
  (data->simulationInfo->realParameter[843] /* winRad.radDat.traRef[3,1,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[843].time_unvarying = 1;
  (data->simulationInfo->realParameter[844] /* winRad.radDat.traRef[3,1,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[844].time_unvarying = 1;
  (data->simulationInfo->realParameter[845] /* winRad.radDat.traRef[3,1,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[845].time_unvarying = 1;
  (data->simulationInfo->realParameter[846] /* winRad.radDat.traRef[3,1,2,1,1] PARAM */) = 0.0;
  data->modelData->realParameterData[846].time_unvarying = 1;
  (data->simulationInfo->realParameter[847] /* winRad.radDat.traRef[3,1,2,2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[847].time_unvarying = 1;
  (data->simulationInfo->realParameter[848] /* winRad.radDat.traRef[3,1,2,3,1] PARAM */) = 0.0;
  data->modelData->realParameterData[848].time_unvarying = 1;
  (data->simulationInfo->realParameter[849] /* winRad.radDat.traRef[3,1,2,4,1] PARAM */) = 0.0;
  data->modelData->realParameterData[849].time_unvarying = 1;
  (data->simulationInfo->realParameter[850] /* winRad.radDat.traRef[3,1,2,5,1] PARAM */) = 0.0;
  data->modelData->realParameterData[850].time_unvarying = 1;
  (data->simulationInfo->realParameter[851] /* winRad.radDat.traRef[3,1,2,6,1] PARAM */) = 0.0;
  data->modelData->realParameterData[851].time_unvarying = 1;
  (data->simulationInfo->realParameter[852] /* winRad.radDat.traRef[3,1,2,7,1] PARAM */) = 0.0;
  data->modelData->realParameterData[852].time_unvarying = 1;
  (data->simulationInfo->realParameter[853] /* winRad.radDat.traRef[3,1,2,8,1] PARAM */) = 0.0;
  data->modelData->realParameterData[853].time_unvarying = 1;
  (data->simulationInfo->realParameter[854] /* winRad.radDat.traRef[3,1,2,9,1] PARAM */) = 0.0;
  data->modelData->realParameterData[854].time_unvarying = 1;
  (data->simulationInfo->realParameter[855] /* winRad.radDat.traRef[3,1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[855].time_unvarying = 1;
  (data->simulationInfo->realParameter[856] /* winRad.radDat.traRef[3,1,2,11,1] PARAM */) = 0.0;
  data->modelData->realParameterData[856].time_unvarying = 1;
  (data->simulationInfo->realParameter[857] /* winRad.radDat.traRef[3,2,1,1,1] PARAM */) = 0.127461797611565;
  data->modelData->realParameterData[857].time_unvarying = 1;
  (data->simulationInfo->realParameter[858] /* winRad.radDat.traRef[3,2,1,2,1] PARAM */) = 0.1273615206111159;
  data->modelData->realParameterData[858].time_unvarying = 1;
  (data->simulationInfo->realParameter[859] /* winRad.radDat.traRef[3,2,1,3,1] PARAM */) = 0.1275322917190642;
  data->modelData->realParameterData[859].time_unvarying = 1;
  (data->simulationInfo->realParameter[860] /* winRad.radDat.traRef[3,2,1,4,1] PARAM */) = 0.1297280574286503;
  data->modelData->realParameterData[860].time_unvarying = 1;
  (data->simulationInfo->realParameter[861] /* winRad.radDat.traRef[3,2,1,5,1] PARAM */) = 0.1382440338153747;
  data->modelData->realParameterData[861].time_unvarying = 1;
  (data->simulationInfo->realParameter[862] /* winRad.radDat.traRef[3,2,1,6,1] PARAM */) = 0.1628935363465329;
  data->modelData->realParameterData[862].time_unvarying = 1;
  (data->simulationInfo->realParameter[863] /* winRad.radDat.traRef[3,2,1,7,1] PARAM */) = 0.2247377823311878;
  data->modelData->realParameterData[863].time_unvarying = 1;
  (data->simulationInfo->realParameter[864] /* winRad.radDat.traRef[3,2,1,8,1] PARAM */) = 0.3612313008417883;
  data->modelData->realParameterData[864].time_unvarying = 1;
  (data->simulationInfo->realParameter[865] /* winRad.radDat.traRef[3,2,1,9,1] PARAM */) = 0.6052446087035255;
  data->modelData->realParameterData[865].time_unvarying = 1;
  (data->simulationInfo->realParameter[866] /* winRad.radDat.traRef[3,2,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[866].time_unvarying = 1;
  (data->simulationInfo->realParameter[867] /* winRad.radDat.traRef[3,2,1,11,1] PARAM */) = 0.2142436332900854;
  data->modelData->realParameterData[867].time_unvarying = 1;
  (data->simulationInfo->realParameter[868] /* winRad.radDat.traRef[3,2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[868].time_unvarying = 1;
  (data->simulationInfo->realParameter[869] /* winRad.radDat.traRef[3,2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[869].time_unvarying = 1;
  (data->simulationInfo->realParameter[870] /* winRad.radDat.traRef[3,2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[870].time_unvarying = 1;
  (data->simulationInfo->realParameter[871] /* winRad.radDat.traRef[3,2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[871].time_unvarying = 1;
  (data->simulationInfo->realParameter[872] /* winRad.radDat.traRef[3,2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[872].time_unvarying = 1;
  (data->simulationInfo->realParameter[873] /* winRad.radDat.traRef[3,2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[873].time_unvarying = 1;
  (data->simulationInfo->realParameter[874] /* winRad.radDat.traRef[3,2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[874].time_unvarying = 1;
  (data->simulationInfo->realParameter[875] /* winRad.radDat.traRef[3,2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[875].time_unvarying = 1;
  (data->simulationInfo->realParameter[876] /* winRad.radDat.traRef[3,2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[876].time_unvarying = 1;
  (data->simulationInfo->realParameter[877] /* winRad.radDat.traRef[3,2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[877].time_unvarying = 1;
  (data->simulationInfo->realParameter[878] /* winRad.radDat.traRef[3,2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[878].time_unvarying = 1;
  (data->simulationInfo->realParameter[879] /* winRad.radDat.traRefShaDev[1,1] PARAM */) = 0.25;
  data->modelData->realParameterData[879].time_unvarying = 1;
  (data->simulationInfo->realParameter[880] /* winRad.radDat.traRefShaDev[1,2] PARAM */) = 0.25;
  data->modelData->realParameterData[880].time_unvarying = 1;
  (data->simulationInfo->realParameter[881] /* winRad.radDat.traRefShaDev[2,1] PARAM */) = 0.25;
  data->modelData->realParameterData[881].time_unvarying = 1;
  (data->simulationInfo->realParameter[882] /* winRad.radDat.traRefShaDev[2,2] PARAM */) = 0.25;
  data->modelData->realParameterData[882].time_unvarying = 1;
  (data->simulationInfo->realParameter[883] /* winRad.radDat.winTraExtIrrExtSha[1,1] PARAM */) = 0.1807604077499478;
  data->modelData->realParameterData[883].time_unvarying = 1;
  (data->simulationInfo->realParameter[884] /* winRad.radDat.winTraExtIrrExtSha[2,1] PARAM */) = 0.1805169418146947;
  data->modelData->realParameterData[884].time_unvarying = 1;
  (data->simulationInfo->realParameter[885] /* winRad.radDat.winTraExtIrrExtSha[3,1] PARAM */) = 0.1796921494729775;
  data->modelData->realParameterData[885].time_unvarying = 1;
  (data->simulationInfo->realParameter[886] /* winRad.radDat.winTraExtIrrExtSha[4,1] PARAM */) = 0.1779366487415986;
  data->modelData->realParameterData[886].time_unvarying = 1;
  (data->simulationInfo->realParameter[887] /* winRad.radDat.winTraExtIrrExtSha[5,1] PARAM */) = 0.1743935175988208;
  data->modelData->realParameterData[887].time_unvarying = 1;
  (data->simulationInfo->realParameter[888] /* winRad.radDat.winTraExtIrrExtSha[6,1] PARAM */) = 0.1670623982483838;
  data->modelData->realParameterData[888].time_unvarying = 1;
  (data->simulationInfo->realParameter[889] /* winRad.radDat.winTraExtIrrExtSha[7,1] PARAM */) = 0.1513996817065354;
  data->modelData->realParameterData[889].time_unvarying = 1;
  (data->simulationInfo->realParameter[890] /* winRad.radDat.winTraExtIrrExtSha[8,1] PARAM */) = 0.1183363819368878;
  data->modelData->realParameterData[890].time_unvarying = 1;
  (data->simulationInfo->realParameter[891] /* winRad.radDat.winTraExtIrrExtSha[9,1] PARAM */) = 0.05832334293934013;
  data->modelData->realParameterData[891].time_unvarying = 1;
  (data->simulationInfo->realParameter[892] /* winRad.radDat.winTraExtIrrExtSha[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[892].time_unvarying = 1;
  (data->simulationInfo->realParameter[893] /* winRad.radDat.winTraExtIrrExtSha[11,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[893].time_unvarying = 1;
  (data->simulationInfo->realParameter[894] /* winRad.radDat.winTraExtIrrIntSha[1,1] PARAM */) = 0.1847690572409374;
  data->modelData->realParameterData[894].time_unvarying = 1;
  (data->simulationInfo->realParameter[895] /* winRad.radDat.winTraExtIrrIntSha[2,1] PARAM */) = 0.1845249205495098;
  data->modelData->realParameterData[895].time_unvarying = 1;
  (data->simulationInfo->realParameter[896] /* winRad.radDat.winTraExtIrrIntSha[3,1] PARAM */) = 0.1836737998725771;
  data->modelData->realParameterData[896].time_unvarying = 1;
  (data->simulationInfo->realParameter[897] /* winRad.radDat.winTraExtIrrIntSha[4,1] PARAM */) = 0.1817774042411072;
  data->modelData->realParameterData[897].time_unvarying = 1;
  (data->simulationInfo->realParameter[898] /* winRad.radDat.winTraExtIrrIntSha[5,1] PARAM */) = 0.1777711516802857;
  data->modelData->realParameterData[898].time_unvarying = 1;
  (data->simulationInfo->realParameter[899] /* winRad.radDat.winTraExtIrrIntSha[6,1] PARAM */) = 0.1692349560988624;
  data->modelData->realParameterData[899].time_unvarying = 1;
  (data->simulationInfo->realParameter[900] /* winRad.radDat.winTraExtIrrIntSha[7,1] PARAM */) = 0.1510035183497123;
  data->modelData->realParameterData[900].time_unvarying = 1;
  (data->simulationInfo->realParameter[901] /* winRad.radDat.winTraExtIrrIntSha[8,1] PARAM */) = 0.1141420148054129;
  data->modelData->realParameterData[901].time_unvarying = 1;
  (data->simulationInfo->realParameter[902] /* winRad.radDat.winTraExtIrrIntSha[9,1] PARAM */) = 0.05312988383825046;
  data->modelData->realParameterData[902].time_unvarying = 1;
  (data->simulationInfo->realParameter[903] /* winRad.radDat.winTraExtIrrIntSha[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[903].time_unvarying = 1;
  (data->simulationInfo->realParameter[904] /* winRad.radDat.winTraExtIrrIntSha[11,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[904].time_unvarying = 1;
  (data->simulationInfo->realParameter[905] /* winRad.radDat.winTraRefIntIrrExtSha[1,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[905].time_unvarying = 1;
  (data->simulationInfo->realParameter[906] /* winRad.radDat.winTraRefIntIrrExtSha[2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[906].time_unvarying = 1;
  (data->simulationInfo->realParameter[907] /* winRad.radDat.winTraRefIntIrrExtSha[3,1] PARAM */) = 0.302420279958754;
  data->modelData->realParameterData[907].time_unvarying = 1;
  (data->simulationInfo->realParameter[908] /* winRad.radDat.winTraRefIntIrrIntSha[1,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[908].time_unvarying = 1;
  (data->simulationInfo->realParameter[909] /* winRad.radDat.winTraRefIntIrrIntSha[2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[909].time_unvarying = 1;
  (data->simulationInfo->realParameter[910] /* winRad.radDat.winTraRefIntIrrIntSha[3,1] PARAM */) = 0.2641480071970583;
  data->modelData->realParameterData[910].time_unvarying = 1;
  (data->simulationInfo->realParameter[911] /* winRad.radDat.xGla[1] PARAM */) = 0.003;
  data->modelData->realParameterData[911].time_unvarying = 1;
  (data->simulationInfo->realParameter[912] /* winRad.radDat.xGla[2] PARAM */) = 0.003;
  data->modelData->realParameterData[912].time_unvarying = 1;
  (data->simulationInfo->realParameter[913] /* winRad.rhoGlaSol_a[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[913].time_unvarying = 1;
  (data->simulationInfo->realParameter[914] /* winRad.rhoGlaSol_a[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[914].time_unvarying = 1;
  (data->simulationInfo->realParameter[915] /* winRad.rhoGlaSol_b[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[915].time_unvarying = 1;
  (data->simulationInfo->realParameter[916] /* winRad.rhoGlaSol_b[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[916].time_unvarying = 1;
  (data->simulationInfo->realParameter[917] /* winRad.rhoShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[917].time_unvarying = 1;
  (data->simulationInfo->realParameter[918] /* winRad.rhoShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[918].time_unvarying = 1;
  (data->simulationInfo->realParameter[919] /* winRad.staIntQAbsExtSha_flow.uSup[1] PARAM */) = 0.0;
  data->modelData->realParameterData[919].time_unvarying = 1;
  (data->simulationInfo->realParameter[920] /* winRad.staIntQAbsGlaSha_flow[1].uSup[1] PARAM */) = 0.0;
  data->modelData->realParameterData[920].time_unvarying = 1;
  (data->simulationInfo->realParameter[921] /* winRad.staIntQAbsGlaSha_flow[2].uSup[1] PARAM */) = 0.0;
  data->modelData->realParameterData[921].time_unvarying = 1;
  (data->simulationInfo->realParameter[922] /* winRad.staIntQAbsGlaUns_flow[1].uSup[1] PARAM */) = 0.0;
  data->modelData->realParameterData[922].time_unvarying = 1;
  (data->simulationInfo->realParameter[923] /* winRad.staIntQAbsGlaUns_flow[2].uSup[1] PARAM */) = 0.0;
  data->modelData->realParameterData[923].time_unvarying = 1;
  (data->simulationInfo->realParameter[924] /* winRad.staIntQAbsIntSha_flow.uSup[1] PARAM */) = 0.0;
  data->modelData->realParameterData[924].time_unvarying = 1;
  (data->simulationInfo->realParameter[925] /* winRad.staIntQTraDif_flow.uSup[1] PARAM */) = 0.0;
  data->modelData->realParameterData[925].time_unvarying = 1;
  (data->simulationInfo->realParameter[926] /* winRad.staIntQTraDir_flow.uSup[1] PARAM */) = 0.0;
  data->modelData->realParameterData[926].time_unvarying = 1;
  (data->simulationInfo->realParameter[927] /* winRad.tauGlaSol[1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[927].time_unvarying = 1;
  (data->simulationInfo->realParameter[928] /* winRad.tauGlaSol[2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[928].time_unvarying = 1;
  (data->simulationInfo->realParameter[929] /* winRad.tauShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[929].time_unvarying = 1;
  (data->simulationInfo->realParameter[930] /* winRad.tauShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[930].time_unvarying = 1;
  (data->simulationInfo->realParameter[931] /* winRad.tra.AWin PARAM */) = 1.0;
  data->modelData->realParameterData[931].time_unvarying = 1;
  (data->simulationInfo->realParameter[958] /* winRad.tra.radDat.absExtIrrExtSha[1,1,1] PARAM */) = 0.02499520908519422;
  data->modelData->realParameterData[958].time_unvarying = 1;
  (data->simulationInfo->realParameter[959] /* winRad.tra.radDat.absExtIrrExtSha[1,2,1] PARAM */) = 0.02514929957574206;
  data->modelData->realParameterData[959].time_unvarying = 1;
  (data->simulationInfo->realParameter[960] /* winRad.tra.radDat.absExtIrrExtSha[1,3,1] PARAM */) = 0.02561776873020298;
  data->modelData->realParameterData[960].time_unvarying = 1;
  (data->simulationInfo->realParameter[961] /* winRad.tra.radDat.absExtIrrExtSha[1,4,1] PARAM */) = 0.02642332367824236;
  data->modelData->realParameterData[961].time_unvarying = 1;
  (data->simulationInfo->realParameter[962] /* winRad.tra.radDat.absExtIrrExtSha[1,5,1] PARAM */) = 0.0276225173612099;
  data->modelData->realParameterData[962].time_unvarying = 1;
  (data->simulationInfo->realParameter[963] /* winRad.tra.radDat.absExtIrrExtSha[1,6,1] PARAM */) = 0.02935337359634402;
  data->modelData->realParameterData[963].time_unvarying = 1;
  (data->simulationInfo->realParameter[964] /* winRad.tra.radDat.absExtIrrExtSha[1,7,1] PARAM */) = 0.03193076631094863;
  data->modelData->realParameterData[964].time_unvarying = 1;
  (data->simulationInfo->realParameter[965] /* winRad.tra.radDat.absExtIrrExtSha[1,8,1] PARAM */) = 0.03581982523119827;
  data->modelData->realParameterData[965].time_unvarying = 1;
  (data->simulationInfo->realParameter[966] /* winRad.tra.radDat.absExtIrrExtSha[1,9,1] PARAM */) = 0.03977435612665067;
  data->modelData->realParameterData[966].time_unvarying = 1;
  (data->simulationInfo->realParameter[967] /* winRad.tra.radDat.absExtIrrExtSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[967].time_unvarying = 1;
  (data->simulationInfo->realParameter[968] /* winRad.tra.radDat.absExtIrrExtSha[1,11,1] PARAM */) = 0.03241615014704199;
  data->modelData->realParameterData[968].time_unvarying = 1;
  (data->simulationInfo->realParameter[969] /* winRad.tra.radDat.absExtIrrExtSha[2,1,1] PARAM */) = 0.01972325791995835;
  data->modelData->realParameterData[969].time_unvarying = 1;
  (data->simulationInfo->realParameter[970] /* winRad.tra.radDat.absExtIrrExtSha[2,2,1] PARAM */) = 0.01983276806040852;
  data->modelData->realParameterData[970].time_unvarying = 1;
  (data->simulationInfo->realParameter[971] /* winRad.tra.radDat.absExtIrrExtSha[2,3,1] PARAM */) = 0.02015480119109085;
  data->modelData->realParameterData[971].time_unvarying = 1;
  (data->simulationInfo->realParameter[972] /* winRad.tra.radDat.absExtIrrExtSha[2,4,1] PARAM */) = 0.02066350412154015;
  data->modelData->realParameterData[972].time_unvarying = 1;
  (data->simulationInfo->realParameter[973] /* winRad.tra.radDat.absExtIrrExtSha[2,5,1] PARAM */) = 0.02129011768881981;
  data->modelData->realParameterData[973].time_unvarying = 1;
  (data->simulationInfo->realParameter[974] /* winRad.tra.radDat.absExtIrrExtSha[2,6,1] PARAM */) = 0.02186559892833682;
  data->modelData->realParameterData[974].time_unvarying = 1;
  (data->simulationInfo->realParameter[975] /* winRad.tra.radDat.absExtIrrExtSha[2,7,1] PARAM */) = 0.0219907802101197;
  data->modelData->realParameterData[975].time_unvarying = 1;
  (data->simulationInfo->realParameter[976] /* winRad.tra.radDat.absExtIrrExtSha[2,8,1] PARAM */) = 0.02077355991365581;
  data->modelData->realParameterData[976].time_unvarying = 1;
  (data->simulationInfo->realParameter[977] /* winRad.tra.radDat.absExtIrrExtSha[2,9,1] PARAM */) = 0.01636894513455467;
  data->modelData->realParameterData[977].time_unvarying = 1;
  (data->simulationInfo->realParameter[978] /* winRad.tra.radDat.absExtIrrExtSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[978].time_unvarying = 1;
  (data->simulationInfo->realParameter[979] /* winRad.tra.radDat.absExtIrrExtSha[2,11,1] PARAM */) = 0.02252369052121515;
  data->modelData->realParameterData[979].time_unvarying = 1;
  (data->simulationInfo->realParameter[980] /* winRad.tra.radDat.absExtIrrIntSha[1,1,1] PARAM */) = 0.1093863539769833;
  data->modelData->realParameterData[980].time_unvarying = 1;
  (data->simulationInfo->realParameter[981] /* winRad.tra.radDat.absExtIrrIntSha[1,2,1] PARAM */) = 0.1100473669610094;
  data->modelData->realParameterData[981].time_unvarying = 1;
  (data->simulationInfo->realParameter[982] /* winRad.tra.radDat.absExtIrrIntSha[1,3,1] PARAM */) = 0.1120318818175741;
  data->modelData->realParameterData[982].time_unvarying = 1;
  (data->simulationInfo->realParameter[983] /* winRad.tra.radDat.absExtIrrIntSha[1,4,1] PARAM */) = 0.1153398886779867;
  data->modelData->realParameterData[983].time_unvarying = 1;
  (data->simulationInfo->realParameter[984] /* winRad.tra.radDat.absExtIrrIntSha[1,5,1] PARAM */) = 0.1199592159293939;
  data->modelData->realParameterData[984].time_unvarying = 1;
  (data->simulationInfo->realParameter[985] /* winRad.tra.radDat.absExtIrrIntSha[1,6,1] PARAM */) = 0.1258553503945128;
  data->modelData->realParameterData[985].time_unvarying = 1;
  (data->simulationInfo->realParameter[986] /* winRad.tra.radDat.absExtIrrIntSha[1,7,1] PARAM */) = 0.1329258880977036;
  data->modelData->realParameterData[986].time_unvarying = 1;
  (data->simulationInfo->realParameter[987] /* winRad.tra.radDat.absExtIrrIntSha[1,8,1] PARAM */) = 0.1403970614972095;
  data->modelData->realParameterData[987].time_unvarying = 1;
  (data->simulationInfo->realParameter[988] /* winRad.tra.radDat.absExtIrrIntSha[1,9,1] PARAM */) = 0.1415178832813775;
  data->modelData->realParameterData[988].time_unvarying = 1;
  (data->simulationInfo->realParameter[989] /* winRad.tra.radDat.absExtIrrIntSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[989].time_unvarying = 1;
  (data->simulationInfo->realParameter[990] /* winRad.tra.radDat.absExtIrrIntSha[1,11,1] PARAM */) = 0.1354931525419724;
  data->modelData->realParameterData[990].time_unvarying = 1;
  (data->simulationInfo->realParameter[991] /* winRad.tra.radDat.absExtIrrIntSha[2,1,1] PARAM */) = 0.0948566787482195;
  data->modelData->realParameterData[991].time_unvarying = 1;
  (data->simulationInfo->realParameter[992] /* winRad.tra.radDat.absExtIrrIntSha[2,2,1] PARAM */) = 0.09537350821079466;
  data->modelData->realParameterData[992].time_unvarying = 1;
  (data->simulationInfo->realParameter[993] /* winRad.tra.radDat.absExtIrrIntSha[2,3,1] PARAM */) = 0.09687385356797265;
  data->modelData->realParameterData[993].time_unvarying = 1;
  (data->simulationInfo->realParameter[994] /* winRad.tra.radDat.absExtIrrIntSha[2,4,1] PARAM */) = 0.09916070692199794;
  data->modelData->realParameterData[994].time_unvarying = 1;
  (data->simulationInfo->realParameter[995] /* winRad.tra.radDat.absExtIrrIntSha[2,5,1] PARAM */) = 0.1017176618131253;
  data->modelData->realParameterData[995].time_unvarying = 1;
  (data->simulationInfo->realParameter[996] /* winRad.tra.radDat.absExtIrrIntSha[2,6,1] PARAM */) = 0.1033001439761687;
  data->modelData->realParameterData[996].time_unvarying = 1;
  (data->simulationInfo->realParameter[997] /* winRad.tra.radDat.absExtIrrIntSha[2,7,1] PARAM */) = 0.1011252056324434;
  data->modelData->realParameterData[997].time_unvarying = 1;
  (data->simulationInfo->realParameter[998] /* winRad.tra.radDat.absExtIrrIntSha[2,8,1] PARAM */) = 0.08990517963983256;
  data->modelData->realParameterData[998].time_unvarying = 1;
  (data->simulationInfo->realParameter[999] /* winRad.tra.radDat.absExtIrrIntSha[2,9,1] PARAM */) = 0.06281787526849789;
  data->modelData->realParameterData[999].time_unvarying = 1;
  (data->simulationInfo->realParameter[1000] /* winRad.tra.radDat.absExtIrrIntSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1000].time_unvarying = 1;
  (data->simulationInfo->realParameter[1001] /* winRad.tra.radDat.absExtIrrIntSha[2,11,1] PARAM */) = 0.1039656205865592;
  data->modelData->realParameterData[1001].time_unvarying = 1;
  (data->simulationInfo->realParameter[1002] /* winRad.tra.radDat.absExtIrrNoSha[1,1,1] PARAM */) = 0.0967242489000629;
  data->modelData->realParameterData[1002].time_unvarying = 1;
  (data->simulationInfo->realParameter[1003] /* winRad.tra.radDat.absExtIrrNoSha[1,2,1] PARAM */) = 0.09732302857079711;
  data->modelData->realParameterData[1003].time_unvarying = 1;
  (data->simulationInfo->realParameter[1004] /* winRad.tra.radDat.absExtIrrNoSha[1,3,1] PARAM */) = 0.09913158934736244;
  data->modelData->realParameterData[1004].time_unvarying = 1;
  (data->simulationInfo->realParameter[1005] /* winRad.tra.radDat.absExtIrrNoSha[1,4,1] PARAM */) = 0.1021914583318008;
  data->modelData->realParameterData[1005].time_unvarying = 1;
  (data->simulationInfo->realParameter[1006] /* winRad.tra.radDat.absExtIrrNoSha[1,5,1] PARAM */) = 0.1065974620703473;
  data->modelData->realParameterData[1006].time_unvarying = 1;
  (data->simulationInfo->realParameter[1007] /* winRad.tra.radDat.absExtIrrNoSha[1,6,1] PARAM */) = 0.1125698390133378;
  data->modelData->realParameterData[1007].time_unvarying = 1;
  (data->simulationInfo->realParameter[1008] /* winRad.tra.radDat.absExtIrrNoSha[1,7,1] PARAM */) = 0.1205657930053361;
  data->modelData->realParameterData[1008].time_unvarying = 1;
  (data->simulationInfo->realParameter[1009] /* winRad.tra.radDat.absExtIrrNoSha[1,8,1] PARAM */) = 0.1307986830869973;
  data->modelData->realParameterData[1009].time_unvarying = 1;
  (data->simulationInfo->realParameter[1010] /* winRad.tra.radDat.absExtIrrNoSha[1,9,1] PARAM */) = 0.1371678328302604;
  data->modelData->realParameterData[1010].time_unvarying = 1;
  (data->simulationInfo->realParameter[1011] /* winRad.tra.radDat.absExtIrrNoSha[1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1011].time_unvarying = 1;
  (data->simulationInfo->realParameter[1012] /* winRad.tra.radDat.absExtIrrNoSha[1,11,1] PARAM */) = 0.1227196468033888;
  data->modelData->realParameterData[1012].time_unvarying = 1;
  (data->simulationInfo->realParameter[1013] /* winRad.tra.radDat.absExtIrrNoSha[2,1,1] PARAM */) = 0.07632331866750475;
  data->modelData->realParameterData[1013].time_unvarying = 1;
  (data->simulationInfo->realParameter[1014] /* winRad.tra.radDat.absExtIrrNoSha[2,2,1] PARAM */) = 0.07674905803113916;
  data->modelData->realParameterData[1014].time_unvarying = 1;
  (data->simulationInfo->realParameter[1015] /* winRad.tra.radDat.absExtIrrNoSha[2,3,1] PARAM */) = 0.07799186166816173;
  data->modelData->realParameterData[1015].time_unvarying = 1;
  (data->simulationInfo->realParameter[1016] /* winRad.tra.radDat.absExtIrrNoSha[2,4,1] PARAM */) = 0.07991551880977556;
  data->modelData->realParameterData[1016].time_unvarying = 1;
  (data->simulationInfo->realParameter[1017] /* winRad.tra.radDat.absExtIrrNoSha[2,5,1] PARAM */) = 0.08216023482328237;
  data->modelData->realParameterData[1017].time_unvarying = 1;
  (data->simulationInfo->realParameter[1018] /* winRad.tra.radDat.absExtIrrNoSha[2,6,1] PARAM */) = 0.08385431211898785;
  data->modelData->realParameterData[1018].time_unvarying = 1;
  (data->simulationInfo->realParameter[1019] /* winRad.tra.radDat.absExtIrrNoSha[2,7,1] PARAM */) = 0.08303389367545573;
  data->modelData->realParameterData[1019].time_unvarying = 1;
  (data->simulationInfo->realParameter[1020] /* winRad.tra.radDat.absExtIrrNoSha[2,8,1] PARAM */) = 0.07585615681252504;
  data->modelData->realParameterData[1020].time_unvarying = 1;
  (data->simulationInfo->realParameter[1021] /* winRad.tra.radDat.absExtIrrNoSha[2,9,1] PARAM */) = 0.05645076246299933;
  data->modelData->realParameterData[1021].time_unvarying = 1;
  (data->simulationInfo->realParameter[1022] /* winRad.tra.radDat.absExtIrrNoSha[2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1022].time_unvarying = 1;
  (data->simulationInfo->realParameter[1023] /* winRad.tra.radDat.absExtIrrNoSha[2,11,1] PARAM */) = 0.08526920479249403;
  data->modelData->realParameterData[1023].time_unvarying = 1;
  (data->simulationInfo->realParameter[1024] /* winRad.tra.radDat.absIntIrrExtSha[1,1] PARAM */) = 0.1039656205865592;
  data->modelData->realParameterData[1024].time_unvarying = 1;
  (data->simulationInfo->realParameter[1025] /* winRad.tra.radDat.absIntIrrExtSha[2,1] PARAM */) = 0.1354931525419724;
  data->modelData->realParameterData[1025].time_unvarying = 1;
  (data->simulationInfo->realParameter[1026] /* winRad.tra.radDat.absIntIrrIntSha[1,1] PARAM */) = 0.02252369052121515;
  data->modelData->realParameterData[1026].time_unvarying = 1;
  (data->simulationInfo->realParameter[1027] /* winRad.tra.radDat.absIntIrrIntSha[2,1] PARAM */) = 0.03241615014704199;
  data->modelData->realParameterData[1027].time_unvarying = 1;
  (data->simulationInfo->realParameter[1028] /* winRad.tra.radDat.absIntIrrNoSha[1,1] PARAM */) = 0.08526920479249403;
  data->modelData->realParameterData[1028].time_unvarying = 1;
  (data->simulationInfo->realParameter[1029] /* winRad.tra.radDat.absIntIrrNoSha[2,1] PARAM */) = 0.1227196468033888;
  data->modelData->realParameterData[1029].time_unvarying = 1;
  (data->simulationInfo->realParameter[1030] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[1,1] PARAM */) = 0.3695381144818747;
  data->modelData->realParameterData[1030].time_unvarying = 1;
  (data->simulationInfo->realParameter[1031] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[2,1] PARAM */) = 0.3690498410990196;
  data->modelData->realParameterData[1031].time_unvarying = 1;
  (data->simulationInfo->realParameter[1032] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[3,1] PARAM */) = 0.3673475997451543;
  data->modelData->realParameterData[1032].time_unvarying = 1;
  (data->simulationInfo->realParameter[1033] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[4,1] PARAM */) = 0.3635548084822143;
  data->modelData->realParameterData[1033].time_unvarying = 1;
  (data->simulationInfo->realParameter[1034] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[5,1] PARAM */) = 0.3555423033605714;
  data->modelData->realParameterData[1034].time_unvarying = 1;
  (data->simulationInfo->realParameter[1035] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[6,1] PARAM */) = 0.3384699121977249;
  data->modelData->realParameterData[1035].time_unvarying = 1;
  (data->simulationInfo->realParameter[1036] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[7,1] PARAM */) = 0.3020070366994245;
  data->modelData->realParameterData[1036].time_unvarying = 1;
  (data->simulationInfo->realParameter[1037] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[8,1] PARAM */) = 0.2282840296108259;
  data->modelData->realParameterData[1037].time_unvarying = 1;
  (data->simulationInfo->realParameter[1038] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[9,1] PARAM */) = 0.1062597676765009;
  data->modelData->realParameterData[1038].time_unvarying = 1;
  (data->simulationInfo->realParameter[1039] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1039].time_unvarying = 1;
  (data->simulationInfo->realParameter[1040] /* winRad.tra.radDat.devAbsExtIrrIntShaDev[11,1] PARAM */) = 0.3052322754811356;
  data->modelData->realParameterData[1040].time_unvarying = 1;
  (data->simulationInfo->realParameter[1041] /* winRad.tra.radDat.devAbsIntIrrIntSha[1] PARAM */) = 0.5282960143941167;
  data->modelData->realParameterData[1041].time_unvarying = 1;
  (data->simulationInfo->realParameter[1042] /* winRad.tra.radDat.glass[1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1042].time_unvarying = 1;
  (data->simulationInfo->realParameter[1043] /* winRad.tra.radDat.glass[1,2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1043].time_unvarying = 1;
  (data->simulationInfo->realParameter[1044] /* winRad.tra.radDat.glass[2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1044].time_unvarying = 1;
  (data->simulationInfo->realParameter[1045] /* winRad.tra.radDat.glass[2,2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1045].time_unvarying = 1;
  (data->simulationInfo->realParameter[1046] /* winRad.tra.radDat.glass[3,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1046].time_unvarying = 1;
  (data->simulationInfo->realParameter[1047] /* winRad.tra.radDat.glass[3,2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1047].time_unvarying = 1;
  (data->simulationInfo->realParameter[1048] /* winRad.tra.radDat.layer[1,1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1048].time_unvarying = 1;
  (data->simulationInfo->realParameter[1049] /* winRad.tra.radDat.layer[1,1,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[1049].time_unvarying = 1;
  (data->simulationInfo->realParameter[1050] /* winRad.tra.radDat.layer[1,1,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[1050].time_unvarying = 1;
  (data->simulationInfo->realParameter[1051] /* winRad.tra.radDat.layer[1,1,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[1051].time_unvarying = 1;
  (data->simulationInfo->realParameter[1052] /* winRad.tra.radDat.layer[1,1,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[1052].time_unvarying = 1;
  (data->simulationInfo->realParameter[1053] /* winRad.tra.radDat.layer[1,1,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[1053].time_unvarying = 1;
  (data->simulationInfo->realParameter[1054] /* winRad.tra.radDat.layer[1,1,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[1054].time_unvarying = 1;
  (data->simulationInfo->realParameter[1055] /* winRad.tra.radDat.layer[1,1,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[1055].time_unvarying = 1;
  (data->simulationInfo->realParameter[1056] /* winRad.tra.radDat.layer[1,1,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[1056].time_unvarying = 1;
  (data->simulationInfo->realParameter[1057] /* winRad.tra.radDat.layer[1,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1057].time_unvarying = 1;
  (data->simulationInfo->realParameter[1058] /* winRad.tra.radDat.layer[1,1,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[1058].time_unvarying = 1;
  (data->simulationInfo->realParameter[1059] /* winRad.tra.radDat.layer[1,2,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1059].time_unvarying = 1;
  (data->simulationInfo->realParameter[1060] /* winRad.tra.radDat.layer[1,2,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[1060].time_unvarying = 1;
  (data->simulationInfo->realParameter[1061] /* winRad.tra.radDat.layer[1,2,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[1061].time_unvarying = 1;
  (data->simulationInfo->realParameter[1062] /* winRad.tra.radDat.layer[1,2,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[1062].time_unvarying = 1;
  (data->simulationInfo->realParameter[1063] /* winRad.tra.radDat.layer[1,2,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[1063].time_unvarying = 1;
  (data->simulationInfo->realParameter[1064] /* winRad.tra.radDat.layer[1,2,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[1064].time_unvarying = 1;
  (data->simulationInfo->realParameter[1065] /* winRad.tra.radDat.layer[1,2,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[1065].time_unvarying = 1;
  (data->simulationInfo->realParameter[1066] /* winRad.tra.radDat.layer[1,2,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[1066].time_unvarying = 1;
  (data->simulationInfo->realParameter[1067] /* winRad.tra.radDat.layer[1,2,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[1067].time_unvarying = 1;
  (data->simulationInfo->realParameter[1068] /* winRad.tra.radDat.layer[1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1068].time_unvarying = 1;
  (data->simulationInfo->realParameter[1069] /* winRad.tra.radDat.layer[1,2,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[1069].time_unvarying = 1;
  (data->simulationInfo->realParameter[1070] /* winRad.tra.radDat.layer[2,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1070].time_unvarying = 1;
  (data->simulationInfo->realParameter[1071] /* winRad.tra.radDat.layer[2,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[1071].time_unvarying = 1;
  (data->simulationInfo->realParameter[1072] /* winRad.tra.radDat.layer[2,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[1072].time_unvarying = 1;
  (data->simulationInfo->realParameter[1073] /* winRad.tra.radDat.layer[2,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[1073].time_unvarying = 1;
  (data->simulationInfo->realParameter[1074] /* winRad.tra.radDat.layer[2,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[1074].time_unvarying = 1;
  (data->simulationInfo->realParameter[1075] /* winRad.tra.radDat.layer[2,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[1075].time_unvarying = 1;
  (data->simulationInfo->realParameter[1076] /* winRad.tra.radDat.layer[2,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[1076].time_unvarying = 1;
  (data->simulationInfo->realParameter[1077] /* winRad.tra.radDat.layer[2,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[1077].time_unvarying = 1;
  (data->simulationInfo->realParameter[1078] /* winRad.tra.radDat.layer[2,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[1078].time_unvarying = 1;
  (data->simulationInfo->realParameter[1079] /* winRad.tra.radDat.layer[2,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1079].time_unvarying = 1;
  (data->simulationInfo->realParameter[1080] /* winRad.tra.radDat.layer[2,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[1080].time_unvarying = 1;
  (data->simulationInfo->realParameter[1081] /* winRad.tra.radDat.layer[2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1081].time_unvarying = 1;
  (data->simulationInfo->realParameter[1082] /* winRad.tra.radDat.layer[2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[1082].time_unvarying = 1;
  (data->simulationInfo->realParameter[1083] /* winRad.tra.radDat.layer[2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[1083].time_unvarying = 1;
  (data->simulationInfo->realParameter[1084] /* winRad.tra.radDat.layer[2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[1084].time_unvarying = 1;
  (data->simulationInfo->realParameter[1085] /* winRad.tra.radDat.layer[2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[1085].time_unvarying = 1;
  (data->simulationInfo->realParameter[1086] /* winRad.tra.radDat.layer[2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[1086].time_unvarying = 1;
  (data->simulationInfo->realParameter[1087] /* winRad.tra.radDat.layer[2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[1087].time_unvarying = 1;
  (data->simulationInfo->realParameter[1088] /* winRad.tra.radDat.layer[2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[1088].time_unvarying = 1;
  (data->simulationInfo->realParameter[1089] /* winRad.tra.radDat.layer[2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[1089].time_unvarying = 1;
  (data->simulationInfo->realParameter[1090] /* winRad.tra.radDat.layer[2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1090].time_unvarying = 1;
  (data->simulationInfo->realParameter[1091] /* winRad.tra.radDat.layer[2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[1091].time_unvarying = 1;
  (data->simulationInfo->realParameter[1092] /* winRad.tra.radDat.layer[3,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1092].time_unvarying = 1;
  (data->simulationInfo->realParameter[1093] /* winRad.tra.radDat.layer[3,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[1093].time_unvarying = 1;
  (data->simulationInfo->realParameter[1094] /* winRad.tra.radDat.layer[3,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[1094].time_unvarying = 1;
  (data->simulationInfo->realParameter[1095] /* winRad.tra.radDat.layer[3,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[1095].time_unvarying = 1;
  (data->simulationInfo->realParameter[1096] /* winRad.tra.radDat.layer[3,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[1096].time_unvarying = 1;
  (data->simulationInfo->realParameter[1097] /* winRad.tra.radDat.layer[3,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[1097].time_unvarying = 1;
  (data->simulationInfo->realParameter[1098] /* winRad.tra.radDat.layer[3,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[1098].time_unvarying = 1;
  (data->simulationInfo->realParameter[1099] /* winRad.tra.radDat.layer[3,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[1099].time_unvarying = 1;
  (data->simulationInfo->realParameter[1100] /* winRad.tra.radDat.layer[3,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[1100].time_unvarying = 1;
  (data->simulationInfo->realParameter[1101] /* winRad.tra.radDat.layer[3,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1101].time_unvarying = 1;
  (data->simulationInfo->realParameter[1102] /* winRad.tra.radDat.layer[3,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[1102].time_unvarying = 1;
  (data->simulationInfo->realParameter[1103] /* winRad.tra.radDat.layer[3,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1103].time_unvarying = 1;
  (data->simulationInfo->realParameter[1104] /* winRad.tra.radDat.layer[3,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[1104].time_unvarying = 1;
  (data->simulationInfo->realParameter[1105] /* winRad.tra.radDat.layer[3,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[1105].time_unvarying = 1;
  (data->simulationInfo->realParameter[1106] /* winRad.tra.radDat.layer[3,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[1106].time_unvarying = 1;
  (data->simulationInfo->realParameter[1107] /* winRad.tra.radDat.layer[3,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[1107].time_unvarying = 1;
  (data->simulationInfo->realParameter[1108] /* winRad.tra.radDat.layer[3,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[1108].time_unvarying = 1;
  (data->simulationInfo->realParameter[1109] /* winRad.tra.radDat.layer[3,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[1109].time_unvarying = 1;
  (data->simulationInfo->realParameter[1110] /* winRad.tra.radDat.layer[3,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[1110].time_unvarying = 1;
  (data->simulationInfo->realParameter[1111] /* winRad.tra.radDat.layer[3,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[1111].time_unvarying = 1;
  (data->simulationInfo->realParameter[1112] /* winRad.tra.radDat.layer[3,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1112].time_unvarying = 1;
  (data->simulationInfo->realParameter[1113] /* winRad.tra.radDat.layer[3,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[1113].time_unvarying = 1;
  (data->simulationInfo->realParameter[1114] /* winRad.tra.radDat.psi[1] PARAM */) = 0.0;
  data->modelData->realParameterData[1114].time_unvarying = 1;
  (data->simulationInfo->realParameter[1115] /* winRad.tra.radDat.psi[2] PARAM */) = 0.1745329251994329;
  data->modelData->realParameterData[1115].time_unvarying = 1;
  (data->simulationInfo->realParameter[1116] /* winRad.tra.radDat.psi[3] PARAM */) = 0.3490658503988659;
  data->modelData->realParameterData[1116].time_unvarying = 1;
  (data->simulationInfo->realParameter[1117] /* winRad.tra.radDat.psi[4] PARAM */) = 0.5235987755982988;
  data->modelData->realParameterData[1117].time_unvarying = 1;
  (data->simulationInfo->realParameter[1118] /* winRad.tra.radDat.psi[5] PARAM */) = 0.6981317007977318;
  data->modelData->realParameterData[1118].time_unvarying = 1;
  (data->simulationInfo->realParameter[1119] /* winRad.tra.radDat.psi[6] PARAM */) = 0.8726646259971648;
  data->modelData->realParameterData[1119].time_unvarying = 1;
  (data->simulationInfo->realParameter[1120] /* winRad.tra.radDat.psi[7] PARAM */) = 1.047197551196598;
  data->modelData->realParameterData[1120].time_unvarying = 1;
  (data->simulationInfo->realParameter[1121] /* winRad.tra.radDat.psi[8] PARAM */) = 1.221730476396031;
  data->modelData->realParameterData[1121].time_unvarying = 1;
  (data->simulationInfo->realParameter[1122] /* winRad.tra.radDat.psi[9] PARAM */) = 1.396263401595464;
  data->modelData->realParameterData[1122].time_unvarying = 1;
  (data->simulationInfo->realParameter[1123] /* winRad.tra.radDat.psi[10] PARAM */) = 1.570796326794897;
  data->modelData->realParameterData[1123].time_unvarying = 1;
  (data->simulationInfo->realParameter[1124] /* winRad.tra.radDat.rhoGlaSol_a[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1124].time_unvarying = 1;
  (data->simulationInfo->realParameter[1125] /* winRad.tra.radDat.rhoGlaSol_a[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1125].time_unvarying = 1;
  (data->simulationInfo->realParameter[1126] /* winRad.tra.radDat.rhoGlaSol_b[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1126].time_unvarying = 1;
  (data->simulationInfo->realParameter[1127] /* winRad.tra.radDat.rhoGlaSol_b[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1127].time_unvarying = 1;
  (data->simulationInfo->realParameter[1128] /* winRad.tra.radDat.rhoShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[1128].time_unvarying = 1;
  (data->simulationInfo->realParameter[1129] /* winRad.tra.radDat.rhoShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[1129].time_unvarying = 1;
  (data->simulationInfo->realParameter[1130] /* winRad.tra.radDat.tauGlaSol[1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1130].time_unvarying = 1;
  (data->simulationInfo->realParameter[1131] /* winRad.tra.radDat.tauGlaSol[2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1131].time_unvarying = 1;
  (data->simulationInfo->realParameter[1132] /* winRad.tra.radDat.tauShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[1132].time_unvarying = 1;
  (data->simulationInfo->realParameter[1133] /* winRad.tra.radDat.tauShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[1133].time_unvarying = 1;
  (data->simulationInfo->realParameter[1134] /* winRad.tra.radDat.traRef[1,1,1,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1134].time_unvarying = 1;
  (data->simulationInfo->realParameter[1135] /* winRad.tra.radDat.traRef[1,1,1,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[1135].time_unvarying = 1;
  (data->simulationInfo->realParameter[1136] /* winRad.tra.radDat.traRef[1,1,1,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[1136].time_unvarying = 1;
  (data->simulationInfo->realParameter[1137] /* winRad.tra.radDat.traRef[1,1,1,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[1137].time_unvarying = 1;
  (data->simulationInfo->realParameter[1138] /* winRad.tra.radDat.traRef[1,1,1,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[1138].time_unvarying = 1;
  (data->simulationInfo->realParameter[1139] /* winRad.tra.radDat.traRef[1,1,1,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[1139].time_unvarying = 1;
  (data->simulationInfo->realParameter[1140] /* winRad.tra.radDat.traRef[1,1,1,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[1140].time_unvarying = 1;
  (data->simulationInfo->realParameter[1141] /* winRad.tra.radDat.traRef[1,1,1,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[1141].time_unvarying = 1;
  (data->simulationInfo->realParameter[1142] /* winRad.tra.radDat.traRef[1,1,1,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[1142].time_unvarying = 1;
  (data->simulationInfo->realParameter[1143] /* winRad.tra.radDat.traRef[1,1,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1143].time_unvarying = 1;
  (data->simulationInfo->realParameter[1144] /* winRad.tra.radDat.traRef[1,1,1,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[1144].time_unvarying = 1;
  (data->simulationInfo->realParameter[1145] /* winRad.tra.radDat.traRef[1,1,2,1,1] PARAM */) = 0.6994906348208673;
  data->modelData->realParameterData[1145].time_unvarying = 1;
  (data->simulationInfo->realParameter[1146] /* winRad.tra.radDat.traRef[1,1,2,2,1] PARAM */) = 0.6985663927869478;
  data->modelData->realParameterData[1146].time_unvarying = 1;
  (data->simulationInfo->realParameter[1147] /* winRad.tra.radDat.traRef[1,1,2,3,1] PARAM */) = 0.6953442572654116;
  data->modelData->realParameterData[1147].time_unvarying = 1;
  (data->simulationInfo->realParameter[1148] /* winRad.tra.radDat.traRef[1,1,2,4,1] PARAM */) = 0.6881649654297732;
  data->modelData->realParameterData[1148].time_unvarying = 1;
  (data->simulationInfo->realParameter[1149] /* winRad.tra.radDat.traRef[1,1,2,5,1] PARAM */) = 0.6729982692909955;
  data->modelData->realParameterData[1149].time_unvarying = 1;
  (data->simulationInfo->realParameter[1150] /* winRad.tra.radDat.traRef[1,1,2,6,1] PARAM */) = 0.6406823125211414;
  data->modelData->realParameterData[1150].time_unvarying = 1;
  (data->simulationInfo->realParameter[1151] /* winRad.tra.radDat.traRef[1,1,2,7,1] PARAM */) = 0.5716625309880206;
  data->modelData->realParameterData[1151].time_unvarying = 1;
  (data->simulationInfo->realParameter[1152] /* winRad.tra.radDat.traRef[1,1,2,8,1] PARAM */) = 0.4321138592586893;
  data->modelData->realParameterData[1152].time_unvarying = 1;
  (data->simulationInfo->realParameter[1153] /* winRad.tra.radDat.traRef[1,1,2,9,1] PARAM */) = 0.2011367960032149;
  data->modelData->realParameterData[1153].time_unvarying = 1;
  (data->simulationInfo->realParameter[1154] /* winRad.tra.radDat.traRef[1,1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1154].time_unvarying = 1;
  (data->simulationInfo->realParameter[1155] /* winRad.tra.radDat.traRef[1,1,2,11,1] PARAM */) = 0.5777675151140318;
  data->modelData->realParameterData[1155].time_unvarying = 1;
  (data->simulationInfo->realParameter[1156] /* winRad.tra.radDat.traRef[1,2,1,1,1] PARAM */) = 0.6994906348208673;
  data->modelData->realParameterData[1156].time_unvarying = 1;
  (data->simulationInfo->realParameter[1157] /* winRad.tra.radDat.traRef[1,2,1,2,1] PARAM */) = 0.6985663927869478;
  data->modelData->realParameterData[1157].time_unvarying = 1;
  (data->simulationInfo->realParameter[1158] /* winRad.tra.radDat.traRef[1,2,1,3,1] PARAM */) = 0.6953442572654116;
  data->modelData->realParameterData[1158].time_unvarying = 1;
  (data->simulationInfo->realParameter[1159] /* winRad.tra.radDat.traRef[1,2,1,4,1] PARAM */) = 0.6881649654297732;
  data->modelData->realParameterData[1159].time_unvarying = 1;
  (data->simulationInfo->realParameter[1160] /* winRad.tra.radDat.traRef[1,2,1,5,1] PARAM */) = 0.6729982692909955;
  data->modelData->realParameterData[1160].time_unvarying = 1;
  (data->simulationInfo->realParameter[1161] /* winRad.tra.radDat.traRef[1,2,1,6,1] PARAM */) = 0.6406823125211414;
  data->modelData->realParameterData[1161].time_unvarying = 1;
  (data->simulationInfo->realParameter[1162] /* winRad.tra.radDat.traRef[1,2,1,7,1] PARAM */) = 0.5716625309880206;
  data->modelData->realParameterData[1162].time_unvarying = 1;
  (data->simulationInfo->realParameter[1163] /* winRad.tra.radDat.traRef[1,2,1,8,1] PARAM */) = 0.4321138592586893;
  data->modelData->realParameterData[1163].time_unvarying = 1;
  (data->simulationInfo->realParameter[1164] /* winRad.tra.radDat.traRef[1,2,1,9,1] PARAM */) = 0.2011367960032149;
  data->modelData->realParameterData[1164].time_unvarying = 1;
  (data->simulationInfo->realParameter[1165] /* winRad.tra.radDat.traRef[1,2,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1165].time_unvarying = 1;
  (data->simulationInfo->realParameter[1166] /* winRad.tra.radDat.traRef[1,2,1,11,1] PARAM */) = 0.5777675151140318;
  data->modelData->realParameterData[1166].time_unvarying = 1;
  (data->simulationInfo->realParameter[1167] /* winRad.tra.radDat.traRef[1,2,2,1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1167].time_unvarying = 1;
  (data->simulationInfo->realParameter[1168] /* winRad.tra.radDat.traRef[1,2,2,2,1] PARAM */) = 0.8334499783754505;
  data->modelData->realParameterData[1168].time_unvarying = 1;
  (data->simulationInfo->realParameter[1169] /* winRad.tra.radDat.traRef[1,2,2,3,1] PARAM */) = 0.8315103375880241;
  data->modelData->realParameterData[1169].time_unvarying = 1;
  (data->simulationInfo->realParameter[1170] /* winRad.tra.radDat.traRef[1,2,2,4,1] PARAM */) = 0.8271040934304237;
  data->modelData->realParameterData[1170].time_unvarying = 1;
  (data->simulationInfo->realParameter[1171] /* winRad.tra.radDat.traRef[1,2,2,5,1] PARAM */) = 0.8175591411591593;
  data->modelData->realParameterData[1171].time_unvarying = 1;
  (data->simulationInfo->realParameter[1172] /* winRad.tra.radDat.traRef[1,2,2,6,1] PARAM */) = 0.796471533732221;
  data->modelData->realParameterData[1172].time_unvarying = 1;
  (data->simulationInfo->realParameter[1173] /* winRad.tra.radDat.traRef[1,2,2,7,1] PARAM */) = 0.7483138645896741;
  data->modelData->realParameterData[1173].time_unvarying = 1;
  (data->simulationInfo->realParameter[1174] /* winRad.tra.radDat.traRef[1,2,2,8,1] PARAM */) = 0.6360985643062074;
  data->modelData->realParameterData[1174].time_unvarying = 1;
  (data->simulationInfo->realParameter[1175] /* winRad.tra.radDat.traRef[1,2,2,9,1] PARAM */) = 0.3873841657715181;
  data->modelData->realParameterData[1175].time_unvarying = 1;
  (data->simulationInfo->realParameter[1176] /* winRad.tra.radDat.traRef[1,2,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1176].time_unvarying = 1;
  (data->simulationInfo->realParameter[1177] /* winRad.tra.radDat.traRef[1,2,2,11,1] PARAM */) = 0.7530698803796315;
  data->modelData->realParameterData[1177].time_unvarying = 1;
  (data->simulationInfo->realParameter[1178] /* winRad.tra.radDat.traRef[2,1,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1178].time_unvarying = 1;
  (data->simulationInfo->realParameter[1179] /* winRad.tra.radDat.traRef[2,1,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[1179].time_unvarying = 1;
  (data->simulationInfo->realParameter[1180] /* winRad.tra.radDat.traRef[2,1,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[1180].time_unvarying = 1;
  (data->simulationInfo->realParameter[1181] /* winRad.tra.radDat.traRef[2,1,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[1181].time_unvarying = 1;
  (data->simulationInfo->realParameter[1182] /* winRad.tra.radDat.traRef[2,1,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[1182].time_unvarying = 1;
  (data->simulationInfo->realParameter[1183] /* winRad.tra.radDat.traRef[2,1,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[1183].time_unvarying = 1;
  (data->simulationInfo->realParameter[1184] /* winRad.tra.radDat.traRef[2,1,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[1184].time_unvarying = 1;
  (data->simulationInfo->realParameter[1185] /* winRad.tra.radDat.traRef[2,1,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[1185].time_unvarying = 1;
  (data->simulationInfo->realParameter[1186] /* winRad.tra.radDat.traRef[2,1,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[1186].time_unvarying = 1;
  (data->simulationInfo->realParameter[1187] /* winRad.tra.radDat.traRef[2,1,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1187].time_unvarying = 1;
  (data->simulationInfo->realParameter[1188] /* winRad.tra.radDat.traRef[2,1,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[1188].time_unvarying = 1;
  (data->simulationInfo->realParameter[1189] /* winRad.tra.radDat.traRef[2,1,2,1,1] PARAM */) = 0.127461797611565;
  data->modelData->realParameterData[1189].time_unvarying = 1;
  (data->simulationInfo->realParameter[1190] /* winRad.tra.radDat.traRef[2,1,2,2,1] PARAM */) = 0.1273615206111159;
  data->modelData->realParameterData[1190].time_unvarying = 1;
  (data->simulationInfo->realParameter[1191] /* winRad.tra.radDat.traRef[2,1,2,3,1] PARAM */) = 0.1275322917190642;
  data->modelData->realParameterData[1191].time_unvarying = 1;
  (data->simulationInfo->realParameter[1192] /* winRad.tra.radDat.traRef[2,1,2,4,1] PARAM */) = 0.1297280574286503;
  data->modelData->realParameterData[1192].time_unvarying = 1;
  (data->simulationInfo->realParameter[1193] /* winRad.tra.radDat.traRef[2,1,2,5,1] PARAM */) = 0.1382440338153747;
  data->modelData->realParameterData[1193].time_unvarying = 1;
  (data->simulationInfo->realParameter[1194] /* winRad.tra.radDat.traRef[2,1,2,6,1] PARAM */) = 0.1628935363465329;
  data->modelData->realParameterData[1194].time_unvarying = 1;
  (data->simulationInfo->realParameter[1195] /* winRad.tra.radDat.traRef[2,1,2,7,1] PARAM */) = 0.2247377823311878;
  data->modelData->realParameterData[1195].time_unvarying = 1;
  (data->simulationInfo->realParameter[1196] /* winRad.tra.radDat.traRef[2,1,2,8,1] PARAM */) = 0.3612313008417883;
  data->modelData->realParameterData[1196].time_unvarying = 1;
  (data->simulationInfo->realParameter[1197] /* winRad.tra.radDat.traRef[2,1,2,9,1] PARAM */) = 0.6052446087035255;
  data->modelData->realParameterData[1197].time_unvarying = 1;
  (data->simulationInfo->realParameter[1198] /* winRad.tra.radDat.traRef[2,1,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1198].time_unvarying = 1;
  (data->simulationInfo->realParameter[1199] /* winRad.tra.radDat.traRef[2,1,2,11,1] PARAM */) = 0.2142436332900854;
  data->modelData->realParameterData[1199].time_unvarying = 1;
  (data->simulationInfo->realParameter[1200] /* winRad.tra.radDat.traRef[2,2,1,1,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1200].time_unvarying = 1;
  (data->simulationInfo->realParameter[1201] /* winRad.tra.radDat.traRef[2,2,1,2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1201].time_unvarying = 1;
  (data->simulationInfo->realParameter[1202] /* winRad.tra.radDat.traRef[2,2,1,3,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1202].time_unvarying = 1;
  (data->simulationInfo->realParameter[1203] /* winRad.tra.radDat.traRef[2,2,1,4,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1203].time_unvarying = 1;
  (data->simulationInfo->realParameter[1204] /* winRad.tra.radDat.traRef[2,2,1,5,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1204].time_unvarying = 1;
  (data->simulationInfo->realParameter[1205] /* winRad.tra.radDat.traRef[2,2,1,6,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1205].time_unvarying = 1;
  (data->simulationInfo->realParameter[1206] /* winRad.tra.radDat.traRef[2,2,1,7,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1206].time_unvarying = 1;
  (data->simulationInfo->realParameter[1207] /* winRad.tra.radDat.traRef[2,2,1,8,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1207].time_unvarying = 1;
  (data->simulationInfo->realParameter[1208] /* winRad.tra.radDat.traRef[2,2,1,9,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1208].time_unvarying = 1;
  (data->simulationInfo->realParameter[1209] /* winRad.tra.radDat.traRef[2,2,1,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1209].time_unvarying = 1;
  (data->simulationInfo->realParameter[1210] /* winRad.tra.radDat.traRef[2,2,1,11,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1210].time_unvarying = 1;
  (data->simulationInfo->realParameter[1211] /* winRad.tra.radDat.traRef[2,2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1211].time_unvarying = 1;
  (data->simulationInfo->realParameter[1212] /* winRad.tra.radDat.traRef[2,2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[1212].time_unvarying = 1;
  (data->simulationInfo->realParameter[1213] /* winRad.tra.radDat.traRef[2,2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[1213].time_unvarying = 1;
  (data->simulationInfo->realParameter[1214] /* winRad.tra.radDat.traRef[2,2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[1214].time_unvarying = 1;
  (data->simulationInfo->realParameter[1215] /* winRad.tra.radDat.traRef[2,2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[1215].time_unvarying = 1;
  (data->simulationInfo->realParameter[1216] /* winRad.tra.radDat.traRef[2,2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[1216].time_unvarying = 1;
  (data->simulationInfo->realParameter[1217] /* winRad.tra.radDat.traRef[2,2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[1217].time_unvarying = 1;
  (data->simulationInfo->realParameter[1218] /* winRad.tra.radDat.traRef[2,2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[1218].time_unvarying = 1;
  (data->simulationInfo->realParameter[1219] /* winRad.tra.radDat.traRef[2,2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[1219].time_unvarying = 1;
  (data->simulationInfo->realParameter[1220] /* winRad.tra.radDat.traRef[2,2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1220].time_unvarying = 1;
  (data->simulationInfo->realParameter[1221] /* winRad.tra.radDat.traRef[2,2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[1221].time_unvarying = 1;
  (data->simulationInfo->realParameter[1222] /* winRad.tra.radDat.traRef[3,1,1,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1222].time_unvarying = 1;
  (data->simulationInfo->realParameter[1223] /* winRad.tra.radDat.traRef[3,1,1,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[1223].time_unvarying = 1;
  (data->simulationInfo->realParameter[1224] /* winRad.tra.radDat.traRef[3,1,1,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[1224].time_unvarying = 1;
  (data->simulationInfo->realParameter[1225] /* winRad.tra.radDat.traRef[3,1,1,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[1225].time_unvarying = 1;
  (data->simulationInfo->realParameter[1226] /* winRad.tra.radDat.traRef[3,1,1,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[1226].time_unvarying = 1;
  (data->simulationInfo->realParameter[1227] /* winRad.tra.radDat.traRef[3,1,1,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[1227].time_unvarying = 1;
  (data->simulationInfo->realParameter[1228] /* winRad.tra.radDat.traRef[3,1,1,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[1228].time_unvarying = 1;
  (data->simulationInfo->realParameter[1229] /* winRad.tra.radDat.traRef[3,1,1,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[1229].time_unvarying = 1;
  (data->simulationInfo->realParameter[1230] /* winRad.tra.radDat.traRef[3,1,1,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[1230].time_unvarying = 1;
  (data->simulationInfo->realParameter[1231] /* winRad.tra.radDat.traRef[3,1,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1231].time_unvarying = 1;
  (data->simulationInfo->realParameter[1232] /* winRad.tra.radDat.traRef[3,1,1,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[1232].time_unvarying = 1;
  (data->simulationInfo->realParameter[1233] /* winRad.tra.radDat.traRef[3,1,2,1,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1233].time_unvarying = 1;
  (data->simulationInfo->realParameter[1234] /* winRad.tra.radDat.traRef[3,1,2,2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1234].time_unvarying = 1;
  (data->simulationInfo->realParameter[1235] /* winRad.tra.radDat.traRef[3,1,2,3,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1235].time_unvarying = 1;
  (data->simulationInfo->realParameter[1236] /* winRad.tra.radDat.traRef[3,1,2,4,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1236].time_unvarying = 1;
  (data->simulationInfo->realParameter[1237] /* winRad.tra.radDat.traRef[3,1,2,5,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1237].time_unvarying = 1;
  (data->simulationInfo->realParameter[1238] /* winRad.tra.radDat.traRef[3,1,2,6,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1238].time_unvarying = 1;
  (data->simulationInfo->realParameter[1239] /* winRad.tra.radDat.traRef[3,1,2,7,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1239].time_unvarying = 1;
  (data->simulationInfo->realParameter[1240] /* winRad.tra.radDat.traRef[3,1,2,8,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1240].time_unvarying = 1;
  (data->simulationInfo->realParameter[1241] /* winRad.tra.radDat.traRef[3,1,2,9,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1241].time_unvarying = 1;
  (data->simulationInfo->realParameter[1242] /* winRad.tra.radDat.traRef[3,1,2,10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1242].time_unvarying = 1;
  (data->simulationInfo->realParameter[1243] /* winRad.tra.radDat.traRef[3,1,2,11,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1243].time_unvarying = 1;
  (data->simulationInfo->realParameter[1244] /* winRad.tra.radDat.traRef[3,2,1,1,1] PARAM */) = 0.127461797611565;
  data->modelData->realParameterData[1244].time_unvarying = 1;
  (data->simulationInfo->realParameter[1245] /* winRad.tra.radDat.traRef[3,2,1,2,1] PARAM */) = 0.1273615206111159;
  data->modelData->realParameterData[1245].time_unvarying = 1;
  (data->simulationInfo->realParameter[1246] /* winRad.tra.radDat.traRef[3,2,1,3,1] PARAM */) = 0.1275322917190642;
  data->modelData->realParameterData[1246].time_unvarying = 1;
  (data->simulationInfo->realParameter[1247] /* winRad.tra.radDat.traRef[3,2,1,4,1] PARAM */) = 0.1297280574286503;
  data->modelData->realParameterData[1247].time_unvarying = 1;
  (data->simulationInfo->realParameter[1248] /* winRad.tra.radDat.traRef[3,2,1,5,1] PARAM */) = 0.1382440338153747;
  data->modelData->realParameterData[1248].time_unvarying = 1;
  (data->simulationInfo->realParameter[1249] /* winRad.tra.radDat.traRef[3,2,1,6,1] PARAM */) = 0.1628935363465329;
  data->modelData->realParameterData[1249].time_unvarying = 1;
  (data->simulationInfo->realParameter[1250] /* winRad.tra.radDat.traRef[3,2,1,7,1] PARAM */) = 0.2247377823311878;
  data->modelData->realParameterData[1250].time_unvarying = 1;
  (data->simulationInfo->realParameter[1251] /* winRad.tra.radDat.traRef[3,2,1,8,1] PARAM */) = 0.3612313008417883;
  data->modelData->realParameterData[1251].time_unvarying = 1;
  (data->simulationInfo->realParameter[1252] /* winRad.tra.radDat.traRef[3,2,1,9,1] PARAM */) = 0.6052446087035255;
  data->modelData->realParameterData[1252].time_unvarying = 1;
  (data->simulationInfo->realParameter[1253] /* winRad.tra.radDat.traRef[3,2,1,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1253].time_unvarying = 1;
  (data->simulationInfo->realParameter[1254] /* winRad.tra.radDat.traRef[3,2,1,11,1] PARAM */) = 0.2142436332900854;
  data->modelData->realParameterData[1254].time_unvarying = 1;
  (data->simulationInfo->realParameter[1255] /* winRad.tra.radDat.traRef[3,2,2,1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1255].time_unvarying = 1;
  (data->simulationInfo->realParameter[1256] /* winRad.tra.radDat.traRef[3,2,2,2,1] PARAM */) = 0.07498177354265534;
  data->modelData->realParameterData[1256].time_unvarying = 1;
  (data->simulationInfo->realParameter[1257] /* winRad.tra.radDat.traRef[3,2,2,3,1] PARAM */) = 0.07522501177712052;
  data->modelData->realParameterData[1257].time_unvarying = 1;
  (data->simulationInfo->realParameter[1258] /* winRad.tra.radDat.traRef[3,2,2,4,1] PARAM */) = 0.07684560459742995;
  data->modelData->realParameterData[1258].time_unvarying = 1;
  (data->simulationInfo->realParameter[1259] /* winRad.tra.radDat.traRef[3,2,2,5,1] PARAM */) = 0.0826325025870837;
  data->modelData->realParameterData[1259].time_unvarying = 1;
  (data->simulationInfo->realParameter[1260] /* winRad.tra.radDat.traRef[3,2,2,6,1] PARAM */) = 0.09928402049768174;
  data->modelData->realParameterData[1260].time_unvarying = 1;
  (data->simulationInfo->realParameter[1261] /* winRad.tra.radDat.traRef[3,2,2,7,1] PARAM */) = 0.1429936630161356;
  data->modelData->realParameterData[1261].time_unvarying = 1;
  (data->simulationInfo->realParameter[1262] /* winRad.tra.radDat.traRef[3,2,2,8,1] PARAM */) = 0.2522364395165995;
  data->modelData->realParameterData[1262].time_unvarying = 1;
  (data->simulationInfo->realParameter[1263] /* winRad.tra.radDat.traRef[3,2,2,9,1] PARAM */) = 0.5038931541498671;
  data->modelData->realParameterData[1263].time_unvarying = 1;
  (data->simulationInfo->realParameter[1264] /* winRad.tra.radDat.traRef[3,2,2,10,1] PARAM */) = 1.0;
  data->modelData->realParameterData[1264].time_unvarying = 1;
  (data->simulationInfo->realParameter[1265] /* winRad.tra.radDat.traRef[3,2,2,11,1] PARAM */) = 0.1357891015233642;
  data->modelData->realParameterData[1265].time_unvarying = 1;
  (data->simulationInfo->realParameter[1266] /* winRad.tra.radDat.traRefShaDev[1,1] PARAM */) = 0.25;
  data->modelData->realParameterData[1266].time_unvarying = 1;
  (data->simulationInfo->realParameter[1267] /* winRad.tra.radDat.traRefShaDev[1,2] PARAM */) = 0.25;
  data->modelData->realParameterData[1267].time_unvarying = 1;
  (data->simulationInfo->realParameter[1268] /* winRad.tra.radDat.traRefShaDev[2,1] PARAM */) = 0.25;
  data->modelData->realParameterData[1268].time_unvarying = 1;
  (data->simulationInfo->realParameter[1269] /* winRad.tra.radDat.traRefShaDev[2,2] PARAM */) = 0.25;
  data->modelData->realParameterData[1269].time_unvarying = 1;
  (data->simulationInfo->realParameter[1270] /* winRad.tra.radDat.winTraExtIrrExtSha[1,1] PARAM */) = 0.1807604077499478;
  data->modelData->realParameterData[1270].time_unvarying = 1;
  (data->simulationInfo->realParameter[1271] /* winRad.tra.radDat.winTraExtIrrExtSha[2,1] PARAM */) = 0.1805169418146947;
  data->modelData->realParameterData[1271].time_unvarying = 1;
  (data->simulationInfo->realParameter[1272] /* winRad.tra.radDat.winTraExtIrrExtSha[3,1] PARAM */) = 0.1796921494729775;
  data->modelData->realParameterData[1272].time_unvarying = 1;
  (data->simulationInfo->realParameter[1273] /* winRad.tra.radDat.winTraExtIrrExtSha[4,1] PARAM */) = 0.1779366487415986;
  data->modelData->realParameterData[1273].time_unvarying = 1;
  (data->simulationInfo->realParameter[1274] /* winRad.tra.radDat.winTraExtIrrExtSha[5,1] PARAM */) = 0.1743935175988208;
  data->modelData->realParameterData[1274].time_unvarying = 1;
  (data->simulationInfo->realParameter[1275] /* winRad.tra.radDat.winTraExtIrrExtSha[6,1] PARAM */) = 0.1670623982483838;
  data->modelData->realParameterData[1275].time_unvarying = 1;
  (data->simulationInfo->realParameter[1276] /* winRad.tra.radDat.winTraExtIrrExtSha[7,1] PARAM */) = 0.1513996817065354;
  data->modelData->realParameterData[1276].time_unvarying = 1;
  (data->simulationInfo->realParameter[1277] /* winRad.tra.radDat.winTraExtIrrExtSha[8,1] PARAM */) = 0.1183363819368878;
  data->modelData->realParameterData[1277].time_unvarying = 1;
  (data->simulationInfo->realParameter[1278] /* winRad.tra.radDat.winTraExtIrrExtSha[9,1] PARAM */) = 0.05832334293934013;
  data->modelData->realParameterData[1278].time_unvarying = 1;
  (data->simulationInfo->realParameter[1279] /* winRad.tra.radDat.winTraExtIrrExtSha[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1279].time_unvarying = 1;
  (data->simulationInfo->realParameter[1280] /* winRad.tra.radDat.winTraExtIrrExtSha[11,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[1280].time_unvarying = 1;
  (data->simulationInfo->realParameter[1281] /* winRad.tra.radDat.winTraExtIrrIntSha[1,1] PARAM */) = 0.1847690572409374;
  data->modelData->realParameterData[1281].time_unvarying = 1;
  (data->simulationInfo->realParameter[1282] /* winRad.tra.radDat.winTraExtIrrIntSha[2,1] PARAM */) = 0.1845249205495098;
  data->modelData->realParameterData[1282].time_unvarying = 1;
  (data->simulationInfo->realParameter[1283] /* winRad.tra.radDat.winTraExtIrrIntSha[3,1] PARAM */) = 0.1836737998725771;
  data->modelData->realParameterData[1283].time_unvarying = 1;
  (data->simulationInfo->realParameter[1284] /* winRad.tra.radDat.winTraExtIrrIntSha[4,1] PARAM */) = 0.1817774042411072;
  data->modelData->realParameterData[1284].time_unvarying = 1;
  (data->simulationInfo->realParameter[1285] /* winRad.tra.radDat.winTraExtIrrIntSha[5,1] PARAM */) = 0.1777711516802857;
  data->modelData->realParameterData[1285].time_unvarying = 1;
  (data->simulationInfo->realParameter[1286] /* winRad.tra.radDat.winTraExtIrrIntSha[6,1] PARAM */) = 0.1692349560988624;
  data->modelData->realParameterData[1286].time_unvarying = 1;
  (data->simulationInfo->realParameter[1287] /* winRad.tra.radDat.winTraExtIrrIntSha[7,1] PARAM */) = 0.1510035183497123;
  data->modelData->realParameterData[1287].time_unvarying = 1;
  (data->simulationInfo->realParameter[1288] /* winRad.tra.radDat.winTraExtIrrIntSha[8,1] PARAM */) = 0.1141420148054129;
  data->modelData->realParameterData[1288].time_unvarying = 1;
  (data->simulationInfo->realParameter[1289] /* winRad.tra.radDat.winTraExtIrrIntSha[9,1] PARAM */) = 0.05312988383825046;
  data->modelData->realParameterData[1289].time_unvarying = 1;
  (data->simulationInfo->realParameter[1290] /* winRad.tra.radDat.winTraExtIrrIntSha[10,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1290].time_unvarying = 1;
  (data->simulationInfo->realParameter[1291] /* winRad.tra.radDat.winTraExtIrrIntSha[11,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[1291].time_unvarying = 1;
  (data->simulationInfo->realParameter[1292] /* winRad.tra.radDat.winTraRefIntIrrExtSha[1,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[1292].time_unvarying = 1;
  (data->simulationInfo->realParameter[1293] /* winRad.tra.radDat.winTraRefIntIrrExtSha[2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1293].time_unvarying = 1;
  (data->simulationInfo->realParameter[1294] /* winRad.tra.radDat.winTraRefIntIrrExtSha[3,1] PARAM */) = 0.302420279958754;
  data->modelData->realParameterData[1294].time_unvarying = 1;
  (data->simulationInfo->realParameter[1295] /* winRad.tra.radDat.winTraRefIntIrrIntSha[1,1] PARAM */) = 0.1526161377405678;
  data->modelData->realParameterData[1295].time_unvarying = 1;
  (data->simulationInfo->realParameter[1296] /* winRad.tra.radDat.winTraRefIntIrrIntSha[2,1] PARAM */) = 0.0;
  data->modelData->realParameterData[1296].time_unvarying = 1;
  (data->simulationInfo->realParameter[1297] /* winRad.tra.radDat.winTraRefIntIrrIntSha[3,1] PARAM */) = 0.2641480071970583;
  data->modelData->realParameterData[1297].time_unvarying = 1;
  (data->simulationInfo->realParameter[1298] /* winRad.tra.radDat.xGla[1] PARAM */) = 0.003;
  data->modelData->realParameterData[1298].time_unvarying = 1;
  (data->simulationInfo->realParameter[1299] /* winRad.tra.radDat.xGla[2] PARAM */) = 0.003;
  data->modelData->realParameterData[1299].time_unvarying = 1;
  (data->simulationInfo->realParameter[1300] /* winRad.tra.rhoGlaSol_a[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1300].time_unvarying = 1;
  (data->simulationInfo->realParameter[1301] /* winRad.tra.rhoGlaSol_a[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1301].time_unvarying = 1;
  (data->simulationInfo->realParameter[1302] /* winRad.tra.rhoGlaSol_b[1,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1302].time_unvarying = 1;
  (data->simulationInfo->realParameter[1303] /* winRad.tra.rhoGlaSol_b[2,1] PARAM */) = 0.075;
  data->modelData->realParameterData[1303].time_unvarying = 1;
  (data->simulationInfo->realParameter[1304] /* winRad.tra.rhoShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[1304].time_unvarying = 1;
  (data->simulationInfo->realParameter[1305] /* winRad.tra.rhoShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[1305].time_unvarying = 1;
  (data->simulationInfo->realParameter[1306] /* winRad.tra.tauGlaSol[1,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1306].time_unvarying = 1;
  (data->simulationInfo->realParameter[1307] /* winRad.tra.tauGlaSol[2,1] PARAM */) = 0.834;
  data->modelData->realParameterData[1307].time_unvarying = 1;
  (data->simulationInfo->realParameter[1308] /* winRad.tra.tauShaSol_a PARAM */) = 0.25;
  data->modelData->realParameterData[1308].time_unvarying = 1;
  (data->simulationInfo->realParameter[1309] /* winRad.tra.tauShaSol_b PARAM */) = 0.25;
  data->modelData->realParameterData[1309].time_unvarying = 1;
  (data->simulationInfo->realParameter[1311] /* winRad.tra.xGla[1] PARAM */) = 0.003;
  data->modelData->realParameterData[1311].time_unvarying = 1;
  (data->simulationInfo->realParameter[1312] /* winRad.tra.xGla[2] PARAM */) = 0.003;
  data->modelData->realParameterData[1312].time_unvarying = 1;
  (data->simulationInfo->realParameter[1313] /* winRad.xGla[1] PARAM */) = 0.003;
  data->modelData->realParameterData[1313].time_unvarying = 1;
  (data->simulationInfo->realParameter[1314] /* winRad.xGla[2] PARAM */) = 0.003;
  data->modelData->realParameterData[1314].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[0] /* HDifTilIso.outGroCon PARAM */) = 0;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[1] /* HDifTilIso.outSkyCon PARAM */) = 0;
  data->modelData->booleanParameterData[1].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[2] /* glaSys.haveControllableWindow PARAM */) = 0;
  data->modelData->booleanParameterData[2].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[3] /* glaSys.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[3].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[4] /* glaSys.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[4].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[5] /* glaSys.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[5].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[6] /* linearize PARAM */) = 1;
  data->modelData->booleanParameterData[6].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[7] /* weaDat.computeWetBulbTemperature PARAM */) = 1;
  data->modelData->booleanParameterData[7].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[10] /* weaDat.datRea.tableOnFile PARAM */) = 1;
  data->modelData->booleanParameterData[10].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[11] /* weaDat.datRea.verboseExtrapolation PARAM */) = 0;
  data->modelData->booleanParameterData[11].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[12] /* weaDat.datRea.verboseRead PARAM */) = 0;
  data->modelData->booleanParameterData[12].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[13] /* weaDat.datRea30Min.tableOnFile PARAM */) = 1;
  data->modelData->booleanParameterData[13].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[14] /* weaDat.datRea30Min.verboseExtrapolation PARAM */) = 0;
  data->modelData->booleanParameterData[14].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[15] /* weaDat.datRea30Min.verboseRead PARAM */) = 0;
  data->modelData->booleanParameterData[15].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[16] /* weaDat.tWetBul_TDryBulXi.approximateWetBulb PARAM */) = 0;
  data->modelData->booleanParameterData[16].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[17] /* winRad.abs.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[17].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[18] /* winRad.abs.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[18].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[19] /* winRad.abs.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[19].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[20] /* winRad.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[20].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[21] /* winRad.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[21].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[22] /* winRad.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[22].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[23] /* winRad.noShade PARAM */) = 0;
  data->modelData->booleanParameterData[23].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[24] /* winRad.tra.haveExteriorShade PARAM */) = 0;
  data->modelData->booleanParameterData[24].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[25] /* winRad.tra.haveInteriorShade PARAM */) = 1;
  data->modelData->booleanParameterData[25].time_unvarying = 1;
  (data->simulationInfo->booleanParameter[26] /* winRad.tra.haveShade PARAM */) = 1;
  data->modelData->booleanParameterData[26].time_unvarying = 1;
  (data->simulationInfo->integerParameter[0] /* weaDat.HInfHorSou PARAM */) = 3;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1] /* weaDat.HSou PARAM */) = 4;
  data->modelData->integerParameterData[1].time_unvarying = 1;
  (data->simulationInfo->integerParameter[2] /* weaDat.TBlaSkySel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[2].time_unvarying = 1;
  (data->simulationInfo->integerParameter[3] /* weaDat.TBlaSkySou PARAM */) = 3;
  data->modelData->integerParameterData[3].time_unvarying = 1;
  (data->simulationInfo->integerParameter[4] /* weaDat.TDewPoiSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[4].time_unvarying = 1;
  (data->simulationInfo->integerParameter[5] /* weaDat.TDewPoiSou PARAM */) = 3;
  data->modelData->integerParameterData[5].time_unvarying = 1;
  (data->simulationInfo->integerParameter[6] /* weaDat.TDryBulSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[6].time_unvarying = 1;
  (data->simulationInfo->integerParameter[7] /* weaDat.TDryBulSou PARAM */) = 3;
  data->modelData->integerParameterData[7].time_unvarying = 1;
  (data->simulationInfo->integerParameter[8] /* weaDat.calTSky PARAM */) = 2;
  data->modelData->integerParameterData[8].time_unvarying = 1;
  (data->simulationInfo->integerParameter[9] /* weaDat.ceiHeiSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[9].time_unvarying = 1;
  (data->simulationInfo->integerParameter[10] /* weaDat.ceiHeiSou PARAM */) = 3;
  data->modelData->integerParameterData[10].time_unvarying = 1;
  (data->simulationInfo->integerParameter[37] /* weaDat.datRea.extrapolation PARAM */) = 2;
  data->modelData->integerParameterData[37].time_unvarying = 1;
  (data->simulationInfo->integerParameter[39] /* weaDat.datRea.smoothness PARAM */) = 2;
  data->modelData->integerParameterData[39].time_unvarying = 1;
  (data->simulationInfo->integerParameter[43] /* weaDat.datRea30Min.extrapolation PARAM */) = 2;
  data->modelData->integerParameterData[43].time_unvarying = 1;
  (data->simulationInfo->integerParameter[45] /* weaDat.datRea30Min.smoothness PARAM */) = 2;
  data->modelData->integerParameterData[45].time_unvarying = 1;
  (data->simulationInfo->integerParameter[46] /* weaDat.horInfRadSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[46].time_unvarying = 1;
  (data->simulationInfo->integerParameter[47] /* weaDat.opaSkyCovSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[47].time_unvarying = 1;
  (data->simulationInfo->integerParameter[48] /* weaDat.opaSkyCovSou PARAM */) = 3;
  data->modelData->integerParameterData[48].time_unvarying = 1;
  (data->simulationInfo->integerParameter[49] /* weaDat.pAtmSel.datSou PARAM */) = 2;
  data->modelData->integerParameterData[49].time_unvarying = 1;
  (data->simulationInfo->integerParameter[50] /* weaDat.pAtmSou PARAM */) = 2;
  data->modelData->integerParameterData[50].time_unvarying = 1;
  (data->simulationInfo->integerParameter[51] /* weaDat.relHumSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[51].time_unvarying = 1;
  (data->simulationInfo->integerParameter[52] /* weaDat.relHumSou PARAM */) = 3;
  data->modelData->integerParameterData[52].time_unvarying = 1;
  (data->simulationInfo->integerParameter[53] /* weaDat.souSelRad.datSou PARAM */) = 4;
  data->modelData->integerParameterData[53].time_unvarying = 1;
  (data->simulationInfo->integerParameter[54] /* weaDat.totSkyCovSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[54].time_unvarying = 1;
  (data->simulationInfo->integerParameter[55] /* weaDat.totSkyCovSou PARAM */) = 3;
  data->modelData->integerParameterData[55].time_unvarying = 1;
  (data->simulationInfo->integerParameter[56] /* weaDat.winDirSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[56].time_unvarying = 1;
  (data->simulationInfo->integerParameter[57] /* weaDat.winDirSou PARAM */) = 3;
  data->modelData->integerParameterData[57].time_unvarying = 1;
  (data->simulationInfo->integerParameter[58] /* weaDat.winSpeSel.datSou PARAM */) = 3;
  data->modelData->integerParameterData[58].time_unvarying = 1;
  (data->simulationInfo->integerParameter[59] /* weaDat.winSpeSou PARAM */) = 3;
  data->modelData->integerParameterData[59].time_unvarying = 1;
  Buildings_HeatTransfer_Windows_Examples_WinRadCustom_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

